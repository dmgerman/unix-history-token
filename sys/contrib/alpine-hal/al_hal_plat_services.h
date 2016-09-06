begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_services Platform Services API  *  @{  * The Platform Services API provides miscellaneous system services to HAL  * drivers, such as:  * - Registers read/write  * - Assertions  * - Memory barriers  * - Endianness conversions  *  * And more.  * @file   plat_api/sample/al_hal_plat_services.h  *  * @brief  API for Platform services provided for to HAL drivers  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PLAT_SERVICES_H__
end_ifndef

begin_define
define|#
directive|define
name|__PLAT_SERVICES_H__
end_define

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
comment|/* Prototypes for all the bus_space structure functions */
end_comment

begin_function_decl
name|uint8_t
name|generic_bs_r_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|generic_bs_r_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|generic_bs_r_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generic_bs_w_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint8_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generic_bs_w_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint16_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generic_bs_w_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generic_bs_w_8
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint64_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|__UNUSED
value|__attribute__((unused))
end_define

begin_comment
comment|/* *INDENT-OFF* */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* *INDENT-ON* */
comment|/**   * Make sure data will be visible by other masters (other CPUS and DMA).   * usually this is achieved by the ARM DMB instruction.   */
specifier|static
name|void
name|al_data_memory_barrier
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|void
name|al_smp_data_memory_barrier
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**   * Make sure data will be visible by DMA masters, no restriction for other cpus   */
specifier|static
specifier|inline
name|void
name|al_data_memory_barrier
parameter_list|(
name|void
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|__aarch64__
name|dsb
argument_list|()
expr_stmt|;
else|#
directive|else
name|dsb
argument_list|(
name|sy
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/**   * Make sure data will be visible in order by other cpus masters.   */
specifier|static
specifier|inline
name|void
name|al_smp_data_memory_barrier
parameter_list|(
name|void
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|__aarch64__
name|dmb
argument_list|()
expr_stmt|;
else|#
directive|else
name|dmb
argument_list|(
name|ish
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/**   * Make sure write data will be visible in order by other cpus masters.   */
specifier|static
specifier|inline
name|void
name|al_local_data_memory_barrier
parameter_list|(
name|void
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|__aarch64__
name|dsb
argument_list|()
expr_stmt|;
else|#
directive|else
name|dsb
argument_list|(
name|sy
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/*  * WMA: This is a hack which allows not modifying the __iomem accessing HAL code.  * On ARMv7, bus_handle holds the information about VA of accessed memory. It  * is possible to use direct load/store instruction instead of bus_dma machinery.  * WARNING: This is not guaranteed to stay that way forever, nor that  * on other architectures these variables behave similarly. Keep that  * in mind during porting to other systems.  */
comment|/**  * Read MMIO 8 bits register  * @param  offset	register offset  *  * @return register value  */
specifier|static
name|uint8_t
name|al_reg_read8
parameter_list|(
name|uint8_t
modifier|*
name|offset
parameter_list|)
function_decl|;
comment|/**  * Read MMIO 16 bits register  * @param  offset	register offset  *  * @return register value  */
specifier|static
name|uint16_t
name|al_reg_read16
parameter_list|(
name|uint16_t
modifier|*
name|offset
parameter_list|)
function_decl|;
comment|/**  * Read MMIO 32 bits register  * @param  offset	register offset  *  * @return register value  */
specifier|static
name|uint32_t
name|al_reg_read32
parameter_list|(
name|uint32_t
modifier|*
name|offset
parameter_list|)
function_decl|;
comment|/**  * Read MMIO 64 bits register  * @param  offset	register offset  *  * @return register value  */
name|uint64_t
name|al_reg_read64
parameter_list|(
name|uint64_t
modifier|*
name|offset
parameter_list|)
function_decl|;
comment|/**  * Relaxed read MMIO 32 bits register  *  * Relaxed register read/write functions don't involve cpu instructions that  * force syncronization, nor ordering between the register access and memory  * data access.  * These instructions are used in performance critical code to avoid the  * overhead of the synchronization instructions.  *  * @param  offset	register offset  *  * @return register value  */
define|#
directive|define
name|al_bus_dma_to_va
parameter_list|(
name|bus_tag
parameter_list|,
name|bus_handle
parameter_list|)
value|((void*)bus_handle)
comment|/**  * Relaxed read MMIO 32 bits register  *  * Relaxed register read/write functions don't involve cpu instructions that  * force syncronization, nor ordering between the register access and memory  * data access.  * These instructions are used in performance critical code to avoid the  * overhead of the synchronization instructions.  *  * @param  offset	register offset  *  * @return register value  */
define|#
directive|define
name|al_reg_read32_relaxed
parameter_list|(
name|l
parameter_list|)
value|generic_bs_r_4(NULL, (bus_space_handle_t)l, 0)
comment|/**  * Relaxed write to MMIO 32 bits register  *  * Relaxed register read/write functions don't involve cpu instructions that  * force syncronization, nor ordering between the register access and memory  * data access.  * These instructions are used in performance critical code to avoid the  * overhead of the synchronization instructions.  *  * @param  offset	register offset  * @param  val		value to write to the register  */
define|#
directive|define
name|al_reg_write32_relaxed
parameter_list|(
name|l
parameter_list|,
name|v
parameter_list|)
value|generic_bs_w_4(NULL, (bus_space_handle_t)l, 0, v)
comment|/**  * Write to MMIO 8 bits register  * @param  offset	register offset  * @param  val		value to write to the register  */
define|#
directive|define
name|al_reg_write8
parameter_list|(
name|l
parameter_list|,
name|v
parameter_list|)
value|do {				\ 	al_data_memory_barrier();				\ 	generic_bs_w_1(NULL, (bus_space_handle_t)l, 0, v);	\ 	al_smp_data_memory_barrier();				\ } while (0)
comment|/**  * Write to MMIO 16 bits register  * @param  offset	register offset  * @param  val		value to write to the register  */
define|#
directive|define
name|al_reg_write16
parameter_list|(
name|l
parameter_list|,
name|v
parameter_list|)
value|do {				\ 	al_data_memory_barrier();				\ 	generic_bs_w_2(NULL, (bus_space_handle_t)l, 0, v);	\ 	al_smp_data_memory_barrier();				\ } while (0)
comment|/**  * Write to MMIO 32 bits register  * @param  offset	register offset  * @param  val		value to write to the register  */
define|#
directive|define
name|al_reg_write32
parameter_list|(
name|l
parameter_list|,
name|v
parameter_list|)
value|do {				\ 	al_data_memory_barrier();				\ 	generic_bs_w_4(NULL, (bus_space_handle_t)l, 0, v);	\ 	al_smp_data_memory_barrier();				\ } while (0)
comment|/**  * Write to MMIO 64 bits register  * @param  offset	register offset  * @param  val		value to write to the register  */
define|#
directive|define
name|al_reg_write64
parameter_list|(
name|l
parameter_list|,
name|v
parameter_list|)
value|do {				\ 	al_data_memory_barrier();				\ 	generic_bs_w_8(NULL, (bus_space_handle_t)l, 0, v);	\ 	al_smp_data_memory_barrier();				\ } while (0)
specifier|static
specifier|inline
name|uint8_t
name|al_reg_read8
parameter_list|(
name|uint8_t
modifier|*
name|l
parameter_list|)
block|{
name|al_data_memory_barrier
argument_list|()
expr_stmt|;
return|return
operator|(
name|generic_bs_r_1
argument_list|(
name|NULL
argument_list|,
operator|(
name|bus_space_handle_t
operator|)
name|l
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
specifier|static
specifier|inline
name|uint16_t
name|al_reg_read16
parameter_list|(
name|uint16_t
modifier|*
name|l
parameter_list|)
block|{
name|al_data_memory_barrier
argument_list|()
expr_stmt|;
return|return
operator|(
name|generic_bs_r_2
argument_list|(
name|NULL
argument_list|,
operator|(
name|bus_space_handle_t
operator|)
name|l
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
specifier|static
specifier|inline
name|uint32_t
name|al_reg_read32
parameter_list|(
name|uint32_t
modifier|*
name|l
parameter_list|)
block|{
name|al_data_memory_barrier
argument_list|()
expr_stmt|;
return|return
operator|(
name|generic_bs_r_4
argument_list|(
name|NULL
argument_list|,
operator|(
name|bus_space_handle_t
operator|)
name|l
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
define|#
directive|define
name|AL_DBG_LEVEL_NONE
value|0
define|#
directive|define
name|AL_DBG_LEVEL_ERR
value|1
define|#
directive|define
name|AL_DBG_LEVEL_WARN
value|2
define|#
directive|define
name|AL_DBG_LEVEL_INFO
value|3
define|#
directive|define
name|AL_DBG_LEVEL_DBG
value|4
define|#
directive|define
name|AL_DBG_LEVEL
value|AL_DBG_LEVEL_ERR
define|#
directive|define
name|AL_DBG_LOCK
parameter_list|()
define|#
directive|define
name|AL_DBG_UNLOCK
parameter_list|()
comment|/**  * print message  *  * @param format The format string  * @param ... Additional arguments  */
define|#
directive|define
name|al_print
parameter_list|(
name|type
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do { if (AL_DBG_LEVEL>= AL_DBG_LEVEL_NONE) { AL_DBG_LOCK(); printf(fmt, ##__VA_ARGS__); AL_DBG_UNLOCK(); } } while(0)
comment|/**  * print error message  *  * @param format  */
define|#
directive|define
name|al_err
parameter_list|(
modifier|...
parameter_list|)
value|do { if (AL_DBG_LEVEL>= AL_DBG_LEVEL_ERR) { AL_DBG_LOCK(); printf(__VA_ARGS__); AL_DBG_UNLOCK(); } } while(0)
comment|/**  * print warning message  *  * @param format  */
define|#
directive|define
name|al_warn
parameter_list|(
modifier|...
parameter_list|)
value|do { if (AL_DBG_LEVEL>= AL_DBG_LEVEL_WARN) { AL_DBG_LOCK(); printf(__VA_ARGS__); AL_DBG_UNLOCK(); } } while(0)
comment|/**  * print info message  *  * @param format  */
define|#
directive|define
name|al_info
parameter_list|(
modifier|...
parameter_list|)
value|do { if (AL_DBG_LEVEL>= AL_DBG_LEVEL_INFO) { AL_DBG_LOCK(); printf(__VA_ARGS__); AL_DBG_UNLOCK(); } } while(0)
comment|/**  * print debug message  *  * @param format  */
define|#
directive|define
name|al_dbg
parameter_list|(
modifier|...
parameter_list|)
value|do { if (AL_DBG_LEVEL>= AL_DBG_LEVEL_DBG) { AL_DBG_LOCK(); printf(__VA_ARGS__); AL_DBG_UNLOCK(); } } while(0)
comment|/**  * Assertion  *  * @param condition  */
define|#
directive|define
name|al_assert
parameter_list|(
name|COND
parameter_list|)
define|\
value|do {			\ 		if (!(COND))	\ 			al_err(	\ 			"%s:%d:%s: Assertion failed! (%s)\n",	\ 			__FILE__, __LINE__, __func__, #COND);	\ 	} while(AL_FALSE)
comment|/**  * al_udelay - micro sec delay  */
define|#
directive|define
name|al_udelay
parameter_list|(
name|u
parameter_list|)
value|DELAY(u)
comment|/**  * al_msleep - mili sec delay  */
define|#
directive|define
name|al_msleep
parameter_list|(
name|m
parameter_list|)
value|DELAY((m) * 1000)
comment|/**  * swap half word to little endian  *  * @param x 16 bit value  *  * @return the value in little endian  */
define|#
directive|define
name|swap16_to_le
parameter_list|(
name|x
parameter_list|)
value|htole16(x)
comment|/**  * swap word to little endian  *  * @param x 32 bit value  *  * @return the value in little endian  */
define|#
directive|define
name|swap32_to_le
parameter_list|(
name|x
parameter_list|)
value|htole32(x)
comment|/**  * swap 8 bytes to little endian  *  * @param x 64 bit value  *  * @return the value in little endian  */
define|#
directive|define
name|swap64_to_le
parameter_list|(
name|x
parameter_list|)
value|htole64(x)
comment|/**  * swap half word from little endian  *  * @param x 16 bit value  *  * @return the value in the cpu endianess  */
define|#
directive|define
name|swap16_from_le
parameter_list|(
name|x
parameter_list|)
value|le16toh(x)
comment|/**  * swap word from little endian  *  * @param x 32 bit value  *  * @return the value in the cpu endianess  */
define|#
directive|define
name|swap32_from_le
parameter_list|(
name|x
parameter_list|)
value|le32toh(x)
comment|/**  * swap 8 bytes from little endian  *  * @param x 64 bit value  *  * @return the value in the cpu endianess  */
define|#
directive|define
name|swap64_from_le
parameter_list|(
name|x
parameter_list|)
value|le64toh(x)
comment|/**  * Memory set  *  * @param p memory pointer  * @param val value for setting  * @param cnt number of bytes to set  */
define|#
directive|define
name|al_memset
parameter_list|(
name|p
parameter_list|,
name|val
parameter_list|,
name|cnt
parameter_list|)
value|memset(p, val, cnt)
comment|/**  * Memory copy  *  * @param p1 memory pointer  * @param p2 memory pointer  * @param cnt number of bytes to copy  */
define|#
directive|define
name|al_memcpy
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|,
name|cnt
parameter_list|)
value|memcpy(p1, p2, cnt)
comment|/**  * Memory compare  *  * @param p1 memory pointer  * @param p2 memory pointer  * @param cnt number of bytes to compare  */
define|#
directive|define
name|al_memcmp
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|,
name|cnt
parameter_list|)
value|memcmp(p1, p2, cnt)
comment|/**  * String compare  *  * @param s1 string pointer  * @param s2 string pointer  */
define|#
directive|define
name|al_strcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|strcmp(s1, s2)
define|#
directive|define
name|al_get_cpu_id
parameter_list|()
value|0
comment|/* *INDENT-OFF* */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *INDENT-ON* */
end_comment

begin_comment
comment|/** @} end of Platform Services API group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PLAT_SERVICES_H__ */
end_comment

end_unit

