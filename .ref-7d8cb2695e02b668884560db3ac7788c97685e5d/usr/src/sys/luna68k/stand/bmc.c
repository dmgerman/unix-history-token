begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)bmc.c	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * bmc.c -- bitmap console driver  *   by A.Fujita, JUL-06-1992  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<luna68k/stand/rcvbuf.h>
end_include

begin_include
include|#
directive|include
file|<luna68k/stand/preset.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|dipsw1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nplane
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rcvbuf
name|rcvbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_macro
name|bmcintr
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/*  * Following are all routines needed for SIO to act as console  */
end_comment

begin_include
include|#
directive|include
file|<luna68k/luna68k/cons.h>
end_include

begin_macro
name|bmccnprobe
argument_list|(
argument|cp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|consdev
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|(
name|dipsw1
operator|&
name|PS_BMC_CONS
operator|)
operator|==
literal|0
condition|)
block|{
name|cp
operator|->
name|cn_pri
operator|=
name|CN_DEAD
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|nplane
operator|==
literal|0
condition|)
block|{
name|cp
operator|->
name|cn_pri
operator|=
name|CN_DEAD
expr_stmt|;
return|return;
block|}
comment|/* initialize required fields */
name|cp
operator|->
name|cn_dev
operator|=
literal|1
expr_stmt|;
name|cp
operator|->
name|cn_tp
operator|=
literal|0
expr_stmt|;
name|cp
operator|->
name|cn_pri
operator|=
name|CN_NORMAL
expr_stmt|;
block|}
end_block

begin_macro
name|bmccninit
argument_list|(
argument|cp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|consdev
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|sioinit
argument_list|()
expr_stmt|;
name|bmdinit
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|bmccngetc
argument_list|(
argument|dev
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|c
decl_stmt|;
specifier|register
name|int
name|unit
init|=
literal|1
decl_stmt|;
while|while
condition|(
name|RBUF_EMPTY
argument_list|(
name|unit
argument_list|)
condition|)
block|{
name|DELAY
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
name|POP_RBUF
argument_list|(
name|unit
argument_list|,
name|c
argument_list|)
expr_stmt|;
return|return
operator|(
name|c
operator|)
return|;
comment|/* 	return(siocngetc(dev));  */
block|}
end_block

begin_macro
name|bmccnputc
argument_list|(
argument|dev
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|bmdputc
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

