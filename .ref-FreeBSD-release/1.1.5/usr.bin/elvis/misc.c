begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* misc.c */
end_comment

begin_comment
comment|/* Author:  *	Steve Kirkendall  *	14407 SW Teal Blvd. #C  *	Beaverton, OR 97005  *	kirkenda@cs.pdx.edu  */
end_comment

begin_comment
comment|/* This file contains functions which didn't seem happy anywhere else */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_comment
comment|/* find a particular line& return a pointer to a copy of its text */
end_comment

begin_function
name|char
modifier|*
name|fetchline
parameter_list|(
name|line
parameter_list|)
name|long
name|line
decl_stmt|;
comment|/* line number of the line to fetch */
block|{
name|int
name|i
decl_stmt|;
name|REG
name|char
modifier|*
name|scan
decl_stmt|;
comment|/* used to search for the line in a BLK */
name|long
name|l
decl_stmt|;
comment|/* line number counter */
specifier|static
name|BLK
name|buf
decl_stmt|;
comment|/* holds ONLY the selected line (as string) */
name|REG
name|char
modifier|*
name|cpy
decl_stmt|;
comment|/* used while copying the line */
specifier|static
name|long
name|nextline
decl_stmt|;
comment|/* }  These four variables are used */
specifier|static
name|long
name|chglevel
decl_stmt|;
comment|/*  } to implement a shortcut when  */
specifier|static
name|char
modifier|*
name|nextscan
decl_stmt|;
comment|/*  } consecutive lines are fetched */
specifier|static
name|long
name|nextlnum
decl_stmt|;
comment|/* }                                */
comment|/* can we do a shortcut? */
if|if
condition|(
name|changes
operator|==
name|chglevel
operator|&&
name|line
operator|==
name|nextline
condition|)
block|{
name|scan
operator|=
name|nextscan
expr_stmt|;
block|}
else|else
block|{
comment|/* scan lnum[] to determine which block its in */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|line
operator|>
name|lnum
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
block|{ 		}
name|nextlnum
operator|=
name|lnum
index|[
name|i
index|]
expr_stmt|;
comment|/* fetch text of the block containing that line */
name|scan
operator|=
name|blkget
argument_list|(
name|i
argument_list|)
operator|->
name|c
expr_stmt|;
comment|/* find the line in the block */
for|for
control|(
name|l
operator|=
name|lnum
index|[
name|i
operator|-
literal|1
index|]
init|;
operator|++
name|l
operator|<
name|line
condition|;
control|)
block|{
while|while
condition|(
operator|*
name|scan
operator|++
operator|!=
literal|'\n'
condition|)
block|{ 			}
block|}
block|}
comment|/* copy it into a block by itself, with no newline */
for|for
control|(
name|cpy
operator|=
name|buf
operator|.
name|c
init|;
operator|*
name|scan
operator|!=
literal|'\n'
condition|;
control|)
block|{
operator|*
name|cpy
operator|++
operator|=
operator|*
name|scan
operator|++
expr_stmt|;
block|}
operator|*
name|cpy
operator|=
literal|'\0'
expr_stmt|;
comment|/* maybe speed up the next call to fetchline() ? */
if|if
condition|(
name|line
operator|<
name|nextlnum
condition|)
block|{
name|nextline
operator|=
name|line
operator|+
literal|1
expr_stmt|;
name|chglevel
operator|=
name|changes
expr_stmt|;
name|nextscan
operator|=
name|scan
operator|+
literal|1
expr_stmt|;
block|}
else|else
block|{
name|nextline
operator|=
literal|0
expr_stmt|;
block|}
comment|/* Calls to fetchline() interfere with calls to pfetch().  Make sure 	 * that pfetch() resets itself on its next invocation. 	 */
name|pchgs
operator|=
literal|0L
expr_stmt|;
comment|/* Return a pointer to the line's text */
return|return
name|buf
operator|.
name|c
return|;
block|}
end_function

begin_comment
comment|/* error message from the regexp code */
end_comment

begin_function
name|void
name|regerr
parameter_list|(
name|txt
parameter_list|)
name|char
modifier|*
name|txt
decl_stmt|;
comment|/* an error message */
block|{
name|msg
argument_list|(
literal|"RE error: %s"
argument_list|,
name|txt
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* This function is equivelent to the pfetch() macro */
end_comment

begin_function
name|void
name|pfetch
parameter_list|(
name|l
parameter_list|)
name|long
name|l
decl_stmt|;
comment|/* line number of line to fetch */
block|{
if|if
condition|(
name|l
operator|!=
name|pline
operator|||
name|changes
operator|!=
name|pchgs
condition|)
block|{
name|pline
operator|=
operator|(
name|l
operator|)
expr_stmt|;
name|ptext
operator|=
name|fetchline
argument_list|(
name|pline
argument_list|)
expr_stmt|;
name|plen
operator|=
name|strlen
argument_list|(
name|ptext
argument_list|)
expr_stmt|;
name|pchgs
operator|=
name|changes
expr_stmt|;
block|}
block|}
end_function

end_unit

