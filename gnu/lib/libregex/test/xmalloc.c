begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
modifier|*
name|xmalloc
parameter_list|(
name|size
parameter_list|)
name|unsigned
name|size
decl_stmt|;
block|{
name|char
modifier|*
name|new_mem
init|=
name|malloc
argument_list|(
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|new_mem
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"xmalloc: request for %u bytes failed.\n"
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
return|return
name|new_mem
return|;
block|}
end_function

end_unit

