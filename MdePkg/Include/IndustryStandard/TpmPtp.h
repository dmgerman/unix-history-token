begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Platform TPM Profile Specification definition for TPM2.0.   It covers both FIFO and CRB interface.  Copyright (c) 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TPM_PTP_H_
end_ifndef

begin_define
define|#
directive|define
name|_TPM_PTP_H_
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// PTP FIFO definition
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Set structure alignment to 1-byte
end_comment

begin_comment
comment|//
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
comment|// Register set map as specified in PTP specification Chapter 5
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Used to gain ownership for this particular port.
comment|///
name|UINT8
name|Access
decl_stmt|;
comment|// 0
name|UINT8
name|Reserved1
index|[
literal|7
index|]
decl_stmt|;
comment|// 1
comment|///
comment|/// Controls interrupts.
comment|///
name|UINT32
name|IntEnable
decl_stmt|;
comment|// 8
comment|///
comment|/// SIRQ vector to be used by the TPM.
comment|///
name|UINT8
name|IntVector
decl_stmt|;
comment|// 0ch
name|UINT8
name|Reserved2
index|[
literal|3
index|]
decl_stmt|;
comment|// 0dh
comment|///
comment|/// What caused interrupt.
comment|///
name|UINT32
name|IntSts
decl_stmt|;
comment|// 10h
comment|///
comment|/// Shows which interrupts are supported by that particular TPM.
comment|///
name|UINT32
name|InterfaceCapability
decl_stmt|;
comment|// 14h
comment|///
comment|/// Status Register. Provides status of the TPM.
comment|///
name|UINT8
name|Status
decl_stmt|;
comment|// 18h
comment|///
comment|/// Number of consecutive writes that can be done to the TPM.
comment|///
name|UINT16
name|BurstCount
decl_stmt|;
comment|// 19h
comment|///
comment|/// Additional Status Register.
comment|///
name|UINT8
name|StatusEx
decl_stmt|;
comment|// 1Bh
name|UINT8
name|Reserved3
index|[
literal|8
index|]
decl_stmt|;
comment|///
comment|/// Read or write FIFO, depending on transaction.
comment|///
name|UINT32
name|DataFifo
decl_stmt|;
comment|// 24h
name|UINT8
name|Reserved4
index|[
literal|8
index|]
decl_stmt|;
comment|// 28h
comment|///
comment|/// Used to identify the Interface types supported by the TPM.
comment|///
name|UINT32
name|InterfaceId
decl_stmt|;
comment|// 30h
name|UINT8
name|Reserved5
index|[
literal|0x4c
index|]
decl_stmt|;
comment|// 34h
comment|///
comment|/// Extended ReadFIFO or WriteFIFO, depending on the current bus cycle (read or write)
comment|///
name|UINT32
name|XDataFifo
decl_stmt|;
comment|// 80h
name|UINT8
name|Reserved6
index|[
literal|0xe7c
index|]
decl_stmt|;
comment|// 84h
comment|///
comment|/// Vendor ID
comment|///
name|UINT16
name|Vid
decl_stmt|;
comment|// 0f00h
comment|///
comment|/// Device ID
comment|///
name|UINT16
name|Did
decl_stmt|;
comment|// 0f02h
comment|///
comment|/// Revision ID
comment|///
name|UINT8
name|Rid
decl_stmt|;
comment|// 0f04h
name|UINT8
name|Reserved
index|[
literal|0xfb
index|]
decl_stmt|;
comment|// 0f05h
block|}
name|PTP_FIFO_REGISTERS
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Restore original structure alignment
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Define pointer types used to access TIS registers on PC
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|PTP_FIFO_REGISTERS
modifier|*
name|PTP_FIFO_REGISTERS_PTR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Define bits of FIFO Interface Identifier Register
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|InterfaceType
range|:
literal|4
decl_stmt|;
name|UINT32
name|InterfaceVersion
range|:
literal|4
decl_stmt|;
name|UINT32
name|CapLocality
range|:
literal|1
decl_stmt|;
name|UINT32
name|Reserved1
range|:
literal|2
decl_stmt|;
name|UINT32
name|CapDataXferSizeSupport
range|:
literal|2
decl_stmt|;
name|UINT32
name|CapFIFO
range|:
literal|1
decl_stmt|;
name|UINT32
name|CapCRB
range|:
literal|1
decl_stmt|;
name|UINT32
name|CapIFRes
range|:
literal|2
decl_stmt|;
name|UINT32
name|InterfaceSelector
range|:
literal|2
decl_stmt|;
name|UINT32
name|IntfSelLock
range|:
literal|1
decl_stmt|;
name|UINT32
name|Reserved2
range|:
literal|4
decl_stmt|;
name|UINT32
name|Reserved3
range|:
literal|8
decl_stmt|;
block|}
name|Bits
struct|;
name|UINT32
name|Uint32
decl_stmt|;
block|}
name|PTP_FIFO_INTERFACE_IDENTIFIER
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Define bits of FIFO Interface Capability Register
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|DataAvailIntSupport
range|:
literal|1
decl_stmt|;
name|UINT32
name|StsValidIntSupport
range|:
literal|1
decl_stmt|;
name|UINT32
name|LocalityChangeIntSupport
range|:
literal|1
decl_stmt|;
name|UINT32
name|InterruptLevelHigh
range|:
literal|1
decl_stmt|;
name|UINT32
name|InterruptLevelLow
range|:
literal|1
decl_stmt|;
name|UINT32
name|InterruptEdgeRising
range|:
literal|1
decl_stmt|;
name|UINT32
name|InterruptEdgeFalling
range|:
literal|1
decl_stmt|;
name|UINT32
name|CommandReadyIntSupport
range|:
literal|1
decl_stmt|;
name|UINT32
name|BurstCountStatic
range|:
literal|1
decl_stmt|;
name|UINT32
name|DataTransferSizeSupport
range|:
literal|2
decl_stmt|;
name|UINT32
name|Reserved
range|:
literal|17
decl_stmt|;
name|UINT32
name|InterfaceVersion
range|:
literal|3
decl_stmt|;
name|UINT32
name|Reserved2
range|:
literal|1
decl_stmt|;
block|}
name|Bits
struct|;
name|UINT32
name|Uint32
decl_stmt|;
block|}
name|PTP_FIFO_INTERFACE_CAPABILITY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// InterfaceVersion
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|INTERFACE_CAPABILITY_INTERFACE_VERSION_TIS_12
value|0x0
end_define

