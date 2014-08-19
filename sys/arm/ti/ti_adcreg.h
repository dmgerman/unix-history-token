begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2014 Luiz Otavio O Souza<loos@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TI_ADCREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_TI_ADCREG_H_
end_define

begin_define
define|#
directive|define
name|ADC_REVISION
value|0x000
end_define

begin_define
define|#
directive|define
name|ADC_REV_SCHEME_MSK
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|ADC_REV_SCHEME_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|ADC_REV_FUNC_MSK
value|0x0fff0000
end_define

begin_define
define|#
directive|define
name|ADC_REV_FUNC_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ADC_REV_RTL_MSK
value|0x0000f800
end_define

begin_define
define|#
directive|define
name|ADC_REV_RTL_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|ADC_REV_MAJOR_MSK
value|0x00000700
end_define

begin_define
define|#
directive|define
name|ADC_REV_MAJOR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ADC_REV_CUSTOM_MSK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|ADC_REV_CUSTOM_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|ADC_REV_MINOR_MSK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|ADC_SYSCFG
value|0x010
end_define

begin_define
define|#
directive|define
name|ADC_SYSCFG_IDLE_MSK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|ADC_SYSCFG_IDLE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|ADC_IRQSTATUS_RAW
value|0x024
end_define

begin_define
define|#
directive|define
name|ADC_IRQSTATUS
value|0x028
end_define

begin_define
define|#
directive|define
name|ADC_IRQENABLE_SET
value|0x02c
end_define

begin_define
define|#
directive|define
name|ADC_IRQENABLE_CLR
value|0x030
end_define

begin_define
define|#
directive|define
name|ADC_IRQ_HW_PEN_SYNC
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|ADC_IRQ_PEN_UP
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|ADC_IRQ_OUT_RANGE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|ADC_IRQ_FIFO1_UNDR
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ADC_IRQ_FIFO1_OVERR
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ADC_IRQ_FIFO1_THRES
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ADC_IRQ_FIFO0_UNDR
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ADC_IRQ_FIFO0_OVERR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ADC_IRQ_FIFO0_THRES
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ADC_IRQ_END_OF_SEQ
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ADC_IRQ_HW_PEN_ASYNC
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ADC_CTRL
value|0x040
end_define

begin_define
define|#
directive|define
name|ADC_CTRL_STEP_WP
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ADC_CTRL_STEP_ID
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ADC_CTRL_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ADC_STAT
value|0x044
end_define

begin_define
define|#
directive|define
name|ADC_CLKDIV
value|0x04c
end_define

begin_define
define|#
directive|define
name|ADC_STEPENABLE
value|0x054
end_define

begin_define
define|#
directive|define
name|ADC_IDLECONFIG
value|0x058
end_define

begin_define
define|#
directive|define
name|ADC_STEPCFG1
value|0x064
end_define

begin_define
define|#
directive|define
name|ADC_STEPDLY1
value|0x068
end_define

begin_define
define|#
directive|define
name|ADC_STEPCFG2
value|0x06c
end_define

begin_define
define|#
directive|define
name|ADC_STEPDLY2
value|0x070
end_define

begin_define
define|#
directive|define
name|ADC_STEPCFG3
value|0x074
end_define

begin_define
define|#
directive|define
name|ADC_STEPDLY3
value|0x078
end_define

begin_define
define|#
directive|define
name|ADC_STEPCFG4
value|0x07c
end_define

begin_define
define|#
directive|define
name|ADC_STEPDLY4
value|0x080
end_define

begin_define
define|#
directive|define
name|ADC_STEPCFG5
value|0x084
end_define

begin_define
define|#
directive|define
name|ADC_STEPDLY5
value|0x088
end_define

begin_define
define|#
directive|define
name|ADC_STEPCFG6
value|0x08c
end_define

begin_define
define|#
directive|define
name|ADC_STEPDLY6
value|0x090
end_define

begin_define
define|#
directive|define
name|ADC_STEPCFG7
value|0x094
end_define

begin_define
define|#
directive|define
name|ADC_STEPDLY7
value|0x098
end_define

begin_define
define|#
directive|define
name|ADC_STEPCFG8
value|0x09c
end_define

begin_define
define|#
directive|define
name|ADC_STEPDLY8
value|0x0a0
end_define

begin_define
define|#
directive|define
name|ADC_STEP_DIFF_CNTRL
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|ADC_STEP_RFM_MSK
value|0x01800000
end_define

begin_define
define|#
directive|define
name|ADC_STEP_RFM_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|ADC_STEP_RFM_VSSA
value|0
end_define

begin_define
define|#
directive|define
name|ADC_STEP_RFM_XNUR
value|1
end_define

begin_define
define|#
directive|define
name|ADC_STEP_RFM_YNLR
value|2
end_define

begin_define
define|#
directive|define
name|ADC_STEP_RFM_VREFN
value|3
end_define

begin_define
define|#
directive|define
name|ADC_STEP_INP_MSK
value|0x00780000
end_define

begin_define
define|#
directive|define
name|ADC_STEP_INP_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|ADC_STEP_INM_MSK
value|0x00078000
end_define

begin_define
define|#
directive|define
name|ADC_STEP_INM_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|ADC_STEP_IN_VREFN
value|8
end_define

begin_define
define|#
directive|define
name|ADC_STEP_RFP_MSK
value|0x00007000
end_define

begin_define
define|#
directive|define
name|ADC_STEP_RFP_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ADC_STEP_RFP_VDDA
value|0
end_define

begin_define
define|#
directive|define
name|ADC_STEP_RFP_XPUL
value|1
end_define

begin_define
define|#
directive|define
name|ADC_STEP_RFP_YPLL
value|2
end_define

begin_define
define|#
directive|define
name|ADC_STEP_RFP_VREFP
value|3
end_define

begin_define
define|#
directive|define
name|ADC_STEP_RFP_INTREF
value|4
end_define

begin_define
define|#
directive|define
name|ADC_STEP_AVG_MSK
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|ADC_STEP_AVG_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|ADC_STEP_MODE_MSK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|ADC_STEP_MODE_ONESHOT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ADC_STEP_MODE_CONTINUOUS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ADC_STEP_SAMPLE_DELAY
value|0xff000000
end_define

begin_define
define|#
directive|define
name|ADC_STEP_OPEN_DELAY
value|0x0003ffff
end_define

begin_define
define|#
directive|define
name|ADC_FIFO0COUNT
value|0x0e4
end_define

begin_define
define|#
directive|define
name|ADC_FIFO0THRESHOLD
value|0x0e8
end_define

begin_define
define|#
directive|define
name|ADC_FIFO0DATA
value|0x100
end_define

begin_define
define|#
directive|define
name|ADC_FIFO_COUNT_MSK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|ADC_FIFO_STEP_ID_MSK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|ADC_FIFO_STEP_ID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ADC_FIFO_DATA_MSK
value|0x00000fff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TI_ADCREG_H_ */
end_comment

end_unit

