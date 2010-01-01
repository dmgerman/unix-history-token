begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %S/attrs.h -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %S/attrs.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-note{{previous overload}}
end_comment

begin_function_decl
name|double
name|f
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{overloadable}}
end_comment

end_unit

