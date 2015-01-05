begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: readconf.h,v 1.102 2014/07/15 15:54:14 millert Exp $ */
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Functions for reading the configuration file.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|READCONF_H
end_ifndef

begin_define
define|#
directive|define
name|READCONF_H
end_define

begin_comment
comment|/* Data structure for representing option data. */
end_comment

begin_define
define|#
directive|define
name|MAX_SEND_ENV
value|256
end_define

begin_define
define|#
directive|define
name|SSH_MAX_HOSTS_FILES
value|32
end_define

begin_define
define|#
directive|define
name|MAX_CANON_DOMAINS
value|32
end_define

begin_define
define|#
directive|define
name|PATH_MAX_SUN
value|(sizeof((struct sockaddr_un *)0)->sun_path)
end_define

begin_struct
struct|struct
name|allowed_cname
block|{
name|char
modifier|*
name|source_list
decl_stmt|;
name|char
modifier|*
name|target_list
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|forward_agent
decl_stmt|;
comment|/* Forward authentication agent. */
name|int
name|forward_x11
decl_stmt|;
comment|/* Forward X11 display. */
name|int
name|forward_x11_timeout
decl_stmt|;
comment|/* Expiration for Cookies */
name|int
name|forward_x11_trusted
decl_stmt|;
comment|/* Trust Forward X11 display. */
name|int
name|exit_on_forward_failure
decl_stmt|;
comment|/* Exit if bind(2) fails for -L/-R */
name|char
modifier|*
name|xauth_location
decl_stmt|;
comment|/* Location for xauth program */
name|struct
name|ForwardOptions
name|fwd_opts
decl_stmt|;
comment|/* forwarding options */
name|int
name|use_privileged_port
decl_stmt|;
comment|/* Don't use privileged port if false. */
name|int
name|rhosts_rsa_authentication
decl_stmt|;
comment|/* Try rhosts with RSA 						 * authentication. */
name|int
name|rsa_authentication
decl_stmt|;
comment|/* Try RSA authentication. */
name|int
name|pubkey_authentication
decl_stmt|;
comment|/* Try ssh2 pubkey authentication. */
name|int
name|hostbased_authentication
decl_stmt|;
comment|/* ssh2's rhosts_rsa */
name|int
name|challenge_response_authentication
decl_stmt|;
comment|/* Try S/Key or TIS, authentication. */
name|int
name|gss_authentication
decl_stmt|;
comment|/* Try GSS authentication */
name|int
name|gss_deleg_creds
decl_stmt|;
comment|/* Delegate GSS credentials */
name|int
name|password_authentication
decl_stmt|;
comment|/* Try password 						 * authentication. */
name|int
name|kbd_interactive_authentication
decl_stmt|;
comment|/* Try keyboard-interactive auth. */
name|char
modifier|*
name|kbd_interactive_devices
decl_stmt|;
comment|/* Keyboard-interactive auth devices. */
name|int
name|batch_mode
decl_stmt|;
comment|/* Batch mode: do not ask for passwords. */
name|int
name|check_host_ip
decl_stmt|;
comment|/* Also keep track of keys for IP address */
name|int
name|strict_host_key_checking
decl_stmt|;
comment|/* Strict host key checking. */
name|int
name|compression
decl_stmt|;
comment|/* Compress packets in both directions. */
name|int
name|compression_level
decl_stmt|;
comment|/* Compression level 1 (fast) to 9 					 * (best). */
name|int
name|tcp_keep_alive
decl_stmt|;
comment|/* Set SO_KEEPALIVE. */
name|int
name|ip_qos_interactive
decl_stmt|;
comment|/* IP ToS/DSCP/class for interactive */
name|int
name|ip_qos_bulk
decl_stmt|;
comment|/* IP ToS/DSCP/class for bulk traffic */
name|LogLevel
name|log_level
decl_stmt|;
comment|/* Level for logging. */
name|int
name|port
decl_stmt|;
comment|/* Port to connect. */
name|int
name|address_family
decl_stmt|;
name|int
name|connection_attempts
decl_stmt|;
comment|/* Max attempts (seconds) before 					 * giving up */
name|int
name|connection_timeout
decl_stmt|;
comment|/* Max time (seconds) before 					 * aborting connection attempt */
name|int
name|number_of_password_prompts
decl_stmt|;
comment|/* Max number of password 						 * prompts. */
name|int
name|cipher
decl_stmt|;
comment|/* Cipher to use. */
name|char
modifier|*
name|ciphers
decl_stmt|;
comment|/* SSH2 ciphers in order of preference. */
name|char
modifier|*
name|macs
decl_stmt|;
comment|/* SSH2 macs in order of preference. */
name|char
modifier|*
name|hostkeyalgorithms
decl_stmt|;
comment|/* SSH2 server key types in order of preference. */
name|char
modifier|*
name|kex_algorithms
decl_stmt|;
comment|/* SSH2 kex methods in order of preference. */
name|int
name|protocol
decl_stmt|;
comment|/* Protocol in order of preference. */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/* Real host to connect. */
name|char
modifier|*
name|host_key_alias
decl_stmt|;
comment|/* hostname alias for .ssh/known_hosts */
name|char
modifier|*
name|proxy_command
decl_stmt|;
comment|/* Proxy command for connecting the host. */
name|char
modifier|*
name|user
decl_stmt|;
comment|/* User to log in as. */
name|int
name|escape_char
decl_stmt|;
comment|/* Escape character; -2 = none */
name|u_int
name|num_system_hostfiles
decl_stmt|;
comment|/* Paths for /etc/ssh/ssh_known_hosts */
name|char
modifier|*
name|system_hostfiles
index|[
name|SSH_MAX_HOSTS_FILES
index|]
decl_stmt|;
name|u_int
name|num_user_hostfiles
decl_stmt|;
comment|/* Path for $HOME/.ssh/known_hosts */
name|char
modifier|*
name|user_hostfiles
index|[
name|SSH_MAX_HOSTS_FILES
index|]
decl_stmt|;
name|char
modifier|*
name|preferred_authentications
decl_stmt|;
name|char
modifier|*
name|bind_address
decl_stmt|;
comment|/* local socket address for connection to sshd */
name|char
modifier|*
name|pkcs11_provider
decl_stmt|;
comment|/* PKCS#11 provider */
name|int
name|verify_host_key_dns
decl_stmt|;
comment|/* Verify host key using DNS */
name|int
name|num_identity_files
decl_stmt|;
comment|/* Number of files for RSA/DSA identities. */
name|char
modifier|*
name|identity_files
index|[
name|SSH_MAX_IDENTITY_FILES
index|]
decl_stmt|;
name|int
name|identity_file_userprovided
index|[
name|SSH_MAX_IDENTITY_FILES
index|]
decl_stmt|;
name|Key
modifier|*
name|identity_keys
index|[
name|SSH_MAX_IDENTITY_FILES
index|]
decl_stmt|;
comment|/* Local TCP/IP forward requests. */
name|int
name|num_local_forwards
decl_stmt|;
name|struct
name|Forward
modifier|*
name|local_forwards
decl_stmt|;
comment|/* Remote TCP/IP forward requests. */
name|int
name|num_remote_forwards
decl_stmt|;
name|struct
name|Forward
modifier|*
name|remote_forwards
decl_stmt|;
name|int
name|clear_forwardings
decl_stmt|;
name|int
name|enable_ssh_keysign
decl_stmt|;
name|int64_t
name|rekey_limit
decl_stmt|;
name|int
name|rekey_interval
decl_stmt|;
name|int
name|no_host_authentication_for_localhost
decl_stmt|;
name|int
name|identities_only
decl_stmt|;
name|int
name|server_alive_interval
decl_stmt|;
name|int
name|server_alive_count_max
decl_stmt|;
name|int
name|num_send_env
decl_stmt|;
name|char
modifier|*
name|send_env
index|[
name|MAX_SEND_ENV
index|]
decl_stmt|;
name|char
modifier|*
name|control_path
decl_stmt|;
name|int
name|control_master
decl_stmt|;
name|int
name|control_persist
decl_stmt|;
comment|/* ControlPersist flag */
name|int
name|control_persist_timeout
decl_stmt|;
comment|/* ControlPersist timeout (seconds) */
name|int
name|hash_known_hosts
decl_stmt|;
name|int
name|tun_open
decl_stmt|;
comment|/* tun(4) */
name|int
name|tun_local
decl_stmt|;
comment|/* force tun device (optional) */
name|int
name|tun_remote
decl_stmt|;
comment|/* force tun device (optional) */
name|char
modifier|*
name|local_command
decl_stmt|;
name|int
name|permit_local_command
decl_stmt|;
name|int
name|visual_host_key
decl_stmt|;
name|int
name|use_roaming
decl_stmt|;
name|int
name|request_tty
decl_stmt|;
name|int
name|proxy_use_fdpass
decl_stmt|;
name|int
name|num_canonical_domains
decl_stmt|;
name|char
modifier|*
name|canonical_domains
index|[
name|MAX_CANON_DOMAINS
index|]
decl_stmt|;
name|int
name|canonicalize_hostname
decl_stmt|;
name|int
name|canonicalize_max_dots
decl_stmt|;
name|int
name|canonicalize_fallback_local
decl_stmt|;
name|int
name|num_permitted_cnames
decl_stmt|;
name|struct
name|allowed_cname
name|permitted_cnames
index|[
name|MAX_CANON_DOMAINS
index|]
decl_stmt|;
name|char
modifier|*
name|ignored_unknown
decl_stmt|;
comment|/* Pattern list of unknown tokens to ignore */
block|}
name|Options
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SSH_CANONICALISE_NO
value|0
end_define

