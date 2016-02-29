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
name|ticker_s
name|ticker_t
typedef|;
end_typedef

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
name|ticker_s
block|{
name|int32_t
name|tick
decl_stmt|;
name|int32_t
name|nticks
decl_stmt|;
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

begin_function_decl
name|void
name|ticker_init
parameter_list|(
name|ticker_t
modifier|*
name|ticker
parameter_list|,
name|int32_t
name|nticks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ticker_copy
parameter_list|(
name|ticker_t
modifier|*
name|ticker
parameter_list|,
specifier|const
name|ticker_t
modifier|*
name|other
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|ticker_read
parameter_list|(
specifier|const
name|ticker_t
modifier|*
name|ticker
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ticker_ticks
parameter_list|(
name|ticker_t
modifier|*
name|ticker
parameter_list|,
name|int32_t
name|nticks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ticker_tick
parameter_list|(
name|ticker_t
modifier|*
name|ticker
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
name|JEMALLOC_TICKER_C_
argument_list|)
operator|)
end_if

begin_function
name|JEMALLOC_INLINE
name|void
name|ticker_init
parameter_list|(
name|ticker_t
modifier|*
name|ticker
parameter_list|,
name|int32_t
name|nticks
parameter_list|)
block|{
name|ticker
operator|->
name|tick
operator|=
name|nticks
expr_stmt|;
name|ticker
operator|->
name|nticks
operator|=
name|nticks
expr_stmt|;
block|}
end_function

begin_function
name|JEMALLOC_INLINE
name|void
name|ticker_copy
parameter_list|(
name|ticker_t
modifier|*
name|ticker
parameter_list|,
specifier|const
name|ticker_t
modifier|*
name|other
parameter_list|)
block|{
operator|*
name|ticker
operator|=
operator|*
name|other
expr_stmt|;
block|}
end_function

begin_function
name|JEMALLOC_INLINE
name|int32_t
name|ticker_read
parameter_list|(
specifier|const
name|ticker_t
modifier|*
name|ticker
parameter_list|)
block|{
return|return
operator|(
name|ticker
operator|->
name|tick
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_INLINE
name|bool
name|ticker_ticks
parameter_list|(
name|ticker_t
modifier|*
name|ticker
parameter_list|,
name|int32_t
name|nticks
parameter_list|)
block|{
if|if
condition|(
name|unlikely
argument_list|(
name|ticker
operator|->
name|tick
operator|<
name|nticks
argument_list|)
condition|)
block|{
name|ticker
operator|->
name|tick
operator|=
name|ticker
operator|->
name|nticks
expr_stmt|;
return|return
operator|(
name|true
operator|)
return|;
block|}
name|ticker
operator|->
name|tick
operator|-=
name|nticks
expr_stmt|;
return|return
operator|(
name|false
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_INLINE
name|bool
name|ticker_tick
parameter_list|(
name|ticker_t
modifier|*
name|ticker
parameter_list|)
block|{
return|return
operator|(
name|ticker_ticks
argument_list|(
name|ticker
argument_list|,
literal|1
argument_list|)
operator|)
return|;
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

