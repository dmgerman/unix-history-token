begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -fsyntax-only -verify %s
end_comment

begin_function_decl
name|void
name|__both3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_pragma
pragma|#
directive|pragma
name|weak
name|both3
name|=
name|__both3
end_pragma

begin_comment
comment|// expected-note {{previous definition}}
end_comment

begin_function_decl
name|void
name|both3
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"__both3"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{redefinition of 'both3'}}
end_comment

begin_function
name|void
name|__both3
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function_decl
name|void
name|__a3
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(noinline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|weak
name|a3
name|=
name|__a3
end_pragma

begin_comment
comment|// expected-note {{previous definition}}
end_comment

begin_function_decl
name|void
name|a3
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"__a3"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{redefinition of 'a3'}}
end_comment

begin_function
name|void
name|__a3
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

end_unit

