begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* list.h - */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/list.h,v 7.2 91/02/22 09:25:55 mrose Interim $  *  *  * $Log:	list.h,v $  * Revision 7.2  91/02/22  09:25:55  mrose  * Interim 6.8  *   * Revision 7.1  90/11/20  15:30:47  mrose  * cjr  *   * Revision 7.0  89/11/23  21:56:37  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPULIST
end_ifndef

begin_define
define|#
directive|define
name|QUIPULIST
end_define

begin_include
include|#
directive|include
file|"quipu/commonarg.h"
end_include

begin_include
include|#
directive|include
file|"quipu/ds_error.h"
end_include

begin_include
include|#
directive|include
file|"quipu/dap.h"
end_include

begin_struct
struct|struct
name|ds_list_arg
block|{
name|CommonArgs
name|lsa_common
decl_stmt|;
name|DN
name|lsa_object
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* .VE .VS */
end_comment

begin_struct
struct|struct
name|subordinate
block|{
name|RDN
name|sub_rdn
decl_stmt|;
name|char
name|sub_aliasentry
decl_stmt|;
comment|/* set to TRUE or FALSE                 */
name|char
name|sub_copy
decl_stmt|;
comment|/* set to TRUE or FALSE                 */
name|struct
name|subordinate
modifier|*
name|sub_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLSUBORD
value|(struct subordinate *) NULL
end_define

begin_function_decl
name|struct
name|subordinate
modifier|*
name|subord_comp_new
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* .VE .VS */
end_comment

begin_struct
struct|struct
name|ds_list_result
block|{
name|CommonResults
name|lsr_common
decl_stmt|;
name|DN
name|lsr_object
decl_stmt|;
name|time_t
name|lsr_age
decl_stmt|;
name|struct
name|subordinate
modifier|*
name|lsr_subordinates
decl_stmt|;
name|POQ
name|lsr_poq
decl_stmt|;
define|#
directive|define
name|lsr_limitproblem
value|lsr_poq.poq_limitproblem
define|#
directive|define
name|lsr_cr
value|lsr_poq.poq_cref
name|struct
name|ds_list_result
modifier|*
name|lsr_next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Note uncorrelated will need to be    */
end_comment

begin_comment
comment|/* added in to do the secure stuff      */
end_comment

begin_comment
comment|/* in a distributed manner              */
end_comment

begin_comment
comment|/* this also applies to search          */
end_comment

begin_struct
struct|struct
name|list_cache
block|{
name|DN
name|list_dn
decl_stmt|;
name|struct
name|subordinate
modifier|*
name|list_subs
decl_stmt|;
name|struct
name|subordinate
modifier|*
name|list_sub_top
decl_stmt|;
name|int
name|list_count
decl_stmt|;
name|int
name|list_problem
decl_stmt|;
name|struct
name|list_cache
modifier|*
name|list_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLCACHE
value|(struct list_cache *) NULL
end_define

begin_function_decl
name|struct
name|list_cache
modifier|*
name|find_list_cache
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

