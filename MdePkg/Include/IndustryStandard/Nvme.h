begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Definitions based on NVMe spec. version 1.1.    (C) Copyright 2016 Hewlett Packard Enterprise Development LP<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Specification Reference:   NVMe Specification 1.1  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NVM_E_H__
end_ifndef

begin_define
define|#
directive|define
name|__NVM_E_H__
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// controller register offsets
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NVME_CAP_OFFSET
value|0x0000
end_define

begin_comment
comment|// Controller Capabilities
end_comment

begin_define
define|#
directive|define
name|NVME_VER_OFFSET
value|0x0008
end_define

begin_comment
comment|// Version
end_comment

begin_define
define|#
directive|define
name|NVME_INTMS_OFFSET
value|0x000c
end_define

begin_comment
comment|// Interrupt Mask Set
end_comment

begin_define
define|#
directive|define
name|NVME_INTMC_OFFSET
value|0x0010
end_define

begin_comment
comment|// Interrupt Mask Clear
end_comment

begin_define
define|#
directive|define
name|NVME_CC_OFFSET
value|0x0014
end_define

begin_comment
comment|// Controller Configuration
end_comment

begin_define
define|#
directive|define
name|NVME_CSTS_OFFSET
value|0x001c
end_define

begin_comment
comment|// Controller Status
end_comment

begin_define
define|#
directive|define
name|NVME_NSSR_OFFSET
value|0x0020
end_define

begin_comment
comment|// NVM Subsystem Reset
end_comment

begin_define
define|#
directive|define
name|NVME_AQA_OFFSET
value|0x0024
end_define

begin_comment
comment|// Admin Queue Attributes
end_comment

begin_define
define|#
directive|define
name|NVME_ASQ_OFFSET
value|0x0028
end_define

begin_comment
comment|// Admin Submission Queue Base Address
end_comment

begin_define
define|#
directive|define
name|NVME_ACQ_OFFSET
value|0x0030
end_define

begin_comment
comment|// Admin Completion Queue Base Address
end_comment

begin_define
define|#
directive|define
name|NVME_SQ0_OFFSET
value|0x1000
end_define

begin_comment
comment|// Submission Queue 0 (admin) Tail Doorbell
end_comment

begin_define
define|#
directive|define
name|NVME_CQ0_OFFSET
value|0x1004
end_define

begin_comment
comment|// Completion Queue 0 (admin) Head Doorbell
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// These register offsets are defined as 0x1000 + (N * (4<< CAP.DSTRD))
end_comment

begin_comment
comment|// Get the doorbell stride bit shift value from the controller capabilities.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NVME_SQTDBL_OFFSET
parameter_list|(
name|QID
parameter_list|,
name|DSTRD
parameter_list|)
value|0x1000 + ((2 * (QID)) * (4<< (DSTRD)))
end_define

begin_comment
comment|// Submission Queue y (NVM) Tail Doorbell
end_comment

begin_define
define|#
directive|define
name|NVME_CQHDBL_OFFSET
parameter_list|(
name|QID
parameter_list|,
name|DSTRD
parameter_list|)
value|0x1000 + (((2 * (QID)) + 1) * (4<< (DSTRD)))
end_define

