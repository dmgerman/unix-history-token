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
comment|// RUN: %clang_cc1 %s -emit-llvm -fno-math-errno -o - | grep {call.*exp2\\..*f}
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -fmath-errno -o - | grep {call.*exp2l}
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -O1 -o - | grep {call.*ldexp}
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -O3 -fno-builtin -o - | grep {call.*exp2l}
end_comment

begin_comment
comment|// clang doesn't support this yet.
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// If this fails for you because your target doesn't support long double,
end_comment

begin_comment
comment|// please xfail the test.
end_comment

begin_function_decl
name|long
name|double
name|exp2l
parameter_list|(
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|long
name|double
name|t4
parameter_list|(
name|unsigned
name|char
name|x
parameter_list|)
block|{
return|return
name|exp2l
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

end_unit

