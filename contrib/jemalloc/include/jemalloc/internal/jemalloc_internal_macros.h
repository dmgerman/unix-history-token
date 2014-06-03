begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * JEMALLOC_ALWAYS_INLINE and JEMALLOC_INLINE are used within header files for  * functions that are static inline functions if inlining is enabled, and  * single-definition library-private functions if inlining is disabled.  *  * JEMALLOC_ALWAYS_INLINE_C and JEMALLOC_INLINE_C are for use in .c files, in  * which case the denoted functions are always static, regardless of whether  * inlining is enabled.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|JEMALLOC_DEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|JEMALLOC_CODE_COVERAGE
argument_list|)
end_if

begin_comment
comment|/* Disable inlining to make debugging/profiling easier. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_ALWAYS_INLINE
end_define

begin_define
define|#
directive|define
name|JEMALLOC_ALWAYS_INLINE_C
value|static
end_define

begin_define
define|#
directive|define
name|JEMALLOC_INLINE
end_define

begin_define
define|#
directive|define
name|JEMALLOC_INLINE_C
value|static
end_define

begin_define
define|#
directive|define
name|inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JEMALLOC_ENABLE_INLINE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_HAVE_ATTR
end_ifdef

begin_define
define|#
directive|define
name|JEMALLOC_ALWAYS_INLINE
define|\
value|static inline JEMALLOC_ATTR(unused) JEMALLOC_ATTR(always_inline)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_ALWAYS_INLINE_C
define|\
value|static inline JEMALLOC_ATTR(always_inline)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JEMALLOC_ALWAYS_INLINE
value|static inline
end_define

begin_define
define|#
directive|define
name|JEMALLOC_ALWAYS_INLINE_C
value|static inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|JEMALLOC_INLINE
value|static inline
end_define

begin_define
define|#
directive|define
name|JEMALLOC_INLINE_C
value|static inline
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|inline
value|_inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_CC_SILENCE
end_ifdef

begin_define
define|#
directive|define
name|UNUSED
value|JEMALLOC_ATTR(unused)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNUSED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ZU
parameter_list|(
name|z
parameter_list|)
value|((size_t)z)
end_define

begin_define
define|#
directive|define
name|QU
parameter_list|(
name|q
parameter_list|)
value|((uint64_t)q)
end_define

begin_define
define|#
directive|define
name|QI
parameter_list|(
name|q
parameter_list|)
value|((int64_t)q)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__DECONST
end_ifndef

begin_define
define|#
directive|define
name|__DECONST
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|)
value|((type)(uintptr_t)(const void *)(var))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_HAS_RESTRICT
end_ifndef

begin_define
define|#
directive|define
name|restrict
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

