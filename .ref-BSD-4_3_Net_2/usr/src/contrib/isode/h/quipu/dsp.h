begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dsp.h - a few DSP things */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/dsp.h,v 7.2 91/02/22 09:25:51 mrose Interim $  *  *  * $Log:	dsp.h,v $  * Revision 7.2  91/02/22  09:25:51  mrose  * Interim 6.8  *   * Revision 7.1  90/11/20  15:30:44  mrose  * cjr  *   * Revision 7.0  89/11/23  21:56:33  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DSP
end_ifndef

begin_define
define|#
directive|define
name|DSP
end_define

begin_include
include|#
directive|include
file|"isoaddrs.h"
end_include

begin_include
include|#
directive|include
file|"quipu/name.h"
end_include

begin_struct
struct|struct
name|op_progress
block|{
comment|/* represents OperationProgress         */
name|int
name|op_resolution_phase
decl_stmt|;
define|#
directive|define
name|OP_PHASE_NOTDEFINED
value|-1
define|#
directive|define
name|OP_PHASE_NOTSTARTED
value|1
define|#
directive|define
name|OP_PHASE_PROCEEDING
value|2
define|#
directive|define
name|OP_PHASE_COMPLETED
value|3
name|int
name|op_nextrdntoberesolved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|access_point
block|{
comment|/* represents AccessPoint               */
name|DN
name|ap_name
decl_stmt|;
name|struct
name|PSAPaddr
modifier|*
name|ap_address
decl_stmt|;
comment|/*  from ISODE                                      */
comment|/* In INCA, this may be left out                    */
name|struct
name|access_point
modifier|*
name|ap_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLACCESSPOINT
value|((struct access_point *) NULL)
end_define

begin_comment
comment|/* Continuation Ref definded in DSP     */
end_comment

begin_comment
comment|/* represents ContinuationReference     */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|continuation_ref
block|{
name|DN
name|cr_name
decl_stmt|;
name|struct
name|op_progress
name|cr_progress
decl_stmt|;
name|int
name|cr_rdn_resolved
decl_stmt|;
define|#
directive|define
name|CR_RDNRESOLVED_NOTDEFINED
value|-1
name|int
name|cr_aliasedRDNs
decl_stmt|;
define|#
directive|define
name|CR_NOALIASEDRDNS
value|-1
name|int
name|cr_reftype
decl_stmt|;
define|#
directive|define
name|RT_UNDEFINED
value|-1
define|#
directive|define
name|RT_SUPERIOR
value|1
define|#
directive|define
name|RT_SUBORDINATE
value|2
define|#
directive|define
name|RT_CROSS
value|3
define|#
directive|define
name|RT_NONSPECIFICSUBORDINATE
value|4
name|struct
name|access_point
modifier|*
name|cr_accesspoints
decl_stmt|;
name|struct
name|continuation_ref
modifier|*
name|cr_next
decl_stmt|;
comment|/*  for chaining Continuation Refs      */
comment|/* They usually occur in SETs           */
block|}
name|continuation_ref
operator|,
typedef|*
name|ContinuationRef
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLCONTINUATIONREF
value|((ContinuationRef) 0)
end_define

begin_struct
struct|struct
name|trace_info
block|{
name|DN
name|ti_target
decl_stmt|;
name|DN
name|ti_dsa
decl_stmt|;
name|struct
name|op_progress
name|ti_progress
decl_stmt|;
name|struct
name|trace_info
modifier|*
name|ti_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLTRACEINFO
value|((struct trace_info *) 0)
end_define

begin_function_decl
name|struct
name|trace_info
modifier|*
name|ti_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* THIS SECTION GIVES VARIOUS COMMON STRUCTURES */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|svccontrol
block|{
comment|/* represents ServiceControls           */
name|int
name|svc_options
decl_stmt|;
define|#
directive|define
name|SVC_OPT_PREFERCHAIN
value|0X001
define|#
directive|define
name|SVC_OPT_CHAININGPROHIBIT
value|0X002
define|#
directive|define
name|SVC_OPT_LOCALSCOPE
value|0X004
define|#
directive|define
name|SVC_OPT_DONTUSECOPY
value|0X008
define|#
directive|define
name|SVC_OPT_DONTDEREFERENCEALIAS
value|0X010
name|int
name|svc_prio
decl_stmt|;
define|#
directive|define
name|SVC_PRIO_LOW
value|0
define|#
directive|define
name|SVC_PRIO_MED
value|1
define|#
directive|define
name|SVC_PRIO_HIGH
value|2
name|int
name|svc_timelimit
decl_stmt|;
comment|/* time limit in second                 */
define|#
directive|define
name|SVC_NOTIMELIMIT
value|-1
name|int
name|svc_sizelimit
decl_stmt|;
define|#
directive|define
name|SVC_NOSIZELIMIT
value|-1
name|int
name|svc_scopeofreferral
decl_stmt|;
comment|/* Parameter for DSP only       */
define|#
directive|define
name|SVC_REFSCOPE_NONE
value|-1
define|#
directive|define
name|SVC_REFSCOPE_DMD
value|0
define|#
directive|define
name|SVC_REFSCOPE_COUNTRY
value|1
name|char
modifier|*
name|svc_tmp
decl_stmt|;
comment|/* pepsy */
name|int
name|svc_len
decl_stmt|;
comment|/* pepsy */
block|}
name|svccontrol
operator|,
name|ServiceControl
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

