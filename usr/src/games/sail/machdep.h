begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)machdep.h	5.1 (Berkeley) %G%  */
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

