begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_PAGES_EXTERNS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_PAGES_EXTERNS_H
end_define

begin_comment
comment|/* Page size.  LG_PAGE is determined by the configure script. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PAGE_MASK
end_ifdef

begin_undef
undef|#
directive|undef
name|PAGE_MASK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PAGE
value|((size_t)(1U<< LG_PAGE))
end_define

begin_define
define|#
directive|define
name|PAGE_MASK
value|((size_t)(PAGE - 1))
end_define

begin_comment
comment|/* Return the page base address for the page containing address a. */
end_comment

begin_define
define|#
directive|define
name|PAGE_ADDR2BASE
parameter_list|(
name|a
parameter_list|)
define|\
value|((void *)((uintptr_t)(a)& ~PAGE_MASK))
end_define

begin_comment
comment|/* Return the smallest pagesize multiple that is>= s. */
end_comment

begin_define
define|#
directive|define
name|PAGE_CEILING
parameter_list|(
name|s
parameter_list|)
define|\
value|(((s) + PAGE_MASK)& ~PAGE_MASK)
end_define

begin_comment
comment|/* Huge page size.  LG_HUGEPAGE is determined by the configure script. */
end_comment

begin_define
define|#
directive|define
name|HUGEPAGE
value|((size_t)(1U<< LG_HUGEPAGE))
end_define

begin_define
define|#
directive|define
name|HUGEPAGE_MASK
value|((size_t)(HUGEPAGE - 1))
end_define

begin_comment
comment|/* Return the huge page base address for the huge page containing address a. */
end_comment

begin_define
define|#
directive|define
name|HUGEPAGE_ADDR2BASE
parameter_list|(
name|a
parameter_list|)
define|\
value|((void *)((uintptr_t)(a)& ~HUGEPAGE_MASK))
end_define

begin_comment
comment|/* Return the smallest pagesize multiple that is>= s. */
end_comment

begin_define
define|#
directive|define
name|HUGEPAGE_CEILING
parameter_list|(
name|s
parameter_list|)
define|\
value|(((s) + HUGEPAGE_MASK)& ~HUGEPAGE_MASK)
end_define

begin_comment
comment|/* PAGES_CAN_PURGE_LAZY is defined if lazy purging is supported. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|JEMALLOC_PURGE_MADVISE_FREE
argument_list|)
end_if

begin_define
define|#
directive|define
name|PAGES_CAN_PURGE_LAZY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * PAGES_CAN_PURGE_FORCED is defined if forced purging is supported.  *  * The only supported way to hard-purge on Windows is to decommit and then  * re-commit, but doing so is racy, and if re-commit fails it's a pain to  * propagate the "poisoned" memory state.  Since we typically decommit as the  * next step after purging on Windows anyway, there's no point in adding such  * complexity.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|(
operator|(
name|defined
argument_list|(
name|JEMALLOC_PURGE_MADVISE_DONTNEED
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|JEMALLOC_PURGE_MADVISE_DONTNEED_ZEROS
argument_list|)
operator|)
operator|||
expr|\
name|defined
argument_list|(
name|JEMALLOC_MAPS_COALESCE
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|PAGES_CAN_PURGE_FORCED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|pages_can_purge_lazy
init|=
ifdef|#
directive|ifdef
name|PAGES_CAN_PURGE_LAZY
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|pages_can_purge_forced
init|=
ifdef|#
directive|ifdef
name|PAGES_CAN_PURGE_FORCED
name|true
else|#
directive|else
name|false
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|pages_map
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
modifier|*
name|commit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pages_unmap
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|pages_commit
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|pages_decommit
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|pages_purge_lazy
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|pages_purge_forced
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|pages_huge
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|pages_nohuge
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|pages_boot
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
comment|/* JEMALLOC_INTERNAL_PAGES_EXTERNS_H */
end_comment

end_unit

