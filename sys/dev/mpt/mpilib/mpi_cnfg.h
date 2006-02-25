begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *           Name:  mpi_cnfg.h  *          Title:  MPI Config message, structures, and Pages  *  Creation Date:  July 27, 2000  *  *    mpi_cnfg.h Version:  01.05.11  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  05-08-00  00.10.01  Original release for 0.10 spec dated 4/26/2000.  *  06-06-00  01.00.01  Update version number for 1.0 release.  *  06-08-00  01.00.02  Added _PAGEVERSION definitions for all pages.  *                      Added FcPhLowestVersion, FcPhHighestVersion, Reserved2  *                      fields to FC_DEVICE_0 page, updated the page version.  *                      Changed _FREE_RUNNING_CLOCK to _PACING_TRANSFERS in  *                      SCSI_PORT_0, SCSI_DEVICE_0 and SCSI_DEVICE_1 pages  *                      and updated the page versions.  *                      Added _RESPONSE_ID_MASK definition to SCSI_PORT_1  *                      page and updated the page version.  *                      Added Information field and _INFO_PARAMS_NEGOTIATED  *                      definitionto SCSI_DEVICE_0 page.  *  06-22-00  01.00.03  Removed batch controls from LAN_0 page and updated the  *                      page version.  *                      Added BucketsRemaining to LAN_1 page, redefined the  *                      state values, and updated the page version.  *                      Revised bus width definitions in SCSI_PORT_0,  *                      SCSI_DEVICE_0 and SCSI_DEVICE_1 pages.  *  06-30-00  01.00.04  Added MaxReplySize to LAN_1 page and updated the page  *                      version.  *                      Moved FC_DEVICE_0 PageAddress description to spec.  *  07-27-00  01.00.05  Corrected the SubsystemVendorID and SubsystemID field  *                      widths in IOC_0 page and updated the page version.  *  11-02-00  01.01.01  Original release for post 1.0 work  *                      Added Manufacturing pages, IO Unit Page 2, SCSI SPI  *                      Port Page 2, FC Port Page 4, FC Port Page 5  *  11-15-00  01.01.02  Interim changes to match proposals  *  12-04-00  01.01.03  Config page changes to match MPI rev 1.00.01.  *  12-05-00  01.01.04  Modified config page actions.  *  01-09-01  01.01.05  Added defines for page address formats.  *                      Data size for Manufacturing pages 2 and 3 no longer  *                      defined here.  *                      Io Unit Page 2 size is fixed at 4 adapters and some  *                      flags were changed.  *                      SCSI Port Page 2 Device Settings modified.  *                      New fields added to FC Port Page 0 and some flags  *                      cleaned up.  *                      Removed impedance flash from FC Port Page 1.  *                      Added FC Port pages 6 and 7.  *  01-25-01  01.01.06  Added MaxInitiators field to FcPortPage0.  *  01-29-01  01.01.07  Changed some defines to make them 32 character unique.  *                      Added some LinkType defines for FcPortPage0.  *  02-20-01  01.01.08  Started using MPI_POINTER.  *  02-27-01  01.01.09  Replaced MPI_CONFIG_PAGETYPE_SCSI_LUN with  *                      MPI_CONFIG_PAGETYPE_RAID_VOLUME.  *                      Added definitions and structures for IOC Page 2 and  *                      RAID Volume Page 2.  *  03-27-01  01.01.10  Added CONFIG_PAGE_FC_PORT_8 and CONFIG_PAGE_FC_PORT_9.  *                      CONFIG_PAGE_FC_PORT_3 now supports persistent by DID.  *                      Added VendorId and ProductRevLevel fields to  *                      RAIDVOL2_IM_PHYS_ID struct.  *                      Modified values for MPI_FCPORTPAGE0_FLAGS_ATTACH_  *                      defines to make them compatible to MPI version 1.0.  *                      Added structure offset comments.  *  04-09-01  01.01.11  Added some new defines for the PageAddress field and  *                      removed some obsolete ones.  *                      Added IO Unit Page 3.  *                      Modified defines for Scsi Port Page 2.  *                      Modified RAID Volume Pages.  *  08-08-01  01.02.01  Original release for v1.2 work.  *                      Added SepID and SepBus to RVP2 IMPhysicalDisk struct.  *                      Added defines for the SEP bits in RVP2 VolumeSettings.  *                      Modified the DeviceSettings field in RVP2 to use the  *                      proper structure.  *                      Added defines for SES, SAF-TE, and cross channel for  *                      IOCPage2 CapabilitiesFlags.  *                      Removed define for MPI_IOUNITPAGE2_FLAGS_RAID_DISABLE.  *                      Removed define for  *                      MPI_SCSIPORTPAGE2_PORT_FLAGS_PARITY_ENABLE.  *                      Added define for MPI_CONFIG_PAGEATTR_RO_PERSISTENT.  *  08-29-01 01.02.02   Fixed value for MPI_MANUFACTPAGE_DEVID_53C1035.  *                      Added defines for MPI_FCPORTPAGE1_FLAGS_HARD_ALPA_ONLY  *                      and MPI_FCPORTPAGE1_FLAGS_IMMEDIATE_ERROR_REPLY.  *                      Removed MPI_SCSIPORTPAGE0_CAP_PACING_TRANSFERS,  *                      MPI_SCSIDEVPAGE0_NP_PACING_TRANSFERS, and  *                      MPI_SCSIDEVPAGE1_RP_PACING_TRANSFERS, and  *                      MPI_SCSIDEVPAGE1_CONF_PPR_ALLOWED.  *                      Added defines for MPI_SCSIDEVPAGE1_CONF_WDTR_DISALLOWED  *                      and MPI_SCSIDEVPAGE1_CONF_SDTR_DISALLOWED.  *                      Added OnBusTimerValue to CONFIG_PAGE_SCSI_PORT_1.  *                      Added rejected bits to SCSI Device Page 0 Information.  *                      Increased size of ALPA array in FC Port Page 2 by one  *                      and removed a one byte reserved field.  *  09-28-01 01.02.03   Swapped NegWireSpeedLow and NegWireSpeedLow in  *                      CONFIG_PAGE_LAN_1 to match preferred 64-bit ordering.  *                      Added structures for Manufacturing Page 4, IO Unit  *                      Page 3, IOC Page 3, IOC Page 4, RAID Volume Page 0, and  *                      RAID PhysDisk Page 0.  *  10-04-01 01.02.04   Added define for MPI_CONFIG_PAGETYPE_RAID_PHYSDISK.  *                      Modified some of the new defines to make them 32  *                      character unique.  *                      Modified how variable length pages (arrays) are defined.  *                      Added generic defines for hot spare pools and RAID  *                      volume types.  *  11-01-01 01.02.05   Added define for MPI_IOUNITPAGE1_DISABLE_IR.  *  03-14-02 01.02.06   Added PCISlotNum field to CONFIG_PAGE_IOC_1 along with  *                      related define, and bumped the page version define.  *  05-31-02 01.02.07   Added a Flags field to CONFIG_PAGE_IOC_2_RAID_VOL in a  *                      reserved byte and added a define.  *                      Added define for  *                      MPI_RAIDVOL0_STATUS_FLAG_VOLUME_INACTIVE.  *                      Added new config page: CONFIG_PAGE_IOC_5.  *                      Added MaxAliases, MaxHardAliases, and NumCurrentAliases  *                      fields to CONFIG_PAGE_FC_PORT_0.  *                      Added AltConnector and NumRequestedAliases fields to  *                      CONFIG_PAGE_FC_PORT_1.  *                      Added new config page: CONFIG_PAGE_FC_PORT_10.  *  07-12-02 01.02.08   Added more MPI_MANUFACTPAGE_DEVID_ defines.  *                      Added additional MPI_SCSIDEVPAGE0_NP_ defines.  *                      Added more MPI_SCSIDEVPAGE1_RP_ defines.  *                      Added define for  *                      MPI_SCSIDEVPAGE1_CONF_EXTENDED_PARAMS_ENABLE.  *                      Added new config page: CONFIG_PAGE_SCSI_DEVICE_3.  *                      Modified MPI_FCPORTPAGE5_FLAGS_ defines.  *  09-16-02 01.02.09   Added MPI_SCSIDEVPAGE1_CONF_FORCE_PPR_MSG define.  *  11-15-02 01.02.10   Added ConnectedID defines for CONFIG_PAGE_SCSI_PORT_0.  *                      Added more Flags defines for CONFIG_PAGE_FC_PORT_1.  *                      Added more Flags defines for CONFIG_PAGE_FC_DEVICE_0.  *  04-01-03 01.02.11   Added RR_TOV field and additional Flags defines for  *                      CONFIG_PAGE_FC_PORT_1.  *                      Added define MPI_FCPORTPAGE5_FLAGS_DISABLE to disable  *                      an alias.  *                      Added more device id defines.  *  06-26-03 01.02.12   Added MPI_IOUNITPAGE1_IR_USE_STATIC_VOLUME_ID define.  *                      Added TargetConfig and IDConfig fields to  *                      CONFIG_PAGE_SCSI_PORT_1.  *                      Added more PortFlags defines for CONFIG_PAGE_SCSI_PORT_2  *                      to control DV.  *                      Added more Flags defines for CONFIG_PAGE_FC_PORT_1.  *                      In CONFIG_PAGE_FC_DEVICE_0, replaced Reserved1 field  *                      with ADISCHardALPA.  *                      Added MPI_FC_DEVICE_PAGE0_PROT_FCP_RETRY define.  *  01-16-04 01.02.13   Added InitiatorDeviceTimeout and InitiatorIoPendTimeout  *                      fields and related defines to CONFIG_PAGE_FC_PORT_1.  *                      Added define for  *                      MPI_FCPORTPAGE1_FLAGS_SOFT_ALPA_FALLBACK.  *                      Added new fields to the substructures of  *                      CONFIG_PAGE_FC_PORT_10.  *  04-29-04 01.02.14   Added define for IDP bit for CONFIG_PAGE_SCSI_PORT_0,  *                      CONFIG_PAGE_SCSI_DEVICE_0, and  *                      CONFIG_PAGE_SCSI_DEVICE_1. Also bumped Page Version for  *                      these pages.  *  05-11-04 01.03.01   Added structure for CONFIG_PAGE_INBAND_0.  *  08-19-04 01.05.01   Modified MSG_CONFIG request to support extended config  *                      pages.  *                      Added a new structure for extended config page header.  *                      Added new extended config pages types and structures for  *                      SAS IO Unit, SAS Expander, SAS Device, and SAS PHY.  *                      Replaced a reserved byte in CONFIG_PAGE_MANUFACTURING_4  *                      to add a Flags field.  *                      Two new Manufacturing config pages (5 and 6).  *                      Two new bits defined for IO Unit Page 1 Flags field.  *                      Modified CONFIG_PAGE_IO_UNIT_2 to add three new fields  *                      to specify the BIOS boot device.  *                      Four new Flags bits defined for IO Unit Page 2.  *                      Added IO Unit Page 4.  *                      Added EEDP Flags settings to IOC Page 1.  *                      Added new BIOS Page 1 config page.  *  10-05-04 01.05.02   Added define for  *                      MPI_IOCPAGE1_INITIATOR_CONTEXT_REPLY_DISABLE.  *                      Added new Flags field to CONFIG_PAGE_MANUFACTURING_5 and  *                      associated defines.  *                      Added more defines for SAS IO Unit Page 0  *                      DiscoveryStatus field.  *                      Added define for MPI_SAS_IOUNIT0_DS_SUBTRACTIVE_LINK  *                      and MPI_SAS_IOUNIT0_DS_TABLE_LINK.  *                      Added defines for Physical Mapping Modes to SAS IO Unit  *                      Page 2.  *                      Added define for  *                      MPI_SAS_DEVICE0_FLAGS_PORT_SELECTOR_ATTACH.  *  10-27-04 01.05.03   Added defines for new SAS PHY page addressing mode.  *                      Added defines for MaxTargetSpinUp to BIOS Page 1.  *                      Added 5 new ControlFlags defines for SAS IO Unit  *                      Page 1.  *                      Added MaxNumPhysicalMappedIDs field to SAS IO Unit  *                      Page 2.  *                      Added AccessStatus field to SAS Device Page 0 and added  *                      new Flags bits for supported SATA features.  *  12-07-04  01.05.04  Added config page structures for BIOS Page 2, RAID  *                      Volume Page 1, and RAID Physical Disk Page 1.  *                      Replaced IO Unit Page 1 BootTargetID,BootBus, and  *                      BootAdapterNum with reserved field.  *                      Added DataScrubRate and ResyncRate to RAID Volume  *                      Page 0.  *                      Added MPI_SAS_IOUNIT2_FLAGS_RESERVE_ID_0_FOR_BOOT  *                      define.  *  12-09-04  01.05.05  Added Target Mode Large CDB Enable to FC Port Page 1  *                      Flags field.  *                      Added Auto Port Config flag define for SAS IOUNIT  *                      Page 1 ControlFlags.  *                      Added Disabled bad Phy define to Expander Page 1  *                      Discovery Info field.  *                      Added SAS/SATA device support to SAS IOUnit Page 1  *                      ControlFlags.  *                      Added Unsupported device to SAS Dev Page 0 Flags field  *                      Added disable use SATA Hash Address for SAS IOUNIT  *                      page 1 in ControlFields.  *  01-15-05  01.05.06  Added defaults for data scrub rate and resync rate to  *                      Manufacturing Page 4.  *                      Added new defines for BIOS Page 1 IOCSettings field.  *                      Added ExtDiskIdentifier field to RAID Physical Disk  *                      Page 0.  *                      Added new defines for SAS IO Unit Page 1 ControlFlags  *                      and to SAS Device Page 0 Flags to control SATA devices.  *                      Added defines and structures for the new Log Page 0, a  *                      new type of configuration page.  *  02-09-05  01.05.07  Added InactiveStatus field to RAID Volume Page 0.  *                      Added WWID field to RAID Volume Page 1.  *                      Added PhysicalPort field to SAS Expander pages 0 and 1.  *  03-11-05  01.05.08  Removed the EEDP flags from IOC Page 1.  *                      Added Enclosure/Slot boot device format to BIOS Page 2.  *                      New status value for RAID Volume Page 0 VolumeStatus  *                      (VolumeState subfield).  *                      New value for RAID Physical Page 0 InactiveStatus.  *                      Added Inactive Volume Member flag RAID Physical Disk  *                      Page 0 PhysDiskStatus field.  *                      New physical mapping mode in SAS IO Unit Page 2.  *                      Added CONFIG_PAGE_SAS_ENCLOSURE_0.  *                      Added Slot and Enclosure fields to SAS Device Page 0.  *  06-24-05  01.05.09  Added EEDP defines to IOC Page 1.  *                      Added more RAID type defines to IOC Page 2.  *                      Added Port Enable Delay settings to BIOS Page 1.  *                      Added Bad Block Table Full define to RAID Volume Page 0.  *                      Added Previous State defines to RAID Physical Disk  *                      Page 0.  *                      Added Max Sata Targets define for DiscoveryStatus field  *                      of SAS IO Unit Page 0.  *                      Added Device Self Test to Control Flags of SAS IO Unit  *                      Page 1.  *                      Added Direct Attach Starting Slot Number define for SAS  *                      IO Unit Page 2.  *                      Added new fields in SAS Device Page 2 for enclosure  *                      mapping.  *                      Added OwnerDevHandle and Flags field to SAS PHY Page 0.  *                      Added IOC GPIO Flags define to SAS Enclosure Page 0.  *                      Fixed the value for MPI_SAS_IOUNIT1_CONTROL_DEV_SATA_SUPPORT.  *  08-03-05  01.05.10  Removed ISDataScrubRate and ISResyncRate from  *                      Manufacturing Page 4.  *                      Added MPI_IOUNITPAGE1_SATA_WRITE_CACHE_DISABLE bit.  *                      Added NumDevsPerEnclosure field to SAS IO Unit page 2.  *                      Added MPI_SAS_IOUNIT2_FLAGS_HOST_ASSIGNED_PHYS_MAP  *                      define.  *                      Added EnclosureHandle field to SAS Expander page 0.  *                      Removed redundant NumTableEntriesProg field from SAS  *                      Expander Page 1.  *  08-30-05  01.05.11  Added DeviceID for FC949E and changed the DeviceID for  *                      SAS1078.  *                      Added more defines for Manufacturing Page 4 Flags field.  *                      Added more defines for IOCSettings and added  *                      ExpanderSpinup field to Bios Page 1.  *                      Added postpone SATA Init bit to SAS IO Unit Page 1  *                      ControlFlags.  *                      Changed LogEntry format for Log Page 0.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_CNFG_H
end_ifndef

begin_define
define|#
directive|define
name|MPI_CNFG_H
end_define

