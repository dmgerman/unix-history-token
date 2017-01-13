begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* struct with only anonymous members */
end_comment

begin_struct
struct|struct
name|foo
block|{
union|union
block|{
name|long
name|loo
decl_stmt|;
name|double
name|doo
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|foo
modifier|*
name|f
init|=
literal|0
decl_stmt|;
name|printf
argument_list|(
literal|"%p\n"
argument_list|,
operator|&
name|f
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

