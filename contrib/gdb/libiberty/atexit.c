begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Wrapper to implement ANSI C's atexit using SunOS's on_exit. */
end_comment

begin_comment
comment|/* This function is in the public domain.  --Mike Stump. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NEED_on_exit
end_ifndef

begin_function_decl
name|int
name|atexit
function_decl|(
name|f
function_decl|)
name|void
argument_list|(
argument|*f
argument_list|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{
comment|/* If the system doesn't provide a definition for atexit, use on_exit      if the system provides that.  */
name|on_exit
argument_list|(
name|f
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

