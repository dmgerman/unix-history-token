begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2000 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1983, 1995-1997 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: conf.h,v 8.496.4.25 2000/08/08 23:50:40 ca Exp $  */
end_comment

begin_comment
comment|/* **  CONF.H -- All user-configurable parameters for sendmail ** **	Send updates to sendmail@Sendmail.ORG so they will be **	included in the next release. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONF_H
end_ifndef

begin_define
define|#
directive|define
name|CONF_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_struct_decl
struct_decl|struct
name|rusage
struct_decl|;
end_struct_decl

begin_comment
comment|/* forward declaration to get gcc to shut up in wait.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|SFIO
operator|&&
name|defined
argument_list|(
name|SF_APPEND
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|SF_APPEND
end_undef

begin_comment
comment|/* Both sfio/stdio.h and sys/stat.h define it */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SFIO&& defined(SF_APPEND) */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__QNX__
end_ifndef

begin_comment
comment|/* in QNX this grabs bogus LOCK_* manifests */
end_comment

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __QNX__ */
end_comment

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_comment
comment|/* make sure TOBUFSIZ isn't larger than system limit for size of exec() args */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ARG_MAX
end_ifdef

begin_if
if|#
directive|if
name|ARG_MAX
operator|>
literal|4096
end_if

begin_define
define|#
directive|define
name|SM_ARG_MAX
value|4096
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ARG_MAX> 4096 */
end_comment

begin_define
define|#
directive|define
name|SM_ARG_MAX
value|ARG_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARG_MAX> 4096 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ARG_MAX */
end_comment

begin_define
define|#
directive|define
name|SM_ARG_MAX
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARG_MAX */
end_comment

begin_comment
comment|/********************************************************************** **  Table sizes, etc.... **	There shouldn't be much need to change these.... **********************************************************************/
end_comment

begin_define
define|#
directive|define
name|MAXLINE
value|2048
end_define

begin_comment
comment|/* max line length */
end_comment

begin_define
define|#
directive|define
name|MAXNAME
value|256
end_define

begin_comment
comment|/* max length of a name */
end_comment

begin_define
define|#
directive|define
name|MAXPV
value|256
end_define

begin_comment
comment|/* max # of parms to mailers */
end_comment

begin_define
define|#
directive|define
name|MAXATOM
value|1000
end_define

begin_comment
comment|/* max atoms per address */
end_comment

begin_define
define|#
directive|define
name|MAXRWSETS
value|200
end_define

begin_comment
comment|/* max # of sets of rewriting rules */
end_comment

begin_define
define|#
directive|define
name|MAXPRIORITIES
value|25
end_define

begin_comment
comment|/* max values for Precedence: field */
end_comment

begin_define
define|#
directive|define
name|MAXMXHOSTS
value|100
end_define

begin_comment
comment|/* max # of MX records for one host */
end_comment

begin_define
define|#
directive|define
name|SMTPLINELIM
value|990
end_define

begin_comment
comment|/* maximum SMTP line length */
end_comment

begin_define
define|#
directive|define
name|MAXKEY
value|128
end_define

begin_comment
comment|/* maximum size of a database key */
end_comment

begin_define
define|#
directive|define
name|MEMCHUNKSIZE
value|1024
end_define

begin_comment
comment|/* chunk size for memory allocation */
end_comment

begin_define
define|#
directive|define
name|MAXUSERENVIRON
value|100
end_define

begin_comment
comment|/* max envars saved, must be>= 3 */
end_comment

begin_define
define|#
directive|define
name|MAXALIASDB
value|12
end_define

begin_comment
comment|/* max # of alias databases */
end_comment

begin_define
define|#
directive|define
name|MAXMAPSTACK
value|12
end_define

begin_comment
comment|/* max # of stacked or sequenced maps */
end_comment

begin_if
if|#
directive|if
name|_FFR_MILTER
end_if

begin_define
define|#
directive|define
name|MAXFILTERS
value|25
end_define

begin_comment
comment|/* max # of milter filters */
end_comment

begin_define
define|#
directive|define
name|MAXFILTERMACROS
value|50
end_define

begin_comment
comment|/* max # of macros per milter cmd */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_MILTER */
end_comment

begin_define
define|#
directive|define
name|MAXSMTPARGS
value|20
end_define

begin_comment
comment|/* max # of ESMTP args for MAIL/RCPT */
end_comment

begin_define
define|#
directive|define
name|MAXTOCLASS
value|8
end_define

begin_comment
comment|/* max # of message timeout classes */
end_comment

begin_define
define|#
directive|define
name|MAXRESTOTYPES
value|3
end_define

begin_comment
comment|/* max # of resolver timeout types */
end_comment

begin_define
define|#
directive|define
name|MAXMIMEARGS
value|20
end_define

begin_comment
comment|/* max args in Content-Type: */
end_comment

begin_define
define|#
directive|define
name|MAXMIMENESTING
value|20
end_define

begin_comment
comment|/* max MIME multipart nesting */
end_comment

begin_define
define|#
directive|define
name|QUEUESEGSIZE
value|1000
end_define

begin_comment
comment|/* increment for queue size */
end_comment

begin_define
define|#
directive|define
name|MAXQFNAME
value|20
end_define

begin_comment
comment|/* max qf file name length */
end_comment

begin_define
define|#
directive|define
name|MACBUFSIZE
value|4096
end_define

begin_comment
comment|/* max expanded macro buffer size */
end_comment

begin_define
define|#
directive|define
name|TOBUFSIZE
value|SM_ARG_MAX
end_define

begin_comment
comment|/* max buffer to hold address list */
end_comment

begin_define
define|#
directive|define
name|MAXSHORTSTR
value|203
end_define

begin_comment
comment|/* max short string length */
end_comment

begin_define
define|#
directive|define
name|MAXMACNAMELEN
value|25
end_define

begin_comment
comment|/* max macro name length */
end_comment

begin_define
define|#
directive|define
name|MAXMACROID
value|0377
end_define

begin_comment
comment|/* max macro id number */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXHDRSLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXHDRSLEN
value|(32 * 1024)
end_define

begin_comment
comment|/* max size of message headers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MAXHDRSLEN */
end_comment

begin_define
define|#
directive|define
name|MAXDAEMONS
value|10
end_define

begin_comment
comment|/* max number of ports to listen to */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXINTERFACES
end_ifndef

begin_define
define|#
directive|define
name|MAXINTERFACES
value|512
end_define

begin_comment
comment|/* number of interfaces to probe */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXINTERFACES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXSYMLINKS
end_ifndef

begin_define
define|#
directive|define
name|MAXSYMLINKS
value|32
end_define

begin_comment
comment|/* max number of symlinks in a path */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MAXSYMLINKS */
end_comment

begin_define
define|#
directive|define
name|MAXLINKPATHLEN
value|(MAXPATHLEN * MAXSYMLINKS)
end_define

begin_comment
comment|/* max link-expanded file */
end_comment

begin_define
define|#
directive|define
name|DATA_PROGRESS_TIMEOUT
value|300
end_define

begin_comment
comment|/* how ofter to check DATA progress */
end_comment

begin_define
define|#
directive|define
name|ENHSCLEN
value|10
end_define

begin_comment
comment|/* max len of enhanced status code */
end_comment

begin_if
if|#
directive|if
name|_FFR_DYNAMIC_TOBUF
end_if

begin_define
define|#
directive|define
name|DEFAULT_MAX_RCPT
value|100
end_define

begin_comment
comment|/* max number of RCPTs per envelope */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_DYNAMIC_TOBUF */
end_comment

begin_if
if|#
directive|if
name|SASL
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|AUTH_MECHANISMS
end_ifndef

begin_if
if|#
directive|if
name|STARTTLS
operator|&&
name|_FFR_EXT_MECH
end_if

begin_define
define|#
directive|define
name|AUTH_MECHANISMS
value|"EXTERNAL GSSAPI KERBEROS_V4 DIGEST-MD5 CRAM-MD5"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* STARTTLS&& _FFR_EXT_MECH */
end_comment

begin_define
define|#
directive|define
name|AUTH_MECHANISMS
value|"GSSAPI KERBEROS_V4 DIGEST-MD5 CRAM-MD5"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STARTTLS&& _FFR_EXT_MECH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! AUTH_MECHANISMS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SASL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LDAPMAP
end_ifdef

begin_define
define|#
directive|define
name|LDAPMAP_MAX_ATTR
value|64
end_define

begin_define
define|#
directive|define
name|LDAPMAP_MAX_FILTER
value|1024
end_define

begin_define
define|#
directive|define
name|LDAPMAP_MAX_PASSWD
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDAPMAP */
end_comment

begin_comment
comment|/********************************************************************** **  Compilation options. **	#define these to 1 if they are available; **	#define them to 0 otherwise. **  All can be overridden from Makefile. **********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETINET
end_ifndef

begin_define
define|#
directive|define
name|NETINET
value|1
end_define

begin_comment
comment|/* include internet support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NETINET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETINET6
end_ifndef

begin_define
define|#
directive|define
name|NETINET6
value|0
end_define

begin_comment
comment|/* do not include IPv6 support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NETINET6 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETISO
end_ifndef

begin_define
define|#
directive|define
name|NETISO
value|0
end_define

begin_comment
comment|/* do not include ISO socket support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NETISO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_BIND
end_ifndef

begin_define
define|#
directive|define
name|NAMED_BIND
value|1
end_define

begin_comment
comment|/* use Berkeley Internet Domain Server */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NAMED_BIND */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XDEBUG
end_ifndef

begin_define
define|#
directive|define
name|XDEBUG
value|1
end_define

begin_comment
comment|/* enable extended debugging */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! XDEBUG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MATCHGECOS
end_ifndef

begin_define
define|#
directive|define
name|MATCHGECOS
value|1
end_define

begin_comment
comment|/* match user names from gecos field */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MATCHGECOS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DSN
end_ifndef

begin_define
define|#
directive|define
name|DSN
value|1
end_define

begin_comment
comment|/* include delivery status notification code */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! DSN */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|USERDB
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|NEWDB
argument_list|)
operator|||
name|defined
argument_list|(
name|HESIOD
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|USERDB
value|1
end_define

begin_comment
comment|/* look in user database */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(USERDB)&& (defined(NEWDB) || defined(HESIOD)) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIME8TO7
end_ifndef

begin_define
define|#
directive|define
name|MIME8TO7
value|1
end_define

begin_comment
comment|/* 8->7 bit MIME conversions */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MIME8TO7 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIME7TO8
end_ifndef

begin_define
define|#
directive|define
name|MIME7TO8
value|1
end_define

begin_comment
comment|/* 7->8 bit MIME conversions */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MIME7TO8 */
end_comment

begin_comment
comment|/********************************************************************** **  "Hard" compilation options. **	#define these if they are available; comment them out otherwise. **  These cannot be overridden from the Makefile, and should really not **  be turned off unless absolutely necessary. **********************************************************************/
end_comment

begin_define
define|#
directive|define
name|LOG
value|1
end_define

begin_comment
comment|/* enable logging -- don't turn off */
end_comment

begin_comment
comment|/********************************************************************** **  End of site-specific configuration. **********************************************************************/
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  General "standard C" defines. ** **	These may be undone later, to cope with systems that claim to **	be Standard C but aren't.  Gcc is the biggest offender -- it **	doesn't realize that the library is part of the language. ** **	Life would be much easier if we could get rid of this sort **	of bozo problems. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* we have setvbuf(3) in libc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_comment
comment|/* **  Assume you have standard calls; can be #undefed below if necessary. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASLSTAT
end_ifndef

begin_define
define|#
directive|define
name|HASLSTAT
value|1
end_define

begin_comment
comment|/* has lstat(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASLSTAT */
end_comment

begin_escape
end_escape

begin_comment
comment|/********************************************************************** **  Operating system configuration. ** **	Unless you are porting to a new OS, you shouldn't have to **	change these. **********************************************************************/
end_comment

begin_comment
comment|/* **  HP-UX -- tested for 8.07, 9.00, and 9.01. ** **	If V4FS is defined, compile for HP-UX 10.0. **	11.x support from Richard Allen<ra@hp.is>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_comment
comment|/* common definitions for HP-UX 9.x and 10.x */
end_comment

begin_undef
undef|#
directive|undef
name|m_flags
end_undef

begin_comment
comment|/* conflict between Berkeley DB 1.85 db.h& sys/sysmacros.h on HP 300 */
end_comment

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* include all the System V defines */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|BOGUS_O_EXCL
value|1
end_define

begin_comment
comment|/* exclusive open follows symlinks */
end_comment

begin_define
define|#
directive|define
name|seteuid
parameter_list|(
name|e
parameter_list|)
value|setresuid(-1, e, -1)
end_define

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|1
end_define

begin_comment
comment|/* can check IP source routing */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_HPUX
end_define

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_PSTAT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HASGETUSERSHELL
end_ifndef

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* getusershell(3) causes core dumps */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX11
end_ifdef

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) */
end_comment

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BROKEN_RES_SEARCH
end_ifndef

begin_define
define|#
directive|define
name|BROKEN_RES_SEARCH
value|1
end_define

begin_comment
comment|/* res_search(unknown) returns h_errno=0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! BROKEN_RES_SEARCH */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HPUX11 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOT_SENDMAIL
end_ifndef

begin_define
define|#
directive|define
name|syslog
value|hard_syslog
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NOT_SENDMAIL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUX11 */
end_comment

begin_define
define|#
directive|define
name|SAFENFSPATHCONF
value|1
end_define

begin_comment
comment|/* pathconf(2) pessimizes on NFS filesystems */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V4FS
end_ifdef

begin_comment
comment|/* HP-UX 10.x */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/stand/vmunix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/mail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/mail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|1
end_define

begin_comment
comment|/* TCP/IP implementation fixed in 10.0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_include
include|#
directive|include
file|<sys/mpctl.h>
end_include

begin_comment
comment|/* for mpctl() in get_num_procs_online() */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* V4FS */
end_comment

begin_comment
comment|/* HP-UX 9.x */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/hp-ux"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|hard_syslog
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_function_decl
specifier|extern
name|void
name|hard_syslog
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|FDSET_CAST
value|(int *)
end_define

begin_comment
comment|/* cast for fd_set parameters to select */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* V4FS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __hpux */
end_comment

begin_comment
comment|/* **  IBM AIX 4.x */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX4
end_ifdef

begin_define
define|#
directive|define
name|_AIX3
value|1
end_define

begin_comment
comment|/* pull in AIX3 stuff */
end_comment

begin_define
define|#
directive|define
name|BSD4_4_SOCKADDR
end_define

begin_comment
comment|/* has sa_len */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* seteuid(2) works */
end_comment

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_NAME
end_define

