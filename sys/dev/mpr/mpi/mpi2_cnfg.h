begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2015 LSI Corp.  * Copyright (c) 2013-2016 Avago Technologies  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Avago Technologies (LSI) MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Copyright (c) 2000-2015 LSI Corporation.  *  Copyright (c) 2013-2016 Avago Technologies  *  All rights reserved.  *  *  *           Name:  mpi2_cnfg.h  *          Title:  MPI Configuration messages and pages  *  Creation Date:  November 10, 2006  *  *    mpi2_cnfg.h Version:  02.00.39  *  *  NOTE: Names (typedefs, defines, etc.) beginning with an MPI25 or Mpi25  *        prefix are for use only on MPI v2.5 products, and must not be used  *        with MPI v2.0 products. Unless otherwise noted, names beginning with  *        MPI2 or Mpi2 are for use with both MPI v2.0 and MPI v2.5 products.  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  04-30-07  02.00.00  Corresponds to Fusion-MPT MPI Specification Rev A.  *  06-04-07  02.00.01  Added defines for SAS IO Unit Page 2 PhyFlags.  *                      Added Manufacturing Page 11.  *                      Added MPI2_SAS_EXPANDER0_FLAGS_CONNECTOR_END_DEVICE  *                      define.  *  06-26-07  02.00.02  Adding generic structure for product-specific  *                      Manufacturing pages: MPI2_CONFIG_PAGE_MANUFACTURING_PS.  *                      Rework of BIOS Page 2 configuration page.  *                      Fixed MPI2_BIOSPAGE2_BOOT_DEVICE to be a union of the  *                      forms.  *                      Added configuration pages IOC Page 8 and Driver  *                      Persistent Mapping Page 0.  *  08-31-07  02.00.03  Modified configuration pages dealing with Integrated  *                      RAID (Manufacturing Page 4, RAID Volume Pages 0 and 1,  *                      RAID Physical Disk Pages 0 and 1, RAID Configuration  *                      Page 0).  *                      Added new value for AccessStatus field of SAS Device  *                      Page 0 (_SATA_NEEDS_INITIALIZATION).  *  10-31-07  02.00.04  Added missing SEPDevHandle field to  *                      MPI2_CONFIG_PAGE_SAS_ENCLOSURE_0.  *  12-18-07  02.00.05  Modified IO Unit Page 0 to use 32-bit version fields for  *                      NVDATA.  *                      Modified IOC Page 7 to use masks and added field for  *                      SASBroadcastPrimitiveMasks.  *                      Added MPI2_CONFIG_PAGE_BIOS_4.  *                      Added MPI2_CONFIG_PAGE_LOG_0.  *  02-29-08  02.00.06  Modified various names to make them 32-character unique.  *                      Added SAS Device IDs.  *                      Updated Integrated RAID configuration pages including  *                      Manufacturing Page 4, IOC Page 6, and RAID Configuration  *                      Page 0.  *  05-21-08  02.00.07  Added define MPI2_MANPAGE4_MIX_SSD_SAS_SATA.  *                      Added define MPI2_MANPAGE4_PHYSDISK_128MB_COERCION.  *                      Fixed define MPI2_IOCPAGE8_FLAGS_ENCLOSURE_SLOT_MAPPING.  *                      Added missing MaxNumRoutedSasAddresses field to  *                      MPI2_CONFIG_PAGE_EXPANDER_0.  *                      Added SAS Port Page 0.  *                      Modified structure layout for  *                      MPI2_CONFIG_PAGE_DRIVER_MAPPING_0.  *  06-27-08  02.00.08  Changed MPI2_CONFIG_PAGE_RD_PDISK_1 to use  *                      MPI2_RAID_PHYS_DISK1_PATH_MAX to size the array.  *  10-02-08  02.00.09  Changed MPI2_RAID_PGAD_CONFIGNUM_MASK from 0x0000FFFF  *                      to 0x000000FF.  *                      Added two new values for the Physical Disk Coercion Size  *                      bits in the Flags field of Manufacturing Page 4.  *                      Added product-specific Manufacturing pages 16 to 31.  *                      Modified Flags bits for controlling write cache on SATA  *                      drives in IO Unit Page 1.  *                      Added new bit to AdditionalControlFlags of SAS IO Unit  *                      Page 1 to control Invalid Topology Correction.  *                      Added additional defines for RAID Volume Page 0  *                      VolumeStatusFlags field.  *                      Modified meaning of RAID Volume Page 0 VolumeSettings  *                      define for auto-configure of hot-swap drives.  *                      Added SupportedPhysDisks field to RAID Volume Page 1 and  *                      added related defines.  *                      Added PhysDiskAttributes field (and related defines) to  *                      RAID Physical Disk Page 0.  *                      Added MPI2_SAS_PHYINFO_PHY_VACANT define.  *                      Added three new DiscoveryStatus bits for SAS IO Unit  *                      Page 0 and SAS Expander Page 0.  *                      Removed multiplexing information from SAS IO Unit pages.  *                      Added BootDeviceWaitTime field to SAS IO Unit Page 4.  *                      Removed Zone Address Resolved bit from PhyInfo and from  *                      Expander Page 0 Flags field.  *                      Added two new AccessStatus values to SAS Device Page 0  *                      for indicating routing problems. Added 3 reserved words  *                      to this page.  *  01-19-09  02.00.10  Fixed defines for GPIOVal field of IO Unit Page 3.  *                      Inserted missing reserved field into structure for IOC  *                      Page 6.  *                      Added more pending task bits to RAID Volume Page 0  *                      VolumeStatusFlags defines.  *                      Added MPI2_PHYSDISK0_STATUS_FLAG_NOT_CERTIFIED define.  *                      Added a new DiscoveryStatus bit for SAS IO Unit Page 0  *                      and SAS Expander Page 0 to flag a downstream initiator  *                      when in simplified routing mode.  *                      Removed SATA Init Failure defines for DiscoveryStatus  *                      fields of SAS IO Unit Page 0 and SAS Expander Page 0.  *                      Added MPI2_SAS_DEVICE0_ASTATUS_DEVICE_BLOCKED define.  *                      Added PortGroups, DmaGroup, and ControlGroup fields to  *                      SAS Device Page 0.  *  05-06-09  02.00.11  Added structures and defines for IO Unit Page 5 and IO  *                      Unit Page 6.  *                      Added expander reduced functionality data to SAS  *                      Expander Page 0.  *                      Added SAS PHY Page 2 and SAS PHY Page 3.  *  07-30-09  02.00.12  Added IO Unit Page 7.  *                      Added new device ids.  *                      Added SAS IO Unit Page 5.  *                      Added partial and slumber power management capable flags  *                      to SAS Device Page 0 Flags field.  *                      Added PhyInfo defines for power condition.  *                      Added Ethernet configuration pages.  *  10-28-09  02.00.13  Added MPI2_IOUNITPAGE1_ENABLE_HOST_BASED_DISCOVERY.  *                      Added SAS PHY Page 4 structure and defines.  *  02-10-10  02.00.14  Modified the comments for the configuration page  *                      structures that contain an array of data. The host  *                      should use the "count" field in the page data (e.g. the  *                      NumPhys field) to determine the number of valid elements  *                      in the array.  *                      Added/modified some MPI2_MFGPAGE_DEVID_SAS defines.  *                      Added PowerManagementCapabilities to IO Unit Page 7.  *                      Added PortWidthModGroup field to  *                      MPI2_SAS_IO_UNIT5_PHY_PM_SETTINGS.  *                      Added MPI2_CONFIG_PAGE_SASIOUNIT_6 and related defines.  *                      Added MPI2_CONFIG_PAGE_SASIOUNIT_7 and related defines.  *                      Added MPI2_CONFIG_PAGE_SASIOUNIT_8 and related defines.  *  05-12-10  02.00.15  Added MPI2_RAIDVOL0_STATUS_FLAG_VOL_NOT_CONSISTENT  *                      define.  *                      Added MPI2_PHYSDISK0_INCOMPATIBLE_MEDIA_TYPE define.  *                      Added MPI2_SAS_NEG_LINK_RATE_UNSUPPORTED_PHY define.  *  08-11-10  02.00.16  Removed IO Unit Page 1 device path (multi-pathing)  *                      defines.  *  11-10-10  02.00.17  Added ReceptacleID field (replacing Reserved1) to  *                      MPI2_MANPAGE7_CONNECTOR_INFO and reworked defines for  *                      the Pinout field.  *                      Added BoardTemperature and BoardTemperatureUnits fields  *                      to MPI2_CONFIG_PAGE_IO_UNIT_7.  *                      Added MPI2_CONFIG_EXTPAGETYPE_EXT_MANUFACTURING define  *                      and MPI2_CONFIG_PAGE_EXT_MAN_PS structure.  *  02-23-11  02.00.18  Added ProxyVF_ID field to MPI2_CONFIG_REQUEST.  *                      Added IO Unit Page 8, IO Unit Page 9,  *                      and IO Unit Page 10.  *                      Added SASNotifyPrimitiveMasks field to  *                      MPI2_CONFIG_PAGE_IOC_7.  *  03-09-11  02.00.19  Fixed IO Unit Page 10 (to match the spec).  *  05-25-11  02.00.20  Cleaned up a few comments.  *  08-24-11  02.00.21  Marked the IO Unit Page 7 PowerManagementCapabilities  *                      for PCIe link as obsolete.  *                      Added SpinupFlags field containing a Disable Spin-up bit  *                      to the MPI2_SAS_IOUNIT4_SPINUP_GROUP fields of SAS IO  *                      Unit Page 4.  *  11-18-11  02.00.22  Added define MPI2_IOCPAGE6_CAP_FLAGS_4K_SECTORS_SUPPORT.  *                      Added UEFIVersion field to BIOS Page 1 and defined new  *                      BiosOptions bits.  *                      Incorporating additions for MPI v2.5.  *  11-27-12  02.00.23  Added MPI2_MANPAGE7_FLAG_EVENTREPLAY_SLOT_ORDER.  *                      Added MPI2_BIOSPAGE1_OPTIONS_MASK_OEM_ID.  *  12-20-12  02.00.24  Marked MPI2_SASIOUNIT1_CONTROL_CLEAR_AFFILIATION as  *                      obsolete for MPI v2.5 and later.  *                      Added some defines for 12G SAS speeds.  *  04-09-13  02.00.25  Added MPI2_IOUNITPAGE1_ATA_SECURITY_FREEZE_LOCK.  *                      Fixed MPI2_IOUNITPAGE5_DMA_CAP_MASK_MAX_REQUESTS to  *                      match the specification.  *  08-19-13  02.00.26  Added reserved words to MPI2_CONFIG_PAGE_IO_UNIT_7 for  *                      future use.  *  12-05-13  02.00.27  Added MPI2_MANPAGE7_FLAG_BASE_ENCLOSURE_LEVEL for  *                      MPI2_CONFIG_PAGE_MAN_7.  *                      Added EnclosureLevel and ConnectorName fields to  *                      MPI2_CONFIG_PAGE_SAS_DEV_0.  *                      Added MPI2_SAS_DEVICE0_FLAGS_ENCL_LEVEL_VALID for  *                      MPI2_CONFIG_PAGE_SAS_DEV_0.  *                      Added EnclosureLevel field to  *                      MPI2_CONFIG_PAGE_SAS_ENCLOSURE_0.  *                      Added MPI2_SAS_ENCLS0_FLAGS_ENCL_LEVEL_VALID for  *                      MPI2_CONFIG_PAGE_SAS_ENCLOSURE_0.  *  01-08-14  02.00.28  Added more defines for the BiosOptions field of  *                      MPI2_CONFIG_PAGE_BIOS_1.  *  06-13-14  02.00.29  Added SSUTimeout field to MPI2_CONFIG_PAGE_BIOS_1, and  *                      more defines for the BiosOptions field.  *  11-18-14  02.00.30  Updated copyright information.  *                      Added MPI2_BIOSPAGE1_OPTIONS_ADVANCED_CONFIG.  *                      Added AdapterOrderAux fields to BIOS Page 3.  *  03-16-15  02.00.31  Updated for MPI v2.6.  *                      Added BoardPowerRequirement, PCISlotPowerAllocation, and  *                      Flags field to IO Unit Page 7.  *                      Added IO Unit Page 11.  *                      Added new SAS Phy Event codes  *                      Added PCIe configuration pages.  *  03-19-15  02.00.32  Fixed PCIe Link Config page structure names to be  *                      unique in first 32 characters.  *  05-25-15  02.00.33  Added more defines for the BiosOptions field of  *                      MPI2_CONFIG_PAGE_BIOS_1.  *  08-25-15  02.00.34  Added PCIe Device Page 2 SGL format capability.  *  12-18-15  02.00.35  Added SATADeviceWaitTime to SAS IO Unit Page 4.  *  01-21-16  02.00.36  Added/modified MPI2_MFGPAGE_DEVID_SAS defines.  *                      Added Link field to PCIe Link Pages  *                      Added EnclosureLevel and ConnectorName to PCIe  *                      Device Page 0.  *                      Added define for PCIE IoUnit page 1 max rate shift.  *                      Added comment for reserved ExtPageTypes.  *                      Added SAS 4 22.5 gbs speed support.  *                      Added PCIe 4 16.0 GT/sec speec support.  *                      Removed AHCI support.  *                      Removed SOP support.  *                      Added NegotiatedLinkRate and NegotiatedPortWidth to  *                      PCIe device page 0.  *  04-10-16  02.00.37  Fixed MPI2_MFGPAGE_DEVID_SAS3616/3708 defines  *  07-01-16  02.00.38  Added Manufacturing page 7 Connector types.  *                      Changed declaration of ConnectorName in PCIe DevicePage0  *                      to match SAS DevicePage 0.  *                      Added SATADeviceWaitTime to IO Unit Page 11.  *                      Added MPI26_MFGPAGE_DEVID_SAS4008  *                      Added x16 PCIe width to IO Unit Page 7  *                      Added LINKFLAGS to control SRIS in PCIe IO Unit page 1  *                      phy data.  *                      Added InitStatus to PCIe IO Unit Page 1 header.  *  09-01-16  02.00.39  Added MPI26_CONFIG_PAGE_ENCLOSURE_0 and related defines.  *                      Added MPI26_ENCLOS_PGAD_FORM_GET_NEXT_HANDLE and  *                      MPI26_ENCLOS_PGAD_FORM_HANDLE page address formats.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_CNFG_H
end_ifndef

begin_define
define|#
directive|define
name|MPI2_CNFG_H
end_define

begin_comment
comment|/***************************************************************************** *   Configuration Page Header and defines *****************************************************************************/
end_comment

begin_comment
comment|/* Config Page Header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_HEADER
block|{
name|U8
name|PageVersion
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PageLength
decl_stmt|;
comment|/* 0x01 */
name|U8
name|PageNumber
decl_stmt|;
comment|/* 0x02 */
name|U8
name|PageType
decl_stmt|;
comment|/* 0x03 */
block|}
name|MPI2_CONFIG_PAGE_HEADER
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_HEADER
operator|,
name|Mpi2ConfigPageHeader_t
operator|,
name|MPI2_POINTER
name|pMpi2ConfigPageHeader_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI2_CONFIG_PAGE_HEADER_UNION
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Struct
decl_stmt|;
name|U8
name|Bytes
index|[
literal|4
index|]
decl_stmt|;
name|U16
name|Word16
index|[
literal|2
index|]
decl_stmt|;
name|U32
name|Word32
decl_stmt|;
block|}
name|MPI2_CONFIG_PAGE_HEADER_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_HEADER_UNION
operator|,
name|Mpi2ConfigPageHeaderUnion
operator|,
name|MPI2_POINTER
name|pMpi2ConfigPageHeaderUnion
typedef|;
end_typedef

begin_comment
comment|/* Extended Config Page Header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_EXTENDED_PAGE_HEADER
block|{
name|U8
name|PageVersion
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U8
name|PageNumber
decl_stmt|;
comment|/* 0x02 */
name|U8
name|PageType
decl_stmt|;
comment|/* 0x03 */
name|U16
name|ExtPageLength
decl_stmt|;
comment|/* 0x04 */
name|U8
name|ExtPageType
decl_stmt|;
comment|/* 0x06 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x07 */
block|}
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_EXTENDED_PAGE_HEADER
operator|,
name|Mpi2ConfigExtendedPageHeader_t
operator|,
name|MPI2_POINTER
name|pMpi2ConfigExtendedPageHeader_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI2_CONFIG_EXT_PAGE_HEADER_UNION
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Struct
decl_stmt|;
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Ext
decl_stmt|;
name|U8
name|Bytes
index|[
literal|8
index|]
decl_stmt|;
name|U16
name|Word16
index|[
literal|4
index|]
decl_stmt|;
name|U32
name|Word32
index|[
literal|2
index|]
decl_stmt|;
block|}
name|MPI2_CONFIG_EXT_PAGE_HEADER_UNION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_EXT_PAGE_HEADER_UNION
operator|,
name|Mpi2ConfigPageExtendedHeaderUnion
operator|,
name|MPI2_POINTER
name|pMpi2ConfigPageExtendedHeaderUnion
typedef|;
end_typedef

begin_comment
comment|/* PageType field values */
end_comment

begin_define
define|#
directive|define
name|MPI2_CONFIG_PAGEATTR_READ_ONLY
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_PAGEATTR_CHANGEABLE
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_PAGEATTR_PERSISTENT
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_PAGEATTR_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_PAGETYPE_IO_UNIT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_PAGETYPE_IOC
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_PAGETYPE_BIOS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_PAGETYPE_RAID_VOLUME
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_PAGETYPE_MANUFACTURING
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_PAGETYPE_RAID_PHYSDISK
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_PAGETYPE_EXTENDED
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_PAGETYPE_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_TYPENUM_MASK
value|(0x0FFF)
end_define

begin_comment
comment|/* ExtPageType field values */
end_comment

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_SAS_IO_UNIT
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_SAS_EXPANDER
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_SAS_DEVICE
value|(0x12)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_SAS_PHY
value|(0x13)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_LOG
value|(0x14)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_ENCLOSURE
value|(0x15)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_RAID_CONFIG
value|(0x16)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_DRIVER_MAPPING
value|(0x17)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_SAS_PORT
value|(0x18)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_ETHERNET
value|(0x19)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_EXT_MANUFACTURING
value|(0x1A)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_PCIE_IO_UNIT
value|(0x1B)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_PCIE_SWITCH
value|(0x1C)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_PCIE_DEVICE
value|(0x1D)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_define
define|#
directive|define
name|MPI2_CONFIG_EXTPAGETYPE_PCIE_LINK
value|(0x1E)
end_define

begin_comment
comment|/* MPI v2.6 and later */
end_comment

begin_comment
comment|/*  Product specific reserved values  0xE0 - 0xEF */
end_comment

begin_comment
comment|/*  Vendor specific reserved values   0xF0 - 0xFF */
end_comment

begin_comment
comment|/***************************************************************************** *   PageAddress defines *****************************************************************************/
end_comment

begin_comment
comment|/* RAID Volume PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_VOLUME_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOLUME_PGAD_FORM_GET_NEXT_HANDLE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOLUME_PGAD_FORM_HANDLE
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOLUME_PGAD_HANDLE_MASK
value|(0x0000FFFF)
end_define

begin_comment
comment|/* RAID Physical Disk PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI2_PHYSDISK_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK_PGAD_FORM_GET_NEXT_PHYSDISKNUM
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK_PGAD_FORM_PHYSDISKNUM
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK_PGAD_FORM_DEVHANDLE
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK_PGAD_PHYSDISKNUM_MASK
value|(0x000000FF)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK_PGAD_DEVHANDLE_MASK
value|(0x0000FFFF)
end_define

begin_comment
comment|/* SAS Expander PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_EXPAND_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPAND_PGAD_FORM_GET_NEXT_HNDL
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPAND_PGAD_FORM_HNDL_PHY_NUM
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPAND_PGAD_FORM_HNDL
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPAND_PGAD_HANDLE_MASK
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPAND_PGAD_PHYNUM_MASK
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPAND_PGAD_PHYNUM_SHIFT
value|(16)
end_define

begin_comment
comment|/* SAS Device PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_PGAD_FORM_GET_NEXT_HANDLE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_PGAD_FORM_HANDLE
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE_PGAD_HANDLE_MASK
value|(0x0000FFFF)
end_define

begin_comment
comment|/* SAS PHY PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_PHY_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHY_PGAD_FORM_PHY_NUMBER
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHY_PGAD_FORM_PHY_TBL_INDEX
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHY_PGAD_PHY_NUMBER_MASK
value|(0x000000FF)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHY_PGAD_PHY_TBL_INDEX_MASK
value|(0x0000FFFF)
end_define

begin_comment
comment|/* SAS Port PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASPORT_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPORT_PGAD_FORM_GET_NEXT_PORT
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPORT_PGAD_FORM_PORT_NUM
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPORT_PGAD_PORTNUMBER_MASK
value|(0x00000FFF)
end_define

begin_comment
comment|/* SAS Enclosure PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_ENCLOS_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_ENCLOS_PGAD_FORM_GET_NEXT_HANDLE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_ENCLOS_PGAD_FORM_HANDLE
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_ENCLOS_PGAD_HANDLE_MASK
value|(0x0000FFFF)
end_define

begin_comment
comment|/* Enclosure PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI26_ENCLOS_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI26_ENCLOS_PGAD_FORM_GET_NEXT_HANDLE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI26_ENCLOS_PGAD_FORM_HANDLE
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI26_ENCLOS_PGAD_HANDLE_MASK
value|(0x0000FFFF)
end_define

begin_comment
comment|/* RAID Configuration PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_PGAD_FORM_GET_NEXT_CONFIGNUM
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_PGAD_FORM_CONFIGNUM
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_PGAD_FORM_ACTIVE_CONFIG
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_PGAD_CONFIGNUM_MASK
value|(0x000000FF)
end_define

begin_comment
comment|/* Driver Persistent Mapping PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI2_DPM_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI2_DPM_PGAD_FORM_ENTRY_RANGE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_DPM_PGAD_ENTRY_COUNT_MASK
value|(0x0FFF0000)
end_define

begin_define
define|#
directive|define
name|MPI2_DPM_PGAD_ENTRY_COUNT_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|MPI2_DPM_PGAD_START_ENTRY_MASK
value|(0x0000FFFF)
end_define

begin_comment
comment|/* Ethernet PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI2_ETHERNET_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHERNET_PGAD_FORM_IF_NUM
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHERNET_PGAD_IF_NUMBER_MASK
value|(0x000000FF)
end_define

begin_comment
comment|/* PCIe Switch PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIE_SWITCH_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_SWITCH_PGAD_FORM_GET_NEXT_HNDL
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_SWITCH_PGAD_FORM_HNDL_PORTNUM
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_SWITCH_EXPAND_PGAD_FORM_HNDL
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_SWITCH_PGAD_HANDLE_MASK
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_SWITCH_PGAD_PORTNUM_MASK
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_SWITCH_PGAD_PORTNUM_SHIFT
value|(16)
end_define

begin_comment
comment|/* PCIe Device PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIE_DEVICE_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_DEVICE_PGAD_FORM_GET_NEXT_HANDLE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_DEVICE_PGAD_FORM_HANDLE
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_DEVICE_PGAD_HANDLE_MASK
value|(0x0000FFFF)
end_define

begin_comment
comment|/* PCIe Link PageAddress format */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIE_LINK_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_LINK_PGAD_FORM_GET_NEXT_LINK
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_LINK_PGAD_FORM_LINK_NUM
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_DEVICE_PGAD_LINKNUM_MASK
value|(0x000000FF)
end_define

