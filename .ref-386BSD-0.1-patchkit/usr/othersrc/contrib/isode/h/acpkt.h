begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* acpkt.h - include file for association control providers (AcS-PROVIDER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/acpkt.h,v 7.3 91/02/22 09:24:31 mrose Interim $  *  *  * $Log:	acpkt.h,v $  * Revision 7.3  91/02/22  09:24:31  mrose  * Interim 6.8  *   * Revision 7.2  90/07/01  21:03:46  mrose  * pepsy  *   * Revision 7.1  90/01/11  18:35:57  mrose  * real-sync  *   * Revision 7.0  89/11/23  21:55:37  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|ACSE
end_ifdef

begin_define
define|#
directive|define
name|AC_ASN
value|"acse pci version 1"
end_define

begin_define
define|#
directive|define
name|acsapPsig
parameter_list|(
name|acb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((acb = findacblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return acsaplose (aci, ACS_PARAMETER, NULLCP, \ 			    "invalid association descriptor"); \     } \     if (!(acb -> acb_flags& ACB_CONN)) { \ 	(void) sigiomask (smask); \ 	return acsaplose (aci, ACS_OPERATION, NULLCP, \ 			    "assocation descriptor not connected"); \     } \     if (acb -> acb_flags& ACB_FINN) { \ 	(void) sigiomask (smask); \ 	return acsaplose (aci, ACS_OPERATION, NULLCP, \ 			    "association descriptor finishing"); \     } \     if (acb -> acb_flags& ACB_RELEASE) { \ 	(void) sigiomask (smask); \ 	return acsaplose (aci, ACS_OPERATION, NULLCP, \ 			    "release in progress"); \     } \ }
end_define

begin_define
define|#
directive|define
name|acsapFsig
parameter_list|(
name|acb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((acb = findacblk (sd)) == NULL) {\ 	(void) sigiomask (smask);\ 	return acsaplose (aci, ACS_PARAMETER, NULLCP, \ 			    "invalid association descriptor"); \     } \     if (!(acb -> acb_flags& ACB_CONN)) { \ 	(void) sigiomask (smask); \ 	return acsaplose (aci, ACS_OPERATION, NULLCP, \ 			    "assocation descriptor not connected"); \     } \     if (!(acb -> acb_flags& ACB_FINN)) { \ 	(void) sigiomask (smask); \ 	return acsaplose (aci, ACS_OPERATION, NULLCP, \ 			    "association descriptor not finishing"); \     } \     if (acb -> acb_flags& ACB_RELEASE) { \ 	(void) sigiomask (smask); \ 	return acsaplose (aci, ACS_OPERATION, NULLCP, \ 			    "release in progress"); \     } \ }
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
value|{ \     if (b == NULL) \ 	n = 0; \     else \ 	if (n> m) \ 	    return acsaplose (aci, ACS_PARAMETER, NULLCP, \ 				"too many %s user data elements", p); \ }
end_define

begin_define
define|#
directive|define
name|missingP
parameter_list|(
name|p
parameter_list|)
define|\
value|{ \     if (p == NULL) \ 	return acsaplose (aci, ACS_PARAMETER, NULLCP, \ 			    "mandatory parameter \"%s\" missing", "p"); \ }
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
name|copyAcSAPdata
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
name|copyAcSAPdata
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
name|copyAcSAPdata
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
name|ACS_USER_BASE
value|ACS_USER_NULL
end_define

begin_define
define|#
directive|define
name|ACS_PROV_BASE
value|ACS_PROV_NULL
end_define

begin_decl_stmt
name|int
name|acpktlose
argument_list|()
decl_stmt|,
name|acsaplose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_function_decl
name|int
name|ps2acslose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|type_ACS_Association__information
modifier|*
name|info2apdu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|apdu2info
parameter_list|()
function_decl|;
end_function_decl

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
name|assocblk
block|{
name|struct
name|assocblk
modifier|*
name|acb_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|assocblk
modifier|*
name|acb_back
decl_stmt|;
comment|/*   .. */
name|int
name|acb_fd
decl_stmt|;
comment|/* session/presentation descriptor */
name|short
name|acb_flags
decl_stmt|;
comment|/* our state */
define|#
directive|define
name|ACB_NULL
value|0x0000
define|#
directive|define
name|ACB_CONN
value|0x0001
comment|/* connected */
define|#
directive|define
name|ACB_FINN
value|0x0002
comment|/* other side wants to finish */
define|#
directive|define
name|ACB_INIT
value|0x0004
comment|/* this side initiated the association */
define|#
directive|define
name|ACB_ASYN
value|0x0008
comment|/* asynchronous */
define|#
directive|define
name|ACB_TURN
value|0x0010
comment|/* we have the turn */
define|#
directive|define
name|ACB_TWA
value|0x0020
comment|/* two-way alternate */
define|#
directive|define
name|ACB_ACT
value|0x0040
comment|/* activity in progress */
define|#
directive|define
name|ACB_PLEASE
value|0x0080
comment|/* RTS: RT-TURN-PLEASE received 				   ROS on Session: sent S-PLEASE-TOKENS */
define|#
directive|define
name|ACB_TIMER
value|0x0100
comment|/* ACTIVITY discarded due to timing 				   constraint */
define|#
directive|define
name|ACB_ROS
value|0x0200
comment|/* ROS started association */
define|#
directive|define
name|ACB_RTS
value|0x0400
comment|/* RTS   .. */
define|#
directive|define
name|ACB_ACS
value|0x0800
comment|/* ACS   .. */
define|#
directive|define
name|ACB_CLOSING
value|0x1000
comment|/* waiting to close */
define|#
directive|define
name|ACB_FINISH
value|0x2000
comment|/*   .. */
define|#
directive|define
name|ACB_STICKY
value|0x4000
comment|/* ROS using RTS (ugh!) */
define|#
directive|define
name|ACB_RELEASE
value|0x8000
comment|/* release in progress */
name|struct
name|SSAPref
name|acb_connect
decl_stmt|;
comment|/* session connection reference */
name|int
name|acb_requirements
decl_stmt|;
comment|/* session requirements */
name|int
name|acb_owned
decl_stmt|;
comment|/* session tokens we own */
name|int
name|acb_avail
decl_stmt|;
comment|/* session tokens available */
name|int
name|acb_settings
decl_stmt|;
comment|/* initial settings */
name|int
name|acb_ssdusize
decl_stmt|;
comment|/* largest atomic SSDU */
name|IFP
name|acb_uabort
decl_stmt|;
comment|/* disconnect underlying service */
comment|/* ACSE */
name|int
name|acb_sversion
decl_stmt|;
comment|/* session service version number */
name|int
name|acb_id
decl_stmt|;
comment|/* ACSE context id */
name|OID
name|acb_context
decl_stmt|;
comment|/* application context name */
name|int
name|acb_offset
decl_stmt|;
comment|/* offset to ACSE PCI */
comment|/* negative means at END */
name|PE
name|acb_retry
decl_stmt|;
comment|/* final acpkt */
comment|/* RTSE */
name|int
name|acb_rtsid
decl_stmt|;
comment|/* RTSE context id */
name|int
name|acb_ckpoint
decl_stmt|;
comment|/* checkpoint size */
name|int
name|acb_window
decl_stmt|;
comment|/* window size */
name|int
name|acb_actno
decl_stmt|;
comment|/* sending activity serial number */
name|long
name|acb_ssn
decl_stmt|;
comment|/* highest serial number sent */
name|int
name|acb_ack
decl_stmt|;
comment|/* highest serial number acknowledged */
name|IFP
name|acb_pturnrequest
decl_stmt|;
comment|/* RT-TURN-PLEASE.REQUEST */
name|IFP
name|acb_gturnrequest
decl_stmt|;
comment|/* RT-TURN-GIVE.REQUEST */
name|IFP
name|acb_transferequest
decl_stmt|;
comment|/* RT-TRANSER.REQUEST */
name|IFP
name|acb_rtwaitrequest
decl_stmt|;
comment|/* RT-WAIT.REQUEST */
name|IFP
name|acb_rtsetindications
decl_stmt|;
comment|/* define vectors for INDICATION events */
name|IFP
name|acb_rtselectmask
decl_stmt|;
comment|/* map association descriptors for select () */
name|IFP
name|acb_rtpktlose
decl_stmt|;
comment|/* protocol-level abort */
name|int
name|acb_priority
decl_stmt|;
comment|/* priority of please turn */
name|struct
name|AcSAPfinish
name|acb_finish
decl_stmt|;
name|char
modifier|*
name|acb_realbase
decl_stmt|;
comment|/* APDU in transit */
name|char
modifier|*
name|acb_base
decl_stmt|;
comment|/*   .. */
name|int
name|acb_len
decl_stmt|;
comment|/*   .. */
name|IFP
name|acb_uptrans
decl_stmt|;
comment|/* upcall for up-transfer */
name|IFP
name|acb_downtrans
decl_stmt|;
comment|/* upcall for down-transfer */
name|IFP
name|acb_rtsindication
decl_stmt|;
comment|/* rts event handler */
comment|/* ROSE */
name|int
name|acb_rosid
decl_stmt|;
comment|/* ROSE (SASE) context id */
name|IFP
name|acb_putosdu
decl_stmt|;
comment|/* osdu2acb */
name|IFP
name|acb_rowaitrequest
decl_stmt|;
comment|/* RO-WAIT.REQUEST */
name|IFP
name|acb_ready
decl_stmt|;
comment|/* get HDX permission */
name|IFP
name|acb_rosetindications
decl_stmt|;
comment|/* define vectors for INDICATION events */
name|IFP
name|acb_roselectmask
decl_stmt|;
comment|/* map association descriptors for select () */
name|IFP
name|acb_ropktlose
decl_stmt|;
comment|/* protocol-level abort */
name|PE
function_decl|(
modifier|*
name|acb_getosdu
function_decl|)
parameter_list|()
function_decl|;
comment|/* for users of THORN... */
name|PE
name|acb_apdu
decl_stmt|;
comment|/* APDU buffered */
name|IFP
name|acb_rosindication
decl_stmt|;
comment|/* ros event handler */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLACB
value|((struct assocblk *) 0)
end_define

begin_define
define|#
directive|define
name|FREEACB
parameter_list|(
name|acb
parameter_list|)
define|\
value|{ \     if ((acb) -> acb_realbase) \ 	free ((acb) -> acb_realbase); \     else \ 	if ((acb) -> acb_base) \ 	    free ((acb) -> acb_base); \     (acb) -> acb_realbase = (acb) -> acb_base = NULL, (acb) -> acb_len = 0; \ }
end_define

begin_function_decl
name|int
name|freeacblk
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|assocblk
modifier|*
name|newacblk
argument_list|()
decl_stmt|,
modifier|*
name|findacblk
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACSE
end_ifndef

begin_comment
comment|/* PConnect Types */
end_comment

begin_define
define|#
directive|define
name|PCONN_DTS
value|0
end_define

begin_comment
comment|/* Data Transfer Syntax */
end_comment

begin_define
define|#
directive|define
name|PCONN_DATA
value|1
end_define

begin_comment
comment|/* User Data */
end_comment

begin_define
define|#
directive|define
name|PCONN_DATA_CK
value|0
end_define

begin_comment
comment|/*   Checkpoint Size */
end_comment

begin_define
define|#
directive|define
name|PCONN_CK_DFLT
value|0
end_define

begin_define
define|#
directive|define
name|PCONN_DATA_WD
value|1
end_define

begin_comment
comment|/*   Window Size */
end_comment

begin_define
define|#
directive|define
name|PCONN_WD_DFLT
value|3
end_define

begin_define
define|#
directive|define
name|PCONN_DATA_DM
value|2
end_define

begin_comment
comment|/*   Dialogue-mode */
end_comment

begin_define
define|#
directive|define
name|PCONN_DM_MONO
value|0
end_define

begin_comment
comment|/*     monologue */
end_comment

begin_define
define|#
directive|define
name|PCONN_DM_TWA
value|1
end_define

begin_comment
comment|/*     two-way alternate */
end_comment

begin_define
define|#
directive|define
name|PCONN_DM_DFLT
value|PCONN_DM_MONO
end_define

begin_define
define|#
directive|define
name|PCONN_DATA_CN
value|3
end_define

begin_comment
comment|/*   Connection Data */
end_comment

begin_define
define|#
directive|define
name|PCONN_DATA_AP
value|4
end_define

begin_comment
comment|/*   Application Protocol */
end_comment

begin_define
define|#
directive|define
name|PCONN_AP_DFLT
value|1
end_define

begin_comment
comment|/* PAccept Types */
end_comment

begin_define
define|#
directive|define
name|PACC_DTS
value|0
end_define

begin_comment
comment|/* Data Transfer Syntax */
end_comment

begin_define
define|#
directive|define
name|PACC_DATA
value|1
end_define

begin_comment
comment|/* User Data */
end_comment

begin_define
define|#
directive|define
name|PACC_DATA_CK
value|0
end_define

begin_comment
comment|/*   Checkpoint Size */
end_comment

begin_define
define|#
directive|define
name|PACC_CK_DFLT
value|0
end_define

begin_define
define|#
directive|define
name|PACC_DATA_WD
value|1
end_define

begin_comment
comment|/*   Window Size */
end_comment

begin_define
define|#
directive|define
name|PACC_WD_DFLT
value|3
end_define

begin_define
define|#
directive|define
name|PACC_DATA_CN
value|2
end_define

begin_comment
comment|/*   Connection Data */
end_comment

begin_comment
comment|/* PRefuse Types */
end_comment

begin_define
define|#
directive|define
name|PREF_REASON
value|0
end_define

begin_comment
comment|/* Refuse Reason */
end_comment

begin_comment
comment|/* Data Transfer Syntax Types */
end_comment

begin_define
define|#
directive|define
name|DTS_SYNTAX
value|0
end_define

begin_comment
comment|/* IMPLICIT INTEGER */
end_comment

begin_define
define|#
directive|define
name|SYN_X409
value|0
end_define

begin_comment
comment|/* x.409 */
end_comment

begin_comment
comment|/* Connection Data Types */
end_comment

begin_define
define|#
directive|define
name|CN_OPEN
value|0
end_define

begin_comment
comment|/* Open */
end_comment

begin_define
define|#
directive|define
name|CN_RECOVER
value|1
end_define

begin_comment
comment|/* Recover */
end_comment

begin_comment
comment|/* Refuse codes */
end_comment

begin_define
define|#
directive|define
name|REFUSE_BUSY
value|0
end_define

begin_comment
comment|/* Busy */
end_comment

begin_define
define|#
directive|define
name|REFUSE_RECOVER
value|1
end_define

begin_comment
comment|/* Cannot recover */
end_comment

begin_define
define|#
directive|define
name|REFUSE_VALIDATE
value|2
end_define

begin_comment
comment|/* Validation failure */
end_comment

begin_define
define|#
directive|define
name|REFUSE_MODE
value|3
end_define

begin_comment
comment|/* Unacceptable dialogue mode */
end_comment

begin_comment
comment|/* Abort codes */
end_comment

begin_define
define|#
directive|define
name|ABORT_LSP
value|0
end_define

begin_comment
comment|/* Local system problem */
end_comment

begin_define
define|#
directive|define
name|ABORT_INV
value|1
end_define

begin_comment
comment|/* Invalid parameter */
end_comment

begin_define
define|#
directive|define
name|ABORT_ACT
value|2
end_define

begin_comment
comment|/* Unrecognized activity */
end_comment

begin_define
define|#
directive|define
name|ABORT_TMP
value|3
end_define

begin_comment
comment|/* Temporary problem */
end_comment

begin_define
define|#
directive|define
name|ABORT_PROTO
value|4
end_define

begin_comment
comment|/* Protocol error */
end_comment

begin_define
define|#
directive|define
name|ABORT_PERM
value|5
end_define

begin_comment
comment|/* Permanent problem */
end_comment

begin_define
define|#
directive|define
name|ABORT_USER
value|6
end_define

begin_comment
comment|/* User abort */
end_comment

begin_define
define|#
directive|define
name|ABORT_TRANS
value|7
end_define

begin_comment
comment|/* Transfer completed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