begin_comment
comment|// Completion Queue y (NVM) Head Doorbell
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// 3.1.1 Offset 00h: CAP - Controller Capabilities
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Mqes
decl_stmt|;
comment|// Maximum Queue Entries Supported
name|UINT8
name|Cqr
range|:
literal|1
decl_stmt|;
comment|// Contiguous Queues Required
name|UINT8
name|Ams
range|:
literal|2
decl_stmt|;
comment|// Arbitration Mechanism Supported
name|UINT8
name|Rsvd1
range|:
literal|5
decl_stmt|;
name|UINT8
name|To
decl_stmt|;
comment|// Timeout
name|UINT16
name|Dstrd
range|:
literal|4
decl_stmt|;
name|UINT16
name|Nssrs
range|:
literal|1
decl_stmt|;
comment|// NVM Subsystem Reset Supported NSSRS
name|UINT16
name|Css
range|:
literal|4
decl_stmt|;
comment|// Command Sets Supported - Bit 37
name|UINT16
name|Rsvd3
range|:
literal|7
decl_stmt|;
name|UINT8
name|Mpsmin
range|:
literal|4
decl_stmt|;
name|UINT8
name|Mpsmax
range|:
literal|4
decl_stmt|;
name|UINT8
name|Rsvd4
decl_stmt|;
block|}
name|NVME_CAP
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// 3.1.2 Offset 08h: VS - Version
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Mnr
decl_stmt|;
comment|// Minor version number
name|UINT16
name|Mjr
decl_stmt|;
comment|// Major version number
block|}
name|NVME_VER
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// 3.1.5 Offset 14h: CC - Controller Configuration
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|En
range|:
literal|1
decl_stmt|;
comment|// Enable
name|UINT16
name|Rsvd1
range|:
literal|3
decl_stmt|;
name|UINT16
name|Css
range|:
literal|3
decl_stmt|;
comment|// I/O Command Set Selected
name|UINT16
name|Mps
range|:
literal|4
decl_stmt|;
comment|// Memory Page Size
name|UINT16
name|Ams
range|:
literal|3
decl_stmt|;
comment|// Arbitration Mechanism Selected
name|UINT16
name|Shn
range|:
literal|2
decl_stmt|;
comment|// Shutdown Notification
name|UINT8
name|Iosqes
range|:
literal|4
decl_stmt|;
comment|// I/O Submission Queue Entry Size
name|UINT8
name|Iocqes
range|:
literal|4
decl_stmt|;
comment|// I/O Completion Queue Entry Size
name|UINT8
name|Rsvd2
decl_stmt|;
block|}
name|NVME_CC
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// 3.1.6 Offset 1Ch: CSTS - Controller Status
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Rdy
range|:
literal|1
decl_stmt|;
comment|// Ready
name|UINT32
name|Cfs
range|:
literal|1
decl_stmt|;
comment|// Controller Fatal Status
name|UINT32
name|Shst
range|:
literal|2
decl_stmt|;
comment|// Shutdown Status
name|UINT32
name|Nssro
range|:
literal|1
decl_stmt|;
comment|// NVM Subsystem Reset Occurred
name|UINT32
name|Rsvd1
range|:
literal|27
decl_stmt|;
block|}
name|NVME_CSTS
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// 3.1.8 Offset 24h: AQA - Admin Queue Attributes
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Asqs
range|:
literal|12
decl_stmt|;
comment|// Submission Queue Size
name|UINT16
name|Rsvd1
range|:
literal|4
decl_stmt|;
name|UINT16
name|Acqs
range|:
literal|12
decl_stmt|;
comment|// Completion Queue Size
name|UINT16
name|Rsvd2
range|:
literal|4
decl_stmt|;
block|}
name|NVME_AQA
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// 3.1.9 Offset 28h: ASQ - Admin Submission Queue Base Address
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NVME_ASQ
value|UINT64
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// 3.1.10 Offset 30h: ACQ - Admin Completion Queue Base Address
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NVME_ACQ
value|UINT64
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// 3.1.11 Offset (1000h + ((2y) * (4<< CAP.DSTRD))): SQyTDBL - Submission Queue y Tail Doorbell
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Sqt
decl_stmt|;
name|UINT16
name|Rsvd1
decl_stmt|;
block|}
name|NVME_SQTDBL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// 3.1.12 Offset (1000h + ((2y + 1) * (4<< CAP.DSTRD))): CQyHDBL - Completion Queue y Head Doorbell
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Cqh
decl_stmt|;
name|UINT16
name|Rsvd1
decl_stmt|;
block|}
name|NVME_CQHDBL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NVM command set structures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Read Command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10, 11
comment|//
name|UINT64
name|Slba
decl_stmt|;
comment|/* Starting Sector Address */
comment|//
comment|// CDW 12
comment|//
name|UINT16
name|Nlb
decl_stmt|;
comment|/* Number of Sectors */
name|UINT16
name|Rsvd1
range|:
literal|10
decl_stmt|;
name|UINT16
name|Prinfo
range|:
literal|4
decl_stmt|;
comment|/* Protection Info Check */
name|UINT16
name|Fua
range|:
literal|1
decl_stmt|;
comment|/* Force Unit Access */
name|UINT16
name|Lr
range|:
literal|1
decl_stmt|;
comment|/* Limited Retry */
comment|//
comment|// CDW 13
comment|//
name|UINT32
name|Af
range|:
literal|4
decl_stmt|;
comment|/* Access Frequency */
name|UINT32
name|Al
range|:
literal|2
decl_stmt|;
comment|/* Access Latency */
name|UINT32
name|Sr
range|:
literal|1
decl_stmt|;
comment|/* Sequential Request */
name|UINT32
name|In
range|:
literal|1
decl_stmt|;
comment|/* Incompressible */
name|UINT32
name|Rsvd2
range|:
literal|24
decl_stmt|;
comment|//
comment|// CDW 14
comment|//
name|UINT32
name|Eilbrt
decl_stmt|;
comment|/* Expected Initial Logical Block Reference Tag */
comment|//
comment|// CDW 15
comment|//
name|UINT16
name|Elbat
decl_stmt|;
comment|/* Expected Logical Block Application Tag */
name|UINT16
name|Elbatm
decl_stmt|;
comment|/* Expected Logical Block Application Tag Mask */
block|}
name|NVME_READ
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Write Command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10, 11
comment|//
name|UINT64
name|Slba
decl_stmt|;
comment|/* Starting Sector Address */
comment|//
comment|// CDW 12
comment|//
name|UINT16
name|Nlb
decl_stmt|;
comment|/* Number of Sectors */
name|UINT16
name|Rsvd1
range|:
literal|10
decl_stmt|;
name|UINT16
name|Prinfo
range|:
literal|4
decl_stmt|;
comment|/* Protection Info Check */
name|UINT16
name|Fua
range|:
literal|1
decl_stmt|;
comment|/* Force Unit Access */
name|UINT16
name|Lr
range|:
literal|1
decl_stmt|;
comment|/* Limited Retry */
comment|//
comment|// CDW 13
comment|//
name|UINT32
name|Af
range|:
literal|4
decl_stmt|;
comment|/* Access Frequency */
name|UINT32
name|Al
range|:
literal|2
decl_stmt|;
comment|/* Access Latency */
name|UINT32
name|Sr
range|:
literal|1
decl_stmt|;
comment|/* Sequential Request */
name|UINT32
name|In
range|:
literal|1
decl_stmt|;
comment|/* Incompressible */
name|UINT32
name|Rsvd2
range|:
literal|24
decl_stmt|;
comment|//
comment|// CDW 14
comment|//
name|UINT32
name|Ilbrt
decl_stmt|;
comment|/* Initial Logical Block Reference Tag */
comment|//
comment|// CDW 15
comment|//
name|UINT16
name|Lbat
decl_stmt|;
comment|/* Logical Block Application Tag */
name|UINT16
name|Lbatm
decl_stmt|;
comment|/* Logical Block Application Tag Mask */
block|}
name|NVME_WRITE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Flush
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT32
name|Flush
decl_stmt|;
comment|/* Flush */
block|}
name|NVME_FLUSH
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Write Uncorrectable command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10, 11
comment|//
name|UINT64
name|Slba
decl_stmt|;
comment|/* Starting LBA */
comment|//
comment|// CDW 12
comment|//
name|UINT32
name|Nlb
range|:
literal|16
decl_stmt|;
comment|/* Number of  Logical Blocks */
name|UINT32
name|Rsvd1
range|:
literal|16
decl_stmt|;
block|}
name|NVME_WRITE_UNCORRECTABLE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Write Zeroes command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10, 11
comment|//
name|UINT64
name|Slba
decl_stmt|;
comment|/* Starting LBA */
comment|//
comment|// CDW 12
comment|//
name|UINT16
name|Nlb
decl_stmt|;
comment|/* Number of Logical Blocks */
name|UINT16
name|Rsvd1
range|:
literal|10
decl_stmt|;
name|UINT16
name|Prinfo
range|:
literal|4
decl_stmt|;
comment|/* Protection Info Check */
name|UINT16
name|Fua
range|:
literal|1
decl_stmt|;
comment|/* Force Unit Access */
name|UINT16
name|Lr
range|:
literal|1
decl_stmt|;
comment|/* Limited Retry */
comment|//
comment|// CDW 13
comment|//
name|UINT32
name|Rsvd2
decl_stmt|;
comment|//
comment|// CDW 14
comment|//
name|UINT32
name|Ilbrt
decl_stmt|;
comment|/* Initial Logical Block Reference Tag */
comment|//
comment|// CDW 15
comment|//
name|UINT16
name|Lbat
decl_stmt|;
comment|/* Logical Block Application Tag */
name|UINT16
name|Lbatm
decl_stmt|;
comment|/* Logical Block Application Tag Mask */
block|}
name|NVME_WRITE_ZEROES
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Compare command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10, 11
comment|//
name|UINT64
name|Slba
decl_stmt|;
comment|/* Starting LBA */
comment|//
comment|// CDW 12
comment|//
name|UINT16
name|Nlb
decl_stmt|;
comment|/* Number of Logical Blocks */
name|UINT16
name|Rsvd1
range|:
literal|10
decl_stmt|;
name|UINT16
name|Prinfo
range|:
literal|4
decl_stmt|;
comment|/* Protection Info Check */
name|UINT16
name|Fua
range|:
literal|1
decl_stmt|;
comment|/* Force Unit Access */
name|UINT16
name|Lr
range|:
literal|1
decl_stmt|;
comment|/* Limited Retry */
comment|//
comment|// CDW 13
comment|//
name|UINT32
name|Rsvd2
decl_stmt|;
comment|//
comment|// CDW 14
comment|//
name|UINT32
name|Eilbrt
decl_stmt|;
comment|/* Expected Initial Logical Block Reference Tag */
comment|//
comment|// CDW 15
comment|//
name|UINT16
name|Elbat
decl_stmt|;
comment|/* Expected Logical Block Application Tag */
name|UINT16
name|Elbatm
decl_stmt|;
comment|/* Expected Logical Block Application Tag Mask */
block|}
name|NVME_COMPARE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|NVME_READ
name|Read
decl_stmt|;
name|NVME_WRITE
name|Write
decl_stmt|;
name|NVME_FLUSH
name|Flush
decl_stmt|;
name|NVME_WRITE_UNCORRECTABLE
name|WriteUncorrectable
decl_stmt|;
name|NVME_WRITE_ZEROES
name|WriteZeros
decl_stmt|;
name|NVME_COMPARE
name|Compare
decl_stmt|;
block|}
name|NVME_CMD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Mp
decl_stmt|;
comment|/* Maximum Power */
name|UINT8
name|Rsvd1
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
name|UINT8
name|Mps
range|:
literal|1
decl_stmt|;
comment|/* Max Power Scale */
name|UINT8
name|Nops
range|:
literal|1
decl_stmt|;
comment|/* Non-Operational State */
name|UINT8
name|Rsvd2
range|:
literal|6
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
name|UINT32
name|Enlat
decl_stmt|;
comment|/* Entry Latency */
name|UINT32
name|Exlat
decl_stmt|;
comment|/* Exit Latency */
name|UINT8
name|Rrt
range|:
literal|5
decl_stmt|;
comment|/* Relative Read Throughput */
name|UINT8
name|Rsvd3
range|:
literal|3
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
name|UINT8
name|Rrl
range|:
literal|5
decl_stmt|;
comment|/* Relative Read Leatency */
name|UINT8
name|Rsvd4
range|:
literal|3
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
name|UINT8
name|Rwt
range|:
literal|5
decl_stmt|;
comment|/* Relative Write Throughput */
name|UINT8
name|Rsvd5
range|:
literal|3
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
name|UINT8
name|Rwl
range|:
literal|5
decl_stmt|;
comment|/* Relative Write Leatency */
name|UINT8
name|Rsvd6
range|:
literal|3
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
name|UINT8
name|Rsvd7
index|[
literal|16
index|]
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
block|}
name|NVME_PSDESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Identify Controller Data
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Controller Capabilities and Features 0-255
comment|//
name|UINT16
name|Vid
decl_stmt|;
comment|/* PCI Vendor ID */
name|UINT16
name|Ssvid
decl_stmt|;
comment|/* PCI sub-system vendor ID */
name|UINT8
name|Sn
index|[
literal|20
index|]
decl_stmt|;
comment|/* Product serial number */
name|UINT8
name|Mn
index|[
literal|40
index|]
decl_stmt|;
comment|/* Proeduct model number */
name|UINT8
name|Fr
index|[
literal|8
index|]
decl_stmt|;
comment|/* Firmware Revision */
name|UINT8
name|Rab
decl_stmt|;
comment|/* Recommended Arbitration Burst */
name|UINT8
name|Ieee_oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* Organization Unique Identifier */
name|UINT8
name|Cmic
decl_stmt|;
comment|/* Multi-interface Capabilities */
name|UINT8
name|Mdts
decl_stmt|;
comment|/* Maximum Data Transfer Size */
name|UINT8
name|Cntlid
index|[
literal|2
index|]
decl_stmt|;
comment|/* Controller ID */
name|UINT8
name|Rsvd1
index|[
literal|176
index|]
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
comment|//
comment|// Admin Command Set Attributes
comment|//
name|UINT16
name|Oacs
decl_stmt|;
comment|/* Optional Admin Command Support */
define|#
directive|define
name|NAMESPACE_MANAGEMENT_SUPPORTED
value|BIT3
define|#
directive|define
name|FW_DOWNLOAD_ACTIVATE_SUPPORTED
value|BIT2
define|#
directive|define
name|FORMAT_NVM_SUPPORTED
value|BIT1
define|#
directive|define
name|SECURITY_SEND_RECEIVE_SUPPORTED
value|BIT0
name|UINT8
name|Acl
decl_stmt|;
comment|/* Abort Command Limit */
name|UINT8
name|Aerl
decl_stmt|;
comment|/* Async Event Request Limit */
name|UINT8
name|Frmw
decl_stmt|;
comment|/* Firmware updates */
name|UINT8
name|Lpa
decl_stmt|;
comment|/* Log Page Attributes */
name|UINT8
name|Elpe
decl_stmt|;
comment|/* Error Log Page Entries */
name|UINT8
name|Npss
decl_stmt|;
comment|/* Number of Power States Support */
name|UINT8
name|Avscc
decl_stmt|;
comment|/* Admin Vendor Specific Command Configuration */
name|UINT8
name|Apsta
decl_stmt|;
comment|/* Autonomous Power State Transition Attributes */
name|UINT8
name|Rsvd2
index|[
literal|246
index|]
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
comment|//
comment|// NVM Command Set Attributes
comment|//
name|UINT8
name|Sqes
decl_stmt|;
comment|/* Submission Queue Entry Size */
name|UINT8
name|Cqes
decl_stmt|;
comment|/* Completion Queue Entry Size */
name|UINT16
name|Rsvd3
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
name|UINT32
name|Nn
decl_stmt|;
comment|/* Number of Namespaces */
name|UINT16
name|Oncs
decl_stmt|;
comment|/* Optional NVM Command Support */
name|UINT16
name|Fuses
decl_stmt|;
comment|/* Fused Operation Support */
name|UINT8
name|Fna
decl_stmt|;
comment|/* Format NVM Attributes */
name|UINT8
name|Vwc
decl_stmt|;
comment|/* Volatile Write Cache */
name|UINT16
name|Awun
decl_stmt|;
comment|/* Atomic Write Unit Normal */
name|UINT16
name|Awupf
decl_stmt|;
comment|/* Atomic Write Unit Power Fail */
name|UINT8
name|Nvscc
decl_stmt|;
comment|/* NVM Vendor Specific Command Configuration */
name|UINT8
name|Rsvd4
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
name|UINT16
name|Acwu
decl_stmt|;
comment|/* Atomic Compare& Write Unit */
name|UINT16
name|Rsvd5
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
name|UINT32
name|Sgls
decl_stmt|;
comment|/* SGL Support  */
name|UINT8
name|Rsvd6
index|[
literal|164
index|]
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
comment|//
comment|// I/O Command set Attributes
comment|//
name|UINT8
name|Rsvd7
index|[
literal|1344
index|]
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
comment|//
comment|// Power State Descriptors
comment|//
name|NVME_PSDESCRIPTOR
name|PsDescriptor
index|[
literal|32
index|]
decl_stmt|;
name|UINT8
name|VendorData
index|[
literal|1024
index|]
decl_stmt|;
comment|/* Vendor specific data */
block|}
name|NVME_ADMIN_CONTROLLER_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Ms
decl_stmt|;
comment|/* Metadata Size */
name|UINT8
name|Lbads
decl_stmt|;
comment|/* LBA Data Size */
name|UINT8
name|Rp
range|:
literal|2
decl_stmt|;
comment|/* Relative Performance */
define|#
directive|define
name|LBAF_RP_BEST
value|00b
define|#
directive|define
name|LBAF_RP_BETTER
value|01b
define|#
directive|define
name|LBAF_RP_GOOD
value|10b
define|#
directive|define
name|LBAF_RP_DEGRADED
value|11b
name|UINT8
name|Rsvd1
range|:
literal|6
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
block|}
name|NVME_LBAFORMAT
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Identify Namespace Data
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// NVM Command Set Specific
comment|//
name|UINT64
name|Nsze
decl_stmt|;
comment|/* Namespace Size (total number of blocks in formatted namespace) */
name|UINT64
name|Ncap
decl_stmt|;
comment|/* Namespace Capacity (max number of logical blocks) */
name|UINT64
name|Nuse
decl_stmt|;
comment|/* Namespace Utilization */
name|UINT8
name|Nsfeat
decl_stmt|;
comment|/* Namespace Features */
name|UINT8
name|Nlbaf
decl_stmt|;
comment|/* Number of LBA Formats */
name|UINT8
name|Flbas
decl_stmt|;
comment|/* Formatted LBA size */
name|UINT8
name|Mc
decl_stmt|;
comment|/* Metadata Capabilities */
name|UINT8
name|Dpc
decl_stmt|;
comment|/* End-to-end Data Protection capabilities */
name|UINT8
name|Dps
decl_stmt|;
comment|/* End-to-end Data Protection Type Settings */
name|UINT8
name|Nmic
decl_stmt|;
comment|/* Namespace Multi-path I/O and Namespace Sharing Capabilities */
name|UINT8
name|Rescap
decl_stmt|;
comment|/* Reservation Capabilities */
name|UINT8
name|Rsvd1
index|[
literal|88
index|]
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
name|UINT64
name|Eui64
decl_stmt|;
comment|/* IEEE Extended Unique Identifier */
comment|//
comment|// LBA Format
comment|//
name|NVME_LBAFORMAT
name|LbaFormat
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|Rsvd2
index|[
literal|192
index|]
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
name|UINT8
name|VendorData
index|[
literal|3712
index|]
decl_stmt|;
comment|/* Vendor specific data */
block|}
name|NVME_ADMIN_NAMESPACE_DATA
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Identify Cmd
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT32
name|Cns
range|:
literal|2
decl_stmt|;
name|UINT32
name|Rsvd1
range|:
literal|30
decl_stmt|;
block|}
name|NVME_ADMIN_IDENTIFY
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Create I/O Completion Queue
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT32
name|Qid
range|:
literal|16
decl_stmt|;
comment|/* Queue Identifier */
name|UINT32
name|Qsize
range|:
literal|16
decl_stmt|;
comment|/* Queue Size */
comment|//
comment|// CDW 11
comment|//
name|UINT32
name|Pc
range|:
literal|1
decl_stmt|;
comment|/* Physically Contiguous */
name|UINT32
name|Ien
range|:
literal|1
decl_stmt|;
comment|/* Interrupts Enabled */
name|UINT32
name|Rsvd1
range|:
literal|14
decl_stmt|;
comment|/* reserved as of Nvm Express 1.1 Spec */
name|UINT32
name|Iv
range|:
literal|16
decl_stmt|;
comment|/* Interrupt Vector for MSI-X or MSI*/
block|}
name|NVME_ADMIN_CRIOCQ
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Create I/O Submission Queue
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT32
name|Qid
range|:
literal|16
decl_stmt|;
comment|/* Queue Identifier */
name|UINT32
name|Qsize
range|:
literal|16
decl_stmt|;
comment|/* Queue Size */
comment|//
comment|// CDW 11
comment|//
name|UINT32
name|Pc
range|:
literal|1
decl_stmt|;
comment|/* Physically Contiguous */
name|UINT32
name|Qprio
range|:
literal|2
decl_stmt|;
comment|/* Queue Priority */
name|UINT32
name|Rsvd1
range|:
literal|13
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
name|UINT32
name|Cqid
range|:
literal|16
decl_stmt|;
comment|/* Completion Queue ID */
block|}
name|NVME_ADMIN_CRIOSQ
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Delete I/O Completion Queue
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT16
name|Qid
decl_stmt|;
name|UINT16
name|Rsvd1
decl_stmt|;
block|}
name|NVME_ADMIN_DEIOCQ
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Delete I/O Submission Queue
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT16
name|Qid
decl_stmt|;
name|UINT16
name|Rsvd1
decl_stmt|;
block|}
name|NVME_ADMIN_DEIOSQ
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Abort Command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT32
name|Sqid
range|:
literal|16
decl_stmt|;
comment|/* Submission Queue identifier */
name|UINT32
name|Cid
range|:
literal|16
decl_stmt|;
comment|/* Command Identifier */
block|}
name|NVME_ADMIN_ABORT
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Firmware Activate Command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT32
name|Fs
range|:
literal|3
decl_stmt|;
comment|/* Submission Queue identifier */
name|UINT32
name|Aa
range|:
literal|2
decl_stmt|;
comment|/* Command Identifier */
name|UINT32
name|Rsvd1
range|:
literal|27
decl_stmt|;
block|}
name|NVME_ADMIN_FIRMWARE_ACTIVATE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Firmware Image Download Command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT32
name|Numd
decl_stmt|;
comment|/* Number of Dwords */
comment|//
comment|// CDW 11
comment|//
name|UINT32
name|Ofst
decl_stmt|;
comment|/* Offset */
block|}
name|NVME_ADMIN_FIRMWARE_IMAGE_DOWNLOAD
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Get Features Command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT32
name|Fid
range|:
literal|8
decl_stmt|;
comment|/* Feature Identifier */
name|UINT32
name|Sel
range|:
literal|3
decl_stmt|;
comment|/* Select */
name|UINT32
name|Rsvd1
range|:
literal|21
decl_stmt|;
block|}
name|NVME_ADMIN_GET_FEATURES
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Get Log Page Command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT32
name|Lid
range|:
literal|8
decl_stmt|;
comment|/* Log Page Identifier */
define|#
directive|define
name|LID_ERROR_INFO
value|0x1
define|#
directive|define
name|LID_SMART_INFO
value|0x2
define|#
directive|define
name|LID_FW_SLOT_INFO
value|0x3
name|UINT32
name|Rsvd1
range|:
literal|8
decl_stmt|;
name|UINT32
name|Numd
range|:
literal|12
decl_stmt|;
comment|/* Number of Dwords */
name|UINT32
name|Rsvd2
range|:
literal|4
decl_stmt|;
comment|/* Reserved as of Nvm Express 1.1 Spec */
block|}
name|NVME_ADMIN_GET_LOG_PAGE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Set Features Command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT32
name|Fid
range|:
literal|8
decl_stmt|;
comment|/* Feature Identifier */
name|UINT32
name|Rsvd1
range|:
literal|23
decl_stmt|;
name|UINT32
name|Sv
range|:
literal|1
decl_stmt|;
comment|/* Save */
block|}
name|NVME_ADMIN_SET_FEATURES
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Format NVM Command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT32
name|Lbaf
range|:
literal|4
decl_stmt|;
comment|/* LBA Format */
name|UINT32
name|Ms
range|:
literal|1
decl_stmt|;
comment|/* Metadata Settings */
name|UINT32
name|Pi
range|:
literal|3
decl_stmt|;
comment|/* Protection Information */
name|UINT32
name|Pil
range|:
literal|1
decl_stmt|;
comment|/* Protection Information Location */
name|UINT32
name|Ses
range|:
literal|3
decl_stmt|;
comment|/* Secure Erase Settings */
name|UINT32
name|Rsvd1
range|:
literal|20
decl_stmt|;
block|}
name|NVME_ADMIN_FORMAT_NVM
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Security Receive Command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT32
name|Rsvd1
range|:
literal|8
decl_stmt|;
name|UINT32
name|Spsp
range|:
literal|16
decl_stmt|;
comment|/* SP Specific */
name|UINT32
name|Secp
range|:
literal|8
decl_stmt|;
comment|/* Security Protocol */
comment|//
comment|// CDW 11
comment|//
name|UINT32
name|Al
decl_stmt|;
comment|/* Allocation Length */
block|}
name|NVME_ADMIN_SECURITY_RECEIVE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NvmExpress Admin Security Send Command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 10
comment|//
name|UINT32
name|Rsvd1
range|:
literal|8
decl_stmt|;
name|UINT32
name|Spsp
range|:
literal|16
decl_stmt|;
comment|/* SP Specific */
name|UINT32
name|Secp
range|:
literal|8
decl_stmt|;
comment|/* Security Protocol */
comment|//
comment|// CDW 11
comment|//
name|UINT32
name|Tl
decl_stmt|;
comment|/* Transfer Length */
block|}
name|NVME_ADMIN_SECURITY_SEND
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|NVME_ADMIN_IDENTIFY
name|Identify
decl_stmt|;
name|NVME_ADMIN_CRIOCQ
name|CrIoCq
decl_stmt|;
name|NVME_ADMIN_CRIOSQ
name|CrIoSq
decl_stmt|;
name|NVME_ADMIN_DEIOCQ
name|DeIoCq
decl_stmt|;
name|NVME_ADMIN_DEIOSQ
name|DeIoSq
decl_stmt|;
name|NVME_ADMIN_ABORT
name|Abort
decl_stmt|;
name|NVME_ADMIN_FIRMWARE_ACTIVATE
name|Activate
decl_stmt|;
name|NVME_ADMIN_FIRMWARE_IMAGE_DOWNLOAD
name|FirmwareImageDownload
decl_stmt|;
name|NVME_ADMIN_GET_FEATURES
name|GetFeatures
decl_stmt|;
name|NVME_ADMIN_GET_LOG_PAGE
name|GetLogPage
decl_stmt|;
name|NVME_ADMIN_SET_FEATURES
name|SetFeatures
decl_stmt|;
name|NVME_ADMIN_FORMAT_NVM
name|FormatNvm
decl_stmt|;
name|NVME_ADMIN_SECURITY_RECEIVE
name|SecurityReceive
decl_stmt|;
name|NVME_ADMIN_SECURITY_SEND
name|SecuritySend
decl_stmt|;
block|}
name|NVME_ADMIN_CMD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Cdw10
decl_stmt|;
name|UINT32
name|Cdw11
decl_stmt|;
name|UINT32
name|Cdw12
decl_stmt|;
name|UINT32
name|Cdw13
decl_stmt|;
name|UINT32
name|Cdw14
decl_stmt|;
name|UINT32
name|Cdw15
decl_stmt|;
block|}
name|NVME_RAW
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|NVME_ADMIN_CMD
name|Admin
decl_stmt|;
comment|// Union of Admin commands
name|NVME_CMD
name|Nvm
decl_stmt|;
comment|// Union of Nvm commands
name|NVME_RAW
name|Raw
decl_stmt|;
block|}
name|NVME_PAYLOAD
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Submission Queue
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 0, Common to all comnmands
comment|//
name|UINT8
name|Opc
decl_stmt|;
comment|// Opcode
name|UINT8
name|Fuse
range|:
literal|2
decl_stmt|;
comment|// Fused Operation
name|UINT8
name|Rsvd1
range|:
literal|5
decl_stmt|;
name|UINT8
name|Psdt
range|:
literal|1
decl_stmt|;
comment|// PRP or SGL for Data Transfer
name|UINT16
name|Cid
decl_stmt|;
comment|// Command Identifier
comment|//
comment|// CDW 1
comment|//
name|UINT32
name|Nsid
decl_stmt|;
comment|// Namespace Identifier
comment|//
comment|// CDW 2,3
comment|//
name|UINT64
name|Rsvd2
decl_stmt|;
comment|//
comment|// CDW 4,5
comment|//
name|UINT64
name|Mptr
decl_stmt|;
comment|// Metadata Pointer
comment|//
comment|// CDW 6-9
comment|//
name|UINT64
name|Prp
index|[
literal|2
index|]
decl_stmt|;
comment|// First and second PRP entries
name|NVME_PAYLOAD
name|Payload
decl_stmt|;
block|}
name|NVME_SQ
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Completion Queue
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// CDW 0
comment|//
name|UINT32
name|Dword0
decl_stmt|;
comment|//
comment|// CDW 1
comment|//
name|UINT32
name|Rsvd1
decl_stmt|;
comment|//
comment|// CDW 2
comment|//
name|UINT16
name|Sqhd
decl_stmt|;
comment|// Submission Queue Head Pointer
name|UINT16
name|Sqid
decl_stmt|;
comment|// Submission Queue Identifier
comment|//
comment|// CDW 3
comment|//
name|UINT16
name|Cid
decl_stmt|;
comment|// Command Identifier
name|UINT16
name|Pt
range|:
literal|1
decl_stmt|;
comment|// Phase Tag
name|UINT16
name|Sc
range|:
literal|8
decl_stmt|;
comment|// Status Code
name|UINT16
name|Sct
range|:
literal|3
decl_stmt|;
comment|// Status Code Type
name|UINT16
name|Rsvd2
range|:
literal|2
decl_stmt|;
name|UINT16
name|Mo
range|:
literal|1
decl_stmt|;
comment|// More
name|UINT16
name|Dnr
range|:
literal|1
decl_stmt|;
comment|// Do Not Retry
block|}
name|NVME_CQ
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Nvm Express Admin cmd opcodes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NVME_ADMIN_DEIOSQ_CMD
value|0x00
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_CRIOSQ_CMD
value|0x01
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_GET_LOG_PAGE_CMD
value|0x02
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_DEIOCQ_CMD
value|0x04
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_CRIOCQ_CMD
value|0x05
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_IDENTIFY_CMD
value|0x06
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_ABORT_CMD
value|0x08
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_SET_FEATURES_CMD
value|0x09
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_GET_FEATURES_CMD
value|0x0A
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_ASYNC_EVENT_REQUEST_CMD
value|0x0C
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_NAMESACE_MANAGEMENT_CMD
value|0x0D
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_FW_COMMIT_CMD
value|0x10
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_FW_IAMGE_DOWNLOAD_CMD
value|0x11
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_NAMESACE_ATTACHMENT_CMD
value|0x15
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_FORMAT_NVM_CMD
value|0x80
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_SECURITY_SEND_CMD
value|0x81
end_define

