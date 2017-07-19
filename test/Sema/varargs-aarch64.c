begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -triple aarch64-linux-gnu
end_comment

begin_function
name|void
name|f1
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
block|{
name|__builtin_ms_va_list
name|ap
decl_stmt|;
name|__builtin_ms_va_start
argument_list|(
name|ap
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// expected-error {{'__builtin_ms_va_start' used in System V ABI function}}
block|}
end_function

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|ms_abi
operator|)
argument_list|)
name|f2
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
comment|// expected-error {{'va_start' used in Win64 ABI function}}
block|}
end_decl_stmt

end_unit

