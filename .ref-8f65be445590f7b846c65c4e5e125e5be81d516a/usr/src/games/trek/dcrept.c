begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)dcrept.c	5.4 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"trek.h"
end_include

begin_comment
comment|/* **  damage control report ** **	Print damages and time to fix.  This is taken from the event **	list.  A couple of factors are set up, based on whether or not **	we are docked.  (One of these factors will always be 1.0.) **	The event list is then scanned for damage fix events, the **	time until they occur is determined, and printed out.  The **	magic number DAMFAC is used to tell how much faster you can **	fix things if you are docked. */
end_comment

begin_macro
name|dcrept
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|,
name|f
decl_stmt|;
name|double
name|x
decl_stmt|;
name|double
name|m1
decl_stmt|,
name|m2
decl_stmt|;
specifier|register
name|struct
name|event
modifier|*
name|e
decl_stmt|;
comment|/* set up the magic factors to output the time till fixed */
if|if
condition|(
name|Ship
operator|.
name|cond
operator|==
name|DOCKED
condition|)
block|{
name|m1
operator|=
literal|1.0
operator|/
name|Param
operator|.
name|dockfac
expr_stmt|;
name|m2
operator|=
literal|1.0
expr_stmt|;
block|}
else|else
block|{
name|m1
operator|=
literal|1.0
expr_stmt|;
name|m2
operator|=
name|Param
operator|.
name|dockfac
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"Damage control report:\n"
argument_list|)
expr_stmt|;
name|f
operator|=
literal|1
expr_stmt|;
comment|/* scan for damages */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAXEVENTS
condition|;
name|i
operator|++
control|)
block|{
name|e
operator|=
operator|&
name|Event
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|evcode
operator|!=
name|E_FIXDV
condition|)
continue|continue;
comment|/* output the title first time */
if|if
condition|(
name|f
condition|)
block|{
name|printf
argument_list|(
literal|"\t\t\t  repair times\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"device\t\t\tin flight  docked\n"
argument_list|)
expr_stmt|;
name|f
operator|=
literal|0
expr_stmt|;
block|}
comment|/* compute time till fixed, then adjust by the magic factors */
name|x
operator|=
name|e
operator|->
name|date
operator|-
name|Now
operator|.
name|date
expr_stmt|;
name|printf
argument_list|(
literal|"%-24s%7.2f  %7.2f\n"
argument_list|,
name|Device
index|[
name|e
operator|->
name|systemname
index|]
operator|.
name|name
argument_list|,
name|x
operator|*
name|m1
operator|+
literal|0.005
argument_list|,
name|x
operator|*
name|m2
operator|+
literal|0.005
argument_list|)
expr_stmt|;
comment|/* do a little consistancy checking */
block|}
comment|/* if everything was ok, reassure the nervous captain */
if|if
condition|(
name|f
condition|)
name|printf
argument_list|(
literal|"All devices functional\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

