begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)declare.h	4.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Declarations of routines from the controller.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|AddHost
argument_list|()
decl_stmt|,
name|DoReadModified
argument_list|()
decl_stmt|,
name|DoReadBuffer
argument_list|()
decl_stmt|,
name|OptInit
argument_list|()
decl_stmt|,
name|SendToIBM
argument_list|()
decl_stmt|,
name|SendTransparent
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|DataFrom3270
argument_list|()
decl_stmt|,
name|DataFromNetwork
argument_list|()
decl_stmt|,
name|OptOrder
argument_list|()
decl_stmt|,
name|OutputClock
decl_stmt|,
name|TransparentClock
decl_stmt|;
end_decl_stmt

end_unit

