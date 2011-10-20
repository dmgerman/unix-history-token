begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %S/Inputs/chain-ext_vector1.h -include %S/Inputs/chain-ext_vector2.h -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t1 %S/Inputs/chain-ext_vector1.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t2 %S/Inputs/chain-ext_vector2.h -include-pch %t1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t2 -fsyntax-only -verify %s
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

