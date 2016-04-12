begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Stanislav Galabov.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MTK_PCIE_H__
end_ifndef

begin_define
define|#
directive|define
name|__MTK_PCIE_H__
end_define

begin_define
define|#
directive|define
name|MTK_PCI_NIRQS
value|3
end_define

begin_define
define|#
directive|define
name|MTK_PCI_BASESLOT
value|0
end_define

begin_struct
struct|struct
name|mtk_pci_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|pci_res
index|[
name|MTK_PCI_NIRQS
operator|+
literal|1
index|]
decl_stmt|;
name|void
modifier|*
name|pci_intrhand
index|[
name|MTK_PCI_NIRQS
index|]
decl_stmt|;
name|int
name|sc_busno
decl_stmt|;
name|int
name|sc_cur_secbus
decl_stmt|;
name|struct
name|rman
name|sc_mem_rman
decl_stmt|;
name|struct
name|rman
name|sc_io_rman
decl_stmt|;
name|struct
name|rman
name|sc_irq_rman
decl_stmt|;
name|uint32_t
name|sc_num_irq
decl_stmt|;
name|uint32_t
name|sc_irq_start
decl_stmt|;
name|uint32_t
name|sc_irq_end
decl_stmt|;
name|bus_addr_t
name|sc_mem_base
decl_stmt|;
name|bus_addr_t
name|sc_mem_size
decl_stmt|;
name|bus_addr_t
name|sc_io_base
decl_stmt|;
name|bus_addr_t
name|sc_io_size
decl_stmt|;
name|struct
name|intr_event
modifier|*
name|sc_eventstab
index|[
name|MTK_PCI_NIRQS
index|]
decl_stmt|;
name|uint32_t
name|pcie_link_status
decl_stmt|;
name|uint32_t
name|num_slots
decl_stmt|;
name|uint32_t
name|socid
decl_stmt|;
name|uint32_t
name|addr_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MTK_PCI_PCICFG
value|0x0000
end_define

begin_define
define|#
directive|define
name|MTK_PCI_RESET
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|MTK_PCI_PCIINT
value|0x0008
end_define

begin_define
define|#
directive|define
name|MTK_PCI_PCIENA
value|0x000C
end_define

begin_define
define|#
directive|define
name|MTK_PCI_CFGADDR
value|0x0020
end_define

begin_define
define|#
directive|define
name|MTK_PCI_CFGDATA
value|0x0024
end_define

begin_define
define|#
directive|define
name|MTK_PCI_MEMBASE
value|0x0028
end_define

begin_define
define|#
directive|define
name|MTK_PCI_IOBASE
value|0x002C
end_define

begin_define
define|#
directive|define
name|MTK_PCI_ARBCTL
value|0x0080
end_define

begin_define
define|#
directive|define
name|MTK_PCI_PHY0_CFG
value|0x0090
end_define

begin_define
define|#
directive|define
name|MTK_PCI_PCIE0_BAR0SETUP
value|0x2010
end_define

begin_define
define|#
directive|define
name|MTK_PCI_PCIE0_BAR1SETUP
value|0x2014
end_define

begin_define
define|#
directive|define
name|MTK_PCI_PCIE0_IMBASEBAR0
value|0x2018
end_define

begin_define
define|#
directive|define
name|MTK_PCI_PCIE0_ID
value|0x2030
end_define

begin_define
define|#
directive|define
name|MTK_PCI_PCIE0_CLASS
value|0x2034
end_define

begin_define
define|#
directive|define
name|MTK_PCI_PCIE0_SUBID
value|0x2038
end_define

begin_define
define|#
directive|define
name|MTK_PCI_PCIE0_STATUS
value|0x2050
end_define

begin_define
define|#
directive|define
name|MTK_PCI_PCIE0_DLECR
value|0x2060
end_define

begin_define
define|#
directive|define
name|MTK_PCI_PCIE0_ECRC
value|0x2064
end_define

begin_define
define|#
directive|define
name|MTK_PCIE_BAR0SETUP
parameter_list|(
name|_s
parameter_list|)
value|(MTK_PCI_PCIE0_BAR0SETUP + (_s)*0x1000)
end_define

begin_define
define|#
directive|define
name|MTK_PCIE_BAR1SETUP
parameter_list|(
name|_s
parameter_list|)
value|(MTK_PCI_PCIE0_BAR1SETUP + (_s)*0x1000)
end_define

begin_define
define|#
directive|define
name|MTK_PCIE_IMBASEBAR0
parameter_list|(
name|_s
parameter_list|)
value|(MTK_PCI_PCIE0_IMBASEBAR0 + (_s)*0x1000)
end_define

