begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ./combining_table.h */
end_comment

begin_comment
comment|/* Automatically generated at 2012-01-11T14:07:00.836450 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMBINING_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|COMBINING_TABLE_H
value|1
end_define

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_struct
struct|struct
name|translation
block|{
name|uint32_t
name|key
decl_stmt|;
name|unsigned
name|combining_class
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|translation
name|_wind_combining_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|size_t
name|_wind_combining_table_size
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMBINING_TABLE_H */
end_comment

end_unit

