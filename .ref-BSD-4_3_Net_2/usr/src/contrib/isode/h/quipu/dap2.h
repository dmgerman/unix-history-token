begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dap.h - */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/quipu/RCS/dap2.h,v 7.2 91/02/22 09:25:42 mrose Interim $  *  *  * $Log:	dap2.h,v $  * Revision 7.2  91/02/22  09:25:42  mrose  * Interim 6.8  *   * Revision 7.1  90/10/17  11:46:22  mrose  * sync  *   * Revision 7.0  90/07/27  05:02:57  mrose  * *** empty log message ***  *   * Revision 7.0  89/11/23  21:56:29  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUDAP2
end_ifndef

begin_define
define|#
directive|define
name|QUIPUDAP2
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
name|_RoSAP_
end_ifndef

begin_include
include|#
directive|include
file|"rosap.h"
end_include

begin_comment
comment|/* definitions for ROSE-USERs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_RoNot_
end_ifndef

begin_include
include|#
directive|include
file|"ronot.h"
end_include

begin_comment
comment|/* definitions for RoBIND-USERs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"quipu/common.h"
end_include

begin_include
include|#
directive|include
file|"quipu/dsargument.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* An additional value for "asyn" parameters for interruptibility */
end_comment

begin_define
define|#
directive|define
name|ROS_INTR
value|-1
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|DAPconnect
block|{
name|int
name|dc_sd
decl_stmt|;
comment|/* association descriptor */
name|int
name|ds_pctx_id
decl_stmt|;
comment|/* Context identifier of directory access AS */
name|struct
name|AcSAPconnect
name|dc_connect
decl_stmt|;
comment|/* info from A-CONNECT.CONFIRMATION */
name|int
name|dc_result
decl_stmt|;
comment|/* result */
define|#
directive|define
name|DC_RESULT
value|1
define|#
directive|define
name|DC_ERROR
value|2
define|#
directive|define
name|DC_REJECT
value|3
union|union
block|{
name|struct
name|ds_bind_arg
name|dc_bind_res
decl_stmt|;
comment|/* DC_RESULT */
name|struct
name|ds_bind_error
name|dc_bind_err
decl_stmt|;
comment|/* DC_ERROR */
block|}
name|dc_un
union|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|DCFREE
end_ifndef

begin_define
define|#
directive|define
name|DCFREE
parameter_list|(
name|dc
parameter_list|)
value|{ \     ACCFREE (&((dc) -> dc_connect)); \     switch ((dc) -> dc_result) { \ 	case DC_RESULT: \ 	    bind_arg_free (&(dc) -> dc_un.dc_bind_res); \ 	    break; \ 	case DC_ERROR: \ 	    break; \ 	default: \ 	    break; \     } \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|DAPrelease
block|{
comment|/* DAP-UNBIND.CONFIRMATION */
name|int
name|dr_affirmative
decl_stmt|;
comment|/* T   = connection released 				   NIL = request refused */
name|int
name|dr_reason
decl_stmt|;
comment|/* reason for result */
comment|/* Takes values from acr_reason */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DAPabort
block|{
comment|/* DAP-ABORT.INDICATION */
name|int
name|da_source
decl_stmt|;
comment|/* abort source */
define|#
directive|define
name|DA_USER
value|0
comment|/*   DAP-user */
define|#
directive|define
name|DA_PROVIDER
value|1
comment|/*   DAP-provider */
define|#
directive|define
name|DA_LOCAL
value|2
comment|/*   DAP interface internal error */
name|int
name|da_reason
decl_stmt|;
comment|/* reason for failure */
define|#
directive|define
name|DA_NO_REASON
value|0
comment|/* Ain't no reason to some things */
define|#
directive|define
name|DA_RONOT
value|1
comment|/* Error from RONOT provider */
define|#
directive|define
name|DA_ROS
value|2
comment|/* Error from ROS provider called */
define|#
directive|define
name|DA_ARG_ENC
value|3
comment|/* Error encoding argument */
define|#
directive|define
name|DA_RES_ENC
value|4
comment|/* Error encoding result */
define|#
directive|define
name|DA_ERR_ENC
value|5
comment|/* Error encoding error */
define|#
directive|define
name|DA_ARG_DEC
value|6
comment|/* Error decoding argument */
define|#
directive|define
name|DA_RES_DEC
value|7
comment|/* Error decoding result */
define|#
directive|define
name|DA_ERR_DEC
value|8
comment|/* Error decoding error */
comment|/* diagnostics from provider */
define|#
directive|define
name|DA_SIZE
value|512
name|int
name|da_cc
decl_stmt|;
comment|/*   length */
name|char
name|da_data
index|[
name|DA_SIZE
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DAPresult
block|{
name|int
name|dr_id
decl_stmt|;
name|struct
name|DSResult
name|dr_res
decl_stmt|;
comment|/* Decoded result and op type */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|DRFREE
end_ifndef

begin_define
define|#
directive|define
name|DRFREE
parameter_list|(
name|dr
parameter_list|)
define|\
value|ds_res_free (&((dr)->dr_res))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|DAPerror
block|{
name|int
name|de_id
decl_stmt|;
name|struct
name|DSError
name|de_err
decl_stmt|;
comment|/* Decoded error and error type */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|DEFREE
end_ifndef

begin_define
define|#
directive|define
name|DEFREE
parameter_list|(
name|de
parameter_list|)
define|\
value|ds_error_free (&((de)->de_err))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|DAPpreject
block|{
name|int
name|dp_id
decl_stmt|;
comment|/* Operation id or -1 */
name|int
name|dp_source
decl_stmt|;
comment|/* same values as DAPabort.da_source */
name|int
name|dp_reason
decl_stmt|;
comment|/* reason for failure */
define|#
directive|define
name|DP_NO_REASON
value|0
comment|/* Ain't no reason to some things */
define|#
directive|define
name|DP_ROS
value|1
comment|/* ROSE error */
define|#
directive|define
name|DP_INVOKE
value|2
comment|/* Failure during invocation */
define|#
directive|define
name|DP_RESULT
value|3
comment|/* Failure during result */
define|#
directive|define
name|DP_ERROR
value|4
comment|/* Failure during error */
comment|/* diagnostics from provider */
define|#
directive|define
name|DP_SIZE
value|512
name|int
name|dp_cc
decl_stmt|;
comment|/*   length */
name|char
name|dp_data
index|[
name|DP_SIZE
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DAPindication
block|{
name|int
name|di_type
decl_stmt|;
define|#
directive|define
name|DI_RESULT
value|2
comment|/* DAP operation result received */
define|#
directive|define
name|DI_ERROR
value|3
comment|/* DAP operation error received */
define|#
directive|define
name|DI_PREJECT
value|4
comment|/* DAP operation rejected */
define|#
directive|define
name|DI_ABORT
value|6
comment|/* DAP association lost */
union|union
block|{
name|struct
name|DAPresult
name|di_un_result
decl_stmt|;
name|struct
name|DAPerror
name|di_un_error
decl_stmt|;
name|struct
name|DAPpreject
name|di_un_preject
decl_stmt|;
name|struct
name|DAPabort
name|di_un_abort
decl_stmt|;
block|}
name|di_un
union|;
define|#
directive|define
name|di_result
value|di_un.di_un_result
define|#
directive|define
name|di_error
value|di_un.di_un_error
define|#
directive|define
name|di_preject
value|di_un.di_un_preject
define|#
directive|define
name|di_abort
value|di_un.di_un_abort
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
name|copyDAPdata
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
name|copyDAPdata
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
name|copyDAPdata
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

begin_comment
comment|/*
comment|*/
end_comment

begin_function_decl
name|int
name|DapAsynBindReqAux
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* DAP-BIND.REQUEST (ARGUMENT) */
end_comment

begin_function_decl
name|int
name|DapAsynBindRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* DAP-BIND.REQUEST (ARGUMENT) */
end_comment

begin_function_decl
name|int
name|DapAsynBindRetry
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* DAP-BIND-RETRY.REQUEST */
end_comment

begin_function_decl
name|int
name|DapUnBindRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* DAP-UNBIND.REQUEST */
end_comment

begin_function_decl
name|int
name|DapUnBindRetry
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* DAP-BIND-RETRY.REQUEST (pseudo) */
end_comment

begin_function_decl
name|char
modifier|*
name|DapErrString
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return DAP error code in string form */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

