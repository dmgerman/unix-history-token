begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|<rpc/svc_dg.h>
end_include

begin_include
include|#
directive|include
file|"yp_extern.h"
end_include

begin_define
define|#
directive|define
name|su_data
parameter_list|(
name|xprt
parameter_list|)
value|((struct svc_dg_data *)(xprt->xp_p2))
end_define

begin_comment
comment|/*  * We need to be able to manually set the transaction ID in the  * UDP transport handle, but the standard library offers us no way  * to do that. Hence we need this garbage.  */
end_comment

begin_function
name|unsigned
name|long
name|svcudp_get_xid
parameter_list|(
name|SVCXPRT
modifier|*
name|xprt
parameter_list|)
block|{
name|struct
name|svc_dg_data
modifier|*
name|su
decl_stmt|;
if|if
condition|(
name|xprt
operator|==
name|NULL
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|su
operator|=
name|su_data
argument_list|(
name|xprt
argument_list|)
expr_stmt|;
return|return
operator|(
name|su
operator|->
name|su_xid
operator|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|svcudp_set_xid
parameter_list|(
name|SVCXPRT
modifier|*
name|xprt
parameter_list|,
name|unsigned
name|long
name|xid
parameter_list|)
block|{
name|struct
name|svc_dg_data
modifier|*
name|su
decl_stmt|;
name|unsigned
name|long
name|old_xid
decl_stmt|;
if|if
condition|(
name|xprt
operator|==
name|NULL
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|su
operator|=
name|su_data
argument_list|(
name|xprt
argument_list|)
expr_stmt|;
name|old_xid
operator|=
name|su
operator|->
name|su_xid
expr_stmt|;
name|su
operator|->
name|su_xid
operator|=
name|xid
expr_stmt|;
return|return
operator|(
name|old_xid
operator|)
return|;
block|}
end_function

end_unit

