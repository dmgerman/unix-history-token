begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)namei.h	6.11 (Berkeley) 2/20/86  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NAMEI_
end_ifndef

begin_define
define|#
directive|define
name|_NAMEI_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"uio.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|ni_seg
decl_stmt|;
comment|/* location of pathname */
name|short
name|ni_nameiop
decl_stmt|;
comment|/* see below */
name|struct
name|vnode
modifier|*
name|ni_cdir
decl_stmt|;
comment|/* current directory */
name|struct
name|vnode
modifier|*
name|ni_rdir
decl_stmt|;
comment|/* root directory, if not normal root */
name|struct
name|ucred
modifier|*
name|ni_cred
decl_stmt|;
comment|/* credentials */
comment|/* shared between namei, lookup routines and commit routines: */
name|caddr_t
name|ni_pnbuf
decl_stmt|;
comment|/* pathname buffer (could be local) */
name|char
modifier|*
name|ni_ptr
decl_stmt|;
comment|/* current location in pathname */
name|int
name|ni_pathlen
decl_stmt|;
comment|/* remaining chars in path */
name|short
name|ni_more
decl_stmt|;
comment|/* more left to translate in pathname */
name|short
name|ni_loopcnt
decl_stmt|;
comment|/* count of symlinks encountered */
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
comment|/* side effects: */
comment|/* BEGIN UFS SPECIFIC */
name|off_t
name|ni_endoff
decl_stmt|;
comment|/* end of useful stuff in directory */
struct|struct
name|diroffcache
block|{
comment|/* last successful directory search */
name|struct
name|vnode
modifier|*
name|nc_prevdir
decl_stmt|;
comment|/* terminal directory */
name|long
name|nc_id
decl_stmt|;
comment|/* directory's unique id */
name|struct
name|timeval
name|nc_time
decl_stmt|;
comment|/* modification time */
name|off_t
name|nc_prevoffset
decl_stmt|;
comment|/* where last entry found */
block|}
name|ni_nc
struct|;
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
name|struct
name|direct
name|nd_dent
decl_stmt|;
comment|/* current directory entry */
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
name|ni_prevdir
value|ni_nc.nc_prevdir
end_define

begin_define
define|#
directive|define
name|ni_id
value|ni_nc.nc_id
end_define

begin_define
define|#
directive|define
name|ni_time
value|ni_nc.nc_time
end_define

begin_define
define|#
directive|define
name|ni_prevoffset
value|ni_nc.nc_prevoffset
end_define

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
name|ni_segflg
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

begin_comment
comment|/*  * namei operations and modifiers  */
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
name|LOCKPARENT
value|0x10
end_define

begin_comment
comment|/* see the top of namei */
end_comment

begin_define
define|#
directive|define
name|NOCACHE
value|0x20
end_define

begin_comment
comment|/* name must not be left in cache */
end_comment

begin_define
define|#
directive|define
name|FOLLOW
value|0x40
end_define

begin_comment
comment|/* follow symbolic links */
end_comment

begin_define
define|#
directive|define
name|NOFOLLOW
value|0x0
end_define

begin_comment
comment|/* don't follow symbolic links (pseudo) */
end_comment

begin_comment
comment|/*  * This structure describes the elements in the cache of recent  * names looked up by namei.  */
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
name|nc_vp
decl_stmt|;
comment|/* vnode the name refers to */
name|fileid
name|nc_fileid
decl_stmt|;
comment|/* fileid of parent of name */
name|dev_t
name|nc_dev
decl_stmt|;
comment|/* dev of parent of name */
name|dev_t
name|nc_idev
decl_stmt|;
comment|/* dev of the name ref'd */
name|long
name|nc_id
decl_stmt|;
comment|/* referenced vnode's id */
name|char
name|nc_nlen
decl_stmt|;
comment|/* length of name */
define|#
directive|define
name|NCHNAMLEN
value|15
comment|/* maximum name segment length we bother with */
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

begin_decl_stmt
name|struct
name|namecache
modifier|*
name|namecache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nchsize
decl_stmt|;
end_decl_stmt

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
comment|/* hits that we can reall use */
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

end_unit

