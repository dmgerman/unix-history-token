begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: servconf.h,v 1.112 2014/01/29 06:18:35 djm Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Definitions for server configuration data and for the functions reading it.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SERVCONF_H
end_ifndef

begin_define
define|#
directive|define
name|SERVCONF_H
end_define

begin_define
define|#
directive|define
name|MAX_PORTS
value|256
end_define

begin_comment
comment|/* Max # ports. */
end_comment

begin_define
define|#
directive|define
name|MAX_ALLOW_USERS
value|256
end_define

begin_comment
comment|/* Max # users on allow list. */
end_comment

begin_define
define|#
directive|define
name|MAX_DENY_USERS
value|256
end_define

begin_comment
comment|/* Max # users on deny list. */
end_comment

begin_define
define|#
directive|define
name|MAX_ALLOW_GROUPS
value|256
end_define

begin_comment
comment|/* Max # groups on allow list. */
end_comment

begin_define
define|#
directive|define
name|MAX_DENY_GROUPS
value|256
end_define

begin_comment
comment|/* Max # groups on deny list. */
end_comment

begin_define
define|#
directive|define
name|MAX_SUBSYSTEMS
value|256
end_define

begin_comment
comment|/* Max # subsystems. */
end_comment

begin_define
define|#
directive|define
name|MAX_HOSTKEYS
value|256
end_define

begin_comment
comment|/* Max # hostkeys. */
end_comment

begin_define
define|#
directive|define
name|MAX_HOSTCERTS
value|256
end_define

begin_comment
comment|/* Max # host certificates. */
end_comment

begin_define
define|#
directive|define
name|MAX_ACCEPT_ENV
value|256
end_define

begin_comment
comment|/* Max # of env vars. */
end_comment

begin_define
define|#
directive|define
name|MAX_MATCH_GROUPS
value|256
end_define

begin_comment
comment|/* Max # of groups for Match. */
end_comment

begin_define
define|#
directive|define
name|MAX_AUTHKEYS_FILES
value|256
end_define

begin_comment
comment|/* Max # of authorized_keys files. */
end_comment

begin_define
define|#
directive|define
name|MAX_AUTH_METHODS
value|256
end_define

begin_comment
comment|/* Max # of AuthenticationMethods. */
end_comment

begin_comment
comment|/* permit_root_login */
end_comment

begin_define
define|#
directive|define
name|PERMIT_NOT_SET
value|-1
end_define

begin_define
define|#
directive|define
name|PERMIT_NO
value|0
end_define

begin_define
define|#
directive|define
name|PERMIT_FORCED_ONLY
value|1
end_define

begin_define
define|#
directive|define
name|PERMIT_NO_PASSWD
value|2
end_define

begin_define
define|#
directive|define
name|PERMIT_YES
value|3
end_define

begin_comment
comment|/* use_privsep */
end_comment

begin_define
define|#
directive|define
name|PRIVSEP_OFF
value|0
end_define

begin_define
define|#
directive|define
name|PRIVSEP_ON
value|1
end_define

begin_define
define|#
directive|define
name|PRIVSEP_NOSANDBOX
value|2
end_define

begin_comment
comment|/* AllowTCPForwarding */
end_comment

begin_define
define|#
directive|define
name|FORWARD_DENY
value|0
end_define

begin_define
define|#
directive|define
name|FORWARD_REMOTE
value|(1)
end_define

begin_define
define|#
directive|define
name|FORWARD_LOCAL
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|FORWARD_ALLOW
value|(FORWARD_REMOTE|FORWARD_LOCAL)
end_define

begin_define
define|#
directive|define
name|DEFAULT_AUTH_FAIL_MAX
value|6
end_define

begin_comment
comment|/* Default for MaxAuthTries */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SESSIONS_MAX
value|10
end_define

begin_comment
comment|/* Default for MaxSessions */
end_comment

begin_comment
comment|/* Magic name for internal sftp-server */
end_comment

