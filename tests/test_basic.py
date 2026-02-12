import cubao_tippecanoe


def test_version():
    assert cubao_tippecanoe.__version__


def test_run_cmd():
    assert callable(cubao_tippecanoe.run_cmd)
