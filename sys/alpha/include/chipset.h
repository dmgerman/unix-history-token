begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CHIPSET_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CHIPSET_H_
end_define

begin_typedef
typedef|typedef
name|u_int64_t
name|alpha_chipset_read_hae_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|alpha_chipset_write_hae_t
parameter_list|(
name|u_int64_t
parameter_list|)
function_decl|;
end_typedef

begin_struct_decl
struct_decl|struct
name|sgmap
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|alpha_chipset
block|{
comment|/*      * Access the HAE register      */
name|alpha_chipset_read_hae_t
modifier|*
name|read_hae
decl_stmt|;
name|alpha_chipset_write_hae_t
modifier|*
name|write_hae
decl_stmt|;
comment|/*      * Scatter-Gather map for ISA dma.      */
name|struct
name|sgmap
modifier|*
name|sgmap
decl_stmt|;
block|}
name|alpha_chipset_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|alpha_chipset_t
name|chipset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Exported sysctl variables describing the PCI chipset.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|chipset_type
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|chipset_bwx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|chipset_ports
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|chipset_memory
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|chipset_dense
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|chipset_hae_mask
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CHIPSET_H_ */
end_comment

end_unit

