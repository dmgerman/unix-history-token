begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntpq.h - definitions of interest to ntpq  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_string.h"
end_include

begin_include
include|#
directive|include
file|"ntp_malloc.h"
end_include

begin_include
include|#
directive|include
file|"ntp_assert.h"
end_include

begin_include
include|#
directive|include
file|"ntp_control.h"
end_include

begin_include
include|#
directive|include
file|"lib_strbuf.h"
end_include

begin_comment
comment|/*  * Maximum number of arguments  */
end_comment

begin_define
define|#
directive|define
name|MAXARGS
value|4
end_define

begin_comment
comment|/*  * Limit on packets in a single response.  Increasing this value to  * 96 will marginally speed "mrulist" operation on lossless networks  * but it has been observed to cause loss on WiFi networks and with  * an IPv6 go6.net tunnel over UDP.  That loss causes the request  * row limit to be cut in half, and it grows back very slowly to  * ensure forward progress is made and loss isn't triggered too quickly  * afterward.  While the lossless case gains only marginally with  * MAXFRAGS == 96, the lossy case is a lot slower due to the repeated  * timeouts.  Empirally, MAXFRAGS == 32 avoids most of the routine loss  * on both the WiFi and UDP v6 tunnel tests and seems a good compromise.  * This suggests some device in the path has a limit of 32 ~512 byte UDP  * packets in queue.  * Lowering MAXFRAGS may help with particularly lossy networks, but some  * ntpq commands may rely on the longtime value of 24 implicitly,  * assuming a single multipacket response will be large enough for any  * needs.  In contrast, the "mrulist" command is implemented as a series  * of requests and multipacket responses to each.  */
end_comment

begin_define
define|#
directive|define
name|MAXFRAGS
value|32
end_define

begin_comment
comment|/*  * Error codes for internal use  */
end_comment

begin_define
define|#
directive|define
name|ERR_UNSPEC
value|256
end_define

begin_define
define|#
directive|define
name|ERR_INCOMPLETE
value|257
end_define

begin_define
define|#
directive|define
name|ERR_TIMEOUT
value|258
end_define

begin_define
define|#
directive|define
name|ERR_TOOMUCH
value|259
end_define

begin_comment
comment|/*  * Flags for forming descriptors.  */
end_comment

begin_define
define|#
directive|define
name|OPT
value|0x80
end_define

begin_comment
comment|/* this argument is optional, or'd with type */
end_comment

begin_define
define|#
directive|define
name|NO
value|0x0
end_define

begin_define
define|#
directive|define
name|NTP_STR
value|0x1
end_define

begin_comment
comment|/* string argument */
end_comment

begin_define
define|#
directive|define
name|NTP_UINT
value|0x2
end_define

begin_comment
comment|/* unsigned integer */
end_comment

begin_define
define|#
directive|define
name|NTP_INT
value|0x3
end_define

begin_comment
comment|/* signed integer */
end_comment

begin_define
define|#
directive|define
name|NTP_ADD
value|0x4
end_define

begin_comment
comment|/* IP network address */
end_comment

begin_define
define|#
directive|define
name|IP_VERSION
value|0x5
end_define

begin_comment
comment|/* IP version */
end_comment

begin_define
define|#
directive|define
name|NTP_ADP
value|0x6
end_define

begin_comment
comment|/* IP address and port */
end_comment

begin_define
define|#
directive|define
name|NTP_LFP
value|0x7
end_define

begin_comment
comment|/* NTP timestamp */
end_comment

begin_define
define|#
directive|define
name|NTP_MODE
value|0x8
end_define

begin_comment
comment|/* peer mode */
end_comment

begin_define
define|#
directive|define
name|NTP_2BIT
value|0x9
end_define

begin_comment
comment|/* leap bits */
end_comment

begin_comment
comment|/*  * Arguments are returned in a union  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
name|long
name|ival
decl_stmt|;
name|u_long
name|uval
decl_stmt|;
name|sockaddr_u
name|netnum
decl_stmt|;
block|}
name|arg_v
typedef|;
end_typedef

begin_comment
comment|/*  * Structure for passing parsed command line  */
end_comment

begin_struct
struct|struct
name|parse
block|{
specifier|const
name|char
modifier|*
name|keyword
decl_stmt|;
name|arg_v
name|argval
index|[
name|MAXARGS
index|]
decl_stmt|;
name|int
name|nargs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ntpdc includes a command parser which could charitably be called  * crude.  The following structure is used to define the command  * syntax.  */
end_comment

begin_struct
struct|struct
name|xcmd
block|{
specifier|const
name|char
modifier|*
name|keyword
decl_stmt|;
comment|/* command key word */
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|struct
name|parse
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
comment|/* command handler */
name|u_char
name|arg
index|[
name|MAXARGS
index|]
decl_stmt|;
comment|/* descriptors for arguments */
specifier|const
name|char
modifier|*
name|desc
index|[
name|MAXARGS
index|]
decl_stmt|;
comment|/* descriptions for arguments */
specifier|const
name|char
modifier|*
name|comment
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure to hold association data  */
end_comment

begin_struct
struct|struct
name|association
block|{
name|associd_t
name|assid
decl_stmt|;
name|u_short
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * mrulist terminal status interval  */
end_comment

begin_define
define|#
directive|define
name|MRU_REPORT_SECS
value|5
end_define

begin_comment
comment|/*  * var_format is used to override cooked formatting for selected vars.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|var_format_tag
block|{
specifier|const
name|char
modifier|*
name|varname
decl_stmt|;
name|u_short
name|fmt
decl_stmt|;
block|}
name|var_format
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|chost_tag
name|chost
typedef|;
end_typedef

begin_struct
struct|struct
name|chost_tag
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|fam
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|chost
name|chosts
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|interactive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* are we prompting? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|old_rv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use old rv behavior? --old-rv */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|assoc_cache_slots
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of allocated array entries */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|numassoc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of cached associations */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|numhosts
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|grow_assoc_cache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|asciize
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getnetnum
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|sockaddr_u
modifier|*
parameter_list|,
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
name|sortassoc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_error_msg
parameter_list|(
name|int
parameter_list|,
name|associd_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dogetassoc
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|doquery
parameter_list|(
name|int
parameter_list|,
name|associd_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|doqueryex
parameter_list|(
name|int
parameter_list|,
name|associd_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
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
name|nntohost
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
name|nntohost_col
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
name|size_t
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
name|nntohostp
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|decodets
parameter_list|(
name|char
modifier|*
parameter_list|,
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|decodeuint
parameter_list|(
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
name|nextvar
parameter_list|(
name|int
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|decodetime
parameter_list|(
name|char
modifier|*
parameter_list|,
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|printvars
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|decodeint
parameter_list|(
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
name|void
name|makeascii
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
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
name|trunc_left
parameter_list|(
specifier|const
name|char
modifier|*
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
name|trunc_right
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

