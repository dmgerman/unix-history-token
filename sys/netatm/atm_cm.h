begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Core ATM Services  * -----------------  *  * ATM Connection Management definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATM_ATM_CM_H
end_ifndef

begin_define
define|#
directive|define
name|_NETATM_ATM_CM_H
end_define

begin_comment
comment|/*  * Forward declaration  */
end_comment

begin_struct_decl
struct_decl|struct
name|atm_connection
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|atm_attributes
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Structure used to define a kernel ATM endpoint service module and its   * associated entry points.  An endpoint service is defined as a kernel   * entity which will serve as the endpoint of an ATM connection, i.e. it is  * responsible for issuing/receiving requests to/from the connection manager.  */
end_comment

begin_struct
struct|struct
name|atm_endpoint
block|{
name|struct
name|atm_endpoint
modifier|*
name|ep_next
decl_stmt|;
comment|/* Next in registry list */
name|u_int
name|ep_id
decl_stmt|;
comment|/* Endpoint ID (see below) */
comment|/* Exported functions: Miscellaneous */
name|int
function_decl|(
modifier|*
name|ep_ioctl
function_decl|)
comment|/* Ioctl */
parameter_list|(
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
name|caddr_t
function_decl|(
modifier|*
name|ep_getname
function_decl|)
comment|/* Get application/owner name */
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* Exported functions: Connection Manager Control API */
name|void
function_decl|(
modifier|*
name|ep_connected
function_decl|)
comment|/* Call connected */
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ep_cleared
function_decl|)
comment|/* Call cleared */
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|t_atm_cause
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ep_incoming
function_decl|)
comment|/* Incoming call */
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|atm_connection
modifier|*
parameter_list|,
name|struct
name|atm_attributes
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ep_addparty
function_decl|)
comment|/* Add Party notification */
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ep_dropparty
function_decl|)
comment|/* Drop Party notification */
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Exported functions: Connection Manager Data API: CPCS */
name|void
function_decl|(
modifier|*
name|ep_cpcs_ctl
function_decl|)
comment|/* Control operation */
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ep_cpcs_data
function_decl|)
comment|/* Received data */
parameter_list|(
name|void
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
comment|/* Exported functions: Connection Manager Data API: SAAL */
name|void
function_decl|(
modifier|*
name|ep_saal_ctl
function_decl|)
comment|/* Control operation */
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ep_saal_data
function_decl|)
comment|/* Received data */
parameter_list|(
name|void
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
comment|/* Exported functions: Connection Manager Data API: SSCOP */
name|void
function_decl|(
modifier|*
name|ep_sscop_ctl
function_decl|)
comment|/* Control operation */
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ep_sscop_data
function_decl|)
comment|/* Received data */
parameter_list|(
name|void
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atm_endpoint
name|Atm_endpoint
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Endpoint IDs  */
end_comment

begin_define
define|#
directive|define
name|ENDPT_UNKNOWN
value|0
end_define

begin_comment
comment|/* Unknown */
end_comment

begin_define
define|#
directive|define
name|ENDPT_IP
value|1
end_define

begin_comment
comment|/* IP over ATM */
end_comment

begin_define
define|#
directive|define
name|ENDPT_ATMARP
value|2
end_define

begin_comment
comment|/* ATMARP */
end_comment

begin_define
define|#
directive|define
name|ENDPT_SPANS_SIG
value|3
end_define

begin_comment
comment|/* SPANS Signalling */
end_comment

begin_define
define|#
directive|define
name|ENDPT_SPANS_CLS
value|4
end_define

begin_comment
comment|/* SPANS CLS */
end_comment

begin_define
define|#
directive|define
name|ENDPT_UNI_SIG
value|5
end_define

begin_comment
comment|/* UNI Signalling */
end_comment

begin_define
define|#
directive|define
name|ENDPT_SOCK_AAL5
value|6
end_define

begin_comment
comment|/* Socket - AAL5 */
end_comment

begin_define
define|#
directive|define
name|ENDPT_SOCK_SSCOP
value|7
end_define

begin_comment
comment|/* Socket - SSCOP */
end_comment

begin_define
define|#
directive|define
name|ENDPT_MAX
value|7
end_define

begin_comment
comment|/*  * ATM Connection Attributes  *  * Note: Attribute tag values are the same as the SVE_tag values.  *       Unless otherwise specified, attribute field values are the same   *       as the corresponding socket option values.  *       The above values are all defined in netatm/atm.h.    */
end_comment

begin_comment
comment|/* AAL Attributes */
end_comment

begin_struct
struct|struct
name|t_atm_aal4
block|{
name|int32_t
name|forward_max_SDU_size
decl_stmt|;
name|int32_t
name|backward_max_SDU_size
decl_stmt|;
name|int32_t
name|SSCS_type
decl_stmt|;
name|int32_t
name|mid_low
decl_stmt|;
name|int32_t
name|mid_high
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|attr_aal
block|{
name|int
name|tag
decl_stmt|;
comment|/* Attribute tag */
name|Aal_t
name|type
decl_stmt|;
comment|/* AAL type (discriminator) */
union|union
block|{
name|struct
name|t_atm_aal4
name|aal4
decl_stmt|;
name|struct
name|t_atm_aal5
name|aal5
decl_stmt|;
block|}
name|v
union|;
comment|/* Attribute value */
block|}
struct|;
end_struct

begin_comment
comment|/* Traffic Descriptor Attributes */
end_comment

begin_struct
struct|struct
name|attr_traffic
block|{
name|int
name|tag
decl_stmt|;
comment|/* Attribute tag */
name|struct
name|t_atm_traffic
name|v
decl_stmt|;
comment|/* Attribute value */
block|}
struct|;
end_struct

begin_comment
comment|/* Broadband Bearer Attributes */
end_comment

begin_struct
struct|struct
name|attr_bearer
block|{
name|int
name|tag
decl_stmt|;
comment|/* Attribute tag */
name|struct
name|t_atm_bearer
name|v
decl_stmt|;
comment|/* Attribute value */
block|}
struct|;
end_struct

begin_comment
comment|/* Broadband High Layer Information Attributes */
end_comment

begin_struct
struct|struct
name|attr_bhli
block|{
name|int
name|tag
decl_stmt|;
comment|/* Attribute tag */
name|struct
name|t_atm_bhli
name|v
decl_stmt|;
comment|/* Attribute value */
block|}
struct|;
end_struct

begin_comment
comment|/* Broadband Low Layer Information Attributes */
end_comment

begin_struct
struct|struct
name|attr_blli
block|{
name|int
name|tag_l2
decl_stmt|;
comment|/* Layer 2 attribute tag */
name|int
name|tag_l3
decl_stmt|;
comment|/* Layer 3 attribute tag */
name|struct
name|t_atm_blli
name|v
decl_stmt|;
comment|/* Attribute value */
block|}
struct|;
end_struct

begin_comment
comment|/* Logical Link Control Attributes (multiplexing use only, not signalled) */
end_comment

begin_struct
struct|struct
name|attr_llc
block|{
name|int
name|tag
decl_stmt|;
comment|/* Attribute tag */
name|struct
name|t_atm_llc
name|v
decl_stmt|;
comment|/* Attribute value */
block|}
struct|;
end_struct

begin_comment
comment|/* Called Party Attributes */
end_comment

begin_struct
struct|struct
name|attr_called
block|{
name|int
name|tag
decl_stmt|;
comment|/* Attribute tag */
name|Atm_addr
name|addr
decl_stmt|;
comment|/* Called party address */
name|Atm_addr
name|subaddr
decl_stmt|;
comment|/* Called party subaddress */
block|}
struct|;
end_struct

begin_comment
comment|/* Calling Party Attributes */
end_comment

begin_struct
struct|struct
name|attr_calling
block|{
name|int
name|tag
decl_stmt|;
comment|/* Attribute tag */
name|Atm_addr
name|addr
decl_stmt|;
comment|/* Calling party address */
name|Atm_addr
name|subaddr
decl_stmt|;
comment|/* Calling party subaddress */
name|struct
name|t_atm_caller_id
name|cid
decl_stmt|;
comment|/* Caller ID */
block|}
struct|;
end_struct

begin_comment
comment|/* Quality of Service Attributes */
end_comment

begin_struct
struct|struct
name|attr_qos
block|{
name|int
name|tag
decl_stmt|;
comment|/* Attribute tag */
name|struct
name|t_atm_qos
name|v
decl_stmt|;
comment|/* Attribute value */
block|}
struct|;
end_struct

begin_comment
comment|/* Transit Network Attributes */
end_comment

begin_struct
struct|struct
name|attr_transit
block|{
name|int
name|tag
decl_stmt|;
comment|/* Attribute tag */
name|struct
name|t_atm_transit
name|v
decl_stmt|;
comment|/* Attribute value */
block|}
struct|;
end_struct

begin_comment
comment|/* Cause Attributes */
end_comment

begin_struct
struct|struct
name|attr_cause
block|{
name|int
name|tag
decl_stmt|;
comment|/* Attribute tag */
name|struct
name|t_atm_cause
name|v
decl_stmt|;
comment|/* Attribute value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atm_attributes
block|{
name|struct
name|atm_nif
modifier|*
name|nif
decl_stmt|;
comment|/* Network interface */
name|u_int
name|api
decl_stmt|;
comment|/* Connect Mgr Data API (see below) */
name|int
name|api_init
decl_stmt|;
comment|/* API initialization parameter */
name|u_short
name|headin
decl_stmt|;
comment|/* Input buffer headroom */
name|u_short
name|headout
decl_stmt|;
comment|/* Output buffer headroom */
name|struct
name|attr_aal
name|aal
decl_stmt|;
comment|/* AAL attributes */
name|struct
name|attr_traffic
name|traffic
decl_stmt|;
comment|/* Traffic descriptor attributes */
name|struct
name|attr_bearer
name|bearer
decl_stmt|;
comment|/* Broadband bearer attributes */
name|struct
name|attr_bhli
name|bhli
decl_stmt|;
comment|/* Broadband high layer attributes */
name|struct
name|attr_blli
name|blli
decl_stmt|;
comment|/* Broadband low layer attributes */
name|struct
name|attr_llc
name|llc
decl_stmt|;
comment|/* Logical link control attributes */
name|struct
name|attr_called
name|called
decl_stmt|;
comment|/* Called party attributes */
name|struct
name|attr_calling
name|calling
decl_stmt|;
comment|/* Calling party attributes */
name|struct
name|attr_qos
name|qos
decl_stmt|;
comment|/* Quality of service attributes */
name|struct
name|attr_transit
name|transit
decl_stmt|;
comment|/* Transit network attributes */
name|struct
name|attr_cause
name|cause
decl_stmt|;
comment|/* Cause attributes */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atm_attributes
name|Atm_attributes
typedef|;
end_typedef

begin_comment
comment|/*  * Connection Manager Data APIs  */
end_comment

begin_define
define|#
directive|define
name|CMAPI_CPCS
value|0
end_define

begin_comment
comment|/* AAL CPCS */
end_comment

begin_define
define|#
directive|define
name|CMAPI_SAAL
value|1
end_define

begin_comment
comment|/* Signalling AAL */
end_comment

begin_define
define|#
directive|define
name|CMAPI_SSCOP
value|2
end_define

begin_comment
comment|/* Reliable data (SSCOP) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * ATM Connection Instance  *  * There will be one connection block for each endpoint<-> Connection Manager   * API instance.  Note that with connection multiplexors (e.g. LLC), there   * may be multiple connections per VCC.  */
end_comment

begin_struct
struct|struct
name|atm_connection
block|{
name|struct
name|atm_connection
modifier|*
name|co_next
decl_stmt|;
comment|/* Multiplexor/listen queue link */
name|struct
name|atm_connection
modifier|*
name|co_mxh
decl_stmt|;
comment|/* Connection multiplexor head */
name|u_char
name|co_flags
decl_stmt|;
comment|/* Connection flags (see below) */
name|u_char
name|co_state
decl_stmt|;
comment|/* User<-> CM state (see below) */
name|Encaps_t
name|co_mpx
decl_stmt|;
comment|/* Multiplexor type */
name|void
modifier|*
name|co_toku
decl_stmt|;
comment|/* Endpoint's session token */
name|Atm_endpoint
modifier|*
name|co_endpt
decl_stmt|;
comment|/* Endpoint service */
name|struct
name|atm_connvc
modifier|*
name|co_connvc
decl_stmt|;
comment|/* Connection VCC */
name|struct
name|attr_llc
name|co_llc
decl_stmt|;
comment|/* Connection LLC header */
name|Atm_attributes
modifier|*
name|co_lattr
decl_stmt|;
comment|/* Listening attributes */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atm_connection
name|Atm_connection
typedef|;
end_typedef

begin_comment
comment|/*  * Connection Flags  */
end_comment

begin_define
define|#
directive|define
name|COF_P2P
value|0x01
end_define

begin_comment
comment|/* Point-to-point */
end_comment

begin_define
define|#
directive|define
name|COF_P2MP
value|0x02
end_define

begin_comment
comment|/* Point-to-multipoint */
end_comment

begin_comment
comment|/*  * Endpoint<-> Connection Manager States  */
end_comment

begin_define
define|#
directive|define
name|COS_FREE
value|0
end_define

begin_comment
comment|/* Not allocated */
end_comment

begin_define
define|#
directive|define
name|COS_OUTCONN
value|1
end_define

begin_comment
comment|/* Outgoing connection pending */
end_comment

begin_define
define|#
directive|define
name|COS_LISTEN
value|2
end_define

begin_comment
comment|/* Listening for connection */
end_comment

begin_define
define|#
directive|define
name|COS_INCONN
value|3
end_define

begin_comment
comment|/* Incoming connection pending */
end_comment

begin_define
define|#
directive|define
name|COS_INACCEPT
value|4
end_define

begin_comment
comment|/* Incoming connection accepted */
end_comment

begin_define
define|#
directive|define
name|COS_ACTIVE
value|5
end_define

begin_comment
comment|/* Connection active */
end_comment

begin_define
define|#
directive|define
name|COS_CLEAR
value|6
end_define

begin_comment
comment|/* Connection is clearing */
end_comment

begin_comment
comment|/*  * ATM Connection VCC Instance  *  * There will be one connection-vcc block for each VCC created by the  * Connection Manager. For multiplexed connections, there may be multiple  * connection blocks associated with each connection-vcc.  This block is  * used to control the Connection Manager<-> VCC interface, including the   * interfaces to stack management and the signalling manager.  */
end_comment

begin_struct
struct|struct
name|atm_connvc
block|{
name|Qelem_t
name|cvc_q
decl_stmt|;
comment|/* Queueing links */
name|Atm_connection
modifier|*
name|cvc_conn
decl_stmt|;
comment|/* Connection head */
name|struct
name|vccb
modifier|*
name|cvc_vcc
decl_stmt|;
comment|/* VCC for connection */
name|struct
name|sigmgr
modifier|*
name|cvc_sigmgr
decl_stmt|;
comment|/* VCC signalling manager */
name|u_char
name|cvc_flags
decl_stmt|;
comment|/* Connection flags (see below) */
name|u_char
name|cvc_state
decl_stmt|;
comment|/* CM - VCC state (see below) */
name|void
modifier|*
name|cvc_tokl
decl_stmt|;
comment|/* Stack lower layer token */
name|void
function_decl|(
modifier|*
name|cvc_lower
function_decl|)
comment|/* Stack lower layer handler */
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|u_short
name|cvc_upcnt
decl_stmt|;
comment|/* Up stack calls in progress */
name|u_short
name|cvc_downcnt
decl_stmt|;
comment|/* Down stack calls in progress */
name|KBuffer
modifier|*
name|cvc_rcvq
decl_stmt|;
comment|/* Packet receive queue */
name|int
name|cvc_rcvqlen
decl_stmt|;
comment|/* Receive queue length */
name|Atm_attributes
name|cvc_attr
decl_stmt|;
comment|/* VCC attributes */
name|struct
name|atm_time
name|cvc_time
decl_stmt|;
comment|/* Timer controls */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atm_connvc
name|Atm_connvc
typedef|;
end_typedef

begin_comment
comment|/*  * Connection Flags  */
end_comment

begin_define
define|#
directive|define
name|CVCF_ABORTING
value|0x01
end_define

begin_comment
comment|/* VCC abort is pending */
end_comment

begin_define
define|#
directive|define
name|CVCF_INCOMQ
value|0x02
end_define

begin_comment
comment|/* VCC is on incoming queue */
end_comment

begin_define
define|#
directive|define
name|CVCF_CONNQ
value|0x04
end_define

begin_comment
comment|/* VCC is on connection queue */
end_comment

begin_define
define|#
directive|define
name|CVCF_CALLER
value|0x08
end_define

begin_comment
comment|/* We are the call originator */
end_comment

begin_comment
comment|/*  * Connection Manager<-> VCC States  */
end_comment

begin_define
define|#
directive|define
name|CVCS_FREE
value|0
end_define

begin_comment
comment|/* Not allocated */
end_comment

begin_define
define|#
directive|define
name|CVCS_SETUP
value|1
end_define

begin_comment
comment|/* Call setup pending */
end_comment

begin_define
define|#
directive|define
name|CVCS_INIT
value|2
end_define

begin_comment
comment|/* Stack INIT pending */
end_comment

begin_define
define|#
directive|define
name|CVCS_INCOMING
value|3
end_define

begin_comment
comment|/* Incoming call present */
end_comment

begin_define
define|#
directive|define
name|CVCS_ACCEPT
value|4
end_define

begin_comment
comment|/* Incoming call accepted */
end_comment

begin_define
define|#
directive|define
name|CVCS_REJECT
value|5
end_define

begin_comment
comment|/* Incoming call rejected */
end_comment

begin_define
define|#
directive|define
name|CVCS_ACTIVE
value|6
end_define

begin_comment
comment|/* Stack active */
end_comment

begin_define
define|#
directive|define
name|CVCS_RELEASE
value|7
end_define

begin_comment
comment|/* Connection release pending */
end_comment

begin_define
define|#
directive|define
name|CVCS_CLEAR
value|8
end_define

begin_comment
comment|/* Call has been cleared */
end_comment

begin_define
define|#
directive|define
name|CVCS_TERM
value|9
end_define

begin_comment
comment|/* Stack TERM pending */
end_comment

begin_comment
comment|/*  * Connection VCC variables  */
end_comment

begin_define
define|#
directive|define
name|CVC_RCVQ_MAX
value|3
end_define

begin_comment
comment|/* Max length of receive queue */
end_comment

begin_comment
comment|/*  * Timer macros  */
end_comment

begin_define
define|#
directive|define
name|CVC_TIMER
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|atm_timeout(&(s)->cvc_time, (t), atm_cm_timeout)
end_define

begin_define
define|#
directive|define
name|CVC_CANCEL
parameter_list|(
name|s
parameter_list|)
value|atm_untimeout(&(s)->cvc_time)
end_define

begin_comment
comment|/*  * Connection Manager Statistics  */
end_comment

begin_struct
struct|struct
name|atm_cm_stat
block|{
name|u_long
name|cms_llcdrop
decl_stmt|;
comment|/* Packets dropped by llc demux'ing */
name|u_long
name|cms_llcid
decl_stmt|;
comment|/* Packets with unknown llc id */
name|u_long
name|cms_rcvconn
decl_stmt|;
comment|/* Packets dropped, bad conn state */
name|u_long
name|cms_rcvconnvc
decl_stmt|;
comment|/* Packets dropped, bad connvc state */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETATM_ATM_CM_H */
end_comment

end_unit

