begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_descriptions.h -------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ASan-private header for asan_descriptions.cc.
end_comment

begin_comment
comment|// TODO(filcab): Most struct definitions should move to the interface headers.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_DESCRIPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_DESCRIPTIONS_H
end_define

begin_include
include|#
directive|include
file|"asan_allocator.h"
end_include

begin_include
include|#
directive|include
file|"asan_thread.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_report_decorator.h"
end_include

begin_decl_stmt
name|namespace
name|__asan
block|{
name|void
name|DescribeThread
parameter_list|(
name|AsanThreadContext
modifier|*
name|context
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|void
name|DescribeThread
parameter_list|(
name|AsanThread
modifier|*
name|t
parameter_list|)
block|{
if|if
condition|(
name|t
condition|)
name|DescribeThread
argument_list|(
name|t
operator|->
name|context
argument_list|()
argument_list|)
expr_stmt|;
block|}
specifier|const
name|char
modifier|*
name|ThreadNameWithParenthesis
parameter_list|(
name|AsanThreadContext
modifier|*
name|t
parameter_list|,
name|char
name|buff
index|[]
parameter_list|,
name|uptr
name|buff_len
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|ThreadNameWithParenthesis
parameter_list|(
name|u32
name|tid
parameter_list|,
name|char
name|buff
index|[]
parameter_list|,
name|uptr
name|buff_len
parameter_list|)
function_decl|;
name|class
name|Decorator
range|:
name|public
name|__sanitizer
operator|::
name|SanitizerCommonDecorator
block|{
name|public
operator|:
name|Decorator
argument_list|()
operator|:
name|SanitizerCommonDecorator
argument_list|()
block|{}
specifier|const
name|char
operator|*
name|Access
argument_list|()
block|{
return|return
name|Blue
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|EndAccess
argument_list|()
block|{
return|return
name|Default
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|Location
argument_list|()
block|{
return|return
name|Green
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|EndLocation
argument_list|()
block|{
return|return
name|Default
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|Allocation
argument_list|()
block|{
return|return
name|Magenta
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|EndAllocation
argument_list|()
block|{
return|return
name|Default
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|ShadowByte
argument_list|(
argument|u8 byte
argument_list|)
block|{
switch|switch
condition|(
name|byte
condition|)
block|{
case|case
name|kAsanHeapLeftRedzoneMagic
case|:
case|case
name|kAsanArrayCookieMagic
case|:
return|return
name|Red
argument_list|()
return|;
case|case
name|kAsanHeapFreeMagic
case|:
return|return
name|Magenta
argument_list|()
return|;
case|case
name|kAsanStackLeftRedzoneMagic
case|:
case|case
name|kAsanStackMidRedzoneMagic
case|:
case|case
name|kAsanStackRightRedzoneMagic
case|:
return|return
name|Red
argument_list|()
return|;
case|case
name|kAsanStackAfterReturnMagic
case|:
return|return
name|Magenta
argument_list|()
return|;
case|case
name|kAsanInitializationOrderMagic
case|:
return|return
name|Cyan
argument_list|()
return|;
case|case
name|kAsanUserPoisonedMemoryMagic
case|:
case|case
name|kAsanContiguousContainerOOBMagic
case|:
case|case
name|kAsanAllocaLeftMagic
case|:
case|case
name|kAsanAllocaRightMagic
case|:
return|return
name|Blue
argument_list|()
return|;
case|case
name|kAsanStackUseAfterScopeMagic
case|:
return|return
name|Magenta
argument_list|()
return|;
case|case
name|kAsanGlobalRedzoneMagic
case|:
return|return
name|Red
argument_list|()
return|;
case|case
name|kAsanInternalHeapMagic
case|:
return|return
name|Yellow
argument_list|()
return|;
case|case
name|kAsanIntraObjectRedzone
case|:
return|return
name|Yellow
argument_list|()
return|;
default|default:
return|return
name|Default
argument_list|()
return|;
block|}
block|}
specifier|const
name|char
operator|*
name|EndShadowByte
argument_list|()
block|{
return|return
name|Default
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|MemoryByte
argument_list|()
block|{
return|return
name|Magenta
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|EndMemoryByte
argument_list|()
block|{
return|return
name|Default
argument_list|()
return|;
block|}
expr|}
block|;  enum
name|ShadowKind
operator|:
name|u8
block|{
name|kShadowKindLow
block|,
name|kShadowKindGap
block|,
name|kShadowKindHigh
block|, }
block|;
specifier|static
specifier|const
name|char
operator|*
specifier|const
name|ShadowNames
index|[]
operator|=
block|{
literal|"low shadow"
block|,
literal|"shadow gap"
block|,
literal|"high shadow"
block|}
block|;  struct
name|ShadowAddressDescription
block|{
name|uptr
name|addr
block|;
name|ShadowKind
name|kind
block|;
name|u8
name|shadow_byte
block|;
name|void
name|Print
argument_list|()
specifier|const
block|; }
block|;
name|bool
name|GetShadowAddressInformation
argument_list|(
argument|uptr addr
argument_list|,
argument|ShadowAddressDescription *descr
argument_list|)
block|;
name|bool
name|DescribeAddressIfShadow
argument_list|(
argument|uptr addr
argument_list|)
block|;  enum
name|AccessType
block|{
name|kAccessTypeLeft
block|,
name|kAccessTypeRight
block|,
name|kAccessTypeInside
block|,
name|kAccessTypeUnknown
block|,
comment|// This means we have an AddressSanitizer bug!
block|}
block|;  struct
name|ChunkAccess
block|{
name|uptr
name|bad_addr
block|;
name|sptr
name|offset
block|;
name|uptr
name|chunk_begin
block|;
name|uptr
name|chunk_size
block|;
name|u32
name|access_type
operator|:
literal|2
block|;
name|u32
name|alloc_type
operator|:
literal|2
block|; }
block|;  struct
name|HeapAddressDescription
block|{
name|uptr
name|addr
block|;
name|uptr
name|alloc_tid
block|;
name|uptr
name|free_tid
block|;
name|u32
name|alloc_stack_id
block|;
name|u32
name|free_stack_id
block|;
name|ChunkAccess
name|chunk_access
block|;
name|void
name|Print
argument_list|()
specifier|const
block|; }
block|;
name|bool
name|GetHeapAddressInformation
argument_list|(
argument|uptr addr
argument_list|,
argument|uptr access_size
argument_list|,
argument|HeapAddressDescription *descr
argument_list|)
block|;
name|bool
name|DescribeAddressIfHeap
argument_list|(
argument|uptr addr
argument_list|,
argument|uptr access_size =
literal|1
argument_list|)
block|;  struct
name|StackAddressDescription
block|{
name|uptr
name|addr
block|;
name|uptr
name|tid
block|;
name|uptr
name|offset
block|;
name|uptr
name|frame_pc
block|;
name|uptr
name|access_size
block|;
specifier|const
name|char
operator|*
name|frame_descr
block|;
name|void
name|Print
argument_list|()
specifier|const
block|; }
block|;
name|bool
name|GetStackAddressInformation
argument_list|(
argument|uptr addr
argument_list|,
argument|uptr access_size
argument_list|,
argument|StackAddressDescription *descr
argument_list|)
block|;  struct
name|GlobalAddressDescription
block|{
name|uptr
name|addr
block|;
comment|// Assume address is close to at most four globals.
specifier|static
specifier|const
name|int
name|kMaxGlobals
operator|=
literal|4
block|;
name|__asan_global
name|globals
index|[
name|kMaxGlobals
index|]
block|;
name|u32
name|reg_sites
index|[
name|kMaxGlobals
index|]
block|;
name|uptr
name|access_size
block|;
name|u8
name|size
block|;
name|void
name|Print
argument_list|(
argument|const char *bug_type =
literal|""
argument_list|)
specifier|const
block|; }
block|;
name|bool
name|GetGlobalAddressInformation
argument_list|(
argument|uptr addr
argument_list|,
argument|uptr access_size
argument_list|,
argument|GlobalAddressDescription *descr
argument_list|)
block|;
name|bool
name|DescribeAddressIfGlobal
argument_list|(
argument|uptr addr
argument_list|,
argument|uptr access_size
argument_list|,
argument|const char *bug_type
argument_list|)
block|;
comment|// General function to describe an address. Will try to describe the address as
comment|// a shadow, global (variable), stack, or heap address.
comment|// bug_type is optional and is used for checking if we're reporting an
comment|// initialization-order-fiasco
comment|// The proper access_size should be passed for stack, global, and heap
comment|// addresses. Defaults to 1.
comment|// Each of the *AddressDescription functions has its own Print() member, which
comment|// may take access_size and bug_type parameters if needed.
name|void
name|PrintAddressDescription
argument_list|(
argument|uptr addr
argument_list|,
argument|uptr access_size =
literal|1
argument_list|,
argument|const char *bug_type =
literal|""
argument_list|)
block|;  enum
name|AddressKind
block|{
name|kAddressKindWild
block|,
name|kAddressKindShadow
block|,
name|kAddressKindHeap
block|,
name|kAddressKindStack
block|,
name|kAddressKindGlobal
block|, }
block|;
name|class
name|AddressDescription
block|{   struct
name|AddressDescriptionData
block|{
name|AddressKind
name|kind
block|;
expr|union
block|{
name|ShadowAddressDescription
name|shadow
block|;
name|HeapAddressDescription
name|heap
block|;
name|StackAddressDescription
name|stack
block|;
name|GlobalAddressDescription
name|global
block|;
name|uptr
name|addr
block|;     }
block|;   }
block|;
name|AddressDescriptionData
name|data
block|;
name|public
operator|:
name|AddressDescription
argument_list|()
operator|=
expr|default
block|;
comment|// shouldLockThreadRegistry allows us to skip locking if we're sure we already
comment|// have done it.
name|AddressDescription
argument_list|(
argument|uptr addr
argument_list|,
argument|bool shouldLockThreadRegistry = true
argument_list|)
operator|:
name|AddressDescription
argument_list|(
argument|addr
argument_list|,
literal|1
argument_list|,
argument|shouldLockThreadRegistry
argument_list|)
block|{}
name|AddressDescription
argument_list|(
argument|uptr addr
argument_list|,
argument|uptr access_size
argument_list|,
argument|bool shouldLockThreadRegistry = true
argument_list|)
block|;
name|uptr
name|Address
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|data
operator|.
name|kind
condition|)
block|{
case|case
name|kAddressKindWild
case|:
return|return
name|data
operator|.
name|addr
return|;
case|case
name|kAddressKindShadow
case|:
return|return
name|data
operator|.
name|shadow
operator|.
name|addr
return|;
case|case
name|kAddressKindHeap
case|:
return|return
name|data
operator|.
name|heap
operator|.
name|addr
return|;
case|case
name|kAddressKindStack
case|:
return|return
name|data
operator|.
name|stack
operator|.
name|addr
return|;
case|case
name|kAddressKindGlobal
case|:
return|return
name|data
operator|.
name|global
operator|.
name|addr
return|;
block|}
name|UNREACHABLE
argument_list|(
literal|"AddressInformation kind is invalid"
argument_list|)
expr_stmt|;
block|}
name|void
name|Print
argument_list|(
argument|const char *bug_descr = nullptr
argument_list|)
specifier|const
block|{
switch|switch
condition|(
name|data
operator|.
name|kind
condition|)
block|{
case|case
name|kAddressKindWild
case|:
name|Printf
argument_list|(
literal|"Address %p is a wild pointer.\n"
argument_list|,
name|data
operator|.
name|addr
argument_list|)
expr_stmt|;
return|return;
case|case
name|kAddressKindShadow
case|:
return|return
name|data
operator|.
name|shadow
operator|.
name|Print
argument_list|()
return|;
case|case
name|kAddressKindHeap
case|:
return|return
name|data
operator|.
name|heap
operator|.
name|Print
argument_list|()
return|;
case|case
name|kAddressKindStack
case|:
return|return
name|data
operator|.
name|stack
operator|.
name|Print
argument_list|()
return|;
case|case
name|kAddressKindGlobal
case|:
comment|// initialization-order-fiasco has a special Print()
return|return
name|data
operator|.
name|global
operator|.
name|Print
argument_list|(
name|bug_descr
argument_list|)
return|;
block|}
name|UNREACHABLE
argument_list|(
literal|"AddressInformation kind is invalid"
argument_list|)
expr_stmt|;
block|}
name|void
name|StoreTo
argument_list|(
argument|AddressDescriptionData *dst
argument_list|)
specifier|const
block|{
operator|*
name|dst
operator|=
name|data
block|; }
specifier|const
name|ShadowAddressDescription
operator|*
name|AsShadow
argument_list|()
specifier|const
block|{
return|return
name|data
operator|.
name|kind
operator|==
name|kAddressKindShadow
operator|?
operator|&
name|data
operator|.
name|shadow
operator|:
name|nullptr
return|;
block|}
specifier|const
name|HeapAddressDescription
operator|*
name|AsHeap
argument_list|()
specifier|const
block|{
return|return
name|data
operator|.
name|kind
operator|==
name|kAddressKindHeap
condition|?
operator|&
name|data
operator|.
name|heap
else|:
name|nullptr
return|;
block|}
specifier|const
name|StackAddressDescription
operator|*
name|AsStack
argument_list|()
specifier|const
block|{
return|return
name|data
operator|.
name|kind
operator|==
name|kAddressKindStack
condition|?
operator|&
name|data
operator|.
name|stack
else|:
name|nullptr
return|;
block|}
specifier|const
name|GlobalAddressDescription
operator|*
name|AsGlobal
argument_list|()
specifier|const
block|{
return|return
name|data
operator|.
name|kind
operator|==
name|kAddressKindGlobal
condition|?
operator|&
name|data
operator|.
name|global
else|:
name|nullptr
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_DESCRIPTIONS_H
end_comment

end_unit

