begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	namei.h	6.5	84/07/08	*/
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
file|"../h/uio.h"
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

begin_struct
struct|struct
name|nameidata
block|{
name|caddr_t
name|ni_dirp
decl_stmt|;
comment|/* pathname pointer */
name|struct
name|inode
modifier|*
name|ni_pdir
decl_stmt|;
comment|/* inode of parent directory of dirp */
name|struct
name|iovec
name|ni_iovec
decl_stmt|;
name|struct
name|uio
name|ni_uio
decl_stmt|;
name|struct
name|direct
name|ni_dent
decl_stmt|;
comment|/* current directory entry */
name|short
name|ni_error
decl_stmt|;
comment|/* error return if any */
name|short
name|ni_nameiop
decl_stmt|;
comment|/* see below */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ni_base
value|ni_iovec.iov_base
end_define

begin_define
define|#
directive|define
name|ni_count
value|ni_iovec.iov_len
end_define

begin_define
define|#
directive|define
name|ni_iov
value|ni_uio.uio_iov
end_define

begin_define
define|#
directive|define
name|ni_iovcnt
value|ni_uio.uio_iovcnt
end_define

begin_define
define|#
directive|define
name|ni_offset
value|ni_uio.uio_offset
end_define

begin_define
define|#
directive|define
name|ni_segflg
value|ni_uio.uio_segflg
end_define

begin_define
define|#
directive|define
name|ni_resid
value|ni_uio.uio_resid
end_define

begin_comment
comment|/*  * namei opertions  */
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
name|nch
block|{
name|struct
name|nch
modifier|*
name|nc_forw
decl_stmt|,
modifier|*
name|nc_back
decl_stmt|;
comment|/* hash chain, MUST BE FIRST */
name|struct
name|nch
modifier|*
name|nc_nxt
decl_stmt|,
modifier|*
modifier|*
name|nc_prev
decl_stmt|;
comment|/* LRU chain */
name|struct
name|inode
modifier|*
name|nc_ip
decl_stmt|;
comment|/* inode the name refers to */
name|ino_t
name|nc_ino
decl_stmt|;
comment|/* ino of parent of name */
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
comment|/* referenced inode's id */
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
name|nch
modifier|*
name|nch
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

