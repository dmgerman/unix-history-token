begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* add.h - */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/add.h,v 7.1 91/02/22 09:25:22 mrose Interim $  *  *  * $Log:	add.h,v $  * Revision 7.1  91/02/22  09:25:22  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:56:20  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUADD
end_ifndef

begin_define
define|#
directive|define
name|QUIPUADD
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
name|ds_addentry_arg
block|{
name|CommonArgs
name|ada_common
decl_stmt|;
name|DN
name|ada_object
decl_stmt|;
name|Attr_Sequence
name|ada_entry
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

