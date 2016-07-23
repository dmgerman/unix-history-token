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
comment|// expected-warning {{pragma diagnostic expected 'error', 'warning', 'ignored', 'fatal', 'push', or 'pop'}}
end_comment

begin_decl_stmt
name|int
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
name|int
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
name|int
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

begin_comment
comment|// Test -Weverything
end_comment

begin_function
name|void
name|ppo0
parameter_list|()
block|{}
end_function

begin_comment
comment|// first verify that we do not give anything on this
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
end_pragma

begin_comment
comment|// now push
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|warning
literal|"-Weverything"
end_pragma

begin_function
name|void
name|ppr1
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning {{no previous prototype for function 'ppr1'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
end_pragma

begin_comment
comment|// push again
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Weverything"
end_pragma

begin_comment
comment|// Set to ignore in this level.
end_comment

begin_function
name|void
name|pps2
parameter_list|()
block|{}
end_function

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|warning
literal|"-Weverything"
end_pragma

begin_comment
comment|// Set to warning in this level.
end_comment

begin_function
name|void
name|ppt2
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning {{no previous prototype for function 'ppt2'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|error
literal|"-Weverything"
end_pragma

begin_comment
comment|// Set to error in this level.
end_comment

begin_function
name|void
name|ppt3
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error {{no previous prototype for function 'ppt3'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

begin_comment
comment|// pop should go back to warning level
end_comment

begin_function
name|void
name|pps1
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning {{no previous prototype for function 'pps1'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
end_pragma

begin_comment
comment|// Another pop should disble it again
end_comment

begin_function
name|void
name|ppu
parameter_list|()
block|{}
end_function

end_unit

