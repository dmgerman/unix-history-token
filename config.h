begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_error
error|#
directive|error
literal|"Do not use C++.  See the INSTALL file."
end_error

begin_endif
endif|#
directive|endif
end_endif

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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|MAN_CONF_FILE
value|"/etc/man.conf"
end_define

begin_define
define|#
directive|define
name|MANPATH_DEFAULT
value|"/usr/share/man:/usr/X11R6/man:/usr/local/man"
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
name|HAVE_ERR
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
name|HAVE_GETLINE
value|0
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
name|HAVE_ISBLANK
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_MKDTEMP
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
name|HAVE_PLEDGE
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_PROGNAME
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_REALLOCARRAY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_REWB_BSD
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_REWB_SYSV
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
name|HAVE_STRINGLIST
value|0
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
name|HAVE_STRTONUM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VASPRINTF
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
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_MANPATH
value|1
end_define

begin_define
define|#
directive|define
name|BINM_APROPOS
value|"apropos"
end_define

begin_define
define|#
directive|define
name|BINM_MAKEWHATIS
value|"makewhatis"
end_define

begin_define
define|#
directive|define
name|BINM_MAN
value|"man"
end_define

begin_define
define|#
directive|define
name|BINM_SOELIM
value|"soelim"
end_define

begin_define
define|#
directive|define
name|BINM_WHATIS
value|"whatis"
end_define

begin_function_decl
specifier|extern
name|ssize_t
name|getline
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|FILE
modifier|*
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

