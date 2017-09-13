begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Broadcom NetXtreme-C/E network driver.  *  * Copyright (c) 2016 Broadcom, All Rights Reserved.  * The term Broadcom refers to Broadcom Limited and/or its subsidiaries  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"bnxt.h"
end_include

begin_function_decl
name|int
name|bnxt_init_sysctl_ctx
parameter_list|(
name|struct
name|bnxt_softc
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bnxt_free_sysctl_ctx
parameter_list|(
name|struct
name|bnxt_softc
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bnxt_create_port_stats_sysctls
parameter_list|(
name|struct
name|bnxt_softc
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bnxt_create_tx_sysctls
parameter_list|(
name|struct
name|bnxt_softc
modifier|*
name|softc
parameter_list|,
name|int
name|txr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bnxt_create_rx_sysctls
parameter_list|(
name|struct
name|bnxt_softc
modifier|*
name|softc
parameter_list|,
name|int
name|rxr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bnxt_create_ver_sysctls
parameter_list|(
name|struct
name|bnxt_softc
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bnxt_create_nvram_sysctls
parameter_list|(
name|struct
name|bnxt_nvram_info
modifier|*
name|ni
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bnxt_create_config_sysctls_pre
parameter_list|(
name|struct
name|bnxt_softc
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bnxt_create_config_sysctls_post
parameter_list|(
name|struct
name|bnxt_softc
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

end_unit

