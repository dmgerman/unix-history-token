begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Configuration information for use by NNTP server and support  * programs.  Change these as appropriate for your system.  */
end_comment

begin_comment
comment|/*  * Compile time options.  */
end_comment

begin_undef
undef|#
directive|undef
name|ALONE
end_undef

begin_comment
comment|/* True if we're running without inetd */
end_comment

begin_undef
undef|#
directive|undef
name|FASTFORK
end_undef

begin_comment
comment|/* True if we don't want to read active file on start */
end_comment

begin_undef
undef|#
directive|undef
name|BSD_42
end_undef

begin_comment
comment|/* 4.2 compatability code -- if this is defined, */
end_comment

begin_comment
comment|/* DBM probably wants to be defined as well. */
end_comment

begin_undef
undef|#
directive|undef
name|DBM
end_undef

begin_comment
comment|/* True if we want to use the old dbm(3x) libraries */
end_comment

begin_comment
comment|/* IF YOU DEFINE THIS, change CFLAGS in makefile to */
end_comment

begin_comment
comment|/* be -ldbm */
end_comment

begin_comment
comment|/*  * If you DON'T have vfork, make this "#define vfork fork"  * vfork will speed up article transfer nntpds by about 2.5 times.  */
end_comment

begin_undef
undef|#
directive|undef
name|vfork
end_undef

begin_comment
comment|/*  * If you have the syslog library routine, define SYSLOG to  * be thef syslog facility name under which stats should be  * logged.  Newer 4.3 systems might choose LOG_NEWS;  * LOG_LOCAL7 is an acceptable substitute.  *  * If you don't have support for syslog, #undef it.  * Obviously, this means that you can't define LOG, either.  */
end_comment

begin_define
define|#
directive|define
name|SYSLOG
value|LOG_NEWS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SYSLOG
end_ifdef

begin_comment
comment|/* Define LOG if you want copious logging info */
end_comment

begin_define
define|#
directive|define
name|LOG
end_define

begin_comment
comment|/* undef it if you don't */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* but you can only have LOG if you have SYSLOG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_42
end_ifdef

begin_comment
comment|/* This is a logical, warranted assumption */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DBM
end_ifndef

begin_comment
comment|/* which will probably get me in trouble. */
end_comment

begin_define
define|#
directive|define
name|DBM
end_define

begin_comment
comment|/* Kill it if you have 4.2 *and* ndbm.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|IHAVE_DEBUG
end_undef

begin_comment
comment|/* Copious debugging output from ihave */
end_comment

begin_define
define|#
directive|define
name|XHDR
end_define

begin_comment
comment|/* Optional XHDR command.  Defining this will */
end_comment

begin_comment
comment|/* speed up '=' command in rn, but will load */
end_comment

begin_comment
comment|/* the server more.  If your server is heavily */
end_comment

begin_comment
comment|/* loaded already, defining this may be a bad idea */
end_comment

begin_define
define|#
directive|define
name|SUBNET
end_define

begin_comment
comment|/* If you have 4.3 subnetting */
end_comment

begin_undef
undef|#
directive|undef
name|DAMAGED_NETMASK
end_undef

begin_comment
comment|/* If your subnet mask is not a multiple of */
end_comment

begin_comment
comment|/* four bits (e.g., UCSD) */
end_comment

begin_undef
undef|#
directive|undef
name|DECNET
end_undef

begin_comment
comment|/* If you want decnet support */
end_comment

begin_define
define|#
directive|define
name|GHNAME
end_define

begin_comment
comment|/* Define if you have gethostname() */
end_comment

begin_undef
undef|#
directive|undef
name|UUNAME
end_undef

begin_comment
comment|/* Define to use /etc/uucpname */
end_comment

begin_comment
comment|/* If neither of these are defined, */
end_comment

begin_comment
comment|/* inews will use the contents of */
end_comment

begin_comment
comment|/* /usr/include/whoami.h */
end_comment

begin_comment
comment|/*  * How long you want nntp servers to hang out without receiving  * commands before they close the connection with an error message.  *  * You CANNOT have TIMEOUT while running in standalone (ALONE) mode,  * as SIGALRM is used for different things.  *  * If you don't want any timeout, #undef it, i.e.,  *  *	#undef	TIMEOUT  *  * TIMEOUT should be at least two hours, which allows users some time  * away from their terminal (e.g., at lunch) while reading news.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ALONE
end_ifndef

begin_define
define|#
directive|define
name|TIMEOUT
value|(2 * 3600)
end_define

begin_endif
endif|#
directive|endif
endif|ALONE
end_endif

begin_comment
comment|/*  * How long you want nntp servers to wait without receiving data  * during article transfers.  You CANNOT have XFER_TIMEOUT while  * running in standalond (ALONE) mode.  *  * If you don't want any transfer timeouts, #undef it, as above.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ALONE
end_ifndef

begin_define
define|#
directive|define
name|XFER_TIMEOUT
value|(30 * 60)
end_define

begin_endif
endif|#
directive|endif
endif|ALONE
end_endif

begin_comment
comment|/*  * Your domain.  This is for the inews generated From: line,  * assuming that it doesn't find one in the article's head.  * Suggestions are .UUCP if you don't belong to the Internet.  * If your hostname returns the fully-qualified domain name  * as some 4.3 BSD systems do, simply undefine DOMAIN.  *  * e.g.  #define	DOMAIN		"berkeley.edu"  */
end_comment

begin_define
define|#
directive|define
name|DOMAIN
value|"uucp"
end_define

begin_comment
comment|/*  * A file containing the name of the host which is running  * the news server.  This will have to match what rrn thinks,  * too.  */
end_comment

begin_define
define|#
directive|define
name|SERVER_FILE
value|"/usr/local/lib/rn/server"
end_define

begin_comment
comment|/*  * Person (user name) to post news as.  */
end_comment

begin_define
define|#
directive|define
name|POSTER
value|"news"
end_define

begin_comment
comment|/*  * These files are generated by the support programs, and are needed  * by the NNTP server.  Make sure that whatever directory you  * decide these files should go is writable by whatever uid you  * have the sypport programs run under.  */
end_comment

begin_define
define|#
directive|define
name|STAT_FILE
value|"/usr/lib/news/mgdstats"
end_define

begin_define
define|#
directive|define
name|NGDATE_FILE
value|"/usr/lib/news/groupdates"
end_define

begin_comment
comment|/*  * Some commonly used programs and files.  */
end_comment

begin_define
define|#
directive|define
name|ACTIVE_FILE
value|"/usr/lib/news/active"
end_define

begin_define
define|#
directive|define
name|ACCESS_FILE
value|"/usr/lib/news/nntp_access"
end_define

begin_define
define|#
directive|define
name|HISTORY_FILE
value|"/usr/lib/news/history"
end_define

begin_define
define|#
directive|define
name|SPOOLDIR
value|"/usr/spool/news"
end_define

begin_define
define|#
directive|define
name|INEWS
value|"/usr/lib/news/inews"
end_define

begin_define
define|#
directive|define
name|RNEWS
value|"/usr/bin/rnews"
end_define

begin_comment
comment|/* Link to inews? */
end_comment

begin_comment
comment|/*  * Some miscellaneous stuff  */
end_comment

begin_define
define|#
directive|define
name|MAX_ARTICLES
value|4096
end_define

begin_comment
comment|/* Maximum number of articles/group */
end_comment

begin_define
define|#
directive|define
name|READINTVL
value|60 * 10
end_define

begin_comment
comment|/* 10 minutes b/n chking active file */
end_comment

end_unit

