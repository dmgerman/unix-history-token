begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|"IIglobals.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)IIresync.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  RESYNCHRONIZE PIPES AFTER AN INTERRUPT ** **	The pipes are all cleared out.  This routines must be called **	by all processes in the system simultaneously.  It should be **	called from the interrupt catching routine. */
end_comment

begin_decl_stmt
name|int
name|IISyncs
index|[
name|CM_MAXPROC
index|]
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern	exit(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|IIinterrupt
function_decl|)
parameter_list|()
init|=
name|exit
function_decl|;
end_function_decl

begin_macro
name|IIresync
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|pb_t
name|pb
decl_stmt|;
specifier|register
name|int
name|stat
decl_stmt|;
name|signal
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* 	**  Send SYNC blocks to all processes that are adjacent 	**	in the write direction. 	**  Arrange to ignore blocks from all processes that 	**	are adjacent in the read direction. 	*/
name|IIpb_prime
argument_list|(
operator|&
name|pb
argument_list|,
name|PB_SYNC
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
name|CM_MAXPROC
condition|;
name|i
operator|++
control|)
block|{
name|IISyncs
index|[
name|i
index|]
operator|++
expr_stmt|;
comment|/* send SYNC to parser */
name|pb
operator|.
name|pb_proc
operator|=
literal|1
expr_stmt|;
name|IIpb_write
argument_list|(
operator|&
name|pb
argument_list|)
expr_stmt|;
block|}
comment|/* ovqp buffer flush is done in IIsetup() */
comment|/* Get out of a retrieve and clear errors */
name|IIin_retrieve
operator|=
literal|0
expr_stmt|;
name|IIerrflag
operator|=
literal|0
expr_stmt|;
name|IIndomains
operator|=
name|IIdomains
operator|=
literal|0
expr_stmt|;
name|IInewqry
operator|=
literal|0
expr_stmt|;
comment|/* reset the signal */
name|signal
argument_list|(
literal|2
argument_list|,
name|IIresync
argument_list|)
expr_stmt|;
comment|/* allow the user to service the interrupt */
call|(
modifier|*
name|IIinterrupt
call|)
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* 	** If IIinterupt returns the user might hang in a retrieve 	*/
name|IIsyserr
argument_list|(
literal|"Interupt returned"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

