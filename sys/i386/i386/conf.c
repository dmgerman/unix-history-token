begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) UNIX System Laboratories, Inc.  All or some portions  * of this file are derived from material licensed to the  * University of California by American Telephone and Telegraph Co.  * or UNIX System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)conf.c	5.8 (Berkeley) 5/12/91  * $FreeBSD$  */
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
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

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

begin_comment
comment|/* Lots of bogus defines for shorthand purposes */
end_comment

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
name|nodump
value|(d_dump_t *)enodev
end_define

begin_define
define|#
directive|define
name|nodevtotty
value|(d_ttycv_t *)nullop
end_define

begin_define
define|#
directive|define
name|nxopen
value|(d_open_t *)enxio
end_define

begin_define
define|#
directive|define
name|nxclose
value|(d_close_t *)enxio
end_define

begin_define
define|#
directive|define
name|nxread
value|(d_rdwr_t *)enxio
end_define

begin_define
define|#
directive|define
name|nxwrite
value|nxread
end_define

begin_define
define|#
directive|define
name|nxstrategy
value|(d_strategy_t *)enxio
end_define

begin_define
define|#
directive|define
name|nxioctl
value|(d_ioctl_t *)enxio
end_define

begin_define
define|#
directive|define
name|nxdump
value|(d_dump_t *)enxio
end_define

begin_define
define|#
directive|define
name|nxstop
value|(d_stop_t *)enxio
end_define

begin_define
define|#
directive|define
name|nxreset
value|(d_reset_t *)enxio
end_define

begin_define
define|#
directive|define
name|nxselect
value|(d_select_t *)enxio
end_define

begin_define
define|#
directive|define
name|nxmmap
value|nommap
end_define

begin_comment
comment|/* must return -1, not ENXIO */
end_comment

begin_define
define|#
directive|define
name|nxdevtotty
value|(d_ttycv_t *)nullop
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

begin_define
define|#
directive|define
name|zerosize
value|(d_psize_t *)0
end_define

begin_function_decl
name|int
name|lkmenodev
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|lkmopen
value|(d_open_t *)lkmenodev
end_define

begin_define
define|#
directive|define
name|lkmclose
value|(d_close_t *)lkmenodev
end_define

begin_define
define|#
directive|define
name|lkmread
value|(d_rdwr_t *)lkmenodev
end_define

begin_define
define|#
directive|define
name|lkmwrite
value|(d_rdwr_t *)lkmenodev
end_define

begin_define
define|#
directive|define
name|lkmstrategy
value|(d_strategy_t *)lkmenodev
end_define

begin_define
define|#
directive|define
name|lkmioctl
value|(d_ioctl_t *)lkmenodev
end_define

begin_define
define|#
directive|define
name|lkmdump
value|(d_dump_t *)lkmenodev
end_define

begin_define
define|#
directive|define
name|lkmsize
value|zerosize
end_define

begin_define
define|#
directive|define
name|lkmstop
value|(d_stop_t *)lkmenodev
end_define

begin_define
define|#
directive|define
name|lkmreset
value|(d_reset_t *)lkmenodev
end_define

begin_define
define|#
directive|define
name|lkmmmap
value|(d_mmap_t *)lkmenodev
end_define

begin_define
define|#
directive|define
name|lkmselect
value|(d_select_t *)lkmenodev
end_define

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
value|nxopen
end_define

begin_define
define|#
directive|define
name|wdclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|wdstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|wdioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|wddump
value|nxdump
end_define

begin_define
define|#
directive|define
name|wdsize
value|zerosize
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"worm.h"
end_include

begin_if
if|#
directive|if
name|NWORM
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|wormopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|wormclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|wormstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|wormioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|wormdump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|wormsize
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|wormopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|wormclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|wormstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|wormioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|wormdump
value|nxdump
end_define

begin_define
define|#
directive|define
name|wormsize
value|zerosize
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sctarg.h"
end_include

begin_if
if|#
directive|if
name|NSCTARG
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|sctargopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|sctargclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|sctargstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|sctargioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|sctargdump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|sctargsize
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sctargopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|sctargclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|sctargstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|sctargioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|sctargdump
value|nxdump
end_define

begin_define
define|#
directive|define
name|sctargsize
value|zerosize
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"pt.h"
end_include

begin_if
if|#
directive|if
name|NPT
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|ptopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ptclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|ptstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ptioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|ptdump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|ptsize
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ptopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|ptclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|ptstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|ptioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|ptdump
value|nxdump
end_define

begin_define
define|#
directive|define
name|ptsize
value|zerosize
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
value|nxopen
end_define

begin_define
define|#
directive|define
name|sdclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|sdstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|sdioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|sddump
value|nxdump
end_define

begin_define
define|#
directive|define
name|sdsize
value|zerosize
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
value|nxdump
end_define

begin_define
define|#
directive|define
name|stsize
value|zerosize
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|stopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|stclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|ststrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|stioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|stdump
value|nxdump
end_define

begin_define
define|#
directive|define
name|stsize
value|zerosize
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"od.h"
end_include

begin_if
if|#
directive|if
name|NOD
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|odopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|odclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|odstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|odioctl
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|oddump
value|nxdump
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|odopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|odclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|odstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|odioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|oddump
value|nxdump
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ccd.h"
end_include

begin_if
if|#
directive|if
name|NCCD
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|ccdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ccdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|ccdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ccdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|ccdsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|ccdread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|ccdwrite
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ccddump
value|nxdump
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ccdopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|ccdclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|ccdstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|ccdioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|ccddump
value|nxdump
end_define

begin_define
define|#
directive|define
name|ccdsize
value|zerosize
end_define

begin_define
define|#
directive|define
name|ccdread
value|nxread
end_define

begin_define
define|#
directive|define
name|ccdwrite
value|nxwrite
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
value|nxdump
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cdopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|cdclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|cdstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|cdioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|cddump
value|nxdump
end_define

begin_define
define|#
directive|define
name|cdsize
value|zerosize
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
value|nxdump
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mcdopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|mcdclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|mcdstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|mcdioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|mcddump
value|nxdump
end_define

begin_define
define|#
directive|define
name|mcdsize
value|zerosize
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"scd.h"
end_include

