begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)conf.c	5.8 (Berkeley) 5/12/91  *	$Id: conf.c,v 1.13 1993/10/26 22:25:20 nate Exp $  */
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
decl_stmt|,
name|rawread
argument_list|()
decl_stmt|,
name|rawwrite
argument_list|()
decl_stmt|,
name|swstrategy
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rawread
argument_list|()
decl_stmt|,
name|rawwrite
argument_list|()
decl_stmt|,
name|swstrategy
argument_list|()
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"wd.h"
end_include

begin_include
include|#
directive|include
file|"wx.h"
end_include

begin_if
if|#
directive|if
operator|(
name|NWD
operator|>
literal|0
operator|)
operator|||
operator|(
name|NWX
operator|>
literal|0
operator|)
end_if

begin_decl_stmt
name|int
name|wdopen
argument_list|()
decl_stmt|,
name|wdclose
argument_list|()
decl_stmt|,
name|wdstrategy
argument_list|()
decl_stmt|,
name|wdioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wddump
argument_list|()
decl_stmt|,
name|wdsize
argument_list|()
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
value|enxio
end_define

begin_define
define|#
directive|define
name|wdclose
value|enxio
end_define

begin_define
define|#
directive|define
name|wdstrategy
value|enxio
end_define

begin_define
define|#
directive|define
name|wdioctl
value|enxio
end_define

begin_define
define|#
directive|define
name|wddump
value|enxio
end_define

begin_define
define|#
directive|define
name|wdsize
value|NULL
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
name|int
name|sdopen
argument_list|()
decl_stmt|,
name|sdclose
argument_list|()
decl_stmt|,
name|sdstrategy
argument_list|()
decl_stmt|,
name|sdioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sddump
argument_list|()
decl_stmt|,
name|sdsize
argument_list|()
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
value|enxio
end_define

begin_define
define|#
directive|define
name|sdclose
value|enxio
end_define

begin_define
define|#
directive|define
name|sdstrategy
value|enxio
end_define

begin_define
define|#
directive|define
name|sdioctl
value|enxio
end_define

begin_define
define|#
directive|define
name|sddump
value|enxio
end_define

begin_define
define|#
directive|define
name|sdsize
value|NULL
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
name|int
name|stopen
argument_list|()
decl_stmt|,
name|stclose
argument_list|()
decl_stmt|,
name|ststrategy
argument_list|()
decl_stmt|,
name|stioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*int	stdump(),stsize();*/
end_comment

begin_define
define|#
directive|define
name|stdump
value|enxio
end_define

begin_define
define|#
directive|define
name|stsize
value|NULL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|stopen
value|enxio
end_define

begin_define
define|#
directive|define
name|stclose
value|enxio
end_define

begin_define
define|#
directive|define
name|ststrategy
value|enxio
end_define

begin_define
define|#
directive|define
name|stioctl
value|enxio
end_define

begin_define
define|#
directive|define
name|stdump
value|enxio
end_define

begin_define
define|#
directive|define
name|stsize
value|NULL
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
name|int
name|cdopen
argument_list|()
decl_stmt|,
name|cdclose
argument_list|()
decl_stmt|,
name|cdstrategy
argument_list|()
decl_stmt|,
name|cdioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
comment|/*cddump(),*/
name|cdsize
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|cddump
value|enxio
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cdopen
value|enxio
end_define

begin_define
define|#
directive|define
name|cdclose
value|enxio
end_define

begin_define
define|#
directive|define
name|cdstrategy
value|enxio
end_define

begin_define
define|#
directive|define
name|cdioctl
value|enxio
end_define

begin_define
define|#
directive|define
name|cddump
value|enxio
end_define

begin_define
define|#
directive|define
name|cdsize
value|NULL
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
name|int
name|mcdopen
argument_list|()
decl_stmt|,
name|mcdclose
argument_list|()
decl_stmt|,
name|mcdstrategy
argument_list|()
decl_stmt|,
name|mcdioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
comment|/*mcddump(),*/
name|mcdsize
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|mcddump
value|enxio
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mcdopen
value|enxio
end_define

