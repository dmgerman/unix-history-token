begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dsap.h - include file for directory service users (DS-USER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/quipu/RCS/dsap.h,v 7.3 91/02/22 09:25:47 mrose Interim $  *  *  * $Log:	dsap.h,v $  * Revision 7.3  91/02/22  09:25:47  mrose  * Interim 6.8  *   * Revision 7.2  90/11/20  15:30:37  mrose  * cjr  *   * Revision 7.1  90/10/17  11:46:25  mrose  * sync  *   * Revision 7.0  90/07/27  05:02:55  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DSAP_
end_ifndef

begin_define
define|#
directive|define
name|_DSAP_
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

begin_comment
comment|/* Values used to convey response type throughout DSAP library */
end_comment

begin_define
define|#
directive|define
name|DS_RESULT
value|1
end_define

begin_define
define|#
directive|define
name|DS_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|DS_REJECT
value|3
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|DSAPstart
block|{
comment|/* D-BIND.INDICATION */
name|int
name|ds_sd
decl_stmt|;
comment|/* association descriptor */
name|int
name|ds_ctx
decl_stmt|;
comment|/* Directory protocol type */
define|#
directive|define
name|DS_CTX_X500_DAP
value|1
define|#
directive|define
name|DS_CTX_X500_DSP
value|2
define|#
directive|define
name|DS_CTX_QUIPU_DSP
value|3
comment|/* Quipu has its own DSP context */
name|int
name|ds_pctx_id
decl_stmt|;
comment|/* Context identifier of directory AS */
name|struct
name|AcSAPstart
name|ds_start
decl_stmt|;
comment|/* info from A-CONNECT.INDICATION */
name|struct
name|ds_bind_arg
name|ds_bind_arg
decl_stmt|;
comment|/* Decoded bind argument */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DSFREE
parameter_list|(
name|ds
parameter_list|)
value|{ \     ACSFREE (&(ds) -> ds_start); \     bind_arg_free (&(ds) -> ds_bind_arg); \ }
end_define

begin_struct
struct|struct
name|DSAPconnect
block|{
name|int
name|dc_sd
decl_stmt|;
comment|/* association descriptor */
name|int
name|dc_ctx
decl_stmt|;
comment|/* Directory protocol type */
name|int
name|ds_pctx_id
decl_stmt|;
comment|/* Context identifier of directory AS */
name|struct
name|AcSAPconnect
name|dc_connect
decl_stmt|;
comment|/* info from A-CONNECT.CONFIRMATION */
name|int
name|dc_result
decl_stmt|;
comment|/* result */
comment|/* Uses general DS response type definitiions */
union|union
block|{
name|struct
name|ds_bind_arg
name|dc_bind_res
decl_stmt|;
name|struct
name|ds_bind_error
name|dc_bind_err
decl_stmt|;
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
value|{ \     ACCFREE (&(dc) -> dc_connect); \     switch ((dc) -> dc_result) { \ 	case DS_RESULT: \ 	    bind_arg_free (&(dc) -> dc_un.dc_bind_res); \ 	    break; \ 	case DS_ERROR: \ 	    break; \ 	default: \ 	    break; \     } \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|DSAPrelease
block|{
comment|/* D-UNBIND.CONFIRMATION */
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
name|DSAPabort
block|{
comment|/* D-ABORT.INDICATION */
name|int
name|da_source
decl_stmt|;
comment|/* abort source */
define|#
directive|define
name|DA_USER
value|0
comment|/*   directory-user */
define|#
directive|define
name|DA_PROVIDER
value|1
comment|/*   directory-provider */
define|#
directive|define
name|DA_LOCAL
value|2
comment|/*   local DPM */
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
name|DA_RO_BIND
value|1
comment|/* Error from RO BIND routine called */
define|#
directive|define
name|DA_ROS
value|2
comment|/* Error from ROS routine called */
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
define|#
directive|define
name|DA_APP_CONTEXT
value|9
comment|/* Unexpected application context */
define|#
directive|define
name|DA_PCDL
value|10
comment|/* Unacceptable presentation context list */
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
name|DSAPinvoke
block|{
name|int
name|dx_id
decl_stmt|;
comment|/* Operation identifier */
name|struct
name|ds_op_arg
name|dx_arg
decl_stmt|;
comment|/* Decoded argument */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DXFREE
parameter_list|(
name|dx
parameter_list|)
define|\
value|op_arg_free (&((dx)->dx_arg))
end_define

begin_struct
struct|struct
name|DSAPresult
block|{
name|int
name|dr_id
decl_stmt|;
name|struct
name|ds_op_res
name|dr_res
decl_stmt|;
comment|/* Decoded argument */
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
value|op_res_free (&((dr)->dr_res))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|DSAPerror
block|{
name|int
name|de_id
decl_stmt|;
name|struct
name|DSError
name|de_err
decl_stmt|;
comment|/* Decoded error */
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
value|op_res_free (&((de)->de_err))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|DSAPpreject
block|{
name|int
name|dp_id
decl_stmt|;
comment|/* Operation id or -1 */
name|int
name|dp_source
decl_stmt|;
comment|/* same values as DSAPabort.da_source */
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
name|DSAPfinish
block|{
name|int
name|df_reason
decl_stmt|;
comment|/* Reason for unbinding */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DFFREE
parameter_list|(
name|df
parameter_list|)
end_define

begin_struct
struct|struct
name|DSAPindication
block|{
name|int
name|di_type
decl_stmt|;
define|#
directive|define
name|DI_INVOKE
value|1
comment|/* DAP operation invocation received */
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
name|DI_FINISH
value|5
comment|/* DAP UnBind received */
define|#
directive|define
name|DI_ABORT
value|6
comment|/* DAP association lost */
union|union
block|{
name|struct
name|DSAPinvoke
name|di_un_invoke
decl_stmt|;
name|struct
name|DSAPerror
name|di_un_error
decl_stmt|;
comment|/* This is used at the same time as the error struct in searches 	struct DSAPresult	di_un_result; */
name|struct
name|DSAPpreject
name|di_un_preject
decl_stmt|;
name|struct
name|DSAPfinish
name|di_un_finish
decl_stmt|;
name|struct
name|DSAPabort
name|di_un_abort
decl_stmt|;
block|}
name|di_un
union|;
name|struct
name|DSAPresult
name|di_result
decl_stmt|;
define|#
directive|define
name|di_invoke
value|di_un.di_un_invoke
comment|/* #define di_result di_un.di_un_result */
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
name|di_finish
value|di_un.di_un_finish
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
name|copyDSAPdata
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
name|copyDSAPdata
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
name|copyDSAPdata
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dsapversion
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|DBindInit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* D-BIND.INDICATION */
end_comment

begin_function_decl
name|int
name|DAsynBindRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* D-BIND.REQUEST (ARGUMENT) */
end_comment

begin_function_decl
name|int
name|DAsynBindRetry
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* D-BIND-RETRY.REQUEST */
end_comment

begin_function_decl
name|int
name|DBindResult
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* D-BIND.RESPONSE (RESULT) */
end_comment

begin_function_decl
name|int
name|DBindError
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* D-BIND.RESPONSE (ERROR) */
end_comment

begin_function_decl
name|int
name|DBindReject
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* D-BIND.RESPONSE (REJECT) */
end_comment

begin_function_decl
name|int
name|DUnBindRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* D-UNBIND.REQUEST */
end_comment

begin_function_decl
name|int
name|DUnBindRetry
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* D-BIND-RETRY.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|DUnBindResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* D-BIND.RESPONSE (RESULT) */
end_comment

begin_function_decl
name|int
name|DUnBindReject
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* D-BIND.RESPONSE (REJECT) */
end_comment

begin_function_decl
name|char
modifier|*
name|DErrString
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return DSAP error code in string form */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

