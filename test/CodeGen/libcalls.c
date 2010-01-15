begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fmath-errno -emit-llvm -o %t %s -triple i386-unknown-unknown
end_comment

begin_comment
comment|// RUN: grep "declare " %t | count 6
end_comment

begin_comment
comment|// RUN: grep "declare " %t | grep "@llvm." | count 1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o %t %s -triple i386-unknown-unknown
end_comment

begin_comment
comment|// RUN: grep "declare " %t | count 6
end_comment

begin_comment
comment|// RUN: grep "declare " %t | grep -v "@llvm." | count 0
end_comment

begin_comment
comment|// IRgen only pays attention to const; it should always call llvm for
end_comment

begin_comment
comment|// this.
end_comment

begin_function_decl
name|float
name|sqrtf
parameter_list|(
name|float
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test_sqrt
parameter_list|(
name|float
name|a0
parameter_list|,
name|double
name|a1
parameter_list|,
name|long
name|double
name|a2
parameter_list|)
block|{
name|float
name|l0
init|=
name|sqrtf
argument_list|(
name|a0
argument_list|)
decl_stmt|;
name|double
name|l1
init|=
name|sqrt
argument_list|(
name|a1
argument_list|)
decl_stmt|;
name|long
name|double
name|l2
init|=
name|sqrtl
argument_list|(
name|a2
argument_list|)
decl_stmt|;
block|}
end_function

begin_function
name|void
name|test_pow
parameter_list|(
name|float
name|a0
parameter_list|,
name|double
name|a1
parameter_list|,
name|long
name|double
name|a2
parameter_list|)
block|{
name|float
name|l0
init|=
name|powf
argument_list|(
name|a0
argument_list|,
name|a0
argument_list|)
decl_stmt|;
name|double
name|l1
init|=
name|pow
argument_list|(
name|a1
argument_list|,
name|a1
argument_list|)
decl_stmt|;
name|long
name|double
name|l2
init|=
name|powl
argument_list|(
name|a2
argument_list|,
name|a2
argument_list|)
decl_stmt|;
block|}
end_function

end_unit

