begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: pathnames.h,v 1.11 2002/02/09 17:37:34 deraadt Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_define
define|#
directive|define
name|ETCDIR
value|"/etc"
end_define

begin_define
define|#
directive|define
name|SSHDIR
value|ETCDIR "/ssh"
end_define

begin_define
define|#
directive|define
name|_PATH_SSH_PIDDIR
value|"/var/run"
end_define

begin_comment
comment|/*  * System-wide file containing host keys of known hosts.  This file should be  * world-readable.  */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_SYSTEM_HOSTFILE
value|SSHDIR "/ssh_known_hosts"
end_define

begin_comment
comment|/* backward compat for protocol 2 */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_SYSTEM_HOSTFILE2
value|SSHDIR "/ssh_known_hosts2"
end_define

begin_comment
comment|/*  * Of these, ssh_host_key must be readable only by root, whereas ssh_config  * should be world-readable.  */
end_comment

begin_define
define|#
directive|define
name|_PATH_SERVER_CONFIG_FILE
value|SSHDIR "/sshd_config"
end_define

begin_define
define|#
directive|define
name|_PATH_HOST_CONFIG_FILE
value|SSHDIR "/ssh_config"
end_define

begin_define
define|#
directive|define
name|_PATH_HOST_KEY_FILE
value|SSHDIR "/ssh_host_key"
end_define

begin_define
define|#
directive|define
name|_PATH_HOST_DSA_KEY_FILE
value|SSHDIR "/ssh_host_dsa_key"
end_define

begin_define
define|#
directive|define
name|_PATH_HOST_RSA_KEY_FILE
value|SSHDIR "/ssh_host_rsa_key"
end_define

begin_define
define|#
directive|define
name|_PATH_DH_MODULI
value|ETCDIR "/moduli"
end_define

begin_comment
comment|/* Backwards compatibility */
end_comment

begin_define
define|#
directive|define
name|_PATH_DH_PRIMES
value|ETCDIR "/primes"
end_define

begin_define
define|#
directive|define
name|_PATH_SSH_PROGRAM
value|"/usr/bin/ssh"
end_define

begin_comment
comment|/*  * The process id of the daemon listening for connections is saved here to  * make it easier to kill the correct daemon when necessary.  */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_DAEMON_PID_FILE
value|_PATH_SSH_PIDDIR "/sshd.pid"
end_define

begin_comment
comment|/*  * The directory in user\'s home directory in which the files reside. The  * directory should be world-readable (though not all files are).  */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_USER_DIR
value|".ssh"
end_define

begin_comment
comment|/*  * Per-user file containing host keys of known hosts.  This file need not be  * readable by anyone except the user him/herself, though this does not  * contain anything particularly secret.  */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_USER_HOSTFILE
value|"~/.ssh/known_hosts"
end_define

begin_comment
comment|/* backward compat for protocol 2 */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_USER_HOSTFILE2
value|"~/.ssh/known_hosts2"
end_define

begin_comment
comment|/*  * Name of the default file containing client-side authentication key. This  * file should only be readable by the user him/herself.  */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_CLIENT_IDENTITY
value|".ssh/identity"
end_define

begin_define
define|#
directive|define
name|_PATH_SSH_CLIENT_ID_DSA
value|".ssh/id_dsa"
end_define

begin_define
define|#
directive|define
name|_PATH_SSH_CLIENT_ID_RSA
value|".ssh/id_rsa"
end_define

begin_comment
comment|/*  * Configuration file in user\'s home directory.  This file need not be  * readable by anyone but the user him/herself, but does not contain anything  * particularly secret.  If the user\'s home directory resides on an NFS  * volume where root is mapped to nobody, this may need to be world-readable.  */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_USER_CONFFILE
value|".ssh/config"
end_define

begin_comment
comment|/*  * File containing a list of those rsa keys that permit logging in as this  * user.  This file need not be readable by anyone but the user him/herself,  * but does not contain anything particularly secret.  If the user\'s home  * directory resides on an NFS volume where root is mapped to nobody, this  * may need to be world-readable.  (This file is read by the daemon which is  * running as root.)  */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_USER_PERMITTED_KEYS
value|".ssh/authorized_keys"
end_define

begin_comment
comment|/* backward compat for protocol v2 */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_USER_PERMITTED_KEYS2
value|".ssh/authorized_keys2"
end_define

begin_comment
comment|/*  * Per-user and system-wide ssh "rc" files.  These files are executed with  * /bin/sh before starting the shell or command if they exist.  They will be  * passed "proto cookie" as arguments if X11 forwarding with spoofing is in  * use.  xauth will be run if neither of these exists.  */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_USER_RC
value|".ssh/rc"
end_define

begin_define
define|#
directive|define
name|_PATH_SSH_SYSTEM_RC
value|SSHDIR "/sshrc"
end_define

begin_comment
comment|/*  * Ssh-only version of /etc/hosts.equiv.  Additionally, the daemon may use  * ~/.rhosts and /etc/hosts.equiv if rhosts authentication is enabled.  */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_HOSTS_EQUIV
value|ETCDIR "/shosts.equiv"
end_define

begin_define
define|#
directive|define
name|_PATH_RHOSTS_EQUIV
value|"/etc/hosts.equiv"
end_define

begin_comment
comment|/*  * Default location of askpass  */
end_comment

begin_define
define|#
directive|define
name|_PATH_SSH_ASKPASS_DEFAULT
value|"/usr/X11R6/bin/ssh-askpass"
end_define

begin_comment
comment|/* xauth for X11 forwarding */
end_comment

begin_define
define|#
directive|define
name|_PATH_XAUTH
value|"/usr/X11R6/bin/xauth"
end_define

begin_comment
comment|/* UNIX domain socket for X11 server; displaynum will replace %u */
end_comment

begin_define
define|#
directive|define
name|_PATH_UNIX_X
value|"/tmp/.X11-unix/X%u"
end_define

begin_comment
comment|/* for scp */
end_comment

begin_define
define|#
directive|define
name|_PATH_CP
value|"cp"
end_define

begin_comment
comment|/* for sftp */
end_comment

begin_define
define|#
directive|define
name|_PATH_SFTP_SERVER
value|"/usr/libexec/sftp-server"
end_define

begin_define
define|#
directive|define
name|_PATH_LS
value|"ls"
end_define

end_unit

