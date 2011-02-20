begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -emit-llvm-only %s
end_comment

begin_comment
comment|// Just verify that we don't crash until we support _Imaginary.
end_comment

begin_decl_stmt
name|double
specifier|_Imaginary
name|foo
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{imaginary types are not supported}}
end_comment

end_unit

