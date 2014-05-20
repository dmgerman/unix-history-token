begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, Stefan Esser<se@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * PCIM_xxx: mask to locate subfield in register  * PCIR_xxx: config register offset  * PCIC_xxx: device class  * PCIS_xxx: device subclass  * PCIP_xxx: device programming interface  * PCIV_xxx: PCI vendor ID (only required to fixup ancient devices)  * PCID_xxx: device ID  * PCIY_xxx: capability identification number  * PCIZ_xxx: extended capability identification number  */
end_comment

begin_comment
comment|/* some PCI bus constants */
end_comment

begin_define
define|#
directive|define
name|PCI_DOMAINMAX
value|65535
end_define

begin_comment
comment|/* highest supported domain number */
end_comment

begin_define
define|#
directive|define
name|PCI_BUSMAX
value|255
end_define

begin_comment
comment|/* highest supported bus number */
end_comment

begin_define
define|#
directive|define
name|PCI_SLOTMAX
value|31
end_define

begin_comment
comment|/* highest supported slot number */
end_comment

begin_define
define|#
directive|define
name|PCI_FUNCMAX
value|7
end_define

begin_comment
comment|/* highest supported function number */
end_comment

begin_define
define|#
directive|define
name|PCI_REGMAX
value|255
end_define

begin_comment
comment|/* highest supported config register addr. */
end_comment

begin_define
define|#
directive|define
name|PCIE_REGMAX
value|4095
end_define

begin_comment
comment|/* highest supported config register addr. */
end_comment

begin_define
define|#
directive|define
name|PCI_MAXHDRTYPE
value|2
end_define

begin_define
define|#
directive|define
name|PCIE_ARI_SLOTMAX
value|0
end_define

begin_define
define|#
directive|define
name|PCIE_ARI_FUNCMAX
value|255
end_define

begin_define
define|#
directive|define
name|PCI_RID_BUS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PCI_RID_SLOT_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|PCI_RID_FUNC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PCI_RID
parameter_list|(
name|bus
parameter_list|,
name|slot
parameter_list|,
name|func
parameter_list|)
define|\
value|((((bus)& PCI_BUSMAX)<< PCI_RID_BUS_SHIFT) | \     (((slot)& PCI_SLOTMAX)<< PCI_RID_SLOT_SHIFT) | \     (((func)& PCI_FUNCMAX)<< PCI_RID_FUNC_SHIFT))
end_define

begin_define
define|#
directive|define
name|PCI_ARI_RID
parameter_list|(
name|bus
parameter_list|,
name|func
parameter_list|)
define|\
value|((((bus)& PCI_BUSMAX)<< PCI_RID_BUS_SHIFT) | \     (((func)& PCIE_ARI_FUNCMAX)<< PCI_RID_FUNC_SHIFT))
end_define

begin_define
define|#
directive|define
name|PCI_RID2BUS
parameter_list|(
name|rid
parameter_list|)
value|(((rid)>> PCI_RID_BUS_SHIFT)& PCI_BUSMAX)
end_define

begin_define
define|#
directive|define
name|PCI_RID2SLOT
parameter_list|(
name|rid
parameter_list|)
value|(((rid)>> PCI_RID_SLOT_SHIFT)& PCI_SLOTMAX)
end_define

begin_define
define|#
directive|define
name|PCI_RID2FUNC
parameter_list|(
name|rid
parameter_list|)
value|(((rid)>> PCI_RID_FUNC_SHIFT)& PCI_FUNCMAX)
end_define

begin_define
define|#
directive|define
name|PCIE_ARI_SLOT
parameter_list|(
name|func
parameter_list|)
value|(((func)>> PCI_RID_SLOT_SHIFT)& PCI_SLOTMAX)
end_define

begin_define
define|#
directive|define
name|PCIE_ARI_FUNC
parameter_list|(
name|func
parameter_list|)
value|(((func)>> PCI_RID_FUNC_SHIFT)& PCI_FUNCMAX)
end_define

begin_comment
comment|/* PCI config header registers for all devices */
end_comment

begin_define
define|#
directive|define
name|PCIR_DEVVENDOR
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIR_VENDOR
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIR_DEVICE
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIR_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_PORTEN
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_MEMEN
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_BUSMASTEREN
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_SPECIALEN
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_MWRICEN
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_PERRESPEN
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_SERRESPEN
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_BACKTOBACK
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_INTxDIS
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIR_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_INTxSTATE
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_CAPPRESENT
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_66CAPABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_BACKTOBACK
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_MDPERR
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_SEL_FAST
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_SEL_MEDIMUM
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_SEL_SLOW
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_SEL_MASK
value|0x0600
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_STABORT
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_RTABORT
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_RMABORT
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_SERR
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_PERR
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCIR_REVID
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIR_PROGIF
value|0x09
end_define

begin_define
define|#
directive|define
name|PCIR_SUBCLASS
value|0x0a
end_define

begin_define
define|#
directive|define
name|PCIR_CLASS
value|0x0b
end_define

begin_define
define|#
directive|define
name|PCIR_CACHELNSZ
value|0x0c
end_define

begin_define
define|#
directive|define
name|PCIR_LATTIMER
value|0x0d
end_define

begin_define
define|#
directive|define
name|PCIR_HDRTYPE
value|0x0e
end_define

begin_define
define|#
directive|define
name|PCIM_HDRTYPE
value|0x7f
end_define

begin_define
define|#
directive|define
name|PCIM_HDRTYPE_NORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIM_HDRTYPE_BRIDGE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIM_HDRTYPE_CARDBUS
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIM_MFDEV
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIR_BIST
value|0x0f
end_define

begin_comment
comment|/* Capability Register Offsets */
end_comment

begin_define
define|#
directive|define
name|PCICAP_ID
value|0x0
end_define

begin_define
define|#
directive|define
name|PCICAP_NEXTPTR
value|0x1
end_define

begin_comment
comment|/* Capability Identification Numbers */
end_comment

begin_define
define|#
directive|define
name|PCIY_PMG
value|0x01
end_define

begin_comment
comment|/* PCI Power Management */
end_comment

begin_define
define|#
directive|define
name|PCIY_AGP
value|0x02
end_define

begin_comment
comment|/* AGP */
end_comment

begin_define
define|#
directive|define
name|PCIY_VPD
value|0x03
end_define

begin_comment
comment|/* Vital Product Data */
end_comment

begin_define
define|#
directive|define
name|PCIY_SLOTID
value|0x04
end_define

begin_comment
comment|/* Slot Identification */
end_comment

begin_define
define|#
directive|define
name|PCIY_MSI
value|0x05
end_define

begin_comment
comment|/* Message Signaled Interrupts */
end_comment

begin_define
define|#
directive|define
name|PCIY_CHSWP
value|0x06
end_define

begin_comment
comment|/* CompactPCI Hot Swap */
end_comment

begin_define
define|#
directive|define
name|PCIY_PCIX
value|0x07
end_define

