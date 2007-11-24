begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Eduardo E. Horvath  * Copyright (c) 1999 Matthew R. Green  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: psychoreg.h,v 1.8 2001/09/10 16:17:06 eeh Exp  *  * $FreeBSD$  */
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
comment|/*  * Sun4u PCI definitions.  Here's where we deal w/the machine  * dependencies of Psycho and the PCI controller on the UltraIIi.  *  * All PCI registers are bit-swapped, however they are not byte-swapped.  * This means that they must be accessed using little-endian access modes,  * either map the pages little-endian or use little-endian ASIs.  *  * PSYCHO implements two PCI buses, A and B.  */
end_comment

begin_define
define|#
directive|define
name|PSYCHO_NINTR
value|6
end_define

begin_define
define|#
directive|define
name|PSYCHO_NRANGE
value|4
end_define

begin_comment
comment|/*  * Psycho register offsets  *  * NB: FFB0 and FFB1 intr map regs also appear at 0x6000 and 0x8000  * respectively.  */
end_comment

begin_define
define|#
directive|define
name|PSR_UPA_PORTID
value|0x0000
end_define

begin_comment
comment|/* UPA port ID register */
end_comment

begin_define
define|#
directive|define
name|PSR_UPA_CONFIG
value|0x0008
end_define

begin_comment
comment|/* UPA config register */
end_comment

begin_define
define|#
directive|define
name|PSR_CS
value|0x0010
end_define

begin_comment
comment|/* PSYCHO control/status register */
end_comment

begin_define
define|#
directive|define
name|PSR_ECCC
value|0x0020
end_define

begin_comment
comment|/* ECC control register */
end_comment

begin_define
define|#
directive|define
name|PSR_UE_AFS
value|0x0030
end_define

begin_comment
comment|/* Uncorrectable Error AFSR */
end_comment

begin_define
define|#
directive|define
name|PSR_UE_AFA
value|0x0038
end_define

begin_comment
comment|/* Uncorrectable Error AFAR */
end_comment

begin_define
define|#
directive|define
name|PSR_CE_AFS
value|0x0040
end_define

begin_comment
comment|/* Correctable Error AFSR */
end_comment

begin_define
define|#
directive|define
name|PSR_CE_AFA
value|0x0048
end_define

begin_comment
comment|/* Correctable Error AFAR */
end_comment

begin_define
define|#
directive|define
name|PSR_PM_CTL
value|0x0100
end_define

begin_comment
comment|/* Performance monitor control reg */
end_comment

begin_define
define|#
directive|define
name|PSR_PM_COUNT
value|0x0108
end_define

begin_comment
comment|/* Performance monitor counter reg */
end_comment

begin_define
define|#
directive|define
name|PSR_IOMMU
value|0x0200
end_define

begin_comment
comment|/* IOMMU registers */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIA0_INT_MAP
value|0x0c00
end_define

begin_comment
comment|/* PCI bus a slot 0 irq map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIA1_INT_MAP
value|0x0c08
end_define

begin_comment
comment|/* PCI bus a slot 1 irq map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIA2_INT_MAP
value|0x0c10
end_define

begin_comment
comment|/* PCI bus a slot 2 irq map reg (IIi) */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIA3_INT_MAP
value|0x0c18
end_define

begin_comment
comment|/* PCI bus a slot 3 irq map reg (IIi) */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIB0_INT_MAP
value|0x0c20
end_define

