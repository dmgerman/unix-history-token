begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* note that only the first 8 letters are significant to cpp */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RAND
end_ifdef

begin_comment
comment|/* Rand definitions */
end_comment

begin_define
define|#
directive|define
name|NETCMD
value|"/usr/Berknet/bin/net"
end_define

begin_define
define|#
directive|define
name|NETCMD1
value|"/usr/Berknet/bin/net"
end_define

begin_define
define|#
directive|define
name|NETDAEMON
value|"/usr/Berknet/bin/netdaemon"
end_define

begin_define
define|#
directive|define
name|BINSH
value|"/bin/sh"
end_define

begin_define
define|#
directive|define
name|MAILFWD1
value|"/usr/Berknet/bin/Mail"
end_define

begin_define
define|#
directive|define
name|SYSMAIL2
value|"/usr/Berknet/bin/v6mail"
end_define

begin_define
define|#
directive|define
name|MMAILCMD
value|"/usr/Berknet/bin/mmail"
end_define

begin_define
define|#
directive|define
name|MWRITECMD
value|"/usr/Berknet/bin/mwrite"
end_define

begin_define
define|#
directive|define
name|NETCPCMD
value|"/usr/Berknet/bin/netcp"
end_define

begin_define
define|#
directive|define
name|PRMAIL
value|"/usr/Berknet/bin/prmail"
end_define

begin_define
define|#
directive|define
name|STATADDR
value|"/usr/spool/berknet/statallnet"
end_define

begin_comment
comment|/* end of Rand definitions */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* for Berkeley */
end_comment

begin_comment
comment|/* adjustable path names, may differ on each machine */
end_comment

begin_define
define|#
directive|define
name|NETCMD
value|"/usr/net/bin/net"
end_define

begin_define
define|#
directive|define
name|NETCMD1
value|"/usr/net/bin/net"
end_define

begin_define
define|#
directive|define
name|NETDAEMON
value|"/usr/net/bin/netdaemon"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CORY
end_ifdef

begin_define
define|#
directive|define
name|BINSH
value|"/bin/csh"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BINSH
value|"/bin/sh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* we use v6mail whether we are or are not on a v6 system */
end_comment

begin_define
define|#
directive|define
name|MAILFWD1
value|"/usr/net/bin/Mail"
end_define

begin_define
define|#
directive|define
name|SYSMAIL2
value|"/usr/net/bin/v6mail"
end_define

begin_comment
comment|/*     Adjustable path names, must be the same on all machines.     MMAILCMD 	sent by sendberkmail    MWRITECMD 	sent by netdaemon    NETCPCMD 	sent by netcp    PRMAIL	sent by netmail  */
end_comment

begin_define
define|#
directive|define
name|MMAILCMD
value|"/usr/net/bin/mmail"
end_define

begin_define
define|#
directive|define
name|MWRITECMD
value|"/usr/net/bin/mwrite"
end_define

begin_define
define|#
directive|define
name|NETCPCMD
value|"/usr/net/bin/netcp"
end_define

begin_define
define|#
directive|define
name|PRMAIL
value|"/usr/net/bin/prmail"
end_define

begin_define
define|#
directive|define
name|STATADDR
value|"CSVAX:/usr/spool/berknet/statallnet"
end_define

begin_comment
comment|/* end of Berkeley */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LOGFILE
value|"/usr/spool/berknet/plogfileX"
end_define

begin_define
define|#
directive|define
name|PUBLOGFILE
value|"/usr/spool/berknet/logfile"
end_define

begin_define
define|#
directive|define
name|RESFILE
value|"/usr/spool/berknet/rcv/rfaaXXXXX"
end_define

begin_define
define|#
directive|define
name|TEMPFILE
value|"/usr/spool/berknet/rcv/tfaaXXXXX"
end_define

begin_define
define|#
directive|define
name|SENDDIR
value|"/usr/spool/berknet/send?"
end_define

begin_define
define|#
directive|define
name|DFNAME
value|"/usr/spool/berknet/send?/dfaaXXXXX"
end_define

begin_define
define|#
directive|define
name|NETRMPATH
value|"/usr/spool/berknet/sendY/cfxx0000x"
end_define

begin_define
define|#
directive|define
name|NETRMNAME
value|"/usr/spool/berknet/sendY/cfaa0000x"
end_define

end_unit