begin_define
define|#
directive|define
name|SSH_CANONICALISE_YES
value|1
end_define

begin_define
define|#
directive|define
name|SSH_CANONICALISE_ALWAYS
value|2
end_define

begin_define
define|#
directive|define
name|SSHCTL_MASTER_NO
value|0
end_define

begin_define
define|#
directive|define
name|SSHCTL_MASTER_YES
value|1
end_define

begin_define
define|#
directive|define
name|SSHCTL_MASTER_AUTO
value|2
end_define

begin_define
define|#
directive|define
name|SSHCTL_MASTER_ASK
value|3
end_define

begin_define
define|#
directive|define
name|SSHCTL_MASTER_AUTO_ASK
value|4
end_define

begin_define
define|#
directive|define
name|REQUEST_TTY_AUTO
value|0
end_define

begin_define
define|#
directive|define
name|REQUEST_TTY_NO
value|1
end_define

begin_define
define|#
directive|define
name|REQUEST_TTY_YES
value|2
end_define

begin_define
define|#
directive|define
name|REQUEST_TTY_FORCE
value|3
end_define

begin_define
define|#
directive|define
name|SSHCONF_CHECKPERM
value|1
end_define

begin_comment
comment|/* check permissions on config file */
end_comment

begin_define
define|#
directive|define
name|SSHCONF_USERCONF
value|2
end_define

begin_comment
comment|/* user provided config file not system */
end_comment

begin_function_decl
name|void
name|initialize_options
parameter_list|(
name|Options
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fill_default_options
parameter_list|(
name|Options
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fill_default_options_for_canonicalization
parameter_list|(
name|Options
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|process_config_line
parameter_list|(
name|Options
modifier|*
parameter_list|,
name|struct
name|passwd
modifier|*
parameter_list|,
specifier|const
name|char
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
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_config_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|passwd
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|Options
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_forward
parameter_list|(
name|struct
name|Forward
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|default_ssh_port
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|option_clear_or_none
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_local_forward
parameter_list|(
name|Options
modifier|*
parameter_list|,
specifier|const
name|struct
name|Forward
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_remote_forward
parameter_list|(
name|Options
modifier|*
parameter_list|,
specifier|const
name|struct
name|Forward
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_identity_file
parameter_list|(
name|Options
modifier|*
parameter_list|,
specifier|const
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* READCONF_H */
end_comment

end_unit

