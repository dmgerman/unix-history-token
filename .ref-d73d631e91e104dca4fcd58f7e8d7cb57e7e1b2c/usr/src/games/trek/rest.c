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
literal|"@(#)rest.c	5.4 (Berkeley) %G%"
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

begin_include
include|#
directive|include
file|"getpar.h"
end_include

begin_comment
comment|/* **  REST FOR REPAIRS ** **	You sit around and wait for repairs to happen.  Actually, you **	sit around and wait for anything to happen.  I do want to point **	out however, that Klingons are not as patient as you are, and **	they tend to attack you while you are resting. ** **	You can never rest through a long range tractor beam. ** **	In events() you will be given an opportunity to cancel the **	rest period if anything momentous happens. */
end_comment

begin_macro
name|rest
argument_list|()
end_macro

begin_block
block|{
name|double
name|t
decl_stmt|;
specifier|register
name|int
name|percent
decl_stmt|;
comment|/* get the time to rest */
name|t
operator|=
name|getfltpar
argument_list|(
literal|"How long"
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|<=
literal|0.0
condition|)
return|return;
name|percent
operator|=
literal|100
operator|*
name|t
operator|/
name|Now
operator|.
name|time
operator|+
literal|0.5
expr_stmt|;
if|if
condition|(
name|percent
operator|>=
literal|70
condition|)
block|{
name|printf
argument_list|(
literal|"Spock: That would take %d%% of our remaining time.\n"
argument_list|,
name|percent
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|getynpar
argument_list|(
literal|"Are you really certain that is wise"
argument_list|)
condition|)
return|return;
block|}
name|Move
operator|.
name|time
operator|=
name|t
expr_stmt|;
comment|/* boundary condition is the LRTB */
name|t
operator|=
name|Now
operator|.
name|eventptr
index|[
name|E_LRTB
index|]
operator|->
name|date
operator|-
name|Now
operator|.
name|date
expr_stmt|;
if|if
condition|(
name|Ship
operator|.
name|cond
operator|!=
name|DOCKED
operator|&&
name|Move
operator|.
name|time
operator|>
name|t
condition|)
name|Move
operator|.
name|time
operator|=
name|t
operator|+
literal|0.0001
expr_stmt|;
name|Move
operator|.
name|free
operator|=
literal|0
expr_stmt|;
name|Move
operator|.
name|resting
operator|=
literal|1
expr_stmt|;
block|}
end_block

end_unit

