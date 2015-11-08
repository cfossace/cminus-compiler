.source Main.java
.class  synchronized Main
.super  java/lang/Object
.field static max I
;>> FUNCTION bubbleSort <<
.method static bubbleSort([II)V
.limit stack 32
.limit locals 32
ldc 0
istore 2
Label1:
iload 2
iload 1
if_icmpge Label2
ldc 1
istore 3
Label3:
iload 3
iload 1
iload 2
isub
if_icmpge Label4
aload 0
iload 3
ldc 1
isub
iaload
aload 0
iload 3
iaload
if_icmple Label5
aload 0
iload 3
ldc 1
isub
iaload
istore 4
aload 0
iload 3
ldc 1
isub
aload 0
iload 3
iaload
iastore
aload 0
iload 3
iload 4
iastore
goto Label6
Label5:
Label6:
iload 3
ldc 1
iadd
istore 3
goto Label3
Label4:
iload 2
ldc 1
iadd
istore 2
goto Label1
Label2:
return
.end method

;>> FUNCTION printArray <<
.method static printArray([I)V
.limit stack 32
.limit locals 32
ldc 0
istore 2
Label7:
iload 2
getstatic Main/max I
if_icmpge Label8
getstatic java/lang/System/out Ljava/io/PrintStream;
aload 0
iload 2
iaload
invokevirtual java/io/PrintStream/println(I)V
iload 2
ldc 1
iadd
istore 2
goto Label7
Label8:
return
.end method

;>> FUNCTION readArray <<
.method static readArray([I)V
.limit stack 32
.limit locals 32
ldc 0
istore 4
ldc 0
istore 2
getstatic java/lang/System/out Ljava/io/PrintStream;
getstatic Main/max I
invokevirtual java/io/PrintStream/println(I)V
Label9:
iload 2
getstatic Main/max I
if_icmpge Label10
new java/util/Scanner
dup
getstatic java/lang/System/in Ljava/io/InputStream;
invokenonvirtual java/util/Scanner/<init>(Ljava/io/InputStream;)V
astore 1
aload 1
invokevirtual java/util/Scanner/nextInt()I
istore 4
aload 0
iload 2
iload 4
iastore
iload 2
ldc 1
iadd
istore 2
goto Label9
Label10:
return
.end method

; >> MAIN <<
.method public static main([Ljava/lang/String;)V
.throws java/io/IOException
.limit stack 32
.limit locals 32
ldc 8
newarray int
astore 1
ldc 8
putstatic Main/max I
aload 1
invokestatic Main/readArray([I)V
aload 1
getstatic Main/max I
invokestatic Main/bubbleSort([II)V
aload 1
invokestatic Main/printArray([I)V
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

