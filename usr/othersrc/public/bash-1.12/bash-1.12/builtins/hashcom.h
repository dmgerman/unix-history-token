begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hashcom.h - Common defines for hashing filenames. */
end_comment

begin_include
include|#
directive|include
file|"../hash.h"
end_include

begin_define
define|#
directive|define
name|FILENAME_HASH_BUCKETS
value|631
end_define

begin_decl_stmt
name|HASH_TABLE
modifier|*
name|hashed_filenames
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|path
decl_stmt|;
comment|/* The full pathname of the file. */
name|int
name|check_dot
decl_stmt|;
comment|/* Whether `.' appeared before this one in $PATH. */
block|}
name|PATH_DATA
typedef|;
end_typedef

begin_define
define|#
directive|define
name|pathdata
parameter_list|(
name|x
parameter_list|)
value|((PATH_DATA *)(x)->data)
end_define

end_unit

