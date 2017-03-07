begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Runtime Architectural Protocol as defined in PI Specification VOLUME 2 DXE    Allows the runtime functionality of the DXE Foundation to be contained    in a separate driver. It also provides hooks for the DXE Foundation to    export information that is needed at runtime. As such, this protocol allows    services to the DXE Foundation to manage runtime drivers and events.    This protocol also implies that the runtime services required to transition    to virtual mode, SetVirtualAddressMap() and ConvertPointer(), have been    registered into the UEFI Runtime Table in the UEFI System Table. This protocol    must be produced by a runtime DXE driver and may only be consumed by the DXE Foundation.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARCH_PROTOCOL_RUNTIME_H__
end_ifndef

begin_define
define|#
directive|define
name|__ARCH_PROTOCOL_RUNTIME_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the Runtime Architectural Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_RUNTIME_ARCH_PROTOCOL_GUID
define|\
value|{ 0xb7dfb4e1, 0x52f, 0x449f, {0x87, 0xbe, 0x98, 0x18, 0xfc, 0x91, 0xb7, 0x33 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_RUNTIME_ARCH_PROTOCOL
name|EFI_RUNTIME_ARCH_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// LIST_ENTRY from BaseType
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|LIST_ENTRY
name|EFI_LIST_ENTRY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_RUNTIME_IMAGE_ENTRY
name|EFI_RUNTIME_IMAGE_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_RUNTIME_IMAGE_ENTRY
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_RUNTIME_IMAGE_ENTRY
block|{
comment|///
comment|/// Start of image that has been loaded in memory. It is a pointer
comment|/// to either the DOS header or PE header of the image.
comment|///
name|VOID
modifier|*
name|ImageBase
decl_stmt|;
comment|///
comment|/// Size in bytes of the image represented by ImageBase.
comment|///
name|UINT64
name|ImageSize
decl_stmt|;
comment|///
comment|/// Information about the fix-ups that were performed on ImageBase when it was
comment|/// loaded into memory.
comment|///
name|VOID
modifier|*
name|RelocationData
decl_stmt|;
comment|///
comment|/// The ImageHandle passed into ImageBase when it was loaded.
comment|///
name|EFI_HANDLE
name|Handle
decl_stmt|;
comment|///
comment|/// Entry for this node in the EFI_RUNTIME_ARCHITECTURE_PROTOCOL.ImageHead list.
comment|///
name|EFI_LIST_ENTRY
name|Link
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_EFI_RUNTIME_EVENT_ENTRY
name|EFI_RUNTIME_EVENT_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_RUNTIME_EVENT_ENTRY
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_RUNTIME_EVENT_ENTRY
block|{
comment|///
comment|/// The same as Type passed into CreateEvent().
comment|///
name|UINT32
name|Type
decl_stmt|;
comment|///
comment|/// The same as NotifyTpl passed into CreateEvent().
comment|///
name|EFI_TPL
name|NotifyTpl
decl_stmt|;
comment|///
comment|/// The same as NotifyFunction passed into CreateEvent().
comment|///
name|EFI_EVENT_NOTIFY
name|NotifyFunction
decl_stmt|;
comment|///
comment|/// The same as NotifyContext passed into CreateEvent().
comment|///
name|VOID
modifier|*
name|NotifyContext
decl_stmt|;
comment|///
comment|/// The EFI_EVENT returned by CreateEvent(). Event must be in runtime memory.
comment|///
name|EFI_EVENT
modifier|*
name|Event
decl_stmt|;
comment|///
comment|/// Entry for this node in the
comment|/// EFI_RUNTIME_ARCHITECTURE_PROTOCOL.EventHead list.
comment|///
name|EFI_LIST_ENTRY
name|Link
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|///
end_comment

begin_comment
comment|/// Allows the runtime functionality of the DXE Foundation to be contained in a
end_comment

begin_comment
comment|/// separate driver. It also provides hooks for the DXE Foundation to export
end_comment

begin_comment
comment|/// information that is needed at runtime. As such, this protocol allows the DXE
end_comment

begin_comment
comment|/// Foundation to manage runtime drivers and events. This protocol also implies
end_comment

begin_comment
comment|/// that the runtime services required to transition to virtual mode,
end_comment

begin_comment
comment|/// SetVirtualAddressMap() and ConvertPointer(), have been registered into the
end_comment

begin_comment
comment|/// EFI Runtime Table in the EFI System Partition.  This protocol must be produced
end_comment

begin_comment
comment|/// by a runtime DXE driver and may only be consumed by the DXE Foundation.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_RUNTIME_ARCH_PROTOCOL
block|{
name|EFI_LIST_ENTRY
name|ImageHead
decl_stmt|;
comment|///< A list of type EFI_RUNTIME_IMAGE_ENTRY.
name|EFI_LIST_ENTRY
name|EventHead
decl_stmt|;
comment|///< A list of type EFI_RUNTIME_EVENT_ENTRY.
name|UINTN
name|MemoryDescriptorSize
decl_stmt|;
comment|///< Size of a memory descriptor that is returned by GetMemoryMap().
name|UINT32
name|MemoryDesciptorVersion
decl_stmt|;
comment|///< Version of a memory descriptor that is returned by GetMemoryMap().
name|UINTN
name|MemoryMapSize
decl_stmt|;
comment|///< Size of the memory map in bytes contained in MemoryMapPhysical and MemoryMapVirtual.
name|EFI_MEMORY_DESCRIPTOR
modifier|*
name|MemoryMapPhysical
decl_stmt|;
comment|///< Pointer to a runtime buffer that contains a copy of
comment|///< the memory map returned via GetMemoryMap().
name|EFI_MEMORY_DESCRIPTOR
modifier|*
name|MemoryMapVirtual
decl_stmt|;
comment|///< Pointer to MemoryMapPhysical that is updated to virtual mode after SetVirtualAddressMap().
name|BOOLEAN
name|VirtualMode
decl_stmt|;
comment|///< Boolean that is TRUE if SetVirtualAddressMap() has been called.
name|BOOLEAN
name|AtRuntime
decl_stmt|;
comment|///< Boolean that is TRUE if ExitBootServices () has been called.
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiRuntimeArchProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

