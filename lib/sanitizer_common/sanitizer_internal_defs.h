begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_internal_defs.h -------------------------------*- C++ -*-===//
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
comment|// This file is shared between AddressSanitizer and ThreadSanitizer.
end_comment

begin_comment
comment|// It contains macro used in run-time libraries code.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_DEFS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_platform.h"
end_include

begin_comment
comment|// Only use SANITIZER_*ATTRIBUTE* before the function return type!
end_comment

begin_if
if|#
directive|if
name|SANITIZER_WINDOWS
end_if

begin_define
define|#
directive|define
name|SANITIZER_INTERFACE_ATTRIBUTE
value|__declspec(dllexport)
end_define

begin_comment
comment|// FIXME find out what we need on Windows, if anything.
end_comment

begin_define
define|#
directive|define
name|SANITIZER_WEAK_ATTRIBUTE
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SANITIZER_GO
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SANITIZER_INTERFACE_ATTRIBUTE
end_define

begin_define
define|#
directive|define
name|SANITIZER_WEAK_ATTRIBUTE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_INTERFACE_ATTRIBUTE
value|__attribute__((visibility("default")))
end_define

begin_define
define|#
directive|define
name|SANITIZER_WEAK_ATTRIBUTE
value|__attribute__((weak))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SANITIZER_LINUX
operator|&&
operator|!
name|defined
argument_list|(
name|SANITIZER_GO
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_SUPPORTS_WEAK_HOOKS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_SUPPORTS_WEAK_HOOKS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// We can use .preinit_array section on Linux to call sanitizer initialization
end_comment

begin_comment
comment|// functions very early in the process startup (unless PIC macro is defined).
end_comment

begin_comment
comment|// FIXME: do we have anything like this on Mac?
end_comment

begin_if
if|#
directive|if
name|SANITIZER_LINUX
operator|&&
operator|!
name|SANITIZER_ANDROID
operator|&&
operator|!
name|defined
argument_list|(
name|PIC
argument_list|)
end_if

begin_define
define|#
directive|define
name|SANITIZER_CAN_USE_PREINIT_ARRAY
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_CAN_USE_PREINIT_ARRAY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GCC does not understand __has_feature
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__has_feature
argument_list|)
end_if

begin_define
define|#
directive|define
name|__has_feature
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// For portability reasons we do not include stddef.h, stdint.h or any other
end_comment

begin_comment
comment|// system header, but we do need some basic types that are not defined
end_comment

