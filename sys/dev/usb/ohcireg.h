begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ohcireg.h,v 1.17 2000/04/01 09:27:35 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_PCI_OHCIREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_PCI_OHCIREG_H_
end_define

begin_comment
comment|/*** PCI config registers ***/
end_comment

begin_define
define|#
directive|define
name|PCI_CBMEM
value|0x10
end_define

begin_comment
comment|/* configuration base memory */
end_comment

begin_define
define|#
directive|define
name|PCI_INTERFACE_OHCI
value|0x10
end_define

begin_comment
comment|/*** OHCI registers */
end_comment

begin_define
define|#
directive|define
name|OHCI_REVISION
value|0x00
end_define

begin_comment
comment|/* OHCI revision # */
end_comment

begin_define
define|#
directive|define
name|OHCI_REV_LO
parameter_list|(
name|rev
parameter_list|)
value|((rev)&0xf)
end_define

begin_define
define|#
directive|define
name|OHCI_REV_HI
parameter_list|(
name|rev
parameter_list|)
value|(((rev)>>4)&0xf)
end_define

begin_define
define|#
directive|define
name|OHCI_REV_LEGACY
parameter_list|(
name|rev
parameter_list|)
value|((rev)& 0x100)
end_define

begin_define
define|#
directive|define
name|OHCI_CONTROL
value|0x04
end_define

begin_define
define|#
directive|define
name|OHCI_CBSR_MASK
value|0x00000003
end_define

begin_comment
comment|/* Control/Bulk Service Ratio */
end_comment

begin_define
define|#
directive|define
name|OHCI_RATIO_1_1
value|0x00000000
end_define

begin_define
define|#
directive|define
name|OHCI_RATIO_1_2
value|0x00000001
end_define

begin_define
define|#
directive|define
name|OHCI_RATIO_1_3
value|0x00000002
end_define

begin_define
define|#
directive|define
name|OHCI_RATIO_1_4
value|0x00000003
end_define

begin_define
define|#
directive|define
name|OHCI_PLE
value|0x00000004
end_define

begin_comment
comment|/* Periodic List Enable */
end_comment

begin_define
define|#
directive|define
name|OHCI_IE
value|0x00000008
end_define

begin_comment
comment|/* Isochronous Enable */
end_comment

begin_define
define|#
directive|define
name|OHCI_CLE
value|0x00000010
end_define

begin_comment
comment|/* Control List Enable */
end_comment

begin_define
define|#
directive|define
name|OHCI_BLE
value|0x00000020
end_define

begin_comment
comment|/* Bulk List Enable */
end_comment

begin_define
define|#
directive|define
name|OHCI_HCFS_MASK
value|0x000000c0
end_define

begin_comment
comment|/* HostControllerFunctionalState */
end_comment

begin_define
define|#
directive|define
name|OHCI_HCFS_RESET
value|0x00000000
end_define

begin_define
define|#
directive|define
name|OHCI_HCFS_RESUME
value|0x00000040
end_define

begin_define
define|#
directive|define
name|OHCI_HCFS_OPERATIONAL
value|0x00000080
end_define

begin_define
define|#
directive|define
name|OHCI_HCFS_SUSPEND
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|OHCI_IR
value|0x00000100
end_define

begin_comment
comment|/* Interrupt Routing */
end_comment

begin_define
define|#
directive|define
name|OHCI_RWC
value|0x00000200
end_define

begin_comment
comment|/* Remote Wakeup Connected */
end_comment

begin_define
define|#
directive|define
name|OHCI_RWE
value|0x00000400
end_define

begin_comment
comment|/* Remote Wakeup Enabled */
end_comment

begin_define
define|#
directive|define
name|OHCI_COMMAND_STATUS
value|0x08
end_define

begin_define
define|#
directive|define
name|OHCI_HCR
value|0x00000001
end_define

begin_comment
comment|/* Host Controller Reset */
end_comment

begin_define
define|#
directive|define
name|OHCI_CLF
value|0x00000002
end_define

begin_comment
comment|/* Control List Filled */
end_comment

begin_define
define|#
directive|define
name|OHCI_BLF
value|0x00000004
end_define

begin_comment
comment|/* Bulk List Filled */
end_comment

