begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<symbol.h>
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
argument|@(#)IIsync.c
literal|7.2
literal|2
argument|/
literal|16
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **	IIsync is called to syncronize the running **	of a query with the running of the equel process. ** **	The query is flushed and an EOP is written **	to the quel parser. ** **	The quel parser will write an end-of-pipe when **	an operation is complete. */
end_comment

begin_macro
name|IIsync
argument_list|(
argument|file_name
argument_list|,
argument|line_no
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|line_no
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|pb_t
name|pb
decl_stmt|;
name|IIpb_flush
argument_list|(
operator|&
name|IIpb
argument_list|)
expr_stmt|;
if|if
condition|(
name|IIproc_name
operator|=
name|file_name
condition|)
name|IIline_no
operator|=
name|line_no
expr_stmt|;
ifdef|#
directive|ifdef
name|xETR1
if|if
condition|(
name|IIdebug
condition|)
name|printf
argument_list|(
literal|"IIsync\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|IIerrflag
operator|=
literal|0
expr_stmt|;
comment|/* reset error flag. If an error occures, 			** IIerrflag will get set in IIerror 			*/
name|IIpb_prime
argument_list|(
operator|&
name|pb
argument_list|,
name|PB_NOTYPE
argument_list|)
expr_stmt|;
name|IIreadinput
argument_list|(
operator|&
name|pb
argument_list|)
expr_stmt|;
name|IInewqry
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

