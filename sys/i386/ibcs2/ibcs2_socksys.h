begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, 1995 Scott Bartram  * Copyright (c) 1994 Arne H Juul  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_IBCS2_IBCS2_SOCKSYS_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_IBCS2_IBCS2_SOCKSYS_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_types.h>
end_include

begin_define
define|#
directive|define
name|SOCKSYS_ACCEPT
value|1
end_define

begin_define
define|#
directive|define
name|SOCKSYS_BIND
value|2
end_define

begin_define
define|#
directive|define
name|SOCKSYS_CONNECT
value|3
end_define

begin_define
define|#
directive|define
name|SOCKSYS_GETPEERNAME
value|4
end_define

begin_define
define|#
directive|define
name|SOCKSYS_GETSOCKNAME
value|5
end_define

begin_define
define|#
directive|define
name|SOCKSYS_GETSOCKOPT
value|6
end_define

begin_define
define|#
directive|define
name|SOCKSYS_LISTEN
value|7
end_define

begin_define
define|#
directive|define
name|SOCKSYS_RECV
value|8
end_define

begin_define
define|#
directive|define
name|SOCKSYS_RECVFROM
value|9
end_define

begin_define
define|#
directive|define
name|SOCKSYS_SEND
value|10
end_define

begin_define
define|#
directive|define
name|SOCKSYS_SENDTO
value|11
end_define

begin_define
define|#
directive|define
name|SOCKSYS_SETSOCKOPT
value|12
end_define

begin_define
define|#
directive|define
name|SOCKSYS_SHUTDOWN
value|13
end_define

begin_define
define|#
directive|define
name|SOCKSYS_SOCKET
value|14
end_define

begin_define
define|#
directive|define
name|SOCKSYS_SELECT
value|15
end_define

begin_define
define|#
directive|define
name|SOCKSYS_GETIPDOMAIN
value|16
end_define

begin_define
define|#
directive|define
name|SOCKSYS_SETIPDOMAIN
value|17
end_define

begin_define
define|#
directive|define
name|SOCKSYS_ADJTIME
value|18
end_define

begin_define
define|#
directive|define
name|SOCKSYS_SETREUID
value|19
end_define

begin_define
define|#
directive|define
name|SOCKSYS_SETREGID
value|20
end_define

begin_define
define|#
directive|define
name|SOCKSYS_GETTIME
value|21
end_define

begin_define
define|#
directive|define
name|SOCKSYS_SETTIME
value|22
end_define

begin_define
define|#
directive|define
name|SOCKSYS_GETITIMER
value|23
end_define

begin_define
define|#
directive|define
name|SOCKSYS_SETITIMER
value|24
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSHIWAT
value|_IOW('S', 1, int)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGHIWAT
value|_IOR('S', 2, int)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSLOWAT
value|_IOW('S', 3, int)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGLOWAT
value|_IOR('S', 4, int)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCATMARK
value|_IOR('S', 5, int)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSPGRP
value|_IOW('S', 6, int)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGPGRP
value|_IOR('S', 7, int)
end_define

begin_define
define|#
directive|define
name|IBCS2_FIONREAD
value|_IOR('S', 8, int)
end_define

begin_define
define|#
directive|define
name|IBCS2_FIONBIO
value|_IOW('S', 9, int)
end_define

begin_define
define|#
directive|define
name|IBCS2_FIOASYNC
value|_IOW('S', 10, int)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCPROTO
value|_IOW('S', 11, struct socknewproto)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGETNAME
value|_IOR('S', 12, struct sockaddr)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGETPEER
value|_IOR('S', 13, struct sockaddr)
end_define

begin_define
define|#
directive|define
name|IBCS2_IF_UNITSEL
value|_IOW('S', 14, int)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCXPROTO
value|_IO('S', 15)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCADDRT
value|_IOW('R', 9, struct rtentry)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCDELRT
value|_IOW('R', 10, struct rtentry)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSIFADDR
value|_IOW('I', 11, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGIFADDR
value|_IOWR('I', 12, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSIFDSTADDR
value|_IOW('I', 13, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGIFDSTADDR
value|_IOWR('I', 14, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSIFFLAGS
value|_IOW('I', 15, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGIFFLAGS
value|_IOWR('I', 16, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGIFCONF
value|_IOWR('I', 17, struct ifconf)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSIFMTU
value|_IOW('I', 21, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGIFMTU
value|_IOWR('I', 22, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCIFDETACH
value|_IOW('I', 26, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGENPSTATS
value|_IOWR('I', 27, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCX25XMT
value|_IOWR('I', 29, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCX25RCV
value|_IOWR('I', 30, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCX25TBL
value|_IOWR('I', 31, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGIFBRDADDR
value|_IOWR('I', 32, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSIFBRDADDR
value|_IOW('I', 33, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGIFNETMASK
value|_IOWR('I', 34, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSIFNETMASK
value|_IOW('I', 35, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGIFMETRIC
value|_IOWR('I', 36, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSIFMETRIC
value|_IOW('I', 37, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSARP
value|_IOW('I', 38, struct arpreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGARP
value|_IOWR('I', 39, struct arpreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCDARP
value|_IOW('I', 40, struct arpreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSIFNAME
value|_IOW('I', 41, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGIFONEP
value|_IOWR('I', 42, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSIFONEP
value|_IOW('I', 43, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCGENADDR
value|_IOWR('I', 65, struct ifreq)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIOCSOCKSYS
value|_IOW('I', 66, struct socksysreq)
end_define

begin_struct
struct|struct
name|socksysreq
block|{
name|int
name|realargs
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|socknewproto
block|{
name|int
name|family
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|proto
decl_stmt|;
name|ibcs2_dev_t
name|dev
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ibcs2_socksys_args
block|{
name|int
name|fd
decl_stmt|;
name|int
name|magic
decl_stmt|;
name|caddr_t
name|argsp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|ibcs2_socksys
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|ibcs2_socksys_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_IBCS2_IBCS2_SOCKSYS_H_ */
end_comment

end_unit

