begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	namei.h	4.2	82/11/13	*/
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

end_unit

