begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)apilib.h	3.2 (Berkeley) 3/28/88  */
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

