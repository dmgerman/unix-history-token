begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Hidetoshi Shimokawa  * Copyright (c) 1998-2002 Katsushi Kobayashi and Hidetoshi Shimokawa  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the acknowledgement as bellow:  *  *    This product includes software developed by K. Kobayashi and H. Shimokawa  *  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  *  */
end_comment

begin_define
define|#
directive|define
name|PCI_CBMEM
value|PCIR_BAR(0)
end_define

begin_define
define|#
directive|define
name|FW_VENDORID_NATSEMI
value|0x100B
end_define

begin_define
define|#
directive|define
name|FW_VENDORID_NEC
value|0x1033
end_define

begin_define
define|#
directive|define
name|FW_VENDORID_SIS
value|0x1039
end_define

begin_define
define|#
directive|define
name|FW_VENDORID_TI
value|0x104c
end_define

begin_define
define|#
directive|define
name|FW_VENDORID_SONY
value|0x104d
end_define

begin_define
define|#
directive|define
name|FW_VENDORID_VIA
value|0x1106
end_define

begin_define
define|#
directive|define
name|FW_VENDORID_RICOH
value|0x1180
end_define

begin_define
define|#
directive|define
name|FW_VENDORID_APPLE
value|0x106b
end_define

begin_define
define|#
directive|define
name|FW_VENDORID_LUCENT
value|0x11c1
end_define

begin_define
define|#
directive|define
name|FW_VENDORID_INTEL
value|0x8086
end_define

begin_define
define|#
directive|define
name|FW_VENDORID_ADAPTEC
value|0x9004
end_define

