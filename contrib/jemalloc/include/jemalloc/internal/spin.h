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
name|spin_s
name|spin_t
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
name|spin_s
block|{
name|unsigned
name|iteration
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
name|spin_init
parameter_list|(
name|spin_t
modifier|*
name|spin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|spin_adaptive
parameter_list|(
name|spin_t
modifier|*
name|spin
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
name|JEMALLOC_SPIN_C_
argument_list|)
operator|)
end_if

begin_function
name|JEMALLOC_INLINE
name|void
name|spin_init
parameter_list|(
name|spin_t
modifier|*
name|spin
parameter_list|)
block|{
name|spin
operator|->
name|iteration
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
name|JEMALLOC_INLINE
name|void
name|spin_adaptive
parameter_list|(
name|spin_t
modifier|*
name|spin
parameter_list|)
block|{
specifier|volatile
name|uint64_t
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
operator|(
name|KQU
argument_list|(
literal|1
argument_list|)
operator|<<
name|spin
operator|->
name|iteration
operator|)
condition|;
name|i
operator|++
control|)
name|CPU_SPINWAIT
expr_stmt|;
if|if
condition|(
name|spin
operator|->
name|iteration
operator|<
literal|63
condition|)
name|spin
operator|->
name|iteration
operator|++
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