begin_comment
comment|/* PCI-X */
end_comment

begin_define
define|#
directive|define
name|PCIY_HT
value|0x08
end_define

begin_comment
comment|/* HyperTransport */
end_comment

begin_define
define|#
directive|define
name|PCIY_VENDOR
value|0x09
end_define

begin_comment
comment|/* Vendor Unique */
end_comment

begin_define
define|#
directive|define
name|PCIY_DEBUG
value|0x0a
end_define

begin_comment
comment|/* Debug port */
end_comment

begin_define
define|#
directive|define
name|PCIY_CRES
value|0x0b
end_define

begin_comment
comment|/* CompactPCI central resource control */
end_comment

begin_define
define|#
directive|define
name|PCIY_HOTPLUG
value|0x0c
end_define

begin_comment
comment|/* PCI Hot-Plug */
end_comment

begin_define
define|#
directive|define
name|PCIY_SUBVENDOR
value|0x0d
end_define

begin_comment
comment|/* PCI-PCI bridge subvendor ID */
end_comment

begin_define
define|#
directive|define
name|PCIY_AGP8X
value|0x0e
end_define

begin_comment
comment|/* AGP 8x */
end_comment

begin_define
define|#
directive|define
name|PCIY_SECDEV
value|0x0f
end_define

begin_comment
comment|/* Secure Device */
end_comment

begin_define
define|#
directive|define
name|PCIY_EXPRESS
value|0x10
end_define

begin_comment
comment|/* PCI Express */
end_comment

begin_define
define|#
directive|define
name|PCIY_MSIX
value|0x11
end_define

begin_comment
comment|/* MSI-X */
end_comment

begin_define
define|#
directive|define
name|PCIY_SATA
value|0x12
end_define

begin_comment
comment|/* SATA */
end_comment

begin_define
define|#
directive|define
name|PCIY_PCIAF
value|0x13
end_define

begin_comment
comment|/* PCI Advanced Features */
end_comment

begin_comment
comment|/* Extended Capability Register Fields */
end_comment

begin_define
define|#
directive|define
name|PCIR_EXTCAP
value|0x100
end_define

begin_define
define|#
directive|define
name|PCIM_EXTCAP_ID
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|PCIM_EXTCAP_VER
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|PCIM_EXTCAP_NEXTPTR
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|PCI_EXTCAP_ID
parameter_list|(
name|ecap
parameter_list|)
value|((ecap)& PCIM_EXTCAP_ID)
end_define

begin_define
define|#
directive|define
name|PCI_EXTCAP_VER
parameter_list|(
name|ecap
parameter_list|)
value|(((ecap)& PCIM_EXTCAP_VER)>> 16)
end_define

begin_define
define|#
directive|define
name|PCI_EXTCAP_NEXTPTR
parameter_list|(
name|ecap
parameter_list|)
value|(((ecap)& PCIM_EXTCAP_NEXTPTR)>> 20)
end_define

begin_comment
comment|/* Extended Capability Identification Numbers */
end_comment

begin_define
define|#
directive|define
name|PCIZ_AER
value|0x0001
end_define

begin_comment
comment|/* Advanced Error Reporting */
end_comment

begin_define
define|#
directive|define
name|PCIZ_VC
value|0x0002
end_define

begin_comment
comment|/* Virtual Channel if MFVC Ext Cap not set */
end_comment

begin_define
define|#
directive|define
name|PCIZ_SERNUM
value|0x0003
end_define

begin_comment
comment|/* Device Serial Number */
end_comment

begin_define
define|#
directive|define
name|PCIZ_PWRBDGT
value|0x0004
end_define

begin_comment
comment|/* Power Budgeting */
end_comment

begin_define
define|#
directive|define
name|PCIZ_RCLINK_DCL
value|0x0005
end_define

begin_comment
comment|/* Root Complex Link Declaration */
end_comment

begin_define
define|#
directive|define
name|PCIZ_RCLINK_CTL
value|0x0006
end_define

begin_comment
comment|/* Root Complex Internal Link Control */
end_comment

begin_define
define|#
directive|define
name|PCIZ_RCEC_ASSOC
value|0x0007
end_define

begin_comment
comment|/* Root Complex Event Collector Association */
end_comment

begin_define
define|#
directive|define
name|PCIZ_MFVC
value|0x0008
end_define

begin_comment
comment|/* Multi-Function Virtual Channel */
end_comment

begin_define
define|#
directive|define
name|PCIZ_VC2
value|0x0009
end_define

begin_comment
comment|/* Virtual Channel if MFVC Ext Cap set */
end_comment

begin_define
define|#
directive|define
name|PCIZ_RCRB
value|0x000a
end_define

begin_comment
comment|/* RCRB Header */
end_comment

begin_define
define|#
directive|define
name|PCIZ_VENDOR
value|0x000b
end_define

begin_comment
comment|/* Vendor Unique */
end_comment

begin_define
define|#
directive|define
name|PCIZ_CAC
value|0x000c
end_define

begin_comment
comment|/* Configuration Access Correction -- obsolete */
end_comment

begin_define
define|#
directive|define
name|PCIZ_ACS
value|0x000d
end_define

begin_comment
comment|/* Access Control Services */
end_comment

begin_define
define|#
directive|define
name|PCIZ_ARI
value|0x000e
end_define

begin_comment
comment|/* Alternative Routing-ID Interpretation */
end_comment

begin_define
define|#
directive|define
name|PCIZ_ATS
value|0x000f
end_define

begin_comment
comment|/* Address Translation Services */
end_comment

begin_define
define|#
directive|define
name|PCIZ_SRIOV
value|0x0010
end_define

begin_comment
comment|/* Single Root IO Virtualization */
end_comment

begin_define
define|#
directive|define
name|PCIZ_MRIOV
value|0x0011
end_define

begin_comment
comment|/* Multiple Root IO Virtualization */
end_comment

begin_define
define|#
directive|define
name|PCIZ_MULTICAST
value|0x0012
end_define

begin_comment
comment|/* Multicast */
end_comment

begin_define
define|#
directive|define
name|PCIZ_PAGE_REQ
value|0x0013
end_define

begin_comment
comment|/* Page Request */
end_comment

begin_define
define|#
directive|define
name|PCIZ_AMD
value|0x0014
end_define

begin_comment
comment|/* Reserved for AMD */
end_comment

begin_define
define|#
directive|define
name|PCIZ_RESIZE_BAR
value|0x0015
end_define

begin_comment
comment|/* Resizable BAR */
end_comment

begin_define
define|#
directive|define
name|PCIZ_DPA
value|0x0016
end_define

begin_comment
comment|/* Dynamic Power Allocation */
end_comment

begin_define
define|#
directive|define
name|PCIZ_TPH_REQ
value|0x0017
end_define

begin_comment
comment|/* TPH Requester */
end_comment

begin_define
define|#
directive|define
name|PCIZ_LTR
value|0x0018
end_define

