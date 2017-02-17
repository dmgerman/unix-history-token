begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* -*- Mode: c; tab-width: 8; indent-tabs-mode: 1; c-basic-offset: 8; -*- */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996, 1997, 1998  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the Computer Systems  *	Engineering Group at Lawrence Berkeley Laboratory.  * 4. Neither the name of the University nor of the Laboratory may be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<ifaddrs.h>
end_include

begin_include
include|#
directive|include
file|"pcap-int.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OS_PROTO_H
end_ifdef

begin_include
include|#
directive|include
file|"os-proto.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We don't do this on Solaris 11 and later, as it appears there aren't  * any AF_PACKET addresses on interfaces, so we don't need this, and  * we end up including both the OS's<net/bpf.h> and our<pcap/bpf.h>,  * and their definitions of some data structures collide.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|linux
argument_list|)
operator|||
name|defined
argument_list|(
name|__Lynx__
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|AF_PACKET
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETPACKET_PACKET_H
end_ifdef

begin_comment
comment|/* Linux distributions with newer glibc */
end_comment

begin_include
include|#
directive|include
file|<netpacket/packet.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_NETPACKET_PACKET_H */
end_comment

begin_comment
comment|/* LynxOS, Linux distributions with older glibc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__Lynx__
end_ifdef

begin_comment
comment|/* LynxOS */
end_comment

begin_include
include|#
directive|include
file|<netpacket/if_packet.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __Lynx__ */
end_comment

begin_comment
comment|/* Linux */
end_comment

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/if_packet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __Lynx__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NETPACKET_PACKET_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(linux) || defined(__Lynx__))&& defined(AF_PACKET) */
end_comment

begin_comment
comment|/*  * This is fun.  *  * In older BSD systems, socket addresses were fixed-length, and  * "sizeof (struct sockaddr)" gave the size of the structure.  * All addresses fit within a "struct sockaddr".  *  * In newer BSD systems, the socket address is variable-length, and  * there's an "sa_len" field giving the length of the structure;  * this allows socket addresses to be longer than 2 bytes of family  * and 14 bytes of data.  *  * Some commercial UNIXes use the old BSD scheme, some use the RFC 2553  * variant of the old BSD scheme (with "struct sockaddr_storage" rather  * than "struct sockaddr"), and some use the new BSD scheme.  *  * Some versions of GNU libc use neither scheme, but has an "SA_LEN()"  * macro that determines the size based on the address family.  Other  * versions don't have "SA_LEN()" (as it was in drafts of RFC 2553  * but not in the final version).  On the latter systems, we explicitly  * check the AF_ type to determine the length; we assume that on  * all those systems we have "struct sockaddr_storage".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SA_LEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SOCKADDR_SA_LEN
end_ifdef

begin_define
define|#
directive|define
name|SA_LEN
parameter_list|(
name|addr
parameter_list|)
value|((addr)->sa_len)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_SOCKADDR_SA_LEN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SOCKADDR_STORAGE
end_ifdef

begin_function
specifier|static
name|size_t
name|get_sa_len
parameter_list|(
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|)
block|{
switch|switch
condition|(
name|addr
operator|->
name|sa_family
condition|)
block|{
ifdef|#
directive|ifdef
name|AF_INET
case|case
name|AF_INET
case|:
return|return
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|sockaddr_in
argument_list|)
operator|)
return|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|AF_INET6
case|case
name|AF_INET6
case|:
return|return
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|sockaddr_in6
argument_list|)
operator|)
return|;
endif|#
directive|endif
if|#
directive|if
operator|(
name|defined
argument_list|(
name|linux
argument_list|)
operator|||
name|defined
argument_list|(
name|__Lynx__
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|AF_PACKET
argument_list|)
case|case
name|AF_PACKET
case|:
return|return
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|sockaddr_ll
argument_list|)
operator|)
return|;
endif|#
directive|endif
default|default:
return|return
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|sockaddr
argument_list|)
operator|)
return|;
block|}
block|}
end_function

begin_define
define|#
directive|define
name|SA_LEN
parameter_list|(
name|addr
parameter_list|)
value|(get_sa_len(addr))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_SOCKADDR_STORAGE */
end_comment

