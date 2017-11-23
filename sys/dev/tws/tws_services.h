begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2010, LSI Corp.  * All rights reserved.  * Author : Manjunath Ranganathaiah  * Support: freebsdraid@lsi.com  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of the<ORGANIZATION> nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* #define TWS_DEBUG on */
end_comment

begin_function_decl
name|void
name|tws_trace
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
specifier|const
name|char
modifier|*
name|fun
parameter_list|,
name|int
name|linenum
parameter_list|,
name|struct
name|tws_softc
modifier|*
name|sc
parameter_list|,
name|char
modifier|*
name|desc
parameter_list|,
name|u_int64_t
name|val1
parameter_list|,
name|u_int64_t
name|val2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tws_log
parameter_list|(
name|struct
name|tws_softc
modifier|*
name|sc
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|tws_read_reg
parameter_list|(
name|struct
name|tws_softc
modifier|*
name|sc
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tws_write_reg
parameter_list|(
name|struct
name|tws_softc
modifier|*
name|sc
parameter_list|,
name|int
name|offset
parameter_list|,
name|u_int32_t
name|value
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|tws_swap16
parameter_list|(
name|u_int16_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|tws_swap32
parameter_list|(
name|u_int32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|tws_swap64
parameter_list|(
name|u_int64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tws_init_qs
parameter_list|(
name|struct
name|tws_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ----------------- trace ----------------- */
end_comment

begin_define
define|#
directive|define
name|TWS_TRACE_ON
value|on
end_define

begin_comment
comment|/* Alawys on - use wisely to trace errors */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TWS_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|TWS_TRACE_DEBUG_ON
value|on
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TWS_TRACE_DEBUG_ON
end_ifdef

begin_define
define|#
directive|define
name|TWS_TRACE_DEBUG
parameter_list|(
name|sc
parameter_list|,
name|desc
parameter_list|,
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|tws_trace(__FILE__, __func__, __LINE__, sc, desc, \                                    (u_int64_t)val1, (u_int64_t)val2)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TWS_TRACE_DEBUG
parameter_list|(
name|sc
parameter_list|,
name|desc
parameter_list|,
name|val1
parameter_list|,
name|val2
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TWS_TRACE_ON
end_ifdef

begin_define
define|#
directive|define
name|TWS_TRACE
parameter_list|(
name|sc
parameter_list|,
name|desc
parameter_list|,
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|tws_trace(__FILE__, __func__, __LINE__, sc, desc, \                                    (u_int64_t)val1, (u_int64_t)val2)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TWS_TRACE
parameter_list|(
name|sc
parameter_list|,
name|desc
parameter_list|,
name|val1
parameter_list|,
name|val2
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ---------------- logging ---------------- */
end_comment

begin_comment
comment|/* ---------------- logging ---------------- */
end_comment

begin_enum
enum|enum
name|error_index
block|{
name|SYSCTL_TREE_NODE_ADD
block|,
name|PCI_COMMAND_READ
block|,
name|ALLOC_MEMORY_RES
block|,
name|ALLOC_IRQ_RES
block|,
name|SETUP_INTR_RES
block|,
name|TWS_CAM_ATTACH
block|,
name|CAM_SIMQ_ALLOC
block|,
name|CAM_SIM_ALLOC
block|,
name|TWS_XPT_BUS_REGISTER
block|,
name|TWS_XPT_CREATE_PATH
block|,
name|TWS_BUS_SCAN_REQ
block|,
name|TWS_INIT_FAILURE
block|,
name|TWS_CTLR_INIT_FAILURE
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|severity
block|{
name|ERROR
init|=
literal|1
block|,
name|WARNING
block|,
name|INFO
block|,
if|#
directive|if
literal|0
block|DEBUG,
endif|#
directive|endif
block|}
enum|;
end_enum

begin_struct
struct|struct
name|error_desc
block|{
name|char
name|desc
index|[
literal|256
index|]
decl_stmt|;
name|u_int32_t
name|error_code
decl_stmt|;
name|int
name|severity_level
decl_stmt|;
name|char
modifier|*
name|fmt
decl_stmt|;
name|char
modifier|*
name|error_str
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ----------- q services ------------- */
end_comment

begin_define
define|#
directive|define
name|TWS_FREE_Q
value|0
end_define

begin_define
define|#
directive|define
name|TWS_PENDING_Q
value|1
end_define

begin_define
define|#
directive|define
name|TWS_BUSY_Q
value|2
end_define

begin_define
define|#
directive|define
name|TWS_COMPLETE_Q
value|3
end_define

begin_comment
comment|/* req return codes */
end_comment

begin_define
define|#
directive|define
name|TWS_REQ_RET_SUBMIT_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|TWS_REQ_RET_PEND_NOMFA
value|1
end_define

begin_define
define|#
directive|define
name|TWS_REQ_RET_RESET
value|2
end_define

begin_define
define|#
directive|define
name|TWS_REQ_RET_INVALID
value|0xdead
end_define

begin_comment
comment|/* ------------------------ */
end_comment

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|700000
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/clock.h>
end_include

begin_define
define|#
directive|define
name|TWS_LOCAL_TIME
value|(time_second - utc_offset())
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_define
define|#
directive|define
name|TWS_LOCAL_TIME
value|(time_second - (tz_minuteswest * 60) -   \                   (wall_cmos_clock ? adjkerntz : 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

