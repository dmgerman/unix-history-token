begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)unctrl.h	5.3 (Berkeley) 6/18/88  */
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

