begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)getgrgid.c	5.2 (Berkeley) 3/9/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_decl_stmt
name|struct
name|group
modifier|*
name|getgrgid
argument_list|(
name|gid
argument_list|)
decl|register
name|gid
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|group
modifier|*
name|p
decl_stmt|;
name|struct
name|group
modifier|*
name|getgrent
parameter_list|()
function_decl|;
name|setgrent
argument_list|()
expr_stmt|;
while|while
condition|(
operator|(
name|p
operator|=
name|getgrent
argument_list|()
operator|)
operator|&&
name|p
operator|->
name|gr_gid
operator|!=
name|gid
condition|)
empty_stmt|;
name|endgrent
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

