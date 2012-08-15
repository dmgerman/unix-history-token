begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple nvptx-unknown-unknown -O3 -S -o - %s -emit-llvm | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx64-unknown-unknown -O3 -S -o - %s -emit-llvm | FileCheck %s
end_comment

begin_function
name|int
name|bar
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|int
name|result
decl_stmt|;
comment|// CHECK: call i32 asm sideeffect "{ {{.*}}
asm|asm
specifier|__volatile__
asm|("{ \n\t"                     ".reg .pred \t%%p1; \n\t"                     ".reg .pred \t%%p2; \n\t"                     "setp.ne.u32 \t%%p1, %1, 0; \n\t"                     "vote.any.pred \t%%p2, %%p1; \n\t"                     "selp.s32 \t%0, 1, 0, %%p2; \n\t"                     "}" : "=r"(result) : "r"(a));
return|return
name|result
return|;
block|}
end_function

end_unit

