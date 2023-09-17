import sys
import os
from cubao_tippecanoe import run_cmd

if __name__ == '__main__':
    print(sys.argv)
    run_cmd(sys.argv[1], sys.argv[2:])

    # - tippecanoe
    # - decode
    # - enumerate
    # - jsontool
    # - overzoom
    # - tile_join