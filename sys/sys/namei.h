begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1989, 1991 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)namei.h	7.15 (Berkeley) 5/15/91  *	$Id: namei.h,v 1.4 1994/05/22 23:08:06 ache Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NAMEI_H_
end_ifndef

begin_define
define|#
directive|define
name|_NAMEI_H_
end_define

begin_comment
comment|/*  * Encapsulation of namei parameters.  */
end_comment

begin_struct
struct|struct
name|nameidata
block|{
comment|/* 	 * Arguments to namei. 	 */
name|caddr_t
name|ni_dirp
decl_stmt|;
comment|/* pathname pointer */
name|enum
name|uio_seg
name|ni_segflg
decl_stmt|;
comment|/* location of pathname */
name|u_long
name|ni_nameiop
decl_stmt|;
comment|/* see below */
comment|/* 	 * Arguments to lookup. 	 */
name|struct
name|ucred
modifier|*
name|ni_cred
decl_stmt|;
comment|/* credentials */
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
comment|/* 	 * Results 	 */
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
comment|/* 	 * Shared between namei, lookup routines, and commit routines. 	 */
name|char
modifier|*
name|ni_pnbuf
decl_stmt|;
comment|/* pathname buffer */
name|long
name|ni_pathlen
decl_stmt|;
comment|/* remaining chars in path */
name|char
modifier|*
name|ni_ptr
decl_stmt|;
comment|/* current location in pathname */
name|long
name|ni_namelen
decl_stmt|;
comment|/* length of current component */
name|char
modifier|*
name|ni_next
decl_stmt|;
comment|/* next location in pathname */
name|u_long
name|ni_hash
decl_stmt|;
comment|/* hash value of current component */
name|u_char
name|ni_loopcnt
decl_stmt|;
comment|/* count of symlinks encountered */
name|u_char
name|ni_makeentry
decl_stmt|;
comment|/* 1 => add entry to name cache */
name|u_char
name|ni_isdotdot
decl_stmt|;
comment|/* 1 => current component name is .. */
name|u_char
name|ni_more
decl_stmt|;
comment|/* 1 => symlink needs interpretation */
comment|/* 	 * Side effects. 	 */
struct|struct
name|ufs_specific
block|{
comment|/* saved info for new dir entry */
name|off_t
name|ufs_endoff
decl_stmt|;
comment|/* end of useful directory contents */
name|long
name|ufs_offset
decl_stmt|;
comment|/* offset of free space in directory */
name|long
name|ufs_count
decl_stmt|;
comment|/* size of free slot in directory */
name|ino_t
name|ufs_ino
decl_stmt|;
comment|/* inode number of found directory */
name|u_long
name|ufs_reclen
decl_stmt|;
comment|/* size of found directory entry */
block|}
name|ni_ufs
struct|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
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
comment|/*  * namei operational modifiers  */
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
value|0x00fc
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
name|NOCROSSMOUNT
value|0x0100
end_define

begin_comment
comment|/* do not cross mount points */
end_comment

begin_define
define|#
directive|define
name|REMOTE
value|0x0200
end_define

begin_comment
comment|/* lookup for remote filesystem servers */
end_comment

begin_define
define|#
directive|define
name|HASBUF
value|0x0400
end_define

begin_comment
comment|/* has allocated pathname buffer */
end_comment

begin_define
define|#
directive|define
name|SAVENAME
value|0x0800
end_define

begin_comment
comment|/* save pathanme buffer */
end_comment

begin_define
define|#
directive|define
name|SAVESTART
value|0x1000
end_define

begin_comment
comment|/* save starting directory */
end_comment

begin_define
define|#
directive|define
name|PARAMASK
value|0xff00
end_define

begin_comment
comment|/* mask of parameter descriptors */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This structure describes the elements in the cache of recent  * names looked up by namei. NCHNAMLEN is sized to make structure  * size a power of two to optimize malloc's. Minimum reasonable  * size is 15.  */
end_comment

begin_define
define|#
directive|define
name|NCHNAMLEN
value|31
end_define

begin_comment
comment|/* maximum name segment length we bother with */
end_comment

begin_struct
struct|struct
name|namecache
block|{
name|struct
name|namecache
modifier|*
name|nc_forw
decl_stmt|;
comment|/* hash chain, MUST BE FIRST */
name|struct
name|namecache
modifier|*
name|nc_back
decl_stmt|;
comment|/* hash chain, MUST BE FIRST */
name|struct
name|namecache
modifier|*
name|nc_nxt
decl_stmt|;
comment|/* LRU chain */
name|struct
name|namecache
modifier|*
modifier|*
name|nc_prev
decl_stmt|;
comment|/* LRU chain */
name|struct
name|vnode
modifier|*
name|nc_dvp
decl_stmt|;
comment|/* vnode of parent of name */
name|u_long
name|nc_dvpid
decl_stmt|;
comment|/* capability number of nc_dvp */
name|struct
name|vnode
modifier|*
name|nc_vp
decl_stmt|;
comment|/* vnode the name refers to */
name|u_long
name|nc_vpid
decl_stmt|;
comment|/* capability number of nc_vp */
name|char
name|nc_nlen
decl_stmt|;
comment|/* length of name */
name|char
name|nc_name
index|[
name|NCHNAMLEN
index|]
decl_stmt|;
comment|/* segment name */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|u_long
name|nextvnodeid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|namei
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lookup
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NAMEI_H_ */
end_comment

end_unit

