begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* modifyrdn.h - */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/modifyrdn.h,v 7.1 91/02/22 09:25:59 mrose Interim $  *  *  * $Log:	modifyrdn.h,v $  * Revision 7.1  91/02/22  09:25:59  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:56:39  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUMODRDN
end_ifndef

begin_define
define|#
directive|define
name|QUIPUMODRDN
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
name|ds_modifyrdn_arg
block|{
name|CommonArgs
name|mra_common
decl_stmt|;
name|DN
name|mra_object
decl_stmt|;
name|RDN
name|mra_newrdn
decl_stmt|;
name|char
name|deleterdn
decl_stmt|;
comment|/* set to TRUE or FLASE                 */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

