begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * Generic header file for ssh.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: ssh.h,v 1.54 2000/10/11 20:27:24 markus Exp $"); */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSH_H
end_ifndef

begin_define
define|#
directive|define
name|SSH_H
end_define

begin_include
include|#
directive|include
file|"rsa.h"
end_include

begin_include
include|#
directive|include
file|"cipher.h"
end_include

begin_comment
comment|/* Cipher used for encrypting authentication files. */
end_comment

begin_define
define|#
directive|define
name|SSH_AUTHFILE_CIPHER
value|SSH_CIPHER_3DES
end_define

begin_comment
comment|/* Default port number. */
end_comment

begin_define
define|#
directive|define
name|SSH_DEFAULT_PORT
value|22
end_define

begin_comment
comment|/* Maximum number of TCP/IP ports forwarded per direction. */
end_comment

begin_define
define|#
directive|define
name|SSH_MAX_FORWARDS_PER_DIRECTION
value|100
end_define

begin_comment
comment|/*  * Maximum number of RSA authentication identity files that can be specified  * in configuration files or on the command line.  */
end_comment

begin_define
define|#
directive|define
name|SSH_MAX_IDENTITY_FILES
value|100
end_define

begin_comment
comment|/*  * Major protocol version.  Different version indicates major incompatiblity  * that prevents communication.  *  * Minor protocol version.  Different version indicates minor incompatibility  * that does not prevent interoperation.  */
end_comment

begin_define
define|#
directive|define
name|PROTOCOL_MAJOR_1
value|1
end_define

begin_define
define|#
directive|define
name|PROTOCOL_MINOR_1
value|5
end_define

begin_comment
comment|/* We support both SSH1 and SSH2 */
end_comment

begin_define
define|#
directive|define
name|PROTOCOL_MAJOR_2
value|2
end_define

begin_define
define|#
directive|define
name|PROTOCOL_MINOR_2
value|0
end_define

begin_comment
comment|/*  * Name for the service.  The port named by this service overrides the  * default port if present.  */
end_comment

begin_define
define|#
directive|define
name|SSH_SERVICE_NAME
value|"ssh"
end_define

begin_define
define|#
directive|define
name|ETCDIR
value|"/etc/ssh"
end_define

begin_define
define|#
directive|define
name|PIDDIR
value|"/var/run"
end_define

begin_comment
comment|/*  * System-wide file containing host keys of known hosts.  This file should be  * world-readable.  */
end_comment

begin_define
define|#
directive|define
name|SSH_SYSTEM_HOSTFILE
value|ETCDIR "/ssh_known_hosts"
end_define

begin_define
define|#
directive|define
name|SSH_SYSTEM_HOSTFILE2
value|ETCDIR "/ssh_known_hosts2"
end_define

begin_comment
comment|/*  * Of these, ssh_host_key must be readable only by root, whereas ssh_config  * should be world-readable.  */
end_comment

begin_define
define|#
directive|define
name|HOST_KEY_FILE
value|ETCDIR "/ssh_host_key"
end_define

begin_define
define|#
directive|define
name|SERVER_CONFIG_FILE
value|ETCDIR "/sshd_config"
end_define

begin_define
define|#
directive|define
name|HOST_CONFIG_FILE
value|ETCDIR "/ssh_config"
end_define

begin_define
define|#
directive|define
name|HOST_DSA_KEY_FILE
value|ETCDIR "/ssh_host_dsa_key"
end_define

begin_define
define|#
directive|define
name|DH_PRIMES
value|ETCDIR "/primes"
end_define

begin_define
define|#
directive|define
name|SSH_PROGRAM
value|"/usr/bin/ssh"
end_define

begin_comment
comment|/*  * The process id of the daemon listening for connections is saved here to  * make it easier to kill the correct daemon when necessary.  */
end_comment

begin_define
define|#
directive|define
name|SSH_DAEMON_PID_FILE
value|PIDDIR "/sshd.pid"
end_define

begin_comment
comment|/*  * The directory in user\'s home directory in which the files reside. The  * directory should be world-readable (though not all files are).  */
end_comment

begin_define
define|#
directive|define
name|SSH_USER_DIR
value|".ssh"
end_define

begin_comment
comment|/*  * Per-user file containing host keys of known hosts.  This file need not be  * readable by anyone except the user him/herself, though this does not  * contain anything particularly secret.  */
end_comment

begin_define
define|#
directive|define
name|SSH_USER_HOSTFILE
value|"~/.ssh/known_hosts"
end_define

