begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *    (C) Copyright 1990, 1991 Tom Dinger  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_comment
comment|/*  * A "DOS-aware" chdir() function, that will change current drive as well.  *  *	chdir( "B:" )	-- changes to the default directory, on drive B:  *	chdir( "C:\FOO" )  changes to the specified directory, on drive C:  *	chdir( "\BAR" )    changes to the specified directory on the current  *			   drive.  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<direct.h>
end_include

begin_include
include|#
directive|include
file|<dos.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|chdir
end_ifdef

begin_undef
undef|#
directive|undef
name|chdir
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We should have the line:  *  * #define chdir perl_chdir  *  * in some header for perl (I put it in config.h) so that all  * references to chdir() become references to this function.  */
end_comment

begin_comment
comment|/*------------------------------------------------------------------*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BUGGY_MSC5
argument_list|)
end_if

begin_comment
comment|/* only needed for MSC 5.1 */
end_comment

begin_function
name|int
name|_chdrive
parameter_list|(
name|int
name|drivenum
parameter_list|)
block|{
name|unsigned
name|int
name|ndrives
decl_stmt|;
name|unsigned
name|int
name|tmpdrive
decl_stmt|;
name|_dos_setdrive
argument_list|(
name|drivenum
argument_list|,
operator|&
name|ndrives
argument_list|)
expr_stmt|;
comment|/* check for illegal drive letter */
name|_dos_getdrive
argument_list|(
operator|&
name|tmpdrive
argument_list|)
expr_stmt|;
return|return
operator|(
name|tmpdrive
operator|!=
name|drivenum
operator|)
condition|?
operator|-
literal|1
else|:
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-----------------------------------------------------------------*/
end_comment

begin_function
name|int
name|perl_chdir
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
block|{
name|int
name|drive_letter
decl_stmt|;
name|unsigned
name|int
name|drivenum
decl_stmt|;
if|if
condition|(
name|path
operator|&&
operator|*
name|path
operator|&&
operator|(
name|path
index|[
literal|1
index|]
operator|==
literal|':'
operator|)
condition|)
block|{
comment|/* The path starts with a drive letter */
comment|/* Change current drive */
name|drive_letter
operator|=
operator|*
name|path
expr_stmt|;
if|if
condition|(
name|isalpha
argument_list|(
name|drive_letter
argument_list|)
condition|)
block|{
comment|/* Drive letter legal */
if|if
condition|(
name|islower
argument_list|(
name|drive_letter
argument_list|)
condition|)
name|drive_letter
operator|=
name|toupper
argument_list|(
name|drive_letter
argument_list|)
expr_stmt|;
name|drivenum
operator|=
name|drive_letter
operator|-
literal|'A'
operator|+
literal|1
expr_stmt|;
comment|/* Change drive */
if|if
condition|(
name|_chdrive
argument_list|(
name|drivenum
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Drive change failed -- must be illegal drive letter */
name|errno
operator|=
name|ENODEV
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
comment|/* Now see if that's all we do */
if|if
condition|(
operator|!
name|path
index|[
literal|2
index|]
condition|)
return|return
literal|0
return|;
comment|/* no path after drive -- all done */
block|}
comment|/* else drive letter illegal -- fall into "normal" chdir */
block|}
comment|/* Here with some path as well */
return|return
name|chdir
argument_list|(
name|path
argument_list|)
return|;
comment|/* end perl_chdir() */
block|}
end_function

end_unit

