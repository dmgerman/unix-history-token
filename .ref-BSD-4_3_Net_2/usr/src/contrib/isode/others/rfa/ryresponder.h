begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ryresponder.h - include file for the generic idempotent responder   *  * $Header: /f/osi/others/rfa/RCS/ryresponder.h,v 7.2 91/02/22 09:28:33 mrose Interim $  *  * $Log:	ryresponder.h,v $  * Revision 7.2  91/02/22  09:28:33  mrose  * Interim 6.8  *   * Revision 7.1  91/01/14  13:55:08  mrose  * update  *   * Revision 1.1  91/01/04  16:10:08  ow  * Initial revision  *   */
end_comment

begin_comment
comment|/*  *                              NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

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

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

end_unit

