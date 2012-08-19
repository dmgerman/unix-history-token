begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple armv7-apple-darwin -verify -fsyntax-only
end_comment

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|Val
decl_stmt|;
asm|asm
specifier|volatile
asm|("lw (r1), %0[val]": "=&b"(Val));
comment|// expected-error {{invalid output constraint '=&b' in asm}}
return|return;
block|}
end_function

end_unit

