begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NLM_HAL_PIC_H
end_ifndef

begin_define
define|#
directive|define
name|_NLM_HAL_PIC_H
end_define

begin_comment
comment|/* PIC Specific registers */
end_comment

begin_define
define|#
directive|define
name|PIC_CTRL
value|0x00
end_define

begin_comment
comment|/* PIC control register defines */
end_comment

begin_define
define|#
directive|define
name|PIC_CTRL_ITV
value|32
end_define

begin_comment
comment|/* interrupt timeout value */
end_comment

begin_define
define|#
directive|define
name|PIC_CTRL_ICI
value|19
end_define

begin_comment
comment|/* ICI interrupt timeout enable */
end_comment

begin_define
define|#
directive|define
name|PIC_CTRL_ITE
value|18
end_define

begin_comment
comment|/* interrupt timeout enable */
end_comment

begin_define
define|#
directive|define
name|PIC_CTRL_STE
value|10
end_define

begin_comment
comment|/* system timer interrupt enable */
end_comment

begin_define
define|#
directive|define
name|PIC_CTRL_WWR1
value|8
end_define

begin_comment
comment|/* watchdog 1 wraparound count for reset */
end_comment

begin_define
define|#
directive|define
name|PIC_CTRL_WWR0
value|6
end_define

begin_comment
comment|/* watchdog 0 wraparound count for reset */
end_comment

begin_define
define|#
directive|define
name|PIC_CTRL_WWN1
value|4
end_define

begin_comment
comment|/* watchdog 1 wraparound count for NMI */
end_comment

begin_define
define|#
directive|define
name|PIC_CTRL_WWN0
value|2
end_define

begin_comment
comment|/* watchdog 0 wraparound count for NMI */
end_comment

begin_define
define|#
directive|define
name|PIC_CTRL_WTE
value|0
end_define

begin_comment
comment|/* watchdog timer enable */
end_comment

begin_comment
comment|/* PIC Status register defines */
end_comment

begin_define
define|#
directive|define
name|PIC_ICI_STATUS
value|33
end_define

begin_comment
comment|/* ICI interrupt timeout status */
end_comment

begin_define
define|#
directive|define
name|PIC_ITE_STATUS
value|32
end_define

begin_comment
comment|/* interrupt timeout status */
end_comment

begin_define
define|#
directive|define
name|PIC_STS_STATUS
value|4
end_define

begin_comment
comment|/* System timer interrupt status */
end_comment

begin_define
define|#
directive|define
name|PIC_WNS_STATUS
value|2
end_define

begin_comment
comment|/* NMI status for watchdog timers */
end_comment

begin_define
define|#
directive|define
name|PIC_WIS_STATUS
value|0
end_define

begin_comment
comment|/* Interrupt status for watchdog timers */
end_comment

begin_comment
comment|/* PIC IPI control register offsets */
end_comment

begin_define
define|#
directive|define
name|PIC_IPICTRL_NMI
value|32
end_define

begin_define
define|#
directive|define
name|PIC_IPICTRL_RIV
value|20
end_define

begin_comment
comment|/* received interrupt vector */
end_comment

begin_define
define|#
directive|define
name|PIC_IPICTRL_IDB
value|16
end_define

begin_comment
comment|/* interrupt destination base */
end_comment

begin_define
define|#
directive|define
name|PIC_IPICTRL_DTE
value|0
end_define

begin_comment
comment|/* interrupt destination thread enables */
end_comment

begin_comment
comment|/* PIC IRT register offsets */
end_comment

begin_define
define|#
directive|define
name|PIC_IRT_ENABLE
value|31
end_define

begin_define
define|#
directive|define
name|PIC_IRT_NMI
value|29
end_define

begin_define
define|#
directive|define
name|PIC_IRT_SCH
value|28
end_define

begin_comment
comment|/* Scheduling scheme */
end_comment

begin_define
define|#
directive|define
name|PIC_IRT_RVEC
value|20
end_define

begin_comment
comment|/* Interrupt receive vectors */
end_comment

begin_define
define|#
directive|define
name|PIC_IRT_DT
value|19
end_define

begin_comment
comment|/* Destination type */
end_comment

begin_define
define|#
directive|define
name|PIC_IRT_DB
value|16
end_define

begin_comment
comment|/* Destination base */
end_comment

begin_define
define|#
directive|define
name|PIC_IRT_DTE
value|0
end_define

begin_comment
comment|/* Destination thread enables */
end_comment

begin_define
define|#
directive|define
name|PIC_BYTESWAP
value|0x02
end_define