begin_comment
comment|/* use tzname[] vector */
end_comment

begin_define
define|#
directive|define
name|SOCKOPT_LEN_T
value|size_t
end_define

begin_comment
comment|/* arg#5 to getsockopt */
end_comment

begin_if
if|#
directive|if
name|_AIX4
operator|>=
literal|40200
end_if

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* setreuid(2) works as of AIX 4.2 */
end_comment

begin_define
define|#
directive|define
name|SOCKADDR_LEN_T
value|size_t
end_define

begin_comment
comment|/* e.g., arg#3 to accept, getsockname */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX4>= 40200 */
end_comment

begin_if
if|#
directive|if
name|_AIX4
operator|>=
literal|40300
end_if

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf starting in 4.3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX4>= 40300 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ILS_MACROS
argument_list|)
end_if

begin_comment
comment|/* IBM versions aren't side-effect clean */
end_comment

begin_undef
undef|#
directive|undef
name|isascii
end_undef

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|!(c& ~0177)
end_define

begin_undef
undef|#
directive|undef
name|isdigit
end_undef

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|__a
parameter_list|)
value|(_IS(__a,_ISDIGIT))
end_define

begin_undef
undef|#
directive|undef
name|isspace
end_undef

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|__a
parameter_list|)
value|(_IS(__a,_ISSPACE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_ILS_MACROS) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX4 */
end_comment

begin_comment
comment|/* **  IBM AIX 3.x -- actually tested for 3.2.3 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX3
end_ifdef

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<sys/machine.h>
end_include

begin_comment
comment|/* to get byte order */
end_comment

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* Something is broken with getsockopt() */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATFS
end_define

begin_comment
comment|/* use<sys/statfs.h> statfs() impl */
end_comment

begin_define
define|#
directive|define
name|SPT_PADCHAR
value|'\0'
end_define

begin_comment
comment|/* pad process title with nulls */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_define
define|#
directive|define
name|FSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|LA_AVENRUN
value|"avenrun"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX3 */
end_comment

begin_comment
comment|/* **  IBM AIX 2.2.1 -- actually tested for osupdate level 2706+1773 ** **	From Mark Whetzel<markw@wg.waii.com>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AIX
end_ifdef

begin_comment
comment|/* AIX/RT compiler pre-defines this */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* AIX/RT resource.h does NOT include this */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|0
end_define

begin_comment
comment|/* does not have fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* use setreuid(2) -lbsd system call */
end_comment

begin_define
define|#
directive|define
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* use setvbuf(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|0
end_define

begin_comment
comment|/* does not have setrlimit call */
end_comment

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_comment
comment|/* does not have flock call - use fcntl */
end_comment

begin_define
define|#
directive|define
name|HASULIMIT
value|1
end_define

begin_comment
comment|/* use ulimit instead of setrlimit call */
end_comment

begin_define
define|#
directive|define
name|NEEDGETOPT
value|1
end_define

begin_comment
comment|/* Do we need theirs or ours */
end_comment

begin_define
define|#
directive|define
name|SYS5SETPGRP
value|1
end_define

begin_comment
comment|/* don't have setpgid on AIX/RT */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* Something is broken with getsockopt() */
end_comment

begin_define
define|#
directive|define
name|BSD4_3
value|1
end_define

begin_comment
comment|/* NOT bsd 4.4 or posix signals */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|int
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATFS
end_define

begin_comment
comment|/* use<sys/statfs.h> statfs() impl */
end_comment

begin_define
define|#
directive|define
name|SPT_PADCHAR
value|'\0'
end_define

begin_comment
comment|/* pad process title with nulls */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_comment
comment|/* use our ported loadavgd daemon */
end_comment

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TZNAME
end_define

begin_comment
comment|/* use tzname[] vector */
end_comment

begin_define
define|#
directive|define
name|ARBPTR_T
value|int *
end_define

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_comment
comment|/* RTisms for BSD compatibility, specified in the Makefile   define BSD		1   define BSD_INCLUDES		1   define BSD_REMAP_SIGNAL_TO_SIGVEC     RTisms needed above */
end_comment

begin_comment
comment|/* make this sendmail in a completely different place */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/local/newmail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/usr/local/newmail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX */
end_comment

begin_comment
comment|/* **  Silicon Graphics IRIX ** **	Compiles on 4.0.1. ** **	Use IRIX64 instead of IRIX for 64-bit IRIX (6.0). **	Use IRIX5 instead of IRIX for IRIX 5.x. ** **	This version tries to be adaptive using _MIPS_SIM: **		_MIPS_SIM == _ABIO32 (= 1)    Abi: -32 on IRIX 6.2 **		_MIPS_SIM == _ABIN32 (= 2)    Abi: -n32 on IRIX 6.2 **		_MIPS_SIM == _ABI64  (= 3)    Abi: -64 on IRIX 6.2 ** **		_MIPS_SIM is 1 also on IRIX 5.3 ** **	IRIX64 changes from Mark R. Levinson<ml@cvdev.rochester.edu>. **	IRIX5 changes from Kari E. Hurtta<Kari.Hurtta@fmi.fi>. **	Adaptive changes from Kari E. Hurtta<Kari.Hurtta@fmi.fi>. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|IRIX
end_ifndef

begin_define
define|#
directive|define
name|IRIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IRIX */
end_comment

begin_if
if|#
directive|if
name|_MIPS_SIM
operator|>
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|IRIX5
argument_list|)
end_if

begin_define
define|#
directive|define
name|IRIX5
end_define

begin_comment
comment|/* IRIX5 or IRIX6 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_SIM> 0&& !defined(IRIX5) */
end_comment

begin_if
if|#
directive|if
name|_MIPS_SIM
operator|>
literal|1
operator|&&
operator|!
name|defined
argument_list|(
name|IRIX6
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|IRIX64
argument_list|)
end_if

begin_define
define|#
directive|define
name|IRIX6
end_define

begin_comment
comment|/* IRIX6 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_SIM> 1&& !defined(IRIX6)&& !defined(IRIX64) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__sgi) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* this is a System-V derived system */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|1
end_define

begin_comment
comment|/* can check IP source routing */
end_comment

begin_define
define|#
directive|define
name|setpgid
value|BSDsetpgrp
end_define

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* four argument statfs() call */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|512
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX6
end_ifdef

begin_define
define|#
directive|define
name|STAT64
value|1
end_define

begin_define
define|#
directive|define
name|QUAD_T
value|unsigned long long
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_IRIX6
end_define

begin_comment
comment|/* figure out at run time */
end_comment

begin_define
define|#
directive|define
name|SAFENFSPATHCONF
value|0
end_define

begin_comment
comment|/* pathconf(2) lies on NFS filesystems */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IRIX6 */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX64
end_ifdef

begin_define
define|#
directive|define
name|STAT64
value|1
end_define

begin_define
define|#
directive|define
name|QUAD_T
value|unsigned long long
end_define

begin_define
define|#
directive|define
name|NAMELISTMASK
value|0x7fffffffffffffff
end_define

begin_comment
comment|/* mask for nlist() values */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IRIX64 */
end_comment

begin_define
define|#
directive|define
name|STAT64
value|0
end_define

begin_define
define|#
directive|define
name|NAMELISTMASK
value|0x7fffffff
end_define

begin_comment
comment|/* mask for nlist() values */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IRIX64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IRIX6 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IRIX64
argument_list|)
operator|||
name|defined
argument_list|(
name|IRIX5
argument_list|)
operator|||
name|defined
argument_list|(
name|IRIX6
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|ARGV_T
value|char *const *
end_define

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) */
end_comment

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* has setrlimit(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_comment
comment|/* has getdtablesize(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(IRIX64) || defined(IRIX5) || defined(IRIX6) */
end_comment

begin_define
define|#
directive|define
name|ARGV_T
value|const char **
end_define

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(IRIX64) || defined(IRIX5) || defined(IRIX6) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IRIX */
end_comment

begin_comment
comment|/* **  SunOS and Solaris ** **	Tested on SunOS 4.1.x (a.k.a. Solaris 1.1.x) and **	Solaris 2.4 (a.k.a. SunOS 5.4). */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|1
end_define

begin_comment
comment|/* can check IP source routing */
end_comment

begin_define
define|#
directive|define
name|SAFENFSPATHCONF
value|1
end_define

begin_comment
comment|/* pathconf(2) pessimizes on NFS filesystems */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFCHOWN
end_ifndef

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* fchown(2) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFCHOWN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SOLARIS_2_3
end_ifdef

begin_define
define|#
directive|define
name|SOLARIS
value|20300
end_define

begin_comment
comment|/* for back compat only -- use -DSOLARIS=20300 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS_2_3 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NOT_SENDMAIL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SOLARIS
argument_list|)
operator|&&
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|SOLARIS
value|1
end_define

begin_comment
comment|/* unknown Solaris version */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(NOT_SENDMAIL)&& !defined(SOLARIS)&& defined(sun)&& (defined(__svr4__) || defined(__SVR4)) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SOLARIS
end_ifdef

begin_comment
comment|/* Solaris 2.x (a.k.a. SunOS 5.x) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__svr4__
end_ifndef

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_comment
comment|/* use all System V Release 4 defines below */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __svr4__ */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|USE_SA_SIGACTION
value|1
end_define

begin_comment
comment|/* use sa_sigaction field */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX
end_ifndef

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/dev/ksyms"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/mail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/mail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_HOSTS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_HOSTS
value|"/etc/inet/hosts"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_HOSTS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSLOG_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
end_define

begin_comment
comment|/* allow full size syslog buffer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SYSLOG_BUFSIZE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_TYPE
end_ifndef

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TZNAME
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! TZ_TYPE */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|>=
literal|20300
operator|||
operator|(
name|SOLARIS
operator|<
literal|10000
operator|&&
name|SOLARIS
operator|>=
literal|203
operator|)
end_if

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* seteuid works as of 2.3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS>= 20300 || (SOLARIS< 10000&& SOLARIS>= 203) */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|>=
literal|20500
operator|||
operator|(
name|SOLARIS
operator|<
literal|10000
operator|&&
name|SOLARIS
operator|>=
literal|205
operator|)
end_if

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* setreuid works as of 2.5 */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|<
literal|207
operator|||
operator|(
name|SOLARIS
operator|>
literal|10000
operator|&&
name|SOLARIS
operator|<
literal|20700
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_KSTAT
end_define

begin_comment
comment|/* use kstat(3k) -- may work in< 2.5 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RANDOMSHIFT
end_ifndef

begin_comment
comment|/* random() doesn't work well (sometimes) */
end_comment

begin_define
define|#
directive|define
name|RANDOMSHIFT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RANDOMSHIFT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS< 207 || (SOLARIS> 10000&& SOLARIS< 20700) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SOLARIS>= 20500 || (SOLARIS< 10000&& SOLARIS>= 205) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASRANDOM
end_ifndef

begin_define
define|#
directive|define
name|HASRANDOM
value|0
end_define

begin_comment
comment|/* doesn't have random(3) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASRANDOM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS>= 20500 || (SOLARIS< 10000&& SOLARIS>= 205) */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|>=
literal|20600
operator|||
operator|(
name|SOLARIS
operator|<
literal|10000
operator|&&
name|SOLARIS
operator|>=
literal|206
operator|)
end_if

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf starting in 2.6 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SOLARIS>= 20600 || (SOLARIS< 10000&& SOLARIS>= 206) */
end_comment

begin_typedef
typedef|typedef
name|int
name|int32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS>= 20600 || (SOLARIS< 10000&& SOLARIS>= 206) */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|>=
literal|20700
operator|||
operator|(
name|SOLARIS
operator|<
literal|10000
operator|&&
name|SOLARIS
operator|>=
literal|207
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_include
include|#
directive|include
file|<sys/loadavg.h>
end_include

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_comment
comment|/* getloadavg(3c) appears in 2.7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|1
end_define

begin_comment
comment|/* getusershell(3c) bug fixed in 2.7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS>= 20700 || (SOLARIS< 10000&& SOLARIS>= 207) */
end_comment

begin_if
if|#
directive|if
name|SOLARIS
operator|>=
literal|20800
operator|||
operator|(
name|SOLARIS
operator|<
literal|10000
operator|&&
name|SOLARIS
operator|>=
literal|208
operator|)
end_if

begin_define
define|#
directive|define
name|HASSTRL
value|1
end_define

begin_comment
comment|/* str*(3) added in 2.8 */
end_comment

begin_undef
undef|#
directive|undef
name|_PATH_SENDMAILPID
end_undef

begin_comment
comment|/* tmpfs /var/run added in 2.8 */
end_comment

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/var/run/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS>= 20800 || (SOLARIS< 10000&& SOLARIS>= 208) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASGETUSERSHELL
end_ifndef

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* getusershell(3) causes core dumps pre-2.7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SOLARIS */
end_comment

begin_comment
comment|/* SunOS 4.0.3 or 4.1.x */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|1
end_define

begin_comment
comment|/* DOES have getusershell(3) call in libc */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFLOCK */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TM_ZONE
end_define

begin_comment
comment|/* use tm->tm_zone */
end_comment

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_include
include|#
directive|include
file|<vfork.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|strtoul
value|strtol
end_define

begin_comment
comment|/* gcc library bogosity */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|(bcopy((s), (d), (l)))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS403
end_ifdef

begin_comment
comment|/* special tweaking for SunOS 4.0.3 */
end_comment

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_define
define|#
directive|define
name|BSD4_3
value|1
end_define

begin_comment
comment|/* 4.3 BSD-based */
end_comment

begin_define
define|#
directive|define
name|NEEDSTRSTR
value|1
end_define

begin_comment
comment|/* need emulation of strstr(3) routine */
end_comment

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
end_comment

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_undef
undef|#
directive|undef
name|HASUNAME
end_undef

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_define
define|#
directive|define
name|MODE_T
value|int
end_define

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SUNOS403 */
end_comment

begin_comment
comment|/* 4.1.x specifics */
end_comment

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has Posix setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* we have setvbuf(3) in libc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS403 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(sun)&& !defined(BSD) */
end_comment

begin_comment
comment|/* **  DG/UX ** **	Tested on 5.4.2 and 5.4.3.  Use DGUX_5_4_2 to get the **	older support. **	5.4.3 changes from Mark T. Robinson<mtr@ornl.gov>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX_5_4_2
end_ifdef

begin_define
define|#
directive|define
name|DGUX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DGUX_5_4_2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_DGUX
end_define

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has Posix setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* does not have<netinet/ip_var.h> */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) */
end_comment

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_NONE
end_define

begin_comment
comment|/* don't use setproctitle */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* four argument statfs() call */
end_comment

begin_comment
comment|/* these include files must be included early on DG/UX */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_comment
comment|/* compiler doesn't understand const? */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX_5_4_2
end_ifdef

begin_define
define|#
directive|define
name|inet_addr
value|dgux_inet_addr
end_define

begin_function_decl
specifier|extern
name|long
name|dgux_inet_addr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DGUX_5_4_2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DGUX */
end_comment

begin_comment
comment|/* **  Digital Ultrix 4.2A or 4.3 ** **	Apparently, fcntl locking is broken on 4.2A, in that locks are **	not dropped when the process exits.  This causes major problems, **	so flock is the only alternative. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) syscall */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFLOCK */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BROKEN_RES_SEARCH
end_ifndef

begin_define
define|#
directive|define
name|BROKEN_RES_SEARCH
value|1
end_define

begin_comment
comment|/* res_search(unknown) returns h_errno=0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! BROKEN_RES_SEARCH */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NEEDLOCAL_HOSTNAME_LENGTH
argument_list|)
operator|&&
name|NAMED_BIND
operator|&&
name|__RES
operator|>=
literal|19931104
operator|&&
name|__RES
operator|<
literal|19950621
end_if

begin_define
define|#
directive|define
name|NEEDLOCAL_HOSTNAME_LENGTH
value|1
end_define

begin_comment
comment|/* see sendmail/README */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NEEDLOCAL_HOSTNAME_LENGTH)&& NAMED_BIND&& __RES>= 19931104&& __RES< 19950621 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_FLOAT
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* vax */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_define
define|#
directive|define
name|LA_AVENRUN
value|"avenrun"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vax */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_MOUNT
end_define