begin_if
if|#
directive|if
name|NSCD
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|scdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|scdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|scdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|scdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|scdsize
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|scddump
value|nxdump
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|scdopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|scdclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|scdstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|scdioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|scddump
value|nxdump
end_define

begin_define
define|#
directive|define
name|scdsize
value|zerosize
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"matcd.h"
end_include

begin_if
if|#
directive|if
name|NMATCD
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|matcdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|matcdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|matcdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|matcdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|matcddump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|matcdsize
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|matcddump
value|nxdump
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|matcdopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|matcdclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|matcdstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|matcdioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|matcddump
value|nxdump
end_define

begin_define
define|#
directive|define
name|matcdsize
value|(d_psize_t *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ata.h"
end_include

begin_if
if|#
directive|if
operator|(
name|NATA
operator|>
literal|0
operator|)
end_if

begin_decl_stmt
name|d_open_t
name|ataopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ataclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|atastrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ataioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|atasize
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|atadump
value|nxdump
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ataopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|ataclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|atastrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|ataioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|atasize
value|zerosize
end_define

begin_define
define|#
directive|define
name|atadump
value|nxdump
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"wcd.h"
end_include

begin_if
if|#
directive|if
name|NWCD
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|wcdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|wcdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|wcdstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|wcdioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|wcdopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|wcdclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|wcdstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|wcdioctl
value|nxioctl
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
value|nxopen
end_define

begin_define
define|#
directive|define
name|chclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|chioctl
value|nxioctl
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
value|nxopen
end_define

begin_define
define|#
directive|define
name|wtclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|wtstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|wtioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|wtdump
value|nxdump
end_define

begin_define
define|#
directive|define
name|wtsize
value|zerosize
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
value|nxdump
end_define

begin_define
define|#
directive|define
name|fdsize
value|zerosize
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Fdopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|fdclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|fdstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|fdioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|fddump
value|nxdump
end_define

begin_define
define|#
directive|define
name|fdsize
value|zerosize
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"vn.h"
end_include

begin_if
if|#
directive|if
name|NVN
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|vnopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|vnclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|vnstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|vnioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_dump_t
name|vndump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|vnsize
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vnopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|vnclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|vnstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|vnioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|vndump
value|nxdump
end_define

begin_define
define|#
directive|define
name|vnsize
value|zerosize
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Matrox Meteor capture card */
end_comment

begin_include
include|#
directive|include
file|"meteor.h"
end_include

begin_if
if|#
directive|if
name|NMETEOR
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|meteor_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|meteor_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|meteor_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|meteor_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|meteor_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_mmap_t
name|meteor_mmap
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|meteor_open
value|nxopen
end_define

begin_define
define|#
directive|define
name|meteor_close
value|nxclose
end_define

begin_define
define|#
directive|define
name|meteor_read
value|nxread
end_define

begin_define
define|#
directive|define
name|meteor_write
value|nxwrite
end_define

begin_define
define|#
directive|define
name|meteor_ioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|meteor_mmap
value|nxmmap
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Connectix QuickCam camera */
end_comment

begin_include
include|#
directive|include
file|"qcam.h"
end_include

begin_if
if|#
directive|if
name|NQCAM
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|qcam_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|qcam_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|qcam_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|qcam_ioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|qcam_open
value|nxopen
end_define

begin_define
define|#
directive|define
name|qcam_close
value|nxclose
end_define

begin_define
define|#
directive|define
name|qcam_read
value|nxread
end_define

begin_define
define|#
directive|define
name|qcam_ioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|swopen
value|noopen
end_define

begin_define
define|#
directive|define
name|swclose
value|noclose
end_define

begin_define
define|#
directive|define
name|swioctl
value|noioc
end_define

begin_define
define|#
directive|define
name|swdump
value|nodump
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
name|lkmopen
block|,
name|lkmclose
block|,
name|lkmstrategy
block|,
name|lkmioctl
block|,
comment|/*8*/
name|lkmdump
block|,
name|lkmsize
block|,
name|NULL
block|}
block|,
block|{
name|lkmopen
block|,
name|lkmclose
block|,
name|lkmstrategy
block|,
name|lkmioctl
block|,
comment|/*9*/
name|lkmdump
block|,
name|lkmsize
block|,
name|NULL
block|}
block|,
block|{
name|lkmopen
block|,
name|lkmclose
block|,
name|lkmstrategy
block|,
name|lkmioctl
block|,
comment|/*10*/
name|lkmdump
block|,
name|lkmsize
block|,
name|NULL
block|}
block|,
block|{
name|lkmopen
block|,
name|lkmclose
block|,
name|lkmstrategy
block|,
name|lkmioctl
block|,
comment|/*11*/
name|lkmdump
block|,
name|lkmsize
block|,
name|NULL
block|}
block|,
block|{
name|lkmopen
block|,
name|lkmclose
block|,
name|lkmstrategy
block|,
name|lkmioctl
block|,
comment|/*12*/
name|lkmdump
block|,
name|lkmsize
block|,
name|NULL
block|}
block|,
block|{
name|lkmopen
block|,
name|lkmclose
block|,
name|lkmstrategy
block|,
name|lkmioctl
block|,
comment|/*13*/
name|lkmdump
block|,
name|lkmsize
block|,
name|NULL
block|}
block|,
comment|/* block device 14 is reserved for local use */
block|{
name|nxopen
block|,
name|nxclose
block|,
name|nxstrategy
block|,
name|nxioctl
block|,
comment|/*14*/
name|nxdump
block|,
name|zerosize
block|,
name|NULL
block|}
block|,
block|{
name|vnopen
block|,
name|vnclose
block|,
name|vnstrategy
block|,
name|vnioctl
block|,
comment|/*15*/
name|vndump
block|,
name|vnsize
block|,
literal|0
block|}
block|,
block|{
name|scdopen
block|,
name|scdclose
block|,
name|scdstrategy
block|,
name|scdioctl
block|,
comment|/*16*/
name|scddump
block|,
name|scdsize
block|,
literal|0
block|}
block|,
block|{
name|matcdopen
block|,
name|matcdclose
block|,
name|matcdstrategy
block|,
name|matcdioctl
block|,
comment|/*17*/
name|matcddump
block|,
name|matcdsize
block|,
literal|0
block|}
block|,
block|{
name|ataopen
block|,
name|ataclose
block|,
name|atastrategy
block|,
name|ataioctl
block|,
comment|/*18*/
name|atadump
block|,
name|atasize
block|,
literal|0
block|}
block|,
block|{
name|wcdopen
block|,
name|wcdclose
block|,
name|wcdstrategy
block|,
name|wcdioctl
block|,
comment|/*19*/
name|nxdump
block|,
name|zerosize
block|,
literal|0
block|}
block|,
block|{
name|odopen
block|,
name|odclose
block|,
name|odstrategy
block|,
name|odioctl
block|,
comment|/*20*/
name|oddump
block|,
name|zerosize
block|,
literal|0
block|}
block|,
block|{
name|ccdopen
block|,
name|ccdclose
block|,
name|ccdstrategy
block|,
name|ccdioctl
block|,
comment|/*21*/
name|ccddump
block|,
name|ccdsize
block|,
literal|0
block|}
block|,
comment|/*  * If you need a bdev major number for a driver that you intend to donate  * back to the group or release publically, please contact the FreeBSD team  * by sending mail to "FreeBSD-hackers@freefall.cdrom.com".  * If you assign one yourself it may conflict with someone else.  * Otherwise, simply use the one reserved for local use.  */
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