begin_comment
comment|// in a portable way by the language itself.
end_comment

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
if|#
directive|if
name|defined
argument_list|(
name|_WIN64
argument_list|)
comment|// 64-bit Windows uses LLP64 data model.
typedef|typedef
name|unsigned
name|long
name|long
name|uptr
typedef|;
comment|// NOLINT
typedef|typedef
name|signed
name|long
name|long
name|sptr
typedef|;
comment|// NOLINT
else|#
directive|else
typedef|typedef
name|unsigned
name|long
name|uptr
typedef|;
comment|// NOLINT
typedef|typedef
name|signed
name|long
name|sptr
typedef|;
comment|// NOLINT
endif|#
directive|endif
comment|// defined(_WIN64)
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
comment|// Since x32 uses ILP32 data model in 64-bit hardware mode, we must use
comment|// 64-bit pointer to unwind stack frame.
typedef|typedef
name|unsigned
name|long
name|long
name|uhwptr
typedef|;
comment|// NOLINT
else|#
directive|else
typedef|typedef
name|uptr
name|uhwptr
typedef|;
comment|// NOLINT
endif|#
directive|endif
typedef|typedef
name|unsigned
name|char
name|u8
typedef|;
typedef|typedef
name|unsigned
name|short
name|u16
typedef|;
comment|// NOLINT
typedef|typedef
name|unsigned
name|int
name|u32
typedef|;
typedef|typedef
name|unsigned
name|long
name|long
name|u64
typedef|;
comment|// NOLINT
typedef|typedef
name|signed
name|char
name|s8
typedef|;
typedef|typedef
name|signed
name|short
name|s16
typedef|;
comment|// NOLINT
typedef|typedef
name|signed
name|int
name|s32
typedef|;
typedef|typedef
name|signed
name|long
name|long
name|s64
typedef|;
comment|// NOLINT
typedef|typedef
name|int
name|fd_t
typedef|;
comment|// WARNING: OFF_T may be different from OS type off_t, depending on the value of
comment|// _FILE_OFFSET_BITS. This definition of OFF_T matches the ABI of system calls
comment|// like pread and mmap, as opposed to pread64 and mmap64.
comment|// Mac and Linux/x86-64 are special.
if|#
directive|if
name|SANITIZER_MAC
operator|||
operator|(
name|SANITIZER_LINUX
operator|&&
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|)
typedef|typedef
name|u64
name|OFF_T
typedef|;
else|#
directive|else
typedef|typedef
name|uptr
name|OFF_T
typedef|;
endif|#
directive|endif
typedef|typedef
name|u64
name|OFF64_T
typedef|;
if|#
directive|if
operator|(
name|SANITIZER_WORDSIZE
operator|==
literal|64
operator|)
operator|||
name|SANITIZER_MAC
typedef|typedef
name|uptr
name|operator_new_size_type
typedef|;
else|#
directive|else
typedef|typedef
name|u32
name|operator_new_size_type
typedef|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_extern
extern|extern
literal|"C"
block|{
comment|// Tell the tools to write their reports to "path.<pid>" instead of stderr.
comment|// The special values are "stdout" and "stderr".
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__sanitizer_set_report_path
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
typedef|typedef
struct|struct
block|{
name|int
name|coverage_sandboxed
decl_stmt|;
name|__sanitizer
operator|::
name|sptr
name|coverage_fd
expr_stmt|;
name|unsigned
name|int
name|coverage_max_block_size
decl_stmt|;
block|}
name|__sanitizer_sandbox_arguments
typedef|;
comment|// Notify the tools that the sandbox is going to be turned on.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_sandbox_on_notify
parameter_list|(
name|__sanitizer_sandbox_arguments
modifier|*
name|args
parameter_list|)
function_decl|;
comment|// This function is called by the tool when it has just finished reporting
comment|// an error. 'error_summary' is a one-line string that summarizes
comment|// the error message. This function can be overridden by the client.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|SANITIZER_WEAK_ATTRIBUTE
name|void
name|__sanitizer_report_error_summary
parameter_list|(
specifier|const
name|char
modifier|*
name|error_summary
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__sanitizer_cov_dump
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__sanitizer_cov_init
parameter_list|()
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__sanitizer_cov
argument_list|(
name|__sanitizer
operator|::
name|u8
operator|*
name|guard
argument_list|)
decl_stmt|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|__sanitizer_annotate_contiguous_container
parameter_list|(
specifier|const
name|void
modifier|*
name|beg
parameter_list|,
specifier|const
name|void
modifier|*
name|end
parameter_list|,
specifier|const
name|void
modifier|*
name|old_mid
parameter_list|,
specifier|const
name|void
modifier|*
name|new_mid
parameter_list|)
function_decl|;
name|SANITIZER_INTERFACE_ATTRIBUTE
name|int
name|__sanitizer_verify_contiguous_container
parameter_list|(
specifier|const
name|void
modifier|*
name|beg
parameter_list|,
specifier|const
name|void
modifier|*
name|mid
parameter_list|,
specifier|const
name|void
modifier|*
name|end
parameter_list|)
function_decl|;
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_decl_stmt
name|using
name|namespace
name|__sanitizer
decl_stmt|;
end_decl_stmt

begin_comment
comment|// NOLINT
end_comment

begin_comment
comment|// ----------- ATTENTION -------------
end_comment

begin_comment
comment|// This header should NOT include any other headers to avoid portability issues.
end_comment

begin_comment
comment|// Common defs.
end_comment

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_define
define|#
directive|define
name|INTERFACE_ATTRIBUTE
value|SANITIZER_INTERFACE_ATTRIBUTE
end_define

begin_define
define|#
directive|define
name|WEAK
value|SANITIZER_WEAK_ATTRIBUTE
end_define

begin_comment
comment|// Platform-specific defs.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_define
define|#
directive|define
name|ALWAYS_INLINE
value|__forceinline
end_define

begin_comment
comment|// FIXME(timurrrr): do we need this on Windows?
end_comment

begin_define
define|#
directive|define
name|ALIAS
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ALIGNED
parameter_list|(
name|x
parameter_list|)
value|__declspec(align(x))
end_define

begin_define
define|#
directive|define
name|FORMAT
parameter_list|(
name|f
parameter_list|,
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NOINLINE
value|__declspec(noinline)
end_define

begin_define
define|#
directive|define
name|NORETURN
value|__declspec(noreturn)
end_define

begin_define
define|#
directive|define
name|THREADLOCAL
value|__declspec(thread)
end_define

begin_define
define|#
directive|define
name|NOTHROW
end_define

begin_define
define|#
directive|define
name|LIKELY
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|UNLIKELY
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|PREFETCH
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* _mm_prefetch(x, _MM_HINT_NTA) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// _MSC_VER
end_comment

begin_define
define|#
directive|define
name|ALWAYS_INLINE
value|inline __attribute__((always_inline))
end_define

begin_define
define|#
directive|define
name|ALIAS
parameter_list|(
name|x
parameter_list|)
value|__attribute__((alias(x)))
end_define

begin_comment
comment|// Please only use the ALIGNED macro before the type.
end_comment

begin_comment
comment|// Using ALIGNED after the variable declaration is not portable!
end_comment

begin_define
define|#
directive|define
name|ALIGNED
parameter_list|(
name|x
parameter_list|)
value|__attribute__((aligned(x)))
end_define

begin_define
define|#
directive|define
name|FORMAT
parameter_list|(
name|f
parameter_list|,
name|a
parameter_list|)
value|__attribute__((format(printf, f, a)))
end_define

begin_define
define|#
directive|define
name|NOINLINE
value|__attribute__((noinline))
end_define

begin_define
define|#
directive|define
name|NORETURN
value|__attribute__((noreturn))
end_define

begin_define
define|#
directive|define
name|THREADLOCAL
value|__thread
end_define

begin_define
define|#
directive|define
name|NOTHROW
value|throw()
end_define

begin_define
define|#
directive|define
name|LIKELY
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 1)
end_define

begin_define
define|#
directive|define
name|UNLIKELY
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 0)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_comment
comment|// __builtin_prefetch(x) generates prefetchnt0 on x86
end_comment

begin_define
define|#
directive|define
name|PREFETCH
parameter_list|(
name|x
parameter_list|)
value|__asm__("prefetchnta (%0)" : : "r" (x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PREFETCH
parameter_list|(
name|x
parameter_list|)
value|__builtin_prefetch(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _MSC_VER
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_define
define|#
directive|define
name|UNUSED
value|__attribute__((unused))
end_define

begin_define
define|#
directive|define
name|USED
value|__attribute__((used))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNUSED
end_define

begin_define
define|#
directive|define
name|USED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Unaligned versions of basic types.
end_comment

begin_typedef
typedef|typedef
name|ALIGNED
argument_list|(
literal|1
argument_list|)
name|u16
name|uu16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ALIGNED
argument_list|(
literal|1
argument_list|)
name|u32
name|uu32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ALIGNED
argument_list|(
literal|1
argument_list|)
name|u64
name|uu64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ALIGNED
argument_list|(
literal|1
argument_list|)
name|s16
name|us16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ALIGNED
argument_list|(
literal|1
argument_list|)
name|s32
name|us32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ALIGNED
argument_list|(
literal|1
argument_list|)
name|s64
name|us64
typedef|;
end_typedef

begin_if
if|#
directive|if
name|SANITIZER_WINDOWS
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|DWORD
typedef|;
end_typedef

begin_comment
comment|// NOLINT
end_comment

begin_typedef
typedef|typedef
name|DWORD
name|thread_return_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|THREAD_CALLING_CONV
value|__stdcall
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// _WIN32
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|thread_return_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|THREAD_CALLING_CONV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _WIN32
end_comment

begin_typedef
typedef|typedef
name|thread_return_t
function_decl|(
name|THREAD_CALLING_CONV
modifier|*
name|thread_callback_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// NOTE: Functions below must be defined in each run-time.
end_comment

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
name|void
name|NORETURN
name|Die
parameter_list|()
function_decl|;
comment|// FIXME: No, this shouldn't be in the sanitizer interface.
name|SANITIZER_INTERFACE_ATTRIBUTE
name|void
name|NORETURN
name|CheckFailed
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|cond
parameter_list|,
name|u64
name|v1
parameter_list|,
name|u64
name|v2
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_comment
comment|// Check macro
end_comment

begin_define
define|#
directive|define
name|RAW_CHECK_MSG
parameter_list|(
name|expr
parameter_list|,
name|msg
parameter_list|)
value|do { \   if (UNLIKELY(!(expr))) { \     RawWrite(msg); \     Die(); \   } \ } while (0)
end_define

begin_define
define|#
directive|define
name|RAW_CHECK
parameter_list|(
name|expr
parameter_list|)
value|RAW_CHECK_MSG(expr, #expr)
end_define

begin_define
define|#
directive|define
name|CHECK_IMPL
parameter_list|(
name|c1
parameter_list|,
name|op
parameter_list|,
name|c2
parameter_list|)
define|\
value|do { \     __sanitizer::u64 v1 = (u64)(c1); \     __sanitizer::u64 v2 = (u64)(c2); \     if (UNLIKELY(!(v1 op v2))) \       __sanitizer::CheckFailed(__FILE__, __LINE__, \         "(" #c1 ") " #op " (" #c2 ")", v1, v2); \   } while (false)
end_define

begin_comment
unit|\
comment|/**/
end_comment

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|a
parameter_list|)
value|CHECK_IMPL((a), !=, 0)
end_define

begin_define
define|#
directive|define
name|CHECK_EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_IMPL((a), ==, (b))
end_define

begin_define
define|#
directive|define
name|CHECK_NE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_IMPL((a), !=, (b))
end_define

begin_define
define|#
directive|define
name|CHECK_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_IMPL((a),<,  (b))
end_define

begin_define
define|#
directive|define
name|CHECK_LE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_IMPL((a),<=, (b))
end_define

begin_define
define|#
directive|define
name|CHECK_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_IMPL((a),>,  (b))
end_define

begin_define
define|#
directive|define
name|CHECK_GE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_IMPL((a),>=, (b))
end_define

begin_if
if|#
directive|if
name|TSAN_DEBUG
end_if

begin_define
define|#
directive|define
name|DCHECK
parameter_list|(
name|a
parameter_list|)
value|CHECK(a)
end_define

begin_define
define|#
directive|define
name|DCHECK_EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_EQ(a, b)
end_define

begin_define
define|#
directive|define
name|DCHECK_NE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_NE(a, b)
end_define

begin_define
define|#
directive|define
name|DCHECK_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_LT(a, b)
end_define

begin_define
define|#
directive|define
name|DCHECK_LE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_LE(a, b)
end_define

begin_define
define|#
directive|define
name|DCHECK_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_GT(a, b)
end_define

begin_define
define|#
directive|define
name|DCHECK_GE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_GE(a, b)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DCHECK
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DCHECK_EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DCHECK_NE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DCHECK_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DCHECK_LE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DCHECK_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DCHECK_GE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UNREACHABLE
parameter_list|(
name|msg
parameter_list|)
value|do { \   CHECK(0&& msg); \   Die(); \ } while (0)
end_define

begin_define
define|#
directive|define
name|UNIMPLEMENTED
parameter_list|()
value|UNREACHABLE("unimplemented")
end_define

begin_define
define|#
directive|define
name|COMPILER_CHECK
parameter_list|(
name|pred
parameter_list|)
value|IMPL_COMPILER_ASSERT(pred, __LINE__)
end_define

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a)/sizeof((a)[0]))
end_define

begin_define
define|#
directive|define
name|IMPL_PASTE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
end_define

begin_define
define|#
directive|define
name|IMPL_COMPILER_ASSERT
parameter_list|(
name|pred
parameter_list|,
name|line
parameter_list|)
define|\
value|typedef char IMPL_PASTE(assertion_failed_##_, line)[2*(int)(pred)-1]
end_define

begin_comment
comment|// Limits for integral types. We have to redefine it in case we don't
end_comment

begin_comment
comment|// have stdint.h (like in Visual Studio 9).
end_comment

begin_undef
undef|#
directive|undef
name|__INT64_C
end_undef

begin_undef
undef|#
directive|undef
name|__UINT64_C
end_undef

begin_if
if|#
directive|if
name|SANITIZER_WORDSIZE
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|__INT64_C
parameter_list|(
name|c
parameter_list|)
value|c ## L
end_define

begin_define
define|#
directive|define
name|__UINT64_C
parameter_list|(
name|c
parameter_list|)
value|c ## UL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__INT64_C
parameter_list|(
name|c
parameter_list|)
value|c ## LL
end_define

begin_define
define|#
directive|define
name|__UINT64_C
parameter_list|(
name|c
parameter_list|)
value|c ## ULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_WORDSIZE == 64
end_comment

begin_undef
undef|#
directive|undef
name|INT32_MIN
end_undef

begin_define
define|#
directive|define
name|INT32_MIN
value|(-2147483647-1)
end_define

begin_undef
undef|#
directive|undef
name|INT32_MAX
end_undef

begin_define
define|#
directive|define
name|INT32_MAX
value|(2147483647)
end_define

begin_undef
undef|#
directive|undef
name|UINT32_MAX
end_undef

begin_define
define|#
directive|define
name|UINT32_MAX
value|(4294967295U)
end_define

begin_undef
undef|#
directive|undef
name|INT64_MIN
end_undef

begin_define
define|#
directive|define
name|INT64_MIN
value|(-__INT64_C(9223372036854775807)-1)
end_define

begin_undef
undef|#
directive|undef
name|INT64_MAX
end_undef

begin_define
define|#
directive|define
name|INT64_MAX
value|(__INT64_C(9223372036854775807))
end_define

begin_undef
undef|#
directive|undef
name|UINT64_MAX
end_undef

begin_define
define|#
directive|define
name|UINT64_MAX
value|(__UINT64_C(18446744073709551615))
end_define

begin_enum
enum|enum
name|LinkerInitialized
block|{
name|LINKER_INITIALIZED
init|=
literal|0
block|}
enum|;
end_enum

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_define
define|#
directive|define
name|GET_CALLER_PC
parameter_list|()
value|(uptr)__builtin_return_address(0)
end_define

begin_define
define|#
directive|define
name|GET_CURRENT_FRAME
parameter_list|()
value|(uptr)__builtin_frame_address(0)
end_define

begin_else
else|#
directive|else
end_else

begin_extern
extern|extern
literal|"C"
name|void
modifier|*
name|_ReturnAddress
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_extern

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_ReturnAddress
name|)
end_pragma

begin_define
define|#
directive|define
name|GET_CALLER_PC
parameter_list|()
value|(uptr)_ReturnAddress()
end_define

begin_comment
comment|// CaptureStackBackTrace doesn't need to know BP on Windows.
end_comment

begin_comment
comment|// FIXME: This macro is still used when printing error reports though it's not
end_comment

begin_comment
comment|// clear if the BP value is needed in the ASan reports on Windows.
end_comment

begin_define
define|#
directive|define
name|GET_CURRENT_FRAME
parameter_list|()
value|(uptr)0xDEADBEEF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HANDLE_EINTR
parameter_list|(
name|res
parameter_list|,
name|f
parameter_list|)
define|\
value|{                                                                \     int rverrno;                                                   \     do {                                                           \       res = (f);                                                   \     } while (internal_iserror(res,&rverrno)&& rverrno == EINTR); \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_DEFS_H
end_comment

end_unit