begin_comment
comment|/* use<sys/mount.h> statfs() impl */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* pre-4.4 TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ultrix */
end_comment

begin_comment
comment|/* **  OSF/1 for KSR. ** **	Contributed by Todd C. Miller<Todd.Miller@cs.colorado.edu> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ksr__
end_ifdef

begin_define
define|#
directive|define
name|__osf__
value|1
end_define

begin_comment
comment|/* get OSF/1 defines below */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_TYPE
end_ifndef

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TZNAME
end_define

begin_comment
comment|/* use tzname[] vector */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! TZ_TYPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ksr__ */
end_comment

begin_comment
comment|/* **  OSF/1 for Intel Paragon. ** **	Contributed by Jeff A. Earickson<jeff@ssd.intel.com> **	of Intel Scalable Systems Divison. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__PARAGON__
end_ifdef

begin_define
define|#
directive|define
name|__osf__
value|1
end_define

begin_comment
comment|/* get OSF/1 defines below */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_TYPE
end_ifndef

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TZNAME
end_define

begin_comment
comment|/* use tzname[] vector */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! TZ_TYPE */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|MAXNAMLEN
value|NAME_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PARAGON__ */
end_comment

begin_comment
comment|/* **  Tru64 UNIX, formerly known as Digital UNIX, formerly known as DEC OSF/1 ** **	Tested for 3.2 and 4.0. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__osf__
end_ifdef

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* has uname(2) call */
end_comment

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) call */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSETLOGIN
value|1
end_define

begin_comment
comment|/* has setlogin(2) */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|1
end_define

begin_comment
comment|/* can check IP source routing */
end_comment

begin_define
define|#
directive|define
name|HAS_ST_GEN
value|1
end_define

begin_comment
comment|/* has st_gen field in stat struct */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_if
if|#
directive|if
name|_FFR_MILTER
end_if

begin_define
define|#
directive|define
name|SM_INT32
value|int
end_define

begin_comment
comment|/* 32bit integer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_MILTER */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFLOCK */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ALPHAOSF
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATVFS
end_define

begin_comment
comment|/* use<sys/statvfs.h> statfs() impl */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/var/adm/sendmail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/var/run/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __osf__ */
end_comment

begin_comment
comment|/* **  NeXTstep */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NeXT
end_ifdef

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|NEEDPUTENV
value|2
end_define

begin_comment
comment|/* need putenv(3) call; no setenv(3) call */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFLOCK */
end_comment

begin_define
define|#
directive|define
name|NEEDGETOPT
value|1
end_define

begin_comment
comment|/* need a replacement for getopt(3) */
end_comment

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
end_comment

begin_define
define|#
directive|define
name|UID_T
value|int
end_define

begin_comment
comment|/* compiler gripes on uid_t */
end_comment

begin_define
define|#
directive|define
name|GID_T
value|int
end_define

begin_comment
comment|/* ditto for gid_t */
end_comment

begin_define
define|#
directive|define
name|MODE_T
value|int
end_define

begin_comment
comment|/* and mode_t */
end_comment

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NOT_SENDMAIL
end_ifndef

begin_define
define|#
directive|define
name|sleep
value|sleepX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NOT_SENDMAIL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_MACH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WIFSTOPPED
end_undef

begin_undef
undef|#
directive|undef
name|WTERMSIG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _POSIX_SOURCE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/sendmail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/sendmail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TCPWRAPPERS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HASUNSETENV
end_ifndef

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASUNSETENV */
end_comment

begin_undef
undef|#
directive|undef
name|NEEDPUTENV
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCPWRAPPERS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NeXT */
end_comment

begin_comment
comment|/* **  Apple Rhapsody **	Contributed by Wilfredo Sanchez<wsanchez@apple.com> ** **	Also used for Apple Darwin support. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DARWIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* has uname(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has the setsid(2) POSIX syscall */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_define
define|#
directive|define
name|HASSETVBUF
value|1
end_define

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASLSTAT
value|1
end_define

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_define
define|#
directive|define
name|HASWAITPID
value|1
end_define

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) and vsnprintf(3) */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|1
end_define

begin_define
define|#
directive|define
name|NEEDGETOPT
value|1
end_define

begin_comment
comment|/* need a replacement for getopt(3) */
end_comment

begin_define
define|#
directive|define
name|BSD4_4_SOCKADDR
end_define

begin_comment
comment|/* has sa_len */
end_comment

begin_define
define|#
directive|define
name|NETLINK
value|1
end_define

begin_comment
comment|/* supports AF_LINK */
end_comment

begin_define
define|#
directive|define
name|HAS_ST_GEN
value|1
end_define

begin_comment
comment|/* has st_gen field in stat struct */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_comment
comment|/* use getloadavg(3) */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_MOUNT
end_define

begin_comment
comment|/* use<sys/mount.h> statfs() impl */
end_comment

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_PSSTRINGS
end_define

begin_define
define|#
directive|define
name|SPT_PADCHAR
value|'\0'
end_define

begin_comment
comment|/* pad process title with nulls */
end_comment

begin_define
define|#
directive|define
name|ERRLIST_PREDEFINED
end_define

begin_comment
comment|/* don't declare sys_errlist */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DARWIN */
end_comment

begin_comment
comment|/* **  4.4 BSD ** **	See also BSD defines. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD4_4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNU__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) call */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) and vsnprintf(3) */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|HAS_ST_GEN
value|1
end_define

begin_comment
comment|/* has st_gen field in stat struct */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|ERRLIST_PREDEFINED
end_define

begin_comment
comment|/* don't declare sys_errlist */
end_comment

begin_define
define|#
directive|define
name|BSD4_4_SOCKADDR
end_define

begin_comment
comment|/* has sa_len */
end_comment

begin_define
define|#
directive|define
name|NEED_PRINTF_PERCENTQ
value|1
end_define

begin_comment
comment|/* doesn't have %lld */
end_comment

begin_define
define|#
directive|define
name|NETLINK
value|1
end_define

begin_comment
comment|/* supports AF_LINK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_MOUNT
end_define

begin_comment
comment|/* use<sys/mount.h> statfs() impl */
end_comment

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_PSSTRINGS
end_define

begin_comment
comment|/* use PS_STRINGS pointer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(BSD4_4)&& !defined(__bsdi__)&& !defined(__GNU__) */
end_comment

begin_comment
comment|/* **  BSD/OS (was BSD/386) (all versions) **	From Tony Sanders, BSDI */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__bsdi__
end_ifdef

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has the unsetenv(3) call */
end_comment

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has the setsid(2) POSIX syscall */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSETLOGIN
value|1
end_define

begin_comment
comment|/* has setlogin(2) */
end_comment

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) and vsnprintf(3) */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* has uname(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|HAS_ST_GEN
value|1
end_define

begin_comment
comment|/* has st_gen field in stat struct */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|ERRLIST_PREDEFINED
end_define

begin_comment
comment|/* don't declare sys_errlist */
end_comment

begin_define
define|#
directive|define
name|BSD4_4_SOCKADDR
end_define

begin_comment
comment|/* has sa_len */
end_comment

begin_define
define|#
directive|define
name|NETLINK
value|1
end_define

begin_comment
comment|/* supports AF_LINK */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_MOUNT
end_define

begin_comment
comment|/* use<sys/mount.h> statfs() impl */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|QUAD_T
value|quad_t
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_BSDI_VERSION
argument_list|)
operator|&&
name|_BSDI_VERSION
operator|>=
literal|199312
end_if

begin_comment
comment|/* version 1.1 or later */
end_comment

begin_undef
undef|#
directive|undef
name|SPT_TYPE
end_undef

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_BUILTIN
end_define

begin_comment
comment|/* setproctitle is in libc */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(_BSDI_VERSION)&& _BSDI_VERSION>= 199312 */
end_comment

begin_comment
comment|/* version 1.0 or earlier */
end_comment

begin_define
define|#
directive|define
name|SPT_PADCHAR
value|'\0'
end_define

begin_comment
comment|/* pad process title with nulls */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_BSDI_VERSION)&& _BSDI_VERSION>= 199312 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_BSDI_VERSION
argument_list|)
operator|&&
name|_BSDI_VERSION
operator|>=
literal|199701
end_if

begin_comment
comment|/* on 3.x */
end_comment

begin_define
define|#
directive|define
name|HASSETUSERCONTEXT
value|1
end_define

begin_comment
comment|/* has setusercontext */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_BSDI_VERSION)&& _BSDI_VERSION>= 199701 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __bsdi__ */
end_comment

begin_comment
comment|/* **  QNX 4.2x **	Contributed by Glen McCready<glen@qnx.com>. ** **	Should work with all versions of QNX. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__QNX__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unix.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_undef
undef|#
directive|undef
name|NGROUPS_MAX
end_undef

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has the setsid(2) POSIX syscall */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_comment
comment|/* has getdtablesize(2) call */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_undef
undef|#
directive|undef
name|HASINITGROUPS
end_undef

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|NEEDGETOPT
value|1
end_define

begin_comment
comment|/* use sendmail's getopt */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|1
end_define

begin_comment
comment|/* can check IP source routing */
end_comment

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TMNAME
end_define

begin_comment
comment|/* use tmname variable */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ZERO
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_NONE
end_define

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_REUSEARGV
end_define

begin_define
define|#
directive|define
name|SPT_PADCHAR
value|'\0'
end_define

begin_comment
comment|/* pad process title with nulls */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_define
define|#
directive|define
name|E_PSEUDOBASE
value|512
end_define

begin_define
define|#
directive|define
name|_FILE_H_INCLUDED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__QNX__) */
end_comment

begin_comment
comment|/* **  FreeBSD / NetBSD / OpenBSD (all architectures, all versions) ** **  4.3BSD clone, closer to 4.4BSD	for FreeBSD 1.x and NetBSD 0.9x **  4.4BSD-Lite based			for FreeBSD 2.x and NetBSD 1.x ** **	See also BSD defines. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) call */
end_comment

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has the setsid(2) POSIX syscall */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* fchown(2) */
end_comment

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) and vsnprintf(3) */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* has uname(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|HAS_ST_GEN
value|1
end_define

begin_comment
comment|/* has st_gen field in stat struct */
end_comment

begin_define
define|#
directive|define
name|NEED_PRINTF_PERCENTQ
value|1
end_define

begin_comment
comment|/* doesn't have %lld */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|ERRLIST_PREDEFINED
end_define

begin_comment
comment|/* don't declare sys_errlist */
end_comment

begin_define
define|#
directive|define
name|BSD4_4_SOCKADDR
end_define

begin_comment
comment|/* has sa_len */
end_comment

begin_define
define|#
directive|define
name|NETLINK
value|1
end_define

begin_comment
comment|/* supports AF_LINK */
end_comment

begin_define
define|#
directive|define
name|SAFENFSPATHCONF
value|1
end_define

begin_comment
comment|/* pathconf(2) pessimizes on NFS filesystems */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|QUAD_T
value|unsigned long long
end_define

begin_define
define|#
directive|define
name|SFIO_STDIO_COMPAT
value|1
end_define

begin_comment
comment|/* can use RES_DEBUG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_MOUNT
end_define

begin_comment
comment|/* use<sys/mount.h> statfs() impl */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
operator|(
name|NetBSD
operator|>
literal|199307
operator|||
name|NetBSD0_9
operator|>
literal|1
operator|)
end_if

begin_undef
undef|#
directive|undef
name|SPT_TYPE
end_undef

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_BUILTIN
end_define

begin_comment
comment|/* setproctitle is in libc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__NetBSD__)&& (NetBSD> 199307 || NetBSD0_9> 1) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
operator|(
operator|(
name|__NetBSD_Version__
operator|>
literal|102070000
operator|)
operator|||
operator|(
name|NetBSD1_2
operator|>
literal|8
operator|)
operator|||
name|defined
argument_list|(
name|NetBSD1_4
argument_list|)
operator|||
name|defined
argument_list|(
name|NetBSD1_3
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|HASURANDOMDEV
value|1
end_define

begin_comment
comment|/* has /dev/urandom(4) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__NetBSD__)&& ((__NetBSD_Version__> 102070000) || (NetBSD1_2> 8) || defined(NetBSD1_4) || defined(NetBSD1_3)) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HASSETLOGIN
value|1
end_define

begin_comment
comment|/* has setlogin(2) */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|227001
end_if

begin_define
define|#
directive|define
name|HASSRANDOMDEV
value|1
end_define

begin_comment
comment|/* has srandomdev(3) */
end_comment

begin_define
define|#
directive|define
name|HASURANDOMDEV
value|1
end_define

begin_comment
comment|/* has /dev/urandom(4) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD_version>= 227001 */
end_comment

begin_undef
undef|#
directive|undef
name|SPT_TYPE
end_undef

begin_if
if|#
directive|if
name|__FreeBSD__
operator|>=
literal|2
end_if

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|199512
end_if

begin_comment
comment|/* 2.2-current when it appeared */
end_comment

begin_include
include|#
directive|include
file|<libutil.h>
end_include

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_BUILTIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD_version>= 199512 */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|222000
end_if

begin_comment
comment|/* 2.2.2-release and later */
end_comment

begin_define
define|#
directive|define
name|HASSETUSERCONTEXT
value|1
end_define

begin_comment
comment|/* BSDI-style login classes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD_version>= 222000 */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|330000
end_if

begin_comment
comment|/* 3.3.0-release and later */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASSTRL
end_ifndef

begin_define
define|#
directive|define
name|HASSTRL
value|1
end_define

begin_comment
comment|/* has strlc{py,at}(3) functions */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASSTRL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD_version>= 330000 */
end_comment

begin_define
define|#
directive|define
name|USESYSCTL
value|1
end_define

begin_comment
comment|/* use sysctl(3) for getting ncpus */
end_comment

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__>= 2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SPT_TYPE
end_ifndef

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_REUSEARGV
end_define

begin_define
define|#
directive|define
name|SPT_PADCHAR
value|'\0'
end_define

begin_comment
comment|/* pad process title with nulls */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SPT_TYPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__FreeBSD__) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|SPT_TYPE
end_undef

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_BUILTIN
end_define

