begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1996 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *   * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_MIB_H
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_MIB_H
value|1
end_define

begin_struct
struct|struct
name|ifmibdata
block|{
name|char
name|ifmd_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* name of interface */
name|int
name|ifmd_pcount
decl_stmt|;
comment|/* number of promiscuous listeners */
name|int
name|ifmd_flags
decl_stmt|;
comment|/* interface flags */
name|struct
name|if_data
name|ifmd_data
decl_stmt|;
comment|/* generic information and statistics */
name|int
name|ifmd_snd_len
decl_stmt|;
comment|/* instantaneous length of send queue */
name|int
name|ifmd_snd_maxlen
decl_stmt|;
comment|/* maximum length of send queue */
name|int
name|ifmd_snd_drops
decl_stmt|;
comment|/* number of drops in send queue */
block|}
struct|;
end_struct

begin_comment
comment|/*  * sysctl MIB tags at the net.link.generic level  */
end_comment

begin_define
define|#
directive|define
name|IFMIB_SYSTEM
value|1
end_define

begin_comment
comment|/* non-interface-specific */
end_comment

begin_define
define|#
directive|define
name|IFMIB_IFDATA
value|2
end_define

begin_comment
comment|/* per-interface data table */
end_comment

begin_comment
comment|/*  * MIB tags for the various net.link.generic.ifdata tables  */
end_comment

begin_define
define|#
directive|define
name|IFDATA_GENERAL
value|1
end_define

begin_comment
comment|/* generic stats for all kinds of ifaces */
end_comment

begin_define
define|#
directive|define
name|IFDATA_LINKSPECIFIC
value|2
end_define

begin_comment
comment|/* specific to the type of interface */
end_comment

begin_comment
comment|/*  * MIB tags at the net.link.generic.system level  */
end_comment

begin_define
define|#
directive|define
name|IFMIB_IFCOUNT
value|1
end_define

begin_comment
comment|/* number of interfaces configured */
end_comment

begin_comment
comment|/*  * MIB tags as the net.link level  * All of the other values are IFT_* names defined in if_types.h.  */
end_comment

begin_define
define|#
directive|define
name|NETLINK_GENERIC
value|0
end_define

begin_comment
comment|/* functions not specific to a type of iface */
end_comment

begin_comment
comment|/*  * The reason why the IFDATA_LINKSPECIFIC stuff is not under the  * net.link.<iftype> branches is twofold:  *   1) It's easier to code this way, and doesn't require duplication.  *   2) The fourth level under net.link.<iftype> is<pf>; that is to say,  *	the net.link.<iftype> tree instruments the adaptation layers between  *<iftype> and a particular protocol family (e.g., net.link.ether.inet  *	instruments ARP).  This does not really leave room for anything else  *	that needs to have a well-known number.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_MIB_H */
end_comment

end_unit