begin_define
define|#
directive|define
name|PIC_STATUS
value|0x04
end_define

begin_define
define|#
directive|define
name|PIC_INTR_TIMEOUT
value|0x06
end_define

begin_define
define|#
directive|define
name|PIC_ICI0_INTR_TIMEOUT
value|0x08
end_define

begin_define
define|#
directive|define
name|PIC_ICI1_INTR_TIMEOUT
value|0x0a
end_define

begin_define
define|#
directive|define
name|PIC_ICI2_INTR_TIMEOUT
value|0x0c
end_define

begin_define
define|#
directive|define
name|PIC_IPI_CTL
value|0x0e
end_define

begin_define
define|#
directive|define
name|PIC_INT_ACK
value|0x10
end_define

begin_define
define|#
directive|define
name|PIC_INT_PENDING0
value|0x12
end_define

begin_define
define|#
directive|define
name|PIC_INT_PENDING1
value|0x14
end_define

begin_define
define|#
directive|define
name|PIC_INT_PENDING2
value|0x16
end_define

begin_define
define|#
directive|define
name|PIC_WDOG0_MAXVAL
value|0x18
end_define

begin_define
define|#
directive|define
name|PIC_WDOG0_COUNT
value|0x1a
end_define

begin_define
define|#
directive|define
name|PIC_WDOG0_ENABLE0
value|0x1c
end_define

begin_define
define|#
directive|define
name|PIC_WDOG0_ENABLE1
value|0x1e
end_define

begin_define
define|#
directive|define
name|PIC_WDOG0_BEATCMD
value|0x20
end_define

begin_define
define|#
directive|define
name|PIC_WDOG0_BEAT0
value|0x22
end_define

begin_define
define|#
directive|define
name|PIC_WDOG0_BEAT1
value|0x24
end_define

begin_define
define|#
directive|define
name|PIC_WDOG1_MAXVAL
value|0x26
end_define

begin_define
define|#
directive|define
name|PIC_WDOG1_COUNT
value|0x28
end_define

begin_define
define|#
directive|define
name|PIC_WDOG1_ENABLE0
value|0x2a
end_define

begin_define
define|#
directive|define
name|PIC_WDOG1_ENABLE1
value|0x2c
end_define

begin_define
define|#
directive|define
name|PIC_WDOG1_BEATCMD
value|0x2e
end_define

begin_define
define|#
directive|define
name|PIC_WDOG1_BEAT0
value|0x30
end_define

begin_define
define|#
directive|define
name|PIC_WDOG1_BEAT1
value|0x32
end_define