begin_comment
comment|/* more console */
end_comment

begin_include
include|#
directive|include
file|"sc.h"
end_include

begin_include
include|#
directive|include
file|"vt.h"
end_include

begin_if
if|#
directive|if
name|NSC
operator|>
literal|0
end_if

begin_if
if|#
directive|if
name|NVT
operator|>
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|LINT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"sc0 and vt0 are mutually exclusive"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|d_open_t
name|scopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|scclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|scread
decl_stmt|,
name|scwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|scioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_mmap_t
name|scmmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|scdevtotty
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|NVT
operator|>
literal|0
end_elif

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
name|d_ttycv_t
name|pcdevtotty
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|scopen
value|pcopen
end_define

begin_define
define|#
directive|define
name|scclose
value|pcclose
end_define

begin_define
define|#
directive|define
name|scread
value|pcread
end_define

begin_define
define|#
directive|define
name|scwrite
value|pcwrite
end_define

begin_define
define|#
directive|define
name|scioctl
value|pcioctl
end_define

begin_define
define|#
directive|define
name|scmmap
value|pcmmap
end_define

begin_define
define|#
directive|define
name|scdevtotty
value|pcdevtotty
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* neither syscons nor pcvt, i.e. no grafx console driver */
end_comment

begin_define
define|#
directive|define
name|scopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|scclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|scread
value|nxread
end_define

begin_define
define|#
directive|define
name|scwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|scioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|scmmap
value|nxmmap
end_define

begin_define
define|#
directive|define
name|scdevtotty
value|nxdevtotty
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NSC> 0, NVT> 0 */
end_comment

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

begin_decl_stmt
name|d_ioctl_t
name|mmioctl
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|ptcwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|ptcselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|ptydevtotty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ptyioctl
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
value|nxopen
end_define

begin_define
define|#
directive|define
name|ptsclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|ptsread
value|nxread
end_define

begin_define
define|#
directive|define
name|ptswrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|ptcopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|ptcclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|ptcread
value|nxread
end_define

begin_define
define|#
directive|define
name|ptcwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|ptyioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|ptcselect
value|nxselect
end_define

begin_define
define|#
directive|define
name|ptsstop
value|nullstop
end_define

begin_define
define|#
directive|define
name|ptydevtotty
value|nxdevtotty
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"snp.h"
end_include

begin_if
if|#
directive|if
name|NSNP
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|snpopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|snpclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|snpread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|snpwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|snpselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|snpioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|snpopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|snpclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|snpread
value|nxread
end_define

begin_define
define|#
directive|define
name|snpwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|snpioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|snpselect
value|nxselect
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

begin_include
include|#
directive|include
file|"bqu.h"
end_include

begin_if
if|#
directive|if
name|NBQU
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|bquopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|bquclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|bquread
decl_stmt|,
name|bquwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|bquselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|bquioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|bquopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|bquclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|bquread
value|nxread
end_define

begin_define
define|#
directive|define
name|bquwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|bquselect
value|nxselect
end_define

begin_define
define|#
directive|define
name|bquioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|nxopen
end_define

begin_define
define|#
directive|define
name|lptclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|lptwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|lptioctl
value|nxioctl
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

begin_decl_stmt
name|d_ttycv_t
name|twdevtotty
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
value|nxopen
end_define

begin_define
define|#
directive|define
name|twclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|twread
value|nxread
end_define

begin_define
define|#
directive|define
name|twwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|twselect
value|nxselect
end_define

begin_define
define|#
directive|define
name|twdevtotty
value|nxdevtotty
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
value|nxopen
end_define

begin_define
define|#
directive|define
name|psmclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|psmread
value|nxread
end_define

begin_define
define|#
directive|define
name|psmselect
value|nxselect
end_define

begin_define
define|#
directive|define
name|psmioctl
value|nxioctl
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
value|nxopen
end_define

begin_define
define|#
directive|define
name|sndclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|sndioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|sndread
value|nxread
end_define

begin_define
define|#
directive|define
name|sndwrite
value|nxwrite
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
value|nxopen
end_define

begin_define
define|#
directive|define
name|bpfclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|bpfread
value|nxread
end_define

begin_define
define|#
directive|define
name|bpfwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|bpfselect
value|nxselect
end_define

begin_define
define|#
directive|define
name|bpfioctl
value|nxioctl
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
value|nxopen
end_define

begin_define
define|#
directive|define
name|spkrclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|spkrwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|spkrioctl
value|nxioctl
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

begin_decl_stmt
name|d_select_t
name|pcaselect
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
value|nxopen
end_define

begin_define
define|#
directive|define
name|pcaclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|pcawrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|pcaioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|pcaselect
value|nxselect
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
value|nxopen
end_define

begin_define
define|#
directive|define
name|mseclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|mseread
value|nxread
end_define

begin_define
define|#
directive|define
name|mseselect
value|nxselect
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
name|d_stop_t
name|siostop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|siodevtotty
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sioreset
value|nxreset
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sioopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|sioclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|sioread
value|nxread
end_define

begin_define
define|#
directive|define
name|siowrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|sioioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|siostop
value|nxstop
end_define

begin_define
define|#
directive|define
name|sioreset
value|nxreset
end_define

