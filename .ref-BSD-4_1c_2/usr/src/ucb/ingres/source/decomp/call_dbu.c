begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|<tree.h>
end_include

begin_include
include|#
directive|include
file|<symbol.h>
end_include

begin_include
include|#
directive|include
file|<pv.h>
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
argument|@(#)call_dbu.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_decl_stmt
name|int
name|Synconly
decl_stmt|,
name|Error_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **	Call the appropriate dbu with the arguments **	given in the globals Pc and Pv. Code is a **	number identifing which dbu to call. Errflag **	indicates whether an error return from the dbu **	is possibly expected. ** **	If errflag is FALSE then call_dbu will syserr on an error **	If errflag is TRUE then call_dbu will return error value ** **	Trace Flags: **		60 */
end_comment

begin_macro
name|call_dbu
argument_list|(
argument|code
argument_list|,
argument|errflag
argument_list|)
end_macro

begin_decl_stmt
name|int
name|code
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|errflag
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|xDTR1
if|if
condition|(
name|tTf
argument_list|(
literal|60
argument_list|,
literal|0
argument_list|)
condition|)
name|printf
argument_list|(
literal|"Calling DBU %d\n"
argument_list|,
name|code
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Error_flag
operator|=
literal|0
expr_stmt|;
name|call
argument_list|(
name|code
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|Error_flag
operator|!=
literal|0
operator|&&
operator|!
name|errflag
condition|)
name|syserr
argument_list|(
literal|"call_dbu:%d,ret %d"
argument_list|,
name|code
argument_list|,
name|Error_flag
argument_list|)
expr_stmt|;
return|return
operator|(
name|Error_flag
operator|)
return|;
block|}
end_block

begin_comment
comment|/* **	Proc_error is called if an error **	block is encountered. **	Otherwise the error block(s) are passed on up. */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|catcherr
argument_list|(
argument|pc
argument_list|,
argument|pv
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PARM
modifier|*
name|pv
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|int
name|Error_flag
decl_stmt|;
name|Error_flag
operator|=
name|pv
index|[
literal|0
index|]
operator|.
name|pv_val
operator|.
name|pv_int
expr_stmt|;
block|}
end_block

end_unit

