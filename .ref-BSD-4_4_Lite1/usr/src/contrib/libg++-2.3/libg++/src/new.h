begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_new_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_new_h
value|1
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<std.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_LIBGXX_MALLOC
end_ifndef

begin_define
define|#
directive|define
name|MALLOC_ALIGN_MASK
value|7
end_define

begin_comment
comment|/* ptrs aligned at 8 byte boundaries */
end_comment

begin_define
define|#
directive|define
name|MALLOC_MIN_OVERHEAD
value|8
end_define

begin_comment
comment|/* 8 bytes of overhead per pointer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|new_handler_t
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|new_handler_t
name|__new_handler
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern
literal|"C"
name|void
name|default_new_handler
parameter_list|()
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|new_handler_t
name|set_new_handler
parameter_list|(
name|new_handler_t
parameter_list|)
function_decl|;
end_extern

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_define
define|#
directive|define
name|NEW
parameter_list|(
name|where
parameter_list|)
value|new { where }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// default placement version of operator new
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
parameter_list|,
name|void
modifier|*
name|place
parameter_list|)
block|{
return|return
name|place
return|;
block|}
end_function

begin_comment
comment|// provide a C++ interface to vector-resize via realloc
end_comment

begin_function
specifier|inline
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
name|size
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|new_len
parameter_list|)
block|{
return|return
name|realloc
argument_list|(
name|ptr
argument_list|,
name|new_len
operator|*
name|size
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

