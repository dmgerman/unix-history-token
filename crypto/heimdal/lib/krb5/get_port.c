begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2001 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_include
include|#
directive|include
file|<krb5_locl.h>
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: get_port.c,v 1.8 2001/01/27 19:24:34 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|krb5_getportbyname
parameter_list|(
name|krb5_context
name|context
parameter_list|,
specifier|const
name|char
modifier|*
name|service
parameter_list|,
specifier|const
name|char
modifier|*
name|proto
parameter_list|,
name|int
name|default_port
parameter_list|)
block|{
name|struct
name|servent
modifier|*
name|sp
decl_stmt|;
if|if
condition|(
operator|(
name|sp
operator|=
name|roken_getservbyname
argument_list|(
name|service
argument_list|,
name|proto
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
if|#
directive|if
literal|0
block|krb5_warnx(context, "%s/%s unknown service, using default port %d",  		   service, proto, default_port);
endif|#
directive|endif
return|return
name|htons
argument_list|(
name|default_port
argument_list|)
return|;
block|}
else|else
return|return
name|sp
operator|->
name|s_port
return|;
block|}
end_function

end_unit

