begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__unused
end_ifndef

begin_define
define|#
directive|define
name|__unused
value|__attribute__((__unused__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__dead
end_ifndef

begin_define
define|#
directive|define
name|__dead
value|__attribute__((__noreturn__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__RCSID
end_ifndef

begin_define
define|#
directive|define
name|__RCSID
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__UNCONST
end_ifndef

begin_define
define|#
directive|define
name|__UNCONST
parameter_list|(
name|a
parameter_list|)
value|((void *)(intptr_t)(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__arraycount
end_ifndef

begin_define
define|#
directive|define
name|__arraycount
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a) / sizeof(a[0]))
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
name|HAVE_STRLCAT
end_ifndef

begin_function_decl
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
name|HAVE_POPENVE
end_ifndef

begin_function_decl
name|FILE
modifier|*
name|popenve
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcloseve
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|pclose
parameter_list|(
name|a
parameter_list|)
value|pcloseve(a);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SOCKADDR_SNPRINTF
end_ifndef

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|sockaddr_snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|sockaddr
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
name|HAVE_STRTOI
end_ifndef

begin_function_decl
name|intmax_t
name|strtoi
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|intmax_t
parameter_list|,
name|intmax_t
parameter_list|,
name|int
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

begin_function_decl
name|void
name|setprogname
parameter_list|(
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
name|HAVE_PIDFILE
end_ifndef

begin_function_decl
name|int
name|pidfile
parameter_list|(
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
name|HAVE_FPARSELN
end_ifndef

begin_define
define|#
directive|define
name|FPARSELN_UNESCALL
value|0xf
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCCOMM
value|0x1
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCCONT
value|0x2
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCESC
value|0x4
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCREST
value|0x8
end_define

begin_function_decl
name|char
modifier|*
name|fparseln
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
specifier|const
name|char
name|delim
index|[
literal|3
index|]
parameter_list|,
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
name|HAVE_FGETLN
end_ifndef

begin_function_decl
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
name|HAVE_CLOCK_GETTIME
end_ifndef

begin_struct_decl
struct_decl|struct
name|timespec
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|clock_gettime
parameter_list|(
name|int
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CLOCK_REALTIME
value|0
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
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_BLCONF
value|"conf"
end_define

begin_define
define|#
directive|define
name|_PATH_BLCONTROL
value|"control"
end_define

begin_define
define|#
directive|define
name|_PATH_BLSOCK
value|"blacklistd.sock"
end_define

begin_define
define|#
directive|define
name|_PATH_BLSTATE
value|"blacklistd.db"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

