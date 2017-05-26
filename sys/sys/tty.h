begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Ed Schouten<ed@FreeBSD.org>  * All rights reserved.  *  * Portions of this software were developed under sponsorship from Snow  * B.V., the Netherlands.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TTY_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TTY_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/_termios.h>
end_include

begin_include
include|#
directive|include
file|<sys/ttycom.h>
end_include

begin_include
include|#
directive|include
file|<sys/ttyqueue.h>
end_include

begin_struct_decl
struct_decl|struct
name|cdev
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pgrp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|session
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ttydevsw
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Per-TTY structure, containing buffers, etc.  *  * List of locks  * (t)	locked by t_mtx  * (l)	locked by tty_list_sx  * (c)	const until freeing  */
end_comment

begin_struct
struct|struct
name|tty
block|{
name|struct
name|mtx
modifier|*
name|t_mtx
decl_stmt|;
comment|/* TTY lock. */
name|struct
name|mtx
name|t_mtxobj
decl_stmt|;
comment|/* Per-TTY lock (when not borrowing). */
name|TAILQ_ENTRY
argument_list|(
argument|tty
argument_list|)
name|t_list
expr_stmt|;
comment|/* (l) TTY list entry. */
name|int
name|t_drainwait
decl_stmt|;
comment|/* (t) TIOCDRAIN timeout seconds. */
name|unsigned
name|int
name|t_flags
decl_stmt|;
comment|/* (t) Terminal option flags. */
comment|/* Keep flags in sync with db_show_tty and pstat(8). */
define|#
directive|define
name|TF_NOPREFIX
value|0x00001
comment|/* Don't prepend "tty" to device name. */
define|#
directive|define
name|TF_INITLOCK
value|0x00002
comment|/* Create init/lock state devices. */
define|#
directive|define
name|TF_CALLOUT
value|0x00004
comment|/* Create "cua" devices. */
define|#
directive|define
name|TF_OPENED_IN
value|0x00008
comment|/* "tty" node is in use. */
define|#
directive|define
name|TF_OPENED_OUT
value|0x00010
comment|/* "cua" node is in use. */
define|#
directive|define
name|TF_OPENED_CONS
value|0x00020
comment|/* Device in use as console. */
define|#
directive|define
name|TF_OPENED
value|(TF_OPENED_IN|TF_OPENED_OUT|TF_OPENED_CONS)
define|#
directive|define
name|TF_GONE
value|0x00040
comment|/* Device node is gone. */
define|#
directive|define
name|TF_OPENCLOSE
value|0x00080
comment|/* Device is in open()/close(). */
define|#
directive|define
name|TF_ASYNC
value|0x00100
comment|/* Asynchronous I/O enabled. */
define|#
directive|define
name|TF_LITERAL
value|0x00200
comment|/* Accept the next character literally. */
define|#
directive|define
name|TF_HIWAT_IN
value|0x00400
comment|/* We've reached the input watermark. */
define|#
directive|define
name|TF_HIWAT_OUT
value|0x00800
comment|/* We've reached the output watermark. */
define|#
directive|define
name|TF_HIWAT
value|(TF_HIWAT_IN|TF_HIWAT_OUT)
define|#
directive|define
name|TF_STOPPED
value|0x01000
comment|/* Output flow control - stopped. */
define|#
directive|define
name|TF_EXCLUDE
value|0x02000
comment|/* Exclusive access. */
define|#
directive|define
name|TF_BYPASS
value|0x04000
comment|/* Optimized input path. */
define|#
directive|define
name|TF_ZOMBIE
value|0x08000
comment|/* Modem disconnect received. */
define|#
directive|define
name|TF_HOOK
value|0x10000
comment|/* TTY has hook attached. */
define|#
directive|define
name|TF_BUSY_IN
value|0x20000
comment|/* Process busy in read() -- not supported. */
define|#
directive|define
name|TF_BUSY_OUT
value|0x40000
comment|/* Process busy in write(). */
define|#
directive|define
name|TF_BUSY
value|(TF_BUSY_IN|TF_BUSY_OUT)
name|unsigned
name|int
name|t_revokecnt
decl_stmt|;
comment|/* (t) revoke() count. */
comment|/* Buffering mechanisms. */
name|struct
name|ttyinq
name|t_inq
decl_stmt|;
comment|/* (t) Input queue. */
name|size_t
name|t_inlow
decl_stmt|;
comment|/* (t) Input low watermark. */
name|struct
name|ttyoutq
name|t_outq
decl_stmt|;
comment|/* (t) Output queue. */
name|size_t
name|t_outlow
decl_stmt|;
comment|/* (t) Output low watermark. */
comment|/* Sleeping mechanisms. */
name|struct
name|cv
name|t_inwait
decl_stmt|;
comment|/* (t) Input wait queue. */
name|struct
name|cv
name|t_outwait
decl_stmt|;
comment|/* (t) Output wait queue. */
name|struct
name|cv
name|t_outserwait
decl_stmt|;
comment|/* (t) Serial output wait queue. */
name|struct
name|cv
name|t_bgwait
decl_stmt|;
comment|/* (t) Background wait queue. */
name|struct
name|cv
name|t_dcdwait
decl_stmt|;
comment|/* (t) Carrier Detect wait queue. */
comment|/* Polling mechanisms. */
name|struct
name|selinfo
name|t_inpoll
decl_stmt|;
comment|/* (t) Input poll queue. */
name|struct
name|selinfo
name|t_outpoll
decl_stmt|;
comment|/* (t) Output poll queue. */
name|struct
name|sigio
modifier|*
name|t_sigio
decl_stmt|;
comment|/* (t) Asynchronous I/O. */
name|struct
name|termios
name|t_termios
decl_stmt|;
comment|/* (t) I/O processing flags. */
name|struct
name|winsize
name|t_winsize
decl_stmt|;
comment|/* (t) Window size. */
name|unsigned
name|int
name|t_column
decl_stmt|;
comment|/* (t) Current cursor position. */
name|unsigned
name|int
name|t_writepos
decl_stmt|;
comment|/* (t) Where input was interrupted. */
name|int
name|t_compatflags
decl_stmt|;
comment|/* (t) COMPAT_43TTY flags. */
comment|/* Init/lock-state devices. */
name|struct
name|termios
name|t_termios_init_in
decl_stmt|;
comment|/* tty%s.init. */
name|struct
name|termios
name|t_termios_lock_in
decl_stmt|;
comment|/* tty%s.lock. */
name|struct
name|termios
name|t_termios_init_out
decl_stmt|;
comment|/* cua%s.init. */
name|struct
name|termios
name|t_termios_lock_out
decl_stmt|;
comment|/* cua%s.lock. */
name|struct
name|ttydevsw
modifier|*
name|t_devsw
decl_stmt|;
comment|/* (c) Driver hooks. */
name|struct
name|ttyhook
modifier|*
name|t_hook
decl_stmt|;
comment|/* (t) Capture/inject hook. */
comment|/* Process signal delivery. */
name|struct
name|pgrp
modifier|*
name|t_pgrp
decl_stmt|;
comment|/* (t) Foreground process group. */
name|struct
name|session
modifier|*
name|t_session
decl_stmt|;
comment|/* (t) Associated session. */
name|unsigned
name|int
name|t_sessioncnt
decl_stmt|;
comment|/* (t) Backpointing sessions. */
name|void
modifier|*
name|t_devswsoftc
decl_stmt|;
comment|/* (c) Soft config, for drivers. */
name|void
modifier|*
name|t_hooksoftc
decl_stmt|;
comment|/* (t) Soft config, for hooks. */
name|struct
name|cdev
modifier|*
name|t_dev
decl_stmt|;
comment|/* (c) Primary character device. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Userland version of struct tty, for sysctl kern.ttys  */
end_comment

begin_struct
struct|struct
name|xtty
block|{
name|size_t
name|xt_size
decl_stmt|;
comment|/* Structure size. */
name|size_t
name|xt_insize
decl_stmt|;
comment|/* Input queue size. */
name|size_t
name|xt_incc
decl_stmt|;
comment|/* Canonicalized characters. */
name|size_t
name|xt_inlc
decl_stmt|;
comment|/* Input line charaters. */
name|size_t
name|xt_inlow
decl_stmt|;
comment|/* Input low watermark. */
name|size_t
name|xt_outsize
decl_stmt|;
comment|/* Output queue size. */
name|size_t
name|xt_outcc
decl_stmt|;
comment|/* Output queue usage. */
name|size_t
name|xt_outlow
decl_stmt|;
comment|/* Output low watermark. */
name|unsigned
name|int
name|xt_column
decl_stmt|;
comment|/* Current column position. */
name|pid_t
name|xt_pgid
decl_stmt|;
comment|/* Foreground process group. */
name|pid_t
name|xt_sid
decl_stmt|;
comment|/* Session. */
name|unsigned
name|int
name|xt_flags
decl_stmt|;
comment|/* Terminal option flags. */
name|uint32_t
name|xt_dev
decl_stmt|;
comment|/* Userland device. XXXKIB truncated */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Used to distinguish between normal, callout, lock and init devices. */
end_comment

begin_define
define|#
directive|define
name|TTYUNIT_INIT
value|0x1
end_define

begin_define
define|#
directive|define
name|TTYUNIT_LOCK
value|0x2
end_define

begin_define
define|#
directive|define
name|TTYUNIT_CALLOUT
value|0x4
end_define

begin_comment
comment|/* Allocation and deallocation. */
end_comment

begin_function_decl
name|struct
name|tty
modifier|*
name|tty_alloc
parameter_list|(
name|struct
name|ttydevsw
modifier|*
name|tsw
parameter_list|,
name|void
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tty
modifier|*
name|tty_alloc_mutex
parameter_list|(
name|struct
name|ttydevsw
modifier|*
name|tsw
parameter_list|,
name|void
modifier|*
name|softc
parameter_list|,
name|struct
name|mtx
modifier|*
name|mtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_rel_pgrp
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|struct
name|pgrp
modifier|*
name|pgrp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_rel_sess
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|struct
name|session
modifier|*
name|sess
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_rel_gone
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tty_lock
parameter_list|(
name|tp
parameter_list|)
value|mtx_lock((tp)->t_mtx)
end_define

begin_define
define|#
directive|define
name|tty_unlock
parameter_list|(
name|tp
parameter_list|)
value|mtx_unlock((tp)->t_mtx)
end_define

begin_define
define|#
directive|define
name|tty_lock_owned
parameter_list|(
name|tp
parameter_list|)
value|mtx_owned((tp)->t_mtx)
end_define

begin_define
define|#
directive|define
name|tty_lock_assert
parameter_list|(
name|tp
parameter_list|,
name|ma
parameter_list|)
value|mtx_assert((tp)->t_mtx, (ma))
end_define

begin_define
define|#
directive|define
name|tty_getlock
parameter_list|(
name|tp
parameter_list|)
value|((tp)->t_mtx)
end_define

begin_comment
comment|/* Device node creation. */
end_comment

begin_function_decl
name|int
name|tty_makedevf
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|TTYMK_CLONING
value|0x1
end_define

begin_define
define|#
directive|define
name|tty_makedev
parameter_list|(
name|tp
parameter_list|,
name|cred
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(void )tty_makedevf((tp), (cred), 0, (fmt), ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|tty_makealias
parameter_list|(
name|tp
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|make_dev_alias((tp)->t_dev, fmt, ## __VA_ARGS__)
end_define

begin_comment
comment|/* Signalling processes. */
end_comment

begin_function_decl
name|void
name|tty_signal_sessleader
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|int
name|signal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_signal_pgrp
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|int
name|signal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Waking up readers/writers. */
end_comment

begin_function_decl
name|int
name|tty_wait
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|struct
name|cv
modifier|*
name|cv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_wait_background
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_timedwait
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|struct
name|cv
modifier|*
name|cv
parameter_list|,
name|int
name|timo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_wakeup
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* System messages. */
end_comment

begin_function_decl
name|int
name|tty_checkoutq
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_putchar
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_ioctl
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|fflag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_ioctl_compat
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|fflag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_set_winsize
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
specifier|const
name|struct
name|winsize
modifier|*
name|wsz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_init_console
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|speed_t
name|speed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_flush
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_hiwat_in_block
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_hiwat_in_unblock
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dev_t
name|tty_udev
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tty_opened
parameter_list|(
name|tp
parameter_list|)
value|((tp)->t_flags& TF_OPENED)
end_define

begin_define
define|#
directive|define
name|tty_gone
parameter_list|(
name|tp
parameter_list|)
value|((tp)->t_flags& TF_GONE)
end_define

begin_define
define|#
directive|define
name|tty_softc
parameter_list|(
name|tp
parameter_list|)
value|((tp)->t_devswsoftc)
end_define

begin_define
define|#
directive|define
name|tty_devname
parameter_list|(
name|tp
parameter_list|)
value|devtoname((tp)->t_dev)
end_define

begin_comment
comment|/* Status line printing. */
end_comment

begin_function_decl
name|void
name|tty_info
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* /dev/console selection. */
end_comment

begin_function_decl
name|void
name|ttyconsdev_select
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Pseudo-terminal hooks. */
end_comment

begin_function_decl
name|int
name|pts_alloc
parameter_list|(
name|int
name|fflags
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|file
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pts_alloc_external
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|file
modifier|*
name|fp
parameter_list|,
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Drivers and line disciplines also need to call these. */
end_comment

begin_include
include|#
directive|include
file|<sys/ttydisc.h>
end_include

begin_include
include|#
directive|include
file|<sys/ttydevsw.h>
end_include

begin_include
include|#
directive|include
file|<sys/ttyhook.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TTY_H_ */
end_comment

end_unit

