begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ./normalize_table.h */
end_comment

begin_comment
comment|/* Automatically generated at 2012-01-11T14:07:01.713967 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NORMALIZE_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|NORMALIZE_TABLE_H
value|1
end_define

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_define
define|#
directive|define
name|MAX_LENGTH_CANON
value|18
end_define

begin_struct
struct|struct
name|translation
block|{
name|uint32_t
name|key
decl_stmt|;
name|unsigned
name|short
name|val_len
decl_stmt|;
name|unsigned
name|short
name|val_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|translation
name|_wind_normalize_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint32_t
name|_wind_normalize_val_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|size_t
name|_wind_normalize_table_size
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|canon_node
block|{
name|uint32_t
name|val
decl_stmt|;
name|unsigned
name|char
name|next_start
decl_stmt|;
name|unsigned
name|char
name|next_end
decl_stmt|;
name|unsigned
name|short
name|next_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|canon_node
name|_wind_canon_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|short
name|_wind_canon_next_table
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NORMALIZE_TABLE_H */
end_comment

end_unit

