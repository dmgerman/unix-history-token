begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)conf.h	8.3 (Berkeley) 1/21/94  * $Id: conf.h,v 1.20 1995/11/05 09:37:28 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CONF_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CONF_H_
end_define

begin_comment
comment|/*  * Definitions of device driver entry switches  */
end_comment

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tty
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|d_strategy_t
name|__P
typedef|((struct
name|buf
modifier|*
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_open_t
name|__P
typedef|((
name|dev_t
typedef|,
name|int
typedef|,
name|int
typedef|, struct
name|proc
modifier|*
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_close_t
name|__P
typedef|((
name|dev_t
typedef|,
name|int
typedef|,
name|int
typedef|, struct
name|proc
modifier|*
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_ioctl_t
name|__P
typedef|((
name|dev_t
typedef|,
name|int
typedef|,
name|caddr_t
typedef|,
name|int
typedef|, struct
name|proc
modifier|*
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_dump_t
name|__P
typedef|((
name|dev_t
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_psize_t
name|__P
typedef|((
name|dev_t
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_read_t
name|__P
typedef|((
name|dev_t
typedef|, struct
name|uio
modifier|*
typedef|,
name|int
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_write_t
name|__P
typedef|((
name|dev_t
typedef|, struct
name|uio
modifier|*
typedef|,
name|int
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_rdwr_t
name|__P
typedef|((
name|dev_t
typedef|, struct
name|uio
modifier|*
typedef|,
name|int
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|void
name|d_stop_t
name|__P
typedef|((struct
name|tty
modifier|*
typedef|,
name|int
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_reset_t
name|__P
typedef|((
name|int
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_select_t
name|__P
typedef|((
name|dev_t
typedef|,
name|int
typedef|, struct
name|proc
modifier|*
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_mmap_t
name|__P
typedef|((
name|dev_t
typedef|,
name|int
typedef|,
name|int
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tty
modifier|*
name|d_ttycv_t
name|__P
typedef|((
name|dev_t
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_open_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|, struct
name|tty
modifier|*
name|tp
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_close_t
name|__P
typedef|((struct
name|tty
modifier|*
name|tp
typedef|,
name|int
name|flag
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_read_t
name|__P
typedef|((struct
name|tty
modifier|*
name|tp
typedef|, struct
name|uio
modifier|*
name|uio
typedef|,
name|int
name|flag
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_write_t
name|__P
typedef|((struct
name|tty
modifier|*
name|tp
typedef|, struct
name|uio
modifier|*
name|uio
typedef|,
name|int
name|flag
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_ioctl_t
name|__P
typedef|((struct
name|tty
modifier|*
name|tp
typedef|,
name|int
name|cmd
typedef|,
name|caddr_t
name|data
typedef|,
name|int
name|flag
typedef|, 			   struct
name|proc
modifier|*
name|p
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_rint_t
name|__P
typedef|((
name|int
name|c
typedef|, struct
name|tty
modifier|*
name|tp
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_start_t
name|__P
typedef|((struct
name|tty
modifier|*
name|tp
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_modem_t
name|__P
typedef|((struct
name|tty
modifier|*
name|tp
typedef|,
name|int
name|flag
typedef|));
end_typedef

begin_struct
struct|struct
name|bdevsw
block|{
name|d_open_t
modifier|*
name|d_open
decl_stmt|;
name|d_close_t
modifier|*
name|d_close
decl_stmt|;
name|d_strategy_t
modifier|*
name|d_strategy
decl_stmt|;
name|d_ioctl_t
modifier|*
name|d_ioctl
decl_stmt|;
name|d_dump_t
modifier|*
name|d_dump
decl_stmt|;
name|d_psize_t
modifier|*
name|d_psize
decl_stmt|;
name|int
name|d_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|bdevsw
name|bdevsw
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|cdevsw
block|{
name|d_open_t
modifier|*
name|d_open
decl_stmt|;
name|d_close_t
modifier|*
name|d_close
decl_stmt|;
name|d_rdwr_t
modifier|*
name|d_read
decl_stmt|;
name|d_rdwr_t
modifier|*
name|d_write
decl_stmt|;
name|d_ioctl_t
modifier|*
name|d_ioctl
decl_stmt|;
name|d_stop_t
modifier|*
name|d_stop
decl_stmt|;
name|d_reset_t
modifier|*
name|d_reset
decl_stmt|;
name|d_ttycv_t
modifier|*
name|d_devtotty
decl_stmt|;
name|d_select_t
modifier|*
name|d_select
decl_stmt|;
name|d_mmap_t
modifier|*
name|d_mmap
decl_stmt|;
name|d_strategy_t
modifier|*
name|d_strategy
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|cdevsw
name|cdevsw
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* symbolic sleep message strings */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|devopn
index|[]
decl_stmt|,
name|devio
index|[]
decl_stmt|,
name|devwait
index|[]
decl_stmt|,
name|devin
index|[]
decl_stmt|,
name|devout
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|devioc
index|[]
decl_stmt|,
name|devcls
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|linesw
block|{
name|l_open_t
modifier|*
name|l_open
decl_stmt|;
name|l_close_t
modifier|*
name|l_close
decl_stmt|;
name|l_read_t
modifier|*
name|l_read
decl_stmt|;
name|l_write_t
modifier|*
name|l_write
decl_stmt|;
name|l_ioctl_t
modifier|*
name|l_ioctl
decl_stmt|;
name|l_rint_t
modifier|*
name|l_rint
decl_stmt|;
name|l_start_t
modifier|*
name|l_start
decl_stmt|;
name|l_modem_t
modifier|*
name|l_modem
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|linesw
name|linesw
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nlinesw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ldisc_register
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|linesw
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ldisc_deregister
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LDISC_LOAD
value|-1
end_define

begin_comment
comment|/* Loadable line discipline */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|swdevt
block|{
name|dev_t
name|sw_dev
decl_stmt|;
name|int
name|sw_flags
decl_stmt|;
name|int
name|sw_nblks
decl_stmt|;
name|struct
name|vnode
modifier|*
name|sw_vp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SW_FREED
value|0x01
end_define

begin_define
define|#
directive|define
name|SW_SEQUENTIAL
value|0x02
end_define

begin_define
define|#
directive|define
name|sw_freed
value|sw_flags
end_define

begin_comment
comment|/* XXX compat */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|d_reset_t
name|noreset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_mmap_t
name|nommap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|nostrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|nullopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|nullclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|nullstop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_reset_t
name|nullreset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * XXX d_strategy seems to be unused for cdevs and called without checking  * for it being non-NULL for bdevs.  */
end_comment

begin_define
define|#
directive|define
name|nullstrategy
value|((d_strategy *)NULL)
end_define

begin_decl_stmt
name|l_read_t
name|l_noread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|l_write_t
name|l_nowrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|chrtoblk
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getmajorbyname
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isdisk
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
name|int
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iskmemdev
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iszerodev
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|register_cdev
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
specifier|const
expr|struct
name|cdevsw
operator|*
name|cdp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setdumpdev
name|__P
argument_list|(
operator|(
name|dev_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unregister_cdev
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
specifier|const
expr|struct
name|cdevsw
operator|*
name|cdp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|JREMOD
end_ifdef

begin_decl_stmt
name|int
name|cdevsw_add
name|__P
argument_list|(
operator|(
name|dev_t
operator|*
name|descrip
operator|,
expr|struct
name|cdevsw
operator|*
name|new
operator|,
expr|struct
name|cdevsw
operator|*
name|old
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bdevsw_add
name|__P
argument_list|(
operator|(
name|dev_t
operator|*
name|descrip
operator|,
expr|struct
name|bdevsw
operator|*
name|new
operator|,
expr|struct
name|bdevsw
operator|*
name|old
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_include
include|#
directive|include
file|<machine/conf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CONF_H_ */
end_comment

end_unit

