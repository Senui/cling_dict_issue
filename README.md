# Reproducer for dynamic cast segfault with ROOT-dictionary-compiled library

This example reproduces the problem described in: https://root-forum.cern.ch/t/program-crashes-in-cling-only-when-dictionaries-are-built/37178/11


### Expected outcome
Processing test.C...
123
123
123

### To reproduce segfault

```
$ source /path/to/thisroot.sh
$ ./build.sh
$ root -l -q test.C

// Output:
Processing test.C...
123

 *** Break *** segmentation violation

```

#### I believe the following is happening
We include classes with `#include src/reproducer.h`, but Cling doesn't know
about `USE_DICT`, so uses our dummy dictionaries.
Then we load libreproducer with `R__LOAD_LIBRARY(libreproducer)`, where the
classes were compiled with `USE_DICT` being set, and use the rootcling-generated
dictionaries. The call to `Foo()` is a library call, so the `dynamic_cast` in
there uses (I think) the library-defined memory layout. The `dynamic_cast` in
test.C uses the cling-defined memory layout, which differs from the former.
Hence, we get an illegal memory access.

### The fix

```
$ git apply fix.patch
$ ./build.sh 
$ root -l -q test.C

// Output:
Processing test.C...
123
123
123
```