begin_define
define|#
directive|define
name|NVME_ADMIN_SECURITY_RECEIVE_CMD
value|0x82
end_define

begin_define
define|#
directive|define
name|NVME_IO_FLUSH_OPC
value|0
end_define

begin_define
define|#
directive|define
name|NVME_IO_WRITE_OPC
value|1
end_define

begin_define
define|#
directive|define
name|NVME_IO_READ_OPC
value|2
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|DeleteIOSubmissionQueueOpcode
init|=
name|NVME_ADMIN_DEIOSQ_CMD
block|,
name|CreateIOSubmissionQueueOpcode
init|=
name|NVME_ADMIN_CRIOSQ_CMD
block|,
name|GetLogPageOpcode
init|=
name|NVME_ADMIN_GET_LOG_PAGE_CMD
block|,
name|DeleteIOCompletionQueueOpcode
init|=
name|NVME_ADMIN_DEIOCQ_CMD
block|,
name|CreateIOCompletionQueueOpcode
init|=
name|NVME_ADMIN_CRIOCQ_CMD
block|,
name|IdentifyOpcode
init|=
name|NVME_ADMIN_IDENTIFY_CMD
block|,
name|AbortOpcode
init|=
name|NVME_ADMIN_ABORT_CMD
block|,
name|SetFeaturesOpcode
init|=
name|NVME_ADMIN_SET_FEATURES_CMD
block|,
name|GetFeaturesOpcode
init|=
name|NVME_ADMIN_GET_FEATURES_CMD
block|,
name|AsyncEventRequestOpcode
init|=
name|NVME_ADMIN_ASYNC_EVENT_REQUEST_CMD
block|,
name|NamespaceManagementOpcode
init|=
name|NVME_ADMIN_NAMESACE_MANAGEMENT_CMD
block|,
name|FirmwareCommitOpcode
init|=
name|NVME_ADMIN_FW_COMMIT_CMD
block|,
name|FirmwareImageDownloadOpcode
init|=
name|NVME_ADMIN_FW_IAMGE_DOWNLOAD_CMD
block|,
name|NamespaceAttachmentOpcode
init|=
name|NVME_ADMIN_NAMESACE_ATTACHMENT_CMD
block|,
name|FormatNvmOpcode
init|=
name|NVME_ADMIN_FORMAT_NVM_CMD
block|,
name|SecuritySendOpcode
init|=
name|NVME_ADMIN_SECURITY_SEND_CMD
block|,
name|SecurityReceiveOpcode
init|=
name|NVME_ADMIN_SECURITY_RECEIVE_CMD
block|}
name|NVME_ADMIN_COMMAND_OPCODE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Controller or Namespace Structure (CNS) field
end_comment

