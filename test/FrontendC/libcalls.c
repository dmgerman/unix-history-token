begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// llvm-gcc -O1+ should run simplify libcalls, O0 shouldn't
end_comment

begin_comment
comment|// and -fno-builtins shouldn't.
end_comment

begin_comment
comment|// -fno-math-errno should emit an llvm intrinsic, -fmath-errno should not.
end_comment

begin_comment
comment|// RUN: %llvmgcc %s -S -emit-llvm -fno-math-errno -O0 -o - | grep {call.*exp2\\.f32}
end_comment

begin_comment
comment|// RUN: %llvmgcc %s -S -emit-llvm -fmath-errno -O0 -o - | grep {call.*exp2f}
end_comment

begin_comment
comment|// RUN: %llvmgcc %s -S -emit-llvm -O1 -o - | grep {call.*ldexp}
end_comment

begin_comment
comment|// RUN: %llvmgcc %s -S -emit-llvm -O3 -fno-builtin -o - | grep {call.*exp2f}
end_comment

begin_function_decl
name|float
name|exp2f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|float
name|t4
parameter_list|(
name|unsigned
name|char
name|x
parameter_list|)
block|{
return|return
name|exp2f
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

end_unit

