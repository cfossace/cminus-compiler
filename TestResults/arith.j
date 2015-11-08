.source Main.java
.class  synchronized Main
.super  java/lang/Object
.field static x I
.field static y I
.field static sum I
; >> MAIN <<
.method public static main([Ljava/lang/String;)V
.throws java/io/IOException
.limit stack 32
.limit locals 32
getstatic Main/x I
ldc 2
isub
putstatic Main/x I
getstatic Main/y I
ldc 3
iadd
putstatic Main/y I
getstatic Main/sum I
getstatic Main/x I
isub
getstatic Main/y I
isub
ldc 4
iadd
putstatic Main/sum I
getstatic Main/sum I
getstatic Main/sum I
imul
getstatic Main/y I
idiv
putstatic Main/sum I
getstatic java/lang/System/out Ljava/io/PrintStream;
getstatic Main/sum I
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

