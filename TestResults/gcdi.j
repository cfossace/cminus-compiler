.source Main.java
.class  synchronized Main
.super  java/lang/Object
;>> FUNCTION gcd <<
.method static gcd(II)I
.limit stack 32
.limit locals 32
iload 1
ldc 0
if_icmpne Label1
iload 0
goto Label2
Label1:
iload 1
iload 0
iload 0
iload 1
idiv
iload 1
imul
isub
invokestatic Main/gcd(II)I
Label2:
ireturn
.end method

; >> MAIN <<
.method public static main([Ljava/lang/String;)V
.throws java/io/IOException
.limit stack 32
.limit locals 32
new java/util/Scanner
dup
getstatic java/lang/System/in Ljava/io/InputStream;
invokenonvirtual java/util/Scanner/<init>(Ljava/io/InputStream;)V
astore 1
aload 1
invokevirtual java/util/Scanner/nextInt()I
istore 1
aload 1
invokevirtual java/util/Scanner/nextInt()I
istore 2
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
iload 2
invokestatic Main/gcd(II)I
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