begin_comment
comment|/* setproctitle is in libc */
end_comment

begin_define
define|#
directive|define
name|HASSETLOGIN
value|1
end_define

begin_comment
comment|/* has setlogin(2) */
end_comment

begin_define
define|#
directive|define
name|HASURANDOMDEV
value|1
end_define

begin_comment
comment|/* has /dev/urandom(4) */
end_comment

begin_if
if|#
directive|if
name|OpenBSD
operator|<
literal|199912
end_if

begin_define
define|#
directive|define
name|HASSTRL
value|0
end_define

begin_comment
comment|/* strlcat(3) is broken in 2.5 and earlier */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* OpenBSD< 199912 */
end_comment

begin_define
define|#
directive|define
name|HASSTRL
value|1
end_define

begin_comment
comment|/* has strlc{py,at}(3) functions */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OpenBSD< 199912 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__OpenBSD__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) */
end_comment

begin_comment
comment|/* **  Mach386 ** **	For mt Xinu's Mach386 system. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MACH
argument_list|)
operator|&&
name|defined
argument_list|(
name|i386
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNU__
argument_list|)
end_if

begin_define
define|#
directive|define
name|MACH386
value|1
end_define

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFLOCK */
end_comment

begin_define
define|#
directive|define
name|NEEDGETOPT
value|1
end_define

begin_comment
comment|/* need a replacement for getopt(3) */
end_comment

begin_define
define|#
directive|define
name|NEEDSTRTOL
value|1
end_define

begin_comment
comment|/* need the strtol() function */
end_comment

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_FLOAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_undef
undef|#
directive|undef
name|HASSETVBUF
end_undef

begin_comment
comment|/* don't actually have setvbuf(3) */
end_comment

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(MACH)&& defined(i386)&& !defined(__GNU__) */
end_comment

begin_comment
comment|/* **  GNU OS (hurd) **	Largely BSD& posix compatible. **	Port contributed by Miles Bader<miles@gnu.ai.mit.edu>. **	Updated by Mark Kettenis<kettenis@wins.uva.nl>. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNU__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) call */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* has uname(2) call */
end_comment

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) call */
end_comment

begin_define
define|#
directive|define
name|HAS_ST_GEN
value|1
end_define

begin_comment
comment|/* has st_gen field in stat struct */
end_comment

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) and vsnprintf(3) */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|SOCKADDR_LEN_T
value|socklen_t
end_define

begin_define
define|#
directive|define
name|SOCKOPT_LEN_T
value|socklen_t
end_define

begin_if
if|#
directive|if
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|>
literal|1
operator|)
operator|||
name|__GLIBC__
operator|>
literal|2
end_if

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_MACH
end_define

begin_comment
comment|/* GNU uses mach[34], which renames some rpcs from mach2.x. */
end_comment

begin_define
define|#
directive|define
name|host_self
value|mach_host_self
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATFS
end_define

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_CHANGEARGV
end_define

begin_define
define|#
directive|define
name|ERRLIST_PREDEFINED
value|1
end_define

begin_comment
comment|/* don't declare sys_errlist */
end_comment

begin_define
define|#
directive|define
name|BSD4_4_SOCKADDR
value|1
end_define

begin_comment
comment|/* has sa_len */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFCONF_IS_BROKEN
value|1
end_define

begin_comment
comment|/* SIOCGFCONF doesn't work */
end_comment

begin_define
define|#
directive|define
name|HAS_IN_H
value|1
end_define

begin_comment
comment|/* GNU has netinet/in.h. */
end_comment

begin_comment
comment|/* GNU has no MAXPATHLEN; ideally the code should be changed to not use it. */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__GNU__)&& !defined(NeXT) */
end_comment

begin_comment
comment|/* **  4.3 BSD -- this is for very old systems ** **	Should work for mt Xinu MORE/BSD and Mips UMIPS-BSD 2.1. ** **	You'll also have to install a new resolver library. **	I don't guarantee that support for this environment is complete. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|oldBSD43
argument_list|)
operator|||
name|defined
argument_list|(
name|MORE_BSD
argument_list|)
operator|||
name|defined
argument_list|(
name|umipsbsd
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEEDVPRINTF
value|1
end_define

begin_comment
comment|/* need a replacement for vprintf(3) */
end_comment

begin_define
define|#
directive|define
name|NEEDGETOPT
value|1
end_define

begin_comment
comment|/* need a replacement for getopt(3) */
end_comment

begin_define
define|#
directive|define
name|ARBPTR_T
value|char *
end_define

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_FLOAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_typedef
typedef|typedef
name|short
name|pid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(oldBSD43) || defined(MORE_BSD) || defined(umipsbsd) */
end_comment

begin_comment
comment|/* **  SCO Unix ** **	This includes three parts: ** **	The first is for SCO OpenServer 5. **	(Contributed by Keith Reynolds<keithr@sco.COM>). ** **		SCO OpenServer 5 has a compiler version number macro, **		which we can use to figure out what version we're on. **		This may have to change in future releases. ** **	The second is for SCO UNIX 3.2v4.2/Open Desktop 3.0. **	(Contributed by Philippe Brand<phb@colombo.telesys-innov.fr>). ** **	The third is for SCO UNIX 3.2v4.0/Open Desktop 2.0 and earlier. */
end_comment

begin_comment
comment|/* SCO OpenServer 5 */
end_comment

begin_if
if|#
directive|if
name|_SCO_DS
operator|>=
literal|1
end_if

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|SIOCGIFNUM_IS_BROKEN
value|1
end_define

begin_comment
comment|/* SIOCGIFNUM returns bogus value */
end_comment

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) call */
end_comment

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* has setrlimit(2) call */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_comment
comment|/* has getdtablesize(2) call */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_NEEDS_SYS_TIME_H
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_DEVSHORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|_PATH_AVENRUN
value|"/dev/table/avenrun"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_SCO_unix_4_2
end_ifndef

begin_define
define|#
directive|define
name|_SCO_unix_4_2
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! _SCO_unix_4_2 */
end_comment

begin_define
define|#
directive|define
name|SOCKADDR_LEN_T
value|size_t
end_define

begin_comment
comment|/* e.g., arg#3 to accept, getsockname */
end_comment

begin_define
define|#
directive|define
name|SOCKOPT_LEN_T
value|size_t
end_define

begin_comment
comment|/* arg#5 to getsockopt */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SCO_unix_4_2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCO_DS>= 1 */
end_comment

begin_comment
comment|/* SCO UNIX 3.2v4.2/Open Desktop 3.0 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SCO_unix_4_2
end_ifdef

begin_define
define|#
directive|define
name|_SCO_unix_
end_define

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCO_unix_4_2 */
end_comment

begin_comment
comment|/* SCO UNIX 3.2v4.0 Open Desktop 2.0 and earlier */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SCO_unix_
end_ifdef

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_comment
comment|/* needed for IP_SRCROUTE */
end_comment

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* include all the System V defines */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|NOFTRUNCATE
value|0
end_define

begin_comment
comment|/* has (simulated) ftruncate call */
end_comment

begin_define
define|#
directive|define
name|USE_SIGLONGJMP
value|1
end_define

begin_comment
comment|/* sigsetjmp needed for signal handling */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATHSIZE
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* use<sys/statfs.h> 4-arg impl */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_SCO
end_define

begin_comment
comment|/* write kernel u. area */
end_comment

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TM_NAME
end_define

begin_comment
comment|/* use tm->tm_name */
end_comment

begin_define
define|#
directive|define
name|UID_T
value|uid_t
end_define

begin_define
define|#
directive|define
name|GID_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_comment
comment|/* stuff fixed in later releases */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCO_unix_4_2
end_ifndef

begin_define
define|#
directive|define
name|SYS5SIGNALS
value|1
end_define

begin_comment
comment|/* SysV signal semantics -- reset on each sig */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SCO_unix_4_2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCO_DS
end_ifndef

begin_define
define|#
directive|define
name|ftruncate
value|chsize
end_define

begin_comment
comment|/* use chsize(2) to emulate ftruncate */
end_comment

begin_define
define|#
directive|define
name|NEEDFSYNC
value|1
end_define

begin_comment
comment|/* needs the fsync(2) call stub */
end_comment

begin_define
define|#
directive|define
name|NETUNIX
value|0
end_define

begin_comment
comment|/* no unix domain socket support */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SHORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SCO_DS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCO_unix_ */
end_comment

begin_comment
comment|/* **  ISC (SunSoft) Unix. ** **	Contributed by J.J. Bailey<jjb@jagware.bcc.com> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_UNIX
end_ifdef

begin_include
include|#
directive|include
file|<net/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_comment
comment|/* needed for IP_SRCROUTE */
end_comment

begin_include
include|#
directive|include
file|<sys/bsdtypes.h>
end_include

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* include all the System V defines */
end_comment

begin_define
define|#
directive|define
name|SYS5SIGNALS
value|1
end_define

begin_comment
comment|/* SysV signal semantics -- reset on each sig */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|NEEDFSYNC
value|1
end_define

begin_comment
comment|/* needs the fsync(2) call stub */
end_comment

begin_define
define|#
directive|define
name|NETUNIX
value|0
end_define

begin_comment
comment|/* no unix domain socket support */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|1024
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SHORT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATFS
end_define

begin_comment
comment|/* use<sys/statfs.h> statfs() impl */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_UNIX */
end_comment

begin_comment
comment|/* **  Altos System V (5.3.1) **	Contributed by Tim Rice<tim@trr.metro.net>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ALTOS_SYSTEM_V
end_ifdef

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* include all the System V defines */
end_comment

begin_define
define|#
directive|define
name|SYS5SIGNALS
value|1
end_define

begin_comment
comment|/* SysV signal semantics -- reset on each sig */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
end_comment

begin_define
define|#
directive|define
name|NEEDFSYNC
value|1
end_define

begin_comment
comment|/* no fsync(2) in system library */
end_comment

begin_define
define|#
directive|define
name|NEEDSTRSTR
value|1
end_define

begin_comment
comment|/* need emulation of the strstr(3) call */
end_comment

begin_define
define|#
directive|define
name|NOFTRUNCATE
value|1
end_define

begin_comment
comment|/* do not have ftruncate(2) */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATH_MAX
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SHORT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATFS
end_define

begin_comment
comment|/* use<sys/statfs.h> statfs() impl */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TZNAME
end_define

begin_comment
comment|/* use tzname[] vector */
end_comment

begin_define
define|#
directive|define
name|NETUNIX
value|0
end_define

begin_comment
comment|/* no unix domain socket support */
end_comment

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_define
define|#
directive|define
name|strtoul
value|strtol
end_define

begin_comment
comment|/* gcc library bogosity */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|mode_t
typedef|;
end_typedef

begin_comment
comment|/* some stuff that should have been in the include files */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|group
modifier|*
name|getgrgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|group
modifier|*
name|getgrnam
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALTOS_SYSTEM_V */
end_comment

begin_comment
comment|/* **  ConvexOS 11.0 and later ** **	"Todd C. Miller"<millert@mroe.cs.colorado.edu> claims this **	works on 9.1 as well. ** **  ConvexOS 11.5 and later, should work on 11.0 as defined. **  For pre-ConvexOOS 11.0, define NEEDGETOPT, undef IDENTPROTO ** **	Eric Schnoebelen (eric@cirr.com) For CONVEX Computer Corp. **		(now the CONVEX Technologies Center of Hewlett Packard) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_CONVEX_SOURCE
end_ifdef

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_comment
comment|/* has getdtablesize(2) */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has POSIX setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) */
end_comment

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) */
end_comment

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* has setrlimit(2) */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) */
end_comment

begin_define
define|#
directive|define
name|BROKEN_RES_SEARCH
value|1
end_define

begin_comment
comment|/* res_search(unknown) returns h_error=0 */
end_comment

begin_define
define|#
directive|define
name|NEEDPUTENV
value|1
end_define

begin_comment
comment|/* needs putenv (written in terms of setenv) */
end_comment

begin_define
define|#
directive|define
name|NEEDGETOPT
value|0
end_define

begin_comment
comment|/* need replacement for getopt(3) */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* Something is broken with getsockopt() */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_FLOAT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IREAD
end_ifndef

begin_define
define|#
directive|define
name|S_IREAD
value|_S_IREAD
end_define

begin_define
define|#
directive|define
name|S_IWRITE
value|_S_IWRITE
end_define

begin_define
define|#
directive|define
name|S_IEXEC
value|_S_IEXEC
end_define

begin_define
define|#
directive|define
name|S_IFMT
value|_S_IFMT
end_define

begin_define
define|#
directive|define
name|S_IFCHR
value|_S_IFCHR
end_define

begin_define
define|#
directive|define
name|S_IFBLK
value|_S_IFBLK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IREAD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_TYPE
end_ifndef

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TIMEZONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! TZ_TYPE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHARE_V1
end_ifndef

begin_define
define|#
directive|define
name|SHARE_V1
value|1
end_define

begin_comment
comment|/* version 1 of the fair share scheduler */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SHARE_V1 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|UID_T
value|int
end_define

begin_comment
comment|/* GNUC gets it right, ConvexC botches */
end_comment

begin_define
define|#
directive|define
name|GID_T
value|int
end_define

begin_comment
comment|/* GNUC gets it right, ConvexC botches */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__GNUC__ ) */
end_comment

begin_if
if|#
directive|if
name|SECUREWARE
end_if

begin_define
define|#
directive|define
name|FORK
value|fork
end_define

begin_comment
comment|/* SecureWare wants the real fork! */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SECUREWARE */
end_comment

begin_define
define|#
directive|define
name|FORK
value|vfork
end_define

begin_comment
comment|/* the rest of the OS versions don't care */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SECUREWARE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CONVEX_SOURCE */
end_comment

