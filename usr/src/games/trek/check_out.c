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
literal|"@(#)check_out.c	5.4 (Berkeley) %G%"
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
comment|/* **  CHECK IF A DEVICE IS OUT ** **	The indicated device is checked to see if it is disabled.  If **	it is, an attempt is made to use the starbase device.  If both **	of these fails, it returns non-zero (device is REALLY out), **	otherwise it returns zero (I can get to it somehow). ** **	It prints appropriate messages too. */
end_comment

begin_macro
name|check_out
argument_list|(
argument|device
argument_list|)
end_macro

begin_decl_stmt
name|int
name|device
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|dev
decl_stmt|;
name|dev
operator|=
name|device
expr_stmt|;
comment|/* check for device ok */
if|if
condition|(
operator|!
name|damaged
argument_list|(
name|dev
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* report it as being dead */
name|out
argument_list|(
name|dev
argument_list|)
expr_stmt|;
comment|/* but if we are docked, we can go ahead anyhow */
if|if
condition|(
name|Ship
operator|.
name|cond
operator|!=
name|DOCKED
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|printf
argument_list|(
literal|"  Using starbase %s\n"
argument_list|,
name|Device
index|[
name|dev
index|]
operator|.
name|name
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

