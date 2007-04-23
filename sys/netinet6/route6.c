begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: route6.c,v 1.24 2001/03/14 03:07:05 itojun Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"opt_inet.h"
end_include

begin_include
include|#
directive|include
file|"opt_inet6.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/in6_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ip6_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/scope6_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/icmp6.h>
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static int ip6_rthdr0 __P((struct mbuf *, struct ip6_hdr *,     struct ip6_rthdr0 *));
endif|#
directive|endif
end_endif

begin_comment
comment|/* Disable route header processing. */
end_comment

begin_function
name|int
name|route6_input
parameter_list|(
name|mp
parameter_list|,
name|offp
parameter_list|,
name|proto
parameter_list|)
name|struct
name|mbuf
modifier|*
modifier|*
name|mp
decl_stmt|;
name|int
modifier|*
name|offp
decl_stmt|,
name|proto
decl_stmt|;
comment|/* proto is unused */
block|{
name|struct
name|ip6_hdr
modifier|*
name|ip6
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m
init|=
operator|*
name|mp
decl_stmt|;
name|struct
name|ip6_rthdr
modifier|*
name|rh
decl_stmt|;
name|int
name|off
init|=
operator|*
name|offp
decl_stmt|,
name|rhlen
decl_stmt|;
name|struct
name|ip6aux
modifier|*
name|ip6a
decl_stmt|;
name|ip6a
operator|=
name|ip6_findaux
argument_list|(
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|ip6a
condition|)
block|{
comment|/* XXX reject home-address option before rthdr */
if|if
condition|(
name|ip6a
operator|->
name|ip6a_flags
operator|&
name|IP6A_SWAP
condition|)
block|{
name|ip6stat
operator|.
name|ip6s_badoptions
operator|++
expr_stmt|;
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return
name|IPPROTO_DONE
return|;
block|}
block|}
ifndef|#
directive|ifndef
name|PULLDOWN_TEST
name|IP6_EXTHDR_CHECK
argument_list|(
name|m
argument_list|,
name|off
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|rh
argument_list|)
argument_list|,
name|IPPROTO_DONE
argument_list|)
expr_stmt|;
name|ip6
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
expr|struct
name|ip6_hdr
operator|*
argument_list|)
expr_stmt|;
name|rh
operator|=
operator|(
expr|struct
name|ip6_rthdr
operator|*
operator|)
operator|(
operator|(
name|caddr_t
operator|)
name|ip6
operator|+
name|off
operator|)
expr_stmt|;
else|#
directive|else
name|ip6
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
expr|struct
name|ip6_hdr
operator|*
argument_list|)
expr_stmt|;
name|IP6_EXTHDR_GET
argument_list|(
name|rh
argument_list|,
expr|struct
name|ip6_rthdr
operator|*
argument_list|,
name|m
argument_list|,
name|off
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|rh
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|rh
operator|==
name|NULL
condition|)
block|{
name|ip6stat
operator|.
name|ip6s_tooshort
operator|++
expr_stmt|;
return|return
name|IPPROTO_DONE
return|;
block|}
endif|#
directive|endif
switch|switch
condition|(
name|rh
operator|->
name|ip6r_type
condition|)
block|{
if|#
directive|if
literal|0
block|case IPV6_RTHDR_TYPE_0: 		rhlen = (rh->ip6r_len + 1)<< 3;
ifndef|#
directive|ifndef
name|PULLDOWN_TEST
comment|/* 		 * note on option length: 		 * due to IP6_EXTHDR_CHECK assumption, we cannot handle 		 * very big routing header (max rhlen == 2048). 		 */
block|IP6_EXTHDR_CHECK(m, off, rhlen, IPPROTO_DONE);
else|#
directive|else
comment|/* 		 * note on option length: 		 * maximum rhlen: 2048 		 * max mbuf m_pulldown can handle: MCLBYTES == usually 2048 		 * so, here we are assuming that m_pulldown can handle 		 * rhlen == 2048 case.  this may not be a good thing to 		 * assume - we may want to avoid pulling it up altogether. 		 */
block|IP6_EXTHDR_GET(rh, struct ip6_rthdr *, m, off, rhlen); 		if (rh == NULL) { 			ip6stat.ip6s_tooshort++; 			return IPPROTO_DONE; 		}
endif|#
directive|endif
block|if (ip6_rthdr0(m, ip6, (struct ip6_rthdr0 *)rh)) 			return (IPPROTO_DONE); 		break;
endif|#
directive|endif
comment|/* Disable route header 0 */
default|default:
comment|/* unknown routing type */
if|if
condition|(
name|rh
operator|->
name|ip6r_segleft
operator|==
literal|0
condition|)
block|{
name|rhlen
operator|=
operator|(
name|rh
operator|->
name|ip6r_len
operator|+
literal|1
operator|)
operator|<<
literal|3
expr_stmt|;
break|break;
comment|/* Final dst. Just ignore the header. */
block|}
name|ip6stat
operator|.
name|ip6s_badoptions
operator|++
expr_stmt|;
name|icmp6_error
argument_list|(
name|m
argument_list|,
name|ICMP6_PARAM_PROB
argument_list|,
name|ICMP6_PARAMPROB_HEADER
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|rh
operator|->
name|ip6r_type
operator|-
operator|(
name|caddr_t
operator|)
name|ip6
argument_list|)
expr_stmt|;
return|return
operator|(
name|IPPROTO_DONE
operator|)
return|;
block|}
operator|*
name|offp
operator|+=
name|rhlen
expr_stmt|;
return|return
operator|(
name|rh
operator|->
name|ip6r_nxt
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Type0 routing header processing  *  * RFC2292 backward compatibility warning: no support for strict/loose bitmap,  * as it was dropped between RFC1883 and RFC2460.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifdef
unit|static int ip6_rthdr0(m, ip6, rh0) 	struct mbuf *m; 	struct ip6_hdr *ip6; 	struct ip6_rthdr0 *rh0; { 	int addrs, index; 	struct in6_addr *nextaddr, tmpaddr; 	struct in6_ifaddr *ifa;  	if (rh0->ip6r0_segleft == 0) 		return (0);  	if (rh0->ip6r0_len % 2
ifdef|#
directive|ifdef
name|COMPAT_RFC1883
end_ifdef

begin_endif
unit||| rh0->ip6r0_len> 46
endif|#
directive|endif
end_endif

begin_comment
unit|) {
comment|/* 		 * Type 0 routing header can't contain more than 23 addresses. 		 * RFC 2462: this limitation was removed since strict/loose 		 * bitmap field was deleted. 		 */
end_comment

begin_comment
unit|ip6stat.ip6s_badoptions++; 		icmp6_error(m, ICMP6_PARAM_PROB, ICMP6_PARAMPROB_HEADER, 			    (caddr_t)&rh0->ip6r0_len - (caddr_t)ip6); 		return (-1); 	}  	if ((addrs = rh0->ip6r0_len / 2)< rh0->ip6r0_segleft) { 		ip6stat.ip6s_badoptions++; 		icmp6_error(m, ICMP6_PARAM_PROB, ICMP6_PARAMPROB_HEADER, 			    (caddr_t)&rh0->ip6r0_segleft - (caddr_t)ip6); 		return (-1); 	}  	index = addrs - rh0->ip6r0_segleft; 	rh0->ip6r0_segleft--; 	nextaddr = ((struct in6_addr *)(rh0 + 1)) + index;
comment|/* 	 * reject invalid addresses.  be proactive about malicious use of 	 * IPv4 mapped/compat address. 	 * XXX need more checks? 	 */
end_comment

begin_comment
unit|if (IN6_IS_ADDR_MULTICAST(nextaddr) || 	    IN6_IS_ADDR_UNSPECIFIED(nextaddr) || 	    IN6_IS_ADDR_V4MAPPED(nextaddr) || 	    IN6_IS_ADDR_V4COMPAT(nextaddr)) { 		ip6stat.ip6s_badoptions++; 		m_freem(m); 		return (-1); 	} 	if (IN6_IS_ADDR_MULTICAST(&ip6->ip6_dst) || 	    IN6_IS_ADDR_UNSPECIFIED(&ip6->ip6_dst) || 	    IN6_IS_ADDR_V4MAPPED(&ip6->ip6_dst) || 	    IN6_IS_ADDR_V4COMPAT(&ip6->ip6_dst)) { 		ip6stat.ip6s_badoptions++; 		m_freem(m); 		return (-1); 	}
comment|/* 	 * Determine the scope zone of the next hop, based on the interface 	 * of the current hop. [RFC4007, Section 9] 	 * Then disambiguate the scope zone for the next hop (if necessary). 	 */
end_comment

begin_comment
unit|if ((ifa = ip6_getdstifaddr(m)) == NULL) 		goto bad; 	if (in6_setscope(nextaddr, ifa->ia_ifp, NULL) != 0) { 		ip6stat.ip6s_badscope++; 		goto bad; 	}
comment|/* 	 * Swap the IPv6 destination address and nextaddr. Forward the packet. 	 */
end_comment

begin_comment
unit|tmpaddr = *nextaddr; 	*nextaddr = ip6->ip6_dst; 	in6_clearscope(nextaddr);
comment|/* XXX */
end_comment

begin_ifdef
unit|ip6->ip6_dst = tmpaddr;
ifdef|#
directive|ifdef
name|COMPAT_RFC1883
end_ifdef

begin_else
unit|if (rh0->ip6r0_slmap[index / 8]& (1<< (7 - (index % 8)))) 		ip6_forward(m, IPV6_SRCRT_NEIGHBOR); 	else 		ip6_forward(m, IPV6_SRCRT_NOTNEIGHBOR);
else|#
directive|else
end_else

begin_endif
unit|ip6_forward(m, 1);
endif|#
directive|endif
end_endif

begin_comment
unit|return (-1);
comment|/* m would be freed in ip6_forward() */
end_comment

begin_endif
unit|bad: 	m_freem(m); 	return (-1); }
endif|#
directive|endif
end_endif

end_unit

