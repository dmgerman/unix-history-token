begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.22 $ ** **  Here be #define's for filenames, socket names, environment variables, **  and so on.  The numbers refer to sections in the config.dist file. */
end_comment

begin_comment
comment|/* **  7.  PATHS TO COMMON PROGRAMS */
end_comment

begin_comment
comment|/* =()<#define _PATH_INND	"@<_PATH_INND>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_INND
value|"/usr/contrib/news/innd"
end_define

begin_comment
comment|/* =()<#define _PATH_INNDSTART	"@<_PATH_INNDSTART>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_INNDSTART
value|"/usr/contrib/news/inndstart"
end_define

begin_comment
comment|/* =()<#define _PATH_SENDMAIL	"@<_PATH_SENDMAIL>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_SENDMAIL
value|"/usr/sbin/sendmail -t"
end_define

begin_comment
comment|/* =()<#define _PATH_SH		"@<_PATH_SH>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_SH
value|"/bin/sh"
end_define

begin_comment
comment|/* =()<#define _PATH_NNRPD		"@<_PATH_NNRPD>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_NNRPD
value|"/usr/contrib/news/nnrpd"
end_define

begin_comment
comment|/* =()<#define _PATH_NNTPD          "@<_PATH_NNTPD>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_NNTPD
value|"/usr/contrib/news/nnrpd"
end_define

begin_comment
comment|/* =()<#define _PATH_NNQRD		"@<_PATH_NNQRD>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_NNQRD
value|"/usr/contrib/news/nnrpd"
end_define

begin_comment
comment|/* =()<#define _PATH_COMPRESS	"@<_PATH_COMPRESS>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_COMPRESS
value|"/usr/bin/compress"
end_define

begin_comment
comment|/* =()<#define _PATH_RNEWS	"@<_PATH_RNEWS>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_RNEWS
value|"/usr/contrib/news/rnews"
end_define

begin_comment
comment|/* =()<#define _PATH_NEWSBIN	"@<_PATH_NEWSBIN>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_NEWSBIN
value|"/usr/contrib/news"
end_define

begin_comment
comment|/* =()<#define _PATH_TMP	"@<_PATH_TMP>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_TMP
value|"/tmp"
end_define

begin_comment
comment|/* **  8.  PATHS RELATED TO THE SPOOL DIRECTORY */
end_comment

begin_comment
comment|/* =()<#define _PATH_SPOOL		"@<_PATH_SPOOL>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_SPOOL
value|"/var/spool/news/spool"
end_define

begin_comment
comment|/* =()<#define _PATH_OVERVIEWDIR		"@<_PATH_OVERVIEWDIR>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_OVERVIEWDIR
value|"/var/spool/news/spool"
end_define

begin_comment
comment|/* =()<#define _PATH_OVERVIEW		"@<_PATH_OVERVIEW>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_OVERVIEW
value|".overview"
end_define

begin_comment
comment|/* =()<#define _PATH_SPOOLNEWS	"@<_PATH_SPOOLNEWS>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_SPOOLNEWS
value|"/var/spool/news/spool/in.coming"
end_define

begin_comment
comment|/* =()<#define _PATH_SPOOLTEMP	"@<_PATH_SPOOLTEMP>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_SPOOLTEMP
value|"/var/spool/news/spool/in.coming/tmp"
end_define

begin_comment
comment|/* =()<#define _PATH_BADNEWS	"@<_PATH_BADNEWS>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_BADNEWS
value|"/var/spool/news/spool/in.coming/bad"
end_define

begin_comment
comment|/* =()<#define _PATH_RELBAD		"@<_PATH_RELBAD>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_RELBAD
value|"bad"
end_define

begin_comment
comment|/* **  9.  EXECUTION PATHS FOR INND AND RNEWS */
end_comment

begin_comment
comment|/* =()<#define _PATH_RNEWS_DUP_LOG	"@<_PATH_RNEWS_DUP_LOG>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_RNEWS_DUP_LOG
value|"/dev/null"
end_define

begin_comment
comment|/* =()<#define _PATH_RNEWSPROGS	"@<_PATH_RNEWSPROGS>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_RNEWSPROGS
value|"/usr/contrib/rnews"
end_define

begin_comment
comment|/* =()<#define _PATH_CONTROLPROGS	"@<_PATH_CONTROLPROGS>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_CONTROLPROGS
value|"/var/spool/news/data/ctlbin"
end_define

begin_comment
comment|/* =()<#define _PATH_BADCONTROLPROG	"@<_PATH_BADCONTROLPROG>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_BADCONTROLPROG
value|"default"
end_define

begin_comment
comment|/* **  10.  SOCKETS CREATED BY INND OR CLIENTS */
end_comment

