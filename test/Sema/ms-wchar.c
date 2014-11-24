begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -fms-extensions -triple i386-pc-win32 %s
end_comment

begin_comment
comment|// C++ mode with -fno-wchar works the same as C mode for wchar_t.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -fno-wchar -fsyntax-only -verify -fms-extensions -triple i386-pc-win32 %s
end_comment

begin_function_decl
name|wchar_t
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{unknown type name 'wchar_t'}}
end_comment

begin_comment
comment|// __wchar_t is available as an MS extension.
end_comment

begin_decl_stmt
name|__wchar_t
name|g
init|=
literal|L'
expr|a'
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous}}
end_comment

begin_comment
comment|// __wchar_t is a distinct type, separate from the target's integer type for wide chars.
end_comment

begin_decl_stmt
name|unsigned
name|short
name|g
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition of 'g' with a different type: 'unsigned short' vs '__wchar_t'}}
end_comment

begin_comment
comment|// The type of a wide string literal is actually not __wchar_t.
end_comment

begin_decl_stmt
name|__wchar_t
name|s
index|[]
init|=
literal|L"Hello world!"
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error-re {{array initializer must be an initializer list{{$}}}}
end_comment

begin_comment
comment|// Do not suggest initializing with a string here, because it would not work.
end_comment

begin_decl_stmt
name|__wchar_t
name|t
index|[]
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error-re {{array initializer must be an initializer list{{$}}}}
end_comment

end_unit