begin_define
define|#
directive|define
name|siodevtotty
value|nxdevtotty
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

begin_decl_stmt
name|d_rdwr_t
name|suread
decl_stmt|,
name|suwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|suselect
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|summap
value|nxmmap
end_define

begin_decl_stmt
name|d_strategy_t
name|sustrategy
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
value|nxopen
end_define

begin_define
define|#
directive|define
name|suclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|suioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|suread
value|nxread
end_define

begin_define
define|#
directive|define
name|suwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|suselect
value|nxselect
end_define

begin_define
define|#
directive|define
name|summap
value|nxmmap
end_define

begin_define
define|#
directive|define
name|sustrategy
value|nxstrategy
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"scbus.h"
end_include

begin_if
if|#
directive|if
name|NSCBUS
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
value|nxopen
end_define

begin_define
define|#
directive|define
name|ukclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|ukioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|d_open_t
name|lkmcopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|lkmcclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|lkmcioctl
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"apm.h"
end_include

begin_if
if|#
directive|if
name|NAPM
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|apmopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|apmclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|apmioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|apmopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|apmclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|apmioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IBCS2
end_ifdef

begin_decl_stmt
name|d_open_t
name|sockopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|sockclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|sockioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sockopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|sockclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|sockioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ctx.h"
end_include

begin_if
if|#
directive|if
name|NCTX
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|ctxopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ctxclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|ctxread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|ctxwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ctxioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ctxopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|ctxclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|ctxread
value|nxread
end_define

begin_define
define|#
directive|define
name|ctxwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|ctxioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ssc.h"
end_include

begin_if
if|#
directive|if
name|NSSC
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|sscopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|sscclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|sscioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|sscread
decl_stmt|,
name|sscwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|sscselect
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sscmmap
value|nxmmap
end_define

begin_decl_stmt
name|d_strategy_t
name|sscstrategy
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sscopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|sscclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|sscioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|sscread
value|nxread
end_define

begin_define
define|#
directive|define
name|sscwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|sscselect
value|nxselect
end_define

begin_define
define|#
directive|define
name|sscmmap
value|nxmmap
end_define

begin_define
define|#
directive|define
name|sscstrategy
value|nxstrategy
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"cx.h"
end_include

begin_if
if|#
directive|if
name|NCX
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|cxopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|cxclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|cxread
decl_stmt|,
name|cxwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|cxioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|cxselect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|cxstop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|cxdevtotty
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cxopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|cxclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|cxread
value|nxread
end_define

begin_define
define|#
directive|define
name|cxwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|cxioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|cxstop
value|nxstop
end_define

begin_define
define|#
directive|define
name|cxselect
value|nxselect
end_define

begin_define
define|#
directive|define
name|cxdevtotty
value|nxdevtotty
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gp.h"
end_include

begin_if
if|#
directive|if
name|NGP
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|gpopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|gpclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|gpwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|gpioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|gpopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|gpclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|gpwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|gpioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gsc.h"
end_include

begin_if
if|#
directive|if
name|NGSC
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|gscopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|gscclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|gscread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|gscioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|gscopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|gscclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|gscread
value|nxread
end_define

begin_define
define|#
directive|define
name|gscioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"crd.h"
end_include

begin_if
if|#
directive|if
name|NCRD
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|crdopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|crdclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|crdread
decl_stmt|,
name|crdwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|crdioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|crdselect
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|crdopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|crdclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|crdread
value|nxread
end_define

begin_define
define|#
directive|define
name|crdwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|crdioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|crdselect
value|nxselect
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"joy.h"
end_include

begin_if
if|#
directive|if
name|NJOY
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|joyopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|joyclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|joyread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|joyioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|joyopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|joyclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|joyread
value|nxread
end_define

begin_define
define|#
directive|define
name|joyioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"asc.h"
end_include

begin_if
if|#
directive|if
name|NASC
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|ascopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ascclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|ascread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ascioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|ascselect
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ascopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|ascclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|ascread
value|nxread
end_define

begin_define
define|#
directive|define
name|ascioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|ascselect
value|nxselect
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"tun.h"
end_include

begin_if
if|#
directive|if
name|NTUN
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|tunopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|tunclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|tunread
decl_stmt|,
name|tunwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|tunioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|tunselect
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|tunopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|tunclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|tunread
value|nxread
end_define

begin_define
define|#
directive|define
name|tunwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|tunioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|tunselect
value|nxselect
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"spigot.h"
end_include

begin_if
if|#
directive|if
name|NSPIGOT
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|spigot_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|spigot_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|spigot_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|spigot_read
decl_stmt|,
name|spigot_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_select_t
name|spigot_select
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_mmap_t
name|spigot_mmap
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|spigot_open
value|nxopen
end_define

begin_define
define|#
directive|define
name|spigot_close
value|nxclose
end_define

begin_define
define|#
directive|define
name|spigot_ioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|spigot_read
value|nxread
end_define

begin_define
define|#
directive|define
name|spigot_write
value|nxwrite
end_define

begin_define
define|#
directive|define
name|spigot_select
value|seltrue
end_define

begin_define
define|#
directive|define
name|spigot_mmap
value|nommap
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Cyclades serial driver */
end_comment

begin_include
include|#
directive|include
file|"cy.h"
end_include

begin_if
if|#
directive|if
name|NCY
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|cyopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|cyclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|cyread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|cywrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|cyioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|cystop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|cydevtotty
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|cyreset
value|nxreset
end_define

begin_define
define|#
directive|define
name|cymmap
value|nxmmap
end_define

begin_define
define|#
directive|define
name|cystrategy
value|nxstrategy
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cyopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|cyclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|cyread
value|nxread
end_define

begin_define
define|#
directive|define
name|cywrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|cyioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|cystop
value|nxstop
end_define

begin_define
define|#
directive|define
name|cyreset
value|nxreset
end_define

begin_define
define|#
directive|define
name|cymmap
value|nxmmap
end_define

begin_define
define|#
directive|define
name|cystrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|cydevtotty
value|nxdevtotty
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"dgb.h"
end_include

begin_if
if|#
directive|if
name|NDGB
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|dgbopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|dgbclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|dgbread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|dgbwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|dgbioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|dgbstop
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dgbreset
value|nxreset
end_define

begin_decl_stmt
name|d_ttycv_t
name|dgbdevtotty
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dgbopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|dgbclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|dgbread
value|nxread
end_define

