begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_interceptors.h -------------------------------------*- C++ -*-===//
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
comment|// ASan-private header for asan_interceptors.cc
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_INTERCEPTORS_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_INTERCEPTORS_H
end_define

begin_include
include|#
directive|include
file|"asan_internal.h"
end_include

begin_comment
comment|// To replace weak system functions on Linux we just need to declare functions
end_comment

begin_comment
comment|// with same names in our library and then obtain the real function pointers
end_comment

begin_comment
comment|// using dlsym(). This is not so on Mac OS, where the two-level namespace makes
end_comment

begin_comment
comment|// our replacement functions invisible to other libraries. This may be overcomed
end_comment

begin_comment
comment|// using the DYLD_FORCE_FLAT_NAMESPACE, but some errors loading the shared
end_comment

begin_comment
comment|// libraries in Chromium were noticed when doing so.
end_comment

begin_comment
comment|// Instead we use mach_override, a handy framework for patching functions at
end_comment

begin_comment
comment|// runtime. To avoid possible name clashes, our replacement functions have
end_comment

begin_comment
comment|// the "wrap_" prefix on Mac.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// After interception, the calls to system functions will be substituted by
end_comment

begin_comment
comment|// calls to our interceptors. We store pointers to system function f()
end_comment

begin_comment
comment|// in __asan::real_f().
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TODO(glider): mach_override_ptr() tends to spend too much time
end_comment

begin_comment
comment|// in allocateBranchIsland(). This should be ok for real-word
end_comment

begin_comment
comment|// application, but slows down our tests which fork too many children.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_include
include|#
directive|include
file|"mach_override/mach_override.h"
end_include

begin_define
define|#
directive|define
name|WRAP
parameter_list|(
name|x
parameter_list|)
value|wrap_##x
end_define

begin_define
define|#
directive|define
name|WRAPPER_NAME
parameter_list|(
name|x
parameter_list|)
value|"wrap_"#x
end_define

