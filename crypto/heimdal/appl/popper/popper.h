begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  * static char copyright[] = "Copyright (c) 1990 Regents of the University of California.\nAll rights reserved.\n";  * static char SccsId[] = "@(#)@(#)popper.h	2.2  2.2 4/2/91";  *  */
end_comment

begin_comment
comment|/* $Id: popper.h,v 1.50 2001/09/10 11:56:34 joda Exp $ */
end_comment

begin_comment
comment|/*   *  Header file for the POP programs  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_define
define|#
directive|define
name|UIDL
end_define

begin_define
define|#
directive|define
name|XOVER
end_define

begin_define
define|#
directive|define
name|XDELE
end_define

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_define
define|#
directive|define
name|RETURN_PATH_HANDLING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Common include files */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PWD_H
end_ifdef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_IO_H
end_ifdef

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STAT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TIME_WITH_SYS_TIME
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SYS_TIME_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_RESOURCE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_WAIT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN6_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET6_IN6_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet6/in6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETDB_H
end_ifdef

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_INET_H
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_struct_decl
struct_decl|struct
name|sockaddr_dl
struct_decl|;
end_struct_decl

begin_comment
comment|/* AIX fun */
end_comment

begin_struct_decl
struct_decl|struct
name|ether_addr
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYSLOG_H
end_ifdef

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SELECT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SOCKS
end_ifdef

begin_include
include|#
directive|include
file|<socks.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_include
include|#
directive|include
file|<getarg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KRB4
end_ifdef

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<prot.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5
end_ifdef

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXUSERNAMELEN
value|65
end_define

begin_define
define|#
directive|define
name|MAXLINELEN
value|1024
end_define

begin_define
define|#
directive|define
name|MAXMSGLINELEN
value|1024
end_define

begin_define
define|#
directive|define
name|MAXCMDLEN
value|4
end_define

begin_define
define|#
directive|define
name|MAXPARMCOUNT
value|10
end_define

begin_define
define|#
directive|define
name|MAXPARMLEN
value|10
end_define

begin_define
define|#
directive|define
name|ALLOC_MSGS
value|20
end_define

begin_define
define|#
directive|define
name|MAIL_COMMAND
value|"/usr/lib/sendmail"
end_define

begin_define
define|#
directive|define
name|POP_FACILITY
value|LOG_LOCAL0
end_define

begin_define
define|#
directive|define
name|POP_PRIORITY
value|LOG_NOTICE
end_define

begin_define
define|#
directive|define
name|POP_DEBUG
value|LOG_DEBUG
end_define

begin_define
define|#
directive|define
name|POP_INFO
value|LOG_INFO
end_define

begin_define
define|#
directive|define
name|POP_LOGOPTS
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PATHS_H
end_ifdef

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MAILLOCK_H
end_ifdef

begin_include
include|#
directive|include
file|<maillock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OTP
end_ifdef

begin_include
include|#
directive|include
file|<otp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KRB4_MAILDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|POP_MAILDIR
value|KRB4_MAILDIR
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_PATH_MAILDIR
argument_list|)
end_elif

begin_define
define|#
directive|define
name|POP_MAILDIR
value|_PATH_MAILDIR
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MAILDIR
argument_list|)
end_elif

begin_define
define|#
directive|define
name|POP_MAILDIR
value|MAILDIR
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|POP_MAILDIR
value|"/usr/spool/mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|POP_DROP
value|POP_MAILDIR "/.%s.pop"
end_define

begin_comment
comment|/* POP_TMPSIZE needs to be big enough to hold the string 	 * defined by POP_TMPDROP.  POP_DROP and POP_TMPDROP 	 * must be in the same filesystem. 	 */
end_comment

begin_define
define|#
directive|define
name|POP_TMPDROP
value|POP_MAILDIR "/tmpXXXXXX"
end_define

begin_define
define|#
directive|define
name|POP_TMPSIZE
value|256
end_define

begin_define
define|#
directive|define
name|POP_TMPXMIT
value|"/tmp/xmitXXXXXX"
end_define

begin_define
define|#
directive|define
name|POP_OK
value|"+OK"
end_define

begin_define
define|#
directive|define
name|POP_ERR
value|"-ERR"
end_define

begin_define
define|#
directive|define
name|POP_SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|POP_FAILURE
value|0
end_define

begin_define
define|#
directive|define
name|POP_TERMINATE
value|'.'
end_define

