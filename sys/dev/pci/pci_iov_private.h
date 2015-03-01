begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2015 Sandvine Inc.  All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI_IOV_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI_IOV_PRIVATE_H_
end_define

begin_struct
struct|struct
name|pci_iov_bar
block|{
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|pci_addr_t
name|bar_size
decl_stmt|;
name|pci_addr_t
name|bar_shift
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcicfg_iov
block|{
name|struct
name|cdev
modifier|*
name|iov_cdev
decl_stmt|;
name|struct
name|pci_iov_bar
name|iov_bar
index|[
name|PCIR_MAX_BAR_0
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|rman
name|rman
decl_stmt|;
name|char
name|rman_name
index|[
literal|64
index|]
decl_stmt|;
name|int
name|iov_pos
decl_stmt|;
name|int
name|iov_num_vfs
decl_stmt|;
name|uint32_t
name|iov_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOV_RMAN_INITED
value|0x0001
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

