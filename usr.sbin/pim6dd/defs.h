begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1998 by the University of Oregon.  *  All rights reserved.  *  *  Permission to use, copy, modify, and distribute this software and  *  its documentation in source and binary forms for lawful  *  purposes and without fee is hereby granted, provided  *  that the above copyright notice appear in all copies and that both  *  the copyright notice and this permission notice appear in supporting  *  documentation, and that any documentation, advertising materials,  *  and other materials related to such distribution and use acknowledge  *  that the software was developed by the University of Oregon.  *  The name of the University of Oregon may not be used to endorse or   *  promote products derived from this software without specific prior   *  written permission.  *  *  THE UNIVERSITY OF OREGON DOES NOT MAKE ANY REPRESENTATIONS  *  ABOUT THE SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE.  THIS SOFTWARE IS  *  PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,  *  INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND   *  NON-INFRINGEMENT.  *  *  IN NO EVENT SHALL UO, OR ANY OTHER CONTRIBUTOR BE LIABLE FOR ANY  *  SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, WHETHER IN CONTRACT,  *  TORT, OR OTHER FORM OF ACTION, ARISING OUT OF OR IN CONNECTION WITH,  *  THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *  Other copyrights might apply to parts of this software and are so  *  noted when applicable.  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to   *  Kurt Windisch (kurtw@antc.uoregon.edu)  *  *  $Id: defs.h,v 1.7 2000/04/30 13:01:36 itojun Exp $  */
end_comment

begin_comment
comment|/*  * Part of this program has been derived from PIM sparse-mode pimd.  * The pimd program is covered by the license in the accompanying file  * named "LICENSE.pimd".  *    * The pimd program is COPYRIGHT 1998 by University of Southern California.  *  * Part of this program has been derived from mrouted.  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE.mrouted".  *   * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  * $FreeBSD$  */
end_comment

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
file|<unistd.h>
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
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

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
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_if
if|#
directive|if
operator|(
operator|(
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|)
operator|||
operator|(
operator|(
name|defined
name|SunOS
operator|)
operator|&&
operator|(
name|SunOS
operator|<
literal|50
operator|)
operator|)
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSV || __bsdi__ || SunOS 4.x */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|>=
literal|3
end_if

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__>= 3 */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/icmp6.h>
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
file|<arpa/inet.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/* sigh */
end_comment

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|>=
literal|220000
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|rtentry
value|kernel_rtentry
end_define

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_undef
undef|#
directive|undef
name|rtentry
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __bsdi__ or __FreeBSD_version>= 220000 */
end_comment

begin_include
include|#
directive|include
file|<netinet/ip_mroute.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ip6_mroute.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RSRR
end_ifdef

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSRR */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|u_int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|u_int16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|u_int8
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*cfunc_t
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*ihfunc_t
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|,
name|fd_set
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_include
include|#
directive|include
file|"pimdd.h"
end_include

begin_include
include|#
directive|include
file|"mrt.h"
end_include

begin_include
include|#
directive|include
file|"mld6.h"
end_include

begin_include
include|#
directive|include
file|"vif.h"
end_include

begin_include
include|#
directive|include
file|"debug.h"
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RSRR
end_ifdef

begin_include
include|#
directive|include
file|"rsrr.h"
end_include

begin_include
include|#
directive|include
file|"rsrr_var.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSRR */
end_comment

begin_comment
comment|/*  * Miscellaneous constants and macros  */
end_comment

begin_comment
comment|/* #if (!(defined(__bsdi__))&& !(defined(KERNEL))) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (b) : (a))
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (b) : (a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Various definitions to make it working for different platforms  */
end_comment

begin_comment
comment|/* The old style sockaddr definition doesn't have sa_len */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199006
operator|)
operator|)
end_if

begin_comment
comment|/* sa_len was added with 4.3-Reno */
end_comment

begin_define
define|#
directive|define
name|HAVE_SA_LEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Versions of Solaris older than 2.6 don't have routing sockets. */
end_comment

