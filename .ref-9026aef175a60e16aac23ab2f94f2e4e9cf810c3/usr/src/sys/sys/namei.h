begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)namei.h	8.5 (Berkeley) %G%  */
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

begin_comment
comment|/*  * Encapsulation of namei parameters.  */
end_comment

begin_struct
struct|struct
name|nameidata
block|{
comment|/* 	 * Arguments to namei/lookup. 	 */
name|caddr_t
name|ni_dirp
decl_stmt|;
comment|/* pathname pointer */
name|enum
name|uio_seg
name|ni_segflg
decl_stmt|;
comment|/* location of pathname */
comment|/* u_long	ni_nameiop;		   namei operation */
comment|/* u_long	ni_flags;		   flags to namei */
comment|/* struct	proc *ni_proc;		   process requesting lookup */
comment|/* 	 * Arguments to lookup. 	 */
comment|/* struct	ucred *ni_cred;		   credentials */
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
name|long
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
struct|struct
name|componentname
block|{
comment|/* 		 * Arguments to lookup. 		 */
name|u_long
name|cn_nameiop
decl_stmt|;
comment|/* namei operation */
name|u_long
name|cn_flags
decl_stmt|;
comment|/* flags to namei */
name|struct
name|proc
modifier|*
name|cn_proc
decl_stmt|;
comment|/* process requesting lookup */
name|struct
name|ucred
modifier|*
name|cn_cred
decl_stmt|;
comment|/* credentials */
comment|/* 		 * Shared between lookup and commit routines. 		 */
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
name|u_long
name|cn_hash
decl_stmt|;
comment|/* hash value of looked up name */
name|long
name|cn_consume
decl_stmt|;
comment|/* chars to consume in lookup() */
block|}
name|ni_cnd
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
value|0x00100
end_define

begin_comment
comment|/* do not cross mount points */
end_comment

begin_define
define|#
directive|define
name|RDONLY
value|0x00200
end_define

begin_comment
comment|/* lookup with read-only semantics */
end_comment

begin_define
define|#
directive|define
name|HASBUF
value|0x00400
end_define

begin_comment
comment|/* has allocated pathname buffer */
end_comment

begin_define
define|#
directive|define
name|SAVENAME
value|0x00800
end_define

begin_comment
comment|/* save pathanme buffer */
end_comment

begin_define
define|#
directive|define
name|SAVESTART
value|0x01000
end_define

begin_comment
comment|/* save starting directory */
end_comment

begin_define
define|#
directive|define
name|ISDOTDOT
value|0x02000
end_define

begin_comment
comment|/* current component name is .. */
end_comment

begin_define
define|#
directive|define
name|MAKEENTRY
value|0x04000
end_define

begin_comment
comment|/* entry is to be added to name cache */
end_comment

begin_define
define|#
directive|define
name|ISLASTCN
value|0x08000
end_define

begin_comment
comment|/* this is last component of pathname */
end_comment

begin_define
define|#
directive|define
name|ISSYMLINK
value|0x10000
end_define

begin_comment
comment|/* symlink needs interpretation */
end_comment

begin_define
define|#
directive|define
name|ISWHITEOUT
value|0x20000
end_define

begin_comment
comment|/* found whiteout */
end_comment

begin_define
define|#
directive|define
name|DOWHITEOUT
value|0x40000
end_define

begin_comment
comment|/* do whiteouts */
end_comment

begin_define
define|#
directive|define
name|PARAMASK
value|0xfff00
end_define

begin_comment
comment|/* mask of parameter descriptors */
end_comment

begin_comment
comment|/*  * Initialization of an nameidata structure.  */
end_comment

begin_define
define|#
directive|define
name|NDINIT
parameter_list|(
name|ndp
parameter_list|,
name|op
parameter_list|,
name|flags
parameter_list|,
name|segflg
parameter_list|,
name|namep
parameter_list|,
name|p
parameter_list|)
value|{ \ 	(ndp)->ni_cnd.cn_nameiop = op; \ 	(ndp)->ni_cnd.cn_flags = flags; \ 	(ndp)->ni_segflg = segflg; \ 	(ndp)->ni_dirp = namep; \ 	(ndp)->ni_cnd.cn_proc = p; \ }
end_define

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
name|LIST_ENTRY
argument_list|(
argument|namecache
argument_list|)
name|nc_hash
expr_stmt|;
comment|/* hash chain */
name|TAILQ_ENTRY
argument_list|(
argument|namecache
argument_list|)
name|nc_lru
expr_stmt|;
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|relookup
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|dvp
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|,
expr|struct
name|componentname
operator|*
name|cnp
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
comment|/* !_SYS_NAMEI_H_ */
end_comment

end_unit

