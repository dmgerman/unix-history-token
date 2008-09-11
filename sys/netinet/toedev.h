begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2008, Chelsio Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * 2. Neither the name of the Chelsio Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_TOEDEV_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_TOEDEV_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"no user-serviceable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|uint32_t
name|toedev_registration_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parameter values for offload_get_phys_egress(). */
end_comment

begin_enum
enum|enum
block|{
name|TOE_OPEN
block|,
name|TOE_FAILOVER
block|, }
enum|;
end_enum

begin_comment
comment|/* Parameter values for toe_failover(). */
end_comment

begin_enum
enum|enum
block|{
name|TOE_ACTIVE_SLAVE
block|,
name|TOE_LINK_DOWN
block|,
name|TOE_LINK_UP
block|,
name|TOE_RELEASE
block|,
name|TOE_RELEASE_ALL
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|TOENAMSIZ
value|16
end_define

begin_comment
comment|/* Get the toedev associated with a ifnet. */
end_comment

begin_define
define|#
directive|define
name|TOEDEV
parameter_list|(
name|ifp
parameter_list|)
value|((ifp)->if_llsoftc)
end_define

begin_struct
struct|struct
name|offload_id
block|{
name|unsigned
name|int
name|id
decl_stmt|;
name|unsigned
name|long
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rt_entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tom_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sysctl_oid
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|toedev
block|{
name|TAILQ_ENTRY
argument_list|(
argument|toedev
argument_list|)
name|entry
expr_stmt|;
name|char
name|tod_name
index|[
name|TOENAMSIZ
index|]
decl_stmt|;
comment|/* TOE device name */
name|unsigned
name|int
name|tod_ttid
decl_stmt|;
comment|/* TOE type id */
name|unsigned
name|long
name|tod_flags
decl_stmt|;
comment|/* device flags */
name|unsigned
name|int
name|tod_mtu
decl_stmt|;
comment|/* max TX offloaded data */
name|unsigned
name|int
name|tod_nconn
decl_stmt|;
comment|/* max # of offloaded 						 * connections 						 */
name|struct
name|ifnet
modifier|*
name|tod_lldev
decl_stmt|;
comment|/* first interface */
specifier|const
name|struct
name|tom_info
modifier|*
name|tod_offload_mod
decl_stmt|;
comment|/* TCP offload module */
comment|/* 	 * This TOE device is capable of offloading the connection for socket so 	 */
name|int
function_decl|(
modifier|*
name|tod_can_offload
function_decl|)
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
comment|/* 	 * Establish a connection to nam using the TOE device dev 	 */
name|int
function_decl|(
modifier|*
name|tod_connect
function_decl|)
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|rtentry
modifier|*
name|rt
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|nam
parameter_list|)
function_decl|;
comment|/* 	 * Send an mbuf down to the toe device  	 */
name|int
function_decl|(
modifier|*
name|tod_send
function_decl|)
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
comment|/* 	 * Receive an array of mbufs from the TOE device dev  	 */
name|int
function_decl|(
modifier|*
name|tod_recv
function_decl|)
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|m
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
comment|/* 	 * Device specific ioctl interface 	 */
name|int
function_decl|(
modifier|*
name|tod_ctl
function_decl|)
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|req
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/* 	 * Update L2 entry in toedev  	 */
name|void
function_decl|(
modifier|*
name|tod_arp_update
function_decl|)
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|,
name|struct
name|rtentry
modifier|*
name|neigh
parameter_list|)
function_decl|;
comment|/* 	 * Failover from one toe device to another 	 */
name|void
function_decl|(
modifier|*
name|tod_failover
function_decl|)
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|,
name|struct
name|ifnet
modifier|*
name|bond_ifp
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ndev
parameter_list|,
name|int
name|event
parameter_list|)
function_decl|;
name|void
modifier|*
name|tod_priv
decl_stmt|;
comment|/* driver private data */
name|void
modifier|*
name|tod_l2opt
decl_stmt|;
comment|/* optional layer 2 data */
name|void
modifier|*
name|tod_l3opt
decl_stmt|;
comment|/* optional layer 3 data */
name|void
modifier|*
name|tod_l4opt
decl_stmt|;
comment|/* optional layer 4 data */
name|void
modifier|*
name|tod_ulp
decl_stmt|;
comment|/* upper lever protocol */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tom_info
block|{
name|TAILQ_ENTRY
argument_list|(
argument|tom_info
argument_list|)
name|entry
expr_stmt|;
name|int
function_decl|(
modifier|*
name|ti_attach
function_decl|)
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|,
specifier|const
name|struct
name|offload_id
modifier|*
name|entry
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ti_detach
function_decl|)
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|ti_name
decl_stmt|;
specifier|const
name|struct
name|offload_id
modifier|*
name|ti_id_table
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|void
name|init_offload_dev
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|)
block|{ }
end_function

begin_function_decl
name|int
name|register_tom
parameter_list|(
name|struct
name|tom_info
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unregister_tom
parameter_list|(
name|struct
name|tom_info
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|register_toedev
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unregister_toedev
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|activate_offload
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|toe_send
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|toe_arp_update
parameter_list|(
name|struct
name|rtentry
modifier|*
name|rt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifnet
modifier|*
name|offload_get_phys_egress
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|toe_receive_mbuf
parameter_list|(
name|struct
name|toedev
modifier|*
name|dev
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|m
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|toe_neigh_update
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|toe_failover
parameter_list|(
name|struct
name|ifnet
modifier|*
name|bond_ifp
parameter_list|,
name|struct
name|ifnet
modifier|*
name|fail_ifp
parameter_list|,
name|int
name|event
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|int
name|toe_enslave
parameter_list|(
name|struct
name|ifnet
modifier|*
name|bond_ifp
parameter_list|,
name|struct
name|ifnet
modifier|*
name|slave_ifp
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_TOEDEV_H_ */
end_comment

end_unit

