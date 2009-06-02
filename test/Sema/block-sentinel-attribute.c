begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fblocks -fsyntax-only -verify %s
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|e
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
function_decl|(__sentinel__
parameter_list|(
function_decl|1
operator|,
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|void
function_decl|(
modifier|^
name|bbad
function_decl|)
parameter_list|(
name|int
name|arg
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__sentinel__
block|)
end_function

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{sentinel' attribute only supported for variadic blocks}}
end_comment

begin_function_decl
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
function_decl|(__sentinel__
end_function_decl

begin_expr_stmt
unit|))
operator|=
comment|// expected-note {{block has been explicitly marked sentinel here}}
lambda|^
name|__attribute__
parameter_list|(
lambda|(__sentinel__
end_expr_stmt

begin_expr_stmt
unit|))
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
function_decl|(__sentinel__
parameter_list|(
function_decl|2
end_function_decl

begin_expr_stmt
unit|)))
operator|=
lambda|^
name|__attribute__
parameter_list|(
lambda|(__sentinel__
parameter_list|(
lambda|2
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
comment|// expected-note {{block has been explicitly marked sentinel here}}
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|y
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
function_decl|(__sentinel__
parameter_list|(
function_decl|5
end_function_decl

begin_expr_stmt
unit|)))
operator|=
lambda|^
name|__attribute__
parameter_list|(
lambda|(__sentinel__
parameter_list|(
lambda|5
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
comment|// expected-note {{block has been explicitly marked sentinel here}}
end_comment

begin_expr_stmt
name|b
argument_list|(
literal|1
argument_list|,
literal|"%s"
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// OK
end_comment

begin_expr_stmt
name|b
argument_list|(
literal|1
argument_list|,
literal|"%s"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{missing sentinel in block call}}
end_comment

begin_expr_stmt
name|z
argument_list|(
literal|1
argument_list|,
literal|"%s"
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{missing sentinel in block call}}
end_comment

begin_expr_stmt
name|z
argument_list|(
literal|1
argument_list|,
literal|"%s"
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// OK
end_comment

begin_expr_stmt
name|y
argument_list|(
literal|1
argument_list|,
literal|"%s"
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{missing sentinel in block call}}
end_comment

begin_expr_stmt
name|y
argument_list|(
literal|1
argument_list|,
literal|"%s"
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// OK
end_comment

unit|}
end_unit

