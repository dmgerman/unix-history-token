begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)lpc.h	5.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Line printer control program.  */
end_comment

begin_struct
struct|struct
name|cmd
block|{
name|char
modifier|*
name|c_name
decl_stmt|;
comment|/* command name */
name|char
modifier|*
name|c_help
decl_stmt|;
comment|/* help message */
name|int
function_decl|(
modifier|*
name|c_handler
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to do the work */
name|int
name|c_priv
decl_stmt|;
comment|/* privileged command */
block|}
struct|;
end_struct

end_unit

