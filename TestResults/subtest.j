.source Main.java
.class  synchronized Main
.super  java/lang/Object
.field static a I
.field static b I
.field static c I
; >> MAIN <<
.method public static main([Ljava/lang/String;)V
.throws java/io/IOException
.limit stack 32
.limit locals 32
ldc 1
putstatic Main/a I
ldc 2
putstatic Main/b I
ldc 3
putstatic Main/c I
getstatic Main/a I
getstatic Main/b I
getstatic Main/c I
idiv
isub
istore 1
getstatic Main/a I
getstatic Main/b I
idiv
getstatic Main/c I
isub
istore 2
iload 1
iload 2
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

