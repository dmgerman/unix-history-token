begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)damage.c	5.3 (Berkeley) 6/18/88"
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
comment|/* **  Schedule Ship.damages to a Device ** **	Device `dev1' is damaged in an amount `dam'.  Dam is measured **	in stardates, and is an additional amount of damage.  It should **	be the amount to occur in non-docked mode.  The adjustment **	to docked mode occurs automatically if we are docked. ** **	Note that the repair of the device occurs on a DATE, meaning **	that the dock() and undock() have to reschedule the event. */
end_comment

begin_macro
name|damage
argument_list|(
argument|dev1
argument_list|,
argument|dam
argument_list|)
end_macro

begin_decl_stmt
name|int
name|dev1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  device index */
end_comment

begin_decl_stmt
name|double
name|dam
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time to repair */
end_comment

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|struct
name|event
modifier|*
name|e
decl_stmt|;
name|int
name|f
decl_stmt|;
specifier|register
name|int
name|dev
decl_stmt|;
comment|/* ignore zero damages */
if|if
condition|(
name|dam
operator|<=
literal|0.0
condition|)
return|return;
name|dev
operator|=
name|dev1
expr_stmt|;
name|printf
argument_list|(
literal|"\t%s damaged\n"
argument_list|,
name|Device
index|[
name|dev
index|]
operator|.
name|name
argument_list|)
expr_stmt|;
comment|/* find actual length till it will be fixed */
if|if
condition|(
name|Ship
operator|.
name|cond
operator|==
name|DOCKED
condition|)
name|dam
operator|*=
name|Param
operator|.
name|dockfac
expr_stmt|;
comment|/* set the damage flag */
name|f
operator|=
name|damaged
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|f
condition|)
block|{
comment|/* new damages -- schedule a fix */
name|schedule
argument_list|(
name|E_FIXDV
argument_list|,
name|dam
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|dev
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* device already damaged -- add to existing damages */
comment|/* scan for old damages */
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
operator|||
name|e
operator|->
name|systemname
operator|!=
name|dev
condition|)
continue|continue;
comment|/* got the right one; add on the new damages */
name|reschedule
argument_list|(
name|e
argument_list|,
name|e
operator|->
name|date
operator|-
name|Now
operator|.
name|date
operator|+
name|dam
argument_list|)
expr_stmt|;
return|return;
block|}
name|syserr
argument_list|(
literal|"Cannot find old damages %d\n"
argument_list|,
name|dev
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