begin_define
define|#
directive|define
name|POP_TIMEOUT
value|120
end_define

begin_comment
comment|/* timeout connection after this many secs */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pop_timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hangup
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AUTH_NONE
value|0
end_define

begin_define
define|#
directive|define
name|AUTH_OTP
value|1
end_define

begin_define
define|#
directive|define
name|pop_command
value|pop_parm[0]
end_define

begin_comment
comment|/*  POP command is first token */
end_comment

begin_define
define|#
directive|define
name|pop_subcommand
value|pop_parm[1]
end_define

begin_comment
comment|/*  POP XTND subcommand is the                                                  second token */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/*  POP processing states */
name|auth1
block|,
comment|/*  Authorization: waiting for                                                  USER command */
name|auth2
block|,
comment|/*  Authorization: waiting for                                                  PASS command */
name|trans
block|,
comment|/*  Transaction */
name|update
block|,
comment|/*  Update:  session ended,                                                  process maildrop changes */
name|halt
block|,
comment|/*  (Halt):  stop processing                                                  and exit */
name|error
comment|/*  (Error): something really                                                  bad happened */
block|}
name|state
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEL_FLAG
value|1
end_define

begin_define
define|#
directive|define
name|RETR_FLAG
value|2
end_define

begin_define
define|#
directive|define
name|NEW_FLAG
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/*  Message information */
name|int
name|number
decl_stmt|;
comment|/*  Message number relative to                                                      the beginning of list */
name|long
name|length
decl_stmt|;
comment|/*  Length of message in                                                      bytes */
name|int
name|lines
decl_stmt|;
comment|/*  Number of (null-terminated)                                                     lines in the message */
name|long
name|offset
decl_stmt|;
comment|/*  Offset from beginning of                                                      file */
name|unsigned
name|flags
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|UIDL
argument_list|)
operator|||
name|defined
argument_list|(
name|XOVER
argument_list|)
name|char
modifier|*
name|msg_id
decl_stmt|;
comment|/*  The POP UIDL uniqueifier */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XOVER
name|char
modifier|*
name|subject
decl_stmt|;
name|char
modifier|*
name|from
decl_stmt|;
name|char
modifier|*
name|date
decl_stmt|;
endif|#
directive|endif
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|MsgInfoList
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IS_MAILDIR
parameter_list|(
name|P
parameter_list|)
value|((P)->temp_drop[0] == '\0')
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/*  POP parameter block */
name|int
name|debug
decl_stmt|;
comment|/*  Debugging requested */
name|char
modifier|*
name|myname
decl_stmt|;
comment|/*  The name of this POP                                                      daemon program */
name|char
name|myhost
index|[
name|MaxHostNameLen
index|]
decl_stmt|;
comment|/*  The name of our host                                                      computer */
name|char
name|client
index|[
name|MaxHostNameLen
index|]
decl_stmt|;
comment|/*  Canonical name of client                                                      computer */
name|char
name|ipaddr
index|[
name|MaxHostNameLen
index|]
decl_stmt|;
comment|/*  Dotted-notation format of                                                      client IP address */
name|unsigned
name|short
name|ipport
decl_stmt|;
comment|/*  Client port for privileged                                                      operations */
name|char
name|user
index|[
name|MAXUSERNAMELEN
index|]
decl_stmt|;
comment|/*  Name of the POP user */
name|state
name|CurrentState
decl_stmt|;
comment|/*  The current POP operational                                                     state */
name|MsgInfoList
modifier|*
name|mlp
decl_stmt|;
comment|/*  Message information list */
name|int
name|msg_count
decl_stmt|;
comment|/*  Number of messages in                                                      the maildrop */
name|int
name|msgs_deleted
decl_stmt|;
comment|/*  Number of messages flagged                                                      for deletion */
name|int
name|last_msg
decl_stmt|;
comment|/*  Last message touched by                                                      the user */
name|long
name|bytes_deleted
decl_stmt|;
comment|/*  Number of maildrop bytes                                                      flagged for deletion */
name|char
name|drop_name
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/*  The name of the user's                                                      maildrop */
name|char
name|temp_drop
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/*  The name of the user's                                                      temporary maildrop */
name|long
name|drop_size
decl_stmt|;
comment|/*  Size of the maildrop in                                                     bytes */
name|FILE
modifier|*
name|drop
decl_stmt|;
comment|/*  (Temporary) mail drop */
name|FILE
modifier|*
name|input
decl_stmt|;
comment|/*  Input TCP/IP communication                                                      stream */
name|FILE
modifier|*
name|output
decl_stmt|;
comment|/*  Output TCP/IP communication                                                     stream */
name|FILE
modifier|*
name|trace
decl_stmt|;
comment|/*  Debugging trace file */
name|char
modifier|*
name|pop_parm
index|[
name|MAXPARMCOUNT
index|]
decl_stmt|;
comment|/*  Parse POP parameter list */
name|int
name|parm_count
decl_stmt|;
comment|/*  Number of parameters in                                                      parsed list */
name|int
name|kerberosp
decl_stmt|;
comment|/*  Using KPOP? */
ifdef|#
directive|ifdef
name|KRB4
name|AUTH_DAT
name|kdata
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|KRB5
name|krb5_context
name|context
decl_stmt|;
name|krb5_principal
name|principal
decl_stmt|;
comment|/*  principal auth as */
name|krb5_log_facility
modifier|*
name|logf
decl_stmt|;
endif|#
directive|endif
name|int
name|version
decl_stmt|;
comment|/*  4 or 5? */
name|int
name|auth_level
decl_stmt|;
comment|/*  Dont allow cleartext */
ifdef|#
directive|ifdef
name|OTP
name|OtpContext
name|otp_ctx
decl_stmt|;
comment|/*  OTP context */
endif|#
directive|endif
block|}
name|POP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/*  State information for                                                      each POP command */
name|state
name|ValidCurrentState
decl_stmt|;
comment|/*  The operating state of                                                      the command */
name|char
modifier|*
name|command
decl_stmt|;
comment|/*  The POP command */
name|int
name|min_parms
decl_stmt|;
comment|/*  Minimum number of parms                                                      for the command */
name|int
name|max_parms
decl_stmt|;
comment|/*  Maximum number of parms                                                      for the command */
name|int
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|()
function_decl|;
comment|/*  The function that process                                                      the command */
name|state
name|result
index|[
literal|2
index|]
decl_stmt|;
comment|/*  The resulting state after                                                      command processing */
define|#
directive|define
name|success_state
value|result[0]
comment|/*  State when a command                                                      succeeds */
block|}
name|state_table
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/*  Table of extensions */
name|char
modifier|*
name|subcommand
decl_stmt|;
comment|/*  The POP XTND subcommand */
name|int
name|min_parms
decl_stmt|;
comment|/*  Minimum number of parms for                                                     the subcommand */
name|int
name|max_parms
decl_stmt|;
comment|/*  Maximum number of parms for                                                     the subcommand */
name|int
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|()
function_decl|;
comment|/*  The function that processes                                                      the subcommand */
block|}
name|xtnd_table
typedef|;
end_typedef

