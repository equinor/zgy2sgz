# zgy2sgz

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![Travis](https://img.shields.io/travis/equinor/zgy2sgz/master.svg?label=travis)](https://travis-ci.org/equinor/zgy2sgz)
[![PyPi Version](https://img.shields.io/pypi/v/zgy2sgz.svg)](https://pypi.org/project/zgy2sgz/)


Tiny utility package which has only one job: Provide a Python function which uses Schlumberger's ZGY library and LLNL's ZFP library to read ZGY files and write [seismic-zfp (.SGZ) format](https://github.com/equinor/seismic-zfp/blob/master/docs/file-specification.md) files.

zgy2sgz is intended exclusively for use by the [seismic-zfp package](https://github.com/equinor/seismic-zfp)

## Example

```python
from zgy2sgz import convertFile
# Yes, the first two arguments are bytes rather than strings
# The 3rd argument is bits_per_voxel {16, 8, 4, 2, 1}
convertFile(b'seismic_file.zgy', b'seismic_file.sgz', 4)
```

---
### Archiving
2023-10-20: Repository archived in Github cleanup as this package is no longer maintained, since [pyzgy](https://github.com/equinor/pyzgy) now provides the required functionality to [semsic-zfp](https://github.com/equinor/seismic-zfp) in a more maintainable way.
