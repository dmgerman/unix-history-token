begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sccsid = "@(#)machdep.h	2.5 %G%";  */
end_comment

begin_define
define|#
directive|define
name|LOGFILE
value|"/usr/games/lib/saillog"
end_define

begin_define
define|#
directive|define
name|DRIVER1
value|"driver"
end_define

begin_define
define|#
directive|define
name|DRIVER2
value|"/usr/games/lib/saildriver"
end_define

begin_define
define|#
directive|define
name|DRIVER3
value|"/usr/public/.driver"
end_define

begin_define
define|#
directive|define
name|DRIVERNAME
value|"driver"
end_define

begin_define
define|#
directive|define
name|SETUID
end_define

begin_comment
comment|/* player and driver run setuid */
end_comment

begin_define
define|#
directive|define
name|TIMEOUT
value|300
end_define

begin_comment
comment|/* Sync() time out */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE
value|4096
end_define

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