begin_define
define|#
directive|define
name|SSH_USER_HOSTFILE2
value|"~/.ssh/known_hosts2"
end_define

begin_comment
comment|/*  * Name of the default file containing client-side authentication key. This  * file should only be readable by the user him/herself.  */
end_comment

begin_define
define|#
directive|define
name|SSH_CLIENT_IDENTITY
value|".ssh/identity"
end_define

begin_define
define|#
directive|define
name|SSH_CLIENT_ID_DSA
value|".ssh/id_dsa"
end_define

begin_comment
comment|/*  * Configuration file in user\'s home directory.  This file need not be  * readable by anyone but the user him/herself, but does not contain anything  * particularly secret.  If the user\'s home directory resides on an NFS  * volume where root is mapped to nobody, this may need to be world-readable.  */
end_comment

begin_define
define|#
directive|define
name|SSH_USER_CONFFILE
value|".ssh/config"
end_define

begin_comment
comment|/*  * File containing a list of those rsa keys that permit logging in as this  * user.  This file need not be readable by anyone but the user him/herself,  * but does not contain anything particularly secret.  If the user\'s home  * directory resides on an NFS volume where root is mapped to nobody, this  * may need to be world-readable.  (This file is read by the daemon which is  * running as root.)  */
end_comment

begin_define
define|#
directive|define
name|SSH_USER_PERMITTED_KEYS
value|".ssh/authorized_keys"
end_define

begin_define
define|#
directive|define
name|SSH_USER_PERMITTED_KEYS2
value|".ssh/authorized_keys2"
end_define

begin_comment
comment|/*  * Per-user and system-wide ssh "rc" files.  These files are executed with  * /bin/sh before starting the shell or command if they exist.  They will be  * passed "proto cookie" as arguments if X11 forwarding with spoofing is in  * use.  xauth will be run if neither of these exists.  */
end_comment

begin_define
define|#
directive|define
name|SSH_USER_RC
value|".ssh/rc"
end_define

begin_define
define|#
directive|define
name|SSH_SYSTEM_RC
value|ETCDIR "/sshrc"
end_define

begin_comment
comment|/*  * Ssh-only version of /etc/hosts.equiv.  Additionally, the daemon may use  * ~/.rhosts and /etc/hosts.equiv if rhosts authentication is enabled.  */
end_comment

begin_define
define|#
directive|define
name|SSH_HOSTS_EQUIV
value|ETCDIR "/shosts.equiv"
end_define

begin_comment
comment|/*  * Name of the environment variable containing the pathname of the  * authentication socket.  */
end_comment

begin_define
define|#
directive|define
name|SSH_AUTHSOCKET_ENV_NAME
value|"SSH_AUTH_SOCK"
end_define

begin_comment
comment|/*  * Name of the environment variable containing the pathname of the  * authentication socket.  */
end_comment

begin_define
define|#
directive|define
name|SSH_AGENTPID_ENV_NAME
value|"SSH_AGENT_PID"
end_define

begin_comment
comment|/*  * Default path to ssh-askpass used by ssh-add,  * environment variable for overwriting the default location  */
end_comment

begin_define
define|#
directive|define
name|SSH_ASKPASS_DEFAULT
value|"/usr/X11R6/bin/ssh-askpass"
end_define

begin_define
define|#
directive|define
name|SSH_ASKPASS_ENV
value|"SSH_ASKPASS"
end_define

begin_comment
comment|/*  * Force host key length and server key length to differ by at least this  * many bits.  This is to make double encryption with rsaref work.  */
end_comment

begin_define
define|#
directive|define
name|SSH_KEY_BITS_RESERVED
value|128
end_define

begin_comment
comment|/*  * Length of the session key in bytes.  (Specified as 256 bits in the  * protocol.)  */
end_comment

begin_define
define|#
directive|define
name|SSH_SESSION_KEY_LENGTH
value|32
end_define

begin_comment
comment|/* Name of Kerberos service for SSH to use. */
end_comment

begin_define
define|#
directive|define
name|KRB4_SERVICE_NAME
value|"rcmd"
end_define

begin_comment
comment|/*  * Authentication methods.  New types can be added, but old types should not  * be removed for compatibility.  The maximum allowed value is 31.  */
end_comment

begin_define
define|#
directive|define
name|SSH_AUTH_RHOSTS
value|1
end_define

begin_define
define|#
directive|define
name|SSH_AUTH_RSA
value|2
end_define

begin_define
define|#
directive|define
name|SSH_AUTH_PASSWORD
value|3
end_define

