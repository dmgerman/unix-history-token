begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 James Gritton.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/jail.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<jail.h>
end_include

begin_define
define|#
directive|define
name|CONF_FILE
value|"/etc/jail.conf"
end_define

begin_define
define|#
directive|define
name|DEP_FROM
value|0
end_define

begin_define
define|#
directive|define
name|DEP_TO
value|1
end_define

begin_define
define|#
directive|define
name|DF_SEEN
value|0x01
end_define

begin_comment
comment|/* Dependency has been followed */
end_comment

begin_define
define|#
directive|define
name|DF_LIGHT
value|0x02
end_define

begin_comment
comment|/* Implied dependency on jail existence only */
end_comment

begin_define
define|#
directive|define
name|DF_NOFAIL
value|0x04
end_define

begin_comment
comment|/* Don't propigate failed jails */
end_comment

begin_define
define|#
directive|define
name|PF_VAR
value|0x01
end_define

begin_comment
comment|/* This is a variable, not a true parameter */
end_comment

begin_define
define|#
directive|define
name|PF_APPEND
value|0x02
end_define

begin_comment
comment|/* Append to existing parameter list */
end_comment

begin_define
define|#
directive|define
name|PF_BAD
value|0x04
end_define

begin_comment
comment|/* Unable to resolve parameter value */
end_comment

begin_define
define|#
directive|define
name|PF_INTERNAL
value|0x08
end_define

begin_comment
comment|/* Internal parameter, not passed to kernel */
end_comment

begin_define
define|#
directive|define
name|PF_BOOL
value|0x10
end_define

begin_comment
comment|/* Boolean parameter */
end_comment

begin_define
define|#
directive|define
name|PF_INT
value|0x20
end_define

begin_comment
comment|/* Integer parameter */
end_comment

begin_define
define|#
directive|define
name|PF_CONV
value|0x40
end_define

begin_comment
comment|/* Parameter duplicated in converted form */
end_comment

begin_define
define|#
directive|define
name|PF_REV
value|0x80
end_define

begin_comment
comment|/* Run commands in reverse order on stopping */
end_comment

begin_define
define|#
directive|define
name|JF_START
value|0x0001
end_define

begin_comment
comment|/* -c */
end_comment

begin_define
define|#
directive|define
name|JF_SET
value|0x0002
end_define

begin_comment
comment|/* -m */
end_comment

begin_define
define|#
directive|define
name|JF_STOP
value|0x0004
end_define

begin_comment
comment|/* -r */
end_comment

begin_define
define|#
directive|define
name|JF_DEPEND
value|0x0008
end_define

begin_comment
comment|/* Operation required by dependency */
end_comment

begin_define
define|#
directive|define
name|JF_WILD
value|0x0010
end_define

begin_comment
comment|/* Not specified on the command line */
end_comment

begin_define
define|#
directive|define
name|JF_FAILED
value|0x0020
end_define

begin_comment
comment|/* Operation failed */
end_comment

begin_define
define|#
directive|define
name|JF_PARAMS
value|0x0040
end_define

begin_comment
comment|/* Parameters checked and imported */
end_comment

begin_define
define|#
directive|define
name|JF_RDTUN
value|0x0080
end_define

begin_comment
comment|/* Create-only parameter check has been done */
end_comment

begin_define
define|#
directive|define
name|JF_PERSIST
value|0x0100
end_define

begin_comment
comment|/* Jail is temporarily persistent */
end_comment

begin_define
define|#
directive|define
name|JF_TIMEOUT
value|0x0200
end_define

begin_comment
comment|/* A command (or process kill) timed out */
end_comment

begin_define
define|#
directive|define
name|JF_SLEEPQ
value|0x0400
end_define

begin_comment
comment|/* Waiting on a command and/or timeout */
end_comment

begin_define
define|#
directive|define
name|JF_OP_MASK
value|(JF_START | JF_SET | JF_STOP)
end_define

begin_define
define|#
directive|define
name|JF_RESTART
value|(JF_START | JF_STOP)
end_define

begin_define
define|#
directive|define
name|JF_START_SET
value|(JF_START | JF_SET)
end_define

begin_define
define|#
directive|define
name|JF_SET_RESTART
value|(JF_SET | JF_STOP)
end_define

begin_define
define|#
directive|define
name|JF_START_SET_RESTART
value|(JF_START | JF_SET | JF_STOP)
end_define

begin_define
define|#
directive|define
name|JF_DO_STOP
parameter_list|(
name|js
parameter_list|)
value|(((js)& (JF_SET | JF_STOP)) == JF_STOP)
end_define