begin_define
define|#
directive|define
name|OHCI_OCR
value|0x00000008
end_define

begin_comment
comment|/* Ownership Change Request */
end_comment

begin_define
define|#
directive|define
name|OHCI_SOC_MASK
value|0x00030000
end_define

begin_comment
comment|/* Scheduling Overrun Count */
end_comment

begin_define
define|#
directive|define
name|OHCI_INTERRUPT_STATUS
value|0x0c
end_define

begin_define
define|#
directive|define
name|OHCI_SO
value|0x00000001
end_define

begin_comment
comment|/* Scheduling Overrun */
end_comment

begin_define
define|#
directive|define
name|OHCI_WDH
value|0x00000002
end_define

begin_comment
comment|/* Writeback Done Head */
end_comment

begin_define
define|#
directive|define
name|OHCI_SF
value|0x00000004
end_define

begin_comment
comment|/* Start of Frame */
end_comment

begin_define
define|#
directive|define
name|OHCI_RD
value|0x00000008
end_define

begin_comment
comment|/* Resume Detected */
end_comment

begin_define
define|#
directive|define
name|OHCI_UE
value|0x00000010
end_define

begin_comment
comment|/* Unrecoverable Error */
end_comment

begin_define
define|#
directive|define
name|OHCI_FNO
value|0x00000020
end_define

begin_comment
comment|/* Frame Number Overflow */
end_comment

begin_define
define|#
directive|define
name|OHCI_RHSC
value|0x00000040
end_define

begin_comment
comment|/* Root Hub Status Change */
end_comment

begin_define
define|#
directive|define
name|OHCI_OC
value|0x40000000
end_define

begin_comment
comment|/* Ownership Change */
end_comment

begin_define
define|#
directive|define
name|OHCI_MIE
value|0x80000000
end_define

begin_comment
comment|/* Master Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|OHCI_INTERRUPT_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|OHCI_INTERRUPT_DISABLE
value|0x14
end_define

begin_define
define|#
directive|define
name|OHCI_HCCA
value|0x18
end_define

begin_define
define|#
directive|define
name|OHCI_PERIOD_CURRENT_ED
value|0x1c
end_define

begin_define
define|#
directive|define
name|OHCI_CONTROL_HEAD_ED
value|0x20
end_define

begin_define
define|#
directive|define
name|OHCI_CONTROL_CURRENT_ED
value|0x24
end_define

begin_define
define|#
directive|define
name|OHCI_BULK_HEAD_ED
value|0x28
end_define

begin_define
define|#
directive|define
name|OHCI_BULK_CURRENT_ED
value|0x2c
end_define

begin_define
define|#
directive|define
name|OHCI_DONE_HEAD
value|0x30
end_define

begin_define
define|#
directive|define
name|OHCI_FM_INTERVAL
value|0x34
end_define

begin_define
define|#
directive|define
name|OHCI_GET_IVAL
parameter_list|(
name|s
parameter_list|)
value|((s)& 0x3fff)
end_define

begin_define
define|#
directive|define
name|OHCI_GET_FSMPS
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 16)& 0x7fff)
end_define

begin_define
define|#
directive|define
name|OHCI_FIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|OHCI_FM_REMAINING
value|0x38
end_define

begin_define
define|#
directive|define
name|OHCI_FM_NUMBER
value|0x3c
end_define

begin_define
define|#
directive|define
name|OHCI_PERIODIC_START
value|0x40
end_define

begin_define
define|#
directive|define
name|OHCI_LS_THRESHOLD
value|0x44
end_define

begin_define
define|#
directive|define
name|OHCI_RH_DESCRIPTOR_A
value|0x48
end_define

begin_define
define|#
directive|define
name|OHCI_GET_NDP
parameter_list|(
name|s
parameter_list|)
value|((s)& 0xff)
end_define

begin_define
define|#
directive|define
name|OHCI_PSM
value|0x0100
end_define

begin_comment
comment|/* Power Switching Mode */
end_comment

begin_define
define|#
directive|define
name|OHCI_NPS
value|0x0200
end_define

begin_comment
comment|/* No Power Switching */
end_comment

begin_define
define|#
directive|define
name|OHCI_DT
value|0x0400
end_define

