begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
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
comment|/**  * @file  *  * cvmx-log supplies a fast log buffer implementation. Each core writes  * log data to a differnet buffer to avoid synchronization overhead. Function  * call logging can be turned on with the GCC option "-pg".  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<asm/octeon/cvmx-core.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"cvmx-core.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|cvmx_core_perf_t
name|counter1
parameter_list|,
name|cvmx_core_perf_t
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

