begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -fdiagnostics-show-option -Werror -Weverything %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_function_decl
name|int
name|f0
parameter_list|(
name|int
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|f0
parameter_list|(
name|int
name|x
parameter_list|,
name|unsigned
name|y
parameter_list|)
block|{
comment|// CHECK: comparison of integers of different signs{{.*}} [-Werror,-Wsign-compare]
return|return
name|x
operator|<
name|y
return|;
comment|// expected-error {{ : 'int' and 'unsigned int'  }}
block|}
end_function

end_unit