begin_comment
comment|/* Latency Tolerance Reporting */
end_comment

begin_define
define|#
directive|define
name|PCIZ_SEC_PCIE
value|0x0019
end_define

begin_comment
comment|/* Secondary PCI Express */
end_comment

begin_define
define|#
directive|define
name|PCIZ_PMUX
value|0x001a
end_define

begin_comment
comment|/* Protocol Multiplexing */
end_comment

begin_define
define|#
directive|define
name|PCIZ_PASID
value|0x001b
end_define

begin_comment
comment|/* Process Address Space ID */
end_comment

begin_define
define|#
directive|define
name|PCIZ_LN_REQ
value|0x001c
end_define

begin_comment
comment|/* LN Requester */
end_comment

begin_define
define|#
directive|define
name|PCIZ_DPC
value|0x001d
end_define

begin_comment
comment|/* Downstream Porto Containment */
end_comment

begin_define
define|#
directive|define
name|PCIZ_L1PM
value|0x001e
end_define

begin_comment
comment|/* L1 PM Substates */
end_comment

begin_comment
comment|/* config registers for header type 0 devices */
end_comment

begin_define
define|#
directive|define
name|PCIR_BARS
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIR_BAR
parameter_list|(
name|x
parameter_list|)
value|(PCIR_BARS + (x) * 4)
end_define

begin_define
define|#
directive|define
name|PCIR_MAX_BAR_0
value|5
end_define

begin_define
define|#
directive|define
name|PCI_RID2BAR
parameter_list|(
name|rid
parameter_list|)
value|(((rid) - PCIR_BARS) / 4)
end_define

begin_define
define|#
directive|define
name|PCI_BAR_IO
parameter_list|(
name|x
parameter_list|)
value|(((x)& PCIM_BAR_SPACE) == PCIM_BAR_IO_SPACE)
end_define

begin_define
define|#
directive|define
name|PCI_BAR_MEM
parameter_list|(
name|x
parameter_list|)
value|(((x)& PCIM_BAR_SPACE) == PCIM_BAR_MEM_SPACE)
end_define

begin_define
define|#
directive|define
name|PCIM_BAR_SPACE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PCIM_BAR_MEM_SPACE
value|0
end_define

begin_define
define|#
directive|define
name|PCIM_BAR_IO_SPACE
value|1
end_define

begin_define
define|#
directive|define
name|PCIM_BAR_MEM_TYPE
value|0x00000006
end_define

begin_define
define|#
directive|define
name|PCIM_BAR_MEM_32
value|0
end_define

begin_define
define|#
directive|define
name|PCIM_BAR_MEM_1MB
value|2
end_define

begin_comment
comment|/* Locate below 1MB in PCI<= 2.1 */
end_comment

begin_define
define|#
directive|define
name|PCIM_BAR_MEM_64
value|4
end_define

begin_define
define|#
directive|define
name|PCIM_BAR_MEM_PREFETCH
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PCIM_BAR_MEM_BASE
value|0xfffffffffffffff0ULL
end_define

begin_define
define|#
directive|define
name|PCIM_BAR_IO_RESERVED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PCIM_BAR_IO_BASE
value|0xfffffffc
end_define

begin_define
define|#
directive|define
name|PCIR_CIS
value|0x28
end_define

begin_define
define|#
directive|define
name|PCIM_CIS_ASI_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|PCIM_CIS_ASI_CONFIG
value|0
end_define

begin_define
define|#
directive|define
name|PCIM_CIS_ASI_BAR0
value|1
end_define

begin_define
define|#
directive|define
name|PCIM_CIS_ASI_BAR1
value|2
end_define

begin_define
define|#
directive|define
name|PCIM_CIS_ASI_BAR2
value|3
end_define

begin_define
define|#
directive|define
name|PCIM_CIS_ASI_BAR3
value|4
end_define

begin_define
define|#
directive|define
name|PCIM_CIS_ASI_BAR4
value|5
end_define

begin_define
define|#
directive|define
name|PCIM_CIS_ASI_BAR5
value|6
end_define

begin_define
define|#
directive|define
name|PCIM_CIS_ASI_ROM
value|7
end_define

begin_define
define|#
directive|define
name|PCIM_CIS_ADDR_MASK
value|0x0ffffff8
end_define

begin_define
define|#
directive|define
name|PCIM_CIS_ROM_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|PCIM_CIS_CONFIG_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|PCIR_SUBVEND_0
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCIR_SUBDEV_0
value|0x2e
end_define

begin_define
define|#
directive|define
name|PCIR_BIOS
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIM_BIOS_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIM_BIOS_ADDR_MASK
value|0xfffff800
end_define

begin_define
define|#
directive|define
name|PCIR_CAP_PTR
value|0x34
end_define

begin_define
define|#
directive|define
name|PCIR_INTLINE
value|0x3c
end_define

begin_define
define|#
directive|define
name|PCIR_INTPIN
value|0x3d
end_define

begin_define
define|#
directive|define
name|PCIR_MINGNT
value|0x3e
end_define

begin_define
define|#
directive|define
name|PCIR_MAXLAT
value|0x3f
end_define

begin_comment
comment|/* config registers for header type 1 (PCI-to-PCI bridge) devices */
end_comment

begin_define
define|#
directive|define
name|PCIR_MAX_BAR_1
value|1
end_define

begin_define
define|#
directive|define
name|PCIR_SECSTAT_1
value|0x1e
end_define

begin_define
define|#
directive|define
name|PCIR_PRIBUS_1
value|0x18
end_define

begin_define
define|#
directive|define
name|PCIR_SECBUS_1
value|0x19
end_define

begin_define
define|#
directive|define
name|PCIR_SUBBUS_1
value|0x1a
end_define

begin_define
define|#
directive|define
name|PCIR_SECLAT_1
value|0x1b
end_define

begin_define
define|#
directive|define
name|PCIR_IOBASEL_1
value|0x1c
end_define

begin_define
define|#
directive|define
name|PCIR_IOLIMITL_1
value|0x1d
end_define

begin_define
define|#
directive|define
name|PCIR_IOBASEH_1
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIR_IOLIMITH_1
value|0x32
end_define

begin_define
define|#
directive|define
name|PCIM_BRIO_16
value|0x0
end_define

begin_define
define|#
directive|define
name|PCIM_BRIO_32
value|0x1
end_define

begin_define
define|#
directive|define
name|PCIM_BRIO_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|PCIR_MEMBASE_1
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIR_MEMLIMIT_1
value|0x22
end_define

begin_define
define|#
directive|define
name|PCIR_PMBASEL_1
value|0x24
end_define

begin_define
define|#
directive|define
name|PCIR_PMLIMITL_1
value|0x26
end_define

begin_define
define|#
directive|define
name|PCIR_PMBASEH_1
value|0x28
end_define

begin_define
define|#
directive|define
name|PCIR_PMLIMITH_1
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCIM_BRPM_32
value|0x0
end_define

