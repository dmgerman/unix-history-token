begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 by Matthew Jacob  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Taken from:  *  *	``RAWHIDE Systems Programmer's Manual, Revision 1.4''  */
end_comment

begin_define
define|#
directive|define
name|REGVAL
parameter_list|(
name|r
parameter_list|)
value|(*(volatile int32_t *)ALPHA_PHYS_TO_K0SEG(r))
end_define

begin_comment
comment|/*  * There are 4 possible PCI busses per MCBUS.  *  * (from mcpcia.h, Digital Unix 4.0E):  *  * I/O Space Per PCI Node (8GBytes per)  * ------------------------------------  * (8+x)8 0000 0000 - (8+x)9 FFFF FFFF  - I/O Space for PCI0  * (8+x)A 0000 0000 - (8+x)B FFFF FFFF  - I/O Space for PCI1  * (8+x)C 0000 0000 - (8+x)D FFFF FFFF  - I/O Space for PCI2  * (8+x)E 0000 0000 - (8+x)F FFFF FFFF  - I/O Space for PCI3  *  * CPU to PCI Address Mapping:  * ---------------------------  *  * +---+-------+-------+--+--+--+--+--+--+---------------+----------+-----+  * | 1 |  GID  |  MID  |  |  |  |  |  |  | Byte Aligned  | Byte Len | Zero|  * |   |       |       |  |  |  |  |  |  | I/O Address   |   Field  |     |  * +---+-------+-------+--+--+--+--+--+--+---------------+----------+-----+  *  39  38   36 35   33 32 31 30 29 28 27 26            5 4        3  2  0  *  *<39> - I/O Select (Always 1 for direct I/O access)  *  *<38-36> - Global Bus slot # (MCBUS #)  *      GID slot #0->7 (MCBUS #0->7)  *  *<35-33> - MCBUS Slot #  *      MCBUS slot 0->7  *  *<32-27> - PCI Address Space  *      0.xxxxx = Sparse Memory Space   (  4GB on MCBUS; 128MB on PCI)  *      1.0xxxx = Dense Memory Space    (  2GB on MCBUS;   2GB on PCI)  *      1.10xxx = Sparse IO Space       (  1GB on MCBUS;  32MB on PCI)  *      1.110xx = Sparse Config Space   (512MB on MCBUS;  16MB on PCI)  *      1.1110x = PCI Bridge CSR Space  (256MB on MCBUS) -- Sparse-mapped!  *      1.11110 = Interrupt Acknowledge (128MB on MCBUS)  *      1.11111 = Unused                (128MB on MCBUS)  *  * ------------------------------------------------------------  * Cpu to PCI Address Mapping for MCBUS-PCIy Bridge on MCBUS x:  * ------------------------------------------------------------      *   * CPU Address Range            PCI Address Range       PCI Address Space  * ------------------------     ---------------------   ------------------------  * (8+x)(8+y*2).0000.0000       0000.0000 - 00FF.FFFF   PCIy Sparse Memory Space  * - (8+x)(8+y*2).1FFF.FFFF                              (fixed, lower 16MB)  *   * (8+x)(8+y*2).2000.0000       0100.0000 - 07FF.FFFF   PCIy Sparse Memory Space  * - (8+x)(8+y*2).FFFF.FFFF                              (variable, offset = 0)  *   * (8+x)(9+y*2).0000.0000       0000.0000 - 7FFF.FFFF   PCIy Dense Memory Space  * - (8+x)(9+y*2).7FFF.FFFF  or 8000.0000 - FFFF.FFFF      if HAE_DENSE_MEM = 1  *   * (8+x)(9+y*2).8000.0000       0000.0000 - 0000.FFFF   PCIy Sparse IO Space  * - (8+x)(9+y*2).801F.FFFF                              (fixed, lower 64K)  *   * (8+x)(9+y*2).8020.0000       0001.0000 - 01FF.FFFF   PCIy Sparse IO Space  * - (8+x)(9+y*2).BFFF.FFFF                              (variable, offset = 0)  *   * (8+x)(9+y*2).C000.0000       0000.0000 - 0FFF.FFFF   PCIy Config Space (16MB)  * - (8+x)(9+y*2).DFFF.FFFF  *   * (8+x)(9+y*2).E000.0000               N/A             PCIy-Bridge CSR Space  *							(8MB)  * - (8+x)(9+y*2).EFFF.FFFF   *  * (8+x)(9+y*2).F000.0000               N/A             Unused  * - (8+x)(9+y*2).F000.3EFF  *  * (8+x)(9+y*2).F000.3F00,              N/A             PCIy Interrupt ACK0  * (8+x)(9+y*2).F000.3F40                               PCIy INteruppt ACK1  *  * (8+x)(9+y*2).F000.3F80               N/A             Unused  * - (8+x)(9+y*2).FFFF.FFFF  *  */
end_comment

