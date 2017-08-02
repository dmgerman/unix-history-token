begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed under the OpenIB.org BSD license (FreeBSD Variant) - See COPYING.md  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NL1_COMPAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NL1_COMPAT_H_
end_define

begin_include
include|#
directive|include
file|<netlink/route/rtnl.h>
end_include

begin_include
include|#
directive|include
file|<netlink/route/link.h>
end_include

begin_include
include|#
directive|include
file|<netlink/route/route.h>
end_include

begin_include
include|#
directive|include
file|<netlink/route/neighbour.h>
end_include

begin_struct_decl
struct_decl|struct
name|nl_handle
struct_decl|;
end_struct_decl

begin_comment
comment|/* Workaround - declaration missing */
end_comment

begin_function_decl
specifier|extern
name|int
name|rtnl_link_vlan_get_id
parameter_list|(
name|struct
name|rtnl_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|nl_geterror
parameter_list|(
name|x
parameter_list|)
value|nl_geterror()
end_define

begin_define
define|#
directive|define
name|nl_sock
value|nl_handle
end_define

begin_function
specifier|static
specifier|inline
name|void
name|nl_socket_disable_seq_check
parameter_list|(
name|struct
name|nl_sock
modifier|*
name|sock
parameter_list|)
block|{
name|nl_disable_sequence_check
argument_list|(
name|sock
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|rtnl_nexthop
block|{}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|struct
name|rtnl_nexthop
modifier|*
name|rtnl_route_nexthop_n
parameter_list|(
name|struct
name|rtnl_route
modifier|*
name|r
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
operator|(
expr|struct
name|rtnl_nexthop
operator|*
operator|)
name|r
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|nl_addr
modifier|*
name|rtnl_route_nh_get_gateway
parameter_list|(
name|struct
name|rtnl_nexthop
modifier|*
name|nh
parameter_list|)
block|{
return|return
name|rtnl_route_get_gateway
argument_list|(
operator|(
expr|struct
name|rtnl_route
operator|*
operator|)
name|nh
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|rtnl_route_nh_get_ifindex
parameter_list|(
name|struct
name|rtnl_nexthop
modifier|*
name|nh
parameter_list|)
block|{
return|return
name|rtnl_route_get_oif
argument_list|(
operator|(
expr|struct
name|rtnl_route
operator|*
operator|)
name|nh
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|nl_addr_info
parameter_list|(
name|addr
parameter_list|,
name|result
parameter_list|)
value|(		\ 	*(result) = nl_addr_info(addr),			\ 	(*(result) == NULL) ? nl_get_errno() : 0		\ )
end_define

begin_function
specifier|static
specifier|inline
name|void
name|nl_socket_free
parameter_list|(
name|struct
name|nl_sock
modifier|*
name|sock
parameter_list|)
block|{
name|nl_close
argument_list|(
name|sock
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|nl_sock
modifier|*
name|nl_socket_alloc
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|nl_handle_alloc
argument_list|()
return|;
block|}
end_function

begin_define
define|#
directive|define
name|rtnl_link_alloc_cache
parameter_list|(
name|sock
parameter_list|,
name|family
parameter_list|,
name|result
parameter_list|)
value|(	\ 	*result = rtnl_link_alloc_cache(sock),		\ 	(*result == NULL) ? nl_get_errno() : 0		\ )
end_define

begin_define
define|#
directive|define
name|rtnl_route_alloc_cache
parameter_list|(
name|sock
parameter_list|,
name|family
parameter_list|,
name|flags
parameter_list|,
name|result
parameter_list|)
value|(	\ 	*result = rtnl_route_alloc_cache(sock),			\ 	(*result == NULL) ? nl_get_errno() : 0			\ )
end_define

begin_define
define|#
directive|define
name|rtnl_neigh_alloc_cache
parameter_list|(
name|sock
parameter_list|,
name|result
parameter_list|)
value|(			\ 	*result = rtnl_neigh_alloc_cache(sock),			\ 	(*result == NULL) ? nl_get_errno() : 0			\ )
end_define

begin_function
specifier|static
specifier|inline
name|int
name|rtnl_link_is_vlan
parameter_list|(
name|struct
name|rtnl_link
modifier|*
name|link
parameter_list|)
block|{
return|return
name|rtnl_link_vlan_get_id
argument_list|(
name|link
argument_list|)
operator|<=
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

