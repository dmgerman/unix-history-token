begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)parser.h	3.9 (Berkeley) 6/6/90  */
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