begin_define
define|#
directive|define
name|INTERNAL_SFTP_NAME
value|"internal-sftp"
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|num_ports
decl_stmt|;
name|u_int
name|ports_from_cmdline
decl_stmt|;
name|int
name|ports
index|[
name|MAX_PORTS
index|]
decl_stmt|;
comment|/* Port number to listen on. */
name|char
modifier|*
name|listen_addr
decl_stmt|;
comment|/* Address on which the server listens. */
name|struct
name|addrinfo
modifier|*
name|listen_addrs
decl_stmt|;
comment|/* Addresses on which the server listens. */
name|int
name|address_family
decl_stmt|;
comment|/* Address family used by the server. */
name|char
modifier|*
name|host_key_files
index|[
name|MAX_HOSTKEYS
index|]
decl_stmt|;
comment|/* Files containing host keys. */
name|int
name|num_host_key_files
decl_stmt|;
comment|/* Number of files for host keys. */
name|char
modifier|*
name|host_cert_files
index|[
name|MAX_HOSTCERTS
index|]
decl_stmt|;
comment|/* Files containing host certs. */
name|int
name|num_host_cert_files
decl_stmt|;
comment|/* Number of files for host certs. */
name|char
modifier|*
name|host_key_agent
decl_stmt|;
comment|/* ssh-agent socket for host keys. */
name|char
modifier|*
name|pid_file
decl_stmt|;
comment|/* Where to put our pid */
name|int
name|server_key_bits
decl_stmt|;
comment|/* Size of the server key. */
name|int
name|login_grace_time
decl_stmt|;
comment|/* Disconnect if no auth in this time 					 * (sec). */
name|int
name|key_regeneration_time
decl_stmt|;
comment|/* Server key lifetime (seconds). */
name|int
name|permit_root_login
decl_stmt|;
comment|/* PERMIT_*, see above */
name|int
name|ignore_rhosts
decl_stmt|;
comment|/* Ignore .rhosts and .shosts. */
name|int
name|ignore_user_known_hosts
decl_stmt|;
comment|/* Ignore ~/.ssh/known_hosts 						 * for RhostsRsaAuth */
name|int
name|print_motd
decl_stmt|;
comment|/* If true, print /etc/motd. */
name|int
name|print_lastlog
decl_stmt|;
comment|/* If true, print lastlog */
name|int
name|x11_forwarding
decl_stmt|;
comment|/* If true, permit inet (spoofing) X11 fwd. */
name|int
name|x11_display_offset
decl_stmt|;
comment|/* What DISPLAY number to start 					 * searching at */
name|int
name|x11_use_localhost
decl_stmt|;
comment|/* If true, use localhost for fake X11 server. */
name|char
modifier|*
name|xauth_location
decl_stmt|;
comment|/* Location of xauth program */
name|int
name|permit_tty
decl_stmt|;
comment|/* If false, deny pty allocation */
name|int
name|strict_modes
decl_stmt|;
comment|/* If true, require string home dir modes. */
name|int
name|tcp_keep_alive
decl_stmt|;
comment|/* If true, set SO_KEEPALIVE. */
name|int
name|ip_qos_interactive
decl_stmt|;
comment|/* IP ToS/DSCP/class for interactive */
name|int
name|ip_qos_bulk
decl_stmt|;
comment|/* IP ToS/DSCP/class for bulk traffic */
name|char
modifier|*
name|ciphers
decl_stmt|;
comment|/* Supported SSH2 ciphers. */
name|char
modifier|*
name|macs
decl_stmt|;
comment|/* Supported SSH2 macs. */
name|char
modifier|*
name|kex_algorithms
decl_stmt|;
comment|/* SSH2 kex methods in order of preference. */
name|int
name|protocol
decl_stmt|;
comment|/* Supported protocol versions. */
name|int
name|gateway_ports
decl_stmt|;
comment|/* If true, allow remote connects to forwarded ports. */
name|SyslogFacility
name|log_facility
decl_stmt|;
comment|/* Facility for system logging. */
name|LogLevel
name|log_level
decl_stmt|;
comment|/* Level for system logging. */
name|int
name|rhosts_rsa_authentication
decl_stmt|;
comment|/* If true, permit rhosts RSA 						 * authentication. */
name|int
name|hostbased_authentication
decl_stmt|;
comment|/* If true, permit ssh2 hostbased auth */
name|int
name|hostbased_uses_name_from_packet_only
decl_stmt|;
comment|/* experimental */
name|int
name|rsa_authentication
decl_stmt|;
comment|/* If true, permit RSA authentication. */
name|int
name|pubkey_authentication
decl_stmt|;
comment|/* If true, permit ssh2 pubkey authentication. */
name|int
name|kerberos_authentication
decl_stmt|;
comment|/* If true, permit Kerberos 						 * authentication. */
name|int
name|kerberos_or_local_passwd
decl_stmt|;
comment|/* If true, permit kerberos 						 * and any other password 						 * authentication mechanism, 						 * such as SecurID or 						 * /etc/passwd */
name|int
name|kerberos_ticket_cleanup
decl_stmt|;
comment|/* If true, destroy ticket 						 * file on logout. */
name|int
name|kerberos_get_afs_token
decl_stmt|;
comment|/* If true, try to get AFS token if 						 * authenticated with Kerberos. */
name|int
name|gss_authentication
decl_stmt|;
comment|/* If true, permit GSSAPI authentication */
name|int
name|gss_cleanup_creds
decl_stmt|;
comment|/* If true, destroy cred cache on logout */
name|int
name|password_authentication
decl_stmt|;
comment|/* If true, permit password 						 * authentication. */
name|int
name|kbd_interactive_authentication
decl_stmt|;
comment|/* If true, permit */
name|int
name|challenge_response_authentication
decl_stmt|;
name|int
name|permit_empty_passwd
decl_stmt|;
comment|/* If false, do not permit empty 					 * passwords. */
name|int
name|permit_user_env
decl_stmt|;
comment|/* If true, read ~/.ssh/environment */
name|int
name|use_login
decl_stmt|;
comment|/* If true, login(1) is used */
name|int
name|compression
decl_stmt|;
comment|/* If true, compression is allowed */
name|int
name|allow_tcp_forwarding
decl_stmt|;
comment|/* One of FORWARD_* */
name|int
name|allow_agent_forwarding
decl_stmt|;
name|u_int
name|num_allow_users
decl_stmt|;
name|char
modifier|*
name|allow_users
index|[
name|MAX_ALLOW_USERS
index|]
decl_stmt|;
name|u_int
name|num_deny_users
decl_stmt|;
name|char
modifier|*
name|deny_users
index|[
name|MAX_DENY_USERS
index|]
decl_stmt|;
name|u_int
name|num_allow_groups
decl_stmt|;
name|char
modifier|*
name|allow_groups
index|[
name|MAX_ALLOW_GROUPS
index|]
decl_stmt|;
name|u_int
name|num_deny_groups
decl_stmt|;
name|char
modifier|*
name|deny_groups
index|[
name|MAX_DENY_GROUPS
index|]
decl_stmt|;
name|u_int
name|num_subsystems
decl_stmt|;
name|char
modifier|*
name|subsystem_name
index|[
name|MAX_SUBSYSTEMS
index|]
decl_stmt|;
name|char
modifier|*
name|subsystem_command
index|[
name|MAX_SUBSYSTEMS
index|]
decl_stmt|;
name|char
modifier|*
name|subsystem_args
index|[
name|MAX_SUBSYSTEMS
index|]
decl_stmt|;
name|u_int
name|num_accept_env
decl_stmt|;
name|char
modifier|*
name|accept_env
index|[
name|MAX_ACCEPT_ENV
index|]
decl_stmt|;
name|int
name|max_startups_begin
decl_stmt|;
name|int
name|max_startups_rate
decl_stmt|;
name|int
name|max_startups
decl_stmt|;
name|int
name|max_authtries
decl_stmt|;
name|int
name|max_sessions
decl_stmt|;
name|char
modifier|*
name|banner
decl_stmt|;
comment|/* SSH-2 banner message */
name|int
name|use_dns
decl_stmt|;
name|int
name|client_alive_interval
decl_stmt|;
comment|/* 					 * poke the client this often to 					 * see if it's still there 					 */
name|int
name|client_alive_count_max
decl_stmt|;
comment|/* 					 * If the client is unresponsive 					 * for this many intervals above, 					 * disconnect the session 					 */
name|u_int
name|num_authkeys_files
decl_stmt|;
comment|/* Files containing public keys */
name|char
modifier|*
name|authorized_keys_files
index|[
name|MAX_AUTHKEYS_FILES
index|]
decl_stmt|;
name|char
modifier|*
name|adm_forced_command
decl_stmt|;
name|int
name|use_pam
decl_stmt|;
comment|/* Enable auth via PAM */
name|int
name|permit_tun
decl_stmt|;
name|int
name|num_permitted_opens
decl_stmt|;
name|char
modifier|*
name|chroot_directory
decl_stmt|;
name|char
modifier|*
name|revoked_keys_file
decl_stmt|;
name|char
modifier|*
name|trusted_user_ca_keys
decl_stmt|;
name|char
modifier|*
name|authorized_principals_file
decl_stmt|;
name|char
modifier|*
name|authorized_keys_command
decl_stmt|;
name|char
modifier|*
name|authorized_keys_command_user
decl_stmt|;
name|int64_t
name|rekey_limit
decl_stmt|;
name|int
name|rekey_interval
decl_stmt|;
name|char
modifier|*
name|version_addendum
decl_stmt|;
comment|/* Appended to SSH banner */
name|int
name|hpn_disabled
decl_stmt|;
comment|/* Disable HPN functionality. */
name|int
name|hpn_buffer_size
decl_stmt|;
comment|/* Set HPN buffer size - default 2MB.*/
name|int
name|tcp_rcv_buf_poll
decl_stmt|;
comment|/* Poll TCP rcv window in autotuning 					 * kernels. */
name|u_int
name|num_auth_methods
decl_stmt|;
name|char
modifier|*
name|auth_methods
index|[
name|MAX_AUTH_METHODS
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|NONE_CIPHER_ENABLED
name|int
name|none_enabled
decl_stmt|;
comment|/* Enable NONE cipher switch. */
endif|#
directive|endif
block|}
name|ServerOptions
typedef|;
end_typedef

