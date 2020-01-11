This repository contains a distribution of ns3.30 (allinone version) with added
class for InfDistHeader --- a header that stores metadata for information
distribution. The following files were modified:

ns-allinone-3.30/ns-3.30/src/network/utils/infdist-header.cc
ns-allinone-3.30/ns-3.30/src/network/utils/infdist-header.h
ns-allinone-3.30/ns-3.30/src/network/wscript

Probably it's possible to have those modifications in our project without
modifying ns3 source code, but I suck in C++.

Installation
============

First of all, you will need to install all Python requirements. I didn't write
all of them down when I was setting up my system, so you might have to figure
them out (if something is missing, install it). Some of them are in the
requirements.txt file and can be installed with pip:

    pip install -r requirements.txt


It might be not the best idea, but this repository contains pre-compiled
binaries that work on my computer. If you are lucky they should also work on
yours. Otherwise use official documentation and `waf` to compile everything on
your own.


How to use it 
=============

Like in the original ns3 distribution (check manual), `waf` should be working.

You can run your python scripts with:

    cd ./ns-allinone-3.30/ns-3.30
    python ./waf --pyrun

If you have changed some C++ source code, you might need to regenerate Python
bindings (only 'network' module in this case):

    python ./waf --apiscan=network  