begin_comment
comment|/* =()<#define _PATH_INNDDIR	"@<_PATH_INNDDIR>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_INNDDIR
value|"/var/spool/news/data/innd"
end_define

begin_comment
comment|/* =()<#define _PATH_NNTPCONNECT	"@<_PATH_NNTPCONNECT>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_NNTPCONNECT
value|"/var/spool/news/data/innd/nntpin"
end_define

begin_comment
comment|/* =()<#define _PATH_NEWSCONTROL	"@<_PATH_NEWSCONTROL>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_NEWSCONTROL
value|"/var/spool/news/data/innd/control"
end_define

begin_comment
comment|/* =()<#define _PATH_TEMPSOCK	"@<_PATH_TEMPSOCK>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_TEMPSOCK
value|"/var/spool/news/data/innd/ctlinndXXXXXX"
end_define

begin_comment
comment|/* **  11.  LOG AND CONFIG FILES */
end_comment

begin_comment
comment|/* =()<#define _PATH_NEWSLIB	"@<_PATH_NEWSLIB>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_NEWSLIB
value|"/var/spool/news/data"
end_define

begin_comment
comment|/* =()<#define _PATH_LOGFILE		"@<_PATH_LOGFILE>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_LOGFILE
value|"/var/spool/news/data/news"
end_define

begin_comment
comment|/* =()<#define _PATH_ERRLOG	"@<_PATH_ERRLOG>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_ERRLOG
value|"/var/spool/news/data/errlog"
end_define

begin_comment
comment|/* =()<#define _PATH_SERVERPID	"@<_PATH_SERVERPID>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_SERVERPID
value|"/var/spool/news/data/innd/innd.pid"
end_define

begin_comment
comment|/* =()<#define _PATH_NEWSFEEDS	"@<_PATH_NEWSFEEDS>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_NEWSFEEDS
value|"/var/spool/news/data/newsfeeds"
end_define

begin_comment
comment|/* =()<#define _PATH_HISTORY	"@<_PATH_HISTORY>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_HISTORY
value|"/var/spool/news/data/history"
end_define

begin_comment
comment|/* =()<#define _PATH_INNDHOSTS	"@<_PATH_INNDHOSTS>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_INNDHOSTS
value|"/var/spool/news/data/hosts.nntp"
end_define

begin_comment
comment|/* =()<#define _PATH_ACTIVE	"@<_PATH_ACTIVE>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_ACTIVE
value|"/var/spool/news/data/active"
end_define

begin_comment
comment|/* =()<#define _PATH_NEWACTIVE	"@<_PATH_NEWACTIVE>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_NEWACTIVE
value|"/var/spool/news/data/active.tmp"
end_define

begin_comment
comment|/* =()<#define _PATH_OLDACTIVE	"@<_PATH_OLDACTIVE>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_OLDACTIVE
value|"/var/spool/news/data/active.old"
end_define

begin_comment
comment|/* =()<#define _PATH_ACTIVETIMES	"@<_PATH_ACTIVETIMES>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_ACTIVETIMES
value|"/var/spool/news/data/active.times"
end_define

begin_comment
comment|/* =()<#define _PATH_BATCHDIR	"@<_PATH_BATCHDIR>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_BATCHDIR
value|"/var/spool/news/out.going"
end_define

begin_comment
comment|/* =()<#define _PATH_ARCHIVEDIR	"@<_PATH_ARCHIVEDIR>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_ARCHIVEDIR
value|"/var/spool/news/news.archive"
end_define

begin_comment
comment|/* =()<#define _PATH_DISTPATS	"@<_PATH_DISTPATS>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_DISTPATS
value|"/var/spool/news/data/distrib.pats"
end_define

begin_comment
comment|/* =()<#define _PATH_NNRPDIST	"@<_PATH_NNRPDIST>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_NNRPDIST
value|"/var/spool/news/data/distributions"
end_define

begin_comment
comment|/* =()<#define _PATH_NEWSGROUPS	"@<_PATH_NEWSGROUPS>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_NEWSGROUPS
value|"/var/spool/news/data/newsgroups"
end_define

begin_comment
comment|/* =()<#define _PATH_CONFIG	"@<_PATH_CONFIG>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_CONFIG
value|"/var/spool/news/data/inn.conf"
end_define

begin_comment
comment|/* =()<#define _PATH_CLIENTACTIVE	"@<_PATH_CLIENTACTIVE>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_CLIENTACTIVE
value|"/var/spool/news/data/active"
end_define

begin_comment
comment|/* =()<#define _PATH_TEMPACTIVE	"@<_PATH_TEMPACTIVE>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_TEMPACTIVE
value|"/tmp/activeXXXXXX"
end_define

begin_comment
comment|/* =()<#define _PATH_MODERATORS	"@<_PATH_MODERATORS>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_MODERATORS
value|"/var/spool/news/data/moderators"
end_define

begin_comment
comment|/* =()<#define _PATH_SERVER	"@<_PATH_SERVER>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_SERVER
value|"/var/spool/news/data/server"
end_define

begin_comment
comment|/* =()<#define _PATH_NNTPPASS	"@<_PATH_NNTPPASS>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_NNTPPASS
value|"/var/spool/news/data/passwd.nntp"
end_define

begin_comment
comment|/* =()<#define _PATH_NNRPACCESS	"@<_PATH_NNRPACCESS>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_NNRPACCESS
value|"/var/spool/news/data/nnrp.access"
end_define

begin_comment
comment|/* =()<#define _PATH_EXPIRECTL	"@<_PATH_EXPIRECTL>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_EXPIRECTL
value|"/var/spool/news/data/expire.ctl"
end_define

begin_comment
comment|/* =()<#define _PATH_SCHEMA	"@<_PATH_SCHEMA>@">()= */
end_comment

