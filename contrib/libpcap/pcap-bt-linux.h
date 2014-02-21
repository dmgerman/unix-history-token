begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Paolo Abeni (Italy)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote   * products derived from this software without specific prior written   * permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Bluetooth sniffing API implementation for Linux platform  * By Paolo Abeni<paolo.abeni@email.it>  *  * @(#) $Header: /tcpdump/master/libpcap/pcap-bt-linux.h,v 1.5 2008-04-04 19:37:45 guy Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Prototypes for Bluetooth-related functions  */
end_comment

begin_function_decl
name|int
name|bt_findalldevs
parameter_list|(
name|pcap_if_t
modifier|*
modifier|*
name|alldevsp
parameter_list|,
name|char
modifier|*
name|err_str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pcap_t
modifier|*
name|bt_create
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

end_unit

