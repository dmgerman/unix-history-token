begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|MANDOC_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|MANDOC_CONFIG_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MINT__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_comment
comment|/* getsubopt(), strcasestr(), strptime() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|VERSION
value|"1.13.1"
end_define

begin_define
define|#
directive|define
name|HAVE_FGETLN
end_define

begin_define
define|#
directive|define
name|HAVE_GETSUBOPT
end_define

begin_define
define|#
directive|define
name|HAVE_MMAP
end_define

begin_define
define|#
directive|define
name|HAVE_STRCASESTR
end_define

begin_define
define|#
directive|define
name|HAVE_STRLCAT
end_define

begin_define
define|#
directive|define
name|HAVE_STRLCPY
end_define

begin_define
define|#
directive|define
name|HAVE_STRPTIME
end_define

begin_define
define|#
directive|define
name|HAVE_STRSEP
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__BEGIN_DECLS
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|__BEGIN_DECLS
value|extern "C" {
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__BEGIN_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|__END_DECLS
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|__END_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__END_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FGETLN
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|fgetln
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|size_t
modifier|*
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
name|HAVE_GETSUBOPT
end_ifndef

begin_function_decl
specifier|extern
name|int
name|getsubopt
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|suboptarg
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_REALLOCARRAY
end_ifndef

begin_function_decl
specifier|extern
name|void
modifier|*
name|reallocarray
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
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
name|HAVE_SQLITE3_ERRSTR
end_ifndef

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|sqlite3_errstr
parameter_list|(
name|int
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
name|HAVE_STRCASESTR
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcasestr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
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
name|HAVE_STRLCAT
end_ifndef

begin_function_decl
specifier|extern
name|size_t
name|strlcat
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
name|HAVE_STRLCPY
end_ifndef

begin_function_decl
specifier|extern
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
name|HAVE_STRSEP
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strsep
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
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
comment|/* MANDOC_CONFIG_H */
end_comment

end_unit

