begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/krb/RCS/create_death_packet.c,v $  * $Author: kfall $  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_cr_death_packet_c
init|=
literal|"$Header: /usr/src/kerberosIV/krb/RCS/create_death_packet.c,v 4.10 90/06/25 20:55:28 kfall Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<prot.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_comment
comment|/*  * This routine creates a packet to type AUTH_MSG_DIE which is sent to  * the Kerberos server to make it shut down.  It is used only in the  * development environment.  *  * It takes a string "a_name" which is sent in the packet.  A pointer  * to the packet is returned.  *  * The format of the killer packet is:  *  * type			variable		data  *			or constant  * ----			-----------		----  *  * unsigned char	KRB_PROT_VERSION	protocol version number  *   * unsigned char	AUTH_MSG_DIE		message type  *   * [least significant	HOST_BYTE_ORDER		byte order of sender  *  bit of above field]  *   * string		a_name			presumably, name of  * 						principal sending killer  * 						packet  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function
name|KTEXT
name|krb_create_death_packet
parameter_list|(
name|a_name
parameter_list|)
name|char
modifier|*
name|a_name
decl_stmt|;
block|{
specifier|static
name|KTEXT_ST
name|pkt_st
decl_stmt|;
name|KTEXT
name|pkt
init|=
operator|&
name|pkt_st
decl_stmt|;
name|unsigned
name|char
modifier|*
name|v
init|=
name|pkt
operator|->
name|dat
decl_stmt|;
name|unsigned
name|char
modifier|*
name|t
init|=
operator|(
name|pkt
operator|->
name|dat
operator|+
literal|1
operator|)
decl_stmt|;
operator|*
name|v
operator|=
operator|(
name|unsigned
name|char
operator|)
name|KRB_PROT_VERSION
expr_stmt|;
operator|*
name|t
operator|=
operator|(
name|unsigned
name|char
operator|)
name|AUTH_MSG_DIE
expr_stmt|;
operator|*
name|t
operator||=
name|HOST_BYTE_ORDER
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
name|pkt
operator|->
name|dat
operator|+
literal|2
operator|)
argument_list|,
name|a_name
argument_list|)
expr_stmt|;
name|pkt
operator|->
name|length
operator|=
literal|3
operator|+
name|strlen
argument_list|(
name|a_name
argument_list|)
expr_stmt|;
return|return
name|pkt
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

end_unit

