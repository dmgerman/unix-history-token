begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Mostyn Lewis  * All rights reserved.  *  * This software is based on code which is:  * Copyright (c) 1994  Mike Jagdis (jaggy@purplet.demon.co.uk)  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|ss_call
block|{
name|int
name|arg
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Alien socket */
end_comment

begin_struct
struct|struct
name|alien_sockaddr
block|{
name|unsigned
name|short
name|sa_family
decl_stmt|;
comment|/* address family, AF_xxx       */
name|char
name|sa_data
index|[
literal|14
index|]
decl_stmt|;
comment|/* 14 bytes of protocol address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|alien_in_addr
block|{
name|unsigned
name|long
name|int
name|s_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|__ALIEN_SOCK_SIZE__
value|16
end_define

begin_comment
comment|/* sizeof(struct alien_sockaddr)*/
end_comment

begin_struct
struct|struct
name|alien_sockaddr_in
block|{
name|short
name|int
name|sin_family
decl_stmt|;
comment|/* Address family               */
name|unsigned
name|short
name|int
name|sin_port
decl_stmt|;
comment|/* Port number                  */
name|struct
name|alien_in_addr
name|sin_addr
decl_stmt|;
comment|/* Internet address             */
name|unsigned
name|char
name|__filling
index|[
name|__ALIEN_SOCK_SIZE__
operator|-
expr|sizeof
operator|(
name|short
name|int
operator|)
operator|-
expr|sizeof
operator|(
name|unsigned
name|short
name|int
operator|)
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|alien_in_addr
argument_list|)
expr|]
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sgdomarg
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|namelen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lstatarg
block|{
name|char
modifier|*
name|fname
decl_stmt|;
name|void
modifier|*
name|statb
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
comment|/* address family (AF_INET, etc.) */
name|int
name|type
decl_stmt|;
comment|/* protocol type (SOCK_STREAM, etc.) */
name|int
name|proto
decl_stmt|;
comment|/* per family proto number */
name|dev_t
name|dev
decl_stmt|;
comment|/* major/minor to use (must be a clone) */
name|int
name|flags
decl_stmt|;
comment|/* protosw flags */
block|}
struct|;
end_struct

begin_comment
comment|/* System type ordinals */
end_comment

begin_define
define|#
directive|define
name|SS_FREEBSD
value|0
end_define

begin_define
define|#
directive|define
name|SS_SYSVR4
value|1
end_define

begin_define
define|#
directive|define
name|SS_SYSVR3
value|2
end_define

begin_define
define|#
directive|define
name|SS_SCO_32
value|3
end_define

begin_define
define|#
directive|define
name|SS_WYSE_321
value|4
end_define

begin_define
define|#
directive|define
name|SS_ISC
value|5
end_define

begin_define
define|#
directive|define
name|SS_LINUX
value|6
end_define

begin_comment
comment|/* Socksys macros */
end_comment

begin_define
define|#
directive|define
name|IOCTL
parameter_list|(
name|cmd
parameter_list|)
define|\
value|if(error = ss_IOCTL(fp, cmd, arg, p))\ 	return(error);
end_define

begin_define
define|#
directive|define
name|SYSCALL
parameter_list|(
name|number
parameter_list|,
name|conv_arg
parameter_list|,
name|indicator
parameter_list|)
define|\
value|if(error = ss_SYSCALL(number,conv_arg,indicator,arg,p,retval))\ 	return(error);
end_define

begin_define
define|#
directive|define
name|SYSCALL_N
parameter_list|(
name|number
parameter_list|,
name|conv_arg
parameter_list|,
name|indicator
parameter_list|)
define|\
value|arg = (caddr_t)(((int *)arg) - 1);\   if(error = ss_SYSCALL(number,conv_arg,indicator,arg,p,retval))\ 	return(error);
end_define

begin_define
define|#
directive|define
name|SYSCALLX
parameter_list|(
name|number
parameter_list|,
name|arg
parameter_list|)
value|(*sysent[number].sy_call)(p, (caddr_t)arg, retval)
end_define

begin_define
define|#
directive|define
name|SYSCALL_RETURN
parameter_list|(
name|number
parameter_list|)
value|SYSCALL(number) ; IBCS2_MAGIC_RETURN
end_define

begin_comment
comment|/* Socksys commands */
end_comment

begin_define
define|#
directive|define
name|CMD_SO_ACCEPT
value|1
end_define

begin_define
define|#
directive|define
name|CMD_SO_BIND
value|2
end_define

begin_define
define|#
directive|define
name|CMD_SO_CONNECT
value|3
end_define

begin_define
define|#
directive|define
name|CMD_SO_GETPEERNAME
value|4
end_define

begin_define
define|#
directive|define
name|CMD_SO_GETSOCKNAME
value|5
end_define

begin_define
define|#
directive|define
name|CMD_SO_GETSOCKOPT
value|6
end_define

begin_define
define|#
directive|define
name|CMD_SO_LISTEN
value|7
end_define

begin_define
define|#
directive|define
name|CMD_SO_RECV
value|8
end_define

begin_define
define|#
directive|define
name|CMD_SO_RECVFROM
value|9
end_define

begin_define
define|#
directive|define
name|CMD_SO_SEND
value|10
end_define

begin_define
define|#
directive|define
name|CMD_SO_SENDTO
value|11
end_define

begin_define
define|#
directive|define
name|CMD_SO_SETSOCKOPT
value|12
end_define

begin_define
define|#
directive|define
name|CMD_SO_SHUTDOWN
value|13
end_define

begin_define
define|#
directive|define
name|CMD_SO_SOCKET
value|14
end_define

begin_define
define|#
directive|define
name|CMD_SO_SELECT
value|15
end_define

begin_define
define|#
directive|define
name|CMD_SO_GETIPDOMAIN
value|16
end_define

begin_define
define|#
directive|define
name|CMD_SO_SETIPDOMAIN
value|17
end_define

begin_define
define|#
directive|define
name|CMD_SO_ADJTIME
value|18
end_define

begin_define
define|#
directive|define
name|CMD_SO_SETREUID
value|19
end_define

begin_define
define|#
directive|define
name|CMD_SO_SETREGID
value|20
end_define

begin_define
define|#
directive|define
name|CMD_SO_GETTIME
value|21
end_define

begin_define
define|#
directive|define
name|CMD_SO_SETTIME
value|22
end_define

begin_define
define|#
directive|define
name|CMD_SO_GETITIMER
value|23
end_define

begin_define
define|#
directive|define
name|CMD_SO_SETITIMER
value|24
end_define

begin_define
define|#
directive|define
name|CMD_SO_SS_DEBUG
value|255
end_define

begin_comment
comment|/* socksys ioctls */
end_comment

begin_define
define|#
directive|define
name|SS_IOCPARM_MASK
value|0x7f
end_define

begin_comment
comment|/* parameters must be< 128 bytes */
end_comment

begin_define
define|#
directive|define
name|SS_IOC_VOID
value|0x20000000
end_define

begin_comment
comment|/* no parameters */
end_comment

begin_define
define|#
directive|define
name|SS_IOC_OUT
value|0x40000000
end_define

begin_comment
comment|/* copy out parameters */
end_comment

begin_define
define|#
directive|define
name|SS_IOC_IN
value|0x80000000
end_define

begin_comment
comment|/* copy in parameters */
end_comment

begin_define
define|#
directive|define
name|SS_IOC_INOUT
value|(SS_IOC_IN|SS_IOC_OUT)
end_define

begin_define
define|#
directive|define
name|SS_IO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(SS_IOC_VOID|(x<<8)|y)
end_define

begin_define
define|#
directive|define
name|SS_IOR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|t
parameter_list|)
value|(SS_IOC_OUT|((sizeof(t)&SS_IOCPARM_MASK)<<16)|(x<<8)|y)
end_define

begin_define
define|#
directive|define
name|SS_IOW
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|t
parameter_list|)
value|(SS_IOC_IN|((sizeof(t)&SS_IOCPARM_MASK)<<16)|(x<<8)|y)
end_define

