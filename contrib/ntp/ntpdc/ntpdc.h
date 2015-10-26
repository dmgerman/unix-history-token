begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntpdc.h - definitions of interest to ntpdc  */
end_comment

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
file|"ntp_request.h"
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

begin_comment
comment|/*  * Maximum number of arguments  */
end_comment

begin_define
define|#
directive|define
name|MAXARGS
value|4
end_define

begin_define
define|#
directive|define
name|MOREARGS
value|10
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

begin_comment
comment|/*  * Arguments are returned in a struct - no  * union space saving is attempted.   */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|type
decl_stmt|;
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
name|char
modifier|*
name|keyword
decl_stmt|;
name|arg_v
name|argval
index|[
name|MAXARGS
operator|+
name|MOREARGS
index|]
decl_stmt|;
name|size_t
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

begin_decl_stmt
specifier|extern
name|int
name|impl_ver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|showhostnames
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|s_port
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|doquery
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
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
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

end_unit

