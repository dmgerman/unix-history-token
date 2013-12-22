begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|STDINT_H
end_ifndef

begin_define
define|#
directive|define
name|STDINT_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__INT32_TYPE__
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|__INT32_TYPE__
name|uint32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__INT64_TYPE__
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|__INT64_TYPE__
name|uint64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__INTPTR_TYPE__
end_ifdef

begin_typedef
typedef|typedef
name|__INTPTR_TYPE__
name|intptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__INTPTR_TYPE__
name|uintptr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Every target should have __INTPTR_TYPE__
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STDINT_H */
end_comment

end_unit