begin_comment
comment|/*                                                         * MC-PCI Bus Bridge CSRs  *                             * Address Map Overview:  *  * Offset                Selected Space  * ----------------      -------------------------------------------------  * 0x00000000            General config, control, diag, error logging regs.  * 0x00001000            PCI Error Status  * 0x00001300            PCI Scatter/Gather Regs.  * 0x00001800            Scatter/Gather TLB Regs.          * 0x00004000            MDPA Error Status& Diagnostic Control  * 0x00008000            MDPB Error Status& Diagnostic Control  * 0x000E0000 -          Flash Rom Space --  * 0x000FFFFF            offset address into PCI Dense Mem Space  * 0x10003F00            Interrupt Acknowledge  *   */
end_comment

begin_comment
comment|/*  * Address Space Cookies  */
end_comment

begin_define
define|#
directive|define
name|MCPCIA_PCI_SPARSE
value|0x000000000LL
end_define

begin_define
define|#
directive|define
name|MCPCIA_PCI_DENSE
value|0x100000000LL
end_define

begin_define
define|#
directive|define
name|MCPCIA_PCI_IOSPACE
value|0x180000000LL
end_define

begin_define
define|#
directive|define
name|MCPCIA_PCI_CONF
value|0x1C0000000LL
end_define

begin_define
define|#
directive|define
name|MCPCIA_PCI_BRIDGE
value|0x1E0000000LL
end_define

begin_define
define|#
directive|define
name|MCPCIA_PCI_IACK
value|0x1F0000000LL
end_define

begin_comment
comment|/*  * MCPCIA Bus Bridge Registers  *  * These are offsets that don't include GBUS, MID, or address space offsets.  */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_PCI_REV
value|0x000000000
end_define

begin_comment
comment|/* PCI Revision Register (R) */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_WHOAMI
value|0x000000040
end_define

begin_comment
comment|/* PCI Who Am I (R) */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_PCI_LAT
value|0x000000080
end_define

begin_comment
comment|/* PCI Latency Timer (RW) */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_CAP_CTRL
value|0x000000100
end_define

begin_comment
comment|/* PCI Bridge Control (RW) */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_HAE_MEM
value|0x000000400
end_define

begin_comment
comment|/* PCI HAE Sparse Memory (RW) */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_HAE_IO
value|0x000000440
end_define

begin_comment
comment|/* PCI HAE Sparse I/O (RW) */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_IACK_SC
value|0x000000480
end_define

begin_comment
comment|/* PCI Special Cycle Ack */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_HAE_DENSE
value|0x0000004C0
end_define

begin_comment
comment|/* PCI HAE Dense Memory (RW) */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_INT_CTL
value|0x000000500
end_define

begin_comment
comment|/* PCI Interrupt Control */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_INT_REQ
value|0x000000540
end_define

begin_comment
comment|/* PCI Interrupt Request */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_INT_TARG
value|0x000000580
end_define

begin_comment
comment|/* PCI Int Tgt Devices */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_INT_ADR
value|0x0000005C0
end_define

begin_comment
comment|/* PCI Int Tgt Address */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_INT_ADR_EXT
value|0x000000600
end_define

begin_comment
comment|/* PCI Int Tgt Addr Ext */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_INT_MASK0
value|0x000000640
end_define

begin_comment
comment|/* PCI Int Mask 0 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_INT_MASK1
value|0x000000680
end_define

begin_comment
comment|/* PCI Int Mask 1 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_INT_ACK0
value|0x100003F00
end_define

begin_comment
comment|/* PCI Int Ack 0 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_INT_ACK1
value|0x100003F40
end_define

begin_comment
comment|/* PCI Int Ack 1 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_PERF_MON
value|0x000000300
end_define

begin_comment
comment|/* PCI Perf Monitor */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_PERF_CONT
value|0x000000340
end_define

