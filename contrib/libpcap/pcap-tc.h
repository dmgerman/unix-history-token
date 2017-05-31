begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 CACE Technologies, Davis (California)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. Neither the name of CACE Technologies nor the names of its  * contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCAP_TC_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCAP_TC_H__
end_define

begin_comment
comment|/*  * needed because gcc headers do not have C_ASSERT  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|C_ASSERT
end_ifndef

begin_define
define|#
directive|define
name|C_ASSERT
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<TcApi.h>
end_include

begin_comment
comment|/*  * functions used effectively by the pcap library  */
end_comment

begin_function_decl
name|pcap_t
modifier|*
name|TcCreate
parameter_list|(
specifier|const
name|char
modifier|*
name|device
parameter_list|,
name|char
modifier|*
name|ebuf
parameter_list|,
name|int
modifier|*
name|is_ours
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|TcFindAllDevs
parameter_list|(
name|pcap_if_t
modifier|*
modifier|*
name|alldevsp
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