begin_define
define|#
directive|define
name|SS_IOWR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|t
parameter_list|)
value|(SS_IOC_INOUT|((sizeof(t)&SS_IOCPARM_MASK)<<16)|(x<<8)|y)
end_define

begin_define
define|#
directive|define
name|SS_SIOCSHIWAT
value|SS_IOW ('S', 1, int)
end_define

begin_comment
comment|/* set high watermark */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGHIWAT
value|SS_IOR ('S', 2, int)
end_define

begin_comment
comment|/* get high watermark */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCSLOWAT
value|SS_IOW ('S', 3, int)
end_define

begin_comment
comment|/* set low watermark */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGLOWAT
value|SS_IOR ('S', 4, int)
end_define

begin_comment
comment|/* get low watermark */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCATMARK
value|SS_IOR ('S', 5, int)
end_define

begin_comment
comment|/* at oob mark? */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCSPGRP
value|SS_IOW ('S', 6, int)
end_define

begin_comment
comment|/* set process group */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGPGRP
value|SS_IOR ('S', 7, int)
end_define

begin_comment
comment|/* get process group */
end_comment

begin_define
define|#
directive|define
name|SS_FIONREAD
value|SS_IOR ('S', 8, int)
end_define

begin_define
define|#
directive|define
name|SS_FIONBIO
value|SS_IOW ('S', 9, int)
end_define

