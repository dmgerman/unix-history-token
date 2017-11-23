begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Landon Fuller<landonf@FreeBSD.org>  * Copyright (C) 2010, Broadcom Corporation.  * All rights reserved.  *  * This file is derived from the hndpmu.h header contributed by Broadcom   * to to the Linux staging repository, as well as later revisions of hndpmu.h  * distributed with the Asus RT-N16 firmware source code release.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_PMU_BHND_PMU_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_PMU_BHND_PMU_PRIVATE_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_pmuvar.h"
end_include

begin_comment
comment|/* Register I/O */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_READ_4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|)
value|(_sc)->io->rd4((_reg), (_sc)->io_ctx)
end_define

begin_define
define|#
directive|define
name|BHND_PMU_WRITE_4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|(_sc)->io->wr4((_reg), (_val), (_sc)->io_ctx)
end_define

begin_define
define|#
directive|define
name|BHND_PMU_AND_4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|BHND_PMU_WRITE_4((_sc), (_reg),		\ 	    BHND_PMU_READ_4((_sc), (_reg))& (_val))
end_define

begin_define
define|#
directive|define
name|BHND_PMU_OR_4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|BHND_PMU_WRITE_4((_sc), (_reg),		\ 	    BHND_PMU_READ_4((_sc), (_reg)) | (_val))
end_define

begin_comment
comment|/* Indirect register support */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_IND_READ
parameter_list|(
name|_sc
parameter_list|,
name|_src
parameter_list|,
name|_reg
parameter_list|)
define|\
value|bhnd_pmu_ind_read((_sc)->io, (_sc)->io_ctx,		\ 	    BHND_PMU_ ## _src ## _ADDR, BHND_PMU_ ## _src ## _DATA, (_reg))
end_define

begin_define
define|#
directive|define
name|BHND_PMU_IND_WRITE
parameter_list|(
name|_sc
parameter_list|,
name|_src
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|,
name|_mask
parameter_list|)
define|\
value|bhnd_pmu_ind_write((_sc)->io, (_sc)->io_ctx,		\ 	    BHND_PMU_ ## _src ## _ADDR,				\ 	    BHND_PMU_ ## _src ## _DATA, (_reg), (_val), (_mask))
end_define

begin_comment
comment|/* Chip Control indirect registers */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL_READ
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|)
define|\
value|BHND_PMU_IND_READ((_sc), CHIP_CONTROL, (_reg))
end_define

begin_define
define|#
directive|define
name|BHND_PMU_CCTRL_WRITE
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|,
name|_mask
parameter_list|)
define|\
value|BHND_PMU_IND_WRITE((_sc), CHIP_CONTROL, (_reg), (_val), (_mask))
end_define

begin_comment
comment|/* Regulator Control indirect registers */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_REGCTRL_READ
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|)
define|\
value|BHND_PMU_IND_READ((_sc), REG_CONTROL, (_reg))
end_define

begin_define
define|#
directive|define
name|BHND_PMU_REGCTRL_WRITE
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|,
name|_mask
parameter_list|)
define|\
value|BHND_PMU_IND_WRITE((_sc), REG_CONTROL, (_reg), (_val), (_mask))
end_define

begin_comment
comment|/* PLL Control indirect registers */
end_comment

begin_define
define|#
directive|define
name|BHND_PMU_PLL_READ
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|)
define|\
value|BHND_PMU_IND_READ((_sc), PLL_CONTROL, (_reg))
end_define

begin_define
define|#
directive|define
name|BHND_PMU_PLL_WRITE
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|,
name|_mask
parameter_list|)
define|\
value|BHND_PMU_IND_WRITE((_sc), PLL_CONTROL, (_reg), (_val), (_mask))
end_define

begin_comment
comment|/** FVCO frequencies, in Hz */
end_comment

begin_enum
enum|enum
block|{
name|FVCO_880
init|=
literal|880
operator|*
literal|1000
block|,
comment|/**< 880MHz */
name|FVCO_1760
init|=
literal|1760
operator|*
literal|1000
block|,
comment|/**< 1760MHz */
name|FVCO_1440
init|=
literal|1440
operator|*
literal|1000
block|,
comment|/**< 1440MHz */
name|FVCO_960
init|=
literal|960
operator|*
literal|1000
block|,
comment|/**< 960MHz */
block|}
enum|;
end_enum

begin_comment
comment|/** LDO voltage tunables */
end_comment

begin_enum
enum|enum
block|{
name|SET_LDO_VOLTAGE_LDO1
init|=
literal|1
block|,
name|SET_LDO_VOLTAGE_LDO2
init|=
literal|2
block|,
name|SET_LDO_VOLTAGE_LDO3
init|=
literal|3
block|,
name|SET_LDO_VOLTAGE_PAREF
init|=
literal|4
block|,
name|SET_LDO_VOLTAGE_CLDO_PWM
init|=
literal|5
block|,
name|SET_LDO_VOLTAGE_CLDO_BURST
init|=
literal|6
block|,
name|SET_LDO_VOLTAGE_CBUCK_PWM
init|=
literal|7
block|,
name|SET_LDO_VOLTAGE_CBUCK_BURST
init|=
literal|8
block|,
name|SET_LDO_VOLTAGE_LNLDO1
init|=
literal|9
block|,
name|SET_LDO_VOLTAGE_LNLDO2_SEL
init|=
literal|10
block|, }
enum|;
end_enum

begin_function_decl
name|uint32_t
name|bhnd_pmu_ind_read
parameter_list|(
specifier|const
name|struct
name|bhnd_pmu_io
modifier|*
name|io
parameter_list|,
name|void
modifier|*
name|io_ctx
parameter_list|,
name|bus_size_t
name|addr
parameter_list|,
name|bus_size_t
name|data
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_pmu_ind_write
parameter_list|(
specifier|const
name|struct
name|bhnd_pmu_io
modifier|*
name|io
parameter_list|,
name|void
modifier|*
name|io_ctx
parameter_list|,
name|bus_size_t
name|addr
parameter_list|,
name|bus_size_t
name|data
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pmu_init
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_pmu_pll_init
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|xtalfreq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pmu_res_init
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_pmu_swreg_init
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_pmu_force_ilp
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|,
name|bool
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_pmu_set_switcher_voltage
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|bb_voltage
parameter_list|,
name|uint8_t
name|rf_voltage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pmu_set_ldo_voltage
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|ldo
parameter_list|,
name|uint8_t
name|voltage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pmu_fast_pwrup_delay
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|,
name|u_int
modifier|*
name|pwrup_delay
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_pmu_rcal
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pmu_set_spuravoid
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|,
name|bhnd_pmu_spuravoid
name|spuravoid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_pmu_is_otp_powered
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_pmu_measure_alpclk
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pmu_radio_enable
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|,
name|device_t
name|d11core
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_pmu_waitforclk_on_backplane
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|clk
parameter_list|,
name|uint32_t
name|delay
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pmu_otp_power
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|,
name|bool
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_pmu_sdiod_drive_strength_init
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|drivestrength
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_pmu_paref_ldo_enable
parameter_list|(
name|struct
name|bhnd_pmu_softc
modifier|*
name|sc
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_PMU_BHND_PMU_PRIVATE_H_ */
end_comment

end_unit

