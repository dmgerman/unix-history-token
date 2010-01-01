begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -pedantic -verify
end_comment

begin_comment
comment|// PR4290
end_comment

begin_comment
comment|// The following declaration is compatible with vfprintf, so we shouldn't
end_comment

begin_comment
comment|// warn.
end_comment

begin_function_decl
name|int
name|vfprintf
parameter_list|()
function_decl|;
end_function_decl

end_unit

