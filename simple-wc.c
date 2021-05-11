// simple-wc.c
// Ray Nieport 2021

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int lines=0, words=0, chars=0;
int total_lines=0, total_words=0, total_chars=0;

// Count lines, words, and chars in the provided file
void getCounts(FILE* fp){
   lines=0, words=0, chars=0;
   int ch, prev=' ';
   while((ch = fgetc(fp)) != EOF){
      chars++;
      if(ch == '\n') lines++;
      if(isspace(ch)!=0 && isspace(prev)==0) words++;
      prev = ch;
   }
   if(isspace(prev)==0) words++;
   total_lines+=lines;
   total_words+=words;
   total_chars+=chars;
   return;
}

// Print counts based on args passed
int printInfo(int option, char* file){
   int tOption = option;
   if(tOption>=4){
      printf("\t%d", lines);
      tOption -= 4;
   }
   if(tOption>=2){
      printf("\t%d", words);
      tOption -= 2;
   }
   if(tOption==1){
      printf("\t%d", chars);
   }
   printf("\t%s\n", file);
}


int main(int argc, char* argv[]) {
   int option=0, optionsPassed=0, m=0, l=0, w=0;

   // use chmod-like system to determine which args were passed (7 for all)
   for(int j=1; j<argc; j++){
      if(argv[j][0]=='-' && strlen(argv[j])>1){
         if(strcmp(argv[j],"--help") == 0){
            fprintf(stderr,"Usage: simple-wc [OPTION]... [FILE]...\n"
               "Prints line, word, and character counts for each FILE, and totals if more than one FILE is given.\n"
               "When no FILE is provided, or FILE is -, reads from standard input.\n\n"
               "Options:\n"
               "-m : print character counts\n"
               "-w : print word counts\n"
               "-l : print line counts\n");
            exit(1);
         }
         for(size_t i=1; i<strlen(argv[j]); i++){
            if(!(argv[j][i] == 'm' || argv[j][i] == 'l' || argv[j][i] == 'w')){
               fprintf(stderr,"simple-wc: invalid option -- '%c'\nTry 'simple-wc --help' for more information.\n", argv[j][i]);
               exit(1);
            }
            else if(argv[j][i] == 'm' && m == 0){
               option += 1, m = 1;
            }
            else if(argv[j][i] == 'w' && w == 0){
               option += 2, w = 1;
            }
            else if(argv[j][i] == 'l' && l == 0){
               option += 4, l = 1;
            }
         }
         optionsPassed += 1;
      }
   }
   if(optionsPassed == 0) option=7;

   // get counts and print stats
   for(int j=1; j<argc; j++){
      if(argv[j][0]=='-' && strlen(argv[j])==1) getCounts(stdin), printInfo(option,argv[j]);
      else if(argv[j][0]!='-'){
         FILE* fp = fopen(argv[j], "r");
         if(!fp) fprintf(stderr,"simple-wc: %s: No such file or directory\n", argv[j]);
         else getCounts(fp), printInfo(option,argv[j]), fclose(fp);
      }
   }
   if(argc-optionsPassed < 2) getCounts(stdin), printInfo(option,"");

   // print the total stats
   if(argc-optionsPassed > 2){
      lines=total_lines;
      words=total_words;
      chars=total_chars;
      printInfo(option,"total");
   }
}