begin_comment
comment|/* Device Type */
end_comment

begin_define
define|#
directive|define
name|OHCI_OCPM
value|0x0800
end_define

begin_comment
comment|/* Overcurrent Protection Mode */
end_comment

begin_define
define|#
directive|define
name|OHCI_NOCP
value|0x1000
end_define

begin_comment
comment|/* No Overcurrent Protection */
end_comment

begin_define
define|#
directive|define
name|OHCI_GET_POTPGT
parameter_list|(
name|s
parameter_list|)
value|((s)>> 24)
end_define

begin_define
define|#
directive|define
name|OHCI_RH_DESCRIPTOR_B
value|0x4c
end_define

begin_define
define|#
directive|define
name|OHCI_RH_STATUS
value|0x50
end_define

begin_define
define|#
directive|define
name|OHCI_LPS
value|0x00000001
end_define

begin_comment
comment|/* Local Power Status */
end_comment

begin_define
define|#
directive|define
name|OHCI_OCI
value|0x00000002
end_define

begin_comment
comment|/* OverCurrent Indicator */
end_comment

begin_define
define|#
directive|define
name|OHCI_DRWE
value|0x00008000
end_define

begin_comment
comment|/* Device Remote Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|OHCI_LPSC
value|0x00010000
end_define

begin_comment
comment|/* Local Power Status Change */
end_comment

begin_define
define|#
directive|define
name|OHCI_CCIC
value|0x00020000
end_define

begin_comment
comment|/* OverCurrent Indicator Change */
end_comment

begin_define
define|#
directive|define
name|OHCI_CRWE
value|0x80000000
end_define

begin_comment
comment|/* Clear Remote Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|OHCI_RH_PORT_STATUS
parameter_list|(
name|n
parameter_list|)
value|(0x50 + (n)*4)
end_define

begin_comment
comment|/* 1 based indexing */
end_comment

begin_define
define|#
directive|define
name|OHCI_LES
value|(OHCI_PLE | OHCI_IE | OHCI_CLE | OHCI_BLE)
end_define

begin_define
define|#
directive|define
name|OHCI_ALL_INTRS
value|(OHCI_SO | OHCI_WDH | OHCI_SF | OHCI_RD | OHCI_UE | \                         OHCI_FNO | OHCI_RHSC | OHCI_OC)
end_define

begin_define
define|#
directive|define
name|OHCI_NORMAL_INTRS
value|(OHCI_SO | OHCI_WDH | OHCI_RD | OHCI_UE | OHCI_RHSC)
end_define

begin_define
define|#
directive|define
name|OHCI_FSMPS
parameter_list|(
name|i
parameter_list|)
value|(((i-210)*6/7)<< 16)
end_define

begin_define
define|#
directive|define
name|OHCI_PERIODIC
parameter_list|(
name|i
parameter_list|)
value|((i)*9/10)
end_define

begin_typedef
typedef|typedef
name|u_int32_t
name|ohci_physaddr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OHCI_NO_INTRS
value|32
end_define

begin_struct
struct|struct
name|ohci_hcca
block|{
name|ohci_physaddr_t
name|hcca_interrupt_table
index|[
name|OHCI_NO_INTRS
index|]
decl_stmt|;
name|u_int32_t
name|hcca_frame_number
decl_stmt|;
name|ohci_physaddr_t
name|hcca_done_head
decl_stmt|;
define|#
directive|define
name|OHCI_DONE_INTRS
value|1
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OHCI_HCCA_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|OHCI_HCCA_ALIGN
value|256
end_define

begin_define
define|#
directive|define
name|OHCI_PAGE_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|OHCI_PAGE
parameter_list|(
name|x
parameter_list|)
value|((x)&~ 0xfff)
end_define

begin_define
define|#
directive|define
name|OHCI_PAGE_OFFSET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xfff)
end_define

