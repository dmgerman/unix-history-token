begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %S/ext_vector.h -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %S/ext_vector.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t -fsyntax-only -verify %s
end_comment

begin_function
name|int
name|test
parameter_list|(
name|float4
name|f4
parameter_list|)
block|{
return|return
name|f4
operator|.
name|xy
return|;
comment|// expected-error{{float2}}
block|}
end_function

end_unit

