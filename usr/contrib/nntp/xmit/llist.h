begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_struct
struct|struct
name|llist
block|{
name|struct
name|llist
modifier|*
name|l_next
decl_stmt|;
name|caddr_t
name|l_item
decl_stmt|;
name|unsigned
name|l_len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|l_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|llist
modifier|*
name|l_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

