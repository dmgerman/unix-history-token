begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rosy.h - include file for ROSY users */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/rosy.h,v 7.3 91/02/22 09:25:01 mrose Interim $  *  *  * $Log:	rosy.h,v $  * Revision 7.3  91/02/22  09:25:01  mrose  * Interim 6.8  *   * Revision 7.2  90/11/20  15:33:31  mrose  * update  *   * Revision 7.1  90/07/01  21:03:55  mrose  * pepsy  *   * Revision 7.0  89/11/23  21:55:57  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ROSY_
end_ifndef

begin_define
define|#
directive|define
name|_ROSY_
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
comment|/* definitions for RoS-USERs */
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
name|PEPSY_VERSION
end_ifdef

begin_include
include|#
directive|include
file|"pepsy.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PEPSY_DEFINITIONS
end_ifdef

begin_comment
comment|/* This is really to change the name of the function RyOperation but the macro  * is unselective so we have to change the name of the structure as well, which  * shouldn't cause any problems  */
end_comment

begin_define
define|#
directive|define
name|RyOperation
value|PRyOperation
end_define

begin_endif
endif|#
directive|endif
endif|PEPSY_DEFINITIONS
end_endif

begin_struct
struct|struct
name|RyOperation
block|{
name|char
modifier|*
name|ryo_name
decl_stmt|;
comment|/* operation name */
name|int
name|ryo_op
decl_stmt|;
comment|/* operation code */
ifdef|#
directive|ifdef
name|PEPSY_DEFINITIONS
name|modtyp
modifier|*
name|ryo_arg_mod
decl_stmt|;
comment|/* pointer to table for arguement type */
name|int
name|ryo_arg_index
decl_stmt|;
comment|/* index to entry in tables */
else|#
directive|else
name|IFP
name|ryo_arg_encode
decl_stmt|;
comment|/* encodes argument */
name|IFP
name|ryo_arg_decode
decl_stmt|;
comment|/* decodes   .. */
name|IFP
name|ryo_arg_free
decl_stmt|;
comment|/* frees     .. */
endif|#
directive|endif
name|int
name|ryo_result
decl_stmt|;
comment|/* result possible */
ifdef|#
directive|ifdef
name|PEPSY_DEFINITIONS
name|modtyp
modifier|*
name|ryo_res_mod
decl_stmt|;
comment|/* pointer to table for result type */
name|int
name|ryo_res_index
decl_stmt|;
comment|/* index to entry in tables */
else|#
directive|else
name|IFP
name|ryo_res_encode
decl_stmt|;
comment|/* encodes result */
name|IFP
name|ryo_res_decode
decl_stmt|;
comment|/* decodes   .. */
name|IFP
name|ryo_res_free
decl_stmt|;
comment|/* frees     .. */
endif|#
directive|endif
name|struct
name|RyError
modifier|*
modifier|*
name|ryo_errors
decl_stmt|;
comment|/* errors possible */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|RyError
block|{
name|char
modifier|*
name|rye_name
decl_stmt|;
comment|/* error name */
name|int
name|rye_err
decl_stmt|;
comment|/* error code */
ifdef|#
directive|ifdef
name|PEPSY_DEFINITIONS
name|modtyp
modifier|*
name|rye_param_mod
decl_stmt|;
comment|/* pointer to table for result type */
name|int
name|rye_param_index
decl_stmt|;
comment|/* index to entry in tables */
else|#
directive|else
name|IFP
name|rye_param_encode
decl_stmt|;
comment|/* encodes parameter */
name|IFP
name|rye_param_decode
decl_stmt|;
comment|/* decodes   .. */
name|IFP
name|rye_param_free
decl_stmt|;
comment|/* frees     .. */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|opsblk
block|{
name|struct
name|opsblk
modifier|*
name|opb_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|opsblk
modifier|*
name|opb_back
decl_stmt|;
comment|/*   .. */
name|short
name|opb_flags
decl_stmt|;
comment|/* our state */
define|#
directive|define
name|OPB_NULL
value|0x0000
define|#
directive|define
name|OPB_EVENT
value|0x0001
comment|/* event present */
define|#
directive|define
name|OPB_INITIATOR
value|0x0002
comment|/* initiator block */
define|#
directive|define
name|OPB_RESPONDER
value|0x0004
comment|/* responder block */
name|int
name|opb_fd
decl_stmt|;
comment|/* association descriptor */
name|int
name|opb_id
decl_stmt|;
comment|/* invoke ID */
name|IFP
name|opb_resfnx
decl_stmt|;
comment|/* result vector */
name|IFP
name|opb_errfnx
decl_stmt|;
comment|/* error vector */
name|struct
name|RyOperation
modifier|*
name|opb_ryo
decl_stmt|;
comment|/* entry in operation table */
name|struct
name|RoSAPindication
name|opb_event
decl_stmt|;
comment|/* resulting event */
name|caddr_t
name|opb_out
decl_stmt|;
comment|/* event parameter */
ifdef|#
directive|ifdef
name|PEPSY_DEFINITIONS
name|modtyp
modifier|*
name|opb_free_mod
decl_stmt|;
comment|/* pointer to table for result type */
name|int
name|opb_free_index
decl_stmt|;
comment|/* index to entry in tables */
else|#
directive|else
name|IFP
name|opb_free
decl_stmt|;
comment|/* free routine for event parameter */
endif|#
directive|endif
name|PE
name|opb_pe
decl_stmt|;
comment|/* for Simon */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLOPB
value|((struct opsblk *) 0)
end_define

begin_struct
struct|struct
name|dspblk
block|{
name|struct
name|dspblk
modifier|*
name|dsb_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|dspblk
modifier|*
name|dsb_back
decl_stmt|;
comment|/*   .. */
name|int
name|dsb_fd
decl_stmt|;
comment|/* association descriptor */
comment|/* NOTOK-valued is wildcard for RyWait */
name|struct
name|RyOperation
modifier|*
name|dsb_ryo
decl_stmt|;
comment|/* entry in operation table */
name|IFP
name|dsb_vector
decl_stmt|;
comment|/* dispatch vector */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLDSB
value|((struct dspblk *) 0)
end_define

begin_define
define|#
directive|define
name|RY_RESULT
value|(-1)
end_define

begin_comment
comment|/* distinguishes RESULTs from ERRORs */
end_comment

begin_define
define|#
directive|define
name|RY_REJECT
value|(-2)
end_define

begin_comment
comment|/* distinguishes REJECTs from ERRORs */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* Change the names to use the pepsy based rosy library */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PEPSY_DEFINITIONS
end_ifdef

begin_define
define|#
directive|define
name|RyDiscard
value|PRyDiscard
end_define

begin_define
define|#
directive|define
name|RyDispatch
value|PRyDispatch
end_define

begin_define
define|#
directive|define
name|RyDsError
value|PRyDsError
end_define

begin_define
define|#
directive|define
name|RyDsResult
value|PRyDsResult
end_define

begin_define
define|#
directive|define
name|RyDsUReject
value|PRyDsUReject
end_define

begin_define
define|#
directive|define
name|RyGenID
value|PRyGenID
end_define

begin_define
define|#
directive|define
name|RyLose
value|PRyLose
end_define

begin_define
define|#
directive|define
name|RyOpInvoke
value|PRyOpInvoke
end_define

begin_define
define|#
directive|define
name|RyStub
value|PRyStub
end_define

begin_define
define|#
directive|define
name|RyWait
value|PRyWait
end_define

begin_define
define|#
directive|define
name|RyWaitAux
value|PRyWaitAux
end_define

begin_define
define|#
directive|define
name|finddsblk
value|Pfinddsblk
end_define

begin_define
define|#
directive|define
name|finderrbyerr
value|Pfinderrbyerr
end_define

begin_define
define|#
directive|define
name|finderrbyname
value|Pfinderrbyname
end_define

begin_define
define|#
directive|define
name|findopblk
value|Pfindopblk
end_define

begin_define
define|#
directive|define
name|findopbyname
value|Pfindopbyname
end_define

begin_define
define|#
directive|define
name|findopbyop
value|Pfindopbyop
end_define

begin_define
define|#
directive|define
name|firstopblk
value|Pfirstopblk
end_define

begin_define
define|#
directive|define
name|freedsblk
value|Pfreedsblk
end_define

begin_define
define|#
directive|define
name|freeopblk
value|Pfreeopblk
end_define

begin_define
define|#
directive|define
name|losedsblk
value|Plosedsblk
end_define

begin_define
define|#
directive|define
name|loseopblk
value|Ploseopblk
end_define

begin_define
define|#
directive|define
name|newdsblk
value|Pnewdsblk
end_define

begin_define
define|#
directive|define
name|newopblk
value|Pnewopblk
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|RyWait
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* WAIT */
end_comment

begin_comment
comment|/* Initiator */
end_comment

begin_function_decl
name|int
name|RyStub
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* STUB */
end_comment

begin_define
define|#
directive|define
name|ROS_INTR
value|2
end_define

begin_comment
comment|/*   invoke stub but return on interrupt */
end_comment

begin_function_decl
name|int
name|RyDiscard
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* DISCARD */
end_comment

begin_function_decl
name|int
name|RyOperation
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* OPERATION */
end_comment

begin_function_decl
name|int
name|RyOpInvoke
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* INVOKE */
end_comment

begin_function_decl
name|int
name|RyGenID
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* generate unique invoke ID */
end_comment

begin_comment
comment|/* Responder */
end_comment

begin_function_decl
name|int
name|RyDispatch
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* DISPATCH */
end_comment

begin_function_decl
name|int
name|RyDsResult
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* RESULT */
end_comment

begin_function_decl
name|int
name|RyDsError
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* ERROR */
end_comment

begin_function_decl
name|int
name|RyDsUReject
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* U-REJECT */
end_comment

begin_function_decl
name|int
name|RyLose
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* clean-up after association termination */
end_comment

begin_decl_stmt
name|struct
name|RyOperation
modifier|*
name|findopbyop
argument_list|()
decl_stmt|,
modifier|*
name|findopbyname
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|RyError
modifier|*
name|finderrbyerr
argument_list|()
decl_stmt|,
modifier|*
name|finderrbyname
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|freeopblk
argument_list|()
decl_stmt|,
name|loseopblk
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|opsblk
modifier|*
name|newopblk
argument_list|()
decl_stmt|,
modifier|*
name|findopblk
argument_list|()
decl_stmt|,
modifier|*
name|firstopblk
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|freedsblk
argument_list|()
decl_stmt|,
name|losedsblk
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|dspblk
modifier|*
name|newdsblk
argument_list|()
decl_stmt|,
modifier|*
name|finddsblk
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

