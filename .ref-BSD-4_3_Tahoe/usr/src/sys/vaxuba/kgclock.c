begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)kgclock.c	7.1 (Berkeley) 6/5/86  */
end_comment

begin_include
include|#
directive|include
file|"kg.h"
end_include

begin_if
if|#
directive|if
name|NKG
operator|>
literal|0
end_if

begin_comment
comment|/*  * KL-11 as profiling clock  */
end_comment

begin_include
include|#
directive|include
file|"../machine/pte.h"
end_include

begin_include
include|#
directive|include
file|"../machine/psl.h"
end_include

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"map.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|"ubavar.h"
end_include

begin_decl_stmt
name|int
name|kgprobe
argument_list|()
decl_stmt|,
name|kgattach
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uba_device
modifier|*
name|kginfo
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|kgstd
index|[]
init|=
block|{
literal|0177560
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uba_driver
name|kgdriver
init|=
block|{
name|kgprobe
block|,
literal|0
block|,
name|kgattach
block|,
literal|0
block|,
name|kgstd
block|,
literal|"kg"
block|,
name|kginfo
block|}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|klregs
block|{
name|u_short
name|fill
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|tcsr
decl_stmt|;
name|u_short
name|tbuf
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KLSTRT
value|0300
end_define

begin_comment
comment|/* intr enbl + done */
end_comment

begin_decl_stmt
name|struct
name|klregs
modifier|*
name|klbase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|usekgclock
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if zero, kgclock is disabled */
end_comment

begin_macro
name|kgprobe
argument_list|(
argument|reg
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|reg
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|br
decl_stmt|,
name|cvec
decl_stmt|;
comment|/* value-result */
specifier|register
name|struct
name|klregs
modifier|*
name|klp
init|=
operator|(
expr|struct
name|klregs
operator|*
operator|)
name|reg
decl_stmt|;
name|klp
operator|->
name|tcsr
operator|=
name|KLSTRT
expr_stmt|;
name|DELAY
argument_list|(
literal|100000
argument_list|)
expr_stmt|;
name|klp
operator|->
name|tcsr
operator|=
literal|0
expr_stmt|;
return|return
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|klregs
argument_list|)
operator|)
return|;
block|}
end_block

begin_macro
name|kgattach
argument_list|(
argument|ui
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|klbase
operator|=
operator|(
expr|struct
name|klregs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * start the sampling clock  */
end_comment

begin_macro
name|startkgclock
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|klbase
operator|&&
name|usekgclock
operator|&&
name|phz
operator|==
literal|0
condition|)
name|klbase
operator|->
name|tcsr
operator|=
name|KLSTRT
expr_stmt|;
comment|/* enable interrupts */
block|}
end_block

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|kgclock
argument_list|(
argument|dev
argument_list|,
argument|r0
argument_list|,
argument|r1
argument_list|,
argument|r2
argument_list|,
argument|r3
argument_list|,
argument|r4
argument_list|,
argument|r5
argument_list|,
argument|pc
argument_list|,
argument|ps
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|pc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ps
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|k
decl_stmt|;
specifier|static
name|long
name|otime
decl_stmt|;
specifier|static
name|long
name|calibrate
decl_stmt|;
if|if
condition|(
name|usekgclock
operator|==
literal|0
condition|)
block|{
name|phz
operator|=
literal|0
expr_stmt|;
name|otime
operator|=
literal|0
expr_stmt|;
return|return;
block|}
name|klbase
operator|->
name|tbuf
operator|=
literal|0377
expr_stmt|;
comment|/* reprime clock (scope sync too) */
if|if
condition|(
name|phz
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|otime
operator|==
literal|0
condition|)
block|{
name|otime
operator|=
name|time
operator|.
name|tv_sec
operator|+
literal|1
expr_stmt|;
name|calibrate
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|time
operator|.
name|tv_sec
operator|>=
name|otime
condition|)
name|calibrate
operator|++
expr_stmt|;
if|if
condition|(
name|time
operator|.
name|tv_sec
operator|>=
name|otime
operator|+
literal|4
condition|)
block|{
name|phz
operator|=
name|calibrate
operator|/
literal|4
expr_stmt|;
name|otime
operator|=
literal|0
expr_stmt|;
block|}
return|return;
block|}
name|gatherstats
argument_list|(
name|pc
argument_list|,
name|ps
argument_list|)
expr_stmt|;
comment|/* this routine lives in kern_clock.c */
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