begin_comment
comment|/* XXX TODO: check FreeBSD version and add all other platforms */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|defined
argument_list|(
name|SunOS
argument_list|)
operator|&&
name|SunOS
operator|>=
literal|56
operator|)
operator|||
operator|(
name|defined
name|__FreeBSD__
operator|)
operator|||
operator|(
name|defined
name|IRIX
operator|)
operator|||
operator|(
name|defined
name|__bsdi__
operator|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|HAVE_ROUTING_SOCKETS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|CREATE
value|TRUE
end_define

begin_define
define|#
directive|define
name|DONT_CREATE
value|FALSE
end_define

begin_define
define|#
directive|define
name|EQUAL
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp((s1), (s2)) == 0)
end_define

begin_comment
comment|/* obnoxious gcc gives an extraneous warning about this constant... */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|JAN_1970
value|2208988800UL
end_define

begin_comment
comment|/* 1970 - 1900 in seconds */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JAN_1970
value|2208988800L
end_define

begin_comment
comment|/* 1970 - 1900 in seconds */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MINHLIM
value|1
end_define

begin_comment
comment|/* min hoplim in the packets send locally */
end_comment

begin_define
define|#
directive|define
name|MAX_IP_PACKET_LEN
value|576
end_define

begin_define
define|#
directive|define
name|MIN_IP_HEADER_LEN
value|20
end_define

begin_define
define|#
directive|define
name|MAX_IP_HEADER_LEN
value|60
end_define

begin_comment
comment|/*  * The IGMPv2<netinet/in.h> defines INADDR_ALLRTRS_GROUP, but earlier  * ones don't, so we define it conditionally here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INADDR_ALLRTRS_GROUP
end_ifndef

begin_comment
comment|/* address for multicast mtrace msg */
end_comment

begin_define
define|#
directive|define
name|INADDR_ALLRTRS_GROUP
value|(u_int32)0xe0000002
end_define

begin_comment
comment|/* 224.0.0.2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INADDR_MAX_LOCAL_GROUP
end_ifndef

begin_decl_stmt
name|define
name|INADDR_MAX_LOCAL_GROUP
argument_list|(
name|u_int32
argument_list|)
decl|0xe00000ff
comment|/* 224.0.0.255 */
endif|#
directive|endif
define|#
directive|define
name|INADDR_ANY_N
value|(u_int32)0x00000000
comment|/* INADDR_ANY in 							 * network order */
define|#
directive|define
name|CLASSD_PREFIX
value|(u_int32)0xe0000000
comment|/* 224.0.0.0 */
define|#
directive|define
name|ALL_MCAST_GROUPS_ADDR
value|(u_int32)0xe0000000
comment|/* 224.0.0.0 */
define|#
directive|define
name|ALL_MCAST_GROUPS_LENGTH
value|4
comment|/* Used by DVMRP */
define|#
directive|define
name|DEFAULT_METRIC
value|1
comment|/* default subnet/tunnel metric     */
define|#
directive|define
name|DEFAULT_THRESHOLD
value|1
comment|/* default subnet/tunnel threshold  */
define|#
directive|define
name|TIMER_INTERVAL
value|5
comment|/* 5 sec virtual timer granularity  */
ifdef|#
directive|ifdef
name|RSRR
define|#
directive|define
name|BIT_ZERO
parameter_list|(
name|X
parameter_list|)
value|((X) = 0)
define|#
directive|define
name|BIT_SET
parameter_list|(
name|X
parameter_list|,
name|n
parameter_list|)
value|((X) |= 1<< (n))
define|#
directive|define
name|BIT_CLR
parameter_list|(
name|X
parameter_list|,
name|n
parameter_list|)
value|((X)&= ~(1<< (n)))
define|#
directive|define
name|BIT_TST
parameter_list|(
name|X
parameter_list|,
name|n
parameter_list|)
value|((X)& 1<< (n))
endif|#
directive|endif
comment|/* RSRR */
ifdef|#
directive|ifdef
name|SYSV
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy((b), (a), (c))
define|#
directive|define
name|bzero
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset((s), 0, (n))
define|#
directive|define
name|setlinebuf
parameter_list|(
name|s
parameter_list|)
value|setvbuf((s), (NULL), (_IOLBF), 0)
define|#
directive|define
name|RANDOM
parameter_list|()
value|lrand48()
else|#
directive|else
define|#
directive|define
name|RANDOM
parameter_list|()
value|random()
endif|#
directive|endif
comment|/* SYSV */
comment|/*  * External declarations for global variables and functions.  */
define|#
directive|define
name|RECV_BUF_SIZE
value|64*1024
comment|/* Maximum buff size to send 					        * or receive packet */
define|#
directive|define
name|SO_RECV_BUF_SIZE_MAX
value|256*1024
define|#
directive|define
name|SO_RECV_BUF_SIZE_MIN
value|48*1024
comment|/* TODO: describe the variables and clean up */
decl|extern
name|char
modifier|*
name|mld6_recv_buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mld6_send_buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pim6_recv_buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pim6_send_buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mld6_socket
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pim6_socket
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in6
name|allnodes_group
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in6
name|allrouters_group
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in6
name|allpim6routers_group
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|if_set
name|nbr_mifs
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RSRR
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|rsrr_socket
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSRR */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|virtual_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|configfilename
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|default_source_metric
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32
name|default_source_preference
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|srcentry_t
modifier|*
name|srclist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|grpentry_t
modifier|*
name|grplist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|uvif
name|uvifs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vifi_t
name|numvifs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|total_interfaces
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|phys_vif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|udp_socket
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vifs_down
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|s1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|s2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|s3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|s4
index|[]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199103
operator|)
operator|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IGMP_MEMBERSHIP_QUERY
end_ifndef

