.source Main.java
.class  synchronized Main
.super  java/lang/Object
.field static i I
.field static f I
.field static a [I
.field static e [I
;>> FUNCTION g <<
.method static g(I[I)I
.limit stack 32
.limit locals 32
ldc 5
newarray int
astore 2
aload 2
ldc 2
iload 0
aload 1
ldc 3
iaload
iadd
iastore
aload 2
ldc 2
iaload
ireturn
.end method

; >> MAIN <<
.method public static main([Ljava/lang/String;)V
.throws java/io/IOException
.limit stack 32
.limit locals 32
ldc 1
istore 1
Label1:
iload 1
ldc 1
if_icmpne Label2
ldc 2
istore 1
goto Label1
Label2:
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

.method static <clinit>()V
.limit stack 1
.limit locals 0
ldc 10
newarray int
putstatic Main/a [I
ldc 10
newarray int
putstatic Main/e [I
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
