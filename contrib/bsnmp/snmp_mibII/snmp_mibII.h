begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: bsnmp/snmp_mibII/snmp_mibII.h,v 1.17 2005/05/23 09:03:43 brandt_h Exp $  *  * Implementation of the interfaces and IP groups of MIB-II.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|snmp_mibII_h_
end_ifndef

begin_define
define|#
directive|define
name|snmp_mibII_h_
end_define

begin_comment
comment|/* forward declaration */
end_comment

begin_struct_decl
struct_decl|struct
name|mibif
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|mibif_notify
block|{
name|MIBIF_NOTIFY_DESTROY
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|mibif_notify_f
function_decl|)
parameter_list|(
name|struct
name|mibif
modifier|*
parameter_list|,
name|enum
name|mibif_notify
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Interfaces. This structure describes one interface as seen in the MIB.  * Interfaces are indexed by ifindex. This is not the same as the index  * used by the system because of the rules in RFC-2863 section 3.1.5. This  * RFC requires, that an ifindex is not to be re-used for ANOTHER dynamically  * interfaces once the interface was deleted. The system's ifindex is in  * sysindex. Mapping is via the mapping table below.  */
end_comment

begin_struct
struct|struct
name|mibif
block|{
name|TAILQ_ENTRY
argument_list|(
argument|mibif
argument_list|)
name|link
expr_stmt|;
name|u_int
name|flags
decl_stmt|;
name|u_int
name|index
decl_stmt|;
comment|/* the logical ifindex */
name|u_int
name|sysindex
decl_stmt|;
name|char
name|name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|char
name|descr
index|[
literal|256
index|]
decl_stmt|;
name|struct
name|ifmibdata
name|mib
decl_stmt|;
name|uint64_t
name|mibtick
decl_stmt|;
name|void
modifier|*
name|specmib
decl_stmt|;
name|size_t
name|specmiblen
decl_stmt|;
name|u_char
modifier|*
name|physaddr
decl_stmt|;
name|u_int
name|physaddrlen
decl_stmt|;
name|int
name|has_connector
decl_stmt|;
name|int
name|trap_enable
decl_stmt|;
name|uint64_t
name|counter_disc
decl_stmt|;
comment|/* 	 * This is needed to handle interface type specific information 	 * in sub-modules. It contains a function pointer which handles 	 * notifications and a data pointer to arbitrary data. 	 * Should be set via the mibif_notify function. 	 */
name|mibif_notify_f
name|xnotify
decl_stmt|;
name|void
modifier|*
name|xnotify_data
decl_stmt|;
specifier|const
name|struct
name|lmodule
modifier|*
name|xnotify_mod
decl_stmt|;
comment|/* to be set by ifType specific modules. This is ifSpecific. */
name|struct
name|asn_oid
name|spec_oid
decl_stmt|;
comment|/* private data - don't touch */
name|void
modifier|*
name|private
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interface IP-address table.  */
end_comment

begin_struct
struct|struct
name|mibifa
block|{
name|TAILQ_ENTRY
argument_list|(
argument|mibifa
argument_list|)
name|link
expr_stmt|;
name|struct
name|in_addr
name|inaddr
decl_stmt|;
name|struct
name|in_addr
name|inmask
decl_stmt|;
name|struct
name|in_addr
name|inbcast
decl_stmt|;
name|struct
name|asn_oid
name|index
decl_stmt|;
comment|/* index for table search */
name|u_int
name|ifindex
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interface receive addresses. Interface link-level multicast, broadcast  * and hardware addresses are handled automatically.  */
end_comment

begin_struct
struct|struct
name|mibrcvaddr
block|{
name|TAILQ_ENTRY
argument_list|(
argument|mibrcvaddr
argument_list|)
name|link
expr_stmt|;
name|struct
name|asn_oid
name|index
decl_stmt|;
name|u_int
name|ifindex
decl_stmt|;
name|u_char
name|addr
index|[
name|ASN_MAXOIDLEN
index|]
decl_stmt|;
name|size_t
name|addrlen
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|MIBRCVADDR_VOLATILE
init|=
literal|0x00000001
block|,
name|MIBRCVADDR_BCAST
init|=
literal|0x00000002
block|,
name|MIBRCVADDR_HW
init|=
literal|0x00000004
block|, }
enum|;
end_enum

begin_comment
comment|/* network socket */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mib_netsock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set an interface name to dynamic mode */
end_comment

begin_function_decl
name|void
name|mib_if_set_dyn
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* re-read the systems interface list */
end_comment

begin_function_decl
name|void
name|mib_refresh_iflist
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* find interface by index */
end_comment

begin_function_decl
name|struct
name|mibif
modifier|*
name|mib_find_if
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mibif
modifier|*
name|mib_find_if_sys
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mibif
modifier|*
name|mib_find_if_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* iterate through all interfaces */
end_comment

begin_function_decl
name|struct
name|mibif
modifier|*
name|mib_first_if
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mibif
modifier|*
name|mib_next_if
parameter_list|(
specifier|const
name|struct
name|mibif
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* register for interface creations */
end_comment

begin_function_decl
name|int
name|mib_register_newif
parameter_list|(
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|mibif
modifier|*
parameter_list|)
parameter_list|,
specifier|const
name|struct
name|lmodule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mib_unregister_newif
parameter_list|(
specifier|const
name|struct
name|lmodule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get fresh MIB data */
end_comment

begin_function_decl
name|int
name|mib_fetch_ifmib
parameter_list|(
name|struct
name|mibif
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* change the ADMIN status of an interface and refresh the MIB */
end_comment

begin_function_decl
name|int
name|mib_if_admin
parameter_list|(
name|struct
name|mibif
modifier|*
parameter_list|,
name|int
name|up
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* find interface address by address */
end_comment

begin_function_decl
name|struct
name|mibifa
modifier|*
name|mib_find_ifa
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* find first/next address for a given interface */
end_comment

begin_function_decl
name|struct
name|mibifa
modifier|*
name|mib_first_ififa
parameter_list|(
specifier|const
name|struct
name|mibif
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mibifa
modifier|*
name|mib_next_ififa
parameter_list|(
name|struct
name|mibifa
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* create/delete stacking entries */
end_comment

begin_function_decl
name|int
name|mib_ifstack_create
parameter_list|(
specifier|const
name|struct
name|mibif
modifier|*
name|lower
parameter_list|,
specifier|const
name|struct
name|mibif
modifier|*
name|upper
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mib_ifstack_delete
parameter_list|(
specifier|const
name|struct
name|mibif
modifier|*
name|lower
parameter_list|,
specifier|const
name|struct
name|mibif
modifier|*
name|upper
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* find receive address */
end_comment

begin_function_decl
name|struct
name|mibrcvaddr
modifier|*
name|mib_find_rcvaddr
parameter_list|(
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* create/delete receive addresses */
end_comment

begin_function_decl
name|struct
name|mibrcvaddr
modifier|*
name|mib_rcvaddr_create
parameter_list|(
name|struct
name|mibif
modifier|*
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
name|mib_rcvaddr_delete
parameter_list|(
name|struct
name|mibrcvaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* register for interface notification */
end_comment

begin_function_decl
name|void
modifier|*
name|mibif_notify
parameter_list|(
name|struct
name|mibif
modifier|*
parameter_list|,
specifier|const
name|struct
name|lmodule
modifier|*
parameter_list|,
name|mibif_notify_f
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mibif_unnotify
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