begin_comment
comment|/* **  RISC/os 4.52 ** **	Gives a ton of warning messages, but otherwise compiles. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RISCOS
end_ifdef

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) call */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFLOCK */
end_comment

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
end_comment

begin_define
define|#
directive|define
name|NEEDGETOPT
value|1
end_define

begin_comment
comment|/* need a replacement for getopt(3) */
end_comment

begin_define
define|#
directive|define
name|NEEDPUTENV
value|1
end_define

begin_comment
comment|/* need putenv(3) call */
end_comment

begin_define
define|#
directive|define
name|NEEDSTRSTR
value|1
end_define

begin_comment
comment|/* need emulation of the strstr(3) call */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_define
define|#
directive|define
name|LA_AVENRUN
value|"avenrun"
end_define

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
end_define

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SIGFUNC_DEFINED
end_define

begin_define
define|#
directive|define
name|SIGFUNC_RETURN
value|(0)
end_define

begin_define
define|#
directive|define
name|SIGFUNC_DECL
value|int
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|sigfunc_t
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* added for RISC/os 4.01...which is dumber than 4.50 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RISCOS_4_0
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ARBPTR_T
end_ifndef

begin_define
define|#
directive|define
name|ARBPTR_T
value|char *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! ARBPTR_T */
end_comment

begin_undef
undef|#
directive|undef
name|HASFLOCK
end_undef

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RISCOS_4_0 */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RISCOS */
end_comment

begin_comment
comment|/* **  Linux 0.99pl10 and above... ** **  Thanks to, in reverse order of contact: ** **	John Kennedy<warlock@csuchico.edu> **	Andrew Pam<avatar@aus.xanadu.com> **	Florian La Roche<rzsfl@rz.uni-sb.de> **	Karl London<karl@borg.demon.co.uk> ** **  Last compiled against:	[07/21/98 @ 11:47:34 AM (Tuesday)] **	sendmail 8.9.1		bind-8.1.2		db-2.4.14 **	gcc-2.8.1		glibc-2.0.94		linux-2.1.109 ** **  NOTE: Override HASFLOCK as you will but, as of 1.99.6, mixed-style **	file locking is no longer allowed.  In particular, make sure **	your DBM library and sendmail are both using either flock(2) **	*or* fcntl(2) file locking, but not both. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_include
include|#
directive|include
file|<linux/version.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KERNEL_VERSION
argument_list|)
end_if

begin_comment
comment|/* not defined in 2.0.x kernel series */
end_comment

begin_define
define|#
directive|define
name|KERNEL_VERSION
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(((a)<< 16) + ((b)<< 8) + (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_VERSION */
end_comment

begin_define
define|#
directive|define
name|BSD
value|1
end_define

begin_comment
comment|/* include BSD defines */
end_comment

begin_define
define|#
directive|define
name|USESETEUID
value|0
end_define

begin_comment
comment|/* Have it due to POSIX, but doesn't work */
end_comment

begin_define
define|#
directive|define
name|NEEDGETOPT
value|1
end_define

begin_comment
comment|/* need a replacement for getopt(3) */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(3) call */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASSNPRINTF
end_ifndef

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) and vsnprintf(3) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASSNPRINTF */
end_comment

begin_define
define|#
directive|define
name|ERRLIST_PREDEFINED
end_define

begin_comment
comment|/* don't declare sys_errlist */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_comment
comment|/* from<linux/types.h> */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* getusershell(3) broken in Slackware 2.0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IP_SRCROUTE
end_ifndef

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* linux<= 1.2.8 doesn't support IP_OPTIONS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IP_SRCROUTE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_IN_H
end_ifndef

begin_define
define|#
directive|define
name|HAS_IN_H
value|1
end_define

begin_comment
comment|/* use netinet/in.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAS_IN_H */
end_comment

begin_define
define|#
directive|define
name|USE_SIGLONGJMP
value|1
end_define

begin_comment
comment|/* sigsetjmp needed for signal handling */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|<
literal|66399
end_if

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_comment
comment|/* flock(2) is broken after 0.99.13 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LINUX_VERSION_CODE< 66399 */
end_comment

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* flock(2) fixed after 1.3.95 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINUX_VERSION_CODE< 66399 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFLOCK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_PROCSTR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() impl */
end_comment

begin_define
define|#
directive|define
name|SPT_PADCHAR
value|'\0'
end_define

begin_comment
comment|/* pad process title with nulls */
end_comment

begin_if
if|#
directive|if
operator|(
name|LINUX_VERSION_CODE
operator|>=
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|0
operator|,
literal|0
argument_list|)
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|HASURANDOMDEV
end_ifndef

begin_define
define|#
directive|define
name|HASURANDOMDEV
value|1
end_define

begin_comment
comment|/* 2.0 (at least) has linux/drivers/char/random.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASURANDOMDEV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINUX_VERSION_CODE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_TYPE
end_ifndef

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_NONE
end_define

begin_comment
comment|/* no standard for Linux */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! TZ_TYPE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/var/run/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_undef
undef|#
directive|undef
name|atol
end_undef

begin_comment
comment|/* wounded in<stdlib.h> */
end_comment

begin_if
if|#
directive|if
name|NETINET6
end_if

begin_comment
comment|/*    **  Linux doesn't have a good way to tell userland what interfaces are    **  IPv6-capable.  Therefore, the BIND resolver can not determine if there    **  are IPv6 interfaces to honor AI_ADDRCONFIG.  Unfortunately, it assumes    **  that none are present.  (Excuse the macro name ADDRCONFIG_IS_BROKEN.)    */
end_comment

begin_define
define|#
directive|define
name|ADDRCONFIG_IS_BROKEN
value|1
end_define

begin_comment
comment|/*    **  Indirectly included from glibc's<feature.h>.  IPv6 support is native    **  in 2.1 and later, but the APIs appear before the functions.    */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GLIBC_MINOR__
argument_list|)
end_if

begin_define
define|#
directive|define
name|GLIBC_VERSION
value|((__GLIBC__<< 8) + __GLIBC_MINOR__)
end_define

begin_if
if|#
directive|if
operator|(
name|GLIBC_VERSION
operator|>=
literal|0x201
operator|)
end_if

begin_undef
undef|#
directive|undef
name|IPPROTO_ICMPV6
end_undef

begin_comment
comment|/* linux #defines, glibc enums */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* (GLIBC_VERSION>= 0x201) */
end_comment

begin_include
include|#
directive|include
file|<linux/in6.h>
end_include

begin_comment
comment|/* IPv6 support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (GLIBC_VERSION>= 0x201) */
end_comment

begin_if
if|#
directive|if
operator|(
name|GLIBC_VERSION
operator|==
literal|0x201
operator|&&
operator|!
name|defined
argument_list|(
name|NEEDSGETIPNODE
argument_list|)
operator|)
end_if

begin_comment
comment|/* Have APIs in<netdb.h>, but no support in glibc */
end_comment

begin_define
define|#
directive|define
name|NEEDSGETIPNODE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (GLIBC_VERSION == 0x201&& ! NEEDSGETIPNODE) */
end_comment

begin_undef
undef|#
directive|undef
name|GLIBC_VERSION
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__GLIBC__)&& defined(__GLIBC_MINOR__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETINET6 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFCHOWN
end_ifndef

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* fchown(2) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFCHOWN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

begin_comment
comment|/* **  DELL SVR4 Issue 2.2, and others **	From Kimmo Suominen<kim@grendel.lut.fi> ** **	It's on #ifdef DELL_SVR4 because Solaris also gets __svr4__ **	defined, and the definitions conflict. ** **	Peter Wemm<peter@perth.DIALix.oz.au> claims that the setreuid **	trick works on DELL 2.2 (SVR4.0/386 version 4.0) and ESIX 4.0.3A **	(SVR4.0/386 version 3.0). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DELL_SVR4
end_ifdef

begin_comment
comment|/* no changes necessary */
end_comment

begin_comment
comment|/* see general __svr4__ defines below */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DELL_SVR4 */
end_comment

begin_comment
comment|/* **  Apple A/UX 3.0 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AUX_SOURCE
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_define
define|#
directive|define
name|BSD
end_define

begin_comment
comment|/* has BSD routines */
end_comment

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|0
end_define

begin_comment
comment|/* ... but not setrlimit(2) */
end_comment

begin_define
define|#
directive|define
name|BROKEN_RES_SEARCH
value|1
end_define

begin_comment
comment|/* res_search(unknown) returns h_errno=0 */
end_comment

begin_define
define|#
directive|define
name|BOGUS_O_EXCL
value|1
end_define

begin_comment
comment|/* exclusive open follows symlinks */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* has setvbuf(3) in libc */
end_comment

begin_define
define|#
directive|define
name|HASSTRERROR
value|1
end_define

begin_comment
comment|/* has strerror(3) */
end_comment

begin_define
define|#
directive|define
name|SIGFUNC_DEFINED
end_define

begin_comment
comment|/* sigfunc_t already defined */
end_comment

begin_define
define|#
directive|define
name|SIGFUNC_RETURN
end_define

begin_comment
comment|/* POSIX-mode */
end_comment

begin_define
define|#
directive|define
name|SIGFUNC_DECL
value|void
end_define

begin_comment
comment|/* POSIX-mode */
end_comment

begin_define
define|#
directive|define
name|ERRLIST_PREDEFINED
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_define
define|#
directive|define
name|FSHIFT
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_define
define|#
directive|define
name|LA_AVENRUN
value|"avenrun"
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TZNAME
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX
end_ifndef

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
end_define

begin_comment
comment|/* should be in<paths.h> */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AUX_SOURCE */
end_comment

begin_comment
comment|/* **  Encore UMAX V ** **	Not extensively tested. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UMAXV
end_ifdef

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* we have setvbuf(3) in libc */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|SYS5SIGNALS
value|1
end_define

begin_comment
comment|/* SysV signal semantics -- reset on each sig */
end_comment

begin_define
define|#
directive|define
name|SYS5SETPGRP
value|1
end_define

begin_comment
comment|/* use System V setpgrp(2) syscall */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* four argument statfs() call */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATH_MAX
end_define

begin_decl_stmt
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwent
argument_list|()
decl_stmt|,
modifier|*
name|getpwnam
argument_list|()
decl_stmt|,
modifier|*
name|getpwuid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|group
modifier|*
name|getgrent
argument_list|()
decl_stmt|,
modifier|*
name|getgrnam
argument_list|()
decl_stmt|,
modifier|*
name|getgrgid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UMAXV */
end_comment

begin_comment
comment|/* **  Stardent Titan 3000 running TitanOS 4.2. ** **	Must be compiled in "cc -43" mode. ** **	From Kate Hedstrom<kate@ahab.rutgers.edu>. ** **	Note the tweaking below after the BSD defines are set. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|titan
end_ifdef

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* titan */
end_comment

begin_comment
comment|/* **  Sequent DYNIX 3.2.0 ** **	From Jim Davis<jdavis@cs.arizona.edu>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sequent
end_ifdef

begin_define
define|#
directive|define
name|BSD
value|1
end_define

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_define
define|#
directive|define
name|BSD4_3
value|1
end_define

begin_comment
comment|/* to get signal() in conf.c */
end_comment

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_FLOAT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_VERSION
end_ifdef

begin_undef
undef|#
directive|undef
name|_POSIX_VERSION
end_undef

begin_comment
comment|/* set in<unistd.h> */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VERSION */
end_comment

begin_undef
undef|#
directive|undef
name|HASSETVBUF
end_undef

begin_comment
comment|/* don't actually have setvbuf(3) */
end_comment

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_comment
comment|/* Have to redefine WIFEXITED to take an int, to work with waitfor() */
end_comment

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|s
parameter_list|)
value|(((union wait*)&(s))->w_stopval != WSTOPPED&& \ 			 ((union wait*)&(s))->w_termsig == 0)
end_define

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|s
parameter_list|)
value|(((union wait*)&(s))->w_retcode)
end_define

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|isgraph
parameter_list|(
name|c
parameter_list|)
value|(isprint(c)&& (c != ' '))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX
end_ifndef

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/dynix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sequent */
end_comment

begin_comment
comment|/* **  Sequent DYNIX/ptx v2.0 (and higher) ** **	For DYNIX/ptx v1.x, undefine HASSETREUID. ** **	From Tim Wright<timw@sequent.com>. **	Update from Jack Woolley<jwoolley@sctcorp.com>, 26 Dec 1995, **		for DYNIX/ptx 4.0.2. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SEQUENT_
end_ifdef

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* include all the System V defines */
end_comment

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has POSIX setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATFS
end_define

begin_comment
comment|/* use<sys/statfs.h> statfs() impl */
end_comment

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_NONE
end_define

begin_comment
comment|/* don't use setproctitle */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SEQUENT_ */
end_comment

begin_comment
comment|/* **  Cray Unicos ** **	Ported by David L. Kensiski, Sterling Sofware<kensiski@nas.nasa.gov> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNICOS
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* include all the System V defines */
end_comment

begin_define
define|#
directive|define
name|SYS5SIGNALS
value|1
end_define

begin_comment
comment|/* SysV signal semantics -- reset on each sig */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATHSIZE
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ZERO
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* four argument statfs() call */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNICOS */
end_comment

begin_comment
comment|/* **  Apollo DomainOS ** **  From Todd Martin<tmartint@tus.ssi1.com>& Don Lewis<gdonl@gv.ssi1.com> ** **  15 Jan 1994; updated 2 Aug 1995 ** */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|apollo
end_ifdef

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(2) call */
end_comment

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* does not have<netinet/ip_var.h> */
end_comment

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_NONE
end_define

begin_comment
comment|/* don't use setproctitle */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_comment
comment|/* use getloadavg.c */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* four argument statfs() call */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TZNAME
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_undef
undef|#
directive|undef
name|S_IFSOCK
end_undef

begin_comment
comment|/* S_IFSOCK and S_IFIFO are the same */
end_comment

begin_undef
undef|#
directive|undef
name|S_IFIFO
end_undef

begin_define
define|#
directive|define
name|S_IFIFO
value|0010000
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_NEEDS_SYS_TIME_H
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NGROUPS_MAX
argument_list|)
operator|&&
operator|!
name|NGROUPS_MAX
end_if

begin_undef
undef|#
directive|undef
name|NGROUPS_MAX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(NGROUPS_MAX)&& !NGROUPS_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* apollo */
end_comment

begin_comment
comment|/* **  System V Rel 5.x (a.k.a Unixware7 w/o BSD-Compatibility Libs ie. native) ** **	Contributed by Paul Gampe<paulg@apnic.net> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__svr5__
end_ifdef

begin_include
include|#
directive|include
file|<sys/mkdev.h>
end_include

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_define
define|#
directive|define
name|SYS5SIGNALS
value|1
end_define

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_define
define|#
directive|define
name|HASWAITPID
value|1
end_define

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|SOCKADDR_LEN_T
value|size_t
end_define

begin_define
define|#
directive|define
name|SOCKOPT_LEN_T
value|size_t
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX
end_ifndef

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/stand/unix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_define
define|#
directive|define
name|SPT_PADCHAR
value|'\0'
end_define

begin_comment
comment|/* pad process title with nulls */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSLOG_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
end_define

