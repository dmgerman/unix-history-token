begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI Timestamp Protocol as defined in UEFI2.4 Specification.    Used to provide a platform independent interface for retrieving a high resolution timestamp counter.      Copyright (c) 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution. The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.          @par Revision Reference:             This Protocol is introduced in UEFI Specification 2.4             **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_TIME_STAMP_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_TIME_STAMP_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_TIMESTAMP_PROTOCOL_GUID
define|\
value|{ 0xafbfde41, 0x2e6e, 0x4262, {0xba, 0x65, 0x62, 0xb9, 0x23, 0x6e, 0x54, 0x95 } }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Declare forward reference for the Time Stamp Protocol
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_TIMESTAMP_PROTOCOL
name|EFI_TIMESTAMP_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TIMESTAMP_PROPERTIES
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The frequency of the timestamp counter in Hz.
comment|///
name|UINT64
name|Frequency
decl_stmt|;
comment|///
comment|/// The value that the timestamp counter ends with immediately before it rolls over.
comment|/// For example, a 64-bit free running counter would have an EndValue of 0xFFFFFFFFFFFFFFFF.
comment|/// A 24-bit free running counter would have an EndValue of 0xFFFFFF.
comment|///
name|UINT64
name|EndValue
decl_stmt|;
block|}
name|EFI_TIMESTAMP_PROPERTIES
typedef|;
end_typedef

begin_comment
comment|/**   Retrieves the current value of a 64-bit free running timestamp counter.      The counter shall count up in proportion to the amount of time that has passed. The counter value   will always roll over to zero. The properties of the counter can be retrieved from GetProperties().   The caller should be prepared for the function to return the same value twice across successive calls.   The counter value will not go backwards other than when wrapping, as defined by EndValue in GetProperties().   The frequency of the returned timestamp counter value must remain constant. Power management operations that    affect clocking must not change the returned counter frequency. The quantization of counter value updates may    vary as long as the value reflecting time passed remains consistent.    @param  None.                 @retval The current value of the free running timestamp counter.  **/
end_comment

begin_typedef
typedef|typedef
name|UINT64
function_decl|(
name|EFIAPI
modifier|*
name|TIMESTAMP_GET
function_decl|)
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Obtains timestamp counter properties including frequency and value limits.    @param[out]  Properties              The properties of the timestamp counter.    @retval      EFI_SUCCESS             The properties were successfully retrieved.    @retval      EFI_DEVICE_ERROR        An error occurred trying to retrieve the properties of the timestamp                                         counter subsystem. Properties is not pedated.                                   @retval      EFI_INVALID_PARAMETER   Properties is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|TIMESTAMP_GET_PROPERTIES
function_decl|)
parameter_list|(
name|OUT
name|EFI_TIMESTAMP_PROPERTIES
modifier|*
name|Properties
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TIMESTAMP_PROTOCOL
end_comment

begin_comment
comment|/// The protocol provides a platform independent interface for retrieving a high resolution
end_comment

begin_comment
comment|/// timestamp counter.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_TIMESTAMP_PROTOCOL
block|{
name|TIMESTAMP_GET
name|GetTimestamp
decl_stmt|;
name|TIMESTAMP_GET_PROPERTIES
name|GetProperties
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiTimestampProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

