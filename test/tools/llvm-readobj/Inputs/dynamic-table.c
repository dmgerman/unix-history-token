begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// clang -target x86_64-linux-gnu -shared -fPIC -lc dynamic-table.c \
end_comment

begin_comment
comment|//       -o dynamic-table-so.x86 -Wl,-f,aux.so -Wl,-F,filter.so
end_comment

begin_comment
comment|// clang -target mipsel-linux-gnu -shared -fPIC -lc dynamic-table.c \
end_comment

begin_comment
comment|//       -o dynamic-table-so.mips
end_comment

begin_comment
comment|// clang -target mipsel-linux-gnu -lc dynamic-table.c \
end_comment

begin_comment
comment|//       -o dynamic-table-exe.mips
end_comment

begin_comment
comment|// clang -target aarch64-linux-gnu -fPIC -shared dynamic-table.c\
end_comment

begin_comment
comment|//       -o dynamic-table-so.aarch64
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

begin_decl_stmt
name|__thread
name|int
name|foo
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|puts
argument_list|(
literal|"Hello, World"
argument_list|)
expr_stmt|;
name|foo
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

