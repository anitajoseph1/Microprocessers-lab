#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
void main(){
   FILE *input,*optab,*symtab,*intermediate,*length;
   input=fopen("input.txt","r");
   optab=fopen("optab.txt","r");
   intermediate=fopen("intermediate.txt","w");
   symtab=fopen("symtab.txt","w+");
   length=fopen("length.txt","w");
   char label[20],opcode[20],operand[20],symtab_data[20],optab_data[20];
   int locctr,start_address,program_length;
   bool symbol_found,opcode_found;
   
   fscanf(input,"%s%s%s",label,opcode,operand);
   if(strcmp(opcode,"START")==0){
     start_address=atoi(operand);
     locctr=start_address;
     fprintf(intermediate,"\t\t%s\t\t%s\t%s\n",label,opcode,operand);
   }
   else{
     locctr=0;
   }
   fscanf(input,"%s%s%s",label,opcode,operand);
   while(strcmp(opcode,"END")!=0){
     if(strcmp(label,"**")!=0){
       symbol_found=false;
       rewind(symtab);
       while(!feof(symtab)){
         fscanf(symtab,"%s",symtab_data);
         if(strcmp(symtab_data,label)==0){
           printf("Error: Label Found!");
           symbol_found=true;
         }
       }
       if(symbol_found==false)
         fprintf(symtab,"%s\t%d\n",label,locctr);
       }
    opcode_found=false;
    rewind(optab);
    while(!feof(optab)){
      fscanf(optab,"%s",optab_data);
      if(strcmp(optab_data,opcode)==0)
        opcode_found=true;
      }
      fprintf(intermediate,"%d\t",locctr);
      if(opcode_found==true)
        locctr+=3;
      else if(strcmp(opcode,"WORD")==0)
        locctr+=3;
      else if(strcmp(opcode,"RESW")==0)
        locctr+=3*(atoi(operand));
      else if(strcmp(opcode,"RESB")==0)
        locctr+=atoi(operand);
      else if(strcmp(opcode,"BYTE")==0)
        locctr+=strlen(operand)-3;
      else
        printf("Error: Invalid Operation Code!");
      fprintf(intermediate,"%s\t%s\t%s\n",label,opcode,operand);
      fscanf(input,"%s%s%s",label,opcode,operand);
   }
   fprintf(intermediate,"%d\t%s\t\t%s\t%s\n",locctr,label,opcode,operand);
   program_length=locctr-start_address;
   printf("Program length: %d",program_length);
   fprintf(length,"%d",program_length);
   fclose(input);
   fclose(optab);
   fclose(intermediate);
   fclose(symtab);
   fclose(length);
}
