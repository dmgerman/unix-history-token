begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-darwin9 -emit-llvm -w -o - %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|long
name|long
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_t
typedef|;
end_typedef

begin_function
name|int64_t
name|foo
parameter_list|(
name|int64_t
name|v
parameter_list|,
specifier|volatile
name|int64_t
modifier|*
name|p
parameter_list|)
block|{
specifier|register
name|uint32_t
name|rl
name|asm
argument_list|(
literal|"r1"
argument_list|)
decl_stmt|;
specifier|register
name|uint32_t
name|rh
name|asm
argument_list|(
literal|"r2"
argument_list|)
decl_stmt|;
name|int64_t
name|r
decl_stmt|;
name|uint32_t
name|t
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(							\ 		       "ldrexd%[_rl], %[_rh], [%[_p]]"			\ 		       : [_rl] "=&r" (rl), [_rh] "=&r" (rh)		\ 		       : [_p] "p" (p) : "memory");
comment|// CHECK: call { i32, i32 } asm sideeffect "ldrexd$0, $1, [$2]", "={r1},={r2},r,~{memory}"(i64*
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// Make sure we translate register names properly.
end_comment

begin_function
name|void
name|bar
parameter_list|(
name|void
parameter_list|)
block|{
specifier|register
name|unsigned
name|int
name|rn
name|asm
argument_list|(
literal|"r14"
argument_list|)
decl_stmt|;
specifier|register
name|unsigned
name|int
name|d
name|asm
argument_list|(
literal|"r2"
argument_list|)
decl_stmt|;
comment|// CHECK: call i32 asm sideeffect "sub $1, $1, #32", "={r2},{lr}"
asm|asm
specifier|volatile
asm|("sub %1, %1, #32" : "=r"(d) : "r"(rn));
block|}
end_function

end_unit

