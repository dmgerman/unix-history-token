begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-win32 -fdeclspec -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-mingw32 -verify %s
end_comment

begin_extern
extern|extern __declspec(selectany
end_extern

begin_decl_stmt
unit|)
specifier|const
name|int
name|x1
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no warning, const means we need extern in C++
end_comment

begin_comment
comment|// Should we really warn on this?
end_comment

begin_extern
extern|extern __declspec(selectany
end_extern

begin_decl_stmt
unit|)
name|int
name|x2
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'extern' variable has an initializer}}
end_comment

begin_macro
name|__declspec
argument_list|(
argument|selectany
argument_list|)
end_macro

begin_function
name|void
name|foo
parameter_list|()
block|{ }
end_function

begin_comment
comment|// expected-error{{'selectany' can only be applied to data items with external linkage}}
end_comment

end_unit

