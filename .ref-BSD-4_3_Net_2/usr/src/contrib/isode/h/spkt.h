begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* spkt.h - include file for session providers (SS-PROVIDER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/spkt.h,v 7.2 91/02/22 09:25:07 mrose Interim $  *  *  * $Log:	spkt.h,v $  * Revision 7.2  91/02/22  09:25:07  mrose  * Interim 6.8  *   * Revision 7.1  89/11/27  10:30:35  mrose  * sync  *   * Revision 7.0  89/11/23  21:56:00  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

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

begin_include
include|#
directive|include
file|"tsap.h"
end_include

begin_comment
comment|/* definitions for TS-USERs */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|ssapPsig
parameter_list|(
name|sb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((sb = findsblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_PARAMETER, NULLCP, \ 			    "invalid session descriptor"); \     } \     if (!(sb -> sb_flags& SB_CONN)) {\ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_PARAMETER, NULLCP, \ 			    "session descriptor not connected"); \     } \     if (sb -> sb_flags& SB_FINN) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "session descriptor finishing"); \     } \     if (sb -> sb_flags& SB_RELEASE) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "release in progress"); \     } \     if (sb -> sb_flags& SB_MAP) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "majorsync in progress"); \     } \     if (sb -> sb_flags& SB_RS) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "resync in progress"); \     } \     if (sb -> sb_flags& SB_RA) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "awaiting your resync response"); \     } \     if (sb -> sb_flags& SB_AI) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "activity interrupt/discard in progress"); \     } \     if (sb -> sb_flags& SB_AIA) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "awaiting your activity interrupt/discard response"); \     } \     if (sb -> sb_flags& (SB_ED | SB_EDACK | SB_ERACK)) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "exception in progress"); \     } \ }
end_define

begin_define
define|#
directive|define
name|ssapXsig
parameter_list|(
name|sb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((sb = findsblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_PARAMETER, NULLCP, \ 			    "invalid session descriptor"); \     } \     if (!(sb -> sb_flags& SB_CONN)) {\ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_PARAMETER, NULLCP, \ 			    "session descriptor not connected"); \     } \     if (sb -> sb_flags& SB_FINN) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "session descriptor finishing"); \     } \     if (sb -> sb_flags& SB_RELEASE) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "release in progress"); \     } \     if (sb -> sb_flags& SB_RS) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "resync in progress"); \     } \     if (sb -> sb_flags& SB_RA) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "awaiting your resync response"); \     } \     if (sb -> sb_flags& SB_AI) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "activity interrupt/discard in progress"); \     } \     if (sb -> sb_flags& SB_AIA) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "awaiting your activity interrupt/discard response"); \     } \     if (sb -> sb_flags& SB_ED) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "exception in progress"); \     } \ }
end_define

begin_define
define|#
directive|define
name|ssapRsig
parameter_list|(
name|sb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((sb = findsblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_PARAMETER, NULLCP, \ 			    "invalid session descriptor"); \     } \     if (!(sb -> sb_flags& SB_CONN)) {\ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_PARAMETER, NULLCP, \ 			    "session descriptor not connected"); \     } \     if (sb -> sb_flags& SB_FINN) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "session descriptor finishing"); \     } \     if (sb -> sb_flags& SB_RELEASE) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "release in progress"); \     } \     if (sb -> sb_flags& SB_RS) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "resync in progress"); \     } \     if (sb -> sb_flags& SB_AI) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "activity interrupt/discard in progress"); \     } \     if (sb -> sb_flags& SB_AIA) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "awaiting your activity interrupt/discard response"); \     } \     if (sb -> sb_flags& SB_AE) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "activity end in progress"); \     } \     if (sb -> sb_flags& SB_ED) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "exception in progress"); \     } \ }
end_define

begin_define
define|#
directive|define
name|ssapAsig
parameter_list|(
name|sb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((sb = findsblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_PARAMETER, NULLCP, \ 			    "invalid session descriptor"); \     } \     if (!(sb -> sb_flags& SB_CONN)) {\ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_PARAMETER, NULLCP, \ 			    "session descriptor not connected"); \     } \     if (sb -> sb_flags& SB_FINN) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "session descriptor finishing"); \     } \     if (sb -> sb_flags& SB_RELEASE) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "release in progress"); \     } \     if (sb -> sb_flags& SB_MAA) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "awaiting your majorsync response"); \     } \     if (sb -> sb_flags& SB_RS) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "resync in progress"); \     } \     if (sb -> sb_flags& SB_AI) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "activity interrupt/discard in response"); \     } \     if (sb -> sb_flags& (SB_ED | SB_EDACK | SB_ERACK)) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "exception in progress"); \     } \ }
end_define

begin_define
define|#
directive|define
name|ssapFsig
parameter_list|(
name|sb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((sb = findsblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_PARAMETER, NULLCP, \ 			    "invalid session descriptor"); \     } \     if (!(sb -> sb_flags& SB_CONN)) {\ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_PARAMETER, NULLCP, \ 			    "session descriptor not connected"); \     } \     if (!(sb -> sb_flags& SB_FINN)) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "session descriptor not finishing"); \     } \     if (sb -> sb_flags& SB_RELEASE) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "release in progress"); \     } \     if (sb -> sb_flags& SB_MAA) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "awaiting your majorsync response"); \     } \     if (sb -> sb_flags& SB_RS) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "resync in progress"); \     } \     if (sb -> sb_flags& SB_RA) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "awaiting your resync response"); \     } \     if (sb -> sb_flags& SB_AI) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "activity interrupt/discard in progress"); \     } \     if (sb -> sb_flags& SB_AIA) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "awaiting your activity interrupt/discard response"); \     } \     if (sb -> sb_flags& (SB_ED | SB_EDACK | SB_ERACK)) { \ 	(void) sigiomask (smask); \ 	return ssaplose (si, SC_OPERATION, NULLCP, \ 			    "exception in progress"); \     } \ }
end_define

