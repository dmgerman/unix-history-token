begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -fms-extensions -verify %s
end_comment

begin_function
name|void
name|emit_error
parameter_list|(
name|unsigned
name|int
name|opcode
parameter_list|)
block|{
name|__emit
argument_list|(
name|opcode
argument_list|)
expr_stmt|;
comment|// expected-error {{argument to '__emit' must be a constant integer}}
block|}
end_function

end_unit

