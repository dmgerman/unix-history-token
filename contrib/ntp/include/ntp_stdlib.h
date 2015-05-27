begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_stdlib.h - Prototypes for NTP lib.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_STDLIB_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_STDLIB_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"declcond.h"
end_include

begin_comment
comment|/* ntpd uses ntpd/declcond.h, others include/ */
end_comment

begin_include
include|#
directive|include
file|"l_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_net.h"
end_include

begin_include
include|#
directive|include
file|"ntp_debug.h"
end_include

begin_include
include|#
directive|include
file|"ntp_malloc.h"
end_include

begin_include
include|#
directive|include
file|"ntp_string.h"
end_include

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|NTP_PRINTF
parameter_list|(
name|fmt
parameter_list|,
name|args
parameter_list|)
value|__attribute__((__format__(__printf__, fmt, args)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NTP_PRINTF
parameter_list|(
name|fmt
parameter_list|,
name|args
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|mprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|NTP_PRINTF
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|mfprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|NTP_PRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|mvfprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|NTP_PRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|mvsnprintf
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
name|va_list
parameter_list|)
function_decl|NTP_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|msnprintf
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
modifier|...
parameter_list|)
function_decl|NTP_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|msyslog
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|NTP_PRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|init_logging
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int32
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|change_logfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setup_logfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|errno_to_str
end_ifndef

begin_function_decl
specifier|extern
name|void
name|errno_to_str
parameter_list|(
name|int
parameter_list|,
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

begin_comment
comment|/*  * When building without OpenSSL, use a few macros of theirs to  * minimize source differences in NTP.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL
end_ifndef

begin_define
define|#
directive|define
name|NID_md5
value|4
end_define

begin_comment
comment|/* from openssl/objects.h */
end_comment

begin_comment
comment|/* from openssl/evp.h */
end_comment

begin_define
define|#
directive|define
name|EVP_MAX_MD_SIZE
value|64
end_define

begin_comment
comment|/* longest known is SHA512 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SAVE_ERRNO
parameter_list|(
name|stmt
parameter_list|)
define|\
value|{						\ 		int preserved_errno;			\ 							\ 		preserved_errno = socket_errno();	\ 		{					\ 			stmt				\ 		}					\ 		errno = preserved_errno;		\ 	}
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ctrl_c_fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* authkeys.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|auth_delkeys
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|auth_havekey
parameter_list|(
name|keyid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|authdecrypt
parameter_list|(
name|keyid_t
parameter_list|,
name|u_int32
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|authencrypt
parameter_list|(
name|keyid_t
parameter_list|,
name|u_int32
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|authhavekey
parameter_list|(
name|keyid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|authistrusted
parameter_list|(
name|keyid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|authreadkeys
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|authtrust
parameter_list|(
name|keyid_t
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|authusekey
parameter_list|(
name|keyid_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Based on the NTP timestamp, calculate the NTP timestamp of  * the corresponding calendar unit. Use the pivot time to unfold  * the NTP timestamp properly, or the current system time if the  * pivot pointer is NULL.  */
end_comment

begin_function_decl
specifier|extern
name|u_int32
name|calyearstart
parameter_list|(
name|u_int32
name|ntptime
parameter_list|,
specifier|const
name|time_t
modifier|*
name|pivot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32
name|calmonthstart
parameter_list|(
name|u_int32
name|ntptime
parameter_list|,
specifier|const
name|time_t
modifier|*
name|pivot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32
name|calweekstart
parameter_list|(
name|u_int32
name|ntptime
parameter_list|,
specifier|const
name|time_t
modifier|*
name|pivot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32
name|caldaystart
parameter_list|(
name|u_int32
name|ntptime
parameter_list|,
specifier|const
name|time_t
modifier|*
name|pivot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|clockname
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|clocktime
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int32
parameter_list|,
name|u_long
modifier|*
parameter_list|,
name|u_int32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntp_getopt
parameter_list|(
name|int
parameter_list|,
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

begin_function_decl
specifier|extern
name|void
name|init_auth
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_lib
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|savekey
modifier|*
name|auth_findkey
parameter_list|(
name|keyid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|auth_moremem
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|auth_prealloc_symkeys
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ymd2yd
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* a_md5encrypt.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|MD5authdecrypt
parameter_list|(
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int32
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|MD5authencrypt
parameter_list|(
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int32
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MD5auth_setkey
parameter_list|(
name|keyid_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32
name|addr2refid
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* emalloc.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EREALLOC_CALLSITE
end_ifndef

begin_comment
comment|/* ntp_malloc.h defines */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|ereallocz
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|erealloczsite
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|,
name|o
parameter_list|,
name|z
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
value|ereallocz(p, n, o, (z))
end_define

begin_define
define|#
directive|define
name|emalloc
parameter_list|(
name|n
parameter_list|)
value|ereallocz(NULL, n, 0, FALSE)
end_define

begin_define
define|#
directive|define
name|emalloc_zero
parameter_list|(
name|c
parameter_list|)
value|ereallocz(NULL, (c), 0, TRUE)
end_define

begin_define
define|#
directive|define
name|erealloc
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|ereallocz(p, (c), 0, FALSE)
end_define

begin_define
define|#
directive|define
name|erealloc_zero
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|,
name|o
parameter_list|)
value|ereallocz(p, n, (o), TRUE)
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|estrdup_impl
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|estrdup
parameter_list|(
name|s
parameter_list|)
value|estrdup_impl(s)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
modifier|*
name|ereallocz
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|erealloczsite
value|ereallocz
end_define

begin_define
define|#
directive|define
name|emalloc
parameter_list|(
name|c
parameter_list|)
value|ereallocz(NULL, (c), 0, FALSE, \ 					  __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|emalloc_zero
parameter_list|(
name|c
parameter_list|)
value|ereallocz(NULL, (c), 0, TRUE, \ 					  __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|erealloc
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|ereallocz(p, (c), 0, FALSE, \ 					  __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|erealloc_zero
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|,
name|o
parameter_list|)
value|ereallocz(p, n, (o), TRUE, \ 					  __FILE__, __LINE__)
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|estrdup_impl
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|estrdup
parameter_list|(
name|s
parameter_list|)
value|estrdup_impl((s), __FILE__, __LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|atoint
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|atouint
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hextoint
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|humanlogtime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|humantime
parameter_list|(
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mfptoa
parameter_list|(
name|u_int32
parameter_list|,
name|u_int32
parameter_list|,
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mfptoms
parameter_list|(
name|u_int32
parameter_list|,
name|u_int32
parameter_list|,
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|modetoa
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|eventstr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|ceventstr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|res_match_flags
parameter_list|(
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|res_access_flags
parameter_list|(
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_PLL
end_ifdef

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|k_st_flags
parameter_list|(
name|u_int32
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|statustoa
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sockaddr_u
modifier|*
name|netof
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|numtoa
parameter_list|(
name|u_int32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|numtohost
parameter_list|(
name|u_int32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|socktoa
parameter_list|(
specifier|const
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|sockporttoa
parameter_list|(
specifier|const
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_short
name|sock_hash
parameter_list|(
specifier|const
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sockaddr_masktoprefixlen
parameter_list|(
specifier|const
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|socktohost
parameter_list|(
specifier|const
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|octtoint
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|ranp2
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|refnumtoa
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|refid_str
parameter_list|(
name|u_int32
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|decodenetnum
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|FindConfig
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|signal_no_reset
parameter_list|(
name|int
parameter_list|,
name|RETSIGTYPE
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_ctrl_c_hook
parameter_list|(
name|ctrl_c_fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|getauthkeys
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|auth_agekeys
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rereadkeys
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Variable declarations for libntp.  */
end_comment

begin_comment
comment|/* authkeys.c */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|authkeynotfound
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keys not found */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|authkeylookups
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* calls to lookup keys */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|authnumkeys
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of active keys */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|authkeyexpired
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* key lifetime expirations */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|authkeyuncached
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cache misses */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|authencryptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* calls to encrypt */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|authdecryptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* calls to decrypt */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|authnumfreekeys
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The key cache. We cache the last key we looked at here.  */
end_comment

begin_decl_stmt
specifier|extern
name|keyid_t
name|cache_keyid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* key identifier */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cache_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* key type */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
modifier|*
name|cache_secret
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* secret */
end_comment

begin_decl_stmt
specifier|extern
name|u_short
name|cache_secretsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* secret octets */
end_comment

begin_decl_stmt
specifier|extern
name|u_short
name|cache_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* KEY_ bit flags */
end_comment

begin_comment
comment|/* getopt.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ntp_optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global argument pointer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ntp_optind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global argv index */
end_comment

begin_comment
comment|/* lib_strbuf.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ipv4_works
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipv6_works
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* machines.c */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|pset_tod_using
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|pset_tod_using
name|set_tod_using
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ssl_init.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_function_decl
specifier|extern
name|void
name|ssl_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ssl_check_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|ssl_init_done
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INIT_SSL
parameter_list|()
define|\
value|do {					\ 		if (!ssl_init_done)		\ 			ssl_init();		\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !OPENSSL follows */
end_comment

begin_define
define|#
directive|define
name|INIT_SSL
parameter_list|()
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|keytype_from_text
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|keytype_name
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getpass_keytype
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* strl-obsd.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRLCPY
end_ifndef

begin_comment
comment|/* + */
end_comment

begin_comment
comment|/*  * Copy src to string dst of size siz.  At most siz-1 characters  * will be copied.  Always NUL terminates (unless siz == 0).  * Returns strlen(src); if retval>= siz, truncation occurred.  */
end_comment

begin_function_decl
specifier|extern
name|size_t
name|strlcpy
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|siz
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

begin_comment
comment|/* + */
end_comment

begin_comment
comment|/*  * Appends src to string dst of size siz (unlike strncat, siz is the  * full size of dst, not space left).  At most siz-1 characters  * will be copied.  Always NUL terminates (unless siz<= strlen(dst)).  * Returns strlen(src) + MIN(siz, strlen(initial dst)).  * If retval>= siz, truncation occurred.  */
end_comment

begin_function_decl
specifier|extern
name|size_t
name|strlcat
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|siz
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lib/isc/win32/strerror.c  *  * To minimize Windows-specific changes to the rest of the NTP code,  * particularly reference clocks, we hijack calls to strerror() to deal  * with our mixture of error codes from the  C runtime (open, write)  * and Windows (sockets, serial ports).  This is an ugly hack because  * both use the lowest values differently, but particularly for ntpd,  * it's not a problem.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NTP_REDEFINE_STRERROR
end_ifdef

begin_define
define|#
directive|define
name|strerror
parameter_list|(
name|e
parameter_list|)
value|ntp_strerror(e)
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|ntp_strerror
parameter_list|(
name|int
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* systime.c */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|sys_tick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tick size or time to read */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|measured_tick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* non-overridable sys_tick */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|sys_fuzz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* min clock read latency */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|trunc_os_clock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sys_tick> measured_tick */
end_comment

begin_comment
comment|/* version.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|Version
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* version declaration */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_STDLIB_H */
end_comment

end_unit

