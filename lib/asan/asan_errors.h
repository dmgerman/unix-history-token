begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_errors.h -------------------------------------------*- C++ -*-===//
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
comment|// ASan-private header for error structures.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_ERRORS_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_ERRORS_H
end_define

begin_include
include|#
directive|include
file|"asan_descriptions.h"
end_include

begin_include
include|#
directive|include
file|"asan_scariness_score.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_decl_stmt
name|namespace
name|__asan
block|{
struct|struct
name|ErrorBase
block|{
name|ErrorBase
argument_list|()
operator|=
expr|default
expr_stmt|;
name|explicit
name|ErrorBase
argument_list|(
argument|u32 tid_
argument_list|)
block|:
name|tid
argument_list|(
argument|tid_
argument_list|)
block|{}
name|ScarinessScoreBase
name|scariness
decl_stmt|;
name|u32
name|tid
decl_stmt|;
block|}
struct|;
name|struct
name|ErrorStackOverflow
range|:
name|ErrorBase
block|{
name|uptr
name|addr
block|,
name|pc
block|,
name|bp
block|,
name|sp
block|;
comment|// ErrorStackOverflow never owns the context.
name|void
operator|*
name|context
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorStackOverflow
argument_list|()
operator|=
expr|default
block|;
name|ErrorStackOverflow
argument_list|(
argument|u32 tid
argument_list|,
argument|const SignalContext&sig
argument_list|)
operator|:
name|ErrorBase
argument_list|(
name|tid
argument_list|)
block|,
name|addr
argument_list|(
name|sig
operator|.
name|addr
argument_list|)
block|,
name|pc
argument_list|(
name|sig
operator|.
name|pc
argument_list|)
block|,
name|bp
argument_list|(
name|sig
operator|.
name|bp
argument_list|)
block|,
name|sp
argument_list|(
name|sig
operator|.
name|sp
argument_list|)
block|,
name|context
argument_list|(
argument|sig.context
argument_list|)
block|{
name|scariness
operator|.
name|Clear
argument_list|()
block|;
name|scariness
operator|.
name|Scare
argument_list|(
literal|10
argument_list|,
literal|"stack-overflow"
argument_list|)
block|;   }
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
name|struct
name|ErrorDeadlySignal
range|:
name|ErrorBase
block|{
name|uptr
name|addr
block|,
name|pc
block|,
name|bp
block|,
name|sp
block|;
comment|// ErrorDeadlySignal never owns the context.
name|void
operator|*
name|context
block|;
name|int
name|signo
block|;
name|SignalContext
operator|::
name|WriteFlag
name|write_flag
block|;
name|bool
name|is_memory_access
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorDeadlySignal
argument_list|()
operator|=
expr|default
block|;
name|ErrorDeadlySignal
argument_list|(
argument|u32 tid
argument_list|,
argument|const SignalContext&sig
argument_list|,
argument|int signo_
argument_list|)
operator|:
name|ErrorBase
argument_list|(
name|tid
argument_list|)
block|,
name|addr
argument_list|(
name|sig
operator|.
name|addr
argument_list|)
block|,
name|pc
argument_list|(
name|sig
operator|.
name|pc
argument_list|)
block|,
name|bp
argument_list|(
name|sig
operator|.
name|bp
argument_list|)
block|,
name|sp
argument_list|(
name|sig
operator|.
name|sp
argument_list|)
block|,
name|context
argument_list|(
name|sig
operator|.
name|context
argument_list|)
block|,
name|signo
argument_list|(
name|signo_
argument_list|)
block|,
name|write_flag
argument_list|(
name|sig
operator|.
name|write_flag
argument_list|)
block|,
name|is_memory_access
argument_list|(
argument|sig.is_memory_access
argument_list|)
block|{
name|scariness
operator|.
name|Clear
argument_list|()
block|;
if|if
condition|(
name|is_memory_access
condition|)
block|{
if|if
condition|(
name|addr
operator|<
name|GetPageSizeCached
argument_list|()
condition|)
block|{
name|scariness
operator|.
name|Scare
argument_list|(
literal|10
argument_list|,
literal|"null-deref"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|addr
operator|==
name|pc
condition|)
block|{
name|scariness
operator|.
name|Scare
argument_list|(
literal|60
argument_list|,
literal|"wild-jump"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|write_flag
operator|==
name|SignalContext
operator|::
name|WRITE
condition|)
block|{
name|scariness
operator|.
name|Scare
argument_list|(
literal|30
argument_list|,
literal|"wild-addr-write"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|write_flag
operator|==
name|SignalContext
operator|::
name|READ
condition|)
block|{
name|scariness
operator|.
name|Scare
argument_list|(
literal|20
argument_list|,
literal|"wild-addr-read"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|scariness
operator|.
name|Scare
argument_list|(
literal|25
argument_list|,
literal|"wild-addr"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|scariness
operator|.
name|Scare
argument_list|(
literal|10
argument_list|,
literal|"signal"
argument_list|)
expr_stmt|;
block|}
block|}
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
name|struct
name|ErrorDoubleFree
range|:
name|ErrorBase
block|{
comment|// ErrorDoubleFree doesn't own the stack trace.
specifier|const
name|BufferedStackTrace
operator|*
name|second_free_stack
block|;
name|HeapAddressDescription
name|addr_description
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorDoubleFree
argument_list|()
operator|=
expr|default
block|;
name|ErrorDoubleFree
argument_list|(
argument|u32 tid
argument_list|,
argument|BufferedStackTrace *stack
argument_list|,
argument|uptr addr
argument_list|)
operator|:
name|ErrorBase
argument_list|(
name|tid
argument_list|)
block|,
name|second_free_stack
argument_list|(
argument|stack
argument_list|)
block|{
name|CHECK_GT
argument_list|(
name|second_free_stack
operator|->
name|size
argument_list|,
literal|0
argument_list|)
block|;
name|GetHeapAddressInformation
argument_list|(
name|addr
argument_list|,
literal|1
argument_list|,
operator|&
name|addr_description
argument_list|)
block|;
name|scariness
operator|.
name|Clear
argument_list|()
block|;
name|scariness
operator|.
name|Scare
argument_list|(
literal|42
argument_list|,
literal|"double-free"
argument_list|)
block|;   }
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
name|struct
name|ErrorNewDeleteSizeMismatch
range|:
name|ErrorBase
block|{
comment|// ErrorNewDeleteSizeMismatch doesn't own the stack trace.
specifier|const
name|BufferedStackTrace
operator|*
name|free_stack
block|;
name|HeapAddressDescription
name|addr_description
block|;
name|uptr
name|delete_size
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorNewDeleteSizeMismatch
argument_list|()
operator|=
expr|default
block|;
name|ErrorNewDeleteSizeMismatch
argument_list|(
argument|u32 tid
argument_list|,
argument|BufferedStackTrace *stack
argument_list|,
argument|uptr addr
argument_list|,
argument|uptr delete_size_
argument_list|)
operator|:
name|ErrorBase
argument_list|(
name|tid
argument_list|)
block|,
name|free_stack
argument_list|(
name|stack
argument_list|)
block|,
name|delete_size
argument_list|(
argument|delete_size_
argument_list|)
block|{
name|GetHeapAddressInformation
argument_list|(
name|addr
argument_list|,
literal|1
argument_list|,
operator|&
name|addr_description
argument_list|)
block|;
name|scariness
operator|.
name|Clear
argument_list|()
block|;
name|scariness
operator|.
name|Scare
argument_list|(
literal|10
argument_list|,
literal|"new-delete-type-mismatch"
argument_list|)
block|;   }
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
name|struct
name|ErrorFreeNotMalloced
range|:
name|ErrorBase
block|{
comment|// ErrorFreeNotMalloced doesn't own the stack trace.
specifier|const
name|BufferedStackTrace
operator|*
name|free_stack
block|;
name|AddressDescription
name|addr_description
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorFreeNotMalloced
argument_list|()
operator|=
expr|default
block|;
name|ErrorFreeNotMalloced
argument_list|(
argument|u32 tid
argument_list|,
argument|BufferedStackTrace *stack
argument_list|,
argument|uptr addr
argument_list|)
operator|:
name|ErrorBase
argument_list|(
name|tid
argument_list|)
block|,
name|free_stack
argument_list|(
name|stack
argument_list|)
block|,
name|addr_description
argument_list|(
argument|addr
argument_list|,
comment|/*shouldLockThreadRegistry=*/
argument|false
argument_list|)
block|{
name|scariness
operator|.
name|Clear
argument_list|()
block|;
name|scariness
operator|.
name|Scare
argument_list|(
literal|40
argument_list|,
literal|"bad-free"
argument_list|)
block|;   }
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
name|struct
name|ErrorAllocTypeMismatch
range|:
name|ErrorBase
block|{
comment|// ErrorAllocTypeMismatch doesn't own the stack trace.
specifier|const
name|BufferedStackTrace
operator|*
name|dealloc_stack
block|;
name|HeapAddressDescription
name|addr_description
block|;
name|AllocType
name|alloc_type
block|,
name|dealloc_type
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorAllocTypeMismatch
argument_list|()
operator|=
expr|default
block|;
name|ErrorAllocTypeMismatch
argument_list|(
argument|u32 tid
argument_list|,
argument|BufferedStackTrace *stack
argument_list|,
argument|uptr addr
argument_list|,
argument|AllocType alloc_type_
argument_list|,
argument|AllocType dealloc_type_
argument_list|)
operator|:
name|ErrorBase
argument_list|(
name|tid
argument_list|)
block|,
name|dealloc_stack
argument_list|(
name|stack
argument_list|)
block|,
name|alloc_type
argument_list|(
name|alloc_type_
argument_list|)
block|,
name|dealloc_type
argument_list|(
argument|dealloc_type_
argument_list|)
block|{
name|GetHeapAddressInformation
argument_list|(
name|addr
argument_list|,
literal|1
argument_list|,
operator|&
name|addr_description
argument_list|)
block|;
name|scariness
operator|.
name|Clear
argument_list|()
block|;
name|scariness
operator|.
name|Scare
argument_list|(
literal|10
argument_list|,
literal|"alloc-dealloc-mismatch"
argument_list|)
block|;   }
block|;
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
name|struct
name|ErrorMallocUsableSizeNotOwned
range|:
name|ErrorBase
block|{
comment|// ErrorMallocUsableSizeNotOwned doesn't own the stack trace.
specifier|const
name|BufferedStackTrace
operator|*
name|stack
block|;
name|AddressDescription
name|addr_description
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorMallocUsableSizeNotOwned
argument_list|()
operator|=
expr|default
block|;
name|ErrorMallocUsableSizeNotOwned
argument_list|(
argument|u32 tid
argument_list|,
argument|BufferedStackTrace *stack_
argument_list|,
argument|uptr addr
argument_list|)
operator|:
name|ErrorBase
argument_list|(
name|tid
argument_list|)
block|,
name|stack
argument_list|(
name|stack_
argument_list|)
block|,
name|addr_description
argument_list|(
argument|addr
argument_list|,
comment|/*shouldLockThreadRegistry=*/
argument|false
argument_list|)
block|{
name|scariness
operator|.
name|Clear
argument_list|()
block|;
name|scariness
operator|.
name|Scare
argument_list|(
literal|10
argument_list|,
literal|"bad-malloc_usable_size"
argument_list|)
block|;   }
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
name|struct
name|ErrorSanitizerGetAllocatedSizeNotOwned
range|:
name|ErrorBase
block|{
comment|// ErrorSanitizerGetAllocatedSizeNotOwned doesn't own the stack trace.
specifier|const
name|BufferedStackTrace
operator|*
name|stack
block|;
name|AddressDescription
name|addr_description
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorSanitizerGetAllocatedSizeNotOwned
argument_list|()
operator|=
expr|default
block|;
name|ErrorSanitizerGetAllocatedSizeNotOwned
argument_list|(
argument|u32 tid
argument_list|,
argument|BufferedStackTrace *stack_
argument_list|,
argument|uptr addr
argument_list|)
operator|:
name|ErrorBase
argument_list|(
name|tid
argument_list|)
block|,
name|stack
argument_list|(
name|stack_
argument_list|)
block|,
name|addr_description
argument_list|(
argument|addr
argument_list|,
comment|/*shouldLockThreadRegistry=*/
argument|false
argument_list|)
block|{
name|scariness
operator|.
name|Clear
argument_list|()
block|;
name|scariness
operator|.
name|Scare
argument_list|(
literal|10
argument_list|,
literal|"bad-__sanitizer_get_allocated_size"
argument_list|)
block|;   }
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
name|struct
name|ErrorStringFunctionMemoryRangesOverlap
range|:
name|ErrorBase
block|{
comment|// ErrorStringFunctionMemoryRangesOverlap doesn't own the stack trace.
specifier|const
name|BufferedStackTrace
operator|*
name|stack
block|;
name|uptr
name|length1
block|,
name|length2
block|;
name|AddressDescription
name|addr1_description
block|;
name|AddressDescription
name|addr2_description
block|;
specifier|const
name|char
operator|*
name|function
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorStringFunctionMemoryRangesOverlap
argument_list|()
operator|=
expr|default
block|;
name|ErrorStringFunctionMemoryRangesOverlap
argument_list|(
argument|u32 tid
argument_list|,
argument|BufferedStackTrace *stack_
argument_list|,
argument|uptr addr1
argument_list|,
argument|uptr length1_
argument_list|,
argument|uptr addr2
argument_list|,
argument|uptr length2_
argument_list|,
argument|const char *function_
argument_list|)
operator|:
name|ErrorBase
argument_list|(
name|tid
argument_list|)
block|,
name|stack
argument_list|(
name|stack_
argument_list|)
block|,
name|length1
argument_list|(
name|length1_
argument_list|)
block|,
name|length2
argument_list|(
name|length2_
argument_list|)
block|,
name|addr1_description
argument_list|(
name|addr1
argument_list|,
name|length1
argument_list|,
comment|/*shouldLockThreadRegistry=*/
name|false
argument_list|)
block|,
name|addr2_description
argument_list|(
name|addr2
argument_list|,
name|length2
argument_list|,
comment|/*shouldLockThreadRegistry=*/
name|false
argument_list|)
block|,
name|function
argument_list|(
argument|function_
argument_list|)
block|{
name|char
name|bug_type
index|[
literal|100
index|]
block|;
name|internal_snprintf
argument_list|(
name|bug_type
argument_list|,
sizeof|sizeof
argument_list|(
name|bug_type
argument_list|)
argument_list|,
literal|"%s-param-overlap"
argument_list|,
name|function
argument_list|)
block|;
name|scariness
operator|.
name|Clear
argument_list|()
block|;
name|scariness
operator|.
name|Scare
argument_list|(
literal|10
argument_list|,
name|bug_type
argument_list|)
block|;   }
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
name|struct
name|ErrorStringFunctionSizeOverflow
range|:
name|ErrorBase
block|{
comment|// ErrorStringFunctionSizeOverflow doesn't own the stack trace.
specifier|const
name|BufferedStackTrace
operator|*
name|stack
block|;
name|AddressDescription
name|addr_description
block|;
name|uptr
name|size
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorStringFunctionSizeOverflow
argument_list|()
operator|=
expr|default
block|;
name|ErrorStringFunctionSizeOverflow
argument_list|(
argument|u32 tid
argument_list|,
argument|BufferedStackTrace *stack_
argument_list|,
argument|uptr addr
argument_list|,
argument|uptr size_
argument_list|)
operator|:
name|ErrorBase
argument_list|(
name|tid
argument_list|)
block|,
name|stack
argument_list|(
name|stack_
argument_list|)
block|,
name|addr_description
argument_list|(
name|addr
argument_list|,
comment|/*shouldLockThreadRegistry=*/
name|false
argument_list|)
block|,
name|size
argument_list|(
argument|size_
argument_list|)
block|{
name|scariness
operator|.
name|Clear
argument_list|()
block|;
name|scariness
operator|.
name|Scare
argument_list|(
literal|10
argument_list|,
literal|"negative-size-param"
argument_list|)
block|;   }
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
name|struct
name|ErrorBadParamsToAnnotateContiguousContainer
range|:
name|ErrorBase
block|{
comment|// ErrorBadParamsToAnnotateContiguousContainer doesn't own the stack trace.
specifier|const
name|BufferedStackTrace
operator|*
name|stack
block|;
name|uptr
name|beg
block|,
name|end
block|,
name|old_mid
block|,
name|new_mid
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorBadParamsToAnnotateContiguousContainer
argument_list|()
operator|=
expr|default
block|;
comment|// PS4: Do we want an AddressDescription for beg?
name|ErrorBadParamsToAnnotateContiguousContainer
argument_list|(
argument|u32 tid
argument_list|,
argument|BufferedStackTrace *stack_
argument_list|,
argument|uptr beg_
argument_list|,
argument|uptr end_
argument_list|,
argument|uptr old_mid_
argument_list|,
argument|uptr new_mid_
argument_list|)
operator|:
name|ErrorBase
argument_list|(
name|tid
argument_list|)
block|,
name|stack
argument_list|(
name|stack_
argument_list|)
block|,
name|beg
argument_list|(
name|beg_
argument_list|)
block|,
name|end
argument_list|(
name|end_
argument_list|)
block|,
name|old_mid
argument_list|(
name|old_mid_
argument_list|)
block|,
name|new_mid
argument_list|(
argument|new_mid_
argument_list|)
block|{
name|scariness
operator|.
name|Clear
argument_list|()
block|;
name|scariness
operator|.
name|Scare
argument_list|(
literal|10
argument_list|,
literal|"bad-__sanitizer_annotate_contiguous_container"
argument_list|)
block|;   }
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
name|struct
name|ErrorODRViolation
range|:
name|ErrorBase
block|{
name|__asan_global
name|global1
block|,
name|global2
block|;
name|u32
name|stack_id1
block|,
name|stack_id2
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorODRViolation
argument_list|()
operator|=
expr|default
block|;
name|ErrorODRViolation
argument_list|(
argument|u32 tid
argument_list|,
argument|const __asan_global *g1
argument_list|,
argument|u32 stack_id1_
argument_list|,
argument|const __asan_global *g2
argument_list|,
argument|u32 stack_id2_
argument_list|)
operator|:
name|ErrorBase
argument_list|(
name|tid
argument_list|)
block|,
name|global1
argument_list|(
operator|*
name|g1
argument_list|)
block|,
name|global2
argument_list|(
operator|*
name|g2
argument_list|)
block|,
name|stack_id1
argument_list|(
name|stack_id1_
argument_list|)
block|,
name|stack_id2
argument_list|(
argument|stack_id2_
argument_list|)
block|{
name|scariness
operator|.
name|Clear
argument_list|()
block|;
name|scariness
operator|.
name|Scare
argument_list|(
literal|10
argument_list|,
literal|"odr-violation"
argument_list|)
block|;   }
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
name|struct
name|ErrorInvalidPointerPair
range|:
name|ErrorBase
block|{
name|uptr
name|pc
block|,
name|bp
block|,
name|sp
block|;
name|AddressDescription
name|addr1_description
block|;
name|AddressDescription
name|addr2_description
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorInvalidPointerPair
argument_list|()
operator|=
expr|default
block|;
name|ErrorInvalidPointerPair
argument_list|(
argument|u32 tid
argument_list|,
argument|uptr pc_
argument_list|,
argument|uptr bp_
argument_list|,
argument|uptr sp_
argument_list|,
argument|uptr p1
argument_list|,
argument|uptr p2
argument_list|)
operator|:
name|ErrorBase
argument_list|(
name|tid
argument_list|)
block|,
name|pc
argument_list|(
name|pc_
argument_list|)
block|,
name|bp
argument_list|(
name|bp_
argument_list|)
block|,
name|sp
argument_list|(
name|sp_
argument_list|)
block|,
name|addr1_description
argument_list|(
name|p1
argument_list|,
literal|1
argument_list|,
comment|/*shouldLockThreadRegistry=*/
name|false
argument_list|)
block|,
name|addr2_description
argument_list|(
argument|p2
argument_list|,
literal|1
argument_list|,
comment|/*shouldLockThreadRegistry=*/
argument|false
argument_list|)
block|{
name|scariness
operator|.
name|Clear
argument_list|()
block|;
name|scariness
operator|.
name|Scare
argument_list|(
literal|10
argument_list|,
literal|"invalid-pointer-pair"
argument_list|)
block|;   }
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
name|struct
name|ErrorGeneric
range|:
name|ErrorBase
block|{
name|AddressDescription
name|addr_description
block|;
name|uptr
name|pc
block|,
name|bp
block|,
name|sp
block|;
name|uptr
name|access_size
block|;
specifier|const
name|char
operator|*
name|bug_descr
block|;
name|bool
name|is_write
block|;
name|u8
name|shadow_val
block|;
comment|// VS2013 doesn't implement unrestricted unions, so we need a trivial default
comment|// constructor
name|ErrorGeneric
argument_list|()
operator|=
expr|default
block|;
name|ErrorGeneric
argument_list|(
argument|u32 tid
argument_list|,
argument|uptr addr
argument_list|,
argument|uptr pc_
argument_list|,
argument|uptr bp_
argument_list|,
argument|uptr sp_
argument_list|,
argument|bool is_write_
argument_list|,
argument|uptr access_size_
argument_list|)
block|;
name|void
name|Print
argument_list|()
block|; }
decl_stmt|;
comment|// clang-format off
define|#
directive|define
name|ASAN_FOR_EACH_ERROR_KIND
parameter_list|(
name|macro
parameter_list|)
define|\
value|macro(StackOverflow)                          \   macro(DeadlySignal)                           \   macro(DoubleFree)                             \   macro(NewDeleteSizeMismatch)                  \   macro(FreeNotMalloced)                        \   macro(AllocTypeMismatch)                      \   macro(MallocUsableSizeNotOwned)               \   macro(SanitizerGetAllocatedSizeNotOwned)      \   macro(StringFunctionMemoryRangesOverlap)      \   macro(StringFunctionSizeOverflow)             \   macro(BadParamsToAnnotateContiguousContainer) \   macro(ODRViolation)                           \   macro(InvalidPointerPair)                     \   macro(Generic)
comment|// clang-format on
define|#
directive|define
name|ASAN_DEFINE_ERROR_KIND
parameter_list|(
name|name
parameter_list|)
value|kErrorKind##name,
define|#
directive|define
name|ASAN_ERROR_DESCRIPTION_MEMBER
parameter_list|(
name|name
parameter_list|)
value|Error##name name;
define|#
directive|define
name|ASAN_ERROR_DESCRIPTION_CONSTRUCTOR
parameter_list|(
name|name
parameter_list|)
define|\
value|ErrorDescription(Error##name const&e) : kind(kErrorKind##name), name(e) {}
define|#
directive|define
name|ASAN_ERROR_DESCRIPTION_PRINT
parameter_list|(
name|name
parameter_list|)
define|\
value|case kErrorKind##name:                   \     return name.Print();
enum|enum
name|ErrorKind
block|{
name|kErrorKindInvalid
init|=
literal|0
block|,
name|ASAN_FOR_EACH_ERROR_KIND
argument_list|(
argument|ASAN_DEFINE_ERROR_KIND
argument_list|)
block|}
enum|;
struct|struct
name|ErrorDescription
block|{
name|ErrorKind
name|kind
decl_stmt|;
comment|// We're using a tagged union because it allows us to have a trivially
comment|// copiable type and use the same structures as the public interface.
comment|//
comment|// We can add a wrapper around it to make it "more c++-like", but that would
comment|// add a lot of code and the benefit wouldn't be that big.
union|union
block|{
name|ErrorBase
name|Base
decl_stmt|;
name|ASAN_FOR_EACH_ERROR_KIND
argument_list|(
argument|ASAN_ERROR_DESCRIPTION_MEMBER
argument_list|)
block|}
union|;
name|ErrorDescription
argument_list|()
block|{
name|internal_memset
argument_list|(
name|this
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|ASAN_FOR_EACH_ERROR_KIND
argument_list|(
argument|ASAN_ERROR_DESCRIPTION_CONSTRUCTOR
argument_list|)
name|bool
name|IsValid
parameter_list|()
block|{
return|return
name|kind
operator|!=
name|kErrorKindInvalid
return|;
block|}
name|void
name|Print
parameter_list|()
block|{
switch|switch
condition|(
name|kind
condition|)
block|{
name|ASAN_FOR_EACH_ERROR_KIND
argument_list|(
argument|ASAN_ERROR_DESCRIPTION_PRINT
argument_list|)
case|case
name|kErrorKindInvalid
case|:
name|CHECK
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|CHECK
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
undef|#
directive|undef
name|ASAN_FOR_EACH_ERROR_KIND
undef|#
directive|undef
name|ASAN_DEFINE_ERROR_KIND
undef|#
directive|undef
name|ASAN_ERROR_DESCRIPTION_MEMBER
undef|#
directive|undef
name|ASAN_ERROR_DESCRIPTION_CONSTRUCTOR
undef|#
directive|undef
name|ASAN_ERROR_DESCRIPTION_PRINT
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_ERRORS_H
end_comment

end_unit

