begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	in_var.h	6.1	85/03/18	*/
end_comment

begin_comment
comment|/*  * Interface address, internet version.  One of these structures  * is allocated for each interface with an internet address.  * The ifaddr structure contains the protocol-independent part  * of the structure and is assumed to be first.  */
end_comment

begin_struct
struct|struct
name|in_ifaddr
block|{
name|struct
name|ifaddr
name|ia_ifa
decl_stmt|;
comment|/* protocol-independent info */
define|#
directive|define
name|ia_addr
value|ia_ifa.ifa_addr
define|#
directive|define
name|ia_broadaddr
value|ia_ifa.ifa_broadaddr
define|#
directive|define
name|ia_dstaddr
value|ia_ifa.ifa_dstaddr
define|#
directive|define
name|ia_ifp
value|ia_ifa.ifa_ifp
name|u_long
name|ia_net
decl_stmt|;
comment|/* network number of interface */
name|u_long
name|ia_netmask
decl_stmt|;
comment|/* mask of net part */
name|u_long
name|ia_subnet
decl_stmt|;
comment|/* subnet number, including net */
name|u_long
name|ia_subnetmask
decl_stmt|;
comment|/* mask of net + subnet */
name|int
name|ia_flags
decl_stmt|;
name|struct
name|in_ifaddr
modifier|*
name|ia_next
decl_stmt|;
comment|/* next in list of internet addresses */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Given a pointer to an in_ifaddr (ifaddr),  * return a pointer to the addr as a sockadd_in.  */
end_comment

begin_define
define|#
directive|define
name|IA_SIN
parameter_list|(
name|ia
parameter_list|)
value|((struct sockaddr_in *)(&((struct in_ifaddr *)ia)->ia_addr))
end_define

begin_comment
comment|/*  * ia_flags  */
end_comment

begin_define
define|#
directive|define
name|IFA_ROUTE
value|0x01
end_define

begin_comment
comment|/* routing entry installed */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|in_ifaddr
modifier|*
name|in_ifaddr
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|in_ifaddr
modifier|*
name|in_iaonnetof
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