begin_enum
enum|enum
name|intparam
block|{
name|IP__NULL
init|=
literal|0
block|,
comment|/* Null command */
name|IP_ALLOW_DYING
block|,
comment|/* Allow making changes to a dying jail */
name|IP_COMMAND
block|,
comment|/* Command run inside jail at creation */
name|IP_DEPEND
block|,
comment|/* Jail starts after (stops before) another */
name|IP_EXEC_CLEAN
block|,
comment|/* Run commands in a clean environment */
name|IP_EXEC_CONSOLELOG
block|,
comment|/* Redirect optput for commands run in jail */
name|IP_EXEC_FIB
block|,
comment|/* Run jailed commands with this FIB */
name|IP_EXEC_JAIL_USER
block|,
comment|/* Run jailed commands as this user */
name|IP_EXEC_POSTSTART
block|,
comment|/* Commands run outside jail after creating */
name|IP_EXEC_POSTSTOP
block|,
comment|/* Commands run outside jail after removing */
name|IP_EXEC_PRESTART
block|,
comment|/* Commands run outside jail before creating */
name|IP_EXEC_PRESTOP
block|,
comment|/* Commands run outside jail before removing */
name|IP_EXEC_START
block|,
comment|/* Commands run inside jail on creation */
name|IP_EXEC_STOP
block|,
comment|/* Commands run inside jail on removal */
name|IP_EXEC_SYSTEM_JAIL_USER
block|,
comment|/* Get jail_user from system passwd file */
name|IP_EXEC_SYSTEM_USER
block|,
comment|/* Run non-jailed commands as this user */
name|IP_EXEC_TIMEOUT
block|,
comment|/* Time to wait for a command to complete */
if|#
directive|if
name|defined
argument_list|(
name|INET
argument_list|)
operator|||
name|defined
argument_list|(
name|INET6
argument_list|)
name|IP_INTERFACE
block|,
comment|/* Add IP addresses to this interface */
name|IP_IP_HOSTNAME
block|,
comment|/* Get jail IP address(es) from hostname */
endif|#
directive|endif
name|IP_MOUNT
block|,
comment|/* Mount points in fstab(5) form */
name|IP_MOUNT_DEVFS
block|,
comment|/* Mount /dev under prison root */
name|IP_MOUNT_FDESCFS
block|,
comment|/* Mount /dev/fd under prison root */
name|IP_MOUNT_FSTAB
block|,
comment|/* A standard fstab(5) file */
name|IP_STOP_TIMEOUT
block|,
comment|/* Time to wait after sending SIGTERM */
name|IP_VNET_INTERFACE
block|,
comment|/* Assign interface(s) to vnet jail */
ifdef|#
directive|ifdef
name|INET
name|IP__IP4_IFADDR
block|,
comment|/* Copy of ip4.addr with interface/netmask */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|INET6
name|IP__IP6_IFADDR
block|,
comment|/* Copy of ip6.addr with interface/prefixlen */
endif|#
directive|endif
name|IP__MOUNT_FROM_FSTAB
block|,
comment|/* Line from mount.fstab file */
name|IP__OP
block|,
comment|/* Placeholder for requested operation */
name|KP_ALLOW_CHFLAGS
block|,
name|KP_ALLOW_MOUNT
block|,
name|KP_ALLOW_RAW_SOCKETS
block|,
name|KP_ALLOW_SET_HOSTNAME
block|,
name|KP_ALLOW_SOCKET_AF
block|,
name|KP_ALLOW_SYSVIPC
block|,
name|KP_DEVFS_RULESET
block|,
name|KP_ENFORCE_STATFS
block|,
name|KP_HOST_HOSTNAME
block|,
ifdef|#
directive|ifdef
name|INET
name|KP_IP4_ADDR
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|INET6
name|KP_IP6_ADDR
block|,
endif|#
directive|endif
name|KP_JID
block|,
name|KP_NAME
block|,
name|KP_PATH
block|,
name|KP_PERSIST
block|,
name|KP_SECURELEVEL
block|,
name|KP_VNET
block|,
name|IP_NPARAM
block|}
enum|;
end_enum

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|cfvars
argument_list|,
name|cfvar
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|cfvar
block|{
name|STAILQ_ENTRY
argument_list|(
argument|cfvar
argument_list|)
name|tq
expr_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|size_t
name|pos
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|cfstrings
argument_list|,
name|cfstring
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|cfstring
block|{
name|TAILQ_ENTRY
argument_list|(
argument|cfstring
argument_list|)
name|tq
expr_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|struct
name|cfvars
name|vars
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|cfparams
argument_list|,
name|cfparam
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|cfparam
block|{
name|TAILQ_ENTRY
argument_list|(
argument|cfparam
argument_list|)
name|tq
expr_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|cfstrings
name|val
decl_stmt|;
name|unsigned
name|flags
decl_stmt|;
name|int
name|gen
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|cfjails
argument_list|,
name|cfjail
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|cfdepends
argument_list|,
name|cfdepend
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|cfjail
block|{
name|TAILQ_ENTRY
argument_list|(
argument|cfjail
argument_list|)
name|tq
expr_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|comline
decl_stmt|;
name|struct
name|cfparams
name|params
decl_stmt|;
name|struct
name|cfdepends
name|dep
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|cfjails
modifier|*
name|queue
decl_stmt|;
name|struct
name|cfparam
modifier|*
name|intparams
index|[
name|IP_NPARAM
index|]
decl_stmt|;
name|struct
name|cfstring
modifier|*
name|comstring
decl_stmt|;
name|struct
name|jailparam
modifier|*
name|jp
decl_stmt|;
name|struct
name|timespec
name|timeout
decl_stmt|;
specifier|const
name|enum
name|intparam
modifier|*
name|comparam
decl_stmt|;
name|unsigned
name|flags
decl_stmt|;
name|int
name|jid
decl_stmt|;
name|int
name|seq
decl_stmt|;
name|int
name|pstatus
decl_stmt|;
name|int
name|ndeps
decl_stmt|;
name|int
name|njp
decl_stmt|;
name|int
name|nprocs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cfdepend
block|{
name|STAILQ_ENTRY
argument_list|(
argument|cfdepend
argument_list|)
name|tq
index|[
literal|2
index|]
expr_stmt|;
name|struct
name|cfjail
modifier|*
name|j
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
modifier|*
name|emalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|erealloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|estrdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|create_jail
parameter_list|(
name|struct
name|cfjail
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|failed
parameter_list|(
name|struct
name|cfjail
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|jail_note
parameter_list|(
specifier|const
name|struct
name|cfjail
modifier|*
name|j
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|jail_warnx
parameter_list|(
specifier|const
name|struct
name|cfjail
modifier|*
name|j
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|next_command
parameter_list|(
name|struct
name|cfjail
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|finish_command
parameter_list|(
name|struct
name|cfjail
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cfjail
modifier|*
name|next_proc
parameter_list|(
name|int
name|nonblock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|load_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cfjail
modifier|*
name|add_jail
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_param
parameter_list|(
name|struct
name|cfjail
modifier|*
name|j
parameter_list|,
specifier|const
name|struct
name|cfparam
modifier|*
name|p
parameter_list|,
name|enum
name|intparam
name|ipnum
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bool_param
parameter_list|(
specifier|const
name|struct
name|cfparam
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|int_param
parameter_list|(
specifier|const
name|struct
name|cfparam
modifier|*
name|p
parameter_list|,
name|int
modifier|*
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|string_param
parameter_list|(
specifier|const
name|struct
name|cfparam
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|check_intparams
parameter_list|(
name|struct
name|cfjail
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|import_params
parameter_list|(
name|struct
name|cfjail
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|equalopts
parameter_list|(
specifier|const
name|char
modifier|*
name|opt1
parameter_list|,
specifier|const
name|char
modifier|*
name|opt2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|wild_jail_name
parameter_list|(
specifier|const
name|char
modifier|*
name|wname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|wild_jail_match
parameter_list|(
specifier|const
name|char
modifier|*
name|jname
parameter_list|,
specifier|const
name|char
modifier|*
name|wname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dep_setup
parameter_list|(
name|int
name|docf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dep_check
parameter_list|(
name|struct
name|cfjail
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dep_done
parameter_list|(
name|struct
name|cfjail
modifier|*
name|j
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dep_reset
parameter_list|(
name|struct
name|cfjail
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|cfjail
modifier|*
name|next_jail
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|start_state
parameter_list|(
specifier|const
name|char
modifier|*
name|target
parameter_list|,
name|int
name|docf
parameter_list|,
name|unsigned
name|state
parameter_list|,
name|int
name|running
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|requeue
parameter_list|(
name|struct
name|cfjail
modifier|*
name|j
parameter_list|,
name|struct
name|cfjails
modifier|*
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|yyerror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|cfjails
name|cfjails
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cfjails
name|ready
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cfjails
name|depend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cfname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|note_remove
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|paralimit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|;
end_decl_stmt

end_unit