begin_define
define|#
directive|define
name|PCIM_BRPM_64
value|0x1
end_define

begin_define
define|#
directive|define
name|PCIM_BRPM_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|PCIR_BIOS_1
value|0x38
end_define

begin_define
define|#
directive|define
name|PCIR_BRIDGECTL_1
value|0x3e
end_define

begin_comment
comment|/* config registers for header type 2 (CardBus) devices */
end_comment

begin_define
define|#
directive|define
name|PCIR_MAX_BAR_2
value|0
end_define

begin_define
define|#
directive|define
name|PCIR_CAP_PTR_2
value|0x14
end_define

begin_define
define|#
directive|define
name|PCIR_SECSTAT_2
value|0x16
end_define

begin_define
define|#
directive|define
name|PCIR_PRIBUS_2
value|0x18
end_define

begin_define
define|#
directive|define
name|PCIR_SECBUS_2
value|0x19
end_define

begin_define
define|#
directive|define
name|PCIR_SUBBUS_2
value|0x1a
end_define

begin_define
define|#
directive|define
name|PCIR_SECLAT_2
value|0x1b
end_define

begin_define
define|#
directive|define
name|PCIR_MEMBASE0_2
value|0x1c
end_define

begin_define
define|#
directive|define
name|PCIR_MEMLIMIT0_2
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIR_MEMBASE1_2
value|0x24
end_define

begin_define
define|#
directive|define
name|PCIR_MEMLIMIT1_2
value|0x28
end_define

begin_define
define|#
directive|define
name|PCIR_IOBASE0_2
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCIR_IOLIMIT0_2
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIR_IOBASE1_2
value|0x34
end_define

begin_define
define|#
directive|define
name|PCIR_IOLIMIT1_2
value|0x38
end_define

begin_define
define|#
directive|define
name|PCIR_BRIDGECTL_2
value|0x3e
end_define

begin_define
define|#
directive|define
name|PCIR_SUBVEND_2
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIR_SUBDEV_2
value|0x42
end_define

begin_define
define|#
directive|define
name|PCIR_PCCARDIF_2
value|0x44
end_define

begin_comment
comment|/* PCI device class, subclass and programming interface definitions */
end_comment

begin_define
define|#
directive|define
name|PCIC_OLD
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_OLD_NONVGA
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_OLD_VGA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIC_STORAGE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_SCSI
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_IDE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIP_STORAGE_IDE_MODEPRIM
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIP_STORAGE_IDE_PROGINDPRIM
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIP_STORAGE_IDE_MODESEC
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIP_STORAGE_IDE_PROGINDSEC
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIP_STORAGE_IDE_MASTERDEV
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_FLOPPY
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_IPI
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_RAID
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_ATA_ADMA
value|0x05
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_SATA
value|0x06
end_define

begin_define
define|#
directive|define
name|PCIP_STORAGE_SATA_AHCI_1_0
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_SAS
value|0x07
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_NVM
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIP_STORAGE_NVM_NVMHCI_1_0
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIP_STORAGE_NVM_ENTERPRISE_NVMHCI_1_0
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_NETWORK
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_ETHERNET
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_TOKENRING
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_FDDI
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_ATM
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_ISDN
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_WORLDFIP
value|0x05
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_PICMG
value|0x06
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_DISPLAY
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_DISPLAY_VGA
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_DISPLAY_XGA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_DISPLAY_3D
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_DISPLAY_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_MULTIMEDIA
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_MULTIMEDIA_VIDEO
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_MULTIMEDIA_AUDIO
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_MULTIMEDIA_TELE
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_MULTIMEDIA_HDA
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_MULTIMEDIA_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_MEMORY
value|0x05
end_define

begin_define
define|#
directive|define
name|PCIS_MEMORY_RAM
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_MEMORY_FLASH
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_MEMORY_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_BRIDGE
value|0x06
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_HOST
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_ISA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_EISA
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_MCA
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_PCI
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIP_BRIDGE_PCI_SUBTRACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_PCMCIA
value|0x05
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_NUBUS
value|0x06
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_CARDBUS
value|0x07
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_RACEWAY
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_PCI_TRANSPARENT
value|0x09
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_INFINIBAND
value|0x0a
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_SIMPLECOMM
value|0x07
end_define

begin_define
define|#
directive|define
name|PCIS_SIMPLECOMM_UART
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIP_SIMPLECOMM_UART_8250
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIP_SIMPLECOMM_UART_16450A
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIP_SIMPLECOMM_UART_16550A
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIP_SIMPLECOMM_UART_16650A
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIP_SIMPLECOMM_UART_16750A
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIP_SIMPLECOMM_UART_16850A
value|0x05
end_define

begin_define
define|#
directive|define
name|PCIP_SIMPLECOMM_UART_16950A
value|0x06
end_define

begin_define
define|#
directive|define
name|PCIS_SIMPLECOMM_PAR
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_SIMPLECOMM_MULSER
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_SIMPLECOMM_MODEM
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_SIMPLECOMM_GPIB
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_SIMPLECOMM_SMART_CARD
value|0x05
end_define

begin_define
define|#
directive|define
name|PCIS_SIMPLECOMM_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_BASEPERIPH
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_PIC
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIP_BASEPERIPH_PIC_8259A
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIP_BASEPERIPH_PIC_ISA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIP_BASEPERIPH_PIC_EISA
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIP_BASEPERIPH_PIC_IO_APIC
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIP_BASEPERIPH_PIC_IOX_APIC
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_DMA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_TIMER
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_RTC
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_PCIHOT
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_SDHC
value|0x05
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_IOMMU
value|0x06
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_INPUTDEV
value|0x09
end_define

begin_define
define|#
directive|define
name|PCIS_INPUTDEV_KEYBOARD
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_INPUTDEV_DIGITIZER
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_INPUTDEV_MOUSE
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_INPUTDEV_SCANNER
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_INPUTDEV_GAMEPORT
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_INPUTDEV_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_DOCKING
value|0x0a
end_define

begin_define
define|#
directive|define
name|PCIS_DOCKING_GENERIC
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_DOCKING_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_PROCESSOR
value|0x0b
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_386
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_486
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_PENTIUM
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_ALPHA
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_POWERPC
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_MIPS
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_COPROC
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIC_SERIALBUS
value|0x0c
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_FW
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_ACCESS
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_SSA
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_USB
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIP_SERIALBUS_USB_UHCI
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIP_SERIALBUS_USB_OHCI
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIP_SERIALBUS_USB_EHCI
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIP_SERIALBUS_USB_XHCI
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIP_SERIALBUS_USB_DEVICE
value|0xfe
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_FC
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_SMBUS
value|0x05
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_INFINIBAND
value|0x06
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_IPMI
value|0x07
end_define

begin_define
define|#
directive|define
name|PCIP_SERIALBUS_IPMI_SMIC
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIP_SERIALBUS_IPMI_KCS
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIP_SERIALBUS_IPMI_BT
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_SERCOS
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_CANBUS
value|0x09
end_define