begin_comment
comment|/**************************************************************************** *   Configuration messages ****************************************************************************/
end_comment

begin_comment
comment|/* Configuration Request Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_REQUEST
block|{
name|U8
name|Action
decl_stmt|;
comment|/* 0x00 */
name|U8
name|SGLFlags
decl_stmt|;
comment|/* 0x01 */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|ExtPageLength
decl_stmt|;
comment|/* 0x04 */
name|U8
name|ExtPageType
decl_stmt|;
comment|/* 0x06 */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 0x07 */
name|U8
name|VP_ID
decl_stmt|;
comment|/* 0x08 */
name|U8
name|VF_ID
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x0A */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
name|U8
name|ProxyVF_ID
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x0E */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x10 */
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x14 */
name|U32
name|PageAddress
decl_stmt|;
comment|/* 0x18 */
name|MPI2_SGE_IO_UNION
name|PageBufferSGE
decl_stmt|;
comment|/* 0x1C */
block|}
name|MPI2_CONFIG_REQUEST
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_REQUEST
operator|,
name|Mpi2ConfigRequest_t
operator|,
name|MPI2_POINTER
name|pMpi2ConfigRequest_t
typedef|;
end_typedef

begin_comment
comment|/* values for the Action field */
end_comment

begin_define
define|#
directive|define
name|MPI2_CONFIG_ACTION_PAGE_HEADER
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_ACTION_PAGE_READ_CURRENT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_ACTION_PAGE_WRITE_CURRENT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_ACTION_PAGE_DEFAULT
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_ACTION_PAGE_WRITE_NVRAM
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_ACTION_PAGE_READ_DEFAULT
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_ACTION_PAGE_READ_NVRAM
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_CONFIG_ACTION_PAGE_GET_CHANGEABLE
value|(0x07)
end_define

begin_comment
comment|/* use MPI2_SGLFLAGS_ defines from mpi2.h for the SGLFlags field */
end_comment

begin_comment
comment|/* Config Reply Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_REPLY
block|{
name|U8
name|Action
decl_stmt|;
comment|/* 0x00 */
name|U8
name|SGLFlags
decl_stmt|;
comment|/* 0x01 */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Function
decl_stmt|;
comment|/* 0x03 */
name|U16
name|ExtPageLength
decl_stmt|;
comment|/* 0x04 */
name|U8
name|ExtPageType
decl_stmt|;
comment|/* 0x06 */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 0x07 */
name|U8
name|VP_ID
decl_stmt|;
comment|/* 0x08 */
name|U8
name|VF_ID
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0x0E */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 0x10 */
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_CONFIG_REPLY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_REPLY
operator|,
name|Mpi2ConfigReply_t
operator|,
name|MPI2_POINTER
name|pMpi2ConfigReply_t
typedef|;
end_typedef

begin_comment
comment|/***************************************************************************** * *               C o n f i g u r a t i o n    P a g e s * *****************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************** *   Manufacturing Config pages ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_VENDORID_LSI
value|(0x1000)
end_define

begin_comment
comment|/* MPI v2.0 SAS products */
end_comment

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2004
value|(0x0070)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2008
value|(0x0072)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2108_1
value|(0x0074)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2108_2
value|(0x0076)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2108_3
value|(0x0077)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2116_1
value|(0x0064)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2116_2
value|(0x0065)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SSS6200
value|(0x007E)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2208_1
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2208_2
value|(0x0081)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2208_3
value|(0x0082)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2208_4
value|(0x0083)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2208_5
value|(0x0084)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2208_6
value|(0x0085)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2308_1
value|(0x0086)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2308_2
value|(0x0087)
end_define

begin_define
define|#
directive|define
name|MPI2_MFGPAGE_DEVID_SAS2308_3
value|(0x006E)
end_define

begin_comment
comment|/* MPI v2.5 SAS products */
end_comment

begin_define
define|#
directive|define
name|MPI25_MFGPAGE_DEVID_SAS3004
value|(0x0096)
end_define

begin_define
define|#
directive|define
name|MPI25_MFGPAGE_DEVID_SAS3008
value|(0x0097)
end_define

begin_define
define|#
directive|define
name|MPI25_MFGPAGE_DEVID_SAS3108_1
value|(0x0090)
end_define

begin_define
define|#
directive|define
name|MPI25_MFGPAGE_DEVID_SAS3108_2
value|(0x0091)
end_define

begin_define
define|#
directive|define
name|MPI25_MFGPAGE_DEVID_SAS3108_5
value|(0x0094)
end_define

begin_define
define|#
directive|define
name|MPI25_MFGPAGE_DEVID_SAS3108_6
value|(0x0095)
end_define

begin_comment
comment|/* MPI v2.6 SAS Products */
end_comment

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3216
value|(0x00C9)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3224
value|(0x00C4)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3316_1
value|(0x00C5)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3316_2
value|(0x00C6)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3316_3
value|(0x00C7)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3316_4
value|(0x00C8)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3324_1
value|(0x00C0)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3324_2
value|(0x00C1)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3324_3
value|(0x00C2)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3324_4
value|(0x00C3)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3516
value|(0x00AA)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3516_1
value|(0x00AB)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3416
value|(0x00AC)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3508
value|(0x00AD)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3508_1
value|(0x00AE)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3408
value|(0x00AF)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3716
value|(0x00D0)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3616
value|(0x00D1)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS3708
value|(0x00D2)
end_define

begin_define
define|#
directive|define
name|MPI26_MFGPAGE_DEVID_SAS4008
value|(0x00A1)
end_define

begin_comment
comment|/* Manufacturing Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_MAN_0
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ChipName
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x04 */
name|U8
name|ChipRevision
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x14 */
name|U8
name|BoardName
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x1C */
name|U8
name|BoardAssembly
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x2C */
name|U8
name|BoardTracerNumber
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x3C */
block|}
name|MPI2_CONFIG_PAGE_MAN_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_MAN_0
operator|,
name|Mpi2ManufacturingPage0_t
operator|,
name|MPI2_POINTER
name|pMpi2ManufacturingPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING0_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* Manufacturing Page 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_MAN_1
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|VPD
index|[
literal|256
index|]
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_CONFIG_PAGE_MAN_1
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_MAN_1
operator|,
name|Mpi2ManufacturingPage1_t
operator|,
name|MPI2_POINTER
name|pMpi2ManufacturingPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING1_PAGEVERSION
value|(0x00)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CHIP_REVISION_ID
block|{
name|U16
name|DeviceID
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PCIRevisionID
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved
decl_stmt|;
comment|/* 0x03 */
block|}
name|MPI2_CHIP_REVISION_ID
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CHIP_REVISION_ID
operator|,
name|Mpi2ChipRevisionId_t
operator|,
name|MPI2_POINTER
name|pMpi2ChipRevisionId_t
typedef|;
end_typedef

begin_comment
comment|/* Manufacturing Page 2 */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check Header.PageLength at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_MAN_PAGE_2_HW_SETTINGS_WORDS
end_ifndef

begin_define
define|#
directive|define
name|MPI2_MAN_PAGE_2_HW_SETTINGS_WORDS
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_MAN_2
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|MPI2_CHIP_REVISION_ID
name|ChipId
decl_stmt|;
comment|/* 0x04 */
name|U32
name|HwSettings
index|[
name|MPI2_MAN_PAGE_2_HW_SETTINGS_WORDS
index|]
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_CONFIG_PAGE_MAN_2
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_MAN_2
operator|,
name|Mpi2ManufacturingPage2_t
operator|,
name|MPI2_POINTER
name|pMpi2ManufacturingPage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING2_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* Manufacturing Page 3 */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check Header.PageLength at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_MAN_PAGE_3_INFO_WORDS
end_ifndef

begin_define
define|#
directive|define
name|MPI2_MAN_PAGE_3_INFO_WORDS
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_MAN_3
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|MPI2_CHIP_REVISION_ID
name|ChipId
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Info
index|[
name|MPI2_MAN_PAGE_3_INFO_WORDS
index|]
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_CONFIG_PAGE_MAN_3
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_MAN_3
operator|,
name|Mpi2ManufacturingPage3_t
operator|,
name|MPI2_POINTER
name|pMpi2ManufacturingPage3_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING3_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* Manufacturing Page 4 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_MANPAGE4_PWR_SAVE_SETTINGS
block|{
name|U8
name|PowerSaveFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|InternalOperationsSleepTime
decl_stmt|;
comment|/* 0x01 */
name|U8
name|InternalOperationsRunTime
decl_stmt|;
comment|/* 0x02 */
name|U8
name|HostIdleTime
decl_stmt|;
comment|/* 0x03 */
block|}
name|MPI2_MANPAGE4_PWR_SAVE_SETTINGS
operator|,
name|MPI2_POINTER
name|PTR_MPI2_MANPAGE4_PWR_SAVE_SETTINGS
operator|,
name|Mpi2ManPage4PwrSaveSettings_t
operator|,
name|MPI2_POINTER
name|pMpi2ManPage4PwrSaveSettings_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the PowerSaveFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_MASK_POWERSAVE_MODE
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_POWERSAVE_MODE_DISABLED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_CUSTOM_POWERSAVE_MODE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_FULL_POWERSAVE_MODE
value|(0x02)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_MAN_4
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Flags
decl_stmt|;
comment|/* 0x08 */
name|U8
name|InquirySize
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0E */
name|U8
name|InquiryData
index|[
literal|56
index|]
decl_stmt|;
comment|/* 0x10 */
name|U32
name|RAID0VolumeSettings
decl_stmt|;
comment|/* 0x48 */
name|U32
name|RAID1EVolumeSettings
decl_stmt|;
comment|/* 0x4C */
name|U32
name|RAID1VolumeSettings
decl_stmt|;
comment|/* 0x50 */
name|U32
name|RAID10VolumeSettings
decl_stmt|;
comment|/* 0x54 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x58 */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x5C */
name|MPI2_MANPAGE4_PWR_SAVE_SETTINGS
name|PowerSaveSettings
decl_stmt|;
comment|/* 0x60 */
name|U8
name|MaxOCEDisks
decl_stmt|;
comment|/* 0x64 */
name|U8
name|ResyncRate
decl_stmt|;
comment|/* 0x65 */
name|U16
name|DataScrubDuration
decl_stmt|;
comment|/* 0x66 */
name|U8
name|MaxHotSpares
decl_stmt|;
comment|/* 0x68 */
name|U8
name|MaxPhysDisksPerVol
decl_stmt|;
comment|/* 0x69 */
name|U8
name|MaxPhysDisks
decl_stmt|;
comment|/* 0x6A */
name|U8
name|MaxVolumes
decl_stmt|;
comment|/* 0x6B */
block|}
name|MPI2_CONFIG_PAGE_MAN_4
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_MAN_4
operator|,
name|Mpi2ManufacturingPage4_t
operator|,
name|MPI2_POINTER
name|pMpi2ManufacturingPage4_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING4_PAGEVERSION
value|(0x0A)
end_define

begin_comment
comment|/* Manufacturing Page 4 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_METADATA_SIZE_MASK
value|(0x00030000)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_METADATA_512MB
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_MIX_SSD_SAS_SATA
value|(0x00008000)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_MIX_SSD_AND_NON_SSD
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_HIDE_PHYSDISK_NON_IR
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_MASK_PHYSDISK_COERCION
value|(0x00001C00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_PHYSDISK_COERCION_1GB
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_PHYSDISK_128MB_COERCION
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_PHYSDISK_ADAPTIVE_COERCION
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_PHYSDISK_ZERO_COERCION
value|(0x00000C00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_MASK_BAD_BLOCK_MARKING
value|(0x00000300)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_DEFAULT_BAD_BLOCK_MARKING
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_TABLE_BAD_BLOCK_MARKING
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_WRITE_LONG_BAD_BLOCK_MARKING
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_FORCE_OFFLINE_FAILOVER
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_RAID10_DISABLE
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_RAID1E_DISABLE
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_RAID1_DISABLE
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_RAID0_DISABLE
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_IR_MODEPAGE8_DISABLE
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_IM_RESYNC_CACHE_ENABLE
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE4_IR_NO_MIX_SAS_SATA
value|(0x00000001)
end_define

begin_comment
comment|/* Manufacturing Page 5 */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumPhys at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_MAN_PAGE_5_PHY_ENTRIES
end_ifndef

begin_define
define|#
directive|define
name|MPI2_MAN_PAGE_5_PHY_ENTRIES
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_MANUFACTURING5_ENTRY
block|{
name|U64
name|WWID
decl_stmt|;
comment|/* 0x00 */
name|U64
name|DeviceName
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_MANUFACTURING5_ENTRY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_MANUFACTURING5_ENTRY
operator|,
name|Mpi2Manufacturing5Entry_t
operator|,
name|MPI2_POINTER
name|pMpi2Manufacturing5Entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_MAN_5
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x05 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x0C */
name|MPI2_MANUFACTURING5_ENTRY
name|Phy
index|[
name|MPI2_MAN_PAGE_5_PHY_ENTRIES
index|]
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_CONFIG_PAGE_MAN_5
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_MAN_5
operator|,
name|Mpi2ManufacturingPage5_t
operator|,
name|MPI2_POINTER
name|pMpi2ManufacturingPage5_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING5_PAGEVERSION
value|(0x03)
end_define

begin_comment
comment|/* Manufacturing Page 6 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_MAN_6
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|ProductSpecificInfo
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_CONFIG_PAGE_MAN_6
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_MAN_6
operator|,
name|Mpi2ManufacturingPage6_t
operator|,
name|MPI2_POINTER
name|pMpi2ManufacturingPage6_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING6_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* Manufacturing Page 7 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_MANPAGE7_CONNECTOR_INFO
block|{
name|U32
name|Pinout
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Connector
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Location
decl_stmt|;
comment|/* 0x14 */
name|U8
name|ReceptacleID
decl_stmt|;
comment|/* 0x15 */
name|U16
name|Slot
decl_stmt|;
comment|/* 0x16 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x18 */
block|}
name|MPI2_MANPAGE7_CONNECTOR_INFO
operator|,
name|MPI2_POINTER
name|PTR_MPI2_MANPAGE7_CONNECTOR_INFO
operator|,
name|Mpi2ManPage7ConnectorInfo_t
operator|,
name|MPI2_POINTER
name|pMpi2ManPage7ConnectorInfo_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the Pinout field */
end_comment

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_LANE_MASK
value|(0x0000FF00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_LANE_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_TYPE_MASK
value|(0x000000FF)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_TYPE_UNKNOWN
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SATA_SINGLE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8482
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8486
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8484
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8087
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8643_4I
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8643_8I
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8470
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8088
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8644_4X
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8644_8X
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8644_16X
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8436
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8088_A
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8643_16i
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8654_4i
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8654_8i
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8611_4i
value|(0x12)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_PINOUT_SFF_8611_8i
value|(0x13)
end_define

begin_comment
comment|/* defines for the Location field */
end_comment

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_LOCATION_UNKNOWN
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_LOCATION_INTERNAL
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_LOCATION_EXTERNAL
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_LOCATION_SWITCHABLE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_LOCATION_AUTO
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_LOCATION_NOT_PRESENT
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_LOCATION_NOT_CONNECTED
value|(0x80)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumPhys at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_MANPAGE7_CONNECTOR_INFO_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_CONNECTOR_INFO_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_MAN_7
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Flags
decl_stmt|;
comment|/* 0x0C */
name|U8
name|EnclosureName
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x10 */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0x20 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x21 */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x22 */
name|MPI2_MANPAGE7_CONNECTOR_INFO
name|ConnectorInfo
index|[
name|MPI2_MANPAGE7_CONNECTOR_INFO_MAX
index|]
decl_stmt|;
comment|/* 0x24 */
block|}
name|MPI2_CONFIG_PAGE_MAN_7
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_MAN_7
operator|,
name|Mpi2ManufacturingPage7_t
operator|,
name|MPI2_POINTER
name|pMpi2ManufacturingPage7_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING7_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/* defines for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_FLAG_BASE_ENCLOSURE_LEVEL
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_FLAG_EVENTREPLAY_SLOT_ORDER
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_MANPAGE7_FLAG_USE_SLOT_INFO
value|(0x00000001)
end_define

begin_comment
comment|/*  * Generic structure to use for product-specific manufacturing pages  * (currently Manufacturing Page 8 through Manufacturing Page 31).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_MAN_PS
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|ProductSpecificInfo
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_CONFIG_PAGE_MAN_PS
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_MAN_PS
operator|,
name|Mpi2ManufacturingPagePS_t
operator|,
name|MPI2_POINTER
name|pMpi2ManufacturingPagePS_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING8_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING9_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING10_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING11_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING12_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING13_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING14_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING15_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING16_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING17_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING18_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING19_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING20_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING21_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING22_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING23_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING24_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING25_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING26_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING27_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING28_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING29_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING30_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_MANUFACTURING31_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/**************************************************************************** *   IO Unit Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* IO Unit Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IO_UNIT_0
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U64
name|UniqueValue
decl_stmt|;
comment|/* 0x04 */
name|MPI2_VERSION_UNION
name|NvdataVersionDefault
decl_stmt|;
comment|/* 0x08 */
name|MPI2_VERSION_UNION
name|NvdataVersionPersistent
decl_stmt|;
comment|/* 0x0A */
block|}
name|MPI2_CONFIG_PAGE_IO_UNIT_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IO_UNIT_0
operator|,
name|Mpi2IOUnitPage0_t
operator|,
name|MPI2_POINTER
name|pMpi2IOUnitPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE0_PAGEVERSION
value|(0x02)
end_define

begin_comment
comment|/* IO Unit Page 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IO_UNIT_1
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Flags
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_CONFIG_PAGE_IO_UNIT_1
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IO_UNIT_1
operator|,
name|Mpi2IOUnitPage1_t
operator|,
name|MPI2_POINTER
name|pMpi2IOUnitPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE1_PAGEVERSION
value|(0x04)
end_define

begin_comment
comment|/* IO Unit Page 1 Flags defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE1_ATA_SECURITY_FREEZE_LOCK
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE1_NEW_DEVICE_FAST_PATH_DISABLE
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE1_DISABLE_FAST_PATH
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE1_ENABLE_HOST_BASED_DISCOVERY
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE1_MASK_SATA_WRITE_CACHE
value|(0x00000600)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE1_SATA_WRITE_CACHE_SHIFT
value|(9)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE1_ENABLE_SATA_WRITE_CACHE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE1_DISABLE_SATA_WRITE_CACHE
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE1_UNCHANGED_SATA_WRITE_CACHE
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE1_NATIVE_COMMAND_Q_DISABLE
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE1_DISABLE_IR
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE1_DISABLE_TASK_SET_FULL_HANDLING
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE1_IR_USE_STATIC_VOLUME_ID
value|(0x00000004)
end_define

begin_comment
comment|/* IO Unit Page 3 */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for GPIOCount at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_IO_UNIT_PAGE_3_GPIO_VAL_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI2_IO_UNIT_PAGE_3_GPIO_VAL_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IO_UNIT_3
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|GPIOCount
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x05 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|U16
name|GPIOVal
index|[
name|MPI2_IO_UNIT_PAGE_3_GPIO_VAL_MAX
index|]
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_CONFIG_PAGE_IO_UNIT_3
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IO_UNIT_3
operator|,
name|Mpi2IOUnitPage3_t
operator|,
name|MPI2_POINTER
name|pMpi2IOUnitPage3_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE3_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/* defines for IO Unit Page 3 GPIOVal field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE3_GPIO_FUNCTION_MASK
value|(0xFFFC)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE3_GPIO_FUNCTION_SHIFT
value|(2)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE3_GPIO_SETTING_OFF
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE3_GPIO_SETTING_ON
value|(0x0001)
end_define

begin_comment
comment|/* IO Unit Page 5 */
end_comment

