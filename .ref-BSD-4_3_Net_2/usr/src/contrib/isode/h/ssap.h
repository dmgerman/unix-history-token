begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ssap.h - include file for session users (SS-USER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/ssap.h,v 7.2 91/02/22 09:25:09 mrose Interim $  *  *  * $Log:	ssap.h,v $  * Revision 7.2  91/02/22  09:25:09  mrose  * Interim 6.8  *   * Revision 7.1  91/01/10  04:11:13  mrose  * foo  *   * Revision 7.0  89/11/23  21:56:02  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SSAP_
end_ifndef

begin_define
define|#
directive|define
name|_SSAP_
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
name|SSAPactid
block|{
comment|/* Activity Identifier */
define|#
directive|define
name|SID_DATA_SIZE
value|6
name|u_char
name|sd_len
decl_stmt|;
name|char
name|sd_data
index|[
name|SID_DATA_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|SSAPref
block|{
comment|/* SSAP reference */
comment|/* USER reference */
define|#
directive|define
name|SREF_USER_SIZE
value|64
name|u_char
name|sr_ulen
decl_stmt|;
name|char
name|sr_udata
index|[
name|SREF_USER_SIZE
index|]
decl_stmt|;
comment|/* COMMON reference */
define|#
directive|define
name|SREF_COMM_SIZE
value|64
name|u_char
name|sr_clen
decl_stmt|;
name|char
name|sr_cdata
index|[
name|SREF_COMM_SIZE
index|]
decl_stmt|;
comment|/* ADDITIONAL reference */
define|#
directive|define
name|SREF_ADDT_SIZE
value|4
name|u_char
name|sr_alen
decl_stmt|;
name|char
name|sr_adata
index|[
name|SREF_ADDT_SIZE
index|]
decl_stmt|;
comment|/* for S-ACTIVITY-RESUME */
name|u_char
name|sr_vlen
decl_stmt|;
name|char
name|sr_vdata
index|[
name|SREF_USER_SIZE
index|]
decl_stmt|;
define|#
directive|define
name|sr_calling
value|sr_udata
define|#
directive|define
name|sr_calling_len
value|sr_ulen
define|#
directive|define
name|sr_called
value|sr_vdata
define|#
directive|define
name|sr_called_len
value|sr_vlen
block|}
struct|;
end_struct

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|SSAPstart
block|{
comment|/* S-CONNECT.INDICATION */
name|int
name|ss_sd
decl_stmt|;
comment|/* SESSION descriptor */
name|struct
name|SSAPref
name|ss_connect
decl_stmt|;
comment|/* session connection identifier */
name|struct
name|SSAPaddr
name|ss_calling
decl_stmt|;
comment|/* address of peer calling */
name|struct
name|SSAPaddr
name|ss_called
decl_stmt|;
comment|/* address of peer called */
name|int
name|ss_requirements
decl_stmt|;
comment|/* session requirements */
name|int
name|ss_settings
decl_stmt|;
comment|/* initial settings of tokens */
name|long
name|ss_isn
decl_stmt|;
comment|/* initial serial number */
name|int
name|ss_ssdusize
decl_stmt|;
comment|/* largest atomic SSDU */
name|struct
name|QOStype
name|ss_qos
decl_stmt|;
comment|/* quality of service */
comment|/* initial DATA from peer */
define|#
directive|define
name|SS_SIZE
value|512
name|int
name|ss_cc
decl_stmt|;
comment|/*   length */
name|char
modifier|*
name|ss_data
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SSFREE
parameter_list|(
name|ss
parameter_list|)
define|\
value|{ \     if ((ss) -> ss_data) \ 	free ((ss) -> ss_data), (ss) -> ss_data = NULL; \ }
end_define

begin_struct
struct|struct
name|SSAPconnect
block|{
comment|/* S-CONNECT.CONFIRMATION */
name|int
name|sc_sd
decl_stmt|;
comment|/* SESSION descriptor */
name|struct
name|SSAPref
name|sc_connect
decl_stmt|;
comment|/* session connection identifier */
name|struct
name|SSAPaddr
name|sc_responding
decl_stmt|;
comment|/* address of peer responding */
name|int
name|sc_result
decl_stmt|;
comment|/* result */
define|#
directive|define
name|SC_ACCEPT
value|(-1)
define|#
directive|define
name|SC_BASE
value|0x80
comment|/* reject by SSAP-provider */
define|#
directive|define
name|SC_SSAPID
value|(SC_BASE + 1)
comment|/* SSAP identifier unknown */
define|#
directive|define
name|SC_SSUSER
value|(SC_BASE + 2)
comment|/* SS-user not attached to SSAP */
define|#
directive|define
name|SC_CONGEST
value|(SC_BASE + 3)
comment|/* Congestion at SSAP */
define|#
directive|define
name|SC_VERSION
value|(SC_BASE + 4)
comment|/* Proposed protocol versions not 					   supported */
comment|/* begin UNOFFICIAL */
define|#
directive|define
name|SC_ADDRESS
value|(SC_BASE + 5)
comment|/* Address unknown */
define|#
directive|define
name|SC_REFUSED
value|(SC_BASE + 6)
comment|/* Connect request refused on this 				           network connection */
define|#
directive|define
name|SC_TRANSPORT
value|(SC_BASE + 7)
comment|/* Transport disconnect */
define|#
directive|define
name|SC_ABORT
value|(SC_BASE + 8)
comment|/* Provider-initiated abort */
define|#
directive|define
name|SC_PROTOCOL
value|(SC_BASE + 9)
comment|/* Protocol error */
define|#
directive|define
name|SC_PARAMETER
value|(SC_BASE + 10)
comment|/* Invalid parameter */
define|#
directive|define
name|SC_OPERATION
value|(SC_BASE + 11)
comment|/* Invalid operation */
define|#
directive|define
name|SC_TIMER
value|(SC_BASE + 12)
comment|/* Timer expired */
define|#
directive|define
name|SC_WAITING
value|(SC_BASE + 13)
comment|/* Indications waiting */
comment|/* end UNOFFICIAL */
comment|/* reject by SSAP-user */
define|#
directive|define
name|SC_NOTSPECIFIED
value|0
comment|/* Reason not specified */
define|#
directive|define
name|SC_CONGESTION
value|1
comment|/* Temporary congestion */
define|#
directive|define
name|SC_REJECTED
value|2
comment|/* Rejected */
ifdef|#
directive|ifdef
name|notdef
define|#
directive|define
name|SC_FATAL
parameter_list|(
name|r
parameter_list|)
value|((r)< SC_BASE || (r)< SC_PARAMETER)
define|#
directive|define
name|SC_OFFICIAL
parameter_list|(
name|r
parameter_list|)
value|((r)< SC_BASE || (r)< SC_ADDRESS)
else|#
directive|else
define|#
directive|define
name|SC_FATAL
parameter_list|(
name|r
parameter_list|)
value|((r)< SC_PARAMETER)
define|#
directive|define
name|SC_OFFICIAL
parameter_list|(
name|r
parameter_list|)
value|((r)< SC_ADDRESS)
endif|#
directive|endif
name|int
name|sc_requirements
decl_stmt|;
comment|/* session requirements */
name|int
name|sc_settings
decl_stmt|;
comment|/* initial assignment of tokens */
name|int
name|sc_please
decl_stmt|;
comment|/* tokens requested by SS-user 				   (S-TOKEN-PLEASE.INDICATION) */
name|long
name|sc_isn
decl_stmt|;
comment|/* initial serial number */
name|int
name|sc_ssdusize
decl_stmt|;
comment|/* largest atomic SSDU */
name|struct
name|QOStype
name|sc_qos
decl_stmt|;
comment|/* quality of service */
comment|/* initial DATA from peer */
ifdef|#
directive|ifdef
name|HPUX
undef|#
directive|undef
name|SC_SIZE
endif|#
directive|endif
define|#
directive|define
name|SC_SIZE
value|512
name|int
name|sc_cc
decl_stmt|;
comment|/*   length */
name|char
modifier|*
name|sc_data
decl_stmt|;
comment|/*   data */
name|char
modifier|*
name|sc_realdata
decl_stmt|;
comment|/*   real head of data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCFREE
parameter_list|(
name|sc
parameter_list|)
define|\
value|{ \     if ((sc) -> sc_realdata) \ 	free ((sc) -> sc_realdata), \ 	    (sc) -> sc_realdata = (sc) -> sc_data = NULL; \     else \ 	if ((sc) -> sc_data) \ 	    free ((sc) -> sc_data), (sc) -> sc_data = NULL; \ }
end_define

begin_comment
comment|/* SESSION requirements */
end_comment

begin_define
define|#
directive|define
name|SR_HALFDUPLEX
value|0x0001
end_define

begin_comment
comment|/* half-duplex */
end_comment

begin_define
define|#
directive|define
name|SR_DUPLEX
value|0x0002
end_define

begin_comment
comment|/* full-duplex */
end_comment

begin_define
define|#
directive|define
name|SR_EXPEDITED
value|0x0004
end_define

begin_comment
comment|/* expedited data transfer */
end_comment

begin_define
define|#
directive|define
name|SR_MINORSYNC
value|0x0008
end_define

begin_comment
comment|/* minor synchronize */
end_comment

begin_define
define|#
directive|define
name|SR_MAJORSYNC
value|0x0010
end_define

begin_comment
comment|/* major synchronize */
end_comment

begin_define
define|#
directive|define
name|SR_RESYNC
value|0x0020
end_define

begin_comment
comment|/* resynchronize */
end_comment

begin_define
define|#
directive|define
name|SR_ACTIVITY
value|0x0040
end_define

begin_comment
comment|/* activity management */
end_comment

begin_define
define|#
directive|define
name|SR_NEGOTIATED
value|0x0080
end_define

begin_comment
comment|/* negotiated release */
end_comment

begin_define
define|#
directive|define
name|SR_CAPABILITY
value|0x0100
end_define

begin_comment
comment|/* capability data transfer */
end_comment

begin_define
define|#
directive|define
name|SR_EXCEPTIONS
value|0x0200
end_define

begin_comment
comment|/* exceptions reporting */
end_comment

begin_define
define|#
directive|define
name|SR_TYPEDATA
value|0x0400
end_define

begin_comment
comment|/* typed data transfer */
end_comment

begin_define
define|#
directive|define
name|SR_SYMMETRIC
value|0x0800
end_define

begin_comment
comment|/* symmetric synchronize */
end_comment

begin_define
define|#
directive|define
name|SR_RLS_EXISTS
value|SR_NEGOTIATED
end_define

begin_define
define|#
directive|define
name|SR_MAJ_EXISTS
value|(SR_MAJORSYNC | SR_ACTIVITY)
end_define

begin_define
define|#
directive|define
name|SR_ACT_EXISTS
value|SR_ACTIVITY
end_define

begin_define
define|#
directive|define
name|SR_MIN_EXISTS
value|SR_MINORSYNC
end_define

begin_define
define|#
directive|define
name|SR_DAT_EXISTS
value|SR_HALFDUPLEX
end_define

begin_define
define|#
directive|define
name|SR_TOKENS
value|(SR_RLS_EXISTS | SR_MAJ_EXISTS | SR_ACT_EXISTS \ 			    | SR_MIN_EXISTS | SR_DAT_EXISTS)
end_define

begin_define
define|#
directive|define
name|SR_BASUBSET
value|(SR_HALFDUPLEX | SR_TYPEDATA | SR_CAPABILITY \ 			    | SR_MINORSYNC | SR_EXCEPTIONS | SR_ACTIVITY)
end_define

begin_define
define|#
directive|define
name|SR_BCSUBSET
value|(SR_HALFDUPLEX | SR_DUPLEX)
end_define

begin_define
define|#
directive|define
name|SR_BSSUBSET
value|(SR_NEGOTIATED | SR_HALFDUPLEX | SR_DUPLEX \ 			    | SR_TYPEDATA | SR_MINORSYNC | SR_MAJORSYNC \ 			    | SR_RESYNC)
end_define

begin_define
define|#
directive|define
name|SR_MYREQUIRE
value|(SR_BASUBSET | SR_BCSUBSET | SR_BSSUBSET \ 			    | SR_EXPEDITED)
end_define

begin_define
define|#
directive|define
name|SR_DEFAULT
value|(SR_HALFDUPLEX | SR_MINORSYNC | SR_ACTIVITY \ 			    | SR_CAPABILITY | SR_EXCEPTIONS)
end_define

begin_comment
comment|/* SESSION tokens */
end_comment

begin_define
define|#
directive|define
name|ST_INIT_VALUE
value|0x00
end_define

begin_comment
comment|/* initiator's side */
end_comment

begin_define
define|#
directive|define
name|ST_RESP_VALUE
value|0x01
end_define

begin_comment
comment|/* responder's side */
end_comment

begin_define
define|#
directive|define
name|ST_CALL_VALUE
value|0x02
end_define

begin_comment
comment|/* called SS-user's choice */
end_comment

begin_define
define|#
directive|define
name|ST_RSVD_VALUE
value|0x03
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|ST_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|ST_RLS_SHIFT
value|6
end_define

begin_comment
comment|/* release token */
end_comment

begin_define
define|#
directive|define
name|ST_MAJ_SHIFT
value|4
end_define

begin_comment
comment|/* major/activity token */
end_comment

begin_define
define|#
directive|define
name|ST_ACT_SHIFT
value|ST_MAJ_SHIFT
end_define

begin_define
define|#
directive|define
name|ST_MIN_SHIFT
value|2
end_define

begin_comment
comment|/* synchronize-minor token */
end_comment

begin_define
define|#
directive|define
name|ST_DAT_SHIFT
value|0
end_define

begin_comment
comment|/* data token */
end_comment

begin_define
define|#
directive|define
name|dotokens
parameter_list|()
define|\
value|{ \     dotoken (SR_RLS_EXISTS, ST_RLS_SHIFT, ST_RLS_TOKEN, "release"); \     dotoken (SR_MAJ_EXISTS, ST_MAJ_SHIFT, ST_MAJ_TOKEN, "majorsync"); \     dotoken (SR_MIN_EXISTS, ST_MIN_SHIFT, ST_MIN_TOKEN, "minorsync"); \     dotoken (SR_DAT_EXISTS, ST_DAT_SHIFT, ST_DAT_TOKEN, "data"); \ }
end_define

begin_struct
struct|struct
name|SSAPdata
block|{
comment|/* S-READ.INDICATION */
name|int
name|sx_type
decl_stmt|;
comment|/* type of indication */
define|#
directive|define
name|SX_NORMAL
value|0x00
comment|/* S-DATA.INDICATION */
define|#
directive|define
name|SX_EXPEDITED
value|0x01
comment|/* S-EXPEDITED-DATA.INDICATION */
define|#
directive|define
name|SX_TYPED
value|0x02
comment|/* S-TYPED-DATA.INDICATION */
define|#
directive|define
name|SX_CAPDIND
value|0x03
comment|/* S-CAPABILITY-DATA.INDICATION */
define|#
directive|define
name|SX_CAPDCNF
value|0x04
comment|/* S-CAPABILITY-DATA.CONFIRMATION */
define|#
directive|define
name|SX_EXSIZE
value|14
comment|/* EXPEDITED DATA (XSSDU) only */
define|#
directive|define
name|SX_CDSIZE
value|512
comment|/* CAPABILITY DATA only */
define|#
directive|define
name|SX_CDASIZE
value|512
comment|/* CAPABILITY DATA ACK only */
name|int
name|sx_cc
decl_stmt|;
comment|/*   total length */
name|struct
name|qbuf
name|sx_qbuf
decl_stmt|;
comment|/*   chained data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SXFREE
parameter_list|(
name|sx
parameter_list|)
value|QBFREE (&((sx) -> sx_qbuf))
end_define

begin_struct
struct|struct
name|SSAPtoken
block|{
comment|/* S-{TOKEN-*,GIVE-CONTROL}.INDICATION */
name|int
name|st_type
decl_stmt|;
comment|/* type of indication */
define|#
directive|define
name|ST_GIVE
value|0x00
comment|/* S-TOKEN-GIVE.INDICATION */
define|#
directive|define
name|ST_PLEASE
value|0x01
comment|/* S-TOKEN-PLEASE.INDICATION */
define|#
directive|define
name|ST_CONTROL
value|0x02
comment|/* S-GIVE-CONTROL.INDICATION */
name|u_char
name|st_tokens
decl_stmt|;
comment|/* tokens offered/wanted */
define|#
directive|define
name|ST_RLS_TOKEN
value|(0x01<< ST_RLS_SHIFT)
define|#
directive|define
name|ST_MAJ_TOKEN
value|(0x01<< ST_MAJ_SHIFT)
define|#
directive|define
name|ST_ACT_TOKEN
value|(0x01<< ST_ACT_SHIFT)
define|#
directive|define
name|ST_MIN_TOKEN
value|(0x01<< ST_MIN_SHIFT)
define|#
directive|define
name|ST_DAT_TOKEN
value|(0x01<< ST_DAT_SHIFT)
name|u_char
name|st_owned
decl_stmt|;
comment|/* tokens owned by user */
define|#
directive|define
name|ST_SIZE
value|512
comment|/* PLEASE TOKEN only */
name|int
name|st_cc
decl_stmt|;
comment|/*   length */
name|char
modifier|*
name|st_data
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STFREE
parameter_list|(
name|st
parameter_list|)
define|\
value|{ \     if ((st) -> st_data) \ 	free ((st) -> st_data), (st) -> st_data = NULL; \ }
end_define

begin_struct
struct|struct
name|SSAPsync
block|{
comment|/* S-*-SYNC.{INDICATION,CONFIRMATION} */
name|int
name|sn_type
decl_stmt|;
comment|/* type of indication/confirmation */
define|#
directive|define
name|SN_MAJORIND
value|0x00
comment|/* S-MAJOR-SYNC.INDICATION */
define|#
directive|define
name|SN_MAJORCNF
value|0x01
comment|/* S-MAJOR-SYNC.CONFIRMATION */
define|#
directive|define
name|SN_MINORIND
value|0x02
comment|/* S-MINOR-SYNC.INDICATION */
define|#
directive|define
name|SN_MINORCNF
value|0x03
comment|/* S-MINOR-SYNC.CONFIRMATION */
define|#
directive|define
name|SN_RESETIND
value|0x04
comment|/* S-RESYNCHRONIZE.INDICATION */
define|#
directive|define
name|SN_RESETCNF
value|0x05
comment|/* S-RESYNCHRONIZE.CONFIRMATION */
name|int
name|sn_options
decl_stmt|;
comment|/* options (!!) */
comment|/* for S-MINOR-SYNC.INDICATION */
define|#
directive|define
name|SYNC_CONFIRM
value|1
comment|/* wants confirmation */
define|#
directive|define
name|SYNC_NOCONFIRM
value|0
comment|/*   .. nope */
comment|/* for S-RESYNCHRONIZE.INDICATION */
define|#
directive|define
name|SYNC_RESTART
value|0
comment|/* restart */
define|#
directive|define
name|SYNC_ABANDON
value|1
comment|/* abandon */
define|#
directive|define
name|SYNC_SET
value|2
comment|/* set */
name|long
name|sn_ssn
decl_stmt|;
comment|/* serial number */
define|#
directive|define
name|SERIAL_NONE
value|(-1L)
comment|/* No SSN */
define|#
directive|define
name|SERIAL_MIN
value|000000L
comment|/* the min SSN */
define|#
directive|define
name|SERIAL_MAX
value|999998L
comment|/* the max SSN */
name|int
name|sn_settings
decl_stmt|;
comment|/* new token settings (RESYNC only) */
comment|/* sync data from peer */
define|#
directive|define
name|SN_SIZE
value|512
name|int
name|sn_cc
decl_stmt|;
comment|/*   length */
name|char
modifier|*
name|sn_data
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SNFREE
parameter_list|(
name|sn
parameter_list|)
define|\
value|{ \     if ((sn) -> sn_data) \ 	free ((sn) -> sn_data), (sn) -> sn_data = NULL; \ }
end_define

begin_struct
struct|struct
name|SSAPactivity
block|{
comment|/* S-ACTIVITY-*.{INDICATION,CONFIRMATION} */
name|int
name|sv_type
decl_stmt|;
comment|/* type of indication/confirmation */
define|#
directive|define
name|SV_START
value|0x00
comment|/* S-ACTIVITY-START.INDICATION */
define|#
directive|define
name|SV_RESUME
value|0x01
comment|/* S-ACTIVITY-RESUME.INDICATION */
define|#
directive|define
name|SV_INTRIND
value|0x02
comment|/* S-ACTIVITY-INTERRUPT.INDICATION */
define|#
directive|define
name|SV_INTRCNF
value|0x03
comment|/* S-ACTIVITY-INTERRUPT.CONFIRMATION */
define|#
directive|define
name|SV_DISCIND
value|0x04
comment|/* S-ACTIVITY-DISCARD.INDICATION */
define|#
directive|define
name|SV_DISCCNF
value|0x05
comment|/* S-ACTIVITY-DISCARD.CONFIRMATION */
define|#
directive|define
name|SV_ENDIND
value|0x06
comment|/* S-ACTIVITY-END.INDICATION */
define|#
directive|define
name|SV_ENDCNF
value|0x07
comment|/* S-ACTIVITY-END.CONFIRMATION */
name|struct
name|SSAPactid
name|sv_id
decl_stmt|;
comment|/* START/RESUME activity identifier */
name|struct
name|SSAPactid
name|sv_oid
decl_stmt|;
comment|/* RESUME old activity identifier */
name|struct
name|SSAPref
name|sv_connect
decl_stmt|;
comment|/* 	  old connection identifier */
name|long
name|sv_ssn
decl_stmt|;
comment|/* RESUME/END Serial number */
name|int
name|sv_reason
decl_stmt|;
comment|/* INTERRUPT/DISCARD */
comment|/* same values as sp_reason */
comment|/* activity DATA from peer */
define|#
directive|define
name|SV_SIZE
value|512
name|int
name|sv_cc
decl_stmt|;
comment|/*   length */
name|char
modifier|*
name|sv_data
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SVFREE
parameter_list|(
name|sv
parameter_list|)
define|\
value|{ \     if ((sv) -> sv_data) \ 	free ((sv) -> sv_data), (sv) -> sv_data = NULL; \ }
end_define

begin_struct
struct|struct
name|SSAPreport
block|{
comment|/* S-{U,P}-EXCEPTION-REPORT.INDICATION */
name|int
name|sp_peer
decl_stmt|;
comment|/* T   = S-U-EXCEPTION-REPORT.INDICATION: 					sp_reason/sp_data both meaningful 				   NIL = S-P-EXCEPTION-REPORT.INDICATION: 					sp_reason == SP_NOREASON, or 					sp_reason == SP_PROTOCOL */
name|int
name|sp_reason
decl_stmt|;
define|#
directive|define
name|SP_NOREASON
value|0
comment|/* No specific reason stated */
define|#
directive|define
name|SP_JEOPARDY
value|1
comment|/* User receiving ability jeopardized */
define|#
directive|define
name|SP_RSVD1
value|2
comment|/* reserved */
define|#
directive|define
name|SP_SEQUENCE
value|3
comment|/* User sequence error */
define|#
directive|define
name|SP_RSVD2
value|4
comment|/* reserved */
define|#
directive|define
name|SP_LOCAL
value|5
comment|/* Local SS-user error */
define|#
directive|define
name|SP_PROCEDURAL
value|6
comment|/* Unrecoverable procedural error */
define|#
directive|define
name|SP_DEMAND
value|128
comment|/* Demand data token */
define|#
directive|define
name|SP_PROTOCOL
value|(-1)
comment|/* SS-provider protocol error */
comment|/* report DATA from peer */
define|#
directive|define
name|SP_SIZE
value|512
name|int
name|sp_cc
decl_stmt|;
comment|/*   length */
name|char
modifier|*
name|sp_data
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SPFREE
parameter_list|(
name|sp
parameter_list|)
define|\
value|{ \     if ((sp) -> sp_data) \ 	free ((sp) -> sp_data), (sp) -> sp_data = NULL; \ }
end_define

begin_struct
struct|struct
name|SSAPfinish
block|{
comment|/* S-RELEASE.INDICATION */
comment|/* release DATA from peer */
define|#
directive|define
name|SF_SIZE
value|512
name|int
name|sf_cc
decl_stmt|;
comment|/*   length */
name|char
modifier|*
name|sf_data
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SFFREE
parameter_list|(
name|sf
parameter_list|)
define|\
value|{ \     if ((sf) -> sf_data) \ 	free ((sf) -> sf_data), (sf) -> sf_data = NULL; \ }
end_define

begin_struct
struct|struct
name|SSAPrelease
block|{
comment|/* S-RELEASE.CONFIRMATION */
name|int
name|sr_affirmative
decl_stmt|;
comment|/* T   = connection released 				   NIL = request refused */
comment|/* release DATA from peer */
define|#
directive|define
name|SR_SIZE
value|512
name|int
name|sr_cc
decl_stmt|;
comment|/*   length */
name|char
modifier|*
name|sr_data
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SRFREE
parameter_list|(
name|sr
parameter_list|)
define|\
value|{ \     if ((sr) -> sr_data) \ 	free ((sr) -> sr_data), (sr) -> sr_data = NULL; \ }
end_define

begin_struct
struct|struct
name|SSAPabort
block|{
comment|/* S-{U,P}-ABORT.INDICATION */
name|int
name|sa_peer
decl_stmt|;
comment|/* T   = S-U-ABORT.INDICATION: 					     sa_info/sa_cc is meaningful 				   NIL = S-P-ABORT.INDICATION: 					     sa_reason is meaningful, 					     sa_data/sa_cc contains diagnostics */
name|int
name|sa_reason
decl_stmt|;
comment|/* same codes as sc_result */
comment|/* abort DATA from peer */
define|#
directive|define
name|SA_SIZE
value|512
comment|/* N.B.: the ISO DIS says 9, but we use 				   512 instead so ASE-level aborts will work 				   reasonably */
name|int
name|sa_cc
decl_stmt|;
comment|/*   length */
name|char
modifier|*
name|sa_info
decl_stmt|;
comment|/*   data (from the peer) */
name|char
modifier|*
name|sa_realinfo
decl_stmt|;
comment|/*   real head of data */
name|char
name|sa_data
index|[
literal|512
index|]
decl_stmt|;
comment|/*   data (for messages from provider) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SAFREE
parameter_list|(
name|sa
parameter_list|)
define|\
value|{ \     if ((sa) -> sa_realinfo) \ 	free ((sa) -> sa_realinfo), (sa) -> sa_realinfo = NULL; \ }
end_define

begin_struct
struct|struct
name|SSAPindication
block|{
name|int
name|si_type
decl_stmt|;
comment|/* the union element present */
define|#
directive|define
name|SI_DATA
value|0x00
define|#
directive|define
name|SI_TOKEN
value|0x01
define|#
directive|define
name|SI_SYNC
value|0x02
define|#
directive|define
name|SI_ACTIVITY
value|0x03
define|#
directive|define
name|SI_REPORT
value|0x04
define|#
directive|define
name|SI_FINISH
value|0x05
define|#
directive|define
name|SI_ABORT
value|0x06
union|union
block|{
name|struct
name|SSAPdata
name|si_un_data
decl_stmt|;
name|struct
name|SSAPtoken
name|si_un_token
decl_stmt|;
name|struct
name|SSAPsync
name|si_un_sync
decl_stmt|;
name|struct
name|SSAPactivity
name|si_un_activity
decl_stmt|;
name|struct
name|SSAPreport
name|si_un_report
decl_stmt|;
name|struct
name|SSAPfinish
name|si_un_finish
decl_stmt|;
name|struct
name|SSAPabort
name|si_un_abort
decl_stmt|;
block|}
name|si_un
union|;
define|#
directive|define
name|si_data
value|si_un.si_un_data
define|#
directive|define
name|si_token
value|si_un.si_un_token
define|#
directive|define
name|si_sync
value|si_un.si_un_sync
define|#
directive|define
name|si_activity
value|si_un.si_un_activity
define|#
directive|define
name|si_report
value|si_un.si_un_report
define|#
directive|define
name|si_finish
value|si_un.si_un_finish
define|#
directive|define
name|si_abort
value|si_un.si_un_abort
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
name|ssapversion
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|SExec
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* SERVER only */
end_comment

begin_function_decl
name|int
name|SInit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-CONNECT.INDICATION */
end_comment

begin_function_decl
name|int
name|SConnResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-CONNECT.RESPONSE */
end_comment

begin_function_decl
name|int
name|SConnRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-CONNECT.REQUEST (backwards-compatible) */
end_comment

begin_define
define|#
directive|define
name|SConnRequest
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
parameter_list|,
name|a9
parameter_list|,
name|a10
parameter_list|,
name|a11
parameter_list|)
define|\
value|SAsynConnRequest (a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,0)
end_define

begin_function_decl
name|int
name|SAsynConnRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-(ASYN-)CONNECT.REQUEST */
end_comment

begin_function_decl
name|int
name|SAsynRetryRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-ASYN-RETRY.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|SDataRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-DATA.REQUEST */
end_comment

begin_function_decl
name|int
name|SSendRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-SEND.REQUEST (segmented) */
end_comment

begin_function_decl
name|int
name|SWriteRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-WRITE.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|SExpdRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-EXPEDITED-DATA.REQUEST */
end_comment

begin_function_decl
name|int
name|STypedRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-TYPED-DATA.REQUEST */
end_comment

begin_function_decl
name|int
name|SCapdRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-CAPABILITY-DATA.REQUEST */
end_comment

begin_function_decl
name|int
name|SCapdResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-CAPABILITY-DATA.RESPONSE */
end_comment

begin_function_decl
name|int
name|SReadRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-READ.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|SGTokenRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-TOKEN-GIVE.REQUEST */
end_comment

begin_function_decl
name|int
name|SPTokenRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-TOKEN-PLEASE.REQUEST */
end_comment

begin_function_decl
name|int
name|SGControlRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-CONTROL-GIVE.REQUEST */
end_comment

begin_function_decl
name|int
name|SMajSyncRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-MAJOR-SYNC.REQUEST */
end_comment

begin_function_decl
name|int
name|SMajSyncResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-MAJOR-SYNC.RESPONSE */
end_comment

begin_function_decl
name|int
name|SMinSyncRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-MINOR-SYNC.REQUEST */
end_comment

begin_function_decl
name|int
name|SMinSyncResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-MINOR-SYNC.RESPONSE */
end_comment

begin_function_decl
name|int
name|SReSyncRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-RESYNCHRONIZE.REQUEST */
end_comment

begin_function_decl
name|int
name|SReSyncResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-RESYNCHRONIZE.RESPONSE */
end_comment

begin_function_decl
name|int
name|SActStartRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-ACTIVITY-START.REQUEST */
end_comment

begin_function_decl
name|int
name|SActResumeRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-ACTIVITY-RESUME.REQUEST */
end_comment

begin_function_decl
name|int
name|SActIntrRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-ACTIVITY-INTERRUPT.REQUEST */
end_comment

begin_function_decl
name|int
name|SActIntrResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-ACTIVITY-INTERRUPT.RESPONSE */
end_comment

begin_function_decl
name|int
name|SActDiscRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-ACTIVITY-DISCARD.REQUEST */
end_comment

begin_function_decl
name|int
name|SActDiscResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-ACTIVITY-DISCARD.RESPONSE */
end_comment

begin_function_decl
name|int
name|SActEndRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-ACTIVITY-END.REQUEST */
end_comment

begin_function_decl
name|int
name|SActEndResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-ACTIVITY-END.RESPONSE */
end_comment

begin_function_decl
name|int
name|SUAbortRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-U-ABORT.REQUEST */
end_comment

begin_function_decl
name|int
name|SUReportRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-U-EXCEPTION-REPORT.REQUEST */
end_comment

begin_function_decl
name|int
name|SRelRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-RELEASE.REQUEST */
end_comment

begin_function_decl
name|int
name|SRelRetryRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-RELEASE-RETRY.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|SRelResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* S-RELEASE.RESPONSE */
end_comment

begin_function_decl
name|int
name|SSetIndications
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* define vectors for INDICATION events */
end_comment

begin_function_decl
name|int
name|SSelectMask
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* map session descriptors for select() */
end_comment

begin_function_decl
name|char
modifier|*
name|SErrString
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return SSAP error code in string form */
end_comment

begin_define
define|#
directive|define
name|SLocalHostName
value|getlocalhost
end_define

begin_function_decl
name|char
modifier|*
name|SLocalHostName
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

