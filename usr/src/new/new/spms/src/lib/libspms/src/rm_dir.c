begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * rm_dir() removes a directory named by dirname via the rmdir command.  * Returns exit status of rmdir command.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|"bin.h"
end_include

begin_include
include|#
directive|include
file|"macro.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_macro
name|rm_dir
argument_list|(
argument|dirname
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|dirname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* directory name */
end_comment

begin_block
block|{
name|int
name|pid
decl_stmt|;
comment|/* process identity */
name|int
name|status
decl_stmt|;
comment|/* child return status */
name|int
name|w
decl_stmt|;
comment|/* a child id */
if|if
condition|(
operator|(
name|pid
operator|=
name|FORK
argument_list|()
operator|)
operator|==
literal|0
condition|)
block|{
name|execl
argument_list|(
name|RMDIR
argument_list|,
literal|"rmdir"
argument_list|,
name|dirname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
operator|(
name|w
operator|=
name|wait
argument_list|(
operator|&
name|status
argument_list|)
operator|)
operator|!=
name|pid
operator|&&
name|w
operator|!=
operator|-
literal|1
condition|)
continue|continue;
name|status
operator|>>=
name|NBBY
expr_stmt|;
name|status
operator|&=
literal|0xff
expr_stmt|;
comment|/* check if the directory exists because rmdir is unreliable */
if|if
condition|(
name|status
operator|==
literal|0
operator|&&
name|FILEXIST
argument_list|(
name|dirname
argument_list|)
condition|)
block|{
name|warn
argument_list|(
literal|"%s not removed"
argument_list|,
name|dirname
argument_list|)
expr_stmt|;
name|status
operator|=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|status
operator|)
return|;
block|}
end_block

end_unit