begin_define
define|#
directive|define
name|dgbwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|dgbioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|dgbstop
value|nxstop
end_define

begin_define
define|#
directive|define
name|dgbreset
value|nxreset
end_define

begin_define
define|#
directive|define
name|dgbdevtotty
value|nxdevtotty
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Specialix serial driver */
end_comment

begin_include
include|#
directive|include
file|"si.h"
end_include

begin_if
if|#
directive|if
name|NSI
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|siopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|siclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|siread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|siwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|siioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|sistop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|sidevtotty
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sireset
value|nxreset
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|siopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|siclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|siread
value|nxread
end_define

begin_define
define|#
directive|define
name|siwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|siioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|sistop
value|nxstop
end_define

begin_define
define|#
directive|define
name|sireset
value|nxreset
end_define

begin_define
define|#
directive|define
name|sidevtotty
value|nxdevtotty
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ity.h"
end_include

begin_if
if|#
directive|if
name|NITY
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|ityopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ityclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|ityread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|itywrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ityioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|itydevtotty
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ityreset
value|nxreset
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ityopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|ityclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|ityread
value|nxread
end_define

begin_define
define|#
directive|define
name|itywrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|ityioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|ityreset
value|nxreset
end_define

begin_define
define|#
directive|define
name|itydevtotty
value|nxdevtotty
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"nic.h"
end_include

begin_if
if|#
directive|if
name|NNIC
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|nicopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|nicclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|nicioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|nicopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|nicclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|nicioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"nnic.h"
end_include

begin_if
if|#
directive|if
name|NNNIC
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|nnicopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|nnicclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|nnicioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|nnicopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|nnicclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|nnicioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"isdn.h"
end_include

begin_if
if|#
directive|if
name|NISDN
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|isdnopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|isdnclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|isdnread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|isdnioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|isdnopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|isdnclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|isdnread
value|nxread
end_define

begin_define
define|#
directive|define
name|isdnioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"itel.h"
end_include

begin_if
if|#
directive|if
name|NITEL
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|itelopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|itelclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|itelread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|itelwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|itelioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|itelopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|itelclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|itelread
value|nxread
end_define

begin_define
define|#
directive|define
name|itelwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|itelioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ispy.h"
end_include

begin_if
if|#
directive|if
name|NISPY
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|ispyopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|ispyclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|ispyread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|ispywrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|ispyioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ispyopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|ispyclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|ispyread
value|nxread
end_define

begin_define
define|#
directive|define
name|ispywrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|ispyioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"rc.h"
end_include

begin_if
if|#
directive|if
name|NRC
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|rcopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|rcclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_rdwr_t
name|rcread
decl_stmt|,
name|rcwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|rcioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|rcstop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|rcdevtotty
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|rcreset
value|nxreset
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|rcopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|rcclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|rcread
value|nxread
end_define

begin_define
define|#
directive|define
name|rcwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|rcioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|rcstop
value|nxstop
end_define

begin_define
define|#
directive|define
name|rcreset
value|nxreset
end_define

begin_define
define|#
directive|define
name|rcdevtotty
value|nxdevtotty
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"labpc.h"
end_include

begin_if
if|#
directive|if
name|NLABPC
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|labpcopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|labpcclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|labpcstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|labpcioctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|labpcopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|labpcclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|labpcstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|labpcioctl
value|nxioctl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Stallion Multiport Serial Driver (cd1400 based) */
end_comment

begin_include
include|#
directive|include
file|"stl.h"
end_include

begin_if
if|#
directive|if
name|NSTL
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|stlopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|stlclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|stlread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|stlwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|stlioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|stlstop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|stldevtotty
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|stlreset
value|nxreset
end_define

begin_define
define|#
directive|define
name|stlmmap
value|nxmmap
end_define

begin_define
define|#
directive|define
name|stlstrategy
value|nxstrategy
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|stlopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|stlclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|stlread
value|nxread
end_define

begin_define
define|#
directive|define
name|stlwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|stlioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|stlstop
value|nxstop
end_define

begin_define
define|#
directive|define
name|stlreset
value|nxreset
end_define

begin_define
define|#
directive|define
name|stlmmap
value|nxmmap
end_define

begin_define
define|#
directive|define
name|stlstrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|stldevtotty
value|nxdevtotty
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Stallion Intelligent Multiport Serial Driver */
end_comment

begin_include
include|#
directive|include
file|"stli.h"
end_include

begin_if
if|#
directive|if
name|NSTLI
operator|>
literal|0
end_if

begin_decl_stmt
name|d_open_t
name|stliopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|stliclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|stliread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|stliwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|stliioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|stlistop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ttycv_t
name|stlidevtotty
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|stlireset
value|nxreset
end_define

begin_define
define|#
directive|define
name|stlimmap
value|nxmmap
end_define

begin_define
define|#
directive|define
name|stlistrategy
value|nxstrategy
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|stliopen
value|nxopen
end_define

begin_define
define|#
directive|define
name|stliclose
value|nxclose
end_define

begin_define
define|#
directive|define
name|stliread
value|nxread
end_define

begin_define
define|#
directive|define
name|stliwrite
value|nxwrite
end_define

begin_define
define|#
directive|define
name|stliioctl
value|nxioctl
end_define

begin_define
define|#
directive|define
name|stlistop
value|nxstop
end_define

begin_define
define|#
directive|define
name|stlireset
value|nxreset
end_define

begin_define
define|#
directive|define
name|stlimmap
value|nxmmap
end_define

begin_define
define|#
directive|define
name|stlistrategy
value|nxstrategy
end_define