begin_define
define|#
directive|define
name|mcdclose
value|enxio
end_define

begin_define
define|#
directive|define
name|mcdstrategy
value|enxio
end_define

begin_define
define|#
directive|define
name|mcdioctl
value|enxio
end_define

begin_define
define|#
directive|define
name|mcddump
value|enxio
end_define

begin_define
define|#
directive|define
name|mcdsize
value|NULL
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
name|int
name|chopen
argument_list|()
decl_stmt|,
name|chclose
argument_list|()
decl_stmt|,
name|chioctl
argument_list|()
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
value|enxio
end_define

begin_define
define|#
directive|define
name|chclose
value|enxio
end_define

begin_define
define|#
directive|define
name|chioctl
value|enxio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sg.h"
end_include

begin_if
if|#
directive|if
name|NSG
operator|>
literal|0
end_if

begin_decl_stmt
name|int
name|sgopen
argument_list|()
decl_stmt|,
name|sgclose
argument_list|()
decl_stmt|,
name|sgioctl
argument_list|()
decl_stmt|,
name|sgstrategy
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sgdump
value|enxio
end_define

begin_define
define|#
directive|define
name|sgsize
value|NULL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sgopen
value|enxio
end_define

begin_define
define|#
directive|define
name|sgclose
value|enxio
end_define

begin_define
define|#
directive|define
name|sgstrategy
value|enxio
end_define

begin_define
define|#
directive|define
name|sgioctl
value|enxio
end_define

begin_define
define|#
directive|define
name|sgdump
value|enxio
end_define

begin_define
define|#
directive|define
name|sgsize
value|NULL
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
name|int
name|wtopen
argument_list|()
decl_stmt|,
name|wtclose
argument_list|()
decl_stmt|,
name|wtstrategy
argument_list|()
decl_stmt|,
name|wtioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wtdump
argument_list|()
decl_stmt|,
name|wtsize
argument_list|()
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
value|enxio
end_define

begin_define
define|#
directive|define
name|wtclose
value|enxio
end_define

begin_define
define|#
directive|define
name|wtstrategy
value|enxio
end_define

begin_define
define|#
directive|define
name|wtioctl
value|enxio
end_define

begin_define
define|#
directive|define
name|wtdump
value|enxio
end_define

begin_define
define|#
directive|define
name|wtsize
value|NULL
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
name|int
name|Fdopen
argument_list|()
decl_stmt|,
name|fdclose
argument_list|()
decl_stmt|,
name|fdstrategy
argument_list|()
decl_stmt|,
name|fdioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fddump
value|enxio
end_define

begin_define
define|#
directive|define
name|fdsize
value|NULL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Fdopen
value|enxio
end_define

begin_define
define|#
directive|define
name|fdclose
value|enxio
end_define

begin_define
define|#
directive|define
name|fdstrategy
value|enxio
end_define

begin_define
define|#
directive|define
name|fdioctl
value|enxio
end_define

begin_define
define|#
directive|define
name|fddump
value|enxio
end_define

begin_define
define|#
directive|define
name|fdsize
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|swstrategy
argument_list|()
decl_stmt|,
name|swread
argument_list|()
decl_stmt|,
name|swwrite
argument_list|()
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
name|NULL
block|}
block|,
block|{
name|enodev
block|,
name|enodev
block|,
name|swstrategy
block|,
name|enodev
block|,
comment|/*1*/
name|enodev
block|,
name|enodev
block|,
name|NULL
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
name|NULL
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
name|NULL
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
name|NULL
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
name|NULL
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
name|NULL
block|}
block|,
comment|/*  * If you need a bdev major number, please contact the 386bsd patchkit  * coordinator by sending mail to "patches@cs.montana.edu".   * If you assign one yourself it may conflict with someone else.  */
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