begin_comment
comment|// (ref. spec. v1.1 figure 82).
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IdentifyNamespaceCns
init|=
literal|0x0
block|,
name|IdentifyControllerCns
init|=
literal|0x1
block|,
name|IdentifyActiveNsListCns
init|=
literal|0x2
block|}
name|NVME_ADMIN_IDENTIFY_CNS
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Commit Action
end_comment

begin_comment
comment|// (ref. spec. 1.1 figure 60).
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ActivateActionReplace
init|=
literal|0x0
block|,
name|ActivateActionReplaceActivate
init|=
literal|0x1
block|,
name|ActivateActionActivate
init|=
literal|0x2
block|}
name|NVME_FW_ACTIVATE_ACTION
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Firmware Slot
end_comment

begin_comment
comment|// (ref. spec. 1.1 Figure 60).
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FirmwareSlotCtrlChooses
init|=
literal|0x0
block|,
name|FirmwareSlot1
init|=
literal|0x1
block|,
name|FirmwareSlot2
init|=
literal|0x2
block|,
name|FirmwareSlot3
init|=
literal|0x3
block|,
name|FirmwareSlot4
init|=
literal|0x4
block|,
name|FirmwareSlot5
init|=
literal|0x5
block|,
name|FirmwareSlot6
init|=
literal|0x6
block|,
name|FirmwareSlot7
init|=
literal|0x7
block|}
name|NVME_FW_ACTIVATE_SLOT
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Get Log Page ? Log Page Identifiers
end_comment

