begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: bsnmp/snmp_mibII/mibII.h,v 1.16 2006/02/14 09:04:19 brandt_h Exp $  *  * Implementation of the interfaces and IP groups of MIB-II.  */
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

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_mib.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|"asn1.h"
end_include

begin_include
include|#
directive|include
file|"snmp.h"
end_include

begin_include
include|#
directive|include
file|"snmpmod.h"
end_include

begin_include
include|#
directive|include
file|"snmp_mibII.h"
end_include

begin_include
include|#
directive|include
file|"mibII_tree.h"
end_include

begin_comment
comment|/*  * Interface list and flags.  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|mibif_list
argument_list|,
name|mibif
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
block|{
name|MIBIF_FOUND
init|=
literal|0x0001
block|,
name|MIBIF_HIGHSPEED
init|=
literal|0x0002
block|,
name|MIBIF_VERYHIGHSPEED
init|=
literal|0x0004
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Private mibif data - hang off from the mibif.  */
end_comment

begin_struct
struct|struct
name|mibif_private
block|{
name|uint64_t
name|hc_inoctets
decl_stmt|;
name|uint64_t
name|hc_outoctets
decl_stmt|;
name|uint64_t
name|hc_omcasts
decl_stmt|;
name|uint64_t
name|hc_opackets
decl_stmt|;
name|uint64_t
name|hc_imcasts
decl_stmt|;
name|uint64_t
name|hc_ipackets
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MIBIF_PRIV
parameter_list|(
name|IFP
parameter_list|)
value|((struct mibif_private *)((IFP)->private))
end_define

begin_comment
comment|/*  * Interface addresses.  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|mibifa_list
argument_list|,
name|mibifa
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
block|{
name|MIBIFA_FOUND
init|=
literal|0x0001
block|,
name|MIBIFA_DESTROYED
init|=
literal|0x0002
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Receive addresses  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|mibrcvaddr_list
argument_list|,
name|mibrcvaddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
block|{
name|MIBRCVADDR_FOUND
init|=
literal|0x00010000
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Interface index mapping. The problem here is, that if the same interface  * is reinstantiated (for examble by unloading and loading the hardware driver)  * we must use the same index for this interface. For dynamic interfaces  * (clip, lane) we must use a fresh index, each time a new interface is created.  * To differentiate between these types of interfaces we use the following table  * which contains an entry for each dynamic interface type. All other interface  * types are supposed to be static. The mibindexmap contains an entry for  * all interfaces. The mibif pointer is NULL, if the interface doesn't exist  * anymore.  */
end_comment

begin_struct
struct|struct
name|mibdynif
block|{
name|SLIST_ENTRY
argument_list|(
argument|mibdynif
argument_list|)
name|link
expr_stmt|;
name|char
name|name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|mibdynif_list
argument_list|,
name|mibdynif
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|mibindexmap
block|{
name|STAILQ_ENTRY
argument_list|(
argument|mibindexmap
argument_list|)
name|link
expr_stmt|;
name|u_short
name|sysindex
decl_stmt|;
name|u_int
name|ifindex
decl_stmt|;
name|struct
name|mibif
modifier|*
name|mibif
decl_stmt|;
comment|/* may be NULL */
name|char
name|name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|mibindexmap_list
argument_list|,
name|mibindexmap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Interface stacking. The generic code cannot know how the interfaces stack.  * For this reason it instantiates only the x.0 and 0.x table elements. All  * others have to be instantiated by the interface specific modules.  * The table is read-only.  */
end_comment

begin_struct
struct|struct
name|mibifstack
block|{
name|TAILQ_ENTRY
argument_list|(
argument|mibifstack
argument_list|)
name|link
expr_stmt|;
name|struct
name|asn_oid
name|index
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|mibifstack_list
argument_list|,
name|mibifstack
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * NetToMediaTable (ArpTable)  */
end_comment

begin_struct
struct|struct
name|mibarp
block|{
name|TAILQ_ENTRY
argument_list|(
argument|mibarp
argument_list|)
name|link
expr_stmt|;
name|struct
name|asn_oid
name|index
decl_stmt|;
comment|/* contains both the ifindex and addr */
name|u_char
name|phys
index|[
literal|128
index|]
decl_stmt|;
comment|/* the physical address */
name|u_int
name|physlen
decl_stmt|;
comment|/* and its length */
name|u_int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|mibarp_list
argument_list|,
name|mibarp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
block|{
name|MIBARP_FOUND
init|=
literal|0x00010000
block|,
name|MIBARP_PERM
init|=
literal|0x00000001
block|, }
enum|;
end_enum

begin_comment
comment|/*  * New if registrations  */
end_comment

begin_struct
struct|struct
name|newifreg
block|{
name|TAILQ_ENTRY
argument_list|(
argument|newifreg
argument_list|)
name|link
expr_stmt|;
specifier|const
name|struct
name|lmodule
modifier|*
name|mod
decl_stmt|;
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|mibif
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|newifreg_list
argument_list|,
name|newifreg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* list of all IP addresses */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mibifa_list
name|mibifa_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of all interfaces */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mibif_list
name|mibif_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of dynamic interface names */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mibdynif_list
name|mibdynif_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of all interface index mappings */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mibindexmap_list
name|mibindexmap_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of all stacking entries */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mibifstack_list
name|mibifstack_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of all receive addresses */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mibrcvaddr_list
name|mibrcvaddr_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of all NetToMedia entries */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mibarp_list
name|mibarp_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of interfaces */
end_comment

begin_decl_stmt
specifier|extern
name|int32_t
name|mib_if_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last change of interface table */
end_comment

begin_decl_stmt
specifier|extern
name|uint64_t
name|mib_iftable_last_change
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last change of stack table */
end_comment

begin_decl_stmt
specifier|extern
name|uint64_t
name|mib_ifstack_last_change
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if this is set, one of our lists may be bad. refresh them when idle */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mib_iflist_bad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last time refreshed */
end_comment

begin_decl_stmt
specifier|extern
name|uint64_t
name|mibarpticks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* info on system clocks */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|clockinfo
name|clockinfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* baud rate of fastest interface */
end_comment

begin_decl_stmt
specifier|extern
name|uint64_t
name|mibif_maxspeed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user-forced update interval */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|mibif_force_hc_update_interval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current update interval */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|mibif_hc_update_interval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* re-compute update interval */
end_comment

begin_function_decl
name|void
name|mibif_reset_hc_timer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* interfaces' data poll interval */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|mibII_poll_ticks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restart the data poll timer */
end_comment

begin_function_decl
name|void
name|mibif_restart_mibII_poll_timer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MIBII_POLL_TICKS
value|100
end_define

begin_comment
comment|/* get interfaces and interface addresses. */
end_comment

begin_function_decl
name|void
name|mib_fetch_interfaces
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check whether this interface(type) is dynamic */
end_comment

begin_function_decl
name|int
name|mib_if_is_dyn
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* destroy an interface address */
end_comment

begin_function_decl
name|int
name|mib_destroy_ifa
parameter_list|(
name|struct
name|mibifa
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* restituate a deleted interface address */
end_comment

begin_function_decl
name|void
name|mib_undestroy_ifa
parameter_list|(
name|struct
name|mibifa
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* change interface address */
end_comment

begin_function_decl
name|int
name|mib_modify_ifa
parameter_list|(
name|struct
name|mibifa
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* undo if address modification */
end_comment

begin_function_decl
name|void
name|mib_unmodify_ifa
parameter_list|(
name|struct
name|mibifa
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* create an interface address */
end_comment

begin_function_decl
name|struct
name|mibifa
modifier|*
name|mib_create_ifa
parameter_list|(
name|u_int
name|ifindex
parameter_list|,
name|struct
name|in_addr
name|addr
parameter_list|,
name|struct
name|in_addr
name|mask
parameter_list|,
name|struct
name|in_addr
name|bcast
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* delete a freshly created address */
end_comment

begin_function_decl
name|void
name|mib_uncreate_ifa
parameter_list|(
name|struct
name|mibifa
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* create/delete arp entries */
end_comment

begin_function_decl
name|struct
name|mibarp
modifier|*
name|mib_arp_create
parameter_list|(
specifier|const
name|struct
name|mibif
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mib_arp_delete
parameter_list|(
name|struct
name|mibarp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* find arp entry */
end_comment

begin_function_decl
name|struct
name|mibarp
modifier|*
name|mib_find_arp
parameter_list|(
specifier|const
name|struct
name|mibif
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* update arp table */
end_comment

begin_function_decl
name|void
name|mib_arp_update
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fetch routing table */
end_comment

begin_function_decl
name|u_char
modifier|*
name|mib_fetch_rtab
parameter_list|(
name|int
name|af
parameter_list|,
name|int
name|info
parameter_list|,
name|int
name|arg
parameter_list|,
name|size_t
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* process routing message */
end_comment

begin_function_decl
name|void
name|mib_sroute_process
parameter_list|(
name|struct
name|rt_msghdr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* send a routing message */
end_comment

begin_function_decl
name|void
name|mib_send_rtmsg
parameter_list|(
name|struct
name|rt_msghdr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* extract addresses from routing message */
end_comment

begin_function_decl
name|void
name|mib_extract_addrs
parameter_list|(
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fetch routing table */
end_comment

begin_function_decl
name|int
name|mib_fetch_route
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

