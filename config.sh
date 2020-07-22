# Define custom utilities

function pre_build {
    # Any stuff that you need to do before you start building the wheels
    # Runs in the root directory of this repository.

    $PYTHON_EXE -m pip install numpy cython scikit-build
    $PYTHON_EXE -m pip install "cmake<3.14"

    yum_install uuid

    # Need to tell auditwheel where to find Slb.Salmon.Zgy
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/zgy2sgz/open-zgy/zgy/Slb.Salmon.ZgyPublic/Lin64_gcc485

    ZFP_BUILD_DIR="zfp/build"
    BUILD_DIR="zgy2sgz/build"

    echo $BUILD_DIR
    echo $ZFP_BUILD_DIR
    $PYTHON_EXE --version
    cmake --version


    mkdir $ZFP_BUILD_DIR
    pushd $ZFP_BUILD_DIR
    cmake ..
    cmake --build . --target install
    popd


    mkdir $BUILD_DIR
    pushd $BUILD_DIR
    cmake ..
    cmake --build . --target install
    popd
}

function run_tests {
    # TODO
    :
}
