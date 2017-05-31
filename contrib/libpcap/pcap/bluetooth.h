begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Paolo Abeni (Italy)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  * products derived from this software without specific prior written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * bluetooth data struct  * By Paolo Abeni<paolo.abeni@email.it>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lib_pcap_bluetooth_h
end_ifndef

begin_define
define|#
directive|define
name|lib_pcap_bluetooth_h
end_define

begin_comment
comment|/*  * Header prepended libpcap to each bluetooth h4 frame,  * fields are in network byte order  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pcap_bluetooth_h4_header
block|{
name|u_int32_t
name|direction
decl_stmt|;
comment|/* if first bit is set direction is incoming */
block|}
name|pcap_bluetooth_h4_header
typedef|;
end_typedef

begin_comment
comment|/*  * Header prepended libpcap to each bluetooth linux monitor frame,  * fields are in network byte order  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pcap_bluetooth_linux_monitor_header
block|{
name|u_int16_t
name|adapter_id
decl_stmt|;
name|u_int16_t
name|opcode
decl_stmt|;
block|}
name|pcap_bluetooth_linux_monitor_header
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

