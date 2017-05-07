begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 2000  *	Poul-Henning Kamp.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)conf.h	8.5 (Berkeley) 1/9/95  * $FreeBSD$  */
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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|snapdata
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|devfs_dirent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cdevsw
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|file
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|cdev
block|{
name|void
modifier|*
name|si_spare0
decl_stmt|;
name|u_int
name|si_flags
decl_stmt|;
define|#
directive|define
name|SI_ETERNAL
value|0x0001
comment|/* never destroyed */
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
comment|/* child of another struct cdev **/
define|#
directive|define
name|SI_DUMPDEV
value|0x0080
comment|/* is kernel dumpdev */
define|#
directive|define
name|SI_CLONELIST
value|0x0200
comment|/* on a clone list */
define|#
directive|define
name|SI_UNMAPPED
value|0x0400
comment|/* can handle unmapped I/O */
define|#
directive|define
name|SI_NOSPLIT
value|0x0800
comment|/* I/O should not be split up */
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
name|uid_t
name|si_uid
decl_stmt|;
name|gid_t
name|si_gid
decl_stmt|;
name|mode_t
name|si_mode
decl_stmt|;
name|struct
name|ucred
modifier|*
name|si_cred
decl_stmt|;
comment|/* cached clone-time credential */
name|int
name|si_drv0
decl_stmt|;
name|int
name|si_refcount
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|cdev
argument_list|)
name|si_list
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|cdev
argument_list|)
name|si_clone
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
name|struct
name|cdev
modifier|*
name|si_parent
decl_stmt|;
name|struct
name|mount
modifier|*
name|si_mountpt
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
name|u_long
name|si_usecount
decl_stmt|;
name|u_long
name|si_threadcount
decl_stmt|;
union|union
block|{
name|struct
name|snapdata
modifier|*
name|__sid_snapdata
decl_stmt|;
block|}
name|__si_u
union|;
name|char
name|si_name
index|[
name|SPECNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|si_snapdata
value|__si_u.__sid_snapdata
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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

begin_struct_decl
struct_decl|struct
name|clonedevs
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vm_object
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
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
name|struct
name|cdev
modifier|*
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
name|d_fdopen_t
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|int
name|oflags
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
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_close_t
parameter_list|(
name|struct
name|cdev
modifier|*
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
name|struct
name|cdev
modifier|*
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
name|d_read_t
parameter_list|(
name|struct
name|cdev
modifier|*
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
name|struct
name|cdev
modifier|*
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
name|struct
name|cdev
modifier|*
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
name|struct
name|cdev
modifier|*
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
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|vm_ooffset_t
name|offset
parameter_list|,
name|vm_paddr_t
modifier|*
name|paddr
parameter_list|,
name|int
name|nprot
parameter_list|,
name|vm_memattr_t
modifier|*
name|memattr
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|d_mmap_single_t
parameter_list|(
name|struct
name|cdev
modifier|*
name|cdev
parameter_list|,
name|vm_ooffset_t
modifier|*
name|offset
parameter_list|,
name|vm_size_t
name|size
parameter_list|,
name|struct
name|vm_object
modifier|*
modifier|*
name|object
parameter_list|,
name|int
name|nprot
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|d_purge_t
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|dumper_t
parameter_list|(
name|void
modifier|*
name|_priv
parameter_list|,
comment|/* Private to the driver. */
name|void
modifier|*
name|_virtual
parameter_list|,
comment|/* Virtual (mapped) address. */
name|vm_offset_t
name|_physical
parameter_list|,
comment|/* Physical address of virtual. */
name|off_t
name|_offset
parameter_list|,
comment|/* Byte-offset to write at. */
name|size_t
name|_length
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Number of bytes to dump. */
end_comment

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

begin_comment
comment|/* /dev/(k)mem */
end_comment

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
comment|/*  * Flags for d_flags which the drivers can set.  */
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
name|D_NEEDGIANT
value|0x00400000
end_define

begin_comment
comment|/* driver want Giant */
end_comment

begin_define
define|#
directive|define
name|D_NEEDMINOR
value|0x00800000
end_define

begin_comment
comment|/* driver uses clone_create() */
end_comment

begin_comment
comment|/*  * Version numbers.  */
end_comment

begin_define
define|#
directive|define
name|D_VERSION_00
value|0x20011966
end_define

begin_define
define|#
directive|define
name|D_VERSION_01
value|0x17032005
end_define

begin_comment
comment|/* Add d_uid,gid,mode& kind */
end_comment

begin_define
define|#
directive|define
name|D_VERSION_02
value|0x28042009
end_define

begin_comment
comment|/* Add d_mmap_single */
end_comment

begin_define
define|#
directive|define
name|D_VERSION_03
value|0x17122009
end_define

begin_comment
comment|/* d_mmap takes memattr,vm_ooffset_t */
end_comment

begin_define
define|#
directive|define
name|D_VERSION
value|D_VERSION_03
end_define

begin_comment
comment|/*  * Flags used for internal housekeeping  */
end_comment

begin_define
define|#
directive|define
name|D_INIT
value|0x80000000
end_define

begin_comment
comment|/* cdevsw initialized */
end_comment

begin_comment
comment|/*  * Character device switch table  */
end_comment

begin_struct
struct|struct
name|cdevsw
block|{
name|int
name|d_version
decl_stmt|;
name|u_int
name|d_flags
decl_stmt|;
specifier|const
name|char
modifier|*
name|d_name
decl_stmt|;
name|d_open_t
modifier|*
name|d_open
decl_stmt|;
name|d_fdopen_t
modifier|*
name|d_fdopen
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
name|dumper_t
modifier|*
name|d_dump
decl_stmt|;
name|d_kqfilter_t
modifier|*
name|d_kqfilter
decl_stmt|;
name|d_purge_t
modifier|*
name|d_purge
decl_stmt|;
name|d_mmap_single_t
modifier|*
name|d_mmap_single
decl_stmt|;
name|int32_t
name|d_spare0
index|[
literal|3
index|]
decl_stmt|;
name|void
modifier|*
name|d_spare1
index|[
literal|3
index|]
decl_stmt|;
comment|/* These fields should not be messed with by drivers */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|cdev
argument_list|)
name|d_devs
expr_stmt|;
name|int
name|d_spare2
decl_stmt|;
union|union
block|{
name|struct
name|cdevsw
modifier|*
name|gianttrick
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|cdevsw
argument_list|)
name|postfree_list
expr_stmt|;
block|}
name|__d_giant
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|d_gianttrick
value|__d_giant.gianttrick
end_define

begin_define
define|#
directive|define
name|d_postfree_list
value|__d_giant.postfree_list
end_define

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
name|DEV_MODULE_ORDERED
parameter_list|(
name|name
parameter_list|,
name|evh
parameter_list|,
name|arg
parameter_list|,
name|ord
parameter_list|)
define|\
value|static moduledata_t name##_mod = {					\     #name,								\     evh,								\     arg									\ };									\ DECLARE_MODULE(name, name##_mod, SI_SUB_DRIVERS, ord)
end_define

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
value|DEV_MODULE_ORDERED(name, evh, arg, SI_ORDER_MIDDLE)
end_define

begin_function_decl
name|void
name|clone_setup
parameter_list|(
name|struct
name|clonedevs
modifier|*
modifier|*
name|cdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clone_cleanup
parameter_list|(
name|struct
name|clonedevs
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CLONE_UNITMASK
value|0xfffff
end_define

begin_define
define|#
directive|define
name|CLONE_FLAG0
value|(CLONE_UNITMASK + 1)
end_define

begin_function_decl
name|int
name|clone_create
parameter_list|(
name|struct
name|clonedevs
modifier|*
modifier|*
parameter_list|,
name|struct
name|cdevsw
modifier|*
parameter_list|,
name|int
modifier|*
name|unit
parameter_list|,
name|struct
name|cdev
modifier|*
modifier|*
name|dev
parameter_list|,
name|int
name|extra
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MAKEDEV_REF
value|0x01
end_define

begin_define
define|#
directive|define
name|MAKEDEV_WHTOUT
value|0x02
end_define

begin_define
define|#
directive|define
name|MAKEDEV_NOWAIT
value|0x04
end_define

begin_define
define|#
directive|define
name|MAKEDEV_WAITOK
value|0x08
end_define

begin_define
define|#
directive|define
name|MAKEDEV_ETERNAL
value|0x10
end_define

begin_define
define|#
directive|define
name|MAKEDEV_CHECKNAME
value|0x20
end_define

begin_struct
struct|struct
name|make_dev_args
block|{
name|size_t
name|mda_size
decl_stmt|;
name|int
name|mda_flags
decl_stmt|;
name|struct
name|cdevsw
modifier|*
name|mda_devsw
decl_stmt|;
name|struct
name|ucred
modifier|*
name|mda_cr
decl_stmt|;
name|uid_t
name|mda_uid
decl_stmt|;
name|gid_t
name|mda_gid
decl_stmt|;
name|int
name|mda_mode
decl_stmt|;
name|int
name|mda_unit
decl_stmt|;
name|void
modifier|*
name|mda_si_drv1
decl_stmt|;
name|void
modifier|*
name|mda_si_drv2
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|make_dev_args_init_impl
parameter_list|(
name|struct
name|make_dev_args
modifier|*
name|_args
parameter_list|,
name|size_t
name|_sz
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|make_dev_args_init
parameter_list|(
name|a
parameter_list|)
define|\
value|make_dev_args_init_impl((a), sizeof(struct make_dev_args))
end_define

begin_function_decl
name|int
name|count_dev
parameter_list|(
name|struct
name|cdev
modifier|*
name|_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delist_dev
parameter_list|(
name|struct
name|cdev
modifier|*
name|_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|destroy_dev
parameter_list|(
name|struct
name|cdev
modifier|*
name|_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|destroy_dev_sched
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|destroy_dev_sched_cb
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|destroy_dev_drain
parameter_list|(
name|struct
name|cdevsw
modifier|*
name|csw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drain_dev_clone_events
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cdevsw
modifier|*
name|dev_refthread
parameter_list|(
name|struct
name|cdev
modifier|*
name|_dev
parameter_list|,
name|int
modifier|*
name|_ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cdevsw
modifier|*
name|devvn_refthread
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|cdev
modifier|*
modifier|*
name|devp
parameter_list|,
name|int
modifier|*
name|_ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dev_relthread
parameter_list|(
name|struct
name|cdev
modifier|*
name|_dev
parameter_list|,
name|int
name|_ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dev_depends
parameter_list|(
name|struct
name|cdev
modifier|*
name|_pdev
parameter_list|,
name|struct
name|cdev
modifier|*
name|_cdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dev_ref
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dev_refl
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dev_rel
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dev_strategy
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dev_strategy_csw
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|struct
name|cdevsw
modifier|*
name|csw
parameter_list|,
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cdev
modifier|*
name|make_dev
parameter_list|(
name|struct
name|cdevsw
modifier|*
name|_devsw
parameter_list|,
name|int
name|_unit
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
name|struct
name|cdev
modifier|*
name|make_dev_cred
parameter_list|(
name|struct
name|cdevsw
modifier|*
name|_devsw
parameter_list|,
name|int
name|_unit
parameter_list|,
name|struct
name|ucred
modifier|*
name|_cr
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
function_decl|7
operator|,
function_decl|8
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|struct
name|cdev
modifier|*
name|make_dev_credf
parameter_list|(
name|int
name|_flags
parameter_list|,
name|struct
name|cdevsw
modifier|*
name|_devsw
parameter_list|,
name|int
name|_unit
parameter_list|,
name|struct
name|ucred
modifier|*
name|_cr
parameter_list|,
name|uid_t
name|_uid
parameter_list|,
name|gid_t
name|_gid
parameter_list|,
name|int
name|_mode
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
function_decl|8
operator|,
function_decl|9
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|make_dev_p
parameter_list|(
name|int
name|_flags
parameter_list|,
name|struct
name|cdev
modifier|*
modifier|*
name|_cdev
parameter_list|,
name|struct
name|cdevsw
modifier|*
name|_devsw
parameter_list|,
name|struct
name|ucred
modifier|*
name|_cr
parameter_list|,
name|uid_t
name|_uid
parameter_list|,
name|gid_t
name|_gid
parameter_list|,
name|int
name|_mode
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
function_decl|8
operator|,
function_decl|9
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|make_dev_s
parameter_list|(
name|struct
name|make_dev_args
modifier|*
name|_args
parameter_list|,
name|struct
name|cdev
modifier|*
modifier|*
name|_cdev
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
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|struct
name|cdev
modifier|*
name|make_dev_alias
parameter_list|(
name|struct
name|cdev
modifier|*
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
name|make_dev_alias_p
parameter_list|(
name|int
name|_flags
parameter_list|,
name|struct
name|cdev
modifier|*
modifier|*
name|_cdev
parameter_list|,
name|struct
name|cdev
modifier|*
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
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|make_dev_physpath_alias
parameter_list|(
name|int
name|_flags
parameter_list|,
name|struct
name|cdev
modifier|*
modifier|*
name|_cdev
parameter_list|,
name|struct
name|cdev
modifier|*
name|_pdev
parameter_list|,
name|struct
name|cdev
modifier|*
name|_old_alias
parameter_list|,
specifier|const
name|char
modifier|*
name|_physpath
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dev_lock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dev_unlock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KLD_MODULE
end_ifdef

begin_define
define|#
directive|define
name|MAKEDEV_ETERNAL_KLD
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAKEDEV_ETERNAL_KLD
value|MAKEDEV_ETERNAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|dev2unit
parameter_list|(
name|d
parameter_list|)
value|((d)->si_drv0)
end_define

begin_typedef
typedef|typedef
name|void
name|d_priv_dtor_t
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|devfs_get_cdevpriv
parameter_list|(
name|void
modifier|*
modifier|*
name|datap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devfs_set_cdevpriv
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|,
name|d_priv_dtor_t
modifier|*
name|dtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devfs_clear_cdevpriv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devfs_fpdrop
parameter_list|(
name|struct
name|file
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX This is not public KPI */
end_comment

begin_function_decl
name|ino_t
name|devfs_alloc_cdp_inode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devfs_free_cdp_inode
parameter_list|(
name|ino_t
name|ino
parameter_list|)
function_decl|;
end_function_decl

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
name|UID_NOBODY
value|65534
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
name|GID_TTY
value|4
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

begin_define
define|#
directive|define
name|GID_NOGROUP
value|65533
end_define

begin_define
define|#
directive|define
name|GID_NOBODY
value|65534
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
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|,
name|struct
name|cdev
modifier|*
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
name|u_int
name|maxiosize
decl_stmt|;
comment|/* Max size allowed for an individual I/O */
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
parameter_list|,
specifier|const
name|char
modifier|*
name|_devname
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
name|dump_write
parameter_list|(
name|struct
name|dumperinfo
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|off_t
parameter_list|,
name|size_t
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

begin_function_decl
name|int
name|doadump
parameter_list|(
name|boolean_t
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

