begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Core ATM Services  * -----------------  *  * ATM Virtual Channel definitions   *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATM_ATM_VC_H
end_ifndef

begin_define
define|#
directive|define
name|_NETATM_ATM_VC_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

begin_comment
comment|/*  * ATM Virtual Channel Connection control block.  All vccb's are created  * and controlled by an ATM signalling manager.  Each ATM signalling   * protocol will also have its own protocol-specific vccb format.  Each   * of these protocol vccb's must have this common block at the beginning.  */
end_comment

begin_struct
struct|struct
name|vccb
block|{
name|u_char
name|vc_type
decl_stmt|;
comment|/* VCC type (see below) */
name|u_char
name|vc_proto
decl_stmt|;
comment|/* Signalling protocol */
name|u_char
name|vc_sstate
decl_stmt|;
comment|/* Signalling state (sigmgr specific) */
name|u_char
name|vc_ustate
decl_stmt|;
comment|/* User interface state (see below) */
name|struct
name|atm_pif
modifier|*
name|vc_pif
decl_stmt|;
comment|/* Physical interface */
name|struct
name|atm_nif
modifier|*
name|vc_nif
decl_stmt|;
comment|/* Network interface */
name|Qelem_t
name|vc_sigelem
decl_stmt|;
comment|/* Signalling instance vccb queue */
name|struct
name|atm_time
name|vc_time
decl_stmt|;
comment|/* Timer controls */
name|u_short
name|vc_vpi
decl_stmt|;
comment|/* Virtual Path Identifier */
name|u_short
name|vc_vci
decl_stmt|;
comment|/* Virtual Channel Identifier */
name|Atm_connvc
modifier|*
name|vc_connvc
decl_stmt|;
comment|/* CM connection VCC instance */
name|long
name|vc_ipdus
decl_stmt|;
comment|/* PDUs received from VCC */
name|long
name|vc_opdus
decl_stmt|;
comment|/* PDUs sent to VCC */
name|long
name|vc_ibytes
decl_stmt|;
comment|/* Bytes received from VCC */
name|long
name|vc_obytes
decl_stmt|;
comment|/* Bytes sent to VCC */
name|long
name|vc_ierrors
decl_stmt|;
comment|/* Errors receiving from VCC */
name|long
name|vc_oerrors
decl_stmt|;
comment|/* Errors sending to VCC */
name|time_t
name|vc_tstamp
decl_stmt|;
comment|/* State transition timestamp */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATM_KERNEL */
end_comment

begin_comment
comment|/*  * VCC Types  */
end_comment

begin_define
define|#
directive|define
name|VCC_PVC
value|0x01
end_define

begin_comment
comment|/* PVC (Permanent Virtual Channel) */
end_comment

begin_define
define|#
directive|define
name|VCC_SVC
value|0x02
end_define

begin_comment
comment|/* SVC (Switched Virtual Channel) */
end_comment

begin_define
define|#
directive|define
name|VCC_IN
value|0x04
end_define

begin_comment
comment|/* Inbound VCC */
end_comment

begin_define
define|#
directive|define
name|VCC_OUT
value|0x08
end_define

begin_comment
comment|/* Outbound VCC */
end_comment

begin_comment
comment|/*  * VCC Signalling-to-User Interface States  */
end_comment

begin_define
define|#
directive|define
name|VCCU_NULL
value|0
end_define

begin_comment
comment|/* No state */
end_comment

begin_define
define|#
directive|define
name|VCCU_POPEN
value|1
end_define

begin_comment
comment|/* Pending open completion */
end_comment

begin_define
define|#
directive|define
name|VCCU_OPEN
value|2
end_define

begin_comment
comment|/* Connection is open */
end_comment

begin_define
define|#
directive|define
name|VCCU_CLOSED
value|3
end_define

begin_comment
comment|/* Connection has been terminated */
end_comment

begin_define
define|#
directive|define
name|VCCU_ABORT
value|4
end_define

begin_comment
comment|/* Connection being aborted */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETATM_ATM_VC_H */
end_comment

end_unit