begin_define
define|#
directive|define
name|SSH_AUTH_RHOSTS_RSA
value|4
end_define

begin_define
define|#
directive|define
name|SSH_AUTH_TIS
value|5
end_define

begin_define
define|#
directive|define
name|SSH_AUTH_KERBEROS
value|6
end_define

begin_define
define|#
directive|define
name|SSH_PASS_KERBEROS_TGT
value|7
end_define

begin_comment
comment|/* 8 to 15 are reserved */
end_comment

begin_define
define|#
directive|define
name|SSH_PASS_AFS_TOKEN
value|21
end_define

begin_comment
comment|/* Protocol flags.  These are bit masks. */
end_comment

begin_define
define|#
directive|define
name|SSH_PROTOFLAG_SCREEN_NUMBER
value|1
end_define

begin_comment
comment|/* X11 forwarding includes screen */
end_comment

begin_define
define|#
directive|define
name|SSH_PROTOFLAG_HOST_IN_FWD_OPEN
value|2
end_define

begin_comment
comment|/* forwarding opens contain host */
end_comment

begin_comment
comment|/*  * Definition of message types.  New values can be added, but old values  * should not be removed or without careful consideration of the consequences  * for compatibility.  The maximum value is 254; value 255 is reserved for  * future extension.  */
end_comment

begin_comment
comment|/* Message name */
end_comment

begin_comment
comment|/* msg code */
end_comment

begin_comment
comment|/* arguments */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_NONE
value|0
end_define

begin_comment
comment|/* no message */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_DISCONNECT
value|1
end_define

begin_comment
comment|/* cause (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_PUBLIC_KEY
value|2
end_define

begin_comment
comment|/* ck,msk,srvk,hostk */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_SESSION_KEY
value|3
end_define

begin_comment
comment|/* key (BIGNUM) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_USER
value|4
end_define

begin_comment
comment|/* user (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_RHOSTS
value|5
end_define

begin_comment
comment|/* user (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_RSA
value|6
end_define

begin_comment
comment|/* modulus (BIGNUM) */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_AUTH_RSA_CHALLENGE
value|7
end_define

begin_comment
comment|/* int (BIGNUM) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_RSA_RESPONSE
value|8
end_define

begin_comment
comment|/* int (BIGNUM) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_PASSWORD
value|9
end_define

begin_comment
comment|/* pass (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_REQUEST_PTY
value|10
end_define

begin_comment
comment|/* TERM, tty modes */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_WINDOW_SIZE
value|11
end_define

begin_comment
comment|/* row,col,xpix,ypix */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_EXEC_SHELL
value|12
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_EXEC_CMD
value|13
end_define

begin_comment
comment|/* cmd (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_SUCCESS
value|14
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_FAILURE
value|15
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_STDIN_DATA
value|16
end_define

begin_comment
comment|/* data (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_STDOUT_DATA
value|17
end_define

begin_comment
comment|/* data (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_STDERR_DATA
value|18
end_define

begin_comment
comment|/* data (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_EOF
value|19
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_EXITSTATUS
value|20
end_define

begin_comment
comment|/* status (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_OPEN_CONFIRMATION
value|21
end_define

begin_comment
comment|/* channel (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_OPEN_FAILURE
value|22
end_define

begin_comment
comment|/* channel (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_DATA
value|23
end_define

begin_comment
comment|/* ch,data (int,str) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_CLOSE
value|24
end_define

begin_comment
comment|/* channel (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_CLOSE_CONFIRMATION
value|25
end_define

begin_comment
comment|/* channel (int) */
end_comment

begin_comment
comment|/*      SSH_CMSG_X11_REQUEST_FORWARDING         26         OBSOLETE */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_X11_OPEN
value|27
end_define

begin_comment
comment|/* channel (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_PORT_FORWARD_REQUEST
value|28
end_define

begin_comment
comment|/* p,host,hp (i,s,i) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_PORT_OPEN
value|29
end_define

begin_comment
comment|/* ch,h,p (i,s,i) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AGENT_REQUEST_FORWARDING
value|30
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_AGENT_OPEN
value|31
end_define

begin_comment
comment|/* port (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_IGNORE
value|32
end_define

begin_comment
comment|/* string */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_EXIT_CONFIRMATION
value|33
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_X11_REQUEST_FORWARDING
value|34
end_define

