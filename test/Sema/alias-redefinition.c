begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|f0
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|fun0
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f0"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|f1
parameter_list|()
block|{}
end_function

begin_function
name|void
name|fun1
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-note {{previous definition}}
end_comment

begin_function_decl
name|void
name|fun1
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f1"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{redefinition of 'fun1'}}
end_comment

begin_function
name|void
name|f2
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|fun2
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f2"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{previous definition}}
end_comment

begin_function
name|void
name|fun2
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error {{redefinition of 'fun2'}}
end_comment

begin_function
name|void
name|f3
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|fun3
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f3"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{previous definition}}
end_comment

begin_function_decl
name|void
name|fun3
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f3"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{redefinition of 'fun3'}}
end_comment

begin_function
name|void
name|f4
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|fun4
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"f4"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|fun4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f5
parameter_list|()
block|{}
end_function

begin_decl_stmt
name|void
name|__attribute
argument_list|(
operator|(
name|alias
argument_list|(
literal|"f5"
argument_list|)
operator|)
argument_list|)
name|fun5
argument_list|(
name|void
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// expected-error {{definition 'fun5' cannot also be an alias}}
end_comment

begin_decl_stmt
name|int
name|var1
name|__attribute
argument_list|(
operator|(
name|alias
argument_list|(
literal|"v1"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{definition 'var1' cannot also be an alias}}
end_comment

begin_decl_stmt
specifier|static
name|int
name|var2
name|__attribute
argument_list|(
operator|(
name|alias
argument_list|(
literal|"v2"
argument_list|)
operator|)
argument_list|)
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{definition 'var2' cannot also be an alias}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|var3
name|__attribute__
argument_list|(
operator|(
name|alias
argument_list|(
literal|"C"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_decl_stmt
name|int
name|var3
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition of 'var3'}}
end_comment

begin_decl_stmt
name|int
name|var4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|var4
name|__attribute__
argument_list|(
operator|(
name|alias
argument_list|(
literal|"v4"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{alias definition of 'var4' after tentative definition}}
end_comment

end_unit