begin_decl_stmt
name|int
name|cnopen
argument_list|()
decl_stmt|,
name|cnclose
argument_list|()
decl_stmt|,
name|cnread
argument_list|()
decl_stmt|,
name|cnwrite
argument_list|()
decl_stmt|,
name|cnioctl
argument_list|()
decl_stmt|,
name|cnselect
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pcopen
argument_list|()
decl_stmt|,
name|pcclose
argument_list|()
decl_stmt|,
name|pcread
argument_list|()
decl_stmt|,
name|pcwrite
argument_list|()
decl_stmt|,
name|pcioctl
argument_list|()
decl_stmt|,
name|pcmmap
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tty
name|pccons
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cttyopen
argument_list|()
decl_stmt|,
name|cttyread
argument_list|()
decl_stmt|,
name|cttywrite
argument_list|()
decl_stmt|,
name|cttyioctl
argument_list|()
decl_stmt|,
name|cttyselect
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mmopen
argument_list|()
decl_stmt|,
name|mmclose
argument_list|()
decl_stmt|,
name|mmrw
argument_list|()
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
name|int
name|ptsopen
argument_list|()
decl_stmt|,
name|ptsclose
argument_list|()
decl_stmt|,
name|ptsread
argument_list|()
decl_stmt|,
name|ptswrite
argument_list|()
decl_stmt|,
name|ptsstop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ptcopen
argument_list|()
decl_stmt|,
name|ptcclose
argument_list|()
decl_stmt|,
name|ptcread
argument_list|()
decl_stmt|,
name|ptcwrite
argument_list|()
decl_stmt|,
name|ptcselect
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ptyioctl
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|tty
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
value|enxio
end_define

begin_define
define|#
directive|define
name|ptsclose
value|enxio
end_define

begin_define
define|#
directive|define
name|ptsread
value|enxio
end_define

begin_define
define|#
directive|define
name|ptswrite
value|enxio
end_define

begin_define
define|#
directive|define
name|ptcopen
value|enxio
end_define

begin_define
define|#
directive|define
name|ptcclose
value|enxio
end_define

begin_define
define|#
directive|define
name|ptcread
value|enxio
end_define

begin_define
define|#
directive|define
name|ptcwrite
value|enxio
end_define

begin_define
define|#
directive|define
name|ptyioctl
value|enxio
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
value|enxio
end_define

begin_define
define|#
directive|define
name|ptsstop
value|nullop
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
name|int
name|comopen
argument_list|()
decl_stmt|,
name|comclose
argument_list|()
decl_stmt|,
name|comread
argument_list|()
decl_stmt|,
name|comwrite
argument_list|()
decl_stmt|,
name|comioctl
argument_list|()
decl_stmt|,
name|comselect
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|comreset
value|enxio
end_define

begin_decl_stmt
specifier|extern
name|struct
name|tty
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
value|enxio
end_define

begin_define
define|#
directive|define
name|comclose
value|enxio
end_define

begin_define
define|#
directive|define
name|comread
value|enxio
end_define

begin_define
define|#
directive|define
name|comwrite
value|enxio
end_define

begin_define
define|#
directive|define
name|comioctl
value|enxio
end_define

begin_define
define|#
directive|define
name|comreset
value|enxio
end_define

begin_define
define|#
directive|define
name|comselect
value|enxio
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

begin_decl_stmt
name|int
name|logopen
argument_list|()
decl_stmt|,
name|logclose
argument_list|()
decl_stmt|,
name|logread
argument_list|()
decl_stmt|,
name|logioctl
argument_list|()
decl_stmt|,
name|logselect
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttselect
argument_list|()
decl_stmt|,
name|seltrue
argument_list|()
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
name|int
name|lptopen
argument_list|()
decl_stmt|,
name|lptclose
argument_list|()
decl_stmt|,
name|lptwrite
argument_list|()
decl_stmt|,
name|lptioctl
argument_list|()
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
value|enxio
end_define

begin_define
define|#
directive|define
name|lptclose
value|enxio
end_define

begin_define
define|#
directive|define
name|lptwrite
value|enxio
end_define

begin_define
define|#
directive|define
name|lptioctl
value|enxio
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
name|int
name|twopen
argument_list|()
decl_stmt|,
name|twclose
argument_list|()
decl_stmt|,
name|twread
argument_list|()
decl_stmt|,
name|twwrite
argument_list|()
decl_stmt|,
name|twselect
argument_list|()
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
value|enxio
end_define

