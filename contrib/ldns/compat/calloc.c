begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Just a replacement, if the original malloc is not    GNU-compliant. See autoconf documentation. */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<ldns/config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|HAVE_BZERO
operator|&&
name|HAVE_MEMSET
end_if

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|buf
parameter_list|,
name|bytes
parameter_list|)
value|((void) memset (buf, 0, bytes))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
modifier|*
name|calloc
parameter_list|(
name|size_t
name|num
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|void
modifier|*
name|new
init|=
name|malloc
argument_list|(
name|num
operator|*
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|new
condition|)
block|{
return|return
name|NULL
return|;
block|}
name|bzero
argument_list|(
name|new
argument_list|,
name|num
operator|*
name|size
argument_list|)
expr_stmt|;
return|return
name|new
return|;
block|}
end_function

end_unit

