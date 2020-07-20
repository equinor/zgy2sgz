#pragma once
/** Copyright 2020 Schlumberger
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *     http://www.apache.org/licenses/LICENSE-2.0
  * 
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
*/

// Since this is example code that should be buildable outside the
// Salmon baseline, it is possible (but perhaps not desirable)
// to not use the full include path but instead rely on the
// compiler having -I directives for all public header directories,
// and to pick up local headers from the current directory.
// So, we can include Api files as either
//   #include <Salmon/Zgy/Api/SOMETHING.h>
//   #include <SOMETHING.h>
// and local includes can be either
//   #include <Salmon/Zgy/Api/Example/SOMETHING.h>
//   #include "SOMETHING.h"
// Using the Salmon convention does have its benefits,
// as it allows more verification in the deploy scripts.

#include <Salmon/Zgy/Api/SimpleString.h>
#include <string>

template <class T>
class Buffer
{
public:

	typedef T   value_type;
	typedef int size_type;

	Buffer(size_type n = 0)
		: addr((n > 0)?new value_type[n]:0)
	{
	}
	~Buffer()
	{
		if (addr != 0) {
			delete[] addr;
		}
	}

	      value_type* get()       { return addr; }
	const value_type* get() const { return addr; }

	      value_type& operator[](size_type i)       { return addr[i]; }
	const value_type& operator[](size_type i) const { return addr[i]; }

private:

	value_type* addr;

	Buffer(const Buffer&);
	Buffer& operator=(const Buffer&);
};


inline std::string StdStr(const Slb::Salmon::Zgy::ZgyApi::SimpleString& s)
{
	const Buffer<char>::size_type bufsize(s.size() + 1);
	Buffer<char> buf(bufsize);
	return std::string((s.getCstr(buf.get(), bufsize) < bufsize)?"<error in string conversion>":buf.get());
}

inline bool operator==(const Slb::Salmon::Zgy::ZgyApi::SimpleString& a, const Slb::Salmon::Zgy::ZgyApi::SimpleString& b)
{
  return StdStr(a) == StdStr(b);
}

template <class Stream>
inline Stream& operator<<(Stream& stream, const Slb::Salmon::Zgy::ZgyApi::SimpleString& s)
{
	return stream << StdStr(s);
}
