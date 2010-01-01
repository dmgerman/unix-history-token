begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wno-undef %s
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
comment|// expected-warning {{pragma diagnostic expected 'error', 'warning', 'ignored', or 'fatal'}}
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
comment|// expected-warning {{unexpected token in pragma diagnostic}}
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

begin_comment
comment|// expected-warning {{unknown warning group '-Winvalid-name', ignored}}
end_comment

end_unit

