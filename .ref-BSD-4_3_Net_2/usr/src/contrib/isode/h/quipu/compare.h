begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* compare.h - */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/compare.h,v 7.1 91/02/22 09:25:31 mrose Interim $  *  *  * $Log:	compare.h,v $  * Revision 7.1  91/02/22  09:25:31  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:56:26  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUCOMP
end_ifndef

begin_define
define|#
directive|define
name|QUIPUCOMP
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
name|ds_compare_arg
block|{
name|CommonArgs
name|cma_common
decl_stmt|;
name|DN
name|cma_object
decl_stmt|;
name|AVA
name|cma_purported
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ds_compare_result
block|{
name|CommonResults
name|cmr_common
decl_stmt|;
name|DN
name|cmr_object
decl_stmt|;
name|char
name|cmr_matched
decl_stmt|;
comment|/* set to TRUE or FALSE                 */
name|char
name|cmr_iscopy
decl_stmt|;
comment|/* values defined in entrystruct        */
name|char
name|cmr_pepsycopy
decl_stmt|;
name|time_t
name|cmr_age
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

