.source Main.java
.class  synchronized Main
.super  java/lang/Object
;>> FUNCTION sum <<
.method static sum(I)I
.limit stack 32
.limit locals 32
ldc 0
istore 2
ldc 0
istore 1
Label1:
iload 1
iload 0
if_icmpgt Label2
iload 2
iload 1
iadd
istore 2
iload 1
ldc 1
iadd
istore 1
goto Label1
Label2:
iload 2
ireturn
.end method

; >> MAIN <<
.method public static main([Ljava/lang/String;)V
.throws java/io/IOException
.limit stack 32
.limit locals 32
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc 20
invokestatic Main/sum(I)I
invokevirtual java/io/PrintStream/println(I)V
return
.end method

; >> CONSTRUCTOR <<
.method <init>()V
.limit stack 1
.limit locals 1
.line 2
aload_0
invokenonvirtual java/lang/Object/<init>()V
return
.end method

; >> READ METHOD <<
.method private static myRead()I
.throws java/io/IOException

.limit stack 5
.limit locals 2

new java/io/BufferedReader
dup
new java/io/InputStreamReader
dup
getstatic java/lang/System/in Ljava/io/InputStream;
invokenonvirtual java/io/InputStreamReader/<init>(Ljava/io/InputStream;)V
invokenonvirtual java/io/BufferedReader/<init>(Ljava/io/Reader;)V
astore_0
aload_0
invokevirtual java/io/BufferedReader/readLine()Ljava/lang/String;
astore_1
aload_1
invokestatic java/lang/Integer/parseInt(Ljava/lang/String;)I
ireturn
.end method