begin_comment
comment|/* PCI bus b slot 0 irq map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIB1_INT_MAP
value|0x0c28
end_define

begin_comment
comment|/* PCI bus b slot 1 irq map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIB2_INT_MAP
value|0x0c30
end_define

begin_comment
comment|/* PCI bus b slot 2 irq map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIB3_INT_MAP
value|0x0c38
end_define

begin_comment
comment|/* PCI bus b slot 3 irq map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_SCSI_INT_MAP
value|0x1000
end_define

begin_comment
comment|/* SCSI interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_ETHER_INT_MAP
value|0x1008
end_define

begin_comment
comment|/* ethernet interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_BPP_INT_MAP
value|0x1010
end_define

begin_comment
comment|/* parallel interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_AUDIOR_INT_MAP
value|0x1018
end_define

begin_comment
comment|/* audio record interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_AUDIOP_INT_MAP
value|0x1020
end_define

begin_comment
comment|/* audio playback interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_POWER_INT_MAP
value|0x1028
end_define

begin_comment
comment|/* power fail interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_SKBDMS_INT_MAP
value|0x1030
end_define

begin_comment
comment|/* serial/kbd/mouse interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_FD_INT_MAP
value|0x1038
end_define

begin_comment
comment|/* floppy interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_SPARE_INT_MAP
value|0x1040
end_define

begin_comment
comment|/* spare interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_KBD_INT_MAP
value|0x1048
end_define

begin_comment
comment|/* kbd [unused] interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_MOUSE_INT_MAP
value|0x1050
end_define

begin_comment
comment|/* mouse [unused] interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_SERIAL_INT_MAP
value|0x1058
end_define

begin_comment
comment|/* second serial interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_TIMER0_INT_MAP
value|0x1060
end_define

begin_comment
comment|/* timer 0 interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_TIMER1_INT_MAP
value|0x1068
end_define

begin_comment
comment|/* timer 1 interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_UE_INT_MAP
value|0x1070
end_define

begin_comment
comment|/* UE interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_CE_INT_MAP
value|0x1078
end_define

begin_comment
comment|/* CE interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIAERR_INT_MAP
value|0x1080
end_define

begin_comment
comment|/* PCI bus a error interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIBERR_INT_MAP
value|0x1088
end_define

begin_comment
comment|/* PCI bus b error interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_PWRMGT_INT_MAP
value|0x1090
end_define

begin_comment
comment|/* power mgmt wake interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_FFB0_INT_MAP
value|0x1098
end_define

begin_comment
comment|/* FFB0 graphics interrupt map reg */
end_comment

begin_define
define|#
directive|define
name|PSR_FFB1_INT_MAP
value|0x10a0
end_define

begin_comment
comment|/* FFB1 graphics interrupt map reg */
end_comment

begin_comment
comment|/* Note: clear interrupt 0 registers are not really used */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIA0_INT_CLR
value|0x1400
end_define

begin_comment
comment|/* PCI a slot 0 clear int regs 0..3 */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIA1_INT_CLR
value|0x1420
end_define

begin_comment
comment|/* PCI a slot 1 clear int regs 0..3 */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIA2_INT_CLR
value|0x1440
end_define

begin_comment
comment|/* PCI a slot 2 clear int regs 0..3 */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIA3_INT_CLR
value|0x1460
end_define

begin_comment
comment|/* PCI a slot 3 clear int regs 0..3 */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIB0_INT_CLR
value|0x1480
end_define

begin_comment
comment|/* PCI b slot 0 clear int regs 0..3 */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIB1_INT_CLR
value|0x14a0
end_define

begin_comment
comment|/* PCI b slot 1 clear int regs 0..3 */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIB2_INT_CLR
value|0x14c0
end_define

begin_comment
comment|/* PCI b slot 2 clear int regs 0..3 */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIB3_INT_CLR
value|0x14d0
end_define

begin_comment
comment|/* PCI b slot 3 clear int regs 0..3 */
end_comment

begin_define
define|#
directive|define
name|PSR_SCSI_INT_CLR
value|0x1800
end_define

