begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpcb_clnt.c,v 1.6 2000/07/16 06:41:43 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * The contents of this file are subject to the Sun Standards  * License Version 1.0 the (the "License";) You may not use  * this file except in compliance with the License.  You may  * obtain a copy of the License at lib/libc/rpc/LICENSE  *  * Software distributed under the License is distributed on  * an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either  * express or implied.  See the License for the specific  * language governing rights and limitations under the License.  *  * The Original Code is Copyright 1998 by Sun Microsystems, Inc  *  * The Initial Developer of the Original Code is:  Sun  * Microsystems, Inc.  *  * All Rights Reserved.  *  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1986-1991 by Sun Microsystems Inc.   */
end_comment

begin_comment
comment|/* #ident	"@(#)rpcb_clnt.c	1.27	94/04/24 SMI" */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)rpcb_clnt.c 1.30 89/06/21 Copyr 1988 Sun Micro"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * rpcb_clnt.c  * interface to rpcbind rpc service.  *  * Copyright (C) 1988, Sun Microsystems, Inc.  */
end_comment

begin_include
include|#
directive|include
file|"opt_inet6.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpcb_clnt.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpcb_prot.h>
end_include

begin_include
include|#
directive|include
file|"rpc_com.h"
end_include

begin_decl_stmt
specifier|static
name|struct
name|timeval
name|tottimeout
init|=
block|{
literal|60
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|timeval
name|rmttimeout
init|=
block|{
literal|3
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|nullstring
index|[]
init|=
literal|"\000"
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|CLIENT
modifier|*
name|local_rpcb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_define
unit|static struct timeval rpcbrmttime = { 15, 0 };
define|#
directive|define
name|CACHESIZE
value|6
end_define

begin_define
unit|struct address_cache { 	char *ac_host; 	char *ac_netid; 	char *ac_uaddr; 	struct netbuf *ac_taddr; 	struct address_cache *ac_next; };  static struct address_cache *front; static int cachesize;
define|#
directive|define
name|CLCR_GET_RPCB_TIMEOUT
value|1
end_define

begin_define
define|#
directive|define
name|CLCR_SET_RPCB_TIMEOUT
value|2
end_define

begin_comment
unit|extern int __rpc_lowvers;  static struct address_cache *check_cache(const char *, const char *); static void delete_cache(struct netbuf *); static void add_cache(const char *, const char *, struct netbuf *, char *); static CLIENT *getclnthandle(const char *, const struct netconfig *, char **); static CLIENT *local_rpcb(void); static struct netbuf *got_entry(rpcb_entry_list_ptr, const struct netconfig *);
comment|/*  * This routine adjusts the timeout used for calls to the remote rpcbind.  * Also, this routine can be used to set the use of portmapper version 2  * only when doing rpc_broadcasts  * These are private routines that may not be provided in future releases.  */
end_comment

begin_comment
unit|bool_t __rpc_control(request, info) 	int	request; 	void	*info; { 	switch (request) { 	case CLCR_GET_RPCB_TIMEOUT: 		*(struct timeval *)info = tottimeout; 		break; 	case CLCR_SET_RPCB_TIMEOUT: 		tottimeout = *(struct timeval *)info; 		break; 	case CLCR_SET_LOWVERS: 		__rpc_lowvers = *(int *)info; 		break; 	case CLCR_GET_LOWVERS: 		*(int *)info = __rpc_lowvers; 		break; 	default: 		return (FALSE); 	} 	return (TRUE); }
comment|/*  *	It might seem that a reader/writer lock would be more reasonable here.  *	However because getclnthandle(), the only user of the cache functions,  *	may do a delete_cache() operation if a check_cache() fails to return an  *	address useful to clnt_tli_create(), we may as well use a mutex.  */
end_comment

begin_comment
comment|/*  * As it turns out, if the cache lock is *not* a reader/writer lock, we will  * block all clnt_create's if we are trying to connect to a host that's down,  * since the lock will be held all during that time.  */
end_comment

begin_comment
comment|/*  * The routines check_cache(), add_cache(), delete_cache() manage the  * cache of rpcbind addresses for (host, netid).  */
end_comment

begin_comment
unit|static struct address_cache * check_cache(host, netid) 	const char *host, *netid; { 	struct address_cache *cptr;
comment|/* READ LOCK HELD ON ENTRY: rpcbaddr_cache_lock */
end_comment

begin_ifdef
unit|for (cptr = front; cptr != NULL; cptr = cptr->ac_next) { 		if (!strcmp(cptr->ac_host, host)&& 		    !strcmp(cptr->ac_netid, netid)) {
ifdef|#
directive|ifdef
name|ND_DEBUG
end_ifdef

begin_endif
unit|fprintf(stderr, "Found cache entry for %s: %s\n", 				host, netid);
endif|#
directive|endif
end_endif

begin_comment
unit|return (cptr); 		} 	} 	return ((struct address_cache *) NULL); }  static void delete_cache(addr) 	struct netbuf *addr; { 	struct address_cache *cptr, *prevptr = NULL;
comment|/* WRITE LOCK HELD ON ENTRY: rpcbaddr_cache_lock */
end_comment

begin_ifdef
unit|for (cptr = front; cptr != NULL; cptr = cptr->ac_next) { 		if (!memcmp(cptr->ac_taddr->buf, addr->buf, addr->len)) { 			free(cptr->ac_host); 			free(cptr->ac_netid); 			free(cptr->ac_taddr->buf); 			free(cptr->ac_taddr); 			if (cptr->ac_uaddr) 				free(cptr->ac_uaddr); 			if (prevptr) 				prevptr->ac_next = cptr->ac_next; 			else 				front = cptr->ac_next; 			free(cptr); 			cachesize--; 			break; 		} 		prevptr = cptr; 	} }  static void add_cache(host, netid, taddr, uaddr) 	const char *host, *netid; 	char *uaddr; 	struct netbuf *taddr; { 	struct address_cache  *ad_cache, *cptr, *prevptr;  	ad_cache = (struct address_cache *) 			malloc(sizeof (struct address_cache)); 	if (!ad_cache) { 		return; 	} 	ad_cache->ac_host = strdup(host); 	ad_cache->ac_netid = strdup(netid); 	ad_cache->ac_uaddr = uaddr ? strdup(uaddr) : NULL; 	ad_cache->ac_taddr = (struct netbuf *)malloc(sizeof (struct netbuf)); 	if (!ad_cache->ac_host || !ad_cache->ac_netid || !ad_cache->ac_taddr || 		(uaddr&& !ad_cache->ac_uaddr)) { 		goto out; 	} 	ad_cache->ac_taddr->len = ad_cache->ac_taddr->maxlen = taddr->len; 	ad_cache->ac_taddr->buf = (char *) malloc(taddr->len); 	if (ad_cache->ac_taddr->buf == NULL) { out: 		if (ad_cache->ac_host) 			free(ad_cache->ac_host); 		if (ad_cache->ac_netid) 			free(ad_cache->ac_netid); 		if (ad_cache->ac_uaddr) 			free(ad_cache->ac_uaddr); 		if (ad_cache->ac_taddr) 			free(ad_cache->ac_taddr); 		free(ad_cache); 		return; 	} 	memcpy(ad_cache->ac_taddr->buf, taddr->buf, taddr->len);
ifdef|#
directive|ifdef
name|ND_DEBUG
end_ifdef

begin_endif
unit|fprintf(stderr, "Added to cache: %s : %s\n", host, netid);
endif|#
directive|endif
end_endif

begin_comment
comment|/* VARIABLES PROTECTED BY rpcbaddr_cache_lock:  cptr */
end_comment

begin_comment
unit|rwlock_wrlock(&rpcbaddr_cache_lock); 	if (cachesize< CACHESIZE) { 		ad_cache->ac_next = front; 		front = ad_cache; 		cachesize++; 	} else {
comment|/* Free the last entry */
end_comment

begin_ifdef
unit|cptr = front; 		prevptr = NULL; 		while (cptr->ac_next) { 			prevptr = cptr; 			cptr = cptr->ac_next; 		}
ifdef|#
directive|ifdef
name|ND_DEBUG
end_ifdef

begin_endif
unit|fprintf(stderr, "Deleted from cache: %s : %s\n", 			cptr->ac_host, cptr->ac_netid);
endif|#
directive|endif
end_endif

begin_comment
unit|free(cptr->ac_host); 		free(cptr->ac_netid); 		free(cptr->ac_taddr->buf); 		free(cptr->ac_taddr); 		if (cptr->ac_uaddr) 			free(cptr->ac_uaddr);  		if (prevptr) { 			prevptr->ac_next = NULL; 			ad_cache->ac_next = front; 			front = ad_cache; 		} else { 			front = ad_cache; 			ad_cache->ac_next = NULL; 		} 		free(cptr); 	} 	rwlock_unlock(&rpcbaddr_cache_lock); }
comment|/*  * This routine will return a client handle that is connected to the  * rpcbind. If targaddr is non-NULL, the "universal address" of the  * host will be stored in *targaddr; the caller is responsible for  * freeing this string.  * On error, returns NULL and free's everything.  */
end_comment

begin_comment
unit|static CLIENT * getclnthandle(host, nconf, targaddr) 	const char *host; 	const struct netconfig *nconf; 	char **targaddr; { 	CLIENT *client; 	struct netbuf *addr, taddr; 	struct netbuf addr_to_delete; 	struct __rpc_sockinfo si; 	struct addrinfo hints, *res, *tres; 	struct address_cache *ad_cache; 	char *tmpaddr;
comment|/* VARIABLES PROTECTED BY rpcbaddr_cache_lock:  ad_cache */
end_comment

begin_comment
comment|/* Get the address of the rpcbind.  Check cache first */
end_comment

begin_comment
unit|client = NULL; 	addr_to_delete.len = 0; 	rwlock_rdlock(&rpcbaddr_cache_lock); 	ad_cache = NULL; 	if (host != NULL) 		ad_cache = check_cache(host, nconf->nc_netid); 	if (ad_cache != NULL) { 		addr = ad_cache->ac_taddr; 		client = clnt_tli_create(RPC_ANYFD, nconf, addr, 		    (rpcprog_t)RPCBPROG, (rpcvers_t)RPCBVERS4, 0, 0); 		if (client != NULL) { 			if (targaddr) 				*targaddr = strdup(ad_cache->ac_uaddr); 			rwlock_unlock(&rpcbaddr_cache_lock); 			return (client); 		} 		addr_to_delete.len = addr->len; 		addr_to_delete.buf = (char *)malloc(addr->len); 		if (addr_to_delete.buf == NULL) { 			addr_to_delete.len = 0; 		} else { 			memcpy(addr_to_delete.buf, addr->buf, addr->len); 		} 	} 	rwlock_unlock(&rpcbaddr_cache_lock); 	if (addr_to_delete.len != 0) {
comment|/* 		 * Assume this may be due to cache data being 		 *  outdated 		 */
end_comment

begin_ifdef
unit|rwlock_wrlock(&rpcbaddr_cache_lock); 		delete_cache(&addr_to_delete); 		rwlock_unlock(&rpcbaddr_cache_lock); 		free(addr_to_delete.buf); 	} 	if (!__rpc_nconf2sockinfo(nconf,&si)) { 		rpc_createerr.cf_stat = RPC_UNKNOWNPROTO; 		return NULL; 	}  	memset(&hints, 0, sizeof hints); 	hints.ai_family = si.si_af; 	hints.ai_socktype = si.si_socktype; 	hints.ai_protocol = si.si_proto;
ifdef|#
directive|ifdef
name|CLNT_DEBUG
end_ifdef

begin_endif
unit|printf("trying netid %s family %d proto %d socktype %d\n", 	    nconf->nc_netid, si.si_af, si.si_proto, si.si_socktype);
endif|#
directive|endif
end_endif

begin_ifdef
unit|if (nconf->nc_protofmly != NULL&& strcmp(nconf->nc_protofmly, NC_LOOPBACK) == 0) { 		client = local_rpcb(); 		if (! client) {
ifdef|#
directive|ifdef
name|ND_DEBUG
end_ifdef

begin_endif
unit|clnt_pcreateerror("rpcbind clnt interface");
endif|#
directive|endif
end_endif

begin_ifdef
unit|return (NULL); 		} else { 			struct sockaddr_un sun; 			if (targaddr) { 			    *targaddr = malloc(sizeof(sun.sun_path)); 			    if (*targaddr == NULL) { 				CLNT_DESTROY(client); 				return (NULL); 			    } 			    strncpy(*targaddr, _PATH_RPCBINDSOCK, 				sizeof(sun.sun_path)); 			} 			return (client); 		} 	} else { 		if (getaddrinfo(host, "sunrpc",&hints,&res) != 0) { 			rpc_createerr.cf_stat = RPC_UNKNOWNHOST; 			return NULL; 		} 	}  	for (tres = res; tres != NULL; tres = tres->ai_next) { 		taddr.buf = tres->ai_addr; 		taddr.len = taddr.maxlen = tres->ai_addrlen;
ifdef|#
directive|ifdef
name|ND_DEBUG
end_ifdef

begin_endif
unit|{ 			char *ua;  			ua = taddr2uaddr(nconf,&taddr); 			fprintf(stderr, "Got it [%s]\n", ua); 			free(ua); 		}
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ND_DEBUG
end_ifdef

begin_endif
unit|{ 			int i;  			fprintf(stderr, "\tnetbuf len = %d, maxlen = %d\n", 				taddr.len, taddr.maxlen); 			fprintf(stderr, "\tAddress is "); 			for (i = 0; i< taddr.len; i++) 				fprintf(stderr, "%u.", ((char *)(taddr.buf))[i]); 			fprintf(stderr, "\n"); 		}
endif|#
directive|endif
end_endif

begin_ifdef
unit|client = clnt_tli_create(RPC_ANYFD, nconf,&taddr, 		    (rpcprog_t)RPCBPROG, (rpcvers_t)RPCBVERS4, 0, 0);
ifdef|#
directive|ifdef
name|ND_DEBUG
end_ifdef

begin_endif
unit|if (! client) { 			clnt_pcreateerror("rpcbind clnt interface"); 		}
endif|#
directive|endif
end_endif

begin_endif
unit|if (client) { 			tmpaddr = targaddr ? taddr2uaddr(nconf,&taddr) : NULL; 			add_cache(host, nconf->nc_netid,&taddr, tmpaddr); 			if (targaddr) 				*targaddr = tmpaddr; 			break; 		} 	} 	if (res) 		freeaddrinfo(res); 	return (client); }
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|IN4_LOCALHOST_STRING
value|"127.0.0.1"
end_define

begin_define
define|#
directive|define
name|IN6_LOCALHOST_STRING
value|"::1"
end_define

begin_comment
comment|/*  * This routine will return a client handle that is connected to the local  * rpcbind. Returns NULL on error and free's everything.  */
end_comment

begin_function
specifier|static
name|CLIENT
modifier|*
name|local_rpcb
parameter_list|()
block|{
name|CLIENT
modifier|*
name|client
decl_stmt|;
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
name|size_t
name|tsize
decl_stmt|;
name|struct
name|sockaddr_un
name|sun
decl_stmt|;
name|int
name|error
decl_stmt|;
comment|/* 	 * Try connecting to the local rpcbind through a local socket 	 * first. If this doesn't work, try all transports defined in 	 * the netconfig file. 	 */
name|memset
argument_list|(
operator|&
name|sun
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
name|sun
argument_list|)
expr_stmt|;
name|so
operator|=
name|NULL
expr_stmt|;
name|error
operator|=
name|socreate
argument_list|(
name|AF_LOCAL
argument_list|,
operator|&
name|so
argument_list|,
name|SOCK_STREAM
argument_list|,
literal|0
argument_list|,
name|curthread
operator|->
name|td_ucred
argument_list|,
name|curthread
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|try_nconf
goto|;
name|sun
operator|.
name|sun_family
operator|=
name|AF_LOCAL
expr_stmt|;
name|strcpy
argument_list|(
name|sun
operator|.
name|sun_path
argument_list|,
name|_PATH_RPCBINDSOCK
argument_list|)
expr_stmt|;
name|sun
operator|.
name|sun_len
operator|=
name|SUN_LEN
argument_list|(
operator|&
name|sun
argument_list|)
expr_stmt|;
name|tsize
operator|=
name|__rpc_get_t_size
argument_list|(
name|AF_LOCAL
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|client
operator|=
name|clnt_vc_create
argument_list|(
name|so
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|sun
argument_list|,
operator|(
name|rpcprog_t
operator|)
name|RPCBPROG
argument_list|,
operator|(
name|rpcvers_t
operator|)
name|RPCBVERS
argument_list|,
name|tsize
argument_list|,
name|tsize
argument_list|)
expr_stmt|;
if|if
condition|(
name|client
operator|!=
name|NULL
condition|)
block|{
comment|/* Mark the socket to be closed in destructor */
operator|(
name|void
operator|)
name|CLNT_CONTROL
argument_list|(
name|client
argument_list|,
name|CLSET_FD_CLOSE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
name|client
return|;
block|}
comment|/* Nobody needs this socket anymore; free the descriptor. */
name|soclose
argument_list|(
name|so
argument_list|)
expr_stmt|;
name|try_nconf
label|:
if|#
directive|if
literal|0
block|static struct netconfig *loopnconf; 	static char *hostname;
comment|/* VARIABLES PROTECTED BY loopnconf_lock: loopnconf */
block|mutex_lock(&loopnconf_lock); 	if (loopnconf == NULL) { 		struct netconfig *nconf, *tmpnconf = NULL; 		void *nc_handle; 		int fd;  		nc_handle = setnetconfig(); 		if (nc_handle == NULL) {
comment|/* fails to open netconfig file */
block|syslog (LOG_ERR, "rpc: failed to open " NETCONFIG); 			rpc_createerr.cf_stat = RPC_UNKNOWNPROTO; 			mutex_unlock(&loopnconf_lock); 			return (NULL); 		} 		while ((nconf = getnetconfig(nc_handle)) != NULL) { 			if ((
ifdef|#
directive|ifdef
name|INET6
block|strcmp(nconf->nc_protofmly, NC_INET6) == 0 ||
endif|#
directive|endif
block|strcmp(nconf->nc_protofmly, NC_INET) == 0)&& 			    (nconf->nc_semantics == NC_TPI_COTS || 			     nconf->nc_semantics == NC_TPI_COTS_ORD)) { 				fd = __rpc_nconf2fd(nconf);
comment|/* 				 * Can't create a socket, assume that 				 * this family isn't configured in the kernel. 				 */
block|if (fd< 0) 					continue; 				_close(fd); 				tmpnconf = nconf; 				if (!strcmp(nconf->nc_protofmly, NC_INET)) 					hostname = IN4_LOCALHOST_STRING; 				else 					hostname = IN6_LOCALHOST_STRING; 			} 		} 		if (tmpnconf == NULL) { 			rpc_createerr.cf_stat = RPC_UNKNOWNPROTO; 			mutex_unlock(&loopnconf_lock); 			return (NULL); 		} 		loopnconf = getnetconfigent(tmpnconf->nc_netid);
comment|/* loopnconf is never freed */
block|endnetconfig(nc_handle); 	} 	mutex_unlock(&loopnconf_lock); 	client = getclnthandle(hostname, loopnconf, NULL); 	return (client);
else|#
directive|else
return|return
operator|(
name|NULL
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Set a mapping between program, version and address.  * Calls the rpcbind service to do the mapping.  */
end_comment

begin_function
name|bool_t
name|rpcb_set
parameter_list|(
name|rpcprog_t
name|program
parameter_list|,
name|rpcvers_t
name|version
parameter_list|,
specifier|const
name|struct
name|netconfig
modifier|*
name|nconf
parameter_list|,
comment|/* Network structure of transport */
specifier|const
name|struct
name|netbuf
modifier|*
name|address
parameter_list|)
comment|/* Services netconfig address */
block|{
name|CLIENT
modifier|*
name|client
decl_stmt|;
name|bool_t
name|rslt
init|=
name|FALSE
decl_stmt|;
name|RPCB
name|parms
decl_stmt|;
if|#
directive|if
literal|0
block|char uidbuf[32];
endif|#
directive|endif
name|struct
name|netconfig
name|nconfcopy
decl_stmt|;
name|struct
name|netbuf
name|addresscopy
decl_stmt|;
comment|/* parameter checking */
if|if
condition|(
name|nconf
operator|==
name|NULL
condition|)
block|{
name|rpc_createerr
operator|.
name|cf_stat
operator|=
name|RPC_UNKNOWNPROTO
expr_stmt|;
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
if|if
condition|(
name|address
operator|==
name|NULL
condition|)
block|{
name|rpc_createerr
operator|.
name|cf_stat
operator|=
name|RPC_UNKNOWNADDR
expr_stmt|;
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
name|client
operator|=
name|local_rpcb
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|client
condition|)
block|{
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
comment|/* convert to universal */
comment|/*LINTED const castaway*/
name|nconfcopy
operator|=
operator|*
name|nconf
expr_stmt|;
name|addresscopy
operator|=
operator|*
name|address
expr_stmt|;
name|parms
operator|.
name|r_addr
operator|=
name|taddr2uaddr
argument_list|(
operator|&
name|nconfcopy
argument_list|,
operator|&
name|addresscopy
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|parms
operator|.
name|r_addr
condition|)
block|{
name|CLNT_DESTROY
argument_list|(
name|client
argument_list|)
expr_stmt|;
name|rpc_createerr
operator|.
name|cf_stat
operator|=
name|RPC_N2AXLATEFAILURE
expr_stmt|;
return|return
operator|(
name|FALSE
operator|)
return|;
comment|/* no universal address */
block|}
name|parms
operator|.
name|r_prog
operator|=
name|program
expr_stmt|;
name|parms
operator|.
name|r_vers
operator|=
name|version
expr_stmt|;
name|parms
operator|.
name|r_netid
operator|=
name|nconf
operator|->
name|nc_netid
expr_stmt|;
if|#
directive|if
literal|0
comment|/* 	 * Though uid is not being used directly, we still send it for 	 * completeness.  For non-unix platforms, perhaps some other 	 * string or an empty string can be sent. 	 */
block|(void) snprintf(uidbuf, sizeof uidbuf, "%d", geteuid()); 	parms.r_owner = uidbuf;
else|#
directive|else
name|parms
operator|.
name|r_owner
operator|=
literal|""
expr_stmt|;
endif|#
directive|endif
name|CLNT_CALL
argument_list|(
name|client
argument_list|,
operator|(
name|rpcproc_t
operator|)
name|RPCBPROC_SET
argument_list|,
operator|(
name|xdrproc_t
operator|)
name|xdr_rpcb
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
operator|&
name|parms
argument_list|,
operator|(
name|xdrproc_t
operator|)
name|xdr_bool
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
operator|&
name|rslt
argument_list|,
name|tottimeout
argument_list|)
expr_stmt|;
name|CLNT_DESTROY
argument_list|(
name|client
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|parms
operator|.
name|r_addr
argument_list|,
name|M_RPC
argument_list|)
expr_stmt|;
return|return
operator|(
name|rslt
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Remove the mapping between program, version and netbuf address.  * Calls the rpcbind service to do the un-mapping.  * If netbuf is NULL, unset for all the transports, otherwise unset  * only for the given transport.  */
end_comment

begin_function
name|bool_t
name|rpcb_unset
parameter_list|(
name|rpcprog_t
name|program
parameter_list|,
name|rpcvers_t
name|version
parameter_list|,
specifier|const
name|struct
name|netconfig
modifier|*
name|nconf
parameter_list|)
block|{
name|CLIENT
modifier|*
name|client
decl_stmt|;
name|bool_t
name|rslt
init|=
name|FALSE
decl_stmt|;
name|RPCB
name|parms
decl_stmt|;
if|#
directive|if
literal|0
block|char uidbuf[32];
endif|#
directive|endif
name|client
operator|=
name|local_rpcb
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|client
condition|)
block|{
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
name|parms
operator|.
name|r_prog
operator|=
name|program
expr_stmt|;
name|parms
operator|.
name|r_vers
operator|=
name|version
expr_stmt|;
if|if
condition|(
name|nconf
condition|)
name|parms
operator|.
name|r_netid
operator|=
name|nconf
operator|->
name|nc_netid
expr_stmt|;
else|else
block|{
comment|/*LINTED const castaway*/
name|parms
operator|.
name|r_netid
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
operator|&
name|nullstring
index|[
literal|0
index|]
expr_stmt|;
comment|/* unsets  all */
block|}
comment|/*LINTED const castaway*/
name|parms
operator|.
name|r_addr
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
operator|&
name|nullstring
index|[
literal|0
index|]
expr_stmt|;
if|#
directive|if
literal|0
block|(void) snprintf(uidbuf, sizeof uidbuf, "%d", geteuid()); 	parms.r_owner = uidbuf;
else|#
directive|else
name|parms
operator|.
name|r_owner
operator|=
literal|""
expr_stmt|;
endif|#
directive|endif
name|CLNT_CALL
argument_list|(
name|client
argument_list|,
operator|(
name|rpcproc_t
operator|)
name|RPCBPROC_UNSET
argument_list|,
operator|(
name|xdrproc_t
operator|)
name|xdr_rpcb
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
operator|&
name|parms
argument_list|,
operator|(
name|xdrproc_t
operator|)
name|xdr_bool
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
operator|&
name|rslt
argument_list|,
name|tottimeout
argument_list|)
expr_stmt|;
name|CLNT_DESTROY
argument_list|(
name|client
argument_list|)
expr_stmt|;
return|return
operator|(
name|rslt
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * From the merged list, find the appropriate entry  */
end_comment

begin_ifdef
unit|static struct netbuf * got_entry(relp, nconf) 	rpcb_entry_list_ptr relp; 	const struct netconfig *nconf; { 	struct netbuf *na = NULL; 	rpcb_entry_list_ptr sp; 	rpcb_entry *rmap;  	for (sp = relp; sp != NULL; sp = sp->rpcb_entry_next) { 		rmap =&sp->rpcb_entry_map; 		if ((strcmp(nconf->nc_proto, rmap->r_nc_proto) == 0)&& 		    (strcmp(nconf->nc_protofmly, rmap->r_nc_protofmly) == 0)&& 		    (nconf->nc_semantics == rmap->r_nc_semantics)&& 		    (rmap->r_maddr != NULL)&& (rmap->r_maddr[0] != 0)) { 			na = uaddr2taddr(nconf, rmap->r_maddr);
ifdef|#
directive|ifdef
name|ND_DEBUG
end_ifdef

begin_endif
unit|fprintf(stderr, "\tRemote address is [%s].\n", 				rmap->r_maddr); 			if (!na) 				fprintf(stderr, 				    "\tCouldn't resolve remote address!\n");
endif|#
directive|endif
end_endif

begin_comment
unit|break; 		} 	} 	return (na); }
comment|/*  * Quick check to see if rpcbind is up.  Tries to connect over  * local transport.  */
end_comment

begin_comment
unit|static bool_t __rpcbind_is_up() { 	struct netconfig *nconf; 	struct sockaddr_un sun; 	void *localhandle; 	int sock;  	nconf = NULL; 	localhandle = setnetconfig(); 	while ((nconf = getnetconfig(localhandle)) != NULL) { 		if (nconf->nc_protofmly != NULL&& 		    strcmp(nconf->nc_protofmly, NC_LOOPBACK) == 0) 			 break; 	} 	if (nconf == NULL) 		return (FALSE);  	endnetconfig(localhandle);  	memset(&sun, 0, sizeof sun); 	sock = _socket(AF_LOCAL, SOCK_STREAM, 0); 	if (sock< 0) 		return (FALSE); 	sun.sun_family = AF_LOCAL; 	strncpy(sun.sun_path, _PATH_RPCBINDSOCK, sizeof(sun.sun_path)); 	sun.sun_len = SUN_LEN(&sun);  	if (_connect(sock, (struct sockaddr *)&sun, sun.sun_len)< 0) { 		_close(sock); 		return (FALSE); 	}  	_close(sock); 	return (TRUE); }
comment|/*  * An internal function which optimizes rpcb_getaddr function.  It also  * returns the client handle that it uses to contact the remote rpcbind.  *  * The algorithm used: If the transports is TCP or UDP, it first tries  * version 2 (portmap), 4 and then 3 (svr4).  This order should be  * changed in the next OS release to 4, 2 and 3.  We are assuming that by  * that time, version 4 would be available on many machines on the network.  * With this algorithm, we get performance as well as a plan for  * obsoleting version 2.  *  * For all other transports, the algorithm remains as 4 and then 3.  *  * XXX: Due to some problems with t_connect(), we do not reuse the same client  * handle for COTS cases and hence in these cases we do not return the  * client handle.  This code will change if t_connect() ever  * starts working properly.  Also look under clnt_vc.c.  */
end_comment

begin_comment
unit|struct netbuf * __rpcb_findaddr_timed(program, version, nconf, host, clpp, tp) 	rpcprog_t program; 	rpcvers_t version; 	const struct netconfig *nconf; 	const char *host; 	CLIENT **clpp; 	struct timeval *tp; { 	static bool_t check_rpcbind = TRUE; 	CLIENT *client = NULL; 	RPCB parms; 	enum clnt_stat clnt_st; 	char *ua = NULL; 	rpcvers_t vers; 	struct netbuf *address = NULL; 	rpcvers_t start_vers = RPCBVERS4; 	struct netbuf servaddr;
comment|/* parameter checking */
end_comment

begin_comment
unit|if (nconf == NULL) { 		rpc_createerr.cf_stat = RPC_UNKNOWNPROTO; 		return (NULL); 	}  	parms.r_addr = NULL;
comment|/* 	 * Use default total timeout if no timeout is specified. 	 */
end_comment

begin_ifdef
unit|if (tp == NULL) 		tp =&tottimeout;
ifdef|#
directive|ifdef
name|PORTMAP
end_ifdef

begin_comment
comment|/* Try version 2 for TCP or UDP */
end_comment

begin_comment
unit|if (strcmp(nconf->nc_protofmly, NC_INET) == 0) { 		u_short port = 0; 		struct netbuf remote; 		rpcvers_t pmapvers = 2; 		struct pmap pmapparms;
comment|/* 		 * Try UDP only - there are some portmappers out 		 * there that use UDP only. 		 */
end_comment

begin_comment
unit|if (strcmp(nconf->nc_proto, NC_TCP) == 0) { 			struct netconfig *newnconf;  			if ((newnconf = getnetconfigent("udp")) == NULL) { 				rpc_createerr.cf_stat = RPC_UNKNOWNPROTO; 				return (NULL); 			} 			client = getclnthandle(host, newnconf,&parms.r_addr); 			freenetconfigent(newnconf); 		} else { 			client = getclnthandle(host, nconf,&parms.r_addr); 		} 		if (client == NULL) 			return (NULL);
comment|/* 		 * Set version and retry timeout. 		 */
end_comment

begin_comment
unit|CLNT_CONTROL(client, CLSET_RETRY_TIMEOUT, (char *)&rpcbrmttime); 		CLNT_CONTROL(client, CLSET_VERS, (char *)&pmapvers);  		pmapparms.pm_prog = program; 		pmapparms.pm_vers = version; 		pmapparms.pm_prot = strcmp(nconf->nc_proto, NC_TCP) ? 					IPPROTO_UDP : IPPROTO_TCP; 		pmapparms.pm_port = 0;
comment|/* not needed */
end_comment

begin_comment
unit|clnt_st = CLNT_CALL(client, (rpcproc_t)PMAPPROC_GETPORT, 		    (xdrproc_t) xdr_pmap, (caddr_t)(void *)&pmapparms, 		    (xdrproc_t) xdr_u_short, (caddr_t)(void *)&port, 		    *tp); 		if (clnt_st != RPC_SUCCESS) { 			if ((clnt_st == RPC_PROGVERSMISMATCH) || 				(clnt_st == RPC_PROGUNAVAIL)) 				goto try_rpcbind;
comment|/* Try different versions */
end_comment

begin_endif
unit|rpc_createerr.cf_stat = RPC_PMAPFAILURE; 			clnt_geterr(client,&rpc_createerr.cf_error); 			goto error; 		} else if (port == 0) { 			address = NULL; 			rpc_createerr.cf_stat = RPC_PROGNOTREGISTERED; 			goto error; 		} 		port = htons(port); 		CLNT_CONTROL(client, CLGET_SVC_ADDR, (char *)&remote); 		if (((address = (struct netbuf *) 			malloc(sizeof (struct netbuf))) == NULL) || 		    ((address->buf = (char *) 			malloc(remote.len)) == NULL)) { 			rpc_createerr.cf_stat = RPC_SYSTEMERROR; 			clnt_geterr(client,&rpc_createerr.cf_error); 			if (address) { 				free(address); 				address = NULL; 			} 			goto error; 		} 		memcpy(address->buf, remote.buf, remote.len); 		memcpy(&((char *)address->buf)[sizeof (short)], 				(char *)(void *)&port, sizeof (short)); 		address->len = address->maxlen = remote.len; 		goto done; 	}
endif|#
directive|endif
end_endif

begin_comment
comment|/* PORTMAP */
end_comment

begin_comment
unit|try_rpcbind:
comment|/* 	 * Check if rpcbind is up.  This prevents needless delays when 	 * accessing applications such as the keyserver while booting 	 * disklessly. 	 */
end_comment

begin_comment
unit|if (check_rpcbind&& strcmp(nconf->nc_protofmly, NC_LOOPBACK) == 0) { 		if (!__rpcbind_is_up()) { 			rpc_createerr.cf_stat = RPC_PMAPFAILURE; 			rpc_createerr.cf_error.re_errno = 0; 			goto error; 		} 		check_rpcbind = FALSE; 	}
comment|/* 	 * Now we try version 4 and then 3. 	 * We also send the remote system the address we used to 	 * contact it in case it can help to connect back with us 	 */
end_comment

begin_comment
unit|parms.r_prog = program; 	parms.r_vers = version;
comment|/*LINTED const castaway*/
end_comment

begin_comment
unit|parms.r_owner = (char *)&nullstring[0];
comment|/* not needed; */
end_comment

begin_comment
comment|/* just for xdring */
end_comment

begin_comment
unit|parms.r_netid = nconf->nc_netid;
comment|/* not really needed */
end_comment

begin_comment
comment|/* 	 * If a COTS transport is being used, try getting address via CLTS 	 * transport.  This works only with version 4. 	 */
end_comment

begin_comment
unit|if (nconf->nc_semantics == NC_TPI_COTS_ORD || 			nconf->nc_semantics == NC_TPI_COTS) {  		void *handle; 		struct netconfig *nconf_clts; 		rpcb_entry_list_ptr relp = NULL;  		if (client == NULL) {
comment|/* This did not go through the above PORTMAP/TCP code */
end_comment

begin_comment
unit|if ((handle = __rpc_setconf("datagram_v")) != NULL) { 				while ((nconf_clts = __rpc_getconf(handle)) 					!= NULL) { 					if (strcmp(nconf_clts->nc_protofmly, 						nconf->nc_protofmly) != 0) { 						continue; 					} 					client = getclnthandle(host, nconf_clts,&parms.r_addr); 					break; 				} 				__rpc_endconf(handle); 			} 			if (client == NULL) 				goto regular_rpcbind;
comment|/* Go the regular way */
end_comment

begin_comment
unit|} else {
comment|/* This is a UDP PORTMAP handle.  Change to version 4 */
end_comment

begin_comment
unit|vers = RPCBVERS4; 			CLNT_CONTROL(client, CLSET_VERS, (char *)(void *)&vers); 		}
comment|/* 		 * We also send the remote system the address we used to 		 * contact it in case it can help it connect back with us 		 */
end_comment

begin_comment
unit|if (parms.r_addr == NULL) {
comment|/*LINTED const castaway*/
end_comment

begin_comment
unit|parms.r_addr = (char *)&nullstring[0];
comment|/* for XDRing */
end_comment

begin_comment
unit|}  		CLNT_CONTROL(client, CLSET_RETRY_TIMEOUT, (char *)&rpcbrmttime);  		clnt_st = CLNT_CALL(client, (rpcproc_t)RPCBPROC_GETADDRLIST, 		    (xdrproc_t) xdr_rpcb, (char *)(void *)&parms, 		    (xdrproc_t) xdr_rpcb_entry_list_ptr, 		    (char *)(void *)&relp, *tp); 		if (clnt_st == RPC_SUCCESS) { 			if ((address = got_entry(relp, nconf)) != NULL) { 				xdr_free((xdrproc_t) xdr_rpcb_entry_list_ptr, 				    (char *)(void *)&relp); 				CLNT_CONTROL(client, CLGET_SVC_ADDR, 					(char *)(void *)&servaddr); 				__rpc_fixup_addr(address,&servaddr); 				goto done; 			}
comment|/* Entry not found for this transport */
end_comment

begin_comment
unit|xdr_free((xdrproc_t) xdr_rpcb_entry_list_ptr, 			    (char *)(void *)&relp);
comment|/* 			 * XXX: should have perhaps returned with error but 			 * since the remote machine might not always be able 			 * to send the address on all transports, we try the 			 * regular way with regular_rpcbind 			 */
end_comment

begin_comment
unit|goto regular_rpcbind; 		} else if ((clnt_st == RPC_PROGVERSMISMATCH) || 			(clnt_st == RPC_PROGUNAVAIL)) { 			start_vers = RPCBVERS;
comment|/* Try version 3 now */
end_comment

begin_comment
unit|goto regular_rpcbind;
comment|/* Try different versions */
end_comment

begin_comment
unit|} else { 			rpc_createerr.cf_stat = RPC_PMAPFAILURE; 			clnt_geterr(client,&rpc_createerr.cf_error); 			goto error; 		} 	}  regular_rpcbind:
comment|/* Now the same transport is to be used to get the address */
end_comment

begin_comment
unit|if (client&& ((nconf->nc_semantics == NC_TPI_COTS_ORD) || 			(nconf->nc_semantics == NC_TPI_COTS))) {
comment|/* A CLTS type of client - destroy it */
end_comment

begin_comment
unit|CLNT_DESTROY(client); 		client = NULL; 	}  	if (client == NULL) { 		client = getclnthandle(host, nconf,&parms.r_addr); 		if (client == NULL) { 			goto error; 		} 	} 	if (parms.r_addr == NULL) {
comment|/*LINTED const castaway*/
end_comment

begin_comment
unit|parms.r_addr = (char *)&nullstring[0]; 	}
comment|/* First try from start_vers and then version 3 (RPCBVERS) */
end_comment

begin_comment
unit|CLNT_CONTROL(client, CLSET_RETRY_TIMEOUT, (char *)&rpcbrmttime); 	for (vers = start_vers;  vers>= RPCBVERS; vers--) {
comment|/* Set the version */
end_comment

begin_comment
unit|CLNT_CONTROL(client, CLSET_VERS, (char *)(void *)&vers); 		clnt_st = CLNT_CALL(client, (rpcproc_t)RPCBPROC_GETADDR, 		    (xdrproc_t) xdr_rpcb, (char *)(void *)&parms, 		    (xdrproc_t) xdr_wrapstring, (char *)(void *)&ua, *tp); 		if (clnt_st == RPC_SUCCESS) { 			if ((ua == NULL) || (ua[0] == 0)) {
comment|/* address unknown */
end_comment

begin_ifdef
unit|rpc_createerr.cf_stat = RPC_PROGNOTREGISTERED; 				goto error; 			} 			address = uaddr2taddr(nconf, ua);
ifdef|#
directive|ifdef
name|ND_DEBUG
end_ifdef

begin_endif
unit|fprintf(stderr, "\tRemote address is [%s]\n", ua); 			if (!address) 				fprintf(stderr, 					"\tCouldn't resolve remote address!\n");
endif|#
directive|endif
end_endif

begin_comment
unit|xdr_free((xdrproc_t)xdr_wrapstring, 			    (char *)(void *)&ua);  			if (! address) {
comment|/* We don't know about your universal address */
end_comment

begin_comment
unit|rpc_createerr.cf_stat = RPC_N2AXLATEFAILURE; 				goto error; 			} 			CLNT_CONTROL(client, CLGET_SVC_ADDR, 			    (char *)(void *)&servaddr); 			__rpc_fixup_addr(address,&servaddr); 			goto done; 		} else if (clnt_st == RPC_PROGVERSMISMATCH) { 			struct rpc_err rpcerr;  			clnt_geterr(client,&rpcerr); 			if (rpcerr.re_vers.low> RPCBVERS4) 				goto error;
comment|/* a new version, can't handle */
end_comment

begin_comment
unit|} else if (clnt_st != RPC_PROGUNAVAIL) {
comment|/* Cant handle this error */
end_comment

begin_comment
unit|rpc_createerr.cf_stat = clnt_st; 			clnt_geterr(client,&rpc_createerr.cf_error); 			goto error; 		} 	}  error: 	if (client) { 		CLNT_DESTROY(client); 		client = NULL; 	} done: 	if (nconf->nc_semantics != NC_TPI_CLTS) {
comment|/* This client is the connectionless one */
end_comment

begin_comment
unit|if (client) { 			CLNT_DESTROY(client); 			client = NULL; 		} 	} 	if (clpp) { 		*clpp = client; 	} else if (client) { 		CLNT_DESTROY(client); 	} 	if (parms.r_addr != NULL&& parms.r_addr != nullstring) 		free(parms.r_addr); 	return (address); }
comment|/*  * Find the mapped address for program, version.  * Calls the rpcbind service remotely to do the lookup.  * Uses the transport specified in nconf.  * Returns FALSE (0) if no map exists, else returns 1.  *  * Assuming that the address is all properly allocated  */
end_comment

begin_comment
unit|int rpcb_getaddr(program, version, nconf, address, host) 	rpcprog_t program; 	rpcvers_t version; 	const struct netconfig *nconf; 	struct netbuf *address; 	const char *host; { 	struct netbuf *na;  	if ((na = __rpcb_findaddr_timed(program, version, 	    (struct netconfig *) nconf, (char *) host, 	    (CLIENT **) NULL, (struct timeval *) NULL)) == NULL) 		return (FALSE);  	if (na->len> address->maxlen) {
comment|/* Too long address */
end_comment

begin_comment
unit|free(na->buf); 		free(na); 		rpc_createerr.cf_stat = RPC_FAILED; 		return (FALSE); 	} 	memcpy(address->buf, na->buf, (size_t)na->len); 	address->len = na->len; 	free(na->buf); 	free(na); 	return (TRUE); }
comment|/*  * Get a copy of the current maps.  * Calls the rpcbind service remotely to get the maps.  *  * It returns only a list of the services  * It returns NULL on failure.  */
end_comment

begin_comment
unit|rpcblist * rpcb_getmaps(nconf, host) 	const struct netconfig *nconf; 	const char *host; { 	rpcblist_ptr head = NULL; 	CLIENT *client; 	enum clnt_stat clnt_st; 	rpcvers_t vers = 0;  	client = getclnthandle(host, nconf, NULL); 	if (client == NULL) { 		return (head); 	} 	clnt_st = CLNT_CALL(client, (rpcproc_t)RPCBPROC_DUMP, 	    (xdrproc_t) xdr_void, NULL, (xdrproc_t) xdr_rpcblist_ptr, 	    (char *)(void *)&head, tottimeout); 	if (clnt_st == RPC_SUCCESS) 		goto done;  	if ((clnt_st != RPC_PROGVERSMISMATCH)&& 	    (clnt_st != RPC_PROGUNAVAIL)) { 		rpc_createerr.cf_stat = RPC_RPCBFAILURE; 		clnt_geterr(client,&rpc_createerr.cf_error); 		goto done; 	}
comment|/* fall back to earlier version */
end_comment

begin_comment
unit|CLNT_CONTROL(client, CLGET_VERS, (char *)(void *)&vers); 	if (vers == RPCBVERS4) { 		vers = RPCBVERS; 		CLNT_CONTROL(client, CLSET_VERS, (char *)(void *)&vers); 		if (CLNT_CALL(client, (rpcproc_t)RPCBPROC_DUMP, 		    (xdrproc_t) xdr_void, NULL, (xdrproc_t) xdr_rpcblist_ptr, 		    (char *)(void *)&head, tottimeout) == RPC_SUCCESS) 			goto done; 	} 	rpc_createerr.cf_stat = RPC_RPCBFAILURE; 	clnt_geterr(client,&rpc_createerr.cf_error);  done: 	CLNT_DESTROY(client); 	return (head); }
comment|/*  * rpcbinder remote-call-service interface.  * This routine is used to call the rpcbind remote call service  * which will look up a service program in the address maps, and then  * remotely call that routine with the given parameters. This allows  * programs to do a lookup and call in one step. */
end_comment

begin_comment
unit|enum clnt_stat rpcb_rmtcall(nconf, host, prog, vers, proc, xdrargs, argsp, 		xdrres, resp, tout, addr_ptr) 	const struct netconfig *nconf;
comment|/* Netconfig structure */
end_comment

begin_comment
unit|const char *host;
comment|/* Remote host name */
end_comment

begin_comment
unit|rpcprog_t prog; 	rpcvers_t vers; 	rpcproc_t proc;
comment|/* Remote proc identifiers */
end_comment

begin_comment
unit|xdrproc_t xdrargs, xdrres;
comment|/* XDR routines */
end_comment

begin_comment
unit|caddr_t argsp, resp;
comment|/* Argument and Result */
end_comment

begin_comment
unit|struct timeval tout;
comment|/* Timeout value for this call */
end_comment

begin_comment
unit|const struct netbuf *addr_ptr;
comment|/* Preallocated netbuf address */
end_comment

begin_comment
unit|{ 	CLIENT *client; 	enum clnt_stat stat; 	struct r_rpcb_rmtcallargs a; 	struct r_rpcb_rmtcallres r; 	rpcvers_t rpcb_vers;  	stat = 0; 	client = getclnthandle(host, nconf, NULL); 	if (client == NULL) { 		return (RPC_FAILED); 	}
comment|/*LINTED const castaway*/
end_comment

begin_comment
unit|CLNT_CONTROL(client, CLSET_RETRY_TIMEOUT, (char *)(void *)&rmttimeout); 	a.prog = prog; 	a.vers = vers; 	a.proc = proc; 	a.args.args_val = argsp; 	a.xdr_args = xdrargs; 	r.addr = NULL; 	r.results.results_val = resp; 	r.xdr_res = xdrres;  	for (rpcb_vers = RPCBVERS4; rpcb_vers>= RPCBVERS; rpcb_vers--) { 		CLNT_CONTROL(client, CLSET_VERS, (char *)(void *)&rpcb_vers); 		stat = CLNT_CALL(client, (rpcproc_t)RPCBPROC_CALLIT, 		    (xdrproc_t) xdr_rpcb_rmtcallargs, (char *)(void *)&a, 		    (xdrproc_t) xdr_rpcb_rmtcallres, (char *)(void *)&r, tout); 		if ((stat == RPC_SUCCESS)&& (addr_ptr != NULL)) { 			struct netbuf *na;
comment|/*LINTED const castaway*/
end_comment

begin_comment
unit|na = uaddr2taddr((struct netconfig *) nconf, r.addr); 			if (!na) { 				stat = RPC_N2AXLATEFAILURE;
comment|/*LINTED const castaway*/
end_comment

begin_comment
unit|((struct netbuf *) addr_ptr)->len = 0; 				goto error; 			} 			if (na->len> addr_ptr->maxlen) {
comment|/* Too long address */
end_comment

begin_comment
unit|stat = RPC_FAILED;
comment|/* XXX A better error no */
end_comment

begin_comment
unit|free(na->buf); 				free(na);
comment|/*LINTED const castaway*/
end_comment

begin_comment
unit|((struct netbuf *) addr_ptr)->len = 0; 				goto error; 			} 			memcpy(addr_ptr->buf, na->buf, (size_t)na->len);
comment|/*LINTED const castaway*/
end_comment

begin_comment
unit|((struct netbuf *)addr_ptr)->len = na->len; 			free(na->buf); 			free(na); 			break; 		} else if ((stat != RPC_PROGVERSMISMATCH)&& 			    (stat != RPC_PROGUNAVAIL)) { 			goto error; 		} 	} error: 	CLNT_DESTROY(client); 	if (r.addr) 		xdr_free((xdrproc_t) xdr_wrapstring, (char *)(void *)&r.addr); 	return (stat); }
comment|/*  * Gets the time on the remote host.  * Returns 1 if succeeds else 0.  */
end_comment

begin_comment
unit|bool_t rpcb_gettime(host, timep) 	const char *host; 	time_t *timep; { 	CLIENT *client = NULL; 	void *handle; 	struct netconfig *nconf; 	rpcvers_t vers; 	enum clnt_stat st;   	if ((host == NULL) || (host[0] == 0)) { 		time(timep); 		return (TRUE); 	}  	if ((handle = __rpc_setconf("netpath")) == NULL) { 		rpc_createerr.cf_stat = RPC_UNKNOWNPROTO; 		return (FALSE); 	} 	rpc_createerr.cf_stat = RPC_SUCCESS; 	while (client == NULL) { 		if ((nconf = __rpc_getconf(handle)) == NULL) { 			if (rpc_createerr.cf_stat == RPC_SUCCESS) 				rpc_createerr.cf_stat = RPC_UNKNOWNPROTO; 			break; 		} 		client = getclnthandle(host, nconf, NULL); 		if (client) 			break; 	} 	__rpc_endconf(handle); 	if (client == (CLIENT *) NULL) { 		return (FALSE); 	}  	st = CLNT_CALL(client, (rpcproc_t)RPCBPROC_GETTIME, 		(xdrproc_t) xdr_void, NULL, 		(xdrproc_t) xdr_int, (char *)(void *)timep, tottimeout);  	if ((st == RPC_PROGVERSMISMATCH) || (st == RPC_PROGUNAVAIL)) { 		CLNT_CONTROL(client, CLGET_VERS, (char *)(void *)&vers); 		if (vers == RPCBVERS4) {
comment|/* fall back to earlier version */
end_comment

begin_comment
unit|vers = RPCBVERS; 			CLNT_CONTROL(client, CLSET_VERS, (char *)(void *)&vers); 			st = CLNT_CALL(client, (rpcproc_t)RPCBPROC_GETTIME, 				(xdrproc_t) xdr_void, NULL, 				(xdrproc_t) xdr_int, (char *)(void *)timep, 				tottimeout); 		} 	} 	CLNT_DESTROY(client); 	return (st == RPC_SUCCESS? TRUE: FALSE); }  static bool_t xdr_netbuf(XDR *xdrs, struct netbuf *objp) { 	bool_t dummy; 	void **pp;  	if (!xdr_uint32_t(xdrs, (uint32_t *)&objp->maxlen)) { 		return (FALSE); 	} 	pp =&objp->buf; 	dummy = xdr_bytes(xdrs, (char **) pp, 			(u_int *)&(objp->len), objp->maxlen); 	return (dummy); }
comment|/*  * Converts taddr to universal address.  This routine should never  * really be called because local n2a libraries are always provided.  */
end_comment

begin_comment
unit|char * rpcb_taddr2uaddr(struct netconfig *nconf, struct netbuf *taddr) { 	CLIENT *client; 	char *uaddr = NULL;
comment|/* parameter checking */
end_comment

begin_comment
unit|if (nconf == NULL) { 		rpc_createerr.cf_stat = RPC_UNKNOWNPROTO; 		return (NULL); 	} 	if (taddr == NULL) { 		rpc_createerr.cf_stat = RPC_UNKNOWNADDR; 		return (NULL); 	} 	client = local_rpcb(); 	if (! client) { 		return (NULL); 	}  	CLNT_CALL(client, (rpcproc_t)RPCBPROC_TADDR2UADDR, 	    (xdrproc_t) xdr_netbuf, (char *)(void *)taddr, 	    (xdrproc_t) xdr_wrapstring, (char *)(void *)&uaddr, tottimeout); 	CLNT_DESTROY(client); 	return (uaddr); }
comment|/*  * Converts universal address to netbuf.  This routine should never  * really be called because local n2a libraries are always provided.  */
end_comment

begin_comment
unit|struct netbuf * rpcb_uaddr2taddr(struct netconfig *nconf, char *uaddr) { 	CLIENT *client; 	struct netbuf *taddr;
comment|/* parameter checking */
end_comment

begin_endif
unit|if (nconf == NULL) { 		rpc_createerr.cf_stat = RPC_UNKNOWNPROTO; 		return (NULL); 	} 	if (uaddr == NULL) { 		rpc_createerr.cf_stat = RPC_UNKNOWNADDR; 		return (NULL); 	} 	client = local_rpcb(); 	if (! client) { 		return (NULL); 	}  	taddr = (struct netbuf *)malloc(sizeof (struct netbuf), M_RPC, M_WAITOK|M_ZERO); 	if (CLNT_CALL(client, (rpcproc_t)RPCBPROC_UADDR2TADDR, 	    (xdrproc_t) xdr_wrapstring, (char *)(void *)&uaddr, 	    (xdrproc_t) xdr_netbuf, (char *)(void *)taddr, 	    tottimeout) != RPC_SUCCESS) { 		free(taddr); 		taddr = NULL; 	} 	CLNT_DESTROY(client); 	return (taddr); }
endif|#
directive|endif
end_endif

end_unit

