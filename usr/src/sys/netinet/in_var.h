begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)in_var.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Interface address, Internet version.  One of these structures  * is allocated for each interface with an Internet address.  * The ifaddr structure contains the protocol-independent part  * of the structure and is assumed to be first.  */
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
name|struct
name|in_addr
name|ia_netbroadcast
decl_stmt|;
comment|/* broadcast addr for (logical) net */
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
name|struct
name|in_ifaddr
modifier|*
name|in_ifaddr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|in_ifaddr
modifier|*
name|in_iaonnetof
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|ifqueue
name|ipintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip packet input queue */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