begin_comment
comment|/* SCSI clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_ETHER_INT_CLR
value|0x1808
end_define

begin_comment
comment|/* ethernet clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_BPP_INT_CLR
value|0x1810
end_define

begin_comment
comment|/* parallel clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_AUDIOR_INT_CLR
value|0x1818
end_define

begin_comment
comment|/* audio record clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_AUDIOP_INT_CLR
value|0x1820
end_define

begin_comment
comment|/* audio playback clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_POWER_INT_CLR
value|0x1828
end_define

begin_comment
comment|/* power fail clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_SKBDMS_INT_CLR
value|0x1830
end_define

begin_comment
comment|/* serial/kbd/mouse clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_FD_INT_CLR
value|0x1838
end_define

begin_comment
comment|/* floppy clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_SPARE_INT_CLR
value|0x1840
end_define

begin_comment
comment|/* spare clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_KBD_INT_CLR
value|0x1848
end_define

begin_comment
comment|/* kbd [unused] clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_MOUSE_INT_CLR
value|0x1850
end_define

begin_comment
comment|/* mouse [unused] clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_SERIAL_INT_CLR
value|0x1858
end_define

begin_comment
comment|/* second serial clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_TIMER0_INT_CLR
value|0x1860
end_define

begin_comment
comment|/* timer 0 clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_TIMER1_INT_CLR
value|0x1868
end_define

begin_comment
comment|/* timer 1 clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_UE_INT_CLR
value|0x1870
end_define

begin_comment
comment|/* UE clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_CE_INT_CLR
value|0x1878
end_define

begin_comment
comment|/* CE clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIAERR_INT_CLR
value|0x1880
end_define

begin_comment
comment|/* PCI bus a error clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_PCIBERR_INT_CLR
value|0x1888
end_define

begin_comment
comment|/* PCI bus b error clear int reg */
end_comment

begin_define
define|#
directive|define
name|PSR_PWRMGT_INT_CLR
value|0x1890
end_define

begin_comment
comment|/* power mgmt wake clr interrupt reg */
end_comment

begin_define
define|#
directive|define
name|PSR_INTR_RETRY_TIM
value|0x1a00
end_define

begin_comment
comment|/* interrupt retry timer */
end_comment

begin_define
define|#
directive|define
name|PSR_TC0
value|0x1c00
end_define

begin_comment
comment|/* timer/counter 0 */
end_comment

begin_define
define|#
directive|define
name|PSR_TC1
value|0x1c10
end_define

begin_comment
comment|/* timer/counter 1 */
end_comment

begin_define
define|#
directive|define
name|PSR_DMA_WRITE_SYNC
value|0x1c20
end_define

begin_comment
comment|/* PCI DMA write sync register (IIi) */
end_comment

begin_define
define|#
directive|define
name|PSR_PCICTL0
value|0x2000
end_define

begin_comment
comment|/* PCICTL registers for 1st Psycho */
end_comment

begin_define
define|#
directive|define
name|PSR_PCICTL1
value|0x4000
end_define

begin_comment
comment|/* PCICTL registers for 2nd Psycho */
end_comment

begin_define
define|#
directive|define
name|PSR_DMA_SCB_DIAG0
value|0xa000
end_define

begin_comment
comment|/* DMA scoreboard diag reg 0 */
end_comment

begin_define
define|#
directive|define
name|PSR_DMA_SCB_DIAG1
value|0xa008
end_define

begin_comment
comment|/* DMA scoreboard diag reg 1 */
end_comment

begin_define
define|#
directive|define
name|PSR_IOMMU_SVADIAG
value|0xa400
end_define

begin_comment
comment|/* IOMMU virtual addr diag reg */
end_comment

begin_define
define|#
directive|define
name|PSR_IOMMU_TLB_CMP_DIAG
value|0xa408
end_define

begin_comment
comment|/* IOMMU TLB tag compare diag reg */
end_comment

begin_define
define|#
directive|define
name|PSR_IOMMU_QUEUE_DIAG
value|0xa500
end_define

begin_comment
comment|/* IOMMU LRU queue diag regs 0..15 */
end_comment

begin_define
define|#
directive|define
name|PSR_IOMMU_TLB_TAG_DIAG
value|0xa580
end_define

