begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ropkt.h - include file for remote operation providers (RoS-PROVIDER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/ropkt.h,v 7.2 91/02/22 09:24:59 mrose Interim $  *  * Based on an TCP-based implementation by George Michaelson of University  * College London.  *  *  * $Log:	ropkt.h,v $  * Revision 7.2  91/02/22  09:24:59  mrose  * Interim 6.8  *   * Revision 7.1  90/07/01  21:03:53  mrose  * pepsy  *   * Revision 7.0  89/11/23  21:55:55  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RoSAP_
end_ifndef

begin_include
include|#
directive|include
file|"rosap.h"
end_include

begin_comment
comment|/* definitions for RoS-USERs */
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
name|rosapPsig
parameter_list|(
name|acb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((acb = findacblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_PARAMETER, NULLCP, \ 			    "invalid association descriptor"); \     } \     if (!(acb -> acb_flags& ACB_CONN)) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_OPERATION, NULLCP, \ 			    "association descriptor not connected"); \     } \     if (acb -> acb_flags& ACB_CLOSING) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_WAITING, NULLCP, NULLCP); \     } \     if (acb -> acb_flags& ACB_FINN) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_OPERATION, NULLCP, \ 			    "association descriptor finishing"); \     } \     if (acb -> acb_putosdu == NULLIFP) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_OPERATION, NULLCP, \ 			    "association descriptor not bound"); \     } \ }
end_define

begin_define
define|#
directive|define
name|rosapXsig
parameter_list|(
name|acb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((acb = findacblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_PARAMETER, NULLCP, \ 			    "invalid association descriptor"); \     } \     if (!(acb -> acb_flags& ACB_CONN)) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_OPERATION, NULLCP, \ 			    "association descriptor not connected"); \     } \     if (acb -> acb_flags& ACB_FINN) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_OPERATION, NULLCP, \ 			    "association descriptor finishing"); \     } \     if (acb -> acb_putosdu == NULLIFP) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_OPERATION, NULLCP, \ 			    "association descriptor not bound"); \     } \ }
end_define

begin_define
define|#
directive|define
name|rosapFsig
parameter_list|(
name|acb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((acb = findacblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_PARAMETER, NULLCP, \ 			    "invalid association descriptor"); \     } \     if (!(acb -> acb_flags& ACB_ROS)) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_OPERATION, NULLCP, \ 			    "not an association descriptor for ROS"); \     } \     if (!(acb -> acb_flags& ACB_CONN)) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_OPERATION, NULLCP, \ 			    "association descriptor not connected"); \     } \     if (!(acb -> acb_flags& ACB_FINN)) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_OPERATION, NULLCP, \ 			    "association descriptor not finishing"); \     } \     if (acb -> acb_putosdu == NULLIFP) { \ 	(void) sigiomask (smask); \ 	return rosaplose (roi, ROS_OPERATION, NULLCP, \ 			    "association descriptor not bound"); \     } \ }
end_define

begin_define
define|#
directive|define
name|missingP
parameter_list|(
name|p
parameter_list|)
define|\
value|{ \     if (p == NULL) \ 	return rosaplose (roi, ROS_PARAMETER, NULLCP, \ 			    "mandatory parameter \"%s\" missing", "p"); \ }
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
name|copyRoSAPdata
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
name|copyRoSAPdata
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
name|copyRoSAPdata
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
value|ropktlose (acb, roi, ROS_PROTOCOL, NULLCP, "%s", PY_pepy)
end_define

begin_decl_stmt
name|int
name|ropktlose
argument_list|()
decl_stmt|,
name|rosapreject
argument_list|()
decl_stmt|,
name|rosaplose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_function_decl
name|int
name|acb2osdu
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|ro2rtswrite
argument_list|()
decl_stmt|,
name|ro2rtswait
argument_list|()
decl_stmt|,
name|ro2rtsready
argument_list|()
decl_stmt|,
name|ro2rtsasync
argument_list|()
decl_stmt|,
name|ro2rtsmask
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ro2pswrite
argument_list|()
decl_stmt|,
name|ro2pswait
argument_list|()
decl_stmt|,
name|ro2psasync
argument_list|()
decl_stmt|,
name|ro2psmask
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ss2roslose
argument_list|()
decl_stmt|,
name|ss2rosabort
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ro2sswrite
argument_list|()
decl_stmt|,
name|ro2sswait
argument_list|()
decl_stmt|,
name|ro2ssasync
argument_list|()
decl_stmt|,
name|ro2ssmask
argument_list|()
decl_stmt|,
name|ro2sslose
argument_list|()
decl_stmt|,
name|ro2ssready
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* APDU types */
end_comment

begin_define
define|#
directive|define
name|APDU_INVOKE
value|1
end_define

begin_comment
comment|/* Invoke */
end_comment

begin_define
define|#
directive|define
name|APDU_RESULT
value|2
end_define

begin_comment
comment|/* Return result */
end_comment

begin_define
define|#
directive|define
name|APDU_ERROR
value|3
end_define

begin_comment
comment|/* Return error */
end_comment

begin_define
define|#
directive|define
name|APDU_REJECT
value|4
end_define

begin_comment
comment|/* Reject */
end_comment

begin_define
define|#
directive|define
name|APDU_UNKNOWN
value|(-1)
end_define

begin_comment
comment|/* anything other than the above */
end_comment

begin_comment
comment|/* Reject APDU types */
end_comment

begin_define
define|#
directive|define
name|REJECT_GENERAL
value|0
end_define

begin_comment
comment|/* General Problem */
end_comment

begin_define
define|#
directive|define
name|REJECT_GENERAL_BASE
value|ROS_GP_UNRECOG
end_define

begin_define
define|#
directive|define
name|REJECT_INVOKE
value|1
end_define

begin_comment
comment|/* Invoke Problem */
end_comment

begin_define
define|#
directive|define
name|REJECT_INVOKE_BASE
value|ROS_IP_DUP
end_define

begin_define
define|#
directive|define
name|REJECT_RESULT
value|2
end_define

begin_comment
comment|/* Return Result Problem */
end_comment

begin_define
define|#
directive|define
name|REJECT_RESULT_BASE
value|ROS_RRP_UNRECOG
end_define

begin_define
define|#
directive|define
name|REJECT_ERROR
value|3
end_define

begin_comment
comment|/* Return Error Problem */
end_comment

begin_define
define|#
directive|define
name|REJECT_ERROR_BASE
value|ROS_REP_UNRECOG
end_define

begin_define
define|#
directive|define
name|REJECT_COMPLETE
value|4
end_define

begin_comment
comment|/* more Invoke Problem codes */
end_comment

end_unit