begin_comment
comment|/*  * Upper layer code (drivers, utilities, etc.) should leave this define set to  * one and check the value returned for NumDmaEngines at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_IOUNITPAGE5_DMAENGINE_ENTRIES
end_ifndef

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE5_DMAENGINE_ENTRIES
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IO_UNIT_5
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U64
name|RaidAcceleratorBufferBaseAddress
decl_stmt|;
comment|/* 0x04 */
name|U64
name|RaidAcceleratorBufferSize
decl_stmt|;
comment|/* 0x0C */
name|U64
name|RaidAcceleratorControlBaseAddress
decl_stmt|;
comment|/* 0x14 */
name|U8
name|RAControlSize
decl_stmt|;
comment|/* 0x1C */
name|U8
name|NumDmaEngines
decl_stmt|;
comment|/* 0x1D */
name|U8
name|RAMinControlSize
decl_stmt|;
comment|/* 0x1E */
name|U8
name|RAMaxControlSize
decl_stmt|;
comment|/* 0x1F */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x20 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x24 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x28 */
name|U32
name|DmaEngineCapabilities
index|[
name|MPI2_IOUNITPAGE5_DMAENGINE_ENTRIES
index|]
decl_stmt|;
comment|/* 0x2C */
block|}
name|MPI2_CONFIG_PAGE_IO_UNIT_5
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IO_UNIT_5
operator|,
name|Mpi2IOUnitPage5_t
operator|,
name|MPI2_POINTER
name|pMpi2IOUnitPage5_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE5_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* defines for IO Unit Page 5 DmaEngineCapabilities field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE5_DMA_CAP_MASK_MAX_REQUESTS
value|(0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE5_DMA_CAP_SHIFT_MAX_REQUESTS
value|(16)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE5_DMA_CAP_EEDP
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE5_DMA_CAP_PARITY_GENERATION
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE5_DMA_CAP_HASHING
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE5_DMA_CAP_ENCRYPTION
value|(0x0001)
end_define

begin_comment
comment|/* IO Unit Page 6 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IO_UNIT_6
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U16
name|Flags
decl_stmt|;
comment|/* 0x04 */
name|U8
name|RAHostControlSize
decl_stmt|;
comment|/* 0x06 */
name|U8
name|Reserved0
decl_stmt|;
comment|/* 0x07 */
name|U64
name|RaidAcceleratorHostControlBaseAddress
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x14 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x18 */
block|}
name|MPI2_CONFIG_PAGE_IO_UNIT_6
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IO_UNIT_6
operator|,
name|Mpi2IOUnitPage6_t
operator|,
name|MPI2_POINTER
name|pMpi2IOUnitPage6_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE6_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* defines for IO Unit Page 6 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE6_FLAGS_ENABLE_RAID_ACCELERATOR
value|(0x0001)
end_define

begin_comment
comment|/* IO Unit Page 7 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IO_UNIT_7
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|CurrentPowerMode
decl_stmt|;
comment|/* 0x04 */
comment|/* reserved in MPI 2.0 */
name|U8
name|PreviousPowerMode
decl_stmt|;
comment|/* 0x05 */
comment|/* reserved in MPI 2.0 */
name|U8
name|PCIeWidth
decl_stmt|;
comment|/* 0x06 */
name|U8
name|PCIeSpeed
decl_stmt|;
comment|/* 0x07 */
name|U32
name|ProcessorState
decl_stmt|;
comment|/* 0x08 */
name|U32
name|PowerManagementCapabilities
decl_stmt|;
comment|/* 0x0C */
name|U16
name|IOCTemperature
decl_stmt|;
comment|/* 0x10 */
name|U8
name|IOCTemperatureUnits
decl_stmt|;
comment|/* 0x12 */
name|U8
name|IOCSpeed
decl_stmt|;
comment|/* 0x13 */
name|U16
name|BoardTemperature
decl_stmt|;
comment|/* 0x14 */
name|U8
name|BoardTemperatureUnits
decl_stmt|;
comment|/* 0x16 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x17 */
name|U32
name|BoardPowerRequirement
decl_stmt|;
comment|/* 0x18 */
comment|/* reserved prior to MPI v2.6 */
name|U32
name|PCISlotPowerAllocation
decl_stmt|;
comment|/* 0x1C */
comment|/* reserved prior to MPI v2.6 */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x20 */
comment|/* reserved prior to MPI v2.6 */
name|U8
name|Reserved6
decl_stmt|;
comment|/* 0x21 */
name|U16
name|Reserved7
decl_stmt|;
comment|/* 0x22 */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 0x24 */
block|}
name|MPI2_CONFIG_PAGE_IO_UNIT_7
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IO_UNIT_7
operator|,
name|Mpi2IOUnitPage7_t
operator|,
name|MPI2_POINTER
name|pMpi2IOUnitPage7_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PAGEVERSION
value|(0x05)
end_define

begin_comment
comment|/* defines for IO Unit Page 7 CurrentPowerMode and PreviousPowerMode fields */
end_comment

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PM_INIT_MASK
value|(0xC0)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PM_INIT_UNAVAILABLE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PM_INIT_HOST
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PM_INIT_IO_UNIT
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PM_INIT_PCIE_DPA
value|(0xC0)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PM_MODE_MASK
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PM_MODE_UNAVAILABLE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PM_MODE_UNKNOWN
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PM_MODE_FULL_POWER
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PM_MODE_REDUCED_POWER
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PM_MODE_STANDBY
value|(0x06)
end_define

begin_comment
comment|/* defines for IO Unit Page 7 PCIeWidth field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PCIE_WIDTH_X1
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PCIE_WIDTH_X2
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PCIE_WIDTH_X4
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PCIE_WIDTH_X8
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PCIE_WIDTH_X16
value|(0x10)
end_define

begin_comment
comment|/* defines for IO Unit Page 7 PCIeSpeed field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PCIE_SPEED_2_5_GBPS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PCIE_SPEED_5_0_GBPS
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PCIE_SPEED_8_0_GBPS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PCIE_SPEED_16_0_GBPS
value|(0x03)
end_define

begin_comment
comment|/* defines for IO Unit Page 7 ProcessorState field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PSTATE_MASK_SECOND
value|(0x0000000F)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PSTATE_SHIFT_SECOND
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PSTATE_NOT_PRESENT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PSTATE_DISABLED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PSTATE_ENABLED
value|(0x02)
end_define

begin_comment
comment|/* defines for IO Unit Page 7 PowerManagementCapabilities field */
end_comment

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_DPA_FULL_PWR_MODE
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_DPA_REDUCED_PWR_MODE
value|(0x00200000)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_DPA_STANDBY_MODE
value|(0x00100000)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_HOST_FULL_PWR_MODE
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_HOST_REDUCED_PWR_MODE
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_HOST_STANDBY_MODE
value|(0x00010000)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_IO_FULL_PWR_MODE
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_IO_REDUCED_PWR_MODE
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_IO_STANDBY_MODE
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PMCAP_HOST_12_5_PCT_IOCSPEED
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PMCAP_HOST_25_0_PCT_IOCSPEED
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PMCAP_HOST_50_0_PCT_IOCSPEED
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_IO_12_5_PCT_IOCSPEED
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_IO_25_0_PCT_IOCSPEED
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_IO_50_0_PCT_IOCSPEED
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PMCAP_HOST_WIDTH_CHANGE_PCIE
value|(0x00000008)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PMCAP_HOST_SPEED_CHANGE_PCIE
value|(0x00000004)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_IO_WIDTH_CHANGE_PCIE
value|(0x00000002)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI25_IOUNITPAGE7_PMCAP_IO_SPEED_CHANGE_PCIE
value|(0x00000001)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_comment
comment|/* obsolete names for the PowerManagementCapabilities bits (above) */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PMCAP_12_5_PCT_IOCSPEED
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PMCAP_25_0_PCT_IOCSPEED
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PMCAP_50_0_PCT_IOCSPEED
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PMCAP_PCIE_WIDTH_CHANGE
value|(0x00000008)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_PMCAP_PCIE_SPEED_CHANGE
value|(0x00000004)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_comment
comment|/* defines for IO Unit Page 7 IOCTemperatureUnits field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_IOC_TEMP_NOT_PRESENT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_IOC_TEMP_FAHRENHEIT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_IOC_TEMP_CELSIUS
value|(0x02)
end_define

begin_comment
comment|/* defines for IO Unit Page 7 IOCSpeed field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_IOC_SPEED_FULL
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_IOC_SPEED_HALF
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_IOC_SPEED_QUARTER
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_IOC_SPEED_EIGHTH
value|(0x08)
end_define

begin_comment
comment|/* defines for IO Unit Page 7 BoardTemperatureUnits field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_BOARD_TEMP_NOT_PRESENT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_BOARD_TEMP_FAHRENHEIT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_BOARD_TEMP_CELSIUS
value|(0x02)
end_define

begin_comment
comment|/* defines for IO Unit Page 7 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE7_FLAG_CABLE_POWER_EXC
value|(0x01)
end_define

begin_comment
comment|/* IO Unit Page 8 */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNIT8_NUM_THRESHOLDS
value|(4)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IOUNIT8_SENSOR
block|{
name|U16
name|Flags
decl_stmt|;
comment|/* 0x00 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x02 */
name|U16
name|Threshold
index|[
name|MPI2_IOUNIT8_NUM_THRESHOLDS
index|]
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_IOUNIT8_SENSOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IOUNIT8_SENSOR
operator|,
name|Mpi2IOUnit8Sensor_t
operator|,
name|MPI2_POINTER
name|pMpi2IOUnit8Sensor_t
typedef|;
end_typedef

begin_comment
comment|/* defines for IO Unit Page 8 Sensor Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNIT8_SENSOR_FLAGS_T3_ENABLE
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNIT8_SENSOR_FLAGS_T2_ENABLE
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNIT8_SENSOR_FLAGS_T1_ENABLE
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_IOUNIT8_SENSOR_FLAGS_T0_ENABLE
value|(0x0001)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumSensors at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_IOUNITPAGE8_SENSOR_ENTRIES
end_ifndef

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE8_SENSOR_ENTRIES
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IO_UNIT_8
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x08 */
name|U8
name|NumSensors
decl_stmt|;
comment|/* 0x0C */
name|U8
name|PollingInterval
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0E */
name|MPI2_IOUNIT8_SENSOR
name|Sensor
index|[
name|MPI2_IOUNITPAGE8_SENSOR_ENTRIES
index|]
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_CONFIG_PAGE_IO_UNIT_8
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IO_UNIT_8
operator|,
name|Mpi2IOUnitPage8_t
operator|,
name|MPI2_POINTER
name|pMpi2IOUnitPage8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE8_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* IO Unit Page 9 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IOUNIT9_SENSOR
block|{
name|U16
name|CurrentTemperature
decl_stmt|;
comment|/* 0x00 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x05 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x06 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI2_IOUNIT9_SENSOR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IOUNIT9_SENSOR
operator|,
name|Mpi2IOUnit9Sensor_t
operator|,
name|MPI2_POINTER
name|pMpi2IOUnit9Sensor_t
typedef|;
end_typedef

begin_comment
comment|/* defines for IO Unit Page 9 Sensor Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOUNIT9_SENSOR_FLAGS_TEMP_VALID
value|(0x01)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumSensors at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_IOUNITPAGE9_SENSOR_ENTRIES
end_ifndef

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE9_SENSOR_ENTRIES
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IO_UNIT_9
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x08 */
name|U8
name|NumSensors
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0E */
name|MPI2_IOUNIT9_SENSOR
name|Sensor
index|[
name|MPI2_IOUNITPAGE9_SENSOR_ENTRIES
index|]
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_CONFIG_PAGE_IO_UNIT_9
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IO_UNIT_9
operator|,
name|Mpi2IOUnitPage9_t
operator|,
name|MPI2_POINTER
name|pMpi2IOUnitPage9_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE9_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* IO Unit Page 10 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_IOUNIT10_FUNCTION
block|{
name|U8
name|CreditPercent
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI2_IOUNIT10_FUNCTION
operator|,
name|MPI2_POINTER
name|PTR_MPI2_IOUNIT10_FUNCTION
operator|,
name|Mpi2IOUnit10Function_t
operator|,
name|MPI2_POINTER
name|pMpi2IOUnit10Function_t
typedef|;
end_typedef

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumFunctions at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_IOUNITPAGE10_FUNCTION_ENTRIES
end_ifndef

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE10_FUNCTION_ENTRIES
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IO_UNIT_10
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|NumFunctions
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x05 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x0C */
name|MPI2_IOUNIT10_FUNCTION
name|Function
index|[
name|MPI2_IOUNITPAGE10_FUNCTION_ENTRIES
index|]
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_CONFIG_PAGE_IO_UNIT_10
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IO_UNIT_10
operator|,
name|Mpi2IOUnitPage10_t
operator|,
name|MPI2_POINTER
name|pMpi2IOUnitPage10_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOUNITPAGE10_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/* IO Unit Page 11 (for MPI v2.6 and later) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_IOUNIT11_SPINUP_GROUP
block|{
name|U8
name|MaxTargetSpinup
decl_stmt|;
comment|/* 0x00 */
name|U8
name|SpinupDelay
decl_stmt|;
comment|/* 0x01 */
name|U8
name|SpinupFlags
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x03 */
block|}
name|MPI26_IOUNIT11_SPINUP_GROUP
operator|,
name|MPI2_POINTER
name|PTR_MPI26_IOUNIT11_SPINUP_GROUP
operator|,
name|Mpi26IOUnit11SpinupGroup_t
operator|,
name|MPI2_POINTER
name|pMpi26IOUnit11SpinupGroup_t
typedef|;
end_typedef

begin_comment
comment|/* defines for IO Unit Page 11 SpinupFlags */
end_comment

begin_define
define|#
directive|define
name|MPI26_IOUNITPAGE11_SPINUP_DISABLE_FLAG
value|(0x01)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * four and check the value returned for NumPhys at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI26_IOUNITPAGE11_PHY_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI26_IOUNITPAGE11_PHY_MAX
value|(4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_CONFIG_PAGE_IO_UNIT_11
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|MPI26_IOUNIT11_SPINUP_GROUP
name|SpinupGroupParameters
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x18 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x1C */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x20 */
name|U8
name|BootDeviceWaitTime
decl_stmt|;
comment|/* 0x24 */
name|U8
name|SATADeviceWaitTime
decl_stmt|;
comment|/* 0x25 */
name|U16
name|Reserved6
decl_stmt|;
comment|/* 0x26 */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0x28 */
name|U8
name|PEInitialSpinupDelay
decl_stmt|;
comment|/* 0x29 */
name|U8
name|PEReplyDelay
decl_stmt|;
comment|/* 0x2A */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x2B */
name|U8
name|PHY
index|[
name|MPI26_IOUNITPAGE11_PHY_MAX
index|]
decl_stmt|;
comment|/* 0x2C */
block|}
name|MPI26_CONFIG_PAGE_IO_UNIT_11
operator|,
name|MPI2_POINTER
name|PTR_MPI26_CONFIG_PAGE_IO_UNIT_11
operator|,
name|Mpi26IOUnitPage11_t
operator|,
name|MPI2_POINTER
name|pMpi26IOUnitPage11_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI26_IOUNITPAGE11_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* defines for Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI26_IOUNITPAGE11_FLAGS_AUTO_PORTENABLE
value|(0x01)
end_define

begin_comment
comment|/* defines for PHY field */
end_comment

begin_define
define|#
directive|define
name|MPI26_IOUNITPAGE11_PHY_SPINUP_GROUP_MASK
value|(0x03)
end_define

begin_comment
comment|/**************************************************************************** *   IOC Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* IOC Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IOC_0
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x08 */
name|U16
name|VendorID
decl_stmt|;
comment|/* 0x0C */
name|U16
name|DeviceID
decl_stmt|;
comment|/* 0x0E */
name|U8
name|RevisionID
decl_stmt|;
comment|/* 0x10 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x11 */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x12 */
name|U32
name|ClassCode
decl_stmt|;
comment|/* 0x14 */
name|U16
name|SubsystemVendorID
decl_stmt|;
comment|/* 0x18 */
name|U16
name|SubsystemID
decl_stmt|;
comment|/* 0x1A */
block|}
name|MPI2_CONFIG_PAGE_IOC_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IOC_0
operator|,
name|Mpi2IOCPage0_t
operator|,
name|MPI2_POINTER
name|pMpi2IOCPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOCPAGE0_PAGEVERSION
value|(0x02)
end_define

begin_comment
comment|/* IOC Page 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IOC_1
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Flags
decl_stmt|;
comment|/* 0x04 */
name|U32
name|CoalescingTimeout
decl_stmt|;
comment|/* 0x08 */
name|U8
name|CoalescingDepth
decl_stmt|;
comment|/* 0x0C */
name|U8
name|PCISlotNum
decl_stmt|;
comment|/* 0x0D */
name|U8
name|PCIBusNum
decl_stmt|;
comment|/* 0x0E */
name|U8
name|PCIDomainSegment
decl_stmt|;
comment|/* 0x0F */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_CONFIG_PAGE_IOC_1
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IOC_1
operator|,
name|Mpi2IOCPage1_t
operator|,
name|MPI2_POINTER
name|pMpi2IOCPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOCPAGE1_PAGEVERSION
value|(0x05)
end_define

begin_comment
comment|/* defines for IOC Page 1 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCPAGE1_REPLY_COALESCING
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE1_PCISLOTNUM_UNKNOWN
value|(0xFF)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE1_PCIBUSNUM_UNKNOWN
value|(0xFF)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE1_PCIDOMAIN_UNKNOWN
value|(0xFF)
end_define

begin_comment
comment|/* IOC Page 6 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IOC_6
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|CapabilitiesFlags
decl_stmt|;
comment|/* 0x04 */
name|U8
name|MaxDrivesRAID0
decl_stmt|;
comment|/* 0x08 */
name|U8
name|MaxDrivesRAID1
decl_stmt|;
comment|/* 0x09 */
name|U8
name|MaxDrivesRAID1E
decl_stmt|;
comment|/* 0x0A */
name|U8
name|MaxDrivesRAID10
decl_stmt|;
comment|/* 0x0B */
name|U8
name|MinDrivesRAID0
decl_stmt|;
comment|/* 0x0C */
name|U8
name|MinDrivesRAID1
decl_stmt|;
comment|/* 0x0D */
name|U8
name|MinDrivesRAID1E
decl_stmt|;
comment|/* 0x0E */
name|U8
name|MinDrivesRAID10
decl_stmt|;
comment|/* 0x0F */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x10 */
name|U8
name|MaxGlobalHotSpares
decl_stmt|;
comment|/* 0x14 */
name|U8
name|MaxPhysDisks
decl_stmt|;
comment|/* 0x15 */
name|U8
name|MaxVolumes
decl_stmt|;
comment|/* 0x16 */
name|U8
name|MaxConfigs
decl_stmt|;
comment|/* 0x17 */
name|U8
name|MaxOCEDisks
decl_stmt|;
comment|/* 0x18 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x19 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x1A */
name|U32
name|SupportedStripeSizeMapRAID0
decl_stmt|;
comment|/* 0x1C */
name|U32
name|SupportedStripeSizeMapRAID1E
decl_stmt|;
comment|/* 0x20 */
name|U32
name|SupportedStripeSizeMapRAID10
decl_stmt|;
comment|/* 0x24 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x28 */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x2C */
name|U16
name|DefaultMetadataSize
decl_stmt|;
comment|/* 0x30 */
name|U16
name|Reserved6
decl_stmt|;
comment|/* 0x32 */
name|U16
name|MaxBadBlockTableEntries
decl_stmt|;
comment|/* 0x34 */
name|U16
name|Reserved7
decl_stmt|;
comment|/* 0x36 */
name|U32
name|IRNvsramVersion
decl_stmt|;
comment|/* 0x38 */
block|}
name|MPI2_CONFIG_PAGE_IOC_6
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IOC_6
operator|,
name|Mpi2IOCPage6_t
operator|,
name|MPI2_POINTER
name|pMpi2IOCPage6_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOCPAGE6_PAGEVERSION
value|(0x05)
end_define

begin_comment
comment|/* defines for IOC Page 6 CapabilitiesFlags */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCPAGE6_CAP_FLAGS_4K_SECTORS_SUPPORT
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE6_CAP_FLAGS_RAID10_SUPPORT
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE6_CAP_FLAGS_RAID1_SUPPORT
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE6_CAP_FLAGS_RAID1E_SUPPORT
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE6_CAP_FLAGS_RAID0_SUPPORT
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE6_CAP_FLAGS_GLOBAL_HOT_SPARE
value|(0x00000001)
end_define

begin_comment
comment|/* IOC Page 7 */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCPAGE7_EVENTMASK_WORDS
value|(4)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IOC_7
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U32
name|EventMasks
index|[
name|MPI2_IOCPAGE7_EVENTMASK_WORDS
index|]
decl_stmt|;
comment|/* 0x08 */
name|U16
name|SASBroadcastPrimitiveMasks
decl_stmt|;
comment|/* 0x18 */
name|U16
name|SASNotifyPrimitiveMasks
decl_stmt|;
comment|/* 0x1A */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x1C */
block|}
name|MPI2_CONFIG_PAGE_IOC_7
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IOC_7
operator|,
name|Mpi2IOCPage7_t
operator|,
name|MPI2_POINTER
name|pMpi2IOCPage7_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOCPAGE7_PAGEVERSION
value|(0x02)
end_define

begin_comment
comment|/* IOC Page 8 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_IOC_8
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|NumDevsPerEnclosure
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x05 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|U16
name|MaxPersistentEntries
decl_stmt|;
comment|/* 0x08 */
name|U16
name|MaxNumPhysicalMappedIDs
decl_stmt|;
comment|/* 0x0A */
name|U16
name|Flags
decl_stmt|;
comment|/* 0x0C */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0E */
name|U16
name|IRVolumeMappingFlags
decl_stmt|;
comment|/* 0x10 */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x12 */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_CONFIG_PAGE_IOC_8
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_IOC_8
operator|,
name|Mpi2IOCPage8_t
operator|,
name|MPI2_POINTER
name|pMpi2IOCPage8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_IOCPAGE8_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* defines for IOC Page 8 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCPAGE8_FLAGS_DA_START_SLOT_1
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE8_FLAGS_RESERVED_TARGETID_0
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE8_FLAGS_MASK_MAPPING_MODE
value|(0x0000000E)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE8_FLAGS_DEVICE_PERSISTENCE_MAPPING
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE8_FLAGS_ENCLOSURE_SLOT_MAPPING
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE8_FLAGS_DISABLE_PERSISTENT_MAPPING
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE8_FLAGS_ENABLE_PERSISTENT_MAPPING
value|(0x00000000)
end_define

begin_comment
comment|/* defines for IOC Page 8 IRVolumeMappingFlags */
end_comment

begin_define
define|#
directive|define
name|MPI2_IOCPAGE8_IRFLAGS_MASK_VOLUME_MAPPING_MODE
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE8_IRFLAGS_LOW_VOLUME_MAPPING
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_IOCPAGE8_IRFLAGS_HIGH_VOLUME_MAPPING
value|(0x00000001)
end_define

