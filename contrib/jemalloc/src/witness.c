begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|JEMALLOC_WITNESS_C_
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/jemalloc_internal.h"
end_include

begin_function
name|void
name|witness_init
parameter_list|(
name|witness_t
modifier|*
name|witness
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|witness_rank_t
name|rank
parameter_list|,
name|witness_comp_t
modifier|*
name|comp
parameter_list|)
block|{
name|witness
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|witness
operator|->
name|rank
operator|=
name|rank
expr_stmt|;
name|witness
operator|->
name|comp
operator|=
name|comp
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_undef
undef|#
directive|undef
name|witness_lock_error
end_undef

begin_define
define|#
directive|define
name|witness_lock_error
value|JEMALLOC_N(n_witness_lock_error)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|witness_lock_error
parameter_list|(
specifier|const
name|witness_list_t
modifier|*
name|witnesses
parameter_list|,
specifier|const
name|witness_t
modifier|*
name|witness
parameter_list|)
block|{
name|witness_t
modifier|*
name|w
decl_stmt|;
name|malloc_printf
argument_list|(
literal|"<jemalloc>: Lock rank order reversal:"
argument_list|)
expr_stmt|;
name|ql_foreach
argument_list|(
argument|w
argument_list|,
argument|witnesses
argument_list|,
argument|link
argument_list|)
block|{
name|malloc_printf
argument_list|(
literal|" %s(%u)"
argument_list|,
name|w
operator|->
name|name
argument_list|,
name|w
operator|->
name|rank
argument_list|)
expr_stmt|;
block|}
name|malloc_printf
argument_list|(
literal|" %s(%u)\n"
argument_list|,
name|witness
operator|->
name|name
argument_list|,
name|witness
operator|->
name|rank
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_undef
undef|#
directive|undef
name|witness_lock_error
end_undef

begin_define
define|#
directive|define
name|witness_lock_error
value|JEMALLOC_N(witness_lock_error)
end_define

begin_decl_stmt
name|witness_lock_error_t
modifier|*
name|witness_lock_error
init|=
name|JEMALLOC_N
argument_list|(
name|n_witness_lock_error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_undef
undef|#
directive|undef
name|witness_owner_error
end_undef

begin_define
define|#
directive|define
name|witness_owner_error
value|JEMALLOC_N(n_witness_owner_error)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|witness_owner_error
parameter_list|(
specifier|const
name|witness_t
modifier|*
name|witness
parameter_list|)
block|{
name|malloc_printf
argument_list|(
literal|"<jemalloc>: Should own %s(%u)\n"
argument_list|,
name|witness
operator|->
name|name
argument_list|,
name|witness
operator|->
name|rank
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_undef
undef|#
directive|undef
name|witness_owner_error
end_undef

begin_define
define|#
directive|define
name|witness_owner_error
value|JEMALLOC_N(witness_owner_error)
end_define

begin_decl_stmt
name|witness_owner_error_t
modifier|*
name|witness_owner_error
init|=
name|JEMALLOC_N
argument_list|(
name|n_witness_owner_error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_undef
undef|#
directive|undef
name|witness_not_owner_error
end_undef

begin_define
define|#
directive|define
name|witness_not_owner_error
value|JEMALLOC_N(n_witness_not_owner_error)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|witness_not_owner_error
parameter_list|(
specifier|const
name|witness_t
modifier|*
name|witness
parameter_list|)
block|{
name|malloc_printf
argument_list|(
literal|"<jemalloc>: Should not own %s(%u)\n"
argument_list|,
name|witness
operator|->
name|name
argument_list|,
name|witness
operator|->
name|rank
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_undef
undef|#
directive|undef
name|witness_not_owner_error
end_undef

begin_define
define|#
directive|define
name|witness_not_owner_error
value|JEMALLOC_N(witness_not_owner_error)
end_define

begin_decl_stmt
name|witness_not_owner_error_t
modifier|*
name|witness_not_owner_error
init|=
name|JEMALLOC_N
argument_list|(
name|n_witness_not_owner_error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_undef
undef|#
directive|undef
name|witness_lockless_error
end_undef

begin_define
define|#
directive|define
name|witness_lockless_error
value|JEMALLOC_N(n_witness_lockless_error)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|witness_lockless_error
parameter_list|(
specifier|const
name|witness_list_t
modifier|*
name|witnesses
parameter_list|)
block|{
name|witness_t
modifier|*
name|w
decl_stmt|;
name|malloc_printf
argument_list|(
literal|"<jemalloc>: Should not own any locks:"
argument_list|)
expr_stmt|;
name|ql_foreach
argument_list|(
argument|w
argument_list|,
argument|witnesses
argument_list|,
argument|link
argument_list|)
block|{
name|malloc_printf
argument_list|(
literal|" %s(%u)"
argument_list|,
name|w
operator|->
name|name
argument_list|,
name|w
operator|->
name|rank
argument_list|)
expr_stmt|;
block|}
name|malloc_printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_undef
undef|#
directive|undef
name|witness_lockless_error
end_undef

begin_define
define|#
directive|define
name|witness_lockless_error
value|JEMALLOC_N(witness_lockless_error)
end_define

begin_decl_stmt
name|witness_lockless_error_t
modifier|*
name|witness_lockless_error
init|=
name|JEMALLOC_N
argument_list|(
name|n_witness_lockless_error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|witnesses_cleanup
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
block|{
name|witness_assert_lockless
argument_list|(
name|tsd_tsdn
argument_list|(
name|tsd
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Do nothing. */
block|}
end_function

begin_function
name|void
name|witness_fork_cleanup
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
block|{
comment|/* Do nothing. */
block|}
end_function

begin_function
name|void
name|witness_prefork
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
block|{
name|tsd_witness_fork_set
argument_list|(
name|tsd
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|witness_postfork_parent
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
block|{
name|tsd_witness_fork_set
argument_list|(
name|tsd
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|witness_postfork_child
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|JEMALLOC_MUTEX_INIT_CB
name|witness_list_t
modifier|*
name|witnesses
decl_stmt|;
name|witnesses
operator|=
name|tsd_witnessesp_get
argument_list|(
name|tsd
argument_list|)
expr_stmt|;
name|ql_new
argument_list|(
name|witnesses
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|tsd_witness_fork_set
argument_list|(
name|tsd
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

