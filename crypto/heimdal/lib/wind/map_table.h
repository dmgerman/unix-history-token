begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ./map_table.h */
end_comment

begin_comment
comment|/* Automatically generated at 2012-01-11T14:07:01.097337 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAP_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|MAP_TABLE_H
value|1
end_define

begin_include
include|#
directive|include
file|"windlocl.h"
end_include

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
name|wind_profile_flags
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|translation
name|_wind_map_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|size_t
name|_wind_map_table_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint32_t
name|_wind_map_table_val
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAP_TABLE_H */
end_comment

end_unit

