begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_AT91_AT91_SMC_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_AT91_AT91_SMC_H
end_define

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|SMC_SETUP
value|0x00
end_define

begin_define
define|#
directive|define
name|SMC_PULSE
value|0x04
end_define

begin_define
define|#
directive|define
name|SMC_CYCLE
value|0x08
end_define

begin_define
define|#
directive|define
name|SMC_MODE
value|0x0C
end_define

begin_define
define|#
directive|define
name|SMC_CS_OFF
parameter_list|(
name|cs
parameter_list|)
value|(0x10 * (cs))
end_define

begin_comment
comment|/* Setup */
end_comment

begin_define
define|#
directive|define
name|SMC_SETUP_NCS_RD_SETUP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|SMC_SETUP_NRD_SETUP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|SMC_SETUP_NCS_WR_SETUP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|SMC_SETUP_NWE_SETUP
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/* Pulse */
end_comment

begin_define
define|#
directive|define
name|SMC_PULSE_NCS_RD_PULSE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|SMC_PULSE_NRD_PULSE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|SMC_PULSE_NCS_WR_PULSE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|SMC_PULSE_NWE_PULSE
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/* Cycle */
end_comment

begin_define
define|#
directive|define
name|SMC_CYCLE_NRD_CYCLE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|SMC_CYCLE_NWE_CYCLE
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/* Mode */
end_comment

begin_define
define|#
directive|define
name|SMC_MODE_READ
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SMC_MODE_WRITE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SMC_MODE_EXNW_DISABLED
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|SMC_MODE_EXNW_FROZEN_MODE
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|SMC_MODE_EXNW_READY_MODE
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|SMC_MODE_BAT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SMC_MODE_DBW_8BIT
value|(0<< 12)
end_define

begin_define
define|#
directive|define
name|SMC_MODE_DBW_16BIT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|SMC_MODE_DBW_32_BIT
value|(2<< 12)
end_define

begin_define
define|#
directive|define
name|SMC_MODE_TDF_CYCLES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|SMC_MODE_TDF_MODE
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|SMC_MODE_PMEN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|SMC_PS_4BYTE
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|SMC_PS_8BYTE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|SMC_PS_16BYTE
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|SMC_PS_32BYTE
value|(3<< 28)
end_define

begin_comment
comment|/*  * structure to ease init. See the SMC chapter in the datasheet for  * the appropriate SoC you are using for details.  */
end_comment

begin_struct
struct|struct
name|at91_smc_init
block|{
comment|/* Setup register */
name|uint8_t
name|ncs_rd_setup
decl_stmt|;
name|uint8_t
name|nrd_setup
decl_stmt|;
name|uint8_t
name|ncs_wr_setup
decl_stmt|;
name|uint8_t
name|nwe_setup
decl_stmt|;
comment|/* Pulse register */
name|uint8_t
name|ncs_rd_pulse
decl_stmt|;
name|uint8_t
name|nrd_pulse
decl_stmt|;
name|uint8_t
name|ncs_wr_pulse
decl_stmt|;
name|uint8_t
name|nwe_pulse
decl_stmt|;
comment|/* Cycle register */
name|uint16_t
name|nrd_cycle
decl_stmt|;
name|uint16_t
name|nwe_cycle
decl_stmt|;
comment|/* Mode register */
name|uint8_t
name|mode
decl_stmt|;
comment|/* Combo of READ/WRITE/EXNW fields */
name|uint8_t
name|bat
decl_stmt|;
name|uint8_t
name|dwb
decl_stmt|;
name|uint8_t
name|tdf_cycles
decl_stmt|;
name|uint8_t
name|tdf_mode
decl_stmt|;
name|uint8_t
name|pmen
decl_stmt|;
name|uint8_t
name|ps
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Convenience routine to fill in SMC registers for a given chip select.  */
end_comment

begin_function_decl
name|void
name|at91_smc_setup
parameter_list|(
name|int
name|id
parameter_list|,
name|int
name|cs
parameter_list|,
specifier|const
name|struct
name|at91_smc_init
modifier|*
name|smc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Disable/Enable different External Bus Interfaces (EBI)  */
end_comment

begin_function_decl
name|void
name|at91_ebi_enable
parameter_list|(
name|int
name|cs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at91_ebi_disable
parameter_list|(
name|int
name|cs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_AT91_AT91_SMC_H */
end_comment

end_unit