begin_comment
comment|/***************************************************************************** * *       C o n f i g    M e s s a g e    a n d    S t r u c t u r e s * *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_HEADER
block|{
name|U8
name|PageVersion
decl_stmt|;
comment|/* 00h */
name|U8
name|PageLength
decl_stmt|;
comment|/* 01h */
name|U8
name|PageNumber
decl_stmt|;
comment|/* 02h */
name|U8
name|PageType
decl_stmt|;
comment|/* 03h */
block|}
name|CONFIG_PAGE_HEADER
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_HEADER
operator|,
name|ConfigPageHeader_t
operator|,
name|MPI_POINTER
name|pConfigPageHeader_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_CONFIG_PAGE_HEADER_UNION
block|{
name|ConfigPageHeader_t
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
name|ConfigPageHeaderUnion
operator|,
name|MPI_POINTER
name|pConfigPageHeaderUnion
operator|,
name|CONFIG_PAGE_HEADER_UNION
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_HEADER_UNION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_EXTENDED_PAGE_HEADER
block|{
name|U8
name|PageVersion
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 01h */
name|U8
name|PageNumber
decl_stmt|;
comment|/* 02h */
name|U8
name|PageType
decl_stmt|;
comment|/* 03h */
name|U16
name|ExtPageLength
decl_stmt|;
comment|/* 04h */
name|U8
name|ExtPageType
decl_stmt|;
comment|/* 06h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 07h */
block|}
name|CONFIG_EXTENDED_PAGE_HEADER
operator|,
name|MPI_POINTER
name|PTR_CONFIG_EXTENDED_PAGE_HEADER
operator|,
name|ConfigExtendedPageHeader_t
operator|,
name|MPI_POINTER
name|pConfigExtendedPageHeader_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *   PageType field values ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGEATTR_READ_ONLY
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGEATTR_CHANGEABLE
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGEATTR_PERSISTENT
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGEATTR_RO_PERSISTENT
value|(0x30)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGEATTR_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_IO_UNIT
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_IOC
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_BIOS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_SCSI_PORT
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_SCSI_DEVICE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_FC_PORT
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_FC_DEVICE
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_LAN
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_RAID_VOLUME
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_MANUFACTURING
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_RAID_PHYSDISK
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_INBAND
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_EXTENDED
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_PAGETYPE_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_TYPENUM_MASK
value|(0x0FFF)
end_define

begin_comment
comment|/**************************************************************************** *   ExtPageType field values ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_CONFIG_EXTPAGETYPE_SAS_IO_UNIT
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_EXTPAGETYPE_SAS_EXPANDER
value|(0x11)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_EXTPAGETYPE_SAS_DEVICE
value|(0x12)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_EXTPAGETYPE_SAS_PHY
value|(0x13)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_EXTPAGETYPE_LOG
value|(0x14)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_EXTPAGETYPE_ENCLOSURE
value|(0x15)
end_define

begin_comment
comment|/**************************************************************************** *   PageAddress field values ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_SCSI_PORT_PGAD_PORT_MASK
value|(0x000000FF)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_DEVICE_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_DEVICE_FORM_BUS_TID
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_DEVICE_TARGET_ID_MASK
value|(0x000000FF)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_DEVICE_TARGET_ID_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_DEVICE_BUS_MASK
value|(0x0000FF00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_DEVICE_BUS_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_DEVICE_FORM_TARGET_MODE
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_DEVICE_TM_RESPOND_ID_MASK
value|(0x000000FF)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_DEVICE_TM_RESPOND_ID_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_DEVICE_TM_BUS_MASK
value|(0x0000FF00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_DEVICE_TM_BUS_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_DEVICE_TM_INIT_ID_MASK
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSI_DEVICE_TM_INIT_ID_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|MPI_FC_PORT_PGAD_PORT_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI_FC_PORT_PGAD_PORT_SHIFT
value|(28)
end_define

begin_define
define|#
directive|define
name|MPI_FC_PORT_PGAD_FORM_MASK
value|(0x0F000000)
end_define

begin_define
define|#
directive|define
name|MPI_FC_PORT_PGAD_FORM_INDEX
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI_FC_PORT_PGAD_INDEX_MASK
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_FC_PORT_PGAD_INDEX_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PGAD_PORT_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PGAD_PORT_SHIFT
value|(28)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PGAD_FORM_MASK
value|(0x0F000000)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PGAD_FORM_NEXT_DID
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PGAD_ND_PORT_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PGAD_ND_PORT_SHIFT
value|(28)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PGAD_ND_DID_MASK
value|(0x00FFFFFF)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PGAD_ND_DID_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PGAD_FORM_BUS_TID
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PGAD_BT_BUS_MASK
value|(0x0000FF00)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PGAD_BT_BUS_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PGAD_BT_TID_MASK
value|(0x000000FF)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PGAD_BT_TID_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK_PGAD_PHYSDISKNUM_MASK
value|(0x000000FF)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK_PGAD_PHYSDISKNUM_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPAND_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPAND_PGAD_FORM_SHIFT
value|(28)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPAND_PGAD_FORM_GET_NEXT_HANDLE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPAND_PGAD_FORM_HANDLE_PHY_NUM
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPAND_PGAD_FORM_HANDLE
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPAND_PGAD_GNH_MASK_HANDLE
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPAND_PGAD_GNH_SHIFT_HANDLE
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPAND_PGAD_HPN_MASK_PHY
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPAND_PGAD_HPN_SHIFT_PHY
value|(16)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPAND_PGAD_HPN_MASK_HANDLE
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPAND_PGAD_HPN_SHIFT_HANDLE
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPAND_PGAD_H_MASK_HANDLE
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPAND_PGAD_H_SHIFT_HANDLE
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_PGAD_FORM_SHIFT
value|(28)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_PGAD_FORM_GET_NEXT_HANDLE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_PGAD_FORM_BUS_TARGET_ID
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_PGAD_FORM_HANDLE
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_PGAD_GNH_HANDLE_MASK
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_PGAD_GNH_HANDLE_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_PGAD_BT_BUS_MASK
value|(0x0000FF00)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_PGAD_BT_BUS_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_PGAD_BT_TID_MASK
value|(0x000000FF)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_PGAD_BT_TID_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_PGAD_H_HANDLE_MASK
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE_PGAD_H_HANDLE_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY_PGAD_FORM_SHIFT
value|(28)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY_PGAD_FORM_PHY_NUMBER
value|(0x0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY_PGAD_FORM_PHY_TBL_INDEX
value|(0x1)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY_PGAD_PHY_NUMBER_MASK
value|(0x000000FF)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY_PGAD_PHY_NUMBER_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY_PGAD_PHY_TBL_INDEX_MASK
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY_PGAD_PHY_TBL_INDEX_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLOS_PGAD_FORM_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLOS_PGAD_FORM_SHIFT
value|(28)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLOS_PGAD_FORM_GET_NEXT_HANDLE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLOS_PGAD_FORM_HANDLE
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLOS_PGAD_GNH_HANDLE_MASK
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLOS_PGAD_GNH_HANDLE_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLOS_PGAD_H_HANDLE_MASK
value|(0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLOS_PGAD_H_HANDLE_SHIFT
value|(0)
end_define

begin_comment
comment|/**************************************************************************** *   Config Request Message ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_CONFIG
block|{
name|U8
name|Action
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U8
name|ChainOffset
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|ExtPageLength
decl_stmt|;
comment|/* 04h */
name|U8
name|ExtPageType
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U8
name|Reserved2
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0Ch */
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 14h */
name|U32
name|PageAddress
decl_stmt|;
comment|/* 18h */
name|SGE_IO_UNION
name|PageBufferSGE
decl_stmt|;
comment|/* 1Ch */
block|}
name|MSG_CONFIG
operator|,
name|MPI_POINTER
name|PTR_MSG_CONFIG
operator|,
name|Config_t
operator|,
name|MPI_POINTER
name|pConfig_t
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************** *   Action field values ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MPI_CONFIG_ACTION_PAGE_HEADER
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_ACTION_PAGE_READ_CURRENT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_ACTION_PAGE_WRITE_CURRENT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_ACTION_PAGE_DEFAULT
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_ACTION_PAGE_WRITE_NVRAM
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_ACTION_PAGE_READ_DEFAULT
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_CONFIG_ACTION_PAGE_READ_NVRAM
value|(0x06)
end_define

begin_comment
comment|/* Config Reply Message */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MSG_CONFIG_REPLY
block|{
name|U8
name|Action
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U8
name|MsgLength
decl_stmt|;
comment|/* 02h */
name|U8
name|Function
decl_stmt|;
comment|/* 03h */
name|U16
name|ExtPageLength
decl_stmt|;
comment|/* 04h */
name|U8
name|ExtPageType
decl_stmt|;
comment|/* 06h */
name|U8
name|MsgFlags
decl_stmt|;
comment|/* 07h */
name|U32
name|MsgContext
decl_stmt|;
comment|/* 08h */
name|U8
name|Reserved2
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0Ch */
name|U16
name|IOCStatus
decl_stmt|;
comment|/* 0Eh */
name|U32
name|IOCLogInfo
decl_stmt|;
comment|/* 10h */
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 14h */
block|}
name|MSG_CONFIG_REPLY
operator|,
name|MPI_POINTER
name|PTR_MSG_CONFIG_REPLY
operator|,
name|ConfigReply_t
operator|,
name|MPI_POINTER
name|pConfigReply_t
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
name|MPI_MANUFACTPAGE_VENDORID_LSILOGIC
value|(0x1000)
end_define

begin_comment
comment|/* Fibre Channel */
end_comment

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVICEID_FC909
value|(0x0621)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVICEID_FC919
value|(0x0624)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVICEID_FC929
value|(0x0622)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVICEID_FC919X
value|(0x0628)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVICEID_FC929X
value|(0x0626)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVICEID_FC939X
value|(0x0642)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVICEID_FC949X
value|(0x0640)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVICEID_FC949E
value|(0x0646)
end_define

begin_comment
comment|/* SCSI */
end_comment

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_53C1030
value|(0x0030)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_53C1030ZC
value|(0x0031)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_1030_53C1035
value|(0x0032)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_1030ZC_53C1035
value|(0x0033)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_53C1035
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_53C1035ZC
value|(0x0041)
end_define

begin_comment
comment|/* SAS */
end_comment

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SAS1064
value|(0x0050)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SAS1064A
value|(0x005C)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SAS1064E
value|(0x0056)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SAS1066
value|(0x005E)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SAS1066E
value|(0x005A)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SAS1068
value|(0x0054)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SAS1068E
value|(0x0058)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SAS1078
value|(0x0062)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_MANUFACTURING_0
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|ChipName
index|[
literal|16
index|]
decl_stmt|;
comment|/* 04h */
name|U8
name|ChipRevision
index|[
literal|8
index|]
decl_stmt|;
comment|/* 14h */
name|U8
name|BoardName
index|[
literal|16
index|]
decl_stmt|;
comment|/* 1Ch */
name|U8
name|BoardAssembly
index|[
literal|16
index|]
decl_stmt|;
comment|/* 2Ch */
name|U8
name|BoardTracerNumber
index|[
literal|16
index|]
decl_stmt|;
comment|/* 3Ch */
block|}
name|CONFIG_PAGE_MANUFACTURING_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_MANUFACTURING_0
operator|,
name|ManufacturingPage0_t
operator|,
name|MPI_POINTER
name|pManufacturingPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_MANUFACTURING0_PAGEVERSION
value|(0x00)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_MANUFACTURING_1
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|VPD
index|[
literal|256
index|]
decl_stmt|;
comment|/* 04h */
block|}
name|CONFIG_PAGE_MANUFACTURING_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_MANUFACTURING_1
operator|,
name|ManufacturingPage1_t
operator|,
name|MPI_POINTER
name|pManufacturingPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_MANUFACTURING1_PAGEVERSION
value|(0x00)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI_CHIP_REVISION_ID
block|{
name|U16
name|DeviceID
decl_stmt|;
comment|/* 00h */
name|U8
name|PCIRevisionID
decl_stmt|;
comment|/* 02h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 03h */
block|}
name|MPI_CHIP_REVISION_ID
operator|,
name|MPI_POINTER
name|PTR_MPI_CHIP_REVISION_ID
operator|,
name|MpiChipRevisionId_t
operator|,
name|MPI_POINTER
name|pMpiChipRevisionId_t
typedef|;
end_typedef

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check Header.PageLength at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_MAN_PAGE_2_HW_SETTINGS_WORDS
end_ifndef

begin_define
define|#
directive|define
name|MPI_MAN_PAGE_2_HW_SETTINGS_WORDS
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_MANUFACTURING_2
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|MPI_CHIP_REVISION_ID
name|ChipId
decl_stmt|;
comment|/* 04h */
name|U32
name|HwSettings
index|[
name|MPI_MAN_PAGE_2_HW_SETTINGS_WORDS
index|]
decl_stmt|;
comment|/* 08h */
block|}
name|CONFIG_PAGE_MANUFACTURING_2
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_MANUFACTURING_2
operator|,
name|ManufacturingPage2_t
operator|,
name|MPI_POINTER
name|pManufacturingPage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_MANUFACTURING2_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check Header.PageLength at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_MAN_PAGE_3_INFO_WORDS
end_ifndef

begin_define
define|#
directive|define
name|MPI_MAN_PAGE_3_INFO_WORDS
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_MANUFACTURING_3
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|MPI_CHIP_REVISION_ID
name|ChipId
decl_stmt|;
comment|/* 04h */
name|U32
name|Info
index|[
name|MPI_MAN_PAGE_3_INFO_WORDS
index|]
decl_stmt|;
comment|/* 08h */
block|}
name|CONFIG_PAGE_MANUFACTURING_3
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_MANUFACTURING_3
operator|,
name|ManufacturingPage3_t
operator|,
name|MPI_POINTER
name|pManufacturingPage3_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_MANUFACTURING3_PAGEVERSION
value|(0x00)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_MANUFACTURING_4
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U8
name|InfoOffset0
decl_stmt|;
comment|/* 08h */
name|U8
name|InfoSize0
decl_stmt|;
comment|/* 09h */
name|U8
name|InfoOffset1
decl_stmt|;
comment|/* 0Ah */
name|U8
name|InfoSize1
decl_stmt|;
comment|/* 0Bh */
name|U8
name|InquirySize
decl_stmt|;
comment|/* 0Ch */
name|U8
name|Flags
decl_stmt|;
comment|/* 0Dh */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0Eh */
name|U8
name|InquiryData
index|[
literal|56
index|]
decl_stmt|;
comment|/* 10h */
name|U32
name|ISVolumeSettings
decl_stmt|;
comment|/* 48h */
name|U32
name|IMEVolumeSettings
decl_stmt|;
comment|/* 4Ch */
name|U32
name|IMVolumeSettings
decl_stmt|;
comment|/* 50h */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 54h */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 58h */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 5Ch */
name|U8
name|IMEDataScrubRate
decl_stmt|;
comment|/* 60h */
name|U8
name|IMEResyncRate
decl_stmt|;
comment|/* 61h */
name|U16
name|Reserved6
decl_stmt|;
comment|/* 62h */
name|U8
name|IMDataScrubRate
decl_stmt|;
comment|/* 64h */
name|U8
name|IMResyncRate
decl_stmt|;
comment|/* 65h */
name|U16
name|Reserved7
decl_stmt|;
comment|/* 66h */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 68h */
name|U32
name|Reserved9
decl_stmt|;
comment|/* 6Ch */
block|}
name|CONFIG_PAGE_MANUFACTURING_4
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_MANUFACTURING_4
operator|,
name|ManufacturingPage4_t
operator|,
name|MPI_POINTER
name|pManufacturingPage4_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_MANUFACTURING4_PAGEVERSION
value|(0x03)
end_define

begin_comment
comment|/* defines for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI_MANPAGE4_IME_DISABLE
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI_MANPAGE4_IM_DISABLE
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_MANPAGE4_IS_DISABLE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_MANPAGE4_IR_MODEPAGE8_DISABLE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_MANPAGE4_IM_RESYNC_CACHE_ENABLE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_MANPAGE4_IR_NO_MIX_SAS_SATA
value|(0x01)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_MANUFACTURING_5
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U64
name|BaseWWID
decl_stmt|;
comment|/* 04h */
name|U8
name|Flags
decl_stmt|;
comment|/* 0Ch */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0Dh */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0Eh */
block|}
name|CONFIG_PAGE_MANUFACTURING_5
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_MANUFACTURING_5
operator|,
name|ManufacturingPage5_t
operator|,
name|MPI_POINTER
name|pManufacturingPage5_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_MANUFACTURING5_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/* defines for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI_MANPAGE5_TWO_WWID_PER_PHY
value|(0x01)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_MANUFACTURING_6
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|ProductSpecificInfo
decl_stmt|;
comment|/* 04h */
block|}
name|CONFIG_PAGE_MANUFACTURING_6
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_MANUFACTURING_6
operator|,
name|ManufacturingPage6_t
operator|,
name|MPI_POINTER
name|pManufacturingPage6_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_MANUFACTURING6_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/**************************************************************************** *   IO Unit Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_IO_UNIT_0
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U64
name|UniqueValue
decl_stmt|;
comment|/* 04h */
block|}
name|CONFIG_PAGE_IO_UNIT_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_IO_UNIT_0
operator|,
name|IOUnitPage0_t
operator|,
name|MPI_POINTER
name|pIOUnitPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE0_PAGEVERSION
value|(0x00)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_IO_UNIT_1
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Flags
decl_stmt|;
comment|/* 04h */
block|}
name|CONFIG_PAGE_IO_UNIT_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_IO_UNIT_1
operator|,
name|IOUnitPage1_t
operator|,
name|MPI_POINTER
name|pIOUnitPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE1_PAGEVERSION
value|(0x02)
end_define