begin_define
define|#
directive|define
name|PCIC_WIRELESS
value|0x0d
end_define

begin_define
define|#
directive|define
name|PCIS_WIRELESS_IRDA
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_WIRELESS_IR
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_WIRELESS_RF
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIS_WIRELESS_BLUETOOTH
value|0x11
end_define

begin_define
define|#
directive|define
name|PCIS_WIRELESS_BROADBAND
value|0x12
end_define

begin_define
define|#
directive|define
name|PCIS_WIRELESS_80211A
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIS_WIRELESS_80211B
value|0x21
end_define

begin_define
define|#
directive|define
name|PCIS_WIRELESS_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_INTELLIIO
value|0x0e
end_define

begin_define
define|#
directive|define
name|PCIS_INTELLIIO_I2O
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_SATCOM
value|0x0f
end_define

begin_define
define|#
directive|define
name|PCIS_SATCOM_TV
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_SATCOM_AUDIO
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_SATCOM_VOICE
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_SATCOM_DATA
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIC_CRYPTO
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIS_CRYPTO_NETCOMP
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_CRYPTO_ENTERTAIN
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIS_CRYPTO_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_DASP
value|0x11
end_define

begin_define
define|#
directive|define
name|PCIS_DASP_DPIO
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_DASP_PERFCNTRS
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_DASP_COMM_SYNC
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIS_DASP_MGMT_CARD
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIS_DASP_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_OTHER
value|0xff
end_define

begin_comment
comment|/* Bridge Control Values. */
end_comment

begin_define
define|#
directive|define
name|PCIB_BCR_PERR_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_SERR_ENABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_ISA_ENABLE
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_VGA_ENABLE
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_MASTER_ABORT_MODE
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_SECBUS_RESET
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_SECBUS_BACKTOBACK
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_PRI_DISCARD_TIMEOUT
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_SEC_DISCARD_TIMEOUT
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_DISCARD_TIMER_STATUS
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_DISCARD_TIMER_SERREN
value|0x0800
end_define

begin_comment
comment|/* PCI power manangement */
end_comment

begin_define
define|#
directive|define
name|PCIR_POWER_CAP
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_SPEC
value|0x0007
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_PMEREQCLK
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_DEVSPECINIT
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_AUXPWR_0
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_AUXPWR_55
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_AUXPWR_100
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_AUXPWR_160
value|0x00c0
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_AUXPWR_220
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_AUXPWR_270
value|0x0140
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_AUXPWR_320
value|0x0180
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_AUXPWR_375
value|0x01c0
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_AUXPWRMASK
value|0x01c0
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_D1SUPP
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_D2SUPP
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_D0PME
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_D1PME
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_D2PME
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_D3PME_HOT
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_D3PME_COLD
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCIR_POWER_STATUS
value|0x4
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D1
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_DMASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_NOSOFTRESET
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_PMEENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D0POWER
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D1POWER
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D2POWER
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D3POWER
value|0x0600
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D0HEAT
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D1HEAT
value|0x0a00
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D2HEAT
value|0x0c00
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D3HEAT
value|0x0e00
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_DATASELMASK
value|0x1e00
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_DATAUNKN
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_DATADIV10
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_DATADIV100
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_DATADIV1000
value|0x6000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_DATADIVMASK
value|0x6000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_PME
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCIR_POWER_BSE
value|0x6
end_define

begin_define
define|#
directive|define
name|PCIM_PMCSR_BSE_D3B3
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIM_PMCSR_BSE_D3B2
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIM_PMCSR_BSE_BPCCE
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIR_POWER_DATA
value|0x7
end_define

begin_comment
comment|/* VPD capability registers */
end_comment

begin_define
define|#
directive|define
name|PCIR_VPD_ADDR
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIR_VPD_DATA
value|0x4
end_define

begin_comment
comment|/* PCI Message Signalled Interrupts (MSI) */
end_comment

begin_define
define|#
directive|define
name|PCIR_MSI_CTRL
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_VECTOR
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_64BIT
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_MASK
value|0x0070
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_1
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_2
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_4
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_8
value|0x0030
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_16
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_32
value|0x0050
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_MASK
value|0x000E
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_1
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_2
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_4
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_8
value|0x0006
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_16
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_32
value|0x000A
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MSI_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIR_MSI_ADDR
value|0x4
end_define

begin_define
define|#
directive|define
name|PCIR_MSI_ADDR_HIGH
value|0x8
end_define

begin_define
define|#
directive|define
name|PCIR_MSI_DATA
value|0x8
end_define

begin_define
define|#
directive|define
name|PCIR_MSI_DATA_64BIT
value|0xc
end_define

begin_define
define|#
directive|define
name|PCIR_MSI_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIR_MSI_PENDING
value|0x14
end_define

begin_comment
comment|/* PCI-X definitions */
end_comment

begin_comment
comment|/* For header type 0 devices */
end_comment

begin_define
define|#
directive|define
name|PCIXR_COMMAND
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIXM_COMMAND_DPERR_E
value|0x0001
end_define

begin_comment
comment|/* Data Parity Error Recovery */
end_comment

begin_define
define|#
directive|define
name|PCIXM_COMMAND_ERO
value|0x0002
end_define

begin_comment
comment|/* Enable Relaxed Ordering */
end_comment

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_READ
value|0x000c
end_define

begin_comment
comment|/* Maximum Burst Read Count */
end_comment

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_READ_512
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_READ_1024
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_READ_2048
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_READ_4096
value|0x000c
end_define

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_SPLITS
value|0x0070
end_define

begin_comment
comment|/* Maximum Split Transactions */
end_comment

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_SPLITS_1
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_SPLITS_2
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_SPLITS_3
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_SPLITS_4
value|0x0030
end_define

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_SPLITS_8
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_SPLITS_12
value|0x0050
end_define

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_SPLITS_16
value|0x0060
end_define

begin_define
define|#
directive|define
name|PCIXM_COMMAND_MAX_SPLITS_32
value|0x0070
end_define

begin_define
define|#
directive|define
name|PCIXM_COMMAND_VERSION
value|0x3000
end_define

begin_define
define|#
directive|define
name|PCIXR_STATUS
value|0x4
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_DEVFN
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_BUS
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_64BIT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_133CAP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_SC_DISCARDED
value|0x00040000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_UNEXP_SC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_COMPLEX_DEV
value|0x00100000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_READ
value|0x00600000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_READ_512
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_READ_1024
value|0x00200000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_READ_2048
value|0x00400000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_READ_4096
value|0x00600000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_SPLITS
value|0x03800000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_SPLITS_1
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_SPLITS_2
value|0x00800000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_SPLITS_3
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_SPLITS_4
value|0x01800000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_SPLITS_8
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_SPLITS_12
value|0x02800000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_SPLITS_16
value|0x03000000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_SPLITS_32
value|0x03800000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAX_CUM_READ
value|0x1C000000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_RCVD_SC_ERR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_266CAP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_533CAP
value|0x80000000
end_define

