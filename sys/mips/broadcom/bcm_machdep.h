begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Landon Fuller<landonf@FreeBSD.org>  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Landon Fuller  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_BROADCOM_BCM_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_BROADCOM_BCM_MACHDEP_H_
end_define

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuregs.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd_eromvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/cores/pmu/bhnd_pmuvar.h>
end_include

begin_include
include|#
directive|include
file|"bcm_nvram_cfevar.h"
end_include

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|bhnd_pmu_io
name|bcm_pmu_soc_io
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|bcm_platform
block|{
name|struct
name|bhnd_chipid
name|cid
decl_stmt|;
comment|/**< chip id */
name|struct
name|bhnd_core_info
name|cc_id
decl_stmt|;
comment|/**< chipc core info */
name|uintptr_t
name|cc_addr
decl_stmt|;
comment|/**< chipc core phys address */
name|uint32_t
name|cc_caps
decl_stmt|;
comment|/**< chipc capabilities */
name|uint32_t
name|cc_caps_ext
decl_stmt|;
comment|/**< chipc extended capabilies */
name|struct
name|bhnd_core_info
name|cpu_id
decl_stmt|;
comment|/**< cpu core info */
name|uintptr_t
name|cpu_addr
decl_stmt|;
comment|/**< cpu core phys address */
comment|/* On non-AOB devices, the PMU register block is mapped to chipc; 	 * the pmu_id and pmu_addr values will be copied from cc_id 	 * and cc_addr. */
name|struct
name|bhnd_core_info
name|pmu_id
decl_stmt|;
comment|/**< PMU core info */
name|uintptr_t
name|pmu_addr
decl_stmt|;
comment|/**< PMU core phys address, or 							     0x0 if no PMU */
name|struct
name|bhnd_pmu_query
name|pmu
decl_stmt|;
comment|/**< PMU query instance */
name|bhnd_erom_class_t
modifier|*
name|erom_impl
decl_stmt|;
comment|/**< erom parser class */
name|struct
name|kobj_ops
name|erom_ops
decl_stmt|;
comment|/**< compiled kobj opcache */
name|struct
name|bhnd_erom_iobus
name|erom_io
decl_stmt|;
comment|/**< erom I/O callbacks */
union|union
block|{
name|bhnd_erom_static_t
name|data
decl_stmt|;
name|bhnd_erom_t
name|obj
decl_stmt|;
block|}
name|erom
union|;
name|struct
name|bhnd_nvram_io
modifier|*
name|nvram_io
decl_stmt|;
comment|/**< NVRAM I/O context, or NULL if unavailable */
name|bhnd_nvram_data_class
modifier|*
name|nvram_cls
decl_stmt|;
comment|/**< NVRAM data class, or NULL if unavailable */
name|struct
name|bhnd_service_registry
name|services
decl_stmt|;
comment|/**< platform service providers */
ifdef|#
directive|ifdef
name|CFE
name|int
name|cfe_console
decl_stmt|;
comment|/**< Console handle, or -1 */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|bcm_platform
modifier|*
name|bcm_get_platform
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|bcm_get_cpufreq
parameter_list|(
name|struct
name|bcm_platform
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|bcm_get_sifreq
parameter_list|(
name|struct
name|bcm_platform
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|bcm_get_alpfreq
parameter_list|(
name|struct
name|bcm_platform
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|bcm_get_ilpfreq
parameter_list|(
name|struct
name|bcm_platform
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|bcm_get_uart_rclk
parameter_list|(
name|struct
name|bcm_platform
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcm_get_nvram
parameter_list|(
name|struct
name|bcm_platform
modifier|*
name|bp
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|outp
parameter_list|,
name|size_t
modifier|*
name|olen
parameter_list|,
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BCM_ERR
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|printf("%s: " fmt, __FUNCTION__, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|BCM_SOC_BSH
parameter_list|(
name|_addr
parameter_list|,
name|_offset
parameter_list|)
define|\
value|((bus_space_handle_t)BCM_SOC_ADDR((_addr), (_offset)))
end_define

begin_define
define|#
directive|define
name|BCM_SOC_ADDR
parameter_list|(
name|_addr
parameter_list|,
name|_offset
parameter_list|)
define|\
value|MIPS_PHYS_TO_KSEG1((_addr) + (_offset))
end_define

begin_define
define|#
directive|define
name|BCM_SOC_READ_4
parameter_list|(
name|_addr
parameter_list|,
name|_offset
parameter_list|)
define|\
value|readl(BCM_SOC_ADDR((_addr), (_offset)))
end_define

begin_define
define|#
directive|define
name|BCM_SOC_WRITE_4
parameter_list|(
name|_addr
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|writel(BCM_SOC_ADDR((_addr), (_offset)), (_val))
end_define

begin_define
define|#
directive|define
name|BCM_CORE_ADDR
parameter_list|(
name|_bp
parameter_list|,
name|_name
parameter_list|,
name|_reg
parameter_list|)
define|\
value|BCM_SOC_ADDR(_bp->_name, (_reg))
end_define

begin_define
define|#
directive|define
name|BCM_CORE_READ_4
parameter_list|(
name|_bp
parameter_list|,
name|_name
parameter_list|,
name|_reg
parameter_list|)
define|\
value|readl(BCM_CORE_ADDR(_bp, _name, (_reg)))
end_define

begin_define
define|#
directive|define
name|BCM_CORE_WRITE_4
parameter_list|(
name|_bp
parameter_list|,
name|_name
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|writel(BCM_CORE_ADDR(_bp, _name, (_reg)), (_val))
end_define

begin_define
define|#
directive|define
name|BCM_CHIPC_READ_4
parameter_list|(
name|_bp
parameter_list|,
name|_reg
parameter_list|)
define|\
value|BCM_CORE_READ_4(_bp, cc_addr, (_reg))
end_define

begin_define
define|#
directive|define
name|BCM_CHIPC_WRITE_4
parameter_list|(
name|_bp
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|BCM_CORE_WRITE_4(_bp, cc_addr, (_reg), (_val))
end_define

begin_define
define|#
directive|define
name|BCM_CPU_READ_4
parameter_list|(
name|_bp
parameter_list|,
name|_reg
parameter_list|)
define|\
value|BCM_CORE_READ_4(_bp, cpu_addr, (_reg))
end_define

begin_define
define|#
directive|define
name|BCM_CPU_WRITE_4
parameter_list|(
name|_bp
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|BCM_CORE_WRITE_4(_bp, cpu_addr, (_reg), (_val))
end_define

begin_define
define|#
directive|define
name|BCM_PMU_READ_4
parameter_list|(
name|_bp
parameter_list|,
name|_reg
parameter_list|)
define|\
value|BCM_CORE_READ_4(_bp, pmu_addr, (_reg))
end_define

begin_define
define|#
directive|define
name|BCM_PMU_WRITE_4
parameter_list|(
name|_bp
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|BCM_CORE_WRITE_4(_bp, pmu_addr, (_reg), (_val))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_BROADCOM_BCM_MACHDEP_H_ */
end_comment

end_unit

