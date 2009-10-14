begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify %s
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

end_unit

