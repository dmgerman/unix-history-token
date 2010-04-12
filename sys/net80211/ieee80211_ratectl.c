begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Rui Paulo<rpaulo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

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

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_var.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_ratectl.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ieee80211_ratectl
modifier|*
name|ratectls
index|[
name|IEEE80211_RATECTL_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|M_80211_RATECTL
argument_list|,
literal|"80211ratectl"
argument_list|,
literal|"802.11 rate control"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|ieee80211_ratectl_register
parameter_list|(
name|int
name|type
parameter_list|,
specifier|const
name|struct
name|ieee80211_ratectl
modifier|*
name|ratectl
parameter_list|)
block|{
if|if
condition|(
name|type
operator|>=
name|IEEE80211_RATECTL_MAX
condition|)
return|return;
name|ratectls
index|[
name|type
index|]
operator|=
name|ratectl
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ieee80211_ratectl_unregister
parameter_list|(
name|int
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|>=
name|IEEE80211_RATECTL_MAX
condition|)
return|return;
name|ratectls
index|[
name|type
index|]
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ieee80211_ratectl_set
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|int
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|>=
name|IEEE80211_RATECTL_MAX
condition|)
return|return;
name|vap
operator|->
name|iv_rate
operator|=
name|ratectls
index|[
name|type
index|]
expr_stmt|;
block|}
end_function

end_unit

