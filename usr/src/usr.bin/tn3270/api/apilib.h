begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)apilib.h	4.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * What one needs to specify  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|api_sup_errno
decl_stmt|,
comment|/* Supervisor error number */
name|api_sup_fcn_id
decl_stmt|,
comment|/* Supervisor function id (0x12) */
name|api_fcn_errno
decl_stmt|,
comment|/* Function error number */
name|api_fcn_fcn_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function ID (0x6b, etc.) */
end_comment

end_unit