begin_comment
comment|/* proto,data (s,s) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_RHOSTS_RSA
value|35
end_define

begin_comment
comment|/* user,mod (s,mpi) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_DEBUG
value|36
end_define

begin_comment
comment|/* string */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_REQUEST_COMPRESSION
value|37
end_define

begin_comment
comment|/* level 1-9 (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_MAX_PACKET_SIZE
value|38
end_define

begin_comment
comment|/* size 4k-1024k (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_TIS
value|39
end_define

begin_comment
comment|/* we use this for s/key */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_AUTH_TIS_CHALLENGE
value|40
end_define

begin_comment
comment|/* challenge (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_TIS_RESPONSE
value|41
end_define

begin_comment
comment|/* response (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_KERBEROS
value|42
end_define

begin_comment
comment|/* (KTEXT) */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_AUTH_KERBEROS_RESPONSE
value|43
end_define

begin_comment
comment|/* (KTEXT) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_HAVE_KERBEROS_TGT
value|44
end_define

begin_define
define|#
directive|define
name|SSH_CMSG_HAVE_AFS_TOKEN
value|65
end_define

begin_comment
comment|/* token (s) */
end_comment

begin_comment
comment|/* Kerberos IV tickets can't be forwarded. This is an AFS hack! */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_HAVE_KRB4_TGT
value|SSH_CMSG_HAVE_KERBEROS_TGT
end_define

begin_comment
comment|/* credentials (s) */
end_comment

begin_comment
comment|/*------------ definitions for login.c -------------*/
end_comment

begin_comment
comment|/*  * Returns the time when the user last logged in.  Returns 0 if the  * information is not available.  This must be called before record_login.  * The host from which the user logged in is stored in buf.  */
end_comment

