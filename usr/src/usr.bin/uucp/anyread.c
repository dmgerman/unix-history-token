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
literal|"@(#)anyread.c	5.4 (Berkeley) 6/19/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_comment
comment|/*  *	anyread		check if anybody can read  *	return SUCCESS ok: FAIL not ok  */
end_comment

begin_macro
name|anyread
argument_list|(
argument|file
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|stat
name|s
decl_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|subfile
argument_list|(
name|file
argument_list|)
argument_list|,
operator|&
name|s
argument_list|)
operator|<
literal|0
condition|)
comment|/* for security check a non existant file is readable */
return|return
name|SUCCESS
return|;
if|if
condition|(
operator|!
operator|(
name|s
operator|.
name|st_mode
operator|&
name|ANYREAD
operator|)
condition|)
return|return
name|FAIL
return|;
return|return
name|SUCCESS
return|;
block|}
end_block

end_unit

