begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * diff() compares files and directories via the diff(1) command. Argv is a  * pointer to an an array of character strings which contain the names of  * the files and/or directories plus flags for diff. The last argument  * must be a null pointer. Returns 0 if no differences, 1 if some, 2 if  * trouble.  */
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
file|"system.h"
end_include

begin_macro
name|diff
argument_list|(
argument|argv
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

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
name|execv
argument_list|(
name|DIFF
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|2
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
return|return
operator|(
name|status
operator|)
return|;
block|}
end_block

end_unit

