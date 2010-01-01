begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -ffreestanding -pedantic -verify %s
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|float
specifier|_Complex
name|c
parameter_list|)
block|{
comment|// expected-warning{{complex numbers are an extension in a freestanding C99 implementation}}
block|}
end_function

end_unit

