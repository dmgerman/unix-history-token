begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)file.h	8.3 (Berkeley) 1/9/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FILE_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
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

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_struct_decl
struct_decl|struct
name|stat
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
name|vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|DTYPE_VNODE
value|1
end_define

begin_comment
comment|/* file */
end_comment

begin_define
define|#
directive|define
name|DTYPE_SOCKET
value|2
end_define

begin_comment
comment|/* communications endpoint */
end_comment

begin_define
define|#
directive|define
name|DTYPE_PIPE
value|3
end_define

begin_comment
comment|/* pipe */
end_comment

begin_define
define|#
directive|define
name|DTYPE_FIFO
value|4
end_define

begin_comment
comment|/* fifo (named pipe) */
end_comment

begin_define
define|#
directive|define
name|DTYPE_KQUEUE
value|5
end_define

begin_comment
comment|/* event queue */
end_comment

begin_define
define|#
directive|define
name|DTYPE_CRYPTO
value|6
end_define

begin_comment
comment|/* crypto */
end_comment

begin_define
define|#
directive|define
name|DTYPE_MQUEUE
value|7
end_define

begin_comment
comment|/* posix message queue */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|fo_rdwr_t
parameter_list|(
name|struct
name|file
modifier|*
name|fp
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|struct
name|ucred
modifier|*
name|active_cred
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|FOF_OFFSET
value|1
end_define

begin_comment
comment|/* Use the offset in uio argument */
end_comment

begin_typedef
typedef|typedef
name|int
name|fo_ioctl_t
parameter_list|(
name|struct
name|file
modifier|*
name|fp
parameter_list|,
name|u_long
name|com
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|ucred
modifier|*
name|active_cred
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
name|fo_poll_t
parameter_list|(
name|struct
name|file
modifier|*
name|fp
parameter_list|,
name|int
name|events
parameter_list|,
name|struct
name|ucred
modifier|*
name|active_cred
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
name|fo_kqfilter_t
parameter_list|(
name|struct
name|file
modifier|*
name|fp
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
name|fo_stat_t
parameter_list|(
name|struct
name|file
modifier|*
name|fp
parameter_list|,
name|struct
name|stat
modifier|*
name|sb
parameter_list|,
name|struct
name|ucred
modifier|*
name|active_cred
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
name|fo_close_t
parameter_list|(
name|struct
name|file
modifier|*
name|fp
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
name|fo_flags_t
typedef|;
end_typedef

begin_struct
struct|struct
name|fileops
block|{
name|fo_rdwr_t
modifier|*
name|fo_read
decl_stmt|;
name|fo_rdwr_t
modifier|*
name|fo_write
decl_stmt|;
name|fo_ioctl_t
modifier|*
name|fo_ioctl
decl_stmt|;
name|fo_poll_t
modifier|*
name|fo_poll
decl_stmt|;
name|fo_kqfilter_t
modifier|*
name|fo_kqfilter
decl_stmt|;
name|fo_stat_t
modifier|*
name|fo_stat
decl_stmt|;
name|fo_close_t
modifier|*
name|fo_close
decl_stmt|;
name|fo_flags_t
name|fo_flags
decl_stmt|;
comment|/* DFLAG_* below */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DFLAG_PASSABLE
value|0x01
end_define

begin_comment
comment|/* may be passed via unix sockets. */
end_comment

begin_define
define|#
directive|define
name|DFLAG_SEEKABLE
value|0x02
end_define

begin_comment
comment|/* seekable / nonsequential */
end_comment

begin_comment
comment|/*  * Kernel descriptor table.  * One entry for each open kernel vnode and socket.  *  * Below is the list of locks that protects members in struct file.  *  * (fl)	filelist_lock  * (f)	f_mtx in struct file  * none	not locked  */
end_comment

begin_struct
struct|struct
name|file
block|{
name|LIST_ENTRY
argument_list|(
argument|file
argument_list|)
name|f_list
expr_stmt|;
comment|/* (fl) list of active files */
name|short
name|f_type
decl_stmt|;
comment|/* descriptor type */
name|void
modifier|*
name|f_data
decl_stmt|;
comment|/* file descriptor specific data */
name|u_int
name|f_flag
decl_stmt|;
comment|/* see fcntl.h */
name|struct
name|mtx
modifier|*
name|f_mtxp
decl_stmt|;
comment|/* mutex to protect data */
name|struct
name|fileops
modifier|*
name|f_ops
decl_stmt|;
comment|/* File operations */
name|struct
name|ucred
modifier|*
name|f_cred
decl_stmt|;
comment|/* credentials associated with descriptor */
name|int
name|f_count
decl_stmt|;
comment|/* (f) reference count */
name|struct
name|vnode
modifier|*
name|f_vnode
decl_stmt|;
comment|/* NULL or applicable vnode */
comment|/* DFLAG_SEEKABLE specific fields */
name|off_t
name|f_offset
decl_stmt|;
name|short
name|f_vnread_flags
decl_stmt|;
comment|/*  				   * (f) home grown sleep lock for f_offset 				   * Used only for shared vnode locking in 				   * vnread() 				   */
define|#
directive|define
name|FOFFSET_LOCKED
value|0x1
define|#
directive|define
name|FOFFSET_LOCK_WAITING
value|0x2
comment|/* DTYPE_SOCKET specific fields */
name|short
name|f_gcflag
decl_stmt|;
comment|/* used by thread doing fd garbage collection */
define|#
directive|define
name|FMARK
value|0x1
comment|/* mark during gc() */
define|#
directive|define
name|FDEFER
value|0x2
comment|/* defer for next gc pass */
define|#
directive|define
name|FWAIT
value|0x4
comment|/* gc is scanning message buffers */
name|int
name|f_msgcount
decl_stmt|;
comment|/* (f) references from message queue */
comment|/* DTYPE_VNODE specific fields */
name|int
name|f_seqcount
decl_stmt|;
comment|/* 				 * count of sequential accesses -- cleared 				 * by most seek operations. 				 */
name|off_t
name|f_nextoff
decl_stmt|;
comment|/* 				 * offset of next expected read or write 				 */
name|void
modifier|*
name|f_label
decl_stmt|;
comment|/* Place-holder for struct label pointer. */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Userland version of struct file, for sysctl  */
end_comment

begin_struct
struct|struct
name|xfile
block|{
name|size_t
name|xf_size
decl_stmt|;
comment|/* size of struct xfile */
name|pid_t
name|xf_pid
decl_stmt|;
comment|/* owning process */
name|uid_t
name|xf_uid
decl_stmt|;
comment|/* effective uid of owning process */
name|int
name|xf_fd
decl_stmt|;
comment|/* descriptor number */
name|void
modifier|*
name|xf_file
decl_stmt|;
comment|/* address of struct file */
name|short
name|xf_type
decl_stmt|;
comment|/* descriptor type */
name|int
name|xf_count
decl_stmt|;
comment|/* reference count */
name|int
name|xf_msgcount
decl_stmt|;
comment|/* references from message queue */
name|off_t
name|xf_offset
decl_stmt|;
comment|/* file offset */
name|void
modifier|*
name|xf_data
decl_stmt|;
comment|/* file descriptor specific data */
name|void
modifier|*
name|xf_vnode
decl_stmt|;
comment|/* vnode pointer */
name|u_int
name|xf_flag
decl_stmt|;
comment|/* flags (see fcntl.h) */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_FILE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|filelist
argument_list|,
name|file
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|filelist
name|filehead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* (fl) head of list of open files */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fileops
name|vnops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fileops
name|badfileops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fileops
name|socketops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxfiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel limit on number of open files */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxfilesperproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* per process limit on number of open files */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|openfiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* (fl) actual number of open files */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|filelist_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sx to protect filelist and openfiles */
end_comment

begin_function_decl
name|int
name|fget
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|fd
parameter_list|,
name|struct
name|file
modifier|*
modifier|*
name|fpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fget_read
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|fd
parameter_list|,
name|struct
name|file
modifier|*
modifier|*
name|fpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fget_write
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|fd
parameter_list|,
name|struct
name|file
modifier|*
modifier|*
name|fpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdrop
parameter_list|(
name|struct
name|file
modifier|*
name|fp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The socket operations are used a couple of places.  * XXX: This is wrong, they should go through the operations vector for  * XXX: sockets instead of going directly for the individual functions. /phk  */
end_comment

begin_decl_stmt
name|fo_rdwr_t
name|soo_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fo_rdwr_t
name|soo_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fo_ioctl_t
name|soo_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fo_poll_t
name|soo_poll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fo_kqfilter_t
name|soo_kqfilter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fo_stat_t
name|soo_stat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|fo_close_t
name|soo_close
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lock a file. */
end_comment

begin_define
define|#
directive|define
name|FILE_LOCK
parameter_list|(
name|f
parameter_list|)
value|mtx_lock((f)->f_mtxp)
end_define

begin_define
define|#
directive|define
name|FILE_UNLOCK
parameter_list|(
name|f
parameter_list|)
value|mtx_unlock((f)->f_mtxp)
end_define

begin_define
define|#
directive|define
name|FILE_LOCKED
parameter_list|(
name|f
parameter_list|)
value|mtx_owned((f)->f_mtxp)
end_define

begin_define
define|#
directive|define
name|FILE_LOCK_ASSERT
parameter_list|(
name|f
parameter_list|,
name|type
parameter_list|)
value|mtx_assert((f)->f_mtxp, (type))
end_define

begin_function_decl
name|int
name|fgetvp
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|fd
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fgetvp_read
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|fd
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fgetvp_write
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|fd
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fgetsock
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|fd
parameter_list|,
name|struct
name|socket
modifier|*
modifier|*
name|spp
parameter_list|,
name|u_int
modifier|*
name|fflagp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fputsock
parameter_list|(
name|struct
name|socket
modifier|*
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|fhold_locked
parameter_list|(
name|fp
parameter_list|)
define|\
value|do {								\ 		FILE_LOCK_ASSERT(fp, MA_OWNED);				\ 		(fp)->f_count++;					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|fhold
parameter_list|(
name|fp
parameter_list|)
define|\
value|do {								\ 		FILE_LOCK(fp);						\ 		(fp)->f_count++;					\ 		FILE_UNLOCK(fp);					\ 	} while (0)
end_define

begin_decl_stmt
specifier|static
name|__inline
name|fo_rdwr_t
name|fo_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|fo_rdwr_t
name|fo_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|fo_ioctl_t
name|fo_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|fo_poll_t
name|fo_poll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|fo_kqfilter_t
name|fo_kqfilter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|fo_stat_t
name|fo_stat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|fo_close_t
name|fo_close
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|int
name|fo_read
parameter_list|(
name|fp
parameter_list|,
name|uio
parameter_list|,
name|active_cred
parameter_list|,
name|flags
parameter_list|,
name|td
parameter_list|)
name|struct
name|file
modifier|*
name|fp
decl_stmt|;
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
name|struct
name|ucred
modifier|*
name|active_cred
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
block|{
return|return
operator|(
call|(
modifier|*
name|fp
operator|->
name|f_ops
operator|->
name|fo_read
call|)
argument_list|(
name|fp
argument_list|,
name|uio
argument_list|,
name|active_cred
argument_list|,
name|flags
argument_list|,
name|td
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|fo_write
parameter_list|(
name|fp
parameter_list|,
name|uio
parameter_list|,
name|active_cred
parameter_list|,
name|flags
parameter_list|,
name|td
parameter_list|)
name|struct
name|file
modifier|*
name|fp
decl_stmt|;
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
name|struct
name|ucred
modifier|*
name|active_cred
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
block|{
return|return
operator|(
call|(
modifier|*
name|fp
operator|->
name|f_ops
operator|->
name|fo_write
call|)
argument_list|(
name|fp
argument_list|,
name|uio
argument_list|,
name|active_cred
argument_list|,
name|flags
argument_list|,
name|td
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|fo_ioctl
parameter_list|(
name|fp
parameter_list|,
name|com
parameter_list|,
name|data
parameter_list|,
name|active_cred
parameter_list|,
name|td
parameter_list|)
name|struct
name|file
modifier|*
name|fp
decl_stmt|;
name|u_long
name|com
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|struct
name|ucred
modifier|*
name|active_cred
decl_stmt|;
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
block|{
return|return
operator|(
call|(
modifier|*
name|fp
operator|->
name|f_ops
operator|->
name|fo_ioctl
call|)
argument_list|(
name|fp
argument_list|,
name|com
argument_list|,
name|data
argument_list|,
name|active_cred
argument_list|,
name|td
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|fo_poll
parameter_list|(
name|fp
parameter_list|,
name|events
parameter_list|,
name|active_cred
parameter_list|,
name|td
parameter_list|)
name|struct
name|file
modifier|*
name|fp
decl_stmt|;
name|int
name|events
decl_stmt|;
name|struct
name|ucred
modifier|*
name|active_cred
decl_stmt|;
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
block|{
return|return
operator|(
call|(
modifier|*
name|fp
operator|->
name|f_ops
operator|->
name|fo_poll
call|)
argument_list|(
name|fp
argument_list|,
name|events
argument_list|,
name|active_cred
argument_list|,
name|td
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|fo_stat
parameter_list|(
name|fp
parameter_list|,
name|sb
parameter_list|,
name|active_cred
parameter_list|,
name|td
parameter_list|)
name|struct
name|file
modifier|*
name|fp
decl_stmt|;
name|struct
name|stat
modifier|*
name|sb
decl_stmt|;
name|struct
name|ucred
modifier|*
name|active_cred
decl_stmt|;
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
block|{
return|return
operator|(
call|(
modifier|*
name|fp
operator|->
name|f_ops
operator|->
name|fo_stat
call|)
argument_list|(
name|fp
argument_list|,
name|sb
argument_list|,
name|active_cred
argument_list|,
name|td
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|fo_close
parameter_list|(
name|fp
parameter_list|,
name|td
parameter_list|)
name|struct
name|file
modifier|*
name|fp
decl_stmt|;
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
block|{
return|return
operator|(
call|(
modifier|*
name|fp
operator|->
name|f_ops
operator|->
name|fo_close
call|)
argument_list|(
name|fp
argument_list|,
name|td
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|fo_kqfilter
parameter_list|(
name|fp
parameter_list|,
name|kn
parameter_list|)
name|struct
name|file
modifier|*
name|fp
decl_stmt|;
name|struct
name|knote
modifier|*
name|kn
decl_stmt|;
block|{
return|return
operator|(
call|(
modifier|*
name|fp
operator|->
name|f_ops
operator|->
name|fo_kqfilter
call|)
argument_list|(
name|fp
argument_list|,
name|kn
argument_list|)
operator|)
return|;
block|}
end_function

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
comment|/* !SYS_FILE_H */
end_comment

end_unit