begin_comment
comment|/* PCI Perf Monitor Control */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_CAP_DIAG
value|0x000000700
end_define

begin_comment
comment|/* MC-PCI Diagnostic Control */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_SCRATCH0
value|0x000000740
end_define

begin_comment
comment|/* Diag General */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_SCRATCH1
value|0x000000780
end_define

begin_comment
comment|/* Diag General */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_TOM
value|0x0000007C0
end_define

begin_comment
comment|/* Top Of Memory */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_MC_ERR0
value|0x000000800
end_define

begin_comment
comment|/* MC Err Info 0 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_MC_ERR1
value|0x000000840
end_define

begin_comment
comment|/* MC Err Info 1 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_CAP_ERR
value|0x000000880
end_define

begin_comment
comment|/* CAP Error Register */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_PCI_ERR1
value|0x000001040
end_define

begin_comment
comment|/* PCI Error Status */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_MDPA_STAT
value|0x000004000
end_define

begin_comment
comment|/* MDPA Status */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_MDPA_SYN
value|0x000004040
end_define

begin_comment
comment|/* MDPA Syndrome */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_MDPA_DIAG
value|0x000004080
end_define

begin_comment
comment|/* Diag Check MDPA */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_MDPB_STAT
value|0x000008000
end_define

begin_comment
comment|/* MDPB Status */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_MDPB_SYN
value|0x000008040
end_define

begin_comment
comment|/* MDPB Syndrome */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_MDPB_DIAG
value|0x000008080
end_define

begin_comment
comment|/* Diag Check MDPB */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_SG_TBIA
value|0x000001300
end_define

begin_comment
comment|/* Scatter/Gather TBIA */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_HBASE
value|0x000001340
end_define

begin_comment
comment|/* PC "Hole" Compatibility */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_W0_BASE
value|0x000001400
end_define

begin_comment
comment|/* Window Base 0 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_W0_MASK
value|0x000001440
end_define

begin_comment
comment|/* Window Mask 0 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_T0_BASE
value|0x000001480
end_define

begin_comment
comment|/* Translated Base 0 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_W1_BASE
value|0x000001500
end_define

begin_comment
comment|/* Window Base 1 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_W1_MASK
value|0x000001540
end_define

begin_comment
comment|/* Window Mask 1 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_T1_BASE
value|0x000001580
end_define

begin_comment
comment|/* Translated Base 1 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_W2_BASE
value|0x000001600
end_define

begin_comment
comment|/* Window Base 2 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_W2_MASK
value|0x000001640
end_define

begin_comment
comment|/* Window Mask 2 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_T2_BASE
value|0x000001680
end_define

begin_comment
comment|/* Translated Base 2 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_W3_BASE
value|0x000001700
end_define

begin_comment
comment|/* Window Base 3 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_W3_MASK
value|0x000001740
end_define

begin_comment
comment|/* Window Mask 3 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_T3_BASE
value|0x000001780
end_define

begin_comment
comment|/* Translated Base 3 */
end_comment

begin_define
define|#
directive|define
name|_MCPCIA_W_DAC
value|0x0000017C0
end_define

begin_comment
comment|/* Window DAC Base */
end_comment

begin_comment
comment|/*  * Handier defines- uses precalculated offset in softc.  */
end_comment

begin_define
define|#
directive|define
name|_SYBRIDGE
parameter_list|(
name|ccp
parameter_list|)
value|((ccp)->sysbase | MCPCIA_PCI_BRIDGE)
end_define

begin_define
define|#
directive|define
name|MCPCIA_PCI_REV
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_PCI_REV)
end_define

begin_define
define|#
directive|define
name|MCPCIA_WHOAMI
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_WHOAMI)
end_define

begin_define
define|#
directive|define
name|MCPCIA_PCI_LAT
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_PCI_LAT)
end_define

begin_define
define|#
directive|define
name|MCPCIA_CAP_CTRL
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_CAP_CTRL)
end_define

begin_define
define|#
directive|define
name|MCPCIA_HAE_MEM
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_HAE_MEM)
end_define

begin_define
define|#
directive|define
name|MCPCIA_HAE_IO
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_HAE_IO)
end_define

