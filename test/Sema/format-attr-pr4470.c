begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify -Wformat=2 %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function_decl
name|int
name|vprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|foo
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format_arg
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
operator|)
argument_list|)
name|foo2
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
name|va_list
name|va
argument_list|)
block|{
name|vprintf
argument_list|(
name|foo
argument_list|(
name|fmt
argument_list|)
argument_list|,
name|va
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

end_unit

