begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2002 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1983, 1995-1997 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: conf.h,v 8.574 2006/11/29 00:36:06 ca Exp $  *  *	$FreeBSD$  *  */
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
comment|/********************************************************************** **  Table sizes, etc.... **	There shouldn't be much need to change these.... **	If you do, be careful, none should be set anywhere near INT_MAX **********************************************************************/
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

begin_if
if|#
directive|if
name|SASL
end_if

begin_define
define|#
directive|define
name|MAXINPLINE
value|12288
end_define

begin_comment
comment|/* max input line length (for AUTH) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SASL */
end_comment

begin_define
define|#
directive|define
name|MAXINPLINE
value|MAXLINE
end_define

begin_comment
comment|/* max input line length */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SASL */
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

begin_ifndef
ifndef|#
directive|ifndef
name|MAXAUTHINFO
end_ifndef

begin_define
define|#
directive|define
name|MAXAUTHINFO
value|100
end_define

begin_comment
comment|/* max length of authinfo token */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MAXAUTHINFO */
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
comment|/* max SMTP line length */
end_comment

begin_define
define|#
directive|define
name|MAXUDBKEY
value|128
end_define

begin_comment
comment|/* max size of a database key (udb only) */
end_comment

begin_define
define|#
directive|define
name|MAXKEY
value|1024
end_define

begin_comment
comment|/* max size of a database key */
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
name|MAXMAPSTACK
value|12
end_define

begin_comment
comment|/* max # of stacked or sequenced maps */
end_comment

begin_if
if|#
directive|if
name|MILTER
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
comment|/* MILTER */
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

begin_ifndef
ifndef|#
directive|ifndef
name|MAXNOOPCOMMANDS
end_ifndef

begin_define
define|#
directive|define
name|MAXNOOPCOMMANDS
value|20
end_define

begin_comment
comment|/* max "noise" commands before slowdown */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MAXNOOPCOMMANDS */
end_comment

begin_comment
comment|/* **  MAXQFNAME == 2 (size of "qf", "df" prefix) **	+ 8 (base 60 encoded date, time& sequence number) **	+ 10 (base 10 encoded 32 bit process id) **	+ 1 (terminating NUL character). */
end_comment

begin_define
define|#
directive|define
name|MAXQFNAME
value|21
end_define

begin_comment
comment|/* max qf file name length + 1 */
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

begin_comment
comment|/* Must match (BITMAPBITS - 1) */
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
comment|/* how often to check DATA progress */
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

begin_define
define|#
directive|define
name|DEFAULT_MAX_RCPT
value|100
end_define

begin_comment
comment|/* max number of RCPTs per envelope */
end_comment

begin_define
define|#
directive|define
name|MAXQUEUEGROUPS
value|50
end_define

begin_comment
comment|/* max # of queue groups */
end_comment

begin_comment
comment|/* must be less than BITMAPBITS for DoQueueRun */
end_comment

begin_define
define|#
directive|define
name|MAXWORKGROUPS
value|50
end_define

begin_comment
comment|/* max # of work groups */
end_comment

begin_define
define|#
directive|define
name|MAXFILESYS
value|BITMAPBITS
end_define

begin_comment
comment|/* max # of queue file systems 					 * must be<= BITMAPBITS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILESYS_UPDATE_INTERVAL
end_ifndef

begin_define
define|#
directive|define
name|FILESYS_UPDATE_INTERVAL
value|300
end_define

begin_comment
comment|/* how often to update FileSys table */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FILESYS_UPDATE_INTERVAL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_DEFAULT_TTL
end_ifndef

begin_define
define|#
directive|define
name|SM_DEFAULT_TTL
value|3600
end_define

begin_comment
comment|/* default TTL for services that don't have one */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_DEFAULT_TTL */
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
comment|/* STARTTLS */
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
comment|/* STARTTLS */
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

begin_comment
comment|/* **  Default database permissions (alias, maps, etc.) **	Used by sendmail and libsmdb */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DBMMODE
end_ifndef

begin_define
define|#
directive|define
name|DBMMODE
value|0640
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! DBMMODE */
end_comment

begin_comment
comment|/* **  Value which means a uid or gid value should not change */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_UID
end_ifndef

begin_define
define|#
directive|define
name|NO_UID
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NO_UID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_GID
end_ifndef

begin_define
define|#
directive|define
name|NO_GID
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NO_GID */
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

begin_if
if|#
directive|if
name|NAMED_BIND
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|DNSMAP
end_ifndef

begin_define
define|#
directive|define
name|DNSMAP
value|1
end_define

begin_comment
comment|/* DNS map type */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! DNSMAP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_BIND */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PIPELINING
end_ifndef

begin_define
define|#
directive|define
name|PIPELINING
value|1
end_define

begin_comment
comment|/* SMTP PIPELINING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PIPELINING */
end_comment

begin_comment
comment|/********************************************************************** **  End of site-specific configuration. **********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<sm/conf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! CONF_H */
end_comment

end_unit

