begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7--windows -fms-extensions -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_macro
name|__declspec
argument_list|(
argument|thread
argument_list|)
end_macro

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

end_unit

