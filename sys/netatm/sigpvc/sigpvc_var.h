begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * PVC-only Signalling Manager  * ---------------------------  *  * Protocol control blocks  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIGPVC_SIGPVC_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_SIGPVC_SIGPVC_VAR_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Structure containing state information for each SigPVC protocol instance.  * There will be one instance for each ATM device interface using the SigPVC  * signalling manager.  */
end_comment

begin_struct
struct|struct
name|sigpvc
block|{
name|struct
name|siginst
name|pv_inst
decl_stmt|;
comment|/* Common header */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pv_next
value|pv_inst.si_next
end_define

begin_define
define|#
directive|define
name|pv_pif
value|pv_inst.si_pif
end_define

begin_define
define|#
directive|define
name|pv_addr
value|pv_inst.si_addr
end_define

begin_define
define|#
directive|define
name|pv_vccq
value|pv_inst.si_vccq
end_define

begin_define
define|#
directive|define
name|pv_state
value|pv_inst.si_state
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * SigPVC Protocol States  */
end_comment

begin_define
define|#
directive|define
name|SIGPVC_ACTIVE
value|1
end_define

begin_comment
comment|/* Active */
end_comment

begin_define
define|#
directive|define
name|SIGPVC_DETACH
value|2
end_define

begin_comment
comment|/* Detach in progress */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * SigPVC Virtual Channel Connection control block.  All information regarding  * the state of a SigPVC controlled VCC will be recorded here.  There will be  * one SigPVC VCC control block for each SigPVC-controlled VCC.  */
end_comment

begin_struct
struct|struct
name|sigpvc_vccb
block|{
name|struct
name|vccb
name|vcp_hdr
decl_stmt|;
comment|/* Generic vccb */
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
comment|/*  * SigPVC VCC Signalling Protocol States  */
end_comment

begin_define
define|#
directive|define
name|VCCS_NULL
value|0
end_define

begin_comment
comment|/* No state */
end_comment

begin_define
define|#
directive|define
name|VCCS_ACTIVE
value|1
end_define

begin_comment
comment|/* Active */
end_comment

begin_define
define|#
directive|define
name|VCCS_FREE
value|2
end_define

begin_comment
comment|/* Waiting for user to free resources */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Global function declarations  */
end_comment

begin_comment
comment|/* sigpvc_if.c */
end_comment

begin_comment
comment|/* sigpvc_subr.c */
end_comment

begin_function_decl
name|int
name|sigpvc_create_pvc
parameter_list|(
name|struct
name|sigpvc
modifier|*
parameter_list|,
name|Atm_connvc
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigpvc_close_vcc
parameter_list|(
name|struct
name|vccb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* _SIGPVC_SIGPVC_VAR_H */
end_comment

end_unit

