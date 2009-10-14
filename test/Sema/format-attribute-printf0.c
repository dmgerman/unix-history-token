begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//RUN: clang-cc -fsyntax-only -verify %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|// same as format(printf(...))...
end_comment

begin_function_decl
name|void
name|a2
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf0
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-error
end_comment

begin_function_decl
name|void
name|b2
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf0
parameter_list|,
function_decl|1
operator|,
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'format' attribute parameter 3 is out of bounds}}
end_comment

begin_function_decl
name|void
name|c2
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf0
parameter_list|,
function_decl|0
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'format' attribute parameter 2 is out of bounds}}
end_comment

begin_function_decl
name|void
name|d2
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf0
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{format attribute requires variadic function}}
end_comment

begin_function_decl
name|void
name|e2
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|int
name|c
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf0
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{format argument not a string type}}
end_comment

begin_comment
comment|// FreeBSD usage
end_comment

begin_define
define|#
directive|define
name|__printf0like
parameter_list|(
name|fmt
parameter_list|,
name|va
parameter_list|)
value|__attribute__((__format__(__printf0__,fmt,va)))
end_define

begin_function_decl
name|void
name|null
parameter_list|(
name|int
name|i
parameter_list|,
specifier|const
name|char
modifier|*
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printf0like
parameter_list|(
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-error
end_comment

begin_function
name|void
name|null
parameter_list|(
name|int
name|i
parameter_list|,
specifier|const
name|char
modifier|*
name|a
parameter_list|,
modifier|...
parameter_list|)
block|{
if|if
condition|(
name|a
condition|)
operator|(
name|void
operator|)
literal|0
comment|/* vprintf(...) would go here */
expr_stmt|;
block|}
end_function

begin_function
name|void
name|callnull
parameter_list|(
name|void
parameter_list|)
block|{
name|null
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// no error
name|null
argument_list|(
literal|0
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no error
name|null
argument_list|(
literal|0
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// no error
name|null
argument_list|(
literal|0
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{incompatible pointer types}}
block|}
end_function

end_unit