begin_define
define|#
directive|define
name|_PATH_SCHEMA
value|"/var/spool/news/data/overview.fmt"
end_define

begin_comment
comment|/* **  ENVIRONMENT VARIABLES */
end_comment

begin_comment
comment|/* The host name of the NNTP server, for client posting. */
end_comment

begin_define
define|#
directive|define
name|_ENV_NNTPSERVER
value|"NNTPSERVER"
end_define

begin_comment
comment|/* The Organization header line, for client posting. */
end_comment

begin_define
define|#
directive|define
name|_ENV_ORGANIZATION
value|"ORGANIZATION"
end_define

begin_comment
comment|/* What to put in the From line, for client posting. */
end_comment

begin_define
define|#
directive|define
name|_ENV_FROMHOST
value|"FROMHOST"
end_define

begin_comment
comment|/* =()<#define _ENV_UUCPHOST	"@<_ENV_UUCPHOST>@">()= */
end_comment

begin_define
define|#
directive|define
name|_ENV_UUCPHOST
value|"UU_MACHINE"
end_define

begin_comment
comment|/* **  PARAMETERS IN THE _PATH_CONFIG FILE. */
end_comment

begin_comment
comment|/* Host for the From line; default is FQDN. */
end_comment

begin_define
define|#
directive|define
name|_CONF_FROMHOST
value|"fromhost"
end_define

begin_comment
comment|/* NNTP server to post to, if getenv(_ENV_NNTPSERVER) is NULL. */
end_comment

begin_define
define|#
directive|define
name|_CONF_SERVER
value|"server"
end_define

begin_comment
comment|/* Host for the Path line; default is FQDN. */
end_comment

begin_define
define|#
directive|define
name|_CONF_PATHHOST
value|"pathhost"
end_define

begin_comment
comment|/* Data for the Organization line if getenv(_ENV_ORGANIZATION) is NULL. */
end_comment

begin_define
define|#
directive|define
name|_CONF_ORGANIZATION
value|"organization"
end_define

begin_comment
comment|/* Default host to mail moderated articles to. */
end_comment

begin_define
define|#
directive|define
name|_CONF_MODMAILER
value|"moderatormailer"
end_define

begin_comment
comment|/* Default domain of local host. */
end_comment

begin_define
define|#
directive|define
name|_CONF_DOMAIN
value|"domain"
end_define

begin_comment
comment|/* Default mime version. */
end_comment

begin_define
define|#
directive|define
name|_CONF_MIMEVERSION
value|"mime-version"
end_define

begin_comment
comment|/* Default Content-Type */
end_comment

begin_define
define|#
directive|define
name|_CONF_CONTENTTYPE
value|"mime-contenttype"
end_define

begin_comment
comment|/* Default encoding */
end_comment

begin_define
define|#
directive|define
name|_CONF_ENCODING
value|"mime-encoding"
end_define

end_unit

