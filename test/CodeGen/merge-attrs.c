begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o %t
end_comment

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|__SIZE_TYPE__
name|size
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__nothrow__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|inline
specifier|static
name|void
name|__zend_malloc
parameter_list|()
block|{
name|malloc
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|__SIZE_TYPE__
name|size
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__nothrow__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|fontFetch
parameter_list|()
block|{
name|__zend_malloc
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

