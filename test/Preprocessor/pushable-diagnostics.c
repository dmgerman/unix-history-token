begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -pedantic %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

begin_comment
comment|// expected-warning{{pragma diagnostic pop could not pop, no matching push}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|puhs
end_pragma

begin_comment
comment|// expected-warning{{pragma diagnostic expected 'error', 'warning', 'ignored', 'fatal' 'push', or 'pop'}}
end_comment

begin_decl_stmt
name|char
name|a
init|=
literal|'df'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{multi-character character constant}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wmultichar"
end_pragma

begin_decl_stmt
name|char
name|b
init|=
literal|'df'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no warning.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

begin_decl_stmt
name|char
name|c
init|=
literal|'df'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{multi-character character constant}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

begin_comment
comment|// expected-warning{{pragma diagnostic pop could not pop, no matching push}}
end_comment

end_unit

