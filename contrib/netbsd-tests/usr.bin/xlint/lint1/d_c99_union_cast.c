begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* union cast */
end_comment

begin_struct
struct|struct
name|bar
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|foo
block|{
name|struct
name|bar
modifier|*
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
union|;
end_union

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|bar
modifier|*
name|a
decl_stmt|;
operator|(
operator|(
expr|union
name|foo
operator|)
name|a
operator|)
operator|.
name|a
expr_stmt|;
block|}
end_function

end_unit

