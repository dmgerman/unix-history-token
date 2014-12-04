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
comment|/* See test-*.c what needs this. */
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

begin_define
define|#
directive|define
name|VERSION
value|"1.13.1"
end_define

begin_define
define|#
directive|define
name|HAVE_DIRENT_NAMLEN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FGETLN
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FTS
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETSUBOPT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MMAP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_REALLOCARRAY
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_STRCASESTR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRLCAT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRPTIME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRSEP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_WCHAR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SQLITE3
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SQLITE3_ERRSTR
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_OHASH
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MANPATH
value|1
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

begin_comment
comment|/* MANDOC_CONFIG_H */
end_comment

end_unit

