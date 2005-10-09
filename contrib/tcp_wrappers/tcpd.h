begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * @(#) tcpd.h 1.5 96/03/19 16:22:24   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   *   * $FreeBSD$   */
end_comment

begin_comment
comment|/* Structure to describe one communications endpoint. */
end_comment

begin_define
define|#
directive|define
name|STRING_LENGTH
value|128
end_define

begin_comment
comment|/* hosts, users, processes */
end_comment

begin_struct
struct|struct
name|host_info
block|{
name|char
name|name
index|[
name|STRING_LENGTH
index|]
decl_stmt|;
comment|/* access via eval_hostname(host) */
name|char
name|addr
index|[
name|STRING_LENGTH
index|]
decl_stmt|;
comment|/* access via eval_hostaddr(host) */
ifdef|#
directive|ifdef
name|INET6
name|struct
name|sockaddr
modifier|*
name|sin
decl_stmt|;
comment|/* socket address or 0 */
else|#
directive|else
name|struct
name|sockaddr_in
modifier|*
name|sin
decl_stmt|;
comment|/* socket address or 0 */
endif|#
directive|endif
name|struct
name|t_unitdata
modifier|*
name|unit
decl_stmt|;
comment|/* TLI transport address or 0 */
name|struct
name|request_info
modifier|*
name|request
decl_stmt|;
comment|/* for shared information */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure to describe what we know about a service request. */
end_comment

begin_struct
struct|struct
name|request_info
block|{
name|int
name|fd
decl_stmt|;
comment|/* socket handle */
name|char
name|user
index|[
name|STRING_LENGTH
index|]
decl_stmt|;
comment|/* access via eval_user(request) */
name|char
name|daemon
index|[
name|STRING_LENGTH
index|]
decl_stmt|;
comment|/* access via eval_daemon(request) */
name|char
name|pid
index|[
literal|10
index|]
decl_stmt|;
comment|/* access via eval_pid(request) */
name|struct
name|host_info
name|client
index|[
literal|1
index|]
decl_stmt|;
comment|/* client endpoint info */
name|struct
name|host_info
name|server
index|[
literal|1
index|]
decl_stmt|;
comment|/* server endpoint info */
name|void
function_decl|(
modifier|*
name|sink
function_decl|)
parameter_list|()
function_decl|;
comment|/* datagram sink function or 0 */
name|void
function_decl|(
modifier|*
name|hostname
function_decl|)
parameter_list|()
function_decl|;
comment|/* address to printable hostname */
name|void
function_decl|(
modifier|*
name|hostaddr
function_decl|)
parameter_list|()
function_decl|;
comment|/* address to printable address */
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|()
function_decl|;
comment|/* cleanup function or 0 */
name|struct
name|netconfig
modifier|*
name|config
decl_stmt|;
comment|/* netdir handle */
block|}
struct|;
end_struct

begin_comment
comment|/* Common string operations. Less clutter should be more readable. */
end_comment

begin_define
define|#
directive|define
name|STRN_CPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|{ strncpy((d),(s),(l)); (d)[(l)-1] = 0; }
end_define

begin_define
define|#
directive|define
name|STRN_EQ
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|l
parameter_list|)
value|(strncasecmp((x),(y),(l)) == 0)
end_define

begin_define
define|#
directive|define
name|STRN_NE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|l
parameter_list|)
value|(strncasecmp((x),(y),(l)) != 0)
end_define

begin_define
define|#
directive|define
name|STR_EQ
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(strcasecmp((x),(y)) == 0)
end_define

begin_define
define|#
directive|define
name|STR_NE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(strcasecmp((x),(y)) != 0)
end_define

begin_comment
comment|/*   * Initially, all above strings have the empty value. Information that   * cannot be determined at runtime is set to "unknown", so that we can   * distinguish between `unavailable' and `not yet looked up'. A hostname   * that we do not believe in is set to "paranoid".   */
end_comment

begin_define
define|#
directive|define
name|STRING_UNKNOWN
value|"unknown"
end_define

begin_comment
comment|/* lookup failed */
end_comment

begin_define
define|#
directive|define
name|STRING_PARANOID
value|"paranoid"
end_define

begin_comment
comment|/* hostname conflict */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|unknown
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|paranoid
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HOSTNAME_KNOWN
parameter_list|(
name|s
parameter_list|)
value|(STR_NE((s),unknown)&& STR_NE((s),paranoid))
end_define

