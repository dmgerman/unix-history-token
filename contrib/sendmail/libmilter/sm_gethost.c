begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1999-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|id
index|[]
init|=
literal|"@(#)$Id: sm_gethost.c,v 8.7.8.11 2001/07/21 00:10:23 gshapiro Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! lint */
end_comment

begin_if
if|#
directive|if
name|_FFR_MILTER
end_if

begin_include
include|#
directive|include
file|<sendmail.h>
end_include

begin_if
if|#
directive|if
name|NETINET
operator|||
name|NETINET6
end_if

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETINET || NETINET6 */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  MI_GETHOSTBY{NAME,ADDR} -- compatibility routines for gethostbyXXX ** **	Some operating systems have wierd problems with the gethostbyXXX **	routines.  For example, Solaris versions at least through 2.3 **	don't properly deliver a canonical h_name field.  This tries to **	work around these problems. ** **	Support IPv6 as well as IPv4. */
end_comment

begin_if
if|#
directive|if
name|NETINET6
operator|&&
name|NEEDSGETIPNODE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|AI_ADDRCONFIG
end_ifndef

begin_define
define|#
directive|define
name|AI_ADDRCONFIG
value|0
end_define

begin_comment
comment|/* dummy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! AI_ADDRCONFIG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AI_ALL
end_ifndef

begin_define
define|#
directive|define
name|AI_ALL
value|0
end_define

begin_comment
comment|/* dummy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! AI_ALL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AI_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|AI_DEFAULT
value|0
end_define

begin_comment
comment|/* dummy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! AI_DEFAULT */
end_comment

begin_function
specifier|static
name|struct
name|hostent
modifier|*
name|getipnodebyname
parameter_list|(
name|name
parameter_list|,
name|family
parameter_list|,
name|flags
parameter_list|,
name|err
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|family
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
modifier|*
name|err
decl_stmt|;
block|{
name|bool
name|resv6
init|=
name|TRUE
decl_stmt|;
name|struct
name|hostent
modifier|*
name|h
decl_stmt|;
if|if
condition|(
name|family
operator|==
name|AF_INET6
condition|)
block|{
comment|/* From RFC2133, section 6.1 */
name|resv6
operator|=
name|bitset
argument_list|(
name|RES_USE_INET6
argument_list|,
name|_res
operator|.
name|options
argument_list|)
expr_stmt|;
name|_res
operator|.
name|options
operator||=
name|RES_USE_INET6
expr_stmt|;
block|}
name|SM_SET_H_ERRNO
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|h
operator|=
name|gethostbyname
argument_list|(
name|name
argument_list|)
expr_stmt|;
operator|*
name|err
operator|=
name|h_errno
expr_stmt|;
if|if
condition|(
name|family
operator|==
name|AF_INET6
operator|&&
operator|!
name|resv6
condition|)
name|_res
operator|.
name|options
operator|&=
operator|~
name|RES_USE_INET6
expr_stmt|;
return|return
name|h
return|;
block|}
end_function

begin_if
if|#
directive|if
name|_FFR_FREEHOSTENT
end_if

begin_function
name|void
name|freehostent
parameter_list|(
name|h
parameter_list|)
name|struct
name|hostent
modifier|*
name|h
decl_stmt|;
block|{
comment|/* 	**  Stub routine -- if they don't have getipnodeby*(), 	**  they probably don't have the free routine either. 	*/
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_FREEHOSTENT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEEDSGETIPNODE&& NETINET6 */
end_comment

begin_function
name|struct
name|hostent
modifier|*
name|mi_gethostbyname
parameter_list|(
name|name
parameter_list|,
name|family
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|family
decl_stmt|;
block|{
name|struct
name|hostent
modifier|*
name|h
init|=
name|NULL
decl_stmt|;
if|#
directive|if
operator|(
name|SOLARIS
operator|>
literal|10000
operator|&&
name|SOLARIS
operator|<
literal|20400
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|SOLARIS
argument_list|)
operator|&&
name|SOLARIS
operator|<
literal|204
operator|)
operator|||
operator|(
name|defined
argument_list|(
name|sony_news
argument_list|)
operator|&&
name|defined
argument_list|(
name|__svr4
argument_list|)
operator|)
if|#
directive|if
name|SOLARIS
operator|==
literal|20300
operator|||
name|SOLARIS
operator|==
literal|203
specifier|static
name|struct
name|hostent
name|hp
decl_stmt|;
specifier|static
name|char
name|buf
index|[
literal|1000
index|]
decl_stmt|;
specifier|extern
name|struct
name|hostent
modifier|*
name|_switch_gethostbyname_r
parameter_list|()
function_decl|;
name|h
operator|=
name|_switch_gethostbyname_r
argument_list|(
name|name
argument_list|,
operator|&
name|hp
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
operator|&
name|h_errno
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* SOLARIS == 20300 || SOLARIS == 203 */
specifier|extern
name|struct
name|hostent
modifier|*
name|__switch_gethostbyname
parameter_list|()
function_decl|;
name|h
operator|=
name|__switch_gethostbyname
argument_list|(
name|name
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SOLARIS == 20300 || SOLARIS == 203 */
else|#
directive|else
comment|/* (SOLARIS> 10000&& SOLARIS< 20400) || (defined(SOLARIS)&& SOLARIS< 204) || (defined(sony_news)&& defined(__svr4)) */
if|#
directive|if
name|NETINET6
name|int
name|flags
init|=
name|AI_DEFAULT
operator||
name|AI_ALL
decl_stmt|;
name|int
name|err
decl_stmt|;
endif|#
directive|endif
comment|/* NETINET6 */
if|#
directive|if
name|NETINET6
if|#
directive|if
name|ADDRCONFIG_IS_BROKEN
name|flags
operator|&=
operator|~
name|AI_ADDRCONFIG
expr_stmt|;
endif|#
directive|endif
comment|/* ADDRCONFIG_IS_BROKEN */
name|h
operator|=
name|getipnodebyname
argument_list|(
name|name
argument_list|,
name|family
argument_list|,
name|flags
argument_list|,
operator|&
name|err
argument_list|)
expr_stmt|;
name|SM_SET_H_ERRNO
argument_list|(
name|err
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* NETINET6 */
name|h
operator|=
name|gethostbyname
argument_list|(
name|name
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NETINET6 */
endif|#
directive|endif
comment|/* (SOLARIS> 10000&& SOLARIS< 20400) || (defined(SOLARIS)&& SOLARIS< 204) || (defined(sony_news)&& defined(__svr4)) */
return|return
name|h
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_MILTER */
end_comment

end_unit