begin_define
define|#
directive|define
name|OHCI_PAGE_MASK
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xfff)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|ed_flags
decl_stmt|;
define|#
directive|define
name|OHCI_ED_GET_FA
parameter_list|(
name|s
parameter_list|)
value|((s)& 0x7f)
define|#
directive|define
name|OHCI_ED_ADDRMASK
value|0x0000007f
define|#
directive|define
name|OHCI_ED_SET_FA
parameter_list|(
name|s
parameter_list|)
value|(s)
define|#
directive|define
name|OHCI_ED_GET_EN
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 7)& 0xf)
define|#
directive|define
name|OHCI_ED_SET_EN
parameter_list|(
name|s
parameter_list|)
value|((s)<< 7)
define|#
directive|define
name|OHCI_ED_DIR_MASK
value|0x00001800
define|#
directive|define
name|OHCI_ED_DIR_TD
value|0x00000000
define|#
directive|define
name|OHCI_ED_DIR_OUT
value|0x00000800
define|#
directive|define
name|OHCI_ED_DIR_IN
value|0x00001000
define|#
directive|define
name|OHCI_ED_SPEED
value|0x00002000
define|#
directive|define
name|OHCI_ED_SKIP
value|0x00004000
define|#
directive|define
name|OHCI_ED_FORMAT_GEN
value|0x00000000
define|#
directive|define
name|OHCI_ED_FORMAT_ISO
value|0x00008000
define|#
directive|define
name|OHCI_ED_GET_MAXP
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 16)& 0x07ff)
define|#
directive|define
name|OHCI_ED_SET_MAXP
parameter_list|(
name|s
parameter_list|)
value|((s)<< 16)
define|#
directive|define
name|OHCI_ED_MAXPMASK
value|(0x7ff<< 16)
name|ohci_physaddr_t
name|ed_tailp
decl_stmt|;
name|ohci_physaddr_t
name|ed_headp
decl_stmt|;
define|#
directive|define
name|OHCI_HALTED
value|0x00000001
define|#
directive|define
name|OHCI_TOGGLECARRY
value|0x00000002
define|#
directive|define
name|OHCI_HEADMASK
value|0xfffffffc
name|ohci_physaddr_t
name|ed_nexted
decl_stmt|;
block|}
name|ohci_ed_t
typedef|;
end_typedef

begin_comment
comment|/* #define OHCI_ED_SIZE 16 */
end_comment

begin_define
define|#
directive|define
name|OHCI_ED_ALIGN
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|td_flags
decl_stmt|;
define|#
directive|define
name|OHCI_TD_R
value|0x00040000
comment|/* Buffer Rounding  */
define|#
directive|define
name|OHCI_TD_DP_MASK
value|0x00180000
comment|/* Direction / PID */
define|#
directive|define
name|OHCI_TD_SETUP
value|0x00000000
define|#
directive|define
name|OHCI_TD_OUT
value|0x00080000
define|#
directive|define
name|OHCI_TD_IN
value|0x00100000
define|#
directive|define
name|OHCI_TD_GET_DI
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 7)
comment|/* Delay Interrupt */
define|#
directive|define
name|OHCI_TD_SET_DI
parameter_list|(
name|x
parameter_list|)
value|((x)<< 21)
define|#
directive|define
name|OHCI_TD_NOINTR
value|0x00e00000
define|#
directive|define
name|OHCI_TD_TOGGLE_CARRY
value|0x00000000
define|#
directive|define
name|OHCI_TD_TOGGLE_0
value|0x02000000
define|#
directive|define
name|OHCI_TD_TOGGLE_1
value|0x03000000
define|#
directive|define
name|OHCI_TD_GET_EC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 3)
comment|/* Error Count */
define|#
directive|define
name|OHCI_TD_GET_CC
parameter_list|(
name|x
parameter_list|)
value|((x)>> 28)
comment|/* Condition Code */
define|#
directive|define
name|OHCI_TD_NOCC
value|0xf0000000
name|ohci_physaddr_t
name|td_cbp
decl_stmt|;
comment|/* Current Buffer Pointer */
name|ohci_physaddr_t
name|td_nexttd
decl_stmt|;
comment|/* Next TD */
name|ohci_physaddr_t
name|td_be
decl_stmt|;
comment|/* Buffer End */
block|}
name|ohci_td_t
typedef|;
end_typedef

begin_comment
comment|/* #define OHCI_TD_SIZE 16 */
end_comment