begin_define
define|#
directive|define
name|INTERFACE_CAPABILITY_INTERFACE_VERSION_TIS_13
value|0x2
end_define

begin_define
define|#
directive|define
name|INTERFACE_CAPABILITY_INTERFACE_VERSION_PTP
value|0x3
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define bits of ACCESS and STATUS registers
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This bit is a 1 to indicate that the other bits in this register are valid.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_VALID
value|BIT7
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Indicate that this locality is active.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_ACC_ACTIVE
value|BIT5
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Set to 1 to indicate that this locality had the TPM taken away while
end_comment

begin_comment
comment|/// this locality had the TIS_PC_ACC_ACTIVE bit set.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_ACC_SEIZED
value|BIT4
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Set to 1 to indicate that TPM MUST reset the
end_comment

begin_comment
comment|/// TIS_PC_ACC_ACTIVE bit and remove ownership for localities less than the
end_comment

begin_comment
comment|/// locality that is writing this bit.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_ACC_SEIZE
value|BIT3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// When this bit is 1, another locality is requesting usage of the TPM.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_ACC_PENDIND
value|BIT2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Set to 1 to indicate that this locality is requesting to use TPM.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_ACC_RQUUSE
value|BIT1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A value of 1 indicates that a T/OS has not been established on the platform
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_ACC_ESTABLISH
value|BIT0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This field indicates that STS_DATA and STS_EXPECT are valid
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_STS_VALID
value|BIT7
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// When this bit is 1, TPM is in the Ready state,
end_comment

begin_comment
comment|/// indicating it is ready to receive a new command.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_STS_READY
value|BIT6
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Write a 1 to this bit to cause the TPM to execute that command.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_STS_GO
value|BIT5
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This bit indicates that the TPM has data available as a response.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_STS_DATA
value|BIT4
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The TPM sets this bit to a value of 1 when it expects another byte of data for a command.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_STS_EXPECT
value|BIT3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Indicates that the TPM has completed all self-test actions following a TPM_ContinueSelfTest command.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_STS_SELFTEST_DONE
value|BIT2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Writes a 1 to this bit to force the TPM to re-send the response.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_STS_RETRY
value|BIT1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TPM Family Identifier.
end_comment

