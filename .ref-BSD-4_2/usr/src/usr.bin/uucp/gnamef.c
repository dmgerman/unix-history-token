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
literal|"@(#)gnamef.c	5.2 (Berkeley) 7/2/83"
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
file|<sys/types.h>
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
comment|/*******  *	gnamef(dirp, filename)	get next file name from directory  *	DIR *dirp;  *	char *filename;  *  *	return codes:  *		0  -  end of directory read  *		1  -  returned name  */
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
while|while
condition|(
literal|1
condition|)
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
return|return
operator|(
literal|0
operator|)
return|;
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
comment|/* Truncate filename.  This may become a problem someday. rti!trt */
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
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

end_unit