begin_comment
comment|/* Information about the incoming connection as used by Match */
end_comment

begin_struct
struct|struct
name|connection_info
block|{
specifier|const
name|char
modifier|*
name|user
decl_stmt|;
specifier|const
name|char
modifier|*
name|host
decl_stmt|;
comment|/* possibly resolved hostname */
specifier|const
name|char
modifier|*
name|address
decl_stmt|;
comment|/* remote address */
specifier|const
name|char
modifier|*
name|laddress
decl_stmt|;
comment|/* local address */
name|int
name|lport
decl_stmt|;
comment|/* local port */
block|}
struct|;
end_struct

begin_comment
comment|/*  * These are string config options that must be copied between the  * Match sub-config and the main config, and must be sent from the  * privsep slave to the privsep master. We use a macro to ensure all  * the options are copied and the copies are done in the correct order.  *  * NB. an option must appear in servconf.c:copy_set_server_options() or  * COPY_MATCH_STRING_OPTS here but never both.  */
end_comment

begin_define
define|#
directive|define
name|COPY_MATCH_STRING_OPTS
parameter_list|()
value|do { \ 		M_CP_STROPT(banner); \ 		M_CP_STROPT(trusted_user_ca_keys); \ 		M_CP_STROPT(revoked_keys_file); \ 		M_CP_STROPT(authorized_principals_file); \ 		M_CP_STROPT(authorized_keys_command); \ 		M_CP_STROPT(authorized_keys_command_user); \ 		M_CP_STRARRAYOPT(authorized_keys_files, num_authkeys_files); \ 		M_CP_STRARRAYOPT(allow_users, num_allow_users); \ 		M_CP_STRARRAYOPT(deny_users, num_deny_users); \ 		M_CP_STRARRAYOPT(allow_groups, num_allow_groups); \ 		M_CP_STRARRAYOPT(deny_groups, num_deny_groups); \ 		M_CP_STRARRAYOPT(accept_env, num_accept_env); \ 		M_CP_STRARRAYOPT(auth_methods, num_auth_methods); \ 	} while (0)
end_define

begin_function_decl
name|struct
name|connection_info
modifier|*
name|get_connection_info
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|initialize_server_options
parameter_list|(
name|ServerOptions
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fill_default_server_options
parameter_list|(
name|ServerOptions
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|process_server_config_line
parameter_list|(
name|ServerOptions
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|connection_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_server_config
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parse_server_config
parameter_list|(
name|ServerOptions
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|Buffer
modifier|*
parameter_list|,
name|struct
name|connection_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parse_server_match_config
parameter_list|(
name|ServerOptions
modifier|*
parameter_list|,
name|struct
name|connection_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_server_match_testspec
parameter_list|(
name|struct
name|connection_info
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|server_match_spec_complete
parameter_list|(
name|struct
name|connection_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_set_server_options
parameter_list|(
name|ServerOptions
modifier|*
parameter_list|,
name|ServerOptions
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_config
parameter_list|(
name|ServerOptions
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|derelativise_path
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERVCONF_H */
end_comment

end_unit

