begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c++11 -fsyntax-only -verify -x c++ %s
end_comment

begin_comment
comment|// This file is encoded using ISO-8859-1
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
operator|(
name|void
operator|)
literal|'é'
expr_stmt|;
comment|// expected-warning {{illegal character encoding in character literal}}
operator|(
name|void
operator|)
literal|u'
expr|é'
expr_stmt|;
comment|// expected-error {{illegal character encoding in character literal}}
operator|(
name|void
operator|)
literal|U'
expr|é'
expr_stmt|;
comment|// expected-error {{illegal character encoding in character literal}}
operator|(
name|void
operator|)
literal|L'
expr|é'
expr_stmt|;
comment|// expected-error {{illegal character encoding in character literal}}
comment|// For narrow character literals, since there is no error, make sure the
comment|// encoding is correct
name|static_assert
argument_list|(
operator|(
name|unsigned
name|char
operator|)
literal|'é'
operator|==
literal|0xE9
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|// expected-warning {{illegal character encoding in character literal}}
name|static_assert
argument_list|(
literal|'éé'
operator|==
literal|0xE9E9
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|// expected-warning {{illegal character encoding in character literal}} expected-warning {{multi-character character constant}}
block|}
end_function

end_unit

