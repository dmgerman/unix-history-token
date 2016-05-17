begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_PCIE2_BHND_PCIE2_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_PCIE2_BHND_PCIE2_VAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_comment
comment|/*  * Shared PCIe-G2 Bridge/Host Bridge definitions.  */
end_comment

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|bhnd_pcie2_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|bhnd_pcie2_softc
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|bhnd_pcie2_generic_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pcie2_generic_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pcie2_generic_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pcie2_generic_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pcie2_generic_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_pcie2_read_proto_reg
parameter_list|(
name|struct
name|bhnd_pcie2_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_pcie2_write_proto_reg
parameter_list|(
name|struct
name|bhnd_pcie2_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|addr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pcie2_mdio_read
parameter_list|(
name|struct
name|bhnd_pcie2_softc
modifier|*
name|sc
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pcie2_mdio_write
parameter_list|(
name|struct
name|bhnd_pcie2_softc
modifier|*
name|sc
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pcie2_mdio_read_ext
parameter_list|(
name|struct
name|bhnd_pcie2_softc
modifier|*
name|sc
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|devaddr
parameter_list|,
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pcie2_mdio_write_ext
parameter_list|(
name|struct
name|bhnd_pcie2_softc
modifier|*
name|sc
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|devaddr
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * bhnd_pcie2 child device info  */
end_comment

begin_struct
struct|struct
name|bhnd_pcie2_devinfo
block|{
name|struct
name|resource_list
name|resources
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Generic PCIe-G2 bridge/end-point driver state.  *   * Must be first member of all subclass softc structures.  */
end_comment

begin_struct
struct|struct
name|bhnd_pcie2_softc
block|{
name|device_t
name|dev
decl_stmt|;
comment|/**< pci device */
name|uint32_t
name|quirks
decl_stmt|;
comment|/**< quirk flags */
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/**< state mutex used to protect 						     interdependent register 						     accesses. */
name|struct
name|bhnd_resource
modifier|*
name|mem_res
decl_stmt|;
comment|/**< device register block. */
name|int
name|mem_rid
decl_stmt|;
comment|/**< register block RID */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BHND_PCIE2_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_init(&(sc)->mtx, device_get_nameunit((sc)->dev), \ 	    "BHND PCIe-G2 driver lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
value|mtx_assert(&(sc)->mtx, what)
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->mtx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_PCIE2_BHND_PCIE2_VAR_H_ */
end_comment

end_unit

