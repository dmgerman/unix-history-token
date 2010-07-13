begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test cxx-using.cpp
end_comment

begin_struct
struct|struct
name|B
block|{
name|void
name|f
parameter_list|(
name|char
name|c
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|D
range|:
name|B
block|{
name|using
name|B
operator|::
name|f
block|;
name|void
name|f
argument_list|(
name|int
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

end_unit

