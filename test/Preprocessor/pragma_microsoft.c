begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -fms-extensions
end_comment

begin_comment
comment|// rdar://6495941
end_comment

begin_define
define|#
directive|define
name|FOO
value|1
end_define

begin_define
define|#
directive|define
name|BAR
value|"2"
end_define

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|linker
name|,
literal|"foo="
name|FOO
name|)
end_pragma

begin_comment
comment|// expected-error {{pragma comment requires parenthesized identifier and optional string}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|linker
name|,
literal|" bar="
name|BAR
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|user
name|,
literal|"Compiled on "
name|__DATE__
literal|" at "
name|__TIME__
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|foo
name|)
end_pragma

begin_comment
comment|// expected-error {{unknown kind of pragma comment}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|compiler
name|,
name|)
end_pragma

begin_comment
comment|// expected-error {{expected string literal in pragma comment}}
end_comment

begin_define
define|#
directive|define
name|foo
value|compiler
end_define

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|foo
name|)
end_pragma

begin_comment
comment|// macro expand kind.
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|foo
name|)
name|x
end_pragma

begin_comment
comment|// expected-error {{pragma comment requires}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|user
name|,
literal|"foo\abar\nbaz\tsome	thing"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|detect_mismatch
name|(
literal|"test"
name|,
literal|"1"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|detect_mismatch
name|(
name|)
end_pragma

begin_comment
comment|// expected-error {{expected string literal in pragma detect_mismatch}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|detect_mismatch
name|(
literal|"test"
name|)
end_pragma

begin_comment
comment|// expected-error {{pragma detect_mismatch is malformed; it requires two comma-separated string literals}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|detect_mismatch
name|(
literal|"test"
name|,
name|1
name|)
end_pragma

begin_comment
comment|// expected-error {{expected string literal in pragma detect_mismatch}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|detect_mismatch
name|(
literal|"test"
name|,
name|BAR
name|)
end_pragma

begin_comment
comment|// __pragma
end_comment

begin_macro
name|__pragma
argument_list|(
argument|comment(linker,
literal|" bar="
argument|BAR)
argument_list|)
end_macro

begin_define
define|#
directive|define
name|MACRO_WITH__PRAGMA
value|{ \   __pragma(warning(push)); \   __pragma(warning(disable: 10000)); \   1 + (2> 3) ? 4 : 5; \   __pragma(warning(pop)); \ }
end_define

begin_function
name|void
name|f
parameter_list|()
block|{
name|__pragma
argument_list|()
comment|// If we ever actually *support* __pragma(warning(disable: x)),
comment|// this warning should go away.
name|MACRO_WITH__PRAGMA
comment|// expected-warning {{lower precedence}} \
comment|// expected-note 2 {{place parentheses}}
block|}
end_function

begin_comment
comment|// This should include macro_arg_directive even though the include
end_comment

begin_comment
comment|// is looking for test.h  This allows us to assign to "n"
end_comment

begin_pragma
pragma|#
directive|pragma
name|include_alias
name|(
literal|"test.h"
name|,
literal|"macro_arg_directive.h"
name|)
end_pragma

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_function
name|void
name|test
parameter_list|(
name|void
parameter_list|)
block|{
name|n
operator|=
literal|12
expr_stmt|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|include_alias
name|(
literal|<bar.h>
name|,
literal|"bar.h"
name|)
end_pragma

begin_comment
comment|// expected-warning {{angle-bracketed include<bar.h> cannot be aliased to double-quoted include "bar.h"}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|include_alias
name|(
literal|"foo.h"
name|,
literal|<bar.h>
name|)
end_pragma

begin_comment
comment|// expected-warning {{double-quoted include "foo.h" cannot be aliased to angle-bracketed include<bar.h>}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|include_alias
name|(
literal|"test.h"
name|)
end_pragma

begin_comment
comment|// expected-warning {{pragma include_alias expected ','}}
end_comment

begin_comment
comment|// Make sure that the names match exactly for a replacement, including path information.  If
end_comment

begin_comment
comment|// this were to fail, we would get a file not found error
end_comment

begin_pragma
pragma|#
directive|pragma
name|include_alias
name|(
literal|".\pp-record.h"
name|,
literal|"does_not_exist.h"
name|)
end_pragma

begin_include
include|#
directive|include
file|"pp-record.h"
end_include

begin_pragma
pragma|#
directive|pragma
name|include_alias
name|(
name|12
name|)
end_pragma

begin_comment
comment|// expected-warning {{pragma include_alias expected include filename}}
end_comment

begin_comment
comment|// It's expected that we can map "bar" and<bar> separately
end_comment

begin_define
define|#
directive|define
name|test
end_define

begin_comment
comment|// We can't actually look up stdio.h because we're using cc1 without header paths, but this will ensure
end_comment

begin_comment
comment|// that we get the right bar.h, because the "bar.h" will undef test for us, where<bar.h> won't
end_comment

begin_pragma
pragma|#
directive|pragma
name|include_alias
name|(
literal|<bar.h>
name|,
literal|<stdio.h>
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|include_alias
name|(
literal|"bar.h"
name|,
literal|"pr2086.h"
name|)
end_pragma

begin_comment
comment|// This should #undef test
end_comment

begin_include
include|#
directive|include
file|"bar.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|test
argument_list|)
end_if

begin_comment
comment|// This should not warn because test should not be defined
end_comment

begin_pragma
pragma|#
directive|pragma
name|include_alias
name|(
literal|"test.h"
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Test to make sure there are no use-after-free problems
end_comment

begin_define
define|#
directive|define
name|B
value|"pp-record.h"
end_define

begin_pragma
pragma|#
directive|pragma
name|include_alias
name|(
literal|"quux.h"
name|,
name|B
name|)
end_pragma

begin_function
name|void
name|g
parameter_list|()
block|{}
end_function

begin_include
include|#
directive|include
file|"quux.h"
end_include

begin_comment
comment|// Make sure that empty includes don't work
end_comment

begin_pragma
pragma|#
directive|pragma
name|include_alias
name|(
literal|""
name|,
literal|"foo.h"
name|)
end_pragma

begin_comment
comment|// expected-error {{empty filename}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|include_alias
name|(
literal|<foo.h>
name|,
literal|<>
name|)
end_pragma

begin_comment
comment|// expected-error {{empty filename}}
end_comment

begin_comment
comment|// Test that we ignore pragma warning.
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4705
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|123
name|456
name|789
name|;
name|error
name|:
name|321
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|once
name|:
name|321
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|suppress
name|:
name|321
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|default
name|:
name|321
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|,
name|0
name|)
end_pragma

begin_comment
comment|// FIXME: We could probably support pushing warning level 0.
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
end_pragma

begin_comment
comment|// expected-warning {{expected '('}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
end_pragma

begin_comment
comment|// expected-warning {{expected 'push', 'pop', 'default', 'disable', 'error', 'once', 'suppress', 1, 2, 3, or 4}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|)
end_pragma

begin_comment
comment|// expected-warning {{expected 'push', 'pop', 'default', 'disable', 'error', 'once', 'suppress', 1, 2, 3, or 4}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|4
name|)
end_pragma

begin_comment
comment|// expected-warning {{expected ')'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
end_pragma

begin_comment
comment|// expected-warning {{expected ')'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|,
name|5
name|)
end_pragma

begin_comment
comment|// expected-warning {{requires a level between 0 and 4}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|,
name|1
name|)
end_pragma

begin_comment
comment|// expected-warning {{expected ')'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|,
name|1
name|)
name|asdf
end_pragma

begin_comment
comment|// expected-warning {{extra tokens at end of #pragma warning directive}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|4705
name|)
end_pragma

begin_comment
comment|// expected-warning {{expected ':'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|0
name|)
end_pragma

begin_comment
comment|// expected-warning {{expected a warning number}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|default
name|321
name|)
end_pragma

begin_comment
comment|// expected-warning {{expected ':'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|asdf
name|:
name|321
name|)
end_pragma

begin_comment
comment|// expected-warning {{expected 'push', 'pop'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|,
name|-
name|1
name|)
end_pragma

begin_comment
comment|// expected-warning {{requires a level between 0 and 4}}
end_comment

end_unit