begin_define
define|#
directive|define
name|OHCI_TD_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|OHCI_ITD_NOFFSET
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|itd_flags
decl_stmt|;
define|#
directive|define
name|OHCI_ITD_GET_SF
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0000ffff)
define|#
directive|define
name|OHCI_ITD_SET_SF
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffff)
define|#
directive|define
name|OHCI_ITD_GET_DI
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 7)
comment|/* Delay Interrupt */
define|#
directive|define
name|OHCI_ITD_SET_DI
parameter_list|(
name|x
parameter_list|)
value|((x)<< 21)
define|#
directive|define
name|OHCI_ITD_NOINTR
value|0x00e00000
define|#
directive|define
name|OHCI_ITD_GET_FC
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 24)& 7)+1)
comment|/* Frame Count */
define|#
directive|define
name|OHCI_ITD_SET_FC
parameter_list|(
name|x
parameter_list|)
value|(((x)-1)<< 24)
define|#
directive|define
name|OHCI_ITD_GET_CC
parameter_list|(
name|x
parameter_list|)
value|((x)>> 28)
comment|/* Condition Code */
define|#
directive|define
name|OHCI_ITD_NOCC
value|0xf0000000
name|ohci_physaddr_t
name|itd_bp0
decl_stmt|;
comment|/* Buffer Page 0 */
name|ohci_physaddr_t
name|itd_nextitd
decl_stmt|;
comment|/* Next ITD */
name|ohci_physaddr_t
name|itd_be
decl_stmt|;
comment|/* Buffer End */
name|u_int16_t
name|itd_offset
index|[
name|OHCI_ITD_NOFFSET
index|]
decl_stmt|;
comment|/* Buffer offsets */
define|#
directive|define
name|itd_pswn
value|itd_offset
comment|/* Packet Status Word*/
define|#
directive|define
name|OHCI_ITD_PAGE_SELECT
value|0x00001000
define|#
directive|define
name|OHCI_ITD_MK_OFFS
parameter_list|(
name|len
parameter_list|)
value|(0xe000 | ((len)& 0x1fff))
define|#
directive|define
name|OHCI_ITD_PSW_LENGTH
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xfff)
comment|/* Transfer length */
define|#
directive|define
name|OHCI_ITD_PSW_GET_CC
parameter_list|(
name|x
parameter_list|)
value|((x)>> 12)
comment|/* Condition Code */
block|}
name|ohci_itd_t
typedef|;
end_typedef

begin_comment
comment|/* #define OHCI_ITD_SIZE 32 */
end_comment

begin_define
define|#
directive|define
name|OHCI_ITD_ALIGN
value|32
end_define

begin_define
define|#
directive|define
name|OHCI_CC_NO_ERROR
value|0
end_define

begin_define
define|#
directive|define
name|OHCI_CC_CRC
value|1
end_define

begin_define
define|#
directive|define
name|OHCI_CC_BIT_STUFFING
value|2
end_define

begin_define
define|#
directive|define
name|OHCI_CC_DATA_TOGGLE_MISMATCH
value|3
end_define

begin_define
define|#
directive|define
name|OHCI_CC_STALL
value|4
end_define

begin_define
define|#
directive|define
name|OHCI_CC_DEVICE_NOT_RESPONDING
value|5
end_define

begin_define
define|#
directive|define
name|OHCI_CC_PID_CHECK_FAILURE
value|6
end_define

begin_define
define|#
directive|define
name|OHCI_CC_UNEXPECTED_PID
value|7
end_define

begin_define
define|#
directive|define
name|OHCI_CC_DATA_OVERRUN
value|8
end_define

begin_define
define|#
directive|define
name|OHCI_CC_DATA_UNDERRUN
value|9
end_define

begin_define
define|#
directive|define
name|OHCI_CC_BUFFER_OVERRUN
value|12
end_define

begin_define
define|#
directive|define
name|OHCI_CC_BUFFER_UNDERRUN
value|13
end_define

begin_define
define|#
directive|define
name|OHCI_CC_NOT_ACCESSED
value|15
end_define

begin_comment
comment|/* Some delay needed when changing certain registers. */
end_comment

begin_define
define|#
directive|define
name|OHCI_ENABLE_POWER_DELAY
value|5
end_define

begin_define
define|#
directive|define
name|OHCI_READ_DESC_DELAY
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_PCI_OHCIREG_H_ */
end_comment

end_unit

