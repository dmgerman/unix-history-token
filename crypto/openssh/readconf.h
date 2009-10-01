begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: readconf.h,v 1.79 2009/06/27 09:35:06 andreas Exp $ */
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
comment|/* Data structure for representing a forwarding request. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|listen_host
decl_stmt|;
comment|/* Host (address) to listen on. */
name|int
name|listen_port
decl_stmt|;
comment|/* Port to forward. */
name|char
modifier|*
name|connect_host
decl_stmt|;
comment|/* Host to connect. */
name|int
name|connect_port
decl_stmt|;
comment|/* Port to connect on connect_host. */
block|}
name|Forward
typedef|;
end_typedef

begin_comment
comment|/* Data structure for representing option data. */
end_comment

begin_define
define|#
directive|define
name|MAX_SEND_ENV
value|256
end_define

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
name|int
name|gateway_ports
decl_stmt|;
comment|/* Allow remote connects to forwarded ports. */
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
name|zero_knowledge_password_authentication
decl_stmt|;
comment|/* Try jpake */
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
name|char
modifier|*
name|system_hostfile
decl_stmt|;
comment|/* Path for /etc/ssh/ssh_known_hosts. */
name|char
modifier|*
name|user_hostfile
decl_stmt|;
comment|/* Path for $HOME/.ssh/known_hosts. */
name|char
modifier|*
name|system_hostfile2
decl_stmt|;
name|char
modifier|*
name|user_hostfile2
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
name|smartcard_device
decl_stmt|;
comment|/* Smartcard reader device */
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
name|Forward
name|local_forwards
index|[
name|SSH_MAX_FORWARDS_PER_DIRECTION
index|]
decl_stmt|;
comment|/* Remote TCP/IP forward requests. */
name|int
name|num_remote_forwards
decl_stmt|;
name|Forward
name|remote_forwards
index|[
name|SSH_MAX_FORWARDS_PER_DIRECTION
index|]
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
block|}
name|Options
typedef|;
end_typedef

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
name|int
name|read_config_file
parameter_list|(
specifier|const
name|char
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
name|process_config_line
parameter_list|(
name|Options
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
name|Forward
modifier|*
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

