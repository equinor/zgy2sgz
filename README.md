# zgy2sgz

Small utility package which has only one job: Provide a Python function which uses Schlumberger's ZGY library and LLNL's ZFP library to read ZGY files and write seismic-zfp files.

###Example

```python
from zgy2sgz import convertFile
# Yes, the first two arguments are bytes rather than strings
# The 3rd argument is bits_per_voxel {16, 8, 4, 2, 1}
convertFile(b'seismic_file.zgy', b'seismic_file.sgz', 4)
```
