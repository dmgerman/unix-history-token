begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-1999 Eduardo Horvath  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR  ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR  BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: sbusreg.h,v 1.7 1999/06/07 05:28:03 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_SBUS_SBUSREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_SBUS_SBUSREG_H_
end_define

begin_comment
comment|/*  * Sbus device addresses are obtained from the FORTH PROMs.  They come  * in `absolute' and `relative' address flavors, so we have to handle both.  * Relative addresses do *not* include the slot number.  */
end_comment

begin_define
define|#
directive|define
name|SBUS_BASE
value|0xf8000000
end_define

begin_define
define|#
directive|define
name|SBUS_ADDR
parameter_list|(
name|slot
parameter_list|,
name|off
parameter_list|)
value|(SBUS_BASE + ((slot)<< 25) + (off))
end_define

begin_define
define|#
directive|define
name|SBUS_ABS
parameter_list|(
name|a
parameter_list|)
value|((unsigned)(a)>= SBUS_BASE)
end_define

begin_define
define|#
directive|define
name|SBUS_ABS_TO_SLOT
parameter_list|(
name|a
parameter_list|)
value|(((a) - SBUS_BASE)>> 25)
end_define

begin_define
define|#
directive|define
name|SBUS_ABS_TO_OFFSET
parameter_list|(
name|a
parameter_list|)
value|(((a) - SBUS_BASE)& 0x1ffffff)
end_define

begin_comment
comment|/*  * Sun4u S-bus definitions.  Here's where we deal w/the machine  * dependencies of sysio.  *  * SYSIO implements or is the interface to several things:  *  * o The SBUS interface itself  * o The IOMMU  * o The DVMA units  * o The interrupt controller  * o The counter/timers  *  * Since it has registers to control lots of different things  * as well as several on-board SBUS devices and external SBUS  * slots scattered throughout its address space, it's a pain.  *  * One good point, however, is that all registers are 64-bit.  */
end_comment

begin_define
define|#
directive|define
name|SBR_UPA_PORTID
value|0x0000
end_define

begin_comment
comment|/* UPA port ID register */
end_comment

begin_define
define|#
directive|define
name|SBR_UPA_CONFIG
value|0x0008
end_define

begin_comment
comment|/* UPA config register */
end_comment

begin_define
define|#
directive|define
name|SBR_CS
value|0x0010
end_define

begin_comment
comment|/* SYSIO control/status register */
end_comment

begin_define
define|#
directive|define
name|SBR_ECCC
value|0x0020
end_define

begin_comment
comment|/* ECC control register */
end_comment

begin_define
define|#
directive|define
name|SBR_UE_AFS
value|0x0030
end_define

begin_comment
comment|/* Uncorrectable Error AFSR */
end_comment

begin_define
define|#
directive|define
name|SBR_UE_AFA
value|0x0038
end_define

begin_comment
comment|/* Uncorrectable Error AFAR */
end_comment

begin_define
define|#
directive|define
name|SBR_CE_AFS
value|0x0040
end_define

begin_comment
comment|/* Correctable Error AFSR */
end_comment

begin_define
define|#
directive|define
name|SBR_CE_AFA
value|0x0048
end_define

begin_comment
comment|/* Correctable Error AFAR */
end_comment

begin_define
define|#
directive|define
name|SBR_PM_CTL
value|0x0100
end_define

begin_comment
comment|/* Performance monitor control reg */
end_comment

begin_define
define|#
directive|define
name|SBR_PM_COUNT
value|0x0108
end_define

begin_comment
comment|/* Performance monitor counter reg */
end_comment

begin_define
define|#
directive|define
name|SBR_CTL
value|0x2000
end_define

begin_comment
comment|/* SBUS Control Register */
end_comment

begin_define
define|#
directive|define
name|SBR_AFS
value|0x2010
end_define

begin_comment
comment|/* SBUS AFSR */
end_comment

begin_define
define|#
directive|define
name|SBR_AFA
value|0x2018
end_define

begin_comment
comment|/* SBUS AFAR */
end_comment

begin_define
define|#
directive|define
name|SBR_CONFIG0
value|0x2020
end_define

begin_comment
comment|/* SBUS Slot 0 config register */
end_comment

begin_define
define|#
directive|define
name|SBR_CONFIG1
value|0x2028
end_define

begin_comment
comment|/* SBUS Slot 1 config register */
end_comment

