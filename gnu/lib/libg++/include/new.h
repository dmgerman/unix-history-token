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
file|<defines.h>
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

begin_extern
extern|extern
literal|"C"
name|fvoid_t
modifier|*
name|set_new_handler
parameter_list|(
name|fvoid_t
modifier|*
parameter_list|)
function_decl|;
end_extern

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_decl_stmt
specifier|extern
name|fvoid_t
modifier|*
name|__new_handler
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern
literal|"C"
name|void
name|__default_new_handler
parameter_list|()
function_decl|;
end_extern

begin_define
define|#
directive|define
name|NEW
parameter_list|(
name|where
parameter_list|)
value|new ( where )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// default placement version of operator new
end_comment

begin_function
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

begin_function
specifier|inline
name|void
modifier|*
name|operator
name|new
function|[]
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