begin_define
define|#
directive|define
name|missingP
parameter_list|(
name|p
parameter_list|)
define|\
value|{ \     if (p == NULL) \ 	return ssaplose (si, SC_PARAMETER, NULLCP, \ 			    "mandatory parameter \"%s\" missing", "p"); \ }
end_define

begin_define
define|#
directive|define
name|refmuchP
parameter_list|(
name|sr
parameter_list|)
define|\
value|{ \     if ((sr) -> sr_ulen> SREF_USER_SIZE \ 	    || (sr) -> sr_clen> SREF_COMM_SIZE \ 	    || (sr) -> sr_alen> SREF_ADDT_SIZE \ 	    || (sr) -> sr_vlen> SREF_USER_SIZE) \ 	return ssaplose (si, SC_PARAMETER, NULLCP, \ 		"bad format for reference"); \ }
end_define

begin_define
define|#
directive|define
name|idmuchP
parameter_list|(
name|sd
parameter_list|)
define|\
value|{ \     if ((sd) -> sd_len> SID_DATA_SIZE) \ 	return ssaplose (si, SC_PARAMETER, NULLCP, \ 		"bad format for activity ID"); \ }
end_define

begin_define
define|#
directive|define
name|toomuchP
parameter_list|(
name|sb
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|,
name|m
parameter_list|,
name|p
parameter_list|)
define|\
value|{ \     if (b == NULL) \ 	n = 0; \     else \ 	if (n> (sb -> sb_version< SB_VRSN2 ? m : ENCLOSE_MAX)) { \ 	    (void) sigiomask (smask); \ 	    return ssaplose (si, SC_PARAMETER, NULLCP, \ 			    "too much %s user data, %d octets", p, n); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|NULLTX
value|((struct TSAPdata *) 0)
end_define

begin_define
define|#
directive|define
name|NULLSD
value|((struct SSAPactid *) 0)
end_define

begin_define
define|#
directive|define
name|NULLSR
value|((struct SSAPref *) 0)
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
name|copySSAPdata
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

begin_define
define|#
directive|define
name|copySPKTdata
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
define|\
value|{ \     d -> d
comment|/* */
value|_data = s -> s_udata, d -> d
comment|/* */
value|_cc = s -> s_ulen; \     s -> s_udata = NULL; \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|copySSAPdata
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

begin_define
define|#
directive|define
name|copySPKTdata
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
define|\
value|{ \     d -> d##_data = s -> s_udata, d -> d##_cc = s -> s_ulen; \     s -> s_udata = NULL; \ }
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
name|copySSAPdata
parameter_list|(
name|base
parameter_list|,
name|len
parameter_list|,
name|d
parameter_list|)
value|bcopy (base, (char *) d, len)
end_define

begin_define
define|#
directive|define
name|copySPKTdata
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|bcopy (s -> s_udata, (char *) d, s -> s_ulen)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AB_TIM
value|30
end_define

begin_comment
comment|/* drain for 30 seconds on ABORTs */
end_comment

begin_define
define|#
directive|define
name|RF_TIM
value|30
end_define

begin_comment
comment|/* drain for 30 seconds on REFUSEs */
end_comment

begin_define
define|#
directive|define
name|SC_REFUSE
value|(SC_BASE<< 1)
end_define

begin_comment
comment|/* larger than any sc_reason */
end_comment

begin_decl_stmt
name|int
name|spktlose
argument_list|()
decl_stmt|,
name|ssaplose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|ssapblk
block|{
name|struct
name|ssapblk
modifier|*
name|sb_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|ssapblk
modifier|*
name|sb_back
decl_stmt|;
comment|/*   .. */
name|int
name|sb_fd
decl_stmt|;
comment|/* transport descriptor */
name|int
name|sb_version
decl_stmt|;
comment|/* version number of protocol */
define|#
directive|define
name|SB_VRSN1
value|0
comment|/*   1 */
define|#
directive|define
name|SB_VRSN2
value|1
comment|/*   2 */
define|#
directive|define
name|SB_ALLVRSNS
value|((1<< SB_VRSN1) | (1<< SB_VRSN2))
name|int
name|sb_vrsnmask
decl_stmt|;
comment|/* for initiating SPM... */
name|long
name|sb_flags
decl_stmt|;
comment|/* our state */
define|#
directive|define
name|SB_NULL
value|0x000000
define|#
directive|define
name|SB_CONN
value|0x000001
comment|/* connected */
define|#
directive|define
name|SB_FINN
value|0x000002
comment|/* other side wants to finish */
define|#
directive|define
name|SB_INIT
value|0x000004
comment|/* this side initiated the session */
define|#
directive|define
name|SB_ASYN
value|0x000008
comment|/* asynchronous */
define|#
directive|define
name|SB_EXPD
value|0x000010
comment|/* expedited service available on transport */
define|#
directive|define
name|SB_CD
value|0x000020
comment|/* CD request in progress */
define|#
directive|define
name|SB_CDA
value|0x000040
comment|/* awaiting CD response from user */
define|#
directive|define
name|SB_GTC
value|0x000080
comment|/* GTC request in progress */
define|#
directive|define
name|SB_MAP
value|0x000100
comment|/* MAP request in progress */
define|#
directive|define
name|SB_MAA
value|0x000200
comment|/* awaiting MAP response from user */
define|#
directive|define
name|SB_AE
value|0x000400
comment|/* MAP is really AE */
define|#
directive|define
name|SB_RS
value|0x000800
comment|/* RS request in progress */
define|#
directive|define
name|SB_RA
value|0x001000
comment|/* awaiting RS response from user */
define|#
directive|define
name|SB_AI
value|0x002000
comment|/* AI request in progress */
define|#
directive|define
name|SB_AIA
value|0x004000
comment|/* awaiting AI response from user */
define|#
directive|define
name|SB_ED
value|0x008000
comment|/* user exception in progress */
define|#
directive|define
name|SB_EDACK
value|0x010000
comment|/* awaiting user exception to be cleared */
define|#
directive|define
name|SB_ERACK
value|0x020000
comment|/* awaiting provider exception to be cleared */
define|#
directive|define
name|SB_Vact
value|0x040000
comment|/* activity in progress */
define|#
directive|define
name|SB_Vsc
value|0x080000
comment|/* okay to reply to minorsync */
define|#
directive|define
name|SB_Vnextact
value|0x100000
comment|/* activity MAP sent/received */
define|#
directive|define
name|SB_RELEASE
value|0x200000
comment|/* release in progress */
name|struct
name|ssapkt
modifier|*
name|sb_retry
decl_stmt|;
comment|/* initial/final spkt */
name|long
name|sb_V_A
decl_stmt|;
comment|/* lowest unconfirmed ssn */
name|long
name|sb_V_M
decl_stmt|;
comment|/* next ssn */
name|long
name|sb_V_R
decl_stmt|;
comment|/* lowest ssn for resynchronization */
name|int
name|sb_rs
decl_stmt|;
comment|/* resynchronization type 				     (an SYNC_xxx code, plus...) */
define|#
directive|define
name|SYNC_INTR
value|3
comment|/* Activity Interrupt */
define|#
directive|define
name|SYNC_DISC
value|4
comment|/* Activity Discard */
name|long
name|sb_rsn
decl_stmt|;
comment|/* resync serial number */
name|u_char
name|sb_rsettings
decl_stmt|;
comment|/* proposed token settings */
name|int
name|sb_pr
decl_stmt|;
comment|/* SPDU to prepare for (an SPDU code) */
name|struct
name|ssapkt
modifier|*
name|sb_xspdu
decl_stmt|;
comment|/* saved expedited SPDU 				   (really should be a linked list!) */
name|struct
name|ssapkt
modifier|*
name|sb_spdu
decl_stmt|;
comment|/* for concatenated SPDUs */
name|struct
name|qbuf
name|sb_qbuf
decl_stmt|;
comment|/* for segmented (T)SSDUs */
name|int
name|sb_len
decl_stmt|;
comment|/*   .. */
name|int
name|sb_code
decl_stmt|;
comment|/*   .. */
name|u_char
name|sb_options
decl_stmt|;
comment|/* connect options */
name|u_char
name|sb_settings
decl_stmt|;
comment|/* tokens settings on connect */
name|u_short
name|sb_tsdu_us
decl_stmt|;
comment|/* our max TSDU size */
name|u_short
name|sb_tsdu_them
decl_stmt|;
comment|/* their max TSDU size */
define|#
directive|define
name|BAD_TSDU_SIZE
parameter_list|(
name|s
parameter_list|)
value|((s) ? (s)< DT_MINSIZE : 0)
define|#
directive|define
name|GET_TSDU_SIZE
parameter_list|(
name|s
parameter_list|)
value|((s)< DT_MINSIZE ? 0 : (s))
name|u_char
name|sb_owned
decl_stmt|;
comment|/* tokens we own */
name|u_short
name|sb_requirements
decl_stmt|;
comment|/* functional units selected */
name|struct
name|SSAPaddr
name|sb_initiating
decl_stmt|;
comment|/* initiator */
name|struct
name|SSAPaddr
name|sb_responding
decl_stmt|;
comment|/* responder */
name|int
name|sb_maxtime
decl_stmt|;
comment|/* for SPM response during S-CONNECT */
name|IFP
name|sb_DataIndication
decl_stmt|;
comment|/* INDICATION handlers */
name|IFP
name|sb_TokenIndication
decl_stmt|;
comment|/*   .. */
name|IFP
name|sb_SyncIndication
decl_stmt|;
comment|/*   .. */
name|IFP
name|sb_ActivityIndication
decl_stmt|;
comment|/*   .. */
name|IFP
name|sb_ReportIndication
decl_stmt|;
comment|/*   .. */
name|IFP
name|sb_ReleaseIndication
decl_stmt|;
comment|/*   .. */
name|IFP
name|sb_AbortIndication
decl_stmt|;
comment|/*   .. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLBP
value|((struct ssapblk *) 0)
end_define

begin_function_decl
name|int
name|freesblk
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|ssapblk
modifier|*
name|newsblk
argument_list|()
decl_stmt|,
modifier|*
name|findsblk
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ts2sslose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|spkt2sd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ssapkt
modifier|*
name|sb2spkt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|SPKT datastructure */
end_comment

begin_struct
struct|struct
name|ssapkt
block|{
name|int
name|s_errno
decl_stmt|;
name|int
name|s_mask
decl_stmt|;
name|u_char
name|s_code
decl_stmt|;
define|#
directive|define
name|SPDU_CN
value|0x0d
comment|/* CONNECT */
define|#
directive|define
name|SPDU_AC
value|0x0e
comment|/* ACCEPT */
define|#
directive|define
name|SPDU_RF
value|0x0c
comment|/* REFUSE */
define|#
directive|define
name|SPDU_FN
value|0x09
comment|/* FINISH */
define|#
directive|define
name|SPDU_DN
value|0x0a
comment|/* DISCONNECT */
define|#
directive|define
name|SPDU_NF
value|0x08
comment|/* NOT FINISHED */
define|#
directive|define
name|SPDU_AB
value|0x19
comment|/* ABORT */
define|#
directive|define
name|SPDU_AA
value|0x1a
comment|/* ABORT ACCEPT */
define|#
directive|define
name|SPDU_DT
value|SPDU_GT
comment|/* DATA TRANSFER */
define|#
directive|define
name|SPDU_EX
value|0x05
comment|/* EXPEDITED */
define|#
directive|define
name|SPDU_TD
value|0x21
comment|/* TYPED DATA */
define|#
directive|define
name|SPDU_CD
value|0x3d
comment|/* CAPABILITY DATA */
define|#
directive|define
name|SPDU_CDA
value|0x3e
comment|/* CAPABILITY DATA ACK */
define|#
directive|define
name|SPDU_GT
value|0x01
comment|/* GIVE TOKENS */
define|#
directive|define
name|SPDU_PT
value|0x02
comment|/* PLEASE TOKENS */
define|#
directive|define
name|SPDU_GTC
value|0x15
comment|/* GIVE TOKENS CONFIRM */
define|#
directive|define
name|SPDU_GTA
value|0x16
comment|/* GIVE TOKENS ACK */
define|#
directive|define
name|SPDU_MIP
value|0x31
comment|/* MINOR SYNCHRONIZATION POINT */
define|#
directive|define
name|SPDU_MIA
value|0x32
comment|/* MINOR SYNC ACK */
define|#
directive|define
name|SPDU_MAP
value|0x29
comment|/* MAJOR SYNCHRONIZATION POINT */
define|#
directive|define
name|SPDU_MAA
value|0x2a
comment|/* MAJOR SYNC ACK */
define|#
directive|define
name|SPDU_RS
value|0x35
comment|/* RESYNCHRONIZE */
define|#
directive|define
name|SPDU_RA
value|0x22
comment|/* RESYNCHRONIZE ACK */
define|#
directive|define
name|SPDU_PR
value|0x07
comment|/* PREPARE */
define|#
directive|define
name|SPDU_ER
value|0x00
comment|/* EXCEPTION REPORT */
define|#
directive|define
name|SPDU_ED
value|0x30
comment|/* EXCEPTION DATA */
define|#
directive|define
name|SPDU_AS
value|0x2d
comment|/* ACTIVITY START */
define|#
directive|define
name|SPDU_AR
value|0x1d
comment|/* ACTIVITY RESUME */
define|#
directive|define
name|SPDU_AI
value|SPDU_AB
comment|/* ACTIVITY INTERRUPT */
define|#
directive|define
name|SPDU_AIA
value|SPDU_AA
comment|/* ACTIVITY INTERRUPT ACK */
define|#
directive|define
name|SPDU_AD
value|0x39
comment|/* ACTIVITY DISCARD */
define|#
directive|define
name|SPDU_ADA
value|0x3a
comment|/* ACTIVITY DISCARD ACK */
define|#
directive|define
name|SPDU_AE
value|SPDU_MAP
comment|/* ACTIVITY END */
define|#
directive|define
name|SPDU_AEA
value|SPDU_MAA
comment|/* ACTIVITY END ACK */
name|u_long
name|s_li
decl_stmt|;
define|#
directive|define
name|SPDU_MAXLEN
value|65535
comment|/* segment if SSDU larger */
comment|/* A nice magic number: 	for the GT SPDU, 2 octets 	for the DT SPDU, 2 octets + 3 octets for the enclosure option      2 + 2 + 3 = 7  */
define|#
directive|define
name|SSDU_MAGIC
value|7
union|union
block|{
struct|struct
block|{
comment|/* CONNECT/ACCEPT SPDU */
define|#
directive|define
name|SMASK_CN_REF
value|0x0001
name|struct
name|SSAPref
name|un_cn_reference
decl_stmt|;
struct|struct
block|{
define|#
directive|define
name|SMASK_CN_OPT
value|0x0002
name|u_char
name|un_cn_options
decl_stmt|;
define|#
directive|define
name|CR_OPT_NULL
value|0x00
define|#
directive|define
name|CR_OPT_EXTD
value|0x01
comment|/* will receive extended concatenated SPDUs, 				   this implementation DOESN'T; segmenting is 				   enough... */
define|#
directive|define
name|CR_OPT_MASK
value|CR_OPT_EXTD
define|#
directive|define
name|SMASK_CN_TSDU
value|0x0004
name|u_short
name|un_cn_tsdu_init
decl_stmt|;
name|u_short
name|un_cn_tsdu_resp
decl_stmt|;
define|#
directive|define
name|SMASK_CN_VRSN
value|0x0008
name|u_char
name|un_cn_version
decl_stmt|;
define|#
directive|define
name|SMASK_CN_ISN
value|0x0010
define|#
directive|define
name|SIZE_CN_ISN
value|6
name|u_long
name|un_cn_isn
decl_stmt|;
define|#
directive|define
name|SMASK_CN_SET
value|0x0020
name|u_char
name|un_settings
decl_stmt|;
block|}
name|un_cn_item
struct|;
define|#
directive|define
name|SMASK_AC_TOKEN
value|0x0040
name|u_char
name|un_ac_token
decl_stmt|;
comment|/* ACCEPT SPDU only */
define|#
directive|define
name|SMASK_CN_REQ
value|0x0080
name|u_short
name|un_cn_requirements
decl_stmt|;
define|#
directive|define
name|SMASK_CN_CALLING
value|0x0100
name|char
name|un_cn_calling
index|[
name|SSSIZE
index|]
decl_stmt|;
name|int
name|un_cn_callinglen
decl_stmt|;
define|#
directive|define
name|SMASK_CN_CALLED
value|0x0200
name|char
name|un_cn_called
index|[
name|SSSIZE
index|]
decl_stmt|;
name|int
name|un_cn_calledlen
decl_stmt|;
block|}
name|un_cn
struct|;
define|#
directive|define
name|CN_SIZE
value|512
define|#
directive|define
name|CONNECT_MAX
value|10240
comment|/* someday support CDO/OA SPDUs and Data 				   Overflow PI... */
define|#
directive|define
name|CN_BASE_SIZE
value|56
define|#
directive|define
name|AC_SIZE
value|512
define|#
directive|define
name|AC_BASE_SIZE
value|62
struct|struct
block|{
comment|/* REFUSE SPDU */
define|#
directive|define
name|SMASK_RF_REF
value|0x0001
name|struct
name|SSAPref
name|un_rf_reference
decl_stmt|;
define|#
directive|define
name|SMASK_RF_DISC
value|0x0002
name|u_char
name|un_rf_disconnect
decl_stmt|;
define|#
directive|define
name|RF_DISC_RELEASE
value|0x01
comment|/* release transport connection */
define|#
directive|define
name|RF_DISC_MASK
value|RF_DISC_RELEASE
define|#
directive|define
name|SMASK_RF_REQ
value|0x0004
name|u_short
name|un_rf_requirements
decl_stmt|;
define|#
directive|define
name|SMASK_RF_VRSN
value|0x0008
name|u_char
name|un_rf_version
decl_stmt|;
name|char
modifier|*
name|un_rf_rdata
decl_stmt|;
name|int
name|un_rf_rlen
decl_stmt|;
block|}
name|un_rf
struct|;
define|#
directive|define
name|RF_SIZE
value|513
define|#
directive|define
name|RF_BASE_SIZE
value|13
struct|struct
block|{
comment|/* FINISH SPDU */
define|#
directive|define
name|SMASK_FN_DISC
value|0x0001
name|u_char
name|un_fn_disconnect
decl_stmt|;
define|#
directive|define
name|FN_DISC_RELEASE
value|0x01
comment|/* release transport connection */
define|#
directive|define
name|FN_DISC_MASK
value|FN_DISC_RELEASE
block|}
name|un_fn
struct|;
define|#
directive|define
name|FN_SIZE
value|512
define|#
directive|define
name|FN_BASE_SIZE
value|6
comment|/* DISCONNECT SPDU */
define|#
directive|define
name|DN_SIZE
value|512
define|#
directive|define
name|DN_BASE_SIZE
value|3
comment|/* NOT FINISHED SPDU */
define|#
directive|define
name|NF_SIZE
value|512
define|#
directive|define
name|NF_BASE_SIZE
value|3
struct|struct
block|{
comment|/* ABORT SPDU */
define|#
directive|define
name|SMASK_AB_DISC
value|0x0001
name|u_char
name|un_ab_disconnect
decl_stmt|;
define|#
directive|define
name|AB_DISC_RELEASE
value|0x01
comment|/* release transport connection */
define|#
directive|define
name|AB_DISC_USER
value|0x02
comment|/* user abort */
define|#
directive|define
name|AB_DISC_PROTO
value|0x04
comment|/* protocol error */
define|#
directive|define
name|AB_DISC_UNKNOWN
value|0x08
comment|/* no reason */
define|#
directive|define
name|AB_DISC_MASK
value|(AB_DISC_RELEASE | AB_DISC_USER | AB_DISC_PROTO \ 			    | AB_DISC_UNKNOWN)
define|#
directive|define
name|SMASK_AB_REFL
value|0x0002
define|#
directive|define
name|AB_REFL_SIZE
value|9
name|u_char
name|un_ab_reflect
index|[
name|AB_REFL_SIZE
index|]
decl_stmt|;
block|}
name|un_ab
struct|;
define|#
directive|define
name|AB_SIZE
value|9
define|#
directive|define
name|AB_BASE_SIZE
value|17
define|#
directive|define
name|SMASK_SPDU_AB
value|0x0004
comment|/* to distinguish between AB and AI SPDUs */
comment|/* ABORT ACCEPT SPDU */
define|#
directive|define
name|AA_SIZE
value|0
define|#
directive|define
name|AA_BASE_SIZE
value|0
define|#
directive|define
name|SMASK_SPDU_AA
value|0x0001
comment|/* to distinguish between AA and AIA SPDUs */
comment|/* DATA TRANSFER SPDU */
define|#
directive|define
name|DT_SIZE
value|65535
define|#
directive|define
name|DT_MINSIZE
value|64
comment|/* don't segment if MSS< this */
define|#
directive|define
name|DT_BASE_SIZE
value|3
comment|/* EXPEDITED DATA SPDU */
define|#
directive|define
name|EX_SIZE
value|SX_EXSIZE
define|#
directive|define
name|EX_BASE_SIZE
value|0
comment|/* TYPED DATA SPDU */
define|#
directive|define
name|TD_SIGHS
value|65535
comment|/* should be TD_SIZE, but<tsap.h> 				   got there first */
define|#
directive|define
name|TD_MINSIZE
value|64
comment|/* don't segment if MSS< this */
define|#
directive|define
name|TD_BASE_SIZE
value|3
comment|/* CAPABILITY DATA SPDU */
define|#
directive|define
name|CD_SIZE
value|SX_CDSIZE
define|#
directive|define
name|CD_BASE_SIZE
value|3
comment|/* CAPABILITY DATA ACK SPDU */
define|#
directive|define
name|CDA_SIZE
value|SX_CDASIZE
define|#
directive|define
name|CDA_BASE_SIZE
value|3
struct|struct
block|{
comment|/* GIVE TOKENS SPDU */
define|#
directive|define
name|SMASK_GT_TOKEN
value|0x0001
name|u_char
name|un_gt_token
decl_stmt|;
block|}
name|un_gt
struct|;
define|#
directive|define
name|GT_SIZE
value|0
define|#
directive|define
name|GT_BASE_SIZE
value|3
define|#
directive|define
name|SMASK_SPDU_GT
value|0x0002
comment|/* to distinguish between DT and GT SPDUs */
struct|struct
block|{
comment|/* PLEASE TOKENS SPDU */
define|#
directive|define
name|SMASK_PT_TOKEN
value|0x0001
name|u_char
name|un_pt_token
decl_stmt|;
block|}
name|un_pt
struct|;
define|#
directive|define
name|PT_SIZE
value|512
define|#
directive|define
name|PT_BASE_SIZE
value|6
comment|/* GIVE TOKENS CONFIRM SPDU */
define|#
directive|define
name|GTC_SIZE
value|0
define|#
directive|define
name|GTC_BASE_SIZE
value|0
comment|/* GIVE TOKENS ACK SPDU */
define|#
directive|define
name|GTA_SIZE
value|0
define|#
directive|define
name|GTA_BASE_SIZE
value|0
struct|struct
block|{
comment|/* MINOR SYNC POINT SPDU */
define|#
directive|define
name|SMASK_MIP_SYNC
value|0x0001
name|u_char
name|un_mip_sync
decl_stmt|;
define|#
directive|define
name|MIP_SYNC_NOEXPL
value|0x01
comment|/* NO EXPLICIT ACK REQUIRED */
define|#
directive|define
name|MIP_SYNC_MASK
value|MIP_SYNC_NOEXPL
define|#
directive|define
name|SMASK_MIP_SERIAL
value|0x0002
name|u_long
name|un_mip_serial
decl_stmt|;
block|}
name|un_mip
struct|;
define|#
directive|define
name|MIP_SIZE
value|512
define|#
directive|define
name|MIP_BASE_SIZE
value|14
struct|struct
block|{
comment|/* MINOR SYNC ACK SPDU */
define|#
directive|define
name|SMASK_MIA_SERIAL
value|0x0001
name|u_long
name|un_mia_serial
decl_stmt|;
block|}
name|un_mia
struct|;
define|#
directive|define
name|MIA_SIZE
value|512
define|#
directive|define
name|MIA_BASE_SIZE
value|11
struct|struct
block|{
comment|/* MAJOR SYNC POINT SPDU */
define|#
directive|define
name|SMASK_MAP_SYNC
value|0x0001
name|u_char
name|un_map_sync
decl_stmt|;
define|#
directive|define
name|MAP_SYNC_NOEND
value|0x01
comment|/* ACTIVITY NOT ENDED (i.e., MAP not AE) */
define|#
directive|define
name|MAP_SYNC_MASK
value|MAP_SYNC_NOEND
define|#
directive|define
name|SMASK_MAP_SERIAL
value|0x0002
name|u_long
name|un_map_serial
decl_stmt|;
block|}
name|un_map
struct|;
define|#
directive|define
name|MAP_SIZE
value|512
define|#
directive|define
name|MAP_BASE_SIZE
value|14
struct|struct
block|{
comment|/* MAJOR SYNC ACK SPDU */
define|#
directive|define
name|SMASK_MAA_SERIAL
value|0x0001
name|u_long
name|un_maa_serial
decl_stmt|;
block|}
name|un_maa
struct|;
define|#
directive|define
name|MAA_SIZE
value|512
define|#
directive|define
name|MAA_BASE_SIZE
value|11
struct|struct
block|{
comment|/* RESYNCHRONIZE SPDU */
define|#
directive|define
name|SMASK_RS_SET
value|0x0001
name|u_char
name|un_rs_settings
decl_stmt|;
define|#
directive|define
name|SMASK_RS_TYPE
value|0x0002
name|u_char
name|un_rs_type
decl_stmt|;
define|#
directive|define
name|SYNC_OK
parameter_list|(
name|r
parameter_list|)
value|(((unsigned) (r))<= SYNC_SET)
define|#
directive|define
name|SMASK_RS_SSN
value|0x0004
name|u_long
name|un_rs_serial
decl_stmt|;
block|}
name|un_rs
struct|;
define|#
directive|define
name|RS_SIZE
value|512
define|#
directive|define
name|RS_BASE_SIZE
value|17
struct|struct
block|{
comment|/* RESYNCHRONIZE ACK SPDU */
define|#
directive|define
name|SMASK_RA_SET
value|0x0001
name|u_char
name|un_ra_settings
decl_stmt|;
define|#
directive|define
name|SMASK_RA_SSN
value|0x0002
name|u_long
name|un_ra_serial
decl_stmt|;
block|}
name|un_ra
struct|;
define|#
directive|define
name|RA_SIZE
value|512
define|#
directive|define
name|RA_BASE_SIZE
value|14
struct|struct
block|{
comment|/* PREPARE SPDU */
define|#
directive|define
name|SMASK_PR_TYPE
value|0x0001
name|u_char
name|un_pr_type
decl_stmt|;
define|#
directive|define
name|PR_MAA
value|1
comment|/* expect SPDU_MAA */
define|#
directive|define
name|PR_RS
value|2
comment|/* expect SPDU_RS */
define|#
directive|define
name|PR_RA
value|3
comment|/* expect SPDU_RA */
define|#
directive|define
name|PR_AB
value|4
comment|/* expect SPDU_AB */
define|#
directive|define
name|PR_MAX
value|PR_AB
block|}
name|un_pr
struct|;
define|#
directive|define
name|PR_SIZE
value|0
define|#
directive|define
name|PR_BASE_SIZE
value|3
comment|/* EXCEPTION REPORT SPDU */
define|#
directive|define
name|ER_SIZE
value|0
define|#
directive|define
name|ER_BASE_SIZE
value|0
struct|struct
block|{
comment|/* EXCEPTION DATA SPDU */
define|#
directive|define
name|SMASK_ED_REASON
value|0x0001
name|u_char
name|un_ed_reason
decl_stmt|;
define|#
directive|define
name|SP_OK
parameter_list|(
name|r
parameter_list|)
value|(((r)< SP_PROCEDURAL \&& (r) != SP_RSVD1 \&& (r) != SP_RSVD2) \ 			    || (r) == SP_DEMAND)
block|}
name|un_ed
struct|;
define|#
directive|define
name|ED_SIZE
value|512
define|#
directive|define
name|ED_BASE_SIZE
value|6
struct|struct
block|{
comment|/* ACTIVITY START SPDU */
define|#
directive|define
name|SMASK_AS_ID
value|0x0001
name|struct
name|SSAPactid
name|un_as_id
decl_stmt|;
block|}
name|un_as
struct|;
define|#
directive|define
name|AS_SIZE
value|512
define|#
directive|define
name|AS_BASE_SIZE
value|11
struct|struct
block|{
comment|/* ACTIVITY RESUME SPDU */
struct|struct
block|{
define|#
directive|define
name|SMASK_AR_REF
value|0x0001
name|struct
name|SSAPref
name|un_ar_reference
decl_stmt|;
define|#
directive|define
name|SMASK_AR_OID
value|0x0002
name|struct
name|SSAPactid
name|un_ar_oid
decl_stmt|;
define|#
directive|define
name|SMASK_AR_SSN
value|0x0004
name|u_long
name|un_ar_serial
decl_stmt|;
block|}
name|un_ar_link
struct|;
define|#
directive|define
name|SMASK_AR_ID
value|0x0008
name|struct
name|SSAPactid
name|un_ar_id
decl_stmt|;
block|}
name|un_ar
struct|;
define|#
directive|define
name|AR_SIZE
value|512
define|#
directive|define
name|AR_BASE_SIZE
value|29
struct|struct
block|{
comment|/* ACTIVITY INTERRUPT (ABORT) SPDU */
define|#
directive|define
name|SMASK_AI_REASON
value|0x0001
comment|/* don't collide with SMASK_AB_DISC */
name|u_char
name|un_ai_reason
decl_stmt|;
block|}
name|un_ai
struct|;
define|#
directive|define
name|AI_SIZE
value|0
define|#
directive|define
name|AI_BASE_SIZE
value|3
comment|/* ACTIVITY INTERRUPT (ABORT) ACK SPDU */
define|#
directive|define
name|AIA_SIZE
value|0
define|#
directive|define
name|AIA_BASE_SIZE
value|0
struct|struct
block|{
comment|/* ACTIVITY DISCARD SPDU */
define|#
directive|define
name|SMASK_AD_REASON
value|0x0001
name|u_char
name|un_ad_reason
decl_stmt|;
block|}
name|un_ad
struct|;
define|#
directive|define
name|AD_SIZE
value|0
define|#
directive|define
name|AD_BASE_SIZE
value|3
comment|/* ACTIVITY DISCARD ACK SPDU */
define|#
directive|define
name|ADA_SIZE
value|0
define|#
directive|define
name|ADA_BASE_SIZE
value|0
comment|/* ACTIVITY END (MAJOR SYNC) SPDU */
define|#
directive|define
name|AE_SIZE
value|512
define|#
directive|define
name|AE_BASE_SIZE
value|8
comment|/* ACTIVITY END (MAJOR SYNC) ACK SPDU */
define|#
directive|define
name|AEA_SIZE
value|MAA_SIZE
define|#
directive|define
name|AEA_BASE_SIZE
value|MAA_BASE_SIZE
block|}
name|s_un
union|;
define|#
directive|define
name|s_cn_reference
value|s_un.un_cn.un_cn_reference
define|#
directive|define
name|s_options
value|s_un.un_cn.un_cn_item.un_cn_options
define|#
directive|define
name|s_tsdu_init
value|s_un.un_cn.un_cn_item.un_cn_tsdu_init
define|#
directive|define
name|s_tsdu_resp
value|s_un.un_cn.un_cn_item.un_cn_tsdu_resp
define|#
directive|define
name|s_cn_version
value|s_un.un_cn.un_cn_item.un_cn_version
define|#
directive|define
name|s_isn
value|s_un.un_cn.un_cn_item.un_cn_isn
define|#
directive|define
name|s_settings
value|s_un.un_cn.un_cn_item.un_settings
define|#
directive|define
name|s_ac_token
value|s_un.un_cn.un_ac_token
define|#
directive|define
name|s_cn_require
value|s_un.un_cn.un_cn_requirements
define|#
directive|define
name|s_calling
value|s_un.un_cn.un_cn_calling
define|#
directive|define
name|s_callinglen
value|s_un.un_cn.un_cn_callinglen
define|#
directive|define
name|s_called
value|s_un.un_cn.un_cn_called
define|#
directive|define
name|s_calledlen
value|s_un.un_cn.un_cn_calledlen
define|#
directive|define
name|s_rf_reference
value|s_un.un_rf.un_rf_reference
define|#
directive|define
name|s_rf_disconnect
value|s_un.un_rf.un_rf_disconnect
define|#
directive|define
name|s_rf_require
value|s_un.un_rf.un_rf_requirements
define|#
directive|define
name|s_rf_version
value|s_un.un_rf.un_rf_version
define|#
directive|define
name|s_rdata
value|s_un.un_rf.un_rf_rdata
define|#
directive|define
name|s_rlen
value|s_un.un_rf.un_rf_rlen
define|#
directive|define
name|s_fn_disconnect
value|s_un.un_fn.un_fn_disconnect
define|#
directive|define
name|s_ab_disconnect
value|s_un.un_ab.un_ab_disconnect
define|#
directive|define
name|s_reflect
value|s_un.un_ab.un_ab_reflect
define|#
directive|define
name|s_gt_token
value|s_un.un_gt.un_gt_token
define|#
directive|define
name|s_pt_token
value|s_un.un_pt.un_pt_token
define|#
directive|define
name|s_mip_sync
value|s_un.un_mip.un_mip_sync
define|#
directive|define
name|s_mip_serial
value|s_un.un_mip.un_mip_serial
define|#
directive|define
name|s_mia_serial
value|s_un.un_mia.un_mia_serial
define|#
directive|define
name|s_map_sync
value|s_un.un_map.un_map_sync
define|#
directive|define
name|s_map_serial
value|s_un.un_map.un_map_serial
define|#
directive|define
name|s_maa_serial
value|s_un.un_maa.un_maa_serial
define|#
directive|define
name|s_rs_settings
value|s_un.un_rs.un_rs_settings
define|#
directive|define
name|s_rs_type
value|s_un.un_rs.un_rs_type
define|#
directive|define
name|s_rs_serial
value|s_un.un_rs.un_rs_serial
define|#
directive|define
name|s_ra_settings
value|s_un.un_ra.un_ra_settings
define|#
directive|define
name|s_ra_serial
value|s_un.un_ra.un_ra_serial
define|#
directive|define
name|s_pr_type
value|s_un.un_pr.un_pr_type
define|#
directive|define
name|s_ed_reason
value|s_un.un_ed.un_ed_reason
define|#
directive|define
name|s_as_id
value|s_un.un_as.un_as_id
define|#
directive|define
name|s_ar_reference
value|s_un.un_ar.un_ar_link.un_ar_reference
define|#
directive|define
name|s_ar_oid
value|s_un.un_ar.un_ar_link.un_ar_oid
define|#
directive|define
name|s_ar_serial
value|s_un.un_ar.un_ar_link.un_ar_serial
define|#
directive|define
name|s_ar_id
value|s_un.un_ar.un_ar_id
define|#
directive|define
name|s_ai_reason
value|s_un.un_ai.un_ai_reason
define|#
directive|define
name|s_ad_reason
value|s_un.un_ad.un_ad_reason
define|#
directive|define
name|SMASK_ENCLOSE
value|0x2000
name|u_char
name|s_enclose
decl_stmt|;
define|#
directive|define
name|ENCL_BEGIN
value|0x01
comment|/* beginning of SSDU */
define|#
directive|define
name|ENCL_END
value|0x02
comment|/* end of SSDU */
define|#
directive|define
name|ENCL_MASK
value|(ENCL_BEGIN | ENCL_END)
define|#
directive|define
name|ENCLOSE_MAX
value|65400
comment|/* maximum size of enclosure per segment 				   less slop; slop varies based on SPDU, but 				   we'll always assume the worst case */
define|#
directive|define
name|SEGMENT_MAX
value|65528
comment|/* for things other than S-DATA and 				   S-TYPED-DATA under version 2 we allow only 				   ONE enclosure */
define|#
directive|define
name|SMASK_UDATA_PGI
value|0x4000
name|char
modifier|*
name|s_udata
decl_stmt|;
comment|/* user data PGI */
name|int
name|s_ulen
decl_stmt|;
comment|/*   .. */
define|#
directive|define
name|SMASK_SPDU_EXPD
value|0x8000
comment|/* SPDU arrived on the expedited connection */
name|struct
name|qbuf
name|s_qbuf
decl_stmt|;
comment|/* user info */
name|int
name|s_qlen
decl_stmt|;
comment|/*   .. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLSPKT
value|((struct ssapkt *) 0)
end_define

begin_function_decl
name|int
name|freespkt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ssapkt
modifier|*
name|newspkt
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|text2spkt
argument_list|()
decl_stmt|,
name|spkt2text
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|spkt2tsdu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ssapkt
modifier|*
name|tsdu2spkt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|spkt2str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ssapkt
modifier|*
name|str2spkt
parameter_list|()
function_decl|;
end_function_decl

end_unit

