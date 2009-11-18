begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: clang-cc -triple=x86_64-unknown-freebsd7.0 -include %S/va_arg.h %s -emit-llvm -o -
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: clang-cc -triple=x86_64-unknown-freebsd7.0 -emit-pch -o %t %S/va_arg.h
end_comment

begin_comment
comment|// RUN: clang-cc -triple=x86_64-unknown-freebsd7.0 -include-pch %t %s -emit-llvm -o -
end_comment

begin_function
name|char
modifier|*
name|g0
parameter_list|(
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|int
name|argc
parameter_list|)
block|{
return|return
name|argv
index|[
name|argc
index|]
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|g
parameter_list|(
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|f
argument_list|(
name|g0
argument_list|,
name|argv
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

