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
comment|// expected-error {{pragma comment requires}}
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
value|{ \   __pragma(warning(push)); \   __pragma(warning(disable: 10000)); \   2+2; \   __pragma(warning(pop)); \ }
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
comment|// expected-warning {{expression result unused}}
block|}
end_function

end_unit

