begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1  -fsyntax-only -verify %s
end_comment

begin_define
define|#
directive|define
name|NULL
value|(void*)0
end_define

begin_define
define|#
directive|define
name|ATTR
value|__attribute__ ((__sentinel__))
end_define

begin_decl_stmt
name|void
name|foo1
argument_list|(
name|int
name|x
argument_list|,
operator|...
argument_list|)
name|ATTR
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note 2 {{function has been explicitly marked sentinel here}}
end_comment

begin_function_decl
name|void
name|foo5
parameter_list|(
name|int
name|x
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__sentinel__
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{function has been explicitly marked sentinel here}}
end_comment

begin_function_decl
name|void
name|foo6
parameter_list|(
name|int
name|x
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__sentinel__
parameter_list|(
function_decl|5
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{function has been explicitly marked sentinel here}}
end_comment

begin_function_decl
name|void
name|foo7
parameter_list|(
name|int
name|x
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__sentinel__
parameter_list|(
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{function has been explicitly marked sentinel here}}
end_comment

begin_function_decl
name|void
name|foo10
parameter_list|(
name|int
name|x
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

begin_decl_stmt
name|void
name|foo12
argument_list|(
name|int
name|x
argument_list|,
operator|...
argument_list|)
name|ATTR
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{function has been explicitly marked sentinel here}}
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
name|foo1
argument_list|(
literal|1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// OK
name|foo1
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{missing sentinel in function call}}
name|foo5
argument_list|(
literal|1
argument_list|,
name|NULL
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// OK
name|foo5
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|NULL
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// OK
name|foo5
argument_list|(
literal|1
argument_list|,
name|NULL
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning {{missing sentinel in function call}}
name|foo6
argument_list|(
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
comment|// expected-warning {{missing sentinel in function call}}
name|foo6
argument_list|(
literal|1
argument_list|,
name|NULL
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
comment|// OK
name|foo7
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning {{not enough variable arguments in 'foo7' declaration to fit a sentinel}}
name|foo7
argument_list|(
literal|1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// OK
name|foo12
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning {{not enough variable arguments in 'foo12' declaration to fit a sentinel}}
comment|// PR 5685
struct|struct
name|A
block|{}
struct|;
name|struct
name|A
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
name|foo1
argument_list|(
literal|3
argument_list|,
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
operator|&
name|c
argument_list|)
expr_stmt|;
comment|// expected-warning {{missing sentinel in function call}}
name|foo1
argument_list|(
literal|3
argument_list|,
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
operator|&
name|c
argument_list|,
operator|(
expr|struct
name|A
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
function_decl|(
modifier|*
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
name|void
name|test2
parameter_list|()
block|{
name|void
function_decl|(
modifier|*
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
block|)
end_function

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{function has been explicitly marked sentinel here}}
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
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

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{function has been explicitly marked sentinel here}}
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
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

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{function has been explicitly marked sentinel here}}
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
comment|// expected-warning {{missing sentinel in function call}}
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
comment|// expected-warning {{missing sentinel in function call}}
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
comment|// expected-warning {{missing sentinel in function call}}
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

