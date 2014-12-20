begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * numtohost - convert network number to host name.  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/* ntohl */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"lib_strbuf.h"
end_include

begin_define
define|#
directive|define
name|LOOPBACKNET
value|0x7f000000
end_define

begin_define
define|#
directive|define
name|LOOPBACKHOST
value|0x7f000001
end_define

begin_define
define|#
directive|define
name|LOOPBACKNETMASK
value|0xff000000
end_define

begin_function
name|char
modifier|*
name|numtohost
parameter_list|(
name|u_int32
name|netnum
parameter_list|)
block|{
name|char
modifier|*
name|bp
decl_stmt|;
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|;
comment|/* 	 * This is really gross, but saves lots of hanging looking for 	 * hostnames for the radio clocks.  Don't bother looking up 	 * addresses on the loopback network except for the loopback 	 * host itself. 	 */
if|if
condition|(
operator|(
operator|(
operator|(
name|ntohl
argument_list|(
name|netnum
argument_list|)
operator|&
name|LOOPBACKNETMASK
operator|)
operator|==
name|LOOPBACKNET
operator|)
operator|&&
operator|(
name|ntohl
argument_list|(
name|netnum
argument_list|)
operator|!=
name|LOOPBACKHOST
operator|)
operator|)
operator|||
operator|(
operator|(
name|hp
operator|=
name|gethostbyaddr
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|netnum
argument_list|,
sizeof|sizeof
name|netnum
argument_list|,
name|AF_INET
argument_list|)
operator|)
operator|==
literal|0
operator|)
condition|)
return|return
name|numtoa
argument_list|(
name|netnum
argument_list|)
return|;
name|LIB_GETBUF
argument_list|(
name|bp
argument_list|)
expr_stmt|;
name|strlcpy
argument_list|(
name|bp
argument_list|,
name|hp
operator|->
name|h_name
argument_list|,
name|LIB_BUFLENGTH
argument_list|)
expr_stmt|;
return|return
name|bp
return|;
block|}
end_function

end_unit

