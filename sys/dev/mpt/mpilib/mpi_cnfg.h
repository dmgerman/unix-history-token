begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000, 2001 by LSI Logic Corporation  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  *           Name:  MPI_CNFG.H  *          Title:  MPI Config message, structures, and Pages  *  Creation Date:  July 27, 2000  *  *    MPI_CNFG.H Version:  01.02.11  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  05-08-00  00.10.01  Original release for 0.10 spec dated 4/26/2000.  *  06-06-00  01.00.01  Update version number for 1.0 release.  *  06-08-00  01.00.02  Added _PAGEVERSION definitions for all pages.  *                      Added FcPhLowestVersion, FcPhHighestVersion, Reserved2  *                      fields to FC_DEVICE_0 page, updated the page version.  *                      Changed _FREE_RUNNING_CLOCK to _PACING_TRANSFERS in  *                      SCSI_PORT_0, SCSI_DEVICE_0 and SCSI_DEVICE_1 pages  *                      and updated the page versions.  *                      Added _RESPONSE_ID_MASK definition to SCSI_PORT_1  *                      page and updated the page version.  *                      Added Information field and _INFO_PARAMS_NEGOTIATED  *                      definitionto SCSI_DEVICE_0 page.  *  06-22-00  01.00.03  Removed batch controls from LAN_0 page and updated the  *                      page version.  *                      Added BucketsRemaining to LAN_1 page, redefined the  *                      state values, and updated the page version.  *                      Revised bus width definitions in SCSI_PORT_0,  *                      SCSI_DEVICE_0 and SCSI_DEVICE_1 pages.  *  06-30-00  01.00.04  Added MaxReplySize to LAN_1 page and updated the page  *                      version.  *                      Moved FC_DEVICE_0 PageAddress description to spec.  *  07-27-00  01.00.05  Corrected the SubsystemVendorID and SubsystemID field  *                      widths in IOC_0 page and updated the page version.  *  11-02-00  01.01.01  Original release for post 1.0 work  *                      Added Manufacturing pages, IO Unit Page 2, SCSI SPI  *                      Port Page 2, FC Port Page 4, FC Port Page 5  *  11-15-00  01.01.02  Interim changes to match proposals  *  12-04-00  01.01.03  Config page changes to match MPI rev 1.00.01.  *  12-05-00  01.01.04  Modified config page actions.  *  01-09-01  01.01.05  Added defines for page address formats.  *                      Data size for Manufacturing pages 2 and 3 no longer  *                      defined here.  *                      Io Unit Page 2 size is fixed at 4 adapters and some  *                      flags were changed.  *                      SCSI Port Page 2 Device Settings modified.  *                      New fields added to FC Port Page 0 and some flags  *                      cleaned up.  *                      Removed impedance flash from FC Port Page 1.  *                      Added FC Port pages 6 and 7.  *  01-25-01  01.01.06  Added MaxInitiators field to FcPortPage0.  *  01-29-01  01.01.07  Changed some defines to make them 32 character unique.  *                      Added some LinkType defines for FcPortPage0.  *  02-20-01  01.01.08  Started using MPI_POINTER.  *  02-27-01  01.01.09  Replaced MPI_CONFIG_PAGETYPE_SCSI_LUN with  *                      MPI_CONFIG_PAGETYPE_RAID_VOLUME.  *                      Added definitions and structures for IOC Page 2 and  *                      RAID Volume Page 2.  *  03-27-01  01.01.10  Added CONFIG_PAGE_FC_PORT_8 and CONFIG_PAGE_FC_PORT_9.  *                      CONFIG_PAGE_FC_PORT_3 now supports persistent by DID.  *                      Added VendorId and ProductRevLevel fields to  *                      RAIDVOL2_IM_PHYS_ID struct.  *                      Modified values for MPI_FCPORTPAGE0_FLAGS_ATTACH_  *                      defines to make them compatible to MPI version 1.0.  *                      Added structure offset comments.  *  04-09-01  01.01.11  Added some new defines for the PageAddress field and  *                      removed some obsolete ones.  *                      Added IO Unit Page 3.  *                      Modified defines for Scsi Port Page 2.  *                      Modified RAID Volume Pages.  *  08-08-01  01.02.01  Original release for v1.2 work.  *                      Added SepID and SepBus to RVP2 IMPhysicalDisk struct.  *                      Added defines for the SEP bits in RVP2 VolumeSettings.  *                      Modified the DeviceSettings field in RVP2 to use the  *                      proper structure.  *                      Added defines for SES, SAF-TE, and cross channel for  *                      IOCPage2 CapabilitiesFlags.  *                      Removed define for MPI_IOUNITPAGE2_FLAGS_RAID_DISABLE.  *                      Removed define for  *                      MPI_SCSIPORTPAGE2_PORT_FLAGS_PARITY_ENABLE.  *                      Added define for MPI_CONFIG_PAGEATTR_RO_PERSISTENT.  *  08-29-01 01.02.02   Fixed value for MPI_MANUFACTPAGE_DEVID_53C1035.  *                      Added defines for MPI_FCPORTPAGE1_FLAGS_HARD_ALPA_ONLY  *                      and MPI_FCPORTPAGE1_FLAGS_IMMEDIATE_ERROR_REPLY.  *                      Removed MPI_SCSIPORTPAGE0_CAP_PACING_TRANSFERS,  *                      MPI_SCSIDEVPAGE0_NP_PACING_TRANSFERS, and  *                      MPI_SCSIDEVPAGE1_RP_PACING_TRANSFERS, and  *                      MPI_SCSIDEVPAGE1_CONF_PPR_ALLOWED.  *                      Added defines for MPI_SCSIDEVPAGE1_CONF_WDTR_DISALLOWED  *                      and MPI_SCSIDEVPAGE1_CONF_SDTR_DISALLOWED.  *                      Added OnBusTimerValue to CONFIG_PAGE_SCSI_PORT_1.  *                      Added rejected bits to SCSI Device Page 0 Information.  *                      Increased size of ALPA array in FC Port Page 2 by one  *                      and removed a one byte reserved field.  *  09-28-01 01.02.03   Swapped NegWireSpeedLow and NegWireSpeedLow in  *                      CONFIG_PAGE_LAN_1 to match preferred 64-bit ordering.  *                      Added structures for Manufacturing Page 4, IO Unit  *                      Page 3, IOC Page 3, IOC Page 4, RAID Volume Page 0, and  *                      RAID PhysDisk Page 0.  *  10-04-01 01.02.04   Added define for MPI_CONFIG_PAGETYPE_RAID_PHYSDISK.  *                      Modified some of the new defines to make them 32  *                      character unique.  *                      Modified how variable length pages (arrays) are defined.  *                      Added generic defines for hot spare pools and RAID  *                      volume types.  *  11-01-01 01.02.05   Added define for MPI_IOUNITPAGE1_DISABLE_IR.  *  03-14-02 01.02.06   Added PCISlotNum field to CONFIG_PAGE_IOC_1 along with  *                      related define, and bumped the page version define.  *  05-31-02 01.02.07   Added a Flags field to CONFIG_PAGE_IOC_2_RAID_VOL in a  *                      reserved byte and added a define.  *                      Added define for  *                      MPI_RAIDVOL0_STATUS_FLAG_VOLUME_INACTIVE.  *                      Added new config page: CONFIG_PAGE_IOC_5.  *                      Added MaxAliases, MaxHardAliases, and NumCurrentAliases  *                      fields to CONFIG_PAGE_FC_PORT_0.  *                      Added AltConnector and NumRequestedAliases fields to  *                      CONFIG_PAGE_FC_PORT_1.  *                      Added new config page: CONFIG_PAGE_FC_PORT_10.  *  07-12-02 01.02.08   Added more MPI_MANUFACTPAGE_DEVID_ defines.  *                      Added additional MPI_SCSIDEVPAGE0_NP_ defines.  *                      Added more MPI_SCSIDEVPAGE1_RP_ defines.  *                      Added define for  *                      MPI_SCSIDEVPAGE1_CONF_EXTENDED_PARAMS_ENABLE.  *                      Added new config page: CONFIG_PAGE_SCSI_DEVICE_3.  *                      Modified MPI_FCPORTPAGE5_FLAGS_ defines.  *  09-16-02 01.02.09   Added MPI_SCSIDEVPAGE1_CONF_FORCE_PPR_MSG define.  *  11-15-02 01.02.10   Added ConnectedID defines for CONFIG_PAGE_SCSI_PORT_0.  *                      Added more Flags defines for CONFIG_PAGE_FC_PORT_1.  *                      Added more Flags defines for CONFIG_PAGE_FC_DEVICE_0.  *  04-01-03 01.02.11   Added RR_TOV field and additional Flags defines for  *                      CONFIG_PAGE_FC_PORT_1.  *                      Added define MPI_FCPORTPAGE5_FLAGS_DISABLE to disable  *                      an alias.  *                      Added more device id defines.  *  --------------------------------------------------------------------------  */
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
name|U8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 04h */
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
name|U8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 04h */
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

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_VENDORID_TREBIA
value|(0x1783)
end_define

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

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SA2010
value|(0x0804)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SA2010ZC
value|(0x0805)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SA2020
value|(0x0806)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SA2020ZC
value|(0x0807)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SNP1000
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|MPI_MANUFACTPAGE_DEVID_SNP500
value|(0x0020)
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
name|Reserved2
decl_stmt|;
comment|/* 0Dh */
name|U16
name|Reserved3
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
value|(0x00)
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
name|MPI_IOUNITPAGE1_DISABLE_IR
value|(0x00000040)
end_define