begin_function_decl
name|unsigned
name|long
name|get_last_login_time
parameter_list|(
name|uid_t
name|uid
parameter_list|,
specifier|const
name|char
modifier|*
name|logname
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|bufsize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Records that the user has logged in.  This does many things normally done  * by login(1).  */
end_comment

begin_function_decl
name|void
name|record_login
parameter_list|(
name|pid_t
name|pid
parameter_list|,
specifier|const
name|char
modifier|*
name|ttyname
parameter_list|,
specifier|const
name|char
modifier|*
name|user
parameter_list|,
name|uid_t
name|uid
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Records that the user has logged out.  This does many thigs normally done  * by login(1) or init.  */
end_comment

begin_function_decl
name|void
name|record_logout
parameter_list|(
name|pid_t
name|pid
parameter_list|,
specifier|const
name|char
modifier|*
name|ttyname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*------------ definitions for sshconnect.c ----------*/
end_comment

begin_comment
comment|/*  * Opens a TCP/IP connection to the remote server on the given host.  If port  * is 0, the default port will be used.  If anonymous is zero, a privileged  * port will be allocated to make the connection. This requires super-user  * privileges if anonymous is false. Connection_attempts specifies the  * maximum number of tries, one per second.  This returns true on success,  * and zero on failure.  If the connection is successful, this calls  * packet_set_connection for the connection.  */
end_comment

begin_function_decl
name|int
name|ssh_connect
parameter_list|(
name|char
modifier|*
modifier|*
name|host
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|hostaddr
parameter_list|,
name|u_short
name|port
parameter_list|,
name|int
name|connection_attempts
parameter_list|,
name|int
name|anonymous
parameter_list|,
name|uid_t
name|original_real_uid
parameter_list|,
specifier|const
name|char
modifier|*
name|proxy_command
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Starts a dialog with the server, and authenticates the current user on the  * server.  This does not need any extra privileges.  The basic connection to  * the server must already have been established before this is called. If  * login fails, this function prints an error and never returns. This  * initializes the random state, and leaves it initialized (it will also have  * references from the packet module).  */
end_comment

begin_function_decl
name|void
name|ssh_login
parameter_list|(
name|int
name|host_key_valid
parameter_list|,
name|RSA
modifier|*
name|host_key
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|hostaddr
parameter_list|,
name|uid_t
name|original_real_uid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*------------ Definitions for various authentication methods. -------*/
end_comment

begin_comment
comment|/*  * Tries to authenticate the user using the .rhosts file.  Returns true if  * authentication succeeds.  If ignore_rhosts is non-zero, this will not  * consider .rhosts and .shosts (/etc/hosts.equiv will still be used).  */
end_comment

begin_function_decl
name|int
name|auth_rhosts
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|client_user
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Tries to authenticate the user using the .rhosts file and the host using  * its host key.  Returns true if authentication succeeds.  */
end_comment

begin_function_decl
name|int
name|auth_rhosts_rsa
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|client_user
parameter_list|,
name|RSA
modifier|*
name|client_host_key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Tries to authenticate the user using password.  Returns true if  * authentication succeeds.  */
end_comment

begin_function_decl
name|int
name|auth_password
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Performs the RSA authentication dialog with the client.  This returns 0 if  * the client could not be authenticated, and 1 if authentication was  * successful.  This may exit if there is a serious protocol violation.  */
end_comment

begin_function_decl
name|int
name|auth_rsa
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
name|BIGNUM
modifier|*
name|client_n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Parses an RSA key (number of bits, e, n) from a string.  Moves the pointer  * over the key.  Skips any whitespace at the beginning and at end.  */
end_comment

begin_function_decl
name|int
name|auth_rsa_read_key
parameter_list|(
name|char
modifier|*
modifier|*
name|cpp
parameter_list|,
name|unsigned
name|int
modifier|*
name|bitsp
parameter_list|,
name|BIGNUM
modifier|*
name|e
parameter_list|,
name|BIGNUM
modifier|*
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the name of the machine at the other end of the socket.  The  * returned string should be freed by the caller.  */
end_comment

begin_function_decl
name|char
modifier|*
name|get_remote_hostname
parameter_list|(
name|int
name|socket
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the canonical name of the host in the other side of the current  * connection (as returned by packet_get_connection).  The host name is  * cached, so it is efficient to call this several times.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|get_canonical_hostname
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the local IP address as an ascii string.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|get_ipaddr
parameter_list|(
name|int
name|socket
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the remote IP address as an ascii string.  The value need not be  * freed by the caller.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|get_remote_ipaddr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the port number of the peer of the socket. */
end_comment

begin_function_decl
name|int
name|get_peer_port
parameter_list|(
name|int
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the port number of the remote/local host. */
end_comment

begin_function_decl
name|int
name|get_remote_port
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_local_port
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Performs the RSA authentication challenge-response dialog with the client,  * and returns true (non-zero) if the client gave the correct answer to our  * challenge; returns zero if the client gives a wrong answer.  */
end_comment

begin_function_decl
name|int
name|auth_rsa_challenge_dialog
parameter_list|(
name|RSA
modifier|*
name|pk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reads a passphrase from /dev/tty with echo turned off.  Returns the  * passphrase (allocated with xmalloc).  Exits if EOF is encountered. If  * from_stdin is true, the passphrase will be read from stdin instead.  */
end_comment

begin_function_decl
name|char
modifier|*
name|read_passphrase
parameter_list|(
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|from_stdin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*------------ Definitions for logging. -----------------------*/
end_comment

begin_comment
comment|/* Supported syslog facilities and levels. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SYSLOG_FACILITY_DAEMON
block|,
name|SYSLOG_FACILITY_USER
block|,
name|SYSLOG_FACILITY_AUTH
block|,
name|SYSLOG_FACILITY_LOCAL0
block|,
name|SYSLOG_FACILITY_LOCAL1
block|,
name|SYSLOG_FACILITY_LOCAL2
block|,
name|SYSLOG_FACILITY_LOCAL3
block|,
name|SYSLOG_FACILITY_LOCAL4
block|,
name|SYSLOG_FACILITY_LOCAL5
block|,
name|SYSLOG_FACILITY_LOCAL6
block|,
name|SYSLOG_FACILITY_LOCAL7
block|}
name|SyslogFacility
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|SYSLOG_LEVEL_QUIET
block|,
name|SYSLOG_LEVEL_FATAL
block|,
name|SYSLOG_LEVEL_ERROR
block|,
name|SYSLOG_LEVEL_INFO
block|,
name|SYSLOG_LEVEL_VERBOSE
block|,
name|SYSLOG_LEVEL_DEBUG1
block|,
name|SYSLOG_LEVEL_DEBUG2
block|,
name|SYSLOG_LEVEL_DEBUG3
block|}
name|LogLevel
typedef|;
end_typedef

begin_comment
comment|/* Initializes logging. */
end_comment

begin_function_decl
name|void
name|log_init
parameter_list|(
name|char
modifier|*
name|av0
parameter_list|,
name|LogLevel
name|level
parameter_list|,
name|SyslogFacility
name|facility
parameter_list|,
name|int
name|on_stderr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Logging implementation, depending on server or client */
end_comment

begin_function_decl
name|void
name|do_log
parameter_list|(
name|LogLevel
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* name to facility/level */
end_comment

begin_function_decl
name|SyslogFacility
name|log_facility_number
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LogLevel
name|log_level_number
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output a message to syslog or stderr */
end_comment

begin_function_decl
name|void
name|fatal
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|error
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|log
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|verbose
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|debug
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|debug2
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|debug3
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* same as fatal() but w/o logging */
end_comment

begin_function_decl
name|void
name|fatal_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Registers a cleanup function to be called by fatal()/fatal_cleanup()  * before exiting. It is permissible to call fatal_remove_cleanup for the  * function itself from the function.  */
end_comment

begin_function_decl
name|void
name|fatal_add_cleanup
parameter_list|(
name|void
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Removes a cleanup function to be called at fatal(). */
end_comment

begin_function_decl
name|void
name|fatal_remove_cleanup
parameter_list|(
name|void
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ---- misc */
end_comment

begin_comment
comment|/*  * Expands tildes in the file name.  Returns data allocated by xmalloc.  * Warning: this calls getpw*.  */
end_comment

begin_function_decl
name|char
modifier|*
name|tilde_expand_filename
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|uid_t
name|my_uid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* remove newline at end of string */
end_comment

begin_function_decl
name|char
modifier|*
name|chop
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return next token in configuration line */
end_comment

begin_function_decl
name|char
modifier|*
name|strdelim
parameter_list|(
name|char
modifier|*
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set filedescriptor to non-blocking */
end_comment

begin_function_decl
name|void
name|set_nonblock
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Performs the interactive session.  This handles data transmission between  * the client and the program.  Note that the notion of stdin, stdout, and  * stderr in this function is sort of reversed: this function writes to stdin  * (of the child program), and reads from stdout and stderr (of the child  * program).  */
end_comment

begin_function_decl
name|void
name|server_loop
parameter_list|(
name|pid_t
name|pid
parameter_list|,
name|int
name|fdin
parameter_list|,
name|int
name|fdout
parameter_list|,
name|int
name|fderr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|server_loop2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Client side main loop for the interactive session. */
end_comment

begin_function_decl
name|int
name|client_loop
parameter_list|(
name|int
name|have_pty
parameter_list|,
name|int
name|escape_char
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Linked list of custom environment strings (see auth-rsa.c). */
end_comment

begin_struct
struct|struct
name|envstring
block|{
name|struct
name|envstring
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ensure all of data on socket comes through. f==read || f==write  */
end_comment

begin_function_decl
name|ssize_t
name|atomicio
parameter_list|(
name|ssize_t
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|()
parameter_list|,
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|s
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|int
name|auth_krb5
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* XXX Doplnit prototypy */
end_comment

begin_function_decl
name|int
name|auth_krb5_tgt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb5_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|krb5_cleanup_proc
parameter_list|(
name|void
modifier|*
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_krb5_password
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KRB5 */
end_comment

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

begin_comment
comment|/*  * Performs Kerberos v4 mutual authentication with the client. This returns 0  * if the client could not be authenticated, and 1 if authentication was  * successful.  This may exit if there is a serious protocol violation.  */
end_comment

begin_function_decl
name|int
name|auth_krb4
parameter_list|(
specifier|const
name|char
modifier|*
name|server_user
parameter_list|,
name|KTEXT
name|auth
parameter_list|,
name|char
modifier|*
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb4_init
parameter_list|(
name|uid_t
name|uid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|krb4_cleanup_proc
parameter_list|(
name|void
modifier|*
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_krb4_password
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|AFS
end_ifdef

begin_include
include|#
directive|include
file|<kafs.h>
end_include

begin_comment
comment|/* Accept passed Kerberos v4 ticket-granting ticket and AFS tokens. */
end_comment

begin_function_decl
name|int
name|auth_krb4_tgt
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_afs_token
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|token_string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|creds_to_radix
parameter_list|(
name|CREDENTIALS
modifier|*
name|creds
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|radix_to_creds
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|CREDENTIALS
modifier|*
name|creds
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AFS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KRB4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SKEY
end_ifdef

begin_include
include|#
directive|include
file|<opie.h>
end_include

begin_function_decl
name|char
modifier|*
name|skey_fake_keyinfo
parameter_list|(
name|char
modifier|*
name|username
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_skey_password
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SKEY */
end_comment

begin_comment
comment|/* AF_UNSPEC or AF_INET or AF_INET6 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|IPv4or6
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PAM
end_ifdef

begin_include
include|#
directive|include
file|"auth-pam.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_PAM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SSH_H */
end_comment

end_unit

