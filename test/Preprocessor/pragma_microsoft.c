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

end_unit

