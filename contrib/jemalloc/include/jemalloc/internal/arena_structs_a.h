begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_ARENA_STRUCTS_A_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_ARENA_STRUCTS_A_H
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/bitmap.h"
end_include

begin_struct
struct|struct
name|arena_slab_data_s
block|{
comment|/* Per region allocated/deallocated bitmap. */
name|bitmap_t
name|bitmap
index|[
name|BITMAP_GROUPS_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_ARENA_STRUCTS_A_H */
end_comment

end_unit

