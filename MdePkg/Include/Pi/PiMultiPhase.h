begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Include file matches things in PI for multiple module types.  Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                                                      THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   These elements are defined in UEFI Platform Initialization Specification 1.2.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PI_MULTIPHASE_H__
end_ifndef

begin_define
define|#
directive|define
name|__PI_MULTIPHASE_H__
end_define

begin_include
include|#
directive|include
file|<Pi/PiFirmwareVolume.h>
end_include

begin_include
include|#
directive|include
file|<Pi/PiFirmwareFile.h>
end_include

begin_include
include|#
directive|include
file|<Pi/PiBootMode.h>
end_include

begin_include
include|#
directive|include
file|<Pi/PiHob.h>
end_include

begin_include
include|#
directive|include
file|<Pi/PiDependency.h>
end_include

begin_include
include|#
directive|include
file|<Pi/PiStatusCode.h>
end_include

begin_include
include|#
directive|include
file|<Pi/PiS3BootScript.h>
end_include

begin_comment
comment|/**   Produces an error code in the range reserved for use by the Platform Initialization   Architecture Specification.    The supported 32-bit range is 0xA0000000-0xBFFFFFFF    The supported 64-bit range is 0xA000000000000000-0xBFFFFFFFFFFFFFFF     @param  StatusCode    The status code value to convert into a warning code.                           StatusCode must be in the range 0x00000000..0x1FFFFFFF.    @return The value specified by StatusCode in the PI reserved range.  **/
end_comment

begin_define
define|#
directive|define
name|DXE_ERROR
parameter_list|(
name|StatusCode
parameter_list|)
value|(MAX_BIT | (MAX_BIT>> 2) | StatusCode)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this value is returned by an EFI image, then the image should be unloaded.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_REQUEST_UNLOAD_IMAGE
value|DXE_ERROR (1)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this value is returned by an API, it means the capability is not yet
end_comment

begin_comment
comment|/// installed/available/ready to use.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_NOT_AVAILABLE_YET
value|DXE_ERROR (2)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Success and warning codes reserved for use by PI.
end_comment

begin_comment
comment|/// Supported 32-bit range is 0x20000000-0x3fffffff.
end_comment

begin_comment
comment|/// Supported 64-bit range is 0x2000000000000000-0x3fffffffffffffff.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PI_ENCODE_WARNING
parameter_list|(
name|a
parameter_list|)
value|((MAX_BIT>> 2) | (a))
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Error codes reserved for use by PI.
end_comment

begin_comment
comment|/// Supported 32-bit range is 0xa0000000-0xbfffffff.
end_comment

begin_comment
comment|/// Supported 64-bit range is 0xa000000000000000-0xbfffffffffffffff.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PI_ENCODE_ERROR
parameter_list|(
name|a
parameter_list|)
value|(MAX_BIT | (MAX_BIT>> 2) | (a))
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Return status codes defined in SMM CIS.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_INTERRUPT_PENDING
value|PI_ENCODE_ERROR (0)
end_define

begin_define
define|#
directive|define
name|EFI_WARN_INTERRUPT_SOURCE_PENDING
value|PI_ENCODE_WARNING (0)
end_define

begin_define
define|#
directive|define
name|EFI_WARN_INTERRUPT_SOURCE_QUIESCED
value|PI_ENCODE_WARNING (1)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Bitmask of values for Authentication Status.
end_comment

begin_comment
comment|/// Authentication Status is returned from EFI_GUIDED_SECTION_EXTRACTION_PROTOCOL
end_comment

begin_comment
comment|/// and the EFI_PEI_GUIDED_SECTION_EXTRACTION_PPI
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// xx00 Image was not signed.
end_comment

begin_comment
comment|/// xxx1 Platform security policy override. Assumes the same meaning as 0010 (the image was signed, the
end_comment

begin_comment
comment|///      signature was tested, and the signature passed authentication test).
end_comment

begin_comment
comment|/// 0010 Image was signed, the signature was tested, and the signature passed authentication test.
end_comment

begin_comment
comment|/// 0110 Image was signed and the signature was not tested.
end_comment

begin_comment
comment|/// 1010 Image was signed, the signature was tested, and the signature failed the authentication test.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_AUTH_STATUS_PLATFORM_OVERRIDE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_AUTH_STATUS_IMAGE_SIGNED
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_AUTH_STATUS_NOT_TESTED
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_AUTH_STATUS_TEST_FAILED
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_AUTH_STATUS_ALL
value|0x0f
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// SMRAM states and capabilities
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SMRAM_OPEN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_SMRAM_CLOSED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_SMRAM_LOCKED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_CACHEABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EFI_ALLOCATED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_NEEDS_TESTING
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EFI_NEEDS_ECC_INITIALIZATION
value|0x00000040
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Structure describing a SMRAM region and its accessibility attributes.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Designates the physical address of the SMRAM in memory. This view of memory is
comment|/// the same as seen by I/O-based agents, for example, but it may not be the address seen
comment|/// by the processors.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|PhysicalStart
decl_stmt|;
comment|///
comment|/// Designates the address of the SMRAM, as seen by software executing on the
comment|/// processors. This address may or may not match PhysicalStart.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|CpuStart
decl_stmt|;
comment|///
comment|/// Describes the number of bytes in the SMRAM region.
comment|///
name|UINT64
name|PhysicalSize
decl_stmt|;
comment|///
comment|/// Describes the accessibility attributes of the SMRAM.  These attributes include the
comment|/// hardware state (e.g., Open/Closed/Locked), capability (e.g., cacheable), logical
comment|/// allocation (e.g., allocated), and pre-use initialization (e.g., needs testing/ECC
comment|/// initialization).
comment|///
name|UINT64
name|RegionState
decl_stmt|;
block|}
name|EFI_SMRAM_DESCRIPTOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EFI_PCD_TYPE_8
block|,
name|EFI_PCD_TYPE_16
block|,
name|EFI_PCD_TYPE_32
block|,
name|EFI_PCD_TYPE_64
block|,
name|EFI_PCD_TYPE_BOOL
block|,
name|EFI_PCD_TYPE_PTR
block|}
name|EFI_PCD_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The returned information associated with the requested TokenNumber. If
comment|/// TokenNumber is 0, then PcdType is set to EFI_PCD_TYPE_8.
comment|///
name|EFI_PCD_TYPE
name|PcdType
decl_stmt|;
comment|///
comment|/// The size of the data in bytes associated with the TokenNumber specified. If
comment|/// TokenNumber is 0, then PcdSize is set 0.
comment|///
name|UINTN
name|PcdSize
decl_stmt|;
comment|///
comment|/// The null-terminated ASCII string associated with a given token. If the
comment|/// TokenNumber specified was 0, then this field corresponds to the null-terminated
comment|/// ASCII string associated with the token's namespace Guid. If NULL, there is no
comment|/// name associated with this request.
comment|///
name|CHAR8
modifier|*
name|PcdName
decl_stmt|;
block|}
name|EFI_PCD_INFO
typedef|;
end_typedef

begin_comment
comment|/**   The function prototype for invoking a function on an Application Processor.    This definition is used by the UEFI MP Serices Protocol, and the   PI SMM System Table.    @param[in,out] Buffer  The pointer to private data buffer. **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_AP_PROCEDURE
function_decl|)
parameter_list|(
name|IN
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

