begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// clang -target mipsel-linux-gnu -shared -fPIC -lc dynamic-table.c \
end_comment

begin_comment
comment|//       -o dynamic-table.mips
end_comment

begin_function_decl
name|int
name|puts
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|puts
argument_list|(
literal|"Hello, World"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