begin_define
define|#
directive|define
name|twclose
value|enxio
end_define

begin_define
define|#
directive|define
name|twread
value|enxio
end_define

begin_define
define|#
directive|define
name|twwrite
value|enxio
end_define

begin_define
define|#
directive|define
name|twselect
value|enxio
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
name|int
name|sbopen
argument_list|()
decl_stmt|,
name|sbclose
argument_list|()
decl_stmt|,
name|sbioctl
argument_list|()
decl_stmt|,
name|sbread
argument_list|()
decl_stmt|,
name|sbwrite
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|sbselect
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sbopen
value|enxio
end_define

begin_define
define|#
directive|define
name|sbclose
value|enxio
end_define

begin_define
define|#
directive|define
name|sbioctl
value|enxio
end_define

begin_define
define|#
directive|define
name|sbread
value|enxio
end_define

begin_define
define|#
directive|define
name|sbwrite
value|enxio
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
name|int
name|psmopen
argument_list|()
decl_stmt|,
name|psmclose
argument_list|()
decl_stmt|,
name|psmread
argument_list|()
decl_stmt|,
name|psmselect
argument_list|()
decl_stmt|,
name|psmioctl
argument_list|()
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
value|enxio
end_define

begin_define
define|#
directive|define
name|psmclose
value|enxio
end_define

begin_define
define|#
directive|define
name|psmread
value|enxio
end_define

begin_define
define|#
directive|define
name|psmselect
value|enxio
end_define

begin_define
define|#
directive|define
name|psmioctl
value|enxio
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
name|int
name|sndopen
argument_list|()
decl_stmt|,
name|sndclose
argument_list|()
decl_stmt|,
name|sndioctl
argument_list|()
decl_stmt|,
name|sndread
argument_list|()
decl_stmt|,
name|sndwrite
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|sndselect
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sndopen
value|enxio
end_define

begin_define
define|#
directive|define
name|sndclose
value|enxio
end_define

begin_define
define|#
directive|define
name|sndioctl
value|enxio
end_define

begin_define
define|#
directive|define
name|sndread
value|enxio
end_define

begin_define
define|#
directive|define
name|sndwrite
value|enxio
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

begin_function_decl
name|int
name|fdopen
parameter_list|()
function_decl|;
end_function_decl

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
name|int
name|bpfopen
argument_list|()
decl_stmt|,
name|bpfclose
argument_list|()
decl_stmt|,
name|bpfread
argument_list|()
decl_stmt|,
name|bpfwrite
argument_list|()
decl_stmt|,
name|bpfselect
argument_list|()
decl_stmt|,
name|bpfioctl
argument_list|()
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
value|enxio
end_define

begin_define
define|#
directive|define
name|bpfclose
value|enxio
end_define

begin_define
define|#
directive|define
name|bpfread
value|enxio
end_define

begin_define
define|#
directive|define
name|bpfwrite
value|enxio
end_define

begin_define
define|#
directive|define
name|bpfselect
value|enxio
end_define

begin_define
define|#
directive|define
name|bpfioctl
value|enxio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"dcfclk.h"
end_include

begin_if
if|#
directive|if
name|NDCFCLK
operator|>
literal|0
end_if

begin_decl_stmt
name|int
name|dcfclkopen
argument_list|()
decl_stmt|,
name|dcfclkclose
argument_list|()
decl_stmt|,
name|dcfclkread
argument_list|()
decl_stmt|,
name|dcfclkioctl
argument_list|()
decl_stmt|,
name|dcfclkselect
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dcfclkopen
value|enxio
end_define

begin_define
define|#
directive|define
name|dcfclkclose
value|enxio
end_define

begin_define
define|#
directive|define
name|dcfclkread
value|enxio
end_define

begin_define
define|#
directive|define
name|dcfclkioctl
value|enxio
end_define

