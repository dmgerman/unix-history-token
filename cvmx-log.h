begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  *  Copyright (c) 2003-2008 Cavium Networks (support@cavium.com). All rights  *  reserved.  *  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions are  *  met:  *  *      * Redistributions of source code must retain the above copyright  *        notice, this list of conditions and the following disclaimer.  *  *      * Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials provided  *        with the distribution.  *  *      * Neither the name of Cavium Networks nor the names of  *        its contributors may be used to endorse or promote products  *        derived from this software without specific prior written  *        permission.  *  *  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  *  AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS  *  OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH  *  RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY  *  REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT  *  DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES  *  OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR  *  PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET  *  POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT  *  OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *  *  *  For any questions regarding licensing please contact marketing@caviumnetworks.com  *  ***********************license end**************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_LOG_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_LOG_H__
end_define

begin_comment
comment|/**  * @file  *  * cvmx-log supplies a fast log buffer implementation. Each core writes  * log data to a differnet buffer to avoid synchronization overhead. Function  * call logging can be turned on with the GCC option "-pg".  *  *<hr>$Revision: 41586 $<hr>  */
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
comment|/**  * Enumeration of all supported performance counter types  */
typedef|typedef
enum|enum
block|{
name|CVMX_LOG_PERF_CNT_NONE
init|=
literal|0
block|,
comment|/**< Turn off the performance counter */
name|CVMX_LOG_PERF_CNT_CLK
init|=
literal|1
block|,
comment|/**< Conditionally clocked cycles (as opposed to count/cvm_count which count even with no clocks) */
name|CVMX_LOG_PERF_CNT_ISSUE
init|=
literal|2
block|,
comment|/**< Instructions issued but not retired */
name|CVMX_LOG_PERF_CNT_RET
init|=
literal|3
block|,
comment|/**< Instructions retired */
name|CVMX_LOG_PERF_CNT_NISSUE
init|=
literal|4
block|,
comment|/**< Cycles no issue */
name|CVMX_LOG_PERF_CNT_SISSUE
init|=
literal|5
block|,
comment|/**< Cycles single issue */
name|CVMX_LOG_PERF_CNT_DISSUE
init|=
literal|6
block|,
comment|/**< Cycles dual issue */
name|CVMX_LOG_PERF_CNT_IFI
init|=
literal|7
block|,
comment|/**< Cycle ifetch issued (but not necessarily commit to pp_mem) */
name|CVMX_LOG_PERF_CNT_BR
init|=
literal|8
block|,
comment|/**< Branches retired */
name|CVMX_LOG_PERF_CNT_BRMIS
init|=
literal|9
block|,
comment|/**< Branch mispredicts */
name|CVMX_LOG_PERF_CNT_J
init|=
literal|10
block|,
comment|/**< Jumps retired */
name|CVMX_LOG_PERF_CNT_JMIS
init|=
literal|11
block|,
comment|/**< Jumps mispredicted */
name|CVMX_LOG_PERF_CNT_REPLAY
init|=
literal|12
block|,
comment|/**< Mem Replays */
name|CVMX_LOG_PERF_CNT_IUNA
init|=
literal|13
block|,
comment|/**< Cycles idle due to unaligned_replays */
name|CVMX_LOG_PERF_CNT_TRAP
init|=
literal|14
block|,
comment|/**< trap_6a signal */
name|CVMX_LOG_PERF_CNT_UULOAD
init|=
literal|16
block|,
comment|/**< Unexpected unaligned loads (REPUN=1) */
name|CVMX_LOG_PERF_CNT_UUSTORE
init|=
literal|17
block|,
comment|/**< Unexpected unaligned store (REPUN=1) */
name|CVMX_LOG_PERF_CNT_ULOAD
init|=
literal|18
block|,
comment|/**< Unaligned loads (REPUN=1 or USEUN=1) */
name|CVMX_LOG_PERF_CNT_USTORE
init|=
literal|19
block|,
comment|/**< Unaligned store (REPUN=1 or USEUN=1) */
name|CVMX_LOG_PERF_CNT_EC
init|=
literal|20
block|,
comment|/**< Exec clocks(must set CvmCtl[DISCE] for accurate timing) */
name|CVMX_LOG_PERF_CNT_MC
init|=
literal|21
block|,
comment|/**< Mul clocks(must set CvmCtl[DISCE] for accurate timing) */
name|CVMX_LOG_PERF_CNT_CC
init|=
literal|22
block|,
comment|/**< Crypto clocks(must set CvmCtl[DISCE] for accurate timing) */
name|CVMX_LOG_PERF_CNT_CSRC
init|=
literal|23
block|,
comment|/**< Issue_csr clocks(must set CvmCtl[DISCE] for accurate timing) */
name|CVMX_LOG_PERF_CNT_CFETCH
init|=
literal|24
block|,
comment|/**< Icache committed fetches (demand+prefetch) */
name|CVMX_LOG_PERF_CNT_CPREF
init|=
literal|25
block|,
comment|/**< Icache committed prefetches */
name|CVMX_LOG_PERF_CNT_ICA
init|=
literal|26
block|,
comment|/**< Icache aliases */
name|CVMX_LOG_PERF_CNT_II
init|=
literal|27
block|,
comment|/**< Icache invalidates */
name|CVMX_LOG_PERF_CNT_IP
init|=
literal|28
block|,
comment|/**< Icache parity error */
name|CVMX_LOG_PERF_CNT_CIMISS
init|=
literal|29
block|,
comment|/**< Cycles idle due to imiss (must set CvmCtl[DISCE] for accurate timing) */
name|CVMX_LOG_PERF_CNT_WBUF
init|=
literal|32
block|,
comment|/**< Number of write buffer entries created */
name|CVMX_LOG_PERF_CNT_WDAT
init|=
literal|33
block|,
comment|/**< Number of write buffer data cycles used (may need to set CvmCtl[DISCE] for accurate counts) */
name|CVMX_LOG_PERF_CNT_WBUFLD
init|=
literal|34
block|,
comment|/**< Number of write buffer entries forced out by loads */
name|CVMX_LOG_PERF_CNT_WBUFFL
init|=
literal|35
block|,
comment|/**< Number of cycles that there was no available write buffer entry (may need to set CvmCtl[DISCE] and CvmMemCtl[MCLK] for accurate counts) */
name|CVMX_LOG_PERF_CNT_WBUFTR
init|=
literal|36
block|,
comment|/**< Number of stores that found no available write buffer entries */
name|CVMX_LOG_PERF_CNT_BADD
init|=
literal|37
block|,
comment|/**< Number of address bus cycles used (may need to set CvmCtl[DISCE] for accurate counts) */
name|CVMX_LOG_PERF_CNT_BADDL2
init|=
literal|38
block|,
comment|/**< Number of address bus cycles not reflected (i.e. destined for L2) (may need to set CvmCtl[DISCE] for accurate counts) */
name|CVMX_LOG_PERF_CNT_BFILL
init|=
literal|39
block|,
comment|/**< Number of fill bus cycles used (may need to set CvmCtl[DISCE] for accurate counts) */
name|CVMX_LOG_PERF_CNT_DDIDS
init|=
literal|40
block|,
comment|/**< Number of Dstream DIDs created */
name|CVMX_LOG_PERF_CNT_IDIDS
init|=
literal|41
block|,
comment|/**< Number of Istream DIDs created */
name|CVMX_LOG_PERF_CNT_DIDNA
init|=
literal|42
block|,
comment|/**< Number of cycles that no DIDs were available (may need to set CvmCtl[DISCE] and CvmMemCtl[MCLK] for accurate counts) */
name|CVMX_LOG_PERF_CNT_LDS
init|=
literal|43
block|,
comment|/**< Number of load issues */
name|CVMX_LOG_PERF_CNT_LMLDS
init|=
literal|44
block|,
comment|/**< Number of local memory load */
name|CVMX_LOG_PERF_CNT_IOLDS
init|=
literal|45
block|,
comment|/**< Number of I/O load issues */
name|CVMX_LOG_PERF_CNT_DMLDS
init|=
literal|46
block|,
comment|/**< Number of loads that were not prefetches and missed in the cache */
name|CVMX_LOG_PERF_CNT_STS
init|=
literal|48
block|,
comment|/**< Number of store issues */
name|CVMX_LOG_PERF_CNT_LMSTS
init|=
literal|49
block|,
comment|/**< Number of local memory store issues */
name|CVMX_LOG_PERF_CNT_IOSTS
init|=
literal|50
block|,
comment|/**< Number of I/O store issues */
name|CVMX_LOG_PERF_CNT_IOBDMA
init|=
literal|51
block|,
comment|/**< Number of IOBDMAs */
name|CVMX_LOG_PERF_CNT_DTLB
init|=
literal|53
block|,
comment|/**< Number of dstream TLB refill, invalid, or modified exceptions */
name|CVMX_LOG_PERF_CNT_DTLBAD
init|=
literal|54
block|,
comment|/**< Number of dstream TLB address errors */
name|CVMX_LOG_PERF_CNT_ITLB
init|=
literal|55
block|,
comment|/**< Number of istream TLB refill, invalid, or address error exceptions */
name|CVMX_LOG_PERF_CNT_SYNC
init|=
literal|56
block|,
comment|/**< Number of SYNC stall cycles (may need to set CvmCtl[DISCE] for accurate counts) */
name|CVMX_LOG_PERF_CNT_SYNCIOB
init|=
literal|57
block|,
comment|/**< Number of SYNCIOBDMA stall cycles (may need to set CvmCtl[DISCE] for accurate counts) */
name|CVMX_LOG_PERF_CNT_SYNCW
init|=
literal|58
block|,
comment|/**< Number of SYNCWs */
block|}
name|cvmx_log_perf_event_t
typedef|;
comment|/**  * Structure of the performance counter control register  */
typedef|typedef
union|union
block|{
name|uint32_t
name|u32
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|M
range|:
literal|1
decl_stmt|;
name|uint32_t
name|W
range|:
literal|1
decl_stmt|;
name|uint32_t
name|reserved
range|:
literal|19
decl_stmt|;
name|cvmx_log_perf_event_t
name|event
range|:
literal|6
decl_stmt|;
name|uint32_t
name|IE
range|:
literal|1
decl_stmt|;
name|uint32_t
name|U
range|:
literal|1
decl_stmt|;
name|uint32_t
name|S
range|:
literal|1
decl_stmt|;
name|uint32_t
name|K
range|:
literal|1
decl_stmt|;
name|uint32_t
name|EX
range|:
literal|1
decl_stmt|;
block|}
name|s
struct|;
block|}
name|cvmx_log_perf_control_t
typedef|;
comment|/*  * Add CVMX_LOG_DISABLE_PC_LOGGING as an attribute to and function prototype  * that you don't want logged when the gcc option "-pg" is supplied. We  * use it on the cvmx-log functions since it is pointless to log the  * calling of a function than in itself writes to the log.  */
define|#
directive|define
name|CVMX_LOG_DISABLE_PC_LOGGING
value|__attribute__((no_instrument_function))
comment|/**  * Log a constant printf style format string with 0 to 4  * arguments. The string must persist until the log is read,  * but the parameters are copied into the log.  *  * @param format  Constant printf style format string.  * @param numberx 64bit argument to the printf format string  */
name|void
name|cvmx_log_printf0
argument_list|(
specifier|const
name|char
operator|*
name|format
argument_list|)
name|CVMX_LOG_DISABLE_PC_LOGGING
decl_stmt|;
name|void
name|cvmx_log_printf1
argument_list|(
specifier|const
name|char
operator|*
name|format
argument_list|,
name|uint64_t
name|number1
argument_list|)
name|CVMX_LOG_DISABLE_PC_LOGGING
decl_stmt|;
name|void
name|cvmx_log_printf2
argument_list|(
specifier|const
name|char
operator|*
name|format
argument_list|,
name|uint64_t
name|number1
argument_list|,
name|uint64_t
name|number2
argument_list|)
name|CVMX_LOG_DISABLE_PC_LOGGING
decl_stmt|;
name|void
name|cvmx_log_printf3
argument_list|(
specifier|const
name|char
operator|*
name|format
argument_list|,
name|uint64_t
name|number1
argument_list|,
name|uint64_t
name|number2
argument_list|,
name|uint64_t
name|number3
argument_list|)
name|CVMX_LOG_DISABLE_PC_LOGGING
decl_stmt|;
name|void
name|cvmx_log_printf4
argument_list|(
specifier|const
name|char
operator|*
name|format
argument_list|,
name|uint64_t
name|number1
argument_list|,
name|uint64_t
name|number2
argument_list|,
name|uint64_t
name|number3
argument_list|,
name|uint64_t
name|number4
argument_list|)
name|CVMX_LOG_DISABLE_PC_LOGGING
decl_stmt|;
comment|/**  * Log an arbitrary block of 64bit words. At most 255 64bit  * words can be logged. The words are copied into the log.  *  * @param size_in_dwords  *               Number of 64bit dwords to copy into the log.  * @param data   Array of 64bit dwords to copy  */
name|void
name|cvmx_log_data
argument_list|(
name|uint64_t
name|size_in_dwords
argument_list|,
specifier|const
name|uint64_t
operator|*
name|data
argument_list|)
name|CVMX_LOG_DISABLE_PC_LOGGING
decl_stmt|;
comment|/**  * Log a structured data object. Post processing will use the  * debugging information in the ELF file to determine how to  * display the structure. Max of 2032 bytes.  *  * Example:  * cvmx_log_structure("cvmx_wqe_t", work, sizeof(*work));  *  * @param type   C typedef expressed as a string. This will be used to  *               lookup the structure in the debugging infirmation.  * @param data   Data to be written to the log.  * @param size_in_bytes  *               Size if the data in bytes. Normally you'll use the  *               sizeof() operator here.  */
name|void
name|cvmx_log_structure
argument_list|(
specifier|const
name|char
operator|*
name|type
argument_list|,
name|void
operator|*
name|data
argument_list|,
name|int
name|size_in_bytes
argument_list|)
name|CVMX_LOG_DISABLE_PC_LOGGING
decl_stmt|;
comment|/**  * Setup the mips performance counters  *  * @param counter1 Event type for counter 1  * @param counter2 Event type for counter 2  */
name|void
name|cvmx_log_perf_setup
parameter_list|(
name|cvmx_log_perf_event_t
name|counter1
parameter_list|,
name|cvmx_log_perf_event_t
name|counter2
parameter_list|)
function_decl|;
comment|/**  * Log the performance counters  */
name|void
name|cvmx_log_perf
argument_list|(
name|void
argument_list|)
name|CVMX_LOG_DISABLE_PC_LOGGING
decl_stmt|;
comment|/**  * Display the current log in a human readable format.  */
name|void
name|cvmx_log_display
parameter_list|(
name|void
parameter_list|)
function_decl|;
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

end_unit

