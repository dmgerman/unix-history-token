begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)unctrl.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * unctrl.h  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_unctrl
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|unctrl
parameter_list|(
name|ch
parameter_list|)
value|(_unctrl[ch& 0177])
end_define

end_unit

