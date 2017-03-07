begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   CPU Architectural Protocol as defined in PI spec Volume 2 DXE    This code abstracts the DXE core from processor implementation details.    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARCH_PROTOCOL_CPU_H__
end_ifndef

begin_define
define|#
directive|define
name|__ARCH_PROTOCOL_CPU_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/DebugSupport.h>
end_include

begin_define
define|#
directive|define
name|EFI_CPU_ARCH_PROTOCOL_GUID
define|\
value|{ 0x26baccb1, 0x6f42, 0x11d4, {0xbc, 0xe7, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_CPU_ARCH_PROTOCOL
name|EFI_CPU_ARCH_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The type of flush operation
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiCpuFlushTypeWriteBackInvalidate
block|,
name|EfiCpuFlushTypeWriteBack
block|,
name|EfiCpuFlushTypeInvalidate
block|,
name|EfiCpuMaxFlushType
block|}
name|EFI_CPU_FLUSH_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The type of processor INIT.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiCpuInit
block|,
name|EfiCpuMaxInitType
block|}
name|EFI_CPU_INIT_TYPE
typedef|;
end_typedef

begin_comment
comment|/**   EFI_CPU_INTERRUPT_HANDLER that is called when a processor interrupt occurs.    @param  InterruptType    Defines the type of interrupt or exception that                            occurred on the processor.This parameter is processor architecture specific.   @param  SystemContext    A pointer to the processor context when                            the interrupt occurred on the processor.    @return None  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CPU_INTERRUPT_HANDLER
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_EXCEPTION_TYPE
name|InterruptType
parameter_list|,
name|IN
name|CONST
name|EFI_SYSTEM_CONTEXT
name|SystemContext
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function flushes the range of addresses from Start to Start+Length    from the processor's data cache. If Start is not aligned to a cache line    boundary, then the bytes before Start to the preceding cache line boundary    are also flushed. If Start+Length is not aligned to a cache line boundary,    then the bytes past Start+Length to the end of the next cache line boundary    are also flushed. The FlushType of EfiCpuFlushTypeWriteBackInvalidate must be    supported. If the data cache is fully coherent with all DMA operations, then    this function can just return EFI_SUCCESS. If the processor does not support    flushing a range of the data cache, then the entire data cache can be flushed.    @param  This             The EFI_CPU_ARCH_PROTOCOL instance.   @param  Start            The beginning physical address to flush from the processor's data                            cache.   @param  Length           The number of bytes to flush from the processor's data cache. This                            function may flush more bytes than Length specifies depending upon                            the granularity of the flush operation that the processor supports.   @param  FlushType        Specifies the type of flush operation to perform.    @retval EFI_SUCCESS           The address range from Start to Start+Length was flushed from                                 the processor's data cache.   @retval EFI_UNSUPPORTED       The processor does not support the cache flush type specified                                 by FlushType.   @retval EFI_DEVICE_ERROR      The address range from Start to Start+Length could not be flushed                                 from the processor's data cache.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CPU_FLUSH_DATA_CACHE
function_decl|)
parameter_list|(
name|IN
name|EFI_CPU_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|Start
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|,
name|IN
name|EFI_CPU_FLUSH_TYPE
name|FlushType
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function enables interrupt processing by the processor.     @param  This             The EFI_CPU_ARCH_PROTOCOL instance.    @retval EFI_SUCCESS           Interrupts are enabled on the processor.   @retval EFI_DEVICE_ERROR      Interrupts could not be enabled on the processor.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CPU_ENABLE_INTERRUPT
function_decl|)
parameter_list|(
name|IN
name|EFI_CPU_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function disables interrupt processing by the processor.    @param  This             The EFI_CPU_ARCH_PROTOCOL instance.    @retval EFI_SUCCESS           Interrupts are disabled on the processor.   @retval EFI_DEVICE_ERROR      Interrupts could not be disabled on the processor.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CPU_DISABLE_INTERRUPT
function_decl|)
parameter_list|(
name|IN
name|EFI_CPU_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function retrieves the processor's current interrupt state a returns it in    State. If interrupts are currently enabled, then TRUE is returned. If interrupts    are currently disabled, then FALSE is returned.    @param  This             The EFI_CPU_ARCH_PROTOCOL instance.   @param  State            A pointer to the processor's current interrupt state. Set to TRUE if                            interrupts are enabled and FALSE if interrupts are disabled.    @retval EFI_SUCCESS           The processor's current interrupt state was returned in State.   @retval EFI_INVALID_PARAMETER State is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CPU_GET_INTERRUPT_STATE
function_decl|)
parameter_list|(
name|IN
name|EFI_CPU_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|State
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function generates an INIT on the processor. If this function succeeds, then the   processor will be reset, and control will not be returned to the caller. If InitType is    not supported by this processor, or the processor cannot programmatically generate an    INIT without help from external hardware, then EFI_UNSUPPORTED is returned. If an error    occurs attempting to generate an INIT, then EFI_DEVICE_ERROR is returned.    @param  This             The EFI_CPU_ARCH_PROTOCOL instance.   @param  InitType         The type of processor INIT to perform.    @retval EFI_SUCCESS           The processor INIT was performed. This return code should never be seen.   @retval EFI_UNSUPPORTED       The processor INIT operation specified by InitType is not supported                                 by this processor.   @retval EFI_DEVICE_ERROR      The processor INIT failed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CPU_INIT
function_decl|)
parameter_list|(
name|IN
name|EFI_CPU_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_CPU_INIT_TYPE
name|InitType
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function registers and enables the handler specified by InterruptHandler for a processor    interrupt or exception type specified by InterruptType. If InterruptHandler is NULL, then the    handler for the processor interrupt or exception type specified by InterruptType is uninstalled.    The installed handler is called once for each processor interrupt or exception.    @param  This             The EFI_CPU_ARCH_PROTOCOL instance.   @param  InterruptType    A pointer to the processor's current interrupt state. Set to TRUE if interrupts                            are enabled and FALSE if interrupts are disabled.   @param  InterruptHandler A pointer to a function of type EFI_CPU_INTERRUPT_HANDLER that is called                            when a processor interrupt occurs. If this parameter is NULL, then the handler                            will be uninstalled.    @retval EFI_SUCCESS           The handler for the processor interrupt was successfully installed or uninstalled.   @retval EFI_ALREADY_STARTED   InterruptHandler is not NULL, and a handler for InterruptType was                                 previously installed.   @retval EFI_INVALID_PARAMETER InterruptHandler is NULL, and a handler for InterruptType was not                                 previously installed.   @retval EFI_UNSUPPORTED       The interrupt specified by InterruptType is not supported.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CPU_REGISTER_INTERRUPT_HANDLER
function_decl|)
parameter_list|(
name|IN
name|EFI_CPU_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_EXCEPTION_TYPE
name|InterruptType
parameter_list|,
name|IN
name|EFI_CPU_INTERRUPT_HANDLER
name|InterruptHandler
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function reads the processor timer specified by TimerIndex and returns it in TimerValue.    @param  This             The EFI_CPU_ARCH_PROTOCOL instance.   @param  TimerIndex       Specifies which processor timer is to be returned in TimerValue. This parameter                            must be between 0 and NumberOfTimers-1.   @param  TimerValue       Pointer to the returned timer value.   @param  TimerPeriod      A pointer to the amount of time that passes in femtoseconds for each increment                            of TimerValue. If TimerValue does not increment at a predictable rate, then 0 is                            returned. This parameter is optional and may be NULL.    @retval EFI_SUCCESS           The processor timer value specified by TimerIndex was returned in TimerValue.   @retval EFI_DEVICE_ERROR      An error occurred attempting to read one of the processor's timers.   @retval EFI_INVALID_PARAMETER TimerValue is NULL or TimerIndex is not valid.   @retval EFI_UNSUPPORTED       The processor does not have any readable timers.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CPU_GET_TIMER_VALUE
function_decl|)
parameter_list|(
name|IN
name|EFI_CPU_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|TimerIndex
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|TimerValue
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|TimerPeriod
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function modifies the attributes for the memory region specified by BaseAddress and   Length from their current attributes to the attributes specified by Attributes.    @param  This             The EFI_CPU_ARCH_PROTOCOL instance.   @param  BaseAddress      The physical address that is the start address of a memory region.   @param  Length           The size in bytes of the memory region.   @param  Attributes       The bit mask of attributes to set for the memory region.    @retval EFI_SUCCESS           The attributes were set for the memory region.   @retval EFI_ACCESS_DENIED     The attributes for the memory resource range specified by                                 BaseAddress and Length cannot be modified.   @retval EFI_INVALID_PARAMETER Length is zero.                                 Attributes specified an illegal combination of attributes that                                 cannot be set together.   @retval EFI_OUT_OF_RESOURCES  There are not enough system resources to modify the attributes of                                 the memory resource range.   @retval EFI_UNSUPPORTED       The processor does not support one or more bytes of the memory                                 resource range specified by BaseAddress and Length.                                 The bit mask of attributes is not support for the memory resource                                 range specified by BaseAddress and Length.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CPU_SET_MEMORY_ATTRIBUTES
function_decl|)
parameter_list|(
name|IN
name|EFI_CPU_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|BaseAddress
parameter_list|,
name|IN
name|UINT64
name|Length
parameter_list|,
name|IN
name|UINT64
name|Attributes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_CPU_ARCH_PROTOCOL is used to abstract processor-specific functions from the DXE
end_comment

begin_comment
comment|/// Foundation. This includes flushing caches, enabling and disabling interrupts, hooking interrupt
end_comment

begin_comment
comment|/// vectors and exception vectors, reading internal processor timers, resetting the processor, and
end_comment

begin_comment
comment|/// determining the processor frequency.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_CPU_ARCH_PROTOCOL
block|{
name|EFI_CPU_FLUSH_DATA_CACHE
name|FlushDataCache
decl_stmt|;
name|EFI_CPU_ENABLE_INTERRUPT
name|EnableInterrupt
decl_stmt|;
name|EFI_CPU_DISABLE_INTERRUPT
name|DisableInterrupt
decl_stmt|;
name|EFI_CPU_GET_INTERRUPT_STATE
name|GetInterruptState
decl_stmt|;
name|EFI_CPU_INIT
name|Init
decl_stmt|;
name|EFI_CPU_REGISTER_INTERRUPT_HANDLER
name|RegisterInterruptHandler
decl_stmt|;
name|EFI_CPU_GET_TIMER_VALUE
name|GetTimerValue
decl_stmt|;
name|EFI_CPU_SET_MEMORY_ATTRIBUTES
name|SetMemoryAttributes
decl_stmt|;
comment|///
comment|/// The number of timers that are available in a processor. The value in this
comment|/// field is a constant that must not be modified after the CPU Architectural
comment|/// Protocol is installed. All consumers must treat this as a read-only field.
comment|///
name|UINT32
name|NumberOfTimers
decl_stmt|;
comment|///
comment|/// The size, in bytes, of the alignment required for DMA buffer allocations.
comment|/// This is typically the size of the largest data cache line in the platform.
comment|/// The value in this field is a constant that must not be modified after the
comment|/// CPU Architectural Protocol is installed. All consumers must treat this as
comment|/// a read-only field.
comment|///
name|UINT32
name|DmaBufferAlignment
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCpuArchProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

