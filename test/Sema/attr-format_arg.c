begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|f
parameter_list|(
specifier|const
name|char
modifier|*
name|s
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

begin_function
name|void
name|g
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%d"
argument_list|,
literal|123
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d %d"
argument_list|,
literal|123
argument_list|)
expr_stmt|;
comment|// expected-warning{{more '%' conversions than data arguments}}
name|printf
argument_list|(
name|f
argument_list|(
literal|"%d"
argument_list|)
argument_list|,
literal|123
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|f
argument_list|(
literal|"%d %d"
argument_list|)
argument_list|,
literal|123
argument_list|)
expr_stmt|;
comment|// expected-warning{{more '%' conversions than data arguments}}
block|}
end_function

end_unit

