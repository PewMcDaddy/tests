#include "getopt.h"
#include <stdio.h>
#include <stdlib.h>

/* Flags whose address we put in option structs for our long_options[] array, if
 * they are given in the form below with initializer lists, must be super
 * constant.  Which means that we have to declare them here. */

int main ( int argc , char* argv[]){
   /* Or they can be static variables in the main function.  (Because either way,
    * they will be living in the DATA or BSS */
   static int   flagOpt2_flag = 0;
   static int   flagOpt1_flag = 0;

   char* lol_arg = NULL;
   int   e_flag = 0;
   extern char* optarg;
   extern int   optind;
   int index,c;

   /* Define options: one letter options in shortopts, the letter should be
    * followed by a colon if the option takes an argument, long_options are
    * defined by a struct with a name, has_args, flag, and val explained within
    * the declaration*/
   char* shortopts = "e:";
   static struct option long_options[] =
   {
      /* Option descriptions */
      {"flagOpt1", /* char* name */
         no_argument, /* int has_arg (Setting required_argument, no_argument, optional_argument) */
         &flagOpt1_flag, /* if not null, will receive the value in the following field*/
         1 /* int val (value assigned to *flag if flag != NULL, othewise, identifier of the option returned by getopt_long()).*/
      },
      {"flagOpt2", no_argument, &flagOpt2_flag, 1},
      {"argopt", required_argument, 0, 'l'},
      {NULL,0,0,0} /* Necessary for getopt_long to know that it has reached the
                      end of the array, otherwise, invalid options would cause
                      segfaults in a weird way.  As long as you don't try to
                      look at the value of optind, it works fine without this
                      line, but try to look at optind after having passed an
                      invalid command line option, and you're screwed! */
   };

   /* Original order of arguments */
   index = 0;
   puts("\nOrder of arguments before option parsing\n========================================");
   printf("(argc = %d)\n",argc);
   for ( index = 0; index < argc; ++index){
      printf("argv[%d] : %s \n", index, argv[index]);
   }

   
   /* Option parsing part: getopt_long will return -1 when option parsing is
    * finished.  It will also rearrange the arguments of the program when it is
    * done so that the positionnal parameters show up at the end.*/
   puts("\nOption parsing part\n===================");
   while ( (c = getopt_long( argc, argv, "e", long_options, &index)) != -1 ) {
      switch (c){
         case 0:
            printf("Encountered flag setting option: %s\n", long_options[index].name);
            break;
         case 'l':
            printf("option argopt with argument %s \n", optarg );
            break;
         case 'e':
            printf("Short option encountered with argument %s \n", optarg);
            index = 0;
            while ( index < argc){
               printf("argv[%d] : %s \n", index++, argv[index]);
            }
            break;
         case '?':
            printf("optind : %d \n", optind);
            puts("Getopt_long printed an error message\n");
            /* Program should abort here but doesn't for demonstration purposes */
            break;
         default:
            abort();
      }
   }

   /* Once option parsing is done, the positionnal parameters will be at the end
    * of the argv array.  They will remain in order, and at the end of option
    * parsing, optind will be the index of the firs one of them.*/
   while ( optind < argc ){
      printf("Non option argument : %s, (optind = %d)\n", argv[optind], optind);
      ++optind;
   }

   /* Here we can notice that the arguments were moved around for the preceding
    * loop to go through the non-option arguments */
   puts("\nOrder of arguments after option parsing \n=======================================");
   for ( index = 0; index < argc; ++index){
      printf("argv[%d] : %s \n", index, argv[index]);
   }
   puts("\nArguments of bad options are treated as positional arguments therefore the program should abort when a bad option is encountered.\n");

   return 0;
}



