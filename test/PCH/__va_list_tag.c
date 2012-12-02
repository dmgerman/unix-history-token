begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// PR13189
end_comment

begin_comment
comment|// rdar://problem/11741429
end_comment

begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple=x86_64-unknown-freebsd7.0 -include %S/Inputs/__va_list_tag.h %s -emit-llvm -o -
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple=x86_64-unknown-freebsd7.0 -emit-pch -x c-header -o %t %S/Inputs/__va_list_tag.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple=x86_64-unknown-freebsd7.0 -include-pch %t %s -verify
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|int
name|myvprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|args
parameter_list|)
block|{
return|return
name|myvfprintf
argument_list|(
name|fmt
argument_list|,
name|args
argument_list|)
return|;
block|}
end_function

end_unit

