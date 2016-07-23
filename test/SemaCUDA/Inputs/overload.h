begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This header is used by tests which are interested in __device__ functions
end_comment

begin_comment
comment|// which appear in a system header.
end_comment

begin_function_decl
name|__device__
name|int
name|OverloadMe
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|namespace
name|ns
block|{
name|using
operator|::
name|OverloadMe
expr_stmt|;
block|}
end_decl_stmt

end_unit

