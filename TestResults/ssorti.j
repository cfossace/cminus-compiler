.source Main.java
.class  synchronized Main
.super  java/lang/Object
.field static max I
.field static data [I
.field static i I
.field static j I
.field static mindex I
.field static tmp I
; >> MAIN <<
.method public static main([Ljava/lang/String;)V
.throws java/io/IOException
.limit stack 32
.limit locals 32
ldc 0
putstatic Main/i I
ldc 9
putstatic Main/max I
ldc 9
putstatic Main/j I
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc 10
invokevirtual java/io/PrintStream/println(I)V
Label1:
getstatic Main/i I
getstatic Main/max I
if_icmpgt Label2
new java/util/Scanner
dup
getstatic java/lang/System/in Ljava/io/InputStream;
invokenonvirtual java/util/Scanner/<init>(Ljava/io/InputStream;)V
astore 1
aload 1
invokevirtual java/util/Scanner/nextInt()I
putstatic Main/tmp I
getstatic Main/data [I
getstatic Main/i I
getstatic Main/tmp I
iastore
getstatic Main/j I
ldc 1
isub
putstatic Main/j I
getstatic Main/i I
ldc 1
iadd
putstatic Main/i I
goto Label1
Label2:
ldc 0
putstatic Main/i I
Label3:
getstatic Main/i I
getstatic Main/max I
if_icmpgt Label4
getstatic Main/i I
putstatic Main/mindex I
getstatic Main/i I
ldc 1
iadd
putstatic Main/j I
Label5:
getstatic Main/j I
getstatic Main/max I
if_icmpgt Label6
getstatic Main/data [I
getstatic Main/j I
iaload
getstatic Main/data [I
getstatic Main/mindex I
iaload
if_icmpge Label7
getstatic Main/j I
putstatic Main/mindex I
goto Label8
Label7:
getstatic Main/mindex I
putstatic Main/mindex I
Label8:
getstatic Main/j I
ldc 1
iadd
putstatic Main/j I
goto Label5
Label6:
getstatic Main/data [I
getstatic Main/mindex I
iaload
putstatic Main/tmp I
getstatic Main/data [I
getstatic Main/mindex I
getstatic Main/data [I
getstatic Main/i I
iaload
iastore
getstatic Main/data [I
getstatic Main/i I
getstatic Main/tmp I
iastore
getstatic Main/i I
ldc 1
iadd
putstatic Main/i I
goto Label3
Label4:
ldc 0
putstatic Main/i I
Label9:
getstatic Main/i I
getstatic Main/max I
if_icmpgt Label10
getstatic java/lang/System/out Ljava/io/PrintStream;
getstatic Main/data [I
getstatic Main/i I
iaload
invokevirtual java/io/PrintStream/println(I)V
getstatic Main/i I
ldc 1
iadd
putstatic Main/i I
goto Label9
Label10:
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
putstatic Main/data [I
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

