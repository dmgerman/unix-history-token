begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ryinitiator.h - include file for the generic interactive initiator */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/imisc/RCS/ryinitiator.h,v 7.2 91/02/22 09:26:26 mrose Interim $  *  *  * $Log:	ryinitiator.h,v $  * Revision 7.2  91/02/22  09:26:26  mrose  * Interim 6.8  *   * Revision 7.1  90/07/01  21:04:12  mrose  * pepsy  *   * Revision 7.0  89/11/23  21:57:44  mrose  * Release 6.0  *   */
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
name|ds_argument
decl_stmt|;
name|modtyp
modifier|*
name|ds_fr_mod
decl_stmt|;
comment|/* pointer to table for arguement type */
name|int
name|ds_fr_index
decl_stmt|;
comment|/* index to entry in tables */
name|IFP
name|ds_result
decl_stmt|;
name|IFP
name|ds_error
decl_stmt|;
name|char
modifier|*
name|ds_help
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

begin_decl_stmt
name|void
name|acs_adios
argument_list|()
decl_stmt|,
name|acs_advise
argument_list|()
decl_stmt|;
end_decl_stmt

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
name|int
name|ryinitiator
parameter_list|()
function_decl|;
end_function_decl

end_unit

