begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* read.h - read operation */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/read.h,v 7.1 91/02/22 09:26:05 mrose Interim $  *  *  * $Log:	read.h,v $  * Revision 7.1  91/02/22  09:26:05  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:56:43  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUREAD
end_ifndef

begin_define
define|#
directive|define
name|QUIPUREAD
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

begin_comment
comment|/* THIS SECTION GIVES OPERATION PARAMETERS */
end_comment

begin_struct
struct|struct
name|ds_read_arg
block|{
name|CommonArgs
name|rda_common
decl_stmt|;
name|DN
name|rda_object
decl_stmt|;
name|EntryInfoSelection
name|rda_eis
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ds_read_result
block|{
name|CommonResults
name|rdr_common
decl_stmt|;
name|EntryInfo
name|rdr_entry
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

