begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|foo
block|{
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|func
parameter_list|()
block|{
name|struct
name|foo
modifier|*
name|f
decl_stmt|;
name|f
operator|->
name|i
operator|=
literal|3
expr_stmt|;
block|}
end_function

end_unit