begin_comment
comment|/// 00: TPM 1.2 Family
end_comment

begin_comment
comment|/// 01: TPM 2.0 Family
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_STS_EX_TPM_FAMILY
value|(BIT2 | BIT3)
end_define

begin_define
define|#
directive|define
name|PTP_FIFO_STS_EX_TPM_FAMILY_OFFSET
value|(2)
end_define

begin_define
define|#
directive|define
name|PTP_FIFO_STS_EX_TPM_FAMILY_TPM12
value|(0)
end_define

begin_define
define|#
directive|define
name|PTP_FIFO_STS_EX_TPM_FAMILY_TPM20
value|(BIT2)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A write of 1 after tpmGo and before dataAvail aborts the currently executing command, resulting in a response of TPM_RC_CANCELLED.
end_comment

begin_comment
comment|/// A write of 1 after dataAvail and before tpmGo is ignored by the TPM.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_FIFO_STS_EX_CANCEL
value|BIT0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// PTP CRB definition
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Set structure alignment to 1-byte
end_comment

begin_comment
comment|//
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
comment|// Register set map as specified in PTP specification Chapter 5
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Used to determine current state of Locality of the TPM.
comment|///
name|UINT32
name|LocalityState
decl_stmt|;
comment|// 0
name|UINT8
name|Reserved1
index|[
literal|4
index|]
decl_stmt|;
comment|// 4
comment|///
comment|/// Used to gain control of the TPM by this Locality.
comment|///
name|UINT32
name|LocalityControl
decl_stmt|;
comment|// 8
comment|///
comment|/// Used to determine whether Locality has been granted or Seized.
comment|///
name|UINT32
name|LocalityStatus
decl_stmt|;
comment|// 0ch
name|UINT8
name|Reserved2
index|[
literal|0x20
index|]
decl_stmt|;
comment|// 10h
comment|///
comment|/// Used to identify the Interface types supported by the TPM.
comment|///
name|UINT32
name|InterfaceId
decl_stmt|;
comment|// 30h
comment|///
comment|/// Vendor ID
comment|///
name|UINT16
name|Vid
decl_stmt|;
comment|// 34h
comment|///
comment|/// Device ID
comment|///
name|UINT16
name|Did
decl_stmt|;
comment|// 36h
comment|///
comment|/// Optional Register used in low memory environments prior to CRB_DATA_BUFFER availability.
comment|///
name|UINT64
name|CrbControlExtension
decl_stmt|;
comment|// 38h
comment|///
comment|/// Register used to initiate transactions for the CRB interface.
comment|///
name|UINT32
name|CrbControlRequest
decl_stmt|;
comment|// 40h
comment|///
comment|/// Register used by the TPM to provide status of the CRB interface.
comment|///
name|UINT32
name|CrbControlStatus
decl_stmt|;
comment|// 44h
comment|///
comment|/// Register used by software to cancel command processing.
comment|///
name|UINT32
name|CrbControlCancel
decl_stmt|;
comment|// 48h
comment|///
comment|/// Register used to indicate presence of command or response data in the CRB buffer.
comment|///
name|UINT32
name|CrbControlStart
decl_stmt|;
comment|// 4Ch
comment|///
comment|/// Register used to configure and respond to interrupts.
comment|///
name|UINT32
name|CrbInterruptEnable
decl_stmt|;
comment|// 50h
name|UINT32
name|CrbInterruptStatus
decl_stmt|;
comment|// 54h
comment|///
comment|/// Size of the Command buffer.
comment|///
name|UINT32
name|CrbControlCommandSize
decl_stmt|;
comment|// 58h
comment|///
comment|/// Command buffer start address
comment|///
name|UINT32
name|CrbControlCommandAddressLow
decl_stmt|;
comment|// 5Ch
name|UINT32
name|CrbControlCommandAddressHigh
decl_stmt|;
comment|// 60h
comment|///
comment|/// Size of the Response buffer
comment|///
name|UINT32
name|CrbControlResponseSize
decl_stmt|;
comment|// 64h
comment|///
comment|/// Address of the start of the Response buffer
comment|///
name|UINT64
name|CrbControlResponseAddrss
decl_stmt|;
comment|// 68h
name|UINT8
name|Reserved4
index|[
literal|0x10
index|]
decl_stmt|;
comment|// 70h
comment|///
comment|/// Command/Response Data may be defined as large as 3968 (0xF80).
comment|///
name|UINT8
name|CrbDataBuffer
index|[
literal|0xF80
index|]
decl_stmt|;
comment|// 80h
block|}
name|PTP_CRB_REGISTERS
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Define pointer types used to access CRB registers on PTP
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|PTP_CRB_REGISTERS
modifier|*
name|PTP_CRB_REGISTERS_PTR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Define bits of CRB Interface Identifier Register
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|InterfaceType
range|:
literal|4
decl_stmt|;
name|UINT32
name|InterfaceVersion
range|:
literal|4
decl_stmt|;
name|UINT32
name|CapLocality
range|:
literal|1
decl_stmt|;
name|UINT32
name|Reserved1
range|:
literal|2
decl_stmt|;
name|UINT32
name|CapDataXferSizeSupport
range|:
literal|2
decl_stmt|;
name|UINT32
name|CapFIFO
range|:
literal|1
decl_stmt|;
name|UINT32
name|CapCRB
range|:
literal|1
decl_stmt|;
name|UINT32
name|CapIFRes
range|:
literal|2
decl_stmt|;
name|UINT32
name|InterfaceSelector
range|:
literal|2
decl_stmt|;
name|UINT32
name|IntfSelLock
range|:
literal|1
decl_stmt|;
name|UINT32
name|Reserved2
range|:
literal|4
decl_stmt|;
name|UINT32
name|Rid
range|:
literal|8
decl_stmt|;
block|}
name|Bits
struct|;
name|UINT32
name|Uint32
decl_stmt|;
block|}
name|PTP_CRB_INTERFACE_IDENTIFIER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// InterfaceType
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_INTERFACE_IDENTIFIER_INTERFACE_TYPE_FIFO
value|0x0
end_define

