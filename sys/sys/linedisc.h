begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 2000  *	Poul-Henning Kamp.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)conf.h	8.5 (Berkeley) 1/9/95  * $FreeBSD$  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

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

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|snaphead
argument_list|,
name|inode
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|cdev
block|{
name|u_int
name|si_flags
decl_stmt|;
define|#
directive|define
name|SI_STASHED
value|0x0001
comment|/* created in stashed storage */
define|#
directive|define
name|SI_ALIAS
value|0x0002
comment|/* carrier of alias name */
define|#
directive|define
name|SI_NAMED
value|0x0004
comment|/* make_dev{_alias} has been called */
define|#
directive|define
name|SI_CHEAPCLONE
value|0x0008
comment|/* can be removed_dev'ed when vnode reclaims */
define|#
directive|define
name|SI_CHILD
value|0x0010
comment|/* child of another dev_t */
define|#
directive|define
name|SI_DEVOPEN
value|0x0020
comment|/* opened by device */
define|#
directive|define
name|SI_CONSOPEN
value|0x0040
comment|/* opened by console */
define|#
directive|define
name|SI_DUMPDEV
value|0x0080
comment|/* is kernel dumpdev */
name|struct
name|timespec
name|si_atime
decl_stmt|;
name|struct
name|timespec
name|si_ctime
decl_stmt|;
name|struct
name|timespec
name|si_mtime
decl_stmt|;
name|udev_t
name|si_udev
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|cdev
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
name|LIST_HEAD
argument_list|(
argument_list|,
argument|cdev
argument_list|)
name|si_children
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|cdev
argument_list|)
name|si_siblings
expr_stmt|;
name|dev_t
name|si_parent
decl_stmt|;
name|u_int
name|si_inode
decl_stmt|;
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
name|uid_t
name|si_uid
decl_stmt|;
name|gid_t
name|si_gid
decl_stmt|;
name|mode_t
name|si_mode
decl_stmt|;
name|u_long
name|si_usecount
decl_stmt|;
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
name|struct
name|snaphead
name|__sid_snapshots
decl_stmt|;
name|daddr_t
name|__sid_snaplistsize
decl_stmt|;
comment|/* size of snapblklist. */
name|daddr_t
modifier|*
name|__sid_snapblklist
decl_stmt|;
comment|/* known snapshot blocks. */
name|int
function_decl|(
modifier|*
name|__sid_copyonwrite
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
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

begin_define
define|#
directive|define
name|si_snapshots
value|__si_u.__si_disk.__sid_snapshots
end_define

begin_define
define|#
directive|define
name|si_snaplistsize
value|__si_u.__si_disk.__sid_snaplistsize
end_define

begin_define
define|#
directive|define
name|si_snapblklist
value|__si_u.__si_disk.__sid_snapblklist
end_define

begin_define
define|#
directive|define
name|si_copyonwrite
value|__si_u.__si_disk.__sid_copyonwrite
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
name|bio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
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

begin_comment
comment|/*  * Note: d_thread_t is provided as a transition aid for those drivers  * that treat struct proc/struct thread as an opaque data type and  * exist in substantially the same form in both 4.x and 5.x.  Writers  * of drivers that dips into the d_thread_t structure should use  * struct thread or struct proc as appropriate for the version of the  * OS they are using.  It is provided in lieu of each device driver  * inventing its own way of doing this.  While it does violate style(9)  * in a number of ways, this violation is deemed to be less  * important than the benefits that a uniform API between releases  * gives.  *  * Users of struct thread/struct proc that aren't device drivers should  * not use d_thread_t.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|thread
name|d_thread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_open_t
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|oflags
parameter_list|,
name|int
name|devtype
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_close_t
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|fflag
parameter_list|,
name|int
name|devtype
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|d_strategy_t
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_ioctl_t
parameter_list|(
name|dev_t
name|dev
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
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_dump_t
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|void
modifier|*
name|virtual
parameter_list|,
name|vm_offset_t
name|physical
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_psize_t
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_read_t
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|ioflag
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_write_t
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|ioflag
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_poll_t
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|events
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_kqfilter_t
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|knote
modifier|*
name|kn
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_mmap_t
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|vm_offset_t
name|offset
parameter_list|,
name|int
name|nprot
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_open_t
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_close_t
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_read_t
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_write_t
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_ioctl_t
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
name|flag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_rint_t
parameter_list|(
name|int
name|c
parameter_list|,
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_start_t
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|l_modem_t
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|BIO_STRATEGY
parameter_list|(
name|bp
parameter_list|)
define|\
value|do {								\ 	if ((!(bp)->bio_cmd) || ((bp)->bio_cmd& ((bp)->bio_cmd - 1)))	\ 		Debugger("bio_cmd botch");				\ 	(*devsw((bp)->bio_dev)->d_strategy)(bp);			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|DEV_STRATEGY
parameter_list|(
name|bp
parameter_list|,
name|dummy
parameter_list|)
define|\
value|do {								\ 	if ((bp)->b_flags& B_PHYS)					\ 		(bp)->b_io.bio_offset = (bp)->b_offset;			\ 	else								\ 		(bp)->b_io.bio_offset = dbtob((bp)->b_blkno);		\ 	(bp)->b_io.bio_done = bufdonebio;				\ 	(bp)->b_io.bio_caller2 = (bp);					\ 	BIO_STRATEGY(&(bp)->b_io);					\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
name|D_MMAP_ANON
value|0x00100000
end_define

begin_comment
comment|/* special treatment in vm_mmap.c */
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

begin_define
define|#
directive|define
name|D_NOGIANT
value|0x00400000
end_define

begin_comment
comment|/* Doesn't want Giant */
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

begin_function_decl
name|int
name|ldisc_register
parameter_list|(
name|int
parameter_list|,
name|struct
name|linesw
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ldisc_deregister
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* _KERNEL */
end_comment

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
name|int
name|sw_used
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
name|SW_CLOSING
value|0x04
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
name|l_ioctl_t
name|l_nullioctl
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

begin_function_decl
name|int
name|cdevsw_add
parameter_list|(
name|struct
name|cdevsw
modifier|*
name|_new
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cdevsw_remove
parameter_list|(
name|struct
name|cdevsw
modifier|*
name|_old
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|count_dev
parameter_list|(
name|dev_t
name|_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|destroy_dev
parameter_list|(
name|dev_t
name|_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|revoke_and_destroy_dev
parameter_list|(
name|dev_t
name|_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cdevsw
modifier|*
name|devsw
parameter_list|(
name|dev_t
name|_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|devtoname
parameter_list|(
name|dev_t
name|_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dev_named
parameter_list|(
name|dev_t
name|_pdev
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dev_depends
parameter_list|(
name|dev_t
name|_pdev
parameter_list|,
name|dev_t
name|_cdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freedev
parameter_list|(
name|dev_t
name|_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iszerodev
parameter_list|(
name|dev_t
name|_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dev_t
name|makebdev
parameter_list|(
name|int
name|_maj
parameter_list|,
name|int
name|_min
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dev_t
name|make_dev
parameter_list|(
name|struct
name|cdevsw
modifier|*
name|_devsw
parameter_list|,
name|int
name|_minor
parameter_list|,
name|uid_t
name|_uid
parameter_list|,
name|gid_t
name|_gid
parameter_list|,
name|int
name|_perms
parameter_list|,
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|6
operator|,
function_decl|7
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|dev_t
name|make_dev_alias
parameter_list|(
name|dev_t
name|_pdev
parameter_list|,
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|dev2unit
parameter_list|(
name|dev_t
name|_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unit2minor
parameter_list|(
name|int
name|_unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setconf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dev_t
name|getdiskbyname
parameter_list|(
name|char
modifier|*
name|_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This is type of the function DEVFS uses to hook into the kernel with */
end_comment

begin_typedef
typedef|typedef
name|void
name|devfs_create_t
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|devfs_destroy_t
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|devfs_create_t
modifier|*
name|devfs_create_hook
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devfs_destroy_t
modifier|*
name|devfs_destroy_hook
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|devfs_present
decl_stmt|;
end_decl_stmt

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

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dev_clone_fn
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|,
name|dev_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|dev_stdclone
parameter_list|(
name|char
modifier|*
name|_name
parameter_list|,
name|char
modifier|*
modifier|*
name|_namep
parameter_list|,
specifier|const
name|char
modifier|*
name|_stem
parameter_list|,
name|int
modifier|*
name|_unit
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|dev_clone
argument_list|,
name|dev_clone_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Stuff relating to kernel-dump */
end_comment

begin_typedef
typedef|typedef
name|int
name|dumper_t
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
comment|/* Private to the driver. */
name|void
modifier|*
name|virtual
parameter_list|,
comment|/* Virtual (mapped) address. */
name|vm_offset_t
name|physical
parameter_list|,
comment|/* Physical address of virtual. */
name|off_t
name|offset
parameter_list|,
comment|/* Byte-offset to write at. */
name|size_t
name|length
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Number of bytes to dump. */
end_comment

begin_struct
struct|struct
name|dumperinfo
block|{
name|dumper_t
modifier|*
name|dumper
decl_stmt|;
comment|/* Dumping function. */
name|void
modifier|*
name|priv
decl_stmt|;
comment|/* Private parts. */
name|u_int
name|blocksize
decl_stmt|;
comment|/* Size of block in bytes. */
name|off_t
name|mediaoffset
decl_stmt|;
comment|/* Initial offset in bytes. */
name|off_t
name|mediasize
decl_stmt|;
comment|/* Space available in bytes. */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|set_dumper
parameter_list|(
name|struct
name|dumperinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dumpsys
parameter_list|(
name|struct
name|dumperinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|dumping
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system is dumping */
end_comment

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

