begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rtsap.h - include file for reliable transfer users (RtS-USER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/rtsap.h,v 7.3 91/02/22 09:25:05 mrose Interim $  *  *  * $Log:	rtsap.h,v $  * Revision 7.3  91/02/22  09:25:05  mrose  * Interim 6.8  *   * Revision 7.2  90/10/23  20:35:53  mrose  * update  *   * Revision 7.1  90/07/27  08:44:53  mrose  * update  *   * Revision 7.0  89/11/23  21:55:59  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RtSAP_
end_ifndef

begin_define
define|#
directive|define
name|_RtSAP_
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
name|RtSAPaddr
block|{
comment|/* RtSAP address (old-style) */
name|struct
name|SSAPaddr
name|rta_addr
decl_stmt|;
name|u_short
name|rta_port
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLRtA
value|((struct RtSAPaddr *) 0)
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|RtSAPstart
block|{
comment|/* RT-OPEN.INDICATION */
name|int
name|rts_sd
decl_stmt|;
comment|/* RTS descriptor */
name|struct
name|RtSAPaddr
name|rts_initiator
decl_stmt|;
comment|/* address */
name|int
name|rts_mode
decl_stmt|;
comment|/* dialogue mode */
define|#
directive|define
name|RTS_MONOLOGUE
value|0
comment|/*   monologue */
define|#
directive|define
name|RTS_TWA
value|1
comment|/*   two-way alternate */
name|int
name|rts_turn
decl_stmt|;
comment|/* initial turn */
define|#
directive|define
name|RTS_INITIATOR
value|0
comment|/*   the initiator */
define|#
directive|define
name|RTS_RESPONDER
value|1
comment|/*   the responder */
name|u_short
name|rts_port
decl_stmt|;
comment|/* application number */
name|PE
name|rts_data
decl_stmt|;
comment|/* initial DATA from peer */
name|struct
name|AcSAPstart
name|rts_start
decl_stmt|;
comment|/* info from A-ASSOCIATE.INDICATION */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RTSFREE
parameter_list|(
name|rts
parameter_list|)
define|\
value|{ \     if ((rts) -> rts_data) \ 	pe_free ((rts) -> rts_data), (rts) -> rts_data = NULLPE; \     ACSFREE (&((rts) -> rts_start)); \ }
end_define

begin_struct
struct|struct
name|RtSAPconnect
block|{
comment|/* RT-OPEN.CONFIRMATION */
name|int
name|rtc_sd
decl_stmt|;
comment|/* RTS descriptor */
name|int
name|rtc_result
decl_stmt|;
comment|/* disposition */
define|#
directive|define
name|RTS_ACCEPT
value|(-1)
comment|/* RT-OPEN.REQUEST */
define|#
directive|define
name|RTS_BUSY
value|0
comment|/* Busy */
define|#
directive|define
name|RTS_RECOVER
value|1
comment|/* Cannot recover */
define|#
directive|define
name|RTS_VALIDATE
value|2
comment|/* Validation failure */
define|#
directive|define
name|RTS_MODE
value|3
comment|/* Unacceptable dialogue mode */
define|#
directive|define
name|RTS_REJECT
value|4
comment|/* Rejected by responder */
name|PE
name|rtc_data
decl_stmt|;
comment|/* initial DATA from peer */
name|struct
name|AcSAPconnect
name|rtc_connect
decl_stmt|;
comment|/* info from A-ASSOCIATE.CONFIRMATION */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RTCFREE
parameter_list|(
name|rtc
parameter_list|)
define|\
value|{ \     if ((rtc) -> rtc_data) \ 	pe_free ((rtc) -> rtc_data), (rtc) -> rtc_data = NULLPE; \     ACCFREE (&((rtc) -> rtc_connect)); \ }
end_define

begin_struct
struct|struct
name|RtSAPturn
block|{
comment|/* RT-TURN-{GIVE,PLEASE}.INDICATION */
name|int
name|rtu_please
decl_stmt|;
comment|/* T   = RT-TURN-PLEASE.INDICATION 				   NIL = RT-TURN-GIVE.INDICATION */
name|int
name|rtu_priority
decl_stmt|;
comment|/* priority, iff rtu_please == T */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RtSAPtransfer
block|{
comment|/* RT-TRANSFER.INDICATION */
name|PE
name|rtt_data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RTTFREE
parameter_list|(
name|rtt
parameter_list|)
define|\
value|{ \     if ((rtt) -> rtt_data) \ 	pe_free ((rtt) -> rtt_data), (rtt) -> rtt_data = NULLPE; \ }
end_define

begin_struct
struct|struct
name|RtSAPabort
block|{
comment|/* RT-{U,P}-ABORT.INDICATION */
name|int
name|rta_peer
decl_stmt|;
comment|/* T   = RT-U-ABORT.INDICATION 				   NIL = RT-P-ABORT.INDICATION */
name|int
name|rta_reason
decl_stmt|;
comment|/* reason */
comment|/* begin UNOFFICIAL */
define|#
directive|define
name|RTS_ADDRESS
value|5
comment|/* Address unknown */
define|#
directive|define
name|RTS_REFUSED
value|6
comment|/* Connect request refused on this network 				   connection */
define|#
directive|define
name|RTS_SESSION
value|7
comment|/* Session disconnect */
define|#
directive|define
name|RTS_PROTOCOL
value|8
comment|/* Protocol error */
define|#
directive|define
name|RTS_CONGEST
value|9
comment|/* Congestion at RtSAP */
define|#
directive|define
name|RTS_REMOTE
value|10
comment|/* Remote system problem */
define|#
directive|define
name|RTS_PRESENTATION
value|11
comment|/* Presentation disconnect */
define|#
directive|define
name|RTS_ACS
value|12
comment|/* ACS disconnect */
define|#
directive|define
name|RTS_ABORTED
value|13
comment|/* Peer aborted association */
define|#
directive|define
name|RTS_PARAMETER
value|14
comment|/* Invalid parameter */
define|#
directive|define
name|RTS_OPERATION
value|15
comment|/* Invalid operation */
define|#
directive|define
name|RTS_TIMER
value|16
comment|/* Timer expired */
define|#
directive|define
name|RTS_WAITING
value|17
comment|/* Indications waiting */
define|#
directive|define
name|RTS_TRANSFER
value|18
comment|/* Transfer failure (not really unofficial) */
comment|/* end UNOFFICIAL */
define|#
directive|define
name|RTS_FATAL
parameter_list|(
name|r
parameter_list|)
value|((r)< RTS_PARAMETER)
define|#
directive|define
name|RTS_OFFICIAL
parameter_list|(
name|r
parameter_list|)
value|((r)< RTS_ADDRESS)
name|PE
name|rta_udata
decl_stmt|;
comment|/* failure data from user */
comment|/* additional failure data from provider */
define|#
directive|define
name|RTA_SIZE
value|512
name|int
name|rta_cc
decl_stmt|;
comment|/*   length */
name|char
name|rta_data
index|[
name|RTA_SIZE
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RTAFREE
parameter_list|(
name|rta
parameter_list|)
define|\
value|{ \     if ((rta) -> rta_udata) \ 	pe_free ((rta) -> rta_udata), (rta) -> rta_udata = NULLPE; \ }
end_define

begin_struct
struct|struct
name|RtSAPclose
block|{
comment|/* RT-CLOSE.INDICATION */
name|int
name|rtc_dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RtSAPindication
block|{
name|int
name|rti_type
decl_stmt|;
comment|/* the union element present */
define|#
directive|define
name|RTI_TURN
value|0x00
define|#
directive|define
name|RTI_TRANSFER
value|0x01
define|#
directive|define
name|RTI_ABORT
value|0x02
define|#
directive|define
name|RTI_CLOSE
value|0x03
define|#
directive|define
name|RTI_FINISH
value|0x04
union|union
block|{
name|struct
name|RtSAPturn
name|rti_un_turn
decl_stmt|;
name|struct
name|RtSAPtransfer
name|rti_un_transfer
decl_stmt|;
name|struct
name|RtSAPabort
name|rti_un_abort
decl_stmt|;
name|struct
name|RtSAPclose
name|rti_un_close
decl_stmt|;
name|struct
name|AcSAPfinish
name|rti_un_finish
decl_stmt|;
block|}
name|rti_un
union|;
define|#
directive|define
name|rti_turn
value|rti_un.rti_un_turn
define|#
directive|define
name|rti_transfer
value|rti_un.rti_un_transfer
define|#
directive|define
name|rti_abort
value|rti_un.rti_un_abort
define|#
directive|define
name|rti_close
value|rti_un.rti_un_close
define|#
directive|define
name|rti_finish
value|rti_un.rti_un_finish
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
name|rtsapversion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RTSE primitives */
end_comment

begin_function_decl
name|int
name|RtInit_Aux
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-OPEN.INDICATION */
end_comment

begin_define
define|#
directive|define
name|RtInit
parameter_list|(
name|vecp
parameter_list|,
name|vec
parameter_list|,
name|rts
parameter_list|,
name|rti
parameter_list|)
define|\
value|RtInit_Aux((vecp),(vec),(rts),(rti),NULLOID)
end_define

begin_function_decl
name|int
name|RtOpenResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-OPEN.RESPONSE */
end_comment

begin_define
define|#
directive|define
name|RtOpenRequest
parameter_list|(
name|mode
parameter_list|,
name|turn
parameter_list|,
name|ctx
parameter_list|,
name|ct1
parameter_list|,
name|ct2
parameter_list|,
name|ca1
parameter_list|,
name|ca2
parameter_list|,
name|ctxl
parameter_list|,
name|defc
parameter_list|,
name|data
parameter_list|,
name|qos
parameter_list|,
name|rtc
parameter_list|,
name|rti
parameter_list|)
define|\
value|RtOpenRequest2((mode),(turn),(ctx),(ct1),(ct2),(ca1),(ca2),\ 		(ctxl),(defc),(data),(qos),NULLOID,(rtc),(rti))
end_define

begin_function_decl
name|int
name|RtOpenRequest2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-OPEN.REQUEST */
end_comment

begin_function_decl
name|int
name|RtCloseRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-CLOSE.REQUEST */
end_comment

begin_function_decl
name|int
name|RtCloseResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-CLOSE.RESPONSE */
end_comment

begin_function_decl
name|int
name|RtUAbortRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-U-ABORT.REQUEST */
end_comment

begin_comment
comment|/* X.410 primitives */
end_comment

begin_function_decl
name|int
name|RtExec
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* SERVER only */
end_comment

begin_function_decl
name|int
name|RtBInit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-BEGIN.INDICATION (X.410 OPEN.INDICATION) */
end_comment

begin_function_decl
name|int
name|RtBeginResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-BEGIN.RESPONSE (X.410 OPEN.RESPONSE) */
end_comment

begin_function_decl
name|int
name|RtBeginRequest2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-BEGIN.REQUEST (X.410 OPEN.REQUEST) */
end_comment

begin_define
define|#
directive|define
name|RtBeginRequest
parameter_list|(
name|called
parameter_list|,
name|mode
parameter_list|,
name|turn
parameter_list|,
name|data
parameter_list|,
name|rtc
parameter_list|,
name|rti
parameter_list|)
define|\
value|RtBeginRequest2((called), NULLRtA, (mode), (turn), (data), (rtc), (rti))
end_define

begin_function_decl
name|int
name|RtEndRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-END.REQUEST (X.410 CLOSE.REQUEST) */
end_comment

begin_function_decl
name|int
name|RtEndResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-END.RESPONSE (X.410 CLOSE.RESPONSE) */
end_comment

begin_function_decl
name|int
name|RtPTurnRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-TURN-PLEASE.REQUEST */
end_comment

begin_function_decl
name|int
name|RtGTurnRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-TURN-GIVE.REQUEST */
end_comment

begin_function_decl
name|int
name|RtTransferRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-TRANSFER.REQUEST */
end_comment

begin_function_decl
name|int
name|RtWaitRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RT-WAIT.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|RtSetIndications
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* define vectors for INDICATION events */
end_comment

begin_function_decl
name|int
name|RtSelectMask
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* map reliable transfer descriptors for 				   select() */
end_comment

begin_function_decl
name|int
name|RtSetDownTrans
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* set downtrans upcall */
end_comment

begin_function_decl
name|int
name|RtSetUpTrans
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* set uptrans upcall */
end_comment

begin_function_decl
name|char
modifier|*
name|RtErrString
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return RtSAP error code in string form */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

