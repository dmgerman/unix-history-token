begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	namei.h	4.1	82/09/04	*/
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

end_unit