begin_define
define|#
directive|define
name|PIC_WDOG_MAXVAL
parameter_list|(
name|i
parameter_list|)
value|(PIC_WDOG0_MAXVAL + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|PIC_WDOG_COUNT
parameter_list|(
name|i
parameter_list|)
value|(PIC_WDOG0_COUNT + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|PIC_WDOG_ENABLE0
parameter_list|(
name|i
parameter_list|)
value|(PIC_WDOG0_ENABLE0 + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|PIC_WDOG_ENABLE1
parameter_list|(
name|i
parameter_list|)
value|(PIC_WDOG0_ENABLE1 + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|PIC_WDOG_BEATCMD
parameter_list|(
name|i
parameter_list|)
value|(PIC_WDOG0_BEATCMD + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|PIC_WDOG_BEAT0
parameter_list|(
name|i
parameter_list|)
value|(PIC_WDOG0_BEAT0 + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|PIC_WDOG_BEAT1
parameter_list|(
name|i
parameter_list|)
value|(PIC_WDOG0_BEAT1 + ((i) ? 7 : 0))
end_define

begin_define
define|#
directive|define
name|PIC_TIMER0_MAXVAL
value|0x34
end_define

begin_define
define|#
directive|define
name|PIC_TIMER1_MAXVAL
value|0x36
end_define

begin_define
define|#
directive|define
name|PIC_TIMER2_MAXVAL
value|0x38
end_define

begin_define
define|#
directive|define
name|PIC_TIMER3_MAXVAL
value|0x3a
end_define

begin_define
define|#
directive|define
name|PIC_TIMER4_MAXVAL
value|0x3c
end_define

begin_define
define|#
directive|define
name|PIC_TIMER5_MAXVAL
value|0x3e
end_define

begin_define
define|#
directive|define
name|PIC_TIMER6_MAXVAL
value|0x40
end_define

begin_define
define|#
directive|define
name|PIC_TIMER7_MAXVAL
value|0x42
end_define

begin_define
define|#
directive|define
name|PIC_TIMER_MAXVAL
parameter_list|(
name|i
parameter_list|)
value|(PIC_TIMER0_MAXVAL + ((i) * 2))
end_define

begin_define
define|#
directive|define
name|PIC_TIMER0_COUNT
value|0x44
end_define

begin_define
define|#
directive|define
name|PIC_TIMER1_COUNT
value|0x46
end_define

begin_define
define|#
directive|define
name|PIC_TIMER2_COUNT
value|0x48
end_define

begin_define
define|#
directive|define
name|PIC_TIMER3_COUNT
value|0x4a
end_define

begin_define
define|#
directive|define
name|PIC_TIMER4_COUNT
value|0x4c
end_define

begin_define
define|#
directive|define
name|PIC_TIMER5_COUNT
value|0x4e
end_define

begin_define
define|#
directive|define
name|PIC_TIMER6_COUNT
value|0x50
end_define

begin_define
define|#
directive|define
name|PIC_TIMER7_COUNT
value|0x52
end_define

begin_define
define|#
directive|define
name|PIC_TIMER_COUNT
parameter_list|(
name|i
parameter_list|)
value|(PIC_TIMER0_COUNT + ((i) * 2))
end_define

begin_define
define|#
directive|define
name|PIC_ITE0_N0_N1
value|0x54
end_define

begin_define
define|#
directive|define
name|PIC_ITE1_N0_N1
value|0x58
end_define

begin_define
define|#
directive|define
name|PIC_ITE2_N0_N1
value|0x5c
end_define

begin_define
define|#
directive|define
name|PIC_ITE3_N0_N1
value|0x60
end_define

begin_define
define|#
directive|define
name|PIC_ITE4_N0_N1
value|0x64
end_define

begin_define
define|#
directive|define
name|PIC_ITE5_N0_N1
value|0x68
end_define

begin_define
define|#
directive|define
name|PIC_ITE6_N0_N1
value|0x6c
end_define

begin_define
define|#
directive|define
name|PIC_ITE7_N0_N1
value|0x70
end_define

begin_define
define|#
directive|define
name|PIC_ITE_N0_N1
parameter_list|(
name|i
parameter_list|)
value|(PIC_ITE0_N0_N1 + ((i) * 4))
end_define

begin_define
define|#
directive|define
name|PIC_ITE0_N2_N3
value|0x56
end_define

begin_define
define|#
directive|define
name|PIC_ITE1_N2_N3
value|0x5a
end_define

begin_define
define|#
directive|define
name|PIC_ITE2_N2_N3
value|0x5e
end_define

begin_define
define|#
directive|define
name|PIC_ITE3_N2_N3
value|0x62
end_define

begin_define
define|#
directive|define
name|PIC_ITE4_N2_N3
value|0x66
end_define

begin_define
define|#
directive|define
name|PIC_ITE5_N2_N3
value|0x6a
end_define

begin_define
define|#
directive|define
name|PIC_ITE6_N2_N3
value|0x6e
end_define

begin_define
define|#
directive|define
name|PIC_ITE7_N2_N3
value|0x72
end_define

begin_define
define|#
directive|define
name|PIC_ITE_N2_N3
parameter_list|(
name|i
parameter_list|)
value|(PIC_ITE0_N2_N3 + ((i) * 4))
end_define

begin_define
define|#
directive|define
name|PIC_IRT0
value|0x74
end_define

begin_define
define|#
directive|define
name|PIC_IRT
parameter_list|(
name|i
parameter_list|)
value|(PIC_IRT0 + ((i) * 2))
end_define

begin_define
define|#
directive|define
name|TIMER_CYCLES_MAXVAL
value|0xffffffffffffffffULL
end_define

begin_comment
comment|/*  *    IRT Map  */
end_comment

begin_define
define|#
directive|define
name|PIC_IRT_WD_0_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|PIC_IRT_WD_1_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|PIC_IRT_WD_NMI_0_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|PIC_IRT_WD_NMI_1_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|PIC_IRT_TIMER_0_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|PIC_IRT_TIMER_1_INDEX
value|5
end_define

begin_define
define|#
directive|define
name|PIC_IRT_TIMER_2_INDEX
value|6
end_define

begin_define
define|#
directive|define
name|PIC_IRT_TIMER_3_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|PIC_IRT_TIMER_4_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|PIC_IRT_TIMER_5_INDEX
value|9
end_define

begin_define
define|#
directive|define
name|PIC_IRT_TIMER_6_INDEX
value|10
end_define

begin_define
define|#
directive|define
name|PIC_IRT_TIMER_7_INDEX
value|11
end_define

begin_define
define|#
directive|define
name|PIC_IRT_CLOCK_INDEX
value|PIC_IRT_TIMER_7_INDEX
end_define

begin_define
define|#
directive|define
name|PIC_IRT_TIMER_INDEX
parameter_list|(
name|num
parameter_list|)
value|((num) + PIC_IRT_TIMER_0_INDEX)
end_define

begin_define
define|#
directive|define
name|PIC_CLOCK_TIMER
value|7
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ASSEMBLY__
argument_list|)
end_if

begin_comment
comment|/*  *   Misc  */
end_comment

begin_define
define|#
directive|define
name|PIC_IRT_VALID
value|1
end_define

begin_define
define|#
directive|define
name|PIC_LOCAL_SCHEDULING
value|1
end_define

begin_define
define|#
directive|define
name|PIC_GLOBAL_SCHEDULING
value|0
end_define

begin_define
define|#
directive|define
name|nlm_read_pic_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|nlm_read_reg64(b, r)
end_define

begin_define
define|#
directive|define
name|nlm_write_pic_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg64(b, r, v)
end_define

begin_define
define|#
directive|define
name|nlm_get_pic_pcibase
parameter_list|(
name|node
parameter_list|)
value|nlm_pcicfg_base(XLP_IO_PIC_OFFSET(node))
end_define

begin_define
define|#
directive|define
name|nlm_get_pic_regbase
parameter_list|(
name|node
parameter_list|)
value|(nlm_get_pic_pcibase(node) + XLP_IO_PCI_HDRSZ)
end_define

begin_comment
comment|/* IRT and h/w interrupt routines */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|nlm_pic_read_irt
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|irt_index
parameter_list|)
block|{
return|return
name|nlm_read_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_IRT
argument_list|(
name|irt_index
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nlm_pic_send_ipi
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|cpu
parameter_list|,
name|int
name|vec
parameter_list|,
name|int
name|nmi
parameter_list|)
block|{
name|uint64_t
name|ipi
decl_stmt|;
name|int
name|node
decl_stmt|,
name|ncpu
decl_stmt|;
name|node
operator|=
name|cpu
operator|/
literal|32
expr_stmt|;
name|ncpu
operator|=
name|cpu
operator|&
literal|0x1f
expr_stmt|;
name|ipi
operator|=
operator|(
operator|(
name|uint64_t
operator|)
name|nmi
operator|<<
literal|31
operator|)
operator||
operator|(
name|vec
operator|<<
literal|20
operator|)
operator||
operator|(
name|node
operator|<<
literal|17
operator|)
operator||
operator|(
literal|1
operator|<<
operator|(
name|cpu
operator|&
literal|0xf
operator|)
operator|)
expr_stmt|;
if|if
condition|(
name|ncpu
operator|>
literal|15
condition|)
name|ipi
operator||=
literal|0x10000
expr_stmt|;
comment|/* Setting bit 16 to select cpus 16-31 */
name|nlm_write_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_IPI_CTL
argument_list|,
name|ipi
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|nlm_pic_read_control
parameter_list|(
name|uint64_t
name|base
parameter_list|)
block|{
return|return
name|nlm_read_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_CTRL
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nlm_pic_write_control
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|uint64_t
name|control
parameter_list|)
block|{
name|nlm_write_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_CTRL
argument_list|,
name|control
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nlm_pic_update_control
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|uint64_t
name|control
parameter_list|)
block|{
name|uint64_t
name|val
decl_stmt|;
name|val
operator|=
name|nlm_read_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_CTRL
argument_list|)
expr_stmt|;
name|nlm_write_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_CTRL
argument_list|,
name|control
operator||
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nlm_pic_ack
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|irt_num
parameter_list|)
block|{
name|nlm_write_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_INT_ACK
argument_list|,
name|irt_num
argument_list|)
expr_stmt|;
comment|/* Ack the Status register for Watchdog& System timers */
if|if
condition|(
name|irt_num
operator|<
literal|12
condition|)
name|nlm_write_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_STATUS
argument_list|,
operator|(
literal|1
operator|<<
name|irt_num
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nlm_set_irt_to_cpu
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|irt
parameter_list|,
name|int
name|cpu
parameter_list|)
block|{
name|uint64_t
name|val
decl_stmt|;
name|val
operator|=
name|nlm_read_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_IRT
argument_list|(
name|irt
argument_list|)
argument_list|)
expr_stmt|;
name|val
operator||=
name|cpu
operator|&
literal|0xf
expr_stmt|;
if|if
condition|(
name|cpu
operator|>
literal|15
condition|)
name|val
operator||=
literal|1
operator|<<
literal|16
expr_stmt|;
name|nlm_write_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_IRT
argument_list|(
name|irt
argument_list|)
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nlm_pic_write_irt
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|irt_num
parameter_list|,
name|int
name|en
parameter_list|,
name|int
name|nmi
parameter_list|,
name|int
name|sch
parameter_list|,
name|int
name|vec
parameter_list|,
name|int
name|dt
parameter_list|,
name|int
name|db
parameter_list|,
name|int
name|dte
parameter_list|)
block|{
name|uint64_t
name|val
decl_stmt|;
name|val
operator|=
operator|(
operator|(
operator|(
name|uint64_t
operator|)
name|en
operator|&
literal|0x1
operator|)
operator|<<
literal|31
operator|)
operator||
operator|(
operator|(
name|nmi
operator|&
literal|0x1
operator|)
operator|<<
literal|29
operator|)
operator||
operator|(
operator|(
name|sch
operator|&
literal|0x1
operator|)
operator|<<
literal|28
operator|)
operator||
operator|(
operator|(
name|vec
operator|&
literal|0x3f
operator|)
operator|<<
literal|20
operator|)
operator||
operator|(
operator|(
name|dt
operator|&
literal|0x1
operator|)
operator|<<
literal|19
operator|)
operator||
operator|(
operator|(
name|db
operator|&
literal|0x7
operator|)
operator|<<
literal|16
operator|)
operator||
operator|(
name|dte
operator|&
literal|0xffff
operator|)
expr_stmt|;
name|nlm_write_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_IRT
argument_list|(
name|irt_num
argument_list|)
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nlm_pic_write_irt_direct
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|irt_num
parameter_list|,
name|int
name|en
parameter_list|,
name|int
name|nmi
parameter_list|,
name|int
name|sch
parameter_list|,
name|int
name|vec
parameter_list|,
name|int
name|cpu
parameter_list|)
block|{
name|nlm_pic_write_irt
argument_list|(
name|base
argument_list|,
name|irt_num
argument_list|,
name|en
argument_list|,
name|nmi
argument_list|,
name|sch
argument_list|,
name|vec
argument_list|,
literal|1
argument_list|,
operator|(
name|cpu
operator|>>
literal|4
operator|)
argument_list|,
comment|/* thread group */
literal|1
operator|<<
operator|(
name|cpu
operator|&
literal|0xf
operator|)
argument_list|)
expr_stmt|;
comment|/* thread mask */
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|nlm_pic_read_timer
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|timer
parameter_list|)
block|{
return|return
name|nlm_read_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_TIMER_COUNT
argument_list|(
name|timer
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nlm_pic_write_timer
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|timer
parameter_list|,
name|uint64_t
name|value
parameter_list|)
block|{
name|nlm_write_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_TIMER_COUNT
argument_list|(
name|timer
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nlm_pic_set_timer
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|timer
parameter_list|,
name|uint64_t
name|value
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|cpu
parameter_list|)
block|{
name|uint64_t
name|pic_ctrl
decl_stmt|;
name|int
name|en
decl_stmt|,
name|nmi
decl_stmt|;
name|en
operator|=
name|nmi
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|irq
operator|>
literal|0
condition|)
name|en
operator|=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|irq
operator|<
literal|0
condition|)
block|{
name|en
operator|=
name|nmi
operator|=
literal|1
expr_stmt|;
name|irq
operator|=
operator|-
name|irq
expr_stmt|;
block|}
name|nlm_write_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_TIMER_MAXVAL
argument_list|(
name|timer
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|nlm_pic_write_irt_direct
argument_list|(
name|base
argument_list|,
name|PIC_IRT_TIMER_INDEX
argument_list|(
name|timer
argument_list|)
argument_list|,
name|en
argument_list|,
name|nmi
argument_list|,
literal|0
argument_list|,
name|irq
argument_list|,
name|cpu
argument_list|)
expr_stmt|;
comment|/* enable the timer */
name|pic_ctrl
operator|=
name|nlm_read_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_CTRL
argument_list|)
expr_stmt|;
name|pic_ctrl
operator||=
operator|(
literal|1
operator|<<
operator|(
name|PIC_CTRL_STE
operator|+
name|timer
operator|)
operator|)
expr_stmt|;
name|nlm_write_pic_reg
argument_list|(
name|base
argument_list|,
name|PIC_CTRL
argument_list|,
name|pic_ctrl
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NLM_HAL_PIC_H */
end_comment

end_unit

