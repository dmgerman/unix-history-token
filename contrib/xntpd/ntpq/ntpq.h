begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ntpq.h,v 3.1 1993/07/06 01:09:30 jbj Exp  * ntpq.h - definitions of interest to ntpq  */
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
file|"ntp_control.h"
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
name|STR
value|0x1
end_define

begin_comment
comment|/* string argument */
end_comment

begin_define
define|#
directive|define
name|UINT
value|0x2
end_define

begin_comment
comment|/* unsigned integer */
end_comment

begin_define
define|#
directive|define
name|INT
value|0x3
end_define

begin_comment
comment|/* signed integer */
end_comment

begin_define
define|#
directive|define
name|ADD
value|0x4
end_define

begin_comment
comment|/* IP network address */
end_comment

begin_comment
comment|/*  * Arguments are returned in a union  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|char
modifier|*
name|string
decl_stmt|;
name|LONG
name|ival
decl_stmt|;
name|U_LONG
name|uval
decl_stmt|;
name|U_LONG
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
index|]
decl_stmt|;
name|int
name|nargs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * xntpdc includes a command parser which could charitably be called  * crude.  The following structure is used to define the command  * syntax.  */
end_comment

begin_struct
struct|struct
name|xcmd
block|{
name|char
modifier|*
name|keyword
decl_stmt|;
comment|/* command key word */
name|void
argument_list|(
argument|*handler
argument_list|)
name|P
argument_list|(
operator|(
expr|struct
name|parse
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* command handler */
name|u_char
name|arg
index|[
name|MAXARGS
index|]
decl_stmt|;
comment|/* descriptors for arguments */
name|char
modifier|*
name|desc
index|[
name|MAXARGS
index|]
decl_stmt|;
comment|/* descriptions for arguments */
name|char
modifier|*
name|comment
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Types of things we may deal with  */
end_comment

begin_define
define|#
directive|define
name|TYPE_SYS
value|1
end_define

begin_define
define|#
directive|define
name|TYPE_PEER
value|2
end_define

begin_define
define|#
directive|define
name|TYPE_CLOCK
value|3
end_define

begin_comment
comment|/*  * Structure to hold association data  */
end_comment

begin_struct
struct|struct
name|association
block|{
name|u_short
name|assid
decl_stmt|;
name|u_short
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXASSOC
value|1024
end_define

begin_comment
comment|/*  * Structure for translation tables between text format  * variable indices and text format.  */
end_comment

begin_struct
struct|struct
name|ctl_var
block|{
name|u_short
name|code
decl_stmt|;
name|u_short
name|fmt
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|void
name|asciize
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getnetnum
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|U_LONG
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sortassoc
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
name|doquery
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
name|char
operator|*
operator|,
name|u_short
operator|*
operator|,
name|int
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|nntohost
name|P
argument_list|(
operator|(
name|U_LONG
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|decodets
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|decodeuint
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|U_LONG
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nextvar
name|P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|decodetime
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|printvars
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|decodeint
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|LONG
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|findvar
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|ctl_var
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