begin_define
define|#
directive|define
name|PTP_INTERFACE_IDENTIFIER_INTERFACE_TYPE_CRB
value|0x1
end_define

begin_define
define|#
directive|define
name|PTP_INTERFACE_IDENTIFIER_INTERFACE_TYPE_TIS
value|0xF
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// InterfaceVersion
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_INTERFACE_IDENTIFIER_INTERFACE_VERSION_FIFO
value|0x0
end_define

begin_define
define|#
directive|define
name|PTP_INTERFACE_IDENTIFIER_INTERFACE_VERSION_CRB
value|0x1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// InterfaceSelector
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_INTERFACE_IDENTIFIER_INTERFACE_SELECTOR_FIFO
value|0x0
end_define

begin_define
define|#
directive|define
name|PTP_INTERFACE_IDENTIFIER_INTERFACE_SELECTOR_CRB
value|0x1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define bits of Locality State Register
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This bit indicates whether all other bits of this register contain valid values, if it is a 1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_STATE_TPM_REG_VALID_STATUS
value|BIT7
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// 000 - Locality 0
end_comment

begin_comment
comment|/// 001 - Locality 1
end_comment

begin_comment
comment|/// 010 - Locality 2
end_comment

begin_comment
comment|/// 011 - Locality 3
end_comment

begin_comment
comment|/// 100 - Locality 4
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_STATE_ACTIVE_LOCALITY_MASK
value|(BIT2 | BIT3 | BIT4)
end_define

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_STATE_ACTIVE_LOCALITY_0
value|(0)
end_define

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_STATE_ACTIVE_LOCALITY_1
value|(BIT2)
end_define

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_STATE_ACTIVE_LOCALITY_2
value|(BIT3)
end_define

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_STATE_ACTIVE_LOCALITY_3
value|(BIT2 | BIT3)
end_define

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_STATE_ACTIVE_LOCALITY_4
value|(BIT4)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A 0 indicates to the host that no locality is assigned.
end_comment

begin_comment
comment|/// A 1 indicates a locality has been assigned.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_STATE_LOCALITY_ASSIGNED
value|BIT1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The TPM clears this bit to 0 upon receipt of _TPM_Hash_End
end_comment