begin_define
define|#
directive|define
name|SBR_CONFIG2
value|0x2030
end_define

begin_comment
comment|/* SBUS Slot 2 config register */
end_comment

begin_define
define|#
directive|define
name|SBR_CONFIG3
value|0x2038
end_define

begin_comment
comment|/* SBUS Slot 3 config register */
end_comment

begin_define
define|#
directive|define
name|SBR_CONFIG13
value|0x2040
end_define

begin_comment
comment|/* Slot 13 config register<audio> */
end_comment

begin_define
define|#
directive|define
name|SBR_CONFIG14
value|0x2048
end_define

begin_comment
comment|/* Slot 14 config register<macio> */
end_comment

begin_define
define|#
directive|define
name|SBR_CONFIG15
value|0x2050
end_define

begin_comment
comment|/* Slot 15 config register<slavio> */
end_comment

begin_define
define|#
directive|define
name|SBR_IOMMU
value|0x2400
end_define

begin_comment
comment|/* IOMMU register block */
end_comment

begin_define
define|#
directive|define
name|SBR_STRBUF
value|0x2800
end_define

begin_comment
comment|/* stream buffer register block */
end_comment

begin_define
define|#
directive|define
name|SBR_SLOT0_INT_MAP
value|0x2c00
end_define

begin_comment
comment|/* SBUS slot 0 interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_SLOT1_INT_MAP
value|0x2c08
end_define

begin_comment
comment|/* SBUS slot 1 interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_SLOT2_INT_MAP
value|0x2c10
end_define

begin_comment
comment|/* SBUS slot 2 interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_SLOT3_INT_MAP
value|0x2c18
end_define

begin_comment
comment|/* SBUS slot 3 interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_INTR_RETRY_TIM
value|0x2c20
end_define

begin_comment
comment|/* interrupt retry timer reg */
end_comment

begin_define
define|#
directive|define
name|SBR_SCSI_INT_MAP
value|0x3000
end_define

begin_comment
comment|/* SCSI interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_ETHER_INT_MAP
value|0x3008
end_define

begin_comment
comment|/* ethernet interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_BPP_INT_MAP
value|0x3010
end_define

begin_comment
comment|/* parallel interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_AUDIO_INT_MAP
value|0x3018
end_define

begin_comment
comment|/* audio interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_POWER_INT_MAP
value|0x3020
end_define

begin_comment
comment|/* power fail interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_SKBDMS_INT_MAP
value|0x3028
end_define

begin_comment
comment|/* serial/kbd/mouse interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_FD_INT_MAP
value|0x3030
end_define

begin_comment
comment|/* floppy interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_THERM_INT_MAP
value|0x3038
end_define

begin_comment
comment|/* thermal warn interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_KBD_INT_MAP
value|0x3040
end_define

begin_comment
comment|/* kbd [unused] interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_MOUSE_INT_MAP
value|0x3048
end_define

begin_comment
comment|/* mouse [unused] interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_SERIAL_INT_MAP
value|0x3050
end_define

begin_comment
comment|/* second serial interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_TIMER0_INT_MAP
value|0x3060
end_define

begin_comment
comment|/* timer 0 interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_TIMER1_INT_MAP
value|0x3068
end_define

begin_comment
comment|/* timer 1 interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_UE_INT_MAP
value|0x3070
end_define

begin_comment
comment|/* UE interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_CE_INT_MAP
value|0x3078
end_define

begin_comment
comment|/* CE interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_ASYNC_INT_MAP
value|0x3080
end_define

begin_comment
comment|/* SBUS error interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_PWRMGT_INT_MAP
value|0x3088
end_define

begin_comment
comment|/* power mgmt wake interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_UPAGR_INT_MAP
value|0x3090
end_define

begin_comment
comment|/* UPA graphics interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|SBR_RESERVED_INT_MAP
value|0x3098
end_define

begin_comment
comment|/* reserved interrupt map reg */
end_comment

begin_comment
comment|/*  * Note: clear interrupt 0 registers are not really used  */
end_comment

begin_define
define|#
directive|define
name|SBR_SLOT0_INT_CLR
value|0x3400
end_define

begin_comment
comment|/* SBUS slot 0 clear int regs 0..7 */
end_comment

