begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_PMU_BHND_PMUVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_PMU_BHND_PMUVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_pmu.h"
end_include

begin_struct_decl
struct_decl|struct
name|bhnd_pmu_query
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bhnd_pmu_io
struct_decl|;
end_struct_decl

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|bhnd_pmu_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|bhnd_pmu_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|bhnd_pmu_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pmu_attach
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|bhnd_resource
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pmu_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pmu_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pmu_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pmu_query_init
parameter_list|(
name|struct
name|bhnd_pmu_query
modifier|*
name|query
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|struct
name|bhnd_chipid
name|id
parameter_list|,
specifier|const
name|struct
name|bhnd_pmu_io
modifier|*
name|io
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_pmu_query_fini
parameter_list|(
name|struct
name|bhnd_pmu_query
modifier|*
name|query
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_pmu_si_clock
parameter_list|(
name|struct
name|bhnd_pmu_query
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_pmu_cpu_clock
parameter_list|(
name|struct
name|bhnd_pmu_query
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_pmu_mem_clock
parameter_list|(
name|struct
name|bhnd_pmu_query
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_pmu_alp_clock
parameter_list|(
name|struct
name|bhnd_pmu_query
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_pmu_ilp_clock
parameter_list|(
name|struct
name|bhnd_pmu_query
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * PMU read-only query support.  *   * Provides support for querying PMU information prior to availability of  * the bhnd(4) bus.  */
end_comment

begin_struct
struct|struct
name|bhnd_pmu_query
block|{
name|device_t
name|dev
decl_stmt|;
comment|/**< owning device, or NULL */
name|struct
name|bhnd_chipid
name|cid
decl_stmt|;
comment|/**< chip identification */
name|uint32_t
name|caps
decl_stmt|;
comment|/**< pmu capability flags. */
specifier|const
name|struct
name|bhnd_pmu_io
modifier|*
name|io
decl_stmt|;
comment|/**< I/O operations */
name|void
modifier|*
name|io_ctx
decl_stmt|;
comment|/**< I/O callback context */
name|uint32_t
name|ilp_cps
decl_stmt|;
comment|/**< measured ILP cycles per second, or 0 */
block|}
struct|;
end_struct

begin_comment
comment|/**  * PMU abstract I/O operations.  */
end_comment

begin_struct
struct|struct
name|bhnd_pmu_io
block|{
comment|/* Read 4 bytes from PMU @p reg */
name|uint32_t
function_decl|(
modifier|*
name|rd4
function_decl|)
parameter_list|(
name|bus_size_t
name|reg
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/* Read 4 bytes to PMU @p reg */
name|void
function_decl|(
modifier|*
name|wr4
function_decl|)
parameter_list|(
name|bus_size_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/* Read ChipCommon's CHIP_ST register */
name|uint32_t
function_decl|(
modifier|*
name|rd_chipst
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * bhnd_pmu driver instance state.  */
end_comment

begin_struct
struct|struct
name|bhnd_pmu_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|uint32_t
name|caps
decl_stmt|;
comment|/**< pmu capability flags. */
name|struct
name|bhnd_chipid
name|cid
decl_stmt|;
comment|/**< chip identification */
name|struct
name|bhnd_pmu_query
name|query
decl_stmt|;
comment|/**< query instance */
name|struct
name|bhnd_board_info
name|board
decl_stmt|;
comment|/**< board identification */
name|device_t
name|chipc_dev
decl_stmt|;
comment|/**< chipcommon device */
name|struct
name|bhnd_resource
modifier|*
name|res
decl_stmt|;
comment|/**< pmu register block. */
name|int
name|rid
decl_stmt|;
comment|/**< pmu register RID */
name|struct
name|bhnd_core_clkctl
modifier|*
name|clkctl
decl_stmt|;
comment|/**< pmu clkctl register */
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/**< state mutex */
comment|/* For compatibility with bhnd_pmu_query APIs and the shared 	 * BHND_PMU_(READ|WRITE) macros. */
specifier|const
name|struct
name|bhnd_pmu_io
modifier|*
name|io
decl_stmt|;
name|void
modifier|*
name|io_ctx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BPMU_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_init(&(sc)->mtx, device_get_nameunit((sc)->dev), NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BPMU_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BPMU_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BPMU_LOCK_ASSERT
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
name|BPMU_LOCK_DESTROY
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
comment|/* _BHND_CORES_PMU_BHND_PMUVAR_H_ */
end_comment

end_unit

