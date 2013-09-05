begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|quarantine_obj_s
name|quarantine_obj_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|quarantine_s
name|quarantine_t
typedef|;
end_typedef

begin_comment
comment|/* Default per thread quarantine size if valgrind is enabled. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_QUARANTINE_DEFAULT
value|(ZU(1)<< 24)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_TYPES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_STRUCTS
end_ifdef

begin_struct
struct|struct
name|quarantine_obj_s
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|size_t
name|usize
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|quarantine_s
block|{
name|size_t
name|curbytes
decl_stmt|;
name|size_t
name|curobjs
decl_stmt|;
name|size_t
name|first
decl_stmt|;
define|#
directive|define
name|LG_MAXOBJS_INIT
value|10
name|size_t
name|lg_maxobjs
decl_stmt|;
name|quarantine_obj_t
name|objs
index|[
literal|1
index|]
decl_stmt|;
comment|/* Dynamically sized ring buffer. */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_STRUCTS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_EXTERNS
end_ifdef

begin_function_decl
name|quarantine_t
modifier|*
name|quarantine_init
parameter_list|(
name|size_t
name|lg_maxobjs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|quarantine
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|quarantine_cleanup
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|quarantine_boot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_EXTERNS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_INLINES
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_ENABLE_INLINE
end_ifndef

begin_macro
name|malloc_tsd_protos
argument_list|(
argument|JEMALLOC_ATTR(unused)
argument_list|,
argument|quarantine
argument_list|,
argument|quarantine_t *
argument_list|)
end_macro

begin_function_decl
name|void
name|quarantine_alloc_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|JEMALLOC_ENABLE_INLINE
argument_list|)
operator|||
name|defined
argument_list|(
name|JEMALLOC_QUARANTINE_C_
argument_list|)
operator|)
end_if

begin_macro
name|malloc_tsd_externs
argument_list|(
argument|quarantine
argument_list|,
argument|quarantine_t *
argument_list|)
end_macro

begin_macro
name|malloc_tsd_funcs
argument_list|(
argument|JEMALLOC_ALWAYS_INLINE
argument_list|,
argument|quarantine
argument_list|,
argument|quarantine_t *
argument_list|,
argument|NULL
argument_list|,
argument|quarantine_cleanup
argument_list|)
end_macro

begin_function
name|JEMALLOC_ALWAYS_INLINE
name|void
name|quarantine_alloc_hook
parameter_list|(
name|void
parameter_list|)
block|{
name|quarantine_t
modifier|*
name|quarantine
decl_stmt|;
name|assert
argument_list|(
name|config_fill
operator|&&
name|opt_quarantine
argument_list|)
expr_stmt|;
name|quarantine
operator|=
operator|*
name|quarantine_tsd_get
argument_list|()
expr_stmt|;
if|if
condition|(
name|quarantine
operator|==
name|NULL
condition|)
name|quarantine_init
argument_list|(
name|LG_MAXOBJS_INIT
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_INLINES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

end_unit

