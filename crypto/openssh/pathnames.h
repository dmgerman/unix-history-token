begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: pathnames.h,v 1.13 2002/05/23 19:24:30 markus Exp $	*/
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

begin_ifndef
ifndef|#
directive|ifndef
name|SSHDIR
end_ifndef

begin_define
define|#
directive|define
name|SSHDIR
value|ETCDIR "/ssh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SSH_PIDDIR
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SSH_PIDDIR
value|"/var/run"
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|SSHDIR "/moduli"
end_define

begin_comment
comment|/* Backwards compatibility */
end_comment

begin_define
define|#
directive|define
name|_PATH_DH_PRIMES
value|SSHDIR "/primes"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SSH_PROGRAM
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SSH_PROGRAM
value|"/usr/bin/ssh"
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|SSHDIR "/shosts.equiv"
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

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SSH_ASKPASS_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SSH_ASKPASS_DEFAULT
value|"/usr/X11R6/bin/ssh-askpass"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Location of ssh-keysign for hostbased authentication */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SSH_KEY_SIGN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SSH_KEY_SIGN
value|"/usr/libexec/ssh-keysign"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* xauth for X11 forwarding */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_XAUTH
end_ifndef

begin_define
define|#
directive|define
name|_PATH_XAUTH
value|"/usr/X11R6/bin/xauth"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX domain socket for X11 server; displaynum will replace %u */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UNIX_X
end_ifndef

begin_define
define|#
directive|define
name|_PATH_UNIX_X
value|"/tmp/.X11-unix/X%u"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* for scp */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_CP
end_ifndef

begin_define
define|#
directive|define
name|_PATH_CP
value|"cp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* for sftp */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SFTP_SERVER
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SFTP_SERVER
value|"/usr/libexec/sftp-server"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* chroot directory for unprivileged user when UsePrivilegeSeparation=yes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_PRIVSEP_CHROOT_DIR
end_ifndef

begin_define
define|#
directive|define
name|_PATH_PRIVSEP_CHROOT_DIR
value|"/var/empty"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_LS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_LS
value|"ls"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* path to login program */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOGIN_PROGRAM
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|LOGIN_PROGRAM_FALLBACK
end_ifdef

begin_define
define|#
directive|define
name|LOGIN_PROGRAM
value|LOGIN_PROGRAM_FALLBACK
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOGIN_PROGRAM
value|"/usr/bin/login"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOGIN_PROGRAM */
end_comment

begin_comment
comment|/* Askpass program define */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASKPASS_PROGRAM
end_ifndef

begin_define
define|#
directive|define
name|ASKPASS_PROGRAM
value|"/usr/lib/ssh/ssh-askpass"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASKPASS_PROGRAM */
end_comment

end_unit

