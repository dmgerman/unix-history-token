begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* psap2.h - include file for presentation users (PS-USER) continued  */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/psap2.h,v 7.2 91/02/22 09:24:56 mrose Interim $  *  *  * $Log:	psap2.h,v $  * Revision 7.2  91/02/22  09:24:56  mrose  * Interim 6.8  *   * Revision 7.1  90/11/21  11:32:11  mrose  * sun  *   * Revision 7.0  89/11/23  21:55:53  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PSAP2_
end_ifndef

begin_define
define|#
directive|define
name|_PSAP2_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PSAP_
end_ifndef

begin_include
include|#
directive|include
file|"psap.h"
end_include

begin_comment
comment|/* definitions for PS-USERs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SSAP_
end_ifndef

begin_include
include|#
directive|include
file|"ssap.h"
end_include

begin_comment
comment|/* definitions for SS-USERs */
end_comment

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

begin_comment
comment|/* definitions of ISO addresses */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|NPDATA
value|125
end_define

begin_comment
comment|/* arbitrary */
end_comment

begin_struct
struct|struct
name|PSAPcontext
block|{
comment|/* presentation context */
name|int
name|pc_id
decl_stmt|;
comment|/* identifier */
name|OID
name|pc_asn
decl_stmt|;
comment|/* abstract syntax name */
name|OID
name|pc_atn
decl_stmt|;
comment|/* abstract transfer name */
comment|/*   NULLOID if provider should handle it */
name|int
name|pc_result
decl_stmt|;
comment|/* same codes as pc_result below */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|PSAPctxlist
block|{
comment|/* list of presentation contexts */
name|int
name|pc_nctx
decl_stmt|;
comment|/* number of contexts */
define|#
directive|define
name|NPCTX
value|10
comment|/* arbitrary */
name|struct
name|PSAPcontext
name|pc_ctx
index|[
name|NPCTX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLPC
value|((struct PSAPctxlist *) 0)
end_define

begin_define
define|#
directive|define
name|BER
value|"basic encoding of a single asn.1 type"
end_define

begin_function_decl
name|struct
name|SSAPref
modifier|*
name|addr2ref
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* address to session reference */
end_comment

begin_function_decl
name|char
modifier|*
name|sprintref
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return session reference in string form */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|PSAPstart
block|{
comment|/* P-CONNECT.INDICATION */
name|int
name|ps_sd
decl_stmt|;
comment|/* PRESENTATION descriptor */
name|struct
name|PSAPaddr
name|ps_calling
decl_stmt|;
comment|/* address of peer calling */
name|struct
name|PSAPaddr
name|ps_called
decl_stmt|;
comment|/* address of peer called */
name|struct
name|PSAPctxlist
name|ps_ctxlist
decl_stmt|;
comment|/* list of proposed contexts */
name|OID
name|ps_defctx
decl_stmt|;
comment|/* name of proposed default context */
name|int
name|ps_defctxresult
decl_stmt|;
comment|/* what the provider thinks about it */
name|int
name|ps_prequirements
decl_stmt|;
comment|/* presentation requirements */
name|int
name|ps_srequirements
decl_stmt|;
comment|/* session requirements */
name|int
name|ps_settings
decl_stmt|;
comment|/* initial settings of tokens */
name|long
name|ps_isn
decl_stmt|;
comment|/* initial serial number */
name|struct
name|SSAPref
name|ps_connect
decl_stmt|;
comment|/* session connection identifier */
name|int
name|ps_ssdusize
decl_stmt|;
comment|/* largest atomic SSDU */
name|struct
name|QOStype
name|ps_qos
decl_stmt|;
comment|/* quality of service */
comment|/* initial data from peer */
name|int
name|ps_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|ps_info
index|[
name|NPDATA
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PSFREE
parameter_list|(
name|ps
parameter_list|)
define|\
value|{ \     register int PSI; \  \     for (PSI = (ps) -> ps_ctxlist.pc_nctx - 1; PSI>= 0; PSI--) { \ 	oid_free ((ps) -> ps_ctxlist.pc_ctx[PSI].pc_asn); \ 	oid_free ((ps) -> ps_ctxlist.pc_ctx[PSI].pc_atn); \ 	(ps) -> ps_ctxlist.pc_ctx[PSI].pc_asn = \ 	    (ps) -> ps_ctxlist.pc_ctx[PSI].pc_atn = NULLOID; \     } \     (ps) -> ps_ctxlist.pc_nctx = 0; \     if ((ps) -> ps_defctx) \ 	oid_free ((ps) -> ps_defctx), (ps) -> ps_defctx = NULLOID; \     for (PSI = (ps) -> ps_ninfo - 1; PSI>= 0; PSI--) \ 	if ((ps) -> ps_info[PSI]) \ 	    pe_free ((ps) -> ps_info[PSI]), (ps) -> ps_info[PSI] = NULLPE; \     (ps) -> ps_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|PSAPconnect
block|{
comment|/* P-CONNECT.CONFIRMATION */
name|int
name|pc_sd
decl_stmt|;
comment|/* PRESENTATION descriptor */
name|struct
name|PSAPaddr
name|pc_responding
decl_stmt|;
comment|/* address of peer responding */
name|struct
name|PSAPctxlist
name|pc_ctxlist
decl_stmt|;
comment|/* the list of negotiated contexts */
name|int
name|pc_defctxresult
decl_stmt|;
comment|/* result for proposed default context name */
name|int
name|pc_prequirements
decl_stmt|;
comment|/* presentation requirements */
name|int
name|pc_srequirements
decl_stmt|;
comment|/* session requirements */
name|int
name|pc_settings
decl_stmt|;
comment|/* initial settings of tokens */
name|int
name|pc_please
decl_stmt|;
comment|/* tokens requested by PS-user */
name|long
name|pc_isn
decl_stmt|;
comment|/* initial serial number */
name|struct
name|SSAPref
name|pc_connect
decl_stmt|;
comment|/* session connection identifier */
name|int
name|pc_ssdusize
decl_stmt|;
comment|/* largest atomic SSDU */
name|struct
name|QOStype
name|pc_qos
decl_stmt|;
comment|/* quality of service */
name|int
name|pc_result
decl_stmt|;
comment|/* result */
define|#
directive|define
name|PC_ACCEPT
value|(-1)
define|#
directive|define
name|PC_REJECTED
value|0
comment|/* Rejected by peer */
comment|/* Provider-reason */
define|#
directive|define
name|PC_NOTSPECIFIED
value|1
comment|/* Reason not specified */
define|#
directive|define
name|PC_CONGEST
value|2
comment|/* Temporary congestion */
define|#
directive|define
name|PC_EXCEEDED
value|3
comment|/* Local limit exceeded */
define|#
directive|define
name|PC_ADDRESS
value|4
comment|/* Called presentation address unknown */
define|#
directive|define
name|PC_VERSION
value|5
comment|/* Protocol version not supported */
define|#
directive|define
name|PC_DEFAULT
value|6
comment|/* Default context not supported */
define|#
directive|define
name|PC_READABLE
value|7
comment|/* User-data not readable */
define|#
directive|define
name|PC_AVAILABLE
value|8
comment|/* No PSAP available */
comment|/* Abort-reason */
define|#
directive|define
name|PC_UNRECOGNIZED
value|9
comment|/* Unrecognized PPDU */
define|#
directive|define
name|PC_UNEXPECTED
value|10
comment|/* Unexpected PPDU */
define|#
directive|define
name|PC_SSPRIMITIVE
value|11
comment|/* Unexpected session service primitive */
define|#
directive|define
name|PC_PPPARAM1
value|12
comment|/* Unrecognized PPDU parameter */
define|#
directive|define
name|PC_PPPARAM2
value|13
comment|/* Unexpected PPDU parameter */
define|#
directive|define
name|PC_INVALID
value|14
comment|/* Invalid PPDU parameter value */
comment|/* Provider-reason */
define|#
directive|define
name|PC_ABSTRACT
value|15
comment|/* Abstract syntax not supported */
define|#
directive|define
name|PC_TRANSFER
value|16
comment|/* Proposed transfer syntaxes not supported */
define|#
directive|define
name|PC_DCSLIMIT
value|17
comment|/* Local limit on DCS exceeded */
comment|/* begin UNOFFICIAL */
define|#
directive|define
name|PC_REFUSED
value|18
comment|/* Connect request refused on this network 				   connection */
define|#
directive|define
name|PC_SESSION
value|19
comment|/* Session disconnect */
define|#
directive|define
name|PC_PROTOCOL
value|20
comment|/* Protocol error */
define|#
directive|define
name|PC_ABORTED
value|21
comment|/* Peer aborted connection */
define|#
directive|define
name|PC_PARAMETER
value|22
comment|/* Invalid parameter */
define|#
directive|define
name|PC_OPERATION
value|23
comment|/* Invalid operation */
define|#
directive|define
name|PC_TIMER
value|24
comment|/* Timer expired */
define|#
directive|define
name|PC_WAITING
value|25
comment|/* Indications waiting */
comment|/* end UNOFFICIAL */
define|#
directive|define
name|PC_FATAL
parameter_list|(
name|r
parameter_list|)
value|((r)< PC_PARAMETER)
define|#
directive|define
name|PC_OFFICIAL
parameter_list|(
name|r
parameter_list|)
value|((r)< PC_REFUSED)
comment|/* initial data from peer */
name|int
name|pc_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|pc_info
index|[
name|NPDATA
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PCFREE
parameter_list|(
name|pc
parameter_list|)
define|\
value|{ \     register int PCI; \  \     for (PCI = (pc) -> pc_ctxlist.pc_nctx - 1; PCI>= 0; PCI--) { \ 	oid_free ((pc) -> pc_ctxlist.pc_ctx[PCI].pc_asn); \ 	oid_free ((pc) -> pc_ctxlist.pc_ctx[PCI].pc_atn); \ 	(pc) -> pc_ctxlist.pc_ctx[PCI].pc_asn = \ 	    (pc) -> pc_ctxlist.pc_ctx[PCI].pc_atn = NULLOID; \     } \     (pc) -> pc_ctxlist.pc_nctx = 0; \     for (PCI = (pc) -> pc_ninfo - 1; PCI>= 0; PCI--) \ 	if ((pc) -> pc_info[PCI]) \ 	    pe_free ((pc) -> pc_info[PCI]), (pc) -> pc_info[PCI] = NULLPE; \     (pc) -> pc_ninfo = 0; \ }
end_define

begin_comment
comment|/* PRESENTATION requirements */
end_comment

begin_define
define|#
directive|define
name|PR_MANAGEMENT
value|0x0001
end_define

begin_comment
comment|/* context management */
end_comment

begin_define
define|#
directive|define
name|PR_RESTORATION
value|0x0002
end_define

begin_comment
comment|/* context restoration */
end_comment

begin_define
define|#
directive|define
name|PR_MYREQUIRE
value|0x0000
end_define

begin_struct
struct|struct
name|PSAPdata
block|{
comment|/* P-READ.INDICATION */
name|int
name|px_type
decl_stmt|;
comment|/* type of indication */
comment|/* same values as sx_type */
name|int
name|px_ninfo
decl_stmt|;
comment|/* number of elements */
name|PE
name|px_info
index|[
name|NPDATA
index|]
decl_stmt|;
comment|/* data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PXFREE
parameter_list|(
name|px
parameter_list|)
define|\
value|{ \     register int PXI; \  \     for (PXI = (px) -> px_ninfo - 1; PXI>= 0; PXI--) \ 	if ((px) -> px_info[PXI]) \ 	    pe_free ((px) -> px_info[PXI]), (px) -> px_info[PXI] = NULLPE; \     (px) -> px_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|PSAPtoken
block|{
comment|/* P-{TOKEN-*,GIVE-CONTROL}.INDICATION */
name|int
name|pt_type
decl_stmt|;
comment|/* type of indication */
comment|/* same values as st_type */
name|u_char
name|pt_tokens
decl_stmt|;
comment|/* tokens offered/wanted */
comment|/* same values as st_tokens */
name|u_char
name|pt_owned
decl_stmt|;
comment|/* tokens owned by user */
comment|/* PLEASE TOKEN only */
name|int
name|pt_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|pt_info
index|[
name|NPDATA
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PTFREE
parameter_list|(
name|pt
parameter_list|)
define|\
value|{ \     register int PTI; \  \     for (PTI = (pt) -> pt_ninfo - 1; PTI>= 0; PTI--) \ 	if ((pt) -> pt_info[PTI]) \ 	    pe_free ((pt) -> pt_info[PTI]), (pt) -> pt_info[PTI] = NULLPE; \     (pt) -> pt_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|PSAPsync
block|{
comment|/* P-*-SYNC.{INDICATION,CONFIRMATION} */
name|int
name|pn_type
decl_stmt|;
comment|/* type of indication/confirmation */
comment|/* same values as sn_type */
name|int
name|pn_options
decl_stmt|;
comment|/* options (!!) */
comment|/* same values as sn_options */
name|long
name|pn_ssn
decl_stmt|;
comment|/* serial number */
comment|/* same values as sn_ssn */
name|int
name|pn_settings
decl_stmt|;
comment|/* new token settings (RESYNC only) */
comment|/* sync data from peer */
name|int
name|pn_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|pn_info
index|[
name|NPDATA
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PNFREE
parameter_list|(
name|pn
parameter_list|)
define|\
value|{ \     register int PNI; \  \     for (PNI = (pn) -> pn_ninfo - 1; PNI>= 0; PNI--) \ 	if ((pn) -> pn_info[PNI]) \ 	    pe_free ((pn) -> pn_info[PNI]), (pn) -> pn_info[PNI] = NULLPE; \     (pn) -> pn_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|PSAPactivity
block|{
comment|/* P-ACTIVITY-*.{INDICATION,CONFIRMATION} */
name|int
name|pv_type
decl_stmt|;
comment|/* type of indication/confirmation */
comment|/* same values as sv_type */
name|struct
name|SSAPactid
name|pv_id
decl_stmt|;
comment|/* START/RESUME activity identifier */
name|struct
name|SSAPactid
name|pv_oid
decl_stmt|;
comment|/* RESUME old activity identifier */
name|struct
name|SSAPref
name|pv_connect
decl_stmt|;
comment|/* 	  old connection identifier */
name|long
name|pv_ssn
decl_stmt|;
comment|/* RESUME/END Serial number */
name|int
name|pv_reason
decl_stmt|;
comment|/* INTERRUPT/DISCARD */
comment|/* same values as sp_reason */
comment|/* activity DATA from peer */
name|int
name|pv_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|pv_info
index|[
name|NPDATA
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PVFREE
parameter_list|(
name|pv
parameter_list|)
define|\
value|{ \     register int PVI; \  \     for (PVI = (pv) -> pv_ninfo - 1; PVI>= 0; PVI--) \ 	if ((pv) -> pv_info[PVI]) \ 	    pe_free ((pv) -> pv_info[PVI]), (pv) -> pv_info[PVI] = NULLPE; \     (pv) -> pv_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|PSAPreport
block|{
comment|/* P-{U,P}-EXCEPTION-REPORT.INDICATION */
name|int
name|pp_peer
decl_stmt|;
comment|/* T   = P-U-EXCEPTION-REPORT.INDICATION: 					pp_reason/pp_info both meaningful 				   NIL = P-P-EXCEPTION-REPORT.INDICATION: 					pp_reason == SP_NOREASON, or 					pp_reason == SP_PROTOCOL */
name|int
name|pp_reason
decl_stmt|;
comment|/* same values as sp_reason */
comment|/* report DATA from peer */
name|int
name|pp_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|pp_info
index|[
name|NPDATA
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PPFREE
parameter_list|(
name|pp
parameter_list|)
define|\
value|{ \     register int PPI; \  \     for (PPI = (pp) -> pp_ninfo - 1; PPI>= 0; PPI--) \ 	if ((pp) -> pp_info[PPI]) \ 	    pe_free ((pp) -> pp_info[PPI]), (pp) -> pp_info[PPI] = NULLPE; \     (pp) -> pp_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|PSAPfinish
block|{
comment|/* P-RELEASE.INDICATION */
comment|/* release DATA from peer */
name|int
name|pf_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|pf_info
index|[
name|NPDATA
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PFFREE
parameter_list|(
name|pf
parameter_list|)
define|\
value|{ \     register int PFI; \  \     for (PFI = (pf) -> pf_ninfo - 1; PFI>= 0; PFI--) \ 	if ((pf) -> pf_info[PFI]) \ 	    pe_free ((pf) -> pf_info[PFI]), (pf) -> pf_info[PFI] = NULLPE; \     (pf) -> pf_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|PSAPrelease
block|{
comment|/* P-RELEASE.CONFIRMATION */
name|int
name|pr_affirmative
decl_stmt|;
comment|/* T   = connection released 				   NIL = request refused */
comment|/* release DATA from peer */
name|int
name|pr_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|pr_info
index|[
name|NPDATA
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PRFREE
parameter_list|(
name|pr
parameter_list|)
define|\
value|{ \     register int PRI; \  \     for (PRI = (pr) -> pr_ninfo - 1; PRI>= 0; PRI--) \ 	if ((pr) -> pr_info[PRI]) \ 	    pe_free ((pr) -> pr_info[PRI]), (pr) -> pr_info[PRI] = NULLPE; \     (pr) -> pr_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|PSAPabort
block|{
comment|/* P-{U,P}-ABORT.INDICATION */
name|int
name|pa_peer
decl_stmt|;
comment|/* T   = P-U-ABORT.INDICATION: 					    pa_info/pa_ninfo is meaningful 				   NIL = P-P-ABORT.INDICATION: 					    pa_reason/pa_ppdu is meaningful, 					    pa_data contains diagnostics */
name|int
name|pa_reason
decl_stmt|;
comment|/* same codes as pc_result */
comment|/* abort information from peer */
name|int
name|pa_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|pa_info
index|[
name|NPDATA
index|]
decl_stmt|;
comment|/*   data */
comment|/* diagnostics from provider */
define|#
directive|define
name|PA_SIZE
value|512
name|int
name|pa_cc
decl_stmt|;
comment|/*   length */
name|char
name|pa_data
index|[
name|PA_SIZE
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PAFREE
parameter_list|(
name|pa
parameter_list|)
define|\
value|{ \     register int PAI; \  \     for (PAI = (pa) -> pa_ninfo - 1; PAI>= 0; PAI--) \ 	if ((pa) -> pa_info[PAI]) \ 	    pe_free ((pa) -> pa_info[PAI]), (pa) -> pa_info[PAI] = NULLPE; \     (pa) -> pa_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|PSAPindication
block|{
name|int
name|pi_type
decl_stmt|;
comment|/* the union element present */
define|#
directive|define
name|PI_DATA
value|0x00
define|#
directive|define
name|PI_TOKEN
value|0x01
define|#
directive|define
name|PI_SYNC
value|0x02
define|#
directive|define
name|PI_ACTIVITY
value|0x03
define|#
directive|define
name|PI_REPORT
value|0x04
define|#
directive|define
name|PI_FINISH
value|0x05
define|#
directive|define
name|PI_ABORT
value|0x06
union|union
block|{
name|struct
name|PSAPdata
name|pi_un_data
decl_stmt|;
name|struct
name|PSAPtoken
name|pi_un_token
decl_stmt|;
name|struct
name|PSAPsync
name|pi_un_sync
decl_stmt|;
name|struct
name|PSAPactivity
name|pi_un_activity
decl_stmt|;
name|struct
name|PSAPreport
name|pi_un_report
decl_stmt|;
name|struct
name|PSAPfinish
name|pi_un_finish
decl_stmt|;
name|struct
name|PSAPabort
name|pi_un_abort
decl_stmt|;
block|}
name|pi_un
union|;
define|#
directive|define
name|pi_data
value|pi_un.pi_un_data
define|#
directive|define
name|pi_token
value|pi_un.pi_un_token
define|#
directive|define
name|pi_sync
value|pi_un.pi_un_sync
define|#
directive|define
name|pi_activity
value|pi_un.pi_un_activity
define|#
directive|define
name|pi_report
value|pi_un.pi_un_report
define|#
directive|define
name|pi_finish
value|pi_un.pi_un_finish
define|#
directive|define
name|pi_abort
value|pi_un.pi_un_abort
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
name|psap2version
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|PExec
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* SERVER only */
end_comment

begin_function_decl
name|int
name|PInit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-CONNECT.INDICATION */
end_comment

begin_function_decl
name|int
name|PConnResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-CONNECT.RESPONSE */
end_comment

begin_comment
comment|/* P-CONNECT.REQUEST (backwards-compatible) */
end_comment

begin_define
define|#
directive|define
name|PConnRequest
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
parameter_list|,
name|a12
parameter_list|,
name|a13
parameter_list|,
name|a14
parameter_list|)
define|\
value|PAsynConnRequest (a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,0)
end_define

begin_function_decl
name|int
name|PAsynConnRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-(ASYN-)CONNECT.REQUEST */
end_comment

begin_function_decl
name|int
name|PAsynRetryRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-ASYN-RETRY.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|PDataRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-DATA.REQUEST */
end_comment

begin_function_decl
name|int
name|PDataRequestAux
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-[*-]DATA.REQUEST */
end_comment

begin_define
define|#
directive|define
name|PPDU_TTD
value|8
end_define

begin_define
define|#
directive|define
name|PPDU_TE
value|9
end_define

begin_define
define|#
directive|define
name|PPDU_TC
value|10
end_define

begin_define
define|#
directive|define
name|PPDU_TCC
value|11
end_define

begin_define
define|#
directive|define
name|PExpdRequest
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|PDataRequestAux ((s), (d), (n), (p), "expedited", SExpdRequest, \ 			"SExpdRequest", "P-EXPEDITED-DATA user-data", PPDU_TE)
end_define

begin_define
define|#
directive|define
name|PTypedRequest
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|PDataRequestAux ((s), (d), (n), (p), "typed", STypedRequest, \ 			"STypedRequest", "P-TYPED-DATA user-data", PPDU_TTD)
end_define

begin_define
define|#
directive|define
name|PCapdRequest
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|PDataRequestAux ((s), (d), (n), (p), "capability", SCapdRequest, \ 			"SCapdRequest", "P-CAPABILITY-DATA user-data", PPDU_TC)
end_define

begin_define
define|#
directive|define
name|PCapdResponse
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|PDataRequestAux ((s), (d), (n), (p), "capability", SCapdResponse, \ 			"SCapdResponse","P-CAPABILITY-DATA user-data",PPDU_TCC)
end_define

begin_function_decl
name|int
name|PReadRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-READ.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|PGTokenRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-TOKEN-GIVE.REQUEST */
end_comment

begin_function_decl
name|int
name|PPTokenRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-TOKEN-PLEASE.REQUEST */
end_comment

begin_function_decl
name|int
name|PGControlRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-CONTROL-GIVE.REQUEST */
end_comment

begin_function_decl
name|int
name|PMajSyncRequestAux
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-{MAJOR-SYNC,ACTIVITY-END}.REQUEST */
end_comment

begin_define
define|#
directive|define
name|PMajSyncRequest
parameter_list|(
name|s
parameter_list|,
name|i
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|PMajSyncRequestAux ((s), (i), (d), (n), (p), "majorsync", \ 			SMajSyncRequest, "SMajSyncRequest")
end_define

begin_define
define|#
directive|define
name|PActEndRequest
parameter_list|(
name|s
parameter_list|,
name|i
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|PMajSyncRequestAux ((s), (i), (d), (n), (p), "activity end", \ 			SActEndRequest, "SActEndRequest")
end_define

begin_function_decl
name|int
name|PMajSyncResponseAux
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-{MAJOR-SYNC,ACTIVITY-END}.RESPONSE */
end_comment

begin_define
define|#
directive|define
name|PMajSyncResponse
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|PMajSyncResponseAux ((s), (d), (n), (p), "majorsync", \ 			SMajSyncResponse, "SMajSyncResponse")
end_define

begin_define
define|#
directive|define
name|PActEndResponse
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|PMajSyncResponseAux ((s), (d), (n), (p), "activity end", \ 			SActEndResponse, "SActEndResponse")
end_define

begin_function_decl
name|int
name|PMinSyncRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-MINOR-SYNC.REQUEST */
end_comment

begin_function_decl
name|int
name|PMinSyncResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-MINOR-SYNC.RESPONSE */
end_comment

begin_function_decl
name|int
name|PReSyncRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-RESYNCHRONIZE.REQUEST */
end_comment

begin_function_decl
name|int
name|PReSyncResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-RESYNCHRONIZE.RESPONSE */
end_comment

begin_function_decl
name|int
name|PActStartRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-ACTIVITY-START.REQUEST */
end_comment

begin_function_decl
name|int
name|PActResumeRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-ACTIVITY-RESUME.REQUEST */
end_comment

begin_function_decl
name|int
name|PActIntrRequestAux
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-ACTIVITY-{INTERRUPT,DISCARD}.REQUEST */
end_comment

begin_define
define|#
directive|define
name|PActIntrRequest
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|,
name|p
parameter_list|)
define|\
value|PActIntrRequestAux ((s), (r), (p), \ 			SActIntrRequest, "SActIntrRequest")
end_define

begin_define
define|#
directive|define
name|PActDiscRequest
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|,
name|p
parameter_list|)
define|\
value|PActIntrRequestAux ((s), (r), (p), \ 			SActDiscRequest, "SActDiscRequest")
end_define

begin_function_decl
name|int
name|PActIntrResponseAux
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-ACTIVITY-{INTERRUPT,DISCARD}.RESPONSE */
end_comment

begin_define
define|#
directive|define
name|PActIntrResponse
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|)
define|\
value|PActIntrResponseAux ((s), (p), \ 			SActIntrResponse, "SActIntrResponse")
end_define

begin_define
define|#
directive|define
name|PActDiscResponse
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|)
define|\
value|PActIntrResponseAux ((s), (p), \ 			SActDiscResponse, "SActDiscResponse")
end_define

begin_function_decl
name|int
name|PUAbortRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-U-ABORT.REQUEST */
end_comment

begin_function_decl
name|int
name|PUReportRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-U-EXCEPTION-REPORT.REQUEST */
end_comment

begin_function_decl
name|int
name|PRelRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-RELEASE.REQUEST */
end_comment

begin_function_decl
name|int
name|PRelRetryRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-RELEASE-RETRY.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|PRelResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* P-RELEASE.RESPONSE */
end_comment

begin_function_decl
name|int
name|PSetIndications
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* define vectors for INDICATION events */
end_comment

begin_function_decl
name|int
name|PSelectMask
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* map presentation descriptors for select() */
end_comment

begin_function_decl
name|char
modifier|*
name|PErrString
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return PSAP error code in string form */
end_comment

begin_define
define|#
directive|define
name|PLocalHostName
value|getlocalhost
end_define

begin_function_decl
name|char
modifier|*
name|PLocalHostName
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

