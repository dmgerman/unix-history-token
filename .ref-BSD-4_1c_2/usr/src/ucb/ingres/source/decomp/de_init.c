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
file|<range.h>
end_include

begin_include
include|#
directive|include
file|"globs.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)de_init.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|de_init
argument_list|(
argument|argc
argument_list|,
argument|argv
argument_list|)
end_macro

begin_decl_stmt
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|Batchupd
operator|=
name|setflag
argument_list|(
name|argv
argument_list|,
literal|'b'
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* 	** Do the necessary decomp initialization. This includes 	** buffering standard output (if i/d system) and giving 	** access methods more pages (if i/d system). 	** init_decomp is defined in either call_ovqp or call_ovqp70. 	*/
name|init_decomp
argument_list|()
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  RUBPROC -- process a rubout signal ** **	Called from the principle rubout catching routine **	when a rubout is to be processed. Notice that rubproc **	must return to its caller and not call reset itself. ** **	Parameters: **		none ** **	Returns: **		none ** **	Side Effects: **		reinitializes the state of the world. ** **	Called By: **		rubcatch */
end_comment

begin_macro
name|de_rubproc
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|int
name|Equel
decl_stmt|;
comment|/* 	** Sync with equel if we have the equel pipe. 	**	This can happen only if ovqp and decomp 	**	are combined. 	*/
comment|/* 	if (W_front>= 0&& Equel) 	Error_flag = pv[0].pv_val.pv_int; 		wrpipe(P_INT,&pipebuf, W_front); */
name|endovqp
argument_list|(
name|RUBACK
argument_list|)
expr_stmt|;
name|reinit
argument_list|()
expr_stmt|;
return|return;
block|}
end_block

end_unit

