begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Note that this puts the expected lines before the directives to work around
end_comment

begin_comment
comment|// limitations in the -verify mode.
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-warning {{expected identifier in '#pragma weak'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|x
end_pragma

begin_decl_stmt
specifier|extern
name|int
name|z
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-warning {{expected identifier in '#pragma weak'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|z
name|=
name|=
end_pragma

begin_comment
comment|/* expected-warning {{expected identifier in '#pragma weak'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|z
name|=
end_pragma

begin_comment
comment|/* expected-warning {{weak identifier 'y' never declared}} */
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|z
name|=
name|y
end_pragma

begin_decl_stmt
specifier|extern
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expected-warning {{extra tokens at end of '#pragma weak'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|a
name|b
end_pragma

begin_comment
comment|/* expected-warning {{extra tokens at end of '#pragma weak'}}*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|a
name|=
name|x
name|c
end_pragma

begin_function
name|void
name|pragma_is_not_a_statement
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|t
decl_stmt|;
block|{
if|if
condition|(
name|x
condition|)
pragma|#
directive|pragma
name|weak
name|t
else|else
comment|// expected-error {{expected expression}}
pragma|#
directive|pragma
name|weak
name|t
block|}
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|1
case|:
pragma|#
directive|pragma
name|weak
name|t
block|}
comment|// expected-error {{expected statement}}
switch|switch
condition|(
name|x
condition|)
block|{
default|default:
pragma|#
directive|pragma
name|weak
name|t
block|}
comment|// expected-error {{expected statement}}
name|label
label|:
pragma|#
directive|pragma
name|weak
name|t
block|}
end_function

begin_comment
comment|// expected-error {{expected statement}}
end_comment

end_unit

