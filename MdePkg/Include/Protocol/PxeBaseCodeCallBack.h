begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   It is invoked when the PXE Base Code Protocol is about to transmit, has received,    or is waiting to receive a packet.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:             This Protocol is introduced in EFI Specification 1.10  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PXE_BASE_CODE_CALLBACK_H_
end_ifndef

begin_define
define|#
directive|define
name|_PXE_BASE_CODE_CALLBACK_H_
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Call Back Definitions.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL_GUID
define|\
value|{ \     0x245dca21, 0xfb7b, 0x11d3, {0x8f, 0x01, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UEFI Revision Number Definition.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL_REVISION
value|0x00010000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI 1.1 Revision Number defintion.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_CALLBACK_INTERFACE_REVISION
define|\
value|EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL_REVISION
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UEFI Protocol name.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL
name|EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI1.1 Protocol name.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL
name|EFI_PXE_BASE_CODE_CALLBACK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Event type list for PXE Base Code Protocol function.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EFI_PXE_BASE_CODE_FUNCTION_FIRST
block|,
name|EFI_PXE_BASE_CODE_FUNCTION_DHCP
block|,
name|EFI_PXE_BASE_CODE_FUNCTION_DISCOVER
block|,
name|EFI_PXE_BASE_CODE_FUNCTION_MTFTP
block|,
name|EFI_PXE_BASE_CODE_FUNCTION_UDP_WRITE
block|,
name|EFI_PXE_BASE_CODE_FUNCTION_UDP_READ
block|,
name|EFI_PXE_BASE_CODE_FUNCTION_ARP
block|,
name|EFI_PXE_BASE_CODE_FUNCTION_IGMP
block|,
name|EFI_PXE_BASE_CODE_PXE_FUNCTION_LAST
block|}
name|EFI_PXE_BASE_CODE_FUNCTION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Callback status type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EFI_PXE_BASE_CODE_CALLBACK_STATUS_FIRST
block|,
name|EFI_PXE_BASE_CODE_CALLBACK_STATUS_CONTINUE
block|,
name|EFI_PXE_BASE_CODE_CALLBACK_STATUS_ABORT
block|,
name|EFI_PXE_BASE_CODE_CALLBACK_STATUS_LAST
block|}
name|EFI_PXE_BASE_CODE_CALLBACK_STATUS
typedef|;
end_typedef

begin_comment
comment|/**                                                                    Callback function that is invoked when the PXE Base Code Protocol is about to transmit, has   received, or is waiting to receive a packet.                                                       This function is invoked when the PXE Base Code Protocol is about to transmit, has received,   or is waiting to receive a packet. Parameters Function and Received specify the type of event.   Parameters PacketLen and Packet specify the packet that generated the event. If these fields   are zero and NULL respectively, then this is a status update callback. If the operation specified   by Function is to continue, then CALLBACK_STATUS_CONTINUE should be returned. If the operation   specified by Function should be aborted, then CALLBACK_STATUS_ABORT should be returned. Due to   the polling nature of UEFI device drivers, a callback function should not execute for more than 5 ms.   The SetParameters() function must be called after a Callback Protocol is installed to enable the   use of callbacks.      @param  This                  The pointer to the EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL instance.   @param  Function              The PXE Base Code Protocol function that is waiting for an event.                                                                 @param  Received              TRUE if the callback is being invoked due to a receive event. FALSE if                                 the callback is being invoked due to a transmit event.                   @param  PacketLen             The length, in bytes, of Packet. This field will have a value of zero if                                 this is a wait for receive event.                                          @param  Packet                If Received is TRUE, a pointer to the packet that was just received;                                 otherwise a pointer to the packet that is about to be transmitted.                                        @retval EFI_PXE_BASE_CODE_CALLBACK_STATUS_CONTINUE if Function specifies a continue operation       @retval EFI_PXE_BASE_CODE_CALLBACK_STATUS_ABORT    if Function specifies an abort operation                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_PXE_BASE_CODE_CALLBACK_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PXE_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PXE_BASE_CODE_FUNCTION
name|Function
parameter_list|,
name|IN
name|BOOLEAN
name|Received
parameter_list|,
name|IN
name|UINT32
name|PacketLen
parameter_list|,
name|IN
name|EFI_PXE_BASE_CODE_PACKET
modifier|*
name|Packet
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol that is invoked when the PXE Base Code Protocol is about
end_comment

begin_comment
comment|/// to transmit, has received, or is waiting to receive a packet.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL
block|{
comment|///
comment|///  The revision of the EFI_PXE_BASE_CODE_PROTOCOL. All future revisions must
comment|///  be backwards compatible. If a future version is not backwards compatible
comment|///  it is not the same GUID.
comment|///
name|UINT64
name|Revision
decl_stmt|;
name|EFI_PXE_CALLBACK
name|Callback
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPxeBaseCodeCallbackProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