begin_comment
comment|/**************************************************************************** *   BIOS Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* BIOS Page 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_BIOS_1
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|BiosOptions
decl_stmt|;
comment|/* 0x04 */
name|U32
name|IOCSettings
decl_stmt|;
comment|/* 0x08 */
name|U8
name|SSUTimeout
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0E */
name|U32
name|DeviceSettings
decl_stmt|;
comment|/* 0x10 */
name|U16
name|NumberOfDevices
decl_stmt|;
comment|/* 0x14 */
name|U16
name|UEFIVersion
decl_stmt|;
comment|/* 0x16 */
name|U16
name|IOTimeoutBlockDevicesNonRM
decl_stmt|;
comment|/* 0x18 */
name|U16
name|IOTimeoutSequential
decl_stmt|;
comment|/* 0x1A */
name|U16
name|IOTimeoutOther
decl_stmt|;
comment|/* 0x1C */
name|U16
name|IOTimeoutBlockDevicesRM
decl_stmt|;
comment|/* 0x1E */
block|}
name|MPI2_CONFIG_PAGE_BIOS_1
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_BIOS_1
operator|,
name|Mpi2BiosPage1_t
operator|,
name|MPI2_POINTER
name|pMpi2BiosPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_PAGEVERSION
value|(0x07)
end_define

begin_comment
comment|/* values for BIOS Page 1 BiosOptions field */
end_comment

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_BOOT_LIST_ADD_ALT_BOOT_DEVICE
value|(0x00008000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_ADVANCED_CONFIG
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_PNS_MASK
value|(0x00003800)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_PNS_PBDHL
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_PNS_ENCSLOSURE
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_PNS_LWWID
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_PNS_PSENS
value|(0x00001800)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_PNS_ESPHY
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_X86_DISABLE_BIOS
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_MASK_REGISTRATION_UEFI_BSD
value|(0x00000300)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_USE_BIT0_REGISTRATION_UEFI_BSD
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_FULL_REGISTRATION_UEFI_BSD
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_ADAPTER_REGISTRATION_UEFI_BSD
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_DISABLE_REGISTRATION_UEFI_BSD
value|(0x00000300)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_MASK_OEM_ID
value|(0x000000F0)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_LSI_OEM_ID
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_MASK_UEFI_HII_REGISTRATION
value|(0x00000006)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_ENABLE_UEFI_HII
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_DISABLE_UEFI_HII
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_VERSION_CHECK_UEFI_HII
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_OPTIONS_DISABLE_BIOS
value|(0x00000001)
end_define

begin_comment
comment|/* values for BIOS Page 1 IOCSettings field */
end_comment

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_IOCSET_MASK_BOOT_PREFERENCE
value|(0x00030000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_IOCSET_ENCLOSURE_SLOT_BOOT
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_IOCSET_SAS_ADDRESS_BOOT
value|(0x00010000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_IOCSET_MASK_RM_SETTING
value|(0x000000C0)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_IOCSET_NONE_RM_SETTING
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_IOCSET_BOOT_RM_SETTING
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_IOCSET_MEDIA_RM_SETTING
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_IOCSET_MASK_ADAPTER_SUPPORT
value|(0x00000030)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_IOCSET_NO_SUPPORT
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_IOCSET_BIOS_SUPPORT
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_IOCSET_OS_SUPPORT
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_IOCSET_ALL_SUPPORT
value|(0x00000030)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_IOCSET_ALTERNATE_CHS
value|(0x00000008)
end_define

begin_comment
comment|/* values for BIOS Page 1 DeviceSettings field */
end_comment

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_DEVSET_DISABLE_SMART_POLLING
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_DEVSET_DISABLE_SEQ_LUN
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_DEVSET_DISABLE_RM_LUN
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_DEVSET_DISABLE_NON_RM_LUN
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_DEVSET_DISABLE_OTHER_LUN
value|(0x00000001)
end_define

begin_comment
comment|/* defines for BIOS Page 1 UEFIVersion field */
end_comment

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_UEFI_VER_MAJOR_MASK
value|(0xFF00)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_UEFI_VER_MAJOR_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_UEFI_VER_MINOR_MASK
value|(0x00FF)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE1_UEFI_VER_MINOR_SHIFT
value|(0)
end_define

begin_comment
comment|/* BIOS Page 2 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_BOOT_DEVICE_ADAPTER_ORDER
block|{
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_BOOT_DEVICE_ADAPTER_ORDER
operator|,
name|MPI2_POINTER
name|PTR_MPI2_BOOT_DEVICE_ADAPTER_ORDER
operator|,
name|Mpi2BootDeviceAdapterOrder_t
operator|,
name|MPI2_POINTER
name|pMpi2BootDeviceAdapterOrder_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_BOOT_DEVICE_SAS_WWID
block|{
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0x00 */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_BOOT_DEVICE_SAS_WWID
operator|,
name|MPI2_POINTER
name|PTR_MPI2_BOOT_DEVICE_SAS_WWID
operator|,
name|Mpi2BootDeviceSasWwid_t
operator|,
name|MPI2_POINTER
name|pMpi2BootDeviceSasWwid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_BOOT_DEVICE_ENCLOSURE_SLOT
block|{
name|U64
name|EnclosureLogicalID
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
name|U16
name|SlotNumber
decl_stmt|;
comment|/* 0x10 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x12 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_BOOT_DEVICE_ENCLOSURE_SLOT
operator|,
name|MPI2_POINTER
name|PTR_MPI2_BOOT_DEVICE_ENCLOSURE_SLOT
operator|,
name|Mpi2BootDeviceEnclosureSlot_t
operator|,
name|MPI2_POINTER
name|pMpi2BootDeviceEnclosureSlot_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_BOOT_DEVICE_DEVICE_NAME
block|{
name|U64
name|DeviceName
decl_stmt|;
comment|/* 0x00 */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_BOOT_DEVICE_DEVICE_NAME
operator|,
name|MPI2_POINTER
name|PTR_MPI2_BOOT_DEVICE_DEVICE_NAME
operator|,
name|Mpi2BootDeviceDeviceName_t
operator|,
name|MPI2_POINTER
name|pMpi2BootDeviceDeviceName_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI2_MPI2_BIOSPAGE2_BOOT_DEVICE
block|{
name|MPI2_BOOT_DEVICE_ADAPTER_ORDER
name|AdapterOrder
decl_stmt|;
name|MPI2_BOOT_DEVICE_SAS_WWID
name|SasWwid
decl_stmt|;
name|MPI2_BOOT_DEVICE_ENCLOSURE_SLOT
name|EnclosureSlot
decl_stmt|;
name|MPI2_BOOT_DEVICE_DEVICE_NAME
name|DeviceName
decl_stmt|;
block|}
name|MPI2_BIOSPAGE2_BOOT_DEVICE
operator|,
name|MPI2_POINTER
name|PTR_MPI2_BIOSPAGE2_BOOT_DEVICE
operator|,
name|Mpi2BiosPage2BootDevice_t
operator|,
name|MPI2_POINTER
name|pMpi2BiosPage2BootDevice_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_BIOS_2
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x14 */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x18 */
name|U8
name|ReqBootDeviceForm
decl_stmt|;
comment|/* 0x1C */
name|U8
name|Reserved7
decl_stmt|;
comment|/* 0x1D */
name|U16
name|Reserved8
decl_stmt|;
comment|/* 0x1E */
name|MPI2_BIOSPAGE2_BOOT_DEVICE
name|RequestedBootDevice
decl_stmt|;
comment|/* 0x20 */
name|U8
name|ReqAltBootDeviceForm
decl_stmt|;
comment|/* 0x38 */
name|U8
name|Reserved9
decl_stmt|;
comment|/* 0x39 */
name|U16
name|Reserved10
decl_stmt|;
comment|/* 0x3A */
name|MPI2_BIOSPAGE2_BOOT_DEVICE
name|RequestedAltBootDevice
decl_stmt|;
comment|/* 0x3C */
name|U8
name|CurrentBootDeviceForm
decl_stmt|;
comment|/* 0x58 */
name|U8
name|Reserved11
decl_stmt|;
comment|/* 0x59 */
name|U16
name|Reserved12
decl_stmt|;
comment|/* 0x5A */
name|MPI2_BIOSPAGE2_BOOT_DEVICE
name|CurrentBootDevice
decl_stmt|;
comment|/* 0x58 */
block|}
name|MPI2_CONFIG_PAGE_BIOS_2
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_BIOS_2
operator|,
name|Mpi2BiosPage2_t
operator|,
name|MPI2_POINTER
name|pMpi2BiosPage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE2_PAGEVERSION
value|(0x04)
end_define

begin_comment
comment|/* values for BIOS Page 2 BootDeviceForm fields */
end_comment

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE2_FORM_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE2_FORM_NO_DEVICE_SPECIFIED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE2_FORM_SAS_WWID
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE2_FORM_ENCLOSURE_SLOT
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE2_FORM_DEVICE_NAME
value|(0x07)
end_define

begin_comment
comment|/* BIOS Page 3 */
end_comment

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE3_NUM_ADAPTER
value|(4)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_ADAPTER_INFO
block|{
name|U8
name|PciBusNumber
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PciDeviceAndFunctionNumber
decl_stmt|;
comment|/* 0x01 */
name|U16
name|AdapterFlags
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI2_ADAPTER_INFO
operator|,
name|MPI2_POINTER
name|PTR_MPI2_ADAPTER_INFO
operator|,
name|Mpi2AdapterInfo_t
operator|,
name|MPI2_POINTER
name|pMpi2AdapterInfo_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_ADAPTER_INFO_FLAGS_EMBEDDED
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI2_ADAPTER_INFO_FLAGS_INIT_STATUS
value|(0x0002)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_ADAPTER_ORDER_AUX
block|{
name|U64
name|WWID
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI2_ADAPTER_ORDER_AUX
operator|,
name|MPI2_POINTER
name|PTR_MPI2_ADAPTER_ORDER_AUX
operator|,
name|Mpi2AdapterOrderAux_t
operator|,
name|MPI2_POINTER
name|pMpi2AdapterOrderAux_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_BIOS_3
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|GlobalFlags
decl_stmt|;
comment|/* 0x04 */
name|U32
name|BiosVersion
decl_stmt|;
comment|/* 0x08 */
name|MPI2_ADAPTER_INFO
name|AdapterOrder
index|[
name|MPI2_BIOSPAGE3_NUM_ADAPTER
index|]
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x1C */
name|MPI2_ADAPTER_ORDER_AUX
name|AdapterOrderAux
index|[
name|MPI2_BIOSPAGE3_NUM_ADAPTER
index|]
decl_stmt|;
comment|/* 0x20 */
comment|/* MPI v2.5 and newer */
block|}
name|MPI2_CONFIG_PAGE_BIOS_3
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_BIOS_3
operator|,
name|Mpi2BiosPage3_t
operator|,
name|MPI2_POINTER
name|pMpi2BiosPage3_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE3_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/* values for BIOS Page 3 GlobalFlags */
end_comment

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE3_FLAGS_PAUSE_ON_ERROR
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE3_FLAGS_VERBOSE_ENABLE
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE3_FLAGS_HOOK_INT_40_DISABLE
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE3_FLAGS_DEV_LIST_DISPLAY_MASK
value|(0x000000E0)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE3_FLAGS_INSTALLED_DEV_DISPLAY
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE3_FLAGS_ADAPTER_DISPLAY
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE3_FLAGS_ADAPTER_DEV_DISPLAY
value|(0x00000040)
end_define

begin_comment
comment|/* BIOS Page 4 */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumPhys at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_BIOS_PAGE_4_PHY_ENTRIES
end_ifndef

begin_define
define|#
directive|define
name|MPI2_BIOS_PAGE_4_PHY_ENTRIES
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_BIOS4_ENTRY
block|{
name|U64
name|ReassignmentWWID
decl_stmt|;
comment|/* 0x00 */
name|U64
name|ReassignmentDeviceName
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_BIOS4_ENTRY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_BIOS4_ENTRY
operator|,
name|Mpi2MBios4Entry_t
operator|,
name|MPI2_POINTER
name|pMpi2Bios4Entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_BIOS_4
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x05 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x06 */
name|MPI2_BIOS4_ENTRY
name|Phy
index|[
name|MPI2_BIOS_PAGE_4_PHY_ENTRIES
index|]
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_CONFIG_PAGE_BIOS_4
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_BIOS_4
operator|,
name|Mpi2BiosPage4_t
operator|,
name|MPI2_POINTER
name|pMpi2BiosPage4_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_BIOSPAGE4_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/**************************************************************************** *   RAID Volume Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* RAID Volume Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAIDVOL0_PHYS_DISK
block|{
name|U8
name|RAIDSetNum
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PhysDiskMap
decl_stmt|;
comment|/* 0x01 */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved
decl_stmt|;
comment|/* 0x03 */
block|}
name|MPI2_RAIDVOL0_PHYS_DISK
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAIDVOL0_PHYS_DISK
operator|,
name|Mpi2RaidVol0PhysDisk_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidVol0PhysDisk_t
typedef|;
end_typedef

begin_comment
comment|/* defines for the PhysDiskMap field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_PHYSDISK_PRIMARY
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_PHYSDISK_SECONDARY
value|(0x02)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAIDVOL0_SETTINGS
block|{
name|U16
name|Settings
decl_stmt|;
comment|/* 0x00 */
name|U8
name|HotSparePool
decl_stmt|;
comment|/* 0x01 */
name|U8
name|Reserved
decl_stmt|;
comment|/* 0x02 */
block|}
name|MPI2_RAIDVOL0_SETTINGS
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAIDVOL0_SETTINGS
operator|,
name|Mpi2RaidVol0Settings_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidVol0Settings_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Volume Page 0 HotSparePool defines, also used in RAID Physical Disk */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_HOT_SPARE_POOL_0
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_HOT_SPARE_POOL_1
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_HOT_SPARE_POOL_2
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_HOT_SPARE_POOL_3
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_HOT_SPARE_POOL_4
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_HOT_SPARE_POOL_5
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_HOT_SPARE_POOL_6
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_HOT_SPARE_POOL_7
value|(0x80)
end_define

begin_comment
comment|/* RAID Volume Page 0 VolumeSettings defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_SETTING_USE_PRODUCT_ID_SUFFIX
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_SETTING_AUTO_CONFIG_HSWAP_DISABLE
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_SETTING_MASK_WRITE_CACHING
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_SETTING_UNCHANGED
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_SETTING_DISABLE_WRITE_CACHING
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_SETTING_ENABLE_WRITE_CACHING
value|(0x0002)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumPhysDisks at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_RAID_VOL_PAGE_0_PHYSDISK_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_PAGE_0_PHYSDISK_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_RAID_VOL_0
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x04 */
name|U8
name|VolumeState
decl_stmt|;
comment|/* 0x06 */
name|U8
name|VolumeType
decl_stmt|;
comment|/* 0x07 */
name|U32
name|VolumeStatusFlags
decl_stmt|;
comment|/* 0x08 */
name|MPI2_RAIDVOL0_SETTINGS
name|VolumeSettings
decl_stmt|;
comment|/* 0x0C */
name|U64
name|MaxLBA
decl_stmt|;
comment|/* 0x10 */
name|U32
name|StripeSize
decl_stmt|;
comment|/* 0x18 */
name|U16
name|BlockSize
decl_stmt|;
comment|/* 0x1C */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x1E */
name|U8
name|SupportedPhysDisks
decl_stmt|;
comment|/* 0x20 */
name|U8
name|ResyncRate
decl_stmt|;
comment|/* 0x21 */
name|U16
name|DataScrubDuration
decl_stmt|;
comment|/* 0x22 */
name|U8
name|NumPhysDisks
decl_stmt|;
comment|/* 0x24 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x25 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x26 */
name|U8
name|InactiveStatus
decl_stmt|;
comment|/* 0x27 */
name|MPI2_RAIDVOL0_PHYS_DISK
name|PhysDisk
index|[
name|MPI2_RAID_VOL_PAGE_0_PHYSDISK_MAX
index|]
decl_stmt|;
comment|/* 0x28 */
block|}
name|MPI2_CONFIG_PAGE_RAID_VOL_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_RAID_VOL_0
operator|,
name|Mpi2RaidVolPage0_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidVolPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_RAIDVOLPAGE0_PAGEVERSION
value|(0x0A)
end_define

begin_comment
comment|/* values for RAID VolumeState */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_STATE_MISSING
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_STATE_FAILED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_STATE_INITIALIZING
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_STATE_ONLINE
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_STATE_DEGRADED
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_STATE_OPTIMAL
value|(0x05)
end_define

begin_comment
comment|/* values for RAID VolumeType */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_TYPE_RAID0
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_TYPE_RAID1E
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_TYPE_RAID1
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_TYPE_RAID10
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_VOL_TYPE_UNKNOWN
value|(0xFF)
end_define

begin_comment
comment|/* values for RAID Volume Page 0 VolumeStatusFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_PENDING_RESYNC
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_BACKG_INIT_PENDING
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_MDC_PENDING
value|(0x00800000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_USER_CONSIST_PENDING
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_MAKE_DATA_CONSISTENT
value|(0x00200000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_DATA_SCRUB
value|(0x00100000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_CONSISTENCY_CHECK
value|(0x00080000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_CAPACITY_EXPANSION
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_BACKGROUND_INIT
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_RESYNC_IN_PROGRESS
value|(0x00010000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_VOL_NOT_CONSISTENT
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_OCE_ALLOWED
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_BGI_COMPLETE
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_1E_OFFSET_MIRROR
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_1E_ADJACENT_MIRROR
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_BAD_BLOCK_TABLE_FULL
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_VOLUME_INACTIVE
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_QUIESCED
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_STATUS_FLAG_ENABLED
value|(0x00000001)
end_define

begin_comment
comment|/* values for RAID Volume Page 0 SupportedPhysDisks field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_SUPPORT_SOLID_STATE_DISKS
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_SUPPORT_HARD_DISKS
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_SUPPORT_SAS_PROTOCOL
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOL0_SUPPORT_SATA_PROTOCOL
value|(0x01)
end_define

begin_comment
comment|/* values for RAID Volume Page 0 InactiveStatus field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAIDVOLPAGE0_UNKNOWN_INACTIVE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOLPAGE0_STALE_METADATA_INACTIVE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOLPAGE0_FOREIGN_VOLUME_INACTIVE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOLPAGE0_INSUFFICIENT_RESOURCE_INACTIVE
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOLPAGE0_CLONE_VOLUME_INACTIVE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOLPAGE0_INSUFFICIENT_METADATA_INACTIVE
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDVOLPAGE0_PREVIOUSLY_DELETED
value|(0x06)
end_define

begin_comment
comment|/* RAID Volume Page 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_RAID_VOL_1
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x04 */
name|U16
name|Reserved0
decl_stmt|;
comment|/* 0x06 */
name|U8
name|GUID
index|[
literal|24
index|]
decl_stmt|;
comment|/* 0x08 */
name|U8
name|Name
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x20 */
name|U64
name|WWID
decl_stmt|;
comment|/* 0x30 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x38 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x3C */
block|}
name|MPI2_CONFIG_PAGE_RAID_VOL_1
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_RAID_VOL_1
operator|,
name|Mpi2RaidVolPage1_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidVolPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_RAIDVOLPAGE1_PAGEVERSION
value|(0x03)
end_define

begin_comment
comment|/**************************************************************************** *   RAID Physical Disk Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* RAID Physical Disk Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAIDPHYSDISK0_SETTINGS
block|{
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x00 */
name|U8
name|HotSparePool
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x03 */
block|}
name|MPI2_RAIDPHYSDISK0_SETTINGS
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAIDPHYSDISK0_SETTINGS
operator|,
name|Mpi2RaidPhysDisk0Settings_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidPhysDisk0Settings_t
typedef|;
end_typedef

begin_comment
comment|/* use MPI2_RAID_HOT_SPARE_POOL_ defines for the HotSparePool field */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAIDPHYSDISK0_INQUIRY_DATA
block|{
name|U8
name|VendorID
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x00 */
name|U8
name|ProductID
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x08 */
name|U8
name|ProductRevLevel
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x18 */
name|U8
name|SerialNum
index|[
literal|32
index|]
decl_stmt|;
comment|/* 0x1C */
block|}
name|MPI2_RAIDPHYSDISK0_INQUIRY_DATA
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAIDPHYSDISK0_INQUIRY_DATA
operator|,
name|Mpi2RaidPhysDisk0InquiryData_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidPhysDisk0InquiryData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_RD_PDISK_0
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x06 */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 0x07 */
name|MPI2_RAIDPHYSDISK0_SETTINGS
name|PhysDiskSettings
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
name|MPI2_RAIDPHYSDISK0_INQUIRY_DATA
name|InquiryData
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x4C */
name|U8
name|PhysDiskState
decl_stmt|;
comment|/* 0x50 */
name|U8
name|OfflineReason
decl_stmt|;
comment|/* 0x51 */
name|U8
name|IncompatibleReason
decl_stmt|;
comment|/* 0x52 */
name|U8
name|PhysDiskAttributes
decl_stmt|;
comment|/* 0x53 */
name|U32
name|PhysDiskStatusFlags
decl_stmt|;
comment|/* 0x54 */
name|U64
name|DeviceMaxLBA
decl_stmt|;
comment|/* 0x58 */
name|U64
name|HostMaxLBA
decl_stmt|;
comment|/* 0x60 */
name|U64
name|CoercedMaxLBA
decl_stmt|;
comment|/* 0x68 */
name|U16
name|BlockSize
decl_stmt|;
comment|/* 0x70 */
name|U16
name|Reserved5
decl_stmt|;
comment|/* 0x72 */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x74 */
block|}
name|MPI2_CONFIG_PAGE_RD_PDISK_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_RD_PDISK_0
operator|,
name|Mpi2RaidPhysDiskPage0_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidPhysDiskPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_RAIDPHYSDISKPAGE0_PAGEVERSION
value|(0x05)
end_define

