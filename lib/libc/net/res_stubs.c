begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1996 Peter Wemm<peter@freebsd.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: res_stubs.c,v 1.6 1997/06/27 08:35:13 peter Exp $  */
end_comment

begin_comment
comment|/*  * This file is for FreeBSD-3.0 that has a bind-4.9.5-P1 derived  * resolver in the libc.  It provides aliases for functions that  * have moved since 4.9.4-P1.  *  * I'll save everybody the trouble and say it now:  *THIS IS A HACK*!  *  * Yes, many of these are private functions to the resolver, but some are  * needed as there is no other way to provide the functionality and they've  * turned up all over the place. :-(  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_addr
argument_list|,
name|inet_addr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_aton
argument_list|,
name|inet_aton
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_lnaof
argument_list|,
name|inet_lnaof
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_makeaddr
argument_list|,
name|inet_makeaddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_neta
argument_list|,
name|inet_neta
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_netof
argument_list|,
name|inet_netof
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_network
argument_list|,
name|inet_network
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_net_ntop
argument_list|,
name|inet_net_ntop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_net_pton
argument_list|,
name|inet_net_pton
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_ntoa
argument_list|,
name|inet_ntoa
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_pton
argument_list|,
name|inet_pton
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_ntop
argument_list|,
name|inet_ntop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_nsap_addr
argument_list|,
name|inet_nsap_addr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__inet_nsap_ntoa
argument_list|,
name|inet_nsap_ntoa
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__sym_ston
argument_list|,
name|sym_ston
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__sym_ntos
argument_list|,
name|sym_ntos
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__sym_ntop
argument_list|,
name|sym_ntop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__fp_resstat
argument_list|,
name|fp_resstat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__p_query
argument_list|,
name|p_query
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__p_fqnname
argument_list|,
name|p_fqnname
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__p_secstodate
argument_list|,
name|p_secstodate
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__dn_count_labels
argument_list|,
name|dn_count_labels
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__dn_comp
argument_list|,
name|dn_comp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__res_close
argument_list|,
name|_res_close
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__dn_expand
argument_list|,
name|dn_expand
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__res_init
argument_list|,
name|res_init
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__res_query
argument_list|,
name|res_query
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__res_search
argument_list|,
name|res_search
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__res_querydomain
argument_list|,
name|res_querydomain
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__res_mkquery
argument_list|,
name|res_mkquery
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__res_send
argument_list|,
name|res_send
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

