begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -fblocks
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

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
comment|// expected-warning{{format specifies type 'char *' but the argument has type 'int'}}
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
comment|// no-warning
end_comment

begin_macro
unit|}  void
name|multi_attr
argument_list|(
argument|va_list ap
argument_list|,
argument|int *x
argument_list|,
argument|long *y
argument_list|)
end_macro

begin_block
block|{
comment|// Handle block with multiple format attributes.
name|void
function_decl|(
modifier|^
name|vprintf_scanf
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|,
specifier|const
name|char
modifier|*
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
function_decl|0
block|)
end_block

begin_expr_stmt
unit|))
name|__attribute__
argument_list|(
operator|(
name|__format__
argument_list|(
name|__scanf__
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
operator|)
argument_list|)
operator|=
operator|^
name|__attribute__
argument_list|(
argument|(__format__(__printf__,
literal|1
argument|,
literal|0
argument|))
argument_list|)
name|__attribute__
argument_list|(
argument|(__format__(__scanf__,
literal|3
argument|,
literal|4
argument|))
argument_list|)
operator|(
specifier|const
name|char
operator|*
name|str
operator|,
name|va_list
name|args
operator|,
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|vprintf_scanf
argument_list|(
literal|"%"
argument_list|,
name|ap
argument_list|,
literal|"%d"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{incomplete format specifier}}, expected-warning {{more '%' conversions than data arguments}}
end_comment

unit|}
end_unit

