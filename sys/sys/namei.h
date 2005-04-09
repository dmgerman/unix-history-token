begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985, 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)namei.h	8.5 (Berkeley) 1/9/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_NAMEI_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_NAMEI_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_struct
struct|struct
name|componentname
block|{
comment|/* 	 * Arguments to lookup. 	 */
name|u_long
name|cn_nameiop
decl_stmt|;
comment|/* namei operation */
name|u_long
name|cn_flags
decl_stmt|;
comment|/* flags to namei */
name|struct
name|thread
modifier|*
name|cn_thread
decl_stmt|;
comment|/* thread requesting lookup */
name|struct
name|ucred
modifier|*
name|cn_cred
decl_stmt|;
comment|/* credentials */
name|int
name|cn_lkflags
decl_stmt|;
comment|/* Lock flags LK_EXCLUSIVE or LK_SHARED */
comment|/* 	 * Shared between lookup and commit routines. 	 */
name|char
modifier|*
name|cn_pnbuf
decl_stmt|;
comment|/* pathname buffer */
name|char
modifier|*
name|cn_nameptr
decl_stmt|;
comment|/* pointer to looked up name */
name|long
name|cn_namelen
decl_stmt|;
comment|/* length of looked up component */
name|long
name|cn_consume
decl_stmt|;
comment|/* chars to consume in lookup() */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Encapsulation of namei parameters.  */
end_comment

begin_struct
struct|struct
name|nameidata
block|{
comment|/* 	 * Arguments to namei/lookup. 	 */
specifier|const
name|char
modifier|*
name|ni_dirp
decl_stmt|;
comment|/* pathname pointer */
name|enum
name|uio_seg
name|ni_segflg
decl_stmt|;
comment|/* location of pathname */
comment|/* 	 * Arguments to lookup. 	 */
name|struct
name|vnode
modifier|*
name|ni_startdir
decl_stmt|;
comment|/* starting directory */
name|struct
name|vnode
modifier|*
name|ni_rootdir
decl_stmt|;
comment|/* logical root directory */
name|struct
name|vnode
modifier|*
name|ni_topdir
decl_stmt|;
comment|/* logical top directory */
comment|/* 	 * Results: returned from/manipulated by lookup 	 */
name|struct
name|vnode
modifier|*
name|ni_vp
decl_stmt|;
comment|/* vnode of result */
name|struct
name|vnode
modifier|*
name|ni_dvp
decl_stmt|;
comment|/* vnode of intermediate directory */
comment|/* 	 * Shared between namei and lookup/commit routines. 	 */
name|size_t
name|ni_pathlen
decl_stmt|;
comment|/* remaining chars in path */
name|char
modifier|*
name|ni_next
decl_stmt|;
comment|/* next location in pathname */
name|u_long
name|ni_loopcnt
decl_stmt|;
comment|/* count of symlinks encountered */
comment|/* 	 * Lookup parameters: this structure describes the subset of 	 * information from the nameidata structure that is passed 	 * through the VOP interface. 	 */
name|struct
name|componentname
name|ni_cnd
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * namei operations  */
end_comment

begin_define
define|#
directive|define
name|LOOKUP
value|0
end_define

begin_comment
comment|/* perform name lookup only */
end_comment

begin_define
define|#
directive|define
name|CREATE
value|1
end_define

begin_comment
comment|/* setup for file creation */
end_comment

begin_define
define|#
directive|define
name|DELETE
value|2
end_define

begin_comment
comment|/* setup for file deletion */
end_comment

begin_define
define|#
directive|define
name|RENAME
value|3
end_define

begin_comment
comment|/* setup for file renaming */
end_comment

begin_define
define|#
directive|define
name|OPMASK
value|3
end_define

begin_comment
comment|/* mask for operation */
end_comment

begin_comment
comment|/*  * namei operational modifier flags, stored in ni_cnd.flags  */
end_comment

begin_define
define|#
directive|define
name|LOCKLEAF
value|0x0004
end_define

begin_comment
comment|/* lock inode on return */
end_comment

begin_define
define|#
directive|define
name|LOCKPARENT
value|0x0008
end_define

begin_comment
comment|/* want parent vnode returned locked */
end_comment

begin_define
define|#
directive|define
name|WANTPARENT
value|0x0010
end_define

begin_comment
comment|/* want parent vnode returned unlocked */
end_comment

begin_define
define|#
directive|define
name|NOCACHE
value|0x0020
end_define

begin_comment
comment|/* name must not be left in cache */
end_comment

begin_define
define|#
directive|define
name|FOLLOW
value|0x0040
end_define

begin_comment
comment|/* follow symbolic links */
end_comment

begin_define
define|#
directive|define
name|LOCKSHARED
value|0x0100
end_define

begin_comment
comment|/* Shared lock leaf */
end_comment

begin_define
define|#
directive|define
name|NOFOLLOW
value|0x0000
end_define

begin_comment
comment|/* do not follow symbolic links (pseudo) */
end_comment

begin_define
define|#
directive|define
name|MODMASK
value|0x01fc
end_define

begin_comment
comment|/* mask of operational modifiers */
end_comment

begin_comment
comment|/*  * Namei parameter descriptors.  *  * SAVENAME may be set by either the callers of namei or by VOP_LOOKUP.  * If the caller of namei sets the flag (for example execve wants to  * know the name of the program that is being executed), then it must  * free the buffer. If VOP_LOOKUP sets the flag, then the buffer must  * be freed by either the commit routine or the VOP_ABORT routine.  * SAVESTART is set only by the callers of namei. It implies SAVENAME  * plus the addition of saving the parent directory that contains the  * name in ni_startdir. It allows repeated calls to lookup for the  * name being sought. The caller is responsible for releasing the  * buffer and for vrele'ing ni_startdir.  */
end_comment

begin_define
define|#
directive|define
name|RDONLY
value|0x0000200
end_define

begin_comment
comment|/* lookup with read-only semantics */
end_comment

begin_define
define|#
directive|define
name|HASBUF
value|0x0000400
end_define

begin_comment
comment|/* has allocated pathname buffer */
end_comment

begin_define
define|#
directive|define
name|SAVENAME
value|0x0000800
end_define

begin_comment
comment|/* save pathname buffer */
end_comment

begin_define
define|#
directive|define
name|SAVESTART
value|0x0001000
end_define

begin_comment
comment|/* save starting directory */
end_comment

begin_define
define|#
directive|define
name|ISDOTDOT
value|0x0002000
end_define

begin_comment
comment|/* current component name is .. */
end_comment

begin_define
define|#
directive|define
name|MAKEENTRY
value|0x0004000
end_define

begin_comment
comment|/* entry is to be added to name cache */
end_comment

begin_define
define|#
directive|define
name|ISLASTCN
value|0x0008000
end_define

begin_comment
comment|/* this is last component of pathname */
end_comment

begin_define
define|#
directive|define
name|ISSYMLINK
value|0x0010000
end_define

begin_comment
comment|/* symlink needs interpretation */
end_comment

begin_define
define|#
directive|define
name|ISWHITEOUT
value|0x0020000
end_define

begin_comment
comment|/* found whiteout */
end_comment

begin_define
define|#
directive|define
name|DOWHITEOUT
value|0x0040000
end_define

begin_comment
comment|/* do whiteouts */
end_comment

begin_define
define|#
directive|define
name|WILLBEDIR
value|0x0080000
end_define

begin_comment
comment|/* new files will be dirs; allow trailing / */
end_comment

begin_define
define|#
directive|define
name|ISUNICODE
value|0x0100000
end_define

begin_comment
comment|/* current component name is unicode*/
end_comment

begin_define
define|#
directive|define
name|NOCROSSMOUNT
value|0x0400000
end_define

begin_comment
comment|/* do not cross mount points */
end_comment

begin_define
define|#
directive|define
name|NOMACCHECK
value|0x0800000
end_define

begin_comment
comment|/* do not perform MAC checks */
end_comment

begin_define
define|#
directive|define
name|MPSAFE
value|0x1000000
end_define

begin_comment
comment|/* namei() must acquire Giant if needed. */
end_comment

begin_define
define|#
directive|define
name|GIANTHELD
value|0x2000000
end_define

begin_comment
comment|/* namei() is holding giant. */
end_comment

begin_define
define|#
directive|define
name|PARAMASK
value|0x3fffe00
end_define

begin_comment
comment|/* mask of parameter descriptors */
end_comment

begin_define
define|#
directive|define
name|NDHASGIANT
parameter_list|(
name|NDP
parameter_list|)
value|(((NDP)->ni_cnd.cn_flags& GIANTHELD) != 0)
end_define

begin_comment
comment|/*  * Initialization of a nameidata structure.  */
end_comment

begin_function_decl
specifier|static
name|void
name|NDINIT
parameter_list|(
name|struct
name|nameidata
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|enum
name|uio_seg
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|NDINIT
parameter_list|(
name|struct
name|nameidata
modifier|*
name|ndp
parameter_list|,
name|u_long
name|op
parameter_list|,
name|u_long
name|flags
parameter_list|,
name|enum
name|uio_seg
name|segflg
parameter_list|,
specifier|const
name|char
modifier|*
name|namep
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
name|ndp
operator|->
name|ni_cnd
operator|.
name|cn_nameiop
operator|=
name|op
expr_stmt|;
name|ndp
operator|->
name|ni_cnd
operator|.
name|cn_flags
operator|=
name|flags
expr_stmt|;
name|ndp
operator|->
name|ni_segflg
operator|=
name|segflg
expr_stmt|;
name|ndp
operator|->
name|ni_dirp
operator|=
name|namep
expr_stmt|;
name|ndp
operator|->
name|ni_cnd
operator|.
name|cn_thread
operator|=
name|td
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|NDF_NO_DVP_RELE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDF_NO_DVP_UNLOCK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDF_NO_DVP_PUT
value|0x00000003
end_define

begin_define
define|#
directive|define
name|NDF_NO_VP_RELE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDF_NO_VP_UNLOCK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NDF_NO_VP_PUT
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|NDF_NO_STARTDIR_RELE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NDF_NO_FREE_PNBUF
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NDF_ONLY_PNBUF
value|(~NDF_NO_FREE_PNBUF)
end_define

begin_function_decl
name|void
name|NDFREE
parameter_list|(
name|struct
name|nameidata
modifier|*
parameter_list|,
specifier|const
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|namei
parameter_list|(
name|struct
name|nameidata
modifier|*
name|ndp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lookup
parameter_list|(
name|struct
name|nameidata
modifier|*
name|ndp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|relookup
parameter_list|(
name|struct
name|vnode
modifier|*
name|dvp
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|,
name|struct
name|componentname
modifier|*
name|cnp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Stats on usefulness of namei caches.  */
end_comment

begin_struct
struct|struct
name|nchstats
block|{
name|long
name|ncs_goodhits
decl_stmt|;
comment|/* hits that we can really use */
name|long
name|ncs_neghits
decl_stmt|;
comment|/* negative hits that we can use */
name|long
name|ncs_badhits
decl_stmt|;
comment|/* hits we must drop */
name|long
name|ncs_falsehits
decl_stmt|;
comment|/* hits with id mismatch */
name|long
name|ncs_miss
decl_stmt|;
comment|/* misses */
name|long
name|ncs_long
decl_stmt|;
comment|/* long names that ignore cache */
name|long
name|ncs_pass2
decl_stmt|;
comment|/* names found with passes == 2 */
name|long
name|ncs_2passes
decl_stmt|;
comment|/* number of times we attempt it */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|nchstats
name|nchstats
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_NAMEI_H_ */
end_comment

end_unit

