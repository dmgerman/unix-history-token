begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_SPIN_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_SPIN_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_SPIN_C_
end_ifdef

begin_define
define|#
directive|define
name|SPIN_INLINE
value|extern inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SPIN_INLINE
value|inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPIN_INITIALIZER
value|{0U}
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|iteration
decl_stmt|;
block|}
name|spin_t
typedef|;
end_typedef

begin_function
name|SPIN_INLINE
name|void
name|spin_adaptive
parameter_list|(
name|spin_t
modifier|*
name|spin
parameter_list|)
block|{
specifier|volatile
name|uint32_t
name|i
decl_stmt|;
if|if
condition|(
name|spin
operator|->
name|iteration
operator|<
literal|5
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
operator|(
literal|1U
operator|<<
name|spin
operator|->
name|iteration
operator|)
condition|;
name|i
operator|++
control|)
block|{
name|CPU_SPINWAIT
expr_stmt|;
block|}
name|spin
operator|->
name|iteration
operator|++
expr_stmt|;
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|_WIN32
name|SwitchToThread
argument_list|()
expr_stmt|;
else|#
directive|else
name|sched_yield
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function

begin_undef
undef|#
directive|undef
name|SPIN_INLINE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_SPIN_H */
end_comment

end_unit

