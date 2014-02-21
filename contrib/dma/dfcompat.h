begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|DFCOMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|DFCOMPAT_H
end_define

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
name|HAVE_STRLCPY
end_ifndef

begin_function_decl
name|size_t
name|strlcpy
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_REALLOCF
end_ifndef

begin_function_decl
name|void
modifier|*
name|reallocf
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETPROGNAME
end_ifndef

begin_function_decl
specifier|const
name|char
modifier|*
name|getprogname
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DFCOMPAT_H */
end_comment

end_unit