begin_comment
comment|/* IO Unit Page 1 Flags defines */
end_comment

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE1_MULTI_FUNCTION
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE1_SINGLE_FUNCTION
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE1_MULTI_PATHING
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE1_SINGLE_PATHING
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE1_IR_USE_STATIC_VOLUME_ID
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE1_DISABLE_QUEUE_FULL_HANDLING
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE1_DISABLE_IR
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE1_FORCE_32
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE1_NATIVE_COMMAND_Q_DISABLE
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE1_SATA_WRITE_CACHE_DISABLE
value|(0x00000200)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI_ADAPTER_INFO
block|{
name|U8
name|PciBusNumber
decl_stmt|;
comment|/* 00h */
name|U8
name|PciDeviceAndFunctionNumber
decl_stmt|;
comment|/* 01h */
name|U16
name|AdapterFlags
decl_stmt|;
comment|/* 02h */
block|}
name|MPI_ADAPTER_INFO
operator|,
name|MPI_POINTER
name|PTR_MPI_ADAPTER_INFO
operator|,
name|MpiAdapterInfo_t
operator|,
name|MPI_POINTER
name|pMpiAdapterInfo_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_ADAPTER_INFO_FLAGS_EMBEDDED
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI_ADAPTER_INFO_FLAGS_INIT_STATUS
value|(0x0002)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_IO_UNIT_2
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Flags
decl_stmt|;
comment|/* 04h */
name|U32
name|BiosVersion
decl_stmt|;
comment|/* 08h */
name|MPI_ADAPTER_INFO
name|AdapterOrder
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0Ch */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 1Ch */
block|}
name|CONFIG_PAGE_IO_UNIT_2
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_IO_UNIT_2
operator|,
name|IOUnitPage2_t
operator|,
name|MPI_POINTER
name|pIOUnitPage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE2_PAGEVERSION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE2_FLAGS_PAUSE_ON_ERROR
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE2_FLAGS_VERBOSE_ENABLE
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE2_FLAGS_COLOR_VIDEO_DISABLE
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE2_FLAGS_DONT_HOOK_INT_40
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE2_FLAGS_DEV_LIST_DISPLAY_MASK
value|(0x000000E0)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE2_FLAGS_INSTALLED_DEV_DISPLAY
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE2_FLAGS_ADAPTER_DISPLAY
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE2_FLAGS_ADAPTER_DEV_DISPLAY
value|(0x00000040)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check Header.PageLength at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_IO_UNIT_PAGE_3_GPIO_VAL_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI_IO_UNIT_PAGE_3_GPIO_VAL_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_IO_UNIT_3
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|GPIOCount
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 06h */
name|U16
name|GPIOVal
index|[
name|MPI_IO_UNIT_PAGE_3_GPIO_VAL_MAX
index|]
decl_stmt|;
comment|/* 08h */
block|}
name|CONFIG_PAGE_IO_UNIT_3
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_IO_UNIT_3
operator|,
name|IOUnitPage3_t
operator|,
name|MPI_POINTER
name|pIOUnitPage3_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE3_PAGEVERSION
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE3_GPIO_FUNCTION_MASK
value|(0xFC)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE3_GPIO_FUNCTION_SHIFT
value|(2)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE3_GPIO_SETTING_OFF
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE3_GPIO_SETTING_ON
value|(0x01)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_IO_UNIT_4
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|SGE_SIMPLE_UNION
name|FWImageSGE
decl_stmt|;
comment|/* 08h */
block|}
name|CONFIG_PAGE_IO_UNIT_4
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_IO_UNIT_4
operator|,
name|IOUnitPage4_t
operator|,
name|MPI_POINTER
name|pIOUnitPage4_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE4_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/**************************************************************************** *   IOC Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_IOC_0
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|TotalNVStore
decl_stmt|;
comment|/* 04h */
name|U32
name|FreeNVStore
decl_stmt|;
comment|/* 08h */
name|U16
name|VendorID
decl_stmt|;
comment|/* 0Ch */
name|U16
name|DeviceID
decl_stmt|;
comment|/* 0Eh */
name|U8
name|RevisionID
decl_stmt|;
comment|/* 10h */
name|U8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
comment|/* 11h */
name|U32
name|ClassCode
decl_stmt|;
comment|/* 14h */
name|U16
name|SubsystemVendorID
decl_stmt|;
comment|/* 18h */
name|U16
name|SubsystemID
decl_stmt|;
comment|/* 1Ah */
block|}
name|CONFIG_PAGE_IOC_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_IOC_0
operator|,
name|IOCPage0_t
operator|,
name|MPI_POINTER
name|pIOCPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_IOCPAGE0_PAGEVERSION
value|(0x01)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_IOC_1
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Flags
decl_stmt|;
comment|/* 04h */
name|U32
name|CoalescingTimeout
decl_stmt|;
comment|/* 08h */
name|U8
name|CoalescingDepth
decl_stmt|;
comment|/* 0Ch */
name|U8
name|PCISlotNum
decl_stmt|;
comment|/* 0Dh */
name|U8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0Eh */
block|}
name|CONFIG_PAGE_IOC_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_IOC_1
operator|,
name|IOCPage1_t
operator|,
name|MPI_POINTER
name|pIOCPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_IOCPAGE1_PAGEVERSION
value|(0x03)
end_define

begin_comment
comment|/* defines for the Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI_IOCPAGE1_EEDP_MODE_MASK
value|(0x07000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE1_EEDP_MODE_OFF
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE1_EEDP_MODE_T10
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE1_EEDP_MODE_LSI_1
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE1_INITIATOR_CONTEXT_REPLY_DISABLE
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE1_REPLY_COALESCING
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE1_PCISLOTNUM_UNKNOWN
value|(0xFF)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_IOC_2_RAID_VOL
block|{
name|U8
name|VolumeID
decl_stmt|;
comment|/* 00h */
name|U8
name|VolumeBus
decl_stmt|;
comment|/* 01h */
name|U8
name|VolumeIOC
decl_stmt|;
comment|/* 02h */
name|U8
name|VolumePageNumber
decl_stmt|;
comment|/* 03h */
name|U8
name|VolumeType
decl_stmt|;
comment|/* 04h */
name|U8
name|Flags
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 06h */
block|}
name|CONFIG_PAGE_IOC_2_RAID_VOL
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_IOC_2_RAID_VOL
operator|,
name|ConfigPageIoc2RaidVol_t
operator|,
name|MPI_POINTER
name|pConfigPageIoc2RaidVol_t
typedef|;
end_typedef

begin_comment
comment|/* IOC Page 2 Volume RAID Type values, also used in RAID Volume pages */
end_comment

begin_define
define|#
directive|define
name|MPI_RAID_VOL_TYPE_IS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_VOL_TYPE_IME
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_VOL_TYPE_IM
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_VOL_TYPE_RAID_5
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_VOL_TYPE_RAID_6
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_VOL_TYPE_RAID_10
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_VOL_TYPE_RAID_50
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_VOL_TYPE_UNKNOWN
value|(0xFF)
end_define

begin_comment
comment|/* IOC Page 2 Volume Flags values */
end_comment

begin_define
define|#
directive|define
name|MPI_IOCPAGE2_FLAG_VOLUME_INACTIVE
value|(0x08)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check Header.PageLength at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_IOC_PAGE_2_RAID_VOLUME_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI_IOC_PAGE_2_RAID_VOLUME_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_IOC_2
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|CapabilitiesFlags
decl_stmt|;
comment|/* 04h */
name|U8
name|NumActiveVolumes
decl_stmt|;
comment|/* 08h */
name|U8
name|MaxVolumes
decl_stmt|;
comment|/* 09h */
name|U8
name|NumActivePhysDisks
decl_stmt|;
comment|/* 0Ah */
name|U8
name|MaxPhysDisks
decl_stmt|;
comment|/* 0Bh */
name|CONFIG_PAGE_IOC_2_RAID_VOL
name|RaidVolume
index|[
name|MPI_IOC_PAGE_2_RAID_VOLUME_MAX
index|]
decl_stmt|;
comment|/* 0Ch */
block|}
name|CONFIG_PAGE_IOC_2
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_IOC_2
operator|,
name|IOCPage2_t
operator|,
name|MPI_POINTER
name|pIOCPage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_IOCPAGE2_PAGEVERSION
value|(0x03)
end_define

begin_comment
comment|/* IOC Page 2 Capabilities flags */
end_comment

begin_define
define|#
directive|define
name|MPI_IOCPAGE2_CAP_FLAGS_IS_SUPPORT
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE2_CAP_FLAGS_IME_SUPPORT
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE2_CAP_FLAGS_IM_SUPPORT
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE2_CAP_FLAGS_RAID_5_SUPPORT
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE2_CAP_FLAGS_RAID_6_SUPPORT
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE2_CAP_FLAGS_RAID_10_SUPPORT
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE2_CAP_FLAGS_RAID_50_SUPPORT
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE2_CAP_FLAGS_SES_SUPPORT
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE2_CAP_FLAGS_SAFTE_SUPPORT
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI_IOCPAGE2_CAP_FLAGS_CROSS_CHANNEL_SUPPORT
value|(0x80000000)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_IOC_3_PHYS_DISK
block|{
name|U8
name|PhysDiskID
decl_stmt|;
comment|/* 00h */
name|U8
name|PhysDiskBus
decl_stmt|;
comment|/* 01h */
name|U8
name|PhysDiskIOC
decl_stmt|;
comment|/* 02h */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 03h */
block|}
name|IOC_3_PHYS_DISK
operator|,
name|MPI_POINTER
name|PTR_IOC_3_PHYS_DISK
operator|,
name|Ioc3PhysDisk_t
operator|,
name|MPI_POINTER
name|pIoc3PhysDisk_t
typedef|;
end_typedef

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check Header.PageLength at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_IOC_PAGE_3_PHYSDISK_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI_IOC_PAGE_3_PHYSDISK_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_IOC_3
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|NumPhysDisks
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 06h */
name|IOC_3_PHYS_DISK
name|PhysDisk
index|[
name|MPI_IOC_PAGE_3_PHYSDISK_MAX
index|]
decl_stmt|;
comment|/* 08h */
block|}
name|CONFIG_PAGE_IOC_3
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_IOC_3
operator|,
name|IOCPage3_t
operator|,
name|MPI_POINTER
name|pIOCPage3_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_IOCPAGE3_PAGEVERSION
value|(0x00)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_IOC_4_SEP
block|{
name|U8
name|SEPTargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|SEPBus
decl_stmt|;
comment|/* 01h */
name|U16
name|Reserved
decl_stmt|;
comment|/* 02h */
block|}
name|IOC_4_SEP
operator|,
name|MPI_POINTER
name|PTR_IOC_4_SEP
operator|,
name|Ioc4Sep_t
operator|,
name|MPI_POINTER
name|pIoc4Sep_t
typedef|;
end_typedef

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check Header.PageLength at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_IOC_PAGE_4_SEP_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI_IOC_PAGE_4_SEP_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_IOC_4
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|ActiveSEP
decl_stmt|;
comment|/* 04h */
name|U8
name|MaxSEP
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 06h */
name|IOC_4_SEP
name|SEP
index|[
name|MPI_IOC_PAGE_4_SEP_MAX
index|]
decl_stmt|;
comment|/* 08h */
block|}
name|CONFIG_PAGE_IOC_4
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_IOC_4
operator|,
name|IOCPage4_t
operator|,
name|MPI_POINTER
name|pIOCPage4_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_IOCPAGE4_PAGEVERSION
value|(0x00)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_IOC_5_HOT_SPARE
block|{
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 00h */
name|U8
name|Reserved
decl_stmt|;
comment|/* 01h */
name|U8
name|HotSparePool
decl_stmt|;
comment|/* 02h */
name|U8
name|Flags
decl_stmt|;
comment|/* 03h */
block|}
name|IOC_5_HOT_SPARE
operator|,
name|MPI_POINTER
name|PTR_IOC_5_HOT_SPARE
operator|,
name|Ioc5HotSpare_t
operator|,
name|MPI_POINTER
name|pIoc5HotSpare_t
typedef|;
end_typedef

begin_comment
comment|/* IOC Page 5 HotSpare Flags */
end_comment

begin_define
define|#
directive|define
name|MPI_IOC_PAGE_5_HOT_SPARE_ACTIVE
value|(0x01)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check Header.PageLength at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_IOC_PAGE_5_HOT_SPARE_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI_IOC_PAGE_5_HOT_SPARE_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_IOC_5
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U8
name|NumHotSpares
decl_stmt|;
comment|/* 08h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 09h */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0Ah */
name|IOC_5_HOT_SPARE
name|HotSpare
index|[
name|MPI_IOC_PAGE_5_HOT_SPARE_MAX
index|]
decl_stmt|;
comment|/* 0Ch */
block|}
name|CONFIG_PAGE_IOC_5
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_IOC_5
operator|,
name|IOCPage5_t
operator|,
name|MPI_POINTER
name|pIOCPage5_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_IOCPAGE5_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/**************************************************************************** *   BIOS Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_BIOS_1
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|BiosOptions
decl_stmt|;
comment|/* 04h */
name|U32
name|IOCSettings
decl_stmt|;
comment|/* 08h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0Ch */
name|U32
name|DeviceSettings
decl_stmt|;
comment|/* 10h */
name|U16
name|NumberOfDevices
decl_stmt|;
comment|/* 14h */
name|U8
name|ExpanderSpinup
decl_stmt|;
comment|/* 16h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 17h */
name|U16
name|IOTimeoutBlockDevicesNonRM
decl_stmt|;
comment|/* 18h */
name|U16
name|IOTimeoutSequential
decl_stmt|;
comment|/* 1Ah */
name|U16
name|IOTimeoutOther
decl_stmt|;
comment|/* 1Ch */
name|U16
name|IOTimeoutBlockDevicesRM
decl_stmt|;
comment|/* 1Eh */
block|}
name|CONFIG_PAGE_BIOS_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_BIOS_1
operator|,
name|BIOSPage1_t
operator|,
name|MPI_POINTER
name|pBIOSPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_PAGEVERSION
value|(0x03)
end_define

begin_comment
comment|/* values for the BiosOptions field */
end_comment

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_OPTIONS_SPI_ENABLE
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_OPTIONS_FC_ENABLE
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_OPTIONS_SAS_ENABLE
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_OPTIONS_DISABLE_BIOS
value|(0x00000001)
end_define

begin_comment
comment|/* values for the IOCSettings field */
end_comment

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_MASK_INITIAL_SPINUP_DELAY
value|(0x0F000000)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_SHIFT_INITIAL_SPINUP_DELAY
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_MASK_PORT_ENABLE_DELAY
value|(0x00F00000)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_SHIFT_PORT_ENABLE_DELAY
value|(20)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_AUTO_PORT_ENABLE
value|(0x00080000)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_DIRECT_ATTACH_SPINUP_MODE
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_MASK_BOOT_PREFERENCE
value|(0x00030000)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_ENCLOSURE_SLOT_BOOT
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_SAS_ADDRESS_BOOT
value|(0x00010000)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_MASK_MAX_TARGET_SPIN_UP
value|(0x0000F000)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_SHIFT_MAX_TARGET_SPIN_UP
value|(12)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_MASK_SPINUP_DELAY
value|(0x00000F00)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_SHIFT_SPINUP_DELAY
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_MASK_RM_SETTING
value|(0x000000C0)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_NONE_RM_SETTING
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_BOOT_RM_SETTING
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_MEDIA_RM_SETTING
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_MASK_ADAPTER_SUPPORT
value|(0x00000030)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_NO_SUPPORT
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_BIOS_SUPPORT
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_OS_SUPPORT
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_ALL_SUPPORT
value|(0x00000030)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_IOCSET_ALTERNATE_CHS
value|(0x00000008)
end_define

begin_comment
comment|/* values for the DeviceSettings field */
end_comment

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_DEVSET_DISABLE_SEQ_LUN
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_DEVSET_DISABLE_RM_LUN
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_DEVSET_DISABLE_NON_RM_LUN
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_DEVSET_DISABLE_OTHER_LUN
value|(0x00000001)
end_define

