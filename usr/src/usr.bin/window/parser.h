begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)parser.h	3.7 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"value.h"
end_include

begin_include
include|#
directive|include
file|"context.h"
end_include

begin_include
include|#
directive|include
file|"token.h"
end_include

begin_include
include|#
directive|include
file|"string.h"
end_include

begin_define
define|#
directive|define
name|p_erred
parameter_list|()
value|(cx.x_erred)
end_define

begin_define
define|#
directive|define
name|p_synerred
parameter_list|()
value|(cx.x_synerred)
end_define

begin_define
define|#
directive|define
name|p_clearerr
parameter_list|()
value|(cx.x_erred = cx.x_synerred = 0)
end_define

begin_define
define|#
directive|define
name|p_abort
parameter_list|()
value|(cx.x_abort)
end_define

end_unit

