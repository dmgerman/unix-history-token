begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tsap.h - include file for transport users (TS-USER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/tsap.h,v 7.4 91/02/22 09:25:16 mrose Interim $  *  *  * $Log:	tsap.h,v $  * Revision 7.4  91/02/22  09:25:16  mrose  * Interim 6.8  *   * Revision 7.3  90/11/21  11:32:15  mrose  * sun  *   * Revision 7.2  90/05/08  08:54:36  mrose  * touch-up  *   * Revision 7.1  89/12/18  17:50:50  mrose  * update  *   * Revision 7.0  89/11/23  21:56:08  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TSAP_
end_ifndef

begin_define
define|#
directive|define
name|_TSAP_
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
name|_ISOADDRS_
end_ifndef

begin_include
include|#
directive|include
file|"isoaddrs.h"
end_include

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
name|TSAPstart
block|{
comment|/* T-CONNECT.INDICATON */
name|int
name|ts_sd
decl_stmt|;
comment|/* TRANSPORT descriptor */
name|struct
name|TSAPaddr
name|ts_calling
decl_stmt|;
comment|/* address of peer calling */
name|struct
name|TSAPaddr
name|ts_called
decl_stmt|;
comment|/* address of peer called */
name|int
name|ts_expedited
decl_stmt|;
comment|/* EXPEDITED DATA ok */
name|int
name|ts_tsdusize
decl_stmt|;
comment|/* largest atomic TSDU */
name|struct
name|QOStype
name|ts_qos
decl_stmt|;
comment|/* quality of service */
comment|/* initial DATA from peer */
define|#
directive|define
name|TS_SIZE
value|32
name|int
name|ts_cc
decl_stmt|;
comment|/*   length */
name|char
name|ts_data
index|[
name|TS_SIZE
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|TSAPconnect
block|{
comment|/* T-CONNECT.CONFIRMATION */
name|int
name|tc_sd
decl_stmt|;
comment|/* TRANSPORT descriptor */
name|struct
name|TSAPaddr
name|tc_responding
decl_stmt|;
comment|/* address of peer responding */
name|int
name|tc_expedited
decl_stmt|;
comment|/* EXPEDITED DATA ok */
name|int
name|tc_tsdusize
decl_stmt|;
comment|/* largest atomic TSDU */
name|struct
name|QOStype
name|tc_qos
decl_stmt|;
comment|/* quality of service */
comment|/* initial DATA from peer */
define|#
directive|define
name|TC_SIZE
value|32
name|int
name|tc_cc
decl_stmt|;
comment|/*   length */
name|char
name|tc_data
index|[
name|TC_SIZE
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|TSAPdata
block|{
comment|/* T-READ.INDICATION */
name|int
name|tx_expedited
decl_stmt|;
comment|/* DATA from peer */
define|#
directive|define
name|TX_SIZE
value|16
comment|/* EXPEDITED DATA only */
name|int
name|tx_cc
decl_stmt|;
comment|/*   total length */
name|struct
name|qbuf
name|tx_qbuf
decl_stmt|;
comment|/*   chained data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TXFREE
parameter_list|(
name|tx
parameter_list|)
value|QBFREE (&((tx) -> tx_qbuf))
end_define

begin_struct
struct|struct
name|TSAPdisconnect
block|{
comment|/* T-DISCONNECT.INDICATION */
name|int
name|td_reason
decl_stmt|;
comment|/* reason for DISCONNECT, from ISO8072: */
define|#
directive|define
name|DR_BASE
value|0x80
define|#
directive|define
name|DR_NORMAL
value|(DR_BASE + 0)
comment|/* NORMAL disconnect by SESSION 					   entity */
define|#
directive|define
name|DR_REMOTE
value|(DR_BASE + 1)
comment|/* Remote TRANSPORT entity congested at 					   connect request time */
define|#
directive|define
name|DR_CONNECT
value|(DR_BASE + 2)
comment|/* Connection negotiation failed */
define|#
directive|define
name|DR_DUPLICATE
value|(DR_BASE + 3)
comment|/* Duplicate source reference detected 				           for the same pair of NSAPs */
define|#
directive|define
name|DR_MISMATCH
value|(DR_BASE + 4)
comment|/* Mismatched references */
define|#
directive|define
name|DR_PROTOCOL
value|(DR_BASE + 5)
comment|/* Protocol error */
define|#
directive|define
name|DR_OVERFLOW
value|(DR_BASE + 7)
comment|/* Reference overflow */
define|#
directive|define
name|DR_REFUSED
value|(DR_BASE + 8)
comment|/* Connect request refused on this 				           network connection */
define|#
directive|define
name|DR_LENGTH
value|(DR_BASE + 10)
comment|/* Header or parameter length 					   invalid */
comment|/* begin UNOFFICIAL */
define|#
directive|define
name|DR_NETWORK
value|(DR_BASE + 11)
comment|/* Network disconnect */
define|#
directive|define
name|DR_PARAMETER
value|(DR_BASE + 12)
comment|/* Invalid parameter */
define|#
directive|define
name|DR_OPERATION
value|(DR_BASE + 13)
comment|/* Invalid operation */
define|#
directive|define
name|DR_TIMER
value|(DR_BASE + 14)
comment|/* Timer expired */
define|#
directive|define
name|DR_WAITING
value|(DR_BASE + 15)
comment|/* Indications waiting */
comment|/* end UNOFFICIAL */
define|#
directive|define
name|DR_UNKNOWN
value|0
comment|/* Reason not specifed */
define|#
directive|define
name|DR_CONGEST
value|1
comment|/* Congestion at TSAP */
define|#
directive|define
name|DR_SESSION
value|2
comment|/* Session entity not attached to 					   TSAP */
define|#
directive|define
name|DR_ADDRESS
value|3
comment|/* Address unknown */
ifdef|#
directive|ifdef
name|notdef
define|#
directive|define
name|DR_FATAL
parameter_list|(
name|r
parameter_list|)
value|((r)< DR_BASE || (r)< DR_PARAMETER)
define|#
directive|define
name|DR_OFFICIAL
parameter_list|(
name|r
parameter_list|)
value|((r)< DR_BASE || (r)< DR_NETWORK)
else|#
directive|else
define|#
directive|define
name|DR_FATAL
parameter_list|(
name|r
parameter_list|)
value|((r)< DR_PARAMETER)
define|#
directive|define
name|DR_OFFICIAL
parameter_list|(
name|r
parameter_list|)
value|((r)< DR_NETWORK)
endif|#
directive|endif
define|#
directive|define
name|DR_CONS
value|256
comment|/* Base for CONS reson codes */
define|#
directive|define
name|DR_CONS_UNDEFINED
value|DR_CONS+0
comment|/* Undefined */
comment|/* originator: NS_PROVIDER */
define|#
directive|define
name|DR_CONS_PROVIDER
value|DR_CONS+224
comment|/* GENERIC */
define|#
directive|define
name|DR_CP_DIS_TRANS
value|DR_CONS+225
comment|/* Disconnect - transient */
define|#
directive|define
name|DR_CP_DIS_PERM
value|DR_CONS+226
comment|/* Disconnect - permanent */
define|#
directive|define
name|DR_CP_REJ_UNSPEC_TRANS
value|DR_CONS+227
comment|/* Reject - transient */
define|#
directive|define
name|DR_CP_REJ_UNSPEC_PERM
value|DR_CONS+228
comment|/* Reject - permanent */
define|#
directive|define
name|DR_CP_REJ_NO_QOS_TRANS
value|DR_CONS+229
comment|/* No QOS - transient */
define|#
directive|define
name|DR_CP_REJ_NO_QOS_PERM
value|DR_CONS+230
comment|/* No QOS - permanent */
define|#
directive|define
name|DR_CP_REJ_NSAP_UNREACH_TRANS
value|DR_CONS+231
comment|/* NSAP unreachable */
define|#
directive|define
name|DR_CP_REJ_NSAP_UNREACH_PERM
value|DR_CONS+232
comment|/* NSAP unreachable */
define|#
directive|define
name|DR_CP_RESET_UNSPEC
value|DR_CONS+233
comment|/* Unspecified RESET */
define|#
directive|define
name|DR_CP_RESET_CONGESTION
value|DR_CONS+234
comment|/* RESET due to congestion */
define|#
directive|define
name|DR_CP_REJ_NSAP_UNKNOWN_PERM
value|DR_CONS+235
comment|/* Unknown NSAP */
comment|/* originator: NS_USER */
define|#
directive|define
name|DR_CONS_USER
value|DR_CONS+240
comment|/* GENERIC */
define|#
directive|define
name|DR_CU_DIS_NORMAL
value|DR_CONS+241
comment|/* Normal disconnect */
define|#
directive|define
name|DR_CU_DIS_ABNORMAL
value|DR_CONS+242
comment|/* Abnormal disconnect */
define|#
directive|define
name|DR_CU_REJ_UNSPEC_TRANS
value|DR_CONS+244
comment|/* Reject - transient */
define|#
directive|define
name|DR_CU_REJ_UNSPEC_PERM
value|DR_CONS+245
comment|/* Reject - permanent */
define|#
directive|define
name|DR_CU_REJ_NO_QOS_TRANS
value|DR_CONS+246
comment|/* No QOS - transient */
define|#
directive|define
name|DR_CU_REJ_NO_QOS_PERM
value|DR_CONS+247
comment|/* No QOS - permanent */
define|#
directive|define
name|DR_CU_REJ_INCOMPAT
value|DR_CONS+248
comment|/* Incompatable NS user data */
define|#
directive|define
name|DR_CU_RESET_USER_RESYNCH
value|DR_CONS+250
comment|/* User RESET */
comment|/* disconnect DATA from peer */
define|#
directive|define
name|TD_SIZE
value|64
name|int
name|td_cc
decl_stmt|;
comment|/*   length */
name|char
name|td_data
index|[
name|TD_SIZE
index|]
decl_stmt|;
comment|/*   data */
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
name|tsapversion
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|TInit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* T-CONNECT.INDICATION */
end_comment

begin_function_decl
name|int
name|TConnResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* T-CONNECT.RESPONSE */
end_comment

begin_comment
comment|/* T-CONNECT.REQUEST (backwards-compatible) */
end_comment

begin_define
define|#
directive|define
name|TConnRequest
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|,
name|a7
parameter_list|,
name|a8
parameter_list|)
define|\
value|TAsynConnRequest(a1,a2,a3,a4,a5,a6,a7,a8,0)
end_define

begin_function_decl
name|int
name|TAsynConnRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* T-(ASYN-)CONNECT.REQUEST */
end_comment

begin_function_decl
name|int
name|TAsynRetryRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* T-ASYN-RETRY.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|TDataRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* T-DATA.REQUEST */
end_comment

begin_function_decl
name|int
name|TWriteRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* T-WRITE.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|TExpdRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* T-EXPEDITED-DATA.REQUEST */
end_comment

begin_function_decl
name|int
name|TReadRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* T-READ.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|TDiscRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* T-DISCONNECT.REQUEST */
end_comment

begin_function_decl
name|int
name|TSetIndications
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* define vectors for INDICATION events */
end_comment

begin_function_decl
name|int
name|TSelectMask
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* map transport descriptors for select() */
end_comment

begin_function_decl
name|int
name|TSelectOctets
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* estimate of octets that might be returned */
end_comment

begin_function_decl
name|int
name|TGetAddresses
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get TSAPs */
end_comment

begin_function_decl
name|int
name|TSetManager
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* defining transport manager */
end_comment

begin_function_decl
name|char
modifier|*
name|TErrString
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return TSAP error code in string form */
end_comment

begin_function_decl
name|int
name|TNetListen
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* start listenting on an TSAP */
end_comment

begin_function_decl
name|int
name|TNetUnique
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* start listenting on a set of unique TSAPs */
end_comment

begin_define
define|#
directive|define
name|TNetAccept
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|,
name|r
parameter_list|,
name|w
parameter_list|,
name|e
parameter_list|,
name|s
parameter_list|,
name|t
parameter_list|)
define|\
value|TNetAcceptAux ((p), (v), NULLIP, NULLTA, (n), (r), (w), (e), (s), (t))
end_define

begin_function_decl
name|int
name|TNetAcceptAux
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* accept a call on an TSAP */
end_comment

begin_function_decl
name|int
name|TNetClose
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* stop listening on an TSAP */
end_comment

begin_function_decl
name|int
name|TSetQueuesOK
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* enable/disable queued (non-blocking) 				   writes */
end_comment

begin_define
define|#
directive|define
name|TLocalHostName
value|getlocalhost
end_define

begin_function_decl
name|char
modifier|*
name|TLocalHostName
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return name of local host (sigh) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

