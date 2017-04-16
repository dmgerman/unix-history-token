begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple avr-unknown-unknown -verify %s
end_comment

begin_decl_stmt
specifier|const
name|unsigned
name|char
name|val
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|foo
parameter_list|()
block|{
asm|__asm__
specifier|volatile
asm|("foo %0, 1" : : "fo" (val));
comment|// expected-error {{invalid input constraint 'fo' in asm}}
asm|__asm__
specifier|volatile
asm|("foo %0, 1" : : "Nd" (val));
comment|// expected-error {{invalid input constraint 'Nd' in asm}}
block|}
end_function

end_unit

