begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|WITH_IRIX_PROJECT
argument_list|)
operator|||
name|defined
argument_list|(
name|WITH_IRIX_JOBS
argument_list|)
operator|||
name|defined
argument_list|(
name|WITH_IRIX_ARRAY
argument_list|)
end_if

begin_function_decl
name|void
name|irix_setusercontext
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(WITH_IRIX_PROJECT) || defined(WITH_IRIX_JOBS) || defined(WITH_IRIX_ARRAY) */
end_comment

end_unit

