begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RMI_DEBUG_H_
end_ifndef

begin_define
define|#
directive|define
name|_RMI_DEBUG_H_
end_define

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_enum
enum|enum
block|{
comment|//cacheline 0
name|MSGRNG_INT
block|,
name|MSGRNG_PIC_INT
block|,
name|MSGRNG_MSG
block|,
name|MSGRNG_EXIT_STATUS
block|,
name|MSGRNG_MSG_CYCLES
block|,
comment|//cacheline 1
name|NETIF_TX
init|=
literal|8
block|,
name|NETIF_RX
block|,
name|NETIF_TX_COMPLETE
block|,
name|NETIF_TX_COMPLETE_TX
block|,
name|NETIF_RX_CYCLES
block|,
name|NETIF_TX_COMPLETE_CYCLES
block|,
name|NETIF_TX_CYCLES
block|,
name|NETIF_TIMER_START_Q
block|,
comment|//NETIF_REG_FRIN,
comment|//NETIF_INT_REG,
comment|//cacheline 2
name|REPLENISH_ENTER
init|=
literal|16
block|,
name|REPLENISH_ENTER_COUNT
block|,
name|REPLENISH_CPU
block|,
name|REPLENISH_FRIN
block|,
name|REPLENISH_CYCLES
block|,
name|NETIF_STACK_TX
block|,
name|NETIF_START_Q
block|,
name|NETIF_STOP_Q
block|,
comment|//cacheline 3
name|USER_MAC_START
init|=
literal|24
block|,
name|USER_MAC_INT
init|=
literal|24
block|,
name|USER_MAC_TX_COMPLETE
block|,
name|USER_MAC_RX
block|,
name|USER_MAC_POLL
block|,
name|USER_MAC_TX
block|,
name|USER_MAC_TX_FAIL
block|,
name|USER_MAC_TX_COUNT
block|,
name|USER_MAC_FRIN
block|,
comment|//cacheline 4
name|USER_MAC_TX_FAIL_GMAC_CREDITS
init|=
literal|32
block|,
name|USER_MAC_DO_PAGE_FAULT
block|,
name|USER_MAC_UPDATE_TLB
block|,
name|USER_MAC_UPDATE_BIGTLB
block|,
name|USER_MAC_UPDATE_TLB_PFN0
block|,
name|USER_MAC_UPDATE_TLB_PFN1
block|,
name|XLR_MAX_COUNTERS
init|=
literal|40
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|int
name|xlr_counters
index|[
name|MAXCPU
index|]
index|[
name|XLR_MAX_COUNTERS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|__uint32_t
name|msgrng_msg_cycles
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|xlr_inc_counter
parameter_list|(
name|x
parameter_list|)
value|atomic_add_int(&xlr_counters[PCPU_GET(cpuid)][(x)], 1)
end_define

begin_define
define|#
directive|define
name|xlr_dec_counter
parameter_list|(
name|x
parameter_list|)
value|atomic_subtract_int(&xlr_counters[PCPU_GET(cpuid)][(x)], 1)
end_define

begin_define
define|#
directive|define
name|xlr_set_counter
parameter_list|(
name|x
parameter_list|,
name|value
parameter_list|)
value|atomic_set_int(&xlr_counters[PCPU_GET(cpuid)][(x)], (value))
end_define

begin_define
define|#
directive|define
name|xlr_get_counter
parameter_list|(
name|x
parameter_list|)
value|(&xlr_counters[0][(x)])
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* default mode */
end_comment

begin_define
define|#
directive|define
name|xlr_inc_counter
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xlr_dec_counter
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xlr_set_counter
parameter_list|(
name|x
parameter_list|,
name|value
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xlr_get_counter
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|dbg_msg
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf(fmt, ##args)
end_define

begin_define
define|#
directive|define
name|dbg_panic
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|panic(fmt, ##args)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

