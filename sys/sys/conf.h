begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)conf.h	8.5 (Berkeley) 1/9/95  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_define
define|#
directive|define
name|SPECNAMELEN
value|15
end_define

begin_struct_decl
struct_decl|struct
name|tty
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|disk
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|specinfo
block|{
name|u_int
name|si_flags
decl_stmt|;
define|#
directive|define
name|SI_STASHED
value|0x0001
comment|/* created in stashed storage */
name|udev_t
name|si_udev
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|specinfo
argument_list|)
name|si_hash
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|vnode
argument_list|)
name|si_hlist
expr_stmt|;
name|char
name|si_name
index|[
name|SPECNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
name|void
modifier|*
name|si_drv1
decl_stmt|,
modifier|*
name|si_drv2
decl_stmt|;
name|struct
name|cdevsw
modifier|*
name|si_devsw
decl_stmt|;
name|int
name|si_iosize_max
decl_stmt|;
comment|/* maximum I/O size (for physio&al) */
union|union
block|{
struct|struct
block|{
name|struct
name|tty
modifier|*
name|__sit_tty
decl_stmt|;
block|}
name|__si_tty
struct|;
struct|struct
block|{
name|struct
name|disk
modifier|*
name|__sid_disk
decl_stmt|;
name|struct
name|mount
modifier|*
name|__sid_mountpoint
decl_stmt|;
name|int
name|__sid_bsize_phys
decl_stmt|;
comment|/* min physical block size */
name|int
name|__sid_bsize_best
decl_stmt|;
comment|/* optimal block size */
block|}
name|__si_disk
struct|;
block|}
name|__si_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|si_tty
value|__si_u.__si_tty.__sit_tty
end_define

begin_define
define|#
directive|define
name|si_disk
value|__si_u.__si_disk.__sid_disk
end_define

begin_define
define|#
directive|define
name|si_mountpoint
value|__si_u.__si_disk.__sid_mountpoint
end_define

begin_define
define|#
directive|define
name|si_bsize_phys
value|__si_u.__si_disk.__sid_bsize_phys
end_define

begin_define
define|#
directive|define
name|si_bsize_best
value|__si_u.__si_disk.__sid_bsize_best
end_define

begin_comment
comment|/*  * Exported shorthand  */
end_comment

begin_define
define|#
directive|define
name|v_hashchain
value|v_rdev->si_hlist
end_define

begin_define
define|#
directive|define
name|v_specmountpoint
value|v_rdev->si_mountpoint
end_define

begin_comment
comment|/*  * Special device management  */
end_comment

begin_define
define|#
directive|define
name|SPECHSZ
value|64
end_define

begin_define
define|#
directive|define
name|SPECHASH
parameter_list|(
name|rdev
parameter_list|)
value|(((unsigned)(minor(rdev)))%SPECHSZ)
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
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|knote
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
name|d_parms_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|, struct
name|specinfo
modifier|*
name|sinfo
typedef|,
name|int
name|ctl
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
name|u_long
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
name|d_kqfilter_t
name|__P
typedef|((
name|dev_t
name|dev
typedef|, struct
name|knote
modifier|*
name|kn
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
name|vm_offset_t
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
name|u_long
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
comment|/*  * XXX: The dummy argument can be used to do what strategy1() never  * did anywhere:  Create a per device flag to lock the device during  * label/slice surgery, all calls with a dummy == 0 gets stalled on  * a queue somewhere, whereas dummy == 1 are let through.  Once out  * of surgery, reset the flag and restart all the stuff on the stall  * queue.  */
end_comment

begin_define
define|#
directive|define
name|BUF_STRATEGY
parameter_list|(
name|bp
parameter_list|,
name|dummy
parameter_list|)
value|(*devsw((bp)->b_dev)->d_strategy)(bp)
end_define

begin_comment
comment|/*  * Types for d_flags.  */
end_comment

begin_define
define|#
directive|define
name|D_TAPE
value|0x0001
end_define

begin_define
define|#
directive|define
name|D_DISK
value|0x0002
end_define

begin_define
define|#
directive|define
name|D_TTY
value|0x0004
end_define

begin_define
define|#
directive|define
name|D_MEM
value|0x0008
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
name|D_MEMDISK
value|0x00010000
end_define

begin_comment
comment|/* memory type disk */
end_comment

begin_define
define|#
directive|define
name|D_NAGGED
value|0x00020000
end_define

begin_comment
comment|/* nagged about missing make_dev() */
end_comment

begin_define
define|#
directive|define
name|D_CANFREE
value|0x00040000
end_define

begin_comment
comment|/* can free blocks */
end_comment

begin_define
define|#
directive|define
name|D_TRACKCLOSE
value|0x00080000
end_define

begin_comment
comment|/* track all closes */
end_comment

begin_define
define|#
directive|define
name|D_KQFILTER
value|0x00200000
end_define

begin_comment
comment|/* has kqfilter entry */
end_comment

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
specifier|const
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* base device name, e.g. 'vn' */
name|int
name|d_maj
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
name|int
name|d_bmaj
decl_stmt|;
comment|/* additions below are not binary compatible with 4.2 and below */
name|d_kqfilter_t
modifier|*
name|d_kqfilter
decl_stmt|;
block|}
struct|;
end_struct

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
name|u_char
name|l_hotchar
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
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
name|udev_t
name|sw_dev
decl_stmt|;
comment|/* For quasibogus swapdev reporting */
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
name|dev_t
name|sw_device
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
name|_KERNEL
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
name|d_mmap_t
name|nommap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_kqfilter_t
name|nokqfilter
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|nostrategy
value|((d_strategy_t *)NULL)
end_define

begin_define
define|#
directive|define
name|nopoll
value|seltrue
end_define

begin_decl_stmt
name|d_dump_t
name|nodump
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMCDEVSW
value|256
end_define

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

begin_struct_decl
struct_decl|struct
name|module
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|devsw_module_data
block|{
name|int
function_decl|(
modifier|*
name|chainevh
function_decl|)
parameter_list|(
name|struct
name|module
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* next handler */
name|void
modifier|*
name|chainarg
decl_stmt|;
comment|/* arg for next event handler */
comment|/* Do not initialize fields hereafter */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEV_MODULE
parameter_list|(
name|name
parameter_list|,
name|evh
parameter_list|,
name|arg
parameter_list|)
define|\
value|static moduledata_t name##_mod = {					\     #name,								\     evh,								\     arg									\ };									\ DECLARE_MODULE(name, name##_mod, SI_SUB_DRIVERS, SI_ORDER_MIDDLE)
end_define

begin_decl_stmt
name|int
name|cdevsw_add
name|__P
argument_list|(
operator|(
expr|struct
name|cdevsw
operator|*
name|new
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cdevsw_remove
name|__P
argument_list|(
operator|(
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
name|count_dev
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
name|destroy_dev
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
name|struct
name|cdevsw
modifier|*
name|devsw
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
specifier|const
name|char
modifier|*
name|devtoname
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
name|freedev
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
name|dev_t
name|makebdev
name|__P
argument_list|(
operator|(
name|int
name|maj
operator|,
name|int
name|min
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|make_dev
name|__P
argument_list|(
operator|(
expr|struct
name|cdevsw
operator|*
name|devsw
operator|,
name|int
name|minor
operator|,
name|uid_t
name|uid
operator|,
name|gid_t
name|gid
operator|,
name|int
name|perms
operator|,
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
name|__printflike
argument_list|(
literal|6
argument_list|,
literal|7
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lminor
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

begin_comment
comment|/*  * XXX: This included for when DEVFS resurfaces   */
end_comment

begin_define
define|#
directive|define
name|UID_ROOT
value|0
end_define

begin_define
define|#
directive|define
name|UID_BIN
value|3
end_define

begin_define
define|#
directive|define
name|UID_UUCP
value|66
end_define

begin_define
define|#
directive|define
name|GID_WHEEL
value|0
end_define

begin_define
define|#
directive|define
name|GID_KMEM
value|2
end_define

begin_define
define|#
directive|define
name|GID_OPERATOR
value|5
end_define

begin_define
define|#
directive|define
name|GID_BIN
value|7
end_define

begin_define
define|#
directive|define
name|GID_GAMES
value|13
end_define

begin_define
define|#
directive|define
name|GID_DIALER
value|68
end_define

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
comment|/* !_SYS_CONF_H_ */
end_comment

end_unit

