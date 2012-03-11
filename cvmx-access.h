begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  * Function prototypes for accessing memory and CSRs on Octeon.  *  *<hr>$Revision: 38306 $<hr> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_ACCESS_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_ACCESS_H__
end_define

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
comment|/* We're going to assume that if we are compiling for Mips then we must be     running natively on Octoen. It is possible that this code could be     compiled on a non Octeon Mips that is acting as a PCI/PCIe host. In this     case this assumption will be wrong and cause issues We can't key off of     __octeon__ since some people use stock gcc toolchains */
if|#
directive|if
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CVMX_BUILD_FOR_LINUX_HOST
argument_list|)
define|#
directive|define
name|CVMX_FUNCTION
value|static inline
else|#
directive|else
define|#
directive|define
name|CVMX_FUNCTION
value|extern
endif|#
directive|endif
comment|/**  * simprintf uses simulator tricks to speed up printouts.  The format  * and args are passed to the simulator and processed natively on the host.  * Simprintf is limited to 7 arguments, and they all must use %ll (long long)  * format specifiers to be displayed correctly.  *  * @param format  *  * @return  */
name|EXTERN_ASM
name|void
name|simprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|/**  * This function performs some default initialization of the Octeon executive.  * It initializes the cvmx_bootmem memory allocator with the list of physical  * memory provided by the bootloader, and creates 1-1 TLB mappings for this  * memory. This function should be called on all cores that will use either the  * bootmem allocator or the 1-1 TLB mappings. Applications which require a  * different configuration can replace this function with a suitable application  * specific one.  *  * @return 0 on success  *         -1 on failure  */
specifier|extern
name|int
name|cvmx_user_app_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Returns the Octeon processor ID.  *  * @return Octeon processor ID from COP0  */
name|CVMX_FUNCTION
name|uint32_t
name|cvmx_get_proc_id
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(pure
block|)
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Convert a memory pointer (void*) into a hardware compatable  * memory address (uint64_t). Octeon hardware widgets don't  * understand logical addresses.  *  * @param ptr    C style memory pointer  * @return Hardware physical address  */
end_comment

begin_function_decl
name|CVMX_FUNCTION
name|uint64_t
name|cvmx_ptr_to_phys
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert a hardware physical address (uint64_t) into a  * memory pointer (void *).  *  * @param physical_address  *               Hardware physical address to memory  * @return Pointer to memory  */
end_comment

begin_function_decl
name|CVMX_FUNCTION
name|void
modifier|*
name|cvmx_phys_to_ptr
parameter_list|(
name|uint64_t
name|physical_address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_write64_int64
parameter_list|(
name|uint64_t
name|address
parameter_list|,
name|int64_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_write64_uint64
parameter_list|(
name|uint64_t
name|address
parameter_list|,
name|uint64_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_write64_int32
parameter_list|(
name|uint64_t
name|address
parameter_list|,
name|int32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_write64_uint32
parameter_list|(
name|uint64_t
name|address
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_write64_int16
parameter_list|(
name|uint64_t
name|address
parameter_list|,
name|int16_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_write64_uint16
parameter_list|(
name|uint64_t
name|address
parameter_list|,
name|uint16_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_write64_int8
parameter_list|(
name|uint64_t
name|address
parameter_list|,
name|int8_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_write64_uint8
parameter_list|(
name|uint64_t
name|address
parameter_list|,
name|uint8_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_write_csr
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|,
name|uint64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_write_io
parameter_list|(
name|uint64_t
name|io_addr
parameter_list|,
name|uint64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|int64_t
name|cvmx_read64_int64
parameter_list|(
name|uint64_t
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|uint64_t
name|cvmx_read64_uint64
parameter_list|(
name|uint64_t
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|int32_t
name|cvmx_read64_int32
parameter_list|(
name|uint64_t
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|uint32_t
name|cvmx_read64_uint32
parameter_list|(
name|uint64_t
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|int16_t
name|cvmx_read64_int16
parameter_list|(
name|uint64_t
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|uint16_t
name|cvmx_read64_uint16
parameter_list|(
name|uint64_t
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|int8_t
name|cvmx_read64_int8
parameter_list|(
name|uint64_t
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|uint8_t
name|cvmx_read64_uint8
parameter_list|(
name|uint64_t
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|uint64_t
name|cvmx_read_csr
parameter_list|(
name|uint64_t
name|csr_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_send_single
parameter_list|(
name|uint64_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_read_csr_async
parameter_list|(
name|uint64_t
name|scraddr
parameter_list|,
name|uint64_t
name|csr_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Number of the Core on which the program is currently running.  *  * @return Number of cores  */
end_comment

begin_function_decl
name|CVMX_FUNCTION
name|unsigned
name|int
name|cvmx_get_core_num
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns the number of bits set in the provided value.  * Simple wrapper for POP instruction.  *  * @param val    32 bit value to count set bits in  *  * @return Number of bits set  */
end_comment

begin_function_decl
name|CVMX_FUNCTION
name|uint32_t
name|cvmx_pop
parameter_list|(
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns the number of bits set in the provided value.  * Simple wrapper for DPOP instruction.  *  * @param val    64 bit value to count set bits in  *  * @return Number of bits set  */
end_comment

begin_function_decl
name|CVMX_FUNCTION
name|int
name|cvmx_dpop
parameter_list|(
name|uint64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @deprecated  * Provide current cycle counter as a return value. Deprecated, use  * cvmx_clock_get_count(CVMX_CLOCK_CORE) to get cycle counter.  *  * @return current cycle counter  */
end_comment

begin_function_decl
name|CVMX_FUNCTION
name|uint64_t
name|cvmx_get_cycle
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @deprecated  * Reads a chip global cycle counter.  This counts SCLK cycles since  * chip reset.  The counter is 64 bit. This function is deprecated as the rate  * of the global cycle counter is different between Octeon+ and Octeon2, use  * cvmx_clock_get_count(CVMX_CLOCK_SCLK) instead. For Octeon2, the clock rate  * of SCLK may be differnet than the core clock.  *  * @return Global chip cycle count since chip reset.  */
end_comment

begin_function_decl
name|CVMX_FUNCTION
name|uint64_t
name|cvmx_get_cycle_global
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(deprecated
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Wait for the specified number of core clock cycles  *  * @param cycles  */
end_comment

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_wait
parameter_list|(
name|uint64_t
name|cycles
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Wait for the specified number of micro seconds  *  * @param usec   micro seconds to wait  */
end_comment

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_wait_usec
parameter_list|(
name|uint64_t
name|usec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Wait for the specified number of io clock cycles  *  * @param cycles  */
end_comment

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_wait_io
parameter_list|(
name|uint64_t
name|cycles
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Perform a soft reset of Octeon  *  * @return  */
end_comment

begin_function_decl
name|CVMX_FUNCTION
name|void
name|cvmx_reset_octeon
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read a byte of fuse data  * @param byte_addr   address to read  *  * @return fuse value: 0 or 1  */
end_comment

begin_function_decl
name|CVMX_FUNCTION
name|uint8_t
name|cvmx_fuse_read_byte
parameter_list|(
name|int
name|byte_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read a single fuse bit  *  * @param fuse   Fuse number (0-1024)  *  * @return fuse value: 0 or 1  */
end_comment

begin_function_decl
name|CVMX_FUNCTION
name|int
name|cvmx_fuse_read
parameter_list|(
name|int
name|fuse
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|CVMX_FUNCTION
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_ACCESS_H__ */
end_comment

end_unit