begin_define
define|#
directive|define
name|FW_VENDORID_SUN
value|0x108e
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_CS4210
value|(0x000f<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_UPD861
value|(0x0063<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_UPD871
value|(0x00ce<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_UPD72870
value|(0x00cd<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_UPD72873
value|(0x00e7<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_UPD72874
value|(0x00f2<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_TITSB22
value|(0x8009<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_TITSB23
value|(0x8019<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_TITSB26
value|(0x8020<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_TITSB43
value|(0x8021<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_TITSB43A
value|(0x8023<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_TITSB43AB23
value|(0x8024<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_TITSB82AA2
value|(0x8025<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_TITSB43AB21
value|(0x8026<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_TIPCI4410A
value|(0x8017<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_TIPCI4450
value|(0x8011<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_TIPCI4451
value|(0x8027<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_CXD1947
value|(0x8009<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_CXD3222
value|(0x8039<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_VT6306
value|(0x3044<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_R5C551
value|(0x0551<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_R5C552
value|(0x0552<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_PANGEA
value|(0x0030<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_UNINORTH
value|(0x0031<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_AIC5800
value|(0x5800<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_FW322
value|(0x5811<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_7007
value|(0x7007<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_82372FB
value|(0x7605<< 16)
end_define

begin_define
define|#
directive|define
name|FW_DEVICE_PCIO2FW
value|(0x1102<< 16)
end_define

begin_define
define|#
directive|define
name|PCI_INTERFACE_OHCI
value|0x10
end_define

begin_define
define|#
directive|define
name|FW_OHCI_BASE_REG
value|0x10
end_define

begin_define
define|#
directive|define
name|OHCI_DMA_ITCH
value|0x20
end_define

begin_define
define|#
directive|define
name|OHCI_DMA_IRCH
value|0x20
end_define

begin_define
define|#
directive|define
name|OHCI_MAX_DMA_CH
value|(0x4 + OHCI_DMA_ITCH + OHCI_DMA_IRCH)
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|fwohcireg_t
typedef|;
end_typedef

begin_comment
comment|/* for PCI */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|FWOHCI_DMA_WRITE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) = htole32(y))
end_define

begin_define
define|#
directive|define
name|FWOHCI_DMA_READ
parameter_list|(
name|x
parameter_list|)
value|le32toh(x)
end_define

begin_define
define|#
directive|define
name|FWOHCI_DMA_SET
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) |= htole32(y))
end_define

begin_define
define|#
directive|define
name|FWOHCI_DMA_CLEAR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)&= htole32(~(y)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FWOHCI_DMA_WRITE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) = (y))
end_define

begin_define
define|#
directive|define
name|FWOHCI_DMA_READ
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|FWOHCI_DMA_SET
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) |= (y))
end_define

begin_define
define|#
directive|define
name|FWOHCI_DMA_CLEAR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)&= ~(y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|fwohcidb
block|{
union|union
block|{
struct|struct
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|depend
decl_stmt|;
name|uint32_t
name|res
decl_stmt|;
block|}
name|desc
struct|;
name|uint32_t
name|immed
index|[
literal|4
index|]
decl_stmt|;
block|}
name|db
union|;
define|#
directive|define
name|OHCI_STATUS_SHIFT
value|16
define|#
directive|define
name|OHCI_COUNT_MASK
value|0xffff
define|#
directive|define
name|OHCI_OUTPUT_MORE
value|(0<< 28)
define|#
directive|define
name|OHCI_OUTPUT_LAST
value|(1<< 28)
define|#
directive|define
name|OHCI_INPUT_MORE
value|(2<< 28)
define|#
directive|define
name|OHCI_INPUT_LAST
value|(3<< 28)
define|#
directive|define
name|OHCI_STORE_QUAD
value|(4<< 28)
define|#
directive|define
name|OHCI_LOAD_QUAD
value|(5<< 28)
define|#
directive|define
name|OHCI_NOP
value|(6<< 28)
define|#
directive|define
name|OHCI_STOP
value|(7<< 28)
define|#
directive|define
name|OHCI_STORE
value|(8<< 28)
define|#
directive|define
name|OHCI_CMD_MASK
value|(0xf<< 28)
define|#
directive|define
name|OHCI_UPDATE
value|(1<< 27)
define|#
directive|define
name|OHCI_KEY_ST0
value|(0<< 24)
define|#
directive|define
name|OHCI_KEY_ST1
value|(1<< 24)
define|#
directive|define
name|OHCI_KEY_ST2
value|(2<< 24)
define|#
directive|define
name|OHCI_KEY_ST3
value|(3<< 24)
define|#
directive|define
name|OHCI_KEY_REGS
value|(5<< 24)
define|#
directive|define
name|OHCI_KEY_SYS
value|(6<< 24)
define|#
directive|define
name|OHCI_KEY_DEVICE
value|(7<< 24)
define|#
directive|define
name|OHCI_KEY_MASK
value|(7<< 24)
define|#
directive|define
name|OHCI_INTERRUPT_NEVER
value|(0<< 20)
define|#
directive|define
name|OHCI_INTERRUPT_TRUE
value|(1<< 20)
define|#
directive|define
name|OHCI_INTERRUPT_FALSE
value|(2<< 20)
define|#
directive|define
name|OHCI_INTERRUPT_ALWAYS
value|(3<< 20)
define|#
directive|define
name|OHCI_BRANCH_NEVER
value|(0<< 18)
define|#
directive|define
name|OHCI_BRANCH_TRUE
value|(1<< 18)
define|#
directive|define
name|OHCI_BRANCH_FALSE
value|(2<< 18)
define|#
directive|define
name|OHCI_BRANCH_ALWAYS
value|(3<< 18)
define|#
directive|define
name|OHCI_BRANCH_MASK
value|(3<< 18)
define|#
directive|define
name|OHCI_WAIT_NEVER
value|(0<< 16)
define|#
directive|define
name|OHCI_WAIT_TRUE
value|(1<< 16)
define|#
directive|define
name|OHCI_WAIT_FALSE
value|(2<< 16)
define|#
directive|define
name|OHCI_WAIT_ALWAYS
value|(3<< 16)
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OHCI_SPD_S100
value|0x4
end_define

begin_define
define|#
directive|define
name|OHCI_SPD_S200
value|0x1
end_define

begin_define
define|#
directive|define
name|OHCI_SPD_S400
value|0x2
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_NOSTAT
value|0
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_LONGP
value|2
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_MISSACK
value|3
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_UNDRRUN
value|4
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_OVRRUN
value|5
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_DESCERR
value|6
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_DTRDERR
value|7
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_DTWRERR
value|8
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_BUSRST
value|9
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_TIMEOUT
value|0xa
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_TCODERR
value|0xb
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_UNKNOWN
value|0xe
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_FLUSHED
value|0xf
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_ACKCOMPL
value|0x11
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_ACKPEND
value|0x12
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_ACKBSX
value|0x14
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_ACKBSA
value|0x15
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_ACKBSB
value|0x16
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_ACKTARD
value|0x1b
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_ACKDERR
value|0x1d
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_ACKTERR
value|0x1e
end_define

begin_define
define|#
directive|define
name|FWOHCIEV_MASK
value|0x1f
end_define

begin_struct
struct|struct
name|ohci_dma
block|{
name|fwohcireg_t
name|cntl
decl_stmt|;
define|#
directive|define
name|OHCI_CNTL_CYCMATCH_S
value|(0x1<< 31)
define|#
directive|define
name|OHCI_CNTL_BUFFIL
value|(0x1<< 31)
define|#
directive|define
name|OHCI_CNTL_ISOHDR
value|(0x1<< 30)
define|#
directive|define
name|OHCI_CNTL_CYCMATCH_R
value|(0x1<< 29)
define|#
directive|define
name|OHCI_CNTL_MULTICH
value|(0x1<< 28)
define|#
directive|define
name|OHCI_CNTL_DMA_RUN
value|(0x1<< 15)
define|#
directive|define
name|OHCI_CNTL_DMA_WAKE
value|(0x1<< 12)
define|#
directive|define
name|OHCI_CNTL_DMA_DEAD
value|(0x1<< 11)
define|#
directive|define
name|OHCI_CNTL_DMA_ACTIVE
value|(0x1<< 10)
define|#
directive|define
name|OHCI_CNTL_DMA_BT
value|(0x1<< 8)
define|#
directive|define
name|OHCI_CNTL_DMA_BAD
value|(0x1<< 7)
define|#
directive|define
name|OHCI_CNTL_DMA_STAT
value|(0xff)
name|fwohcireg_t
name|cntl_clr
decl_stmt|;
name|fwohcireg_t
name|dummy0
decl_stmt|;
name|fwohcireg_t
name|cmd
decl_stmt|;
name|fwohcireg_t
name|match
decl_stmt|;
name|fwohcireg_t
name|dummy1
decl_stmt|;
name|fwohcireg_t
name|dummy2
decl_stmt|;
name|fwohcireg_t
name|dummy3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ohci_itdma
block|{
name|fwohcireg_t
name|cntl
decl_stmt|;
name|fwohcireg_t
name|cntl_clr
decl_stmt|;
name|fwohcireg_t
name|dummy0
decl_stmt|;
name|fwohcireg_t
name|cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ohci_registers
block|{
name|fwohcireg_t
name|ver
decl_stmt|;
comment|/* Version No. 0x0 */
name|fwohcireg_t
name|guid
decl_stmt|;
comment|/* GUID_ROM No. 0x4 */
name|fwohcireg_t
name|retry
decl_stmt|;
comment|/* AT retries 0x8 */
define|#
directive|define
name|FWOHCI_RETRY
value|0x8
name|fwohcireg_t
name|csr_data
decl_stmt|;
comment|/* CSR data   0xc */
name|fwohcireg_t
name|csr_cmp
decl_stmt|;
comment|/* CSR compare 0x10 */
name|fwohcireg_t
name|csr_cntl
decl_stmt|;
comment|/* CSR compare 0x14 */
name|fwohcireg_t
name|rom_hdr
decl_stmt|;
comment|/* config ROM ptr. 0x18 */
name|fwohcireg_t
name|bus_id
decl_stmt|;
comment|/* BUS_ID 0x1c */
name|fwohcireg_t
name|bus_opt
decl_stmt|;
comment|/* BUS option 0x20 */
define|#
directive|define
name|FWOHCIGUID_H
value|0x24
define|#
directive|define
name|FWOHCIGUID_L
value|0x28
name|fwohcireg_t
name|guid_hi
decl_stmt|;
comment|/* GUID hi 0x24 */
name|fwohcireg_t
name|guid_lo
decl_stmt|;
comment|/* GUID lo 0x28 */
name|fwohcireg_t
name|dummy0
index|[
literal|2
index|]
decl_stmt|;
comment|/* dummy 0x2c-0x30 */
name|fwohcireg_t
name|config_rom
decl_stmt|;
comment|/* config ROM map 0x34 */
name|fwohcireg_t
name|post_wr_lo
decl_stmt|;
comment|/* post write addr lo 0x38 */
name|fwohcireg_t
name|post_wr_hi
decl_stmt|;
comment|/* post write addr hi 0x3c */
name|fwohcireg_t
name|vender
decl_stmt|;
comment|/* vender ID 0x40 */
name|fwohcireg_t
name|dummy1
index|[
literal|3
index|]
decl_stmt|;
comment|/* dummy 0x44-0x4c */
name|fwohcireg_t
name|hcc_cntl_set
decl_stmt|;
comment|/* HCC control set 0x50 */
name|fwohcireg_t
name|hcc_cntl_clr
decl_stmt|;
comment|/* HCC control clr 0x54 */
define|#
directive|define
name|OHCI_HCC_BIBIV
value|(1<< 31)
comment|/* BIBimage Valid */
define|#
directive|define
name|OHCI_HCC_BIGEND
value|(1<< 30)
comment|/* noByteSwapData */
define|#
directive|define
name|OHCI_HCC_PRPHY
value|(1<< 23)
comment|/* programPhyEnable */
define|#
directive|define
name|OHCI_HCC_PHYEN
value|(1<< 22)
comment|/* aPhyEnhanceEnable */
define|#
directive|define
name|OHCI_HCC_LPS
value|(1<< 19)
comment|/* LPS */
define|#
directive|define
name|OHCI_HCC_POSTWR
value|(1<< 18)
comment|/* postedWriteEnable */
define|#
directive|define
name|OHCI_HCC_LINKEN
value|(1<< 17)
comment|/* linkEnable */
define|#
directive|define
name|OHCI_HCC_RESET
value|(1<< 16)
comment|/* softReset */
name|fwohcireg_t
name|dummy2
index|[
literal|2
index|]
decl_stmt|;
comment|/* dummy 0x58-0x5c */
name|fwohcireg_t
name|dummy3
index|[
literal|1
index|]
decl_stmt|;
comment|/* dummy 0x60 */
name|fwohcireg_t
name|sid_buf
decl_stmt|;
comment|/* self id buffer 0x64 */
name|fwohcireg_t
name|sid_cnt
decl_stmt|;
comment|/* self id count 0x68 */
name|fwohcireg_t
name|dummy4
index|[
literal|1
index|]
decl_stmt|;
comment|/* dummy 0x6c */
name|fwohcireg_t
name|ir_mask_hi_set
decl_stmt|;
comment|/* ir mask hi set 0x70 */
name|fwohcireg_t
name|ir_mask_hi_clr
decl_stmt|;
comment|/* ir mask hi set 0x74 */
name|fwohcireg_t
name|ir_mask_lo_set
decl_stmt|;
comment|/* ir mask hi set 0x78 */
name|fwohcireg_t
name|ir_mask_lo_clr
decl_stmt|;
comment|/* ir mask hi set 0x7c */
define|#
directive|define
name|FWOHCI_INTSTAT
value|0x80
define|#
directive|define
name|FWOHCI_INTSTATCLR
value|0x84
define|#
directive|define
name|FWOHCI_INTMASK
value|0x88
define|#
directive|define
name|FWOHCI_INTMASKCLR
value|0x8c
name|fwohcireg_t
name|int_stat
decl_stmt|;
comment|/*       0x80 */
name|fwohcireg_t
name|int_clear
decl_stmt|;
comment|/*       0x84 */
name|fwohcireg_t
name|int_mask
decl_stmt|;
comment|/*       0x88 */
name|fwohcireg_t
name|int_mask_clear
decl_stmt|;
comment|/*       0x8c */
name|fwohcireg_t
name|it_int_stat
decl_stmt|;
comment|/*       0x90 */
name|fwohcireg_t
name|it_int_clear
decl_stmt|;
comment|/*       0x94 */
name|fwohcireg_t
name|it_int_mask
decl_stmt|;
comment|/*       0x98 */
name|fwohcireg_t
name|it_mask_clear
decl_stmt|;
comment|/*       0x9c */
name|fwohcireg_t
name|ir_int_stat
decl_stmt|;
comment|/*       0xa0 */
name|fwohcireg_t
name|ir_int_clear
decl_stmt|;
comment|/*       0xa4 */
name|fwohcireg_t
name|ir_int_mask
decl_stmt|;
comment|/*       0xa8 */
name|fwohcireg_t
name|ir_mask_clear
decl_stmt|;
comment|/*       0xac */
name|fwohcireg_t
name|dummy5
index|[
literal|11
index|]
decl_stmt|;
comment|/* dummy 0xb0-d8 */
name|fwohcireg_t
name|fairness
decl_stmt|;
comment|/* fairness control      0xdc */
name|fwohcireg_t
name|link_cntl
decl_stmt|;
comment|/* Chip control 0xe0*/
name|fwohcireg_t
name|link_cntl_clr
decl_stmt|;
comment|/* Chip control clear 0xe4*/
define|#
directive|define
name|FWOHCI_NODEID
value|0xe8
name|fwohcireg_t
name|node
decl_stmt|;
comment|/* Node ID 0xe8 */
define|#
directive|define
name|OHCI_NODE_VALID
value|(1<< 31)
define|#
directive|define
name|OHCI_NODE_ROOT
value|(1<< 30)
define|#
directive|define
name|OHCI_ASYSRCBUS
value|1
name|fwohcireg_t
name|phy_access
decl_stmt|;
comment|/* PHY cntl 0xec */
define|#
directive|define
name|PHYDEV_RDDONE
value|(1<<31)
define|#
directive|define
name|PHYDEV_RDCMD
value|(1<<15)
define|#
directive|define
name|PHYDEV_WRCMD
value|(1<<14)
define|#
directive|define
name|PHYDEV_REGADDR
value|8
define|#
directive|define
name|PHYDEV_WRDATA
value|0
define|#
directive|define
name|PHYDEV_RDADDR
value|24
define|#
directive|define
name|PHYDEV_RDDATA
value|16
name|fwohcireg_t
name|cycle_timer
decl_stmt|;
comment|/* Cycle Timer 0xf0 */
name|fwohcireg_t
name|dummy6
index|[
literal|3
index|]
decl_stmt|;
comment|/* dummy 0xf4-fc */
name|fwohcireg_t
name|areq_hi
decl_stmt|;
comment|/* Async req. filter hi 0x100 */
name|fwohcireg_t
name|areq_hi_clr
decl_stmt|;
comment|/* Async req. filter hi 0x104 */
name|fwohcireg_t
name|areq_lo
decl_stmt|;
comment|/* Async req. filter lo 0x108 */
name|fwohcireg_t
name|areq_lo_clr
decl_stmt|;
comment|/* Async req. filter lo 0x10c */
name|fwohcireg_t
name|preq_hi
decl_stmt|;
comment|/* Async req. filter hi 0x110 */
name|fwohcireg_t
name|preq_hi_clr
decl_stmt|;
comment|/* Async req. filter hi 0x114 */
name|fwohcireg_t
name|preq_lo
decl_stmt|;
comment|/* Async req. filter lo 0x118 */
name|fwohcireg_t
name|preq_lo_clr
decl_stmt|;
comment|/* Async req. filter lo 0x11c */
name|fwohcireg_t
name|pys_upper
decl_stmt|;
comment|/* Physical Upper bound 0x120 */
name|fwohcireg_t
name|dummy7
index|[
literal|23
index|]
decl_stmt|;
comment|/* dummy 0x124-0x17c */
comment|/*       0x180, 0x184, 0x188, 0x18c */
comment|/*       0x190, 0x194, 0x198, 0x19c */
comment|/*       0x1a0, 0x1a4, 0x1a8, 0x1ac */
comment|/*       0x1b0, 0x1b4, 0x1b8, 0x1bc */
comment|/*       0x1c0, 0x1c4, 0x1c8, 0x1cc */
comment|/*       0x1d0, 0x1d4, 0x1d8, 0x1dc */
comment|/*       0x1e0, 0x1e4, 0x1e8, 0x1ec */
comment|/*       0x1f0, 0x1f4, 0x1f8, 0x1fc */
name|struct
name|ohci_dma
name|dma_ch
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0x200, 0x204, 0x208, 0x20c */
comment|/*       0x210, 0x204, 0x208, 0x20c */
name|struct
name|ohci_itdma
name|dma_itch
index|[
literal|0x20
index|]
decl_stmt|;
comment|/*       0x400, 0x404, 0x408, 0x40c */
comment|/*       0x410, 0x404, 0x408, 0x40c */
name|struct
name|ohci_dma
name|dma_irch
index|[
literal|0x20
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fwohcidb_tr
block|{
name|STAILQ_ENTRY
argument_list|(
argument|fwohcidb_tr
argument_list|)
name|link
expr_stmt|;
name|struct
name|fw_xfer
modifier|*
name|xfer
decl_stmt|;
name|struct
name|fwohcidb
modifier|*
name|db
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|caddr_t
name|buf
decl_stmt|;
name|bus_addr_t
name|bus_addr
decl_stmt|;
name|int
name|dbcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * OHCI info structure.  */
end_comment

begin_struct
struct|struct
name|fwohci_txpkthdr
block|{
union|union
block|{
name|uint32_t
name|ld
index|[
literal|4
index|]
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint32_t
name|spd
range|:
literal|16
decl_stmt|,
comment|/* XXX include reserved field */
range|:
literal|8
decl_stmt|,
name|tcode
range|:
literal|4
decl_stmt|,
range|:
literal|4
decl_stmt|;
else|#
directive|else
name|uint32_t
label|:
literal|4
operator|,
name|tcode
operator|:
literal|4
operator|,
operator|:
literal|8
operator|,
name|spd
operator|:
literal|16
expr_stmt|;
comment|/* XXX include reserved fields */
endif|#
directive|endif
block|}
name|common
struct|;
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint32_t
label|:
literal|8
operator|,
name|srcbus
operator|:
literal|1
operator|,
operator|:
literal|4
operator|,
name|spd
operator|:
literal|3
operator|,
name|tlrt
operator|:
literal|8
operator|,
name|tcode
operator|:
literal|4
operator|,
operator|:
literal|4
expr_stmt|;
else|#
directive|else
name|uint32_t
label|:
literal|4
operator|,
name|tcode
operator|:
literal|4
operator|,
name|tlrt
operator|:
literal|8
operator|,
name|spd
operator|:
literal|3
operator|,
operator|:
literal|4
operator|,
name|srcbus
operator|:
literal|1
operator|,
operator|:
literal|8
expr_stmt|;
endif|#
directive|endif
name|BIT16x2
argument_list|(
name|dst
argument_list|, )
expr_stmt|;
block|}
name|asycomm
struct|;
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint32_t
label|:
literal|13
operator|,
name|spd
operator|:
literal|3
operator|,
name|chtag
operator|:
literal|8
operator|,
name|tcode
operator|:
literal|4
operator|,
name|sy
operator|:
literal|4
expr_stmt|;
else|#
directive|else
name|uint32_t
name|sy
range|:
literal|4
decl_stmt|,
name|tcode
range|:
literal|4
decl_stmt|,
name|chtag
range|:
literal|8
decl_stmt|,
name|spd
range|:
literal|3
decl_stmt|,
range|:
literal|13
decl_stmt|;
endif|#
directive|endif
name|BIT16x2
argument_list|(
name|len
argument_list|, )
expr_stmt|;
block|}
name|stream
struct|;
block|}
name|mode
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fwohci_trailer
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|uint32_t
name|stat
range|:
literal|16
decl_stmt|,
name|time
range|:
literal|16
decl_stmt|;
else|#
directive|else
name|uint32_t
name|time
range|:
literal|16
decl_stmt|,
name|stat
range|:
literal|16
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OHCI_CNTL_CYCSRC
value|(0x1<< 22)
end_define

begin_define
define|#
directive|define
name|OHCI_CNTL_CYCMTR
value|(0x1<< 21)
end_define

begin_define
define|#
directive|define
name|OHCI_CNTL_CYCTIMER
value|(0x1<< 20)
end_define

begin_define
define|#
directive|define
name|OHCI_CNTL_PHYPKT
value|(0x1<< 10)
end_define

begin_define
define|#
directive|define
name|OHCI_CNTL_SID
value|(0x1<< 9)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_DMA_ATRQ
value|(0x1<< 0)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_DMA_ATRS
value|(0x1<< 1)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_DMA_ARRQ
value|(0x1<< 2)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_DMA_ARRS
value|(0x1<< 3)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_DMA_PRRQ
value|(0x1<< 4)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_DMA_PRRS
value|(0x1<< 5)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_DMA_IT
value|(0x1<< 6)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_DMA_IR
value|(0x1<< 7)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_PW_ERR
value|(0x1<< 8)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_LR_ERR
value|(0x1<< 9)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_PHY_SID
value|(0x1<< 16)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_PHY_BUS_R
value|(0x1<< 17)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_REG_FAIL
value|(0x1<< 18)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_PHY_INT
value|(0x1<< 19)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_CYC_START
value|(0x1<< 20)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_CYC_64SECOND
value|(0x1<< 21)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_CYC_LOST
value|(0x1<< 22)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_CYC_ERR
value|(0x1<< 23)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_ERR
value|(0x1<< 24)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_CYC_LONG
value|(0x1<< 25)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_PHY_REG
value|(0x1<< 26)
end_define

begin_define
define|#
directive|define
name|OHCI_INT_EN
value|(0x1<< 31)
end_define

begin_define
define|#
directive|define
name|IP_CHANNELS
value|0x0234
end_define

begin_define
define|#
directive|define
name|FWOHCI_MAXREC
value|2048
end_define

begin_define
define|#
directive|define
name|OHCI_ISORA
value|0x02
end_define

begin_define
define|#
directive|define
name|OHCI_ISORB
value|0x04
end_define

begin_define
define|#
directive|define
name|FWOHCITCODE_PHY
value|0xe
end_define

end_unit

