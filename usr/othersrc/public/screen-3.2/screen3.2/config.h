begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* from libove@libove.det.dec.com (Jay Vassos-Libove)  ****************************************************************  * $Id: config.bsd386,v 1.2 92/02/03 02:30:42 jnweiger Exp $ FAU  */
end_comment

begin_define
define|#
directive|define
name|POSIX
end_define

begin_define
define|#
directive|define
name|BSDJOBS
end_define

begin_define
define|#
directive|define
name|TERMIO
end_define

begin_undef
undef|#
directive|undef
name|TERMINFO
end_undef

begin_undef
undef|#
directive|undef
name|SYSV
end_undef

begin_define
define|#
directive|define
name|SIGVOID
end_define

begin_define
define|#
directive|define
name|DIRENT
end_define

begin_define
define|#
directive|define
name|SUIDROOT
end_define

begin_define
define|#
directive|define
name|UTMPOK
end_define

begin_define
define|#
directive|define
name|LOGINDEFAULT
value|1
end_define

begin_undef
undef|#
directive|undef
name|GETUTENT
end_undef

begin_define
define|#
directive|define
name|UTHOST
end_define

begin_undef
undef|#
directive|undef
name|USRLIMIT
end_undef

begin_undef
undef|#
directive|undef
name|LOCKPTY
end_undef

begin_undef
undef|#
directive|undef
name|NOREUID
end_undef

begin_define
define|#
directive|define
name|LOADAV_3DOUBLES
end_define

begin_undef
undef|#
directive|undef
name|LOADAV_3LONGS
end_undef

begin_undef
undef|#
directive|undef
name|LOADAV_4LONGS
end_undef

begin_define
define|#
directive|define
name|GETTTYENT
end_define

begin_undef
undef|#
directive|undef
name|NFS_HACK
end_undef

begin_undef
undef|#
directive|undef
name|LOCALSOCKDIR
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|LOCALSOCKDIR
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|TMPTEST
end_ifndef

begin_define
define|#
directive|define
name|SOCKDIR
value|"/tmp/screens"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SOCKDIR
value|"/tmp/testscreens"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USEBCOPY
end_define

begin_undef
undef|#
directive|undef
name|TOPSTAT
end_undef

begin_define
define|#
directive|define
name|USEVARARGS
end_define

begin_undef
undef|#
directive|undef
name|NAMEDPIPE
end_undef

begin_define
define|#
directive|define
name|LOCK
end_define

begin_define
define|#
directive|define
name|PASSWORD
end_define

begin_define
define|#
directive|define
name|COPY_PASTE
end_define

begin_define
define|#
directive|define
name|REMOTE_DETACH
end_define

begin_define
define|#
directive|define
name|POW_DETACH
end_define

begin_define
define|#
directive|define
name|NETHACK
end_define

begin_define
define|#
directive|define
name|ETCSCREENRC
value|"/usr/local/etc/screenrc"
end_define

begin_comment
comment|/* These get seen in screen.h, extern.h and other places to avoid conflicts  * with the definitions and declarations in /usr/include/...  * on BSD/386 from BSD, Inc.  */
end_comment

begin_comment
comment|/* modified for 386BSD by rich@rice.edu */
end_comment

begin_define
define|#
directive|define
name|SIG_T_DEFINED
end_define

begin_define
define|#
directive|define
name|PID_T_DEFINED
end_define

begin_define
define|#
directive|define
name|MEMFUNCS_DECLARED
end_define

begin_define
define|#
directive|define
name|WAITSTUFF_DECLARED
end_define

begin_define
define|#
directive|define
name|KILLSTUFF_DECLARED
end_define

begin_define
define|#
directive|define
name|REUID_DECLARED
end_define

begin_define
define|#
directive|define
name|CRYPT_DECLARED
end_define

begin_define
define|#
directive|define
name|MKNOD_DECLARED
end_define

begin_define
define|#
directive|define
name|PUTENV_DECLARED
end_define

begin_define
define|#
directive|define
name|SETPGID_DECLARED
end_define

begin_define
define|#
directive|define
name|GETHOSTNAME_DECLARED
end_define

begin_define
define|#
directive|define
name|VPRNT_DECLARED
end_define

begin_define
define|#
directive|define
name|NLIST_DECLARED
end_define

end_unit

