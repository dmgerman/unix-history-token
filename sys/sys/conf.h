begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)conf.h	8.5 (Berkeley) 1/9/95  * $Id: conf.h,v 1.36 1997/09/27 13:39:46 kato Exp $  */
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
name|int
name|d_open_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|,
name|int
name|oflags
typedef|,
name|int
name|devtype
typedef|, struct
name|proc
modifier|*
name|p
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_close_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|,
name|int
name|fflag
typedef|,
name|int
name|devtype
typedef|, struct
name|proc
modifier|*
name|p
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|void
name|d_strategy_t
name|__P
typedef|((struct
name|buf
modifier|*
name|bp
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_ioctl_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|,
name|int
name|cmd
typedef|,
name|caddr_t
name|data
typedef|,
name|int
name|fflag
typedef|, struct
name|proc
modifier|*
name|p
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_dump_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_psize_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_read_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|, struct
name|uio
modifier|*
name|uio
typedef|,
name|int
name|ioflag
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_write_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|, struct
name|uio
modifier|*
name|uio
typedef|,
name|int
name|ioflag
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
name|tp
typedef|,
name|int
name|rw
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_reset_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tty
modifier|*
name|d_devtotty_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_poll_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|,
name|int
name|events
typedef|, struct
name|proc
modifier|*
name|p
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_mmap_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|,
name|int
name|offset
typedef|,
name|int
name|nprot
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
typedef|, struct
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

begin_comment
comment|/*  * Types for d_type.  */
end_comment

begin_define
define|#
directive|define
name|D_TAPE
value|1
end_define

begin_define
define|#
directive|define
name|D_DISK
value|2
end_define

begin_define
define|#
directive|define
name|D_TTY
value|3
end_define

begin_define
define|#
directive|define
name|D_TYPEMASK
value|0xffff
end_define

begin_comment
comment|/*  * Flags for d_flags.  */
end_comment

begin_define
define|#
directive|define
name|D_NOCLUSTERR
value|0x10000
end_define

begin_comment
comment|/* disables cluter read */
end_comment

begin_define
define|#
directive|define
name|D_NOCLUSTERW
value|0x20000
end_define

begin_comment
comment|/* disables cluster write */
end_comment

begin_define
define|#
directive|define
name|D_NOCLUSTERRW
value|(D_NOCLUSTERR | D_NOCLUSTERW)
end_define

begin_comment
comment|/*  * Block device switch table  */
end_comment

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
name|u_int
name|d_flags
decl_stmt|;
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* name of the driver e.g. audio */
name|struct
name|cdevsw
modifier|*
name|d_cdev
decl_stmt|;
comment|/* cross pointer to the cdev */
name|int
name|d_maj
decl_stmt|;
comment|/* the major number we were assigned */
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
modifier|*
name|bdevsw
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Character device switch table  */
end_comment

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
name|d_read_t
modifier|*
name|d_read
decl_stmt|;
name|d_write_t
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
comment|/* XXX not used */
name|d_devtotty_t
modifier|*
name|d_devtotty
decl_stmt|;
name|d_poll_t
modifier|*
name|d_poll
decl_stmt|;
name|d_mmap_t
modifier|*
name|d_mmap
decl_stmt|;
name|d_strategy_t
modifier|*
name|d_strategy
decl_stmt|;
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* see above */
name|struct
name|bdevsw
modifier|*
name|d_bdev
decl_stmt|;
name|int
name|d_maj
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
modifier|*
name|cdevsw
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Line discipline switch table  */
end_comment

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

begin_comment
comment|/*  * Swap device table  */
end_comment

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
name|d_open_t
name|noopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|noclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|noread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|nowrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|noioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_stop_t
name|nostop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_reset_t
name|noreset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_devtotty_t
name|nodevtotty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_mmap_t
name|nommap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bogus defines for compatibility. */
end_comment

begin_define
define|#
directive|define
name|noioc
value|noioctl
end_define

begin_define
define|#
directive|define
name|nostrat
value|nostrategy
end_define

begin_define
define|#
directive|define
name|zerosize
value|nopsize
end_define

begin_comment
comment|/*  * XXX d_strategy seems to be unused for cdevs that aren't associated with  * bdevs and called without checking for it being non-NULL for bdevs.  */
end_comment

begin_define
define|#
directive|define
name|nostrategy
value|((d_strategy_t *)NULL)
end_define

begin_decl_stmt
name|d_dump_t
name|nodump
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * nopsize is little used, so not worth having dummy functions for.  */
end_comment

begin_define
define|#
directive|define
name|nopsize
value|((d_psize_t *)NULL)
end_define

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

begin_define
define|#
directive|define
name|nullstop
value|nostop
end_define

begin_comment
comment|/* one void return is as good as another */
end_comment

begin_define
define|#
directive|define
name|nullreset
value|noreset
end_define

begin_comment
comment|/* one unused function is as good as another */
end_comment

begin_decl_stmt
name|d_open_t
name|nxopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|nxclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|nxread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|nxwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|nxioctl
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|nxstop
value|nostop
end_define

begin_comment
comment|/* one void return is as good as another */
end_comment

begin_define
define|#
directive|define
name|nxreset
value|noreset
end_define

begin_comment
comment|/* one unused function is as good as another */
end_comment

begin_define
define|#
directive|define
name|nxdevtotty
value|nodevtotty
end_define

begin_comment
comment|/* one NULL return is as good as another */
end_comment

begin_define
define|#
directive|define
name|nxmmap
value|nommap
end_define

begin_comment
comment|/* one -1 return is as good as another */
end_comment

begin_define
define|#
directive|define
name|nxstrategy
value|nostrategy
end_define

begin_comment
comment|/* one NULL value is as good as another */
end_comment

begin_decl_stmt
name|d_dump_t
name|nxdump
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|nxpsize
value|nopsize
end_define

begin_comment
comment|/* one NULL value is as good as another */
end_comment

begin_decl_stmt
name|d_read_t
name|rawread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|rawwrite
decl_stmt|;
end_decl_stmt

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
operator|*
name|old
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
operator|*
name|old
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bdevsw_add_generic
name|__P
argument_list|(
operator|(
name|int
name|bdev
operator|,
name|int
name|cdev
operator|,
expr|struct
name|bdevsw
operator|*
name|bdevsw
operator|)
argument_list|)
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
name|void
name|setconf
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

