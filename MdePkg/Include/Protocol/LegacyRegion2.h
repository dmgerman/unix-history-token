begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The Legacy Region Protocol controls the read, write and boot-lock attributes for   the region 0xC0000 to 0xFFFFF.    Copyright (c) 2009 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is defined in UEFI Platform Initialization Specification 1.2    Volume 5: Standards  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LEGACY_REGION2_H__
end_ifndef

begin_define
define|#
directive|define
name|__LEGACY_REGION2_H__
end_define

begin_define
define|#
directive|define
name|EFI_LEGACY_REGION2_PROTOCOL_GUID
define|\
value|{ \   0x70101eaf, 0x85, 0x440c, {0xb3, 0x56, 0x8e, 0xe3, 0x6f, 0xef, 0x24, 0xf0 } \ }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_LEGACY_REGION2_PROTOCOL
name|EFI_LEGACY_REGION2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Modify the hardware to allow (decode) or disallow (not decode) memory reads in a region.    If the On parameter evaluates to TRUE, this function enables memory reads in the address range    Start to (Start + Length - 1).   If the On parameter evaluates to FALSE, this function disables memory reads in the address range    Start to (Start + Length - 1).    @param  This[in]              Indicates the EFI_LEGACY_REGION2_PROTOCOL instance.   @param  Start[in]             The beginning of the physical address of the region whose attributes                                 should be modified.   @param  Length[in]            The number of bytes of memory whose attributes should be modified.                                 The actual number of bytes modified may be greater than the number                                 specified.   @param  Granularity[out]      The number of bytes in the last region affected. This may be less                                 than the total number of bytes affected if the starting address                                 was not aligned to a region's starting address or if the length                                 was greater than the number of bytes in the first region.   @param  On[in]                Decode / Non-Decode flag.    @retval EFI_SUCCESS           The region's attributes were successfully modified.   @retval EFI_INVALID_PARAMETER If Start or Length describe an address not in the Legacy Region.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_LEGACY_REGION2_DECODE
function_decl|)
parameter_list|(
name|IN
name|EFI_LEGACY_REGION2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|Start
parameter_list|,
name|IN
name|UINT32
name|Length
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Granularity
parameter_list|,
name|IN
name|BOOLEAN
modifier|*
name|On
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Modify the hardware to disallow memory writes in a region.    This function changes the attributes of a memory range to not allow writes.    @param  This[in]              Indicates the EFI_LEGACY_REGION2_PROTOCOL instance.   @param  Start[in]             The beginning of the physical address of the region whose                                 attributes should be modified.   @param  Length[in]            The number of bytes of memory whose attributes should be modified.                                 The actual number of bytes modified may be greater than the number                                 specified.   @param  Granularity[out]      The number of bytes in the last region affected. This may be less                                 than the total number of bytes affected if the starting address was                                 not aligned to a region's starting address or if the length was                                 greater than the number of bytes in the first region.    @retval EFI_SUCCESS           The region's attributes were successfully modified.   @retval EFI_INVALID_PARAMETER If Start or Length describe an address not in the Legacy Region.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_LEGACY_REGION2_LOCK
function_decl|)
parameter_list|(
name|IN
name|EFI_LEGACY_REGION2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|Start
parameter_list|,
name|IN
name|UINT32
name|Length
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Granularity
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Modify the hardware to disallow memory attribute changes in a region.    This function makes the attributes of a region read only. Once a region is boot-locked with this    function, the read and write attributes of that region cannot be changed until a power cycle has   reset the boot-lock attribute. Calls to Decode(), Lock() and Unlock() will have no effect.    @param  This[in]              Indicates the EFI_LEGACY_REGION2_PROTOCOL instance.   @param  Start[in]             The beginning of the physical address of the region whose                                 attributes should be modified.   @param  Length[in]            The number of bytes of memory whose attributes should be modified.                                 The actual number of bytes modified may be greater than the number                                 specified.   @param  Granularity[out]      The number of bytes in the last region affected. This may be less                                 than the total number of bytes affected if the starting address was                                 not aligned to a region's starting address or if the length was                                 greater than the number of bytes in the first region.    @retval EFI_SUCCESS           The region's attributes were successfully modified.   @retval EFI_INVALID_PARAMETER If Start or Length describe an address not in the Legacy Region.   @retval EFI_UNSUPPORTED       The chipset does not support locking the configuration registers in                                 a way that will not affect memory regions outside the legacy memory                                 region.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_LEGACY_REGION2_BOOT_LOCK
function_decl|)
parameter_list|(
name|IN
name|EFI_LEGACY_REGION2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|Start
parameter_list|,
name|IN
name|UINT32
name|Length
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Granularity
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Modify the hardware to allow memory writes in a region.    This function changes the attributes of a memory range to allow writes.      @param  This[in]              Indicates the EFI_LEGACY_REGION2_PROTOCOL instance.   @param  Start[in]             The beginning of the physical address of the region whose                                 attributes should be modified.   @param  Length[in]            The number of bytes of memory whose attributes should be modified.                                 The actual number of bytes modified may be greater than the number                                 specified.   @param  Granularity[out]      The number of bytes in the last region affected. This may be less                                 than the total number of bytes affected if the starting address was                                 not aligned to a region's starting address or if the length was                                 greater than the number of bytes in the first region.    @retval EFI_SUCCESS           The region's attributes were successfully modified.   @retval EFI_INVALID_PARAMETER If Start or Length describe an address not in the Legacy Region.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_LEGACY_REGION2_UNLOCK
function_decl|)
parameter_list|(
name|IN
name|EFI_LEGACY_REGION2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|Start
parameter_list|,
name|IN
name|UINT32
name|Length
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Granularity
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|LegacyRegionDecoded
block|,
comment|///< This region is currently set to allow reads.
name|LegacyRegionNotDecoded
block|,
comment|///< This region is currently set to not allow reads.
name|LegacyRegionWriteEnabled
block|,
comment|///< This region is currently set to allow writes.
name|LegacyRegionWriteDisabled
block|,
comment|///< This region is currently set to write protected.
name|LegacyRegionBootLocked
block|,
comment|///< This region's attributes are locked, cannot be modified until
comment|///< after a power cycle.
name|LegacyRegionNotLocked
comment|///< This region's attributes are not locked.
block|}
name|EFI_LEGACY_REGION_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The beginning of the physical address of this
comment|/// region.
comment|///
name|UINT32
name|Start
decl_stmt|;
comment|///
comment|/// The number of bytes in this region.
comment|///
name|UINT32
name|Length
decl_stmt|;
comment|///
comment|/// Attribute of the Legacy Region Descriptor that
comment|/// describes the capabilities for that memory region.
comment|///
name|EFI_LEGACY_REGION_ATTRIBUTE
name|Attribute
decl_stmt|;
comment|///
comment|/// Describes the byte length programmability
comment|/// associated with the Start address and the specified
comment|/// Attribute setting.
name|UINT32
name|Granularity
decl_stmt|;
block|}
name|EFI_LEGACY_REGION_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|/**   Get region information for the attributes of the Legacy Region.    This function is used to discover the granularity of the attributes for the memory in the legacy    region. Each attribute may have a different granularity and the granularity may not be the same   for all memory ranges in the legacy region.      @param  This[in]              Indicates the EFI_LEGACY_REGION2_PROTOCOL instance.   @param  DescriptorCount[out]  The number of region descriptor entries returned in the Descriptor                                 buffer.   @param  Descriptor[out]       A pointer to a pointer used to return a buffer where the legacy                                 region information is deposited. This buffer will contain a list of                                 DescriptorCount number of region descriptors.  This function will                                 provide the memory for the buffer.    @retval EFI_SUCCESS           The information structure was returned.   @retval EFI_UNSUPPORTED       This function is not supported.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_LEGACY_REGION_GET_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_LEGACY_REGION2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|DescriptorCount
parameter_list|,
name|OUT
name|EFI_LEGACY_REGION_DESCRIPTOR
modifier|*
modifier|*
name|Descriptor
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_LEGACY_REGION2_PROTOCOL is used to abstract the hardware control of the memory
end_comment

begin_comment
comment|/// attributes of the Option ROM shadowing region, 0xC0000 to 0xFFFFF.
end_comment

begin_comment
comment|/// There are three memory attributes that can be modified through this protocol: read, write and
end_comment

begin_comment
comment|/// boot-lock. These protocols may be set in any combination.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_LEGACY_REGION2_PROTOCOL
block|{
name|EFI_LEGACY_REGION2_DECODE
name|Decode
decl_stmt|;
name|EFI_LEGACY_REGION2_LOCK
name|Lock
decl_stmt|;
name|EFI_LEGACY_REGION2_BOOT_LOCK
name|BootLock
decl_stmt|;
name|EFI_LEGACY_REGION2_UNLOCK
name|UnLock
decl_stmt|;
name|EFI_LEGACY_REGION_GET_INFO
name|GetInfo
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiLegacyRegion2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