begin_define
define|#
directive|define
name|MCPCIA_IACK_SC
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_IACK_SC)
end_define

begin_define
define|#
directive|define
name|MCPCIA_HAE_DENSE
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_HAE_DENSE)
end_define

begin_define
define|#
directive|define
name|MCPCIA_INT_CTL
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_INT_CTL)
end_define

begin_define
define|#
directive|define
name|MCPCIA_INT_REQ
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_INT_REQ)
end_define

begin_define
define|#
directive|define
name|MCPCIA_INT_TARG
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_INT_TARG)
end_define

begin_define
define|#
directive|define
name|MCPCIA_INT_ADR
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_INT_ADR)
end_define

begin_define
define|#
directive|define
name|MCPCIA_INT_ADR_EXT
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_INT_ADR_EXT)
end_define

begin_define
define|#
directive|define
name|MCPCIA_INT_MASK0
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_INT_MASK0)
end_define

begin_define
define|#
directive|define
name|MCPCIA_INT_MASK1
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_INT_MASK1)
end_define

begin_define
define|#
directive|define
name|MCPCIA_INT_ACK0
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_INT_ACK0)
end_define

begin_define
define|#
directive|define
name|MCPCIA_INT_ACK1
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_INT_ACK1)
end_define

begin_define
define|#
directive|define
name|MCPCIA_PERF_MON
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_PERF_MON)
end_define

begin_define
define|#
directive|define
name|MCPCIA_PERF_CONT
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_PERF_CONT)
end_define

begin_define
define|#
directive|define
name|MCPCIA_CAP_DIAG
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_CAP_DIAG)
end_define

begin_define
define|#
directive|define
name|MCPCIA_SCRATCH0
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_SCRATCH0)
end_define

begin_define
define|#
directive|define
name|MCPCIA_SCRATCH1
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_SCRATCH1)
end_define

begin_define
define|#
directive|define
name|MCPCIA_TOM
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_TOM)
end_define

begin_define
define|#
directive|define
name|MCPCIA_MC_ERR0
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_MC_ERR0)
end_define

begin_define
define|#
directive|define
name|MCPCIA_MC_ERR1
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_MC_ERR1)
end_define

begin_define
define|#
directive|define
name|MCPCIA_CAP_ERR
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_CAP_ERR)
end_define

begin_define
define|#
directive|define
name|MCPCIA_PCI_ERR1
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_PCI_ERR1)
end_define

begin_define
define|#
directive|define
name|MCPCIA_MDPA_STAT
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_MDPA_STAT)
end_define

begin_define
define|#
directive|define
name|MCPCIA_MDPA_SYN
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_MDPA_SYN)
end_define

begin_define
define|#
directive|define
name|MCPCIA_MDPA_DIAG
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_MDPA_DIAG)
end_define

begin_define
define|#
directive|define
name|MCPCIA_MDPB_STAT
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_MDPB_STAT)
end_define

begin_define
define|#
directive|define
name|MCPCIA_MDPB_SYN
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_MDPB_SYN)
end_define

begin_define
define|#
directive|define
name|MCPCIA_MDPB_DIAG
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_MDPB_DIAG)
end_define

begin_define
define|#
directive|define
name|MCPCIA_SG_TBIA
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_SG_TBIA)
end_define

begin_define
define|#
directive|define
name|MCPCIA_HBASE
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_HBASE)
end_define

begin_define
define|#
directive|define
name|MCPCIA_W0_BASE
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_W0_BASE)
end_define

begin_define
define|#
directive|define
name|MCPCIA_W0_MASK
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_W0_MASK)
end_define

begin_define
define|#
directive|define
name|MCPCIA_T0_BASE
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_T0_BASE)
end_define

begin_define
define|#
directive|define
name|MCPCIA_W1_BASE
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_W1_BASE)
end_define

begin_define
define|#
directive|define
name|MCPCIA_W1_MASK
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_W1_MASK)
end_define

begin_define
define|#
directive|define
name|MCPCIA_T1_BASE
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_T1_BASE)
end_define

begin_define
define|#
directive|define
name|MCPCIA_W2_BASE
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_W2_BASE)
end_define

begin_define
define|#
directive|define
name|MCPCIA_W2_MASK
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_W2_MASK)
end_define