begin_comment
comment|/* TLB tag diag regs 0..15 */
end_comment

begin_define
define|#
directive|define
name|PSR_IOMMU_TLB_DATA_DIAG
value|0xa600
end_define

begin_comment
comment|/* TLB data RAM diag regs 0..15 */
end_comment

begin_define
define|#
directive|define
name|PSR_PCI_INT_DIAG
value|0xa800
end_define

begin_comment
comment|/* PCI int state diag reg */
end_comment

begin_define
define|#
directive|define
name|PSR_OBIO_INT_DIAG
value|0xa808
end_define

begin_comment
comment|/* OBIO and misc int state diag reg */
end_comment

begin_define
define|#
directive|define
name|PSR_STRBUF_DIAG
value|0xb000
end_define

begin_comment
comment|/* Streaming buffer diag regs */
end_comment

begin_comment
comment|/*  * Here is the rest of the map, which we're not specifying:  *  * 1fe.0100.0000 - 1fe.01ff.ffff	PCI configuration space  * 1fe.0100.0000 - 1fe.0100.00ff	PCI B configuration header  * 1fe.0101.0000 - 1fe.0101.00ff	PCI A configuration header  * 1fe.0200.0000 - 1fe.0200.ffff	PCI A I/O space  * 1fe.0201.0000 - 1fe.0201.ffff	PCI B I/O space  * 1ff.0000.0000 - 1ff.7fff.ffff	PCI A memory space  * 1ff.8000.0000 - 1ff.ffff.ffff	PCI B memory space  *  * NB: config and I/O space can use 1-4 byte accesses, not 8 byte  * accesses.  Memory space can use any sized accesses.  *  * Note that the SUNW,sabre/SUNW,simba combinations found on the  * Ultra5 and Ultra10 machines uses slightly differrent addresses  * than the above.  This is mostly due to the fact that the APB is  * a multi-function PCI device with two PCI bridges, and the U2P is  * two separate PCI bridges.  It uses the same PCI configuration  * space, though the configuration header for each PCI bus is  * located differently due to the SUNW,simba PCI busses being  * function 0 and function 1 of the APB, whereas the Psycho's are  * each their own PCI device.  The I/O and memory spaces are each  * split into 8 equally sized areas (8x2MB blocks for I/O space,  * and 8x512MB blocks for memory space).  These are allocated in to  * either PCI A or PCI B, or neither in the APB's `I/O Address Map  * Register A/B' (0xde) and `Memory Address Map Register A/B' (0xdf)  * registers of each Simba.  We must ensure that both of the  * following are correct (the prom should do this for us):  *  *    (PCI A Memory Address Map)& (PCI B Memory Address Map) == 0  *  *    (PCI A I/O Address Map)& (PCI B I/O Address Map) == 0  *  * 1fe.0100.0000 - 1fe.01ff.ffff	PCI configuration space  * 1fe.0100.0800 - 1fe.0100.08ff	PCI B configuration header  * 1fe.0100.0900 - 1fe.0100.09ff	PCI A configuration header  * 1fe.0200.0000 - 1fe.02ff.ffff	PCI I/O space (divided)  * 1ff.0000.0000 - 1ff.ffff.ffff	PCI memory space (divided)  */
end_comment

begin_comment
comment|/*  * PSR_CS defines:  *  * 63     59     55     50     45     4        3       2     1      0  * +------+------+------+------+--//---+--------+-------+-----+------+  * | IMPL | VERS | MID  | IGN  |  xxx  | APCKEN | APERR | IAP | MODE |  * +------+------+------+------+--//---+--------+-------+-----+------+  *  */
end_comment

begin_define
define|#
directive|define
name|PSYCHO_GCSR_IMPL
parameter_list|(
name|csr
parameter_list|)
value|((u_int)(((csr)>> 60)& 0xf))
end_define

