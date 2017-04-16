begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|X
block|{
union|union
block|{
name|int
name|n
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_function
specifier|inline
name|int
name|a
parameter_list|(
name|X
name|x
parameter_list|)
block|{
return|return
name|x
operator|.
name|n
return|;
block|}
end_function

end_unit

