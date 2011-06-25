# Nintendo DS Pong #
This is a homebrew pong-clone for Nintendo DS.
To compile the source code, you can use the supported Makefile.
You will need to set up devkitPRO-environment with devkitARM- and libnds-library.
Files can be found here: http://sourceforge.net/projects/devkitpro/

## Compiler Setup (Unix only) ##
We assume gcc is configured. Download devkitPRO, devkitARM, libnds and libnds-maxmod.  
1. If not exists, create a folder /etc/devkitPRO  
2. Extract devkitARM into a subdirectory to /etc/devkitPRO/devkitARM   
3. Extract libnds and libnds-maxmod to /etc/devkitPRO/libnds  
4. Set DEVKITPRO and DEVKITARM as globals (e.g. in your .bashrc: export DEVKITPRO=/etc/devkitPRO export DEVKITARM=${DEVKITPRO}/devkitARM

## Authors ##
Tobias Dreyer   
Oliver Lorenz
Florian Purchess