begin_comment
comment|/* For header type 1 devices (PCI-X bridges) */
end_comment

begin_define
define|#
directive|define
name|PCIXR_SEC_STATUS
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIXM_SEC_STATUS_64BIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIXM_SEC_STATUS_133CAP
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIXM_SEC_STATUS_SC_DISC
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCIXM_SEC_STATUS_UNEXP_SC
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIXM_SEC_STATUS_SC_OVERRUN
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIXM_SEC_STATUS_SR_DELAYED
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIXM_SEC_STATUS_BUS_MODE
value|0x03c0
end_define

begin_define
define|#
directive|define
name|PCIXM_SEC_STATUS_VERSION
value|0x3000
end_define

begin_define
define|#
directive|define
name|PCIXM_SEC_STATUS_266CAP
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCIXM_SEC_STATUS_533CAP
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCIXR_BRIDGE_STATUS
value|0x4
end_define

begin_define
define|#
directive|define
name|PCIXM_BRIDGE_STATUS_DEVFN
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|PCIXM_BRIDGE_STATUS_BUS
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|PCIXM_BRIDGE_STATUS_64BIT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PCIXM_BRIDGE_STATUS_133CAP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PCIXM_BRIDGE_STATUS_SC_DISCARDED
value|0x00040000
end_define

begin_define
define|#
directive|define
name|PCIXM_BRIDGE_STATUS_UNEXP_SC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|PCIXM_BRIDGE_STATUS_SC_OVERRUN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|PCIXM_BRIDGE_STATUS_SR_DELAYED
value|0x00200000
end_define

begin_define
define|#
directive|define
name|PCIXM_BRIDGE_STATUS_DEVID_MSGCAP
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PCIXM_BRIDGE_STATUS_266CAP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PCIXM_BRIDGE_STATUS_533CAP
value|0x80000000
end_define

begin_comment
comment|/* HT (HyperTransport) Capability definitions */
end_comment

begin_define
define|#
directive|define
name|PCIR_HT_COMMAND
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIM_HTCMD_CAP_MASK
value|0xf800
end_define

begin_comment
comment|/* Capability type. */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_SLAVE
value|0x0000
end_define

begin_comment
comment|/* 000xx */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_HOST
value|0x2000
end_define

begin_comment
comment|/* 001xx */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_SWITCH
value|0x4000
end_define

begin_comment
comment|/* 01000 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_INTERRUPT
value|0x8000
end_define

begin_comment
comment|/* 10000 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_REVISION_ID
value|0x8800
end_define

begin_comment
comment|/* 10001 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_UNITID_CLUMPING
value|0x9000
end_define

begin_comment
comment|/* 10010 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_EXT_CONFIG_SPACE
value|0x9800
end_define

begin_comment
comment|/* 10011 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_ADDRESS_MAPPING
value|0xa000
end_define

begin_comment
comment|/* 10100 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_MSI_MAPPING
value|0xa800
end_define

begin_comment
comment|/* 10101 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_DIRECT_ROUTE
value|0xb000
end_define

begin_comment
comment|/* 10110 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_VCSET
value|0xb800
end_define

begin_comment
comment|/* 10111 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_RETRY_MODE
value|0xc000
end_define

begin_comment
comment|/* 11000 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_X86_ENCODING
value|0xc800
end_define

begin_comment
comment|/* 11001 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_GEN3
value|0xd000
end_define

begin_comment
comment|/* 11010 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_FLE
value|0xd800
end_define

begin_comment
comment|/* 11011 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_PM
value|0xe000
end_define

begin_comment
comment|/* 11100 */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCAP_HIGH_NODE_COUNT
value|0xe800
end_define

begin_comment
comment|/* 11101 */
end_comment

begin_comment
comment|/* HT MSI Mapping Capability definitions. */
end_comment

begin_define
define|#
directive|define
name|PCIM_HTCMD_MSI_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIM_HTCMD_MSI_FIXED
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIR_HTMSI_ADDRESS_LO
value|0x4
end_define

begin_define
define|#
directive|define
name|PCIR_HTMSI_ADDRESS_HI
value|0x8
end_define

begin_comment
comment|/* PCI Vendor capability definitions */
end_comment

begin_define
define|#
directive|define
name|PCIR_VENDOR_LENGTH
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIR_VENDOR_DATA
value|0x3
end_define

begin_comment
comment|/* PCI EHCI Debug Port definitions */
end_comment

begin_define
define|#
directive|define
name|PCIR_DEBUG_PORT
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIM_DEBUG_PORT_OFFSET
value|0x1FFF
end_define

begin_define
define|#
directive|define
name|PCIM_DEBUG_PORT_BAR
value|0xe000
end_define

begin_comment
comment|/* PCI-PCI Bridge Subvendor definitions */
end_comment

begin_define
define|#
directive|define
name|PCIR_SUBVENDCAP_ID
value|0x4
end_define

begin_comment
comment|/* PCI Express definitions */
end_comment

begin_define
define|#
directive|define
name|PCIER_FLAGS
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIEM_FLAGS_VERSION
value|0x000F
end_define

begin_define
define|#
directive|define
name|PCIEM_FLAGS_TYPE
value|0x00F0
end_define

begin_define
define|#
directive|define
name|PCIEM_TYPE_ENDPOINT
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIEM_TYPE_LEGACY_ENDPOINT
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIEM_TYPE_ROOT_PORT
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCIEM_TYPE_UPSTREAM_PORT
value|0x0050
end_define

begin_define
define|#
directive|define
name|PCIEM_TYPE_DOWNSTREAM_PORT
value|0x0060
end_define

begin_define
define|#
directive|define
name|PCIEM_TYPE_PCI_BRIDGE
value|0x0070
end_define

begin_define
define|#
directive|define
name|PCIEM_TYPE_PCIE_BRIDGE
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCIEM_TYPE_ROOT_INT_EP
value|0x0090
end_define

begin_define
define|#
directive|define
name|PCIEM_TYPE_ROOT_EC
value|0x00a0
end_define

begin_define
define|#
directive|define
name|PCIEM_FLAGS_SLOT
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIEM_FLAGS_IRQ
value|0x3e00
end_define

begin_define
define|#
directive|define
name|PCIER_DEVICE_CAP
value|0x4
end_define

begin_define
define|#
directive|define
name|PCIEM_CAP_MAX_PAYLOAD
value|0x00000007
end_define

begin_define
define|#
directive|define
name|PCIEM_CAP_PHANTHOM_FUNCS
value|0x00000018
end_define

begin_define
define|#
directive|define
name|PCIEM_CAP_EXT_TAG_FIELD
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PCIEM_CAP_L0S_LATENCY
value|0x000001c0
end_define

begin_define
define|#
directive|define
name|PCIEM_CAP_L1_LATENCY
value|0x00000e00
end_define