begin_define
define|#
directive|define
name|stlidevtotty
value|nxdevtotty
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|nodevtotty
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
name|nodevtotty
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
name|mmioctl
block|,
name|nullstop
block|,
name|nullreset
block|,
name|nodevtotty
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
name|nodevtotty
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
name|nodevtotty
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
name|ptydevtotty
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
name|ptydevtotty
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
name|nodevtotty
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
name|bquopen
block|,
name|bquclose
block|,
name|bquread
block|,
name|bquwrite
block|,
comment|/*8*/
name|bquioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* tputer */
name|bquselect
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
name|nodevtotty
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
name|nodevtotty
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
name|spigot_open
block|,
name|spigot_close
block|,
name|spigot_read
block|,
name|spigot_write
block|,
comment|/*11*/
name|spigot_ioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* Spigot */
name|spigot_select
block|,
name|spigot_mmap
block|,
name|NULL
block|}
block|,
block|{
name|scopen
block|,
name|scclose
block|,
name|scread
block|,
name|scwrite
block|,
comment|/*12*/
name|scioctl
block|,
name|nullstop
block|,
name|nullreset
block|,
name|scdevtotty
block|,
comment|/* sc */
name|ttselect
block|,
name|scmmap
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
name|nodevtotty
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
name|nodevtotty
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
name|nodevtotty
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
name|nodevtotty
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
name|nodevtotty
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
name|suread
block|,
name|suwrite
block|,
comment|/*18*/
name|suioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* scsi */
name|suselect
block|,
name|summap
block|,
name|sustrategy
block|}
block|,
comment|/* 'generic' */
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
name|nodevtotty
block|,
comment|/* tw */
name|twselect
block|,
name|nommap
block|,
name|nostrat
block|}
block|,
comment|/*  * If you need a cdev major number for a driver that you intend to donate  * back to the group or release publically, please contact the FreeBSD team  * by sending mail to "hackers@freebsd.org".  * If you assign one yourself it may conflict with someone else.  * Otherwise, simply use the one reserved for local use.  */
comment|/* character device 20 is reserved for local use */
block|{
name|nxopen
block|,
name|nxclose
block|,
name|nxread
block|,
name|nxwrite
block|,
comment|/*20*/
name|nxioctl
block|,
name|nxstop
block|,
name|nxreset
block|,
name|nxdevtotty
block|,
comment|/* reserved */
name|nxselect
block|,
name|nxmmap
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
name|nodevtotty
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
name|nodevtotty
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
name|nodevtotty
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
name|nodevtotty
block|,
comment|/* pcaudio */
name|pcaselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|nxopen
block|,
name|nxclose
block|,
name|nxread
block|,
name|nxwrite
block|,
comment|/*25*/
name|nxioctl
block|,
name|nxstop
block|,
name|nxreset
block|,
name|nxdevtotty
block|,
comment|/* was vat */
name|nxselect
block|,
name|nxmmap
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
name|nodevtotty
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
name|nodevtotty
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
name|siodevtotty
block|,
comment|/* sio */
name|ttselect
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
name|nodevtotty
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
name|nodevtotty
block|,
comment|/* sound */
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
name|nodevtotty
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
name|lkmcopen
block|,
name|lkmcclose
block|,
name|noread
block|,
name|nowrite
block|,
comment|/*32*/
name|lkmcioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
name|noselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|lkmopen
block|,
name|lkmclose
block|,
name|lkmread
block|,
name|lkmwrite
block|,
comment|/*33*/
name|lkmioctl
block|,
name|lkmstop
block|,
name|lkmreset
block|,
name|nodevtotty
block|,
name|lkmselect
block|,
name|lkmmmap
block|,
name|NULL
block|}
block|,
block|{
name|lkmopen
block|,
name|lkmclose
block|,
name|lkmread
block|,
name|lkmwrite
block|,
comment|/*34*/
name|lkmioctl
block|,
name|lkmstop
block|,
name|lkmreset
block|,
name|nodevtotty
block|,
name|lkmselect
block|,
name|lkmmmap
block|,
name|NULL
block|}
block|,
block|{
name|lkmopen
block|,
name|lkmclose
block|,
name|lkmread
block|,
name|lkmwrite
block|,
comment|/*35*/
name|lkmioctl
block|,
name|lkmstop
block|,
name|lkmreset
block|,
name|nodevtotty
block|,
name|lkmselect
block|,
name|lkmmmap
block|,
name|NULL
block|}
block|,
block|{
name|lkmopen
block|,
name|lkmclose
block|,
name|lkmread
block|,
name|lkmwrite
block|,
comment|/*36*/
name|lkmioctl
block|,
name|lkmstop
block|,
name|lkmreset
block|,
name|nodevtotty
block|,
name|lkmselect
block|,
name|lkmmmap
block|,
name|NULL
block|}
block|,
block|{
name|lkmopen
block|,
name|lkmclose
block|,
name|lkmread
block|,
name|lkmwrite
block|,
comment|/*37*/
name|lkmioctl
block|,
name|lkmstop
block|,
name|lkmreset
block|,
name|nodevtotty
block|,
name|lkmselect
block|,
name|lkmmmap
block|,
name|NULL
block|}
block|,
block|{
name|lkmopen
block|,
name|lkmclose
block|,
name|lkmread
block|,
name|lkmwrite
block|,
comment|/*38*/
name|lkmioctl
block|,
name|lkmstop
block|,
name|lkmreset
block|,
name|nodevtotty
block|,
name|lkmselect
block|,
name|lkmmmap
block|,
name|NULL
block|}
block|,
block|{
name|apmopen
block|,
name|apmclose
block|,
name|noread
block|,
name|nowrite
block|,
comment|/*39*/
name|apmioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* APM */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|ctxopen
block|,
name|ctxclose
block|,
name|ctxread
block|,
name|ctxwrite
block|,
comment|/*40*/
name|ctxioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* cortex */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|sockopen
block|,
name|sockclose
block|,
name|noread
block|,
name|nowrite
block|,
comment|/*41*/
name|sockioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* socksys */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|cxopen
block|,
name|cxclose
block|,
name|cxread
block|,
name|cxwrite
block|,
comment|/*42*/
name|cxioctl
block|,
name|cxstop
block|,
name|nullreset
block|,
name|cxdevtotty
block|,
comment|/* cronyx */
name|cxselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|vnopen
block|,
name|vnclose
block|,
name|rawread
block|,
name|rawwrite
block|,
comment|/*43*/
name|vnioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* vn */
name|seltrue
block|,
name|nommap
block|,
name|vnstrategy
block|}
block|,
block|{
name|gpopen
block|,
name|gpclose
block|,
name|noread
block|,
name|gpwrite
block|,
comment|/*44*/
name|gpioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* GPIB */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|scdopen
block|,
name|scdclose
block|,
name|rawread
block|,
name|nowrite
block|,
comment|/*45*/
name|scdioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* sony cd */
name|seltrue
block|,
name|nommap
block|,
name|scdstrategy
block|}
block|,
block|{
name|matcdopen
block|,
name|matcdclose
block|,
name|rawread
block|,
name|nowrite
block|,
comment|/*46*/
name|matcdioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* SB cd */
name|seltrue
block|,
name|nommap
block|,
name|matcdstrategy
block|}
block|,
block|{
name|gscopen
block|,
name|gscclose
block|,
name|gscread
block|,
name|nowrite
block|,
comment|/*47*/
name|gscioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* gsc */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|cyopen
block|,
name|cyclose
block|,
name|cyread
block|,
name|cywrite
block|,
comment|/*48*/
name|cyioctl
block|,
name|cystop
block|,
name|cyreset
block|,
name|cydevtotty
block|,
comment|/*cyclades*/
name|ttselect
block|,
name|cymmap
block|,
name|cystrategy
block|}
block|,
block|{
name|sscopen
block|,
name|sscclose
block|,
name|sscread
block|,
name|sscwrite
block|,
comment|/*49*/
name|sscioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* scsi super */
name|sscselect
block|,
name|sscmmap
block|,
name|sscstrategy
block|}
block|,
block|{
name|crdopen
block|,
name|crdclose
block|,
name|crdread
block|,
name|crdwrite
block|,
comment|/*50*/
name|crdioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* pcmcia */
name|crdselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|joyopen
block|,
name|joyclose
block|,
name|joyread
block|,
name|nowrite
block|,
comment|/*51*/
name|joyioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/*joystick */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|tunopen
block|,
name|tunclose
block|,
name|tunread
block|,
name|tunwrite
block|,
comment|/*52*/
name|tunioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* tunnel */
name|tunselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|snpopen
block|,
name|snpclose
block|,
name|snpread
block|,
name|snpwrite
block|,
comment|/*53*/
name|snpioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* snoop */
name|snpselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|nicopen
block|,
name|nicclose
block|,
name|noread
block|,
name|nowrite
block|,
comment|/*54*/
name|nicioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* nic */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|isdnopen
block|,
name|isdnclose
block|,
name|isdnread
block|,
name|nowrite
block|,
comment|/*55*/
name|isdnioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* isdn */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|ityopen
block|,
name|ityclose
block|,
name|ityread
block|,
name|itywrite
block|,
comment|/*56*/
name|ityioctl
block|,
name|nostop
block|,
name|ityreset
block|,
name|itydevtotty
block|,
comment|/* ity */
name|ttselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|itelopen
block|,
name|itelclose
block|,
name|itelread
block|,
name|itelwrite
block|,
comment|/*57*/
name|itelioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* itel */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|dgbopen
block|,
name|dgbclose
block|,
name|dgbread
block|,
name|dgbwrite
block|,
comment|/*58*/
name|dgbioctl
block|,
name|dgbstop
block|,
name|dgbreset
block|,
name|dgbdevtotty
block|,
comment|/* dgb */
name|ttselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|ispyopen
block|,
name|ispyclose
block|,
name|ispyread
block|,
name|nowrite
block|,
comment|/*59*/
name|ispyioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* ispy */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|nnicopen
block|,
name|nnicclose
block|,
name|noread
block|,
name|nowrite
block|,
comment|/*60*/
name|nnicioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* nnic */
name|seltrue
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|ptopen
block|,
name|ptclose
block|,
name|rawread
block|,
name|rawwrite
block|,
comment|/*61*/
name|ptioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* pt */
name|seltrue
block|,
name|nommap
block|,
name|ptstrategy
block|}
block|,
block|{
name|wormopen
block|,
name|wormclose
block|,
name|rawread
block|,
name|rawwrite
block|,
comment|/*62*/
name|wormioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* worm */
name|seltrue
block|,
name|nommap
block|,
name|wormstrategy
block|}
block|,
block|{
name|rcopen
block|,
name|rcclose
block|,
name|rcread
block|,
name|rcwrite
block|,
comment|/*63*/
name|rcioctl
block|,
name|rcstop
block|,
name|rcreset
block|,
name|rcdevtotty
block|,
comment|/* rc */
name|ttselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|nxopen
block|,
name|nxclose
block|,
name|nxread
block|,
name|nxwrite
block|,
comment|/*64*/
name|nxioctl
block|,
name|nxstop
block|,
name|nxreset
block|,
name|nxdevtotty
block|,
comment|/* Talisman */
name|nxselect
block|,
name|nxmmap
block|,
name|NULL
block|}
block|,
block|{
name|sctargopen
block|,
name|sctargclose
block|,
name|rawread
block|,
name|rawwrite
block|,
comment|/*65*/
name|sctargioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* sctarg */
name|seltrue
block|,
name|nommap
block|,
name|sctargstrategy
block|}
block|,
block|{
name|labpcopen
block|,
name|labpcclose
block|,
name|rawread
block|,
name|rawwrite
block|,
comment|/*66*/
name|labpcioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* labpc */
name|seltrue
block|,
name|nommap
block|,
name|labpcstrategy
block|}
block|,
block|{
name|meteor_open
block|,
name|meteor_close
block|,
name|meteor_read
block|,
name|meteor_write
block|,
comment|/*67*/
name|meteor_ioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* Meteor */
name|seltrue
block|,
name|meteor_mmap
block|,
name|NULL
block|}
block|,
block|{
name|siopen
block|,
name|siclose
block|,
name|siread
block|,
name|siwrite
block|,
comment|/*68*/
name|siioctl
block|,
name|sistop
block|,
name|sireset
block|,
name|sidevtotty
block|,
comment|/* slxos */
name|ttselect
block|,
name|nxmmap
block|,
name|NULL
block|}
block|,
block|{
name|wcdopen
block|,
name|wcdclose
block|,
name|rawread
block|,
name|nowrite
block|,
comment|/*69*/
name|wcdioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* atapi */
name|seltrue
block|,
name|nommap
block|,
name|wcdstrategy
block|}
block|,
block|{
name|odopen
block|,
name|odclose
block|,
name|rawread
block|,
name|rawwrite
block|,
comment|/*70*/
name|odioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* od */
name|seltrue
block|,
name|nommap
block|,
name|odstrategy
block|}
block|,
block|{
name|ascopen
block|,
name|ascclose
block|,
name|ascread
block|,
name|nowrite
block|,
comment|/*71*/
name|ascioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* asc */
name|ascselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|stlopen
block|,
name|stlclose
block|,
name|stlread
block|,
name|stlwrite
block|,
comment|/*72*/
name|stlioctl
block|,
name|stlstop
block|,
name|stlreset
block|,
name|stldevtotty
block|,
comment|/*stli*/
name|ttselect
block|,
name|stlmmap
block|,
name|stlstrategy
block|}
block|,
block|{
name|qcam_open
block|,
name|qcam_close
block|,
name|qcam_read
block|,
name|nowrite
block|,
comment|/*73*/
name|qcam_ioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* qcam */
name|noselect
block|,
name|nommap
block|,
name|NULL
block|}
block|,
block|{
name|ccdopen
block|,
name|ccdclose
block|,
name|ccdread
block|,
name|ccdwrite
block|,
comment|/*74*/
name|ccdioctl
block|,
name|nostop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
comment|/* ccd */
name|seltrue
block|,
name|nommap
block|,
name|ccdstrategy
block|}
block|,
block|{
name|stliopen
block|,
name|stliclose
block|,
name|stliread
block|,
name|stliwrite
block|,
comment|/*75*/
name|stliioctl
block|,
name|stlistop
block|,
name|stlireset
block|,
name|stlidevtotty
block|,
comment|/*stli*/
name|ttselect
block|,
name|stlimmap
block|,
name|stlistrategy
block|}
block|,  }
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

