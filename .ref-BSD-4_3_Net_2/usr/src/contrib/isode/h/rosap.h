begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rosap.h - include file for remote operation users (RoS-USER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/rosap.h,v 7.1 91/02/22 09:25:00 mrose Interim $  *  * Based on an TCP-based implementation by George Michaelson of University  * College London.  *  *  * $Log:	rosap.h,v $  * Revision 7.1  91/02/22  09:25:00  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:55:56  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RoSAP_
end_ifndef

begin_define
define|#
directive|define
name|_RoSAP_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_MANIFEST_
end_ifndef

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_GENERAL_
end_ifndef

begin_include
include|#
directive|include
file|"general.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_AcSAP_
end_ifndef

begin_include
include|#
directive|include
file|"acsap.h"
end_include

begin_comment
comment|/* definitions for AcS-USERs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|RoSAPaddr
block|{
comment|/* RoSAP address (old-style)*/
name|struct
name|SSAPaddr
name|roa_addr
decl_stmt|;
name|u_short
name|roa_port
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLRoA
value|((struct RoSAPaddr *) 0)
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|ROS_MYREQUIRE
value|SR_DUPLEX
end_define

begin_comment
comment|/* for direct users of ACSE */
end_comment

begin_struct
struct|struct
name|RoSAPstart
block|{
comment|/* RO-BEGIN.INDICATION */
name|int
name|ros_sd
decl_stmt|;
comment|/* ROS descriptor */
name|struct
name|RoSAPaddr
name|ros_initiator
decl_stmt|;
comment|/* unique identifier */
name|u_short
name|ros_port
decl_stmt|;
comment|/* application number */
name|PE
name|ros_data
decl_stmt|;
comment|/* initial DATA from peer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ROSFREE
parameter_list|(
name|ros
parameter_list|)
define|\
value|{ \     if ((ros) -> ros_data) \ 	pe_free ((ros) -> ros_data), (ros) -> ros_data = NULLPE; \ }
end_define

begin_struct
struct|struct
name|RoSAPconnect
block|{
comment|/* RO-BEGIN.CONFIRMATION */
name|int
name|roc_sd
decl_stmt|;
comment|/* ROS descriptor */
name|int
name|roc_result
decl_stmt|;
comment|/* result */
define|#
directive|define
name|ROS_ACCEPT
value|(-1)
comment|/* RO-BEGIN.REQUEST */
define|#
directive|define
name|ROS_VALIDATE
value|0
comment|/* Authentication failure */
define|#
directive|define
name|ROS_BUSY
value|1
comment|/* Busy */
comment|/* General Problem */
define|#
directive|define
name|ROS_GP_UNRECOG
value|2
comment|/* Unrecognized APDU */
define|#
directive|define
name|ROS_GP_MISTYPED
value|3
comment|/* Mistyped APDU */
define|#
directive|define
name|ROS_GP_STRUCT
value|4
comment|/* Badly structured APDU */
comment|/* Invoke Problem */
define|#
directive|define
name|ROS_IP_DUP
value|5
comment|/* Duplicate invocation */
define|#
directive|define
name|ROS_IP_UNRECOG
value|6
comment|/* Unrecognized operation */
define|#
directive|define
name|ROS_IP_MISTYPED
value|7
comment|/* Mistyped argument */
define|#
directive|define
name|ROS_IP_LIMIT
value|8
comment|/* Resource limitation */
define|#
directive|define
name|ROS_IP_RELEASE
value|9
comment|/* Initiator releasing */
define|#
directive|define
name|ROS_IP_UNLINKED
value|10
comment|/* Unrecognized linked ID */
define|#
directive|define
name|ROS_IP_LINKED
value|11
comment|/* Linked response unexpected */
define|#
directive|define
name|ROS_IP_CHILD
value|12
comment|/* Unexpected child operation */
comment|/* Return Result Problem */
define|#
directive|define
name|ROS_RRP_UNRECOG
value|13
comment|/* Unrecognized invocation */
define|#
directive|define
name|ROS_RRP_UNEXP
value|14
comment|/* Result response unexpected */
define|#
directive|define
name|ROS_RRP_MISTYPED
value|15
comment|/* Mistyped result */
comment|/* Return Error Problem */
define|#
directive|define
name|ROS_REP_UNRECOG
value|16
comment|/* Unrecognized invocation */
define|#
directive|define
name|ROS_REP_UNEXP
value|17
comment|/* Error response unexpected */
define|#
directive|define
name|ROS_REP_RECERR
value|18
comment|/* Unrecognized error */
define|#
directive|define
name|ROS_REP_UNEXPERR
value|19
comment|/* Unexpected error */
define|#
directive|define
name|ROS_REP_MISTYPED
value|20
comment|/* Mistyped parameter */
comment|/* begin UNOFFICIAL */
define|#
directive|define
name|ROS_ADDRESS
value|21
comment|/* Address unknown */
define|#
directive|define
name|ROS_REFUSED
value|22
comment|/* Connect request refused on this network 				   connection */
define|#
directive|define
name|ROS_SESSION
value|23
comment|/* Session disconnect */
define|#
directive|define
name|ROS_PROTOCOL
value|24
comment|/* Protocol error */
define|#
directive|define
name|ROS_CONGEST
value|25
comment|/* Congestion at RoSAP */
define|#
directive|define
name|ROS_REMOTE
value|26
comment|/* Remote system problem */
define|#
directive|define
name|ROS_DONE
value|27
comment|/* Association done via async handler */
define|#
directive|define
name|ROS_ABORTED
value|28
comment|/* Peer aborted association */
define|#
directive|define
name|ROS_RTS
value|29
comment|/* RTS disconnect */
define|#
directive|define
name|ROS_PRESENTATION
value|30
comment|/* Presentation disconnect */
define|#
directive|define
name|ROS_ACS
value|31
comment|/* ACS disconnect */
define|#
directive|define
name|ROS_PARAMETER
value|32
comment|/* Invalid parameter */
define|#
directive|define
name|ROS_OPERATION
value|33
comment|/* Invalid operation */
define|#
directive|define
name|ROS_TIMER
value|34
comment|/* Timer expired */
define|#
directive|define
name|ROS_WAITING
value|35
comment|/* Indications waiting */
define|#
directive|define
name|ROS_APDU
value|36
comment|/* APDU not transferred */
define|#
directive|define
name|ROS_INTERRUPTED
value|37
comment|/* stub interrupted */
comment|/* end UNOFFICIAL */
define|#
directive|define
name|ROS_FATAL
parameter_list|(
name|r
parameter_list|)
value|(!(ROS_OFFICIAL (r))&& (r)< ROS_PARAMETER)
define|#
directive|define
name|ROS_OFFICIAL
parameter_list|(
name|r
parameter_list|)
value|((r)< ROS_ADDRESS)
name|PE
name|roc_data
decl_stmt|;
comment|/* initial DATA from peer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ROCFREE
parameter_list|(
name|roc
parameter_list|)
define|\
value|{ \     if ((roc) -> roc_data) \ 	pe_free ((roc) -> roc_data), (roc) -> roc_data = NULLPE; \ }
end_define

begin_comment
comment|/* Operation Classes */
end_comment

begin_define
define|#
directive|define
name|ROS_SYNC
value|0
end_define

begin_comment
comment|/* synchronous mode with result or error */
end_comment

begin_define
define|#
directive|define
name|ROS_ASYNC
value|1
end_define

begin_comment
comment|/* asynchronous mode with result or error */
end_comment

begin_comment
comment|/* APDU priorities */
end_comment

begin_define
define|#
directive|define
name|ROS_NOPRIO
value|0
end_define

begin_comment
comment|/* no priority */
end_comment

begin_struct
struct|struct
name|RoSAPinvoke
block|{
comment|/* RO-INVOKE.INDICATION */
name|int
name|rox_id
decl_stmt|;
comment|/*   invokeID */
name|int
name|rox_linkid
decl_stmt|;
comment|/*   linkedID */
name|int
name|rox_nolinked
decl_stmt|;
comment|/*   non-zero if no linkedID present */
name|int
name|rox_op
decl_stmt|;
comment|/*   operation */
name|PE
name|rox_args
decl_stmt|;
comment|/*   arguments */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ROXFREE
parameter_list|(
name|rox
parameter_list|)
define|\
value|{ \     if ((rox) -> rox_args) \ 	pe_free ((rox) -> rox_args), (rox) -> rox_args = NULLPE; \ }
end_define

begin_struct
struct|struct
name|RoSAPresult
block|{
comment|/* RO-RESULT.INDICATION */
name|int
name|ror_id
decl_stmt|;
comment|/*   invokeID */
name|int
name|ror_op
decl_stmt|;
comment|/*   operation */
name|PE
name|ror_result
decl_stmt|;
comment|/*   result */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RORFREE
parameter_list|(
name|ror
parameter_list|)
define|\
value|{ \     if ((ror) -> ror_result) \ 	pe_free ((ror) -> ror_result), (ror) -> ror_result = NULLPE; \ }
end_define

begin_struct
struct|struct
name|RoSAPerror
block|{
comment|/* RO-ERROR.INDICATION */
name|int
name|roe_id
decl_stmt|;
comment|/*   invokeID */
name|int
name|roe_error
decl_stmt|;
comment|/*   error */
name|PE
name|roe_param
decl_stmt|;
comment|/*   parameter */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ROEFREE
parameter_list|(
name|roe
parameter_list|)
define|\
value|{ \     if ((roe) -> roe_param) \ 	pe_free ((roe) -> roe_param), (roe) -> roe_param = NULLPE; \ }
end_define

begin_struct
struct|struct
name|RoSAPureject
block|{
comment|/* RO-U-REJECT.INDICATION */
name|int
name|rou_id
decl_stmt|;
comment|/*   invokeID */
name|int
name|rou_noid
decl_stmt|;
comment|/*     .. is not present */
name|int
name|rou_reason
decl_stmt|;
comment|/*   reason (same as roc_result) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RoSAPpreject
block|{
comment|/* RO-P-REJECT.INDICATION */
name|int
name|rop_reason
decl_stmt|;
comment|/*   reason (same as roc_result) */
comment|/* APDU not transferred (reason is ROS_APDU) */
name|int
name|rop_id
decl_stmt|;
comment|/*   invokeID */
name|PE
name|rop_apdu
decl_stmt|;
comment|/*   APDU */
comment|/*   additional failure data from provider */
define|#
directive|define
name|ROP_SIZE
value|512
name|int
name|rop_cc
decl_stmt|;
comment|/*   length */
name|char
name|rop_data
index|[
name|ROP_SIZE
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ROPFREE
parameter_list|(
name|rop
parameter_list|)
define|\
value|{ \     if ((rop) -> rop_apdu) \ 	pe_free ((rop) -> rop_apdu), (rop) -> rop_apdu = NULLPE; \ }
end_define

begin_struct
struct|struct
name|RoSAPend
block|{
comment|/* RO-END.INDICATION */
name|int
name|roe_dummy
decl_stmt|;
comment|/*   not used */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RoSAPindication
block|{
name|int
name|roi_type
decl_stmt|;
comment|/* the union element present */
define|#
directive|define
name|ROI_INVOKE
value|0x00
define|#
directive|define
name|ROI_RESULT
value|0x01
define|#
directive|define
name|ROI_ERROR
value|0x02
define|#
directive|define
name|ROI_UREJECT
value|0x03
define|#
directive|define
name|ROI_PREJECT
value|0x04
define|#
directive|define
name|ROI_END
value|0x05
define|#
directive|define
name|ROI_FINISH
value|0x06
union|union
block|{
name|struct
name|RoSAPinvoke
name|roi_un_invoke
decl_stmt|;
name|struct
name|RoSAPresult
name|roi_un_result
decl_stmt|;
name|struct
name|RoSAPerror
name|roi_un_error
decl_stmt|;
name|struct
name|RoSAPureject
name|roi_un_ureject
decl_stmt|;
name|struct
name|RoSAPpreject
name|roi_un_preject
decl_stmt|;
name|struct
name|RoSAPend
name|roi_un_end
decl_stmt|;
name|struct
name|AcSAPfinish
name|roi_un_finish
decl_stmt|;
block|}
name|roi_un
union|;
define|#
directive|define
name|roi_invoke
value|roi_un.roi_un_invoke
define|#
directive|define
name|roi_result
value|roi_un.roi_un_result
define|#
directive|define
name|roi_error
value|roi_un.roi_un_error
define|#
directive|define
name|roi_ureject
value|roi_un.roi_un_ureject
define|#
directive|define
name|roi_preject
value|roi_un.roi_un_preject
define|#
directive|define
name|roi_end
value|roi_un.roi_un_end
define|#
directive|define
name|roi_finish
value|roi_un.roi_un_finish
block|}
struct|;
end_struct

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rosapversion
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|RoExec
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* SERVER only */
end_comment

begin_function_decl
name|int
name|RoInit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RO-BEGIN.INDICATION */
end_comment

begin_function_decl
name|int
name|RoBeginResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RO-BEGIN.RESPONSE */
end_comment

begin_function_decl
name|int
name|RoBeginRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RO-BEGIN.REQUEST */
end_comment

begin_function_decl
name|int
name|RoEndRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RO-END.REQUEST */
end_comment

begin_function_decl
name|int
name|RoEndResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RO-END.RESPONSE */
end_comment

begin_function_decl
name|int
name|RoInvokeRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RO-INVOKE.REQUEST */
end_comment

begin_function_decl
name|int
name|RoResultRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RO-RESULT.REQUEST */
end_comment

begin_function_decl
name|int
name|RoErrorRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RO-ERROR.REQUEST */
end_comment

begin_function_decl
name|int
name|RoURejectRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RO-U-REJECT.REQUEST */
end_comment

begin_define
define|#
directive|define
name|RoRejectURequest
value|RoURejectRequest
end_define

begin_function_decl
name|int
name|RoIntrRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RO-INVOKE.REQUEST (interruptable) */
end_comment

begin_function_decl
name|int
name|RoWaitRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RO-WAIT.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|RoSetIndications
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* define vectors for INDICATION events */
end_comment

begin_function_decl
name|int
name|RoSelectMask
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* map remote operation descriptors for 				   select() */
end_comment

begin_function_decl
name|int
name|RoSetService
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* bind underlying service */
end_comment

begin_decl_stmt
name|int
name|RoRtService
argument_list|()
decl_stmt|,
name|RoPService
argument_list|()
decl_stmt|,
name|RoSService
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|RoSetThorn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|RoErrString
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return RoSAP error code in string form */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

