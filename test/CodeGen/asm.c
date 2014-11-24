begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// PR10415
end_comment

begin_asm
asm|__asm__ ("foo1");
end_asm

begin_asm
asm|__asm__ ("foo2");
end_asm

begin_asm
asm|__asm__ ("foo3");
end_asm

begin_comment
comment|// CHECK: module asm "foo1"
end_comment

begin_comment
comment|// CHECK-NEXT: module asm "foo2"
end_comment

begin_comment
comment|// CHECK-NEXT: module asm "foo3"
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
comment|// CHECK: @t7(i32
comment|// CHECK: T7 NAMED: $1
block|}
end_function

begin_function
name|void
name|t8
parameter_list|()
block|{
asm|__asm__
specifier|volatile
asm|("T8 NAMED MODIFIER: %c[input]" :: [input] "i" (4));
comment|// CHECK: @t8()
comment|// CHECK: T8 NAMED MODIFIER: ${0:c}
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

begin_function
name|void
name|t10
parameter_list|(
name|int
name|r
parameter_list|)
block|{
asm|__asm__("PR3908 %[lf] %[xx] %[li] %[r]" : [r] "+r" (r) : [lf] "mx" (0), [li] "mr" (0), [xx] "x" ((double)(0)));
comment|// CHECK: @t10(
comment|// CHECK:PR3908 $1 $3 $2 $0
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

begin_comment
comment|// PR6475
end_comment

begin_function
name|void
name|t17
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
asm|__asm__ ( "nop": "=m"(i));
comment|// CHECK: @t17()
comment|// CHECK: call void asm "nop", "=*m,
block|}
end_function

begin_comment
comment|//<rdar://problem/6841383>
end_comment

begin_function
name|int
name|t18
parameter_list|(
name|unsigned
name|data
parameter_list|)
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
asm|asm("xyz" :"=a"(a), "=d"(b) : "a"(data));
return|return
name|a
operator|+
name|b
return|;
comment|// CHECK: t18(i32
comment|// CHECK: = call {{.*}}asm "xyz"
comment|// CHECK-NEXT: extractvalue
comment|// CHECK-NEXT: extractvalue
block|}
end_function

begin_comment
comment|// PR6780
end_comment

begin_function
name|int
name|t19
parameter_list|(
name|unsigned
name|data
parameter_list|)
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
asm|asm("x{abc|def|ghi}z" :"=r"(a): "r"(data));
return|return
name|a
operator|+
name|b
return|;
comment|// CHECK: t19(i32
comment|// CHECK: = call {{.*}}asm "x$(abc$|def$|ghi$)z"
block|}
end_function

begin_comment
comment|// PR6845 - Mismatching source/dest fp types.
end_comment

begin_function
name|double
name|t20
parameter_list|(
name|double
name|x
parameter_list|)
block|{
specifier|register
name|long
name|double
name|result
decl_stmt|;
asm|__asm __volatile ("frndint"  : "=t" (result) : "0" (x));
return|return
name|result
return|;
comment|// CHECK: @t20
comment|// CHECK: fpext double {{.*}} to x86_fp80
comment|// CHECK-NEXT: call x86_fp80 asm sideeffect "frndint"
comment|// CHECK: fptrunc x86_fp80 {{.*}} to double
block|}
end_function

begin_function
name|float
name|t21
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
specifier|register
name|float
name|result
decl_stmt|;
asm|__asm __volatile ("frndint"  : "=t" (result) : "0" (x));
return|return
name|result
return|;
comment|// CHECK: @t21
comment|// CHECK: call x86_fp80 asm sideeffect "frndint"
comment|// CHECK-NEXT: fptrunc x86_fp80 {{.*}} to float
block|}
end_function

begin_comment
comment|//<rdar://problem/8348447> - accept 'l' constraint
end_comment

begin_function
name|unsigned
name|char
name|t22
parameter_list|(
name|unsigned
name|char
name|a
parameter_list|,
name|unsigned
name|char
name|b
parameter_list|)
block|{
name|unsigned
name|int
name|la
init|=
name|a
decl_stmt|;
name|unsigned
name|int
name|lb
init|=
name|b
decl_stmt|;
name|unsigned
name|int
name|bigres
decl_stmt|;
name|unsigned
name|char
name|res
decl_stmt|;
asm|__asm__ ("0:\n1:\n" : [bigres] "=la"(bigres) : [la] "0"(la), [lb] "c"(lb) :                         "edx", "cc");
name|res
operator|=
name|bigres
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_comment
comment|//<rdar://problem/8348447> - accept 'l' constraint
end_comment

begin_function
name|unsigned
name|char
name|t23
parameter_list|(
name|unsigned
name|char
name|a
parameter_list|,
name|unsigned
name|char
name|b
parameter_list|)
block|{
name|unsigned
name|int
name|la
init|=
name|a
decl_stmt|;
name|unsigned
name|int
name|lb
init|=
name|b
decl_stmt|;
name|unsigned
name|char
name|res
decl_stmt|;
asm|__asm__ ("0:\n1:\n" : [res] "=la"(res) : [la] "0"(la), [lb] "c"(lb) :                         "edx", "cc");
return|return
name|res
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|t24
parameter_list|(
name|char
name|c
parameter_list|)
block|{
name|void
modifier|*
name|addr
decl_stmt|;
comment|// CHECK: @t24
comment|// CHECK: zext i8 {{.*}} to i32
comment|// CHECK-NEXT: call i8* asm "foobar"
asm|__asm__ ("foobar" : "=a" (addr) : "0" (c));
return|return
name|addr
return|;
block|}
end_function

begin_comment
comment|// PR10299 - fpsr, fpcr
end_comment

begin_function
name|void
name|t25
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(					   \ 		       "finit"				   \ 		       :				   \ 		       :				   \ 		       :"st","st(1)","st(2)","st(3)",	   \ 			"st(4)","st(5)","st(6)","st(7)",   \ 			"fpsr","fpcr"			   \ 							   );
block|}
end_function

begin_comment
comment|// rdar://10510405 - AVX registers
end_comment

begin_typedef
typedef|typedef
name|long
name|long
name|__m256i
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_function
name|void
name|t26
parameter_list|(
name|__m256i
modifier|*
name|p
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|("vmovaps  %0, %%ymm0" :: "m" (*(__m256i*)p) : "ymm0");
block|}
end_function

begin_comment
comment|// Check to make sure the inline asm non-standard dialect attribute _not_ is
end_comment

begin_comment
comment|// emitted.
end_comment

begin_function
name|void
name|t27
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("nop");
comment|// CHECK: @t27
comment|// CHECK: call void asm sideeffect "nop"
comment|// CHECK-NOT: ia_nsdialect
comment|// CHECK: ret void
block|}
end_function

begin_comment
comment|// Check handling of '*' and '#' constraint modifiers.
end_comment

begin_function
name|void
name|t28
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("/* %0 */" : : "i#*X,*r" (1));
comment|// CHECK: @t28
comment|// CHECK: call void asm sideeffect "/* $0 */", "i|r,~{dirflag},~{fpsr},~{flags}"(i32 1)
block|}
end_function

begin_decl_stmt
specifier|static
name|unsigned
name|t29_var
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|t29
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("movl %%eax, %0"                :                : "m"(t29_var));
comment|// CHECK: @t29
comment|// CHECK: call void asm sideeffect "movl %eax, $0", "*m,~{dirflag},~{fpsr},~{flags}"([1 x i32]* @t29_var)
block|}
end_function

end_unit