begin_comment
comment|/* defines for the ExpanderSpinup field */
end_comment

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_EXPSPINUP_MASK_MAX_TARGET
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_EXPSPINUP_SHIFT_MAX_TARGET
value|(4)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE1_EXPSPINUP_MASK_DELAY
value|(0x0F)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI_BOOT_DEVICE_ADAPTER_ORDER
block|{
name|U32
name|Reserved1
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 08h */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0Ch */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 14h */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 18h */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 1Ch */
name|U32
name|Reserved9
decl_stmt|;
comment|/* 20h */
name|U32
name|Reserved10
decl_stmt|;
comment|/* 24h */
name|U32
name|Reserved11
decl_stmt|;
comment|/* 28h */
name|U32
name|Reserved12
decl_stmt|;
comment|/* 2Ch */
name|U32
name|Reserved13
decl_stmt|;
comment|/* 30h */
name|U32
name|Reserved14
decl_stmt|;
comment|/* 34h */
name|U32
name|Reserved15
decl_stmt|;
comment|/* 38h */
name|U32
name|Reserved16
decl_stmt|;
comment|/* 3Ch */
name|U32
name|Reserved17
decl_stmt|;
comment|/* 40h */
block|}
name|MPI_BOOT_DEVICE_ADAPTER_ORDER
operator|,
name|MPI_POINTER
name|PTR_MPI_BOOT_DEVICE_ADAPTER_ORDER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI_BOOT_DEVICE_ADAPTER_NUMBER
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
decl_stmt|;
comment|/* 01h */
name|U8
name|AdapterNumber
decl_stmt|;
comment|/* 02h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 03h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 08h */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0Ch */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 18h */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 1Ch */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 20h */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 24h */
name|U32
name|Reserved9
decl_stmt|;
comment|/* 28h */
name|U32
name|Reserved10
decl_stmt|;
comment|/* 2Ch */
name|U32
name|Reserved11
decl_stmt|;
comment|/* 30h */
name|U32
name|Reserved12
decl_stmt|;
comment|/* 34h */
name|U32
name|Reserved13
decl_stmt|;
comment|/* 38h */
name|U32
name|Reserved14
decl_stmt|;
comment|/* 3Ch */
name|U32
name|Reserved15
decl_stmt|;
comment|/* 40h */
block|}
name|MPI_BOOT_DEVICE_ADAPTER_NUMBER
operator|,
name|MPI_POINTER
name|PTR_MPI_BOOT_DEVICE_ADAPTER_NUMBER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI_BOOT_DEVICE_PCI_ADDRESS
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
decl_stmt|;
comment|/* 01h */
name|U16
name|PCIAddress
decl_stmt|;
comment|/* 02h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 08h */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0Ch */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 18h */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 1Ch */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 20h */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 24h */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 28h */
name|U32
name|Reserved9
decl_stmt|;
comment|/* 2Ch */
name|U32
name|Reserved10
decl_stmt|;
comment|/* 30h */
name|U32
name|Reserved11
decl_stmt|;
comment|/* 34h */
name|U32
name|Reserved12
decl_stmt|;
comment|/* 38h */
name|U32
name|Reserved13
decl_stmt|;
comment|/* 3Ch */
name|U32
name|Reserved14
decl_stmt|;
comment|/* 40h */
block|}
name|MPI_BOOT_DEVICE_PCI_ADDRESS
operator|,
name|MPI_POINTER
name|PTR_MPI_BOOT_DEVICE_PCI_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI_BOOT_DEVICE_SLOT_NUMBER
block|{
name|U8
name|TargetID
decl_stmt|;
comment|/* 00h */
name|U8
name|Bus
decl_stmt|;
comment|/* 01h */
name|U8
name|PCISlotNumber
decl_stmt|;
comment|/* 02h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 03h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 04h */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 08h */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 0Ch */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 18h */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 1Ch */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 20h */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 24h */
name|U32
name|Reserved9
decl_stmt|;
comment|/* 28h */
name|U32
name|Reserved10
decl_stmt|;
comment|/* 2Ch */
name|U32
name|Reserved11
decl_stmt|;
comment|/* 30h */
name|U32
name|Reserved12
decl_stmt|;
comment|/* 34h */
name|U32
name|Reserved13
decl_stmt|;
comment|/* 38h */
name|U32
name|Reserved14
decl_stmt|;
comment|/* 3Ch */
name|U32
name|Reserved15
decl_stmt|;
comment|/* 40h */
block|}
name|MPI_BOOT_DEVICE_PCI_SLOT_NUMBER
operator|,
name|MPI_POINTER
name|PTR_MPI_BOOT_DEVICE_PCI_SLOT_NUMBER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI_BOOT_DEVICE_FC_WWN
block|{
name|U64
name|WWPN
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 08h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 18h */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 1Ch */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 20h */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 24h */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 28h */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 2Ch */
name|U32
name|Reserved9
decl_stmt|;
comment|/* 30h */
name|U32
name|Reserved10
decl_stmt|;
comment|/* 34h */
name|U32
name|Reserved11
decl_stmt|;
comment|/* 38h */
name|U32
name|Reserved12
decl_stmt|;
comment|/* 3Ch */
name|U32
name|Reserved13
decl_stmt|;
comment|/* 40h */
block|}
name|MPI_BOOT_DEVICE_FC_WWN
operator|,
name|MPI_POINTER
name|PTR_MPI_BOOT_DEVICE_FC_WWN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI_BOOT_DEVICE_SAS_WWN
block|{
name|U64
name|SASAddress
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 08h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 18h */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 1Ch */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 20h */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 24h */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 28h */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 2Ch */
name|U32
name|Reserved9
decl_stmt|;
comment|/* 30h */
name|U32
name|Reserved10
decl_stmt|;
comment|/* 34h */
name|U32
name|Reserved11
decl_stmt|;
comment|/* 38h */
name|U32
name|Reserved12
decl_stmt|;
comment|/* 3Ch */
name|U32
name|Reserved13
decl_stmt|;
comment|/* 40h */
block|}
name|MPI_BOOT_DEVICE_SAS_WWN
operator|,
name|MPI_POINTER
name|PTR_MPI_BOOT_DEVICE_SAS_WWN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MPI_BOOT_DEVICE_ENCLOSURE_SLOT
block|{
name|U64
name|EnclosureLogicalID
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 08h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U8
name|LUN
index|[
literal|8
index|]
decl_stmt|;
comment|/* 10h */
name|U16
name|SlotNumber
decl_stmt|;
comment|/* 18h */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 1Ah */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 1Ch */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 20h */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 24h */
name|U32
name|Reserved7
decl_stmt|;
comment|/* 28h */
name|U32
name|Reserved8
decl_stmt|;
comment|/* 2Ch */
name|U32
name|Reserved9
decl_stmt|;
comment|/* 30h */
name|U32
name|Reserved10
decl_stmt|;
comment|/* 34h */
name|U32
name|Reserved11
decl_stmt|;
comment|/* 38h */
name|U32
name|Reserved12
decl_stmt|;
comment|/* 3Ch */
name|U32
name|Reserved13
decl_stmt|;
comment|/* 40h */
block|}
name|MPI_BOOT_DEVICE_ENCLOSURE_SLOT
operator|,
name|MPI_POINTER
name|PTR_MPI_BOOT_DEVICE_ENCLOSURE_SLOT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_MPI_BIOSPAGE2_BOOT_DEVICE
block|{
name|MPI_BOOT_DEVICE_ADAPTER_ORDER
name|AdapterOrder
decl_stmt|;
name|MPI_BOOT_DEVICE_ADAPTER_NUMBER
name|AdapterNumber
decl_stmt|;
name|MPI_BOOT_DEVICE_PCI_ADDRESS
name|PCIAddress
decl_stmt|;
name|MPI_BOOT_DEVICE_PCI_SLOT_NUMBER
name|PCISlotNumber
decl_stmt|;
name|MPI_BOOT_DEVICE_FC_WWN
name|FcWwn
decl_stmt|;
name|MPI_BOOT_DEVICE_SAS_WWN
name|SasWwn
decl_stmt|;
name|MPI_BOOT_DEVICE_ENCLOSURE_SLOT
name|EnclosureSlot
decl_stmt|;
block|}
name|MPI_BIOSPAGE2_BOOT_DEVICE
operator|,
name|MPI_POINTER
name|PTR_MPI_BIOSPAGE2_BOOT_DEVICE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_BIOS_2
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 08h */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 0Ch */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved5
decl_stmt|;
comment|/* 14h */
name|U32
name|Reserved6
decl_stmt|;
comment|/* 18h */
name|U8
name|BootDeviceForm
decl_stmt|;
comment|/* 1Ch */
name|U8
name|Reserved7
decl_stmt|;
comment|/* 1Dh */
name|U16
name|Reserved8
decl_stmt|;
comment|/* 1Eh */
name|MPI_BIOSPAGE2_BOOT_DEVICE
name|BootDevice
decl_stmt|;
comment|/* 20h */
block|}
name|CONFIG_PAGE_BIOS_2
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_BIOS_2
operator|,
name|BIOSPage2_t
operator|,
name|MPI_POINTER
name|pBIOSPage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_BIOSPAGE2_PAGEVERSION
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE2_FORM_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE2_FORM_ADAPTER_ORDER
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE2_FORM_ADAPTER_NUMBER
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE2_FORM_PCI_ADDRESS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE2_FORM_PCI_SLOT_NUMBER
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE2_FORM_FC_WWN
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE2_FORM_SAS_WWN
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_BIOSPAGE2_FORM_ENCLOSURE_SLOT
value|(0x06)
end_define

begin_comment
comment|/**************************************************************************** *   SCSI Port Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SCSI_PORT_0
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Capabilities
decl_stmt|;
comment|/* 04h */
name|U32
name|PhysicalInterface
decl_stmt|;
comment|/* 08h */
block|}
name|CONFIG_PAGE_SCSI_PORT_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SCSI_PORT_0
operator|,
name|SCSIPortPage0_t
operator|,
name|MPI_POINTER
name|pSCSIPortPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_PAGEVERSION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_CAP_IU
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_CAP_DT
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_CAP_QAS
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_CAP_MIN_SYNC_PERIOD_MASK
value|(0x0000FF00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_SYNC_ASYNC
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_SYNC_5
value|(0x32)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_SYNC_10
value|(0x19)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_SYNC_20
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_SYNC_33_33
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_SYNC_40
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_SYNC_80
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_SYNC_160
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_SYNC_UNKNOWN
value|(0xFF)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_CAP_SHIFT_MIN_SYNC_PERIOD
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_CAP_GET_MIN_SYNC_PERIOD
parameter_list|(
name|Cap
parameter_list|)
define|\
value|(  ((Cap)& MPI_SCSIPORTPAGE0_CAP_MIN_SYNC_PERIOD_MASK) \>> MPI_SCSIPORTPAGE0_CAP_SHIFT_MIN_SYNC_PERIOD          \     )
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_CAP_MAX_SYNC_OFFSET_MASK
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_CAP_SHIFT_MAX_SYNC_OFFSET
value|(16)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_CAP_GET_MAX_SYNC_OFFSET
parameter_list|(
name|Cap
parameter_list|)
define|\
value|(  ((Cap)& MPI_SCSIPORTPAGE0_CAP_MAX_SYNC_OFFSET_MASK) \>> MPI_SCSIPORTPAGE0_CAP_SHIFT_MAX_SYNC_OFFSET          \     )
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_CAP_IDP
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_CAP_WIDE
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_CAP_AIP
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_PHY_SIGNAL_TYPE_MASK
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_PHY_SIGNAL_HVD
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_PHY_SIGNAL_SE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_PHY_SIGNAL_LVD
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_PHY_MASK_CONNECTED_ID
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_PHY_SHIFT_CONNECTED_ID
value|(24)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_PHY_BUS_FREE_CONNECTED_ID
value|(0xFE)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE0_PHY_UNKNOWN_CONNECTED_ID
value|(0xFF)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SCSI_PORT_1
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Configuration
decl_stmt|;
comment|/* 04h */
name|U32
name|OnBusTimerValue
decl_stmt|;
comment|/* 08h */
name|U8
name|TargetConfig
decl_stmt|;
comment|/* 0Ch */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 0Dh */
name|U16
name|IDConfig
decl_stmt|;
comment|/* 0Eh */
block|}
name|CONFIG_PAGE_SCSI_PORT_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SCSI_PORT_1
operator|,
name|SCSIPortPage1_t
operator|,
name|MPI_POINTER
name|pSCSIPortPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE1_PAGEVERSION
value|(0x03)
end_define

begin_comment
comment|/* Configuration values */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE1_CFG_PORT_SCSI_ID_MASK
value|(0x000000FF)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE1_CFG_PORT_RESPONSE_ID_MASK
value|(0xFFFF0000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE1_CFG_SHIFT_PORT_RESPONSE_ID
value|(16)
end_define

begin_comment
comment|/* TargetConfig values */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE1_TARGCONFIG_TARG_ONLY
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE1_TARGCONFIG_INIT_TARG
value|(0x02)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI_DEVICE_INFO
block|{
name|U8
name|Timeout
decl_stmt|;
comment|/* 00h */
name|U8
name|SyncFactor
decl_stmt|;
comment|/* 01h */
name|U16
name|DeviceFlags
decl_stmt|;
comment|/* 02h */
block|}
name|MPI_DEVICE_INFO
operator|,
name|MPI_POINTER
name|PTR_MPI_DEVICE_INFO
operator|,
name|MpiDeviceInfo_t
operator|,
name|MPI_POINTER
name|pMpiDeviceInfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SCSI_PORT_2
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|PortFlags
decl_stmt|;
comment|/* 04h */
name|U32
name|PortSettings
decl_stmt|;
comment|/* 08h */
name|MPI_DEVICE_INFO
name|DeviceSettings
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0Ch */
block|}
name|CONFIG_PAGE_SCSI_PORT_2
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SCSI_PORT_2
operator|,
name|SCSIPortPage2_t
operator|,
name|MPI_POINTER
name|pSCSIPortPage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PAGEVERSION
value|(0x02)
end_define

begin_comment
comment|/* PortFlags values */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_FLAGS_SCAN_HIGH_TO_LOW
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_FLAGS_AVOID_SCSI_RESET
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_FLAGS_ALTERNATE_CHS
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_FLAGS_TERMINATION_DISABLE
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_FLAGS_DV_MASK
value|(0x00000060)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_FLAGS_FULL_DV
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_FLAGS_BASIC_DV_ONLY
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_FLAGS_OFF_DV
value|(0x00000060)
end_define