begin_comment
comment|/* unsure */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSLOG_BUFSIZE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __svr5__ */
end_comment

begin_comment
comment|/* ###################################################################### */
end_comment

begin_comment
comment|/* **  UnixWare 2.x */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIXWARE2
end_ifdef

begin_define
define|#
directive|define
name|UNIXWARE
value|1
end_define

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) and vsnprintf(3) */
end_comment

begin_undef
undef|#
directive|undef
name|offsetof
end_undef

begin_comment
comment|/* avoid stddefs.h, sys/sysmacros.h conflict */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIXWARE2 */
end_comment

begin_comment
comment|/* **  UnixWare 1.1.2. ** **	Updated by Petr Lampa<lampa@fee.vutbr.cz>. **	From Evan Champion<evanc@spatial.synapse.org>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIXWARE
end_ifdef

begin_include
include|#
directive|include
file|<sys/mkdev.h>
end_include

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_define
define|#
directive|define
name|SLEEP_T
value|unsigned
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATVFS
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ZERO
end_define

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX
end_ifndef

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/ucblib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/usr/ucblib/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIXWARE */
end_comment

begin_comment
comment|/* **  Intergraph CLIX 3.1 ** **	From Paul Southworth<pauls@locust.cic.net> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CLIX
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* looks like System V */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASGETUSERSHELL
end_ifndef

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

begin_define
define|#
directive|define
name|DEV_BSIZE
value|512
end_define

begin_comment
comment|/* device block size not defined */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_undef
undef|#
directive|undef
name|LOG
end_undef

begin_comment
comment|/* syslog not available */
end_comment

begin_define
define|#
directive|define
name|NEEDFSYNC
value|1
end_define

begin_comment
comment|/* no fsync in system library */
end_comment

begin_define
define|#
directive|define
name|GETSHORT
value|_getshort
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CLIX */
end_comment

begin_comment
comment|/* **  NCR MP-RAS 2.x (SysVr4) with Wollongong TCP/IP ** **	From Kevin Darcy<kevin@tech.mis.cfc.com>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NCR_MP_RAS2
end_ifdef

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|0
end_define

begin_comment
comment|/* Something is broken with getsockopt() */
end_comment

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_NONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCR_MP_RAS2 */
end_comment

begin_comment
comment|/* **  NCR MP-RAS 3.x (SysVr4) with STREAMware TCP/IP ** **	From Tom Moore<Tom.Moore@DaytonOH.NCR.COM> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NCR_MP_RAS3
end_ifdef

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_define
define|#
directive|define
name|HASFCHOWN
value|1
end_define

begin_comment
comment|/* has fchown(2) call */
end_comment

begin_define
define|#
directive|define
name|SIOCGIFNUM_IS_BROKEN
value|1
end_define

begin_comment
comment|/* SIOCGIFNUM has non-std interface */
end_comment

begin_define
define|#
directive|define
name|SO_REUSEADDR_IS_BROKEN
value|1
end_define

begin_comment
comment|/* doesn't work if accept() fails */
end_comment

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_NONE
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_XOPEN_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_XOPEN_SOURCE
end_define

begin_define
define|#
directive|define
name|_XOPEN_SOURCE_EXTENDED
value|1
end_define

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_undef
undef|#
directive|undef
name|_XOPEN_SOURCE
end_undef

begin_undef
undef|#
directive|undef
name|_XOPEN_SOURCE_EXTENDED
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _XOPEN_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCR_MP_RAS3 */
end_comment

begin_comment
comment|/* **  Tandem NonStop-UX SVR4 ** **	From Rick McCarty<mccarty@mpd.tandem.com>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NonStop_UX_BXX
end_ifdef

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NonStop_UX_BXX */
end_comment

begin_comment
comment|/* **  Hitachi 3050R/3050RX and 3500 Workstations running HI-UX/WE2. ** **	Tested for 1.04, 1.03 **	From Akihiro Hashimoto ("Hash")<hash@dominic.ipc.chiba-u.ac.jp>. ** **	Tested for 4.02, 6.10 and 7.10 **	From Motonori NAKAMURA<motonori@media.kyoto-u.ac.jp>. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__hpux
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_H3050R
argument_list|)
operator|||
name|defined
argument_list|(
name|_HIUX_SOURCE
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* include all the System V defines */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* has fchmod(2) syscall */
end_comment

begin_define
define|#
directive|define
name|setreuid
parameter_list|(
name|r
parameter_list|,
name|e
parameter_list|)
value|setresuid(r, e, -1)
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_FLOAT
end_define

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_PSTAT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASSETVBUF
end_ifndef

begin_define
define|#
directive|define
name|HASSETVBUF
end_define

begin_comment
comment|/* HI-UX has no setlinebuf */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASSETVBUF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GIDSET_T
end_ifndef

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GIDSET_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX
end_ifndef

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/HI-UX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASGETUSERSHELL
end_ifndef

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* getusershell(3) causes core dumps */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

begin_define
define|#
directive|define
name|FDSET_CAST
value|(int *)
end_define

begin_comment
comment|/* cast for fd_set parameters to select */
end_comment

begin_comment
comment|/* **  avoid m_flags conflict between Berkeley DB 1.85 db.h& sys/sysmacros.h **  on HIUX 3050 */
end_comment

begin_undef
undef|#
directive|undef
name|m_flags
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|int
name|syslog
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_function_decl
specifier|extern
name|int
name|syslog
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__hpux)&& (defined(_H3050R) || defined(_HIUX_SOURCE)) */
end_comment

begin_comment
comment|/* **  Amdahl UTS System V 2.1.5 (SVr3-based) ** **    From: Janet Jackson<janet@dialix.oz.au>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_UTS
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_undef
undef|#
directive|undef
name|HASLSTAT
end_undef

begin_comment
comment|/* has symlinks, but they cause problems */
end_comment

begin_define
define|#
directive|define
name|NEEDFSYNC
value|1
end_define

begin_comment
comment|/* system fsync(2) fails on non-EFS filesys */
end_comment

begin_define
define|#
directive|define
name|SYS5SIGNALS
value|1
end_define

begin_comment
comment|/* System V signal semantics */
end_comment

begin_define
define|#
directive|define
name|SYS5SETPGRP
value|1
end_define

begin_comment
comment|/* use System V setpgrp(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) function */
end_comment

begin_define
define|#
directive|define
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* has setvbuf(3) function */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASGETUSERSHELL
end_ifndef

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) function */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_comment
comment|/* type of 2nd arg to getgroups(2) isn't int */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ZERO
end_define

begin_comment
comment|/* doesn't have load average */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* use 4-arg statfs() */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UTS */
end_comment

begin_comment
comment|/* **  Cray Computer Corporation's CSOS ** **	From Scott Bolte<scott@craycos.com>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_CRAYCOM
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_comment
comment|/* include all the System V defines */
end_comment

begin_define
define|#
directive|define
name|SYS5SIGNALS
value|1
end_define

begin_comment
comment|/* SysV signal semantics -- reset on each sig */
end_comment

begin_define
define|#
directive|define
name|NEEDFSYNC
value|1
end_define

begin_comment
comment|/* no fsync in system library */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATHSIZE
end_define

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ZERO
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_4ARGS
end_define

begin_comment
comment|/* four argument statfs() call */
end_comment

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bfree
end_define

begin_comment
comment|/* alternate field name */
end_comment

begin_define
define|#
directive|define
name|_POSIX_CHOWN_RESTRICTED
value|-1
end_define

begin_decl_stmt
specifier|extern
name|struct
name|group
modifier|*
name|getgrent
argument_list|()
decl_stmt|,
modifier|*
name|getgrnam
argument_list|()
decl_stmt|,
modifier|*
name|getgrgid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CRAYCOM */
end_comment

begin_comment
comment|/* **  Sony NEWS-OS 4.2.1R and 6.0.3 ** **	From Motonori NAKAMURA<motonori@cs.ritsumei.ac.jp>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sony_news
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__svr4
end_ifndef

begin_comment
comment|/* NEWS-OS 4.2.1R */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
end_define

begin_comment
comment|/* has BSD routines */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! BSD */
end_comment

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(2) call */
end_comment

begin_undef
undef|#
directive|undef
name|HASSETVBUF
end_undef

begin_comment
comment|/* don't actually have setvbuf(3) */
end_comment

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFLOCK */
end_comment

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_define
define|#
directive|define
name|MODE_T
value|int
end_define

begin_comment
comment|/* system include files have no mode_t */
end_comment

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|sigfunc_t
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|SIGFUNC_DEFINED
end_define

begin_define
define|#
directive|define
name|SIGFUNC_RETURN
value|(0)
end_define

begin_define
define|#
directive|define
name|SIGFUNC_DECL
value|int
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! __svr4 */
end_comment

begin_comment
comment|/* NEWS-OS 6.0.3 with /bin/cc */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__svr4__
end_ifndef

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_comment
comment|/* use all System V Release 4 defines below */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __svr4__ */
end_comment

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has Posix setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|1
end_define

begin_comment
comment|/* DOES have getusershell(3) call in libc */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_READKSYM
end_define

begin_comment
comment|/* use MIOC_READKSYM ioctl */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SPT_TYPE
end_ifndef

begin_define
define|#
directive|define
name|SPT_TYPE
value|SPT_SYSMIPS
end_define

begin_comment
comment|/* use sysmips() (OS 6.0.2 or later) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SPT_TYPE */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|SYSLOG_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SYSLOG_BUFSIZE */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/stand/unix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/mail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/mail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __svr4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sony_news */
end_comment

begin_comment
comment|/* **  Omron LUNA/UNIOS-B 3.0, LUNA2/Mach and LUNA88K Mach ** **	From Motonori NAKAMURA<motonori@cs.ritsumei.ac.jp>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|luna
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_define
define|#
directive|define
name|HASUNSETENV
value|1
end_define

begin_comment
comment|/* has unsetenv(2) call */
end_comment

begin_define
define|#
directive|define
name|NEEDPUTENV
value|1
end_define

begin_comment
comment|/* need putenv(3) call */
end_comment

begin_define
define|#
directive|define
name|NEEDGETOPT
value|1
end_define

begin_comment
comment|/* need a replacement for getopt(3) */
end_comment

begin_define
define|#
directive|define
name|NEEDSTRSTR
value|1
end_define

begin_comment
comment|/* need emulation of the strstr(3) call */
end_comment

begin_define
define|#
directive|define
name|WAITUNION
value|1
end_define

begin_comment
comment|/* use "union wait" as wait argument type */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|uniosb
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|NEEDVPRINTF
value|1
end_define

begin_comment
comment|/* need a replacement for vprintf(3) */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TM_ZONE
end_define

begin_comment
comment|/* use tm->tm_zone */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* uniosb */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|luna2
end_ifdef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_SUBR
end_define

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TM_ZONE
end_define

begin_comment
comment|/* use tm->tm_zone */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* luna2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|luna88k
end_ifdef

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) and vsnprintf(3) */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* luna88k */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_VFS
end_define

begin_comment
comment|/* use<sys/vfs.h> statfs() implementation */
end_comment

begin_define
define|#
directive|define
name|setpgid
value|setpgrp
end_define

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|sigfunc_t
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|SIGFUNC_DEFINED
end_define

begin_define
define|#
directive|define
name|SIGFUNC_RETURN
value|(0)
end_define

begin_define
define|#
directive|define
name|SIGFUNC_DECL
value|int
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/lib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* luna */
end_comment

begin_comment
comment|/* **  NEC EWS-UX/V 4.2 (with /usr/ucb/cc) ** **	From Motonori NAKAMURA<motonori@cs.ritsumei.ac.jp>. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|nec_ews_svr4
argument_list|)
operator|||
name|defined
argument_list|(
name|_nec_ews_svr4
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__svr4__
end_ifndef

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_comment
comment|/* use all System V Release 4 defines below */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __svr4__ */
end_comment

begin_define
define|#
directive|define
name|SYS5SIGNALS
value|1
end_define

begin_comment
comment|/* SysV signal semantics -- reset on each sig */
end_comment

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has Posix setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_READKSYM
end_define

begin_comment
comment|/* use MIOC_READSYM ioctl */
end_comment

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_USTAT
end_define

begin_comment
comment|/* use System V ustat(2) syscall */
end_comment

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_define
define|#
directive|define
name|NAMELISTMASK
value|0x7fffffff
end_define

begin_comment
comment|/* mask for nlist() values */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/ucblib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/usr/ucblib/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSLOG_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
end_define

begin_comment
comment|/* allow full size syslog buffer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SYSLOG_BUFSIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(nec_ews_svr4) || defined(_nec_ews_svr4) */
end_comment

begin_comment
comment|/* **  Fujitsu/ICL UXP/DS (For the DS/90 Series) ** **	From Diego R. Lopez<drlopez@cica.es>. **	Additional changes from Fumio Moriya and Toshiaki Nomura of the **		Fujitsu Fresoftware group<dsfrsoft@oai6.yk.fujitsu.co.jp>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__uxp__
end_ifdef

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_include
include|#
directive|include
file|<sys/mkdev.h>
end_include

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_if
if|#
directive|if
name|UXPDS
operator|==
literal|10
end_if

begin_define
define|#
directive|define
name|HASSNPRINTF
value|0
end_define

begin_comment
comment|/* no snprintf(3) or vsnprintf(3) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* UXPDS == 10 */
end_comment

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) and vsnprintf(3) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UXPDS == 10 */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/stand/unix"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/ucblib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/usr/ucblib/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __uxp__ */
end_comment

begin_comment
comment|/* **  Pyramid DC/OSx ** **	From Earle Ake<akee@wpdiss1.wpafb.af.mil>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DCOSx
end_ifdef

begin_define
define|#
directive|define
name|GIDSET_T
value|gid_t
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_comment
comment|/* TCP/IP implementation is broken */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DCOSx */
end_comment

begin_comment
comment|/* **  Concurrent Computer Corporation Maxion ** **	From Donald R. Laster Jr.<laster@access.digex.net>. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__MAXION__
end_ifdef

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_define
define|#
directive|define
name|__svr4__
value|1
end_define

begin_comment
comment|/* SVR4.2MP */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* have setreuid(2) */
end_comment

begin_define
define|#
directive|define
name|HASLSTAT
value|1
end_define

