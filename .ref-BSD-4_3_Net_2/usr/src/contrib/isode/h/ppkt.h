begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ppkt.h - include file for presentation providers (PS-PROVIDER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/ppkt.h,v 7.1 91/02/22 09:24:53 mrose Interim $  *  * RFC1085 (LPP) support contributed by the Wollongong Group, Inc.  *  *  * $Log:	ppkt.h,v $  * Revision 7.1  91/02/22  09:24:53  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:55:51  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PSAP2_
end_ifndef

begin_include
include|#
directive|include
file|"psap2.h"
end_include

begin_comment
comment|/* definitions for PS-USERs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ssap.h"
end_include

begin_comment
comment|/* definitinos for SS-USERs */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|psapPsig
parameter_list|(
name|pb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((pb = findpblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return psaplose (pi, PC_PARAMETER, NULLCP, \ 			    "invalid presentation descriptor"); \     } \     if (!(pb -> pb_flags& PB_CONN)) { \ 	(void) sigiomask (smask); \ 	return psaplose (pi, PC_OPERATION, NULLCP, \ 			    "presentation descriptor not connected"); \     } \     if (pb -> pb_flags& PB_FINN) { \ 	(void) sigiomask (smask); \ 	return psaplose (pi, PC_OPERATION, NULLCP, \ 			    "presentation descriptor finishing"); \     } \     if (pb -> pb_flags& PB_RELEASE) { \ 	(void) sigiomask (smask); \ 	return psaplose (pi, PC_OPERATION, NULLCP, \ 			    "release in progress"); \     } \ }
end_define

begin_define
define|#
directive|define
name|psapFsig
parameter_list|(
name|pb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((pb = findpblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return psaplose (pi, PC_PARAMETER, NULLCP, \ 			    "invalid presentation descriptor"); \     } \     if (!(pb -> pb_flags& PB_CONN)) { \ 	(void) sigiomask (smask); \ 	return psaplose (pi, PC_OPERATION, NULLCP, \ 			    "presentation descriptor not connected"); \     } \     if (!(pb -> pb_flags& PB_FINN)) { \ 	(void) sigiomask (smask); \ 	return psaplose (pi, PC_OPERATION, NULLCP, \ 			    "presentation descriptor not finishing"); \     } \     if (pb -> pb_flags& PB_RELEASE) { \ 	(void) sigiomask (smask); \ 	return psaplose (pi, PC_OPERATION, NULLCP, \ 			    "release in progress"); \     } \ }
end_define

begin_define
define|#
directive|define
name|toomuchP
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|,
name|m
parameter_list|,
name|p
parameter_list|)
define|\
value|{ \     if (b == NULL) \ 	n = 0; \     else \ 	if (n> m) \ 	    return psaplose (pi, PC_PARAMETER, NULLCP, \ 			    "too many %s user data elements", p); \ }
end_define

begin_define
define|#
directive|define
name|missingP
parameter_list|(
name|p
parameter_list|)
define|\
value|{ \     if (p == NULL) \ 	return psaplose (pi, PC_PARAMETER, NULLCP, \ 			    "mandatory parameter \"%s\" missing", "p"); \ }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|copyPSAPdata
parameter_list|(
name|base
parameter_list|,
name|len
parameter_list|,
name|d
parameter_list|)
define|\
value|{ \     register int i = len; \     if ((d -> d
comment|/* */
value|_cc = min (i, sizeof d -> d
comment|/* */
value|_data))> 0) \ 	bcopy (base, d -> d
comment|/* */
value|_data, d -> d
comment|/* */
value|_cc); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|copyPSAPdata
parameter_list|(
name|base
parameter_list|,
name|len
parameter_list|,
name|d
parameter_list|)
define|\
value|{ \     register int i = len; \     if ((d -> d##_cc = min (i, sizeof d -> d##_data))> 0) \ 	bcopy (base, d -> d##_data, d -> d##_cc); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|copyPSAPdata
parameter_list|(
name|base
parameter_list|,
name|len
parameter_list|,
name|d
parameter_list|)
value|bcopy (base, (char *) d, len)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|pylose
parameter_list|(
name|p
parameter_list|)
define|\
value|ppktlose (pb, pi, PC_UNRECOGNIZED, (p), NULLCP, "%s", PY_pepy)
end_define

begin_decl_stmt
name|int
name|ppktlose
argument_list|()
decl_stmt|,
name|psaplose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|DFLT_ASN
value|"iso asn.1 abstract syntax"
end_define

begin_define
define|#
directive|define
name|DFLT_ATN
value|BER
end_define

begin_define
define|#
directive|define
name|atn_is_ok
parameter_list|(
name|pb
parameter_list|,
name|atn
parameter_list|)
value|atn_is_ber ((pb), (atn))
end_define

begin_define
define|#
directive|define
name|atn_is_ber
parameter_list|(
name|pb
parameter_list|,
name|atn
parameter_list|)
value|(!oid_cmp (pb -> pb_ber, atn))
end_define

begin_struct
struct|struct
name|psapblk
block|{
name|struct
name|psapblk
modifier|*
name|pb_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|psapblk
modifier|*
name|pb_back
decl_stmt|;
comment|/*   .. */
name|int
name|pb_fd
decl_stmt|;
comment|/* session descriptor */
name|short
name|pb_flags
decl_stmt|;
comment|/* our state */
define|#
directive|define
name|PB_NULL
value|0x00
define|#
directive|define
name|PB_CONN
value|0x01
comment|/* connected */
define|#
directive|define
name|PB_FINN
value|0x02
comment|/* other side wants to finish */
define|#
directive|define
name|PB_ASYN
value|0x04
comment|/* asynchronous */
define|#
directive|define
name|PB_DFLT
value|0x10
comment|/* respond with default context result */
define|#
directive|define
name|PB_RELEASE
value|0x20
comment|/* release in progress */
ifndef|#
directive|ifndef
name|LPP
name|char
modifier|*
name|pb_retry
decl_stmt|;
comment|/* initial/final ppkt */
name|char
modifier|*
name|pb_realbase
decl_stmt|;
name|int
name|pb_len
decl_stmt|;
else|#
directive|else
name|PE
name|pb_retry
decl_stmt|;
name|PE
name|pb_response
decl_stmt|;
name|struct
name|type_PS_SessionConnectionIdentifier
modifier|*
name|pb_reference
decl_stmt|;
name|PS
name|pb_stream
decl_stmt|;
name|int
name|pb_reliability
decl_stmt|;
name|int
name|pb_maxtries
decl_stmt|;
name|int
name|pb_tries
decl_stmt|;
endif|#
directive|endif
name|int
name|pb_ncontext
decl_stmt|;
comment|/* presentation context set */
name|struct
name|PSAPcontext
name|pb_contexts
index|[
name|NPCTX
index|]
decl_stmt|;
name|OID
name|pb_asn
decl_stmt|;
comment|/* default: abstract syntax name */
name|OID
name|pb_atn
decl_stmt|;
comment|/*   ..     abstract transfer name */
name|int
name|pb_result
decl_stmt|;
comment|/* 	    response */
name|OID
name|pb_ber
decl_stmt|;
comment|/* BER */
name|int
name|pb_prequirements
decl_stmt|;
comment|/* presentation requirements */
name|int
name|pb_srequirements
decl_stmt|;
comment|/* our session requirements */
name|int
name|pb_urequirements
decl_stmt|;
comment|/* user's session requirements */
name|int
name|pb_owned
decl_stmt|;
comment|/* session tokens we own */
name|int
name|pb_avail
decl_stmt|;
comment|/* session tokens available */
name|int
name|pb_ssdusize
decl_stmt|;
comment|/* largest atomic SSDU */
ifdef|#
directive|ifdef
name|LPP
name|struct
name|NSAPaddr
name|pb_initiating
decl_stmt|;
comment|/* initiator */
endif|#
directive|endif
name|struct
name|PSAPaddr
name|pb_responding
decl_stmt|;
comment|/* responder */
name|IFP
name|pb_DataIndication
decl_stmt|;
comment|/* INDICATION handlers */
name|IFP
name|pb_TokenIndication
decl_stmt|;
comment|/*   .. */
name|IFP
name|pb_SyncIndication
decl_stmt|;
comment|/*   .. */
name|IFP
name|pb_ActivityIndication
decl_stmt|;
comment|/*   .. */
name|IFP
name|pb_ReportIndication
decl_stmt|;
comment|/*   .. */
name|IFP
name|pb_ReleaseIndication
decl_stmt|;
comment|/*   .. */
name|IFP
name|pb_AbortIndication
decl_stmt|;
comment|/*   .. */
ifdef|#
directive|ifdef
name|LPP
name|IFP
name|pb_retryfnx
decl_stmt|;
name|IFP
name|pb_closefnx
decl_stmt|;
name|IFP
name|pb_selectfnx
decl_stmt|;
name|IFP
name|pb_checkfnx
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLPB
value|((struct psapblk *) 0)
end_define

begin_function_decl
name|int
name|freepblk
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|psapblk
modifier|*
name|newpblk
argument_list|()
decl_stmt|,
modifier|*
name|findpblk
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|LPP
end_ifndef

begin_define
define|#
directive|define
name|PC_PROV_BASE
value|PC_NOTSPECIFIED
end_define

begin_define
define|#
directive|define
name|PC_ABORT_BASE
define|\
value|(PC_UNRECOGNIZED - int_PS_Abort__reason_unrecognized__ppdu)
end_define

begin_define
define|#
directive|define
name|PC_REASON_BASE
define|\
value|(PC_ABSTRACT - int_PS_provider__reason_abstract__syntax__not__supported)
end_define

begin_function_decl
name|struct
name|type_PS_User__data
modifier|*
name|info2ppdu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ppdu2info
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|info2ssdu
argument_list|()
decl_stmt|,
name|ssdu2info
argument_list|()
decl_stmt|,
name|qbuf2info
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|qbuf
modifier|*
name|info2qb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|qb2info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|type_PS_Identifier__list
modifier|*
name|silly_list
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|ss2pslose
argument_list|()
decl_stmt|,
name|ss2psabort
argument_list|()
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|pair
block|{
name|int
name|p_mask
decl_stmt|;
name|int
name|p_bitno
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|pair
name|preq_pairs
index|[]
decl_stmt|,
name|sreq_pairs
index|[]
decl_stmt|;
end_decl_stmt

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
name|REASON_BASE
value|PC_NOTSPECIFIED
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LPP
end_ifndef

begin_define
define|#
directive|define
name|PPDU_NONE
value|(-1)
end_define

begin_define
define|#
directive|define
name|PPDU_CP
value|0
end_define

begin_define
define|#
directive|define
name|PPDU_CPA
value|1
end_define

begin_define
define|#
directive|define
name|PPDU_CPR
value|2
end_define

begin_define
define|#
directive|define
name|PPDU_ARU
value|3
end_define

begin_define
define|#
directive|define
name|PPDU_ARP
value|4
end_define

begin_define
define|#
directive|define
name|PPDU_TD
value|7
end_define

begin_define
define|#
directive|define
name|PPDU_RS
value|12
end_define

begin_define
define|#
directive|define
name|PPDU_RSA
value|13
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PR_KERNEL
value|0x0000
end_define

begin_comment
comment|/* kernel (yuk) */
end_comment

begin_define
define|#
directive|define
name|NPCTX_PS
value|2
end_define

begin_comment
comment|/* maximum number of contexts */
end_comment

begin_define
define|#
directive|define
name|NPDATA_PS
value|1
end_define

begin_comment
comment|/* maximum number of PDVs in a request */
end_comment

begin_define
define|#
directive|define
name|PCI_ROSE
value|1
end_define

begin_comment
comment|/* PCI for SASE using ROSE */
end_comment

begin_define
define|#
directive|define
name|PCI_ACSE
value|3
end_define

begin_comment
comment|/* PCI for ACSE */
end_comment

begin_define
define|#
directive|define
name|PT_TCP
value|'T'
end_define

begin_comment
comment|/* TCP providing backing */
end_comment

begin_define
define|#
directive|define
name|PT_UDP
value|'U'
end_define

begin_comment
comment|/* UDP providing backing */
end_comment

begin_define
define|#
directive|define
name|NULLRF
value|((struct type_PS_SessionConnectionIdentifier *) 0)
end_define

begin_define
define|#
directive|define
name|pslose
parameter_list|(
name|pi
parameter_list|,
name|reason
parameter_list|)
define|\
value|(reason != PS_ERR_NONE&& reason != PS_ERR_IO \ 	? psaplose ((pi), PC_CONGEST, NULLCP, "%s", ps_error (reason)) \ 	: psaplose ((pi), PC_SESSION, NULLCP, NULLCP))
end_define

begin_decl_stmt
name|int
name|pdu2sel
argument_list|()
decl_stmt|,
name|refcmp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|SSAPref
modifier|*
name|pdu2ref
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

