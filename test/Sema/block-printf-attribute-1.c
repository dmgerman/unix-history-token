begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -fblocks
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|void
function_decl|(
modifier|^
name|b
function_decl|)
parameter_list|(
name|int
name|arg
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|3
block|)
end_function

begin_expr_stmt
unit|))
operator|=
comment|// expected-error {{format argument not a string type}}
lambda|^
name|__attribute__
parameter_list|(
lambda|(__format__
parameter_list|(
name|__printf__
parameter_list|,
lambda|1
operator|,
literal|3
end_expr_stmt

begin_expr_stmt
unit|)))
operator|(
name|int
name|arg
operator|,
specifier|const
name|char
operator|*
name|format
operator|,
operator|...
operator|)
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{format argument not a string type}}
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|z
function_decl|)
parameter_list|(
name|int
name|arg
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_expr_stmt
unit|)))
operator|=
lambda|^
name|__attribute__
parameter_list|(
lambda|(__format__
parameter_list|(
name|__printf__
parameter_list|,
lambda|2
operator|,
literal|3
end_expr_stmt

begin_expr_stmt
unit|)))
operator|(
name|int
name|arg
operator|,
specifier|const
name|char
operator|*
name|format
operator|,
operator|...
operator|)
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// FIXME: argument type poking not yet supportted.
end_comment

begin_expr_stmt
name|z
argument_list|(
literal|1
argument_list|,
literal|"%s"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* { dg-warning "format \\'\%s\\' expects type \\'char \\*\\'\, but argument 3 has type \\'int\\'" } */
end_comment

begin_expr_stmt
name|z
argument_list|(
literal|1
argument_list|,
literal|"%s"
argument_list|,
literal|"HELLO"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// OK
end_comment

unit|}
end_unit

