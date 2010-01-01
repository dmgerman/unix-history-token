begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fheinous-gnu-extensions
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|a
decl_stmt|;
comment|// PR3788
asm|asm("nop" : : "m"((int)(a)));
comment|// expected-warning {{cast in a inline asm context requiring an l-value}}
comment|// PR3794
asm|asm("nop" : "=r"((unsigned)a));
comment|// expected-warning {{cast in a inline asm context requiring an l-value}}
block|}
end_function

end_unit

