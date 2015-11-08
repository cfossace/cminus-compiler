/* Functions to print JVM assembly instructions */
#include <stdio.h>
#include <stdlib.h>


void genBegin() {/* boilerplate code */
	/* comment and header including default constructor */
  printf(".source Main.java\n");
  printf(".class  synchronized Main\n");
  printf(".super  java/lang/Object\n");

}

void genConstruct(){
  printf("; >> CONSTRUCTOR <<\n");
  printf(".method <init>()V\n");
  printf(".limit stack 1\n");
  printf(".limit locals 1\n");
  printf(".line 2\n");
  printf("aload_0\n");
  printf("invokenonvirtual java/lang/Object/<init>()V\n");
  printf("return\n");
  printf(".end method\n\n");
}

void genFunc(){
  //printf(";>> FUNCTION %s <<\n", name);
    printf(".limit stack 32\n");
    printf(".limit locals 32\n");
}


void genMain(){
  /* start of main */
  printf("; >> MAIN <<\n");
  printf(".method public static main([Ljava/lang/String;)V\n");
  printf(".throws java/io/IOException\n");
  printf(".limit stack 32\n");
  printf(".limit locals 32\n");
  
 
} 

void genReadMethod() {/* boilerplate code for read method */
  printf("; >> READ METHOD <<\n");
  printf(".method private static myRead()I\n");
  printf(".throws java/io/IOException\n\n");

  printf(".limit stack 5\n");
  printf(".limit locals 2\n\n");

  printf("new java/io/BufferedReader\n");
  printf("dup\n");
  printf("new java/io/InputStreamReader\n");
  printf("dup\n");
  printf("getstatic java/lang/System/in Ljava/io/InputStream;\n");
  printf("invokenonvirtual java/io/InputStreamReader/<init>(Ljava/io/InputStream;)V\n");
  printf("invokenonvirtual java/io/BufferedReader/<init>(Ljava/io/Reader;)V\n");
  printf("astore_0\n");
  printf("aload_0\n");
  printf("invokevirtual java/io/BufferedReader/readLine()Ljava/lang/String;\n");
  printf("astore_1\n");
  printf("aload_1\n");
  printf("invokestatic java/lang/Integer/parseInt(Ljava/lang/String;)I\n");
  printf("ireturn\n");
  printf(".end method\n\n");
} 

void genAssign(int i) {
    printf("istore %d\n", i);
}

void genRead(int i) {
  printf("invokestatic Main/myRead()I\n");
  printf("istore %d\n", i);
}

void genBeginPrint() {
  printf("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
}

void genEndPrint() {
  printf("invokevirtual java/io/PrintStream/println(I)V\n");
}

void genLoadVar(int scope,int JVM, char*name) { /* i is the JVM # for the variable */
    if (scope!= 0)
	{printf("iload %d\n", JVM);
	}
    else
	{
         printf("getstatic Main/%s I\n", name);
	}
}

void genLoadArr(int scope,int JVM, char*name) { /* i is the JVM # for the variable */
    if(scope!= 0){printf("aload %d\n", JVM);}
    else {printf("getstatic Main/%s [I\n", name);}
}

void genLoadConst(int JVM) {
    printf("ldc %d\n", JVM);
}

void genCodeAdd() {
    printf("iadd\n");
}

void genCodeSub() {
    printf("isub\n");
}

void genCodeMul() {
    printf("imul\n");
}

void genCodeDiv() {
    printf("idiv\n");
}

void genCodeEQUAL(){
    printf("if_icmpeq ");
}

void genCodeNOTEQ(){
    printf("if_icmpne ");
}

void genCodeLESS(){
    printf("if_icmplt ");
}

void genCodeLESSEQ(){
    printf("if_icmple ");
}

void genCodeGREATEQ(){
    printf("if_icmpge ");
}

void genCodeGREAT(){
    printf("if_icmpgt ");
}

void genRet(){
  printf("return\n");
  printf(".end method\n\n");
}
void genEnd() {/* end main and print boilerplate code for myRead() */
  genReadMethod();
}
/*
void genClinit(){
  if (globArrCnt !=0)
	{	
		int count;
		printf(".method static <clinit>()V\n");
	  	printf(".limit stack 1\n");
	  	printf(".limit locals 0\n");
		print
	}
}
*/

/*void genGlobArr(int size, char *name){
	printf("ldc %d\n",size);
	printf("newarray int\n");
       	printf("putstatic Main/%s [I\n", name);
}
*/
void genVar(int scope, char * name, int JVM){ /*impossible to have type VOID*/
  
 if(scope == 0)
	{
	printf(".field static %s I\n", name);
	}
  else {
	printf("iload %d\n", JVM);
	}
}

void genArr(int scope, char * name, int size, int JVM){ /*impossible to have type VOID*/
  if (scope == 0)
	{
	printf(".field static %s [I\n", name);
	}

  else {
	printf("ldc %d\n", size);
	printf("newarray int\n");
	printf("astore %d\n", JVM);
	}
}

/* A C function to generate new label names */

char * genLabel(void) {
  static int num = 0;
  char * lab = (char *)malloc(20*sizeof(char) + 1);
  num++;
  sprintf(lab, "Label%d", num);
  return lab;
}


void scanNow(int JVM){
	printf("aload %d\ninvokevirtual java/util/Scanner/nextInt()I\n",JVM, JVM);}


