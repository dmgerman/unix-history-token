begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fifo.h	8.2 (Berkeley) 2/2/94  * $FreeBSD$  */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
modifier|*
name|fifo_vnodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Prototypes for fifo operations on vnodes.  */
end_comment

begin_decl_stmt
name|int
name|fifo_badop
argument_list|()
decl_stmt|,
name|fifo_ebadf
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fifo_printinfo
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fifo_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lookup_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fifo_create
value|((int (*) __P((struct  vop_create_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_mknod
value|((int (*) __P((struct  vop_mknod_args *)))fifo_badop)
end_define

begin_decl_stmt
name|int
name|fifo_open
name|__P
argument_list|(
operator|(
expr|struct
name|vop_open_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fifo_close
name|__P
argument_list|(
operator|(
expr|struct
name|vop_close_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fifo_access
value|((int (*) __P((struct  vop_access_args *)))fifo_ebadf)
end_define

begin_define
define|#
directive|define
name|fifo_getattr
value|((int (*) __P((struct  vop_getattr_args *)))fifo_ebadf)
end_define

begin_define
define|#
directive|define
name|fifo_setattr
value|((int (*) __P((struct  vop_setattr_args *)))fifo_ebadf)
end_define

begin_decl_stmt
name|int
name|fifo_read
name|__P
argument_list|(
operator|(
expr|struct
name|vop_read_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fifo_write
name|__P
argument_list|(
operator|(
expr|struct
name|vop_write_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fifo_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|vop_ioctl_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fifo_select
name|__P
argument_list|(
operator|(
expr|struct
name|vop_select_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fifo_mmap
value|((int (*) __P((struct  vop_mmap_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_fsync
value|((int (*) __P((struct  vop_fsync_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|fifo_seek
value|((int (*) __P((struct  vop_seek_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_remove
value|((int (*) __P((struct  vop_remove_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_link
value|((int (*) __P((struct  vop_link_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_rename
value|((int (*) __P((struct  vop_rename_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_mkdir
value|((int (*) __P((struct  vop_mkdir_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_rmdir
value|((int (*) __P((struct  vop_rmdir_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_symlink
value|((int (*) __P((struct  vop_symlink_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_readdir
value|((int (*) __P((struct  vop_readdir_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_readlink
value|((int (*) __P((struct  vop_readlink_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_abortop
value|((int (*) __P((struct  vop_abortop_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_inactive
value|((int (*) __P((struct  vop_inactive_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|fifo_reclaim
value|((int (*) __P((struct  vop_reclaim_args *)))nullop)
end_define

begin_decl_stmt
name|int
name|fifo_lock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fifo_unlock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_unlock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fifo_bmap
name|__P
argument_list|(
operator|(
expr|struct
name|vop_bmap_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fifo_strategy
value|((int (*) __P((struct  vop_strategy_args *)))fifo_badop)
end_define

begin_decl_stmt
name|int
name|fifo_print
name|__P
argument_list|(
operator|(
expr|struct
name|vop_print_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fifo_islocked
value|((int (*) __P((struct  vop_islocked_args *)))nullop)
end_define

begin_decl_stmt
name|int
name|fifo_pathconf
name|__P
argument_list|(
operator|(
expr|struct
name|vop_pathconf_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fifo_advlock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_advlock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fifo_blkatoff
value|((int (*) __P((struct  vop_blkatoff_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_valloc
value|((int (*) __P((struct  vop_valloc_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_reallocblks
define|\
value|((int (*) __P((struct  vop_reallocblks_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_vfree
value|((int (*) __P((struct  vop_vfree_args *)))fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_truncate
value|((int (*) __P((struct  vop_truncate_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|fifo_update
value|((int (*) __P((struct  vop_update_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|fifo_bwrite
value|((int (*) __P((struct  vop_bwrite_args *)))nullop)
end_define

end_unit