begin_define
define|#
directive|define
name|PSYCHO_GCSR_VERS
parameter_list|(
name|csr
parameter_list|)
value|((u_int)(((csr)>> 56)& 0xf))
end_define

begin_define
define|#
directive|define
name|PSYCHO_GCSR_MID
parameter_list|(
name|csr
parameter_list|)
value|((u_int)(((csr)>> 51)& 0x1f))
end_define

begin_define
define|#
directive|define
name|PSYCHO_GCSR_IGN
parameter_list|(
name|csr
parameter_list|)
value|((u_int)(((csr)>> 46)& 0x1f))
end_define

begin_define
define|#
directive|define
name|PSYCHO_CSR_APCKEN
value|8
end_define

begin_comment
comment|/* UPA addr parity check enable */
end_comment

begin_define
define|#
directive|define
name|PSYCHO_CSR_APERR
value|4
end_define

begin_comment
comment|/* UPA addr parity error */
end_comment

begin_define
define|#
directive|define
name|PSYCHO_CSR_IAP
value|2
end_define

begin_comment
comment|/* invert UPA address parity */
end_comment

begin_define
define|#
directive|define
name|PSYCHO_CSR_MODE
value|1
end_define

begin_comment
comment|/* UPA/PCI handshake */
end_comment

begin_comment
comment|/* Offsets into the PSR_PCICTL* register block */
end_comment

begin_define
define|#
directive|define
name|PCR_CS
value|0x0000
end_define

begin_comment
comment|/* PCI control/status register */
end_comment

begin_define
define|#
directive|define
name|PCR_AFS
value|0x0010
end_define

begin_comment
comment|/* PCI AFSR register */
end_comment

begin_define
define|#
directive|define
name|PCR_AFA
value|0x0018
end_define

begin_comment
comment|/* PCI AFAR register */
end_comment

begin_define
define|#
directive|define
name|PCR_DIAG
value|0x0020
end_define

begin_comment
comment|/* PCI diagnostic register */
end_comment

begin_define
define|#
directive|define
name|PCR_TAS
value|0x0028
end_define

begin_comment
comment|/* PCI target address space reg (IIi) */
end_comment

begin_define
define|#
directive|define
name|PCR_STRBUF
value|0x0800
end_define

begin_comment
comment|/* IOMMU streaming buffer registers. */
end_comment

begin_comment
comment|/* Device space defines */
end_comment

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
comment|/*  * PCI [a|b] control/status register  * Note that the Hummingbird/Sabre only has one set of PCI control/status  * registers.  */
end_comment

begin_define
define|#
directive|define
name|PCICTL_SBHERR
value|0x0000000800000000
end_define

begin_comment
comment|/* strm. byte hole error; W1C */
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
name|PCICTL_PCISPEED
value|0x0000000200000000
end_define

begin_comment
comment|/* 0:half 1:full bus speed */
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
name|PCICTL_SBHINTEN
value|0x0000000000000400
end_define

begin_comment
comment|/* strm. byte hole int. en. */
end_comment

begin_define
define|#
directive|define
name|PCICTL_WAKEUPEN
value|0x0000000000000200
end_define

begin_comment
comment|/* power mgmt. wakeup enable */
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
name|PCICTL_ARB_4
value|0x000000000000000f
end_define

begin_comment
comment|/* DVMA arb. 4 PCI slots mask */
end_comment

begin_define
define|#
directive|define
name|PCICTL_ARB_6
value|0x000000000000003f
end_define

begin_comment
comment|/* DVMA arb. 6 PCI slots mask */
end_comment

begin_comment
comment|/* The following are Hummingbird/Sabre only. */
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
name|PCICTL_CPU_PRIO
value|0x0000000000100000
end_define

begin_comment
comment|/* CPU extra arb. prio. en. */
end_comment

begin_define
define|#
directive|define
name|PCICTL_ARB_PRIO
value|0x00000000000f0000
end_define

begin_comment
comment|/* PCI extra arb. prio. en. */
end_comment