begin_comment
comment|/* PortSettings values */
end_comment

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_HOST_ID_MASK
value|(0x0000000F)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_MASK_INIT_HBA
value|(0x00000030)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_DISABLE_INIT_HBA
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_BIOS_INIT_HBA
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_OS_INIT_HBA
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_BIOS_OS_INIT_HBA
value|(0x00000030)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_REMOVABLE_MEDIA
value|(0x000000C0)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_RM_NONE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_RM_BOOT_ONLY
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_RM_WITH_MEDIA
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_SPINUP_DELAY_MASK
value|(0x00000F00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_SHIFT_SPINUP_DELAY
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_MASK_NEGO_MASTER_SETTINGS
value|(0x00003000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_NEGO_MASTER_SETTINGS
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_NONE_MASTER_SETTINGS
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_PORT_ALL_MASTER_SETTINGS
value|(0x00003000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_DEVICE_DISCONNECT_ENABLE
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_DEVICE_ID_SCAN_ENABLE
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_DEVICE_LUN_SCAN_ENABLE
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_DEVICE_TAG_QUEUE_ENABLE
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_DEVICE_WIDE_DISABLE
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIPORTPAGE2_DEVICE_BOOT_CHOICE
value|(0x0020)
end_define

begin_comment
comment|/**************************************************************************** *   SCSI Target Device Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SCSI_DEVICE_0
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|NegotiatedParameters
decl_stmt|;
comment|/* 04h */
name|U32
name|Information
decl_stmt|;
comment|/* 08h */
block|}
name|CONFIG_PAGE_SCSI_DEVICE_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SCSI_DEVICE_0
operator|,
name|SCSIDevicePage0_t
operator|,
name|MPI_POINTER
name|pSCSIDevicePage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_PAGEVERSION
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_IU
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_DT
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_QAS
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_HOLD_MCS
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_WR_FLOW
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_RD_STRM
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_RTI
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_PCOMP_EN
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_NEG_SYNC_PERIOD_MASK
value|(0x0000FF00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_SHIFT_SYNC_PERIOD
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_NEG_SYNC_OFFSET_MASK
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_SHIFT_SYNC_OFFSET
value|(16)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_IDP
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_WIDE
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_NP_AIP
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_INFO_PARAMS_NEGOTIATED
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_INFO_SDTR_REJECTED
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_INFO_WDTR_REJECTED
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE0_INFO_PPR_REJECTED
value|(0x00000008)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SCSI_DEVICE_1
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|RequestedParameters
decl_stmt|;
comment|/* 04h */
name|U32
name|Reserved
decl_stmt|;
comment|/* 08h */
name|U32
name|Configuration
decl_stmt|;
comment|/* 0Ch */
block|}
name|CONFIG_PAGE_SCSI_DEVICE_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SCSI_DEVICE_1
operator|,
name|SCSIDevicePage1_t
operator|,
name|MPI_POINTER
name|pSCSIDevicePage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_PAGEVERSION
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_IU
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_DT
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_QAS
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_HOLD_MCS
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_WR_FLOW
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_RD_STRM
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_RTI
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_PCOMP_EN
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_MIN_SYNC_PERIOD_MASK
value|(0x0000FF00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_SHIFT_MIN_SYNC_PERIOD
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_MAX_SYNC_OFFSET_MASK
value|(0x00FF0000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_SHIFT_MAX_SYNC_OFFSET
value|(16)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_IDP
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_WIDE
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_RP_AIP
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_CONF_WDTR_DISALLOWED
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_CONF_SDTR_DISALLOWED
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_CONF_EXTENDED_PARAMS_ENABLE
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE1_CONF_FORCE_PPR_MSG
value|(0x00000010)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SCSI_DEVICE_2
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|DomainValidation
decl_stmt|;
comment|/* 04h */
name|U32
name|ParityPipeSelect
decl_stmt|;
comment|/* 08h */
name|U32
name|DataPipeSelect
decl_stmt|;
comment|/* 0Ch */
block|}
name|CONFIG_PAGE_SCSI_DEVICE_2
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SCSI_DEVICE_2
operator|,
name|SCSIDevicePage2_t
operator|,
name|MPI_POINTER
name|pSCSIDevicePage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_PAGEVERSION
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DV_ISI_ENABLE
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DV_SECONDARY_DRIVER_ENABLE
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DV_SLEW_RATE_CTRL
value|(0x00000380)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DV_PRIM_DRIVE_STR_CTRL
value|(0x00001C00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DV_SECOND_DRIVE_STR_CTRL
value|(0x0000E000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DV_XCLKH_ST
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DV_XCLKS_ST
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DV_XCLKH_DT
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DV_XCLKS_DT
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_PPS_PPS_MASK
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_0_PL_SELECT_MASK
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_1_PL_SELECT_MASK
value|(0x0000000C)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_2_PL_SELECT_MASK
value|(0x00000030)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_3_PL_SELECT_MASK
value|(0x000000C0)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_4_PL_SELECT_MASK
value|(0x00000300)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_5_PL_SELECT_MASK
value|(0x00000C00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_6_PL_SELECT_MASK
value|(0x00003000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_7_PL_SELECT_MASK
value|(0x0000C000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_8_PL_SELECT_MASK
value|(0x00030000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_9_PL_SELECT_MASK
value|(0x000C0000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_10_PL_SELECT_MASK
value|(0x00300000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_11_PL_SELECT_MASK
value|(0x00C00000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_12_PL_SELECT_MASK
value|(0x03000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_13_PL_SELECT_MASK
value|(0x0C000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_14_PL_SELECT_MASK
value|(0x30000000)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE2_DPS_BIT_15_PL_SELECT_MASK
value|(0xC0000000)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SCSI_DEVICE_3
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U16
name|MsgRejectCount
decl_stmt|;
comment|/* 04h */
name|U16
name|PhaseErrorCount
decl_stmt|;
comment|/* 06h */
name|U16
name|ParityErrorCount
decl_stmt|;
comment|/* 08h */
name|U16
name|Reserved
decl_stmt|;
comment|/* 0Ah */
block|}
name|CONFIG_PAGE_SCSI_DEVICE_3
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SCSI_DEVICE_3
operator|,
name|SCSIDevicePage3_t
operator|,
name|MPI_POINTER
name|pSCSIDevicePage3_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE3_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE3_MAX_COUNTER
value|(0xFFFE)
end_define

begin_define
define|#
directive|define
name|MPI_SCSIDEVPAGE3_UNSUPPORTED_COUNTER
value|(0xFFFF)
end_define

begin_comment
comment|/**************************************************************************** *   FC Port Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_0
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Flags
decl_stmt|;
comment|/* 04h */
name|U8
name|MPIPortNumber
decl_stmt|;
comment|/* 08h */
name|U8
name|LinkType
decl_stmt|;
comment|/* 09h */
name|U8
name|PortState
decl_stmt|;
comment|/* 0Ah */
name|U8
name|Reserved
decl_stmt|;
comment|/* 0Bh */
name|U32
name|PortIdentifier
decl_stmt|;
comment|/* 0Ch */
name|U64
name|WWNN
decl_stmt|;
comment|/* 10h */
name|U64
name|WWPN
decl_stmt|;
comment|/* 18h */
name|U32
name|SupportedServiceClass
decl_stmt|;
comment|/* 20h */
name|U32
name|SupportedSpeeds
decl_stmt|;
comment|/* 24h */
name|U32
name|CurrentSpeed
decl_stmt|;
comment|/* 28h */
name|U32
name|MaxFrameSize
decl_stmt|;
comment|/* 2Ch */
name|U64
name|FabricWWNN
decl_stmt|;
comment|/* 30h */
name|U64
name|FabricWWPN
decl_stmt|;
comment|/* 38h */
name|U32
name|DiscoveredPortsCount
decl_stmt|;
comment|/* 40h */
name|U32
name|MaxInitiators
decl_stmt|;
comment|/* 44h */
name|U8
name|MaxAliasesSupported
decl_stmt|;
comment|/* 48h */
name|U8
name|MaxHardAliasesSupported
decl_stmt|;
comment|/* 49h */
name|U8
name|NumCurrentAliases
decl_stmt|;
comment|/* 4Ah */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 4Bh */
block|}
name|CONFIG_PAGE_FC_PORT_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_0
operator|,
name|FCPortPage0_t
operator|,
name|MPI_POINTER
name|pFCPortPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_PAGEVERSION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_PROT_MASK
value|(0x0000000F)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_PROT_FCP_INIT
value|(MPI_PORTFACTS_PROTOCOL_INITIATOR)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_PROT_FCP_TARG
value|(MPI_PORTFACTS_PROTOCOL_TARGET)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_PROT_LAN
value|(MPI_PORTFACTS_PROTOCOL_LAN)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_PROT_LOGBUSADDR
value|(MPI_PORTFACTS_PROTOCOL_LOGBUSADDR)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_ALIAS_ALPA_SUPPORTED
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_ALIAS_WWN_SUPPORTED
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_FABRIC_WWN_VALID
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_ATTACH_TYPE_MASK
value|(0x00000F00)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_ATTACH_NO_INIT
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_ATTACH_POINT_TO_POINT
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_ATTACH_PRIVATE_LOOP
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_ATTACH_FABRIC_DIRECT
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_FLAGS_ATTACH_PUBLIC_LOOP
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_RESERVED
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_OTHER
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_UNKNOWN
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_COPPER
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_SINGLE_1300
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_SINGLE_1500
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_50_LASER_MULTI
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_50_LED_MULTI
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_62_LASER_MULTI
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_62_LED_MULTI
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_MULTI_LONG_WAVE
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_MULTI_SHORT_WAVE
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_LASER_SHORT_WAVE
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_LED_SHORT_WAVE
value|(0x0D)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_1300_LONG_WAVE
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_LTYPE_1500_LONG_WAVE
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_PORTSTATE_UNKNOWN
value|(0x01)
end_define

begin_comment
comment|/*(SNIA)HBA_PORTSTATE_UNKNOWN       1 Unknown */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_PORTSTATE_ONLINE
value|(0x02)
end_define

begin_comment
comment|/*(SNIA)HBA_PORTSTATE_ONLINE        2 Operational */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_PORTSTATE_OFFLINE
value|(0x03)
end_define

begin_comment
comment|/*(SNIA)HBA_PORTSTATE_OFFLINE       3 User Offline */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_PORTSTATE_BYPASSED
value|(0x04)
end_define

begin_comment
comment|/*(SNIA)HBA_PORTSTATE_BYPASSED      4 Bypassed */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_PORTSTATE_DIAGNOST
value|(0x05)
end_define

begin_comment
comment|/*(SNIA)HBA_PORTSTATE_DIAGNOSTICS   5 In diagnostics mode */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_PORTSTATE_LINKDOWN
value|(0x06)
end_define

begin_comment
comment|/*(SNIA)HBA_PORTSTATE_LINKDOWN      6 Link Down */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_PORTSTATE_ERROR
value|(0x07)
end_define

begin_comment
comment|/*(SNIA)HBA_PORTSTATE_ERROR         7 Port Error */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_PORTSTATE_LOOPBACK
value|(0x08)
end_define

begin_comment
comment|/*(SNIA)HBA_PORTSTATE_LOOPBACK      8 Loopback */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_SUPPORT_CLASS_1
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_SUPPORT_CLASS_2
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_SUPPORT_CLASS_3
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_SUPPORT_SPEED_UKNOWN
value|(0x00000000)
end_define

begin_comment
comment|/* (SNIA)HBA_PORTSPEED_UNKNOWN 0   Unknown - transceiver incapable of reporting */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_SUPPORT_1GBIT_SPEED
value|(0x00000001)
end_define

begin_comment
comment|/* (SNIA)HBA_PORTSPEED_1GBIT 1  1 GBit/sec  */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_SUPPORT_2GBIT_SPEED
value|(0x00000002)
end_define

begin_comment
comment|/* (SNIA)HBA_PORTSPEED_2GBIT 2  2 GBit/sec  */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_SUPPORT_10GBIT_SPEED
value|(0x00000004)
end_define

begin_comment
comment|/* (SNIA)HBA_PORTSPEED_10GBIT 4 10 GBit/sec */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_SUPPORT_4GBIT_SPEED
value|(0x00000008)
end_define

begin_comment
comment|/* (SNIA)HBA_PORTSPEED_4GBIT   8   4 GBit/sec */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_CURRENT_SPEED_UKNOWN
value|MPI_FCPORTPAGE0_SUPPORT_SPEED_UKNOWN
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_CURRENT_SPEED_1GBIT
value|MPI_FCPORTPAGE0_SUPPORT_1GBIT_SPEED
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_CURRENT_SPEED_2GBIT
value|MPI_FCPORTPAGE0_SUPPORT_2GBIT_SPEED
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_CURRENT_SPEED_10GBIT
value|MPI_FCPORTPAGE0_SUPPORT_10GBIT_SPEED
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_CURRENT_SPEED_4GBIT
value|MPI_FCPORTPAGE0_SUPPORT_4GBIT_SPEED
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE0_CURRENT_SPEED_NOT_NEGOTIATED
value|(0x00008000)
end_define

begin_comment
comment|/* (SNIA)HBA_PORTSPEED_NOT_NEGOTIATED (1<<15) Speed not established */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_1
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Flags
decl_stmt|;
comment|/* 04h */
name|U64
name|NoSEEPROMWWNN
decl_stmt|;
comment|/* 08h */
name|U64
name|NoSEEPROMWWPN
decl_stmt|;
comment|/* 10h */
name|U8
name|HardALPA
decl_stmt|;
comment|/* 18h */
name|U8
name|LinkConfig
decl_stmt|;
comment|/* 19h */
name|U8
name|TopologyConfig
decl_stmt|;
comment|/* 1Ah */
name|U8
name|AltConnector
decl_stmt|;
comment|/* 1Bh */
name|U8
name|NumRequestedAliases
decl_stmt|;
comment|/* 1Ch */
name|U8
name|RR_TOV
decl_stmt|;
comment|/* 1Dh */
name|U8
name|InitiatorDeviceTimeout
decl_stmt|;
comment|/* 1Eh */
name|U8
name|InitiatorIoPendTimeout
decl_stmt|;
comment|/* 1Fh */
block|}
name|CONFIG_PAGE_FC_PORT_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_1
operator|,
name|FCPortPage1_t
operator|,
name|MPI_POINTER
name|pFCPortPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_PAGEVERSION
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_EXT_FCP_STATUS_EN
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_IMMEDIATE_ERROR_REPLY
value|(0x04000000)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_FORCE_USE_NOSEEPROM_WWNS
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_VERBOSE_RESCAN_EVENTS
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_TARGET_MODE_OXID
value|(0x00800000)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_PORT_OFFLINE
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_SOFT_ALPA_FALLBACK
value|(0x00200000)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_TARGET_LARGE_CDB_ENABLE
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_MASK_RR_TOV_UNITS
value|(0x00000070)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_SUPPRESS_PROT_REG
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_PLOGI_ON_LOGO
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_MAINTAIN_LOGINS
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_SORT_BY_DID
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_SORT_BY_WWN
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_PROT_MASK
value|(0xF0000000)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_PROT_SHIFT
value|(28)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_PROT_FCP_INIT
value|((U32)MPI_PORTFACTS_PROTOCOL_INITIATOR<< MPI_FCPORTPAGE1_FLAGS_PROT_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_PROT_FCP_TARG
value|((U32)MPI_PORTFACTS_PROTOCOL_TARGET<< MPI_FCPORTPAGE1_FLAGS_PROT_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_PROT_LAN
value|((U32)MPI_PORTFACTS_PROTOCOL_LAN<< MPI_FCPORTPAGE1_FLAGS_PROT_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_PROT_LOGBUSADDR
value|((U32)MPI_PORTFACTS_PROTOCOL_LOGBUSADDR<< MPI_FCPORTPAGE1_FLAGS_PROT_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_NONE_RR_TOV_UNITS
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_THOUSANDTH_RR_TOV_UNITS
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_TENTH_RR_TOV_UNITS
value|(0x00000030)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_FLAGS_TEN_RR_TOV_UNITS
value|(0x00000050)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_HARD_ALPA_NOT_USED
value|(0xFF)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_LCONFIG_SPEED_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_LCONFIG_SPEED_1GIG
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_LCONFIG_SPEED_2GIG
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_LCONFIG_SPEED_4GIG
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_LCONFIG_SPEED_10GIG
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_LCONFIG_SPEED_AUTO
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_TOPOLOGY_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_TOPOLOGY_NLPORT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_TOPOLOGY_NPORT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_TOPOLOGY_AUTO
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_ALT_CONN_UNKNOWN
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_INITIATOR_DEV_TIMEOUT_MASK
value|(0x7F)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE1_INITIATOR_DEV_UNIT_16
value|(0x80)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_2
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|NumberActive
decl_stmt|;
comment|/* 04h */
name|U8
name|ALPA
index|[
literal|127
index|]
decl_stmt|;
comment|/* 05h */
block|}
name|CONFIG_PAGE_FC_PORT_2
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_2
operator|,
name|FCPortPage2_t
operator|,
name|MPI_POINTER
name|pFCPortPage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE2_PAGEVERSION
value|(0x01)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_WWN_FORMAT
block|{
name|U64
name|WWNN
decl_stmt|;
comment|/* 00h */
name|U64
name|WWPN
decl_stmt|;
comment|/* 08h */
block|}
name|WWN_FORMAT
operator|,
name|MPI_POINTER
name|PTR_WWN_FORMAT
operator|,
name|WWNFormat
operator|,
name|MPI_POINTER
name|pWWNFormat
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|_FC_PORT_PERSISTENT_PHYSICAL_ID
block|{
name|WWN_FORMAT
name|WWN
decl_stmt|;
name|U32
name|Did
decl_stmt|;
block|}
name|FC_PORT_PERSISTENT_PHYSICAL_ID
operator|,
name|MPI_POINTER
name|PTR_FC_PORT_PERSISTENT_PHYSICAL_ID
operator|,
name|PersistentPhysicalId_t
operator|,
name|MPI_POINTER
name|pPersistentPhysicalId_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_FC_PORT_PERSISTENT
block|{
name|FC_PORT_PERSISTENT_PHYSICAL_ID
name|PhysicalIdentifier
decl_stmt|;
comment|/* 00h */
name|U8
name|TargetID
decl_stmt|;
comment|/* 10h */
name|U8
name|Bus
decl_stmt|;
comment|/* 11h */
name|U16
name|Flags
decl_stmt|;
comment|/* 12h */
block|}
name|FC_PORT_PERSISTENT
operator|,
name|MPI_POINTER
name|PTR_FC_PORT_PERSISTENT
operator|,
name|PersistentData_t
operator|,
name|MPI_POINTER
name|pPersistentData_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_PERSISTENT_FLAGS_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|MPI_PERSISTENT_FLAGS_ENTRY_VALID
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI_PERSISTENT_FLAGS_SCAN_ID
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_PERSISTENT_FLAGS_SCAN_LUNS
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI_PERSISTENT_FLAGS_BOOT_DEVICE
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI_PERSISTENT_FLAGS_BY_DID
value|(0x0080)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check Header.PageLength at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_FC_PORT_PAGE_3_ENTRY_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI_FC_PORT_PAGE_3_ENTRY_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_3
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|FC_PORT_PERSISTENT
name|Entry
index|[
name|MPI_FC_PORT_PAGE_3_ENTRY_MAX
index|]
decl_stmt|;
comment|/* 04h */
block|}
name|CONFIG_PAGE_FC_PORT_3
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_3
operator|,
name|FCPortPage3_t
operator|,
name|MPI_POINTER
name|pFCPortPage3_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE3_PAGEVERSION
value|(0x01)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_4
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|PortFlags
decl_stmt|;
comment|/* 04h */
name|U32
name|PortSettings
decl_stmt|;
comment|/* 08h */
block|}
name|CONFIG_PAGE_FC_PORT_4
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_4
operator|,
name|FCPortPage4_t
operator|,
name|MPI_POINTER
name|pFCPortPage4_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE4_PAGEVERSION
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE4_PORT_FLAGS_ALTERNATE_CHS
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE4_PORT_MASK_INIT_HBA
value|(0x00000030)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE4_PORT_DISABLE_INIT_HBA
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE4_PORT_BIOS_INIT_HBA
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE4_PORT_OS_INIT_HBA
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE4_PORT_BIOS_OS_INIT_HBA
value|(0x00000030)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE4_PORT_REMOVABLE_MEDIA
value|(0x000000C0)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE4_PORT_SPINUP_DELAY_MASK
value|(0x00000F00)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_5_ALIAS_INFO
block|{
name|U8
name|Flags
decl_stmt|;
comment|/* 00h */
name|U8
name|AliasAlpa
decl_stmt|;
comment|/* 01h */
name|U16
name|Reserved
decl_stmt|;
comment|/* 02h */
name|U64
name|AliasWWNN
decl_stmt|;
comment|/* 04h */
name|U64
name|AliasWWPN
decl_stmt|;
comment|/* 0Ch */
block|}
name|CONFIG_PAGE_FC_PORT_5_ALIAS_INFO
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_5_ALIAS_INFO
operator|,
name|FcPortPage5AliasInfo_t
operator|,
name|MPI_POINTER
name|pFcPortPage5AliasInfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_5
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|CONFIG_PAGE_FC_PORT_5_ALIAS_INFO
name|AliasInfo
decl_stmt|;
comment|/* 04h */
block|}
name|CONFIG_PAGE_FC_PORT_5
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_5
operator|,
name|FCPortPage5_t
operator|,
name|MPI_POINTER
name|pFCPortPage5_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE5_PAGEVERSION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE5_FLAGS_ALPA_ACQUIRED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE5_FLAGS_HARD_ALPA
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE5_FLAGS_HARD_WWNN
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE5_FLAGS_HARD_WWPN
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE5_FLAGS_DISABLE
value|(0x10)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_6
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved
decl_stmt|;
comment|/* 04h */
name|U64
name|TimeSinceReset
decl_stmt|;
comment|/* 08h */
name|U64
name|TxFrames
decl_stmt|;
comment|/* 10h */
name|U64
name|RxFrames
decl_stmt|;
comment|/* 18h */
name|U64
name|TxWords
decl_stmt|;
comment|/* 20h */
name|U64
name|RxWords
decl_stmt|;
comment|/* 28h */
name|U64
name|LipCount
decl_stmt|;
comment|/* 30h */
name|U64
name|NosCount
decl_stmt|;
comment|/* 38h */
name|U64
name|ErrorFrames
decl_stmt|;
comment|/* 40h */
name|U64
name|DumpedFrames
decl_stmt|;
comment|/* 48h */
name|U64
name|LinkFailureCount
decl_stmt|;
comment|/* 50h */
name|U64
name|LossOfSyncCount
decl_stmt|;
comment|/* 58h */
name|U64
name|LossOfSignalCount
decl_stmt|;
comment|/* 60h */
name|U64
name|PrimativeSeqErrCount
decl_stmt|;
comment|/* 68h */
name|U64
name|InvalidTxWordCount
decl_stmt|;
comment|/* 70h */
name|U64
name|InvalidCrcCount
decl_stmt|;
comment|/* 78h */
name|U64
name|FcpInitiatorIoCount
decl_stmt|;
comment|/* 80h */
block|}
name|CONFIG_PAGE_FC_PORT_6
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_6
operator|,
name|FCPortPage6_t
operator|,
name|MPI_POINTER
name|pFCPortPage6_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE6_PAGEVERSION
value|(0x00)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_7
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved
decl_stmt|;
comment|/* 04h */
name|U8
name|PortSymbolicName
index|[
literal|256
index|]
decl_stmt|;
comment|/* 08h */
block|}
name|CONFIG_PAGE_FC_PORT_7
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_7
operator|,
name|FCPortPage7_t
operator|,
name|MPI_POINTER
name|pFCPortPage7_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE7_PAGEVERSION
value|(0x00)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_8
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|BitVector
index|[
literal|8
index|]
decl_stmt|;
comment|/* 04h */
block|}
name|CONFIG_PAGE_FC_PORT_8
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_8
operator|,
name|FCPortPage8_t
operator|,
name|MPI_POINTER
name|pFCPortPage8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE8_PAGEVERSION
value|(0x00)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_9
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved
decl_stmt|;
comment|/* 04h */
name|U64
name|GlobalWWPN
decl_stmt|;
comment|/* 08h */
name|U64
name|GlobalWWNN
decl_stmt|;
comment|/* 10h */
name|U32
name|UnitType
decl_stmt|;
comment|/* 18h */
name|U32
name|PhysicalPortNumber
decl_stmt|;
comment|/* 1Ch */
name|U32
name|NumAttachedNodes
decl_stmt|;
comment|/* 20h */
name|U16
name|IPVersion
decl_stmt|;
comment|/* 24h */
name|U16
name|UDPPortNumber
decl_stmt|;
comment|/* 26h */
name|U8
name|IPAddress
index|[
literal|16
index|]
decl_stmt|;
comment|/* 28h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 38h */
name|U16
name|TopologyDiscoveryFlags
decl_stmt|;
comment|/* 3Ah */
block|}
name|CONFIG_PAGE_FC_PORT_9
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_9
operator|,
name|FCPortPage9_t
operator|,
name|MPI_POINTER
name|pFCPortPage9_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE9_PAGEVERSION
value|(0x00)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_10_BASE_SFP_DATA
block|{
name|U8
name|Id
decl_stmt|;
comment|/* 10h */
name|U8
name|ExtId
decl_stmt|;
comment|/* 11h */
name|U8
name|Connector
decl_stmt|;
comment|/* 12h */
name|U8
name|Transceiver
index|[
literal|8
index|]
decl_stmt|;
comment|/* 13h */
name|U8
name|Encoding
decl_stmt|;
comment|/* 1Bh */
name|U8
name|BitRate_100mbs
decl_stmt|;
comment|/* 1Ch */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 1Dh */
name|U8
name|Length9u_km
decl_stmt|;
comment|/* 1Eh */
name|U8
name|Length9u_100m
decl_stmt|;
comment|/* 1Fh */
name|U8
name|Length50u_10m
decl_stmt|;
comment|/* 20h */
name|U8
name|Length62p5u_10m
decl_stmt|;
comment|/* 21h */
name|U8
name|LengthCopper_m
decl_stmt|;
comment|/* 22h */
name|U8
name|Reseverved2
decl_stmt|;
comment|/* 22h */
name|U8
name|VendorName
index|[
literal|16
index|]
decl_stmt|;
comment|/* 24h */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 34h */
name|U8
name|VendorOUI
index|[
literal|3
index|]
decl_stmt|;
comment|/* 35h */
name|U8
name|VendorPN
index|[
literal|16
index|]
decl_stmt|;
comment|/* 38h */
name|U8
name|VendorRev
index|[
literal|4
index|]
decl_stmt|;
comment|/* 48h */
name|U16
name|Wavelength
decl_stmt|;
comment|/* 4Ch */
name|U8
name|Reserved4
decl_stmt|;
comment|/* 4Eh */
name|U8
name|CC_BASE
decl_stmt|;
comment|/* 4Fh */
block|}
name|CONFIG_PAGE_FC_PORT_10_BASE_SFP_DATA
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_10_BASE_SFP_DATA
operator|,
name|FCPortPage10BaseSfpData_t
operator|,
name|MPI_POINTER
name|pFCPortPage10BaseSfpData_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_ID_UNKNOWN
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_ID_GBIC
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_ID_FIXED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_ID_SFP
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_ID_SFP_MIN
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_ID_SFP_MAX
value|(0x7F)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_ID_VEND_SPEC_MASK
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_EXTID_UNKNOWN
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_EXTID_MODDEF1
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_EXTID_MODDEF2
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_EXTID_MODDEF3
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_EXTID_SEEPROM
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_EXTID_MODDEF5
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_EXTID_MODDEF6
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_EXTID_MODDEF7
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_EXTID_VNDSPC_MASK
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_UNKNOWN
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_SC
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_COPPER1
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_COPPER2
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_BNC_TNC
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_COAXIAL
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_FIBERJACK
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_LC
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_MT_RJ
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_MU
value|(0x09)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_SG
value|(0x0A)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_OPT_PIGT
value|(0x0B)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_RSV1_MIN
value|(0x0C)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_RSV1_MAX
value|(0x1F)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_HSSDC_II
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_CPR_PIGT
value|(0x21)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_RSV2_MIN
value|(0x22)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_RSV2_MAX
value|(0x7F)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_CONN_VNDSPC_MASK
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_ENCODE_UNSPEC
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_ENCODE_8B10B
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_ENCODE_4B5B
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_ENCODE_NRZ
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_BASE_ENCODE_MANCHESTER
value|(0x04)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_10_EXTENDED_SFP_DATA
block|{
name|U8
name|Options
index|[
literal|2
index|]
decl_stmt|;
comment|/* 50h */
name|U8
name|BitRateMax
decl_stmt|;
comment|/* 52h */
name|U8
name|BitRateMin
decl_stmt|;
comment|/* 53h */
name|U8
name|VendorSN
index|[
literal|16
index|]
decl_stmt|;
comment|/* 54h */
name|U8
name|DateCode
index|[
literal|8
index|]
decl_stmt|;
comment|/* 64h */
name|U8
name|DiagMonitoringType
decl_stmt|;
comment|/* 6Ch */
name|U8
name|EnhancedOptions
decl_stmt|;
comment|/* 6Dh */
name|U8
name|SFF8472Compliance
decl_stmt|;
comment|/* 6Eh */
name|U8
name|CC_EXT
decl_stmt|;
comment|/* 6Fh */
block|}
name|CONFIG_PAGE_FC_PORT_10_EXTENDED_SFP_DATA
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_10_EXTENDED_SFP_DATA
operator|,
name|FCPortPage10ExtendedSfpData_t
operator|,
name|MPI_POINTER
name|pFCPortPage10ExtendedSfpData_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FCPORT10_EXT_OPTION1_RATESEL
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_EXT_OPTION1_TX_DISABLE
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_EXT_OPTION1_TX_FAULT
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_EXT_OPTION1_LOS_INVERT
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORT10_EXT_OPTION1_LOS
value|(0x02)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_PORT_10
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|Flags
decl_stmt|;
comment|/* 04h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 06h */
name|U32
name|HwConfig1
decl_stmt|;
comment|/* 08h */
name|U32
name|HwConfig2
decl_stmt|;
comment|/* 0Ch */
name|CONFIG_PAGE_FC_PORT_10_BASE_SFP_DATA
name|Base
decl_stmt|;
comment|/* 10h */
name|CONFIG_PAGE_FC_PORT_10_EXTENDED_SFP_DATA
name|Extended
decl_stmt|;
comment|/* 50h */
name|U8
name|VendorSpecific
index|[
literal|32
index|]
decl_stmt|;
comment|/* 70h */
block|}
name|CONFIG_PAGE_FC_PORT_10
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_PORT_10
operator|,
name|FCPortPage10_t
operator|,
name|MPI_POINTER
name|pFCPortPage10_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/* standard MODDEF pin definitions (from GBIC spec.) */
end_comment

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_MODDEF_MASK
value|(0x00000007)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_MODDEF2
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_MODDEF1
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_MODDEF0
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_MODDEF_NOGBIC
value|(0x00000007)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_MODDEF_CPR_IEEE_CX
value|(0x00000006)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_MODDEF_COPPER
value|(0x00000005)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_MODDEF_OPTICAL_LW
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_MODDEF_SEEPROM
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_MODDEF_SW_OPTICAL
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_MODDEF_LX_IEEE_OPT_LW
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_MODDEF_SX_IEEE_OPT_SW
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_CC_BASE_OK
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_FCPORTPAGE10_FLAGS_CC_EXT_OK
value|(0x00000020)
end_define

begin_comment
comment|/**************************************************************************** *   FC Device Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_FC_DEVICE_0
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U64
name|WWNN
decl_stmt|;
comment|/* 04h */
name|U64
name|WWPN
decl_stmt|;
comment|/* 0Ch */
name|U32
name|PortIdentifier
decl_stmt|;
comment|/* 14h */
name|U8
name|Protocol
decl_stmt|;
comment|/* 18h */
name|U8
name|Flags
decl_stmt|;
comment|/* 19h */
name|U16
name|BBCredit
decl_stmt|;
comment|/* 1Ah */
name|U16
name|MaxRxFrameSize
decl_stmt|;
comment|/* 1Ch */
name|U8
name|ADISCHardALPA
decl_stmt|;
comment|/* 1Eh */
name|U8
name|PortNumber
decl_stmt|;
comment|/* 1Fh */
name|U8
name|FcPhLowestVersion
decl_stmt|;
comment|/* 20h */
name|U8
name|FcPhHighestVersion
decl_stmt|;
comment|/* 21h */
name|U8
name|CurrentTargetID
decl_stmt|;
comment|/* 22h */
name|U8
name|CurrentBus
decl_stmt|;
comment|/* 23h */
block|}
name|CONFIG_PAGE_FC_DEVICE_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_FC_DEVICE_0
operator|,
name|FCDevicePage0_t
operator|,
name|MPI_POINTER
name|pFCDevicePage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_PAGEVERSION
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_FLAGS_TARGETID_BUS_VALID
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_FLAGS_PLOGI_INVALID
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_FLAGS_PRLI_INVALID
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_PROT_IP
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_PROT_FCP_TARGET
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_PROT_FCP_INITIATOR
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_PROT_FCP_RETRY
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_PGAD_PORT_MASK
value|(MPI_FC_DEVICE_PGAD_PORT_MASK)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_PGAD_FORM_MASK
value|(MPI_FC_DEVICE_PGAD_FORM_MASK)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_PGAD_FORM_NEXT_DID
value|(MPI_FC_DEVICE_PGAD_FORM_NEXT_DID)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_PGAD_FORM_BUS_TID
value|(MPI_FC_DEVICE_PGAD_FORM_BUS_TID)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_PGAD_DID_MASK
value|(MPI_FC_DEVICE_PGAD_ND_DID_MASK)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_PGAD_BUS_MASK
value|(MPI_FC_DEVICE_PGAD_BT_BUS_MASK)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_PGAD_BUS_SHIFT
value|(MPI_FC_DEVICE_PGAD_BT_BUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_PGAD_TID_MASK
value|(MPI_FC_DEVICE_PGAD_BT_TID_MASK)
end_define

begin_define
define|#
directive|define
name|MPI_FC_DEVICE_PAGE0_HARD_ALPA_UNKNOWN
value|(0xFF)
end_define

begin_comment
comment|/**************************************************************************** *   RAID Volume Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_RAID_VOL0_PHYS_DISK
block|{
name|U16
name|Reserved
decl_stmt|;
comment|/* 00h */
name|U8
name|PhysDiskMap
decl_stmt|;
comment|/* 02h */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 03h */
block|}
name|RAID_VOL0_PHYS_DISK
operator|,
name|MPI_POINTER
name|PTR_RAID_VOL0_PHYS_DISK
operator|,
name|RaidVol0PhysDisk_t
operator|,
name|MPI_POINTER
name|pRaidVol0PhysDisk_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_PHYSDISK_PRIMARY
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_PHYSDISK_SECONDARY
value|(0x02)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_RAID_VOL0_STATUS
block|{
name|U8
name|Flags
decl_stmt|;
comment|/* 00h */
name|U8
name|State
decl_stmt|;
comment|/* 01h */
name|U16
name|Reserved
decl_stmt|;
comment|/* 02h */
block|}
name|RAID_VOL0_STATUS
operator|,
name|MPI_POINTER
name|PTR_RAID_VOL0_STATUS
operator|,
name|RaidVol0Status_t
operator|,
name|MPI_POINTER
name|pRaidVol0Status_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Volume Page 0 VolumeStatus defines */
end_comment

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_STATUS_FLAG_ENABLED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_STATUS_FLAG_QUIESCED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_STATUS_FLAG_RESYNC_IN_PROGRESS
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_STATUS_FLAG_VOLUME_INACTIVE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_STATUS_FLAG_BAD_BLOCK_TABLE_FULL
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_STATUS_STATE_OPTIMAL
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_STATUS_STATE_DEGRADED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_STATUS_STATE_FAILED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_STATUS_STATE_MISSING
value|(0x03)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_RAID_VOL0_SETTINGS
block|{
name|U16
name|Settings
decl_stmt|;
comment|/* 00h */
name|U8
name|HotSparePool
decl_stmt|;
comment|/* 01h */
comment|/* MPI_RAID_HOT_SPARE_POOL_ */
name|U8
name|Reserved
decl_stmt|;
comment|/* 02h */
block|}
name|RAID_VOL0_SETTINGS
operator|,
name|MPI_POINTER
name|PTR_RAID_VOL0_SETTINGS
operator|,
name|RaidVol0Settings
operator|,
name|MPI_POINTER
name|pRaidVol0Settings
typedef|;
end_typedef

begin_comment
comment|/* RAID Volume Page 0 VolumeSettings defines */
end_comment

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_SETTING_WRITE_CACHING_ENABLE
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_SETTING_OFFLINE_ON_SMART
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_SETTING_AUTO_CONFIGURE
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_SETTING_PRIORITY_RESYNC
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_SETTING_FAST_DATA_SCRUBBING_0102
value|(0x0020)
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_SETTING_USE_PRODUCT_ID_SUFFIX
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOL0_SETTING_USE_DEFAULTS
value|(0x8000)
end_define

begin_comment
comment|/* RAID Volume Page 0 HotSparePool defines, also used in RAID Physical Disk */
end_comment

begin_define
define|#
directive|define
name|MPI_RAID_HOT_SPARE_POOL_0
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_HOT_SPARE_POOL_1
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_HOT_SPARE_POOL_2
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_HOT_SPARE_POOL_3
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_HOT_SPARE_POOL_4
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_HOT_SPARE_POOL_5
value|(0x20)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_HOT_SPARE_POOL_6
value|(0x40)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_HOT_SPARE_POOL_7
value|(0x80)
end_define

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check Header.PageLength at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_RAID_VOL_PAGE_0_PHYSDISK_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI_RAID_VOL_PAGE_0_PHYSDISK_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_RAID_VOL_0
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|VolumeID
decl_stmt|;
comment|/* 04h */
name|U8
name|VolumeBus
decl_stmt|;
comment|/* 05h */
name|U8
name|VolumeIOC
decl_stmt|;
comment|/* 06h */
name|U8
name|VolumeType
decl_stmt|;
comment|/* 07h */
comment|/* MPI_RAID_VOL_TYPE_ */
name|RAID_VOL0_STATUS
name|VolumeStatus
decl_stmt|;
comment|/* 08h */
name|RAID_VOL0_SETTINGS
name|VolumeSettings
decl_stmt|;
comment|/* 0Ch */
name|U32
name|MaxLBA
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 14h */
name|U32
name|StripeSize
decl_stmt|;
comment|/* 18h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 1Ch */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 20h */
name|U8
name|NumPhysDisks
decl_stmt|;
comment|/* 24h */
name|U8
name|DataScrubRate
decl_stmt|;
comment|/* 25h */
name|U8
name|ResyncRate
decl_stmt|;
comment|/* 26h */
name|U8
name|InactiveStatus
decl_stmt|;
comment|/* 27h */
name|RAID_VOL0_PHYS_DISK
name|PhysDisk
index|[
name|MPI_RAID_VOL_PAGE_0_PHYSDISK_MAX
index|]
decl_stmt|;
comment|/* 28h */
block|}
name|CONFIG_PAGE_RAID_VOL_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_RAID_VOL_0
operator|,
name|RaidVolumePage0_t
operator|,
name|MPI_POINTER
name|pRaidVolumePage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_RAIDVOLPAGE0_PAGEVERSION
value|(0x05)
end_define

begin_comment
comment|/* values for RAID Volume Page 0 InactiveStatus field */
end_comment

begin_define
define|#
directive|define
name|MPI_RAIDVOLPAGE0_UNKNOWN_INACTIVE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOLPAGE0_STALE_METADATA_INACTIVE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOLPAGE0_FOREIGN_VOLUME_INACTIVE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOLPAGE0_INSUFFICIENT_RESOURCE_INACTIVE
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOLPAGE0_CLONE_VOLUME_INACTIVE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOLPAGE0_INSUFFICIENT_METADATA_INACTIVE
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_RAIDVOLPAGE0_PREVIOUSLY_DELETED
value|(0x06)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_RAID_VOL_1
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|VolumeID
decl_stmt|;
comment|/* 01h */
name|U8
name|VolumeBus
decl_stmt|;
comment|/* 02h */
name|U8
name|VolumeIOC
decl_stmt|;
comment|/* 03h */
name|U8
name|Reserved0
decl_stmt|;
comment|/* 04h */
name|U8
name|GUID
index|[
literal|24
index|]
decl_stmt|;
comment|/* 05h */
name|U8
name|Name
index|[
literal|32
index|]
decl_stmt|;
comment|/* 20h */
name|U64
name|WWID
decl_stmt|;
comment|/* 40h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 48h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 4Ch */
block|}
name|CONFIG_PAGE_RAID_VOL_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_RAID_VOL_1
operator|,
name|RaidVolumePage1_t
operator|,
name|MPI_POINTER
name|pRaidVolumePage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_RAIDVOLPAGE1_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/**************************************************************************** *   RAID Physical Disk Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_RAID_PHYS_DISK0_ERROR_DATA
block|{
name|U8
name|ErrorCdbByte
decl_stmt|;
comment|/* 00h */
name|U8
name|ErrorSenseKey
decl_stmt|;
comment|/* 01h */
name|U16
name|Reserved
decl_stmt|;
comment|/* 02h */
name|U16
name|ErrorCount
decl_stmt|;
comment|/* 04h */
name|U8
name|ErrorASC
decl_stmt|;
comment|/* 06h */
name|U8
name|ErrorASCQ
decl_stmt|;
comment|/* 07h */
name|U16
name|SmartCount
decl_stmt|;
comment|/* 08h */
name|U8
name|SmartASC
decl_stmt|;
comment|/* 0Ah */
name|U8
name|SmartASCQ
decl_stmt|;
comment|/* 0Bh */
block|}
name|RAID_PHYS_DISK0_ERROR_DATA
operator|,
name|MPI_POINTER
name|PTR_RAID_PHYS_DISK0_ERROR_DATA
operator|,
name|RaidPhysDisk0ErrorData_t
operator|,
name|MPI_POINTER
name|pRaidPhysDisk0ErrorData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_RAID_PHYS_DISK_INQUIRY_DATA
block|{
name|U8
name|VendorID
index|[
literal|8
index|]
decl_stmt|;
comment|/* 00h */
name|U8
name|ProductID
index|[
literal|16
index|]
decl_stmt|;
comment|/* 08h */
name|U8
name|ProductRevLevel
index|[
literal|4
index|]
decl_stmt|;
comment|/* 18h */
name|U8
name|Info
index|[
literal|32
index|]
decl_stmt|;
comment|/* 1Ch */
block|}
name|RAID_PHYS_DISK0_INQUIRY_DATA
operator|,
name|MPI_POINTER
name|PTR_RAID_PHYS_DISK0_INQUIRY_DATA
operator|,
name|RaidPhysDisk0InquiryData
operator|,
name|MPI_POINTER
name|pRaidPhysDisk0InquiryData
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_RAID_PHYS_DISK0_SETTINGS
block|{
name|U8
name|SepID
decl_stmt|;
comment|/* 00h */
name|U8
name|SepBus
decl_stmt|;
comment|/* 01h */
name|U8
name|HotSparePool
decl_stmt|;
comment|/* 02h */
comment|/* MPI_RAID_HOT_SPARE_POOL_ */
name|U8
name|PhysDiskSettings
decl_stmt|;
comment|/* 03h */
block|}
name|RAID_PHYS_DISK0_SETTINGS
operator|,
name|MPI_POINTER
name|PTR_RAID_PHYS_DISK0_SETTINGS
operator|,
name|RaidPhysDiskSettings_t
operator|,
name|MPI_POINTER
name|pRaidPhysDiskSettings_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_RAID_PHYS_DISK0_STATUS
block|{
name|U8
name|Flags
decl_stmt|;
comment|/* 00h */
name|U8
name|State
decl_stmt|;
comment|/* 01h */
name|U16
name|Reserved
decl_stmt|;
comment|/* 02h */
block|}
name|RAID_PHYS_DISK0_STATUS
operator|,
name|MPI_POINTER
name|PTR_RAID_PHYS_DISK0_STATUS
operator|,
name|RaidPhysDiskStatus_t
operator|,
name|MPI_POINTER
name|pRaidPhysDiskStatus_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Volume 2 IM Physical Disk DiskStatus flags */
end_comment

begin_define
define|#
directive|define
name|MPI_PHYSDISK0_STATUS_FLAG_OUT_OF_SYNC
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK0_STATUS_FLAG_QUIESCED
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK0_STATUS_FLAG_INACTIVE_VOLUME
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK0_STATUS_FLAG_OPTIMAL_PREVIOUS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK0_STATUS_FLAG_NOT_OPTIMAL_PREVIOUS
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK0_STATUS_ONLINE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK0_STATUS_MISSING
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK0_STATUS_NOT_COMPATIBLE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK0_STATUS_FAILED
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK0_STATUS_INITIALIZING
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK0_STATUS_OFFLINE_REQUESTED
value|(0x05)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK0_STATUS_FAILED_REQUESTED
value|(0x06)
end_define

begin_define
define|#
directive|define
name|MPI_PHYSDISK0_STATUS_OTHER_OFFLINE
value|(0xFF)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_RAID_PHYS_DISK_0
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|PhysDiskID
decl_stmt|;
comment|/* 04h */
name|U8
name|PhysDiskBus
decl_stmt|;
comment|/* 05h */
name|U8
name|PhysDiskIOC
decl_stmt|;
comment|/* 06h */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 07h */
name|RAID_PHYS_DISK0_SETTINGS
name|PhysDiskSettings
decl_stmt|;
comment|/* 08h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0Ch */
name|U8
name|ExtDiskIdentifier
index|[
literal|8
index|]
decl_stmt|;
comment|/* 10h */
name|U8
name|DiskIdentifier
index|[
literal|16
index|]
decl_stmt|;
comment|/* 18h */
name|RAID_PHYS_DISK0_INQUIRY_DATA
name|InquiryData
decl_stmt|;
comment|/* 28h */
name|RAID_PHYS_DISK0_STATUS
name|PhysDiskStatus
decl_stmt|;
comment|/* 64h */
name|U32
name|MaxLBA
decl_stmt|;
comment|/* 68h */
name|RAID_PHYS_DISK0_ERROR_DATA
name|ErrorData
decl_stmt|;
comment|/* 6Ch */
block|}
name|CONFIG_PAGE_RAID_PHYS_DISK_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_RAID_PHYS_DISK_0
operator|,
name|RaidPhysDiskPage0_t
operator|,
name|MPI_POINTER
name|pRaidPhysDiskPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_RAIDPHYSDISKPAGE0_PAGEVERSION
value|(0x02)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_RAID_PHYS_DISK1_PATH
block|{
name|U8
name|PhysDiskID
decl_stmt|;
comment|/* 00h */
name|U8
name|PhysDiskBus
decl_stmt|;
comment|/* 01h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 02h */
name|U64
name|WWID
decl_stmt|;
comment|/* 04h */
name|U64
name|OwnerWWID
decl_stmt|;
comment|/* 0Ch */
name|U8
name|OwnerIdentifier
decl_stmt|;
comment|/* 14h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 15h */
name|U16
name|Flags
decl_stmt|;
comment|/* 16h */
block|}
name|RAID_PHYS_DISK1_PATH
operator|,
name|MPI_POINTER
name|PTR_RAID_PHYS_DISK1_PATH
operator|,
name|RaidPhysDisk1Path_t
operator|,
name|MPI_POINTER
name|pRaidPhysDisk1Path_t
typedef|;
end_typedef

begin_comment
comment|/* RAID Physical Disk Page 1 Flags field defines */
end_comment

begin_define
define|#
directive|define
name|MPI_RAID_PHYSDISK1_FLAG_BROKEN
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_RAID_PHYSDISK1_FLAG_INVALID
value|(0x0001)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_RAID_PHYS_DISK_1
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|NumPhysDiskPaths
decl_stmt|;
comment|/* 04h */
name|U8
name|PhysDiskNum
decl_stmt|;
comment|/* 05h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 06h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 08h */
name|RAID_PHYS_DISK1_PATH
name|Path
index|[
literal|1
index|]
decl_stmt|;
comment|/* 0Ch */
block|}
name|CONFIG_PAGE_RAID_PHYS_DISK_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_RAID_PHYS_DISK_1
operator|,
name|RaidPhysDiskPage1_t
operator|,
name|MPI_POINTER
name|pRaidPhysDiskPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_RAIDPHYSDISKPAGE1_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/**************************************************************************** *   LAN Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_LAN_0
block|{
name|ConfigPageHeader_t
name|Header
decl_stmt|;
comment|/* 00h */
name|U16
name|TxRxModes
decl_stmt|;
comment|/* 04h */
name|U16
name|Reserved
decl_stmt|;
comment|/* 06h */
name|U32
name|PacketPrePad
decl_stmt|;
comment|/* 08h */
block|}
name|CONFIG_PAGE_LAN_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_LAN_0
operator|,
name|LANPage0_t
operator|,
name|MPI_POINTER
name|pLANPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_LAN_PAGE0_PAGEVERSION
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_LAN_PAGE0_RETURN_LOOPBACK
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI_LAN_PAGE0_SUPPRESS_LOOPBACK
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI_LAN_PAGE0_LOOPBACK_MASK
value|(0x0001)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_LAN_1
block|{
name|ConfigPageHeader_t
name|Header
decl_stmt|;
comment|/* 00h */
name|U16
name|Reserved
decl_stmt|;
comment|/* 04h */
name|U8
name|CurrentDeviceState
decl_stmt|;
comment|/* 06h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 07h */
name|U32
name|MinPacketSize
decl_stmt|;
comment|/* 08h */
name|U32
name|MaxPacketSize
decl_stmt|;
comment|/* 0Ch */
name|U32
name|HardwareAddressLow
decl_stmt|;
comment|/* 10h */
name|U32
name|HardwareAddressHigh
decl_stmt|;
comment|/* 14h */
name|U32
name|MaxWireSpeedLow
decl_stmt|;
comment|/* 18h */
name|U32
name|MaxWireSpeedHigh
decl_stmt|;
comment|/* 1Ch */
name|U32
name|BucketsRemaining
decl_stmt|;
comment|/* 20h */
name|U32
name|MaxReplySize
decl_stmt|;
comment|/* 24h */
name|U32
name|NegWireSpeedLow
decl_stmt|;
comment|/* 28h */
name|U32
name|NegWireSpeedHigh
decl_stmt|;
comment|/* 2Ch */
block|}
name|CONFIG_PAGE_LAN_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_LAN_1
operator|,
name|LANPage1_t
operator|,
name|MPI_POINTER
name|pLANPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_LAN_PAGE1_PAGEVERSION
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_LAN_PAGE1_DEV_STATE_RESET
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_LAN_PAGE1_DEV_STATE_OPERATIONAL
value|(0x01)
end_define

