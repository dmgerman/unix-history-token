begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Definitions for server configuration data and for the functions reading it.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: servconf.h,v 1.30 2000/10/14 12:12:09 markus Exp $"); */
end_comment

begin_comment
comment|/* $FreeBSD$ */
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|num_ports
decl_stmt|;
name|unsigned
name|int
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
name|char
modifier|*
name|host_key_file
decl_stmt|;
comment|/* File containing host key. */
name|char
modifier|*
name|host_dsa_key_file
decl_stmt|;
comment|/* File containing dsa host key. */
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
comment|/* If true, permit root login. */
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
name|check_mail
decl_stmt|;
comment|/* If true, check for new mail. */
name|int
name|x11_forwarding
decl_stmt|;
comment|/* If true, permit inet (spoofing) X11 fwd. */
name|int
name|x11_display_offset
decl_stmt|;
comment|/* What DISPLAY number to start 					 * searching at */
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
name|keepalives
decl_stmt|;
comment|/* If true, set SO_KEEPALIVE. */
name|char
modifier|*
name|ciphers
decl_stmt|;
comment|/* Ciphers in order of preference. */
name|int
name|protocol
decl_stmt|;
comment|/* Protocol in order of preference. */
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
name|rhosts_authentication
decl_stmt|;
comment|/* If true, permit rhosts 					 * authentication. */
name|int
name|rhosts_rsa_authentication
decl_stmt|;
comment|/* If true, permit rhosts RSA 						 * authentication. */
name|int
name|rsa_authentication
decl_stmt|;
comment|/* If true, permit RSA authentication. */
name|int
name|dsa_authentication
decl_stmt|;
comment|/* If true, permit DSA authentication. */
if|#
directive|if
name|defined
argument_list|(
name|KRB4
argument_list|)
operator|||
name|defined
argument_list|(
name|KRB5
argument_list|)
name|int
name|kerberos_authentication
decl_stmt|;
comment|/* If true, permit Kerberos auth. */
endif|#
directive|endif
comment|/* KRB4 || KRB5 */
ifdef|#
directive|ifdef
name|KRB4
name|int
name|krb4_or_local_passwd
decl_stmt|;
comment|/* If true, permit kerberos v4 						 * and any other password 						 * authentication mechanism, 						 * such as SecurID or 						 * /etc/passwd */
name|int
name|krb4_ticket_cleanup
decl_stmt|;
comment|/* If true, destroy ticket 						 * file on logout. */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|KRB5
name|int
name|krb5_tgt_passing
decl_stmt|;
endif|#
directive|endif
comment|/* KRB5 */
ifdef|#
directive|ifdef
name|AFS
name|int
name|krb4_tgt_passing
decl_stmt|;
comment|/* If true, permit Kerberos v4 tgt 					 * passing. */
name|int
name|afs_token_passing
decl_stmt|;
comment|/* If true, permit AFS token passing. */
endif|#
directive|endif
name|int
name|password_authentication
decl_stmt|;
comment|/* If true, permit password 						 * authentication. */
name|int
name|kbd_interactive_authentication
decl_stmt|;
comment|/* If true, permit */
ifdef|#
directive|ifdef
name|SKEY
name|int
name|skey_authentication
decl_stmt|;
comment|/* If true, permit s/key 					 * authentication. */
endif|#
directive|endif
name|int
name|permit_empty_passwd
decl_stmt|;
comment|/* If false, do not permit empty 					 * passwords. */
name|int
name|use_login
decl_stmt|;
comment|/* If true, login(1) is used */
name|int
name|allow_tcp_forwarding
decl_stmt|;
name|unsigned
name|int
name|num_allow_users
decl_stmt|;
name|char
modifier|*
name|allow_users
index|[
name|MAX_ALLOW_USERS
index|]
decl_stmt|;
name|unsigned
name|int
name|num_deny_users
decl_stmt|;
name|char
modifier|*
name|deny_users
index|[
name|MAX_DENY_USERS
index|]
decl_stmt|;
name|unsigned
name|int
name|num_allow_groups
decl_stmt|;
name|char
modifier|*
name|allow_groups
index|[
name|MAX_ALLOW_GROUPS
index|]
decl_stmt|;
name|unsigned
name|int
name|num_deny_groups
decl_stmt|;
name|char
modifier|*
name|deny_groups
index|[
name|MAX_DENY_GROUPS
index|]
decl_stmt|;
name|unsigned
name|int
name|connections_per_period
decl_stmt|;
comment|/* 						 * If not 0, number of sshd 						 * connections accepted per 						 * connections_period. 						 */
name|unsigned
name|int
name|connections_period
decl_stmt|;
name|unsigned
name|int
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
name|int
name|max_startups_begin
decl_stmt|;
name|int
name|max_startups_rate
decl_stmt|;
name|int
name|max_startups
decl_stmt|;
block|}
name|ServerOptions
typedef|;
end_typedef

begin_comment
comment|/*  * Initializes the server options to special values that indicate that they  * have not yet been set.  */
end_comment

begin_function_decl
name|void
name|initialize_server_options
parameter_list|(
name|ServerOptions
modifier|*
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reads the server configuration file.  This only sets the values for those  * options that have the special value indicating they have not been set.  */
end_comment

begin_function_decl
name|void
name|read_server_config
parameter_list|(
name|ServerOptions
modifier|*
name|options
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Sets values for those values that have not yet been set. */
end_comment

begin_function_decl
name|void
name|fill_default_server_options
parameter_list|(
name|ServerOptions
modifier|*
name|options
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

