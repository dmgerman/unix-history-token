begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)machdep.h	5.3 (Berkeley) 6/18/88  */
end_comment

begin_define
define|#
directive|define
name|LOGFILE
value|"/usr/games/lib/saillog"
end_define

begin_comment
comment|/* has to match the makefile */
end_comment

begin_define
define|#
directive|define
name|TIMEOUT
value|300
end_define

begin_comment
comment|/* Sync() timeout in seconds */
end_comment

begin_comment
comment|/* for 4.2bsd machines */
end_comment

begin_define
define|#
directive|define
name|blockalarm
parameter_list|()
value|((void) sigblock(1<< SIGALRM-1))
end_define

begin_define
define|#
directive|define
name|unblockalarm
parameter_list|()
value|((void) sigsetmask(sigblock(0)& ~(1<< SIGALRM-1)))
end_define

begin_comment
comment|/* for 2.9bsd machines (onyx) typedef int void; #define blockalarm()	((void) sighold(SIGALRM)) #define unblockalarm()	((void) sigrelse(SIGALRM)) */
end_comment

end_unit