begin_comment
comment|/**************************************************************************** *   Inband Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_INBAND_0
block|{
name|CONFIG_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|MPI_VERSION_FORMAT
name|InbandVersion
decl_stmt|;
comment|/* 04h */
name|U16
name|MaximumBuffers
decl_stmt|;
comment|/* 08h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0Ah */
block|}
name|CONFIG_PAGE_INBAND_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_INBAND_0
operator|,
name|InbandPage0_t
operator|,
name|MPI_POINTER
name|pInbandPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_INBAND_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/**************************************************************************** *   SAS IO Unit Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MPI_SAS_IO_UNIT0_PHY_DATA
block|{
name|U8
name|Port
decl_stmt|;
comment|/* 00h */
name|U8
name|PortFlags
decl_stmt|;
comment|/* 01h */
name|U8
name|PhyFlags
decl_stmt|;
comment|/* 02h */
name|U8
name|NegotiatedLinkRate
decl_stmt|;
comment|/* 03h */
name|U32
name|ControllerPhyDeviceInfo
decl_stmt|;
comment|/* 04h */
name|U16
name|AttachedDeviceHandle
decl_stmt|;
comment|/* 08h */
name|U16
name|ControllerDevHandle
decl_stmt|;
comment|/* 0Ah */
name|U32
name|DiscoveryStatus
decl_stmt|;
comment|/* 0Ch */
block|}
name|MPI_SAS_IO_UNIT0_PHY_DATA
operator|,
name|MPI_POINTER
name|PTR_MPI_SAS_IO_UNIT0_PHY_DATA
operator|,
name|SasIOUnit0PhyData
operator|,
name|MPI_POINTER
name|pSasIOUnit0PhyData
typedef|;
end_typedef

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check Header.PageLength at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_SAS_IOUNIT0_PHY_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_PHY_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SAS_IO_UNIT_0
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 08h */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0Ch */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 0Dh */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 0Eh */
name|MPI_SAS_IO_UNIT0_PHY_DATA
name|PhyData
index|[
name|MPI_SAS_IOUNIT0_PHY_MAX
index|]
decl_stmt|;
comment|/* 10h */
block|}
name|CONFIG_PAGE_SAS_IO_UNIT_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SAS_IO_UNIT_0
operator|,
name|SasIOUnitPage0_t
operator|,
name|MPI_POINTER
name|pSasIOUnitPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SASIOUNITPAGE0_PAGEVERSION
value|(0x03)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 0 PortFlags */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_PORT_FLAGS_DISCOVERY_IN_PROGRESS
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_PORT_FLAGS_0_TARGET_IOC_NUM
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_PORT_FLAGS_1_TARGET_IOC_NUM
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_PORT_FLAGS_AUTO_PORT_CONFIG
value|(0x01)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 0 PhyFlags */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_PHY_FLAGS_PHY_DISABLED
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_PHY_FLAGS_TX_INVERT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_PHY_FLAGS_RX_INVERT
value|(0x01)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 0 NegotiatedLinkRate */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_RATE_UNKNOWN
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_RATE_PHY_DISABLED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_RATE_FAILED_SPEED_NEGOTIATION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_RATE_SATA_OOB_COMPLETE
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_RATE_3_0
value|(0x09)
end_define

