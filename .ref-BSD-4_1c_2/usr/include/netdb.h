begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	netdb.h	4.1	82/10/05	*/
end_comment

begin_comment
comment|/*  * Structures returned by network  * data base library.  All addresses  * are supplied in host order, and  * returned in network order (suitable  * for use in system calls).  */
end_comment

begin_struct
struct|struct
name|hostent
block|{
name|char
modifier|*
name|h_name
decl_stmt|;
comment|/* official name of host */
name|char
modifier|*
modifier|*
name|h_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|h_addrtype
decl_stmt|;
comment|/* host address type */
name|int
name|h_length
decl_stmt|;
comment|/* length of address */
name|char
modifier|*
name|h_addr
decl_stmt|;
comment|/* address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Assumption here is that a network number  * fits in 32 bits -- probably a poor one.  */
end_comment

begin_struct
struct|struct
name|netent
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
comment|/* official name of net */
name|char
modifier|*
modifier|*
name|n_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|n_addrtype
decl_stmt|;
comment|/* net address type */
name|int
name|n_net
decl_stmt|;
comment|/* network # */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|servent
block|{
name|char
modifier|*
name|s_name
decl_stmt|;
comment|/* official service name */
name|char
modifier|*
modifier|*
name|s_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|s_port
decl_stmt|;
comment|/* port # */
name|char
modifier|*
name|s_proto
decl_stmt|;
comment|/* protocol to use */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|protoent
block|{
name|char
modifier|*
name|p_name
decl_stmt|;
comment|/* official protocol name */
name|char
modifier|*
modifier|*
name|p_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|p_proto
decl_stmt|;
comment|/* protocol # */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|hostent
modifier|*
name|gethostbyname
argument_list|()
decl_stmt|,
modifier|*
name|gethostbyaddr
argument_list|()
decl_stmt|,
modifier|*
name|gethostent
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|netent
modifier|*
name|getnetbyname
argument_list|()
decl_stmt|,
modifier|*
name|getnetbyaddr
argument_list|()
decl_stmt|,
modifier|*
name|getnetent
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|servent
modifier|*
name|getservbyname
argument_list|()
decl_stmt|,
modifier|*
name|getservbyport
argument_list|()
decl_stmt|,
modifier|*
name|getservent
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|protoent
modifier|*
name|getprotobyname
argument_list|()
decl_stmt|,
modifier|*
name|getprotobynumber
argument_list|()
decl_stmt|,
modifier|*
name|getprotoent
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

