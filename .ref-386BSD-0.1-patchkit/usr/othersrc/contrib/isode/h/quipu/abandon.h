begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* abandon.h - */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/abandon.h,v 7.1 91/02/22 09:25:21 mrose Interim $  *  *  * $Log:	abandon.h,v $  * Revision 7.1  91/02/22  09:25:21  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:56:19  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *                                NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUABANDON
end_ifndef

begin_define
define|#
directive|define
name|QUIPUABANDON
end_define

begin_include
include|#
directive|include
file|"quipu/dap.h"
end_include

begin_struct
struct|struct
name|ds_abandon_arg
block|{
name|int
name|aba_invokeid
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

