begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * IP Over ATM Support  * -------------------  *  * Protocol control blocks  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IPATM_IPATM_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IPATM_IPATM_VAR_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Structure containing information for each VCC, both SVC and PVC, which  * supports IP traffic.  */
end_comment

begin_struct
struct|struct
name|ipvcc
block|{
name|Qelem_t
name|iv_elem
decl_stmt|;
comment|/* ip_nif queueing links */
name|u_short
name|iv_flags
decl_stmt|;
comment|/* VCC flags (see below) */
name|u_char
name|iv_state
decl_stmt|;
comment|/* VCC state (see below) */
name|Atm_connection
modifier|*
name|iv_conn
decl_stmt|;
comment|/* Connection manager token */
name|struct
name|in_addr
name|iv_dst
decl_stmt|;
comment|/* Peer's IP address */
name|struct
name|ip_nif
modifier|*
name|iv_ipnif
decl_stmt|;
comment|/* IP network interface */
name|struct
name|atm_time
name|iv_time
decl_stmt|;
comment|/* Timer controls */
name|short
name|iv_idle
decl_stmt|;
comment|/* VCC idle timer */
name|u_char
name|iv_parmx
decl_stmt|;
comment|/* Index into provider's vcc params */
name|KBuffer
modifier|*
name|iv_queue
decl_stmt|;
comment|/* Packet waiting for VCC */
name|struct
name|arpmap
modifier|*
name|iv_arpent
decl_stmt|;
comment|/* ARP entry for VCC */
name|struct
name|ipvcc
modifier|*
name|iv_arpnext
decl_stmt|;
comment|/* ARP link field */
name|Atm_connection
modifier|*
name|iv_arpconn
decl_stmt|;
comment|/* ARP connection manager token */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|iv_forw
value|iv_elem.q_forw
end_define

begin_define
define|#
directive|define
name|iv_back
value|iv_elem.q_back
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * VCC Flags  */
end_comment

begin_define
define|#
directive|define
name|IVF_PVC
value|0x0001
end_define

begin_comment
comment|/* PVC */
end_comment

begin_define
define|#
directive|define
name|IVF_SVC
value|0x0002
end_define

begin_comment
comment|/* SVC */
end_comment

begin_define
define|#
directive|define
name|IVF_LLC
value|0x0004
end_define

begin_comment
comment|/* VCC uses LLC/SNAP encapsulation */
end_comment

begin_define
define|#
directive|define
name|IVF_MAPOK
value|0x0008
end_define

begin_comment
comment|/* VCC ARP mapping is valid */
end_comment

begin_define
define|#
directive|define
name|IVF_NOIDLE
value|0x0010
end_define

begin_comment
comment|/* Do not idle-timeout this VCC */
end_comment

begin_comment
comment|/*  * VCC States  */
end_comment

begin_define
define|#
directive|define
name|IPVCC_FREE
value|0
end_define

begin_comment
comment|/* No VCC associated with entry */
end_comment

begin_define
define|#
directive|define
name|IPVCC_PMAP
value|1
end_define

begin_comment
comment|/* SVC waiting for ARP mapping */
end_comment

begin_define
define|#
directive|define
name|IPVCC_POPEN
value|2
end_define

begin_comment
comment|/* Pending SVC open completion */
end_comment

begin_define
define|#
directive|define
name|IPVCC_PACCEPT
value|3
end_define

begin_comment
comment|/* Pending SVC accept completion */
end_comment

begin_define
define|#
directive|define
name|IPVCC_ACTPENT
value|4
end_define

begin_comment
comment|/* PVC open - waiting for ARP entry */
end_comment

begin_define
define|#
directive|define
name|IPVCC_ACTIVE
value|5
end_define

begin_comment
comment|/* VCC open - available */
end_comment

begin_define
define|#
directive|define
name|IPVCC_CLOSED
value|6
end_define

begin_comment
comment|/* VCC has been closed */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Structure containing IP-specific information for each ATM network  * interface in the system.  */
end_comment

begin_struct
struct|struct
name|ip_nif
block|{
name|struct
name|ip_nif
modifier|*
name|inf_next
decl_stmt|;
comment|/* Next on interface chain */
name|struct
name|atm_nif
modifier|*
name|inf_nif
decl_stmt|;
comment|/* ATM network interface */
name|u_short
name|inf_state
decl_stmt|;
comment|/* Interface state (see below) */
name|struct
name|in_ifaddr
modifier|*
name|inf_addr
decl_stmt|;
comment|/* Interface's IP address */
name|Queue_t
name|inf_vcq
decl_stmt|;
comment|/* VCC connections queue */
name|struct
name|ip_serv
modifier|*
name|inf_serv
decl_stmt|;
comment|/* Interface service provider */
comment|/* For use by IP interface service provider (ie signalling manager) */
name|caddr_t
name|inf_isintf
decl_stmt|;
comment|/* Interface control block */
comment|/* IP/ATM provided interface services */
name|void
function_decl|(
modifier|*
name|inf_arpnotify
function_decl|)
comment|/* ARP event notification */
parameter_list|(
name|struct
name|ipvcc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|inf_ipinput
function_decl|)
comment|/* IP packet input */
parameter_list|(
name|struct
name|ip_nif
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|inf_createsvc
function_decl|)
comment|/* Create an IP SVC */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_short
parameter_list|,
name|caddr_t
parameter_list|,
name|struct
name|ipvcc
modifier|*
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Network Interface States  */
end_comment

begin_define
define|#
directive|define
name|IPNIF_ADDR
value|1
end_define

begin_comment
comment|/* Waiting for i/f address */
end_comment

begin_define
define|#
directive|define
name|IPNIF_SIGMGR
value|2
end_define

begin_comment
comment|/* Waiting for sigmgr attach */
end_comment

begin_define
define|#
directive|define
name|IPNIF_ACTIVE
value|3
end_define

begin_comment
comment|/* Active */
end_comment

begin_comment
comment|/*  * Global IP/ATM Statistics  */
end_comment

begin_struct
struct|struct
name|ipatm_stat
block|{
name|u_long
name|ias_rcvstate
decl_stmt|;
comment|/* Packets received, bad vcc state */
name|u_long
name|ias_rcvnobuf
decl_stmt|;
comment|/* Packets received, no buf avail */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure to pass parameters for ipatm_openpvc()  */
end_comment

begin_struct
struct|struct
name|ipatmpvc
block|{
name|struct
name|ip_nif
modifier|*
name|ipp_ipnif
decl_stmt|;
comment|/* PVC's IP network interface */
name|u_short
name|ipp_vpi
decl_stmt|;
comment|/* VPI value */
name|u_short
name|ipp_vci
decl_stmt|;
comment|/* VCI value */
name|Aal_t
name|ipp_aal
decl_stmt|;
comment|/* AAL type */
name|Encaps_t
name|ipp_encaps
decl_stmt|;
comment|/* VCC encapsulation */
name|struct
name|sockaddr_in
name|ipp_dst
decl_stmt|;
comment|/* Destination's IP address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Timer macros  */
end_comment

begin_define
define|#
directive|define
name|IPVCC_TIMER
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|atm_timeout(&(s)->iv_time, (t), ipatm_timeout)
end_define

begin_define
define|#
directive|define
name|IPVCC_CANCEL
parameter_list|(
name|s
parameter_list|)
value|atm_untimeout(&(s)->iv_time)
end_define

begin_comment
comment|/*  * Misc useful macros  */
end_comment

begin_define
define|#
directive|define
name|SATOSIN
parameter_list|(
name|sa
parameter_list|)
value|((struct sockaddr_in *)(sa))
end_define

begin_comment
comment|/*  * Global function declarations  */
end_comment

begin_comment
comment|/* ipatm_event.c */
end_comment

begin_function_decl
name|void
name|ipatm_timeout
parameter_list|(
name|struct
name|atm_time
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipatm_connected
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipatm_cleared
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|t_atm_cause
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipatm_arpnotify
parameter_list|(
name|struct
name|ipvcc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipatm_itimeout
parameter_list|(
name|struct
name|atm_time
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ipatm_if.c */
end_comment

begin_function_decl
name|int
name|ipatm_nifstat
parameter_list|(
name|int
parameter_list|,
name|struct
name|atm_nif
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ipatm_input.c */
end_comment

begin_function_decl
name|void
name|ipatm_cpcs_data
parameter_list|(
name|void
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipatm_ipinput
parameter_list|(
name|struct
name|ip_nif
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ipatm_load.c */
end_comment

begin_comment
comment|/* ipatm_output.c */
end_comment

begin_function_decl
name|int
name|ipatm_ifoutput
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ipatm_usrreq.c */
end_comment

begin_function_decl
name|int
name|ipatm_ioctl
parameter_list|(
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|ipatm_getname
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ipatm_vcm.c */
end_comment

begin_function_decl
name|int
name|ipatm_openpvc
parameter_list|(
name|struct
name|ipatmpvc
modifier|*
parameter_list|,
name|struct
name|ipvcc
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipatm_createsvc
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_short
parameter_list|,
name|caddr_t
parameter_list|,
name|struct
name|ipvcc
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipatm_opensvc
parameter_list|(
name|struct
name|ipvcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipatm_retrysvc
parameter_list|(
name|struct
name|ipvcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipatm_activate
parameter_list|(
name|struct
name|ipvcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipatm_incoming
parameter_list|(
name|void
modifier|*
parameter_list|,
name|Atm_connection
modifier|*
parameter_list|,
name|Atm_attributes
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipatm_closevc
parameter_list|(
name|struct
name|ipvcc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipatm_chknif
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|ip_nif
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ipvcc
modifier|*
name|ipatm_iptovc
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
parameter_list|,
name|struct
name|atm_nif
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * External variables  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ipatm_vccnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipatm_vcidle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ipatm_print
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|last_map_ipdst
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipvcc
modifier|*
name|last_map_ipvcc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ip_nif
modifier|*
name|ipatm_nif_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|ipatm_vcpool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|ipatm_nifpool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipatm_stat
name|ipatm_stat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|atm_time
name|ipatm_itimer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Atm_endpoint
name|ipatm_endpt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Atm_attributes
name|ipatm_aal5llc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Atm_attributes
name|ipatm_aal5null
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Atm_attributes
name|ipatm_aal4null
decl_stmt|;
end_decl_stmt

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
comment|/* _IPATM_IPATM_VAR_H */
end_comment

end_unit

