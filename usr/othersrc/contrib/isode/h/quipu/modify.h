begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* modify.h - */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/modify.h,v 7.2 91/02/22 09:25:58 mrose Interim $  *  *  * $Log:	modify.h,v $  * Revision 7.2  91/02/22  09:25:58  mrose  * Interim 6.8  *   * Revision 7.1  90/11/20  15:30:51  mrose  * cjr  *   * Revision 7.0  89/11/23  21:56:39  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUMOD
end_ifndef

begin_define
define|#
directive|define
name|QUIPUMOD
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
name|entrymod
block|{
name|int
name|em_type
decl_stmt|;
define|#
directive|define
name|EM_ADDATTRIBUTE
value|1
define|#
directive|define
name|EM_REMOVEATTRIBUTE
value|2
define|#
directive|define
name|EM_ADDVALUES
value|3
define|#
directive|define
name|EM_REMOVEVALUES
value|4
name|Attr_Sequence
name|em_what
decl_stmt|;
comment|/* holds a single attribute.  the values */
comment|/* ignored for remove attribute          */
name|struct
name|entrymod
modifier|*
name|em_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLMOD
value|(struct entrymod *)NULL
end_define

begin_define
define|#
directive|define
name|em_alloc
parameter_list|()
value|(struct entrymod *) smalloc (sizeof (struct entrymod))
end_define

begin_struct
struct|struct
name|ds_modifyentry_arg
block|{
name|CommonArgs
name|mea_common
decl_stmt|;
name|DN
name|mea_object
decl_stmt|;
name|struct
name|entrymod
modifier|*
name|mea_changes
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