begin_comment
comment|/* see mpi_sas.h for values for SAS IO Unit Page 0 ControllerPhyDeviceInfo values */
end_comment

begin_comment
comment|/* values for SAS IO Unit Page 0 DiscoveryStatus */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_DS_LOOP_DETECTED
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_DS_UNADDRESSABLE_DEVICE
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_DS_MULTIPLE_PORTS
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_DS_EXPANDER_ERR
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_DS_SMP_TIMEOUT
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_DS_OUT_ROUTE_ENTRIES
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_DS_INDEX_NOT_EXIST
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_DS_SMP_FUNCTION_FAILED
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_DS_SMP_CRC_ERROR
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_DS_SUBTRACTIVE_LINK
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_DS_TABLE_LINK
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_DS_UNSUPPORTED_DEVICE
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT0_DS_MAX_SATA_TARGETS
value|(0x00001000)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI_SAS_IO_UNIT1_PHY_DATA
block|{
name|U8
name|Port
decl_stmt|;
comment|/* 00h */
name|U8
name|PortFlags
decl_stmt|;
comment|/* 01h */
name|U8
name|PhyFlags
decl_stmt|;
comment|/* 02h */
name|U8
name|MaxMinLinkRate
decl_stmt|;
comment|/* 03h */
name|U32
name|ControllerPhyDeviceInfo
decl_stmt|;
comment|/* 04h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 08h */
block|}
name|MPI_SAS_IO_UNIT1_PHY_DATA
operator|,
name|MPI_POINTER
name|PTR_MPI_SAS_IO_UNIT1_PHY_DATA
operator|,
name|SasIOUnit1PhyData
operator|,
name|MPI_POINTER
name|pSasIOUnit1PhyData
typedef|;
end_typedef

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check Header.PageLength at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_SAS_IOUNIT1_PHY_MAX
end_ifndef

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_PHY_MAX
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SAS_IO_UNIT_1
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U16
name|ControlFlags
decl_stmt|;
comment|/* 08h */
name|U16
name|MaxNumSATATargets
decl_stmt|;
comment|/* 0Ah */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 0Ch */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 10h */
name|U8
name|SATAMaxQDepth
decl_stmt|;
comment|/* 11h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 12h */
name|MPI_SAS_IO_UNIT1_PHY_DATA
name|PhyData
index|[
name|MPI_SAS_IOUNIT1_PHY_MAX
index|]
decl_stmt|;
comment|/* 14h */
block|}
name|CONFIG_PAGE_SAS_IO_UNIT_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SAS_IO_UNIT_1
operator|,
name|SasIOUnitPage1_t
operator|,
name|MPI_POINTER
name|pSasIOUnitPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SASIOUNITPAGE1_PAGEVERSION
value|(0x05)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 1 ControlFlags */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_DEVICE_SELF_TEST
value|(0x8000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_SATA_3_0_MAX
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_SATA_1_5_MAX
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_SATA_SW_PRESERVE
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_DISABLE_SAS_HASH
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_MASK_DEV_SUPPORT
value|(0x0600)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_SHIFT_DEV_SUPPORT
value|(9)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_DEV_SUPPORT_BOTH
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_DEV_SAS_SUPPORT
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_DEV_SATA_SUPPORT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_POSTPONE_SATA_INIT
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_SATA_48BIT_LBA_REQUIRED
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_SATA_SMART_REQUIRED
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_SATA_NCQ_REQUIRED
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_SATA_FUA_REQUIRED
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_PHY_ENABLE_ORDER_HIGH
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_SUBTRACTIVE_ILLEGAL
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_FIRST_LVL_DISC_ONLY
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_CONTROL_CLEAR_AFFILIATION
value|(0x0001)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 1 PortFlags */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_PORT_FLAGS_0_TARGET_IOC_NUM
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_PORT_FLAGS_1_TARGET_IOC_NUM
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_PORT_FLAGS_AUTO_PORT_CONFIG
value|(0x01)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 0 PhyFlags */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_PHY_FLAGS_PHY_DISABLE
value|(0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_PHY_FLAGS_TX_INVERT
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_PHY_FLAGS_RX_INVERT
value|(0x01)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 0 MaxMinLinkRate */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_MAX_RATE_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_MAX_RATE_1_5
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_MAX_RATE_3_0
value|(0x90)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_MIN_RATE_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_MIN_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT1_MIN_RATE_3_0
value|(0x09)
end_define

begin_comment
comment|/* see mpi_sas.h for values for SAS IO Unit Page 1 ControllerPhyDeviceInfo values */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SAS_IO_UNIT_2
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|NumDevsPerEnclosure
decl_stmt|;
comment|/* 08h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 09h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0Ah */
name|U16
name|MaxPersistentIDs
decl_stmt|;
comment|/* 0Ch */
name|U16
name|NumPersistentIDsUsed
decl_stmt|;
comment|/* 0Eh */
name|U8
name|Status
decl_stmt|;
comment|/* 10h */
name|U8
name|Flags
decl_stmt|;
comment|/* 11h */
name|U16
name|MaxNumPhysicalMappedIDs
decl_stmt|;
comment|/* 12h */
block|}
name|CONFIG_PAGE_SAS_IO_UNIT_2
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SAS_IO_UNIT_2
operator|,
name|SasIOUnitPage2_t
operator|,
name|MPI_POINTER
name|pSasIOUnitPage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SASIOUNITPAGE2_PAGEVERSION
value|(0x05)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 2 Status field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT2_STATUS_DISABLED_PERSISTENT_MAPPINGS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT2_STATUS_FULL_PERSISTENT_MAPPINGS
value|(0x01)
end_define

begin_comment
comment|/* values for SAS IO Unit Page 2 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT2_FLAGS_DISABLE_PERSISTENT_MAPPINGS
value|(0x01)
end_define

begin_comment
comment|/* Physical Mapping Modes */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT2_FLAGS_MASK_PHYS_MAP_MODE
value|(0x0E)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT2_FLAGS_SHIFT_PHYS_MAP_MODE
value|(1)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT2_FLAGS_NO_PHYS_MAP
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT2_FLAGS_DIRECT_ATTACH_PHYS_MAP
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT2_FLAGS_ENCLOSURE_SLOT_PHYS_MAP
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT2_FLAGS_HOST_ASSIGNED_PHYS_MAP
value|(0x07)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT2_FLAGS_RESERVE_ID_0_FOR_BOOT
value|(0x10)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_IOUNIT2_FLAGS_DA_STARTING_SLOT
value|(0x20)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SAS_IO_UNIT_3
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 08h */
name|U32
name|MaxInvalidDwordCount
decl_stmt|;
comment|/* 0Ch */
name|U32
name|InvalidDwordCountTime
decl_stmt|;
comment|/* 10h */
name|U32
name|MaxRunningDisparityErrorCount
decl_stmt|;
comment|/* 14h */
name|U32
name|RunningDisparityErrorTime
decl_stmt|;
comment|/* 18h */
name|U32
name|MaxLossDwordSynchCount
decl_stmt|;
comment|/* 1Ch */
name|U32
name|LossDwordSynchCountTime
decl_stmt|;
comment|/* 20h */
name|U32
name|MaxPhyResetProblemCount
decl_stmt|;
comment|/* 24h */
name|U32
name|PhyResetProblemTime
decl_stmt|;
comment|/* 28h */
block|}
name|CONFIG_PAGE_SAS_IO_UNIT_3
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SAS_IO_UNIT_3
operator|,
name|SasIOUnitPage3_t
operator|,
name|MPI_POINTER
name|pSasIOUnitPage3_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SASIOUNITPAGE3_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/**************************************************************************** *   SAS Expander Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SAS_EXPANDER_0
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 08h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 09h */
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 0Ah */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0Ch */
name|U32
name|DiscoveryStatus
decl_stmt|;
comment|/* 14h */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 18h */
name|U16
name|ParentDevHandle
decl_stmt|;
comment|/* 1Ah */
name|U16
name|ExpanderChangeCount
decl_stmt|;
comment|/* 1Ch */
name|U16
name|ExpanderRouteIndexes
decl_stmt|;
comment|/* 1Eh */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 20h */
name|U8
name|SASLevel
decl_stmt|;
comment|/* 21h */
name|U8
name|Flags
decl_stmt|;
comment|/* 22h */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 23h */
block|}
name|CONFIG_PAGE_SAS_EXPANDER_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SAS_EXPANDER_0
operator|,
name|SasExpanderPage0_t
operator|,
name|MPI_POINTER
name|pSasExpanderPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SASEXPANDER0_PAGEVERSION
value|(0x03)
end_define

