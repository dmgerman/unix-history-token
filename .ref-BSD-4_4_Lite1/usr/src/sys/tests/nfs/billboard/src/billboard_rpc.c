begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  ******************************************************************************  *  * Module: billboard_rpc.c  *  * Description: billboard_rpc.c  *		Conatins routines that handle RPC calls.  *  * Functions:  *	bb_call_rpc(func_p, arg_p)  *	_get_handle()  *  * Notes:  *  ******************************************************************************  */
end_comment

begin_comment
comment|/*  ******************************************************************************  * Include Files  ******************************************************************************  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"protocol.h"
end_include

begin_comment
comment|/*  ******************************************************************************  * Manifest Constants  ******************************************************************************  */
end_comment

begin_define
define|#
directive|define
name|_SERVER_NAME
value|"BB_SERVER"
end_define

begin_comment
comment|/* environment variable to 						   set the billboard server  						   name */
end_comment

begin_define
define|#
directive|define
name|_SERVER_NAME_LEN
value|64
end_define

begin_comment
comment|/*  ******************************************************************************  * Global Declarations  ******************************************************************************  */
end_comment

begin_decl_stmt
name|CLIENT
modifier|*
name|client_handle_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* request client handle */
end_comment

begin_decl_stmt
name|char
name|server_name
index|[
name|_SERVER_NAME_LEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of the billboard server */
end_comment

begin_comment
comment|/*  ******************************************************************************  * Function Declarations  ******************************************************************************  */
end_comment

begin_function_decl
specifier|static
name|CLIENT
modifier|*
name|_get_handle
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|bb_call_rpc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  ******************************************************************************  *  * Function: bb_call_rpc  *  * Description:  *	Gets client handle and does the remote procedure call.  *  * Input:  *	func_p -- address of remote procedure   *	arg_p -- input arguments to the remote procedure  *  * Output:  *  * Returns:  *	result of the RPC call  *  * Side Effects:  *  * Notes:  *  ******************************************************************************  */
end_comment

begin_function
name|char
modifier|*
name|bb_call_rpc
parameter_list|(
name|func_p
parameter_list|,
name|arg_p
parameter_list|)
function|char	*
parameter_list|(
function|*func_p
end_function

begin_expr_stmt
unit|)
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|arg_p
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * gets client handle 	 */
if|if
condition|(
name|client_handle_p
operator|==
name|NULL
condition|)
name|client_handle_p
operator|=
name|_get_handle
argument_list|()
expr_stmt|;
comment|/* 	 * do the RPC call 	 */
return|return
operator|(
operator|(
name|char
operator|*
operator|)
call|(
modifier|*
name|func_p
call|)
argument_list|(
name|arg_p
argument_list|,
name|client_handle_p
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  ******************************************************************************  *  * Function: _get_handle  *  * Description:  *	Gets client handle for the RPC call.  *	The server name may be specified in the environment        *	variable BB_SERVER, otherwise, the user will be prompted   *	for one.						  *  * Input:  *  * Output:  *  * Returns:  *	client handle  *  * Side Effects:  *  * Notes:  *  ******************************************************************************  */
end_comment

begin_function
specifier|static
name|CLIENT
modifier|*
name|_get_handle
parameter_list|()
block|{
name|char
modifier|*
name|server_p
decl_stmt|;
name|char
name|buffer
index|[
name|BB_MAX_LINE_LEN
index|]
decl_stmt|;
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
name|CLIENT
modifier|*
name|cl_handle_p
decl_stmt|;
comment|/* 	 * gets the server name from the environment variable, if not specified 	 * the user will be prompted 	 */
if|if
condition|(
operator|(
name|server_p
operator|=
name|getenv
argument_list|(
name|_SERVER_NAME
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"Server name: "
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
name|sscanf
argument_list|(
name|buffer
argument_list|,
literal|"%s"
argument_list|,
name|server_name
argument_list|)
expr_stmt|;
block|}
else|else
name|strcpy
argument_list|(
name|server_name
argument_list|,
name|server_p
argument_list|)
expr_stmt|;
comment|/* 	 * gets a client handle 	 */
if|if
condition|(
operator|(
name|cl_handle_p
operator|=
name|clnt_create
argument_list|(
name|server_name
argument_list|,
name|BILLBOARD_PROG
argument_list|,
name|BILLBOARD_VERS
argument_list|,
literal|"tcp"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|clnt_pcreateerror
argument_list|(
name|server_name
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|cl_handle_p
operator|)
return|;
block|}
end_function

end_unit

