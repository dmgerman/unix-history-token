begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* recycle.c */
end_comment

begin_comment
comment|/* Author:  *	Steve Kirkendall  *	14407 SW Teal Blvd. #C  *	Beaverton, OR 97005  *	kirkenda@cs.pdx.edu  */
end_comment

begin_comment
comment|/* This file contains the functions perform garbage collection and allocate  * reusable blocks.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|NO_RECYCLE
end_ifndef

begin_comment
comment|/* this whole file would have be skipped if NO_RECYCLE is defined */
end_comment

begin_function_decl
specifier|extern
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BTST
parameter_list|(
name|bitno
parameter_list|,
name|byte
parameter_list|)
value|((byte)& (1<< (bitno)))
end_define

begin_define
define|#
directive|define
name|BSET
parameter_list|(
name|bitno
parameter_list|,
name|byte
parameter_list|)
value|((byte) |= (1<< (bitno)))
end_define

begin_define
define|#
directive|define
name|BCLR
parameter_list|(
name|bitno
parameter_list|,
name|byte
parameter_list|)
value|((byte)&= ~(1<< (bitno)))
end_define

begin_define
define|#
directive|define
name|TST
parameter_list|(
name|blkno
parameter_list|)
value|((blkno)< MAXBIT ? BTST((blkno)& 7, bitmap[(blkno)>> 3]) : 1)
end_define

begin_define
define|#
directive|define
name|SET
parameter_list|(
name|blkno
parameter_list|)
value|if ((blkno)< MAXBIT) BSET((blkno)& 7, bitmap[(blkno)>> 3])
end_define

begin_define
define|#
directive|define
name|CLR
parameter_list|(
name|blkno
parameter_list|)
value|if ((blkno)< MAXBIT) BCLR((blkno)& 7, bitmap[(blkno)>> 3])
end_define

begin_comment
comment|/* bitmap of free blocks in first 4096k of tmp file */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|bitmap
index|[
literal|512
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAXBIT
value|(sizeof bitmap<< 3)
end_define

begin_comment
comment|/* this function locates all free blocks in the current tmp file */
end_comment

begin_function
name|void
name|garbage
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|BLK
name|oldhdr
decl_stmt|;
comment|/* start by assuming every block is free */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
name|bitmap
condition|;
name|i
operator|++
control|)
block|{
name|bitmap
index|[
name|i
index|]
operator|=
literal|255
expr_stmt|;
block|}
comment|/* header block isn't free */
ifndef|#
directive|ifndef
name|lint
name|CLR
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* blocks needed for current hdr aren't free */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|MAXBLKS
condition|;
name|i
operator|++
control|)
block|{
name|CLR
argument_list|(
name|hdr
operator|.
name|n
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
comment|/* blocks needed for undo version aren't free */
name|lseek
argument_list|(
name|tmpfd
argument_list|,
literal|0L
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|read
argument_list|(
name|tmpfd
argument_list|,
operator|&
name|oldhdr
argument_list|,
operator|(
name|unsigned
operator|)
sizeof|sizeof
name|oldhdr
argument_list|)
operator|!=
sizeof|sizeof
name|oldhdr
condition|)
block|{
name|msg
argument_list|(
literal|"garbage() failed to read oldhdr??"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
name|bitmap
condition|;
name|i
operator|++
control|)
block|{
name|bitmap
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
return|return;
block|}
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|MAXBLKS
condition|;
name|i
operator|++
control|)
block|{
name|CLR
argument_list|(
name|oldhdr
operator|.
name|n
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
comment|/* blocks needed for cut buffers aren't free */
for|for
control|(
name|i
operator|=
name|cutneeds
argument_list|(
operator|&
name|oldhdr
argument_list|)
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
name|i
operator|--
control|)
block|{
name|CLR
argument_list|(
name|oldhdr
operator|.
name|n
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* This function allocates the first available block in the tmp file */
end_comment

begin_function
name|long
name|allocate
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|long
name|offset
decl_stmt|;
comment|/* search for the first byte with a free bit set */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
name|bitmap
operator|&&
name|bitmap
index|[
name|i
index|]
operator|==
literal|0
condition|;
name|i
operator|++
control|)
block|{ 	}
comment|/* if we hit the end of the bitmap, return the end of the file */
if|if
condition|(
name|i
operator|==
sizeof|sizeof
name|bitmap
condition|)
block|{
name|offset
operator|=
name|lseek
argument_list|(
name|tmpfd
argument_list|,
literal|0L
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
else|else
comment|/* compute the offset for the free block */
block|{
for|for
control|(
name|i
operator|<<=
literal|3
init|;
name|TST
argument_list|(
name|i
argument_list|)
operator|==
literal|0
condition|;
name|i
operator|++
control|)
block|{ 		}
name|offset
operator|=
operator|(
name|long
operator|)
name|i
operator|*
operator|(
name|long
operator|)
name|BLKSIZE
expr_stmt|;
comment|/* mark the block as "allocated" */
name|CLR
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
return|return
name|offset
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