begin_comment
comment|/*  * The tunnel device's LKM wants to know where to install itself in the  * cdevsw table.  Sigh.  */
end_comment

begin_decl_stmt
name|dev_t
name|tuncdev
init|=
name|makedev
argument_list|(
literal|52
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Routine that identifies /dev/mem and /dev/kmem.  *  * A minimal stub routine can always return 0.  */
end_comment

begin_function
name|int
name|iskmemdev
parameter_list|(
name|dev
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
block|{
return|return
operator|(
name|major
argument_list|(
name|dev
argument_list|)
operator|==
literal|2
operator|&&
operator|(
name|minor
argument_list|(
name|dev
argument_list|)
operator|==
literal|0
operator|||
name|minor
argument_list|(
name|dev
argument_list|)
operator|==
literal|1
operator|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|iszerodev
parameter_list|(
name|dev
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
block|{
return|return
operator|(
name|major
argument_list|(
name|dev
argument_list|)
operator|==
literal|2
operator|&&
name|minor
argument_list|(
name|dev
argument_list|)
operator|==
literal|12
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Routine to determine if a device is a disk.  *  * A minimal stub routine can always return 0.  */
end_comment

begin_function
name|int
name|isdisk
parameter_list|(
name|dev
parameter_list|,
name|type
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
name|int
name|type
decl_stmt|;
block|{
switch|switch
condition|(
name|major
argument_list|(
name|dev
argument_list|)
condition|)
block|{
case|case
literal|15
case|:
comment|/* VBLK: vn, VCHR: cd */
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|0
case|:
comment|/* wd */
case|case
literal|2
case|:
comment|/* fd */
case|case
literal|4
case|:
comment|/* sd */
case|case
literal|6
case|:
comment|/* cd */
case|case
literal|7
case|:
comment|/* mcd */
case|case
literal|16
case|:
comment|/* scd */
case|case
literal|17
case|:
comment|/* matcd */
case|case
literal|18
case|:
comment|/* ata */
case|case
literal|19
case|:
comment|/* wcd */
case|case
literal|20
case|:
comment|/* od */
if|if
condition|(
name|type
operator|==
name|VBLK
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|3
case|:
comment|/* wd */
case|case
literal|9
case|:
comment|/* fd */
case|case
literal|13
case|:
comment|/* sd */
case|case
literal|29
case|:
comment|/* mcd */
case|case
literal|43
case|:
comment|/* vn */
case|case
literal|45
case|:
comment|/* scd */
case|case
literal|46
case|:
comment|/* matcd */
case|case
literal|69
case|:
comment|/* wcd */
case|case
literal|70
case|:
comment|/* od */
if|if
condition|(
name|type
operator|==
name|VCHR
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* fall through */
default|default:
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* NOTREACHED */
block|}
end_function

begin_comment
comment|/*  * Routine to convert from character to block device number.  *  * A minimal stub routine can always return NODEV.  */
end_comment

begin_function
name|dev_t
name|chrtoblk
parameter_list|(
name|dev
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
block|{
name|int
name|blkmaj
decl_stmt|;
switch|switch
condition|(
name|major
argument_list|(
name|dev
argument_list|)
condition|)
block|{
case|case
literal|3
case|:
name|blkmaj
operator|=
literal|0
expr_stmt|;
break|break;
comment|/* wd */
case|case
literal|9
case|:
name|blkmaj
operator|=
literal|2
expr_stmt|;
break|break;
comment|/* fd */
case|case
literal|10
case|:
name|blkmaj
operator|=
literal|3
expr_stmt|;
break|break;
comment|/* wt */
case|case
literal|13
case|:
name|blkmaj
operator|=
literal|4
expr_stmt|;
break|break;
comment|/* sd */
case|case
literal|14
case|:
name|blkmaj
operator|=
literal|5
expr_stmt|;
break|break;
comment|/* st */
case|case
literal|15
case|:
name|blkmaj
operator|=
literal|6
expr_stmt|;
break|break;
comment|/* cd */
case|case
literal|29
case|:
name|blkmaj
operator|=
literal|7
expr_stmt|;
break|break;
comment|/* mcd */
case|case
literal|43
case|:
name|blkmaj
operator|=
literal|15
expr_stmt|;
break|break;
comment|/* vn */
case|case
literal|45
case|:
name|blkmaj
operator|=
literal|16
expr_stmt|;
break|break;
comment|/* scd */
case|case
literal|46
case|:
name|blkmaj
operator|=
literal|17
expr_stmt|;
break|break;
comment|/* matcd */
case|case
literal|69
case|:
name|blkmaj
operator|=
literal|19
expr_stmt|;
break|break;
comment|/* wcd */
case|case
literal|70
case|:
name|blkmaj
operator|=
literal|20
expr_stmt|;
break|break;
comment|/* od */
default|default:
return|return
operator|(
name|NODEV
operator|)
return|;
block|}
return|return
operator|(
name|makedev
argument_list|(
name|blkmaj
argument_list|,
name|minor
argument_list|(
name|dev
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