begin_define
define|#
directive|define
name|SS_FIOASYNC
value|SS_IOW ('S', 10, int)
end_define

begin_define
define|#
directive|define
name|SS_SIOCPROTO
value|SS_IOW ('S', 11, struct socknewproto)
end_define

begin_comment
comment|/* link proto */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGETNAME
value|SS_IOR ('S', 12, struct sockaddr)
end_define

begin_comment
comment|/* getsockname */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGETPEER
value|SS_IOR ('S', 13,struct sockaddr)
end_define

begin_comment
comment|/* getpeername */
end_comment

begin_define
define|#
directive|define
name|SS_IF_UNITSEL
value|SS_IOW ('S', 14, int)
end_define

begin_comment
comment|/* set unit number */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCXPROTO
value|SS_IO  ('S', 15)
end_define

begin_comment
comment|/* empty proto table */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCADDRT
value|SS_IOW ('R', 9, struct ortentry)
end_define

begin_comment
comment|/* add route */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCDELRT
value|SS_IOW ('R', 10, struct ortentry)
end_define

begin_comment
comment|/* delete route */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCSIFADDR
value|SS_IOW ('I', 11, struct ifreq)
end_define

begin_comment
comment|/* set ifnet address */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGIFADDR
value|SS_IOWR('I', 12, struct ifreq)
end_define

begin_comment
comment|/* get ifnet address */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCSIFDSTADDR
value|SS_IOW ('I', 13, struct ifreq)
end_define

begin_comment
comment|/* set p-p address */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGIFDSTADDR
value|SS_IOWR('I', 14,struct ifreq)
end_define

begin_comment
comment|/* get p-p address */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCSIFFLAGS
value|SS_IOW ('I', 15, struct ifreq)
end_define

begin_comment
comment|/* set ifnet flags */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGIFFLAGS
value|SS_IOWR('I', 16, struct ifreq)
end_define

begin_comment
comment|/* get ifnet flags */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGIFCONF
value|SS_IOWR('I', 17, struct ifconf)
end_define

begin_comment
comment|/* get ifnet list */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCSIFMTU
value|SS_IOW ('I', 21, struct ifreq)
end_define

begin_comment
comment|/* get if_mtu */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGIFMTU
value|SS_IOWR('I', 22, struct ifreq)
end_define

begin_comment
comment|/* set if_mtu */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCIFDETACH
value|SS_IOW ('I', 26, struct ifreq)
end_define