begin_define
define|#
directive|define
name|MCPCIA_T2_BASE
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_T2_BASE)
end_define

begin_define
define|#
directive|define
name|MCPCIA_W3_BASE
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_W3_BASE)
end_define

begin_define
define|#
directive|define
name|MCPCIA_W3_MASK
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_W3_MASK)
end_define

begin_define
define|#
directive|define
name|MCPCIA_T3_BASE
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_T3_BASE)
end_define

begin_define
define|#
directive|define
name|MCPCIA_W_DAC
parameter_list|(
name|ccp
parameter_list|)
value|(_SYBRIDGE(ccp) | _MCPCIA_W_DAC)
end_define

begin_comment
comment|/*  * This is here for what error handling will get as a collected subpacket.  */
end_comment

begin_struct
struct|struct
name|mcpcia_iodsnap
block|{
name|u_int64_t
name|base_addr
decl_stmt|;
name|u_int32_t
name|whami
decl_stmt|;
name|u_int32_t
name|rsvd0
decl_stmt|;
name|u_int32_t
name|pci_rev
decl_stmt|;
name|u_int32_t
name|cap_ctrl
decl_stmt|;
name|u_int32_t
name|hae_mem
decl_stmt|;
name|u_int32_t
name|hae_io
decl_stmt|;
name|u_int32_t
name|int_ctl
decl_stmt|;
name|u_int32_t
name|int_reg
decl_stmt|;
name|u_int32_t
name|int_mask0
decl_stmt|;
name|u_int32_t
name|int_mask1
decl_stmt|;
name|u_int32_t
name|mc_err0
decl_stmt|;
name|u_int32_t
name|mc_err1
decl_stmt|;
name|u_int32_t
name|cap_err
decl_stmt|;
name|u_int32_t
name|sys_env
decl_stmt|;
name|u_int32_t
name|pci_err1
decl_stmt|;
name|u_int32_t
name|mdpa_stat
decl_stmt|;
name|u_int32_t
name|mdpa_syn
decl_stmt|;
name|u_int32_t
name|mdpb_stat
decl_stmt|;
name|u_int32_t
name|mdpb_syn
decl_stmt|;
name|u_int32_t
name|rsvd2
decl_stmt|;
name|u_int32_t
name|rsvd3
decl_stmt|;
name|u_int32_t
name|rsvd4
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * PCI_REV Register definitions  */
end_comment

begin_define
define|#
directive|define
name|CAP_REV
parameter_list|(
name|reg
parameter_list|)
value|((reg)& 0xf)
end_define

begin_define
define|#
directive|define
name|HORSE_REV
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 4)& 0xf)
end_define

begin_define
define|#
directive|define
name|SADDLE_REV
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 8)& 0xf)
end_define

begin_define
define|#
directive|define
name|SADDLE_TYPE
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 12)& 0x3)
end_define

begin_define
define|#
directive|define
name|EISA_PRESENT
parameter_list|(
name|reg
parameter_list|)
value|((reg)& (1<< 15))
end_define

begin_define
define|#
directive|define
name|IS_MCPCIA_MAGIC
parameter_list|(
name|reg
parameter_list|)
value|(((reg)& 0xffff0000) == 0x6000000)
end_define

begin_comment
comment|/*  * WHOAMI Register definitions  *  * The Device ID is an echo of the MID of the CPU reading this register-  * cheezy way to figure out who you are (ask someone else!).  */
end_comment

begin_define
define|#
directive|define
name|MCBUS_CPU_MID
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7)
end_define

begin_define
define|#
directive|define
name|MCBUS_CPU_INFO
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0xff)
end_define

begin_define
define|#
directive|define
name|CPU_Fill_Err
value|0x80
end_define

begin_define
define|#
directive|define
name|CPU_DTAG_Perr
value|0x40
end_define

begin_define
define|#
directive|define
name|CPU_RevMask
value|0x38
end_define

begin_define
define|#
directive|define
name|CPU_RevShift
value|3
end_define

begin_define
define|#
directive|define
name|CPU_BCacheMask
value|0x3
end_define

begin_define
define|#
directive|define
name|CPU_BCache_0MB
value|0
end_define

begin_define
define|#
directive|define
name|CPU_BCache_1MB
value|1
end_define

