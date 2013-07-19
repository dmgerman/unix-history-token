begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2002-2004 by Darren Reed.  *   * See the IPFILTER.LICENCE file for details on licencing.    *     * $Id: getifname.c,v 1.5.2.3 2006/07/14 06:12:24 darrenr Exp $   */
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_include
include|#
directive|include
file|"kmem.h"
end_include

begin_comment
comment|/*  * Given a pointer to an interface in the kernel, return a pointer to a  * string which is the interface name.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_if
unit|char *getifname(ptr) struct ifnet *ptr; {
if|#
directive|if
name|SOLARIS
operator|||
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_if
if|#
directive|if
name|SOLARIS
end_if

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_include
include|#
directive|include
file|"compat.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"../pfil/qif.h"
end_include

begin_else
unit|char *ifname; 	qif_t qif;  	if ((void *)ptr == (void *)-1) 		return "!"; 	if (ptr == NULL) 		return "-";  	if (kmemcpy((char *)&qif, (u_long)ptr, sizeof(qif)) == -1) 		return "X"; 	ifname = strdup(qif.qf_name); 	if ((ifname != NULL)&& (*ifname == '\0')) { 		free(ifname); 		return "!"; 	} 	return ifname;
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NetBSD
argument_list|)
operator|&&
operator|(
name|NetBSD
operator|>=
literal|199905
operator|)
operator|&&
operator|(
name|NetBSD
operator|<
literal|1991011
operator|)
operator|||
expr|\
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|>=
literal|501113
operator|)
operator|)
end_if

begin_else
else|#
directive|else
end_else

begin_endif
unit|char buf[32]; 	int len;
endif|#
directive|endif
end_endif

begin_if
unit|struct ifnet netif;  	if ((void *)ptr == (void *)-1) 		return "!"; 	if (ptr == NULL) 		return "-";  	if (kmemcpy((char *)&netif, (u_long)ptr, sizeof(netif)) == -1) 		return "X";
if|#
directive|if
name|defined
argument_list|(
name|NetBSD
argument_list|)
operator|&&
operator|(
name|NetBSD
operator|>=
literal|199905
operator|)
operator|&&
operator|(
name|NetBSD
operator|<
literal|1991011
operator|)
operator|||
expr|\
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|linux
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|>=
literal|501113
operator|)
operator|)
end_if

begin_else
unit|return strdup(netif.if_xname);
else|#
directive|else
end_else

begin_endif
unit|if (kstrncpy(buf, (u_long)netif.if_name, sizeof(buf)) == -1) 		return "X"; 	if (netif.if_unit< 10) 		len = 2; 	else if (netif.if_unit< 1000) 		len = 3; 	else if (netif.if_unit< 10000) 		len = 4; 	else 		len = 5; 	buf[sizeof(buf) - len] = '\0'; 	sprintf(buf + strlen(buf), "%d", netif.if_unit % 10000); 	return strdup(buf);
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
unit|}
else|#
directive|else
end_else

begin_function
name|char
modifier|*
name|getifname
parameter_list|(
name|ptr
parameter_list|)
name|struct
name|ifnet
modifier|*
name|ptr
decl_stmt|;
block|{
return|return
literal|"X"
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