begin_comment
comment|// (ref. spec. v1.1 Figure 73).
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ErrorInfoLogID
init|=
name|LID_ERROR_INFO
block|,
name|SmartHealthInfoLogID
init|=
name|LID_SMART_INFO
block|,
name|FirmwareSlotInfoLogID
init|=
name|LID_FW_SLOT_INFO
block|}
name|NVME_LOG_ID
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Get Log Page ? Firmware Slot Information Log
end_comment

begin_comment
comment|// (ref. spec. v1.1 Figure 77).
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Indicates the firmware slot from which the actively running firmware revision was loaded.
comment|//
name|UINT8
name|ActivelyRunningFwSlot
range|:
literal|3
decl_stmt|;
name|UINT8
label|:
literal|1
expr_stmt|;
comment|//
comment|// Indicates the firmware slot that is going to be activated at the next controller reset. If this field is 0h, then the controller does not indicate the firmware slot that is going to be activated at the next controller reset.
comment|//
name|UINT8
name|NextActiveFwSlot
range|:
literal|3
decl_stmt|;
name|UINT8
label|:
literal|1
expr_stmt|;
block|}
name|NVME_ACTIVE_FW_INFO
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Get Log Page ? Firmware Slot Information Log
end_comment

begin_comment
comment|// (ref. spec. v1.1 Figure 77).
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Specifies information about the active firmware revision.
comment|//s
name|NVME_ACTIVE_FW_INFO
name|ActiveFwInfo
decl_stmt|;
name|UINT8
name|Reserved1
index|[
literal|7
index|]
decl_stmt|;
comment|//
comment|// Contains the revision of the firmware downloaded to firmware slot 1/7. If no valid firmware revision is present or if this slot is unsupported, all zeros shall be returned.
comment|//
name|CHAR8
name|FwRevisionSlot
index|[
literal|7
index|]
index|[
literal|8
index|]
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|448
index|]
decl_stmt|;
block|}
name|NVME_FW_SLOT_INFO_LOG
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// SMART / Health Information (Log Identifier 02h)
end_comment