begin_define
define|#
directive|define
name|PCICTL_RTRYWAIT
value|0x0000000000000080
end_define

begin_comment
comment|/* 0:wait 1:retry DMA write */
end_comment

begin_comment
comment|/* Uncorrectable error asynchronous fault status register */
end_comment

begin_define
define|#
directive|define
name|UEAFSR_BLK
value|(1UL<< 23)
end_define

begin_comment
comment|/* Error caused by block transaction */
end_comment

begin_define
define|#
directive|define
name|UEAFSR_P_DTE
value|(1UL<< 56)
end_define

begin_comment
comment|/* Pri. DVMA translation error */
end_comment

begin_define
define|#
directive|define
name|UEAFSR_S_DTE
value|(1UL<< 57)
end_define

begin_comment
comment|/* Sec. DVMA translation error */
end_comment

begin_define
define|#
directive|define
name|UEAFSR_S_DWR
value|(1UL<< 58)
end_define

begin_comment
comment|/* Sec. error during DVMA write */
end_comment

begin_define
define|#
directive|define
name|UEAFSR_S_DRD
value|(1UL<< 59)
end_define

begin_comment
comment|/* Sec. error during DVMA read */
end_comment

begin_define
define|#
directive|define
name|UEAFSR_S_PIO
value|(1UL<< 60)
end_define

begin_comment
comment|/* Sec. error during PIO access */
end_comment

begin_define
define|#
directive|define
name|UEAFSR_P_DWR
value|(1UL<< 61)
end_define

begin_comment
comment|/* Pri. error during DVMA write */
end_comment

begin_define
define|#
directive|define
name|UEAFSR_P_DRD
value|(1UL<< 62)
end_define

begin_comment
comment|/* Pri. error during DVMA read */
end_comment

begin_define
define|#
directive|define
name|UEAFSR_P_PIO
value|(1UL<< 63)
end_define

begin_comment
comment|/* Pri. error during PIO access */
end_comment

begin_comment
comment|/* Correctable error asynchronous fault status register */
end_comment

begin_define
define|#
directive|define
name|CEAFSR_BLK
value|(1UL<< 23)
end_define

begin_comment
comment|/* Error caused by block transaction */
end_comment

begin_define
define|#
directive|define
name|CEAFSR_S_DWR
value|(1UL<< 58)
end_define

begin_comment
comment|/* Sec. error caused by DVMA write */
end_comment

begin_define
define|#
directive|define
name|CEAFSR_S_DRD
value|(1UL<< 59)
end_define

begin_comment
comment|/* Sec. error caused by DVMA read */
end_comment

begin_define
define|#
directive|define
name|CEAFSR_S_PIO
value|(1UL<< 60)
end_define

begin_comment
comment|/* Sec. error caused by PIO access */
end_comment

begin_define
define|#
directive|define
name|CEAFSR_P_DWR
value|(1UL<< 61)
end_define

begin_comment
comment|/* Pri. error caused by DVMA write */
end_comment

begin_define
define|#
directive|define
name|CEAFSR_P_DRD
value|(1UL<< 62)
end_define

begin_comment
comment|/* Pri. error caused by DVMA read */
end_comment

begin_define
define|#
directive|define
name|CEAFSR_P_PIO
value|(1UL<< 63)
end_define

begin_comment
comment|/* Pri. error caused by PIO access */
end_comment

begin_define
define|#
directive|define
name|CEAFSR_ERRMASK
define|\
value|(CEAFSR_P_PIO | CEAFSR_P_DRD | CEAFSR_P_DWR |			\ 	CEAFSR_S_PIO | CEAFSR_S_DRD | CEAFSR_S_DWR)
end_define

begin_comment
comment|/* PCI asynchronous fault status register */
end_comment

begin_define
define|#
directive|define
name|PCIAFSR_P_MA
value|(1UL<< 63)
end_define

begin_comment
comment|/* Pri. master abort */
end_comment

