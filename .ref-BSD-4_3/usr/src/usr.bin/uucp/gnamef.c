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
literal|"@(#)gnamef.c	5.4 (Berkeley) 6/20/85"
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

begin_ifdef
ifdef|#
directive|ifdef
name|NDIR
end_ifdef

begin_include
include|#
directive|include
file|"ndir.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_comment
comment|/*  *	get next file name from directory  *  *	return codes:  *		0  -  end of directory read  *		1  -  returned name  */
end_comment

begin_expr_stmt
name|gnamef
argument_list|(
name|dirp
argument_list|,
name|filename
argument_list|)
specifier|register
name|DIR
operator|*
name|dirp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|direct
modifier|*
name|dentp
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
operator|(
name|dentp
operator|=
name|readdir
argument_list|(
name|dirp
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
return|return
literal|0
return|;
block|}
if|if
condition|(
name|dentp
operator|->
name|d_ino
operator|!=
literal|0
condition|)
break|break;
block|}
comment|/* Truncate filename.  This may become a problem someday. */
name|strncpy
argument_list|(
name|filename
argument_list|,
name|dentp
operator|->
name|d_name
argument_list|,
name|NAMESIZE
operator|-
literal|1
argument_list|)
expr_stmt|;
name|filename
index|[
name|NAMESIZE
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|DEBUG
argument_list|(
literal|99
argument_list|,
literal|"gnamef returns %s\n"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_block

end_unit