begin_define
define|#
directive|define
name|dcfclkselect
value|enxio
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
name|int
name|lpaopen
argument_list|()
decl_stmt|,
name|lpaclose
argument_list|()
decl_stmt|,
name|lpawrite
argument_list|()
decl_stmt|,
name|lpaioctl
argument_list|()
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
value|enxio
end_define

begin_define
define|#
directive|define
name|lpaclose
value|enxio
end_define

begin_define
define|#
directive|define
name|lpawrite
value|enxio
end_define

begin_define
define|#
directive|define
name|lpaioctl
value|enxio
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
name|int
name|spkropen
argument_list|()
decl_stmt|,
name|spkrclose
argument_list|()
decl_stmt|,
name|spkrwrite
argument_list|()
decl_stmt|,
name|spkrioctl
argument_list|()
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
value|enxio
end_define

begin_define
define|#
directive|define
name|spkrclose
value|enxio
end_define

begin_define
define|#
directive|define
name|spkrwrite
value|enxio
end_define

begin_define
define|#
directive|define
name|spkrioctl
value|enxio
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
name|int
name|mseopen
argument_list|()
decl_stmt|,
name|mseclose
argument_list|()
decl_stmt|,
name|mseread
argument_list|()
decl_stmt|,
name|mseselect
argument_list|()
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
value|enxio
end_define

begin_define
define|#
directive|define
name|mseclose
value|enxio
end_define

begin_define
define|#
directive|define
name|mseread
value|enxio
end_define

begin_define
define|#
directive|define
name|mseselect
value|enxio
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
name|int
name|sioopen
argument_list|()
decl_stmt|,
name|sioclose
argument_list|()
decl_stmt|,
name|sioread
argument_list|()
decl_stmt|,
name|siowrite
argument_list|()
decl_stmt|,
name|sioioctl
argument_list|()
decl_stmt|,
name|sioselect
argument_list|()
decl_stmt|,
name|siostop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sioreset
value|enxio
end_define

begin_decl_stmt
specifier|extern
name|struct
name|tty
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
value|enxio
end_define

begin_define
define|#
directive|define
name|sioclose
value|enxio
end_define

begin_define
define|#
directive|define
name|sioread
value|enxio
end_define

begin_define
define|#
directive|define
name|siowrite
value|enxio
end_define

begin_define
define|#
directive|define
name|sioioctl
value|enxio
end_define

begin_define
define|#
directive|define
name|siostop
value|enxio
end_define

begin_define
define|#
directive|define
name|sioreset
value|enxio
end_define

