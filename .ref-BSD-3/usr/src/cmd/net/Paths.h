begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* note that only the first 8 letters are significant to cpp */
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

begin_define
define|#
directive|define
name|NETQSTAT
value|"/usr/net/bin/netqstats"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CSVAX
end_ifdef

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
name|DUMPFILE
value|"/usr/spool/berknet/netstatX"
end_define

begin_define
define|#
directive|define
name|NAMEFILE
value|"/usr/spool/berknet/usernames"
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOGFILE
value|"/usr/net/plogfileX"
end_define

begin_define
define|#
directive|define
name|PUBLOGFILE
value|"/usr/net/logfile"
end_define

begin_define
define|#
directive|define
name|DUMPFILE
value|"/usr/net/netstatX"
end_define

begin_define
define|#
directive|define
name|NAMEFILE
value|"/usr/net/usernames"
end_define

begin_define
define|#
directive|define
name|RESFILE
value|"/usr/net/rcv/rfaaXXXXX"
end_define

begin_define
define|#
directive|define
name|TEMPFILE
value|"/usr/net/rcv/tfaaXXXXX"
end_define

begin_define
define|#
directive|define
name|SENDDIR
value|"/usr/net/send?"
end_define

begin_define
define|#
directive|define
name|DFNAME
value|"/usr/net/send?/dfaaXXXXX"
end_define

begin_define
define|#
directive|define
name|NETRMPATH
value|"/usr/net/sendY/cfxx0000x"
end_define

begin_define
define|#
directive|define
name|NETRMNAME
value|"/usr/net/sendY/cfaa0000x"
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|CSVAX
end_ifdef

begin_define
define|#
directive|define
name|SYSMAIL1
value|"/usr/ucb/Mail"
end_define

begin_define
define|#
directive|define
name|SYSMAIL2
value|"/bin/mail"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYSMAIL1
value|"/bin/mail"
end_define

begin_define
define|#
directive|define
name|SYSMAIL2
value|"/usr/bin/mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SYSMAIL3
value|"/bin/mail"
end_define

begin_define
define|#
directive|define
name|SYSMAIL4
value|"/usr/bin/mail"
end_define

begin_comment
comment|/*     Adjustable path names, must be the same on all machines.     MMAILCMD 	sent by sendberkmail    MWRITECMD 	sent by netdaemon    NETCPCMD 	sent by netcp    PRMAIL	sent by netmail    CATCMD 	sent by netcp and netdaemon    FILECAT	should be sent by netcp and netdaemon  */
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
name|CATCMD
value|"/bin/cat"
end_define

begin_define
define|#
directive|define
name|FILECAT
value|"/usr/net/bin/filecat"
end_define

end_unit

