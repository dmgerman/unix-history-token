begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: servconf.h,v 1.72 2005/12/06 22:38:27 reyk Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
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

begin_include
include|#
directive|include
file|"buffer.h"
end_include

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
name|MAX_ACCEPT_ENV
value|256
end_define

begin_comment
comment|/* Max # of env vars. */
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

begin_define
define|#
directive|define
name|DEFAULT_AUTH_FAIL_MAX
value|6
end_define

begin_comment
comment|/* Default for MaxAuthTries */
end_comment

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
name|u_short
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
name|strict_modes
decl_stmt|;
comment|/* If true, require string home dir modes. */
name|int
name|tcp_keep_alive
decl_stmt|;
comment|/* If true, set SO_KEEPALIVE. */
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
name|char
modifier|*
name|authorized_keys_file
decl_stmt|;
comment|/* File containing public keys */
name|char
modifier|*
name|authorized_keys_file2
decl_stmt|;
name|int
name|use_pam
decl_stmt|;
comment|/* Enable auth via PAM */
name|int
name|permit_tun
decl_stmt|;
block|}
name|ServerOptions
typedef|;
end_typedef

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

