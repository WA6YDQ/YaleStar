/* star.c - parse the Yale star catalog */
/* k theis 3/2019 */
/* display as text file, output as .csv for spreadsheet use */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[200];
    char BSN[5];        // Harvard Bright Star Number
    char NAME[11];      // Name (bayer or flamsteed)
    char RAH[3];        // RA hours
    char RAM[3];        // RA min
    char RAS[5];        // RA sec
    char DECD[5];       // DEC deg
    char DECM[4];       // DEC min
    char DECS[4];       // DEC sec
    char MAG[6];        // Visual Magnitude
    char SPECTRAL[22];  // Spectral Type

    int n;

    FILE *infile, *outfile;

    infile = fopen("bsc5.dat","r");
    if (infile == NULL) {
        fprintf(stderr,"Error opening source file\n");
        exit(1);
    }
    outfile = fopen("yalecat.csv","w");
    if (outfile == NULL) {
        fprintf(stderr,"Error creating dest file\n");
        exit(1);
    }

    while (!feof(infile)) {
        fgets(line,198,infile);
        for (n=0; n<4; n++) {
            if (line[n]=='\n') line[n]='\0';
            BSN[n] = line[n]; // Bright Star Number
        }
        BSN[n]='\0';
        if (strlen(BSN) == 0) continue;

        for (n=4; n<14; n++) {
            if (line[n]=='\n') line[n]='\0';
            NAME[n-4] = line[n]; // Star Name
        }
        NAME[n-4]='\0';

        for (n=60; n<62; n++) RAH[n-60]=line[n]; // RA hours
        RAH[n-60]='\0';
        for (n=62; n<64; n++) RAM[n-62]=line[n]; // RA min
        RAM[n-62]='\0';
        for (n=64; n<68; n++) RAS[n-64]=line[n]; // RA sec
        RAS[n-64]='\0';
        for (n=68; n<71; n++) DECD[n-68]=line[n]; // DEC Sgn/Deg
        DECD[n-68]='\0';
        for (n=71; n<73; n++) DECM[n-71]=line[n]; // DEC min
        DECM[n-71]='\0';
        for (n=73; n<75; n++) DECS[n-73]=line[n]; // DEC sec
        DECS[n-73]='\0';

        for (n=102; n<107; n++) MAG[n-102] = line[n];  // Magnitude
        MAG[n-102] = '\0';

        for (n=127; n<147; n++) SPECTRAL[n-127] = line[n];  // Spectral
        SPECTRAL[n-127] = '\0';

        /* print to file for spreadsheet use */
        fprintf(outfile,"%s,%d,%d,%d,%d,%d,%d,%d,%s,%s\n",NAME,atoi(BSN),atoi(RAH),atoi(RAM),atoi(RAS),atoi(DECD),atoi(DECM),atoi(DECS),MAG,SPECTRAL);
        printf("%s ",NAME);
        printf("%s ",BSN);
        printf("RA %02d %02d %02d\t ",atoi(RAH),atoi(RAM),atoi(RAS));
        printf("Dec %s %s %s Mag %s Class %s \n",DECD,DECM,DECS,MAG,SPECTRAL);
   }

   fclose(outfile);
   fclose(infile);

   return 0;
}