begin_define
define|#
directive|define
name|SBR_SLOT1_INT_CLR
value|0x3440
end_define

begin_comment
comment|/* SBUS slot 1 clear int regs 0..7 */
end_comment

begin_define
define|#
directive|define
name|SBR_SLOT2_INT_CLR
value|0x3480
end_define

begin_comment
comment|/* SBUS slot 2 clear int regs 0..7 */
end_comment

begin_define
define|#
directive|define
name|SBR_SLOT3_INT_CLR
value|0x34c0
end_define

begin_comment
comment|/* SBUS slot 3 clear int regs 0..7 */
end_comment

begin_define
define|#
directive|define
name|SBR_SCSI_INT_CLR
value|0x3800
end_define

begin_comment
comment|/* SCSI clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_ETHER_INT_CLR
value|0x3808
end_define

begin_comment
comment|/* ethernet clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_BPP_INT_CLR
value|0x3810
end_define

begin_comment
comment|/* parallel clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_AUDIO_INT_CLR
value|0x3818
end_define

begin_comment
comment|/* audio clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_POWER_INT_CLR
value|0x3820
end_define

begin_comment
comment|/* power fail clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_SKBDMS_INT_CLR
value|0x3828
end_define

begin_comment
comment|/* serial/kbd/mouse clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_FD_INT_CLR
value|0x3830
end_define

begin_comment
comment|/* floppy clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_THERM_INT_CLR
value|0x3838
end_define

begin_comment
comment|/* thermal warn clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_KBD_INT_CLR
value|0x3840
end_define

begin_comment
comment|/* kbd [unused] clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_MOUSE_INT_CLR
value|0x3848
end_define

begin_comment
comment|/* mouse [unused] clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_SERIAL_INT_CLR
value|0x3850
end_define

begin_comment
comment|/* second serial clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_TIMER0_INT_CLR
value|0x3860
end_define

begin_comment
comment|/* timer 0 clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_TIMER1_INT_CLR
value|0x3868
end_define

begin_comment
comment|/* timer 1 clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_UE_INT_CLR
value|0x3870
end_define

begin_comment
comment|/* UE clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_CE_INT_CLR
value|0x3878
end_define

begin_comment
comment|/* CE clear int reg */
end_comment

begin_define
define|#
directive|define
name|SBR_ASYNC_INT_CLR
value|0x3880
end_define

begin_comment
comment|/* SBUS error clr interrupt reg */
end_comment

begin_define
define|#
directive|define
name|SBR_PWRMGT_INT_CLR
value|0x3888
end_define

begin_comment
comment|/* power mgmt wake clr interrupt reg */
end_comment

begin_define
define|#
directive|define
name|SBR_TC0
value|0x3c00
end_define

begin_comment
comment|/* timer/counter 0 */
end_comment

begin_define
define|#
directive|define
name|SBR_TC1
value|0x3c10
end_define

begin_comment
comment|/* timer/counter 1 */
end_comment

begin_define
define|#
directive|define
name|SBR_IOMMU_SVADIAG
value|0x4400
end_define

begin_comment
comment|/* SBUS virtual addr diag reg */
end_comment

begin_define
define|#
directive|define
name|SBR_IOMMU_QUEUE_DIAG
value|0x4500
end_define

begin_comment
comment|/* IOMMU LRU queue diag 0..15 */
end_comment

begin_define
define|#
directive|define
name|SBR_IOMMU_TLB_TAG_DIAG
value|0x4580
end_define

begin_comment
comment|/* TLB tag diag 0..15 */
end_comment

begin_define
define|#
directive|define
name|SBR_IOMMU_TLB_DATA_DIAG
value|0x4600
end_define

begin_comment
comment|/* TLB data RAM diag 0..31 */
end_comment

begin_define
define|#
directive|define
name|SBR_INT_DIAG
value|0x4800
end_define

begin_comment
comment|/* SBUS int state diag reg */
end_comment

begin_define
define|#
directive|define
name|SBR_OBIO_DIAG
value|0x4808
end_define

begin_comment
comment|/* OBIO and misc int state diag reg */
end_comment

begin_define
define|#
directive|define
name|SBR_STRBUF_DIAG
value|0x5000
end_define

begin_comment
comment|/* Streaming buffer diag regs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SPARC64_SBUS_SBUSREG_H_ */
end_comment

end_unit