begin_define
define|#
directive|define
name|PCIEM_CAP_ROLE_ERR_RPT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PCIEM_CAP_SLOT_PWR_LIM_VAL
value|0x03fc0000
end_define

begin_define
define|#
directive|define
name|PCIEM_CAP_SLOT_PWR_LIM_SCALE
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|PCIEM_CAP_FLR
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PCIER_DEVICE_CTL
value|0x8
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL_COR_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL_NFER_ENABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL_FER_ENABLE
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL_URR_ENABLE
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL_RELAXED_ORD_ENABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL_MAX_PAYLOAD
value|0x00e0
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL_EXT_TAG_FIELD
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL_PHANTHOM_FUNCS
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL_AUX_POWER_PM
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL_NOSNOOP_ENABLE
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL_MAX_READ_REQUEST
value|0x7000
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL_BRDG_CFG_RETRY
value|0x8000
end_define

begin_comment
comment|/* PCI-E - PCI/PCI-X bridges */
end_comment

begin_define
define|#
directive|define
name|PCIEM_CTL_INITIATE_FLR
value|0x8000
end_define

begin_comment
comment|/* FLR capable endpoints */
end_comment

begin_define
define|#
directive|define
name|PCIER_DEVICE_STA
value|0xa
end_define

begin_define
define|#
directive|define
name|PCIEM_STA_CORRECTABLE_ERROR
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIEM_STA_NON_FATAL_ERROR
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIEM_STA_FATAL_ERROR
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCIEM_STA_UNSUPPORTED_REQ
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIEM_STA_AUX_POWER
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIEM_STA_TRANSACTION_PND
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIER_LINK_CAP
value|0xc
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CAP_MAX_SPEED
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CAP_MAX_WIDTH
value|0x000003f0
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CAP_ASPM
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CAP_L0S_EXIT
value|0x00007000
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CAP_L1_EXIT
value|0x00038000
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CAP_CLOCK_PM
value|0x00040000
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CAP_SURPRISE_DOWN
value|0x00080000
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CAP_DL_ACTIVE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CAP_LINK_BW_NOTIFY
value|0x00200000
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CAP_ASPM_COMPLIANCE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CAP_PORT
value|0xff000000
end_define

begin_define
define|#
directive|define
name|PCIER_LINK_CTL
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CTL_ASPMC_DIS
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CTL_ASPMC_L0S
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CTL_ASPMC_L1
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CTL_ASPMC
value|0x0003
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CTL_RCB
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CTL_LINK_DIS
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CTL_RETRAIN_LINK
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CTL_COMMON_CLOCK
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CTL_EXTENDED_SYNC
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CTL_ECPM
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CTL_HAWD
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CTL_LBMIE
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_CTL_LABIE
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCIER_LINK_STA
value|0x12
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_STA_SPEED
value|0x000f
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_STA_WIDTH
value|0x03f0
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_STA_TRAINING_ERROR
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_STA_TRAINING
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_STA_SLOT_CLOCK
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_STA_DL_ACTIVE
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_STA_LINK_BW_MGMT
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCIEM_LINK_STA_LINK_AUTO_BW
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCIER_SLOT_CAP
value|0x14
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CAP_APB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CAP_PCP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CAP_MRLSP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CAP_AIP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CAP_PIP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CAP_HPS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CAP_HPC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CAP_SPLV
value|0x00007f80
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CAP_SPLS
value|0x00018000
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CAP_EIP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CAP_NCCS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CAP_PSN
value|0xfff80000
end_define

begin_define
define|#
directive|define
name|PCIER_SLOT_CTL
value|0x18
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CTL_ABPE
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CTL_PFDE
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CTL_MRLSCE
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CTL_PDCE
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CTL_CCIE
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CTL_HPIE
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CTL_AIC
value|0x00c0
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CTL_PIC
value|0x0300
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CTL_PCC
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CTL_EIC
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_CTL_DLLSCE
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCIER_SLOT_STA
value|0x1a
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_STA_ABP
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_STA_PFD
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_STA_MRLSC
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_STA_PDC
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_STA_CC
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_STA_MRLSS
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_STA_PDS
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_STA_EIS
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCIEM_SLOT_STA_DLLSC
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIER_ROOT_CTL
value|0x1c
end_define

begin_define
define|#
directive|define
name|PCIEM_ROOT_CTL_SERR_CORR
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIEM_ROOT_CTL_SERR_NONFATAL
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIEM_ROOT_CTL_SERR_FATAL
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCIEM_ROOT_CTL_PME
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIEM_ROOT_CTL_CRS_VIS
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIER_ROOT_CAP
value|0x1e
end_define

begin_define
define|#
directive|define
name|PCIEM_ROOT_CAP_CRS_VIS
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIER_ROOT_STA
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIEM_ROOT_STA_PME_REQID_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|PCIEM_ROOT_STA_PME_STATUS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PCIEM_ROOT_STA_PME_PEND
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PCIER_DEVICE_CAP2
value|0x24
end_define

begin_define
define|#
directive|define
name|PCIEM_CAP2_ARI
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIER_DEVICE_CTL2
value|0x28
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL2_COMP_TIMEOUT_VAL
value|0x000f
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL2_COMP_TIMEOUT_DIS
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL2_ARI
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL2_ATOMIC_REQ_ENABLE
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL2_ATOMIC_EGR_BLOCK
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL2_ID_ORDERED_REQ_EN
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL2_ID_ORDERED_CMP_EN
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL2_LTR_ENABLE
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL2_OBFF
value|0x6000
end_define

begin_define
define|#
directive|define
name|PCIEM_OBFF_DISABLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIEM_OBFF_MSGA_ENABLE
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCIEM_OBFF_MSGB_ENABLE
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCIEM_OBFF_WAKE_ENABLE
value|0x6000
end_define

begin_define
define|#
directive|define
name|PCIEM_CTL2_END2END_TLP
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCIER_DEVICE_STA2
value|0x2a
end_define

begin_define
define|#
directive|define
name|PCIER_LINK_CAP2
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCIER_LINK_CTL2
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIER_LINK_STA2
value|0x32
end_define

begin_define
define|#
directive|define
name|PCIER_SLOT_CAP2
value|0x34
end_define

begin_define
define|#
directive|define
name|PCIER_SLOT_CTL2
value|0x38
end_define

begin_define
define|#
directive|define
name|PCIER_SLOT_STA2
value|0x3a
end_define

begin_comment
comment|/* MSI-X definitions */
end_comment

begin_define
define|#
directive|define
name|PCIR_MSIX_CTRL
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIM_MSIXCTRL_MSIX_ENABLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCIM_MSIXCTRL_FUNCTION_MASK
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCIM_MSIXCTRL_TABLE_SIZE
value|0x07FF
end_define

begin_define
define|#
directive|define
name|PCIR_MSIX_TABLE
value|0x4
end_define

begin_define
define|#
directive|define
name|PCIR_MSIX_PBA
value|0x8
end_define

