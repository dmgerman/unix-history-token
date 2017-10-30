begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dpaa_portal
block|{
name|int
name|dp_irid
decl_stmt|;
comment|/* interrupt rid */
name|struct
name|resource
modifier|*
name|dp_ires
decl_stmt|;
comment|/* interrupt resource */
name|bool
name|dp_regs_mapped
decl_stmt|;
comment|/* register mapping status */
name|t_Handle
name|dp_ph
decl_stmt|;
comment|/* portal's handle */
name|vm_paddr_t
name|dp_ce_pa
decl_stmt|;
comment|/* portal's CE area PA */
name|vm_paddr_t
name|dp_ci_pa
decl_stmt|;
comment|/* portal's CI area PA */
name|uint32_t
name|dp_ce_size
decl_stmt|;
comment|/* portal's CE area size */
name|uint32_t
name|dp_ci_size
decl_stmt|;
comment|/* portal's CI area size */
name|uintptr_t
name|dp_intr_num
decl_stmt|;
comment|/* portal's intr. number */
block|}
name|dpaa_portal_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dpaa_portals_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* device handle */
name|vm_paddr_t
name|sc_dp_pa
decl_stmt|;
comment|/* portal's PA */
name|uint32_t
name|sc_dp_size
decl_stmt|;
comment|/* portal's size */
name|int
name|sc_rrid
index|[
literal|2
index|]
decl_stmt|;
comment|/* memory rid */
name|struct
name|resource
modifier|*
name|sc_rres
index|[
literal|2
index|]
decl_stmt|;
comment|/* memory resource */
name|dpaa_portal_t
name|sc_dp
index|[
name|MAXCPU
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dpaa_portals_devinfo
block|{
name|struct
name|resource_list
name|di_res
decl_stmt|;
name|int
name|di_intr_rid
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|bman_portals_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bman_portals_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|qman_portals_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|qman_portals_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dpaa_portal_alloc_res
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|dpaa_portals_devinfo
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dpaa_portal_map_registers
parameter_list|(
name|struct
name|dpaa_portals_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

