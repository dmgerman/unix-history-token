begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998, 1999 Eduardo E. Horvath  * Copyright (c) 1999 Matthew R. Green  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: psychoreg.h,v 1.8 2001/09/10 16:17:06 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_PCI_PSYCHOREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_PCI_PSYCHOREG_H_
end_define

begin_comment
comment|/*  * Sun4u PCI definitions.  Here's where we deal w/the machine  * dependencies of psycho and the PCI controller on the UltraIIi.  *  * All PCI registers are bit-swapped, however they are not byte-swapped.  * This means that they must be accessed using little-endian access modes,  * either map the pages little-endian or use little-endian ASIs.  *  * PSYCHO implements two PCI buses, A and B.  */
end_comment

begin_struct
struct|struct
name|psychoreg
block|{
struct|struct
name|upareg
block|{
comment|/* UPA port ID register */
comment|/* 1fe.0000.0000 */
name|u_int64_t
name|upa_portid
decl_stmt|;
comment|/* UPA config register */
comment|/* 1fe.0000.0008 */
name|u_int64_t
name|upa_config
decl_stmt|;
block|}
name|sys_upa
struct|;
comment|/* PSYCHO control/status register */
comment|/* 1fe.0000.0010 */
name|u_int64_t
name|psy_csr
decl_stmt|;
comment|/*  	 * 63     59     55     50     45     4        3       2     1      0 	 * +------+------+------+------+--//---+--------+-------+-----+------+ 	 * | IMPL | VERS | MID  | IGN  |  xxx  | APCKEN | APERR | IAP | MODE | 	 * +------+------+------+------+--//---+--------+-------+-----+------+ 	 * 	 */
define|#
directive|define
name|PSYCHO_GCSR_IMPL
parameter_list|(
name|csr
parameter_list|)
value|((u_int)(((csr)>> 60)& 0xf))
define|#
directive|define
name|PSYCHO_GCSR_VERS
parameter_list|(
name|csr
parameter_list|)
value|((u_int)(((csr)>> 56)& 0xf))
define|#
directive|define
name|PSYCHO_GCSR_MID
parameter_list|(
name|csr
parameter_list|)
value|((u_int)(((csr)>> 51)& 0x1f))
define|#
directive|define
name|PSYCHO_GCSR_IGN
parameter_list|(
name|csr
parameter_list|)
value|((u_int)(((csr)>> 46)& 0x1f))
define|#
directive|define
name|PSYCHO_CSR_APCKEN
value|8
comment|/* UPA addr parity check enable */
define|#
directive|define
name|PSYCHO_CSR_APERR
value|4
comment|/* UPA addr parity error */
define|#
directive|define
name|PSYCHO_CSR_IAP
value|2
comment|/* invert UPA address parity */
define|#
directive|define
name|PSYCHO_CSR_MODE
value|1
comment|/* UPA/PCI handshake */
name|u_int64_t
name|pad0
decl_stmt|;
comment|/* ECC control register */
comment|/* 1fe.0000.0020 */
name|u_int64_t
name|psy_ecccr
decl_stmt|;
comment|/* 1fe.0000.0028 */
name|u_int64_t
name|reserved
decl_stmt|;
comment|/* Uncorrectable Error AFSR */
comment|/* 1fe.0000.0030 */
name|u_int64_t
name|psy_ue_afsr
decl_stmt|;
comment|/* Uncorrectable Error AFAR */
comment|/* 1fe.0000.0038 */
name|u_int64_t
name|psy_ue_afar
decl_stmt|;
comment|/* Correctable Error AFSR */
comment|/* 1fe.0000.0040 */
name|u_int64_t
name|psy_ce_afsr
decl_stmt|;
comment|/* Correctable Error AFAR */
comment|/* 1fe.0000.0048 */
name|u_int64_t
name|psy_ce_afar
decl_stmt|;
name|u_int64_t
name|pad1
index|[
literal|22
index|]
decl_stmt|;
struct|struct
name|perfmon
block|{
comment|/* Performance monitor control reg */
comment|/* 1fe.0000.0100 */
name|u_int64_t
name|pm_cr
decl_stmt|;
comment|/* Performance monitor counter reg */
comment|/* 1fe.0000.0108 */
name|u_int64_t
name|pm_count
decl_stmt|;
block|}
name|psy_pm
struct|;
name|u_int64_t
name|pad2
index|[
literal|30
index|]
decl_stmt|;
comment|/* 1fe.0000.0200,0210 */
name|struct
name|iommureg
name|psy_iommu
decl_stmt|;
name|u_int64_t
name|pad3
index|[
literal|317
index|]
decl_stmt|;
comment|/* PCI bus a slot 0 irq map reg */
comment|/* 1fe.0000.0c00 */
name|u_int64_t
name|pcia0_int_map
decl_stmt|;
comment|/* PCI bus a slot 1 irq map reg */
comment|/* 1fe.0000.0c08 */
name|u_int64_t
name|pcia1_int_map
decl_stmt|;
comment|/* PCI bus a slot 2 irq map reg (IIi) */
comment|/* 1fe.0000.0c10 */
name|u_int64_t
name|pcia2_int_map
decl_stmt|;
comment|/* PCI bus a slot 3 irq map reg (IIi) */
comment|/* 1fe.0000.0c18 */
name|u_int64_t
name|pcia3_int_map
decl_stmt|;
comment|/* PCI bus b slot 0 irq map reg */
comment|/* 1fe.0000.0c20 */
name|u_int64_t
name|pcib0_int_map
decl_stmt|;
comment|/* PCI bus b slot 1 irq map reg */
comment|/* 1fe.0000.0c28 */
name|u_int64_t
name|pcib1_int_map
decl_stmt|;
comment|/* PCI bus b slot 2 irq map reg */
comment|/* 1fe.0000.0c30 */
name|u_int64_t
name|pcib2_int_map
decl_stmt|;
comment|/* PCI bus b slot 3 irq map reg */
comment|/* 1fe.0000.0c38 */
name|u_int64_t
name|pcib3_int_map
decl_stmt|;
name|u_int64_t
name|pad4
index|[
literal|120
index|]
decl_stmt|;
comment|/* SCSI interrupt map reg */
comment|/* 1fe.0000.1000 */
name|u_int64_t
name|scsi_int_map
decl_stmt|;
comment|/* ethernet interrupt map reg */
comment|/* 1fe.0000.1008 */
name|u_int64_t
name|ether_int_map
decl_stmt|;
comment|/* parallel interrupt map reg */
comment|/* 1fe.0000.1010 */
name|u_int64_t
name|bpp_int_map
decl_stmt|;
comment|/* audio record interrupt map reg */
comment|/* 1fe.0000.1018 */
name|u_int64_t
name|audior_int_map
decl_stmt|;
comment|/* audio playback interrupt map reg */
comment|/* 1fe.0000.1020 */
name|u_int64_t
name|audiop_int_map
decl_stmt|;
comment|/* power fail interrupt map reg */
comment|/* 1fe.0000.1028 */
name|u_int64_t
name|power_int_map
decl_stmt|;
comment|/* serial/kbd/mouse interrupt map reg */
comment|/* 1fe.0000.1030 */
name|u_int64_t
name|ser_kbd_ms_int_map
decl_stmt|;
comment|/* floppy interrupt map reg */
comment|/* 1fe.0000.1038 */
name|u_int64_t
name|fd_int_map
decl_stmt|;
comment|/* spare interrupt map reg */
comment|/* 1fe.0000.1040 */
name|u_int64_t
name|spare_int_map
decl_stmt|;
comment|/* kbd [unused] interrupt map reg */
comment|/* 1fe.0000.1048 */
name|u_int64_t
name|kbd_int_map
decl_stmt|;
comment|/* mouse [unused] interrupt map reg */
comment|/* 1fe.0000.1050 */
name|u_int64_t
name|mouse_int_map
decl_stmt|;
comment|/* second serial interrupt map reg */
comment|/* 1fe.0000.1058 */
name|u_int64_t
name|serial_int_map
decl_stmt|;
comment|/* timer 0 interrupt map reg */
comment|/* 1fe.0000.1060 */
name|u_int64_t
name|timer0_int_map
decl_stmt|;
comment|/* timer 1 interrupt map reg */
comment|/* 1fe.0000.1068 */
name|u_int64_t
name|timer1_int_map
decl_stmt|;
comment|/* UE interrupt map reg */
comment|/* 1fe.0000.1070 */
name|u_int64_t
name|ue_int_map
decl_stmt|;
comment|/* CE interrupt map reg */
comment|/* 1fe.0000.1078 */
name|u_int64_t
name|ce_int_map
decl_stmt|;
comment|/* PCI bus a error interrupt map reg */
comment|/* 1fe.0000.1080 */
name|u_int64_t
name|pciaerr_int_map
decl_stmt|;
comment|/* PCI bus b error interrupt map reg */
comment|/* 1fe.0000.1088 */
name|u_int64_t
name|pciberr_int_map
decl_stmt|;
comment|/* power mgmt wake interrupt map reg */
comment|/* 1fe.0000.1090 */
name|u_int64_t
name|pwrmgt_int_map
decl_stmt|;
comment|/* FFB0 graphics interrupt map reg */
comment|/* 1fe.0000.1098 */
name|u_int64_t
name|ffb0_int_map
decl_stmt|;
comment|/* FFB1 graphics interrupt map reg */
comment|/* 1fe.0000.10a0 */
name|u_int64_t
name|ffb1_int_map
decl_stmt|;
name|u_int64_t
name|pad5
index|[
literal|107
index|]
decl_stmt|;
comment|/* Note: clear interrupt 0 registers are not really used */
comment|/* PCI a slot 0 clear int regs 0..7 */
comment|/* 1fe.0000.1400-1418 */
name|u_int64_t
name|pcia0_int_clr
index|[
literal|4
index|]
decl_stmt|;
comment|/* PCI a slot 1 clear int regs 0..7 */
comment|/* 1fe.0000.1420-1438 */
name|u_int64_t
name|pcia1_int_clr
index|[
literal|4
index|]
decl_stmt|;
comment|/* PCI a slot 2 clear int regs 0..7 */
comment|/* 1fe.0000.1440-1458 */
name|u_int64_t
name|pcia2_int_clr
index|[
literal|4
index|]
decl_stmt|;
comment|/* PCI a slot 3 clear int regs 0..7 */
comment|/* 1fe.0000.1480-1478 */
name|u_int64_t
name|pcia3_int_clr
index|[
literal|4
index|]
decl_stmt|;
comment|/* PCI b slot 0 clear int regs 0..7 */
comment|/* 1fe.0000.1480-1498 */
name|u_int64_t
name|pcib0_int_clr
index|[
literal|4
index|]
decl_stmt|;
comment|/* PCI b slot 1 clear int regs 0..7 */
comment|/* 1fe.0000.14a0-14b8 */
name|u_int64_t
name|pcib1_int_clr
index|[
literal|4
index|]
decl_stmt|;
comment|/* PCI b slot 2 clear int regs 0..7 */
comment|/* 1fe.0000.14c0-14d8 */
name|u_int64_t
name|pcib2_int_clr
index|[
literal|4
index|]
decl_stmt|;
comment|/* PCI b slot 3 clear int regs 0..7 */
comment|/* 1fe.0000.14d0-14f8 */
name|u_int64_t
name|pcib3_int_clr
index|[
literal|4
index|]
decl_stmt|;
name|u_int64_t
name|pad6
index|[
literal|96
index|]
decl_stmt|;
comment|/* SCSI clear int reg */
comment|/* 1fe.0000.1800 */
name|u_int64_t
name|scsi_int_clr
decl_stmt|;
comment|/* ethernet clear int reg */
comment|/* 1fe.0000.1808 */
name|u_int64_t
name|ether_int_clr
decl_stmt|;
comment|/* parallel clear int reg */
comment|/* 1fe.0000.1810 */
name|u_int64_t
name|bpp_int_clr
decl_stmt|;
comment|/* audio record clear int reg */
comment|/* 1fe.0000.1818 */
name|u_int64_t
name|audior_int_clr
decl_stmt|;
comment|/* audio playback clear int reg */
comment|/* 1fe.0000.1820 */
name|u_int64_t
name|audiop_int_clr
decl_stmt|;
comment|/* power fail clear int reg */
comment|/* 1fe.0000.1828 */
name|u_int64_t
name|power_int_clr
decl_stmt|;
comment|/* serial/kbd/mouse clear int reg */
comment|/* 1fe.0000.1830 */
name|u_int64_t
name|ser_kb_ms_int_clr
decl_stmt|;
comment|/* floppy clear int reg */
comment|/* 1fe.0000.1838 */
name|u_int64_t
name|fd_int_clr
decl_stmt|;
comment|/* spare clear int reg */
comment|/* 1fe.0000.1840 */
name|u_int64_t
name|spare_int_clr
decl_stmt|;
comment|/* kbd [unused] clear int reg */
comment|/* 1fe.0000.1848 */
name|u_int64_t
name|kbd_int_clr
decl_stmt|;
comment|/* mouse [unused] clear int reg */
comment|/* 1fe.0000.1850 */
name|u_int64_t
name|mouse_int_clr
decl_stmt|;
comment|/* second serial clear int reg */
comment|/* 1fe.0000.1858 */
name|u_int64_t
name|serial_clr
decl_stmt|;
comment|/* timer 0 clear int reg */
comment|/* 1fe.0000.1860 */
name|u_int64_t
name|timer0_int_clr
decl_stmt|;
comment|/* timer 1 clear int reg */
comment|/* 1fe.0000.1868 */
name|u_int64_t
name|timer1_int_clr
decl_stmt|;
comment|/* UE clear int reg */
comment|/* 1fe.0000.1870 */
name|u_int64_t
name|ue_int_clr
decl_stmt|;
comment|/* CE clear int reg */
comment|/* 1fe.0000.1878 */
name|u_int64_t
name|ce_int_clr
decl_stmt|;
comment|/* PCI bus a error clear int reg */
comment|/* 1fe.0000.1880 */
name|u_int64_t
name|pciaerr_int_clr
decl_stmt|;
comment|/* PCI bus b error clear int reg */
comment|/* 1fe.0000.1888 */
name|u_int64_t
name|pciberr_int_clr
decl_stmt|;
comment|/* power mgmt wake clr interrupt reg */
comment|/* 1fe.0000.1890 */
name|u_int64_t
name|pwrmgt_int_clr
decl_stmt|;
name|u_int64_t
name|pad7
index|[
literal|45
index|]
decl_stmt|;
comment|/* interrupt retry timer */
comment|/* 1fe.0000.1a00 */
name|u_int64_t
name|intr_retry_timer
decl_stmt|;
name|u_int64_t
name|pad8
index|[
literal|63
index|]
decl_stmt|;
struct|struct
name|timer_counter
block|{
comment|/* timer/counter 0/1 count register */
comment|/* 1fe.0000.1c00,1c10 */
name|u_int64_t
name|tc_count
decl_stmt|;
comment|/* timer/counter 0/1 limit register */
comment|/* 1fe.0000.1c08,1c18 */
name|u_int64_t
name|tc_limit
decl_stmt|;
block|}
name|tc
index|[
literal|2
index|]
struct|;
comment|/* PCI DMA write sync register (IIi) */
comment|/* 1fe.0000.1c20 */
name|u_int64_t
name|pci_dma_write_sync
decl_stmt|;
name|u_int64_t
name|pad9
index|[
literal|123
index|]
decl_stmt|;
struct|struct
name|pci_ctl
block|{
comment|/* PCI a/b control/status register */
comment|/* 1fe.0000.2000,4000 */
name|u_int64_t
name|pci_csr
decl_stmt|;
name|u_int64_t
name|pad10
decl_stmt|;
comment|/* PCI a/b AFSR register */
comment|/* 1fe.0000.2010,4010 */
name|u_int64_t
name|pci_afsr
decl_stmt|;
comment|/* PCI a/b AFAR register */
comment|/* 1fe.0000.2018,4018 */
name|u_int64_t
name|pci_afar
decl_stmt|;
comment|/* PCI a/b diagnostic register */
comment|/* 1fe.0000.2020,4020 */
name|u_int64_t
name|pci_diag
decl_stmt|;
comment|/* PCI target address space reg (IIi)*/
comment|/* 1fe.0000.2028,4028 */
name|u_int64_t
name|pci_tasr
decl_stmt|;
name|u_int64_t
name|pad11
index|[
literal|250
index|]
decl_stmt|;
comment|/* This is really the IOMMU's, not the PCI bus's */
comment|/* 1fe.0000.2800-210 */
name|struct
name|iommu_strbuf
name|pci_strbuf
decl_stmt|;
define|#
directive|define
name|psy_iommu_strbuf
value|psy_pcictl[0].pci_strbuf
name|u_int64_t
name|pad12
index|[
literal|765
index|]
decl_stmt|;
block|}
name|psy_pcictl
index|[
literal|2
index|]
struct|;
comment|/* For PCI a and b */
comment|/* 	 * NB: FFB0 and FFB1 intr map regs also appear at 1fe.0000.6000 and 	 * 1fe.0000.8000 respectively 	 */
name|u_int64_t
name|pad13
index|[
literal|2048
index|]
decl_stmt|;
comment|/* DMA scoreboard diag reg 0 */
comment|/* 1fe.0000.a000 */
name|u_int64_t
name|dma_scb_diag0
decl_stmt|;
comment|/* DMA scoreboard diag reg 1 */
comment|/* 1fe.0000.a008 */
name|u_int64_t
name|dma_scb_diag1
decl_stmt|;
name|u_int64_t
name|pad14
index|[
literal|126
index|]
decl_stmt|;
comment|/* IOMMU virtual addr diag reg */
comment|/* 1fe.0000.a400 */
name|u_int64_t
name|iommu_svadiag
decl_stmt|;
comment|/* IOMMU TLB tag compare diag reg */
comment|/* 1fe.0000.a408 */
name|u_int64_t
name|iommu_tlb_comp_diag
decl_stmt|;
name|u_int64_t
name|pad15
index|[
literal|30
index|]
decl_stmt|;
comment|/* IOMMU LRU queue diag */
comment|/* 1fe.0000.a500-a578 */
name|u_int64_t
name|iommu_queue_diag
index|[
literal|16
index|]
decl_stmt|;
comment|/* TLB tag diag */
comment|/* 1fe.0000.a580-a5f8 */
name|u_int64_t
name|tlb_tag_diag
index|[
literal|16
index|]
decl_stmt|;
comment|/* TLB data RAM diag */
comment|/* 1fe.0000.a600-a678 */
name|u_int64_t
name|tlb_data_diag
index|[
literal|16
index|]
decl_stmt|;
name|u_int64_t
name|pad16
index|[
literal|48
index|]
decl_stmt|;
comment|/* PCI int state diag reg */
comment|/* 1fe.0000.a800 */
name|u_int64_t
name|pci_int_diag
decl_stmt|;
comment|/* OBIO and misc int state diag reg */
comment|/* 1fe.0000.a808 */
name|u_int64_t
name|obio_int_diag
decl_stmt|;
name|u_int64_t
name|pad17
index|[
literal|254
index|]
decl_stmt|;
struct|struct
name|strbuf_diag
block|{
comment|/* streaming buffer data RAM diag */
comment|/* 1fe.0000.b000-b3f8 */
name|u_int64_t
name|strbuf_data_diag
index|[
literal|128
index|]
decl_stmt|;
comment|/* streaming buffer error status diag */
comment|/* 1fe.0000.b400-b7f8 */
name|u_int64_t
name|strbuf_error_diag
index|[
literal|128
index|]
decl_stmt|;
comment|/* streaming buffer page tag diag */
comment|/* 1fe.0000.b800-b878 */
name|u_int64_t
name|strbuf_pg_tag_diag
index|[
literal|16
index|]
decl_stmt|;
name|u_int64_t
name|pad18
index|[
literal|16
index|]
decl_stmt|;
comment|/* streaming buffer line tag diag */
comment|/* 1fe.0000.b900-b978 */
name|u_int64_t
name|strbuf_ln_tag_diag
index|[
literal|16
index|]
decl_stmt|;
name|u_int64_t
name|pad19
index|[
literal|208
index|]
decl_stmt|;
block|}
name|psy_strbufdiag
index|[
literal|2
index|]
struct|;
comment|/* For PCI a and b */
comment|/*  	 * Here is the rest of the map, which we're not specifying: 	 * 	 * 1fe.0100.0000 - 1fe.01ff.ffff	PCI configuration space 	 * 1fe.0100.0000 - 1fe.0100.00ff	PCI B configuration header 	 * 1fe.0101.0000 - 1fe.0101.00ff	PCI A configuration header 	 * 1fe.0200.0000 - 1fe.0200.ffff	PCI A I/O space 	 * 1fe.0201.0000 - 1fe.0201.ffff	PCI B I/O space 	 * 1ff.0000.0000 - 1ff.7fff.ffff	PCI A memory space 	 * 1ff.8000.0000 - 1ff.ffff.ffff	PCI B memory space 	 * 	 * NB: config and I/O space can use 1-4 byte accesses, not 8 byte 	 * accesses.  Memory space can use any sized accesses. 	 * 	 * Note that the SUNW,sabre/SUNW,simba combinations found on the 	 * Ultra5 and Ultra10 machines uses slightly differrent addresses 	 * than the above.  This is mostly due to the fact that the APB is 	 * a multi-function PCI device with two PCI bridges, and the U2P is 	 * two separate PCI bridges.  It uses the same PCI configuration 	 * space, though the configuration header for each PCI bus is 	 * located differently due to the SUNW,simba PCI busses being 	 * function 0 and function 1 of the APB, whereas the psycho's are 	 * each their own PCI device.  The I/O and memory spaces are each 	 * split into 8 equally sized areas (8x2MB blocks for I/O space, 	 * and 8x512MB blocks for memory space).  These are allocated in to 	 * either PCI A or PCI B, or neither in the APB's `I/O Address Map 	 * Register A/B' (0xde) and `Memory Address Map Register A/B' (0xdf) 	 * registers of each simba.  We must ensure that both of the 	 * following are correct (the prom should do this for us): 	 * 	 *    (PCI A Memory Address Map)& (PCI B Memory Address Map) == 0 	 * 	 *    (PCI A I/O Address Map)& (PCI B I/O Address Map) == 0 	 * 	 * 1fe.0100.0000 - 1fe.01ff.ffff	PCI configuration space 	 * 1fe.0100.0800 - 1fe.0100.08ff	PCI B configuration header 	 * 1fe.0100.0900 - 1fe.0100.09ff	PCI A configuration header 	 * 1fe.0200.0000 - 1fe.02ff.ffff	PCI I/O space (divided) 	 * 1ff.0000.0000 - 1ff.ffff.ffff	PCI memory space (divided)  	 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PSYCHO_CONF_SIZE
value|0x1000000
end_define

begin_define
define|#
directive|define
name|PSYCHO_CONF_BUS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PSYCHO_CONF_DEV_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|PSYCHO_CONF_FUNC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PSYCHO_CONF_REG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PSYCHO_IO_SIZE
value|0x1000000
end_define

begin_define
define|#
directive|define
name|PSYCHO_MEM_SIZE
value|0x100000000
end_define

begin_define
define|#
directive|define
name|PSYCHO_CONF_OFF
parameter_list|(
name|bus
parameter_list|,
name|slot
parameter_list|,
name|func
parameter_list|,
name|reg
parameter_list|)
define|\
value|(((bus)<< PSYCHO_CONF_BUS_SHIFT) |				\ 	((slot)<< PSYCHO_CONF_DEV_SHIFT) |				\ 	((func)<< PSYCHO_CONF_FUNC_SHIFT) |				\ 	((reg)<< PSYCHO_CONF_REG_SHIFT))
end_define

begin_comment
comment|/* what the bits mean! */
end_comment

begin_comment
comment|/* PCI [a|b] control/status register */
end_comment

begin_comment
comment|/* note that the sabre only has one set of PCI control/status registers */
end_comment

begin_define
define|#
directive|define
name|PCICTL_MRLM
value|0x0000001000000000
end_define

begin_comment
comment|/* Memory Read Line/Multiple */
end_comment

begin_define
define|#
directive|define
name|PCICTL_SERR
value|0x0000000400000000
end_define

begin_comment
comment|/* SERR asserted; W1C */
end_comment

begin_define
define|#
directive|define
name|PCICTL_ARB_PARK
value|0x0000000000200000
end_define

begin_comment
comment|/* PCI arbitration parking */
end_comment

begin_define
define|#
directive|define
name|PCICTL_CPU_PRIO
value|0x0000000000100000
end_define

begin_comment
comment|/* PCI arbitration parking */
end_comment

begin_define
define|#
directive|define
name|PCICTL_ARB_PRIO
value|0x00000000000f0000
end_define

begin_comment
comment|/* PCI arbitration parking */
end_comment

begin_define
define|#
directive|define
name|PCICTL_ERRINTEN
value|0x0000000000000100
end_define

begin_comment
comment|/* PCI error interrupt enable */
end_comment

begin_define
define|#
directive|define
name|PCICTL_RTRYWAIT
value|0x0000000000000080
end_define

begin_comment
comment|/* PCI error interrupt enable */
end_comment

begin_define
define|#
directive|define
name|PCICTL_4ENABLE
value|0x000000000000000f
end_define

begin_comment
comment|/* enable 4 PCI slots */
end_comment

begin_define
define|#
directive|define
name|PCICTL_6ENABLE
value|0x000000000000003f
end_define

begin_comment
comment|/* enable 6 PCI slots */
end_comment

begin_comment
comment|/*  * these are the PROM structures we grovel  */
end_comment

begin_comment
comment|/*  * For the physical adddresses split into 3 32 bit values, we deocde  * them like the following (IEEE1275 PCI Bus binding 2.0, 2.2.1.1  * Numerical Representation):  *  * 	phys.hi cell:	npt000ss bbbbbbbb dddddfff rrrrrrrr  * 	phys.mid cell:	hhhhhhhh hhhhhhhh hhhhhhhh hhhhhhhh  * 	phys.lo cell:	llllllll llllllll llllllll llllllll  *  * where these bits affect the address' properties:  *	n	not-relocatable  *	p	prefetchable  *	t	aliased (non-relocatable IO), below 1MB (memory) or  *		below 64KB (reloc. IO)  *	ss	address space code:  *		00 - configuration space  *		01 - I/O space  *		10 - 32 bit memory space  *		11 - 64 bit memory space  *	bb..bb	8 bit bus number  *	ddddd	5 bit device number  *	fff	3 bit function number  *	rr..rr	8 bit register number  *	hh..hh	32 bit unsigned value  *	ll..ll	32 bit unsigned value  * the values of hh..hh and ll..ll are combined to form a larger number.  *  * For config space, we don't have to do much special.  For I/O space,  * hh..hh must be zero, and if n == 0 ll..ll is the offset from the  * start of I/O space, otherwise ll..ll is the I/O space.  For memory  * space, hh..hh must be zero for the 32 bit space, and is the high 32  * bits in 64 bit space, with ll..ll being the low 32 bits in both cases,  * with offset handling being driver via `n == 0' as for I/O space.  */
end_comment

begin_comment
comment|/* commonly used */
end_comment

begin_define
define|#
directive|define
name|TAG2BUS
parameter_list|(
name|tag
parameter_list|)
value|((tag)>> 16)& 0xff;
end_define

begin_define
define|#
directive|define
name|TAG2DEV
parameter_list|(
name|tag
parameter_list|)
value|((tag)>> 11)& 0x1f;
end_define

begin_define
define|#
directive|define
name|TAG2FN
parameter_list|(
name|tag
parameter_list|)
value|((tag)>> 8)& 0x7;
end_define

begin_define
define|#
directive|define
name|INTPCI_MAXOBINO
value|0x16
end_define

begin_comment
comment|/* maximum OBIO INO value for PCI */
end_comment

begin_define
define|#
directive|define
name|INTPCIOBINOX
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1f)
end_define

begin_comment
comment|/* OBIO ino index (for PCI machines) */
end_comment

begin_define
define|#
directive|define
name|INTPCIINOX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1c)>> 2)
end_define

begin_comment
comment|/* PCI ino index */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SPARC64_PCI_PSYCHOREG_H_ */
end_comment

end_unit

