begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cmd_srch.h - command search structure */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/RCS/cmd_srch.h,v 7.1 91/02/22 09:24:36 mrose Interim $  *  *  * $Log:	cmd_srch.h,v $  * Revision 7.1  91/02/22  09:24:36  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:55:40  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CMD_SRCH_
end_ifndef

begin_define
define|#
directive|define
name|_CMD_SRCH_
end_define

begin_typedef
typedef|typedef
struct|struct
name|cmd_table
block|{
name|char
modifier|*
name|cmd_key
decl_stmt|;
name|int
name|cmd_value
decl_stmt|;
block|}
name|CMD_TABLE
typedef|;
end_typedef

begin_struct
struct|struct
name|cm_args
block|{
name|char
modifier|*
name|cm_key
decl_stmt|;
name|char
modifier|*
name|cm_value
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|cmd_srch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rcmd_srch
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