begin_define
define|#
directive|define
name|PCIM_MSIX_BIR_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|PCIM_MSIX_BIR_BAR_10
value|0
end_define

begin_define
define|#
directive|define
name|PCIM_MSIX_BIR_BAR_14
value|1
end_define

begin_define
define|#
directive|define
name|PCIM_MSIX_BIR_BAR_18
value|2
end_define

begin_define
define|#
directive|define
name|PCIM_MSIX_BIR_BAR_1C
value|3
end_define

begin_define
define|#
directive|define
name|PCIM_MSIX_BIR_BAR_20
value|4
end_define

begin_define
define|#
directive|define
name|PCIM_MSIX_BIR_BAR_24
value|5
end_define

begin_define
define|#
directive|define
name|PCIM_MSIX_VCTRL_MASK
value|0x1
end_define

begin_comment
comment|/* PCI Advanced Features definitions */
end_comment

begin_define
define|#
directive|define
name|PCIR_PCIAF_CAP
value|0x3
end_define

begin_define
define|#
directive|define
name|PCIM_PCIAFCAP_TP
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIM_PCIAFCAP_FLR
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIR_PCIAF_CTRL
value|0x4
end_define

begin_define
define|#
directive|define
name|PCIR_PCIAFCTRL_FLR
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIR_PCIAF_STATUS
value|0x5
end_define

begin_define
define|#
directive|define
name|PCIR_PCIAFSTATUS_TP
value|0x01
end_define

begin_comment
comment|/* Advanced Error Reporting */
end_comment

begin_define
define|#
directive|define
name|PCIR_AER_UC_STATUS
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_TRAINING_ERROR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_DL_PROTOCOL_ERROR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_SURPRISE_LINK_DOWN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_POISONED_TLP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_FC_PROTOCOL_ERROR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_COMPLETION_TIMEOUT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_COMPLETER_ABORT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_UNEXPECTED_COMPLETION
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_RECEIVER_OVERFLOW
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_MALFORMED_TLP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_ECRC_ERROR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_UNSUPPORTED_REQUEST
value|0x00100000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_ACS_VIOLATION
value|0x00200000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_INTERNAL_ERROR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_MC_BLOCKED_TLP
value|0x00800000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_ATOMIC_EGRESS_BLK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_UC_TLP_PREFIX_BLOCKED
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PCIR_AER_UC_MASK
value|0x08
end_define

begin_comment
comment|/* Shares bits with UC_STATUS */
end_comment

begin_define
define|#
directive|define
name|PCIR_AER_UC_SEVERITY
value|0x0c
end_define

begin_comment
comment|/* Shares bits with UC_STATUS */
end_comment

begin_define
define|#
directive|define
name|PCIR_AER_COR_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIM_AER_COR_RECEIVER_ERROR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PCIM_AER_COR_BAD_TLP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PCIM_AER_COR_BAD_DLLP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PCIM_AER_COR_REPLAY_ROLLOVER
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PCIM_AER_COR_REPLAY_TIMEOUT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_COR_ADVISORY_NF_ERROR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_COR_INTERNAL_ERROR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|PCIM_AER_COR_HEADER_LOG_OVFLOW
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PCIR_AER_COR_MASK
value|0x14
end_define

begin_comment
comment|/* Shares bits with COR_STATUS */
end_comment

begin_define
define|#
directive|define
name|PCIR_AER_CAP_CONTROL
value|0x18
end_define

begin_define
define|#
directive|define
name|PCIM_AER_FIRST_ERROR_PTR
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|PCIM_AER_ECRC_GEN_CAPABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PCIM_AER_ECRC_GEN_ENABLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PCIM_AER_ECRC_CHECK_CAPABLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PCIM_AER_ECRC_CHECK_ENABLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PCIM_AER_MULT_HDR_CAPABLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PCIM_AER_MULT_HDR_ENABLE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PCIM_AER_TLP_PREFIX_LOG_PRESENT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PCIR_AER_HEADER_LOG
value|0x1c
end_define

begin_define
define|#
directive|define
name|PCIR_AER_ROOTERR_CMD
value|0x2c
end_define

begin_comment
comment|/* Only for root complex ports */
end_comment

begin_define
define|#
directive|define
name|PCIM_AER_ROOTERR_COR_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PCIM_AER_ROOTERR_NF_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PCIM_AER_ROOTERR_F_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PCIR_AER_ROOTERR_STATUS
value|0x30
end_define

begin_comment
comment|/* Only for root complex ports */
end_comment

begin_define
define|#
directive|define
name|PCIM_AER_ROOTERR_COR_ERR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PCIM_AER_ROOTERR_MULTI_COR_ERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PCIM_AER_ROOTERR_UC_ERR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PCIM_AER_ROOTERR_MULTI_UC_ERR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PCIM_AER_ROOTERR_FIRST_UC_FATAL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PCIM_AER_ROOTERR_NF_ERR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PCIM_AER_ROOTERR_F_ERR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PCIM_AER_ROOTERR_INT_MESSAGE
value|0xf8000000
end_define

begin_define
define|#
directive|define
name|PCIR_AER_COR_SOURCE_ID
value|0x34
end_define

begin_comment
comment|/* Only for root complex ports */
end_comment

begin_define
define|#
directive|define
name|PCIR_AER_ERR_SOURCE_ID
value|0x36
end_define

begin_comment
comment|/* Only for root complex ports */
end_comment

begin_define
define|#
directive|define
name|PCIR_AER_TLP_PREFIX_LOG
value|0x38
end_define

begin_comment
comment|/* Only for TLP prefix functions */
end_comment

begin_comment
comment|/* Virtual Channel definitions */
end_comment

begin_define
define|#
directive|define
name|PCIR_VC_CAP1
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIM_VC_CAP1_EXT_COUNT
value|0x00000007
end_define

begin_define
define|#
directive|define
name|PCIM_VC_CAP1_LOWPRI_EXT_COUNT
value|0x00000070
end_define

begin_define
define|#
directive|define
name|PCIR_VC_CAP2
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIR_VC_CONTROL
value|0x0C
end_define

begin_define
define|#
directive|define
name|PCIR_VC_STATUS
value|0x0E
end_define

begin_define
define|#
directive|define
name|PCIR_VC_RESOURCE_CAP
parameter_list|(
name|n
parameter_list|)
value|(0x10 + (n) * 0x0C)
end_define

begin_define
define|#
directive|define
name|PCIR_VC_RESOURCE_CTL
parameter_list|(
name|n
parameter_list|)
value|(0x14 + (n) * 0x0C)
end_define

begin_define
define|#
directive|define
name|PCIR_VC_RESOURCE_STA
parameter_list|(
name|n
parameter_list|)
value|(0x18 + (n) * 0x0C)
end_define

begin_comment
comment|/* Serial Number definitions */
end_comment

begin_define
define|#
directive|define
name|PCIR_SERIAL_LOW
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIR_SERIAL_HIGH
value|0x08
end_define

end_unit

