begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Core ATM Services  * -----------------  *  * ATM Signalling Manager definitions   *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATM_ATM_SIGMGR_H
end_ifndef

begin_define
define|#
directive|define
name|_NETATM_ATM_SIGMGR_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Structure common to all ATM Signalling Managers.  Each Signalling   * Manager must create one of these and use it to register itself   * with the system.  */
end_comment

begin_struct
struct|struct
name|sigmgr
block|{
name|struct
name|sigmgr
modifier|*
name|sm_next
decl_stmt|;
comment|/* Next registered sigmgr */
name|u_char
name|sm_proto
decl_stmt|;
comment|/* Signalling protocol (see below) */
name|struct
name|siginst
modifier|*
name|sm_prinst
decl_stmt|;
comment|/* List of protocol instances */
comment|/* Exported functions */
name|int
function_decl|(
modifier|*
name|sm_attach
function_decl|)
comment|/* Attach interface */
parameter_list|(
name|struct
name|sigmgr
modifier|*
parameter_list|,
name|struct
name|atm_pif
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sm_detach
function_decl|)
comment|/* Detach interface */
parameter_list|(
name|struct
name|atm_pif
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sm_setup
function_decl|)
comment|/* Connection setup */
parameter_list|(
name|Atm_connvc
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sm_accept
function_decl|)
comment|/* Call accepted */
parameter_list|(
name|struct
name|vccb
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sm_reject
function_decl|)
comment|/* Call rejected */
parameter_list|(
name|struct
name|vccb
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sm_release
function_decl|)
comment|/* Connection release */
parameter_list|(
name|struct
name|vccb
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sm_free
function_decl|)
comment|/* Free connection resources */
parameter_list|(
name|struct
name|vccb
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sm_ioctl
function_decl|)
comment|/* Ioctl handler */
parameter_list|(
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
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

begin_comment
comment|/*   * ATM Signalling Protocols  */
end_comment

begin_define
define|#
directive|define
name|ATM_SIG_PVC
value|1
end_define

begin_comment
comment|/* PVC-only */
end_comment

begin_define
define|#
directive|define
name|ATM_SIG_SPANS
value|2
end_define

begin_comment
comment|/* Fore Systems SPANS */
end_comment

begin_define
define|#
directive|define
name|ATM_SIG_UNI30
value|3
end_define

begin_comment
comment|/* ATM Forum UNI 3.0 */
end_comment

begin_define
define|#
directive|define
name|ATM_SIG_UNI31
value|4
end_define

begin_comment
comment|/* ATM Forum UNI 3.1 */
end_comment

begin_define
define|#
directive|define
name|ATM_SIG_UNI40
value|5
end_define

begin_comment
comment|/* ATM Forum UNI 4.0 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Signalling Protocol Instance control block header.  Common header for  * every signalling protocol instance control block.  */
end_comment

begin_struct
struct|struct
name|siginst
block|{
name|struct
name|siginst
modifier|*
name|si_next
decl_stmt|;
comment|/* Next sigmgr protocol instance */
name|struct
name|atm_pif
modifier|*
name|si_pif
decl_stmt|;
comment|/* Device interface */
name|Atm_addr
name|si_addr
decl_stmt|;
comment|/* Interface ATM address */
name|Atm_addr
name|si_subaddr
decl_stmt|;
comment|/* Interface ATM subaddress */
name|Queue_t
name|si_vccq
decl_stmt|;
comment|/* VCCB queue */
name|u_short
name|si_state
decl_stmt|;
comment|/* Protocol state (sigmgr specific) */
comment|/* Exported protocol services */
name|struct
name|ip_serv
modifier|*
name|si_ipserv
decl_stmt|;
comment|/* IP/ATM services */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Sigmgr function return codes  */
end_comment

begin_define
define|#
directive|define
name|CALL_PROCEEDING
value|1
end_define

begin_comment
comment|/* Connection request is in progress */
end_comment

begin_define
define|#
directive|define
name|CALL_FAILED
value|2
end_define

begin_comment
comment|/* Connection request failed */
end_comment

begin_define
define|#
directive|define
name|CALL_CONNECTED
value|3
end_define

begin_comment
comment|/* Connection setup successful */
end_comment

begin_define
define|#
directive|define
name|CALL_CLEARED
value|4
end_define

begin_comment
comment|/* Connection has been terminated */
end_comment

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
comment|/* _NETATM_ATM_SIGMGR_H */
end_comment

end_unit