begin_define
define|#
directive|define
name|MTK_PCIE_ID
parameter_list|(
name|_s
parameter_list|)
value|(MTK_PCI_PCIE0_ID + (_s)*0x1000)
end_define

begin_define
define|#
directive|define
name|MTK_PCIE_CLASS
parameter_list|(
name|_s
parameter_list|)
value|(MTK_PCI_PCIE0_CLASS + (_s)*0x1000)
end_define

begin_define
define|#
directive|define
name|MTK_PCIE_SUBID
parameter_list|(
name|_s
parameter_list|)
value|(MTK_PCI_PCIE0_SUBID + (_s)*0x1000)
end_define

begin_define
define|#
directive|define
name|MTK_PCIE_STATUS
parameter_list|(
name|_s
parameter_list|)
value|(MTK_PCI_PCIE0_STATUS + (_s)*0x1000)
end_define

begin_define
define|#
directive|define
name|MTK_PCIE0_IRQ
value|20
end_define

begin_define
define|#
directive|define
name|MTK_PCIE1_IRQ
value|21
end_define

begin_define
define|#
directive|define
name|MTK_PCIE2_IRQ
value|22
end_define

begin_define
define|#
directive|define
name|MTK_PCI_INTR_PIN
value|2
end_define

begin_comment
comment|/* Chip specific defines */
end_comment

begin_define
define|#
directive|define
name|MT7620_MAX_RETRIES
value|10
end_define

begin_define
define|#
directive|define
name|MT7620_PCIE_PHY_CFG
value|0x90
end_define

begin_define
define|#
directive|define
name|PHY_BUSY
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|PHY_MODE_WRITE
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|PHY_ADDR_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|MT7620_PPLL_CFG0
value|0x98
end_define

begin_define
define|#
directive|define
name|PPLL_SW_SET
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|MT7620_PPLL_CFG1
value|0x9c
end_define

begin_define
define|#
directive|define
name|PPLL_PD
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|PPLL_LOCKED
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|MT7620_PPLL_DRV
value|0xa0
end_define

begin_define
define|#
directive|define
name|PDRV_SW_SET
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|LC_CKDRVPD
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|LC_CKDRVOHZ
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|LC_CKDRVHZ
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|MT7620_PERST_GPIO_MODE
value|(3<<16)
end_define

begin_define
define|#
directive|define
name|MT7620_PERST
value|(0<<16)
end_define

begin_define
define|#
directive|define
name|MT7620_GPIO
value|(2<<16)
end_define

begin_define
define|#
directive|define
name|MT7620_PKG_BGA
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|MT7628_PERST_GPIO_MODE
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|MT7628_PERST
value|(0<<16)
end_define

begin_define
define|#
directive|define
name|MT7621_PERST_GPIO_MODE
value|(3<<10)
end_define

begin_define
define|#
directive|define
name|MT7621_PERST_GPIO
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|MT7621_UARTL3_GPIO_MODE
value|(3<<3)
end_define

begin_define
define|#
directive|define
name|MT7621_UARTL3_GPIO
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|MT7621_PCIE0_RST
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|MT7621_PCIE1_RST
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|MT7621_PCIE2_RST
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|MT7621_PCIE_RST
value|(MT7621_PCIE0_RST | MT7621_PCIE1_RST | \ 				 MT7621_PCIE2_RST)
end_define

begin_define
define|#
directive|define
name|RT3883_PCI_RST
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|RT3883_PCI_CLK
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|RT3883_PCI_HOST_MODE
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|RT3883_PCIE_RC_MODE
value|(1<<8)
end_define

begin_comment
comment|/* End of chip specific defines */
end_comment

begin_define
define|#
directive|define
name|MT_WRITE32
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4((sc)->pci_res[0], (off), (val))
end_define

begin_define
define|#
directive|define
name|MT_WRITE16
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_2((sc)->pci_res[0], (off), (val))
end_define

begin_define
define|#
directive|define
name|MT_WRITE8
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_1((sc)->pci_res[0], (off), (val))
end_define

begin_define
define|#
directive|define
name|MT_READ32
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
define|\
value|bus_read_4((sc)->pci_res[0], (off))
end_define

begin_define
define|#
directive|define
name|MT_READ16
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
define|\
value|bus_read_2((sc)->pci_res[0], (off))
end_define

begin_define
define|#
directive|define
name|MT_READ8
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
define|\
value|bus_read_1((sc)->pci_res[0], (off))
end_define

begin_define
define|#
directive|define
name|MT_CLR_SET32
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|clr
parameter_list|,
name|set
parameter_list|)
define|\
value|MT_WRITE32((sc), (off), ((MT_READ32((sc), (off))& ~(clr)) | (off)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MTK_PCIE_H__ */
end_comment

end_unit