begin_comment
comment|/* have lstat(2) */
end_comment

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* have setrlimit(2) */
end_comment

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_comment
comment|/* have getdtablesize(2) */
end_comment

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* have snprintf(3) */
end_comment

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|1
end_define

begin_comment
comment|/* have getusershell(3) */
end_comment

begin_define
define|#
directive|define
name|NOFTRUNCATE
value|1
end_define

begin_comment
comment|/* do not have ftruncate(2) */
end_comment

begin_define
define|#
directive|define
name|SLEEP_T
value|unsigned
end_define

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATVFS
end_define

begin_define
define|#
directive|define
name|SFS_BAVAIL
value|f_bavail
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SYSLOG_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|256
end_define

begin_comment
comment|/* Use 256 bytes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SYSLOG_BUFSIZE */
end_comment

begin_undef
undef|#
directive|undef
name|WUNTRACED
end_undef

begin_undef
undef|#
directive|undef
name|WIFEXITED
end_undef

begin_undef
undef|#
directive|undef
name|WIFSIGNALED
end_undef

begin_undef
undef|#
directive|undef
name|WIFSTOPPED
end_undef

begin_undef
undef|#
directive|undef
name|WEXITSTATUS
end_undef

begin_undef
undef|#
directive|undef
name|WTERMSIG
end_undef

begin_undef
undef|#
directive|undef
name|WSTOPSIG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MAXION__ */
end_comment

begin_comment
comment|/* **  Harris Nighthawk PowerUX (nh6000 box) ** **  Contributed by Bob Miorelli, Pratt& Whitney<miorelli@pweh.com> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_PowerUX
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__svr4__
end_ifndef

begin_define
define|#
directive|define
name|__svr4__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __svr4__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/mail/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/etc/mail/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* has snprintf(3) and vsnprintf(3) */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_ZERO
end_define

begin_typedef
typedef|typedef
name|struct
name|msgb
name|mblk_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|offsetof
end_undef

begin_comment
comment|/* avoid stddefs.h and sys/sysmacros.h conflict */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PowerUX */
end_comment

begin_comment
comment|/* **  Siemens Nixdorf Informationssysteme AG SINIX ** **	Contributed by Gerald Rinske<Gerald.Rinske@mch.sni.de> **	of Siemens Business Services VAS. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sinix
end_ifdef

begin_define
define|#
directive|define
name|HASRANDOM
value|0
end_define

begin_comment
comment|/* has random(3) */
end_comment

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sinix */
end_comment

begin_comment
comment|/* **  CRAY T3E ** **	Contributed by Manu Mahonen<mailadm@csc.fi> **	of Center for Scientific Computing. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_CRAY
end_ifdef

begin_define
define|#
directive|define
name|GET_IPOPT_DST
parameter_list|(
name|dst
parameter_list|)
value|*(struct in_addr *)&(dst)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CRAY */
end_comment

begin_comment
comment|/* **  Motorola 922, MC88110, UNIX SYSTEM V/88 Release 4.0 Version 4.3 ** **	Contributed by Sergey Rusanov<rsm@utfoms.udmnet.ru> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MOTO
end_ifdef

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|0
end_define

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_define
define|#
directive|define
name|HASULIMIT
value|1
end_define

begin_define
define|#
directive|define
name|HASWAITPID
value|1
end_define

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|1
end_define

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|0
end_define

begin_define
define|#
directive|define
name|IDENTPROTO
value|0
end_define

begin_define
define|#
directive|define
name|RES_DNSRCH_VARIABLE
value|_res_dnsrch
end_define

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
end_define

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/etc/sendmail.cf"
end_define

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/var/run/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MOTO */
end_comment

begin_comment
comment|/********************************************************************** **  End of Per-Operating System defines **********************************************************************/
end_comment

begin_escape
end_escape

begin_comment
comment|/********************************************************************** **  More general defines **********************************************************************/
end_comment

begin_comment
comment|/* general BSD defines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|HASGETDTABLESIZE
value|1
end_define

begin_comment
comment|/* has getdtablesize(2) call */
end_comment

begin_define
define|#
directive|define
name|HASSETREUID
value|1
end_define

begin_comment
comment|/* has setreuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IP_SRCROUTE
end_ifndef

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|1
end_define

begin_comment
comment|/* can check IP source routing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IP_SRCROUTE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASSETRLIMIT
end_ifndef

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* has setrlimit(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASSETRLIMIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_define
define|#
directive|define
name|HASFLOCK
value|1
end_define

begin_comment
comment|/* has flock(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFLOCK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_TYPE
end_ifndef

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TM_ZONE
end_define

begin_comment
comment|/* use tm->tm_zone variable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! TZ_TYPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_comment
comment|/* general System V Release 4 defines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__svr4__
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM5
value|1
end_define

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASINITGROUPS
value|1
end_define

begin_comment
comment|/* has initgroups(3) call */
end_comment

begin_define
define|#
directive|define
name|BSD_COMP
value|1
end_define

begin_comment
comment|/* get BSD ioctl calls */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASSETRLIMIT
end_ifndef

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|1
end_define

begin_comment
comment|/* has setrlimit(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASSETRLIMIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASGETUSERSHELL
end_ifndef

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|0
end_define

begin_comment
comment|/* does not have getusershell(3) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFCHMOD
end_ifndef

begin_define
define|#
directive|define
name|HASFCHMOD
value|1
end_define

begin_comment
comment|/* most (all?) SVr4s seem to have fchmod(2) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFCHMOD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX
end_ifndef

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"/unix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_VENDOR_CF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_VENDOR_CF
value|"/usr/ucblib/sendmail.cf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_VENDOR_CF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAILPID
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAILPID
value|"/usr/ucblib/sendmail.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _PATH_SENDMAILPID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSLOG_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SYSLOG_BUFSIZE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SFS_TYPE
end_ifndef

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_STATVFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SFS_TYPE */
end_comment

begin_define
define|#
directive|define
name|USE_SIGLONGJMP
value|1
end_define

begin_comment
comment|/* sigsetjmp needed for signal handling */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __svr4__ */
end_comment

begin_comment
comment|/* general System V defines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSTEM5
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_define
define|#
directive|define
name|HASUNAME
value|1
end_define

begin_comment
comment|/* use System V uname(2) system call */
end_comment

begin_define
define|#
directive|define
name|SYS5SETPGRP
value|1
end_define

begin_comment
comment|/* use System V setpgrp(2) syscall */
end_comment

begin_define
define|#
directive|define
name|HASSETVBUF
value|1
end_define

begin_comment
comment|/* we have setvbuf(3) in libc */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASULIMIT
end_ifndef

begin_define
define|#
directive|define
name|HASULIMIT
value|1
end_define

begin_comment
comment|/* has the ulimit(2) syscall */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASULIMIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LA_TYPE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MIOC_READKSYM
end_ifdef

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_READKSYM
end_define

begin_comment
comment|/* use MIOC_READKSYM ioctl */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MIOC_READKSYM */
end_comment

begin_define
define|#
directive|define
name|LA_TYPE
value|LA_INT
end_define

begin_comment
comment|/* assume integer load average */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIOC_READKSYM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LA_TYPE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SFS_TYPE
end_ifndef

begin_define
define|#
directive|define
name|SFS_TYPE
value|SFS_USTAT
end_define

begin_comment
comment|/* use System V ustat(2) syscall */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SFS_TYPE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TZ_TYPE
end_ifndef

begin_define
define|#
directive|define
name|TZ_TYPE
value|TZ_TZNAME
end_define

begin_comment
comment|/* use tzname[] vector */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! TZ_TYPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSTEM5 */
end_comment

begin_comment
comment|/* general POSIX defines */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_VERSION
end_ifdef

begin_define
define|#
directive|define
name|HASSETSID
value|1
end_define

begin_comment
comment|/* has Posix setsid(2) call */
end_comment

begin_define
define|#
directive|define
name|HASWAITPID
value|1
end_define

begin_comment
comment|/* has Posix waitpid(2) call */
end_comment

begin_if
if|#
directive|if
name|_POSIX_VERSION
operator|>=
literal|199500
operator|&&
operator|!
name|defined
argument_list|(
name|USESETEUID
argument_list|)
end_if

begin_define
define|#
directive|define
name|USESETEUID
value|1
end_define

begin_comment
comment|/* has usable seteuid(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VERSION>= 199500&& !defined(USESETEUID) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_VERSION */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  Tweaking for systems that (for example) claim to be BSD or POSIX **  but don't have all the standard BSD or POSIX routines (boo hiss). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|titan
end_ifdef

begin_undef
undef|#
directive|undef
name|HASINITGROUPS
end_undef

begin_comment
comment|/* doesn't have initgroups(3) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* titan */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_CRAYCOM
end_ifdef

begin_undef
undef|#
directive|undef
name|HASSETSID
end_undef

begin_comment
comment|/* despite POSIX claim, doesn't have setsid */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CRAYCOM */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MOTO
end_ifdef

begin_undef
undef|#
directive|undef
name|USESETEUID
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MOTO */
end_comment

begin_comment
comment|/* **  Due to a "feature" in some operating systems such as Ultrix 4.3 and **  HPUX 8.0, if you receive a "No route to host" message (ICMP message **  ICMP_UNREACH_HOST) on _any_ connection, all connections to that host **  are closed.  Some firewalls return this error if you try to connect **  to the IDENT port (113), so you can't receive email from these hosts **  on these systems.  The firewall really should use a more specific **  message such as ICMP_UNREACH_PROTOCOL or _PORT or _FILTER_PROHIB.  If **  not explicitly set to zero above, default it on. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IDENTPROTO
end_ifndef

begin_define
define|#
directive|define
name|IDENTPROTO
value|1
end_define

begin_comment
comment|/* use IDENT proto (RFC 1413) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IDENTPROTO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IP_SRCROUTE
end_ifndef

begin_define
define|#
directive|define
name|IP_SRCROUTE
value|1
end_define

begin_comment
comment|/* Detect IP source routing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IP_SRCROUTE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASGETUSERSHELL
end_ifndef

begin_define
define|#
directive|define
name|HASGETUSERSHELL
value|1
end_define

begin_comment
comment|/* libc has getusershell(3) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASGETUSERSHELL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETUNIX
end_ifndef

begin_define
define|#
directive|define
name|NETUNIX
value|1
end_define

begin_comment
comment|/* include unix domain support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NETUNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASRANDOM
end_ifndef

begin_define
define|#
directive|define
name|HASRANDOM
value|1
end_define

begin_comment
comment|/* has random(3) support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASRANDOM */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFLOCK
end_ifndef

begin_define
define|#
directive|define
name|HASFLOCK
value|0
end_define

begin_comment
comment|/* assume no flock(2) support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFLOCK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASSETREUID
end_ifndef

begin_define
define|#
directive|define
name|HASSETREUID
value|0
end_define

begin_comment
comment|/* assume no setreuid(2) call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASSETREUID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASFCHMOD
end_ifndef

begin_define
define|#
directive|define
name|HASFCHMOD
value|0
end_define

begin_comment
comment|/* assume no fchmod(2) syscall */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASFCHMOD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USESETEUID
end_ifndef

begin_define
define|#
directive|define
name|USESETEUID
value|0
end_define

begin_comment
comment|/* assume no seteuid(2) call or no saved ids */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USESETEUID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASSETRLIMIT
end_ifndef

begin_define
define|#
directive|define
name|HASSETRLIMIT
value|0
end_define

begin_comment
comment|/* assume no setrlimit(2) support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASSETRLIMIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HASULIMIT
end_ifndef

begin_define
define|#
directive|define
name|HASULIMIT
value|0
end_define

begin_comment
comment|/* assume no ulimit(2) support */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HASULIMIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SECUREWARE
end_ifndef

begin_define
define|#
directive|define
name|SECUREWARE
value|0
end_define

begin_comment
comment|/* assume no SecureWare C2 auditing hooks */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SECUREWARE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_SIGLONGJMP
end_ifndef

begin_define
define|#
directive|define
name|USE_SIGLONGJMP
value|0
end_define

begin_comment
comment|/* assume setjmp handles signals properly */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USE_SIGLONGJMP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FDSET_CAST
end_ifndef

begin_define
define|#
directive|define
name|FDSET_CAST
end_define

begin_comment
comment|/* (empty) cast for fd_set arg to select */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! FDSET_CAST */
end_comment

begin_comment
comment|/* **  Pick a mailer setuid method for changing the current uid */
end_comment

begin_define
define|#
directive|define
name|USE_SETEUID
value|0
end_define

begin_define
define|#
directive|define
name|USE_SETREUID
value|1
end_define

begin_define
define|#
directive|define
name|USE_SETUID
value|2
end_define

begin_if
if|#
directive|if
name|USESETEUID
end_if

begin_define
define|#
directive|define
name|MAILER_SETUID_METHOD
value|USE_SETEUID
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USESETEUID */
end_comment

begin_if
if|#
directive|if
name|HASSETREUID
end_if

begin_define
define|#
directive|define
name|MAILER_SETUID_METHOD
value|USE_SETREUID
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HASSETREUID */
end_comment

begin_define
define|#
directive|define
name|MAILER_SETUID_METHOD
value|USE_SETUID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASSETREUID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USESETEUID */
end_comment

begin_comment
comment|/* **  If no type for argument two of getgroups call is defined, assume **  it's an integer -- unfortunately, there seem to be several choices **  here. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GIDSET_T
end_ifndef

begin_define
define|#
directive|define
name|GIDSET_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GIDSET_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UID_T
end_ifndef

begin_define
define|#
directive|define
name|UID_T
value|uid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! UID_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GID_T
end_ifndef

begin_define
define|#
directive|define
name|GID_T
value|gid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GID_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_T
end_ifndef

begin_define
define|#
directive|define
name|SIZE_T
value|size_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SIZE_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MODE_T
end_ifndef

begin_define
define|#
directive|define
name|MODE_T
value|mode_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MODE_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARGV_T
end_ifndef

begin_define
define|#
directive|define
name|ARGV_T
value|char **
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! ARGV_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOCKADDR_LEN_T
end_ifndef

begin_define
define|#
directive|define
name|SOCKADDR_LEN_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SOCKADDR_LEN_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOCKOPT_LEN_T
end_ifndef

begin_define
define|#
directive|define
name|SOCKOPT_LEN_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SOCKOPT_LEN_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUAD_T
end_ifndef

begin_define
define|#
directive|define
name|QUAD_T
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! QUAD_T */
end_comment

begin_escape
end_escape

begin_comment
comment|/********************************************************************** **  Remaining definitions should never have to be changed.  They are **  primarily to provide back compatibility for older systems -- for **  example, it includes some POSIX compatibility definitions **********************************************************************/
end_comment

