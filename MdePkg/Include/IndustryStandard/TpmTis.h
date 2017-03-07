begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   TPM Interface Specification definition.   It covers both TPM1.2 and TPM2.0.  Copyright (c) 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TPM_TIS_H_
end_ifndef

begin_define
define|#
directive|define
name|_TPM_TIS_H_
end_define

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
comment|// Register set map as specified in TIS specification Chapter 10
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
name|IntfCapability
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
name|UINT8
name|Reserved3
index|[
literal|9
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
literal|0xed8
index|]
decl_stmt|;
comment|// 28h
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
literal|0x7b
index|]
decl_stmt|;
comment|// 0f05h
comment|///
comment|/// Alias to I/O legacy space.
comment|///
name|UINT32
name|LegacyAddress1
decl_stmt|;
comment|// 0f80h
comment|///
comment|/// Additional 8 bits for I/O legacy space extension.
comment|///
name|UINT32
name|LegacyAddress1Ex
decl_stmt|;
comment|// 0f84h
comment|///
comment|/// Alias to second I/O legacy space.
comment|///
name|UINT32
name|LegacyAddress2
decl_stmt|;
comment|// 0f88h
comment|///
comment|/// Additional 8 bits for second I/O legacy space extension.
comment|///
name|UINT32
name|LegacyAddress2Ex
decl_stmt|;
comment|// 0f8ch
comment|///
comment|/// Vendor-defined configuration registers.
comment|///
name|UINT8
name|VendorDefined
index|[
literal|0x70
index|]
decl_stmt|;
comment|// 0f90h
block|}
name|TIS_PC_REGISTERS
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
name|TIS_PC_REGISTERS
modifier|*
name|TIS_PC_REGISTERS_PTR
typedef|;
end_typedef

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
name|TIS_PC_VALID
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
name|TIS_PC_ACC_ACTIVE
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
name|TIS_PC_ACC_SEIZED
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
name|TIS_PC_ACC_SEIZE
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
name|TIS_PC_ACC_PENDIND
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
name|TIS_PC_ACC_RQUUSE
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
name|TIS_PC_ACC_ESTABLISH
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
name|TIS_PC_STS_VALID
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
name|TIS_PC_STS_READY
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
name|TIS_PC_STS_GO
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
name|TIS_PC_STS_DATA
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
name|TIS_PC_STS_EXPECT
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
name|TIS_PC_STS_SELFTEST_DONE
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
name|TIS_PC_STS_RETRY
value|BIT1
end_define

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
name|TIS_TIMEOUT_A
value|(750  * 1000)
end_define

begin_comment
comment|// 750ms
end_comment

begin_define
define|#
directive|define
name|TIS_TIMEOUT_B
value|(2000 * 1000)
end_define

begin_comment
comment|// 2s
end_comment

begin_define
define|#
directive|define
name|TIS_TIMEOUT_C
value|(750  * 1000)
end_define

begin_comment
comment|// 750ms
end_comment

begin_define
define|#
directive|define
name|TIS_TIMEOUT_D
value|(750  * 1000)
end_define

begin_comment
comment|// 750ms
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

