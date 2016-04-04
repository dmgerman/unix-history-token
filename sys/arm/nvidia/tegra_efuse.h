begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Michal Meloun<mmel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TEGRA_EFUSE_H_
end_ifndef

begin_enum
enum|enum
name|tegra_revision
block|{
name|TEGRA_REVISION_UNKNOWN
init|=
literal|0
block|,
name|TEGRA_REVISION_A01
block|,
name|TEGRA_REVISION_A02
block|,
name|TEGRA_REVISION_A03
block|,
name|TEGRA_REVISION_A03p
block|,
name|TEGRA_REVISION_A04
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|tegra_sku_info
block|{
name|u_int
name|chip_id
decl_stmt|;
name|u_int
name|sku_id
decl_stmt|;
name|u_int
name|cpu_process_id
decl_stmt|;
name|u_int
name|cpu_speedo_id
decl_stmt|;
name|u_int
name|cpu_speedo_value
decl_stmt|;
name|u_int
name|cpu_iddq_value
decl_stmt|;
name|u_int
name|soc_process_id
decl_stmt|;
name|u_int
name|soc_speedo_id
decl_stmt|;
name|u_int
name|soc_speedo_value
decl_stmt|;
name|u_int
name|soc_iddq_value
decl_stmt|;
name|u_int
name|gpu_process_id
decl_stmt|;
name|u_int
name|gpu_speedo_id
decl_stmt|;
name|u_int
name|gpu_speedo_value
decl_stmt|;
name|u_int
name|gpu_iddq_value
decl_stmt|;
name|enum
name|tegra_revision
name|revision
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|tegra_sku_info
name|tegra_sku_info
decl_stmt|;
end_decl_stmt

begin_function_decl
name|uint32_t
name|tegra_fuse_read_4
parameter_list|(
name|int
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TEGRA_EFUSE_H_ */
end_comment

end_unit

