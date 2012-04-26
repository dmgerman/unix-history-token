begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Interface to debug exception handler  *  *<hr>$Revision:  $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_DEBUG_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_DEBUG_H__
end_define

begin_include
include|#
directive|include
file|"cvmx-core.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-spinlock.h"
end_include

begin_define
define|#
directive|define
name|CVMX_DEBUG_MAX_REQUEST_SIZE
value|1024 + 34
end_define

begin_comment
comment|/* Enough room for setting memory of 512 bytes. */
end_comment

begin_define
define|#
directive|define
name|CVMX_DEBUG_MAX_RESPONSE_SIZE
value|1024 + 5
end_define

begin_define
define|#
directive|define
name|CVMX_DEBUG_GLOBALS_BLOCK_NAME
value|"cvmx-debug-globals"
end_define

begin_define
define|#
directive|define
name|CVMX_DEBUG_GLOBALS_VERSION
value|3
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
name|void
name|cvmx_debug_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|cvmx_debug_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|cvmx_debug_trigger_exception
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_TOOLCHAIN
specifier|extern
name|int
name|__octeon_debug_booted
decl_stmt|;
specifier|static
specifier|inline
name|int
name|cvmx_debug_booted
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|__octeon_debug_booted
return|;
block|}
else|#
directive|else
specifier|static
specifier|inline
name|int
name|cvmx_debug_booted
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|cvmx_sysinfo_get
argument_list|()
operator|->
name|bootloader_config_flags
operator|&
name|CVMX_BOOTINFO_CFG_FLAG_DEBUG
return|;
block|}
endif|#
directive|endif
comment|/* There are 64 TLB entries in CN5XXX and 32 TLB entries in CN3XXX and    128 TLB entries in CN6XXX. */
define|#
directive|define
name|CVMX_DEBUG_N_TLB_ENTRIES
value|128
comment|/* Maximium number of hardware breakpoints/watchpoints allowed */
define|#
directive|define
name|CVMX_DEBUG_MAX_OCTEON_HW_BREAKPOINTS
value|4
typedef|typedef
struct|struct
block|{
specifier|volatile
name|uint64_t
name|remote_controlled
decl_stmt|;
name|uint64_t
name|regs
index|[
literal|32
index|]
decl_stmt|;
name|uint64_t
name|lo
decl_stmt|;
name|uint64_t
name|hi
decl_stmt|;
define|#
directive|define
name|CVMX_DEBUG_BASIC_CONTEXT
define|\
value|F(remote_controlled);                       \     {   int i;                                  \         for (i = 0; i< 32; i++)                \             F(regs[i]);                         \     }                                           \     F(lo);                                      \     F(hi);
struct|struct
block|{
name|uint64_t
name|index
decl_stmt|;
name|uint64_t
name|entrylo
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|entryhi
decl_stmt|;
name|uint64_t
name|pagemask
decl_stmt|;
name|uint64_t
name|status
decl_stmt|;
name|uint64_t
name|badvaddr
decl_stmt|;
name|uint64_t
name|cause
decl_stmt|;
name|uint64_t
name|depc
decl_stmt|;
name|uint64_t
name|desave
decl_stmt|;
name|uint64_t
name|debug
decl_stmt|;
name|uint64_t
name|multicoredebug
decl_stmt|;
name|uint64_t
name|perfval
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|perfctrl
index|[
literal|2
index|]
decl_stmt|;
block|}
name|cop0
struct|;
define|#
directive|define
name|CVMX_DEBUG_COP0_CONTEXT
define|\
value|F(cop0.index);                              \     F(cop0.entrylo[0]);                         \     F(cop0.entrylo[1]);                         \     F(cop0.entryhi);                            \     F(cop0.pagemask);                           \     F(cop0.status);                             \     F(cop0.badvaddr);                           \     F(cop0.cause);                              \     F(cop0.depc);                               \     F(cop0.desave);                             \     F(cop0.debug);                              \     F(cop0.multicoredebug);                     \     F(cop0.perfval[0]);                         \     F(cop0.perfval[1]);                         \     F(cop0.perfctrl[0]);                        \     F(cop0.perfctrl[1]);
struct|struct
block|{
name|uint64_t
name|status
decl_stmt|;
name|uint64_t
name|address
index|[
literal|4
index|]
decl_stmt|;
name|uint64_t
name|address_mask
index|[
literal|4
index|]
decl_stmt|;
name|uint64_t
name|asid
index|[
literal|4
index|]
decl_stmt|;
name|uint64_t
name|control
index|[
literal|4
index|]
decl_stmt|;
block|}
name|hw_ibp
struct|,
name|hw_dbp
struct|;
comment|/* Hardware Instruction Break Point */
define|#
directive|define
name|CVMX_DEBUG_HW_IBP_CONTEXT
define|\
value|F(hw_ibp.status);				\     F(hw_ibp.address[0]);			\     F(hw_ibp.address[1]);			\     F(hw_ibp.address[2]);			\     F(hw_ibp.address[3]);			\     F(hw_ibp.address_mask[0]);			\     F(hw_ibp.address_mask[1]);			\     F(hw_ibp.address_mask[2]);			\     F(hw_ibp.address_mask[3]);			\     F(hw_ibp.asid[0]);				\     F(hw_ibp.asid[1]);				\     F(hw_ibp.asid[2]);				\     F(hw_ibp.asid[3]);				\     F(hw_ibp.control[0]);			\     F(hw_ibp.control[1]);			\     F(hw_ibp.control[2]);			\     F(hw_ibp.control[3]);
comment|/* Hardware Data Break Point */
define|#
directive|define
name|CVMX_DEBUG_HW_DBP_CONTEXT
define|\
value|F(hw_dbp.status);				\     F(hw_dbp.address[0]);			\     F(hw_dbp.address[1]);			\     F(hw_dbp.address[2]);			\     F(hw_dbp.address[3]);			\     F(hw_dbp.address_mask[0]);			\     F(hw_dbp.address_mask[1]);			\     F(hw_dbp.address_mask[2]);			\     F(hw_dbp.address_mask[3]);			\     F(hw_dbp.asid[0]);				\     F(hw_dbp.asid[1]);				\     F(hw_dbp.asid[2]);				\     F(hw_dbp.asid[3]);				\     F(hw_dbp.control[0]);			\     F(hw_dbp.control[1]);			\     F(hw_dbp.control[2]);			\     F(hw_dbp.control[3]);
struct|struct
name|cvmx_debug_tlb_t
block|{
name|uint64_t
name|entryhi
decl_stmt|;
name|uint64_t
name|pagemask
decl_stmt|;
name|uint64_t
name|entrylo
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|reserved
decl_stmt|;
block|}
name|tlbs
index|[
name|CVMX_DEBUG_N_TLB_ENTRIES
index|]
struct|;
define|#
directive|define
name|CVMX_DEBUG_TLB_CONTEXT
define|\
value|{   int i;                                          \         for (i = 0; i< CVMX_DEBUG_N_TLB_ENTRIES; i++)  \         {                                               \             F(tlbs[i].entryhi);                         \             F(tlbs[i].pagemask);                        \             F(tlbs[i].entrylo[0]);                      \             F(tlbs[i].entrylo[1]);                      \         }                                               \     }
block|}
name|cvmx_debug_core_context_t
typedef|;
typedef|typedef
name|struct
name|cvmx_debug_tlb_t
name|cvmx_debug_tlb_t
typedef|;
typedef|typedef
enum|enum
name|cvmx_debug_comm_type_e
block|{
name|COMM_UART
block|,
name|COMM_REMOTE
block|,
name|COMM_SIZE
block|}
name|cvmx_debug_comm_type_t
typedef|;
typedef|typedef
enum|enum
block|{
name|COMMAND_NOP
init|=
literal|0
block|,
comment|/**< Core doesn't need to do anything. Just stay in exception handler */
name|COMMAND_STEP
block|,
comment|/**< Core needs to perform a single instruction step */
name|COMMAND_CONTINUE
comment|/**< Core need to start running. Doesn't return until some debug event occurs */
block|}
name|cvmx_debug_command_t
typedef|;
comment|/* Every field in this struct has to be uint32_t. */
typedef|typedef
struct|struct
block|{
name|uint32_t
name|known_cores
decl_stmt|;
name|uint32_t
name|step_isr
decl_stmt|;
comment|/**< True if we are going to step into ISR's. */
name|uint32_t
name|focus_switch
decl_stmt|;
comment|/**< Focus can be switched. */
name|uint32_t
name|core_finished
decl_stmt|;
comment|/**< True if a core has finished and not been processed yet.  */
name|uint32_t
name|command
decl_stmt|;
comment|/**< Command for all cores (cvmx_debug_command_t) */
name|uint32_t
name|step_all
decl_stmt|;
comment|/**< True if step and continue should affect all cores. False, only the focus core is affected */
name|uint32_t
name|focus_core
decl_stmt|;
comment|/**< Core currently under control of the debugger */
name|uint32_t
name|active_cores
decl_stmt|;
comment|/**< Bitmask of cores that should stop on a breakpoint */
name|uint32_t
name|handler_cores
decl_stmt|;
comment|/**< Bitmask of cores currently running the exception handler */
name|uint32_t
name|ever_been_in_debug
decl_stmt|;
comment|/**< True if we have been ever been in the debugger stub at all.  */
block|}
name|__attribute__
typedef|((
name|aligned
typedef|(sizeof(
name|uint64_t
typedef|))))
name|cvmx_debug_state_t
typedef|;
typedef|typedef
name|int
name|cvmx_debug_state_t_should_fit_inside_a_cache_block
index|[
sizeof|sizeof
argument_list|(
name|cvmx_debug_state_t
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|cvmx_spinlock_t
argument_list|)
operator|+
literal|4
operator|*
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|>
literal|128
condition|?
operator|-
literal|1
else|:
literal|1
index|]
typedef|;
typedef|typedef
struct|struct
name|cvmx_debug_globals_s
block|{
name|uint64_t
name|version
decl_stmt|;
comment|/* This is always the first element of this struct */
name|uint64_t
name|comm_type
decl_stmt|;
comment|/* cvmx_debug_comm_type_t */
specifier|volatile
name|uint64_t
name|comm_changed
decl_stmt|;
comment|/* cvmx_debug_comm_type_t+1 when someone wants to change it. */
specifier|volatile
name|uint64_t
name|init_complete
decl_stmt|;
name|uint32_t
name|tlb_entries
decl_stmt|;
name|uint32_t
name|state
index|[
sizeof|sizeof
argument_list|(
name|cvmx_debug_state_t
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
index|]
decl_stmt|;
name|cvmx_spinlock_t
name|lock
decl_stmt|;
specifier|volatile
name|cvmx_debug_core_context_t
name|contextes
index|[
name|CVMX_MAX_CORES
index|]
decl_stmt|;
block|}
name|cvmx_debug_globals_t
typedef|;
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|rsrvd
range|:
literal|32
decl_stmt|;
comment|/**< Unused */
name|uint64_t
name|dbd
range|:
literal|1
decl_stmt|;
comment|/**< Indicates whether the last debug exception or                                     exception in Debug Mode occurred in a branch or                                     jump delay slot */
name|uint64_t
name|dm
range|:
literal|1
decl_stmt|;
comment|/**< Indicates that the processor is operating in Debug                                     Mode: */
name|uint64_t
name|nodcr
range|:
literal|1
decl_stmt|;
comment|/**< Indicates whether the dseg segment is present */
name|uint64_t
name|lsnm
range|:
literal|1
decl_stmt|;
comment|/**< Controls access of loads/stores between the dseg                                     segment and remaining memory when the dseg                                     segment is present */
name|uint64_t
name|doze
range|:
literal|1
decl_stmt|;
comment|/**< Indicates that the processor was in a low-power mode                                     when a debug exception occurred */
name|uint64_t
name|halt
range|:
literal|1
decl_stmt|;
comment|/**< Indicates that the internal processor system bus clock                                     was stopped when the debug exception occurred */
name|uint64_t
name|countdm
range|:
literal|1
decl_stmt|;
comment|/**< Controls or indicates the Count register behavior in                                     Debug Mode. Implementations can have fixed                                     behavior, in which case this bit is read-only (R), or                                     the implementation can allow this bit to control the                                     behavior, in which case this bit is read/write (R/W).                                     The reset value of this bit indicates the behavior after                                     reset, and depends on the implementation.                                     Encoding of the bit is:                                     - 0      Count register stopped in Debug Mode Count register is running in Debug                                     - 1      Mode                                     This bit is read-only (R) and reads as zero if not implemented. */
name|uint64_t
name|ibusep
range|:
literal|1
decl_stmt|;
comment|/**< Indicates if a Bus Error exception is pending from an                                     instruction fetch. Set when an instruction fetch bus                                     error event occurs or a 1 is written to the bit by                                     software. Cleared when a Bus Error exception on an                                     instruction fetch is taken by the processor. If IBusEP                                     is set when IEXI is cleared, a Bus Error exception on                                     an instruction fetch is taken by the processor, and                                     IBusEP is cleared.                                     In Debug Mode, a Bus Error exception applies to a                                     Debug Mode Bus Error exception.                                     This bit is read-only (R) and reads as zero if not                                     implemented. */
name|uint64_t
name|mcheckp
range|:
literal|1
decl_stmt|;
comment|/**< Indicates if a Machine Check exception is pending.                                     Set when a machine check event occurs or a 1 is                                     written to the bit by software. Cleared when a                                     Machine Check exception is taken by the processor.                                     If MCheckP is set when IEXI is cleared, a Machine                                     Check exception is taken by the processor, and                                     MCheckP is cleared.                                     In Debug Mode, a Machine Check exception applies                                     to a Debug Mode Machine Check exception.                                     This bit is read-only (R) and reads as zero if not                                     implemented. */
name|uint64_t
name|cacheep
range|:
literal|1
decl_stmt|;
comment|/**< Indicates if a Cache Error is pending. Set when a                                     cache error event occurs or a 1 is written to the bit by                                     software. Cleared when a Cache Error exception is                                     taken by the processor. If CacheEP is set when IEXI                                     is cleared, a Cache Error exception is taken by the                                     processor, and CacheEP is cleared.                                     In Debug Mode, a Cache Error exception applies to a                                     Debug Mode Cache Error exception.                                     This bit is read-only (R) and reads as zero if not                                     implemented. */
name|uint64_t
name|dbusep
range|:
literal|1
decl_stmt|;
comment|/**< Indicates if a Data Access Bus Error exception is                                     pending. Set when a data access bus error event                                     occurs or a 1 is written to the bit by software. Cleared                                     when a Bus Error exception on data access is taken by                                     the processor. If DBusEP is set when IEXI is cleared,                                     a Bus Error exception on data access is taken by the                                     processor, and DBusEP is cleared.                                     In Debug Mode, a Bus Error exception applies to a                                     Debug Mode Bus Error exception.                                     This bit is read-only (R) and reads as zero if not                                     implemented. */
name|uint64_t
name|iexi
range|:
literal|1
decl_stmt|;
comment|/**< An Imprecise Error eXception Inhibit (IEXI) controls                                     exceptions taken due to imprecise error indications.                                     Set when the processor takes a debug exception or an                                     exception in Debug Mode occurs. Cleared by                                     execution of the DERET instruction. Otherwise                                     modifiable by Debug Mode software.                                     When IEXI is set, then the imprecise error exceptions                                     from bus errors on instruction fetches or data                                     accesses, cache errors, or machine checks are                                     inhibited and deferred until the bit is cleared.                                     This bit is read-only (R) and reads as zero if not                                     implemented. */
name|uint64_t
name|ddbsimpr
range|:
literal|1
decl_stmt|;
comment|/**< Indicates that a Debug Data Break Store Imprecise                                     exception due to a store was the cause of the debug                                     exception, or that an imprecise data hardware break                                     due to a store was indicated after another debug                                     exception occurred. Cleared on exception in Debug                                     Mode.                                         - 0 No match of an imprecise data hardware breakpoint on store                                         - 1 Match of imprecise data hardware breakpoint on store                                     This bit is read-only (R) and reads as zero if not                                     implemented. */
name|uint64_t
name|ddblimpr
range|:
literal|1
decl_stmt|;
comment|/**< Indicates that a Debug Data Break Load Imprecise                                     exception due to a load was the cause of the debug                                     exception, or that an imprecise data hardware break                                     due to a load was indicated after another debug                                     exception occurred. Cleared on exception in Debug                                     Mode.                                         - 0 No match of an imprecise data hardware breakpoint on load                                         - 1 Match of imprecise data hardware breakpoint on load                                     This bit is read-only (R) and reads as zero if not                                     implemented. */
name|uint64_t
name|ejtagver
range|:
literal|3
decl_stmt|;
comment|/**< Provides the EJTAG version.                                         - 0      Version 1 and 2.0                                         - 1      Version 2.5                                         - 2      Version 2.6                                         - 3-7    Reserved */
name|uint64_t
name|dexccode
range|:
literal|5
decl_stmt|;
comment|/**< Indicates the cause of the latest exception in Debug                                     Mode.                                     The field is encoded as the ExcCode field in the                                     Cause register for those exceptions that can occur in                                     Debug Mode (the encoding is shown in MIPS32 and                                     MIPS64 specifications), with addition of code 30                                     with the mnemonic CacheErr for cache errors and the                                     use of code 9 with mnemonic Bp for the SDBBP                                     instruction.                                     This value is undefined after a debug exception. */
name|uint64_t
name|nosst
range|:
literal|1
decl_stmt|;
comment|/**< Indicates whether the single-step feature controllable                                     by the SSt bit is available in this implementation:                                           - 0      Single-step feature available                                           - 1      No single-step feature available                                     A minimum number of hardware instruction                                     breakpoints must be available if no single-step                                     feature is implemented in hardware. Refer to Section                                     4.8.1 on page 69 for more information. */
name|uint64_t
name|sst
range|:
literal|1
decl_stmt|;
comment|/**< Controls whether single-step feature is enabled:                                           - 0       No enable of single-step feature                                           - 1       Single-step feature enabled                                     This bit is read-only (R) and reads as zero if not                                     implemented due to no single-step feature (NoSSt is                                     1). */
name|uint64_t
name|rsrvd2
range|:
literal|2
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|dint
range|:
literal|1
decl_stmt|;
comment|/**< Indicates that a Debug Interrupt exception occurred.                                     Cleared on exception in Debug Mode.                                           - 0       No Debug Interrupt exception                                           - 1       Debug Interrupt exception                                     This bit is read-only (R) and reads as zero if not                                     implemented. */
name|uint64_t
name|dib
range|:
literal|1
decl_stmt|;
comment|/**< Indicates that a Debug Instruction Break exception                                     occurred. Cleared on exception in Debug Mode.                                           - 0       No Debug Instruction Break exception                                           - 1       Debug Instruction Break exception                                     This bit is read-only (R) and reads as zero if not                                     implemented. */
name|uint64_t
name|ddbs
range|:
literal|1
decl_stmt|;
comment|/**< Indicates that a Debug Data Break Store exception                                     occurred on a store due to a precise data hardware                                     break. Cleared on exception in Debug Mode.                                           - 0       No Debug Data Break Store Exception                                           - 1       Debug Data Break Store Exception                                     This bit is read-only (R) and reads as zero if not                                     implemented. */
name|uint64_t
name|ddbl
range|:
literal|1
decl_stmt|;
comment|/**< Indicates that a Debug Data Break Load exception                                     occurred on a load due to a precise data hardware                                     break. Cleared on exception in Debug Mode.                                           - 0       No Debug Data Break Store Exception                                           - 1       Debug Data Break Store Exception                                     This bit is read-only (R) and reads as zero if not                                     implemented. */
name|uint64_t
name|dbp
range|:
literal|1
decl_stmt|;
comment|/**< Indicates that a Debug Breakpoint exception                                     occurred. Cleared on exception in Debug Mode.                                           - 0      No Debug Breakpoint exception                                           - 1      Debug Breakpoint exception */
name|uint64_t
name|dss
range|:
literal|1
decl_stmt|;
comment|/**< Indicates that a Debug Single Step exception                                     occurred. Cleared on exception in Debug Mode.                                           - 0       No debug single-step exception                                           - 1       Debug single-step exception                                     This bit is read-only (R) and reads as zero if not                                     implemented. */
block|}
name|s
struct|;
block|}
name|cvmx_debug_register_t
typedef|;
typedef|typedef
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|install_break_handler
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|needs_proxy
decl_stmt|;
name|int
function_decl|(
modifier|*
name|getpacket
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|putpacket
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|wait_for_resume
function_decl|)
parameter_list|(
specifier|volatile
name|cvmx_debug_core_context_t
modifier|*
parameter_list|,
name|cvmx_debug_state_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|change_core
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
name|cvmx_debug_comm_t
typedef|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_DEBUG_H__ */
end_comment

end_unit

