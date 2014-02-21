begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASHTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|HASHTABLE_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|HASH_OK
value|0
end_define

begin_define
define|#
directive|define
name|HASH_UPDATED
value|1
end_define

begin_define
define|#
directive|define
name|HASH_FAIL
value|2
end_define

begin_define
define|#
directive|define
name|HASH_FULL
value|3
end_define

begin_define
define|#
directive|define
name|HASH_NOTFOUND
value|4
end_define

begin_define
define|#
directive|define
name|HASHSTEP
parameter_list|(
name|x
parameter_list|,
name|c
parameter_list|)
value|(((x<< 5) + x) + (c))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|key
decl_stmt|;
name|void
modifier|*
name|value
decl_stmt|;
block|}
name|hashtable_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|size_t
name|key_size
decl_stmt|;
name|size_t
name|table_size
decl_stmt|;
name|size_t
name|usage
decl_stmt|;
name|size_t
name|value_size
decl_stmt|;
name|hashtable_entry
modifier|*
modifier|*
name|entries
decl_stmt|;
block|}
name|hashtable
typedef|;
end_typedef

begin_function_decl
name|void
name|hashtable_free
parameter_list|(
name|hashtable
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hashtable_get
parameter_list|(
name|hashtable
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|hashtable
modifier|*
name|hashtable_init
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hashtable_put
parameter_list|(
name|hashtable
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hashtable_remove
parameter_list|(
name|hashtable
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASHTABLE.H */
end_comment

end_unit

