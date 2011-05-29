begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Chelsio Communications, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__T4_REGS_VALUES_H__
end_ifndef

begin_define
define|#
directive|define
name|__T4_REGS_VALUES_H__
end_define

begin_comment
comment|/*  * This file contains definitions for various T4 register value hardware  * constants.  The types of values encoded here are predominantly those for  * register fields which control "modal" behavior.  For the most part, we do  * not include definitions for register fields which are simple numeric  * metrics, etc.  *  * These new "modal values" use a naming convention which matches the  * currently existing macros in t4_reg.h.  For register field FOO which would  * have S_FOO, M_FOO, V_FOO() and G_FOO() macros, we introduce X_FOO_{MODE}  * definitions.  These can be used as V_FOO(X_FOO_MODE) or as (G_FOO(x) ==  * X_FOO_MODE).  *  * Note that this should all be part of t4_regs.h but the toolset used to  * generate that file doesn't [yet] have the capability of collecting these  * constants.  */
end_comment

begin_comment
comment|/*  * SGE definitions.  * ================  */
end_comment

begin_comment
comment|/*  * SGE register field values.  */
end_comment

begin_comment
comment|/* CONTROL register */
end_comment

begin_define
define|#
directive|define
name|X_FLSPLITMODE_FLSPLITMIN
value|0
end_define

begin_define
define|#
directive|define
name|X_FLSPLITMODE_ETHHDR
value|1
end_define

begin_define
define|#
directive|define
name|X_FLSPLITMODE_IPHDR
value|2
end_define

begin_define
define|#
directive|define
name|X_FLSPLITMODE_TCPHDR
value|3
end_define

begin_define
define|#
directive|define
name|X_DCASYSTYPE_FSB
value|0
end_define

begin_define
define|#
directive|define
name|X_DCASYSTYPE_CSI
value|1
end_define

begin_define
define|#
directive|define
name|X_EGSTATPAGESIZE_64B
value|0
end_define

begin_define
define|#
directive|define
name|X_EGSTATPAGESIZE_128B
value|1
end_define

begin_define
define|#
directive|define
name|X_RXPKTCPLMODE_DATA
value|0
end_define

begin_define
define|#
directive|define
name|X_RXPKTCPLMODE_SPLIT
value|1
end_define

begin_define
define|#
directive|define
name|X_INGPCIEBOUNDARY_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|X_INGPCIEBOUNDARY_32B
value|0
end_define

begin_define
define|#
directive|define
name|X_INGPCIEBOUNDARY_64B
value|1
end_define

begin_define
define|#
directive|define
name|X_INGPCIEBOUNDARY_128B
value|2
end_define

begin_define
define|#
directive|define
name|X_INGPCIEBOUNDARY_256B
value|3
end_define

begin_define
define|#
directive|define
name|X_INGPCIEBOUNDARY_512B
value|4
end_define

begin_define
define|#
directive|define
name|X_INGPCIEBOUNDARY_1024B
value|5
end_define

begin_define
define|#
directive|define
name|X_INGPCIEBOUNDARY_2048B
value|6
end_define

begin_define
define|#
directive|define
name|X_INGPCIEBOUNDARY_4096B
value|7
end_define

begin_define
define|#
directive|define
name|X_INGPADBOUNDARY_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|X_INGPADBOUNDARY_32B
value|0
end_define

begin_define
define|#
directive|define
name|X_INGPADBOUNDARY_64B
value|1
end_define

begin_define
define|#
directive|define
name|X_INGPADBOUNDARY_128B
value|2
end_define

begin_define
define|#
directive|define
name|X_INGPADBOUNDARY_256B
value|3
end_define

begin_define
define|#
directive|define
name|X_INGPADBOUNDARY_512B
value|4
end_define

begin_define
define|#
directive|define
name|X_INGPADBOUNDARY_1024B
value|5
end_define

begin_define
define|#
directive|define
name|X_INGPADBOUNDARY_2048B
value|6
end_define

begin_define
define|#
directive|define
name|X_INGPADBOUNDARY_4096B
value|7
end_define

begin_define
define|#
directive|define
name|X_EGRPCIEBOUNDARY_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|X_EGRPCIEBOUNDARY_32B
value|0
end_define

begin_define
define|#
directive|define
name|X_EGRPCIEBOUNDARY_64B
value|1
end_define

begin_define
define|#
directive|define
name|X_EGRPCIEBOUNDARY_128B
value|2
end_define

begin_define
define|#
directive|define
name|X_EGRPCIEBOUNDARY_256B
value|3
end_define

begin_define
define|#
directive|define
name|X_EGRPCIEBOUNDARY_512B
value|4
end_define

begin_define
define|#
directive|define
name|X_EGRPCIEBOUNDARY_1024B
value|5
end_define

begin_define
define|#
directive|define
name|X_EGRPCIEBOUNDARY_2048B
value|6
end_define

begin_define
define|#
directive|define
name|X_EGRPCIEBOUNDARY_4096B
value|7
end_define

begin_comment
comment|/* GTS register */
end_comment

begin_define
define|#
directive|define
name|SGE_TIMERREGS
value|6
end_define

begin_define
define|#
directive|define
name|X_TIMERREG_COUNTER0
value|0
end_define

begin_define
define|#
directive|define
name|X_TIMERREG_COUNTER1
value|1
end_define

begin_define
define|#
directive|define
name|X_TIMERREG_COUNTER2
value|2
end_define

begin_define
define|#
directive|define
name|X_TIMERREG_COUNTER3
value|3
end_define

