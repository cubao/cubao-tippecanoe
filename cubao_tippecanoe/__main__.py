import sys
import os
import cubao_tippecanoe
import glob

__PWD = os.path.abspath(os.path.dirname(__file__))


if __name__ == '__main__':
    print(cubao_tippecanoe.__path__, 'die')
    print(sys.argv)
    # - tippecanoe
    # - decode
    # - enumerate
    # - jsontool
    # - overzoom
    # - tile_join