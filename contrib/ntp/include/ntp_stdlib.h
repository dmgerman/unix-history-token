begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_stdlib.h - Prototypes for NTP lib.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_include
include|#
directive|include
file|"ntp_string.h"
end_include

begin_include
include|#
directive|include
file|"l_stdlib.h"
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_STDARG_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_decl_stmt
specifier|extern
name|void
name|msyslog
name|P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|__format__
argument_list|(
name|__printf__
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_decl_stmt
specifier|extern
name|void
name|msyslog
name|P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* HMS: These seem to be unused now */
end_comment

begin_endif
unit|extern	void	auth_des	P((u_long *, u_char *)); extern	void	auth_delkeys	P((void)); extern	int	auth_parity	P((u_long *)); extern	void	auth_setkey	P((u_long, u_long *)); extern	void	auth_subkeys	P((u_long *, u_char *, u_char *));
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|auth1crypt
name|P
argument_list|(
operator|(
name|u_long
operator|,
name|u_int32
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|auth2crypt
name|P
argument_list|(
operator|(
name|u_long
operator|,
name|u_int32
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|auth_delkeys
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|auth_havekey
name|P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|authdecrypt
name|P
argument_list|(
operator|(
name|u_long
operator|,
name|u_int32
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|authencrypt
name|P
argument_list|(
operator|(
name|u_long
operator|,
name|u_int32
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|authhavekey
name|P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|authistrusted
name|P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|authreadkeys
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|authtrust
name|P
argument_list|(
operator|(
name|u_long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|authusekey
name|P
argument_list|(
operator|(
name|u_long
operator|,
name|int
operator|,
specifier|const
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|calleapwhen
name|P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|calyearstart
name|P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|clockname
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|clocktime
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|u_long
operator|,
name|u_long
operator|*
operator|,
name|u_int32
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
name|SYS_WINNT
operator|&&
name|defined
name|DEBUG
end_if

begin_define
define|#
directive|define
name|emalloc
parameter_list|(
name|_c
parameter_list|)
value|debug_emalloc(_c, __FILE__, __LINE__)
end_define

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|debug_emalloc
name|P
argument_list|(
operator|(
name|u_int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|emalloc
name|P
argument_list|(
operator|(
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|ntp_getopt
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_auth
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_lib
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_random
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|savekey
modifier|*
name|auth_findkey
name|P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|auth_moremem
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ymd2yd
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DES
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|DESauthdecrypt
name|P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_int32
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|DESauthencrypt
name|P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_int32
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|DESauth_setkey
name|P
argument_list|(
operator|(
name|u_long
operator|,
specifier|const
name|u_int32
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|DESauth_subkeys
name|P
argument_list|(
operator|(
specifier|const
name|u_int32
operator|*
operator|,
name|u_char
operator|*
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|DESauth_des
name|P
argument_list|(
operator|(
name|u_int32
operator|*
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|DESauth_parity
name|P
argument_list|(
operator|(
name|u_int32
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DES */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MD5
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|MD5authdecrypt
name|P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_int32
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|MD5authencrypt
name|P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_int32
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|MD5auth_setkey
name|P
argument_list|(
operator|(
name|u_long
operator|,
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|session_key
name|P
argument_list|(
operator|(
name|u_int32
operator|,
name|u_int32
operator|,
name|u_long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MD5 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|atoint
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atouint
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|u_long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hextoint
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|u_long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|humandate
name|P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|humanlogtime
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|inttoa
name|P
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mfptoa
name|P
argument_list|(
operator|(
name|u_long
operator|,
name|u_long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mfptoms
name|P
argument_list|(
operator|(
name|u_long
operator|,
name|u_long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|modetoa
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|eventstr
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ceventstr
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|statustoa
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|sysstatstr
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|peerstatstr
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|clockstatstr
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|netof
name|P
argument_list|(
operator|(
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|numtoa
name|P
argument_list|(
operator|(
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|numtohost
name|P
argument_list|(
operator|(
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|octtoint
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|u_long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|ranp2
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|refnumtoa
name|P
argument_list|(
operator|(
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tsftomsu
name|P
argument_list|(
operator|(
name|u_long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|uinttoa
name|P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|decodenetnum
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|u_int32
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|FindConfig
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|signal_no_reset
name|P
argument_list|(
operator|(
name|int
operator|,
name|RETSIGTYPE
argument_list|(
operator|*
name|func
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|getauthkeys
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|auth_agekeys
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rereadkeys
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|u_long
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
name|u_int
name|cache_keylen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* key length */
end_comment

begin_comment
comment|/* clocktypes.c */
end_comment

begin_struct_decl
struct_decl|struct
name|clktype
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|clktype
name|clktypes
index|[]
decl_stmt|;
end_decl_stmt

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
comment|/* machines.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|set_tod_using
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mexit.c */
end_comment

begin_if
if|#
directive|if
name|defined
name|SYS_WINNT
operator|||
name|defined
name|SYS_CYGWIN32
end_if

begin_decl_stmt
specifier|extern
name|HANDLE
name|hServDoneEvent
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* systime.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|systime_10ms_ticks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* adj sysclock in 10ms increments */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|sys_maxfreq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max frequency correction */
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

end_unit