begin_define
define|#
directive|define
name|X_TIMERREG_COUNTER4
value|4
end_define

begin_define
define|#
directive|define
name|X_TIMERREG_COUNTER5
value|5
end_define

begin_define
define|#
directive|define
name|X_TIMERREG_RESTART_COUNTER
value|6
end_define

begin_define
define|#
directive|define
name|X_TIMERREG_UPDATE_CIDX
value|7
end_define

begin_comment
comment|/*  * Egress Context field values  */
end_comment

begin_define
define|#
directive|define
name|EC_WR_UNITS
value|16
end_define

begin_define
define|#
directive|define
name|X_FETCHBURSTMIN_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|X_FETCHBURSTMIN_16B
value|0
end_define

begin_define
define|#
directive|define
name|X_FETCHBURSTMIN_32B
value|1
end_define

begin_define
define|#
directive|define
name|X_FETCHBURSTMIN_64B
value|2
end_define

begin_define
define|#
directive|define
name|X_FETCHBURSTMIN_128B
value|3
end_define

begin_define
define|#
directive|define
name|X_FETCHBURSTMAX_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|X_FETCHBURSTMAX_64B
value|0
end_define

begin_define
define|#
directive|define
name|X_FETCHBURSTMAX_128B
value|1
end_define

begin_define
define|#
directive|define
name|X_FETCHBURSTMAX_256B
value|2
end_define

begin_define
define|#
directive|define
name|X_FETCHBURSTMAX_512B
value|3
end_define

begin_define
define|#
directive|define
name|X_HOSTFCMODE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|X_HOSTFCMODE_INGRESS_QUEUE
value|1
end_define

begin_define
define|#
directive|define
name|X_HOSTFCMODE_STATUS_PAGE
value|2
end_define

begin_define
define|#
directive|define
name|X_HOSTFCMODE_BOTH
value|3
end_define

begin_define
define|#
directive|define
name|X_HOSTFCOWNER_UP
value|0
end_define

begin_define
define|#
directive|define
name|X_HOSTFCOWNER_SGE
value|1
end_define

begin_define
define|#
directive|define
name|X_CIDXFLUSHTHRESH_1
value|0
end_define

begin_define
define|#
directive|define
name|X_CIDXFLUSHTHRESH_2
value|1
end_define

begin_define
define|#
directive|define
name|X_CIDXFLUSHTHRESH_4
value|2
end_define

begin_define
define|#
directive|define
name|X_CIDXFLUSHTHRESH_8
value|3
end_define

begin_define
define|#
directive|define
name|X_CIDXFLUSHTHRESH_16
value|4
end_define

begin_define
define|#
directive|define
name|X_CIDXFLUSHTHRESH_32
value|5
end_define

begin_define
define|#
directive|define
name|X_CIDXFLUSHTHRESH_64
value|6
end_define

begin_define
define|#
directive|define
name|X_CIDXFLUSHTHRESH_128
value|7
end_define

begin_define
define|#
directive|define
name|X_IDXSIZE_UNIT
value|64
end_define

begin_define
define|#
directive|define
name|X_BASEADDRESS_ALIGN
value|512
end_define

begin_comment
comment|/*  * Ingress Context field values  */
end_comment

begin_define
define|#
directive|define
name|X_UPDATESCHEDULING_TIMER
value|0
end_define

begin_define
define|#
directive|define
name|X_UPDATESCHEDULING_COUNTER_OPTTIMER
value|1
end_define

begin_define
define|#
directive|define
name|X_UPDATEDELIVERY_NONE
value|0
end_define

begin_define
define|#
directive|define
name|X_UPDATEDELIVERY_INTERRUPT
value|1
end_define

begin_define
define|#
directive|define
name|X_UPDATEDELIVERY_STATUS_PAGE
value|2
end_define

begin_define
define|#
directive|define
name|X_UPDATEDELIVERY_BOTH
value|3
end_define

begin_define
define|#
directive|define
name|X_INTERRUPTDESTINATION_PCIE
value|0
end_define

begin_define
define|#
directive|define
name|X_INTERRUPTDESTINATION_IQ
value|1
end_define

begin_define
define|#
directive|define
name|X_QUEUEENTRYSIZE_16B
value|0
end_define

begin_define
define|#
directive|define
name|X_QUEUEENTRYSIZE_32B
value|1
end_define

begin_define
define|#
directive|define
name|X_QUEUEENTRYSIZE_64B
value|2
end_define

begin_define
define|#
directive|define
name|X_QUEUEENTRYSIZE_128B
value|3
end_define

begin_define
define|#
directive|define
name|IC_SIZE_UNIT
value|16
end_define

begin_define
define|#
directive|define
name|IC_BASEADDRESS_ALIGN
value|512
end_define

begin_define
define|#
directive|define
name|X_RSPD_TYPE_FLBUF
value|0
end_define

begin_define
define|#
directive|define
name|X_RSPD_TYPE_CPL
value|1
end_define

begin_define
define|#
directive|define
name|X_RSPD_TYPE_INTR
value|2
end_define

begin_comment
comment|/*  * CIM definitions.  * ================  */
end_comment

begin_comment
comment|/*  * CIM register field values.  */
end_comment

begin_define
define|#
directive|define
name|X_MBOWNER_NONE
value|0
end_define

begin_define
define|#
directive|define
name|X_MBOWNER_FW
value|1
end_define

begin_define
define|#
directive|define
name|X_MBOWNER_PL
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __T4_REGS_VALUES_H__ */
end_comment

end_unit