begin_define
define|#
directive|define
name|IGMP_MEMBERSHIP_QUERY
value|IGMP_HOST_MEMBERSHIP_QUERY
end_define

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|IGMP_V1_MEMBERSHIP_REPORT
value|IGMP_HOST_MEMBERSHIP_REPORT
end_define

begin_define
define|#
directive|define
name|IGMP_V2_MEMBERSHIP_REPORT
value|IGMP_HOST_NEW_MEMBERSHIP_REPORT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IGMP_V1_MEMBERSHIP_REPORT
value|IGMP_v1_HOST_MEMBERSHIP_REPORT
end_define

begin_define
define|#
directive|define
name|IGMP_V2_MEMBERSHIP_REPORT
value|IGMP_v2_HOST_MEMBERSHIP_REPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IGMP_V2_LEAVE_GROUP
value|IGMP_HOST_LEAVE_MESSAGE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|IGMP_MTRACE_RESP
value|IGMP_MTRACE_REPLY
end_define

begin_define
define|#
directive|define
name|IGMP_MTRACE
value|IGMP_MTRACE_QUERY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For timeout. The timers count down */
end_comment

begin_define
define|#
directive|define
name|SET_TIMER
parameter_list|(
name|timer
parameter_list|,
name|value
parameter_list|)
value|(timer) = (value)
end_define

begin_define
define|#
directive|define
name|IF_TIMER_SET
parameter_list|(
name|timer
parameter_list|)
value|if ((timer)> 0)
end_define

begin_define
define|#
directive|define
name|IF_TIMER_NOT_SET
parameter_list|(
name|timer
parameter_list|)
value|if ((timer)<= 0)
end_define

begin_define
define|#
directive|define
name|FIRE_TIMER
parameter_list|(
name|timer
parameter_list|)
value|(timer) = 0
end_define

begin_define
define|#
directive|define
name|IF_TIMEOUT
parameter_list|(
name|value
parameter_list|)
define|\
value|if (!(((value)>= TIMER_INTERVAL)&& ((value) -= TIMER_INTERVAL)))
end_define

begin_define
define|#
directive|define
name|IF_NOT_TIMEOUT
parameter_list|(
name|value
parameter_list|)
define|\
value|if (((value)>= TIMER_INTERVAL)&& ((value) -= TIMER_INTERVAL))
end_define

begin_define
define|#
directive|define
name|TIMEOUT
parameter_list|(
name|value
parameter_list|)
define|\
value|(!(((value)>= TIMER_INTERVAL)&& ((value) -= TIMER_INTERVAL)))
end_define

