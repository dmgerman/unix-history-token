begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2012 Luigi Rizzo. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/* signal */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
file|<string.h>
end_include

begin_comment
comment|/* strcmp */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/* open */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* close */
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
file|<sys/mman.h>
end_include

begin_comment
comment|/* PROT_* */
end_comment

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_comment
comment|/* ioctl */
end_comment

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_comment
comment|/* sockaddr.. */
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
file|<sys/param.h>
end_include

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
file|<sys/time.h>
end_include

begin_comment
comment|/* timersub */
end_comment

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_comment
comment|/* ifreq */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<net/netmap.h>
end_include

begin_include
include|#
directive|include
file|<net/netmap_user.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MY_PCAP
end_ifndef

begin_comment
comment|/* use the system's pcap if available */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_PCAP
end_ifdef

begin_define
define|#
directive|define
name|PCAP_ERRBUF_SIZE
value|512
end_define

begin_typedef
typedef|typedef
name|void
name|pcap_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|pcap_pkthdr
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|pcap_inject
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|((void)a, (void)b, (void)c, -1)
end_define

begin_define
define|#
directive|define
name|pcap_dispatch
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|(void)c
end_define

begin_define
define|#
directive|define
name|pcap_open_live
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|((void)e, NULL)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !NO_PCAP */
end_comment

begin_include
include|#
directive|include
file|<pcap/pcap.h>
end_include

begin_comment
comment|// XXX do we need it ?
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NO_PCAP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// XXX hack
end_comment

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
name|ifr_flagshigh
value|ifr_flags
end_define

begin_define
define|#
directive|define
name|ifr_curcap
value|ifr_flags
end_define

begin_define
define|#
directive|define
name|ifr_reqcap
value|ifr_flags
end_define

begin_define
define|#
directive|define
name|IFF_PPROMISC
value|IFF_PROMISC
end_define

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

begin_comment
comment|// XXX does it work on 32-bit machines ?
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|prefetch
parameter_list|(
specifier|const
name|void
modifier|*
name|x
parameter_list|)
block|{
asm|__asm volatile("prefetcht0 %0" :: "m" (*(const unsigned long *)x));
block|}
end_function

begin_comment
comment|// XXX only for multiples of 64 bytes, non overlapped.
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|pkt_copy
parameter_list|(
specifier|const
name|void
modifier|*
name|_src
parameter_list|,
name|void
modifier|*
name|_dst
parameter_list|,
name|int
name|l
parameter_list|)
block|{
specifier|const
name|uint64_t
modifier|*
name|src
init|=
name|_src
decl_stmt|;
name|uint64_t
modifier|*
name|dst
init|=
name|_dst
decl_stmt|;
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 1)
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 0)
if|if
condition|(
name|unlikely
argument_list|(
name|l
operator|>=
literal|1024
argument_list|)
condition|)
block|{
name|bcopy
argument_list|(
name|src
argument_list|,
name|dst
argument_list|,
name|l
argument_list|)
expr_stmt|;
return|return;
block|}
for|for
control|(
init|;
name|l
operator|>
literal|0
condition|;
name|l
operator|-=
literal|64
control|)
block|{
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * info on a ring we handle  */
end_comment

begin_struct
struct|struct
name|my_ring
block|{
specifier|const
name|char
modifier|*
name|ifname
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|char
modifier|*
name|mem
decl_stmt|;
comment|/* userspace mmap address */
name|u_int
name|memsize
decl_stmt|;
name|u_int
name|queueid
decl_stmt|;
name|u_int
name|begin
decl_stmt|,
name|end
decl_stmt|;
comment|/* first..last+1 rings to check */
name|struct
name|netmap_if
modifier|*
name|nifp
decl_stmt|;
name|struct
name|netmap_ring
modifier|*
name|tx
decl_stmt|,
modifier|*
name|rx
decl_stmt|;
comment|/* shortcuts */
name|uint32_t
name|if_flags
decl_stmt|;
name|uint32_t
name|if_reqcap
decl_stmt|;
name|uint32_t
name|if_curcap
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|netmap_open
parameter_list|(
name|struct
name|my_ring
modifier|*
name|me
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
name|netmap_close
parameter_list|(
name|struct
name|my_ring
modifier|*
name|me
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nm_do_ioctl
parameter_list|(
name|struct
name|my_ring
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NM_UTIL_H */
end_comment

end_unit