begin_comment
comment|/* detach interface */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGENPSTATS
value|SS_IOWR('I', 27, struct ifreq)
end_define

begin_comment
comment|/* get ENP stats */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCX25XMT
value|SS_IOWR('I', 29, struct ifreq)
end_define

begin_comment
comment|/* start a slp proc in x25if */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCX25RCV
value|SS_IOWR('I', 30, struct ifreq)
end_define

begin_comment
comment|/* start a slp proc in x25if */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCX25TBL
value|SS_IOWR('I', 31, struct ifreq)
end_define

begin_comment
comment|/* xfer lun table to kernel */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGIFBRDADDR
value|SS_IOWR('I', 32, struct ifreq)
end_define

begin_comment
comment|/* get broadcast addr */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCSIFBRDADDR
value|SS_IOW ('I', 33, struct ifreq)
end_define

begin_comment
comment|/* set broadcast addr */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGIFNETMASK
value|SS_IOWR('I', 34, struct ifreq)
end_define

begin_comment
comment|/* get net addr mask */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCSIFNETMASK
value|SS_IOW ('I', 35, struct ifreq)
end_define

begin_comment
comment|/* set net addr mask */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGIFMETRIC
value|SS_IOWR('I', 36, struct ifreq)
end_define

begin_comment
comment|/* get IF metric */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCSIFMETRIC
value|SS_IOW ('I', 37, struct ifreq)
end_define

begin_comment
comment|/* set IF metric */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCSARP
value|SS_IOW ('I', 38, struct arpreq)
end_define

begin_comment
comment|/* set arp entry */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGARP
value|SS_IOWR('I', 39, struct arpreq)
end_define

begin_comment
comment|/* get arp entry */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCDARP
value|SS_IOW ('I', 40, struct arpreq)
end_define

begin_comment
comment|/* delete arp entry */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCSIFNAME
value|SS_IOW ('I', 41, struct ifreq)
end_define

begin_comment
comment|/* set interface name */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGIFONEP
value|SS_IOWR('I', 42, struct ifreq)
end_define

begin_comment
comment|/* get 1-packet parms */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCSIFONEP
value|SS_IOW ('I', 43, struct ifreq)
end_define

begin_comment
comment|/* set 1-packet parms */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCGENADDR
value|SS_IOWR('I', 65, struct ifreq)
end_define

begin_comment
comment|/* Get ethernet addr */
end_comment

begin_define
define|#
directive|define
name|SS_SIOCSOCKSYS
value|SS_IOW ('I', 66, struct ss_call)
end_define

begin_comment
comment|/* ss syscall */
end_comment

begin_comment
comment|/*  *	NFS/NIS has a pseudo device called /dev/nfsd which may accept ioctl  *	calls. /dev/nfsd is linked to /dev/socksys.  */
end_comment

begin_define
define|#
directive|define
name|NIOCNFSD
value|1
end_define

begin_define
define|#
directive|define
name|NIOCOLDGETFH
value|2
end_define

begin_define
define|#
directive|define
name|NIOCASYNCD
value|3
end_define

begin_define
define|#
directive|define
name|NIOCSETDOMNAM
value|4
end_define

begin_define
define|#
directive|define
name|NIOCGETDOMNAM
value|5
end_define

begin_define
define|#
directive|define
name|NIOCCLNTHAND
value|6
end_define

begin_define
define|#
directive|define
name|NIOCEXPORTFS
value|7
end_define

begin_define
define|#
directive|define
name|NIOCGETFH
value|8
end_define

begin_define
define|#
directive|define
name|NIOCLSTAT
value|9
end_define

begin_comment
comment|/*  *	noso  */
end_comment

begin_define
define|#
directive|define
name|SO_ORDREL
value|0xff02
end_define

begin_define
define|#
directive|define
name|SO_IMASOCKET
value|0xff03
end_define

begin_define
define|#
directive|define
name|SO_PROTOTYPE
value|0xff04
end_define

