#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


   int main(int argc, char *argv[])
   {
     FILE *pipe_fp, *infile;
     char readbuf[80];

     if(argc!=3) { fprintf(stderr, "USAGE: popen3 [command] [filename]\n"); exit(1); }


       /* Open up input file */
       if((infile = fopen(argv[2], "rt")) == NULL) { perror("fopen"); exit(1); }

       /* Create one way pipe line with call to popen() */
       if((pipe_fp = popen(argv[1], "w")) == NULL) { perror("popen"); exit(1); }

        /* Processing loop */
        do {
             fgets(readbuf, 80, infile);
             if(feof(infile)) break;
             fputs(readbuf, pipe_fp);
            } while(!feof(infile));

            fclose(infile);
            pclose(pipe_fp);
            return(0);
         }

       /* 
          
          popen3 sort popen3.c
          popen3 cat popen3.c
          popen3 more popen3.c 
          popen3 cat popen3.c | grep main
       */

