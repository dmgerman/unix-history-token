begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)specdev.h	8.2 (Berkeley) 2/2/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This structure defines the information maintained about  * special devices. It is allocated in checkalias and freed  * in vgone.  */
end_comment

begin_struct
struct|struct
name|specinfo
block|{
name|struct
name|vnode
modifier|*
modifier|*
name|si_hashchain
decl_stmt|;
name|struct
name|vnode
modifier|*
name|si_specnext
decl_stmt|;
name|long
name|si_flags
decl_stmt|;
name|dev_t
name|si_rdev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Exported shorthand  */
end_comment

begin_define
define|#
directive|define
name|v_rdev
value|v_specinfo->si_rdev
end_define

begin_define
define|#
directive|define
name|v_hashchain
value|v_specinfo->si_hashchain
end_define

begin_define
define|#
directive|define
name|v_specnext
value|v_specinfo->si_specnext
end_define

begin_define
define|#
directive|define
name|v_specflags
value|v_specinfo->si_flags
end_define

begin_comment
comment|/*  * Flags for specinfo  */
end_comment

begin_define
define|#
directive|define
name|SI_MOUNTEDON
value|0x0001
end_define

begin_comment
comment|/* block special device is mounted on */
end_comment

begin_comment
comment|/*  * Special device management  */
end_comment

begin_define
define|#
directive|define
name|SPECHSZ
value|64
end_define

begin_if
if|#
directive|if
operator|(
operator|(
name|SPECHSZ
operator|&
operator|(
name|SPECHSZ
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|SPECHASH
parameter_list|(
name|rdev
parameter_list|)
value|(((rdev>>5)+(rdev))&(SPECHSZ-1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SPECHASH
parameter_list|(
name|rdev
parameter_list|)
value|(((unsigned)((rdev>>5)+(rdev)))%SPECHSZ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|vnode
modifier|*
name|speclisth
index|[
name|SPECHSZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Prototypes for special file operations on vnodes.  */
end_comment

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|spec_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|nameidata
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|componentname
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|flock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|spec_badop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spec_lookup
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
name|spec_create
value|((int (*) __P((struct  vop_create_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_mknod
value|((int (*) __P((struct  vop_mknod_args *)))spec_badop)
end_define

begin_decl_stmt
name|int
name|spec_open
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
name|spec_close
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
name|spec_access
value|((int (*) __P((struct  vop_access_args *)))spec_ebadf)
end_define

begin_define
define|#
directive|define
name|spec_setattr
value|((int (*) __P((struct  vop_setattr_args *)))spec_ebadf)
end_define

begin_decl_stmt
name|int
name|spec_read
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
name|spec_write
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
name|spec_ioctl
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
name|spec_select
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
name|spec_mmap
value|((int (*) __P((struct  vop_mmap_args *)))spec_badop)
end_define

begin_decl_stmt
name|int
name|spec_fsync
name|__P
argument_list|(
operator|(
expr|struct
name|vop_fsync_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|spec_seek
value|((int (*) __P((struct  vop_seek_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_remove
value|((int (*) __P((struct  vop_remove_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_link
value|((int (*) __P((struct  vop_link_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_rename
value|((int (*) __P((struct  vop_rename_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_mkdir
value|((int (*) __P((struct  vop_mkdir_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_rmdir
value|((int (*) __P((struct  vop_rmdir_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_symlink
value|((int (*) __P((struct  vop_symlink_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_readdir
value|((int (*) __P((struct  vop_readdir_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_readlink
value|((int (*) __P((struct  vop_readlink_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_abortop
value|((int (*) __P((struct  vop_abortop_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_inactive
value|((int (*) __P((struct  vop_inactive_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|spec_reclaim
value|((int (*) __P((struct  vop_reclaim_args *)))nullop)
end_define

begin_decl_stmt
name|int
name|spec_lock
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
name|spec_unlock
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
name|spec_bmap
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

begin_decl_stmt
name|int
name|spec_strategy
name|__P
argument_list|(
operator|(
expr|struct
name|vop_strategy_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spec_print
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
name|spec_islocked
value|((int (*) __P((struct  vop_islocked_args *)))nullop)
end_define

begin_decl_stmt
name|int
name|spec_pathconf
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
name|spec_advlock
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

begin_decl_stmt
name|int
name|spec_getpages
name|__P
argument_list|(
operator|(
expr|struct
name|vop_getpages_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|spec_blkatoff
value|((int (*) __P((struct  vop_blkatoff_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_valloc
value|((int (*) __P((struct  vop_valloc_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_reallocblks
define|\
value|((int (*) __P((struct  vop_reallocblks_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_vfree
value|((int (*) __P((struct  vop_vfree_args *)))spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_truncate
value|((int (*) __P((struct  vop_truncate_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|spec_update
value|((int (*) __P((struct  vop_update_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|spec_bwrite
value|((int (*) __P((struct  vop_bwrite_args *)))nullop)
end_define

end_unit

