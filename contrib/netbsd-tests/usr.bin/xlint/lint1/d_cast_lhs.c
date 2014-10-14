begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pointer casts are valid lhs lvalues */
end_comment

begin_struct
struct|struct
name|sockaddr
block|{ }
struct|;
end_struct

begin_function
name|void
name|foo
parameter_list|()
block|{
name|unsigned
name|long
name|p
init|=
literal|6
decl_stmt|;
operator|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
name|p
operator|)
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

