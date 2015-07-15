begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*****************************************************************************  *  *  libntpq.h  *  *  This is the wrapper library for ntpq, the NTP query utility.   *  This library reuses the sourcecode from ntpq and exports a number  *  of useful functions in a library that can be linked against applications  *  that need to query the status of a running ntpd. The whole   *  communcation is based on mode 6 packets.  *  * This header file can be used in applications that want to link against   * libntpq.  *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"ntp_net.h"
end_include

begin_comment
comment|/* general purpose buffer size */
end_comment

begin_define
define|#
directive|define
name|NTPQ_BUFLEN
value|2048
end_define

begin_comment
comment|/* max. number of associations */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXASSOC
end_ifndef

begin_define
define|#
directive|define
name|MAXASSOC
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* general purpose max array size definition */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXLIST
end_ifndef

begin_define
define|#
directive|define
name|MAXLIST
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LENHOSTNAME
end_ifndef

begin_define
define|#
directive|define
name|LENHOSTNAME
value|256
end_define

begin_comment
comment|/* host name is max. 256 characters long */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP Status codes */
end_comment

begin_define
define|#
directive|define
name|NTP_STATUS_INVALID
value|0
end_define

begin_define
define|#
directive|define
name|NTP_STATUS_FALSETICKER
value|1
end_define

begin_define
define|#
directive|define
name|NTP_STATUS_EXCESS
value|2
end_define

begin_define
define|#
directive|define
name|NTP_STATUS_OUTLYER
value|3
end_define

begin_define
define|#
directive|define
name|NTP_STATUS_CANDIDATE
value|4
end_define

begin_define
define|#
directive|define
name|NTP_STATUS_SELECTED
value|5
end_define

begin_define
define|#
directive|define
name|NTP_STATUS_SYSPEER
value|6
end_define

begin_define
define|#
directive|define
name|NTP_STATUS_PPSPEER
value|7
end_define

begin_comment
comment|/* NTP association type identifier */
end_comment

begin_define
define|#
directive|define
name|NTP_CLOCKTYPE_UNKNOWN
value|'-'
end_define

begin_define
define|#
directive|define
name|NTP_CLOCKTYPE_BROADCAST
value|'b'
end_define

begin_define
define|#
directive|define
name|NTP_CLOCKTYPE_LOCAL
value|'l'
end_define

begin_define
define|#
directive|define
name|NTP_CLOCKTYPE_UNICAST
value|'u'
end_define

begin_define
define|#
directive|define
name|NTP_CLOCKTYPE_MULTICAST
value|'m'
end_define

begin_comment
comment|/* Variable Sets */
end_comment

begin_define
define|#
directive|define
name|PEERVARS
value|CTL_OP_READVAR
end_define

begin_define
define|#
directive|define
name|CLOCKVARS
value|CTL_OP_CLOCKVAR
end_define

begin_comment
comment|/* Variable list struct */
end_comment

begin_struct
struct|struct
name|ntpq_varlist
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* global variables used for holding snapshots of data */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBNTPQ_C
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|peervars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|peervarlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|peervar_assoc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|clockvars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|clockvarlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|clockvar_assoc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|sysvars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sysvarlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ntpq_resultbuffer
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ntpq_varlist
name|ntpq_varlist
index|[
name|MAXLIST
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * Prototypes of exported libary functions  */
end_comment

begin_comment
comment|/* from libntpq.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|ntpq_openhost
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_closehost
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_queryhost
parameter_list|(
name|unsigned
name|short
name|VARSET
parameter_list|,
name|associd_t
name|association
parameter_list|,
name|char
modifier|*
name|resultbuf
parameter_list|,
name|int
name|maxlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|ntpq_getvar
parameter_list|(
specifier|const
name|char
modifier|*
name|resultbuf
parameter_list|,
name|size_t
name|datalen
parameter_list|,
specifier|const
name|char
modifier|*
name|varname
parameter_list|,
name|char
modifier|*
name|varvalue
parameter_list|,
name|size_t
name|maxlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_stripquotes
parameter_list|(
name|char
modifier|*
name|resultbuf
parameter_list|,
name|char
modifier|*
name|srcbuf
parameter_list|,
name|int
name|datalen
parameter_list|,
name|int
name|maxlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_queryhost_peervars
parameter_list|(
name|associd_t
name|association
parameter_list|,
name|char
modifier|*
name|resultbuf
parameter_list|,
name|int
name|maxlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_get_peervar
parameter_list|(
specifier|const
name|char
modifier|*
name|varname
parameter_list|,
name|char
modifier|*
name|varvalue
parameter_list|,
name|int
name|maxlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|ntpq_read_sysvars
parameter_list|(
name|char
modifier|*
name|resultbuf
parameter_list|,
name|size_t
name|maxsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_get_sysvars
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_read_associations
parameter_list|(
name|unsigned
name|short
name|resultbuf
index|[]
parameter_list|,
name|int
name|max_entries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_get_assocs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_get_assoc_number
parameter_list|(
name|associd_t
name|associd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_get_assoc_peervars
parameter_list|(
name|associd_t
name|associd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_get_assoc_clockvars
parameter_list|(
name|associd_t
name|associd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_get_assoc_allvars
parameter_list|(
name|associd_t
name|associd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_get_assoc_clocktype
parameter_list|(
name|int
name|assoc_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_read_assoc_peervars
parameter_list|(
name|associd_t
name|associd
parameter_list|,
name|char
modifier|*
name|resultbuf
parameter_list|,
name|int
name|maxsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_read_assoc_clockvars
parameter_list|(
name|associd_t
name|associd
parameter_list|,
name|char
modifier|*
name|resultbuf
parameter_list|,
name|int
name|maxsize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in libntpq_subs.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|ntpq_dogetassoc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
name|ntpq_decodeaddrtype
parameter_list|(
name|sockaddr_u
modifier|*
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntpq_doquerylist
parameter_list|(
name|struct
name|ntpq_varlist
modifier|*
parameter_list|,
name|int
parameter_list|,
name|associd_t
parameter_list|,
name|int
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
name|datap
parameter_list|)
function_decl|;
end_function_decl

end_unit

