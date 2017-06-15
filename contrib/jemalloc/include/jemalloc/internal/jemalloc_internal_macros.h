begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_MACROS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_MACROS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|JEMALLOC_ALWAYS_INLINE
value|static inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JEMALLOC_ALWAYS_INLINE
value|JEMALLOC_ATTR(always_inline) static inline
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|UNUSED
value|JEMALLOC_ATTR(unused)
end_define

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
name|ZD
parameter_list|(
name|z
parameter_list|)
value|((ssize_t)z)
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
name|QD
parameter_list|(
name|q
parameter_list|)
value|((int64_t)q)
end_define

begin_define
define|#
directive|define
name|KZU
parameter_list|(
name|z
parameter_list|)
value|ZU(z##ULL)
end_define

begin_define
define|#
directive|define
name|KZD
parameter_list|(
name|z
parameter_list|)
value|ZD(z##LL)
end_define

begin_define
define|#
directive|define
name|KQU
parameter_list|(
name|q
parameter_list|)
value|QU(q##ULL)
end_define

begin_define
define|#
directive|define
name|KQD
parameter_list|(
name|q
parameter_list|)
value|QI(q##LL)
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|JEMALLOC_HAS_RESTRICT
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|restrict
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Various function pointers are statick and immutable except during testing. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_define
define|#
directive|define
name|JET_MUTABLE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JET_MUTABLE
value|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_MACROS_H */
end_comment

end_unit

