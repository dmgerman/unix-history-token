begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004  *	Doug Rabson  * Copyright (c) 2002-2003  * 	Hidetoshi Shimokawa. All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  *	This product includes software developed by Hidetoshi Shimokawa.  *  * 4. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_FWIPVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_FWIPVAR_H_
end_define

begin_struct
struct|struct
name|fwip_softc
block|{
comment|/* XXX this must be first for fd.post_explore() */
name|struct
name|firewire_dev_comm
name|fd
decl_stmt|;
name|short
name|dma_ch
decl_stmt|;
name|struct
name|fw_bind
name|fwb
decl_stmt|;
name|struct
name|fw_eui64
name|last_dest
decl_stmt|;
name|struct
name|fw_pkt
name|last_hdr
decl_stmt|;
name|struct
name|task
name|start_send
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|fw_xfer
argument_list|)
name|xferlist
expr_stmt|;
name|struct
name|crom_chunk
name|unit4
decl_stmt|;
comment|/* unit directory for IPv4 */
name|struct
name|crom_chunk
name|spec4
decl_stmt|;
comment|/* specifier description IPv4 */
name|struct
name|crom_chunk
name|ver4
decl_stmt|;
comment|/* version description IPv4 */
name|struct
name|crom_chunk
name|unit6
decl_stmt|;
comment|/* unit directory for IPv6 */
name|struct
name|crom_chunk
name|spec6
decl_stmt|;
comment|/* specifier description IPv6 */
name|struct
name|crom_chunk
name|ver6
decl_stmt|;
comment|/* version description IPv6 */
struct|struct
name|fwip_eth_softc
block|{
name|struct
name|ifnet
modifier|*
name|fwip_ifp
decl_stmt|;
name|struct
name|fwip_softc
modifier|*
name|fwip
decl_stmt|;
block|}
name|fw_softc
struct|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IF_FWIPVAR_H_ */
end_comment

end_unit