begin_define
define|#
directive|define
name|NOT_INADDR
parameter_list|(
name|s
parameter_list|)
value|(s[strspn(s,"01234567890./")] != 0)
end_define

begin_comment
comment|/* Global functions. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TLI
argument_list|)
operator|||
name|defined
argument_list|(
name|PTX
argument_list|)
operator|||
name|defined
argument_list|(
name|TLI_SEQUENT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
name|fromhost
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get/validate client host info */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fromhost
value|sock_host
end_define

begin_comment
comment|/* no TLI support needed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|hosts_access
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* access control */
end_comment

begin_function_decl
specifier|extern
name|void
name|shell_cmd
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* execute shell command */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|percent_x
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* do %<char> expansion */
end_comment

begin_function_decl
specifier|extern
name|void
name|rfc931
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* client name from RFC 931 daemon */
end_comment

begin_function_decl
specifier|extern
name|void
name|clean_exit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* clean up and exit */
end_comment

begin_function_decl
specifier|extern
name|void
name|refuse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* clean up and exit */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|xgets
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* fgets() on steroids */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|split_at
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* strchr() and split */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|long
name|dot_quad_addr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* restricted inet_addr() */
end_comment

begin_comment
comment|/* Global variables. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|allow_severity
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for connection logging */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|deny_severity
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for connection logging */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hosts_allow_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for verification mode redirection */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hosts_deny_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for verification mode redirection */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hosts_access_verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for verbose matching mode */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rfc931_timeout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user lookup timeout */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|resident
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*> 0 if resident process */
end_comment

begin_comment
comment|/*   * Routines for controlled initialization and update of request structure   * attributes. Each attribute has its own key.   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|struct
name|request_info
modifier|*
name|request_init
parameter_list|(
name|struct
name|request_info
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|request_info
modifier|*
name|request_set
parameter_list|(
name|struct
name|request_info
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

begin_function_decl
specifier|extern
name|struct
name|request_info
modifier|*
name|request_init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize request */
end_comment

begin_function_decl
specifier|extern
name|struct
name|request_info
modifier|*
name|request_set
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* update request structure */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RQ_FILE
value|1
end_define

begin_comment
comment|/* file descriptor */
end_comment

begin_define
define|#
directive|define
name|RQ_DAEMON
value|2
end_define

begin_comment
comment|/* server process (argv[0]) */
end_comment

begin_define
define|#
directive|define
name|RQ_USER
value|3
end_define

begin_comment
comment|/* client user name */
end_comment

begin_define
define|#
directive|define
name|RQ_CLIENT_NAME
value|4
end_define

begin_comment
comment|/* client host name */
end_comment

begin_define
define|#
directive|define
name|RQ_CLIENT_ADDR
value|5
end_define

begin_comment
comment|/* client host address */
end_comment

begin_define
define|#
directive|define
name|RQ_CLIENT_SIN
value|6
end_define

begin_comment
comment|/* client endpoint (internal) */
end_comment

begin_define
define|#
directive|define
name|RQ_SERVER_NAME
value|7
end_define

begin_comment
comment|/* server host name */
end_comment

begin_define
define|#
directive|define
name|RQ_SERVER_ADDR
value|8
end_define

begin_comment
comment|/* server host address */
end_comment

begin_define
define|#
directive|define
name|RQ_SERVER_SIN
value|9
end_define

begin_comment
comment|/* server endpoint (internal) */
end_comment

begin_comment
comment|/*   * Routines for delayed evaluation of request attributes. Each attribute   * type has its own access method. The trivial ones are implemented by   * macros. The other ones are wrappers around the transport-specific host   * name, address, and client user lookup methods. The request_info and   * host_info structures serve as caches for the lookup results.   */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|eval_user
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* client user */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|eval_hostname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* printable hostname */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|eval_hostaddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* printable host address */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|eval_hostinfo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* host name or address */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|eval_client
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* whatever is available */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|eval_server
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* whatever is available */
end_comment

begin_define
define|#
directive|define
name|eval_daemon
parameter_list|(
name|r
parameter_list|)
value|((r)->daemon)
end_define

begin_comment
comment|/* daemon process name */
end_comment

begin_define
define|#
directive|define
name|eval_pid
parameter_list|(
name|r
parameter_list|)
value|((r)->pid)
end_define

begin_comment
comment|/* process id */
end_comment