begin_comment
comment|/* values for SAS Expander Page 0 DiscoveryStatus field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_DS_LOOP_DETECTED
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_DS_UNADDRESSABLE_DEVICE
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_DS_MULTIPLE_PORTS
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_DS_EXPANDER_ERR
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_DS_SMP_TIMEOUT
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_DS_OUT_ROUTE_ENTRIES
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_DS_INDEX_NOT_EXIST
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_DS_SMP_FUNCTION_FAILED
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_DS_SMP_CRC_ERROR
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_DS_SUBTRACTIVE_LINK
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_DS_TABLE_LINK
value|(0x00000400)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_DS_UNSUPPORTED_DEVICE
value|(0x00000800)
end_define

begin_comment
comment|/* values for SAS Expander Page 0 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_FLAGS_ROUTE_TABLE_CONFIG
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER0_FLAGS_CONFIG_IN_PROGRESS
value|(0x01)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SAS_EXPANDER_1
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 08h */
name|U8
name|Reserved1
decl_stmt|;
comment|/* 09h */
name|U16
name|Reserved2
decl_stmt|;
comment|/* 0Ah */
name|U8
name|NumPhys
decl_stmt|;
comment|/* 0Ch */
name|U8
name|Phy
decl_stmt|;
comment|/* 0Dh */
name|U16
name|NumTableEntriesProgrammed
decl_stmt|;
comment|/* 0Eh */
name|U8
name|ProgrammedLinkRate
decl_stmt|;
comment|/* 10h */
name|U8
name|HwLinkRate
decl_stmt|;
comment|/* 11h */
name|U16
name|AttachedDevHandle
decl_stmt|;
comment|/* 12h */
name|U32
name|PhyInfo
decl_stmt|;
comment|/* 14h */
name|U32
name|AttachedDeviceInfo
decl_stmt|;
comment|/* 18h */
name|U16
name|OwnerDevHandle
decl_stmt|;
comment|/* 1Ch */
name|U8
name|ChangeCount
decl_stmt|;
comment|/* 1Eh */
name|U8
name|NegotiatedLinkRate
decl_stmt|;
comment|/* 1Fh */
name|U8
name|PhyIdentifier
decl_stmt|;
comment|/* 20h */
name|U8
name|AttachedPhyIdentifier
decl_stmt|;
comment|/* 21h */
name|U8
name|Reserved3
decl_stmt|;
comment|/* 22h */
name|U8
name|DiscoveryInfo
decl_stmt|;
comment|/* 23h */
name|U32
name|Reserved4
decl_stmt|;
comment|/* 24h */
block|}
name|CONFIG_PAGE_SAS_EXPANDER_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SAS_EXPANDER_1
operator|,
name|SasExpanderPage1_t
operator|,
name|MPI_POINTER
name|pSasExpanderPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SASEXPANDER1_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/* use MPI_SAS_PHY0_PRATE_ defines for ProgrammedLinkRate */
end_comment

begin_comment
comment|/* use MPI_SAS_PHY0_HWRATE_ defines for HwLinkRate */
end_comment

begin_comment
comment|/* use MPI_SAS_PHY0_PHYINFO_ defines for PhyInfo */
end_comment

begin_comment
comment|/* see mpi_sas.h for values for SAS Expander Page 1 AttachedDeviceInfo values */
end_comment

begin_comment
comment|/* values for SAS Expander Page 1 DiscoveryInfo field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER1_DISCINFO_BAD_PHY
value|DISABLED     (0x04)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER1_DISCINFO_LINK_STATUS_CHANGE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER1_DISCINFO_NO_ROUTING_ENTRIES
value|(0x01)
end_define

begin_comment
comment|/* values for SAS Expander Page 1 NegotiatedLinkRate field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER1_NEG_RATE_UNKNOWN
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER1_NEG_RATE_PHY_DISABLED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER1_NEG_RATE_FAILED_NEGOTIATION
value|(0x02)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER1_NEG_RATE_SATA_OOB_COMPLETE
value|(0x03)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER1_NEG_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_EXPANDER1_NEG_RATE_3_0
value|(0x09)
end_define

begin_comment
comment|/**************************************************************************** *   SAS Device Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SAS_DEVICE_0
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U16
name|Slot
decl_stmt|;
comment|/* 08h */
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 0Ah */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0Ch */
name|U16
name|ParentDevHandle
decl_stmt|;
comment|/* 14h */
name|U8
name|PhyNum
decl_stmt|;
comment|/* 16h */
name|U8
name|AccessStatus
decl_stmt|;
comment|/* 17h */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 18h */
name|U8
name|TargetID
decl_stmt|;
comment|/* 1Ah */
name|U8
name|Bus
decl_stmt|;
comment|/* 1Bh */
name|U32
name|DeviceInfo
decl_stmt|;
comment|/* 1Ch */
name|U16
name|Flags
decl_stmt|;
comment|/* 20h */
name|U8
name|PhysicalPort
decl_stmt|;
comment|/* 22h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 23h */
block|}
name|CONFIG_PAGE_SAS_DEVICE_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SAS_DEVICE_0
operator|,
name|SasDevicePage0_t
operator|,
name|MPI_POINTER
name|pSasDevicePage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SASDEVICE0_PAGEVERSION
value|(0x04)
end_define

begin_comment
comment|/* values for SAS Device Page 0 AccessStatus field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE0_ASTATUS_NO_ERRORS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE0_ASTATUS_SATA_INIT_FAILED
value|(0x01)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE0_ASTATUS_SATA_CAPABILITY_FAILED
value|(0x02)
end_define

begin_comment
comment|/* values for SAS Device Page 0 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE0_FLAGS_SATA_SW_PRESERVE
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE0_FLAGS_UNSUPPORTED_DEVICE
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE0_FLAGS_SATA_48BIT_LBA_SUPPORTED
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE0_FLAGS_SATA_SMART_SUPPORTED
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE0_FLAGS_SATA_NCQ_SUPPORTED
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE0_FLAGS_SATA_FUA_SUPPORTED
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE0_FLAGS_PORT_SELECTOR_ATTACH
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE0_FLAGS_MAPPING_PERSISTENT
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE0_FLAGS_DEVICE_MAPPED
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_DEVICE0_FLAGS_DEVICE_PRESENT
value|(0x0001)
end_define

begin_comment
comment|/* see mpi_sas.h for values for SAS Device Page 0 DeviceInfo values */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SAS_DEVICE_1
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 08h */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0Ch */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 14h */
name|U16
name|DevHandle
decl_stmt|;
comment|/* 18h */
name|U8
name|TargetID
decl_stmt|;
comment|/* 1Ah */
name|U8
name|Bus
decl_stmt|;
comment|/* 1Bh */
name|U8
name|InitialRegDeviceFIS
index|[
literal|20
index|]
decl_stmt|;
comment|/* 1Ch */
block|}
name|CONFIG_PAGE_SAS_DEVICE_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SAS_DEVICE_1
operator|,
name|SasDevicePage1_t
operator|,
name|MPI_POINTER
name|pSasDevicePage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SASDEVICE1_PAGEVERSION
value|(0x00)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SAS_DEVICE_2
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U64
name|PhysicalIdentifier
decl_stmt|;
comment|/* 08h */
name|U32
name|EnclosureMapping
decl_stmt|;
comment|/* 10h */
block|}
name|CONFIG_PAGE_SAS_DEVICE_2
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SAS_DEVICE_2
operator|,
name|SasDevicePage2_t
operator|,
name|MPI_POINTER
name|pSasDevicePage2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SASDEVICE2_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/* defines for SAS Device Page 2 EnclosureMapping field */
end_comment

begin_define
define|#
directive|define
name|MPI_SASDEVICE2_ENC_MAP_MASK_MISSING_COUNT
value|(0x0000000F)
end_define

begin_define
define|#
directive|define
name|MPI_SASDEVICE2_ENC_MAP_SHIFT_MISSING_COUNT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPI_SASDEVICE2_ENC_MAP_MASK_NUM_SLOTS
value|(0x000007F0)
end_define

begin_define
define|#
directive|define
name|MPI_SASDEVICE2_ENC_MAP_SHIFT_NUM_SLOTS
value|(4)
end_define

begin_define
define|#
directive|define
name|MPI_SASDEVICE2_ENC_MAP_MASK_START_INDEX
value|(0x001FF800)
end_define

begin_define
define|#
directive|define
name|MPI_SASDEVICE2_ENC_MAP_SHIFT_START_INDEX
value|(11)
end_define

begin_comment
comment|/**************************************************************************** *   SAS PHY Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SAS_PHY_0
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U16
name|OwnerDevHandle
decl_stmt|;
comment|/* 08h */
name|U16
name|Reserved1
decl_stmt|;
comment|/* 0Ah */
name|U64
name|SASAddress
decl_stmt|;
comment|/* 0Ch */
name|U16
name|AttachedDevHandle
decl_stmt|;
comment|/* 14h */
name|U8
name|AttachedPhyIdentifier
decl_stmt|;
comment|/* 16h */
name|U8
name|Reserved2
decl_stmt|;
comment|/* 17h */
name|U32
name|AttachedDeviceInfo
decl_stmt|;
comment|/* 18h */
name|U8
name|ProgrammedLinkRate
decl_stmt|;
comment|/* 20h */
name|U8
name|HwLinkRate
decl_stmt|;
comment|/* 21h */
name|U8
name|ChangeCount
decl_stmt|;
comment|/* 22h */
name|U8
name|Flags
decl_stmt|;
comment|/* 23h */
name|U32
name|PhyInfo
decl_stmt|;
comment|/* 24h */
block|}
name|CONFIG_PAGE_SAS_PHY_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SAS_PHY_0
operator|,
name|SasPhyPage0_t
operator|,
name|MPI_POINTER
name|pSasPhyPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SASPHY0_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/* values for SAS PHY Page 0 ProgrammedLinkRate field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PRATE_MAX_RATE_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PRATE_MAX_RATE_NOT_PROGRAMMABLE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PRATE_MAX_RATE_1_5
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PRATE_MAX_RATE_3_0
value|(0x90)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PRATE_MIN_RATE_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PRATE_MIN_RATE_NOT_PROGRAMMABLE
value|(0x00)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PRATE_MIN_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PRATE_MIN_RATE_3_0
value|(0x09)
end_define

begin_comment
comment|/* values for SAS PHY Page 0 HwLinkRate field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_HWRATE_MAX_RATE_MASK
value|(0xF0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_HWRATE_MAX_RATE_1_5
value|(0x80)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_HWRATE_MAX_RATE_3_0
value|(0x90)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_HWRATE_MIN_RATE_MASK
value|(0x0F)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_HWRATE_MIN_RATE_1_5
value|(0x08)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_HWRATE_MIN_RATE_3_0
value|(0x09)
end_define

begin_comment
comment|/* values for SAS PHY Page 0 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_FLAGS_SGPIO_DIRECT_ATTACH_ENC
value|(0x01)
end_define

begin_comment
comment|/* values for SAS PHY Page 0 PhyInfo field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_SATA_PORT_ACTIVE
value|(0x00004000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_SATA_PORT_SELECTOR
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_VIRTUAL_PHY
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_MASK_PARTIAL_PATHWAY_TIME
value|(0x00000F00)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_SHIFT_PARTIAL_PATHWAY_TIME
value|(8)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_MASK_ROUTING_ATTRIBUTE
value|(0x000000F0)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_DIRECT_ROUTING
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_SUBTRACTIVE_ROUTING
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_TABLE_ROUTING
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_MASK_LINK_RATE
value|(0x0000000F)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_UNKNOWN_LINK_RATE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_PHY_DISABLED
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_NEGOTIATION_FAILED
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_SATA_OOB_COMPLETE
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_RATE_1_5
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_PHY0_PHYINFO_RATE_3_0
value|(0x00000009)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SAS_PHY_1
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 08h */
name|U32
name|InvalidDwordCount
decl_stmt|;
comment|/* 0Ch */
name|U32
name|RunningDisparityErrorCount
decl_stmt|;
comment|/* 10h */
name|U32
name|LossDwordSynchCount
decl_stmt|;
comment|/* 14h */
name|U32
name|PhyResetProblemCount
decl_stmt|;
comment|/* 18h */
block|}
name|CONFIG_PAGE_SAS_PHY_1
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SAS_PHY_1
operator|,
name|SasPhyPage1_t
operator|,
name|MPI_POINTER
name|pSasPhyPage1_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SASPHY1_PAGEVERSION
value|(0x00)
end_define

begin_comment
comment|/**************************************************************************** *   SAS Enclosure Config Pages ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_SAS_ENCLOSURE_0
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 08h */
name|U64
name|EnclosureLogicalID
decl_stmt|;
comment|/* 0Ch */
name|U16
name|Flags
decl_stmt|;
comment|/* 14h */
name|U16
name|EnclosureHandle
decl_stmt|;
comment|/* 16h */
name|U16
name|NumSlots
decl_stmt|;
comment|/* 18h */
name|U16
name|StartSlot
decl_stmt|;
comment|/* 1Ah */
name|U8
name|StartTargetID
decl_stmt|;
comment|/* 1Ch */
name|U8
name|StartBus
decl_stmt|;
comment|/* 1Dh */
name|U8
name|SEPTargetID
decl_stmt|;
comment|/* 1Eh */
name|U8
name|SEPBus
decl_stmt|;
comment|/* 1Fh */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 20h */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 24h */
block|}
name|CONFIG_PAGE_SAS_ENCLOSURE_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_SAS_ENCLOSURE_0
operator|,
name|SasEnclosurePage0_t
operator|,
name|MPI_POINTER
name|pSasEnclosurePage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_SASENCLOSURE0_PAGEVERSION
value|(0x01)
end_define

begin_comment
comment|/* values for SAS Enclosure Page 0 Flags field */
end_comment

begin_define
define|#
directive|define
name|MPI_SAS_ENCLS0_FLAGS_SEP_BUS_ID_VALID
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLS0_FLAGS_START_BUS_ID_VALID
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLS0_FLAGS_MNG_MASK
value|(0x000F)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLS0_FLAGS_MNG_UNKNOWN
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLS0_FLAGS_MNG_IOC_SES
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLS0_FLAGS_MNG_IOC_SGPIO
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLS0_FLAGS_MNG_EXP_SGPIO
value|(0x0003)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLS0_FLAGS_MNG_SES_ENCLOSURE
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|MPI_SAS_ENCLS0_FLAGS_MNG_IOC_GPIO
value|(0x0005)
end_define

begin_comment
comment|/**************************************************************************** *   Log Config Pages ****************************************************************************/
end_comment

begin_comment
comment|/*  * Host code (drivers, BIOS, utilities, etc.) should leave this define set to  * one and check NumLogEntries at runtime.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_LOG_0_NUM_LOG_ENTRIES
end_ifndef

begin_define
define|#
directive|define
name|MPI_LOG_0_NUM_LOG_ENTRIES
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MPI_LOG_0_LOG_DATA_LENGTH
value|(0x1C)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_MPI_LOG_0_ENTRY
block|{
name|U32
name|TimeStamp
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 04h */
name|U16
name|LogSequence
decl_stmt|;
comment|/* 08h */
name|U16
name|LogEntryQualifier
decl_stmt|;
comment|/* 0Ah */
name|U8
name|LogData
index|[
name|MPI_LOG_0_LOG_DATA_LENGTH
index|]
decl_stmt|;
comment|/* 0Ch */
block|}
name|MPI_LOG_0_ENTRY
operator|,
name|MPI_POINTER
name|PTR_MPI_LOG_0_ENTRY
operator|,
name|MpiLog0Entry_t
operator|,
name|MPI_POINTER
name|pMpiLog0Entry_t
typedef|;
end_typedef

begin_comment
comment|/* values for Log Page 0 LogEntry LogEntryQualifier field */
end_comment

begin_define
define|#
directive|define
name|MPI_LOG_0_ENTRY_QUAL_ENTRY_UNUSED
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|MPI_LOG_0_ENTRY_QUAL_POWER_ON_RESET
value|(0x0001)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_CONFIG_PAGE_LOG_0
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|Header
decl_stmt|;
comment|/* 00h */
name|U32
name|Reserved1
decl_stmt|;
comment|/* 08h */
name|U32
name|Reserved2
decl_stmt|;
comment|/* 0Ch */
name|U16
name|NumLogEntries
decl_stmt|;
comment|/* 10h */
name|U16
name|Reserved3
decl_stmt|;
comment|/* 12h */
name|MPI_LOG_0_ENTRY
name|LogEntry
index|[
name|MPI_LOG_0_NUM_LOG_ENTRIES
index|]
decl_stmt|;
comment|/* 14h */
block|}
name|CONFIG_PAGE_LOG_0
operator|,
name|MPI_POINTER
name|PTR_CONFIG_PAGE_LOG_0
operator|,
name|LogPage0_t
operator|,
name|MPI_POINTER
name|pLogPage0_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MPI_LOG_0_PAGEVERSION
value|(0x01)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