begin_define
define|#
directive|define
name|OVERRIDE_FUNCTION
parameter_list|(
name|oldfunc
parameter_list|,
name|newfunc
parameter_list|)
define|\
value|CHECK(0 == __asan_mach_override_ptr((void*)(oldfunc),                        \                                       (void*)(newfunc),                        \                                       (void**)&real_##oldfunc));               \   CHECK(real_##oldfunc != NULL);
end_define

begin_define
define|#
directive|define
name|OVERRIDE_FUNCTION_IF_EXISTS
parameter_list|(
name|oldfunc
parameter_list|,
name|newfunc
parameter_list|)
define|\
value|do { __asan_mach_override_ptr((void*)(oldfunc),                              \                                 (void*)(newfunc),                              \                                 (void**)&real_##oldfunc); } while (0)
end_define

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION
parameter_list|(
name|func
parameter_list|)
define|\
value|OVERRIDE_FUNCTION(func, WRAP(func))
end_define

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_IF_EXISTS
parameter_list|(
name|func
parameter_list|)
define|\
value|OVERRIDE_FUNCTION_IF_EXISTS(func, WRAP(func))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// __linux__
end_comment

begin_define
define|#
directive|define
name|WRAP
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|WRAPPER_NAME
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION
parameter_list|(
name|func
parameter_list|)
define|\
value|CHECK((real_##func = (func##_f)dlsym(RTLD_NEXT, #func)));
end_define

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_IF_EXISTS
parameter_list|(
name|func
parameter_list|)
define|\
value|do { real_##func = (func##_f)dlsym(RTLD_NEXT, #func); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_function_decl
name|int
name|WRAP
function_decl|(
name|memcmp
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
specifier|const
name|void
modifier|*
name|a2
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|WRAP
function_decl|(
name|memcpy
function_decl|)
parameter_list|(
name|void
modifier|*
name|to
parameter_list|,
specifier|const
name|void
modifier|*
name|from
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|WRAP
function_decl|(
name|memmove
function_decl|)
parameter_list|(
name|void
modifier|*
name|to
parameter_list|,
specifier|const
name|void
modifier|*
name|from
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|WRAP
function_decl|(
name|memset
function_decl|)
parameter_list|(
name|void
modifier|*
name|block
parameter_list|,
name|int
name|c
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|WRAP
function_decl|(
name|strcasecmp
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|WRAP
function_decl|(
name|strcat
function_decl|)
parameter_list|(
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// NOLINT
end_comment

begin_function_decl
name|char
modifier|*
name|WRAP
function_decl|(
name|strchr
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|WRAP
function_decl|(
name|strcmp
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|WRAP
function_decl|(
name|strcpy
function_decl|)
parameter_list|(
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// NOLINT
end_comment

begin_function_decl
name|char
modifier|*
name|WRAP
function_decl|(
name|strdup
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|WRAP
function_decl|(
name|strlen
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|WRAP
function_decl|(
name|strncasecmp
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|WRAP
function_decl|(
name|strncmp
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|WRAP
function_decl|(
name|strncpy
function_decl|)
parameter_list|(
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|__asan
block|{
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|index_f
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|memcmp_f
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
specifier|const
name|void
modifier|*
name|a2
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|memcpy_f
function_decl|)
parameter_list|(
name|void
modifier|*
name|to
parameter_list|,
specifier|const
name|void
modifier|*
name|from
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|memmove_f
function_decl|)
parameter_list|(
name|void
modifier|*
name|to
parameter_list|,
specifier|const
name|void
modifier|*
name|from
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|memset_f
function_decl|)
parameter_list|(
name|void
modifier|*
name|block
parameter_list|,
name|int
name|c
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|strcasecmp_f
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|strcat_f
function_decl|)
parameter_list|(
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|)
function_decl|;
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|strchr_f
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|strcmp_f
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|strcpy_f
function_decl|)
parameter_list|(
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|)
function_decl|;
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|strdup_f
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
typedef|typedef
name|size_t
function_decl|(
modifier|*
name|strlen_f
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|strncasecmp_f
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|strncmp_f
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|strncpy_f
function_decl|)
parameter_list|(
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
typedef|typedef
name|size_t
function_decl|(
modifier|*
name|strnlen_f
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|maxlen
parameter_list|)
function_decl|;
comment|// __asan::real_X() holds pointer to library implementation of X().
specifier|extern
name|index_f
name|real_index
decl_stmt|;
specifier|extern
name|memcmp_f
name|real_memcmp
decl_stmt|;
specifier|extern
name|memcpy_f
name|real_memcpy
decl_stmt|;
specifier|extern
name|memmove_f
name|real_memmove
decl_stmt|;
specifier|extern
name|memset_f
name|real_memset
decl_stmt|;
specifier|extern
name|strcasecmp_f
name|real_strcasecmp
decl_stmt|;
specifier|extern
name|strcat_f
name|real_strcat
decl_stmt|;
specifier|extern
name|strchr_f
name|real_strchr
decl_stmt|;
specifier|extern
name|strcmp_f
name|real_strcmp
decl_stmt|;
specifier|extern
name|strcpy_f
name|real_strcpy
decl_stmt|;
specifier|extern
name|strdup_f
name|real_strdup
decl_stmt|;
specifier|extern
name|strlen_f
name|real_strlen
decl_stmt|;
specifier|extern
name|strncasecmp_f
name|real_strncasecmp
decl_stmt|;
specifier|extern
name|strncmp_f
name|real_strncmp
decl_stmt|;
specifier|extern
name|strncpy_f
name|real_strncpy
decl_stmt|;
specifier|extern
name|strnlen_f
name|real_strnlen
decl_stmt|;
comment|// __asan::internal_X() is the implementation of X() for use in RTL.
name|size_t
name|internal_strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
name|size_t
name|internal_strnlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|maxlen
parameter_list|)
function_decl|;
name|void
modifier|*
name|internal_memchr
parameter_list|(
specifier|const
name|void
modifier|*
name|s
parameter_list|,
name|int
name|c
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
name|int
name|internal_memcmp
parameter_list|(
specifier|const
name|void
modifier|*
name|s1
parameter_list|,
specifier|const
name|void
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
comment|// Initializes pointers to str*/mem* functions.
name|void
name|InitializeAsanInterceptors
parameter_list|()
function_decl|;
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
comment|// ASAN_INTERCEPTORS_H
end_comment

end_unit