begin_define
define|#
directive|define
name|SA_LEN
parameter_list|(
name|addr
parameter_list|)
value|(sizeof (struct sockaddr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SOCKADDR_STORAGE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SOCKADDR_SA_LEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SA_LEN */
end_comment

begin_comment
comment|/*  * Get a list of all interfaces that are up and that we can open.  * Returns -1 on error, 0 otherwise.  * The list, as returned through "alldevsp", may be null if no interfaces  * could be opened.  */
end_comment

begin_function
name|int
name|pcap_findalldevs_interfaces
parameter_list|(
name|pcap_if_t
modifier|*
modifier|*
name|alldevsp
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|int
function_decl|(
modifier|*
name|check_usable
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
parameter_list|)
block|{
name|pcap_if_t
modifier|*
name|devlist
init|=
name|NULL
decl_stmt|;
name|struct
name|ifaddrs
modifier|*
name|ifap
decl_stmt|,
modifier|*
name|ifa
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|addr
decl_stmt|,
modifier|*
name|netmask
decl_stmt|,
modifier|*
name|broadaddr
decl_stmt|,
modifier|*
name|dstaddr
decl_stmt|;
name|size_t
name|addr_size
decl_stmt|,
name|broadaddr_size
decl_stmt|,
name|dstaddr_size
decl_stmt|;
name|int
name|ret
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
comment|/* 	 * Get the list of interface addresses. 	 * 	 * Note: this won't return information about interfaces 	 * with no addresses, so, if a platform has interfaces 	 * with no interfaces on which traffic can be captured, 	 * we must check for those interfaces as well (see, for 	 * example, what's done on Linux). 	 * 	 * LAN interfaces will probably have link-layer 	 * addresses; I don't know whether all implementations 	 * of "getifaddrs()" now, or in the future, will return 	 * those. 	 */
if|if
condition|(
name|getifaddrs
argument_list|(
operator|&
name|ifap
argument_list|)
operator|!=
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|pcap_snprintf
argument_list|(
name|errbuf
argument_list|,
name|PCAP_ERRBUF_SIZE
argument_list|,
literal|"getifaddrs: %s"
argument_list|,
name|pcap_strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
for|for
control|(
name|ifa
operator|=
name|ifap
init|;
name|ifa
operator|!=
name|NULL
condition|;
name|ifa
operator|=
name|ifa
operator|->
name|ifa_next
control|)
block|{
comment|/* 		 * If this entry has a colon followed by a number at 		 * the end, we assume it's a logical interface.  Those 		 * are just the way you assign multiple IP addresses to 		 * a real interface on Linux, so an entry for a logical 		 * interface should be treated like the entry for the 		 * real interface; we do that by stripping off the ":" 		 * and the number. 		 * 		 * XXX - should we do this only on Linux? 		 */
name|p
operator|=
name|strchr
argument_list|(
name|ifa
operator|->
name|ifa_name
argument_list|,
literal|':'
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|!=
name|NULL
condition|)
block|{
comment|/* 			 * We have a ":"; is it followed by a number? 			 */
name|q
operator|=
name|p
operator|+
literal|1
expr_stmt|;
while|while
condition|(
name|isdigit
argument_list|(
operator|(
name|unsigned
name|char
operator|)
operator|*
name|q
argument_list|)
condition|)
name|q
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|q
operator|==
literal|'\0'
condition|)
block|{
comment|/* 				 * All digits after the ":" until the end. 				 * Strip off the ":" and everything after 				 * it. 				 */
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
block|}
block|}
comment|/* 		 * Can we capture on this device? 		 */
if|if
condition|(
operator|!
call|(
modifier|*
name|check_usable
call|)
argument_list|(
name|ifa
operator|->
name|ifa_name
argument_list|)
condition|)
block|{
comment|/* 			 * No. 			 */
continue|continue;
block|}
comment|/* 		 * "ifa_addr" was apparently null on at least one 		 * interface on some system.  Therefore, we supply 		 * the address and netmask only if "ifa_addr" is 		 * non-null (if there's no address, there's obviously 		 * no netmask). 		 */
if|if
condition|(
name|ifa
operator|->
name|ifa_addr
operator|!=
name|NULL
condition|)
block|{
name|addr
operator|=
name|ifa
operator|->
name|ifa_addr
expr_stmt|;
name|addr_size
operator|=
name|SA_LEN
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|netmask
operator|=
name|ifa
operator|->
name|ifa_netmask
expr_stmt|;
block|}
else|else
block|{
name|addr
operator|=
name|NULL
expr_stmt|;
name|addr_size
operator|=
literal|0
expr_stmt|;
name|netmask
operator|=
name|NULL
expr_stmt|;
block|}
comment|/* 		 * Note that, on some platforms, ifa_broadaddr and 		 * ifa_dstaddr could be the same field (true on at 		 * least some versions of *BSD and OS X), so we 		 * can't just check whether the broadcast address 		 * is null and add it if so and check whether the 		 * destination address is null and add it if so. 		 * 		 * Therefore, we must also check the IFF_BROADCAST 		 * flag, and only add a broadcast address if it's 		 * set, and check the IFF_POINTTOPOINT flag, and 		 * only add a destination address if it's set (as 		 * per man page recommendations on some of those 		 * platforms). 		 */
if|if
condition|(
name|ifa
operator|->
name|ifa_flags
operator|&
name|IFF_BROADCAST
operator|&&
name|ifa
operator|->
name|ifa_broadaddr
operator|!=
name|NULL
condition|)
block|{
name|broadaddr
operator|=
name|ifa
operator|->
name|ifa_broadaddr
expr_stmt|;
name|broadaddr_size
operator|=
name|SA_LEN
argument_list|(
name|broadaddr
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|broadaddr
operator|=
name|NULL
expr_stmt|;
name|broadaddr_size
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|ifa
operator|->
name|ifa_flags
operator|&
name|IFF_POINTOPOINT
operator|&&
name|ifa
operator|->
name|ifa_dstaddr
operator|!=
name|NULL
condition|)
block|{
name|dstaddr
operator|=
name|ifa
operator|->
name|ifa_dstaddr
expr_stmt|;
name|dstaddr_size
operator|=
name|SA_LEN
argument_list|(
name|ifa
operator|->
name|ifa_dstaddr
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|dstaddr
operator|=
name|NULL
expr_stmt|;
name|dstaddr_size
operator|=
literal|0
expr_stmt|;
block|}
comment|/* 		 * Add information for this address to the list. 		 */
if|if
condition|(
name|add_addr_to_iflist
argument_list|(
operator|&
name|devlist
argument_list|,
name|ifa
operator|->
name|ifa_name
argument_list|,
name|if_flags_to_pcap_flags
argument_list|(
name|ifa
operator|->
name|ifa_name
argument_list|,
name|ifa
operator|->
name|ifa_flags
argument_list|)
argument_list|,
name|addr
argument_list|,
name|addr_size
argument_list|,
name|netmask
argument_list|,
name|addr_size
argument_list|,
name|broadaddr
argument_list|,
name|broadaddr_size
argument_list|,
name|dstaddr
argument_list|,
name|dstaddr_size
argument_list|,
name|errbuf
argument_list|)
operator|<
literal|0
condition|)
block|{
name|ret
operator|=
operator|-
literal|1
expr_stmt|;
break|break;
block|}
block|}
name|freeifaddrs
argument_list|(
name|ifap
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* 		 * We had an error; free the list we've been constructing. 		 */
if|if
condition|(
name|devlist
operator|!=
name|NULL
condition|)
block|{
name|pcap_freealldevs
argument_list|(
name|devlist
argument_list|)
expr_stmt|;
name|devlist
operator|=
name|NULL
expr_stmt|;
block|}
block|}
operator|*
name|alldevsp
operator|=
name|devlist
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

end_unit

