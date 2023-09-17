import sys
import os
import glob
from pprint import pprint
import subprocess


if __name__ == '__main__':
    import _pybind11_tippecanoe
    libdir = os.path.dirname(_pybind11_tippecanoe.__file__)
    prefix = '__cubao_tippecanoe_'
    exes = sorted(glob.glob(f'{libdir}/{prefix}*.exe'))
    exes = {e.rsplit('/', 1)[-1][len(prefix):].split('.')[0]: e for e in exes}
    if len(sys.argv) > 1 and sys.argv[1] not in exes:
        exe = exes[sys.argv[1]]
        print(f'exe: {exe}')
        args = sys.argv[2:]
        print(f'args: {args}')
        subprocess.check_call([exe, *args])
    else:
        print('commands are:', '\n\t'.join(exes.keys()))
        exit(-1)