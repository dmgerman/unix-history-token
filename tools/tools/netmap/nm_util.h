begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2012-2014 Luigi Rizzo. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  * $Id$  *  * Some utilities to build netmap-based programs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NM_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|_NM_UTIL_H
end_define

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_comment
comment|/* for CPU_SET() */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* fprintf */
end_comment

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_comment
comment|/* POLLIN */
end_comment

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_comment
comment|/* PRI* macros */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* u_char */
end_comment

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_comment
comment|/* ntohs */
end_comment

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_comment
comment|/* sysctl */
end_comment

begin_include
include|#
directive|include
file|<ifaddrs.h>
end_include

begin_comment
comment|/* getifaddrs */
end_comment

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_comment
comment|/* ETHERTYPE_IP */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/* IPPROTO_* */
end_comment

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_comment
comment|/* struct ip */
end_comment

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_comment
comment|/* struct udp */
end_comment

begin_define
define|#
directive|define
name|NETMAP_WITH_LIBS
end_define

begin_include
include|#
directive|include
file|<net/netmap_user.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_comment
comment|/* pthread_* */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_define
define|#
directive|define
name|cpuset_t
value|cpu_set_t
end_define

begin_define
define|#
directive|define
name|ifr_flagshigh
value|ifr_flags
end_define

begin_comment
comment|/* only the low 16 bits here */
end_comment

begin_define
define|#
directive|define
name|IFF_PPROMISC
value|IFF_PROMISC
end_define

begin_comment
comment|/* IFF_PPROMISC does not exist */
end_comment

begin_include
include|#
directive|include
file|<linux/ethtool.h>
end_include

begin_include
include|#
directive|include
file|<linux/sockios.h>
end_include

begin_define
define|#
directive|define
name|CLOCK_REALTIME_PRECISE
value|CLOCK_REALTIME
end_define

begin_include
include|#
directive|include
file|<netinet/ether.h>
end_include

begin_comment
comment|/* ether_aton */
end_comment

begin_include
include|#
directive|include
file|<linux/if_packet.h>
end_include

begin_comment
comment|/* sockaddr_ll */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* linux */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_comment
comment|/* le64toh */
end_comment

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_include
include|#
directive|include
file|<pthread_np.h>
end_include

begin_comment
comment|/* pthread w/ affinity */
end_comment

begin_include
include|#
directive|include
file|<sys/cpuset.h>
end_include

begin_comment
comment|/* cpu_set */
end_comment

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_comment
comment|/* LLADDR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_define
define|#
directive|define
name|cpuset_t
value|uint64_t
end_define

begin_comment
comment|// XXX
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|CPU_ZERO
parameter_list|(
name|cpuset_t
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|CPU_SET
parameter_list|(
name|uint32_t
name|i
parameter_list|,
name|cpuset_t
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator||=
literal|1
operator|<<
operator|(
name|i
operator|&
literal|0x3f
operator|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|pthread_setaffinity_np
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|((void)a, 0)
end_define

begin_define
define|#
directive|define
name|ifr_flagshigh
value|ifr_flags
end_define

begin_comment
comment|// XXX
end_comment

begin_define
define|#
directive|define
name|IFF_PPROMISC
value|IFF_PROMISC
end_define

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_comment
comment|/* LLADDR */
end_comment

begin_define
define|#
directive|define
name|clock_gettime
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|do {struct timespec t0 = {0,0};	*(b) = t0; } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __APPLE__ */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|min
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
return|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|time_second
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug support */
end_comment

begin_define
define|#
directive|define
name|ND
parameter_list|(
name|format
parameter_list|,
modifier|...
parameter_list|)
value|do {} while(0)
end_define

begin_define
define|#
directive|define
name|D
parameter_list|(
name|format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|fprintf(stderr, "%s [%d] " format "\n",		\ 	__FUNCTION__, __LINE__, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|RD
parameter_list|(
name|lps
parameter_list|,
name|format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {						\ 		static int t0, cnt;			\ 		if (t0 != time_second) {		\ 			t0 = time_second;		\ 			cnt = 0;			\ 		}					\ 		if (cnt++< lps)			\ 			D(format, ##__VA_ARGS__);	\ 	} while (0)
end_define

begin_function_decl
name|struct
name|nm_desc_t
modifier|*
name|netmap_open
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|ringid
parameter_list|,
name|int
name|promisc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nm_do_ioctl
parameter_list|(
name|struct
name|nm_desc_t
modifier|*
name|me
parameter_list|,
name|u_long
name|what
parameter_list|,
name|int
name|subcmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pkt_queued
parameter_list|(
name|struct
name|nm_desc_t
modifier|*
name|d
parameter_list|,
name|int
name|tx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NM_UTIL_H */
end_comment

end_unit