begin_comment
comment|/* Socket-specific methods, including DNS hostname lookups. */
end_comment

begin_function_decl
specifier|extern
name|void
name|sock_host
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* look up endpoint addresses */
end_comment

begin_function_decl
specifier|extern
name|void
name|sock_hostname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* translate address to hostname */
end_comment

begin_function_decl
specifier|extern
name|void
name|sock_hostaddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* address to printable address */
end_comment

begin_define
define|#
directive|define
name|sock_methods
parameter_list|(
name|r
parameter_list|)
define|\
value|{ (r)->hostname = sock_hostname; (r)->hostaddr = sock_hostaddr; }
end_define

begin_comment
comment|/* The System V Transport-Level Interface (TLI) interface. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TLI
argument_list|)
operator|||
name|defined
argument_list|(
name|PTX
argument_list|)
operator|||
name|defined
argument_list|(
name|TLI_SEQUENT
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
name|tli_host
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* look up endpoint addresses etc. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * Problem reporting interface. Additional file/line context is reported   * when available. The jump buffer (tcpd_buf) is not declared here, or   * everyone would have to include<setjmp.h>.   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|tcpd_warn
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* report problem and proceed */
end_comment

begin_function_decl
specifier|extern
name|void
name|tcpd_jump
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* report problem and jump */
end_comment

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|tcpd_warn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcpd_jump
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|tcpd_context
block|{
name|char
modifier|*
name|file
decl_stmt|;
comment|/* current file */
name|int
name|line
decl_stmt|;
comment|/* current line */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|tcpd_context
name|tcpd_context
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * While processing access control rules, error conditions are handled by   * jumping back into the hosts_access() routine. This is cleaner than   * checking the return value of each and every silly little function. The   * (-1) returns are here because zero is already taken by longjmp().   */
end_comment

begin_define
define|#
directive|define
name|AC_PERMIT
value|1
end_define

begin_comment
comment|/* permit access */
end_comment

begin_define
define|#
directive|define
name|AC_DENY
value|(-1)
end_define

begin_comment
comment|/* deny_access */
end_comment

begin_define
define|#
directive|define
name|AC_ERROR
value|AC_DENY
end_define

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*   * In verification mode an option function should just say what it would do,   * instead of really doing it. An option function that would not return   * should clear the dry_run flag to inform the caller of this unusual   * behavior.   */
end_comment

begin_function_decl
specifier|extern
name|void
name|process_options
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* execute options */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dry_run
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* verification flag */
end_comment

begin_comment
comment|/* Bug workarounds. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INET_ADDR_BUG
end_ifdef

begin_comment
comment|/* inet_addr() returns struct */
end_comment

begin_define
define|#
directive|define
name|inet_addr
value|fix_inet_addr
end_define

begin_function_decl
specifier|extern
name|long
name|fix_inet_addr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BROKEN_FGETS
end_ifdef

begin_comment
comment|/* partial reads from sockets */
end_comment

begin_define
define|#
directive|define
name|fgets
value|fix_fgets
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|fix_fgets
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RECVFROM_BUG
end_ifdef

begin_comment
comment|/* no address family info */
end_comment

begin_define
define|#
directive|define
name|recvfrom
value|fix_recvfrom
end_define

begin_function_decl
specifier|extern
name|int
name|fix_recvfrom
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GETPEERNAME_BUG
end_ifdef

begin_comment
comment|/* claims success with UDP */
end_comment

begin_define
define|#
directive|define
name|getpeername
value|fix_getpeername
end_define

begin_function_decl
specifier|extern
name|int
name|fix_getpeername
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SOLARIS_24_GETHOSTBYNAME_BUG
end_ifdef

begin_comment
comment|/* lists addresses as aliases */
end_comment

begin_define
define|#
directive|define
name|gethostbyname
value|fix_gethostbyname
end_define

begin_function_decl
specifier|extern
name|struct
name|hostent
modifier|*
name|fix_gethostbyname
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_STRSEP
end_ifdef

begin_comment
comment|/* libc calls strtok() */
end_comment

begin_define
define|#
directive|define
name|strtok
value|fix_strtok
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|fix_strtok
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LIBC_CALLS_STRTOK
end_ifdef

begin_comment
comment|/* libc calls strtok() */
end_comment

begin_define
define|#
directive|define
name|strtok
value|my_strtok
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|my_strtok
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