begin_comment
comment|// (ref. spec. v1.1 5.10.1.2)
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// This field indicates critical warnings for the state of the controller.
comment|//
name|UINT8
name|CriticalWarningAvailableSpare
range|:
literal|1
decl_stmt|;
name|UINT8
name|CriticalWarningTemperature
range|:
literal|1
decl_stmt|;
name|UINT8
name|CriticalWarningReliability
range|:
literal|1
decl_stmt|;
name|UINT8
name|CriticalWarningMediaReadOnly
range|:
literal|1
decl_stmt|;
name|UINT8
name|CriticalWarningVolatileBackup
range|:
literal|1
decl_stmt|;
name|UINT8
name|CriticalWarningReserved
range|:
literal|3
decl_stmt|;
comment|//
comment|// Contains a value corresponding to a temperature in degrees Kelvin that represents the current composite temperature of the controller and namespace(s) associated with that controller. The manner in which this value is computed is implementation specific and may not represent the actual temperature of any physical point in the NVM subsystem.
comment|//
name|UINT16
name|CompositeTemp
decl_stmt|;
comment|//
comment|// Contains a normalized percentage (0 to 100%) of the remaining spare capacity available.
comment|//
name|UINT8
name|AvailableSpare
decl_stmt|;
comment|//
comment|// When the Available Spare falls below the threshold indicated in this field, an asynchronous event completion may occur. The value is indicated as a normalized percentage (0 to 100%).
comment|//
name|UINT8
name|AvailableSpareThreshold
decl_stmt|;
comment|//
comment|// Contains a vendor specific estimate of the percentage of NVM subsystem life used based on the actual usage and the manufacturer?s prediction of NVM life. A value of 100 indicates that the estimated endurance of the NVM in the NVM subsystem has been consumed, but may not indicate an NVM subsystem failure. The value is allowed to exceed 100. Percentages greater than 254 shall be represented as 255. This value shall be updated once per power-on hour (when the controller is not in a sleep state).
comment|//
name|UINT8
name|PercentageUsed
decl_stmt|;
name|UINT8
name|Reserved1
index|[
literal|26
index|]
decl_stmt|;
comment|//
comment|// Contains the number of 512 byte data units the host has read from the controller; this value does not include metadata.
comment|//
name|UINT8
name|DataUnitsRead
index|[
literal|16
index|]
decl_stmt|;
comment|//
comment|// Contains the number of 512 byte data units the host has written to the controller; this value does not include metadata.
comment|//
name|UINT8
name|DataUnitsWritten
index|[
literal|16
index|]
decl_stmt|;
comment|//
comment|// Contains the number of read commands completed by the controller.
comment|//
name|UINT8
name|HostReadCommands
index|[
literal|16
index|]
decl_stmt|;
comment|//
comment|// Contains the number of write commands completed by the controller.
comment|//
name|UINT8
name|HostWriteCommands
index|[
literal|16
index|]
decl_stmt|;
comment|//
comment|// Contains the amount of time the controller is busy with I/O commands. This value is reported in minutes.
comment|//
name|UINT8
name|ControllerBusyTime
index|[
literal|16
index|]
decl_stmt|;
comment|//
comment|// Contains the number of power cycles.
comment|//
name|UINT8
name|PowerCycles
index|[
literal|16
index|]
decl_stmt|;
comment|//
comment|// Contains the number of power-on hours.
comment|//
name|UINT8
name|PowerOnHours
index|[
literal|16
index|]
decl_stmt|;
comment|//
comment|// Contains the number of unsafe shutdowns.
comment|//
name|UINT8
name|UnsafeShutdowns
index|[
literal|16
index|]
decl_stmt|;
comment|//
comment|// Contains the number of occurrences where the controller detected an unrecovered data integrity error.
comment|//
name|UINT8
name|MediaAndDataIntegrityErrors
index|[
literal|16
index|]
decl_stmt|;
comment|//
comment|// Contains the number of Error Information log entries over the life of the controller.
comment|//
name|UINT8
name|NumberErrorInformationLogEntries
index|[
literal|16
index|]
decl_stmt|;
comment|//
comment|// Contains the amount of time in minutes that the controller is operational and the Composite Temperature is greater than or equal to the Warning Composite Temperature Threshold (WCTEMP) field and less than the Critical Composite Temperature Threshold (CCTEMP) field in the Identify Controller data structure in Figure 90.
comment|//
name|UINT32
name|WarningCompositeTemperatureTime
decl_stmt|;
comment|//
comment|// Contains the amount of time in minutes that the controller is operational and the Composite Temperature is greater the Critical Composite Temperature Threshold (CCTEMP) field in the Identify Controller data structure in Figure 90.
comment|//
name|UINT32
name|CriticalCompositeTemperatureTime
decl_stmt|;
comment|//
comment|// Contains the current temperature in degrees Kelvin reported by the temperature sensor.  An implementation that does not implement the temperature sensor reports a temperature of zero degrees Kelvin.
comment|//
name|UINT16
name|TemperatureSensor
index|[
literal|8
index|]
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|296
index|]
decl_stmt|;
block|}
name|NVME_SMART_HEALTH_INFO_LOG
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

