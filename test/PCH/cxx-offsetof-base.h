begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test cxx-offsetof-base.cpp
end_comment

begin_struct
struct|struct
name|Base
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|Derived
range|:
name|Base
block|{
name|int
name|y
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|o
init|=
name|__builtin_offsetof
argument_list|(
name|Derived
argument_list|,
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

