begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -o - %s
end_comment

begin_comment
comment|// PR1083
end_comment

begin_function_decl
name|int
name|svc_register
parameter_list|(
name|void
function_decl|(
modifier|*
name|dispatch
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|svc_register
function_decl|(
name|dispatch
function_decl|)
name|void
argument_list|(
argument|*dispatch
argument_list|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{ }
end_block

end_unit

