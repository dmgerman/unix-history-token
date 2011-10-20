begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o -
end_comment

begin_comment
comment|// PR3744
end_comment

begin_struct
struct|struct
name|Empty
block|{}
struct|;
end_struct

begin_struct
struct|struct
name|Union
block|{
union|union
block|{
name|int
name|zero_arr
index|[
literal|0
index|]
decl_stmt|;
block|}
name|contents
union|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|void
name|Foo
parameter_list|(
name|struct
name|Union
modifier|*
name|u
parameter_list|)
block|{
name|int
modifier|*
name|array
init|=
name|u
operator|->
name|contents
operator|.
name|zero_arr
decl_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|Bar
parameter_list|(
name|struct
name|Union
modifier|*
name|u
parameter_list|)
block|{
name|Foo
argument_list|(
name|u
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

