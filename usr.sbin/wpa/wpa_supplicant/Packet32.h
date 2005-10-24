begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005  *      Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PACKET32_H_
end_ifndef

begin_define
define|#
directive|define
name|_PACKET32_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<ntddndis.h>
end_include

begin_struct
struct|struct
name|PACKET_OID_DATA
block|{
name|uint32_t
name|Oid
decl_stmt|;
name|uint32_t
name|Length
decl_stmt|;
name|uint8_t
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|PACKET_OID_DATA
name|PACKET_OID_DATA
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|PCHAR
name|PacketGetVersion
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|PacketOpenAdapter
parameter_list|(
name|CHAR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|PacketRequest
parameter_list|(
name|void
modifier|*
parameter_list|,
name|BOOLEAN
parameter_list|,
name|PACKET_OID_DATA
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|PacketGetAdapterNames
parameter_list|(
name|CHAR
modifier|*
parameter_list|,
name|ULONG
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|PacketCloseAdapter
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This is for backwards compatibility on FreeBSD 5.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIOCGDRVSPEC
end_ifndef

begin_define
define|#
directive|define
name|SIOCSDRVSPEC
value|_IOW('i', 123, struct ifreq)
end_define

begin_comment
comment|/* set driver-specific 								parameters */
end_comment

begin_define
define|#
directive|define
name|SIOCGDRVSPEC
value|_IOWR('i', 123, struct ifreq)
end_define

begin_comment
comment|/* get driver-specific 								parameters */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PACKET32_H_ */
end_comment

end_unit

