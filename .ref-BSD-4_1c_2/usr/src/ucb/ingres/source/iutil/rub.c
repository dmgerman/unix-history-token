begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<useful.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)rub.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  RUB -- handle interrupt signals ** **	This routine arranges to handle the interrupt signal **	on behalf of the CM.  It sends SYNC blocks to everyone **	who ought to get them, and arranges to ignore all **	blocks except SYNC (and RESET) blocks from everyone **	who will be sending one.  It also calls all of the **	interrupt functions for all active modules.  It does **	this after writing all of the sync blocks, so an **	interrupt function can safely issue a query if it **	wants.  It then does a non-local goto to the top of **	the main loop. ** **	Parameters: **		none ** **	Returns: **		non-local ** **	Side Effects: **		Proc_name gets set to the CM name. **		Interrupt functions for all active modules **			are invoked. **		The 'Syncs' vector is updated appropriately. **		SYNC blocks are sent to all adjacent processes. ** **	Called By: **		System, via 'signal' (section 2). ** **	Trace Flags: **		none */
end_comment

begin_decl_stmt
name|int
name|RubLevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* depth of ruboff calls, -1 if off */
end_comment

begin_decl_stmt
name|char
modifier|*
name|RubWhy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* why are interrupts disabled */
end_comment

begin_decl_stmt
name|int
name|RubGot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if we have an unprocessed interrupt */
end_comment

begin_macro
name|rubcatch
argument_list|()
end_macro

begin_block
block|{
comment|/* ignore interrupts while we are processing */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* find out if we are allowing interrupts */
if|if
condition|(
name|RubLevel
operator|<
literal|0
condition|)
name|syserr
argument_list|(
literal|"bad SIGINT"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|RubLevel
operator|>
literal|0
condition|)
block|{
comment|/* save interrupt for later processing */
name|RubGot
operator|++
expr_stmt|;
if|if
condition|(
name|RubWhy
operator|!=
name|NULL
condition|)
name|printf
argument_list|(
literal|"Rubout locked out (%s in progress)\n"
argument_list|,
name|RubWhy
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* do other processing (either from ctlmod or standalones) */
name|rubproc
argument_list|()
expr_stmt|;
name|syserr
argument_list|(
literal|"rubcatch: rubproc"
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  TURN RUBOUTS OFF ** **	Further rubouts will be caught by rubsave. **	The parameter should be the name of the processor which **	insists that rubouts do not occur. */
end_comment

begin_macro
name|ruboff
argument_list|(
argument|why
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|why
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* check to see if this should be ignored */
if|if
condition|(
name|RubLevel
operator|<
literal|0
operator|||
name|RubLevel
operator|++
operator|>
literal|0
condition|)
return|return;
comment|/* set up to ignore interrupts */
name|RubGot
operator|=
literal|0
expr_stmt|;
name|RubWhy
operator|=
name|why
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  TURN RUBOUTS BACK ON ** **	Rubout processing is restored to the norm (calling rubcatch). **	If any rubouts have occured while disabled, they are processed **	now. */
end_comment

begin_macro
name|rubon
argument_list|()
end_macro

begin_block
block|{
comment|/* check to see if we should leave as-is */
if|if
condition|(
name|RubLevel
operator|<
literal|0
operator|||
operator|--
name|RubLevel
operator|>
literal|0
condition|)
return|return;
comment|/* process any old interrupts */
if|if
condition|(
name|RubGot
operator|>
literal|0
condition|)
name|rubcatch
argument_list|()
expr_stmt|;
comment|/* reset state */
name|RubWhy
operator|=
name|NULL
expr_stmt|;
block|}
end_block

end_unit

