begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<useful.h>
end_include

begin_include
include|#
directive|include
file|"pipes.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)pb_wphys.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  PB_WPHYS -- physical write on pipe ** **	Parameters: **		ppb -- a pointer to the data area. **		fd -- the file descriptor. ** **	Returns: **		none ** **	Side Effects: **		none ** **	Called By: **		pb_write ** **	Trace Flags: **		none */
end_comment

begin_expr_stmt
name|pb_wphys
argument_list|(
name|ppb
argument_list|,
name|fd
argument_list|)
specifier|register
name|pb_t
operator|*
name|ppb
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|i
operator|=
name|write
argument_list|(
name|fd
argument_list|,
operator|(
name|char
operator|*
operator|)
name|ppb
argument_list|,
name|PB_IOSIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|!=
name|PB_IOSIZE
condition|)
block|{
name|pb_dump
argument_list|(
name|ppb
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|syserr
argument_list|(
literal|"pb_wphys: write error: fd=%d, i=%d"
argument_list|,
name|fd
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

