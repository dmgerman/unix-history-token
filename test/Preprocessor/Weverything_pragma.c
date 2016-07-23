begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Weverything   -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test that the pragma overrides command line option -Weverythings,
end_comment

begin_comment
comment|// a diagnostic with DefaultIgnore. This is part of a group 'unused-macro'
end_comment

begin_comment
comment|// but -Weverything forces it
end_comment

begin_define
define|#
directive|define
name|UNUSED_MACRO1
value|1
end_define

begin_comment
comment|// expected-warning{{macro is not used}}
end_comment

begin_function
name|void
name|foo
parameter_list|()
comment|// expected-warning {{no previous prototype for function}}
block|{
comment|// A diagnostic without DefaultIgnore, and not part of a group.
operator|(
name|void
operator|)
literal|L'
expr|ab'
expr_stmt|;
comment|// expected-warning {{extraneous characters in character constant ignored}}
pragma|#
directive|pragma
name|clang
name|diagnostic
name|warning
literal|"-Weverything"
comment|// Should not change anyhting.
define|#
directive|define
name|UNUSED_MACRO2
value|1
comment|// expected-warning{{macro is not used}}
operator|(
name|void
operator|)
literal|L'
expr|cd'
expr_stmt|;
comment|// expected-warning {{extraneous characters in character constant ignored}}
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Weverything"
comment|// Ignore warnings now.
define|#
directive|define
name|UNUSED_MACRO2
value|1
comment|// no warning
operator|(
name|void
operator|)
literal|L'
expr|ef'
expr_stmt|;
comment|// no warning here
pragma|#
directive|pragma
name|clang
name|diagnostic
name|warning
literal|"-Weverything"
comment|// Revert back to warnings.
define|#
directive|define
name|UNUSED_MACRO3
value|1
comment|// expected-warning{{macro is not used}}
operator|(
name|void
operator|)
literal|L'
expr|gh'
expr_stmt|;
comment|// expected-warning {{extraneous characters in character constant ignored}}
pragma|#
directive|pragma
name|clang
name|diagnostic
name|error
literal|"-Weverything"
comment|// Give errors now.
define|#
directive|define
name|UNUSED_MACRO4
value|1
comment|// expected-error{{macro is not used}}
operator|(
name|void
operator|)
literal|L'
expr|ij'
expr_stmt|;
comment|// expected-error {{extraneous characters in character constant ignored}}
block|}
end_function

end_unit

