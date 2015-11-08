.source Main.java
.class  synchronized Main
.super  java/lang/Object
.field static x I
;>> FUNCTION f <<
.method static f(I)I
.limit stack 32
.limit locals 32
iload 0
ldc 1
if_icmpgt Label1
ldc 1
istore 1
goto Label2
Label1:
iload 0
iload 0
ldc 1
isub
invokestatic Main/f(I)I
imul
istore 1
Label2:
iload 1
ireturn
.end method

; >> MAIN <<
.method public static main([Ljava/lang/String;)V
.throws java/io/IOException
.limit stack 32
.limit locals 32
ldc 5
putstatic Main/x I
getstatic java/lang/System/out Ljava/io/PrintStream;
getstatic Main/x I
invokestatic Main/f(I)I
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

