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
file|"l_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_rfc2553.h"
end_include

begin_include
include|#
directive|include
file|"ntp_types.h"
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
file|"ntp_net.h"
end_include

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_comment
comment|/*  * Handle gcc __attribute__ if available.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_comment
comment|/* This feature is available in gcc versions 2.5 and later.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|5
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|Spec
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The __-protected variants of `format' and `printf' attributes    are accepted by gcc versions 2.6.4 (effectively 2.7) and later.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|7
operator|)
end_if

begin_define
define|#
directive|define
name|__format__
value|format
end_define

begin_define
define|#
directive|define
name|__printf__
value|printf
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
name|int
name|mprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
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
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
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
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
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
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
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
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
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
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

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

begin_function_decl
specifier|extern
name|u_long
name|calyearstart
parameter_list|(
name|u_long
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
name|u_long
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
name|int
name|auth_moremem
parameter_list|(
name|void
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
specifier|const
name|int
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

begin_function_decl
specifier|extern
name|void
modifier|*
name|emalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

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
name|char
modifier|*
name|inttoa
parameter_list|(
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mfptoa
parameter_list|(
name|u_long
parameter_list|,
name|u_long
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
name|u_long
parameter_list|,
name|u_long
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
name|int
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
specifier|const
name|char
modifier|*
name|sysstatstr
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
name|peerstatstr
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
name|clockstatstr
parameter_list|(
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
name|int
name|tsftomsu
parameter_list|(
name|u_long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|uinttoa
parameter_list|(
name|u_long
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
comment|/*  * Defined by any program.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugging flag */
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
name|u_char
modifier|*
name|cache_key
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* key pointer */
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
name|u_int
name|cache_keylen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* key length */
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
comment|/* adjtime() resolution */
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

