begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * lookup.c - Lookup IP address, HW address, netmask  *  *	$Id: lookup.c,v 1.2 1996/09/22 21:52:21 wosch Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* for struct timeval in net/if.h */
end_comment

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ETC_ETHERS
end_ifdef

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_function_decl
specifier|extern
name|int
name|ether_hostton
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|USE_BFUNCS
end_ifndef

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_comment
comment|/* Yes, memcpy is OK here (no overlapped copies). */
end_comment

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy(b,a,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"bootp.h"
end_include

begin_include
include|#
directive|include
file|"lookup.h"
end_include

begin_include
include|#
directive|include
file|"report.h"
end_include

begin_comment
comment|/*  * Lookup an Ethernet address and return it.  * Return NULL if addr not found.  */
end_comment

begin_function
name|u_char
modifier|*
name|lookup_hwa
parameter_list|(
name|hostname
parameter_list|,
name|htype
parameter_list|)
name|char
modifier|*
name|hostname
decl_stmt|;
name|int
name|htype
decl_stmt|;
block|{
switch|switch
condition|(
name|htype
condition|)
block|{
comment|/* XXX - How is this done on other systems? -gwr */
ifdef|#
directive|ifdef
name|ETC_ETHERS
case|case
name|HTYPE_ETHERNET
case|:
case|case
name|HTYPE_IEEE802
case|:
block|{
specifier|static
name|struct
name|ether_addr
name|ea
decl_stmt|;
comment|/* This does a lookup in /etc/ethers */
if|if
condition|(
name|ether_hostton
argument_list|(
name|hostname
argument_list|,
operator|&
name|ea
argument_list|)
condition|)
block|{
name|report
argument_list|(
name|LOG_ERR
argument_list|,
literal|"no HW addr for host \"%s\""
argument_list|,
name|hostname
argument_list|)
expr_stmt|;
return|return
operator|(
name|u_char
operator|*
operator|)
literal|0
return|;
block|}
return|return
operator|(
name|u_char
operator|*
operator|)
operator|&
name|ea
return|;
block|}
endif|#
directive|endif
comment|/* ETC_ETHERS */
default|default:
name|report
argument_list|(
name|LOG_ERR
argument_list|,
literal|"no lookup for HW addr type %d"
argument_list|,
name|htype
argument_list|)
expr_stmt|;
block|}
comment|/* switch */
comment|/* If the system can't do it, just return an error. */
return|return
operator|(
name|u_char
operator|*
operator|)
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Lookup an IP address.  * Return non-zero on failure.  */
end_comment

begin_function
name|int
name|lookup_ipa
parameter_list|(
name|hostname
parameter_list|,
name|result
parameter_list|)
name|char
modifier|*
name|hostname
decl_stmt|;
name|u_int32
modifier|*
name|result
decl_stmt|;
block|{
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|;
name|hp
operator|=
name|gethostbyname
argument_list|(
name|hostname
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hp
condition|)
return|return
operator|-
literal|1
return|;
name|bcopy
argument_list|(
name|hp
operator|->
name|h_addr
argument_list|,
name|result
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|result
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Lookup a netmask  * Return non-zero on failure.  *  * XXX - This is OK as a default, but to really make this automatic,  * we would need to get the subnet mask from the ether interface.  * If this is wrong, specify the correct value in the bootptab.  */
end_comment

begin_function
name|int
name|lookup_netmask
parameter_list|(
name|addr
parameter_list|,
name|result
parameter_list|)
name|u_int32
name|addr
decl_stmt|;
comment|/* both in network order */
name|u_int32
modifier|*
name|result
decl_stmt|;
block|{
name|int32
name|m
decl_stmt|,
name|a
decl_stmt|;
name|a
operator|=
name|ntohl
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|m
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|IN_CLASSA
argument_list|(
name|a
argument_list|)
condition|)
name|m
operator|=
name|IN_CLASSA_NET
expr_stmt|;
if|if
condition|(
name|IN_CLASSB
argument_list|(
name|a
argument_list|)
condition|)
name|m
operator|=
name|IN_CLASSB_NET
expr_stmt|;
if|if
condition|(
name|IN_CLASSC
argument_list|(
name|a
argument_list|)
condition|)
name|m
operator|=
name|IN_CLASSC_NET
expr_stmt|;
if|if
condition|(
operator|!
name|m
condition|)
return|return
operator|-
literal|1
return|;
operator|*
name|result
operator|=
name|htonl
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Local Variables:  * tab-width: 4  * c-indent-level: 4  * c-argdecl-indent: 4  * c-continued-statement-offset: 4  * c-continued-brace-offset: -4  * c-label-offset: -4  * c-brace-offset: 0  * End:  */
end_comment

end_unit

