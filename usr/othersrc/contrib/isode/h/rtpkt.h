begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rtpkt.h - include file for reliable transfer providers (RtS-PROVIDER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/rtpkt.h,v 7.1 91/02/22 09:25:03 mrose Interim $  *  *  * $Log:	rtpkt.h,v $  * Revision 7.1  91/02/22  09:25:03  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:55:58  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RtSAP_
end_ifndef

begin_include
include|#
directive|include
file|"rtsap.h"
end_include

begin_comment
comment|/* definitions for RtS-USERs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"acpkt.h"
end_include

begin_comment
comment|/* definitions for AcS-PROVIDERs */
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

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|rtsapPsig
parameter_list|(
name|acb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((acb = findacblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return rtsaplose (rti, RTS_PARAMETER, NULLCP, \ 			    "invalid association descriptor"); \     } \     if (!(acb -> acb_flags& ACB_RTS)) { \ 	(void) sigiomask (smask); \ 	return rtsaplose (rti, RTS_OPERATION, NULLCP, \ 			    "not an association descriptor for RTS"); \     } \     if (!(acb -> acb_flags& ACB_CONN)) { \ 	(void) sigiomask (smask); \ 	return rtsaplose (rti, RTS_OPERATION, NULLCP, \ 			    "association descriptor not connected"); \     } \     if (acb -> acb_flags& ACB_FINN) { \ 	(void) sigiomask (smask); \ 	return rtsaplose (rti, RTS_OPERATION, NULLCP, \ 			    "association descriptor finishing"); \     } \ }
end_define

begin_define
define|#
directive|define
name|rtsapFsig
parameter_list|(
name|acb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((acb = findacblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return rtsaplose (rti, RTS_PARAMETER, NULLCP, \ 			    "invalid association descriptor"); \     } \     if (!(acb -> acb_flags& ACB_RTS)) { \ 	(void) sigiomask (smask); \ 	return rtsaplose (rti, RTS_OPERATION, NULLCP, \ 			    "not an association descriptor for RTS"); \     } \     if (!(acb -> acb_flags& ACB_CONN)) { \ 	(void) sigiomask (smask); \ 	return rtsaplose (rti, RTS_OPERATION, NULLCP, \ 			    "association descriptor not connected"); \     } \     if (!(acb -> acb_flags& ACB_FINN)) { \ 	(void) sigiomask (smask); \ 	return rtsaplose (rti, RTS_OPERATION, NULLCP, \ 			    "association descriptor not finishing"); \     } \ }
end_define

begin_define
define|#
directive|define
name|missingP
parameter_list|(
name|p
parameter_list|)
define|\
value|{ \     if (p == NULL) \ 	return rtsaplose (rti, RTS_PARAMETER, NULLCP, \ 			    "mandatory parameter \"%s\" missing", "p"); \ }
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
name|copyRtSAPdata
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
name|copyRtSAPdata
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
name|copyRtSAPdata
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
parameter_list|()
define|\
value|rtpktlose (acb, rti, RTS_PROTOCOL, NULLCP, "%s", PY_pepy)
end_define

begin_comment
comment|/* would really prefer to determine DEFAULT_CKPOINT dynamically, but can't    since need to know it *before* doing the A-ASSOCIATE.REQUEST or    S-CONNECT.REQUEST... */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_CKPOINT
value|(65518>> 10)
end_define

begin_define
define|#
directive|define
name|DEFAULT_WINDOW
value|PCONN_WD_DFLT
end_define

begin_define
define|#
directive|define
name|RTS_MYREQUIRE
value|(SR_EXCEPTIONS | SR_ACTIVITY | SR_HALFDUPLEX \ 			    | SR_MINORSYNC)
end_define

begin_define
define|#
directive|define
name|RT_ASN
value|"rtse pci version 1"
end_define

begin_decl_stmt
name|int
name|rtpktlose
argument_list|()
decl_stmt|,
name|rtsaplose
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
name|SetPS2RtService
parameter_list|(
name|acb
parameter_list|)
define|\
value|{ \     (acb) -> acb_pturnrequest = rt2pspturn; \     (acb) -> acb_gturnrequest = rt2psgturn; \     (acb) -> acb_transferequest = rt2pstrans; \     (acb) -> acb_rtwaitrequest = rt2pswait; \     (acb) -> acb_rtsetindications = rt2psasync; \     (acb) -> acb_rtselectmask = rt2psmask; \     (acb) -> acb_rtpktlose = rt2pslose; \ }
end_define

begin_decl_stmt
name|int
name|acs2rtslose
argument_list|()
decl_stmt|,
name|acs2rtsabort
argument_list|()
decl_stmt|,
name|ps2rtslose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rt2pspturn
argument_list|()
decl_stmt|,
name|rt2psgturn
argument_list|()
decl_stmt|,
name|rt2pstrans
argument_list|()
decl_stmt|,
name|rt2pswait
argument_list|()
decl_stmt|,
name|rt2psasync
argument_list|()
decl_stmt|,
name|rt2psmask
argument_list|()
decl_stmt|,
name|rt2pslose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SetSS2RtService
parameter_list|(
name|acb
parameter_list|)
define|\
value|{ \     (acb) -> acb_pturnrequest = rt2sspturn; \     (acb) -> acb_gturnrequest = rt2ssgturn; \     (acb) -> acb_transferequest = rt2sstrans; \     (acb) -> acb_rtwaitrequest = rt2sswait; \     (acb) -> acb_rtsetindications = rt2ssasync; \     (acb) -> acb_rtselectmask = rt2ssmask; \     (acb) -> acb_rtpktlose = rt2sslose; \ }
end_define

begin_decl_stmt
name|int
name|ss2rtslose
argument_list|()
decl_stmt|,
name|ss2rtsabort
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rt2sspturn
argument_list|()
decl_stmt|,
name|rt2ssgturn
argument_list|()
decl_stmt|,
name|rt2sstrans
argument_list|()
decl_stmt|,
name|rt2sswait
argument_list|()
decl_stmt|,
name|rt2ssasync
argument_list|()
decl_stmt|,
name|rt2ssmask
argument_list|()
decl_stmt|,
name|rt2sslose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* RTORQ apdu */
end_comment

begin_define
define|#
directive|define
name|RTORQ_CKPOINT
value|0
end_define

begin_comment
comment|/* checkpointSize tag */
end_comment

begin_define
define|#
directive|define
name|RTORQ_CK_DFLT
value|0
end_define

begin_comment
comment|/*   default */
end_comment

begin_define
define|#
directive|define
name|RTORQ_WINDOW
value|1
end_define

begin_comment
comment|/* windowSize tag */
end_comment

begin_define
define|#
directive|define
name|RTORQ_WD_DFLT
value|3
end_define

begin_comment
comment|/*   default */
end_comment

begin_define
define|#
directive|define
name|RTORQ_DIALOGUE
value|2
end_define

begin_comment
comment|/* dialogueMode tag */
end_comment

begin_define
define|#
directive|define
name|RTORQ_DM_MONO
value|0
end_define

begin_comment
comment|/*   monologue */
end_comment

begin_define
define|#
directive|define
name|RTORQ_DM_TWA
value|1
end_define

begin_comment
comment|/*   two-way alternate */
end_comment

begin_define
define|#
directive|define
name|RTORQ_DM_DFLT
value|RTORQ_DM_MONO
end_define

begin_define
define|#
directive|define
name|RTORQ_CONNDATA
value|3
end_define

begin_comment
comment|/* connectionDataRQ tag */
end_comment

begin_define
define|#
directive|define
name|RTORQ_CD_OPEN
value|0
end_define

begin_comment
comment|/*   open tag */
end_comment

begin_define
define|#
directive|define
name|RTORQ_CD_RCVR
value|1
end_define

begin_comment
comment|/*   recover tag */
end_comment

begin_comment
comment|/* RTOAC apdu */
end_comment

begin_define
define|#
directive|define
name|RTOAC_CKPOINT
value|0
end_define

begin_comment
comment|/* checkpointSize tag */
end_comment

begin_define
define|#
directive|define
name|RTOAC_CK_DFLT
value|0
end_define

begin_comment
comment|/*   default */
end_comment

begin_define
define|#
directive|define
name|RTOAC_WINDOW
value|1
end_define

begin_comment
comment|/* windowSize tag */
end_comment

begin_define
define|#
directive|define
name|RTOAC_WD_DFLT
value|3
end_define

begin_comment
comment|/*   default */
end_comment

begin_define
define|#
directive|define
name|RTOAC_CONNDATA
value|2
end_define

begin_comment
comment|/* connectionDataAC */
end_comment

begin_define
define|#
directive|define
name|RTOAC_CD_OPEN
value|0
end_define

begin_comment
comment|/*   open tag */
end_comment

begin_define
define|#
directive|define
name|RTOAC_CD_RCVR
value|1
end_define

begin_comment
comment|/*   recover tag */
end_comment

begin_comment
comment|/* RTORJ apdu */
end_comment

begin_define
define|#
directive|define
name|RTORJ_REFUSE
value|0
end_define

begin_comment
comment|/* refuseReason tag */
end_comment

begin_define
define|#
directive|define
name|RTORJ_USERDATA
value|1
end_define

begin_comment
comment|/* userDataRJ */
end_comment

begin_comment
comment|/* RTAB apdu */
end_comment

begin_define
define|#
directive|define
name|RTAB_REASON
value|0
end_define

begin_comment
comment|/* abortReason tag */
end_comment

begin_define
define|#
directive|define
name|RTAB_REFLECT
value|1
end_define

begin_comment
comment|/* relectedParameter tag */
end_comment

begin_define
define|#
directive|define
name|RTAB_USERDATA
value|2
end_define

begin_comment
comment|/* userDataAB */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rtsap_priority
decl_stmt|;
end_decl_stmt

end_unit

