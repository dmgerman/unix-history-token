begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tailor.h - ISODE tailoring */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/tailor.h,v 7.3 91/02/22 09:25:12 mrose Interim $  *  *  * $Log:	tailor.h,v $  * Revision 7.3  91/02/22  09:25:12  mrose  * Interim 6.8  *   * Revision 7.2  90/11/21  11:35:51  mrose  * update  *   * Revision 7.1  90/07/09  14:38:07  mrose  * sync  *   * Revision 7.0  89/11/23  21:56:05  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TAILOR_
end_ifndef

begin_define
define|#
directive|define
name|_TAILOR_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_LOGGER_
end_ifndef

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSTEM AREAS */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|isodename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|isodebinpath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|isodesbinpath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|isodetcpath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|isodelogpath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* LOGGING */
end_comment

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|compat_log
decl_stmt|,
name|_compat_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|addr_log
decl_stmt|,
name|_addr_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|tsap_log
decl_stmt|,
name|_tsap_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|ssap_log
decl_stmt|,
name|_ssap_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|psap_log
decl_stmt|,
name|_psap_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|psap2_log
decl_stmt|,
name|_psap2_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|acsap_log
decl_stmt|,
name|_acsap_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|rtsap_log
decl_stmt|,
name|_rtsap_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|rosap_log
decl_stmt|,
name|_rosap_log
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRANSPORT-SWITCH */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ts_stacks
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TS_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|TS_TCP
value|0x01
end_define

begin_define
define|#
directive|define
name|TS_X25
value|0x02
end_define

begin_define
define|#
directive|define
name|TS_BRG
value|0x04
end_define

begin_define
define|#
directive|define
name|TS_TP4
value|0x08
end_define

begin_define
define|#
directive|define
name|TS_ALL
value|0xff
end_define

begin_struct
struct|struct
name|ts_interim
block|{
name|char
modifier|*
name|ts_name
decl_stmt|;
comment|/* community name, also MACRO name */
name|char
modifier|*
name|ts_value
decl_stmt|;
comment|/*   .. MACRO value */
name|int
name|ts_subnet
decl_stmt|;
comment|/* internal key */
name|int
name|ts_syntax
decl_stmt|;
comment|/* same values as na_stack */
name|char
name|ts_prefix
index|[
literal|20
index|]
decl_stmt|;
comment|/* NSAP prefix */
name|int
name|ts_length
decl_stmt|;
comment|/*   .. and length */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ts_interim
name|ts_interim
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ts_communities
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ts_comm_nsap_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ts_comm_x25_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ts_comm_tcp_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tsb_addresses
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tsb_communities
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tsb_default_address
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* X.25 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|X25
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|x25_local_dte
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|x25_local_pid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|x25_intl_zero
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|x25_strip_dnic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|x25_dnic_prefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|reverse_charge
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|recvpktsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|sendpktsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|recvwndsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|sendwndsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|recvthruput
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|sendthruput
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|cug_req
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|cug_index
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|fast_select_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|rpoa_req
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|rpoa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|x25_log
decl_stmt|,
name|_x25_log
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CAMTEC_CCL
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|x25_outgoing_port
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BRIDGE X.25 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BRIDGE_X25
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|x25_bridge_host
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|x25_bridge_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|x25_bridge_listen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|x25_bridge_pid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|x25_bridge_discrim
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BRIDGE_X25
argument_list|)
operator|||
name|defined
argument_list|(
name|X25
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|u_short
name|x25_bridge_port
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SESSION */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ses_ab_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ses_dn_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ses_rf_timer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* USER-FRIENDLY NAMESERVICE */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ns_enabled
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ns_address
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ROUTINES */
end_comment

begin_function_decl
name|void
name|isodetailor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isodesetvar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isodexport
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|isodefile
parameter_list|(
name|file
parameter_list|,
name|ispgm
parameter_list|)
define|\
value|_isodefile ((ispgm) ? isodesbinpath : isodetcpath, (file))
end_define

begin_function_decl
name|char
modifier|*
name|_isodefile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getlocalhost
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

