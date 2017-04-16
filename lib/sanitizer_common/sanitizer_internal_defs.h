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

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_DEBUG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Only use SANITIZER_*ATTRIBUTE* before the function return type!
end_comment

begin_if
if|#
directive|if
name|SANITIZER_WINDOWS
end_if

begin_if
if|#
directive|if
name|SANITIZER_IMPORT_INTERFACE
end_if

begin_define
define|#
directive|define
name|SANITIZER_INTERFACE_ATTRIBUTE
value|__declspec(dllimport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_INTERFACE_ATTRIBUTE
value|__declspec(dllexport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SANITIZER_WEAK_ATTRIBUTE
end_define

begin_elif
elif|#
directive|elif
name|SANITIZER_GO
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

begin_comment
comment|//--------------------------- WEAK FUNCTIONS ---------------------------------//
end_comment

begin_comment
comment|// When working with weak functions, to simplify the code and make it more
end_comment

begin_comment
comment|// portable, when possible define a default implementation using this macro:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SANITIZER_INTERFACE_WEAK_DEF(<return_type>,<name>,<parameter list>)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For example:
end_comment

begin_comment
comment|//   SANITIZER_INTERFACE_WEAK_DEF(bool, compare, int a, int b) { return a> b; }
end_comment

begin_comment
comment|//
end_comment

begin_if
if|#
directive|if
name|SANITIZER_WINDOWS
end_if

begin_include
include|#
directive|include
file|"sanitizer_win_defs.h"
end_include

begin_define
define|#
directive|define
name|SANITIZER_INTERFACE_WEAK_DEF
parameter_list|(
name|ReturnType
parameter_list|,
name|Name
parameter_list|,
modifier|...
parameter_list|)
define|\
value|WIN_WEAK_EXPORT_DEF(ReturnType, Name, __VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SANITIZER_INTERFACE_WEAK_DEF
parameter_list|(
name|ReturnType
parameter_list|,
name|Name
parameter_list|,
modifier|...
parameter_list|)
define|\
value|extern "C" SANITIZER_INTERFACE_ATTRIBUTE SANITIZER_WEAK_ATTRIBUTE            \   ReturnType Name(__VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_SUPPORTS_WEAK_HOOKS means that we support real weak functions that
end_comment

begin_comment
comment|// will evaluate to a null pointer when not defined.
end_comment

begin_if
if|#
directive|if
operator|(
name|SANITIZER_LINUX
operator|||
name|SANITIZER_MAC
operator|)
operator|&&
operator|!
name|SANITIZER_GO
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
comment|// For some weak hooks that will be called very often and we want to avoid the
end_comment

begin_comment
comment|// overhead of executing the default implementation when it is not necessary,
end_comment

begin_comment
comment|// we can use the flag SANITIZER_SUPPORTS_WEAK_HOOKS to only define the default
end_comment

begin_comment
comment|// implementation for platforms that doesn't support weak symbols. For example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   #if !SANITIZER_SUPPORT_WEAK_HOOKS
end_comment

begin_comment
comment|//     SANITIZER_INTERFACE_WEAK_DEF(bool, compare_hook, int a, int b) {
end_comment

begin_comment
comment|//       return a> b;
end_comment

begin_comment
comment|//     }
end_comment

begin_comment
comment|//   #endif
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// And then use it as: if (compare_hook) compare_hook(a, b);
end_comment

begin_comment
comment|//----------------------------------------------------------------------------//
end_comment

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
if|#
directive|if
name|SANITIZER_WINDOWS
comment|// On Windows, files are HANDLE, which is a synonim of void*.
comment|// Use void* to avoid including<windows.h> everywhere.
typedef|typedef
name|void
modifier|*
name|fd_t
typedef|;
typedef|typedef
name|unsigned
name|error_t
typedef|;
else|#
directive|else
typedef|typedef
name|int
name|fd_t
typedef|;
typedef|typedef
name|int
name|error_t
typedef|;
endif|#
directive|endif
typedef|typedef
name|int
name|pid_t
typedef|;
comment|// WARNING: OFF_T may be different from OS type off_t, depending on the value of
comment|// _FILE_OFFSET_BITS. This definition of OFF_T matches the ABI of system calls
comment|// like pread and mmap, as opposed to pread64 and mmap64.
comment|// FreeBSD, Mac and Linux/x86-64 are special.
if|#
directive|if
name|SANITIZER_FREEBSD
operator|||
name|SANITIZER_MAC
operator|||
expr|\
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
if|#
directive|if
name|defined
argument_list|(
name|__s390__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__s390x__
argument_list|)
comment|// Special case: 31-bit s390 has unsigned long as size_t.
typedef|typedef
name|unsigned
name|long
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
endif|#
directive|endif
comment|// ----------- ATTENTION -------------
comment|// This header should NOT include any other headers to avoid portability issues.
comment|// Common defs.
define|#
directive|define
name|INLINE
value|inline
define|#
directive|define
name|INTERFACE_ATTRIBUTE
value|SANITIZER_INTERFACE_ATTRIBUTE
define|#
directive|define
name|SANITIZER_WEAK_DEFAULT_IMPL
define|\
value|extern "C" SANITIZER_INTERFACE_ATTRIBUTE SANITIZER_WEAK_ATTRIBUTE NOINLINE
define|#
directive|define
name|SANITIZER_WEAK_CXX_DEFAULT_IMPL
define|\
value|extern "C++" SANITIZER_INTERFACE_ATTRIBUTE SANITIZER_WEAK_ATTRIBUTE NOINLINE
comment|// Platform-specific defs.
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
define|#
directive|define
name|ALWAYS_INLINE
value|__forceinline
comment|// FIXME(timurrrr): do we need this on Windows?
define|#
directive|define
name|ALIAS
parameter_list|(
name|x
parameter_list|)
define|#
directive|define
name|ALIGNED
parameter_list|(
name|x
parameter_list|)
value|__declspec(align(x))
define|#
directive|define
name|FORMAT
parameter_list|(
name|f
parameter_list|,
name|a
parameter_list|)
define|#
directive|define
name|NOINLINE
value|__declspec(noinline)
define|#
directive|define
name|NORETURN
value|__declspec(noreturn)
define|#
directive|define
name|THREADLOCAL
value|__declspec(thread)
define|#
directive|define
name|LIKELY
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|UNLIKELY
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|PREFETCH
parameter_list|(
name|x
parameter_list|)
comment|/* _mm_prefetch(x, _MM_HINT_NTA) */
value|(void)0
else|#
directive|else
comment|// _MSC_VER
define|#
directive|define
name|ALWAYS_INLINE
value|inline __attribute__((always_inline))
define|#
directive|define
name|ALIAS
parameter_list|(
name|x
parameter_list|)
value|__attribute__((alias(x)))
comment|// Please only use the ALIGNED macro before the type.
comment|// Using ALIGNED after the variable declaration is not portable!
define|#
directive|define
name|ALIGNED
parameter_list|(
name|x
parameter_list|)
value|__attribute__((aligned(x)))
define|#
directive|define
name|FORMAT
parameter_list|(
name|f
parameter_list|,
name|a
parameter_list|)
value|__attribute__((format(printf, f, a)))
define|#
directive|define
name|NOINLINE
value|__attribute__((noinline))
define|#
directive|define
name|NORETURN
value|__attribute__((noreturn))
define|#
directive|define
name|THREADLOCAL
value|__thread
define|#
directive|define
name|LIKELY
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 1)
define|#
directive|define
name|UNLIKELY
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 0)
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
comment|// __builtin_prefetch(x) generates prefetchnt0 on x86
define|#
directive|define
name|PREFETCH
parameter_list|(
name|x
parameter_list|)
value|__asm__("prefetchnta (%0)" : : "r" (x))
else|#
directive|else
define|#
directive|define
name|PREFETCH
parameter_list|(
name|x
parameter_list|)
value|__builtin_prefetch(x)
endif|#
directive|endif
endif|#
directive|endif
comment|// _MSC_VER
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
define|#
directive|define
name|UNUSED
value|__attribute__((unused))
define|#
directive|define
name|USED
value|__attribute__((used))
else|#
directive|else
define|#
directive|define
name|UNUSED
define|#
directive|define
name|USED
endif|#
directive|endif
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
operator|||
name|MSC_PREREQ
argument_list|(
literal|1900
argument_list|)
define|#
directive|define
name|NOEXCEPT
value|noexcept
else|#
directive|else
define|#
directive|define
name|NOEXCEPT
value|throw()
endif|#
directive|endif
comment|// Unaligned versions of basic types.
typedef|typedef
name|ALIGNED
argument_list|(
literal|1
argument_list|)
name|u16
name|uu16
typedef|;
typedef|typedef
name|ALIGNED
argument_list|(
literal|1
argument_list|)
name|u32
name|uu32
typedef|;
typedef|typedef
name|ALIGNED
argument_list|(
literal|1
argument_list|)
name|u64
name|uu64
typedef|;
typedef|typedef
name|ALIGNED
argument_list|(
literal|1
argument_list|)
name|s16
name|us16
typedef|;
typedef|typedef
name|ALIGNED
argument_list|(
literal|1
argument_list|)
name|s32
name|us32
typedef|;
typedef|typedef
name|ALIGNED
argument_list|(
literal|1
argument_list|)
name|s64
name|us64
typedef|;
if|#
directive|if
name|SANITIZER_WINDOWS
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

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

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
typedef|typedef
name|DWORD
name|thread_return_t
typedef|;
define|#
directive|define
name|THREAD_CALLING_CONV
value|__stdcall
else|#
directive|else
comment|// _WIN32
typedef|typedef
name|void
modifier|*
name|thread_return_t
typedef|;
define|#
directive|define
name|THREAD_CALLING_CONV
endif|#
directive|endif
comment|// _WIN32
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
comment|// NOTE: Functions below must be defined in each run-time.
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
comment|// Check macro
define|#
directive|define
name|RAW_CHECK_MSG
parameter_list|(
name|expr
parameter_list|,
name|msg
parameter_list|)
value|do { \   if (UNLIKELY(!(expr))) { \     RawWrite(msg); \     Die(); \   } \ } while (0)
define|#
directive|define
name|RAW_CHECK
parameter_list|(
name|expr
parameter_list|)
value|RAW_CHECK_MSG(expr, #expr)
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
block|\
comment|/**/
define|#
directive|define
name|CHECK
parameter_list|(
name|a
parameter_list|)
value|CHECK_IMPL((a), !=, 0)
define|#
directive|define
name|CHECK_EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_IMPL((a), ==, (b))
define|#
directive|define
name|CHECK_NE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_IMPL((a), !=, (b))
define|#
directive|define
name|CHECK_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_IMPL((a),<,  (b))
define|#
directive|define
name|CHECK_LE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_IMPL((a),<=, (b))
define|#
directive|define
name|CHECK_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_IMPL((a),>,  (b))
define|#
directive|define
name|CHECK_GE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_IMPL((a),>=, (b))
if|#
directive|if
name|SANITIZER_DEBUG
define|#
directive|define
name|DCHECK
parameter_list|(
name|a
parameter_list|)
value|CHECK(a)
define|#
directive|define
name|DCHECK_EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_EQ(a, b)
define|#
directive|define
name|DCHECK_NE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_NE(a, b)
define|#
directive|define
name|DCHECK_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_LT(a, b)
define|#
directive|define
name|DCHECK_LE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_LE(a, b)
define|#
directive|define
name|DCHECK_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_GT(a, b)
define|#
directive|define
name|DCHECK_GE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CHECK_GE(a, b)
else|#
directive|else
define|#
directive|define
name|DCHECK
parameter_list|(
name|a
parameter_list|)
define|#
directive|define
name|DCHECK_EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|#
directive|define
name|DCHECK_NE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|#
directive|define
name|DCHECK_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|#
directive|define
name|DCHECK_LE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|#
directive|define
name|DCHECK_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|#
directive|define
name|DCHECK_GE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
endif|#
directive|endif
define|#
directive|define
name|UNREACHABLE
parameter_list|(
name|msg
parameter_list|)
value|do { \   CHECK(0&& msg); \   Die(); \ } while (0)
define|#
directive|define
name|UNIMPLEMENTED
parameter_list|()
value|UNREACHABLE("unimplemented")
define|#
directive|define
name|COMPILER_CHECK
parameter_list|(
name|pred
parameter_list|)
value|IMPL_COMPILER_ASSERT(pred, __LINE__)
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a)/sizeof((a)[0]))
define|#
directive|define
name|IMPL_PASTE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
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
comment|// Limits for integral types. We have to redefine it in case we don't
comment|// have stdint.h (like in Visual Studio 9).
undef|#
directive|undef
name|__INT64_C
undef|#
directive|undef
name|__UINT64_C
if|#
directive|if
name|SANITIZER_WORDSIZE
operator|==
literal|64
define|#
directive|define
name|__INT64_C
parameter_list|(
name|c
parameter_list|)
value|c ## L
define|#
directive|define
name|__UINT64_C
parameter_list|(
name|c
parameter_list|)
value|c ## UL
else|#
directive|else
define|#
directive|define
name|__INT64_C
parameter_list|(
name|c
parameter_list|)
value|c ## LL
define|#
directive|define
name|__UINT64_C
parameter_list|(
name|c
parameter_list|)
value|c ## ULL
endif|#
directive|endif
comment|// SANITIZER_WORDSIZE == 64
undef|#
directive|undef
name|INT32_MIN
define|#
directive|define
name|INT32_MIN
value|(-2147483647-1)
undef|#
directive|undef
name|INT32_MAX
define|#
directive|define
name|INT32_MAX
value|(2147483647)
undef|#
directive|undef
name|UINT32_MAX
define|#
directive|define
name|UINT32_MAX
value|(4294967295U)
undef|#
directive|undef
name|INT64_MIN
define|#
directive|define
name|INT64_MIN
value|(-__INT64_C(9223372036854775807)-1)
undef|#
directive|undef
name|INT64_MAX
define|#
directive|define
name|INT64_MAX
value|(__INT64_C(9223372036854775807))
undef|#
directive|undef
name|UINT64_MAX
define|#
directive|define
name|UINT64_MAX
value|(__UINT64_C(18446744073709551615))
enum|enum
name|LinkerInitialized
block|{
name|LINKER_INITIALIZED
init|=
literal|0
block|}
enum|;
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
if|#
directive|if
name|SANITIZER_S390_31
define|#
directive|define
name|GET_CALLER_PC
parameter_list|()
define|\
value|(__sanitizer::uptr) __builtin_extract_return_addr(__builtin_return_address(0))
else|#
directive|else
define|#
directive|define
name|GET_CALLER_PC
parameter_list|()
value|(__sanitizer::uptr) __builtin_return_address(0)
endif|#
directive|endif
define|#
directive|define
name|GET_CURRENT_FRAME
parameter_list|()
value|(__sanitizer::uptr) __builtin_frame_address(0)
specifier|inline
name|void
name|Trap
parameter_list|()
block|{
name|__builtin_trap
argument_list|()
expr_stmt|;
block|}
else|#
directive|else
extern|extern
literal|"C"
name|void
modifier|*
name|_ReturnAddress
parameter_list|(
name|void
parameter_list|)
function_decl|;
extern|extern
literal|"C"
name|void
modifier|*
name|_AddressOfReturnAddress
parameter_list|(
name|void
parameter_list|)
function_decl|;
pragma|#
directive|pragma
name|intrinsic
name|(
name|_ReturnAddress
name|)
pragma|#
directive|pragma
name|intrinsic
name|(
name|_AddressOfReturnAddress
name|)
define|#
directive|define
name|GET_CALLER_PC
parameter_list|()
value|(__sanitizer::uptr) _ReturnAddress()
comment|// CaptureStackBackTrace doesn't need to know BP on Windows.
define|#
directive|define
name|GET_CURRENT_FRAME
parameter_list|()
define|\
value|(((__sanitizer::uptr)_AddressOfReturnAddress()) + sizeof(__sanitizer::uptr))
extern|extern
literal|"C"
name|void
name|__ud2
parameter_list|(
name|void
parameter_list|)
function_decl|;
pragma|#
directive|pragma
name|intrinsic
name|(
name|__ud2
name|)
specifier|inline
name|void
name|Trap
parameter_list|()
block|{
name|__ud2
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
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
comment|// Forces the compiler to generate a frame pointer in the function.
define|#
directive|define
name|ENABLE_FRAME_POINTER
define|\
value|do {                                    \     volatile __sanitizer::uptr enable_fp; \     enable_fp = GET_CURRENT_FRAME();      \     (void)enable_fp;                      \   } while (0)
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_decl_stmt
name|namespace
name|__asan
block|{
name|using
name|namespace
name|__sanitizer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// NOLINT
end_comment

begin_decl_stmt
name|namespace
name|__dsan
block|{
name|using
name|namespace
name|__sanitizer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// NOLINT
end_comment

begin_decl_stmt
name|namespace
name|__dfsan
block|{
name|using
name|namespace
name|__sanitizer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// NOLINT
end_comment

begin_decl_stmt
name|namespace
name|__esan
block|{
name|using
name|namespace
name|__sanitizer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// NOLINT
end_comment

begin_decl_stmt
name|namespace
name|__lsan
block|{
name|using
name|namespace
name|__sanitizer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// NOLINT
end_comment

begin_decl_stmt
name|namespace
name|__msan
block|{
name|using
name|namespace
name|__sanitizer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// NOLINT
end_comment

begin_decl_stmt
name|namespace
name|__tsan
block|{
name|using
name|namespace
name|__sanitizer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// NOLINT
end_comment

begin_decl_stmt
name|namespace
name|__scudo
block|{
name|using
name|namespace
name|__sanitizer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// NOLINT
end_comment

begin_decl_stmt
name|namespace
name|__ubsan
block|{
name|using
name|namespace
name|__sanitizer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// NOLINT
end_comment

begin_decl_stmt
name|namespace
name|__xray
block|{
name|using
name|namespace
name|__sanitizer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// NOLINT
end_comment

begin_decl_stmt
name|namespace
name|__interception
block|{
name|using
name|namespace
name|__sanitizer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// NOLINT
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_DEFS_H
end_comment

end_unit