begin_define
define|#
directive|define
name|NOT_TIMEOUT
parameter_list|(
name|value
parameter_list|)
define|\
value|(((value)>= TIMER_INTERVAL)&& ((value) -= TIMER_INTERVAL))
end_define

begin_define
define|#
directive|define
name|ELSE
value|else
end_define

begin_comment
comment|/* To make emacs cc-mode happy */
end_comment

begin_comment
comment|/*  * External function definitions  */
end_comment

begin_comment
comment|/* callout.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|callout_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_all_callouts
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|age_callout_queue
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timer_nextTimer
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timer_setTimer
name|__P
argument_list|(
operator|(
name|int
operator|,
name|cfunc_t
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|timer_clearTimer
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timer_leftTimer
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* config.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|config_vifs_from_kernel
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|config_vifs_from_file
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|packet_kind
name|__P
argument_list|(
operator|(
name|u_int
name|proto
operator|,
name|u_int
name|type
operator|,
name|u_int
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debug_kind
name|__P
argument_list|(
operator|(
name|u_int
name|proto
operator|,
name|u_int
name|type
operator|,
name|u_int
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|log
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_mldqueriers
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|log_level
name|__P
argument_list|(
operator|(
name|u_int
name|proto
operator|,
name|u_int
name|type
operator|,
name|u_int
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump
name|__P
argument_list|(
operator|(
name|int
name|i
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fdump
name|__P
argument_list|(
operator|(
name|int
name|i
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cdump
name|__P
argument_list|(
operator|(
name|int
name|i
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_vifs
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_pim_mrt
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_lcl_grp
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|fp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dvmrp_proto.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dvmrp_accept_probe
name|__P
argument_list|(
operator|(
name|u_int32
name|src
operator|,
name|u_int32
name|dst
operator|,
name|char
operator|*
name|p
operator|,
name|int
name|datalen
operator|,
name|u_int32
name|level
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dvmrp_accept_report
name|__P
argument_list|(
operator|(
name|u_int32
name|src
operator|,
name|u_int32
name|dst
operator|,
name|char
operator|*
name|p
operator|,
name|int
name|datalen
operator|,
name|u_int32
name|level
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dvmrp_accept_info_request
name|__P
argument_list|(
operator|(
name|u_int32
name|src
operator|,
name|u_int32
name|dst
operator|,
name|u_char
operator|*
name|p
operator|,
name|int
name|datalen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dvmrp_accept_info_reply
name|__P
argument_list|(
operator|(
name|u_int32
name|src
operator|,
name|u_int32
name|dst
operator|,
name|u_char
operator|*
name|p
operator|,
name|int
name|datalen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dvmrp_accept_neighbors
name|__P
argument_list|(
operator|(
name|u_int32
name|src
operator|,
name|u_int32
name|dst
operator|,
name|u_char
operator|*
name|p
operator|,
name|int
name|datalen
operator|,
name|u_int32
name|level
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dvmrp_accept_neighbors2
name|__P
argument_list|(
operator|(
name|u_int32
name|src
operator|,
name|u_int32
name|dst
operator|,
name|u_char
operator|*
name|p
operator|,
name|int
name|datalen
operator|,
name|u_int32
name|level
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dvmrp_accept_prune
name|__P
argument_list|(
operator|(
name|u_int32
name|src
operator|,
name|u_int32
name|dst
operator|,
name|char
operator|*
name|p
operator|,
name|int
name|datalen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dvmrp_accept_graft
name|__P
argument_list|(
operator|(
name|u_int32
name|src
operator|,
name|u_int32
name|dst
operator|,
name|char
operator|*
name|p
operator|,
name|int
name|datalen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dvmrp_accept_g_ack
name|__P
argument_list|(
operator|(
name|u_int32
name|src
operator|,
name|u_int32
name|dst
operator|,
name|char
operator|*
name|p
operator|,
name|int
name|datalen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mld6.c */
end_comment

