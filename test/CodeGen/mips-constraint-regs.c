begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -ccc-clang-archs mipsel -S -o - -emit-llvm %s
end_comment

begin_comment
comment|// This checks that the frontend will accept inline asm constraints
end_comment

begin_comment
comment|// c', 'l' and 'x'. Semantic checking will happen in the
end_comment

begin_comment
comment|// llvm backend. Any bad constraint letters will cause the frontend to
end_comment

begin_comment
comment|// error out.
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// 'c': 16 bit address register for Mips16, GPR for all others
comment|// I am using 'c' to constrain both the target and one of the source
comment|// registers. We are looking for syntactical correctness.
name|int
name|__s
decl_stmt|,
name|__v
init|=
literal|17
decl_stmt|;
name|int
name|__t
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(       "addi %0,%1,%2 \n\t\t"       : "=c" (__t)         : "c" (__s), "I" (__v));
comment|// 'l': lo register
comment|// We are making it clear that destination register is lo with the
comment|// use of the 'l' constraint ("=l").
name|int
name|i_temp
init|=
literal|44
decl_stmt|;
name|int
name|i_result
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(       "mtlo %1 \n\t\t"       : "=l" (i_result)         : "r" (i_temp)           : "lo");
comment|// 'x': Combined lo/hi registers
comment|// We are specifying that destination registers are the hi/lo pair with the
comment|// use of the 'x' constraint ("=x").
name|int
name|i_hi
init|=
literal|3
decl_stmt|;
name|int
name|i_lo
init|=
literal|2
decl_stmt|;
name|long
name|long
name|ll_result
init|=
literal|0
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(       "mthi %1 \n\t\t"       "mtlo %2 \n\t\t"       : "=x" (ll_result)         : "r" (i_hi), "r" (i_lo)           : );
return|return
literal|0
return|;
block|}
end_function

end_unit