begin_comment
comment|/* Check below */
end_comment

begin_define
define|#
directive|define
name|SO_NO_CHECK
value|11
end_define

begin_define
define|#
directive|define
name|SO_PRIORITY
value|12
end_define

begin_comment
comment|/*  *	convert  */
end_comment

begin_comment
comment|/* Structure conversion indicators */
end_comment

begin_define
define|#
directive|define
name|SS_STRUCT_ARPREQ
value|1
end_define

begin_define
define|#
directive|define
name|SS_STRUCT_IFCONF
value|2
end_define

begin_define
define|#
directive|define
name|SS_STRUCT_IFREQ
value|3
end_define

begin_define
define|#
directive|define
name|SS_STRUCT_ORTENTRY
value|4
end_define

begin_define
define|#
directive|define
name|SS_STRUCT_SOCKADDR
value|5
end_define

begin_define
define|#
directive|define
name|SS_STRUCT_SOCKNEWPROTO
value|6
end_define

begin_define
define|#
directive|define
name|SS_ALIEN_TO_NATIVE
value|1
end_define

begin_define
define|#
directive|define
name|SS_NATIVE_TO_ALIEN
value|2
end_define

begin_struct
struct|struct
name|whatever
block|{
name|int
name|from
decl_stmt|,
name|to
decl_stmt|;
name|unsigned
name|char
modifier|*
name|conversion
decl_stmt|;
name|unsigned
name|char
name|all_the_same
decl_stmt|;
name|struct
name|whatever
modifier|*
name|more
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|whatever
modifier|*
name|af_whatevers
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|whatever
modifier|*
name|type_whatevers
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|whatever
modifier|*
name|sopt_whatevers
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|whatever
modifier|*
name|struct_whatevers
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|ss_convert
parameter_list|(
name|struct
name|whatever
modifier|*
modifier|*
name|what
parameter_list|,
name|int
modifier|*
name|this
parameter_list|,
name|int
name|otherwise
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ss_convert_struct
parameter_list|(
name|char
modifier|*
name|alien
parameter_list|,
name|int
name|indicator
parameter_list|,
name|int
name|direction
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	convert af  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|whatever
name|af_whatevers_all
index|[]
init|=
block|{
block|{
literal|0
block|,
literal|2
block|,
name|NULL
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|whatever
modifier|*
name|af_whatevers
index|[]
init|=
block|{
name|NULL
block|,
comment|/* FreeBSD */
name|af_whatevers_all
block|,
comment|/* SysVR4 */
name|af_whatevers_all
block|,
comment|/* SysVR3 */
name|af_whatevers_all
block|,
comment|/* SCO 3.2.[24] */
name|af_whatevers_all
block|,
comment|/* Wyse Unix V/386 3.2.1 */
name|af_whatevers_all
block|,
comment|/* ISC */
name|af_whatevers_all
comment|/* Linux */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	convert sopt  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|whatever
name|sopt_whatevers_all
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|0x0001
block|,
operator|(
name|char
operator|*
operator|)
name|SO_DEBUG
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x0002
block|,
literal|0x0002
block|,
operator|(
name|char
operator|*
operator|)
name|SO_ACCEPTCONN
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x0004
block|,
literal|0x0004
block|,
operator|(
name|char
operator|*
operator|)
name|SO_REUSEADDR
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x0008
block|,
literal|0x0008
block|,
operator|(
name|char
operator|*
operator|)
name|SO_KEEPALIVE
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x0010
block|,
literal|0x0010
block|,
operator|(
name|char
operator|*
operator|)
name|SO_DONTROUTE
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x0020
block|,
literal|0x0020
block|,
operator|(
name|char
operator|*
operator|)
name|SO_BROADCAST
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x0040
block|,
literal|0x0040
block|,
operator|(
name|char
operator|*
operator|)
name|SO_USELOOPBACK
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x0080
block|,
literal|0x0080
block|,
operator|(
name|char
operator|*
operator|)
name|SO_LINGER
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x0100
block|,
literal|0x0100
block|,
operator|(
name|char
operator|*
operator|)
name|SO_OOBINLINE
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x0200
block|,
literal|0x0200
block|,
operator|(
name|char
operator|*
operator|)
name|SO_ORDREL
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x0400
block|,
literal|0x0400
block|,
operator|(
name|char
operator|*
operator|)
name|SO_IMASOCKET
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x1001
block|,
literal|0x1001
block|,
operator|(
name|char
operator|*
operator|)
name|SO_SNDBUF
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x1002
block|,
literal|0x1001
block|,
operator|(
name|char
operator|*
operator|)
name|SO_RCVBUF
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x1003
block|,
literal|0x1001
block|,
operator|(
name|char
operator|*
operator|)
name|SO_SNDLOWAT
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x1004
block|,
literal|0x1001
block|,
operator|(
name|char
operator|*
operator|)
name|SO_RCVLOWAT
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x1005
block|,
literal|0x1001
block|,
operator|(
name|char
operator|*
operator|)
name|SO_SNDTIMEO
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x1006
block|,
literal|0x1001
block|,
operator|(
name|char
operator|*
operator|)
name|SO_RCVTIMEO
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x1007
block|,
literal|0x1001
block|,
operator|(
name|char
operator|*
operator|)
name|SO_ERROR
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x1008
block|,
literal|0x1001
block|,
operator|(
name|char
operator|*
operator|)
name|SO_TYPE
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|0x1009
block|,
literal|0x1001
block|,
operator|(
name|char
operator|*
operator|)
name|SO_PROTOTYPE
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|whatever
modifier|*
name|sopt_whatevers
index|[]
init|=
block|{
name|NULL
block|,
comment|/* FreeBSD */
name|sopt_whatevers_all
block|,
comment|/* SysVR4 */
name|sopt_whatevers_all
block|,
comment|/* SysVR3 */
name|sopt_whatevers_all
block|,
comment|/* SCO 3.2.[24] */
name|sopt_whatevers_all
block|,
comment|/* Wyse Unix V/386 3.2.1 */
name|sopt_whatevers_all
block|,
comment|/* ISC */
name|sopt_whatevers_all
comment|/* Linux */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	convert struct  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|whatever
name|struct_whatever_typeI_ranges
index|[]
init|=
block|{
block|{
literal|11
block|,
literal|16
block|,
operator|(
name|char
operator|*
operator|)
name|SS_STRUCT_IFREQ
block|,
literal|1
block|,
literal|0
block|}
block|,
comment|/* OK */
block|{
literal|17
block|,
literal|17
block|,
operator|(
name|char
operator|*
operator|)
name|SS_STRUCT_IFCONF
block|,
literal|1
block|,
literal|0
block|}
block|,
comment|/* OK */
block|{
literal|21
block|,
literal|22
block|,
operator|(
name|char
operator|*
operator|)
name|SS_STRUCT_IFREQ
block|,
literal|1
block|,
literal|0
block|}
block|,
comment|/* SIZE OK */
block|{
literal|26
block|,
literal|27
block|,
operator|(
name|char
operator|*
operator|)
name|SS_STRUCT_IFREQ
block|,
literal|1
block|,
literal|0
block|}
block|,
comment|/* SIZE OK */
block|{
literal|29
block|,
literal|37
block|,
operator|(
name|char
operator|*
operator|)
name|SS_STRUCT_IFREQ
block|,
literal|1
block|,
literal|0
block|}
block|,
comment|/* SIZE OK */
block|{
literal|38
block|,
literal|40
block|,
operator|(
name|char
operator|*
operator|)
name|SS_STRUCT_ARPREQ
block|,
literal|1
block|,
literal|0
block|}
block|,
comment|/* OK */
block|{
literal|41
block|,
literal|43
block|,
operator|(
name|char
operator|*
operator|)
name|SS_STRUCT_IFREQ
block|,
literal|1
block|,
literal|0
block|}
block|,
comment|/* SIZE OK */
block|{
literal|65
block|,
literal|65
block|,
operator|(
name|char
operator|*
operator|)
name|SS_STRUCT_IFREQ
block|,
literal|1
block|,
literal|0
block|}
block|,
comment|/* SIZE OK */
block|{
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|whatever
name|struct_whatever_typeR_ranges
index|[]
init|=
block|{
block|{
literal|9
block|,
literal|10
block|,
operator|(
name|char
operator|*
operator|)
name|SS_STRUCT_ORTENTRY
block|,
literal|1
block|,
literal|0
block|}
block|,
comment|/* SIZE OK */
block|{
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|whatever
name|struct_whatever_typeS_ranges
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|10
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|}
block|,
block|{
literal|11
block|,
literal|11
block|,
operator|(
name|char
operator|*
operator|)
name|SS_STRUCT_SOCKNEWPROTO
block|,
literal|1
block|,
literal|0
block|}
block|,
comment|/* NO SUPPORT */
block|{
literal|12
block|,
literal|13
block|,
operator|(
name|char
operator|*
operator|)
name|SS_STRUCT_SOCKADDR
block|,
literal|1
block|,
literal|0
block|}
block|,
comment|/* len and family */
block|{
literal|14
block|,
literal|15
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|}
block|,
block|{
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|whatever
name|struct_whatevers_all
index|[]
init|=
block|{
block|{
literal|'I'
block|,
literal|'I'
block|,
literal|0
block|,
literal|0
block|,
name|struct_whatever_typeI_ranges
block|}
block|,
block|{
literal|'R'
block|,
literal|'R'
block|,
literal|0
block|,
literal|0
block|,
name|struct_whatever_typeR_ranges
block|}
block|,
block|{
literal|'S'
block|,
literal|'S'
block|,
literal|0
block|,
literal|0
block|,
name|struct_whatever_typeS_ranges
block|}
block|,
block|{
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|whatever
modifier|*
name|struct_whatevers
index|[]
init|=
block|{
name|struct_whatevers_all
block|,
comment|/* FreeBSD */
name|struct_whatevers_all
block|,
comment|/* SysVR4 */
name|struct_whatevers_all
block|,
comment|/* SysVR3 */
name|struct_whatevers_all
block|,
comment|/* SCO 3.2.[24] */
name|struct_whatevers_all
block|,
comment|/* Wyse Unix V/386 3.2.1 */
name|struct_whatevers_all
block|,
comment|/* ISC */
name|struct_whatevers_all
comment|/* Linux */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ss_struct_native_sizes
index|[]
init|=
block|{
sizeof|sizeof
argument_list|(
expr|struct
name|arpreq
argument_list|)
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|ifconf
argument_list|)
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|ifreq
argument_list|)
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|rtentry
argument_list|)
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|sockaddr
argument_list|)
block|,
expr|sizeof
operator|(
expr|struct
name|socknewproto
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	convert type  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|type_conversion_SysVr4_range1
index|[]
init|=
block|{
name|SOCK_DGRAM
block|,
name|SOCK_STREAM
block|,
literal|0
block|,
name|SOCK_RAW
block|,
name|SOCK_RDM
block|,
name|SOCK_SEQPACKET
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|whatever
name|type_whatevers_SysVr4
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|6
block|,
name|type_conversion_SysVr4_range1
block|,
literal|0
block|}
block|,
block|{
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|whatever
modifier|*
name|type_whatevers
index|[]
init|=
block|{
name|NULL
block|,
comment|/* FreeBSD */
name|type_whatevers_SysVr4
block|,
comment|/* SysVR4 */
name|NULL
block|,
comment|/* SysVR3 */
name|NULL
block|,
comment|/* SCO 3.2.[24] */
name|NULL
block|,
comment|/* Wyse Unix V/386 3.2.1 */
name|NULL
block|,
comment|/* ISC */
name|NULL
comment|/* Linux */
block|}
decl_stmt|;
end_decl_stmt

end_unit

