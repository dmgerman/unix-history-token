begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify %s
end_comment

begin_comment
comment|// PR3592
end_comment

begin_function_decl
specifier|static
name|void
modifier|*
name|malloc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
modifier|*
name|malloc
parameter_list|(
name|int
name|size
parameter_list|)
block|{
return|return
operator|(
operator|(
name|void
operator|*
operator|)
literal|0
operator|)
return|;
comment|/*do not use heap in this file*/
block|}
end_function

begin_function_decl
name|void
modifier|*
name|calloc
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{incompatible redeclaration of library function 'calloc' will be ignored}} \
end_comment

begin_comment
comment|// expected-note{{'calloc' is a builtin with type 'void *}}
end_comment

begin_function
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
name|calloc
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f2
parameter_list|()
block|{
name|int
name|index
init|=
literal|1
decl_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
name|int
name|index
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f3
parameter_list|()
block|{
return|return
name|index
operator|<<
literal|2
return|;
block|}
end_function

begin_typedef
typedef|typedef
name|int
name|rindex
typedef|;
end_typedef

end_unit