begin_define
define|#
directive|define
name|MPI_IOUNITPAGE1_FORCE_32
value|(0x00000080)
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
value|(0x00)
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
value|(0x01)
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
value|(0x02)
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
value|(0x01)
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
name|MPI_SCSIPORTPAGE0_CAP_MAX_SYNC_OFFSET_MASK
value|(0x00FF0000)
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
value|(0x02)
end_define

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
value|(0x01)
end_define

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
name|MPI_SCSIPORTPAGE2_PORT_SPINUP_DELAY_MASK
value|(0x00000F00)
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
value|(0x03)
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
name|MPI_SCSIDEVPAGE0_NP_NEG_SYNC_OFFSET_MASK
value|(0x00FF0000)
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
value|(0x04)
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
name|MPI_SCSIDEVPAGE1_RP_MAX_SYNC_OFFSET_MASK
value|(0x00FF0000)
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
name|U16
name|Reserved2
decl_stmt|;
comment|/* 1Eh */
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
value|(0x05)
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
name|MPI_FCPORTPAGE1_FLAGS_MASK_RR_TOV_UNITS
value|(0x00000070)
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
name|Reserved4
decl_stmt|;
comment|/* 4Ch */
name|U8
name|Reserved5
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
name|Reserved5
index|[
literal|3
index|]
decl_stmt|;
comment|/* 6Ch */
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
value|(0x00)
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
name|Reserved1
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
value|(0x02)
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
name|Reserved4
decl_stmt|;
comment|/* 25h */
name|U16
name|Reserved5
decl_stmt|;
comment|/* 26h */
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
name|U32
name|Reserved2
decl_stmt|;
comment|/* 10h */
name|U32
name|Reserved3
decl_stmt|;
comment|/* 14h */
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

