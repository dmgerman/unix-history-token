begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"ctlmod.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)cm_reset.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  CM_RESET -- reset control module ** **	Called on a RESET block, this routine should reset the **	state to something well known.  Useful for debugging. ** **	Parameters: **		none ** **	Returns: **		never -- non-locally to top of CM loop. ** **	Side Effects: **		'Syncs' is cleared. **		'Qbuf' is reset. **		'Cm.cm_input' is set to the default input. **		All extra files are closed. ** **	Trace Flags: **		none */
end_comment

begin_macro
name|cm_reset
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|extern
name|jmp_buf
name|CmReset
decl_stmt|;
specifier|extern
name|long
name|CmOfiles
decl_stmt|;
comment|/* clear all Syncs */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|CM_MAXPROC
condition|;
name|i
operator|++
control|)
name|Syncs
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
comment|/* close and report all extraneous files */
name|closeall
argument_list|(
name|TRUE
argument_list|,
name|CmOfiles
argument_list|)
expr_stmt|;
comment|/* return to top of loop */
name|longjmp
argument_list|(
name|CmReset
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