begin_define
define|#
directive|define
name|CPU_BCache_2MB
value|2
end_define

begin_define
define|#
directive|define
name|CPU_BCache_4MB
value|3
end_define

begin_comment
comment|/*  * PCI Latency Register Definitions  */
end_comment

begin_define
define|#
directive|define
name|PCI_LAT_SHIFT
value|8
end_define

begin_comment
comment|/* it's in the 2nd byte. */
end_comment

begin_comment
comment|/*  * CAP Control Register Defintions  */
end_comment

begin_define
define|#
directive|define
name|CAP_LED_ON
value|0x00000001
end_define

begin_comment
comment|/* Selftest LED passed */
end_comment

begin_define
define|#
directive|define
name|CAP_EV56_BW_EN
value|0x00000002
end_define

begin_comment
comment|/* BW Enables (EV56, EV6 only) */
end_comment

begin_define
define|#
directive|define
name|CAP_DLY_RD_EN
value|0x00000010
end_define

begin_comment
comment|/* PCI Delayed Reads Enabled */
end_comment

begin_define
define|#
directive|define
name|CAP_MEM_EN
value|0x00000020
end_define

begin_comment
comment|/* Respond to PCI transactions */
end_comment

begin_define
define|#
directive|define
name|CAP_REQ64_EN
value|0x00000040
end_define

begin_comment
comment|/* Request 64 bit data transactions */
end_comment

begin_define
define|#
directive|define
name|CAP_ACK64_EN
value|0x00000080
end_define

begin_comment
comment|/* Respond to 64 bit data "" */
end_comment

begin_define
define|#
directive|define
name|CAP_ADR_PAR_EN
value|0x00000100
end_define

begin_comment
comment|/* Check PCI address Parity */
end_comment

begin_define
define|#
directive|define
name|CAP_MC_CA_PAR
value|0x00000200
end_define

begin_comment
comment|/* Check MC bus CMD/Address Parity */
end_comment

begin_define
define|#
directive|define
name|CAP_MC_NXM_EN
value|0x00000400
end_define

begin_comment
comment|/* Check for MC NXM */
end_comment

begin_define
define|#
directive|define
name|CAP_BUS_MON
value|0x00000800
end_define

begin_comment
comment|/* Check for PCI errs (as bystander) */
end_comment

begin_comment
comment|/* bits 19:16 control number of pending write transactions */
end_comment

begin_define
define|#
directive|define
name|SHORT
value|0
end_define

begin_define
define|#
directive|define
name|MED
value|1
end_define

begin_define
define|#
directive|define
name|LONG
value|2
end_define

begin_define
define|#
directive|define
name|CAP_MEMRD_PREFETCH_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|CAP_MEMRDLN_PREFETCH_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|CAP_MEMRDMULT_PREFETCH_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CAP_PARTIAL_WRITE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|CAP_ARB_BPRI
value|0x00000000
end_define

begin_comment
comment|/* Bridge Priority Arb */
end_comment

begin_define
define|#
directive|define
name|CAP_ARB_RROBIN
value|0x40000000
end_define

begin_comment
comment|/* "" Round Robin */
end_comment

begin_define
define|#
directive|define
name|CAP_ARB_RROBIN1
value|0x80000000
end_define

begin_comment
comment|/* "" Round Robin #1 */
end_comment

begin_comment
comment|/*  * Diagnostic Register Bits  */
end_comment

begin_comment
comment|/* CAP_DIAG register */
end_comment

begin_define
define|#
directive|define
name|CAP_DIAG_PCIRESET
value|0x1
end_define

begin_comment
comment|/* 					 * WriteOnly. Assert 1 for 100usec min., 					 * then write zero. NOTE: deadlocks 					 * exist in h/w if anything but this 					 * register is accessed while reset 					 * is asserted. 					 */
end_comment

begin_define
define|#
directive|define
name|CAP_DIAG_MC_ADRPE
value|(1<<30)
end_define

begin_comment
comment|/* Invert MC Bus Address/Parity */
end_comment

begin_define
define|#
directive|define
name|CAP_DIAG_PCI_ADRPE
value|(1<<31)
end_define

begin_comment
comment|/* Force bad PCI parity (low 32) */
end_comment

begin_comment
comment|/* MDPA_DIAG or MDPB_DIAG registers */
end_comment

