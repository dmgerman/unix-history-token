begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 The Regents of the University of California.  * Copyright (c) 1994 Jan-Simon Pendry.  * All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)union.h	8.9 (Berkeley) 12/10/94  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|union_args
block|{
name|char
modifier|*
name|target
decl_stmt|;
comment|/* Target of loopback  */
name|int
name|mntflags
decl_stmt|;
comment|/* Options on the mount */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNMNT_ABOVE
value|0x0001
end_define

begin_comment
comment|/* Target appears above mount point */
end_comment

begin_define
define|#
directive|define
name|UNMNT_BELOW
value|0x0002
end_define

begin_comment
comment|/* Target appears below mount point */
end_comment

begin_define
define|#
directive|define
name|UNMNT_REPLACE
value|0x0003
end_define

begin_comment
comment|/* Target replaces mount point */
end_comment

begin_define
define|#
directive|define
name|UNMNT_OPMASK
value|0x0003
end_define

begin_struct
struct|struct
name|union_mount
block|{
name|struct
name|vnode
modifier|*
name|um_uppervp
decl_stmt|;
comment|/* UN_ULOCK holds locking state */
name|struct
name|vnode
modifier|*
name|um_lowervp
decl_stmt|;
comment|/* Left unlocked */
name|struct
name|ucred
modifier|*
name|um_cred
decl_stmt|;
comment|/* Credentials of user calling mount */
name|int
name|um_cmode
decl_stmt|;
comment|/* cmask from mount process */
name|int
name|um_op
decl_stmt|;
comment|/* Operation mode */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DIAGNOSTIC
end_ifndef

begin_define
define|#
directive|define
name|DIAGNOSTIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * DEFDIRMODE is the mode bits used to create a shadow directory.  */
end_comment

begin_define
define|#
directive|define
name|VRWXMODE
value|(VREAD|VWRITE|VEXEC)
end_define

begin_define
define|#
directive|define
name|VRWMODE
value|(VREAD|VWRITE)
end_define

begin_define
define|#
directive|define
name|UN_DIRMODE
value|((VRWXMODE)|(VRWXMODE>>3)|(VRWXMODE>>6))
end_define

begin_define
define|#
directive|define
name|UN_FILEMODE
value|((VRWMODE)|(VRWMODE>>3)|(VRWMODE>>6))
end_define

begin_comment
comment|/*  * A cache of vnode references	(hangs off v_data)  *  * Placing un_lock as the first elements theoretically allows us to  * use the vop_stdlock functions.  However, we need to make sure of  * certain side effects so we will still punch in our own code.  */
end_comment

begin_struct
struct|struct
name|union_node
block|{
name|struct
name|lock
name|un_lock
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|union_node
argument_list|)
name|un_cache
expr_stmt|;
comment|/* Hash chain */
name|struct
name|vnode
modifier|*
name|un_vnode
decl_stmt|;
comment|/* Back pointer */
name|struct
name|vnode
modifier|*
name|un_uppervp
decl_stmt|;
comment|/* overlaying object */
name|struct
name|vnode
modifier|*
name|un_lowervp
decl_stmt|;
comment|/* underlying object */
name|struct
name|vnode
modifier|*
name|un_dirvp
decl_stmt|;
comment|/* Parent dir of uppervp */
name|struct
name|vnode
modifier|*
name|un_pvp
decl_stmt|;
comment|/* Parent vnode */
name|char
modifier|*
name|un_path
decl_stmt|;
comment|/* saved component name */
name|int
name|un_openl
decl_stmt|;
comment|/* # of opens on lowervp */
name|int
name|un_exclcnt
decl_stmt|;
comment|/* exclusive count */
name|unsigned
name|int
name|un_flags
decl_stmt|;
name|struct
name|vnode
modifier|*
modifier|*
name|un_dircache
decl_stmt|;
comment|/* cached union stack */
name|off_t
name|un_uppersz
decl_stmt|;
comment|/* size of upper object */
name|off_t
name|un_lowersz
decl_stmt|;
comment|/* size of lower object */
ifdef|#
directive|ifdef
name|DIAGNOSTIC
name|pid_t
name|un_pid
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * XXX UN_ULOCK -	indicates that the uppervp is locked  *  * UN_CACHED -	node is in the union cache  */
end_comment

begin_comment
comment|/*#define UN_ULOCK	0x04*/
end_comment

begin_comment
comment|/* Upper node is locked */
end_comment

begin_define
define|#
directive|define
name|UN_CACHED
value|0x10
end_define

begin_comment
comment|/* In union cache */
end_comment

begin_comment
comment|/*  * Hash table locking flags  */
end_comment

begin_define
define|#
directive|define
name|UNVP_WANT
value|0x01
end_define

begin_define
define|#
directive|define
name|UNVP_LOCKED
value|0x02
end_define

begin_function_decl
specifier|extern
name|int
name|union_allocvp
parameter_list|(
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|,
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|componentname
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|union_freevp
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|vnode
modifier|*
name|union_dircache
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|union_copyup
parameter_list|(
name|struct
name|union_node
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|union_dowhiteout
parameter_list|(
name|struct
name|union_node
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|union_mkshadow
parameter_list|(
name|struct
name|union_mount
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|componentname
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|union_mkwhiteout
parameter_list|(
name|struct
name|union_mount
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|componentname
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|union_cn_close
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|union_removed_upper
parameter_list|(
name|struct
name|union_node
modifier|*
name|un
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|vnode
modifier|*
name|union_lowervp
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|union_newsize
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|union_dircheckp
function_decl|)
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|,
name|struct
name|file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MOUNTTOUNIONMOUNT
parameter_list|(
name|mp
parameter_list|)
value|((struct union_mount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTOUNION
parameter_list|(
name|vp
parameter_list|)
value|((struct union_node *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|UNIONTOV
parameter_list|(
name|un
parameter_list|)
value|((un)->un_vnode)
end_define

begin_define
define|#
directive|define
name|LOWERVP
parameter_list|(
name|vp
parameter_list|)
value|(VTOUNION(vp)->un_lowervp)
end_define

begin_define
define|#
directive|define
name|UPPERVP
parameter_list|(
name|vp
parameter_list|)
value|(VTOUNION(vp)->un_uppervp)
end_define

begin_define
define|#
directive|define
name|OTHERVP
parameter_list|(
name|vp
parameter_list|)
value|(UPPERVP(vp) ? UPPERVP(vp) : LOWERVP(vp))
end_define

begin_define
define|#
directive|define
name|UDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (uniondebug) printf x
end_define

begin_define
define|#
directive|define
name|UDEBUG_ENABLED
value|1
end_define

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|union_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|union_vfsops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|uniondebug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