begin_comment
comment|/* PhysDiskState defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_PD_STATE_NOT_CONFIGURED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_PD_STATE_NOT_COMPATIBLE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_PD_STATE_OFFLINE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_PD_STATE_ONLINE
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_PD_STATE_HOT_SPARE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_PD_STATE_DEGRADED
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_PD_STATE_REBUILDING
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_PD_STATE_OPTIMAL
value|(0x07)
end_define

begin_comment
comment|/* OfflineReason defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_ONLINE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_OFFLINE_MISSING
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_OFFLINE_FAILED
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_OFFLINE_INITIALIZING
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_OFFLINE_REQUESTED
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_OFFLINE_FAILED_REQUESTED
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_OFFLINE_OTHER
value|(0xFF)
end_define

begin_comment
comment|/* IncompatibleReason defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_COMPATIBLE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_INCOMPATIBLE_PROTOCOL
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_INCOMPATIBLE_BLOCKSIZE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_INCOMPATIBLE_MAX_LBA
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_INCOMPATIBLE_SATA_EXTENDED_CMD
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_INCOMPATIBLE_REMOVEABLE_MEDIA
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_INCOMPATIBLE_MEDIA_TYPE
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_INCOMPATIBLE_UNKNOWN
value|(0xFF)
end_define

begin_comment
comment|/* PhysDiskAttributes defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_ATTRIB_MEDIA_MASK
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_ATTRIB_SOLID_STATE_DRIVE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_ATTRIB_HARD_DISK_DRIVE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_ATTRIB_PROTOCOL_MASK
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_ATTRIB_SAS_PROTOCOL
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_ATTRIB_SATA_PROTOCOL
value|(0x01)
end_define

begin_comment
comment|/* PhysDiskStatusFlags defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_STATUS_FLAG_NOT_CERTIFIED
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_STATUS_FLAG_OCE_TARGET
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_STATUS_FLAG_WRITE_CACHE_ENABLED
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_STATUS_FLAG_OPTIMAL_PREVIOUS
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_STATUS_FLAG_NOT_OPTIMAL_PREVIOUS
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_STATUS_FLAG_INACTIVE_VOLUME
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_STATUS_FLAG_QUIESCED
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_PHYSDISK0_STATUS_FLAG_OUT_OF_SYNC
value|(0x00000001)
end_define

begin_comment
comment|/* RAID Physical Disk Page 1 */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumPhysDiskPaths at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_RAID_PHYS_DISK1_PATH_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI2_RAID_PHYS_DISK1_PATH_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAIDPHYSDISK1_PATH
block|{
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x00 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x02 */
name|U64
name|WWID
decl_stmt|;
comment|/* 0x04 */
name|U64
name|OwnerWWID
decl_stmt|;
comment|/* 0x0C */
name|U8
name|OwnerIdentifier
decl_stmt|;
comment|/* 0x14 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x15 */
name|U16
name|Flags
decl_stmt|;
comment|/* 0x16 */
block|}
name|MPI2_RAIDPHYSDISK1_PATH
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAIDPHYSDISK1_PATH
operator|,
name|Mpi2RaidPhysDisk1Path_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidPhysDisk1Path_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Physical Disk Page 1 Physical Disk Path Flags field defines */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAID_PHYSDISK1_FLAG_PRIMARY
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_PHYSDISK1_FLAG_BROKEN
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_RAID_PHYSDISK1_FLAG_INVALID
value|(0x0001)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_RD_PDISK_1
block|{
name|MPI2_CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|NumPhysDiskPaths
decl_stmt|;
comment|/* 0x04 */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 0x05 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x06 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x08 */
name|MPI2_RAIDPHYSDISK1_PATH
name|PhysicalDiskPath
index|[
name|MPI2_RAID_PHYS_DISK1_PATH_MAX
index|]
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI2_CONFIG_PAGE_RD_PDISK_1
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_RD_PDISK_1
operator|,
name|Mpi2RaidPhysDiskPage1_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidPhysDiskPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_RAIDPHYSDISKPAGE1_PAGEVERSION
value|(0x02)
end_define

begin_comment
comment|/**************************************************************************** *   values for fields used by several types of SAS Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* values for NegotiatedLinkRates fields */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_NEG_LINK_RATE_MASK_LOGICAL
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_NEG_LINK_RATE_SHIFT_LOGICAL
value|(4)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_NEG_LINK_RATE_MASK_PHYSICAL
value|(0x0F)
end_define

begin_comment
comment|/* link rates used for Negotiated Physical and Logical Link Rate */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_NEG_LINK_RATE_UNKNOWN_LINK_RATE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_NEG_LINK_RATE_PHY_DISABLED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_NEG_LINK_RATE_NEGOTIATION_FAILED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_NEG_LINK_RATE_SATA_OOB_COMPLETE
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_NEG_LINK_RATE_PORT_SELECTOR
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_NEG_LINK_RATE_SMP_RESET_IN_PROGRESS
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_NEG_LINK_RATE_UNSUPPORTED_PHY
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_NEG_LINK_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_NEG_LINK_RATE_3_0
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_NEG_LINK_RATE_6_0
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI25_SAS_NEG_LINK_RATE_12_0
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI26_SAS_NEG_LINK_RATE_22_5
value|(0x0C)
end_define

begin_comment
comment|/* values for AttachedPhyInfo fields */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_APHYINFO_INSIDE_ZPSDS_PERSISTENT
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_APHYINFO_REQUESTED_INSIDE_ZPSDS
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_APHYINFO_BREAK_REPLY_CAPABLE
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_APHYINFO_REASON_MASK
value|(0x0000000F)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_APHYINFO_REASON_UNKNOWN
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_APHYINFO_REASON_POWER_ON
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_APHYINFO_REASON_HARD_RESET
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_APHYINFO_REASON_SMP_PHY_CONTROL
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_APHYINFO_REASON_LOSS_OF_SYNC
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_APHYINFO_REASON_MULTIPLEXING_SEQ
value|(0x00000005)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_APHYINFO_REASON_IT_NEXUS_LOSS_TIMER
value|(0x00000006)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_APHYINFO_REASON_BREAK_TIMEOUT
value|(0x00000007)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_APHYINFO_REASON_PHY_TEST_STOPPED
value|(0x00000008)
end_define

begin_comment
comment|/* values for PhyInfo fields */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_PHY_VACANT
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_PHY_POWER_CONDITION_MASK
value|(0x18000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_SHIFT_PHY_POWER_CONDITION
value|(27)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_PHY_POWER_ACTIVE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_PHY_POWER_PARTIAL
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_PHY_POWER_SLUMBER
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_CHANGED_REQ_INSIDE_ZPSDS
value|(0x04000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_INSIDE_ZPSDS_PERSISTENT
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_REQ_INSIDE_ZPSDS
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_ZONE_GROUP_PERSISTENT
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_INSIDE_ZPSDS
value|(0x00200000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_ZONING_ENABLED
value|(0x00100000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_REASON_MASK
value|(0x000F0000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_REASON_UNKNOWN
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_REASON_POWER_ON
value|(0x00010000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_REASON_HARD_RESET
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_REASON_SMP_PHY_CONTROL
value|(0x00030000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_REASON_LOSS_OF_SYNC
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_REASON_MULTIPLEXING_SEQ
value|(0x00050000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_REASON_IT_NEXUS_LOSS_TIMER
value|(0x00060000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_REASON_BREAK_TIMEOUT
value|(0x00070000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_REASON_PHY_TEST_STOPPED
value|(0x00080000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_MULTIPLEXING_SUPPORTED
value|(0x00008000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_SATA_PORT_ACTIVE
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_SATA_PORT_SELECTOR_PRESENT
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_VIRTUAL_PHY
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_MASK_PARTIAL_PATHWAY_TIME
value|(0x00000F00)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_SHIFT_PARTIAL_PATHWAY_TIME
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_MASK_ROUTING_ATTRIBUTE
value|(0x000000F0)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_DIRECT_ROUTING
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_SUBTRACTIVE_ROUTING
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PHYINFO_TABLE_ROUTING
value|(0x00000020)
end_define

begin_comment
comment|/* values for SAS ProgrammedLinkRate fields */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_PRATE_MAX_RATE_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PRATE_MAX_RATE_NOT_PROGRAMMABLE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PRATE_MAX_RATE_1_5
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PRATE_MAX_RATE_3_0
value|(0x90)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PRATE_MAX_RATE_6_0
value|(0xA0)
end_define

begin_define
define|#
directive|define
name|MPI25_SAS_PRATE_MAX_RATE_12_0
value|(0xB0)
end_define

begin_define
define|#
directive|define
name|MPI26_SAS_PRATE_MAX_RATE_22_5
value|(0xC0)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PRATE_MIN_RATE_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PRATE_MIN_RATE_NOT_PROGRAMMABLE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PRATE_MIN_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PRATE_MIN_RATE_3_0
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_PRATE_MIN_RATE_6_0
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI25_SAS_PRATE_MIN_RATE_12_0
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI26_SAS_PRATE_MIN_RATE_22_5
value|(0x0C)
end_define

begin_comment
comment|/* values for SAS HwLinkRate fields */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_HWRATE_MAX_RATE_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_HWRATE_MAX_RATE_1_5
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_HWRATE_MAX_RATE_3_0
value|(0x90)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_HWRATE_MAX_RATE_6_0
value|(0xA0)
end_define

begin_define
define|#
directive|define
name|MPI25_SAS_HWRATE_MAX_RATE_12_0
value|(0xB0)
end_define

begin_define
define|#
directive|define
name|MPI26_SAS_HWRATE_MAX_RATE_22_5
value|(0xC0)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_HWRATE_MIN_RATE_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_HWRATE_MIN_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_HWRATE_MIN_RATE_3_0
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_HWRATE_MIN_RATE_6_0
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI25_SAS_HWRATE_MIN_RATE_12_0
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI26_SAS_HWRATE_MIN_RATE_22_5
value|(0x0C)
end_define

begin_comment
comment|/**************************************************************************** *   SAS IO Unit Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* SAS IO Unit Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SAS_IO_UNIT0_PHY_DATA
block|{
name|U8
name|Port
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PortFlags
decl_stmt|;
comment|/* 0x01 */
name|U8
name|PhyFlags
decl_stmt|;
comment|/* 0x02 */
name|U8
name|NegotiatedLinkRate
decl_stmt|;
comment|/* 0x03 */
name|U32
name|ControllerPhyDeviceInfo
decl_stmt|;
comment|/* 0x04 */
name|U16
name|AttachedDevHandle
decl_stmt|;
comment|/* 0x08 */
name|U16
name|ControllerDevHandle
decl_stmt|;
comment|/* 0x0A */
name|U32
name|DiscoveryStatus
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_SAS_IO_UNIT0_PHY_DATA
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SAS_IO_UNIT0_PHY_DATA
operator|,
name|Mpi2SasIOUnit0PhyData_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnit0PhyData_t
typedef|;
end_typedef

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumPhys at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_SAS_IOUNIT0_PHY_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI2_SAS_IOUNIT0_PHY_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SASIOUNIT_0
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0E */
name|MPI2_SAS_IO_UNIT0_PHY_DATA
name|PhyData
index|[
name|MPI2_SAS_IOUNIT0_PHY_MAX
index|]
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_CONFIG_PAGE_SASIOUNIT_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SASIOUNIT_0
operator|,
name|Mpi2SasIOUnitPage0_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnitPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASIOUNITPAGE0_PAGEVERSION
value|(0x05)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 0 PortFlags */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_PORTFLAGS_DISCOVERY_IN_PROGRESS
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_PORTFLAGS_AUTO_PORT_CONFIG
value|(0x01)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 0 PhyFlags */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_PHYFLAGS_INIT_PERSIST_CONNECT
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_PHYFLAGS_TARG_PERSIST_CONNECT
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_PHYFLAGS_ZONING_ENABLED
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_PHYFLAGS_PHY_DISABLED
value|(0x08)
end_define

begin_comment
comment|/* use MPI2_SAS_NEG_LINK_RATE_ defines for the NegotiatedLinkRate field */
end_comment

begin_comment
comment|/* see mpi2_sas.h for values for SAS IO Unit Page 0 ControllerPhyDeviceInfo values */
end_comment

begin_comment
comment|/* values for SAS IO Unit Page 0 DiscoveryStatus */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_MAX_ENCLOSURES_EXCEED
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_MAX_EXPANDERS_EXCEED
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_MAX_DEVICES_EXCEED
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_MAX_TOPO_PHYS_EXCEED
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_DOWNSTREAM_INITIATOR
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_MULTI_SUBTRACTIVE_SUBTRACTIVE
value|(0x00008000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_EXP_MULTI_SUBTRACTIVE
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_MULTI_PORT_DOMAIN
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_TABLE_TO_SUBTRACTIVE_LINK
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_UNSUPPORTED_DEVICE
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_TABLE_LINK
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_SUBTRACTIVE_LINK
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_SMP_CRC_ERROR
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_SMP_FUNCTION_FAILED
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_INDEX_NOT_EXIST
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_OUT_ROUTE_ENTRIES
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_SMP_TIMEOUT
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_MULTIPLE_PORTS
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_UNADDRESSABLE_DEVICE
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT0_DS_LOOP_DETECTED
value|(0x00000001)
end_define

begin_comment
comment|/* SAS IO Unit Page 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SAS_IO_UNIT1_PHY_DATA
block|{
name|U8
name|Port
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PortFlags
decl_stmt|;
comment|/* 0x01 */
name|U8
name|PhyFlags
decl_stmt|;
comment|/* 0x02 */
name|U8
name|MaxMinLinkRate
decl_stmt|;
comment|/* 0x03 */
name|U32
name|ControllerPhyDeviceInfo
decl_stmt|;
comment|/* 0x04 */
name|U16
name|MaxTargetPortConnectTime
decl_stmt|;
comment|/* 0x08 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x0A */
block|}
name|MPI2_SAS_IO_UNIT1_PHY_DATA
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SAS_IO_UNIT1_PHY_DATA
operator|,
name|Mpi2SasIOUnit1PhyData_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnit1PhyData_t
typedef|;
end_typedef

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumPhys at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_SAS_IOUNIT1_PHY_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI2_SAS_IOUNIT1_PHY_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SASIOUNIT_1
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U16
name|ControlFlags
decl_stmt|;
comment|/* 0x08 */
name|U16
name|SASNarrowMaxQueueDepth
decl_stmt|;
comment|/* 0x0A */
name|U16
name|AdditionalControlFlags
decl_stmt|;
comment|/* 0x0C */
name|U16
name|SASWideMaxQueueDepth
decl_stmt|;
comment|/* 0x0E */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0x10 */
name|U8
name|SATAMaxQDepth
decl_stmt|;
comment|/* 0x11 */
name|U8
name|ReportDeviceMissingDelay
decl_stmt|;
comment|/* 0x12 */
name|U8
name|IODeviceMissingDelay
decl_stmt|;
comment|/* 0x13 */
name|MPI2_SAS_IO_UNIT1_PHY_DATA
name|PhyData
index|[
name|MPI2_SAS_IOUNIT1_PHY_MAX
index|]
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_CONFIG_PAGE_SASIOUNIT_1
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SASIOUNIT_1
operator|,
name|Mpi2SasIOUnitPage1_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnitPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASIOUNITPAGE1_PAGEVERSION
value|(0x09)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 1 ControlFlags */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_DEVICE_SELF_TEST
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_SATA_3_0_MAX
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_SATA_1_5_MAX
value|(0x2000)
end_define

begin_comment
comment|/* MPI v2.0 only. Obsolete in MPI v2.5 and later. */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_SATA_SW_PRESERVE
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_MASK_DEV_SUPPORT
value|(0x0600)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_SHIFT_DEV_SUPPORT
value|(9)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_DEV_SUPPORT_BOTH
value|(0x0)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_DEV_SAS_SUPPORT
value|(0x1)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_DEV_SATA_SUPPORT
value|(0x2)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_SATA_48BIT_LBA_REQUIRED
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_SATA_SMART_REQUIRED
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_SATA_NCQ_REQUIRED
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_SATA_FUA_REQUIRED
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_TABLE_SUBTRACTIVE_ILLEGAL
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_SUBTRACTIVE_ILLEGAL
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_FIRST_LVL_DISC_ONLY
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_CONTROL_CLEAR_AFFILIATION
value|(0x0001)
end_define

begin_comment
comment|/* MPI v2.0 only. Obsolete in MPI v2.5 and later. */
end_comment

begin_comment
comment|/* values for SAS IO Unit Page 1 AdditionalControlFlags */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_ACONTROL_DA_PERSIST_CONNECT
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_ACONTROL_MULTI_PORT_DOMAIN_ILLEGAL
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_ACONTROL_SATA_ASYNCHROUNOUS_NOTIFICATION
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_ACONTROL_INVALID_TOPOLOGY_CORRECTION
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_ACONTROL_PORT_ENABLE_ONLY_SATA_LINK_RESET
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_ACONTROL_OTHER_AFFILIATION_SATA_LINK_RESET
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_ACONTROL_SELF_AFFILIATION_SATA_LINK_RESET
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_ACONTROL_NO_AFFILIATION_SATA_LINK_RESET
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_ACONTROL_ALLOW_TABLE_TO_TABLE
value|(0x0001)
end_define

begin_comment
comment|/* defines for SAS IO Unit Page 1 ReportDeviceMissingDelay */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_REPORT_MISSING_TIMEOUT_MASK
value|(0x7F)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_REPORT_MISSING_UNIT_16
value|(0x80)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 1 PortFlags */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_PORT_FLAGS_AUTO_PORT_CONFIG
value|(0x01)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 1 PhyFlags */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_PHYFLAGS_INIT_PERSIST_CONNECT
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_PHYFLAGS_TARG_PERSIST_CONNECT
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_PHYFLAGS_ZONING_ENABLE
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_PHYFLAGS_PHY_DISABLE
value|(0x08)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 1 MaxMinLinkRate */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_MAX_RATE_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_MAX_RATE_1_5
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_MAX_RATE_3_0
value|(0x90)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_MAX_RATE_6_0
value|(0xA0)
end_define

begin_define
define|#
directive|define
name|MPI25_SASIOUNIT1_MAX_RATE_12_0
value|(0xB0)
end_define

begin_define
define|#
directive|define
name|MPI26_SASIOUNIT1_MAX_RATE_22_5
value|(0xC0)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_MIN_RATE_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_MIN_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_MIN_RATE_3_0
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT1_MIN_RATE_6_0
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI25_SASIOUNIT1_MIN_RATE_12_0
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI26_SASIOUNIT1_MIN_RATE_22_5
value|(0x0C)
end_define

begin_comment
comment|/* see mpi2_sas.h for values for SAS IO Unit Page 1 ControllerPhyDeviceInfo values */
end_comment

begin_comment
comment|/* SAS IO Unit Page 4 (for MPI v2.5 and earlier) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SAS_IOUNIT4_SPINUP_GROUP
block|{
name|U8
name|MaxTargetSpinup
decl_stmt|;
comment|/* 0x00 */
name|U8
name|SpinupDelay
decl_stmt|;
comment|/* 0x01 */
name|U8
name|SpinupFlags
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x03 */
block|}
name|MPI2_SAS_IOUNIT4_SPINUP_GROUP
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SAS_IOUNIT4_SPINUP_GROUP
operator|,
name|Mpi2SasIOUnit4SpinupGroup_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnit4SpinupGroup_t
typedef|;
end_typedef

begin_comment
comment|/* defines for SAS IO Unit Page 4 SpinupFlags */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT4_SPINUP_DISABLE_FLAG
value|(0x01)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumPhys at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_SAS_IOUNIT4_PHY_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI2_SAS_IOUNIT4_PHY_MAX
value|(4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SASIOUNIT_4
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|MPI2_SAS_IOUNIT4_SPINUP_GROUP
name|SpinupGroupParameters
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x18 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x1C */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x20 */
name|U8
name|BootDeviceWaitTime
decl_stmt|;
comment|/* 0x24 */
name|U8
name|SATADeviceWaitTime
decl_stmt|;
comment|/* 0x25 */
name|U16
name|Reserved5
decl_stmt|;
comment|/* 0x26 */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0x28 */
name|U8
name|PEInitialSpinupDelay
decl_stmt|;
comment|/* 0x29 */
name|U8
name|PEReplyDelay
decl_stmt|;
comment|/* 0x2A */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x2B */
name|U8
name|PHY
index|[
name|MPI2_SAS_IOUNIT4_PHY_MAX
index|]
decl_stmt|;
comment|/* 0x2C */
block|}
name|MPI2_CONFIG_PAGE_SASIOUNIT_4
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SASIOUNIT_4
operator|,
name|Mpi2SasIOUnitPage4_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnitPage4_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASIOUNITPAGE4_PAGEVERSION
value|(0x02)
end_define

begin_comment
comment|/* defines for Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT4_FLAGS_AUTO_PORTENABLE
value|(0x01)
end_define

begin_comment
comment|/* defines for PHY field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT4_PHY_SPINUP_GROUP_MASK
value|(0x03)
end_define

begin_comment
comment|/* SAS IO Unit Page 5 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SAS_IO_UNIT5_PHY_PM_SETTINGS
block|{
name|U8
name|ControlFlags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PortWidthModGroup
decl_stmt|;
comment|/* 0x01 */
name|U16
name|InactivityTimerExponent
decl_stmt|;
comment|/* 0x02 */
name|U8
name|SATAPartialTimeout
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x05 */
name|U8
name|SATASlumberTimeout
decl_stmt|;
comment|/* 0x06 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x07 */
name|U8
name|SASPartialTimeout
decl_stmt|;
comment|/* 0x08 */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 0x09 */
name|U8
name|SASSlumberTimeout
decl_stmt|;
comment|/* 0x0A */
name|U8
name|Reserved5
decl_stmt|;
comment|/* 0x0B */
block|}
name|MPI2_SAS_IO_UNIT5_PHY_PM_SETTINGS
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SAS_IO_UNIT5_PHY_PM_SETTINGS
operator|,
name|Mpi2SasIOUnit5PhyPmSettings_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnit5PhyPmSettings_t
typedef|;
end_typedef

begin_comment
comment|/* defines for ControlFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_CONTROL_SAS_SLUMBER_ENABLE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_CONTROL_SAS_PARTIAL_ENABLE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_CONTROL_SATA_SLUMBER_ENABLE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_CONTROL_SATA_PARTIAL_ENABLE
value|(0x01)
end_define

begin_comment
comment|/* defines for PortWidthModeGroup field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_PWMG_DISABLE
value|(0xFF)
end_define

begin_comment
comment|/* defines for InactivityTimerExponent field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_MASK_SAS_SLUMBER
value|(0x7000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_SHIFT_SAS_SLUMBER
value|(12)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_MASK_SAS_PARTIAL
value|(0x0700)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_SHIFT_SAS_PARTIAL
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_MASK_SATA_SLUMBER
value|(0x0070)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_SHIFT_SATA_SLUMBER
value|(4)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_MASK_SATA_PARTIAL
value|(0x0007)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_SHIFT_SATA_PARTIAL
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_TEN_SECONDS
value|(7)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_ONE_SECOND
value|(6)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_HUNDRED_MILLISECONDS
value|(5)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_TEN_MILLISECONDS
value|(4)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_ONE_MILLISECOND
value|(3)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_HUNDRED_MICROSECONDS
value|(2)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_TEN_MICROSECONDS
value|(1)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT5_ITE_ONE_MICROSECOND
value|(0)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumPhys at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_SAS_IOUNIT5_PHY_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI2_SAS_IOUNIT5_PHY_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SASIOUNIT_5
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0x08 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x0C */
name|MPI2_SAS_IO_UNIT5_PHY_PM_SETTINGS
name|SASPhyPowerManagementSettings
index|[
name|MPI2_SAS_IOUNIT5_PHY_MAX
index|]
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_CONFIG_PAGE_SASIOUNIT_5
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SASIOUNIT_5
operator|,
name|Mpi2SasIOUnitPage5_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnitPage5_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASIOUNITPAGE5_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/* SAS IO Unit Page 6 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SAS_IO_UNIT6_PORT_WIDTH_MOD_GROUP_STATUS
block|{
name|U8
name|CurrentStatus
decl_stmt|;
comment|/* 0x00 */
name|U8
name|CurrentModulation
decl_stmt|;
comment|/* 0x01 */
name|U8
name|CurrentUtilization
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x03 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_SAS_IO_UNIT6_PORT_WIDTH_MOD_GROUP_STATUS
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SAS_IO_UNIT6_PORT_WIDTH_MOD_GROUP_STATUS
operator|,
name|Mpi2SasIOUnit6PortWidthModGroupStatus_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnit6PortWidthModGroupStatus_t
typedef|;
end_typedef

begin_comment
comment|/* defines for CurrentStatus field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT6_STATUS_UNAVAILABLE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT6_STATUS_UNCONFIGURED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT6_STATUS_INVALID_CONFIG
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT6_STATUS_LINK_DOWN
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT6_STATUS_OBSERVATION_ONLY
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT6_STATUS_INACTIVE
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT6_STATUS_ACTIVE_IOUNIT
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT6_STATUS_ACTIVE_HOST
value|(0x07)
end_define

begin_comment
comment|/* defines for CurrentModulation field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT6_MODULATION_25_PERCENT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT6_MODULATION_50_PERCENT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT6_MODULATION_75_PERCENT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT6_MODULATION_100_PERCENT
value|(0x03)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumGroups at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_SAS_IOUNIT6_GROUP_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI2_SAS_IOUNIT6_GROUP_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SASIOUNIT_6
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
name|U8
name|NumGroups
decl_stmt|;
comment|/* 0x10 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x11 */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x12 */
name|MPI2_SAS_IO_UNIT6_PORT_WIDTH_MOD_GROUP_STATUS
name|PortWidthModulationGroupStatus
index|[
name|MPI2_SAS_IOUNIT6_GROUP_MAX
index|]
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_CONFIG_PAGE_SASIOUNIT_6
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SASIOUNIT_6
operator|,
name|Mpi2SasIOUnitPage6_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnitPage6_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASIOUNITPAGE6_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* SAS IO Unit Page 7 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SAS_IO_UNIT7_PORT_WIDTH_MOD_GROUP_SETTINGS
block|{
name|U8
name|Flags
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
name|U8
name|Threshold75Pct
decl_stmt|;
comment|/* 0x04 */
name|U8
name|Threshold50Pct
decl_stmt|;
comment|/* 0x05 */
name|U8
name|Threshold25Pct
decl_stmt|;
comment|/* 0x06 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x07 */
block|}
name|MPI2_SAS_IO_UNIT7_PORT_WIDTH_MOD_GROUP_SETTINGS
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SAS_IO_UNIT7_PORT_WIDTH_MOD_GROUP_SETTINGS
operator|,
name|Mpi2SasIOUnit7PortWidthModGroupSettings_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnit7PortWidthModGroupSettings_t
typedef|;
end_typedef

begin_comment
comment|/* defines for Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT7_FLAGS_ENABLE_PORT_WIDTH_MODULATION
value|(0x01)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumGroups at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_SAS_IOUNIT7_GROUP_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI2_SAS_IOUNIT7_GROUP_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SASIOUNIT_7
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|SamplingInterval
decl_stmt|;
comment|/* 0x08 */
name|U8
name|WindowLength
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x10 */
name|U8
name|NumGroups
decl_stmt|;
comment|/* 0x14 */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 0x15 */
name|U16
name|Reserved5
decl_stmt|;
comment|/* 0x16 */
name|MPI2_SAS_IO_UNIT7_PORT_WIDTH_MOD_GROUP_SETTINGS
name|PortWidthModulationGroupSettings
index|[
name|MPI2_SAS_IOUNIT7_GROUP_MAX
index|]
decl_stmt|;
comment|/* 0x18 */
block|}
name|MPI2_CONFIG_PAGE_SASIOUNIT_7
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SASIOUNIT_7
operator|,
name|Mpi2SasIOUnitPage7_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnitPage7_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASIOUNITPAGE7_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* SAS IO Unit Page 8 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SASIOUNIT_8
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U32
name|PowerManagementCapabilities
decl_stmt|;
comment|/* 0x0C */
name|U8
name|TxRxSleepStatus
decl_stmt|;
comment|/* 0x10 */
comment|/* reserved in MPI 2.0 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x11 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x12 */
block|}
name|MPI2_CONFIG_PAGE_SASIOUNIT_8
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SASIOUNIT_8
operator|,
name|Mpi2SasIOUnitPage8_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnitPage8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASIOUNITPAGE8_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* defines for PowerManagementCapabilities field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT8_PM_HOST_PORT_WIDTH_MOD
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT8_PM_HOST_SAS_SLUMBER_MODE
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT8_PM_HOST_SAS_PARTIAL_MODE
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT8_PM_HOST_SATA_SLUMBER_MODE
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT8_PM_HOST_SATA_PARTIAL_MODE
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT8_PM_IOUNIT_PORT_WIDTH_MOD
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT8_PM_IOUNIT_SAS_SLUMBER_MODE
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT8_PM_IOUNIT_SAS_PARTIAL_MODE
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT8_PM_IOUNIT_SATA_SLUMBER_MODE
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_SASIOUNIT8_PM_IOUNIT_SATA_PARTIAL_MODE
value|(0x00000001)
end_define

begin_comment
comment|/* defines for TxRxSleepStatus field */
end_comment

begin_define
define|#
directive|define
name|MPI25_SASIOUNIT8_TXRXSLEEP_UNSUPPORTED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI25_SASIOUNIT8_TXRXSLEEP_DISENGAGED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI25_SASIOUNIT8_TXRXSLEEP_ACTIVE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI25_SASIOUNIT8_TXRXSLEEP_SHUTDOWN
value|(0x03)
end_define

begin_comment
comment|/* SAS IO Unit Page 16 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SASIOUNIT16
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U64
name|TimeStamp
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x14 */
name|U32
name|FastPathPendedRequests
decl_stmt|;
comment|/* 0x18 */
name|U32
name|FastPathUnPendedRequests
decl_stmt|;
comment|/* 0x1C */
name|U32
name|FastPathHostRequestStarts
decl_stmt|;
comment|/* 0x20 */
name|U32
name|FastPathFirmwareRequestStarts
decl_stmt|;
comment|/* 0x24 */
name|U32
name|FastPathHostCompletions
decl_stmt|;
comment|/* 0x28 */
name|U32
name|FastPathFirmwareCompletions
decl_stmt|;
comment|/* 0x2C */
name|U32
name|NonFastPathRequestStarts
decl_stmt|;
comment|/* 0x30 */
name|U32
name|NonFastPathHostCompletions
decl_stmt|;
comment|/* 0x30 */
block|}
name|MPI2_CONFIG_PAGE_SASIOUNIT16
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SASIOUNIT16
operator|,
name|Mpi2SasIOUnitPage16_t
operator|,
name|MPI2_POINTER
name|pMpi2SasIOUnitPage16_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASIOUNITPAGE16_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/**************************************************************************** *   SAS Expander Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* SAS Expander Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_EXPANDER_0
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x08 */
name|U8
name|ReportGenLength
decl_stmt|;
comment|/* 0x09 */
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 0x0A */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0x0C */
name|U32
name|DiscoveryStatus
decl_stmt|;
comment|/* 0x14 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x18 */
name|U16
name|ParentDevHandle
decl_stmt|;
comment|/* 0x1A */
name|U16
name|ExpanderChangeCount
decl_stmt|;
comment|/* 0x1C */
name|U16
name|ExpanderRouteIndexes
decl_stmt|;
comment|/* 0x1E */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0x20 */
name|U8
name|SASLevel
decl_stmt|;
comment|/* 0x21 */
name|U16
name|Flags
decl_stmt|;
comment|/* 0x22 */
name|U16
name|STPBusInactivityTimeLimit
decl_stmt|;
comment|/* 0x24 */
name|U16
name|STPMaxConnectTimeLimit
decl_stmt|;
comment|/* 0x26 */
name|U16
name|STP_SMP_NexusLossTime
decl_stmt|;
comment|/* 0x28 */
name|U16
name|MaxNumRoutedSasAddresses
decl_stmt|;
comment|/* 0x2A */
name|U64
name|ActiveZoneManagerSASAddress
decl_stmt|;
comment|/* 0x2C */
name|U16
name|ZoneLockInactivityLimit
decl_stmt|;
comment|/* 0x34 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x36 */
name|U8
name|TimeToReducedFunc
decl_stmt|;
comment|/* 0x38 */
name|U8
name|InitialTimeToReducedFunc
decl_stmt|;
comment|/* 0x39 */
name|U8
name|MaxReducedFuncTime
decl_stmt|;
comment|/* 0x3A */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x3B */
block|}
name|MPI2_CONFIG_PAGE_EXPANDER_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_EXPANDER_0
operator|,
name|Mpi2ExpanderPage0_t
operator|,
name|MPI2_POINTER
name|pMpi2ExpanderPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASEXPANDER0_PAGEVERSION
value|(0x06)
end_define

begin_comment
comment|/* values for SAS Expander Page 0 DiscoveryStatus field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_MAX_ENCLOSURES_EXCEED
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_MAX_EXPANDERS_EXCEED
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_MAX_DEVICES_EXCEED
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_MAX_TOPO_PHYS_EXCEED
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_DOWNSTREAM_INITIATOR
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_MULTI_SUBTRACTIVE_SUBTRACTIVE
value|(0x00008000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_EXP_MULTI_SUBTRACTIVE
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_MULTI_PORT_DOMAIN
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_TABLE_TO_SUBTRACTIVE_LINK
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_UNSUPPORTED_DEVICE
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_TABLE_LINK
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_SUBTRACTIVE_LINK
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_SMP_CRC_ERROR
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_SMP_FUNCTION_FAILED
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_INDEX_NOT_EXIST
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_OUT_ROUTE_ENTRIES
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_SMP_TIMEOUT
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_MULTIPLE_PORTS
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_UNADDRESSABLE_DEVICE
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_DS_LOOP_DETECTED
value|(0x00000001)
end_define

begin_comment
comment|/* values for SAS Expander Page 0 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_FLAGS_REDUCED_FUNCTIONALITY
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_FLAGS_ZONE_LOCKED
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_FLAGS_SUPPORTED_PHYSICAL_PRES
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_FLAGS_ASSERTED_PHYSICAL_PRES
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_FLAGS_ZONING_SUPPORT
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_FLAGS_ENABLED_ZONING
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_FLAGS_TABLE_TO_TABLE_SUPPORT
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_FLAGS_CONNECTOR_END_DEVICE
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_FLAGS_OTHERS_CONFIG
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_FLAGS_CONFIG_IN_PROGRESS
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER0_FLAGS_ROUTE_TABLE_CONFIG
value|(0x0001)
end_define

begin_comment
comment|/* SAS Expander Page 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_EXPANDER_1
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x08 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Phy
decl_stmt|;
comment|/* 0x0D */
name|U16
name|NumTableEntriesProgrammed
decl_stmt|;
comment|/* 0x0E */
name|U8
name|ProgrammedLinkRate
decl_stmt|;
comment|/* 0x10 */
name|U8
name|HwLinkRate
decl_stmt|;
comment|/* 0x11 */
name|U16
name|AttachedDevHandle
decl_stmt|;
comment|/* 0x12 */
name|U32
name|PhyInfo
decl_stmt|;
comment|/* 0x14 */
name|U32
name|AttachedDeviceInfo
decl_stmt|;
comment|/* 0x18 */
name|U16
name|ExpanderDevHandle
decl_stmt|;
comment|/* 0x1C */
name|U8
name|ChangeCount
decl_stmt|;
comment|/* 0x1E */
name|U8
name|NegotiatedLinkRate
decl_stmt|;
comment|/* 0x1F */
name|U8
name|PhyIdentifier
decl_stmt|;
comment|/* 0x20 */
name|U8
name|AttachedPhyIdentifier
decl_stmt|;
comment|/* 0x21 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x22 */
name|U8
name|DiscoveryInfo
decl_stmt|;
comment|/* 0x23 */
name|U32
name|AttachedPhyInfo
decl_stmt|;
comment|/* 0x24 */
name|U8
name|ZoneGroup
decl_stmt|;
comment|/* 0x28 */
name|U8
name|SelfConfigStatus
decl_stmt|;
comment|/* 0x29 */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x2A */
block|}
name|MPI2_CONFIG_PAGE_EXPANDER_1
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_EXPANDER_1
operator|,
name|Mpi2ExpanderPage1_t
operator|,
name|MPI2_POINTER
name|pMpi2ExpanderPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASEXPANDER1_PAGEVERSION
value|(0x02)
end_define

begin_comment
comment|/* use MPI2_SAS_PRATE_ defines for the ProgrammedLinkRate field */
end_comment

begin_comment
comment|/* use MPI2_SAS_HWRATE_ defines for the HwLinkRate field */
end_comment

begin_comment
comment|/* use MPI2_SAS_PHYINFO_ for the PhyInfo field */
end_comment

begin_comment
comment|/* see mpi2_sas.h for the MPI2_SAS_DEVICE_INFO_ defines used for the AttachedDeviceInfo field */
end_comment

begin_comment
comment|/* use MPI2_SAS_NEG_LINK_RATE_ defines for the NegotiatedLinkRate field */
end_comment

begin_comment
comment|/* values for SAS Expander Page 1 DiscoveryInfo field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER1_DISCINFO_BAD_PHY_DISABLED
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER1_DISCINFO_LINK_STATUS_CHANGE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_EXPANDER1_DISCINFO_NO_ROUTING_ENTRIES
value|(0x01)
end_define

begin_comment
comment|/* use MPI2_SAS_APHYINFO_ defines for AttachedPhyInfo field */
end_comment

begin_comment
comment|/**************************************************************************** *   SAS Device Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* SAS Device Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SAS_DEV_0
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U16
name|Slot
decl_stmt|;
comment|/* 0x08 */
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 0x0A */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0x0C */
name|U16
name|ParentDevHandle
decl_stmt|;
comment|/* 0x14 */
name|U8
name|PhyNum
decl_stmt|;
comment|/* 0x16 */
name|U8
name|AccessStatus
decl_stmt|;
comment|/* 0x17 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x18 */
name|U8
name|AttachedPhyIdentifier
decl_stmt|;
comment|/* 0x1A */
name|U8
name|ZoneGroup
decl_stmt|;
comment|/* 0x1B */
name|U32
name|DeviceInfo
decl_stmt|;
comment|/* 0x1C */
name|U16
name|Flags
decl_stmt|;
comment|/* 0x20 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x22 */
name|U8
name|MaxPortConnections
decl_stmt|;
comment|/* 0x23 */
name|U64
name|DeviceName
decl_stmt|;
comment|/* 0x24 */
name|U8
name|PortGroups
decl_stmt|;
comment|/* 0x2C */
name|U8
name|DmaGroup
decl_stmt|;
comment|/* 0x2D */
name|U8
name|ControlGroup
decl_stmt|;
comment|/* 0x2E */
name|U8
name|EnclosureLevel
decl_stmt|;
comment|/* 0x2F */
name|U8
name|ConnectorName
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x30 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x34 */
block|}
name|MPI2_CONFIG_PAGE_SAS_DEV_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SAS_DEV_0
operator|,
name|Mpi2SasDevicePage0_t
operator|,
name|MPI2_POINTER
name|pMpi2SasDevicePage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASDEVICE0_PAGEVERSION
value|(0x09)
end_define

begin_comment
comment|/* values for SAS Device Page 0 AccessStatus field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_NO_ERRORS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SATA_INIT_FAILED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SATA_CAPABILITY_FAILED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SATA_AFFILIATION_CONFLICT
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SATA_NEEDS_INITIALIZATION
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_ROUTE_NOT_ADDRESSABLE
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SMP_ERROR_NOT_ADDRESSABLE
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_DEVICE_BLOCKED
value|(0x07)
end_define

begin_comment
comment|/* specific values for SATA Init failures */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SIF_UNKNOWN
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SIF_AFFILIATION_CONFLICT
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SIF_DIAG
value|(0x12)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SIF_IDENTIFICATION
value|(0x13)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SIF_CHECK_POWER
value|(0x14)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SIF_PIO_SN
value|(0x15)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SIF_MDMA_SN
value|(0x16)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SIF_UDMA_SN
value|(0x17)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SIF_ZONING_VIOLATION
value|(0x18)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SIF_NOT_ADDRESSABLE
value|(0x19)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_ASTATUS_SIF_MAX
value|(0x1F)
end_define

begin_comment
comment|/* see mpi2_sas.h for values for SAS Device Page 0 DeviceInfo values */
end_comment

begin_comment
comment|/* values for SAS Device Page 0 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_UNAUTHORIZED_DEVICE
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|MPI25_SAS_DEVICE0_FLAGS_ENABLED_FAST_PATH
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|MPI25_SAS_DEVICE0_FLAGS_FAST_PATH_CAPABLE
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_SLUMBER_PM_CAPABLE
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_PARTIAL_PM_CAPABLE
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_SATA_ASYNCHRONOUS_NOTIFY
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_SATA_SW_PRESERVE
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_UNSUPPORTED_DEVICE
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_SATA_48BIT_LBA_SUPPORTED
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_SATA_SMART_SUPPORTED
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_SATA_NCQ_SUPPORTED
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_SATA_FUA_SUPPORTED
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_PORT_SELECTOR_ATTACH
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_PERSIST_CAPABLE
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_ENCL_LEVEL_VALID
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_DEVICE0_FLAGS_DEVICE_PRESENT
value|(0x0001)
end_define

begin_comment
comment|/* SAS Device Page 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SAS_DEV_1
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x14 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x18 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x1A */
name|U8
name|InitialRegDeviceFIS
index|[
literal|20
index|]
decl_stmt|;
comment|/* 0x1C */
block|}
name|MPI2_CONFIG_PAGE_SAS_DEV_1
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SAS_DEV_1
operator|,
name|Mpi2SasDevicePage1_t
operator|,
name|MPI2_POINTER
name|pMpi2SasDevicePage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASDEVICE1_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/**************************************************************************** *   SAS PHY Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* SAS PHY Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SAS_PHY_0
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U16
name|OwnerDevHandle
decl_stmt|;
comment|/* 0x08 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x0A */
name|U16
name|AttachedDevHandle
decl_stmt|;
comment|/* 0x0C */
name|U8
name|AttachedPhyIdentifier
decl_stmt|;
comment|/* 0x0E */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x0F */
name|U32
name|AttachedPhyInfo
decl_stmt|;
comment|/* 0x10 */
name|U8
name|ProgrammedLinkRate
decl_stmt|;
comment|/* 0x14 */
name|U8
name|HwLinkRate
decl_stmt|;
comment|/* 0x15 */
name|U8
name|ChangeCount
decl_stmt|;
comment|/* 0x16 */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x17 */
name|U32
name|PhyInfo
decl_stmt|;
comment|/* 0x18 */
name|U8
name|NegotiatedLinkRate
decl_stmt|;
comment|/* 0x1C */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x1D */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x1E */
block|}
name|MPI2_CONFIG_PAGE_SAS_PHY_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SAS_PHY_0
operator|,
name|Mpi2SasPhyPage0_t
operator|,
name|MPI2_POINTER
name|pMpi2SasPhyPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASPHY0_PAGEVERSION
value|(0x03)
end_define

begin_comment
comment|/* use MPI2_SAS_APHYINFO_ defines for AttachedPhyInfo field */
end_comment

begin_comment
comment|/* use MPI2_SAS_PRATE_ defines for the ProgrammedLinkRate field */
end_comment

begin_comment
comment|/* use MPI2_SAS_HWRATE_ defines for the HwLinkRate field */
end_comment

begin_comment
comment|/* values for SAS PHY Page 0 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_PHY0_FLAGS_SGPIO_DIRECT_ATTACH_ENC
value|(0x01)
end_define

begin_comment
comment|/* use MPI2_SAS_PHYINFO_ for the PhyInfo field */
end_comment

begin_comment
comment|/* use MPI2_SAS_NEG_LINK_RATE_ defines for the NegotiatedLinkRate field */
end_comment

begin_comment
comment|/* SAS PHY Page 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SAS_PHY_1
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U32
name|InvalidDwordCount
decl_stmt|;
comment|/* 0x0C */
name|U32
name|RunningDisparityErrorCount
decl_stmt|;
comment|/* 0x10 */
name|U32
name|LossDwordSynchCount
decl_stmt|;
comment|/* 0x14 */
name|U32
name|PhyResetProblemCount
decl_stmt|;
comment|/* 0x18 */
block|}
name|MPI2_CONFIG_PAGE_SAS_PHY_1
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SAS_PHY_1
operator|,
name|Mpi2SasPhyPage1_t
operator|,
name|MPI2_POINTER
name|pMpi2SasPhyPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASPHY1_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/* SAS PHY Page 2 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SASPHY2_PHY_EVENT
block|{
name|U8
name|PhyEventCode
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
name|U32
name|PhyEventInfo
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI2_SASPHY2_PHY_EVENT
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SASPHY2_PHY_EVENT
operator|,
name|Mpi2SasPhy2PhyEvent_t
operator|,
name|MPI2_POINTER
name|pMpi2SasPhy2PhyEvent_t
typedef|;
end_typedef

begin_comment
comment|/* use MPI2_SASPHY3_EVENT_CODE_ for the PhyEventCode field */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumPhyEvents at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_SASPHY2_PHY_EVENT_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI2_SASPHY2_PHY_EVENT_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SAS_PHY_2
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U8
name|NumPhyEvents
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0E */
name|MPI2_SASPHY2_PHY_EVENT
name|PhyEvent
index|[
name|MPI2_SASPHY2_PHY_EVENT_MAX
index|]
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_CONFIG_PAGE_SAS_PHY_2
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SAS_PHY_2
operator|,
name|Mpi2SasPhyPage2_t
operator|,
name|MPI2_POINTER
name|pMpi2SasPhyPage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASPHY2_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* SAS PHY Page 3 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_SASPHY3_PHY_EVENT_CONFIG
block|{
name|U8
name|PhyEventCode
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
name|U8
name|CounterType
decl_stmt|;
comment|/* 0x04 */
name|U8
name|ThresholdWindow
decl_stmt|;
comment|/* 0x05 */
name|U8
name|TimeUnits
decl_stmt|;
comment|/* 0x06 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x07 */
name|U32
name|EventThreshold
decl_stmt|;
comment|/* 0x08 */
name|U16
name|ThresholdFlags
decl_stmt|;
comment|/* 0x0C */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x0E */
block|}
name|MPI2_SASPHY3_PHY_EVENT_CONFIG
operator|,
name|MPI2_POINTER
name|PTR_MPI2_SASPHY3_PHY_EVENT_CONFIG
operator|,
name|Mpi2SasPhy3PhyEventConfig_t
operator|,
name|MPI2_POINTER
name|pMpi2SasPhy3PhyEventConfig_t
typedef|;
end_typedef

begin_comment
comment|/* values for PhyEventCode field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_NO_EVENT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_INVALID_DWORD
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RUNNING_DISPARITY_ERROR
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_LOSS_DWORD_SYNC
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_PHY_RESET_PROBLEM
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_ELASTICITY_BUF_OVERFLOW
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_ERROR
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_ADDR_FRAME_ERROR
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_TX_AC_OPEN_REJECT
value|(0x21)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_AC_OPEN_REJECT
value|(0x22)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_TX_RC_OPEN_REJECT
value|(0x23)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_RC_OPEN_REJECT
value|(0x24)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_AIP_PARTIAL_WAITING_ON
value|(0x25)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_AIP_CONNECT_WAITING_ON
value|(0x26)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_TX_BREAK
value|(0x27)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_BREAK
value|(0x28)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_BREAK_TIMEOUT
value|(0x29)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_CONNECTION
value|(0x2A)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_PEAKTX_PATHWAY_BLOCKED
value|(0x2B)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_PEAKTX_ARB_WAIT_TIME
value|(0x2C)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_PEAK_ARB_WAIT_TIME
value|(0x2D)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_PEAK_CONNECT_TIME
value|(0x2E)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_TX_SSP_FRAMES
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_SSP_FRAMES
value|(0x41)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_TX_SSP_ERROR_FRAMES
value|(0x42)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_SSP_ERROR_FRAMES
value|(0x43)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_TX_CREDIT_BLOCKED
value|(0x44)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_CREDIT_BLOCKED
value|(0x45)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_TX_SATA_FRAMES
value|(0x50)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_SATA_FRAMES
value|(0x51)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_SATA_OVERFLOW
value|(0x52)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_TX_SMP_FRAMES
value|(0x60)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_SMP_FRAMES
value|(0x61)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_SMP_ERROR_FRAMES
value|(0x63)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_HOTPLUG_TIMEOUT
value|(0xD0)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_MISALIGNED_MUX_PRIMITIVE
value|(0xD1)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RX_AIP
value|(0xD2)
end_define

begin_comment
comment|/* Following codes are product specific and in MPI v2.6 and later */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_LCARB_WAIT_TIME
value|(0xD3)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_RCVD_CONN_RESP_WAIT_TIME
value|(0xD4)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_LCCONN_TIME
value|(0xD5)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_SSP_TX_START_TRANSMIT
value|(0xD6)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_SATA_TX_START
value|(0xD7)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_SMP_TX_START_TRANSMT
value|(0xD8)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_TX_SMP_BREAK_CONN
value|(0xD9)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_SSP_RX_START_RECEIVE
value|(0xDA)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_SATA_RX_START_RECEIVE
value|(0xDB)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_EVENT_CODE_SMP_RX_START_RECEIVE
value|(0xDC)
end_define

begin_comment
comment|/* values for the CounterType field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASPHY3_COUNTER_TYPE_WRAPPING
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_COUNTER_TYPE_SATURATING
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_COUNTER_TYPE_PEAK_VALUE
value|(0x02)
end_define

begin_comment
comment|/* values for the TimeUnits field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASPHY3_TIME_UNITS_10_MICROSECONDS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_TIME_UNITS_100_MICROSECONDS
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_TIME_UNITS_1_MILLISECOND
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_TIME_UNITS_10_MILLISECONDS
value|(0x03)
end_define

begin_comment
comment|/* values for the ThresholdFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASPHY3_TFLAGS_PHY_RESET
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY3_TFLAGS_EVENT_NOTIFY
value|(0x0001)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumPhyEvents at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_SASPHY3_PHY_EVENT_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI2_SASPHY3_PHY_EVENT_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SAS_PHY_3
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U8
name|NumPhyEvents
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0E */
name|MPI2_SASPHY3_PHY_EVENT_CONFIG
name|PhyEventConfig
index|[
name|MPI2_SASPHY3_PHY_EVENT_MAX
index|]
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_CONFIG_PAGE_SAS_PHY_3
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SAS_PHY_3
operator|,
name|Mpi2SasPhyPage3_t
operator|,
name|MPI2_POINTER
name|pMpi2SasPhyPage3_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASPHY3_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* SAS PHY Page 4 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SAS_PHY_4
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U8
name|Flags
decl_stmt|;
comment|/* 0x0B */
name|U8
name|InitialFrame
index|[
literal|28
index|]
decl_stmt|;
comment|/* 0x0C */
block|}
name|MPI2_CONFIG_PAGE_SAS_PHY_4
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SAS_PHY_4
operator|,
name|Mpi2SasPhyPage4_t
operator|,
name|MPI2_POINTER
name|pMpi2SasPhyPage4_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASPHY4_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* values for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SASPHY4_FLAGS_FRAME_VALID
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_SASPHY4_FLAGS_SATA_FRAME
value|(0x01)
end_define

begin_comment
comment|/**************************************************************************** *   SAS Port Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* SAS Port Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SAS_PORT_0
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PortNumber
decl_stmt|;
comment|/* 0x08 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x09 */
name|U8
name|PortWidth
decl_stmt|;
comment|/* 0x0A */
name|U8
name|PhysicalPortWidth
decl_stmt|;
comment|/* 0x0B */
name|U8
name|ZoneGroup
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0E */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0x10 */
name|U32
name|DeviceInfo
decl_stmt|;
comment|/* 0x18 */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x1C */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x20 */
block|}
name|MPI2_CONFIG_PAGE_SAS_PORT_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SAS_PORT_0
operator|,
name|Mpi2SasPortPage0_t
operator|,
name|MPI2_POINTER
name|pMpi2SasPortPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASPORT0_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* see mpi2_sas.h for values for SAS Port Page 0 DeviceInfo values */
end_comment

