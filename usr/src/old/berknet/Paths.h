begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)Paths.h	4.2	(Berkeley)	10/12/82	*/
end_comment

begin_comment
comment|/* sccs id variable */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|Paths_h_sid
init|=
literal|"@(#)Paths.h	1.6"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* note that only the first 8 letters are significant to cpp */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RAND
end_ifdef

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

begin_endif
endif|#
directive|endif
endif|RAND
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NOSC
end_ifdef

begin_define
define|#
directive|define
name|NETCMD
value|"/usr/ucbnet/bin/net"
end_define

begin_define
define|#
directive|define
name|NETCMD1
value|"/usr/ucbnet/bin/net"
end_define

begin_define
define|#
directive|define
name|NETDAEMON
value|"/usr/ucbnet/bin/netdaemon"
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
value|"/usr/ucbnet/bin/Mail"
end_define

begin_define
define|#
directive|define
name|SYSMAIL2
value|"/usr/ucbnet/bin/v6mail"
end_define

begin_define
define|#
directive|define
name|MMAILCMD
value|"/usr/ucbnet/bin/mmail"
end_define

begin_define
define|#
directive|define
name|MWRITECMD
value|"/usr/ucbnet/bin/mwrite"
end_define

begin_define
define|#
directive|define
name|NETCPCMD
value|"/usr/ucbnet/bin/netcp"
end_define

begin_define
define|#
directive|define
name|PRMAIL
value|"/usr/ucbnet/bin/prmail"
end_define

begin_define
define|#
directive|define
name|STATADDR
value|"/usr/spool/berknet/statallnet"
end_define

begin_endif
endif|#
directive|endif
endif|NOSC
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BERKELEY
end_ifdef

begin_comment
comment|/* adjustable path names, may differ on each machine */
end_comment

begin_define
define|#
directive|define
name|FREEPATH
value|"/usr/net/network/freecmd/"
end_define

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
name|CSH
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
else|CSH
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
endif|CSH
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
value|"ucbvax:/usr/spool/berknet/statallnet"
end_define

begin_endif
endif|#
directive|endif
endif|BERKELEY
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