begin_function_decl
name|int
name|pop_dele
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_dropcopy
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|,
name|struct
name|passwd
modifier|*
name|pwp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_dropinfo
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_init
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|,
name|int
name|argcount
parameter_list|,
name|char
modifier|*
modifier|*
name|argmessage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_last
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_list
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_parse
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_pass
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_quit
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_rset
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_send
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_stat
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_updt
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_user
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|UIDL
end_ifdef

begin_function_decl
name|int
name|pop_uidl
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XOVER
end_ifdef

begin_function_decl
name|int
name|pop_xover
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XDELE
end_ifdef

begin_function_decl
name|int
name|pop_xdele
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|pop_help
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|state_table
modifier|*
name|pop_get_command
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|,
name|char
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pop_lower
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_log
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|,
name|int
name|stat
parameter_list|,
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
ifdef|#
directive|ifdef
name|__GNUC__
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|pop_msg
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|,
name|int
name|stat
parameter_list|,
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
ifdef|#
directive|ifdef
name|__GNUC__
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_endif
unit|)))
endif|#
directive|endif
end_endif

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|pop_maildir_info
parameter_list|(
name|POP
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_maildir_open
parameter_list|(
name|POP
modifier|*
parameter_list|,
name|MsgInfoList
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pop_maildir_update
parameter_list|(
name|POP
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|changeuser
parameter_list|(
name|POP
modifier|*
parameter_list|,
name|struct
name|passwd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parse_header
parameter_list|(
name|MsgInfoList
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|add_missing_headers
parameter_list|(
name|POP
modifier|*
parameter_list|,
name|MsgInfoList
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

