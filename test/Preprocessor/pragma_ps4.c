begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-scei-ps4 -fsyntax-only -verify -fms-extensions
end_comment

begin_comment
comment|// On PS4, issue a diagnostic that pragma comments are ignored except:
end_comment

begin_comment
comment|//   #pragma comment lib
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|lib
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|lib
name|,
literal|"foo"
name|)
end_pragma

begin_macro
name|__pragma
argument_list|(
argument|comment(lib,
literal|"bar"
argument|)
argument_list|)
end_macro

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|linker
name|)
end_pragma

begin_comment
comment|// expected-warning {{'#pragma comment linker' ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|linker
name|,
literal|"foo"
name|)
end_pragma

begin_comment
comment|// expected-warning {{'#pragma comment linker' ignored}}
end_comment

begin_macro
name|__pragma
argument_list|(
argument|comment(linker,
literal|" bar="
literal|"2"
argument|)
argument_list|)
end_macro

begin_comment
comment|// expected-warning {{'#pragma comment linker' ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|user
name|)
end_pragma

begin_comment
comment|// expected-warning {{'#pragma comment user' ignored}}
end_comment

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

begin_comment
comment|// expected-warning {{'#pragma comment user' ignored}}
end_comment

begin_macro
name|__pragma
argument_list|(
argument|comment(user,
literal|"foo"
argument|)
argument_list|)
end_macro

begin_comment
comment|// expected-warning {{'#pragma comment user' ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|compiler
name|)
end_pragma

begin_comment
comment|// expected-warning {{'#pragma comment compiler' ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|compiler
name|,
literal|"foo"
name|)
end_pragma

begin_comment
comment|// expected-warning {{'#pragma comment compiler' ignored}}
end_comment

begin_macro
name|__pragma
argument_list|(
argument|comment(compiler,
literal|"foo"
argument|)
argument_list|)
end_macro

begin_comment
comment|// expected-warning {{'#pragma comment compiler' ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|exestr
name|)
end_pragma

begin_comment
comment|// expected-warning {{'#pragma comment exestr' ignored}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|comment
name|(
name|exestr
name|,
literal|"foo"
name|)
end_pragma

begin_comment
comment|// expected-warning {{'#pragma comment exestr' ignored}}
end_comment

begin_macro
name|__pragma
argument_list|(
argument|comment(exestr,
literal|"foo"
argument|)
argument_list|)
end_macro

begin_comment
comment|// expected-warning {{'#pragma comment exestr' ignored}}
end_comment

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

begin_macro
name|__pragma
argument_list|(
argument|comment(foo)
argument_list|)
end_macro

begin_comment
comment|// expected-error {{unknown kind of pragma comment}}
end_comment

end_unit

