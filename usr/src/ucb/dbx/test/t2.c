begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|struct
name|Blah
modifier|*
name|Blah
typedef|;
end_typedef

begin_struct
struct|struct
name|Blah
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

begin_decl_stmt
name|struct
name|Blah
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|t2
decl_stmt|;
end_decl_stmt

begin_function
name|Blah
name|f
parameter_list|()
block|{
name|x
operator|.
name|a
operator|=
literal|3
expr_stmt|;
name|x
operator|.
name|b
operator|=
literal|4
expr_stmt|;
return|return
operator|&
name|x
return|;
block|}
end_function

end_unit

