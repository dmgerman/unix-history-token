begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)namei.h	7.14 (Berkeley) %G%  */
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

begin_include
include|#
directive|include
file|<ufs/dir.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*  * Encapsulation of namei parameters.  * One of these is located in the u. area to  * minimize space allocated on the kernel stack.  */
end_comment

begin_struct
struct|struct
name|nameidata
block|{
comment|/* arguments to namei and related context: */
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
comment|/* alternate starting directory */
comment|/* shared between namei, lookup routines and commit routines: */
name|caddr_t
name|ni_pnbuf
decl_stmt|;
comment|/* pathname buffer */
name|char
modifier|*
name|ni_ptr
decl_stmt|;
comment|/* current location in pathname */
name|char
modifier|*
name|ni_next
decl_stmt|;
comment|/* next location in pathname */
name|u_int
name|ni_pathlen
decl_stmt|;
comment|/* remaining chars in path */
name|u_long
name|ni_hash
decl_stmt|;
comment|/* hash value of current component */
name|short
name|ni_namelen
decl_stmt|;
comment|/* length of current component */
name|short
name|ni_loopcnt
decl_stmt|;
comment|/* count of symlinks encountered */
name|char
name|ni_makeentry
decl_stmt|;
comment|/* 1 => add entry to name cache */
name|char
name|ni_isdotdot
decl_stmt|;
comment|/* 1 => current component name is .. */
comment|/* results: */
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
name|struct
name|direct
name|ni_dent
decl_stmt|;
comment|/* final component name */
comment|/* side effects: */
comment|/* BEGIN UFS SPECIFIC */
name|off_t
name|ni_endoff
decl_stmt|;
comment|/* end of useful directory contents */
struct|struct
name|ndirinfo
block|{
comment|/* saved info for new dir entry */
name|struct
name|iovec
name|nd_iovec
decl_stmt|;
comment|/* pointed to by ni_iov */
name|struct
name|uio
name|nd_uio
decl_stmt|;
comment|/* directory I/O parameters */
block|}
name|ni_nd
struct|;
comment|/* END UFS SPECIFIC */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ni_base
value|ni_nd.nd_iovec.iov_base
end_define

begin_define
define|#
directive|define
name|ni_count
value|ni_nd.nd_iovec.iov_len
end_define

begin_define
define|#
directive|define
name|ni_uioseg
value|ni_nd.nd_uio.uio_segflg
end_define

begin_define
define|#
directive|define
name|ni_iov
value|ni_nd.nd_uio.uio_iov
end_define

begin_define
define|#
directive|define
name|ni_iovcnt
value|ni_nd.nd_uio.uio_iovcnt
end_define

begin_define
define|#
directive|define
name|ni_offset
value|ni_nd.nd_uio.uio_offset
end_define

begin_define
define|#
directive|define
name|ni_resid
value|ni_nd.nd_uio.uio_resid
end_define

begin_define
define|#
directive|define
name|ni_rw
value|ni_nd.nd_uio.uio_rw
end_define

begin_define
define|#
directive|define
name|ni_uio
value|ni_nd.nd_uio
end_define

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
comment|/*  * namei parameter descriptors  */
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
comment|/* has preallocated pathname buffer */
end_comment

begin_define
define|#
directive|define
name|STARTDIR
value|0x0800
end_define

begin_comment
comment|/* has alternate starting directory */
end_comment

begin_define
define|#
directive|define
name|SAVESTARTDIR
value|0x1000
end_define

begin_comment
comment|/* do not vrele alternate starting directory */
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