begin_comment
comment|/* System 5 compatibility */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|foo
parameter_list|)
value|((foo& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_ISREG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|foo
parameter_list|)
value|((foo& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_ISDIR */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISLNK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFLNK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|foo
parameter_list|)
value|((foo& S_IFMT) == S_IFLNK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(S_ISLNK)&& defined(S_IFLNK) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISFIFO
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFIFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|foo
parameter_list|)
value|((foo& S_IFMT) == S_IFIFO)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(S_IFIFO) */
end_comment

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|foo
parameter_list|)
value|FALSE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(S_IFIFO) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(S_ISFIFO) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IRUSR
value|0400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IRUSR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IWUSR
value|0200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IWUSR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IRGRP
value|0040
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IRGRP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IWGRP
value|0020
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IWGRP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IROTH
end_ifndef

begin_define
define|#
directive|define
name|S_IROTH
value|0004
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IROTH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWOTH
end_ifndef

begin_define
define|#
directive|define
name|S_IWOTH
value|0002
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IWOTH */
end_comment

begin_comment
comment|/* close-on-exec flag */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FD_CLOEXEC
end_ifndef

begin_define
define|#
directive|define
name|FD_CLOEXEC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! FD_CLOEXEC */
end_comment

begin_comment
comment|/* **  Older systems don't have this error code -- it should be in **  /usr/include/sysexits.h. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EX_CONFIG
end_ifndef

begin_define
define|#
directive|define
name|EX_CONFIG
value|78
end_define

begin_comment
comment|/* configuration error */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! EX_CONFIG */
end_comment

begin_comment
comment|/* pseudo-codes */
end_comment

begin_define
define|#
directive|define
name|EX_QUIT
value|22
end_define

begin_comment
comment|/* drop out of server immediately */
end_comment

begin_define
define|#
directive|define
name|EX_RESTART
value|23
end_define

begin_comment
comment|/* restart sendmail daemon */
end_comment

begin_define
define|#
directive|define
name|EX_SHUTDOWN
value|24
end_define

begin_comment
comment|/* shutdown sendmail daemon */
end_comment

begin_comment
comment|/* pseudo-code used for mci_setstat */
end_comment

begin_define
define|#
directive|define
name|EX_NOTSTICKY
value|-5
end_define

begin_comment
comment|/* don't save persistent status */
end_comment

begin_comment
comment|/* **  An "impossible" file mode to indicate that the file does not exist. */
end_comment

begin_define
define|#
directive|define
name|ST_MODE_NOFILE
value|0171147
end_define

begin_comment
comment|/* unlikely to occur */
end_comment

begin_comment
comment|/* type of arbitrary pointer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARBPTR_T
end_ifndef

begin_define
define|#
directive|define
name|ARBPTR_T
value|void *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! ARBPTR_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_include
include|#
directive|include
file|"sendmail/cdefs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __P */
end_comment

begin_if
if|#
directive|if
name|HESIOD
operator|&&
operator|!
name|defined
argument_list|(
name|NAMED_BIND
argument_list|)
end_if

begin_define
define|#
directive|define
name|NAMED_BIND
value|1
end_define

begin_comment
comment|/* not one without the other */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HESIOD&& !defined(NAMED_BIND) */
end_comment

begin_if
if|#
directive|if
name|NAMED_BIND
operator|&&
operator|!
name|defined
argument_list|(
name|__ksr__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|h_errno
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|h_errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_BIND&& !defined( __ksr__ )&& !defined( h_errno ) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LDAPMAP
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<lber.h>
end_include

begin_include
include|#
directive|include
file|<ldap.h>
end_include

begin_comment
comment|/* Some LDAP constants */
end_comment

begin_define
define|#
directive|define
name|LDAPMAP_FALSE
value|0
end_define

begin_define
define|#
directive|define
name|LDAPMAP_TRUE
value|1
end_define

begin_comment
comment|/* **  ldap_init(3) is broken in Umich 3.x and OpenLDAP 1.0/1.1. **  Use the lack of LDAP_OPT_SIZELIMIT to detect old API implementations **  and assume (falsely) that all old API implementations are broken. **  (OpenLDAP 1.2 and later have a working ldap_init(), add -DUSE_LDAP_INIT) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LDAP_OPT_SIZELIMIT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_LDAP_INIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_LDAP_INIT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(LDAP_OPT_SIZELIMIT)&& !defined(USE_LDAP_INIT) */
end_comment

begin_comment
comment|/* **  LDAP_OPT_SIZELIMIT is not defined under Umich 3.x nor OpenLDAP 1.x, **  hence ldap_set_option() must not exist. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LDAP_OPT_SIZELIMIT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_LDAP_SET_OPTION
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_LDAP_SET_OPTION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(LDAP_OPT_SIZELIMIT)&& !defined(USE_LDAP_SET_OPTION) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDAPMAP */
end_comment

begin_comment
comment|/* **  Do some required dependencies */
end_comment

begin_if
if|#
directive|if
name|NETINET
operator|||
name|NETINET6
operator|||
name|NETISO
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|SMTP
end_ifndef

begin_define
define|#
directive|define
name|SMTP
value|1
end_define

begin_comment
comment|/* enable user and server SMTP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SMTP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUEUE
end_ifndef

begin_define
define|#
directive|define
name|QUEUE
value|1
end_define

begin_comment
comment|/* enable queueing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! QUEUE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DAEMON
end_ifndef

begin_define
define|#
directive|define
name|DAEMON
value|1
end_define

begin_comment
comment|/* include the daemon (requires IPC& SMTP) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! DAEMON */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETINET || NETINET6 || NETISO */
end_comment

begin_comment
comment|/* **  Arrange to use either varargs or stdargs */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_define
define|#
directive|define
name|VA_LOCAL_DECL
value|va_list ap;
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|f
parameter_list|)
value|va_start(ap, f)
end_define

begin_define
define|#
directive|define
name|VA_END
value|va_end(ap)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_define
define|#
directive|define
name|VA_LOCAL_DECL
value|va_list ap;
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|f
parameter_list|)
value|va_start(ap)
end_define

begin_define
define|#
directive|define
name|VA_END
value|va_end(ap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_if
if|#
directive|if
name|HASUNAME
end_if

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|newstr
end_ifdef

begin_undef
undef|#
directive|undef
name|newstr
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* newstr */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HASUNAME */
end_comment

begin_define
define|#
directive|define
name|NODE_LENGTH
value|32
end_define

begin_struct
struct|struct
name|utsname
block|{
name|char
name|nodename
index|[
name|NODE_LENGTH
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASUNAME */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAXHOSTNAMELEN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_SCO_unix_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NonStop_UX_BXX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ALTOS_SYSTEM_V
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(MAXHOSTNAMELEN)&& !defined(_SCO_unix_)&& !defined(NonStop_UX_BXX)&& !defined(ALTOS_SYSTEM_V) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIGCHLD
argument_list|)
operator|&&
name|defined
argument_list|(
name|SIGCLD
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGCHLD
value|SIGCLD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(SIGCHLD)&& defined(SIGCLD) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDIN_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! STDIN_FILENO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDOUT_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! STDOUT_FILENO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDERR_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! STDERR_FILENO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_SH
end_ifndef

begin_define
define|#
directive|define
name|LOCK_SH
value|0x01
end_define

begin_comment
comment|/* shared lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_EX
value|0x02
end_define

begin_comment
comment|/* exclusive lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_NB
value|0x04
end_define

begin_comment
comment|/* non-blocking lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_UN
value|0x08
end_define

begin_comment
comment|/* unlock */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LOCK_SH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXOTH
end_ifndef

begin_define
define|#
directive|define
name|S_IXOTH
value|(S_IEXEC>> 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IXOTH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IXGRP
value|(S_IEXEC>> 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IXGRP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IXUSR
value|(S_IEXEC)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_IXUSR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SEEK_SET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIG_ERR
end_ifndef

begin_define
define|#
directive|define
name|SIG_ERR
value|((void (*)()) -1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SIG_ERR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WEXITSTATUS
end_ifndef

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|st
parameter_list|)
value|(((st)>> 8)& 0377)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! WEXITSTATUS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIFEXITED
end_ifndef

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|st
parameter_list|)
value|(((st)& 0377) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! WIFEXITED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIFSTOPPED
end_ifndef

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|st
parameter_list|)
value|(((st)& 0100) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! WIFSTOPPED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WCOREDUMP
end_ifndef

begin_define
define|#
directive|define
name|WCOREDUMP
parameter_list|(
name|st
parameter_list|)
value|(((st)& 0200) != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! WCOREDUMP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WTERMSIG
end_ifndef

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|st
parameter_list|)
value|(((st)& 0177))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! WTERMSIG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGFUNC_DEFINED
end_ifndef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*sigfunc_t
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SIGFUNC_DEFINED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGFUNC_RETURN
end_ifndef

begin_define
define|#
directive|define
name|SIGFUNC_RETURN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SIGFUNC_RETURN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGFUNC_DECL
end_ifndef

begin_define
define|#
directive|define
name|SIGFUNC_DECL
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SIGFUNC_DECL */
end_comment

begin_comment
comment|/* size of syslog buffer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSLOG_BUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|SYSLOG_BUFSIZE
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SYSLOG_BUFSIZE */
end_comment

begin_comment
comment|/* **  Size of prescan buffer. **	Despite comments in the _sendmail_ book, this probably should **	not be changed; there are some hard-to-define dependencies. */
end_comment

begin_define
define|#
directive|define
name|PSBUFSIZE
value|(MAXNAME + MAXATOM)
end_define

begin_comment
comment|/* size of prescan buffer */
end_comment

begin_comment
comment|/* fork routine -- set above using #ifdef _osname_ or in Makefile */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FORK
end_ifndef

begin_define
define|#
directive|define
name|FORK
value|fork
end_define

begin_comment
comment|/* function to call to fork mailer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! FORK */
end_comment

begin_comment
comment|/* random routine -- set above using #ifdef _osname_ or in Makefile */
end_comment

begin_if
if|#
directive|if
name|HASRANDOM
end_if

begin_define
define|#
directive|define
name|get_random
parameter_list|()
value|random()
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HASRANDOM */
end_comment

begin_define
define|#
directive|define
name|get_random
parameter_list|()
value|((long) rand())
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|RANDOMSHIFT
end_ifndef

begin_define
define|#
directive|define
name|RANDOMSHIFT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RANDOMSHIFT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASRANDOM */
end_comment

begin_comment
comment|/* **  Default to using scanf in readcf. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCANF
end_ifndef

begin_define
define|#
directive|define
name|SCANF
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SCANF */
end_comment

begin_if
if|#
directive|if
name|_FFR_MILTER
end_if

begin_comment
comment|/* 32 bit type */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_INT32
end_ifndef

begin_define
define|#
directive|define
name|SM_INT32
value|int32_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_INT32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_MILTER */
end_comment

begin_comment
comment|/* **  SVr4 and similar systems use different routines for setjmp/longjmp **  with signal support */
end_comment

begin_if
if|#
directive|if
name|USE_SIGLONGJMP
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|jmp_buf
end_ifdef

begin_undef
undef|#
directive|undef
name|jmp_buf
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* jmp_buf */
end_comment

begin_define
define|#
directive|define
name|jmp_buf
value|sigjmp_buf
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|setjmp
end_ifdef

begin_undef
undef|#
directive|undef
name|setjmp
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* setjmp */
end_comment

begin_define
define|#
directive|define
name|setjmp
parameter_list|(
name|env
parameter_list|)
value|sigsetjmp(env, 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|longjmp
end_ifdef

begin_undef
undef|#
directive|undef
name|longjmp
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* longjmp */
end_comment

begin_define
define|#
directive|define
name|longjmp
parameter_list|(
name|env
parameter_list|,
name|val
parameter_list|)
value|siglongjmp(env, val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_SIGLONGJMP */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NGROUPS_MAX
argument_list|)
operator|&&
name|defined
argument_list|(
name|NGROUPS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NGROUPS_MAX
value|NGROUPS
end_define

begin_comment
comment|/* POSIX naming convention */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NGROUPS_MAX)&& defined(NGROUPS) */
end_comment

begin_comment
comment|/* **  Some snprintf() implementations are rumored not to NUL terminate. */
end_comment

begin_if
if|#
directive|if
name|SNPRINTF_IS_BROKEN
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|snprintf
end_ifdef

begin_undef
undef|#
directive|undef
name|snprintf
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* snprintf */
end_comment

begin_define
define|#
directive|define
name|snprintf
value|sm_snprintf
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|vsnprintf
end_ifdef

begin_undef
undef|#
directive|undef
name|vsnprintf
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vsnprintf */
end_comment

begin_define
define|#
directive|define
name|vsnprintf
value|sm_vsnprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SNPRINTF_IS_BROKEN */
end_comment

begin_comment
comment|/* **  If we don't have a system syslog, simulate it. */
end_comment

begin_if
if|#
directive|if
operator|!
name|LOG
end_if

begin_define
define|#
directive|define
name|LOG_EMERG
value|0
end_define

begin_comment
comment|/* system is unusable */
end_comment

begin_define
define|#
directive|define
name|LOG_ALERT
value|1
end_define

begin_comment
comment|/* action must be taken immediately */
end_comment

begin_define
define|#
directive|define
name|LOG_CRIT
value|2
end_define

begin_comment
comment|/* critical conditions */
end_comment

begin_define
define|#
directive|define
name|LOG_ERR
value|3
end_define

begin_comment
comment|/* error conditions */
end_comment

begin_define
define|#
directive|define
name|LOG_WARNING
value|4
end_define

begin_comment
comment|/* warning conditions */
end_comment

begin_define
define|#
directive|define
name|LOG_NOTICE
value|5
end_define

begin_comment
comment|/* normal but significant condition */
end_comment

begin_define
define|#
directive|define
name|LOG_INFO
value|6
end_define

begin_comment
comment|/* informational */
end_comment

begin_define
define|#
directive|define
name|LOG_DEBUG
value|7
end_define

begin_comment
comment|/* debug-level messages */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOG */
end_comment

begin_if
if|#
directive|if
name|SFIO
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|ERRLIST_PREDEFINED
end_ifdef

begin_undef
undef|#
directive|undef
name|ERRLIST_PREDEFINED
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ERRLIST_PREDEFINED */
end_comment

begin_if
if|#
directive|if
operator|!
name|HASSNPRINTF
end_if

begin_define
define|#
directive|define
name|HASSNPRINTF
value|1
end_define

begin_comment
comment|/* sfio includes snprintf() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HASSNPRINTF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SFIO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SFIO_STDIO_COMPAT
end_ifndef

begin_define
define|#
directive|define
name|SFIO_STDIO_COMPAT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SFIO_STDIO_COMPAT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONF_H */
end_comment

end_unit