begin_define
define|#
directive|define
name|MDPX_ECC_ENA
value|(1<<28)
end_define

begin_comment
comment|/* Enable ECC on MC Bus (default 1) */
end_comment

begin_define
define|#
directive|define
name|MDPX_PAR_ENA
value|(1<<29)
end_define

begin_comment
comment|/* Enable Parity on PCI (default 0) */
end_comment

begin_define
define|#
directive|define
name|MDPX_DIAG_FPE_PCI
value|(1<<30)
end_define

begin_comment
comment|/* Force PCI parity error */
end_comment

begin_define
define|#
directive|define
name|MDPX_DIAG_USE_CHK
value|(1<<31)
end_define

begin_comment
comment|/* 					 * When set, DMA write cycles use the 					 * value in the low 8 bits of this 					 * register (MDPA or MDPB) as ECC 					 * sent onto main memory. 					 */
end_comment

begin_comment
comment|/*  * Interrupt Specific bits...  *  * Mostly we don't have to mess with any of the interrupt specific registers  * as the SRM has set most of this pretty complex stuff up for us.  *  * However, to enable specific interrupts, we need to set some bits  * in imask0 if we want to have them vectored to PALcode for appropriate  * dispatch.  */
end_comment

begin_comment
comment|/*  * bits 0-15 correspond to 4 slots (time 4 buspins) for each PCI bus.  * bit 16 is the NCR810 onboard SCSI interrupt.  * bits 19-20 are reserved.  */
end_comment

begin_define
define|#
directive|define
name|MCPCIA_I2C_CTRL_INTR
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|MCPCIA_I2C_CTRL_BUS_ERR
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|MCPCIA_8259_NMI_INTR
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|MCPCIA_SOFT_ERR_INTR
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|MCPCIA_HARD_ERR_INTR
value|(1<<23)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|YET
end_ifdef

begin_define
define|#
directive|define
name|MCPCIA_GEN_IENABL
define|\
value|(MCPCIA_I2C_CTRL_BUS_ERR|MCPCIA_SOFT_ERR_INTR|MCPCIA_HARD_ERR_INTR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MCPCIA_GEN_IENABL
define|\
value|(MCPCIA_SOFT_ERR_INTR|MCPCIA_HARD_ERR_INTR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * DMA Address Specific bits...  */
end_comment

begin_define
define|#
directive|define
name|MCPCIA_WBASE_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|MCPCIA_WBASE_SG
value|0x2
end_define

begin_define
define|#
directive|define
name|MCPCIA_WBASE_DAC
value|0x8
end_define

begin_define
define|#
directive|define
name|MCPCIA_WBASE_BSHIFT
value|20
end_define

begin_define
define|#
directive|define
name|MCPCIA_WMASK_1M
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MCPCIA_WMASK_2M
value|0x00100000
end_define

begin_define
define|#
directive|define
name|MCPCIA_WMASK_4M
value|0x00300000
end_define

begin_define
define|#
directive|define
name|MCPCIA_WMASK_8M
value|0x00700000
end_define

begin_define
define|#
directive|define
name|MCPCIA_WMASK_16M
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|MCPCIA_WMASK_32M
value|0x01f00000
end_define

begin_define
define|#
directive|define
name|MCPCIA_WMASK_64M
value|0x03f00000
end_define

begin_define
define|#
directive|define
name|MCPCIA_WMASK_128M
value|0x07f00000
end_define

begin_define
define|#
directive|define
name|MCPCIA_WMASK_256M
value|0x0ff00000
end_define

begin_define
define|#
directive|define
name|MCPCIA_WMASK_512M
value|0x1ff00000
end_define

begin_define
define|#
directive|define
name|MCPCIA_WMASK_1G
value|0x3ff00000
end_define

begin_define
define|#
directive|define
name|MCPCIA_WMASK_2G
value|0x7ff00000
end_define

begin_define
define|#
directive|define
name|MCPCIA_WMASK_4G
value|0xfff00000
end_define

begin_comment
comment|/*  * The WBASEX register contains bits 39:10 of a physical address  * shifted to bits 31:2 of this 32 bit register. Namely, shifted  * right by 8 bits.  */
end_comment

begin_define
define|#
directive|define
name|MCPCIA_TBASEX_SHIFT
value|8
end_define

end_unit

