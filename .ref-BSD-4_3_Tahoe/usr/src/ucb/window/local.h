begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)local.h	3.7 (Berkeley) 6/29/88  */
end_comment

begin_comment
comment|/*  * Things of local interest.  */
end_comment

begin_define
define|#
directive|define
name|RUNCOM
value|".windowrc"
end_define

begin_define
define|#
directive|define
name|ESCAPEC
value|ctrl('p')
end_define

begin_define
define|#
directive|define
name|NLINE
value|48
end_define

begin_comment
comment|/* default text buffer size */
end_comment

begin_define
define|#
directive|define
name|SHELL
value|"/bin/csh"
end_define

begin_comment
comment|/* if no environment SHELL */
end_comment

end_unit

