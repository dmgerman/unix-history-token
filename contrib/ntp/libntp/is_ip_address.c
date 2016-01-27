begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * is_ip_address  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FNMATCH_H
end_ifdef

begin_include
include|#
directive|include
file|<fnmatch.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FNM_CASEFOLD
argument_list|)
operator|&&
name|defined
argument_list|(
name|FNM_IGNORECASE
argument_list|)
end_if

begin_define
define|#
directive|define
name|FNM_CASEFOLD
value|FNM_IGNORECASE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_IOCTL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKIO_H
end_ifdef

begin_comment
comment|/* UXPV: SIOC* #defines (Frank Vance<fvance@waii.com>) */
end_comment

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_UIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntp_assert.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"safecast.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|"ntp_machine.h"
end_include

begin_include
include|#
directive|include
file|"ntpd.h"
end_include

begin_include
include|#
directive|include
file|"ntp_io.h"
end_include

begin_include
include|#
directive|include
file|"iosignal.h"
end_include

begin_include
include|#
directive|include
file|"ntp_lists.h"
end_include

begin_include
include|#
directive|include
file|"ntp_refclock.h"
end_include

begin_include
include|#
directive|include
file|"ntp_worker.h"
end_include

begin_include
include|#
directive|include
file|"ntp_request.h"
end_include

begin_include
include|#
directive|include
file|"timevalops.h"
end_include

begin_include
include|#
directive|include
file|"timespecops.h"
end_include

begin_include
include|#
directive|include
file|"ntpd-opts.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Don't include ISC's version of IPv6 variables and structures */
end_comment

begin_define
define|#
directive|define
name|ISC_IPV6_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/mem.h>
end_include

begin_include
include|#
directive|include
file|<isc/interfaceiter.h>
end_include

begin_include
include|#
directive|include
file|<isc/netaddr.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_include
include|#
directive|include
file|<isc/sockaddr.h>
end_include

begin_comment
comment|/*  * Code to tell if we have an IP address  * If we have then return the sockaddr structure  * and set the return value  * see the bind9/getaddresses.c for details  */
end_comment

begin_function
name|int
name|is_ip_address
parameter_list|(
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|u_short
name|af
parameter_list|,
name|sockaddr_u
modifier|*
name|addr
parameter_list|)
block|{
name|struct
name|in_addr
name|in4
decl_stmt|;
name|struct
name|addrinfo
name|hints
decl_stmt|;
name|struct
name|addrinfo
modifier|*
name|result
decl_stmt|;
name|struct
name|sockaddr_in6
modifier|*
name|resaddr6
decl_stmt|;
name|char
name|tmpbuf
index|[
literal|128
index|]
decl_stmt|;
name|char
modifier|*
name|pch
decl_stmt|;
name|REQUIRE
argument_list|(
name|host
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|REQUIRE
argument_list|(
name|addr
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|ZERO_SOCK
argument_list|(
name|addr
argument_list|)
expr_stmt|;
comment|/* 	 * Try IPv4, then IPv6.  In order to handle the extended format 	 * for IPv6 scoped addresses (address%scope_ID), we'll use a local 	 * working buffer of 128 bytes.  The length is an ad-hoc value, but 	 * should be enough for this purpose; the buffer can contain a string 	 * of at least 80 bytes for scope_ID in addition to any IPv6 numeric 	 * addresses (up to 46 bytes), the delimiter character and the 	 * terminating NULL character. 	 */
if|if
condition|(
name|AF_UNSPEC
operator|==
name|af
operator|||
name|AF_INET
operator|==
name|af
condition|)
if|if
condition|(
name|inet_pton
argument_list|(
name|AF_INET
argument_list|,
name|host
argument_list|,
operator|&
name|in4
argument_list|)
operator|==
literal|1
condition|)
block|{
name|AF
argument_list|(
name|addr
argument_list|)
operator|=
name|AF_INET
expr_stmt|;
name|SET_ADDR4N
argument_list|(
name|addr
argument_list|,
name|in4
operator|.
name|s_addr
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
if|if
condition|(
name|AF_UNSPEC
operator|==
name|af
operator|||
name|AF_INET6
operator|==
name|af
condition|)
if|if
condition|(
sizeof|sizeof
argument_list|(
name|tmpbuf
argument_list|)
operator|>
name|strlen
argument_list|(
name|host
argument_list|)
condition|)
block|{
if|if
condition|(
literal|'['
operator|==
name|host
index|[
literal|0
index|]
condition|)
block|{
name|strlcpy
argument_list|(
name|tmpbuf
argument_list|,
operator|&
name|host
index|[
literal|1
index|]
argument_list|,
sizeof|sizeof
argument_list|(
name|tmpbuf
argument_list|)
argument_list|)
expr_stmt|;
name|pch
operator|=
name|strchr
argument_list|(
name|tmpbuf
argument_list|,
literal|']'
argument_list|)
expr_stmt|;
if|if
condition|(
name|pch
operator|!=
name|NULL
condition|)
operator|*
name|pch
operator|=
literal|'\0'
expr_stmt|;
block|}
else|else
block|{
name|strlcpy
argument_list|(
name|tmpbuf
argument_list|,
name|host
argument_list|,
sizeof|sizeof
argument_list|(
name|tmpbuf
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|ZERO
argument_list|(
name|hints
argument_list|)
expr_stmt|;
name|hints
operator|.
name|ai_family
operator|=
name|AF_INET6
expr_stmt|;
name|hints
operator|.
name|ai_flags
operator||=
name|AI_NUMERICHOST
expr_stmt|;
if|if
condition|(
name|getaddrinfo
argument_list|(
name|tmpbuf
argument_list|,
name|NULL
argument_list|,
operator|&
name|hints
argument_list|,
operator|&
name|result
argument_list|)
operator|==
literal|0
condition|)
block|{
name|AF
argument_list|(
name|addr
argument_list|)
operator|=
name|AF_INET6
expr_stmt|;
name|resaddr6
operator|=
name|UA_PTR
argument_list|(
expr|struct
name|sockaddr_in6
argument_list|,
name|result
operator|->
name|ai_addr
argument_list|)
expr_stmt|;
name|SET_ADDR6N
argument_list|(
name|addr
argument_list|,
name|resaddr6
operator|->
name|sin6_addr
argument_list|)
expr_stmt|;
name|SET_SCOPE
argument_list|(
name|addr
argument_list|,
name|resaddr6
operator|->
name|sin6_scope_id
argument_list|)
expr_stmt|;
name|freeaddrinfo
argument_list|(
name|result
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
block|}
comment|/* 	 * If we got here it was not an IP address 	 */
return|return
name|FALSE
return|;
block|}
end_function

end_unit