begin_define
define|#
directive|define
name|sioselect
value|enxio
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
name|nullop
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* console */
name|cnselect
block|,
name|enodev
block|,
name|NULL
block|}
block|,
block|{
name|cttyopen
block|,
name|nullop
block|,
name|cttyread
block|,
name|cttywrite
block|,
comment|/*1*/
name|cttyioctl
block|,
name|nullop
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* tty */
name|cttyselect
block|,
name|enodev
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
name|enodev
block|,
name|nullop
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* memory */
name|mmselect
block|,
name|enodev
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
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* wd */
name|seltrue
block|,
name|enodev
block|,
name|wdstrategy
block|}
block|,
block|{
name|nullop
block|,
name|nullop
block|,
name|rawread
block|,
name|rawwrite
block|,
comment|/*4*/
name|enodev
block|,
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* swap */
name|enodev
block|,
name|enodev
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
name|nullop
block|,
name|pt_tty
block|,
comment|/* ttyp */
name|ttselect
block|,
name|enodev
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
name|nullop
block|,
name|nullop
block|,
name|pt_tty
block|,
comment|/* ptyp */
name|ptcselect
block|,
name|enodev
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
name|enodev
block|,
comment|/*7*/
name|logioctl
block|,
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* klog */
name|logselect
block|,
name|enodev
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
name|enodev
block|,
name|comreset
block|,
name|com_tty
block|,
comment|/* com */
name|comselect
block|,
name|enodev
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
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* Fd (!=fd) */
name|seltrue
block|,
name|enodev
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
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* wt */
name|seltrue
block|,
name|enodev
block|,
name|wtstrategy
block|}
block|,
block|{
name|enodev
block|,
name|enodev
block|,
name|enodev
block|,
name|enodev
block|,
comment|/*11*/
name|enodev
block|,
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
name|seltrue
block|,
name|enodev
block|,
name|enodev
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
name|nullop
block|,
name|nullop
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
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* sd */
name|seltrue
block|,
name|enodev
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
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* st */
name|seltrue
block|,
name|enodev
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
name|enodev
block|,
comment|/*15*/
name|cdioctl
block|,
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* cd */
name|seltrue
block|,
name|enodev
block|,
name|cdstrategy
block|}
block|,
block|{
name|lptopen
block|,
name|lptclose
block|,
name|nullop
block|,
name|lptwrite
block|,
comment|/*16*/
name|lptioctl
block|,
name|nullop
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* lpt */
name|seltrue
block|,
name|enodev
block|,
name|enodev
block|}
block|,
block|{
name|chopen
block|,
name|chclose
block|,
name|enxio
block|,
name|enxio
block|,
comment|/*17*/
name|chioctl
block|,
name|enxio
block|,
name|enxio
block|,
name|NULL
block|,
comment|/* ch */
name|enxio
block|,
name|enxio
block|,
name|enxio
block|}
block|,
block|{
name|sgopen
block|,
name|sgclose
block|,
name|enodev
block|,
name|enodev
block|,
comment|/*18*/
name|sgioctl
block|,
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* scsi 'generic' */
name|seltrue
block|,
name|enodev
block|,
name|sgstrategy
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
name|enodev
block|,
name|nullop
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* tw */
name|twselect
block|,
name|enodev
block|,
name|enodev
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
name|enodev
block|,
name|enodev
block|,
name|NULL
block|,
comment|/* soundblaster*/
name|sbselect
block|,
name|enodev
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
name|nullop
block|,
comment|/*21*/
name|psmioctl
block|,
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* psm mice */
name|psmselect
block|,
name|enodev
block|,
name|NULL
block|}
block|,
block|{
name|fdopen
block|,
name|enxio
block|,
name|enxio
block|,
name|enxio
block|,
comment|/*22*/
name|enxio
block|,
name|enxio
block|,
name|enxio
block|,
name|NULL
block|,
comment|/* fd (!=Fd) */
name|enxio
block|,
name|enxio
block|,
name|enxio
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
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* bpf */
name|bpfselect
block|,
name|enodev
block|,
name|NULL
block|}
block|,
block|{
name|dcfclkopen
block|,
name|dcfclkclose
block|,
name|dcfclkread
block|,
name|enodev
block|,
comment|/*24*/
name|dcfclkioctl
block|,
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* dcfclk */
name|dcfclkselect
block|,
name|enodev
block|,
name|NULL
block|}
block|,
block|{
name|lpaopen
block|,
name|lpaclose
block|,
name|nullop
block|,
name|lpawrite
block|,
comment|/*25*/
name|lpaioctl
block|,
name|nullop
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* lpa */
name|seltrue
block|,
name|enodev
block|,
name|enodev
block|}
block|,
block|{
name|spkropen
block|,
name|spkrclose
block|,
name|enxio
block|,
name|spkrwrite
block|,
comment|/*26*/
name|spkrioctl
block|,
name|enxio
block|,
name|enxio
block|,
name|NULL
block|,
comment|/* spkr */
name|enxio
block|,
name|enxio
block|,
name|enxio
block|}
block|,
block|{
name|mseopen
block|,
name|mseclose
block|,
name|mseread
block|,
name|nullop
block|,
comment|/*27*/
name|nullop
block|,
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* mse */
name|mseselect
block|,
name|enodev
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
name|enodev
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
name|enodev
block|,
comment|/*29*/
name|mcdioctl
block|,
name|enodev
block|,
name|nullop
block|,
name|NULL
block|,
comment|/* mitsumi cd */
name|seltrue
block|,
name|enodev
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
name|enodev
block|,
name|enodev
block|,
name|NULL
block|,
comment|/* sound driver */
name|sndselect
block|,
name|enodev
block|,
name|NULL
block|}
block|,
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

