begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vfs_xxx.c	4.1	82/10/20	*/
end_comment

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/systm.h"
end_include

begin_include
include|#
directive|include
file|"../h/inode.h"
end_include

begin_include
include|#
directive|include
file|"../h/fs.h"
end_include

begin_include
include|#
directive|include
file|"../h/mount.h"
end_include

begin_include
include|#
directive|include
file|"../h/dir.h"
end_include

begin_include
include|#
directive|include
file|"../h/user.h"
end_include

begin_include
include|#
directive|include
file|"../h/buf.h"
end_include

begin_include
include|#
directive|include
file|"../h/conf.h"
end_include

begin_comment
comment|/*  * Return the next character fromt the  * kernel string pointed at by dirp.  */
end_comment

begin_macro
name|schar
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
operator|*
name|u
operator|.
name|u_dirp
operator|++
operator|&
literal|0377
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Return the next character from the  * user string pointed at by dirp.  */
end_comment

begin_macro
name|uchar
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|c
expr_stmt|;
name|c
operator|=
name|fubyte
argument_list|(
name|u
operator|.
name|u_dirp
operator|++
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
operator|-
literal|1
condition|)
block|{
name|u
operator|.
name|u_error
operator|=
name|EFAULT
expr_stmt|;
name|c
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|(
name|c
operator|)
return|;
block|}
end_block

end_unit

