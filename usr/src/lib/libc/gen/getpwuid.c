begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)getpwuid.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_decl_stmt
name|struct
name|passwd
modifier|*
name|getpwuid
argument_list|(
name|uid
argument_list|)
decl|register
name|uid
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|passwd
modifier|*
name|p
decl_stmt|;
name|struct
name|passwd
modifier|*
name|getpwent
parameter_list|()
function_decl|;
name|setpwent
argument_list|()
expr_stmt|;
while|while
condition|(
operator|(
name|p
operator|=
name|getpwent
argument_list|()
operator|)
operator|&&
name|p
operator|->
name|pw_uid
operator|!=
name|uid
condition|)
empty_stmt|;
name|endpwent
argument_list|()
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_block

end_unit