begin_comment
comment|/**************************************************************************** *   SAS Enclosure Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* SAS Enclosure Page 0, Enclosure Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_SAS_ENCLOSURE_0
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U64
name|EnclosureLogicalID
decl_stmt|;
comment|/* 0x0C */
name|U16
name|Flags
decl_stmt|;
comment|/* 0x14 */
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 0x16 */
name|U16
name|NumSlots
decl_stmt|;
comment|/* 0x18 */
name|U16
name|StartSlot
decl_stmt|;
comment|/* 0x1A */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x1C */
name|U8
name|EnclosureLevel
decl_stmt|;
comment|/* 0x1D */
name|U16
name|SEPDevHandle
decl_stmt|;
comment|/* 0x1E */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0x20 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x24 */
block|}
name|MPI2_CONFIG_PAGE_SAS_ENCLOSURE_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_SAS_ENCLOSURE_0
operator|,
name|Mpi2SasEnclosurePage0_t
operator|,
name|MPI2_POINTER
name|pMpi2SasEnclosurePage0_t
operator|,
name|MPI26_CONFIG_PAGE_ENCLOSURE_0
operator|,
name|MPI2_POINTER
name|PTR_MPI26_CONFIG_PAGE_ENCLOSURE_0
operator|,
name|Mpi26EnclosurePage0_t
operator|,
name|MPI2_POINTER
name|pMpi26EnclosurePage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_SASENCLOSURE0_PAGEVERSION
value|(0x04)
end_define

