# YaleStar
Parse the Yale Star catalog for field use.

star.c is a simple C program to extract a few useful fields from the 
Yale bright star catalog. 

To use it, compile star.c:
   gcc -o star star.c
or use any other compiler of your choice. This was written for Linux/unix
so the cr/lf of MS-DOS may be a problem. 

The following fields will be extracted:

Harvard Bright Star Number

Name (Bayer or Flamsteed)

RA hours/min/sec

DEC sign/dev/min/sec

Visual magnitude

Spectral type

To use place the star executable and bsc5.dat in the same
directory. Run star. The output will be displayed on screen or you can save it to a file:
   star > output.txt

The filed splits are in bsc5.readme if you need other fields.

