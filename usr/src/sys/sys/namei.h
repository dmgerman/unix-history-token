begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	namei.h	6.4	84/06/27	*/
end_comment

begin_struct
struct|struct
name|namidata
block|{
name|int
name|ni_offset
decl_stmt|;
name|int
name|ni_count
decl_stmt|;
name|struct
name|inode
modifier|*
name|ni_pdir
decl_stmt|;
name|struct
name|direct
name|ni_dent
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|nami_op
block|{
name|NAMI_LOOKUP
block|,
name|NAMI_CREATE
block|,
name|NAMI_DELETE
block|}
enum|;
end_enum

begin_comment
comment|/* this is temporary until the namei interface changes */
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

end_unit

