begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ronote.h - Additions to properly support ABSTRACT-BIND */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/ronot.h,v 7.1 91/02/22 09:24:58 mrose Interim $  *  *  * $Log:	ronot.h,v $  * Revision 7.1  91/02/22  09:24:58  mrose  * Interim 6.8  *   * Revision 7.0  90/07/26  14:26:02  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RoNot_
end_ifndef

begin_define
define|#
directive|define
name|_RoNot_
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

begin_define
define|#
directive|define
name|BIND_RESULT
value|1
end_define

begin_comment
comment|/* indicates a bind result occured */
end_comment

begin_define
define|#
directive|define
name|BIND_ERROR
value|2
end_define

begin_comment
comment|/* indicates a bind error occured */
end_comment

begin_struct
struct|struct
name|RoNOTindication
block|{
name|int
name|rni_reason
decl_stmt|;
comment|/* reason for failure */
define|#
directive|define
name|RBI_ACSE
value|1
comment|/* ACSE provider failed */
define|#
directive|define
name|RBI_SET_ROSE_PRES
value|2
comment|/* Failed to set ROS-USER */
define|#
directive|define
name|RBI_ENC_BIND_ARG
value|3
comment|/* Failed encoding bind argument */
define|#
directive|define
name|RBI_ENC_BIND_RES
value|4
comment|/* Failed encoding bind result */
define|#
directive|define
name|RBI_ENC_BIND_ERR
value|5
comment|/* Failed encoding bind error */
define|#
directive|define
name|RBI_ENC_UNBIND_ARG
value|6
comment|/* Failed encoding unbind argument */
define|#
directive|define
name|RBI_ENC_UNBIND_RES
value|7
comment|/* Failed encoding unbind result */
define|#
directive|define
name|RBI_ENC_UNBIND_ERR
value|8
comment|/* Failed encoding unbind error */
define|#
directive|define
name|RBI_DEC_BIND_ARG
value|9
comment|/* Failed decoding bind argument */
define|#
directive|define
name|RBI_DEC_BIND_RES
value|10
comment|/* Failed decoding bind result */
define|#
directive|define
name|RBI_DEC_BIND_ERR
value|11
comment|/* Failed decoding bind error */
define|#
directive|define
name|RBI_DEC_UNBIND_ARG
value|12
comment|/* Failed decoding unbind argument */
define|#
directive|define
name|RBI_DEC_UNBIND_RES
value|13
comment|/* Failed decoding unbind result */
define|#
directive|define
name|RBI_DEC_UNBIND_ERR
value|14
comment|/* Failed decoding unbind error */
define|#
directive|define
name|RBI_DEC_NINFO
value|15
comment|/* Erroneous number of user infos */
comment|/* diagnostics from provider */
define|#
directive|define
name|RB_SIZE
value|512
name|int
name|rni_cc
decl_stmt|;
comment|/*   length */
name|char
name|rni_data
index|[
name|RB_SIZE
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

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
name|copyRoNOTdata
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
name|copyRoNOTdata
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
name|copyRoNOTdata
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