begin_comment
comment|/* values for SAS Enclosure Page 0 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_SAS_ENCLS0_FLAGS_ENCL_LEVEL_VALID
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_ENCLS0_FLAGS_MNG_MASK
value|(0x000F)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_ENCLS0_FLAGS_MNG_UNKNOWN
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_ENCLS0_FLAGS_MNG_IOC_SES
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_ENCLS0_FLAGS_MNG_IOC_SGPIO
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_ENCLS0_FLAGS_MNG_EXP_SGPIO
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_ENCLS0_FLAGS_MNG_SES_ENCLOSURE
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI2_SAS_ENCLS0_FLAGS_MNG_IOC_GPIO
value|(0x0005)
end_define

begin_define
define|#
directive|define
name|MPI26_ENCLOSURE0_PAGEVERSION
value|(0x04)
end_define

begin_comment
comment|/* Values for Enclosure Page 0 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI26_ENCLS0_FLAGS_ENCL_LEVEL_VALID
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI26_ENCLS0_FLAGS_MNG_MASK
value|(0x000F)
end_define

begin_define
define|#
directive|define
name|MPI26_ENCLS0_FLAGS_MNG_UNKNOWN
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI26_ENCLS0_FLAGS_MNG_IOC_SES
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI26_ENCLS0_FLAGS_MNG_IOC_SGPIO
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI26_ENCLS0_FLAGS_MNG_EXP_SGPIO
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI26_ENCLS0_FLAGS_MNG_SES_ENCLOSURE
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI26_ENCLS0_FLAGS_MNG_IOC_GPIO
value|(0x0005)
end_define

begin_comment
comment|/**************************************************************************** *   Log Config Page ****************************************************************************/
end_comment

begin_comment
comment|/* Log Page 0 */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumLogEntries at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_LOG_0_NUM_LOG_ENTRIES
end_ifndef

begin_define
define|#
directive|define
name|MPI2_LOG_0_NUM_LOG_ENTRIES
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MPI2_LOG_0_LOG_DATA_LENGTH
value|(0x1C)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_LOG_0_ENTRY
block|{
name|U64
name|TimeStamp
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U16
name|LogSequence
decl_stmt|;
comment|/* 0x0C */
name|U16
name|LogEntryQualifier
decl_stmt|;
comment|/* 0x0E */
name|U8
name|VP_ID
decl_stmt|;
comment|/* 0x10 */
name|U8
name|VF_ID
decl_stmt|;
comment|/* 0x11 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x12 */
name|U8
name|LogData
index|[
name|MPI2_LOG_0_LOG_DATA_LENGTH
index|]
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_LOG_0_ENTRY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_LOG_0_ENTRY
operator|,
name|Mpi2Log0Entry_t
operator|,
name|MPI2_POINTER
name|pMpi2Log0Entry_t
typedef|;
end_typedef

begin_comment
comment|/* values for Log Page 0 LogEntry LogEntryQualifier field */
end_comment

begin_define
define|#
directive|define
name|MPI2_LOG_0_ENTRY_QUAL_ENTRY_UNUSED
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI2_LOG_0_ENTRY_QUAL_POWER_ON_RESET
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI2_LOG_0_ENTRY_QUAL_TIMESTAMP_UPDATE
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_LOG_0_ENTRY_QUAL_MIN_IMPLEMENT_SPEC
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|MPI2_LOG_0_ENTRY_QUAL_MAX_IMPLEMENT_SPEC
value|(0xFFFF)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_LOG_0
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x0C */
name|U16
name|NumLogEntries
decl_stmt|;
comment|/* 0x10 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x12 */
name|MPI2_LOG_0_ENTRY
name|LogEntry
index|[
name|MPI2_LOG_0_NUM_LOG_ENTRIES
index|]
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI2_CONFIG_PAGE_LOG_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_LOG_0
operator|,
name|Mpi2LogPage0_t
operator|,
name|MPI2_POINTER
name|pMpi2LogPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_LOG_0_PAGEVERSION
value|(0x02)
end_define

begin_comment
comment|/**************************************************************************** *   RAID Config Page ****************************************************************************/
end_comment

begin_comment
comment|/* RAID Page 0 */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumElements at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_RAIDCONFIG0_MAX_ELEMENTS
end_ifndef

begin_define
define|#
directive|define
name|MPI2_RAIDCONFIG0_MAX_ELEMENTS
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_RAIDCONFIG0_CONFIG_ELEMENT
block|{
name|U16
name|ElementFlags
decl_stmt|;
comment|/* 0x00 */
name|U16
name|VolDevHandle
decl_stmt|;
comment|/* 0x02 */
name|U8
name|HotSparePool
decl_stmt|;
comment|/* 0x04 */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 0x05 */
name|U16
name|PhysDiskDevHandle
decl_stmt|;
comment|/* 0x06 */
block|}
name|MPI2_RAIDCONFIG0_CONFIG_ELEMENT
operator|,
name|MPI2_POINTER
name|PTR_MPI2_RAIDCONFIG0_CONFIG_ELEMENT
operator|,
name|Mpi2RaidConfig0ConfigElement_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidConfig0ConfigElement_t
typedef|;
end_typedef

begin_comment
comment|/* values for the ElementFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAIDCONFIG0_EFLAGS_MASK_ELEMENT_TYPE
value|(0x000F)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDCONFIG0_EFLAGS_VOLUME_ELEMENT
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDCONFIG0_EFLAGS_VOL_PHYS_DISK_ELEMENT
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDCONFIG0_EFLAGS_HOT_SPARE_ELEMENT
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI2_RAIDCONFIG0_EFLAGS_OCE_ELEMENT
value|(0x0003)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_RAID_CONFIGURATION_0
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|NumHotSpares
decl_stmt|;
comment|/* 0x08 */
name|U8
name|NumPhysDisks
decl_stmt|;
comment|/* 0x09 */
name|U8
name|NumVolumes
decl_stmt|;
comment|/* 0x0A */
name|U8
name|ConfigNum
decl_stmt|;
comment|/* 0x0B */
name|U32
name|Flags
decl_stmt|;
comment|/* 0x0C */
name|U8
name|ConfigGUID
index|[
literal|24
index|]
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x28 */
name|U8
name|NumElements
decl_stmt|;
comment|/* 0x2C */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x2D */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x2E */
name|MPI2_RAIDCONFIG0_CONFIG_ELEMENT
name|ConfigElement
index|[
name|MPI2_RAIDCONFIG0_MAX_ELEMENTS
index|]
decl_stmt|;
comment|/* 0x30 */
block|}
name|MPI2_CONFIG_PAGE_RAID_CONFIGURATION_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_RAID_CONFIGURATION_0
operator|,
name|Mpi2RaidConfigurationPage0_t
operator|,
name|MPI2_POINTER
name|pMpi2RaidConfigurationPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_RAIDCONFIG0_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* values for RAID Configuration Page 0 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_RAIDCONFIG0_FLAG_FOREIGN_CONFIG
value|(0x00000001)
end_define

begin_comment
comment|/**************************************************************************** *   Driver Persistent Mapping Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* Driver Persistent Mapping Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_DRIVER_MAP0_ENTRY
block|{
name|U64
name|PhysicalIdentifier
decl_stmt|;
comment|/* 0x00 */
name|U16
name|MappingInformation
decl_stmt|;
comment|/* 0x08 */
name|U16
name|DeviceIndex
decl_stmt|;
comment|/* 0x0A */
name|U32
name|PhysicalBitsMapping
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI2_CONFIG_PAGE_DRIVER_MAP0_ENTRY
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_DRIVER_MAP0_ENTRY
operator|,
name|Mpi2DriverMap0Entry_t
operator|,
name|MPI2_POINTER
name|pMpi2DriverMap0Entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_DRIVER_MAPPING_0
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|MPI2_CONFIG_PAGE_DRIVER_MAP0_ENTRY
name|Entry
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_CONFIG_PAGE_DRIVER_MAPPING_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_DRIVER_MAPPING_0
operator|,
name|Mpi2DriverMappingPage0_t
operator|,
name|MPI2_POINTER
name|pMpi2DriverMappingPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_DRIVERMAPPING0_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* values for Driver Persistent Mapping Page 0 MappingInformation field */
end_comment

begin_define
define|#
directive|define
name|MPI2_DRVMAP0_MAPINFO_SLOT_MASK
value|(0x07F0)
end_define

begin_define
define|#
directive|define
name|MPI2_DRVMAP0_MAPINFO_SLOT_SHIFT
value|(4)
end_define

begin_define
define|#
directive|define
name|MPI2_DRVMAP0_MAPINFO_MISSING_MASK
value|(0x000F)
end_define

begin_comment
comment|/**************************************************************************** *   Ethernet Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* Ethernet Page 0 */
end_comment

begin_comment
comment|/* IP address (union of IPv4 and IPv6) */
end_comment

begin_typedef
typedef|typedef
union|union
name|_MPI2_ETHERNET_IP_ADDR
block|{
name|U32
name|IPv4Addr
decl_stmt|;
name|U32
name|IPv6Addr
index|[
literal|4
index|]
decl_stmt|;
block|}
name|MPI2_ETHERNET_IP_ADDR
operator|,
name|MPI2_POINTER
name|PTR_MPI2_ETHERNET_IP_ADDR
operator|,
name|Mpi2EthernetIpAddr_t
operator|,
name|MPI2_POINTER
name|pMpi2EthernetIpAddr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_ETHERNET_HOST_NAME_LENGTH
value|(32)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_ETHERNET_0
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|NumInterfaces
decl_stmt|;
comment|/* 0x08 */
name|U8
name|Reserved0
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x0A */
name|U32
name|Status
decl_stmt|;
comment|/* 0x0C */
name|U8
name|MediaState
decl_stmt|;
comment|/* 0x10 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x11 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x12 */
name|U8
name|MacAddress
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x14 */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 0x1A */
name|U8
name|Reserved5
decl_stmt|;
comment|/* 0x1B */
name|MPI2_ETHERNET_IP_ADDR
name|IpAddress
decl_stmt|;
comment|/* 0x1C */
name|MPI2_ETHERNET_IP_ADDR
name|SubnetMask
decl_stmt|;
comment|/* 0x2C */
name|MPI2_ETHERNET_IP_ADDR
name|GatewayIpAddress
decl_stmt|;
comment|/* 0x3C */
name|MPI2_ETHERNET_IP_ADDR
name|DNS1IpAddress
decl_stmt|;
comment|/* 0x4C */
name|MPI2_ETHERNET_IP_ADDR
name|DNS2IpAddress
decl_stmt|;
comment|/* 0x5C */
name|MPI2_ETHERNET_IP_ADDR
name|DhcpIpAddress
decl_stmt|;
comment|/* 0x6C */
name|U8
name|HostName
index|[
name|MPI2_ETHERNET_HOST_NAME_LENGTH
index|]
decl_stmt|;
comment|/* 0x7C */
block|}
name|MPI2_CONFIG_PAGE_ETHERNET_0
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_ETHERNET_0
operator|,
name|Mpi2EthernetPage0_t
operator|,
name|MPI2_POINTER
name|pMpi2EthernetPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_ETHERNETPAGE0_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* values for Ethernet Page 0 Status field */
end_comment

begin_define
define|#
directive|define
name|MPI2_ETHPG0_STATUS_IPV6_CAPABLE
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_STATUS_IPV4_CAPABLE
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_STATUS_CONSOLE_CONNECTED
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_STATUS_DEFAULT_IF
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_STATUS_FW_DWNLD_ENABLED
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_STATUS_TELNET_ENABLED
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_STATUS_SSH2_ENABLED
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_STATUS_DHCP_CLIENT_ENABLED
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_STATUS_IPV6_ENABLED
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_STATUS_IPV4_ENABLED
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_STATUS_IPV6_ADDRESSES
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_STATUS_ETH_IF_ENABLED
value|(0x00000001)
end_define

begin_comment
comment|/* values for Ethernet Page 0 MediaState field */
end_comment

begin_define
define|#
directive|define
name|MPI2_ETHPG0_MS_DUPLEX_MASK
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_MS_HALF_DUPLEX
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_MS_FULL_DUPLEX
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_MS_CONNECT_SPEED_MASK
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_MS_NOT_CONNECTED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_MS_10MBIT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_MS_100MBIT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG0_MS_1GBIT
value|(0x03)
end_define

begin_comment
comment|/* Ethernet Page 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_ETHERNET_1
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved0
decl_stmt|;
comment|/* 0x08 */
name|U32
name|Flags
decl_stmt|;
comment|/* 0x0C */
name|U8
name|MediaState
decl_stmt|;
comment|/* 0x10 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x11 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x12 */
name|U8
name|MacAddress
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x14 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x1A */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 0x1B */
name|MPI2_ETHERNET_IP_ADDR
name|StaticIpAddress
decl_stmt|;
comment|/* 0x1C */
name|MPI2_ETHERNET_IP_ADDR
name|StaticSubnetMask
decl_stmt|;
comment|/* 0x2C */
name|MPI2_ETHERNET_IP_ADDR
name|StaticGatewayIpAddress
decl_stmt|;
comment|/* 0x3C */
name|MPI2_ETHERNET_IP_ADDR
name|StaticDNS1IpAddress
decl_stmt|;
comment|/* 0x4C */
name|MPI2_ETHERNET_IP_ADDR
name|StaticDNS2IpAddress
decl_stmt|;
comment|/* 0x5C */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x6C */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x70 */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 0x74 */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 0x78 */
name|U8
name|HostName
index|[
name|MPI2_ETHERNET_HOST_NAME_LENGTH
index|]
decl_stmt|;
comment|/* 0x7C */
block|}
name|MPI2_CONFIG_PAGE_ETHERNET_1
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_ETHERNET_1
operator|,
name|Mpi2EthernetPage1_t
operator|,
name|MPI2_POINTER
name|pMpi2EthernetPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI2_ETHERNETPAGE1_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* values for Ethernet Page 1 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI2_ETHPG1_FLAG_SET_DEFAULT_IF
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_FLAG_ENABLE_FW_DOWNLOAD
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_FLAG_ENABLE_TELNET
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_FLAG_ENABLE_SSH2
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_FLAG_ENABLE_DHCP_CLIENT
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_FLAG_ENABLE_IPV6
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_FLAG_ENABLE_IPV4
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_FLAG_USE_IPV6_ADDRESSES
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_FLAG_ENABLE_ETH_IF
value|(0x00000001)
end_define

