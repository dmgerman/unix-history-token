begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)netdb.h	5.7 (Berkeley) 5/12/86  */
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
modifier|*
name|h_addr_list
decl_stmt|;
comment|/* list of addresses from name server */
define|#
directive|define
name|h_addr
value|h_addr_list[0]
comment|/* address, for backward compatiblity */
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
name|unsigned
name|long
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

begin_comment
comment|/*  * Error return codes from gethostbyname() and gethostbyaddr()  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|h_errno
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HOST_NOT_FOUND
value|1
end_define

begin_comment
comment|/* Authoritive Answer Host not found */
end_comment

begin_define
define|#
directive|define
name|TRY_AGAIN
value|2
end_define

begin_comment
comment|/* Non-Authoritive Host not found, or SERVERFAIL */
end_comment

begin_define
define|#
directive|define
name|NO_RECOVERY
value|3
end_define

begin_comment
comment|/* Non recoverable errors, FORMERR, REFUSED, NOTIMP */
end_comment

begin_define
define|#
directive|define
name|NO_ADDRESS
value|4
end_define

begin_comment
comment|/* Valid host name, no address, look for MX record */
end_comment

end_unit

