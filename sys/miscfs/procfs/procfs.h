begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Jan-Simon Pendry  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)procfs.h	8.9 (Berkeley) 5/14/95  *  * From:  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * The different types of node in a procfs filesystem  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Proot
block|,
comment|/* the filesystem root */
name|Pcurproc
block|,
comment|/* symbolic link for curproc */
name|Pproc
block|,
comment|/* a process-specific sub-directory */
name|Pfile
block|,
comment|/* the executable file */
name|Pmem
block|,
comment|/* the process's memory image */
name|Pregs
block|,
comment|/* the process's register set */
name|Pfpregs
block|,
comment|/* the process's FP register set */
name|Pdbregs
block|,
comment|/* the process's debug register set */
name|Pctl
block|,
comment|/* process control */
name|Pstatus
block|,
comment|/* process status */
name|Pnote
block|,
comment|/* process notifier */
name|Pnotepg
block|,
comment|/* process group notifier */
name|Pmap
block|,
comment|/* memory map */
name|Ptype
block|,
comment|/* executable type */
name|Pcmdline
block|,
comment|/* command line */
name|Prlimit
comment|/* resource limits */
block|}
name|pfstype
typedef|;
end_typedef

begin_comment
comment|/*  * control data for the proc file system.  */
end_comment

begin_struct
struct|struct
name|pfsnode
block|{
name|struct
name|pfsnode
modifier|*
name|pfs_next
decl_stmt|;
comment|/* next on list */
name|struct
name|vnode
modifier|*
name|pfs_vnode
decl_stmt|;
comment|/* vnode associated with this pfsnode */
name|pfstype
name|pfs_type
decl_stmt|;
comment|/* type of procfs node */
name|pid_t
name|pfs_pid
decl_stmt|;
comment|/* associated process */
name|u_short
name|pfs_mode
decl_stmt|;
comment|/* mode bits for stat() */
name|u_long
name|pfs_flags
decl_stmt|;
comment|/* open flags */
name|u_long
name|pfs_fileno
decl_stmt|;
comment|/* unique file id */
name|pid_t
name|pfs_lockowner
decl_stmt|;
comment|/* pfs lock owner */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PROCFS_NOTELEN
value|64
end_define

begin_comment
comment|/* max length of a note (/proc/$pid/note) */
end_comment

begin_define
define|#
directive|define
name|PROCFS_CTLLEN
value|8
end_define

begin_comment
comment|/* max length of a ctl msg (/proc/$pid/ctl */
end_comment

begin_define
define|#
directive|define
name|PROCFS_NAMELEN
value|8
end_define

begin_comment
comment|/* max length of a filename component */
end_comment

begin_comment
comment|/*  * Kernel stuff follows  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|CNEQ
parameter_list|(
name|cnp
parameter_list|,
name|s
parameter_list|,
name|len
parameter_list|)
define|\
value|((cnp)->cn_namelen == (len)&& \ 	  (bcmp((s), (cnp)->cn_nameptr, (len)) == 0))
end_define

begin_define
define|#
directive|define
name|PROCFS_FILENO
parameter_list|(
name|pid
parameter_list|,
name|type
parameter_list|)
define|\
value|(((type)< Pproc) ? \ 			((type) + 2) : \ 			((((pid)+1)<< 4) + ((int) (type))))
end_define

begin_define
define|#
directive|define
name|CHECKIO
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|((((p1)->p_cred->pc_ucred->cr_uid == (p2)->p_cred->p_ruid)&& \        ((p1)->p_cred->p_ruid == (p2)->p_cred->p_ruid)&& \        ((p1)->p_cred->p_svuid == (p2)->p_cred->p_ruid)&& \        ((p2)->p_flag& P_SUGID) == 0) || \       (suser_xxx((p1)->p_cred->pc_ucred, (p1), PRISON_ROOT) == 0))
end_define

begin_comment
comment|/*  * Convert between pfsnode vnode  */
end_comment

begin_define
define|#
directive|define
name|VTOPFS
parameter_list|(
name|vp
parameter_list|)
value|((struct pfsnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|PFSTOV
parameter_list|(
name|pfs
parameter_list|)
value|((pfs)->pfs_vnode)
end_define

begin_typedef
typedef|typedef
name|struct
name|vfs_namemap
name|vfs_namemap_t
typedef|;
end_typedef

begin_struct
struct|struct
name|vfs_namemap
block|{
specifier|const
name|char
modifier|*
name|nm_name
decl_stmt|;
name|int
name|nm_val
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|vfs_getuserstr
name|__P
argument_list|(
operator|(
expr|struct
name|uio
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_namemap_t
modifier|*
name|vfs_findname
name|__P
argument_list|(
operator|(
name|vfs_namemap_t
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*<machine/reg.h> */
end_comment

begin_struct_decl
struct_decl|struct
name|reg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fpreg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|dbreg
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|PFIND
parameter_list|(
name|pid
parameter_list|)
value|((pid) ? pfind(pid) :&proc0)
end_define

begin_decl_stmt
name|void
name|procfs_exit
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_freevp
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
name|procfs_allocvp
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
expr|struct
name|vnode
operator|*
operator|*
operator|,
name|long
operator|,
name|pfstype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|procfs_findtextvp
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_sstep
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|procfs_fix_sstep
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_read_regs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|reg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_write_regs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|reg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_read_fpregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|fpreg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_write_fpregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|fpreg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_read_dbregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|dbreg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_write_dbregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|dbreg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_donote
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_doregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_dofpregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_dodbregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_domem
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_doctl
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_dostatus
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_domap
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_dotype
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_docmdline
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_dorlimit
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* functions to check whether or not files should be displayed */
end_comment

begin_decl_stmt
name|int
name|procfs_validfile
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_validfpregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_validregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_validdbregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_validmap
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_validtype
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PROCFS_LOCKED
value|0x01
end_define

begin_define
define|#
directive|define
name|PROCFS_WANT
value|0x02
end_define

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|procfs_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_root
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
expr|struct
name|vnode
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_rw
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

