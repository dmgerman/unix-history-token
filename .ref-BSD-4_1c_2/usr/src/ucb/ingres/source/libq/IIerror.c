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
argument|%W%	%G%
argument_list|)
end_macro

begin_comment
comment|/* **	IIerror -- std. equel error reporting routine. ** **		IIerror is called either directly by a **		routine detecting an error or by **		IIrdpipe where INGRES returns an error. ** **		In the case of an appropriate error, IIerrflag is set to **		prevent the reading of the ovqp data pipe. This happens **		on errors that happen during retrieves to C vars. ** **		Errno is the error number: 1??? is an equel error **		others are Ingres errors. ** **		Argc and argv are structured as in Unix main program calls. ** **		The error is printed if the call (*IIprint_err)() **		returns> 0. Otherwise no error message is printed. **		The error message that is printed is the one corresponding **		to the number returned by (*IIprint_err)(). */
end_comment

begin_extern
extern|extern	IIret_err(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|IIprint_err
function_decl|)
parameter_list|()
init|=
name|IIret_err
function_decl|;
end_function_decl

begin_macro
name|IIerror
argument_list|(
argument|errno
argument_list|,
argument|argc
argument_list|,
argument|argv
argument_list|)
end_macro

begin_decl_stmt
name|int
name|errno
decl_stmt|,
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
ifdef|#
directive|ifdef
name|xETR1
if|if
condition|(
name|IIdebug
operator|>
literal|1
condition|)
name|printf
argument_list|(
literal|"ent IIerror : errno %d, argc %d\n"
argument_list|,
name|errno
argument_list|,
name|argc
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|IIerrflag
operator|=
name|errno
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|errno
operator|=
call|(
modifier|*
name|IIprint_err
call|)
argument_list|(
name|errno
argument_list|)
operator|)
condition|)
block|{
ifdef|#
directive|ifdef
name|xETR2
if|if
condition|(
name|IIdebug
operator|>
literal|1
condition|)
name|printf
argument_list|(
literal|"IIerror : IIprint_err returned 0\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* if must restore printing turned off in IIw_left() 		 * or IIw_right(), then do so. 		 */
if|if
condition|(
name|IIo_print
condition|)
block|{
name|IIprint_err
operator|=
name|IIo_print
expr_stmt|;
name|IIo_print
operator|=
literal|0
expr_stmt|;
block|}
return|return;
block|}
if|if
condition|(
name|errno
operator|>
literal|2000
condition|)
name|printf
argument_list|(
literal|"INGRES ERROR: "
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"EQUEL ERROR: "
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|IIp_err
argument_list|(
name|errno
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
condition|)
block|{
comment|/* couldn't process error in IIp_err() */
name|printf
argument_list|(
literal|" %d with parameters:"
argument_list|,
name|errno
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
name|argc
condition|;
control|)
name|printf
argument_list|(
literal|" %s"
argument_list|,
name|argv
index|[
name|i
operator|++
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|errno
operator|==
literal|3
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|IIproc_name
condition|)
name|printf
argument_list|(
literal|"On file %s line %d.\n"
argument_list|,
name|IIproc_name
argument_list|,
name|IIline_no
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* **  IIret_err -- returns its single argument for IIerror. ** */
end_comment

begin_macro
name|IIret_err
argument_list|(
argument|err
argument_list|)
end_macro

begin_decl_stmt
name|int
name|err
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|err
operator|)
return|;
block|}
end_block

begin_comment
comment|/* **  IIno_err -- returns 0. Called from IIerror **		(through (*IIprint_err)()) **		to supress error message printing. */
end_comment

begin_macro
name|IIno_err
argument_list|(
argument|err
argument_list|)
end_macro

begin_decl_stmt
name|int
name|err
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

