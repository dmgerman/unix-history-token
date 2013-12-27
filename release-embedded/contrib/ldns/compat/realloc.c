begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Just a replacement, if the original malloc is not    GNU-compliant. Based on malloc.c */
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

begin_undef
undef|#
directive|undef
name|realloc
end_undef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_function_decl
name|void
modifier|*
name|realloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Changes allocation to new sizes, copies over old data.  * if oldptr is NULL, does a malloc.  * if size is zero, allocate 1-byte block....  *   (does not return NULL and free block)  */
end_comment

begin_function
name|void
modifier|*
name|rpl_realloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
if|if
condition|(
name|n
operator|==
literal|0
condition|)
name|n
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|ptr
operator|==
literal|0
condition|)
block|{
return|return
name|malloc
argument_list|(
name|n
argument_list|)
return|;
block|}
return|return
name|realloc
argument_list|(
name|ptr
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

end_unit

