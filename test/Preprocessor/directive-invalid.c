begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -verify %s
end_comment

begin_comment
comment|// rdar://7683173
end_comment

begin_define
define|#
directive|define
name|r_paren
value|)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
argument|x r_paren
comment|// expected-error {{missing ')' after 'defined'}} \
comment|// expected-note {{to match this '('}}
argument|#endif
end_if

end_unit

