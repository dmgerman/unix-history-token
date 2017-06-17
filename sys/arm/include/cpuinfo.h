begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2014 Svatopluk Kraus<onwahe@gmail.com>  * Copyright 2014 Michal Meloun<meloun@miracle.cz>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPUINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPUINFO_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|CPU_IMPLEMENTER_ARM
value|0x41
end_define

begin_define
define|#
directive|define
name|CPU_IMPLEMENTER_QCOM
value|0x51
end_define

begin_define
define|#
directive|define
name|CPU_IMPLEMENTER_MRVL
value|0x56
end_define

begin_comment
comment|/* ARM */
end_comment

begin_define
define|#
directive|define
name|CPU_ARCH_ARM1176
value|0xB76
end_define

begin_define
define|#
directive|define
name|CPU_ARCH_CORTEX_A5
value|0xC05
end_define

begin_define
define|#
directive|define
name|CPU_ARCH_CORTEX_A7
value|0xC07
end_define

begin_define
define|#
directive|define
name|CPU_ARCH_CORTEX_A8
value|0xC08
end_define

begin_define
define|#
directive|define
name|CPU_ARCH_CORTEX_A9
value|0xC09
end_define

begin_define
define|#
directive|define
name|CPU_ARCH_CORTEX_A12
value|0xC0D
end_define

begin_define
define|#
directive|define
name|CPU_ARCH_CORTEX_A15
value|0xC0F
end_define

begin_define
define|#
directive|define
name|CPU_ARCH_CORTEX_A17
value|0xC11
end_define

begin_define
define|#
directive|define
name|CPU_ARCH_CORTEX_A53
value|0xD03
end_define

begin_define
define|#
directive|define
name|CPU_ARCH_CORTEX_A57
value|0xD07
end_define

begin_define
define|#
directive|define
name|CPU_ARCH_CORTEX_A72
value|0xD08
end_define

begin_define
define|#
directive|define
name|CPU_ARCH_CORTEX_A73
value|0xD09
end_define

begin_comment
comment|/* QCOM */
end_comment

begin_define
define|#
directive|define
name|CPU_ARCH_KRAIT_300
value|0x06F
end_define

begin_comment
comment|/* MRVL */
end_comment

begin_define
define|#
directive|define
name|CPU_ARCH_SHEEVA_581
value|0x581
end_define

begin_comment
comment|/* PJ4/PJ4B */
end_comment

begin_define
define|#
directive|define
name|CPU_ARCH_SHEEVA_584
value|0x584
end_define

begin_comment
comment|/* PJ4B-MP/PJ4C */
end_comment

begin_struct
struct|struct
name|cpuinfo
block|{
comment|/* raw id registers */
name|uint32_t
name|midr
decl_stmt|;
name|uint32_t
name|ctr
decl_stmt|;
name|uint32_t
name|tcmtr
decl_stmt|;
name|uint32_t
name|tlbtr
decl_stmt|;
name|uint32_t
name|mpidr
decl_stmt|;
name|uint32_t
name|revidr
decl_stmt|;
name|uint32_t
name|id_pfr0
decl_stmt|;
name|uint32_t
name|id_pfr1
decl_stmt|;
name|uint32_t
name|id_dfr0
decl_stmt|;
name|uint32_t
name|id_afr0
decl_stmt|;
name|uint32_t
name|id_mmfr0
decl_stmt|;
name|uint32_t
name|id_mmfr1
decl_stmt|;
name|uint32_t
name|id_mmfr2
decl_stmt|;
name|uint32_t
name|id_mmfr3
decl_stmt|;
name|uint32_t
name|id_isar0
decl_stmt|;
name|uint32_t
name|id_isar1
decl_stmt|;
name|uint32_t
name|id_isar2
decl_stmt|;
name|uint32_t
name|id_isar3
decl_stmt|;
name|uint32_t
name|id_isar4
decl_stmt|;
name|uint32_t
name|id_isar5
decl_stmt|;
name|uint32_t
name|cbar
decl_stmt|;
name|uint32_t
name|ccsidr
decl_stmt|;
name|uint32_t
name|clidr
decl_stmt|;
comment|/* Parsed bits of above registers... */
comment|/* midr */
name|int
name|implementer
decl_stmt|;
name|int
name|revision
decl_stmt|;
name|int
name|architecture
decl_stmt|;
name|int
name|part_number
decl_stmt|;
name|int
name|patch
decl_stmt|;
comment|/* id_mmfr0 */
name|int
name|outermost_shareability
decl_stmt|;
name|int
name|shareability_levels
decl_stmt|;
name|int
name|auxiliary_registers
decl_stmt|;
name|int
name|innermost_shareability
decl_stmt|;
comment|/* id_mmfr1 */
name|int
name|mem_barrier
decl_stmt|;
comment|/* id_mmfr3 */
name|int
name|coherent_walk
decl_stmt|;
name|int
name|maintenance_broadcast
decl_stmt|;
comment|/* id_pfr1 */
name|int
name|generic_timer_ext
decl_stmt|;
name|int
name|virtualization_ext
decl_stmt|;
name|int
name|security_ext
decl_stmt|;
comment|/* L1 cache info */
name|int
name|dcache_line_size
decl_stmt|;
name|int
name|dcache_line_mask
decl_stmt|;
name|int
name|icache_line_size
decl_stmt|;
name|int
name|icache_line_mask
decl_stmt|;
comment|/* mpidr */
name|int
name|mp_ext
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|cpuinfo
name|cpuinfo
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|cpuinfo_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_function_decl
name|void
name|cpuinfo_reinit_mmu
parameter_list|(
name|uint32_t
name|ttb
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_CPUINFO_H_ */
end_comment

end_unit

