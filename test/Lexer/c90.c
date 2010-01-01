begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 -std=c90 -fsyntax-only %s -verify -pedantic-errors  */
end_comment

begin_enum
enum|enum
block|{
name|cast_hex
init|=
operator|(
name|long
operator|)
operator|(
literal|0x0p
operator|-
literal|1
comment|/* expected-error {{hexadecimal floating constants are a C99 feature}} */
operator|)
block|}
enum|;
end_enum

begin_comment
comment|/* PR2477 */
end_comment

begin_function
name|int
name|test1
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|a
comment|//* This is a divide followed by block comment in c89 mode */
name|b
return|;
block|}
end_function

begin_comment
comment|// comment accepted as extension    /* expected-error {{// comments are not allowed in this language}}
end_comment

end_unit

