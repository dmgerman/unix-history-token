begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm-only %s
end_comment

begin_typedef
typedef|typedef
name|struct
name|_IO_FILE
name|FILE
typedef|;
end_typedef

begin_function_decl
name|int
name|vfprintf
parameter_list|(
name|FILE
modifier|*
specifier|restrict
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
name|__builtin_va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|__builtin_va_list
name|ap
parameter_list|)
block|{
name|vfprintf
argument_list|(
literal|0
argument_list|,
literal|" "
argument_list|,
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

