begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016 Cavium Inc.  * All rights reserved.  *  * Developed by Semihalf.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__THUNDER_PCIE_PEM_H__
end_ifndef

begin_define
define|#
directive|define
name|__THUNDER_PCIE_PEM_H__
end_define

begin_define
define|#
directive|define
name|THUNDER_PEM_DESC
value|"ThunderX PEM"
end_define

begin_struct
struct|struct
name|thunder_pem_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|reg
decl_stmt|;
name|bus_space_tag_t
name|reg_bst
decl_stmt|;
name|bus_space_handle_t
name|reg_bsh
decl_stmt|;
name|struct
name|pcie_range
name|ranges
index|[
name|MAX_RANGES_TUPLES
index|]
decl_stmt|;
name|struct
name|rman
name|mem_rman
decl_stmt|;
name|struct
name|rman
name|io_rman
decl_stmt|;
name|bus_space_handle_t
name|pem_sli_base
decl_stmt|;
name|uint32_t
name|node
decl_stmt|;
name|uint32_t
name|id
decl_stmt|;
name|uint32_t
name|sli
decl_stmt|;
name|uint32_t
name|sli_group
decl_stmt|;
name|uint64_t
name|sli_window_base
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