begin_comment
comment|/// The TPM sets this bit to a 1 when the TPM_LOC_CTRL_x.resetEstablishment field is set to 1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_STATE_TPM_ESTABLISHED
value|BIT0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define bits of Locality Control Register
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Writes (1): Reset TPM_LOC_STATE_x.tpmEstablished bit if the write occurs from Locality 3 or 4.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_CONTROL_RESET_ESTABLISHMENT_BIT
value|BIT3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Writes (1): The TPM gives control of the TPM to the locality setting this bit if it is the higher priority locality.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_CONTROL_SEIZE
value|BIT2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Writes (1): The active Locality is done with the TPM.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_CONTROL_RELINQUISH
value|BIT1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Writes (1): Interrupt the TPM and generate a locality arbitration algorithm.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_CONTROL_REQUEST_ACCESS
value|BIT0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define bits of Locality Status Register
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 0: A higher locality has not initiated a Seize arbitration process.
end_comment

begin_comment
comment|/// 1: A higher locality has Seized the TPM from this locality.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_STATUS_BEEN_SEIZED
value|BIT1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// 0: Locality has not been granted to the TPM.
end_comment

begin_comment
comment|/// 1: Locality has been granted access to the TPM
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_LOCALITY_STATUS_GRANTED
value|BIT0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define bits of CRB Control Area Request Register
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used by Software to indicate transition the TPM to and from the Idle state
end_comment

begin_comment
comment|/// 1: Set by Software to indicate response has been read from the response buffer and TPM can transition to Idle
end_comment

begin_comment
comment|/// 0: Cleared to 0 by TPM to acknowledge the request when TPM enters Idle state.
end_comment

begin_comment
comment|/// TPM SHALL complete this transition within TIMEOUT_C.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_CONTROL_AREA_REQUEST_GO_IDLE
value|BIT1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used by Software to request the TPM transition to the Ready State.
end_comment

begin_comment
comment|/// 1: Set to 1 by Software to indicate the TPM should be ready to receive a command.
end_comment

begin_comment
comment|/// 0: Cleared to 0 by TPM to acknowledge the request.
end_comment

begin_comment
comment|/// TPM SHALL complete this transition within TIMEOUT_C.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_CONTROL_AREA_REQUEST_COMMAND_READY
value|BIT0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define bits of CRB Control Area Status Register
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used by TPM to indicate it is in the Idle State
end_comment

begin_comment
comment|/// 1: Set by TPM when in the Idle State
end_comment

begin_comment
comment|/// 0: Cleared by TPM on receipt of TPM_CRB_CTRL_REQ_x.cmdReady when TPM transitions to the Ready State.
end_comment

begin_comment
comment|/// SHALL be cleared by TIMEOUT_C.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_CONTROL_AREA_STATUS_TPM_IDLE
value|BIT1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used by the TPM to indicate current status.
end_comment

begin_comment
comment|/// 1: Set by TPM to indicate a FATAL Error
end_comment

begin_comment
comment|/// 0: Indicates TPM is operational
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_CONTROL_AREA_STATUS_TPM_STATUS
value|BIT0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define bits of CRB Control Cancel Register
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used by software to cancel command processing Reads return correct value
end_comment

begin_comment
comment|/// Writes (0000 0001h): Cancel a command
end_comment

begin_comment
comment|/// Writes (0000 0000h): Clears field when command has been cancelled
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_CONTROL_CANCEL
value|BIT0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define bits of CRB Control Start Register
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When set by software, indicates a command is ready for processing.
end_comment

begin_comment
comment|/// Writes (0000 0001h): TPM transitions to Command Execution
end_comment

begin_comment
comment|/// Writes (0000 0000h): TPM clears this field and transitions to Command Completion
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PTP_CRB_CONTROL_START
value|BIT0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Restore original structure alignment
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Default TimeOut value
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PTP_TIMEOUT_A
value|(750 * 1000)
end_define

begin_comment
comment|// 750ms
end_comment

begin_define
define|#
directive|define
name|PTP_TIMEOUT_B
value|(2000 * 1000)
end_define

begin_comment
comment|// 2s
end_comment

begin_define
define|#
directive|define
name|PTP_TIMEOUT_C
value|(200 * 1000)
end_define

begin_comment
comment|// 200ms
end_comment

begin_define
define|#
directive|define
name|PTP_TIMEOUT_D
value|(30 * 1000)
end_define

begin_comment
comment|// 30ms
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

