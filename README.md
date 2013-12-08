gopower
=======

Go language port for Linux on the IBM POWER architecture

Compiling
=========

To compile first set GOOS=linux and GOARCH=ppc environment variables and run make.bash in the "src" directory. At the moment the build will ultimately fail but the qa and qc binaries (among others) can be found in the pkg/tool/os-architecture folder.
