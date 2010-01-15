begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -g -o /dev/null
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|sigcatch_t
function_decl|)
parameter_list|(
name|struct
name|sigcontext
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|sigcatch_t
name|sigcatch
index|[
literal|50
index|]
init|=
block|{
operator|(
name|sigcatch_t
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