begin_comment
comment|/* values for Ethernet Page 1 MediaState field */
end_comment

begin_define
define|#
directive|define
name|MPI2_ETHPG1_MS_DUPLEX_MASK
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_MS_HALF_DUPLEX
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_MS_FULL_DUPLEX
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_MS_DATA_RATE_MASK
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_MS_DATA_RATE_AUTO
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_MS_DATA_RATE_10MBIT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_MS_DATA_RATE_100MBIT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI2_ETHPG1_MS_DATA_RATE_1GBIT
value|(0x03)
end_define

begin_comment
comment|/**************************************************************************** *   Extended Manufacturing Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/*  * Generic structure to use for product-specific extended manufacturing pages  * (currently Extended Manufacturing Page 40 through Extended Manufacturing  * Page 60).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI2_CONFIG_PAGE_EXT_MAN_PS
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|ProductSpecificInfo
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI2_CONFIG_PAGE_EXT_MAN_PS
operator|,
name|MPI2_POINTER
name|PTR_MPI2_CONFIG_PAGE_EXT_MAN_PS
operator|,
name|Mpi2ExtManufacturingPagePS_t
operator|,
name|MPI2_POINTER
name|pMpi2ExtManufacturingPagePS_t
typedef|;
end_typedef

begin_comment
comment|/* PageVersion should be provided by product-specific code */
end_comment

begin_comment
comment|/**************************************************************************** *   values for fields used by several types of PCIe Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/* values for NegotiatedLinkRates fields */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIE_NEG_LINK_RATE_MASK_PHYSICAL
value|(0x0F)
end_define

begin_comment
comment|/* link rates used for Negotiated Physical Link Rate */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIE_NEG_LINK_RATE_UNKNOWN
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_NEG_LINK_RATE_PHY_DISABLED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_NEG_LINK_RATE_2_5
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_NEG_LINK_RATE_5_0
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_NEG_LINK_RATE_8_0
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIE_NEG_LINK_RATE_16_0
value|(0x05)
end_define

begin_comment
comment|/**************************************************************************** *   PCIe IO Unit Config Pages (MPI v2.6 and later) ****************************************************************************/
end_comment

begin_comment
comment|/* PCIe IO Unit Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_PCIE_IO_UNIT0_PHY_DATA
block|{
name|U8
name|Link
decl_stmt|;
comment|/* 0x00 */
name|U8
name|LinkFlags
decl_stmt|;
comment|/* 0x01 */
name|U8
name|PhyFlags
decl_stmt|;
comment|/* 0x02 */
name|U8
name|NegotiatedLinkRate
decl_stmt|;
comment|/* 0x03 */
name|U32
name|ControllerPhyDeviceInfo
decl_stmt|;
comment|/* 0x04 */
name|U16
name|AttachedDevHandle
decl_stmt|;
comment|/* 0x08 */
name|U16
name|ControllerDevHandle
decl_stmt|;
comment|/* 0x0A */
name|U32
name|EnumerationStatus
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI26_PCIE_IO_UNIT0_PHY_DATA
operator|,
name|MPI2_POINTER
name|PTR_MPI26_PCIE_IO_UNIT0_PHY_DATA
operator|,
name|Mpi26PCIeIOUnit0PhyData_t
operator|,
name|MPI2_POINTER
name|pMpi26PCIeIOUnit0PhyData_t
typedef|;
end_typedef

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumPhys at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI26_PCIE_IOUNIT0_PHY_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI26_PCIE_IOUNIT0_PHY_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_CONFIG_PAGE_PIOUNIT_0
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0x0C */
name|U8
name|InitStatus
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x0E */
name|MPI26_PCIE_IO_UNIT0_PHY_DATA
name|PhyData
index|[
name|MPI26_PCIE_IOUNIT0_PHY_MAX
index|]
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI26_CONFIG_PAGE_PIOUNIT_0
operator|,
name|MPI2_POINTER
name|PTR_MPI26_CONFIG_PAGE_PIOUNIT_0
operator|,
name|Mpi26PCIeIOUnitPage0_t
operator|,
name|MPI2_POINTER
name|pMpi26PCIeIOUnitPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNITPAGE0_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* values for PCIe IO Unit Page 0 LinkFlags */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT0_LINKFLAGS_ENUMERATION_IN_PROGRESS
value|(0x08)
end_define

begin_comment
comment|/* values for PCIe IO Unit Page 0 PhyFlags */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT0_PHYFLAGS_PHY_DISABLED
value|(0x08)
end_define

begin_comment
comment|/* use MPI26_PCIE_NEG_LINK_RATE_ defines for the NegotiatedLinkRate field */
end_comment

begin_comment
comment|/* see mpi2_pci.h for values for PCIe IO Unit Page 0 ControllerPhyDeviceInfo values */
end_comment

begin_comment
comment|/* values for PCIe IO Unit Page 0 EnumerationStatus */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT0_ES_MAX_SWITCHES_EXCEEDED
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT0_ES_MAX_DEVICES_EXCEEDED
value|(0x20000000)
end_define

begin_comment
comment|/* PCIe IO Unit Page 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_PCIE_IO_UNIT1_PHY_DATA
block|{
name|U8
name|Link
decl_stmt|;
comment|/* 0x00 */
name|U8
name|LinkFlags
decl_stmt|;
comment|/* 0x01 */
name|U8
name|PhyFlags
decl_stmt|;
comment|/* 0x02 */
name|U8
name|MaxMinLinkRate
decl_stmt|;
comment|/* 0x03 */
name|U32
name|ControllerPhyDeviceInfo
decl_stmt|;
comment|/* 0x04 */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0x08 */
block|}
name|MPI26_PCIE_IO_UNIT1_PHY_DATA
operator|,
name|MPI2_POINTER
name|PTR_MPI26_PCIE_IO_UNIT1_PHY_DATA
operator|,
name|Mpi26PCIeIOUnit1PhyData_t
operator|,
name|MPI2_POINTER
name|pMpi26PCIeIOUnit1PhyData_t
typedef|;
end_typedef

begin_comment
comment|/* values for LinkFlags */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT1_LINKFLAGS_DIS_SRIS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT1_LINKFLAGS_EN_SRIS
value|(0x01)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumPhys at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI26_PCIE_IOUNIT1_PHY_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI26_PCIE_IOUNIT1_PHY_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_CONFIG_PAGE_PIOUNIT_1
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U16
name|ControlFlags
decl_stmt|;
comment|/* 0x08 */
name|U16
name|Reserved
decl_stmt|;
comment|/* 0x0A */
name|U16
name|AdditionalControlFlags
decl_stmt|;
comment|/* 0x0C */
name|U16
name|NVMeMaxQueueDepth
decl_stmt|;
comment|/* 0x0E */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0x10 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x11 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x12 */
name|MPI26_PCIE_IO_UNIT1_PHY_DATA
name|PhyData
index|[
name|MPI26_PCIE_IOUNIT1_PHY_MAX
index|]
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI26_CONFIG_PAGE_PIOUNIT_1
operator|,
name|MPI2_POINTER
name|PTR_MPI26_CONFIG_PAGE_PIOUNIT_1
operator|,
name|Mpi26PCIeIOUnitPage1_t
operator|,
name|MPI2_POINTER
name|pMpi26PCIeIOUnitPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNITPAGE1_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* values for PCIe IO Unit Page 1 PhyFlags */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT1_PHYFLAGS_PHY_DISABLE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT1_PHYFLAGS_ENDPOINT_ONLY
value|(0x01)
end_define

begin_comment
comment|/* values for PCIe IO Unit Page 1 MaxMinLinkRate */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT1_MAX_RATE_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT1_MAX_RATE_SHIFT
value|(4)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT1_MAX_RATE_2_5
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT1_MAX_RATE_5_0
value|(0x30)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT1_MAX_RATE_8_0
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEIOUNIT1_MAX_RATE_16_0
value|(0x50)
end_define

begin_comment
comment|/* see mpi2_pci.h for values for PCIe IO Unit Page 0 ControllerPhyDeviceInfo values */
end_comment

begin_comment
comment|/**************************************************************************** *   PCIe Switch Config Pages (MPI v2.6 and later) ****************************************************************************/
end_comment

begin_comment
comment|/* PCIe Switch Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_CONFIG_PAGE_PSWITCH_0
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x08 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x0C */
name|U16
name|ParentDevHandle
decl_stmt|;
comment|/* 0x0E */
name|U8
name|NumPorts
decl_stmt|;
comment|/* 0x10 */
name|U8
name|PCIeLevel
decl_stmt|;
comment|/* 0x11 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x12 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x14 */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x18 */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 0x1C */
block|}
name|MPI26_CONFIG_PAGE_PSWITCH_0
operator|,
name|MPI2_POINTER
name|PTR_MPI26_CONFIG_PAGE_PSWITCH_0
operator|,
name|Mpi26PCIeSwitchPage0_t
operator|,
name|MPI2_POINTER
name|pMpi26PCIeSwitchPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI26_PCIESWITCH0_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* PCIe Switch Page 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_CONFIG_PAGE_PSWITCH_1
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x08 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U8
name|NumPorts
decl_stmt|;
comment|/* 0x0C */
name|U8
name|PortNum
decl_stmt|;
comment|/* 0x0D */
name|U16
name|AttachedDevHandle
decl_stmt|;
comment|/* 0x0E */
name|U16
name|SwitchDevHandle
decl_stmt|;
comment|/* 0x10 */
name|U8
name|NegotiatedPortWidth
decl_stmt|;
comment|/* 0x12 */
name|U8
name|NegotiatedLinkRate
decl_stmt|;
comment|/* 0x13 */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x14 */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x18 */
block|}
name|MPI26_CONFIG_PAGE_PSWITCH_1
operator|,
name|MPI2_POINTER
name|PTR_MPI26_CONFIG_PAGE_PSWITCH_1
operator|,
name|Mpi26PCIeSwitchPage1_t
operator|,
name|MPI2_POINTER
name|pMpi26PCIeSwitchPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI26_PCIESWITCH1_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* use MPI26_PCIE_NEG_LINK_RATE_ defines for the NegotiatedLinkRate field */
end_comment

begin_comment
comment|/**************************************************************************** *   PCIe Device Config Pages (MPI v2.6 and later) ****************************************************************************/
end_comment

begin_comment
comment|/* PCIe Device Page 0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_CONFIG_PAGE_PCIEDEV_0
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U16
name|Slot
decl_stmt|;
comment|/* 0x08 */
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 0x0A */
name|U64
name|WWID
decl_stmt|;
comment|/* 0x0C */
name|U16
name|ParentDevHandle
decl_stmt|;
comment|/* 0x14 */
name|U8
name|PortNum
decl_stmt|;
comment|/* 0x16 */
name|U8
name|AccessStatus
decl_stmt|;
comment|/* 0x17 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x18 */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 0x1A */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x1B */
name|U32
name|DeviceInfo
decl_stmt|;
comment|/* 0x1C */
name|U32
name|Flags
decl_stmt|;
comment|/* 0x20 */
name|U8
name|SupportedLinkRates
decl_stmt|;
comment|/* 0x24 */
name|U8
name|MaxPortWidth
decl_stmt|;
comment|/* 0x25 */
name|U8
name|NegotiatedPortWidth
decl_stmt|;
comment|/* 0x26 */
name|U8
name|NegotiatedLinkRate
decl_stmt|;
comment|/* 0x27 */
name|U8
name|EnclosureLevel
decl_stmt|;
comment|/* 0x28 */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0x29 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x2A */
name|U8
name|ConnectorName
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x2C */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0x30 */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 0x34 */
block|}
name|MPI26_CONFIG_PAGE_PCIEDEV_0
operator|,
name|MPI2_POINTER
name|PTR_MPI26_CONFIG_PAGE_PCIEDEV_0
operator|,
name|Mpi26PCIeDevicePage0_t
operator|,
name|MPI2_POINTER
name|pMpi26PCIeDevicePage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI26_PCIEDEVICE0_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/* values for PCIe Device Page 0 AccessStatus field */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_NO_ERRORS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_NEEDS_INITIALIZATION
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_CAPABILITY_FAILED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_DEVICE_BLOCKED
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_MEMORY_SPACE_ACCESS_FAILED
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_UNSUPPORTED_DEVICE
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_MSIX_REQUIRED
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_UNKNOWN
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_NVME_READY_TIMEOUT
value|(0x30)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_NVME_DEVCFG_UNSUPPORTED
value|(0x31)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_NVME_IDENTIFY_FAILED
value|(0x32)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_NVME_QCONFIG_FAILED
value|(0x33)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_NVME_QCREATION_FAILED
value|(0x34)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_NVME_EVENTCFG_FAILED
value|(0x35)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_NVME_GET_FEATURE_STAT_FAILED
value|(0x36)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_NVME_IDLE_TIMEOUT
value|(0x37)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_NVME_FAILURE_STATUS
value|(0x38)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_ASTATUS_INIT_FAIL_MAX
value|(0x3F)
end_define

begin_comment
comment|/* see mpi2_pci.h for the MPI26_PCIE_DEVINFO_ defines used for the DeviceInfo field */
end_comment

begin_comment
comment|/* values for PCIe Device Page 0 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_FLAGS_UNAUTHORIZED_DEVICE
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_FLAGS_ENABLED_FAST_PATH
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_FLAGS_FAST_PATH_CAPABLE
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_FLAGS_ASYNCHRONOUS_NOTIFICATION
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_FLAGS_ATA_SW_PRESERVATION
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_FLAGS_UNSUPPORTED_DEVICE
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_FLAGS_ATA_48BIT_LBA_SUPPORTED
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_FLAGS_ATA_SMART_SUPPORTED
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_FLAGS_ATA_NCQ_SUPPORTED
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_FLAGS_ATA_FUA_SUPPORTED
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_FLAGS_ENCL_LEVEL_VALID
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_FLAGS_DEVICE_PRESENT
value|(0x0001)
end_define

begin_comment
comment|/* values for PCIe Device Page 0 SupportedLinkRates field */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_LINK_RATE_16_0_SUPPORTED
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_LINK_RATE_8_0_SUPPORTED
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_LINK_RATE_5_0_SUPPORTED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV0_LINK_RATE_2_5_SUPPORTED
value|(0x01)
end_define

begin_comment
comment|/* use MPI26_PCIE_NEG_LINK_RATE_ defines for the NegotiatedLinkRate field */
end_comment

begin_comment
comment|/* PCIe Device Page 2 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_CONFIG_PAGE_PCIEDEV_2
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 0x08 */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0x0A */
name|U32
name|MaximumDataTransferSize
decl_stmt|;
comment|/* 0x0C */
name|U32
name|Capabilities
decl_stmt|;
comment|/* 0x10 */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0x14 */
block|}
name|MPI26_CONFIG_PAGE_PCIEDEV_2
operator|,
name|MPI2_POINTER
name|PTR_MPI26_CONFIG_PAGE_PCIEDEV_2
operator|,
name|Mpi26PCIeDevicePage2_t
operator|,
name|MPI2_POINTER
name|pMpi26PCIeDevicePage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI26_PCIEDEVICE2_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* defines for PCIe Device Page 2 Capabilities field */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIEDEV2_CAP_SGL_FORMAT
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV2_CAP_BIT_BUCKET_SUPPORT
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIEDEV2_CAP_SGL_SUPPORT
value|(0x00000001)
end_define

begin_comment
comment|/**************************************************************************** *   PCIe Link Config Pages (MPI v2.6 and later) ****************************************************************************/
end_comment

begin_comment
comment|/* PCIe Link Page 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_CONFIG_PAGE_PCIELINK_1
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Link
decl_stmt|;
comment|/* 0x08 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U32
name|CorrectableErrorCount
decl_stmt|;
comment|/* 0x0C */
name|U16
name|NonFatalErrorCount
decl_stmt|;
comment|/* 0x10 */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0x12 */
name|U16
name|FatalErrorCount
decl_stmt|;
comment|/* 0x14 */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x16 */
block|}
name|MPI26_CONFIG_PAGE_PCIELINK_1
operator|,
name|MPI2_POINTER
name|PTR_MPI26_CONFIG_PAGE_PCIELINK_1
operator|,
name|Mpi26PcieLinkPage1_t
operator|,
name|MPI2_POINTER
name|pMpi26PcieLinkPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI26_PCIELINK1_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* PCIe Link Page 2 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_PCIELINK2_LINK_EVENT
block|{
name|U8
name|LinkEventCode
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
name|U32
name|LinkEventInfo
decl_stmt|;
comment|/* 0x04 */
block|}
name|MPI26_PCIELINK2_LINK_EVENT
operator|,
name|MPI2_POINTER
name|PTR_MPI26_PCIELINK2_LINK_EVENT
operator|,
name|Mpi26PcieLink2LinkEvent_t
operator|,
name|MPI2_POINTER
name|pMpi26PcieLink2LinkEvent_t
typedef|;
end_typedef

begin_comment
comment|/* use MPI26_PCIELINK3_EVTCODE_ for the LinkEventCode field */
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumLinkEvents at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI26_PCIELINK2_LINK_EVENT_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI26_PCIELINK2_LINK_EVENT_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_CONFIG_PAGE_PCIELINK_2
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Link
decl_stmt|;
comment|/* 0x08 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U8
name|NumLinkEvents
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x0E */
name|MPI26_PCIELINK2_LINK_EVENT
name|LinkEvent
index|[
name|MPI26_PCIELINK2_LINK_EVENT_MAX
index|]
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI26_CONFIG_PAGE_PCIELINK_2
operator|,
name|MPI2_POINTER
name|PTR_MPI26_CONFIG_PAGE_PCIELINK_2
operator|,
name|Mpi26PcieLinkPage2_t
operator|,
name|MPI2_POINTER
name|pMpi26PcieLinkPage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI26_PCIELINK2_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/* PCIe Link Page 3 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_PCIELINK3_LINK_EVENT_CONFIG
block|{
name|U8
name|LinkEventCode
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x01 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x02 */
name|U8
name|CounterType
decl_stmt|;
comment|/* 0x04 */
name|U8
name|ThresholdWindow
decl_stmt|;
comment|/* 0x05 */
name|U8
name|TimeUnits
decl_stmt|;
comment|/* 0x06 */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x07 */
name|U32
name|EventThreshold
decl_stmt|;
comment|/* 0x08 */
name|U16
name|ThresholdFlags
decl_stmt|;
comment|/* 0x0C */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x0E */
block|}
name|MPI26_PCIELINK3_LINK_EVENT_CONFIG
operator|,
name|MPI2_POINTER
name|PTR_MPI26_PCIELINK3_LINK_EVENT_CONFIG
operator|,
name|Mpi26PcieLink3LinkEventConfig_t
operator|,
name|MPI2_POINTER
name|pMpi26PcieLink3LinkEventConfig_t
typedef|;
end_typedef

begin_comment
comment|/* values for LinkEventCode field */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_NO_EVENT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_CORRECTABLE_ERROR_RECEIVED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_NON_FATAL_ERROR_RECEIVED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_FATAL_ERROR_RECEIVED
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_DATA_LINK_ERROR_DETECTED
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_TRANSACTION_LAYER_ERROR_DETECTED
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_TLP_ECRC_ERROR_DETECTED
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_POISONED_TLP
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_RECEIVED_NAK_DLLP
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_SENT_NAK_DLLP
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_LTSSM_RECOVERY_STATE
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_LTSSM_RXL0S_STATE
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_LTSSM_TXL0S_STATE
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_LTSSM_L1_STATE
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_LTSSM_DISABLED_STATE
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_LTSSM_HOT_RESET_STATE
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_SYSTEM_ERROR
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_DECODE_ERROR
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_EVTCODE_DISPARITY_ERROR
value|(0x12)
end_define

begin_comment
comment|/* values for the CounterType field */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_COUNTER_TYPE_WRAPPING
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_COUNTER_TYPE_SATURATING
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_COUNTER_TYPE_PEAK_VALUE
value|(0x02)
end_define

begin_comment
comment|/* values for the TimeUnits field */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_TM_UNITS_10_MICROSECONDS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_TM_UNITS_100_MICROSECONDS
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_TM_UNITS_1_MILLISECOND
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_TM_UNITS_10_MILLISECONDS
value|(0x03)
end_define

begin_comment
comment|/* values for the ThresholdFlags field */
end_comment

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_TFLAGS_EVENT_NOTIFY
value|(0x0001)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check the value returned for NumLinkEvents at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI26_PCIELINK3_LINK_EVENT_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_LINK_EVENT_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_MPI26_CONFIG_PAGE_PCIELINK_3
block|{
name|MPI2_CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 0x00 */
name|U8
name|Link
decl_stmt|;
comment|/* 0x08 */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0x09 */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0x0A */
name|U8
name|NumLinkEvents
decl_stmt|;
comment|/* 0x0C */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 0x0D */
name|U16
name|Reserved4
decl_stmt|;
comment|/* 0x0E */
name|MPI26_PCIELINK3_LINK_EVENT_CONFIG
name|LinkEventConfig
index|[
name|MPI26_PCIELINK3_LINK_EVENT_MAX
index|]
decl_stmt|;
comment|/* 0x10 */
block|}
name|MPI26_CONFIG_PAGE_PCIELINK_3
operator|,
name|MPI2_POINTER
name|PTR_MPI26_CONFIG_PAGE_PCIELINK_3
operator|,
name|Mpi26PcieLinkPage3_t
operator|,
name|MPI2_POINTER
name|pMpi26PcieLinkPage3_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI26_PCIELINK3_PAGEVERSION
value|(0x00)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

