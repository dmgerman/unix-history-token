begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|CAN_RECONNECT
end_define

begin_define
define|#
directive|define
name|USE_POSIX
end_define

begin_define
define|#
directive|define
name|POSIX_SIGNALS
end_define

begin_define
define|#
directive|define
name|USE_UTIME
end_define

begin_define
define|#
directive|define
name|USE_WAITPID
end_define

begin_define
define|#
directive|define
name|HAVE_GETRUSAGE
end_define

begin_define
define|#
directive|define
name|HAVE_FCHMOD
end_define

begin_define
define|#
directive|define
name|NEED_PSELECT
end_define

begin_define
define|#
directive|define
name|HAVE_SA_LEN
end_define

begin_define
define|#
directive|define
name|HAVE_MINIMUM_IFREQ
end_define

begin_define
define|#
directive|define
name|USE_LOG_CONS
end_define

begin_define
define|#
directive|define
name|HAVE_CHROOT
end_define

begin_define
define|#
directive|define
name|CAN_CHANGE_ID
end_define

begin_define
define|#
directive|define
name|_TIMEZONE
value|timezone
end_define

begin_define
define|#
directive|define
name|PORT_NONBLOCK
value|O_NONBLOCK
end_define

begin_define
define|#
directive|define
name|PORT_WOULDBLK
value|EWOULDBLOCK
end_define

begin_define
define|#
directive|define
name|WAIT_T
value|int
end_define

begin_define
define|#
directive|define
name|KSYMS
value|"/kernel"
end_define

begin_define
define|#
directive|define
name|KMEM
value|"/dev/kmem"
end_define

begin_define
define|#
directive|define
name|UDPSUM
value|"udpcksum"
end_define

begin_comment
comment|/*  * We need to know the IPv6 address family number even on IPv4-only systems.  * Note that this is NOT a protocol constant, and that if the system has its  * own AF_INET6, different from ours below, all of BIND's libraries and  * executables will need to be recompiled after the system<sys/socket.h>  * has had this type added.  The type number below is correct on most BSD-  * derived systems for which AF_INET6 is defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AF_INET6
end_ifndef

begin_define
define|#
directive|define
name|AF_INET6
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

