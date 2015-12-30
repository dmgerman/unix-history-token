begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -triple x86_64-pc-win32
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|sysv_abi
operator|)
argument_list|)
name|foo
argument_list|(
name|int
name|a
argument_list|,
operator|...
argument_list|)
block|{
name|__builtin_va_list
name|ap
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|ap
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// expected-error {{'va_start' used in System V ABI function}}
block|}
end_decl_stmt

end_unit

