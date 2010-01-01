begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -triple i686-pc-linux-gnu
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|percentm
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%m"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

