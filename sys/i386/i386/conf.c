begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) UNIX System Laboratories, Inc.  All or some portions  * of this file are derived from material licensed to the  * University of California by American Telephone and Telegraph Co.  * or UNIX System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)conf.c	5.8 (Berkeley) 5/12/91  *	$Id: conf.c,v 1.24 1994/04/21 14:10:31 sos Exp $  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"tty.h"
end_include

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_decl_stmt
name|int
name|nullop
argument_list|()
decl_stmt|,
name|enxio
argument_list|()
decl_stmt|,
name|enodev
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|rawread
decl_stmt|,
name|rawwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|swstrategy
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"wd.h"
end_include

begin_if
if|#
directive|if
operator|(
name|NWD
operator|>
literal|0
operator|)
end_if

begin_decl_stmt
name|d_open_t
name|wdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|wdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|wdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|wdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|wddump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|wdsize
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|wdopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|wdclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|wdstrategy
value|(d_strategy_t *)enxio
end_define

begin_define
define|#
directive|define
name|wdioctl
value|(d_ioctl_t *)enxio
end_define

begin_define
define|#
directive|define
name|wddump
value|(d_dump_t *)enxio
end_define

begin_define
define|#
directive|define
name|wdsize
value|(d_psize_t *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sd.h"
end_include

begin_if
if|#
directive|if
name|NSD
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|sdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|sdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|sdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|sdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|sddump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|sdsize
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sdopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|sdclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|sdstrategy
value|(d_strategy_t *)enxio
end_define

begin_define
define|#
directive|define
name|sdioctl
value|(d_ioctl_t *)enxio
end_define

begin_define
define|#
directive|define
name|sddump
value|(d_dump_t *)enxio
end_define

begin_define
define|#
directive|define
name|sdsize
value|(d_psize_t *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"st.h"
end_include

begin_if
if|#
directive|if
name|NST
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|stopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|stclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|ststrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|stioctl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*int	stdump(),stsize();*/
end_comment

begin_define
define|#
directive|define
name|stdump
value|(d_dump_t *)enxio
end_define

begin_define
define|#
directive|define
name|stsize
value|(d_psize_t *)0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|stopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|stclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|ststrategy
value|(d_strategy_t *)enxio
end_define

begin_define
define|#
directive|define
name|stioctl
value|(d_ioctl_t *)enxio
end_define

begin_define
define|#
directive|define
name|stdump
value|(d_dump_t *)enxio
end_define

begin_define
define|#
directive|define
name|stsize
value|(d_psize_t *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"cd.h"
end_include

begin_if
if|#
directive|if
name|NCD
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|cdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|cdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|cdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|cdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|cdsize
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|cddump
value|(d_dump_t *)enxio
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cdopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|cdclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|cdstrategy
value|(d_strategy_t *)enxio
end_define

begin_define
define|#
directive|define
name|cdioctl
value|(d_ioctl_t *)enxio
end_define

begin_define
define|#
directive|define
name|cddump
value|(d_dump_t *)enxio
end_define

begin_define
define|#
directive|define
name|cdsize
value|(d_psize_t *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"mcd.h"
end_include

begin_if
if|#
directive|if
name|NMCD
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|mcdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|mcdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|mcdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|mcdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|mcdsize
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|mcddump
value|(d_dump_t *)enxio
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mcdopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|mcdclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|mcdstrategy
value|(d_strategy_t *)enxio
end_define

begin_define
define|#
directive|define
name|mcdioctl
value|(d_ioctl_t *)enxio
end_define

begin_define
define|#
directive|define
name|mcddump
value|(d_dump_t *)enxio
end_define

begin_define
define|#
directive|define
name|mcdsize
value|(d_psize_t *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ch.h"
end_include

begin_if
if|#
directive|if
name|NCH
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|chopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|chclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|chioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|chopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|chclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|chioctl
value|(d_ioctl_t *)enxio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"wt.h"
end_include

begin_if
if|#
directive|if
name|NWT
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|wtopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|wtclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|wtstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|wtioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|wtdump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|wtsize
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|wtopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|wtclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|wtstrategy
value|(d_strategy_t *)enxio
end_define

begin_define
define|#
directive|define
name|wtioctl
value|(d_ioctl_t *)enxio
end_define

begin_define
define|#
directive|define
name|wtdump
value|(d_dump_t *)enxio
end_define

begin_define
define|#
directive|define
name|wtsize
value|(d_psize_t *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"fd.h"
end_include

begin_if
if|#
directive|if
name|NFD
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|Fdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|fdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|fdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|fdioctl
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fddump
value|(d_dump_t *)enxio
end_define

begin_define
define|#
directive|define
name|fdsize
value|(d_psize_t *)0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Fdopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|fdclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|fdstrategy
value|(d_strategy_t *)enxio
end_define

begin_define
define|#
directive|define
name|fdioctl
value|(d_ioctl_t *)enxio
end_define

begin_define
define|#
directive|define
name|fddump
value|(d_dump_t *)enxio
end_define

begin_define
define|#
directive|define
name|fdsize
value|(d_psize_t *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|swopen
value|(d_open_t *)enodev
end_define

begin_define
define|#
directive|define
name|swclose
value|(d_close_t *)enodev
end_define

begin_decl_stmt
name|d_strategy_t
name|swstrategy
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|swioctl
value|(d_ioctl_t *)enodev
end_define

begin_define
define|#
directive|define
name|swdump
value|(d_dump_t *)enodev
end_define

begin_define
define|#
directive|define
name|swsize
value|(d_psize_t *)enodev
end_define

begin_decl_stmt
name|d_rdwr_t
name|swread
decl_stmt|,
name|swwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bdevsw
name|bdevsw
index|[]
init|=
block|{
block|{
name|wdopen
block|,
name|wdclose
block|,
name|wdstrategy
block|,
name|wdioctl
block|,
comment|/*0*/
name|wddump
block|,
name|wdsize
block|,
literal|0
block|}
block|,
block|{
name|swopen
block|,
name|swclose
block|,
name|swstrategy
block|,
name|swioctl
block|,
comment|/*1*/
name|swdump
block|,
name|swsize
block|,
literal|0
block|}
block|,
block|{
name|Fdopen
block|,
name|fdclose
block|,
name|fdstrategy
block|,
name|fdioctl
block|,
comment|/*2*/
name|fddump
block|,
name|fdsize
block|,
literal|0
block|}
block|,
block|{
name|wtopen
block|,
name|wtclose
block|,
name|wtstrategy
block|,
name|wtioctl
block|,
comment|/*3*/
name|wtdump
block|,
name|wtsize
block|,
name|B_TAPE
block|}
block|,
block|{
name|sdopen
block|,
name|sdclose
block|,
name|sdstrategy
block|,
name|sdioctl
block|,
comment|/*4*/
name|sddump
block|,
name|sdsize
block|,
literal|0
block|}
block|,
block|{
name|stopen
block|,
name|stclose
block|,
name|ststrategy
block|,
name|stioctl
block|,
comment|/*5*/
name|stdump
block|,
name|stsize
block|,
literal|0
block|}
block|,
block|{
name|cdopen
block|,
name|cdclose
block|,
name|cdstrategy
block|,
name|cdioctl
block|,
comment|/*6*/
name|cddump
block|,
name|cdsize
block|,
literal|0
block|}
block|,
block|{
name|mcdopen
block|,
name|mcdclose
block|,
name|mcdstrategy
block|,
name|mcdioctl
block|,
comment|/*7*/
name|mcddump
block|,
name|mcdsize
block|,
literal|0
block|}
block|,
block|{
literal|0
block|, }
comment|/* block major 8 is reserved for local use */
comment|/*  * If you need a bdev major number, please contact the FreeBSD team  * by sending mail to "FreeBSD-hackers@freefall.cdrom.com".  * If you assign one yourself it may conflict with someone else.  */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nblkdev
init|=
sizeof|sizeof
argument_list|(
name|bdevsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|bdevsw
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* console */
end_comment

begin_include
include|#
directive|include
file|"machine/cons.h"
end_include

begin_decl_stmt
name|d_open_t
name|cnopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|cnclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|cnread
decl_stmt|,
name|cnwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|cnioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|cnselect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* more console */
end_comment

begin_decl_stmt
name|d_open_t
name|pcopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|pcclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|pcread
decl_stmt|,
name|pcwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|pcioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_mmap_t
name|pcmmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tty
modifier|*
name|pccons
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* controlling TTY */
end_comment

begin_decl_stmt
name|d_open_t
name|cttyopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|cttyread
decl_stmt|,
name|cttywrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|cttyioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|cttyselect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* /dev/mem */
end_comment

begin_decl_stmt
name|d_open_t
name|mmopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|mmclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|mmrw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_mmap_t
name|memmmap
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|mmselect
value|seltrue
end_define

begin_include
include|#
directive|include
file|"pty.h"
end_include

begin_if
if|#
directive|if
name|NPTY
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|ptsopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ptsclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|ptsread
decl_stmt|,
name|ptswrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|ptsstop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|ptcopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ptcclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|ptcread
decl_stmt|,
name|ptcwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|ptcselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ptyioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tty
modifier|*
name|pt_tty
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ptsopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|ptsclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|ptsread
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|ptswrite
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|ptcopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|ptcclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|ptcread
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|ptcwrite
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|ptyioctl
value|(d_ioctl_t *)enxio
end_define

begin_define
define|#
directive|define
name|pt_tty
value|NULL
end_define

begin_define
define|#
directive|define
name|ptcselect
value|(d_select_t *)enxio
end_define

begin_define
define|#
directive|define
name|ptsstop
value|(d_stop_t *)nullop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"com.h"
end_include

begin_if
if|#
directive|if
name|NCOM
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|comopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|comclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|comread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|comwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|comioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|comselect
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|comreset
value|(d_reset_t *)enxio
end_define

begin_decl_stmt
specifier|extern
name|struct
name|tty
modifier|*
name|com_tty
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|comopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|comclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|comread
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|comwrite
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|comioctl
value|(d_ioctl_t *)enxio
end_define

begin_define
define|#
directive|define
name|comreset
value|(d_reset_t *)enxio
end_define

begin_define
define|#
directive|define
name|comselect
value|(d_select_t *)enxio
end_define

begin_define
define|#
directive|define
name|com_tty
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* /dev/klog */
end_comment

begin_decl_stmt
name|d_open_t
name|logopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|logclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|logread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|logioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|logselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|ttselect
decl_stmt|,
name|seltrue
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"lpt.h"
end_include

begin_if
if|#
directive|if
name|NLPT
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|lptopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|lptclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|lptwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|lptioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|lptopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|lptclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|lptwrite
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|lptioctl
value|(d_ioctl_t *)enxio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"tw.h"
end_include

begin_if
if|#
directive|if
name|NTW
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|twopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|twclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|twread
decl_stmt|,
name|twwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|twselect
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|twopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|twclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|twread
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|twwrite
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|twselect
value|(d_select_t *)enxio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sb.h"
end_include

begin_comment
comment|/* Sound Blaster */
end_comment

begin_if
if|#
directive|if
name|NSB
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|sbopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|sbclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|sbioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|sbread
decl_stmt|,
name|sbwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|sbselect
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sbopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|sbclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|sbioctl
value|(d_ioctl_t *)enxio
end_define

begin_define
define|#
directive|define
name|sbread
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|sbwrite
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|sbselect
value|seltrue
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"psm.h"
end_include

begin_if
if|#
directive|if
name|NPSM
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|psmopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|psmclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|psmread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|psmselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|psmioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|psmopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|psmclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|psmread
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|psmselect
value|(d_select_t *)enxio
end_define

begin_define
define|#
directive|define
name|psmioctl
value|(d_ioctl_t *)enxio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"snd.h"
end_include

begin_comment
comment|/* General Sound Driver */
end_comment

begin_if
if|#
directive|if
name|NSND
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|sndopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|sndclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|sndioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|sndread
decl_stmt|,
name|sndwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|sndselect
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sndopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|sndclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|sndioctl
value|(d_ioctl_t *)enxio
end_define

begin_define
define|#
directive|define
name|sndread
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|sndwrite
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|sndselect
value|seltrue
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* /dev/fd/NNN */
end_comment

begin_decl_stmt
name|d_open_t
name|fdopen
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"bpfilter.h"
end_include

begin_if
if|#
directive|if
name|NBPFILTER
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|bpfopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|bpfclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|bpfread
decl_stmt|,
name|bpfwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|bpfselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|bpfioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|bpfopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|bpfclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|bpfread
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|bpfwrite
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|bpfselect
value|(d_select_t *)enxio
end_define

begin_define
define|#
directive|define
name|bpfioctl
value|(d_ioctl_t *)enxio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"lpa.h"
end_include

begin_if
if|#
directive|if
name|NLPA
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|lpaopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|lpaclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|lpawrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|lpaioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|lpaopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|lpaclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|lpawrite
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|lpaioctl
value|(d_ioctl_t *)enxio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"speaker.h"
end_include

begin_if
if|#
directive|if
name|NSPEAKER
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|spkropen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|spkrclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|spkrwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|spkrioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|spkropen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|spkrclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|spkrwrite
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|spkrioctl
value|(d_ioctl_t *)enxio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"pca.h"
end_include

begin_if
if|#
directive|if
name|NPCA
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|pcaopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|pcaclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|pcawrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|pcaioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|pcaopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|pcaclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|pcawrite
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|pcaioctl
value|(d_ioctl_t *)enxio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"mse.h"
end_include

begin_if
if|#
directive|if
name|NMSE
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|mseopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|mseclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|mseread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|mseselect
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mseopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|mseclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|mseread
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|mseselect
value|(d_select_t *)enxio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sio.h"
end_include

begin_if
if|#
directive|if
name|NSIO
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|sioopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|sioclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|sioread
decl_stmt|,
name|siowrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|sioioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|sioselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|siostop
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sioreset
value|(d_reset_t *)enxio
end_define

begin_decl_stmt
specifier|extern
name|struct
name|tty
modifier|*
name|sio_tty
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sioopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|sioclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|sioread
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|siowrite
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|sioioctl
value|(d_ioctl_t *)enxio
end_define

begin_define
define|#
directive|define
name|siostop
value|(d_stop_t *)enxio
end_define

begin_define
define|#
directive|define
name|sioreset
value|(d_reset_t *)enxio
end_define

begin_define
define|#
directive|define
name|sioselect
value|(d_select_t *)enxio
end_define

begin_define
define|#
directive|define
name|sio_tty
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"su.h"
end_include

begin_if
if|#
directive|if
name|NSU
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|suopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|suclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|suioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|suopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|suclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|suioctl
value|(d_ioctl_t *)enxio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"uk.h"
end_include

begin_if
if|#
directive|if
name|NUK
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|ukopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ukclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ukioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ukopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|ukclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|ukioctl
value|(d_ioctl_t *)enxio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|noopen
value|(d_open_t *)enodev
end_define

begin_define
define|#
directive|define
name|noclose
value|(d_close_t *)enodev
end_define

begin_define
define|#
directive|define
name|noread
value|(d_rdwr_t *)enodev
end_define

begin_define
define|#
directive|define
name|nowrite
value|noread
end_define

begin_define
define|#
directive|define
name|noioc
value|(d_ioctl_t *)enodev
end_define

begin_define
define|#
directive|define
name|nostop
value|(d_stop_t *)enodev
end_define

begin_define
define|#
directive|define
name|noreset
value|(d_reset_t *)enodev
end_define

begin_define
define|#
directive|define
name|noselect
value|(d_select_t *)enodev
end_define

begin_define
define|#
directive|define
name|nommap
value|(d_mmap_t *)enodev
end_define

begin_define
define|#
directive|define
name|nostrat
value|(d_strategy_t *)enodev
end_define

begin_define
define|#
directive|define
name|nullopen
value|(d_open_t *)nullop
end_define

begin_define
define|#
directive|define
name|nullclose
value|(d_close_t *)nullop
end_define

begin_define
define|#
directive|define
name|nullstop
value|(d_stop_t *)nullop
end_define

begin_define
define|#
directive|define
name|nullreset
value|(d_reset_t *)nullop
end_define

begin_comment
comment|/* open, close, read, write, ioctl, stop, reset, ttys, select, mmap, strat */
end_comment

begin_decl_stmt
name|struct
name|cdevsw
name|cdevsw
index|[]
init|=
block|{
block|{
name|cnopen
block|,
name|cnclose
block|,
name|cnread
block|,
name|cnwrite
block|,
comment|/*0*/
name|cnioctl
block|,
name|nullstop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* console */
name|cnselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|cttyopen
block|,
name|nullclose
block|,
name|cttyread
block|,
name|cttywrite
block|,
comment|/*1*/
name|cttyioctl
block|,
name|nullstop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* tty */
name|cttyselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|mmopen
block|,
name|mmclose
block|,
name|mmrw
block|,
name|mmrw
block|,
comment|/*2*/
name|noioc
block|,
name|nullstop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* memory */
name|mmselect
block|,
name|memmmap
block|,
name|NULL
block|}
block|,
block|{
name|wdopen
block|,
name|wdclose
block|,
name|rawread
block|,
name|rawwrite
block|,
comment|/*3*/
name|wdioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* wd */
name|seltrue
block|,
name|nommap
block|,
name|wdstrategy
block|}
block|,
block|{
name|nullopen
block|,
name|nullclose
block|,
name|rawread
block|,
name|rawwrite
block|,
comment|/*4*/
name|noioc
block|,
name|nostop
block|,
name|noreset
block|,
name|NULL
block|,
comment|/* swap */
name|noselect
block|,
name|nommap
block|,
name|swstrategy
block|}
block|,
block|{
name|ptsopen
block|,
name|ptsclose
block|,
name|ptsread
block|,
name|ptswrite
block|,
comment|/*5*/
name|ptyioctl
block|,
name|ptsstop
block|,
name|nullreset
block|,
name|pt_tty
block|,
comment|/* ttyp */
name|ttselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|ptcopen
block|,
name|ptcclose
block|,
name|ptcread
block|,
name|ptcwrite
block|,
comment|/*6*/
name|ptyioctl
block|,
name|nullstop
block|,
name|nullreset
block|,
name|pt_tty
block|,
comment|/* ptyp */
name|ptcselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|logopen
block|,
name|logclose
block|,
name|logread
block|,
name|nowrite
block|,
comment|/*7*/
name|logioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* klog */
name|logselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|comopen
block|,
name|comclose
block|,
name|comread
block|,
name|comwrite
block|,
comment|/*8*/
name|comioctl
block|,
name|nostop
block|,
name|comreset
block|,
name|com_tty
block|,
comment|/* com */
name|comselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|Fdopen
block|,
name|fdclose
block|,
name|rawread
block|,
name|rawwrite
block|,
comment|/*9*/
name|fdioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* Fd (!=fd) */
name|seltrue
block|,
name|nommap
block|,
name|fdstrategy
block|}
block|,
block|{
name|wtopen
block|,
name|wtclose
block|,
name|rawread
block|,
name|rawwrite
block|,
comment|/*10*/
name|wtioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* wt */
name|seltrue
block|,
name|nommap
block|,
name|wtstrategy
block|}
block|,
block|{
name|noopen
block|,
name|noclose
block|,
name|noread
block|,
name|nowrite
block|,
comment|/*11*/
name|noioc
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
name|seltrue
block|,
name|nommap
block|,
name|nostrat
block|}
block|,
block|{
name|pcopen
block|,
name|pcclose
block|,
name|pcread
block|,
name|pcwrite
block|,
comment|/*12*/
name|pcioctl
block|,
name|nullstop
block|,
name|nullreset
block|,
operator|&
name|pccons
block|,
comment|/* pc */
name|ttselect
block|,
name|pcmmap
block|,
name|NULL
block|}
block|,
block|{
name|sdopen
block|,
name|sdclose
block|,
name|rawread
block|,
name|rawwrite
block|,
comment|/*13*/
name|sdioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* sd */
name|seltrue
block|,
name|nommap
block|,
name|sdstrategy
block|}
block|,
block|{
name|stopen
block|,
name|stclose
block|,
name|rawread
block|,
name|rawwrite
block|,
comment|/*14*/
name|stioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* st */
name|seltrue
block|,
name|nommap
block|,
name|ststrategy
block|}
block|,
block|{
name|cdopen
block|,
name|cdclose
block|,
name|rawread
block|,
name|nowrite
block|,
comment|/*15*/
name|cdioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* cd */
name|seltrue
block|,
name|nommap
block|,
name|cdstrategy
block|}
block|,
block|{
name|lptopen
block|,
name|lptclose
block|,
name|noread
block|,
name|lptwrite
block|,
comment|/*16*/
name|lptioctl
block|,
name|nullstop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* lpt */
name|seltrue
block|,
name|nommap
block|,
name|nostrat
block|}
block|,
block|{
name|chopen
block|,
name|chclose
block|,
name|noread
block|,
name|nowrite
block|,
comment|/*17*/
name|chioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* ch */
name|noselect
block|,
name|nommap
block|,
name|nostrat
block|}
block|,
block|{
name|suopen
block|,
name|suclose
block|,
name|noread
block|,
name|nowrite
block|,
comment|/*18*/
name|suioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* scsi 'generic' */
name|seltrue
block|,
name|nommap
block|,
name|nostrat
block|}
block|,
block|{
name|twopen
block|,
name|twclose
block|,
name|twread
block|,
name|twwrite
block|,
comment|/*19*/
name|noioc
block|,
name|nullstop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* tw */
name|twselect
block|,
name|nommap
block|,
name|nostrat
block|}
block|,
block|{
name|sbopen
block|,
name|sbclose
block|,
name|sbread
block|,
name|sbwrite
block|,
comment|/*20*/
name|sbioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* soundblaster*/
name|sbselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|psmopen
block|,
name|psmclose
block|,
name|psmread
block|,
name|nowrite
block|,
comment|/*21*/
name|psmioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* psm mice */
name|psmselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|fdopen
block|,
name|noclose
block|,
name|noread
block|,
name|nowrite
block|,
comment|/*22*/
name|noioc
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* fd (!=Fd) */
name|noselect
block|,
name|nommap
block|,
name|nostrat
block|}
block|,
block|{
name|bpfopen
block|,
name|bpfclose
block|,
name|bpfread
block|,
name|bpfwrite
block|,
comment|/*23*/
name|bpfioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* bpf */
name|bpfselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|pcaopen
block|,
name|pcaclose
block|,
name|noread
block|,
name|pcawrite
block|,
comment|/*24*/
name|pcaioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* pcaudio */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|lpaopen
block|,
name|lpaclose
block|,
name|noread
block|,
name|lpawrite
block|,
comment|/*25*/
name|lpaioctl
block|,
name|nullstop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* lpa */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|spkropen
block|,
name|spkrclose
block|,
name|noread
block|,
name|spkrwrite
block|,
comment|/*26*/
name|spkrioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* spkr */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|mseopen
block|,
name|mseclose
block|,
name|mseread
block|,
name|nowrite
block|,
comment|/*27*/
name|noioc
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* mse */
name|mseselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|sioopen
block|,
name|sioclose
block|,
name|sioread
block|,
name|siowrite
block|,
comment|/*28*/
name|sioioctl
block|,
name|siostop
block|,
name|sioreset
block|,
name|sio_tty
block|,
comment|/* sio */
name|sioselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|mcdopen
block|,
name|mcdclose
block|,
name|rawread
block|,
name|nowrite
block|,
comment|/*29*/
name|mcdioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* mitsumi cd */
name|seltrue
block|,
name|nommap
block|,
name|mcdstrategy
block|}
block|,
block|{
name|sndopen
block|,
name|sndclose
block|,
name|sndread
block|,
name|sndwrite
block|,
comment|/*30*/
name|sndioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* sound driver */
name|sndselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|ukopen
block|,
name|ukclose
block|,
name|noread
block|,
name|nowrite
block|,
comment|/*31*/
name|ukioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|NULL
block|,
comment|/* unknown */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
comment|/* scsi */
block|{
literal|0
block|, }
comment|/* character device 32 is reserved for local use */
comment|/*  * If you need a cdev major number, please contact the FreeBSD team  * by sending mail to `freebsd-hackers@freefall.cdrom.com'.  * If you assign one yourself it may then conflict with someone else.  */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nchrdev
init|=
sizeof|sizeof
argument_list|(
name|cdevsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|cdevsw
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mem_no
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* major device number of memory special file */
end_comment

begin_comment
comment|/*  * Swapdev is a fake device implemented  * in sw.c used only internally to get to swstrategy.  * It cannot be provided to the users, because the  * swstrategy routine munches the b_dev and b_blkno entries  * before calling the appropriate driver.  This would horribly  * confuse, e.g. the hashing routines. Instead, /dev/drum is  * provided as a character (raw) device.  */
end_comment

begin_decl_stmt
name|dev_t
name|swapdev
init|=
name|makedev
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

