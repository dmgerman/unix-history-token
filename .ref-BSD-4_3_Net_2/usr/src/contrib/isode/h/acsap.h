begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* acsap.h - include file for association control users (AcS-USER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/acsap.h,v 7.1 91/02/22 09:24:34 mrose Interim $  *  *  * $Log:	acsap.h,v $  * Revision 7.1  91/02/22  09:24:34  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:55:39  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AcSAP_
end_ifndef

begin_define
define|#
directive|define
name|_AcSAP_
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

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|NACDATA
value|3
end_define

begin_comment
comment|/* arbitrary */
end_comment

begin_struct
struct|struct
name|AcSAPstart
block|{
comment|/* A-CONNECT.INDICATION */
name|int
name|acs_sd
decl_stmt|;
comment|/* association descriptor */
name|OID
name|acs_context
decl_stmt|;
comment|/* application context name */
name|AEInfo
name|acs_callingtitle
decl_stmt|;
comment|/* info on calling application-entity */
name|AEInfo
name|acs_calledtitle
decl_stmt|;
comment|/* info on called application-entity */
name|struct
name|PSAPstart
name|acs_start
decl_stmt|;
comment|/* info from P-CONNECT.INDICATION */
comment|/* initial information from peer */
name|int
name|acs_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|acs_info
index|[
name|NACDATA
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACSFREE
parameter_list|(
name|acs
parameter_list|)
value|{ \     register int ACSI; \  \     if ((acs) -> acs_context) \ 	oid_free ((acs) -> acs_context), (acs) -> acs_context = NULLOID; \  \     AEIFREE (&(acs) -> acs_callingtitle); \     AEIFREE (&(acs) -> acs_calledtitle); \  \     PSFREE (&(acs) -> acs_start); \  \     for (ACSI = (acs) -> acs_ninfo - 1; ACSI>= 0; ACSI--) \ 	if ((acs) -> acs_info[ACSI]) \ 	    pe_free ((acs) -> acs_info[ACSI]), \ 		(acs) -> acs_info[ACSI] = NULLPE; \     (acs) -> acs_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|AcSAPconnect
block|{
name|int
name|acc_sd
decl_stmt|;
comment|/* association descriptor */
name|int
name|acc_result
decl_stmt|;
comment|/* result */
define|#
directive|define
name|ACS_ACCEPT
value|0
comment|/*   Accepted */
define|#
directive|define
name|ACS_REJECT
value|(-1)
comment|/*   Release rejected */
comment|/*   Rejected by responder: */
define|#
directive|define
name|ACS_PERMANENT
value|1
comment|/*     Permanent */
define|#
directive|define
name|ACS_TRANSIENT
value|2
comment|/*     Transient */
name|int
name|acc_diagnostic
decl_stmt|;
comment|/* source-diagnostic */
comment|/* service-user */
define|#
directive|define
name|ACS_USER_NULL
value|3
comment|/*   null */
define|#
directive|define
name|ACS_USER_NOREASON
value|4
comment|/*   no reason given */
define|#
directive|define
name|ACS_CONTEXT
value|5
comment|/*   application context name not supported*/
define|#
directive|define
name|ACS_CALLING_AP_TITLE
value|6
comment|/*   calling AP title not recognized */
define|#
directive|define
name|ACS_CALLING_AP_ID
value|7
comment|/*   calling AP invocation-ID not recognized */
define|#
directive|define
name|ACS_CALLING_AE_QUAL
value|8
comment|/*   calling AE qualifier not recognized */
define|#
directive|define
name|ACS_CALLING_AE_ID
value|9
comment|/*   calling AE invocation-ID not recognized */
define|#
directive|define
name|ACS_CALLED_AP_TITLE
value|10
comment|/*   called AP title not recognized */
define|#
directive|define
name|ACS_CALLED_AP_ID
value|11
comment|/*   called AP invocation-ID not recognized */
define|#
directive|define
name|ACS_CALLED_AE_QUAL
value|12
comment|/*   called AE qualifier not recognized */
define|#
directive|define
name|ACS_CALLED_AE_ID
value|13
comment|/*   called AE invocation-ID not recognized */
comment|/* service-provider */
define|#
directive|define
name|ACS_PROV_NULL
value|14
comment|/*   null */
define|#
directive|define
name|ACS_PROV_NOREASON
value|15
comment|/*   no reason given */
define|#
directive|define
name|ACS_VERSION
value|16
comment|/*   no common acse version */
comment|/* begin UNOFFICIAL */
define|#
directive|define
name|ACS_ADDRESS
value|17
comment|/* Address unknown */
define|#
directive|define
name|ACS_REFUSED
value|18
comment|/* Connect request refused on this network 				   connection */
define|#
directive|define
name|ACS_CONGEST
value|19
comment|/* Local limit exceeded */
define|#
directive|define
name|ACS_PRESENTATION
value|20
comment|/* Presentation disconnect */
define|#
directive|define
name|ACS_PROTOCOL
value|21
comment|/* Protocol error */
define|#
directive|define
name|ACS_ABORTED
value|22
comment|/* Peer aborted association */
define|#
directive|define
name|ACS_PARAMETER
value|23
comment|/* Invalid parameter */
define|#
directive|define
name|ACS_OPERATION
value|24
comment|/* Invalid operation */
define|#
directive|define
name|ACS_TIMER
value|25
comment|/* Timer expired */
comment|/* end UNOFFICIAL */
define|#
directive|define
name|ACS_FATAL
parameter_list|(
name|r
parameter_list|)
value|((r)< ACS_PARAMETER)
define|#
directive|define
name|ACS_OFFICIAL
parameter_list|(
name|r
parameter_list|)
value|((r)< ACS_ADDRESS)
name|OID
name|acc_context
decl_stmt|;
comment|/* application context name */
name|AEInfo
name|acc_respondtitle
decl_stmt|;
comment|/* info on responding application-entity */
name|struct
name|PSAPconnect
name|acc_connect
decl_stmt|;
comment|/* info from P-CONNECT.CONFIRMATION */
comment|/* initial information from peer */
name|int
name|acc_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|acc_info
index|[
name|NACDATA
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACCFREE
parameter_list|(
name|acc
parameter_list|)
value|{ \     register int ACCI; \  \     if ((acc) -> acc_context) \ 	oid_free ((acc) -> acc_context), (acc) -> acc_context = NULLOID; \  \     AEIFREE (&(acc) -> acc_respondtitle); \  \     PCFREE (&(acc) -> acc_connect); \  \     for (ACCI = (acc) -> acc_ninfo - 1; ACCI>= 0; ACCI--) \ 	if ((acc) -> acc_info[ACCI]) \ 	    pe_free ((acc) -> acc_info[ACCI]), \ 		(acc) -> acc_info[ACCI] = NULLPE; \     (acc) -> acc_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|AcSAPfinish
block|{
comment|/* A-RELEASE.INDICATION */
name|int
name|acf_reason
decl_stmt|;
comment|/* reason for release */
define|#
directive|define
name|ACF_NORMAL
value|0
comment|/*   normal */
define|#
directive|define
name|ACF_URGENT
value|1
comment|/*   urgent */
define|#
directive|define
name|ACF_USERDEFINED
value|30
comment|/*   user-defined */
comment|/* release information from peer */
name|int
name|acf_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|acf_info
index|[
name|NACDATA
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACFFREE
parameter_list|(
name|acf
parameter_list|)
define|\
value|{ \     register int ACFI; \  \     for (ACFI = (acf) -> acf_ninfo - 1; ACFI>= 0; ACFI--) \ 	if ((acf) -> acf_info[ACFI]) \ 	    pe_free ((acf) -> acf_info[ACFI]), \ 		(acf) -> acf_info[ACFI] = NULLPE; \     (acf) -> acf_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|AcSAPrelease
block|{
comment|/* A-RELEASE.CONFIRMATION */
name|int
name|acr_affirmative
decl_stmt|;
comment|/* T   = connection released 				   NIL = request refused */
name|int
name|acr_reason
decl_stmt|;
comment|/* reason for result */
define|#
directive|define
name|ACR_NORMAL
value|0
comment|/*   normal */
define|#
directive|define
name|ACR_NOTFINISHED
value|1
comment|/*   not finished */
define|#
directive|define
name|ACR_USERDEFINED
value|30
comment|/*   user-defined */
comment|/* release information from peer */
name|int
name|acr_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|acr_info
index|[
name|NACDATA
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACRFREE
parameter_list|(
name|acr
parameter_list|)
define|\
value|{ \     register int ACRI; \  \     for (ACRI = (acr) -> acr_ninfo - 1; ACRI>= 0; ACRI--) \ 	if ((acr) -> acr_info[ACRI]) \ 	    pe_free ((acr) -> acr_info[ACRI]), \ 		(acr) -> acr_info[ACRI] = NULLPE; \     (acr) -> acr_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|AcSAPabort
block|{
comment|/* A-{U,P}-ABORT.INDICATION */
name|int
name|aca_source
decl_stmt|;
comment|/* abort source */
define|#
directive|define
name|ACA_USER
value|0
comment|/*   service-user */
define|#
directive|define
name|ACA_PROVIDER
value|1
comment|/*   service-provider */
define|#
directive|define
name|ACA_LOCAL
value|2
comment|/*   local ACPM (UNOFFICIAL) */
name|int
name|aca_reason
decl_stmt|;
comment|/* same codes as acc_result */
comment|/* abort information from peer */
name|int
name|aca_ninfo
decl_stmt|;
comment|/*   number of elements */
name|PE
name|aca_info
index|[
name|NACDATA
index|]
decl_stmt|;
comment|/*   data */
comment|/* diagnostics from provider */
define|#
directive|define
name|ACA_SIZE
value|512
name|int
name|aca_cc
decl_stmt|;
comment|/*   length */
name|char
name|aca_data
index|[
name|ACA_SIZE
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ACAFREE
parameter_list|(
name|aca
parameter_list|)
define|\
value|{ \     register int ACAI; \  \     for (ACAI = (aca) -> aca_ninfo - 1; ACAI>= 0; ACAI--) \ 	if ((aca) -> aca_info[ACAI]) \ 	    pe_free ((aca) -> aca_info[ACAI]), \ 		(aca) -> aca_info[ACAI] = NULLPE; \     (aca) -> aca_ninfo = 0; \ }
end_define

begin_struct
struct|struct
name|AcSAPindication
block|{
name|int
name|aci_type
decl_stmt|;
comment|/* the union element present */
define|#
directive|define
name|ACI_FINISH
value|0x00
define|#
directive|define
name|ACI_ABORT
value|0x01
union|union
block|{
name|struct
name|AcSAPfinish
name|aci_un_finish
decl_stmt|;
name|struct
name|AcSAPabort
name|aci_un_abort
decl_stmt|;
block|}
name|aci_un
union|;
define|#
directive|define
name|aci_finish
value|aci_un.aci_un_finish
define|#
directive|define
name|aci_abort
value|aci_un.aci_un_abort
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
name|acsapversion
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|AcInit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A-ASSOCIATE.INDICATION */
end_comment

begin_function_decl
name|int
name|AcAssocResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A-ASSOCIATE.RESPONSE */
end_comment

begin_comment
comment|/* A-ASSOCIATE.REQUEST 				   (backwards-compatible) */
end_comment

begin_define
define|#
directive|define
name|AcAssocRequest
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
parameter_list|,
name|a15
parameter_list|,
name|a16
parameter_list|,
name|a17
parameter_list|)
define|\
value|AcAsynAssocRequest (a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,0)
end_define

begin_function_decl
name|int
name|AcAsynAssocRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A-(ASYN-)ASSOCIATE.REQUEST */
end_comment

begin_function_decl
name|int
name|AcAsynRetryRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A-ASYN-RETRY.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|AcRelRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A-RELEASE.REQUEST */
end_comment

begin_function_decl
name|int
name|AcRelRetryRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A-RELEASE-RETRY.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|AcRelResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A-RELEASE.RESPONSE */
end_comment

begin_function_decl
name|int
name|AcUAbortRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A-ABORT.REQUEST */
end_comment

begin_function_decl
name|int
name|AcFINISHser
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* handle P-RELEASE.INDICATION */
end_comment

begin_function_decl
name|int
name|AcABORTser
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* handle P-{U,P}-ABORT.INDICATION */
end_comment

begin_function_decl
name|int
name|AcFindPCI
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return PCI used by ACSE */
end_comment

begin_function_decl
name|char
modifier|*
name|AcErrString
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return AcSAP error code in string form */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

