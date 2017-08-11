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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
operator|(
name|__GNUC__
operator|<
literal|4
operator|)
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|MAN_CONF_FILE
value|"/etc/man.conf"
end_define

begin_define
define|#
directive|define
name|MANPATH_BASE
value|"/usr/share/man"
end_define

begin_define
define|#
directive|define
name|MANPATH_DEFAULT
value|"/usr/share/man:/usr/local/man"
end_define

begin_define
define|#
directive|define
name|UTF8_LOCALE
value|"en_US.UTF-8"
end_define

begin_define
define|#
directive|define
name|HAVE_CMSG_XPG42
value|0
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
name|HAVE_ENDIAN
value|0
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
name|HAVE_FTS_COMPARE_CONST
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_GETLINE
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
name|HAVE_NTOHL
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
name|HAVE_RECALLOCARRAY
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_REWB_BSD
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_REWB_SYSV
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SANDBOX_INIT
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
name|HAVE_STRTONUM
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_ENDIAN
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
name|HAVE_OHASH
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
name|void
modifier|*
name|recallocarray
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

