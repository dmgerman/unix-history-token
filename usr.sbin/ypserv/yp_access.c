begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

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
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|"yp_extern.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TCP_WRAPPER
end_ifdef

begin_include
include|#
directive|include
file|"tcpd.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|yp_procs
index|[]
init|=
block|{
literal|"ypproc_null"
block|,
literal|"ypproc_domain"
block|,
literal|"ypproc_domain_nonack"
block|,
literal|"ypproc_match"
block|,
literal|"ypproc_first"
block|,
literal|"ypproc_next"
block|,
literal|"ypproc_xfr"
block|,
literal|"ypproc_clear"
block|,
literal|"ypproc_all"
block|,
literal|"ypproc_master"
block|,
literal|"ypproc_order"
block|,
literal|"ypproc_maplist"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Access control functions.  *  * yp_access() checks the mapname and client host address and watches for  * the following things:  *  * - If the client is referencing one of the master.passwd.* maps, it must  *   be using a privileged port to make its RPC to us. If it is, then we can  *   assume that the caller is root and allow the RPC to succeed. If it  *   isn't access is denied.  *  * - If we are compiled with the tcpwrapper package, we also check to see  *   if the host makes it past the libwrap checks and deny access if it  *   doesn't. Host address checks are disabled if not compiled with the  *   tcp_wrapper package.  *  * The yp_validdomain() functions checks the domain specified by the caller  * to make sure it's actually served by this server. This is more a sanity  * check than an a security check, but this seems to be the best place for  * it.  */
end_comment

begin_function
name|int
name|yp_access
parameter_list|(
name|map
parameter_list|,
name|rqstp
parameter_list|)
specifier|const
name|char
modifier|*
name|map
decl_stmt|;
specifier|const
name|struct
name|svc_req
modifier|*
name|rqstp
decl_stmt|;
block|{
name|struct
name|sockaddr_in
modifier|*
name|rqhost
decl_stmt|;
ifdef|#
directive|ifdef
name|TCP_WRAPPER
name|int
name|status
init|=
literal|0
decl_stmt|;
name|unsigned
name|long
name|oldaddr
decl_stmt|;
endif|#
directive|endif
name|rqhost
operator|=
name|svc_getcaller
argument_list|(
name|rqstp
operator|->
name|rq_xprt
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
block|{
name|yp_error
argument_list|(
literal|"Procedure %s called from %s:%d"
argument_list|,
name|yp_procs
index|[
name|rqstp
operator|->
name|rq_proc
index|]
argument_list|,
name|inet_ntoa
argument_list|(
name|rqhost
operator|->
name|sin_addr
argument_list|)
argument_list|,
name|ntohs
argument_list|(
name|rqhost
operator|->
name|sin_port
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|map
operator|!=
name|NULL
condition|)
name|yp_error
argument_list|(
literal|"Client is referencing map \"%s\"."
argument_list|,
name|map
argument_list|)
expr_stmt|;
block|}
comment|/* Check the map name if one was supplied. */
if|if
condition|(
name|map
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|strstr
argument_list|(
name|map
argument_list|,
literal|"master.passwd."
argument_list|)
operator|&&
name|ntohs
argument_list|(
name|rqhost
operator|->
name|sin_port
argument_list|)
operator|>
literal|1023
condition|)
block|{
name|yp_error
argument_list|(
literal|"Access to %s denied -- client not privileged"
argument_list|,
name|map
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
ifdef|#
directive|ifdef
name|TCP_WRAPPER
comment|/* Check client address if TCP_WRAPPER is enalbled. */
name|status
operator|=
name|hosts_ctl
argument_list|(
argument|progname
argument_list|,
argument|STRING_UNKNOWN
argument_list|,
argument|inet_ntoa(rqhost->sin_addr,
literal|""
argument|);  	if (!status&& rqhost->sin_addr.s_addr != oldaddr) { 		yp_error(
literal|"connect from %s:%d refused"
argument|, 			  inet_ntoa(rqhost->sin_addr, ntohs(rqhost->sin_port)); 		oldaddr = rqhost->sin_addr.s_addr; 		return(
literal|1
argument|); 	}
endif|#
directive|endif
argument|return(
literal|0
argument|);  }  int yp_validdomain(domain) 	const char *domain; { 	struct stat statbuf; 	char dompath[MAXPATHLEN +
literal|2
argument|];  	if (domain == NULL || strstr(domain,
literal|"binding"
argument|) || 	    !strcmp(domain,
literal|"."
argument|) || !strcmp(domain,
literal|".."
argument|) || 	    strchr(domain,
literal|'/'
argument|)) 		return(
literal|1
argument|);  	snprintf(dompath, sizeof(dompath),
literal|"%s/%s"
argument|, yp_dir, domain);  	if (stat(dompath,&statbuf)<
literal|0
argument||| !S_ISDIR(statbuf.st_mode)) 		return(
literal|1
argument|);  	return(
literal|0
argument|); }
end_function

end_unit