begin_decl_stmt
name|void
name|init_mld6
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|send_mld6
name|__P
argument_list|(
operator|(
name|int
name|type
operator|,
name|int
name|code
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|dst
operator|,
expr|struct
name|in6_addr
operator|*
name|group
operator|,
name|int
name|index
operator|,
name|int
name|delay
operator|,
name|int
name|datalen
operator|,
name|int
name|alert
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mld6_proto.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|query_groups
name|__P
argument_list|(
operator|(
expr|struct
name|uvif
operator|*
name|v
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|check_grp_membership
name|__P
argument_list|(
operator|(
expr|struct
name|uvif
operator|*
name|v
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_listener_query
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|,
expr|struct
name|in6_addr
operator|*
name|dst
operator|,
expr|struct
name|in6_addr
operator|*
name|group
operator|,
name|int
name|tmo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_listener_report
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|,
expr|struct
name|in6_addr
operator|*
name|dst
operator|,
expr|struct
name|in6_addr
operator|*
name|group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|accept_listener_done
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|,
expr|struct
name|in6_addr
operator|*
name|dst
operator|,
expr|struct
name|in6_addr
operator|*
name|group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|check_multicast_listener
name|__P
argument_list|(
operator|(
expr|struct
name|uvif
operator|*
name|v
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* igmp.c */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|extern void     init_igmp     __P((void)); extern void     send_igmp     __P((char *buf, u_int32 src, u_int32 dst, 				   int type, int code, u_int32 group, 				   int datalen));
comment|/* igmp_proto.c */
end_comment

begin_endif
unit|extern void     query_groups            __P((struct uvif *v)); extern void     accept_membership_query __P((u_int32 src, u_int32 dst, 					     u_int32 group, int tmo)); extern void     accept_group_report     __P((u_int32 src, u_int32 dst, 					     u_int32 group, int r_type)); extern void     accept_leave_message    __P((u_int32 src, u_int32 dst, 					     u_int32 group));
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* inet.c */
end_comment

begin_ifdef
unit|extern int      inet_cksum        __P((u_int16 *addr, u_int len)); extern int      inet_valid_host   __P((u_int32 naddr)); extern int      inet_valid_mask   __P((u_int32 mask)); extern int      inet_valid_subnet __P((u_int32 nsubnet, u_int32 nmask)); extern char    *inet_fmt          __P((u_int32, char *s));
ifdef|#
directive|ifdef
name|NOSUCHDEF
end_ifdef

begin_endif
unit|extern char    *inet_fmts         __P((u_int32 addr, u_int32 mask, char *s));
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSUCHDEF */
end_comment

begin_endif
unit|extern char    *netname           __P((u_int32 addr, u_int32 mask)); extern u_int32  inet_parse        __P((char *s, int n));
endif|#
directive|endif
end_endif

begin_comment
comment|/* inet6.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inet6_equal
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|sa1
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|sa2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_lessoreq
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|sa1
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|sa2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_lessthan
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|sa1
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|sa2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_localif_address
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|sa
operator|,
expr|struct
name|uvif
operator|*
name|v
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_greaterthan
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|sa1
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|sa2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_greateroreq
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|sa1
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|sa2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_match_prefix
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|sa1
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|sa2
operator|,
expr|struct
name|in6_addr
operator|*
name|mask
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_mask2plen
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
operator|*
name|mask
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_uvif2scopeid
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|sa
operator|,
expr|struct
name|uvif
operator|*
name|v
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inet6_valid_host
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|inet6_fmt
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
operator|*
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ifindex2str
name|__P
argument_list|(
operator|(
name|int
name|ifindex
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|net6name
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
operator|*
name|prefix
operator|,
expr|struct
name|in6_addr
operator|*
name|mask
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kern.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|k_set_rcvbuf
name|__P
argument_list|(
operator|(
name|int
name|socket
operator|,
name|int
name|bufsize
operator|,
name|int
name|minsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_hdr_include
name|__P
argument_list|(
operator|(
name|int
name|socket
operator|,
name|int
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_set_hlim
name|__P
argument_list|(
operator|(
name|int
name|socket
operator|,
name|int
name|t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_set_loop
name|__P
argument_list|(
operator|(
name|int
name|socket
operator|,
name|int
name|l
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_set_if
name|__P
argument_list|(
operator|(
name|int
name|socket
operator|,
name|u_int
name|ifindex
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_join
name|__P
argument_list|(
operator|(
name|int
name|socket
operator|,
expr|struct
name|in6_addr
operator|*
name|grp
operator|,
name|u_int
name|ifindex
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_leave
name|__P
argument_list|(
operator|(
name|int
name|socket
operator|,
expr|struct
name|in6_addr
operator|*
name|grp
operator|,
name|u_int
name|ifindex
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_init_pim
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_stop_pim
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|k_del_mfc
name|__P
argument_list|(
operator|(
name|int
name|socket
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|k_chg_mfc
name|__P
argument_list|(
operator|(
name|int
name|socket
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|,
name|vifi_t
name|iif
operator|,
name|if_set
operator|*
name|oifs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_add_vif
name|__P
argument_list|(
operator|(
name|int
name|socket
operator|,
name|vifi_t
name|vifi
operator|,
expr|struct
name|uvif
operator|*
name|v
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|k_del_vif
name|__P
argument_list|(
operator|(
name|int
name|socket
operator|,
name|vifi_t
name|vifi
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|k_get_vif_count
name|__P
argument_list|(
operator|(
name|vifi_t
name|vifi
operator|,
expr|struct
name|vif_count
operator|*
name|retval
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|k_get_sg_cnt
name|__P
argument_list|(
operator|(
name|int
name|socket
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|,
expr|struct
name|sg_count
operator|*
name|retval
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* main.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|register_input_handler
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|,
name|ihfunc_t
name|func
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mrt.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_pim6_mrt
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mrtentry_t
modifier|*
name|find_route
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|,
name|u_int16
name|flags
operator|,
name|char
name|create
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|grpentry_t
modifier|*
name|find_group
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|srcentry_t
modifier|*
name|find_source
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_mrtentry
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_srcentry
name|__P
argument_list|(
operator|(
name|srcentry_t
operator|*
name|srcentry_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_grpentry
name|__P
argument_list|(
operator|(
name|grpentry_t
operator|*
name|grpentry_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mrtfilter
modifier|*
name|search_filter
name|__P
argument_list|(
operator|(
expr|struct
name|in6_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mrtfilter
modifier|*
name|add_filter
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|in6_addr
operator|*
operator|,
expr|struct
name|in6_addr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pim6.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_pim6
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|send_pim6
name|__P
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|dst
operator|,
name|int
name|type
operator|,
name|int
name|datalen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pim6_poto.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|receive_pim6_hello
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|,
name|char
operator|*
name|pim_message
operator|,
name|int
name|datalen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|send_pim6_hello
name|__P
argument_list|(
operator|(
expr|struct
name|uvif
operator|*
name|v
operator|,
name|u_int16
name|holdtime
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_pim6_nbr
name|__P
argument_list|(
operator|(
name|pim_nbr_entry_t
operator|*
name|nbr_delete
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|receive_pim6_join_prune
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|,
name|char
operator|*
name|pim_message
operator|,
name|int
name|datalen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|send_pim6_jp
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|,
name|int
name|action
operator|,
name|mifi_t
name|mifi
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|target_addr
operator|,
name|u_int16
name|holdtime
operator|,
name|int
name|echo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|receive_pim6_assert
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|,
name|char
operator|*
name|pim_message
operator|,
name|int
name|datalen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|send_pim6_assert
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|,
name|mifi_t
name|mifi
operator|,
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_pim6_graft_entry
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|receive_pim6_graft
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|,
name|char
operator|*
name|pim_message
operator|,
name|int
name|datalen
operator|,
name|int
name|pimtype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|send_pim6_graft
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* pim.c */
end_comment

begin_comment
unit|extern void         init_pim         __P((void)); extern void         send_pim         __P((char *buf, u_int32 src, u_int32 dst, 					  int type, int datalen)); extern void         send_pim_unicast __P((char *buf, u_int32 src, u_int32 dst, 					  int type, int datalen));
comment|/* pim_proto.c */
end_comment

begin_endif
unit|extern int receive_pim_hello         __P((u_int32 src, u_int32 dst, 					  char *pim_message, int datalen)); extern int send_pim_hello            __P((struct uvif *v, u_int16 holdtime)); extern void delete_pim_nbr           __P((pim_nbr_entry_t *nbr_delete)); extern int receive_pim_join_prune    __P((u_int32 src, u_int32 dst, 					  char *pim_message, int datalen)); extern int send_pim_jp               __P((mrtentry_t *mrtentry_ptr, int action, 					  vifi_t vifi, u_int32 target_addr,  					  u_int16 holdtime)); extern int receive_pim_assert        __P((u_int32 src, u_int32 dst, 					  char *pim_message, int datalen)); extern int send_pim_assert           __P((u_int32 source, u_int32 group, 					  vifi_t vifi, 					  mrtentry_t *mrtentry_ptr)); extern void delete_pim_graft_entry   __P((mrtentry_t *mrtentry_ptr)); extern int receive_pim_graft         __P((u_int32 src, u_int32 dst,  					  char *pim_message, int datalen, 					  int pimtype));
endif|#
directive|endif
end_endif

begin_comment
comment|/* route.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|set_incoming
name|__P
argument_list|(
operator|(
name|srcentry_t
operator|*
name|srcentry_ptr
operator|,
name|int
name|srctype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vifi_t
name|get_iif
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pim_nbr_entry_t
modifier|*
name|find_pim6_nbr
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|add_sg_oif
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|,
name|vifi_t
name|vifi
operator|,
name|u_int16
name|holdtime
operator|,
name|int
name|update_holdtime
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_leaf
name|__P
argument_list|(
operator|(
name|vifi_t
name|vifi
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_leaf
name|__P
argument_list|(
operator|(
name|vifi_t
name|vifi
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_leaves
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|change_interfaces
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|,
name|vifi_t
name|new_iif
operator|,
name|if_set
operator|*
name|new_pruned_oifs
operator|,
name|if_set
operator|*
name|new_leaves_
operator|,
name|if_set
operator|*
name|new_asserted_oifs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|calc_oifs
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|,
name|if_set
operator|*
name|oifs_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|process_kernel_call
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|delete_vif_from_mrt
name|__P
argument_list|(
operator|(
name|vifi_t
name|vifi
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|trigger_join_alert
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|trigger_prune_alert
name|__P
argument_list|(
operator|(
name|mrtentry_t
operator|*
name|mrtentry_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* routesock.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|k_req_incoming
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|source
operator|,
expr|struct
name|rpfctl
operator|*
name|rpfp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ROUTING_SOCKETS
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|init_routesock
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ROUTING_SOCKETS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RSRR
end_ifdef

begin_define
define|#
directive|define
name|gtable
value|mrtentry
end_define

begin_define
define|#
directive|define
name|RSRR_NOTIFICATION_OK
value|TRUE
end_define

begin_define
define|#
directive|define
name|RSRR_NOTIFICATION_FALSE
value|FALSE
end_define

begin_comment
comment|/* rsrr.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|rsrr_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rsrr_clean
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rsrr_cache_send
name|__P
argument_list|(
operator|(
expr|struct
name|gtable
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rsrr_cache_clean
name|__P
argument_list|(
operator|(
expr|struct
name|gtable
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rsrr_cache_bring_up
name|__P
argument_list|(
operator|(
expr|struct
name|gtable
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
comment|/* RSRR */
end_comment

begin_comment
comment|/* timer.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_timers
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|age_vifs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|age_routes
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|clean_srclist
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trace.c */
end_comment

begin_comment
comment|/* u_int is promoted u_char */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|accept_mtrace
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|,
expr|struct
name|in6_addr
operator|*
name|dst
operator|,
expr|struct
name|in6_addr
operator|*
name|group
operator|,
name|int
name|ifindex
operator|,
name|char
operator|*
name|data
operator|,
name|u_int
name|no
operator|,
name|int
name|datalen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vif.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_vifs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|stop_all_vifs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|check_vif_state
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vifi_t
name|local_address
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vifi_t
name|find_vif_direct
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vifi_t
name|find_vif_direct_local
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in6
modifier|*
name|max_global_address
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in6
modifier|*
name|uv_global
name|__P
argument_list|(
operator|(
name|vifi_t
name|vifi
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

