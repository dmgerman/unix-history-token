begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm %s -o %t
end_comment

begin_function
name|void
name|t1
parameter_list|(
name|int
name|len
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|("" : "=&r"(len), "+&r"(len));
block|}
end_function

begin_function
name|void
name|t2
parameter_list|(
name|unsigned
name|long
name|long
name|t
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|("" : "+m"(t));
block|}
end_function

begin_function
name|void
name|t3
parameter_list|(
name|unsigned
name|char
modifier|*
name|src
parameter_list|,
name|unsigned
name|long
name|long
name|temp
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|("" : "+m"(temp), "+r"(src));
block|}
end_function

begin_function
name|void
name|t4
parameter_list|()
block|{
name|unsigned
name|long
name|long
name|a
decl_stmt|;
struct|struct
name|reg
block|{
name|unsigned
name|long
name|long
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
name|b
struct|;
asm|__asm__
specifier|volatile
asm|("":: "m"(a), "m"(b));
block|}
end_function

begin_comment
comment|// PR3417
end_comment

begin_function
name|void
name|t5
parameter_list|(
name|int
name|i
parameter_list|)
block|{
asm|asm("nop" : "=r"(i) : "0"(t5));
block|}
end_function

begin_comment
comment|// PR3641
end_comment

begin_function
name|void
name|t6
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|("" : : "i" (t6));
block|}
end_function

begin_comment
comment|// RUN: grep "T7 NAMED: \$1" %t
end_comment

begin_function
name|void
name|t7
parameter_list|(
name|int
name|a
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|("T7 NAMED: %[input]" : "+r"(a): [input] "i" (4));
block|}
end_function

begin_comment
comment|// RUN: grep "T8 NAMED MODIFIER: \${0:c}" %t
end_comment

begin_function
name|void
name|t8
parameter_list|()
block|{
asm|__asm__
specifier|volatile
asm|("T8 NAMED MODIFIER: %c[input]" :: [input] "i" (4));
block|}
end_function

begin_comment
comment|// PR3682
end_comment

begin_function
name|unsigned
name|t9
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|)
block|{
asm|asm("bswap %0 %1" : "+r" (a));
return|return
name|a
return|;
block|}
end_function

begin_comment
comment|// PR3908
end_comment

begin_comment
comment|// RUN: grep "PR3908 \$1 \$3 \$2 \$0" %t
end_comment

begin_function
name|void
name|t10
parameter_list|(
name|int
name|r
parameter_list|)
block|{
asm|__asm__("PR3908 %[lf] %[xx] %[li] %[r]" : [r] "+r" (r) : [lf] "mx" (0), [li] "mr" (0), [xx] "x" ((double)(0)));
block|}
end_function

begin_comment
comment|// PR3373
end_comment

begin_function
name|unsigned
name|t11
parameter_list|(
name|signed
name|char
name|input
parameter_list|)
block|{
name|unsigned
name|output
decl_stmt|;
asm|__asm__("xyz"           : "=a" (output)           : "0" (input));
return|return
name|output
return|;
block|}
end_function

begin_comment
comment|// PR3373
end_comment

begin_function
name|unsigned
name|char
name|t12
parameter_list|(
name|unsigned
name|input
parameter_list|)
block|{
name|unsigned
name|char
name|output
decl_stmt|;
asm|__asm__("xyz"           : "=a" (output)           : "0" (input));
return|return
name|output
return|;
block|}
end_function

begin_function
name|unsigned
name|char
name|t13
parameter_list|(
name|unsigned
name|input
parameter_list|)
block|{
name|unsigned
name|char
name|output
decl_stmt|;
asm|__asm__("xyz %1"           : "=a" (output)           : "0" (input));
return|return
name|output
return|;
block|}
end_function

begin_struct
struct|struct
name|large
block|{
name|int
name|x
index|[
literal|1000
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|unsigned
name|long
name|t15
parameter_list|(
name|int
name|x
parameter_list|,
name|struct
name|large
modifier|*
name|P
parameter_list|)
block|{
asm|__asm__("xyz "           : "=r" (x)           : "m" (*P), "0" (x));
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// bitfield destination of an asm.
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
name|a
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|t14
parameter_list|(
name|struct
name|S
modifier|*
name|P
parameter_list|)
block|{
asm|__asm__("abc %0" : "=r"(P->a) );
block|}
end_function

begin_comment
comment|// PR4938
end_comment

begin_function
name|int
name|t16
parameter_list|()
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
asm|asm ( "nop;"        :"=%c" (a)        : "r" (b)        );
return|return
literal|0
return|;
block|}
end_function

end_unit

