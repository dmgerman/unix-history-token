begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Romain Francoise<romain@orebokech.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|NETDISSECT_REWORKED
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<tcpdump-stdinc.h>
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_struct
struct|struct
name|msnlb_heartbeat_pkt
block|{
name|uint32_t
name|unknown1
decl_stmt|;
name|uint32_t
name|unknown2
decl_stmt|;
name|uint32_t
name|host_prio
decl_stmt|;
comment|/* little-endian */
name|uint32_t
name|virtual_ip
decl_stmt|;
name|uint32_t
name|host_ip
decl_stmt|;
comment|/* the protocol is undocumented so we ignore the rest */
block|}
struct|;
end_struct

begin_function
name|void
name|msnlb_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|)
block|{
specifier|const
name|struct
name|msnlb_heartbeat_pkt
modifier|*
name|hb
decl_stmt|;
name|hb
operator|=
operator|(
expr|struct
name|msnlb_heartbeat_pkt
operator|*
operator|)
name|bp
expr_stmt|;
name|ND_TCHECK
argument_list|(
operator|*
name|hb
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"MS NLB heartbeat, host priority: %u,"
operator|,
name|EXTRACT_LE_32BITS
argument_list|(
operator|&
operator|(
name|hb
operator|->
name|host_prio
operator|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" cluster IP: %s,"
operator|,
name|ipaddr_string
argument_list|(
name|ndo
argument_list|,
operator|&
operator|(
name|hb
operator|->
name|virtual_ip
operator|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" host IP: %s"
operator|,
name|ipaddr_string
argument_list|(
name|ndo
argument_list|,
operator|&
operator|(
name|hb
operator|->
name|host_ip
operator|)
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return;
name|trunc
label|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"[|MS NLB]"
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

