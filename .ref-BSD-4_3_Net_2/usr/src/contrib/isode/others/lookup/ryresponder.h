begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ryresponder.h - include file for the generic idempotent responder */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/others/lookup/RCS/ryresponder.h,v 7.2 91/02/22 09:27:43 mrose Interim $  *  *  * $Log:	ryresponder.h,v $  * Revision 7.2  91/02/22  09:27:43  mrose  * Interim 6.8  *   * Revision 7.1  90/12/11  10:40:07  mrose  * sync  *   * Revision 7.0  89/11/23  22:56:46  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PEPSY_VERSION
end_ifndef

begin_define
define|#
directive|define
name|PEPSY_VERSION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"rosy.h"
end_include

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_struct
specifier|static
struct|struct
name|dispatch
block|{
name|char
modifier|*
name|ds_name
decl_stmt|;
name|int
name|ds_operation
decl_stmt|;
name|IFP
name|ds_vector
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|adios
argument_list|()
decl_stmt|,
name|advise
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|acs_advise
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|ros_adios
argument_list|()
decl_stmt|,
name|ros_advise
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ryr_advise
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ryresponder
parameter_list|()
function_decl|;
end_function_decl

end_unit

