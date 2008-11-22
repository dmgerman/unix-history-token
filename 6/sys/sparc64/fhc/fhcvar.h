begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_FHC_FHCVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_FHC_FHCVAR_H_
end_define

begin_define
define|#
directive|define
name|FHC_CENTRAL
value|(1<<0)
end_define

begin_struct
struct|struct
name|fhc_softc
block|{
name|phandle_t
name|sc_node
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_memres
index|[
name|FHC_NREG
index|]
decl_stmt|;
name|bus_space_handle_t
name|sc_bh
index|[
name|FHC_NREG
index|]
decl_stmt|;
name|bus_space_tag_t
name|sc_bt
index|[
name|FHC_NREG
index|]
decl_stmt|;
name|int
name|sc_nrange
decl_stmt|;
name|struct
name|sbus_ranges
modifier|*
name|sc_ranges
decl_stmt|;
name|int
name|sc_board
decl_stmt|;
name|int
name|sc_ign
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
name|struct
name|cdev
modifier|*
name|sc_led_dev
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|device_probe_t
name|fhc_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|device_attach_t
name|fhc_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_print_child_t
name|fhc_print_child
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_probe_nomatch_t
name|fhc_probe_nomatch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_setup_intr_t
name|fhc_setup_intr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_teardown_intr_t
name|fhc_teardown_intr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_alloc_resource_t
name|fhc_alloc_resource
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_get_resource_list_t
name|fhc_get_resource_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ofw_bus_get_compat_t
name|fhc_get_compat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ofw_bus_get_model_t
name|fhc_get_model
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ofw_bus_get_name_t
name|fhc_get_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ofw_bus_get_node_t
name|fhc_get_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ofw_bus_get_type_t
name|fhc_get_type
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SPARC64_FHC_FHCVAR_H_ */
end_comment

end_unit

