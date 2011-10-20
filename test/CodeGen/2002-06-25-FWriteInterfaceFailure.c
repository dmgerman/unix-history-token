begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s  -o /dev/null
end_comment

begin_typedef
typedef|typedef
name|struct
name|_IO_FILE
name|FILE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|stderr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|fprintf
parameter_list|(
name|FILE
modifier|*
specifier|restrict
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|()
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"testing\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

