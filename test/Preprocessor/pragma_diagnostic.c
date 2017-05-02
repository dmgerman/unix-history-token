begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wno-undef %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wno-undef -Wno-unknown-warning-option -DAVOID_UNKNOWN_WARNING %s
end_comment

begin_comment
comment|// rdar://2362963
end_comment

begin_if
if|#
directive|if
name|FOO
end_if

begin_comment
comment|// ok.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|warning
literal|"-Wundef"
end_pragma

begin_if
if|#
directive|if
name|FOO
end_if

begin_comment
comment|// expected-warning {{'FOO' is not defined}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wun"
literal|"def"
end_pragma

begin_if
if|#
directive|if
name|FOO
end_if

begin_comment
comment|// ok.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|error
literal|"-Wundef"
end_pragma

begin_if
if|#
directive|if
name|FOO
end_if

begin_comment
comment|// expected-error {{'FOO' is not defined}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|foo
value|error
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|foo
literal|"-Wundef"
end_pragma

begin_comment
comment|// expected-warning {{pragma diagnostic expected 'error', 'warning', 'ignored', 'fatal', 'push', or 'pop'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|error
name|42
end_pragma

begin_comment
comment|// expected-error {{expected string literal in pragma diagnostic}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|error
literal|"-Wundef"
name|42
end_pragma

begin_comment
comment|// expected-warning {{unexpected token in pragma diagnostic}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|error
literal|"invalid-name"
end_pragma

begin_comment
comment|// expected-warning {{pragma diagnostic expected option name (e.g. "-Wundef")}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|error
literal|"-Winvalid-name"
end_pragma

begin_ifndef
ifndef|#
directive|ifndef
name|AVOID_UNKNOWN_WARNING
end_ifndef

begin_comment
comment|// expected-warning@-2 {{unknown warning group '-Winvalid-name', ignored}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Testing pragma clang diagnostic with -Weverything
end_comment

begin_function
name|void
name|ppo
parameter_list|()
block|{}
end_function

begin_comment
comment|// First test that we do not diagnose on this.
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
name|ppp
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning {{no previous prototype for function 'ppp'}}
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
comment|// Reset it.
end_comment

begin_function
name|void
name|ppq
parameter_list|()
block|{}
end_function

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|error
literal|"-Weverything"
end_pragma

begin_comment
comment|// Now set to error
end_comment

begin_function
name|void
name|ppr
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error {{no previous prototype for function 'ppr'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|warning
literal|"-Weverything"
end_pragma

begin_comment
comment|// This should not be effective
end_comment

begin_function
name|void
name|pps
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error {{no previous prototype for function 'pps'}}
end_comment

end_unit