begin_define
define|#
directive|define
name|PCIAFSR_P_TA
value|(1UL<< 62)
end_define

begin_comment
comment|/* Pri. target abort */
end_comment

begin_define
define|#
directive|define
name|PCIAFSR_P_RTRY
value|(1UL<< 61)
end_define

begin_comment
comment|/* Pri. excessive retries */
end_comment

begin_define
define|#
directive|define
name|PCIAFSR_P_RERR
value|(1UL<< 60)
end_define

begin_comment
comment|/* Pri. parity error */
end_comment

begin_define
define|#
directive|define
name|PCIAFSR_S_MA
value|(1UL<< 59)
end_define

begin_comment
comment|/* Sec. master abort */
end_comment

begin_define
define|#
directive|define
name|PCIAFSR_S_TA
value|(1UL<< 58)
end_define

begin_comment
comment|/* Sec. target abort */
end_comment

begin_define
define|#
directive|define
name|PCIAFSR_S_RTRY
value|(1UL<< 57)
end_define

begin_comment
comment|/* Sec. excessive retries */
end_comment

begin_define
define|#
directive|define
name|PCIAFSR_S_RERR
value|(1UL<< 56)
end_define

begin_comment
comment|/* Sec. parity error */
end_comment

begin_define
define|#
directive|define
name|PCIAFSR_BMASK
value|(0xffffUL<< 32)
end_define

begin_comment
comment|/* Bytemask of failed pri. transfer */
end_comment

begin_define
define|#
directive|define
name|PCIAFSR_BLK
value|(1UL<< 31)
end_define

begin_comment
comment|/* failed pri. transfer was block r/w */
end_comment

begin_define
define|#
directive|define
name|PCIAFSR_MID
value|(0x3eUL<< 25)
end_define

begin_comment
comment|/* UPA MID causing error transaction */
end_comment

begin_define
define|#
directive|define
name|PCIAFSR_ERRMASK
define|\
value|(PCIAFSR_P_MA | PCIAFSR_P_TA | PCIAFSR_P_RTRY |	PCIAFSR_P_RERR |\ 	PCIAFSR_S_MA | PCIAFSR_S_TA | PCIAFSR_S_RTRY | PCIAFSR_S_RERR)
end_define

begin_comment
comment|/* PCI diagnostic register */
end_comment

begin_define
define|#
directive|define
name|DIAG_RTRY_DIS
value|0x0000000000000040
end_define

begin_comment
comment|/* dis. retry limit */
end_comment

begin_define
define|#
directive|define
name|DIAG_ISYNC_DIS
value|0x0000000000000020
end_define

begin_comment
comment|/* dis. DMA write / int sync */
end_comment

begin_define
define|#
directive|define
name|DIAG_DWSYNC_DIS
value|0x0000000000000010
end_define

begin_comment
comment|/* dis. DMA write / PIO sync */
end_comment

begin_comment
comment|/* Definitions for the target address space register */
end_comment

begin_define
define|#
directive|define
name|PCITAS_ADDR_SHIFT
value|29
end_define

begin_comment
comment|/* Definitions for the Psycho configuration space */
end_comment

begin_define
define|#
directive|define
name|PCS_DEVICE
value|0
end_define

begin_comment
comment|/* Device number of Psycho CS entry */
end_comment

begin_define
define|#
directive|define
name|PCS_FUNC
value|0
end_define

begin_comment
comment|/* Function number of Psycho CS entry */
end_comment

begin_comment
comment|/* Non-Standard registers in the configration space */
end_comment

begin_define
define|#
directive|define
name|PCSR_SECBUS
value|0x40
end_define

begin_comment
comment|/* Secondary bus number register */
end_comment

begin_define
define|#
directive|define
name|PCSR_SUBBUS
value|0x41
end_define

begin_comment
comment|/* Subordinate bus number register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SPARC64_PCI_PSYCHOREG_H_ */
end_comment

end_unit

