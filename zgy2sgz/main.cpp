#include "convert/convert.h"

int main(int argc, char* argv[])
{
  // check args
    if (argc != 4) {
        std::cout << "usage: " << argv[0] << " <infilename> <outfilename> <bits-per-voxel>" << std::endl;
        return 0;
    }
	convertFile(argv[1], argv[2], atoi(argv[3]));
	return 0;
}
