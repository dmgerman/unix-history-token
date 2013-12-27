begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- ittnotify_config.h - JIT Profiling API internal config-----*- C -*-===*  *  *                     The LLVM Compiler Infrastructure  *  * This file is distributed under the University of Illinois Open Source  * License. See LICENSE.TXT for details.  *  *===----------------------------------------------------------------------===*  *  * This file provides Intel(R) Performance Analyzer JIT (Just-In-Time)   * Profiling API internal config.  *  * NOTE: This file comes in a style different from the rest of LLVM  * source base since  this is a piece of code shared from Intel(R)  * products.  Please do not reformat / re-style this code to make  * subsequent merges and contributions from the original source base eaiser.  *  *===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ITTNOTIFY_CONFIG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ITTNOTIFY_CONFIG_H_
end_define

begin_comment
comment|/** @cond exclude_from_documentation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITT_OS_WIN
end_ifndef

begin_define
define|#
directive|define
name|ITT_OS_WIN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_OS_WIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITT_OS_LINUX
end_ifndef

begin_define
define|#
directive|define
name|ITT_OS_LINUX
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_OS_LINUX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITT_OS_MAC
end_ifndef

begin_define
define|#
directive|define
name|ITT_OS_MAC
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_OS_MAC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITT_OS
end_ifndef

begin_if
if|#
directive|if
name|defined
name|WIN32
operator|||
name|defined
name|_WIN32
end_if

begin_define
define|#
directive|define
name|ITT_OS
value|ITT_OS_WIN
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__MACH__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ITT_OS
value|ITT_OS_MAC
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ITT_OS
value|ITT_OS_LINUX
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
comment|/* ITT_OS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITT_PLATFORM_WIN
end_ifndef

begin_define
define|#
directive|define
name|ITT_PLATFORM_WIN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_PLATFORM_WIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITT_PLATFORM_POSIX
end_ifndef

begin_define
define|#
directive|define
name|ITT_PLATFORM_POSIX
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_PLATFORM_POSIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITT_PLATFORM
end_ifndef

begin_if
if|#
directive|if
name|ITT_OS
operator|==
name|ITT_OS_WIN
end_if

begin_define
define|#
directive|define
name|ITT_PLATFORM
value|ITT_PLATFORM_WIN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ITT_PLATFORM
value|ITT_PLATFORM_POSIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WIN32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_PLATFORM */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_UNICODE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|UNICODE
argument_list|)
end_if

begin_define
define|#
directive|define
name|UNICODE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_if
if|#
directive|if
name|ITT_PLATFORM
operator|==
name|ITT_PLATFORM_WIN
end_if

begin_include
include|#
directive|include
file|<tchar.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ITT_PLATFORM==ITT_PLATFORM_WIN */
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UNICODE
argument_list|)
operator|||
name|defined
argument_list|(
name|_UNICODE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNICODE || _UNICODE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_PLATFORM==ITT_PLATFORM_WIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CDECL
end_ifndef

begin_if
if|#
directive|if
name|ITT_PLATFORM
operator|==
name|ITT_PLATFORM_WIN
end_if

begin_define
define|#
directive|define
name|CDECL
value|__cdecl
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ITT_PLATFORM==ITT_PLATFORM_WIN */
end_comment

begin_if
if|#
directive|if
name|defined
name|_M_X64
operator|||
name|defined
name|_M_AMD64
operator|||
name|defined
name|__x86_64__
end_if

begin_define
define|#
directive|define
name|CDECL
end_define

begin_comment
comment|/* not actual on x86_64 platform */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _M_X64 || _M_AMD64 || __x86_64__ */
end_comment

begin_define
define|#
directive|define
name|CDECL
value|__attribute__ ((cdecl))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _M_X64 || _M_AMD64 || __x86_64__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_PLATFORM==ITT_PLATFORM_WIN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CDECL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDCALL
end_ifndef

begin_if
if|#
directive|if
name|ITT_PLATFORM
operator|==
name|ITT_PLATFORM_WIN
end_if

begin_define
define|#
directive|define
name|STDCALL
value|__stdcall
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ITT_PLATFORM==ITT_PLATFORM_WIN */
end_comment

begin_if
if|#
directive|if
name|defined
name|_M_X64
operator|||
name|defined
name|_M_AMD64
operator|||
name|defined
name|__x86_64__
end_if

begin_define
define|#
directive|define
name|STDCALL
end_define

begin_comment
comment|/* not supported on x86_64 platform */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _M_X64 || _M_AMD64 || __x86_64__ */
end_comment

begin_define
define|#
directive|define
name|STDCALL
value|__attribute__ ((stdcall))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _M_X64 || _M_AMD64 || __x86_64__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_PLATFORM==ITT_PLATFORM_WIN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STDCALL */
end_comment

begin_define
define|#
directive|define
name|ITTAPI
value|CDECL
end_define

begin_define
define|#
directive|define
name|LIBITTAPI
value|CDECL
end_define

begin_comment
comment|/* TODO: Temporary for compatibility! */
end_comment

begin_define
define|#
directive|define
name|ITTAPI_CALL
value|CDECL
end_define

begin_define
define|#
directive|define
name|LIBITTAPI_CALL
value|CDECL
end_define

begin_if
if|#
directive|if
name|ITT_PLATFORM
operator|==
name|ITT_PLATFORM_WIN
end_if

begin_comment
comment|/* use __forceinline (VC++ specific) */
end_comment

begin_define
define|#
directive|define
name|ITT_INLINE
value|__forceinline
end_define

begin_define
define|#
directive|define
name|ITT_INLINE_ATTRIBUTE
end_define

begin_comment
comment|/* nothing */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ITT_PLATFORM==ITT_PLATFORM_WIN */
end_comment

begin_comment
comment|/*  * Generally, functions are not inlined unless optimization is specified.  * For functions declared inline, this attribute inlines the function even  * if no optimization level was specified.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STRICT_ANSI__
end_ifdef

begin_define
define|#
directive|define
name|ITT_INLINE
value|static
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STRICT_ANSI__ */
end_comment

begin_define
define|#
directive|define
name|ITT_INLINE
value|static inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STRICT_ANSI__ */
end_comment

begin_define
define|#
directive|define
name|ITT_INLINE_ATTRIBUTE
value|__attribute__ ((always_inline))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_PLATFORM==ITT_PLATFORM_WIN */
end_comment

begin_comment
comment|/** @endcond */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITT_ARCH_IA32
end_ifndef

begin_define
define|#
directive|define
name|ITT_ARCH_IA32
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_ARCH_IA32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITT_ARCH_IA32E
end_ifndef

begin_define
define|#
directive|define
name|ITT_ARCH_IA32E
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_ARCH_IA32E */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITT_ARCH_IA64
end_ifndef

begin_define
define|#
directive|define
name|ITT_ARCH_IA64
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_ARCH_IA64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITT_ARCH
end_ifndef

begin_if
if|#
directive|if
name|defined
name|_M_X64
operator|||
name|defined
name|_M_AMD64
operator|||
name|defined
name|__x86_64__
end_if

begin_define
define|#
directive|define
name|ITT_ARCH
value|ITT_ARCH_IA32E
end_define

begin_elif
elif|#
directive|elif
name|defined
name|_M_IA64
operator|||
name|defined
name|__ia64
end_elif

begin_define
define|#
directive|define
name|ITT_ARCH
value|ITT_ARCH_IA64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ITT_ARCH
value|ITT_ARCH_IA32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|ITT_EXTERN_C
value|extern "C"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ITT_EXTERN_C
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_define
define|#
directive|define
name|ITT_TO_STR_AUX
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|ITT_TO_STR
parameter_list|(
name|x
parameter_list|)
value|ITT_TO_STR_AUX(x)
end_define

begin_define
define|#
directive|define
name|__ITT_BUILD_ASSERT
parameter_list|(
name|expr
parameter_list|,
name|suffix
parameter_list|)
value|do { \     static char __itt_build_check_##suffix[(expr) ? 1 : -1]; \     __itt_build_check_##suffix[0] = 0; \ } while(0)
end_define

begin_define
define|#
directive|define
name|_ITT_BUILD_ASSERT
parameter_list|(
name|expr
parameter_list|,
name|suffix
parameter_list|)
value|__ITT_BUILD_ASSERT((expr), suffix)
end_define

begin_define
define|#
directive|define
name|ITT_BUILD_ASSERT
parameter_list|(
name|expr
parameter_list|)
value|_ITT_BUILD_ASSERT((expr), __LINE__)
end_define

begin_define
define|#
directive|define
name|ITT_MAGIC
value|{ 0xED, 0xAB, 0xAB, 0xEC, 0x0D, 0xEE, 0xDA, 0x30 }
end_define

begin_comment
comment|/* Replace with snapshot date YYYYMMDD for promotion build. */
end_comment

begin_define
define|#
directive|define
name|API_VERSION_BUILD
value|20111111
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|API_VERSION_NUM
end_ifndef

begin_define
define|#
directive|define
name|API_VERSION_NUM
value|0.0.0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* API_VERSION_NUM */
end_comment

begin_define
define|#
directive|define
name|API_VERSION
value|"ITT-API-Version " ITT_TO_STR(API_VERSION_NUM) \                                 " (" ITT_TO_STR(API_VERSION_BUILD) ")"
end_define

begin_comment
comment|/* OS communication functions */
end_comment

begin_if
if|#
directive|if
name|ITT_PLATFORM
operator|==
name|ITT_PLATFORM_WIN
end_if

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_typedef
typedef|typedef
name|HMODULE
name|lib_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|DWORD
name|TIDT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CRITICAL_SECTION
name|mutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MUTEX_INITIALIZER
value|{ 0 }
end_define

begin_define
define|#
directive|define
name|strong_alias
parameter_list|(
name|name
parameter_list|,
name|aliasname
parameter_list|)
end_define

begin_comment
comment|/* empty for Windows */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ITT_PLATFORM==ITT_PLATFORM_WIN */
end_comment

begin_include
include|#
directive|include
file|<dlfcn.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UNICODE
argument_list|)
operator|||
name|defined
argument_list|(
name|_UNICODE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNICODE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_comment
comment|/* need for PTHREAD_MUTEX_RECURSIVE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GNU_SOURCE */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_typedef
typedef|typedef
name|void
modifier|*
name|lib_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_t
name|TIDT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|mutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MUTEX_INITIALIZER
value|PTHREAD_MUTEX_INITIALIZER
end_define

begin_define
define|#
directive|define
name|_strong_alias
parameter_list|(
name|name
parameter_list|,
name|aliasname
parameter_list|)
define|\
value|extern __typeof (name) aliasname __attribute__ ((alias (#name)));
end_define

begin_define
define|#
directive|define
name|strong_alias
parameter_list|(
name|name
parameter_list|,
name|aliasname
parameter_list|)
value|_strong_alias(name, aliasname)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_PLATFORM==ITT_PLATFORM_WIN */
end_comment

begin_if
if|#
directive|if
name|ITT_PLATFORM
operator|==
name|ITT_PLATFORM_WIN
end_if

begin_define
define|#
directive|define
name|__itt_get_proc
parameter_list|(
name|lib
parameter_list|,
name|name
parameter_list|)
value|GetProcAddress(lib, name)
end_define

begin_define
define|#
directive|define
name|__itt_mutex_init
parameter_list|(
name|mutex
parameter_list|)
value|InitializeCriticalSection(mutex)
end_define

begin_define
define|#
directive|define
name|__itt_mutex_lock
parameter_list|(
name|mutex
parameter_list|)
value|EnterCriticalSection(mutex)
end_define

begin_define
define|#
directive|define
name|__itt_mutex_unlock
parameter_list|(
name|mutex
parameter_list|)
value|LeaveCriticalSection(mutex)
end_define

begin_define
define|#
directive|define
name|__itt_load_lib
parameter_list|(
name|name
parameter_list|)
value|LoadLibraryA(name)
end_define

begin_define
define|#
directive|define
name|__itt_unload_lib
parameter_list|(
name|handle
parameter_list|)
value|FreeLibrary(handle)
end_define

begin_define
define|#
directive|define
name|__itt_system_error
parameter_list|()
value|(int)GetLastError()
end_define

begin_define
define|#
directive|define
name|__itt_fstrcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|lstrcmpA(s1, s2)
end_define

begin_define
define|#
directive|define
name|__itt_fstrlen
parameter_list|(
name|s
parameter_list|)
value|lstrlenA(s)
end_define

begin_define
define|#
directive|define
name|__itt_fstrcpyn
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|lstrcpynA(s1, s2, l)
end_define

begin_define
define|#
directive|define
name|__itt_fstrdup
parameter_list|(
name|s
parameter_list|)
value|_strdup(s)
end_define

begin_define
define|#
directive|define
name|__itt_thread_id
parameter_list|()
value|GetCurrentThreadId()
end_define

begin_define
define|#
directive|define
name|__itt_thread_yield
parameter_list|()
value|SwitchToThread()
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ITT_SIMPLE_INIT
end_ifndef

begin_decl_stmt
name|ITT_INLINE
name|long
name|__itt_interlocked_increment
argument_list|(
specifier|volatile
name|long
operator|*
name|ptr
argument_list|)
name|ITT_INLINE_ATTRIBUTE
decl_stmt|;
end_decl_stmt

begin_function
name|ITT_INLINE
name|long
name|__itt_interlocked_increment
parameter_list|(
specifier|volatile
name|long
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|InterlockedIncrement
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_SIMPLE_INIT */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ITT_PLATFORM!=ITT_PLATFORM_WIN */
end_comment

begin_define
define|#
directive|define
name|__itt_get_proc
parameter_list|(
name|lib
parameter_list|,
name|name
parameter_list|)
value|dlsym(lib, name)
end_define

begin_define
define|#
directive|define
name|__itt_mutex_init
parameter_list|(
name|mutex
parameter_list|)
value|{\     pthread_mutexattr_t mutex_attr;                                         \     int error_code = pthread_mutexattr_init(&mutex_attr);                   \     if (error_code)                                                         \         __itt_report_error(__itt_error_system, "pthread_mutexattr_init",    \                            error_code);                                     \     error_code = pthread_mutexattr_settype(&mutex_attr,                     \                                            PTHREAD_MUTEX_RECURSIVE);        \     if (error_code)                                                         \         __itt_report_error(__itt_error_system, "pthread_mutexattr_settype", \                            error_code);                                     \     error_code = pthread_mutex_init(mutex,&mutex_attr);                    \     if (error_code)                                                         \         __itt_report_error(__itt_error_system, "pthread_mutex_init",        \                            error_code);                                     \     error_code = pthread_mutexattr_destroy(&mutex_attr);                    \     if (error_code)                                                         \         __itt_report_error(__itt_error_system, "pthread_mutexattr_destroy", \                            error_code);                                     \ }
end_define

begin_define
define|#
directive|define
name|__itt_mutex_lock
parameter_list|(
name|mutex
parameter_list|)
value|pthread_mutex_lock(mutex)
end_define

begin_define
define|#
directive|define
name|__itt_mutex_unlock
parameter_list|(
name|mutex
parameter_list|)
value|pthread_mutex_unlock(mutex)
end_define

begin_define
define|#
directive|define
name|__itt_load_lib
parameter_list|(
name|name
parameter_list|)
value|dlopen(name, RTLD_LAZY)
end_define

begin_define
define|#
directive|define
name|__itt_unload_lib
parameter_list|(
name|handle
parameter_list|)
value|dlclose(handle)
end_define

begin_define
define|#
directive|define
name|__itt_system_error
parameter_list|()
value|errno
end_define

begin_define
define|#
directive|define
name|__itt_fstrcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|strcmp(s1, s2)
end_define

begin_define
define|#
directive|define
name|__itt_fstrlen
parameter_list|(
name|s
parameter_list|)
value|strlen(s)
end_define

begin_define
define|#
directive|define
name|__itt_fstrcpyn
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|strncpy(s1, s2, l)
end_define

begin_define
define|#
directive|define
name|__itt_fstrdup
parameter_list|(
name|s
parameter_list|)
value|strdup(s)
end_define

begin_define
define|#
directive|define
name|__itt_thread_id
parameter_list|()
value|pthread_self()
end_define

begin_define
define|#
directive|define
name|__itt_thread_yield
parameter_list|()
value|sched_yield()
end_define

begin_if
if|#
directive|if
name|ITT_ARCH
operator|==
name|ITT_ARCH_IA64
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__INTEL_COMPILER
end_ifdef

begin_define
define|#
directive|define
name|__TBB_machine_fetchadd4
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
value|__fetchadd4_acq((void *)addr, val)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __INTEL_COMPILER */
end_comment

begin_comment
comment|/* TODO: Add Support for not Intel compilers for IA64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INTEL_COMPILER */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ITT_ARCH!=ITT_ARCH_IA64 */
end_comment

begin_decl_stmt
name|ITT_INLINE
name|long
name|__TBB_machine_fetchadd4
argument_list|(
specifier|volatile
name|void
operator|*
name|ptr
argument_list|,
name|long
name|addend
argument_list|)
name|ITT_INLINE_ATTRIBUTE
decl_stmt|;
end_decl_stmt

begin_function
name|ITT_INLINE
name|long
name|__TBB_machine_fetchadd4
parameter_list|(
specifier|volatile
name|void
modifier|*
name|ptr
parameter_list|,
name|long
name|addend
parameter_list|)
block|{
name|long
name|result
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("lock\nxadd %0,%1"                           : "=r"(result),"=m"(*(long*)ptr)                           : "0"(addend), "m"(*(long*)ptr)                           : "memory");
return|return
name|result
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_ARCH==ITT_ARCH_IA64 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITT_SIMPLE_INIT
end_ifndef

begin_decl_stmt
name|ITT_INLINE
name|long
name|__itt_interlocked_increment
argument_list|(
specifier|volatile
name|long
operator|*
name|ptr
argument_list|)
name|ITT_INLINE_ATTRIBUTE
decl_stmt|;
end_decl_stmt

begin_function
name|ITT_INLINE
name|long
name|__itt_interlocked_increment
parameter_list|(
specifier|volatile
name|long
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|__TBB_machine_fetchadd4
argument_list|(
name|ptr
argument_list|,
literal|1
argument_list|)
operator|+
literal|1L
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_SIMPLE_INIT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITT_PLATFORM==ITT_PLATFORM_WIN */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|__itt_collection_normal
init|=
literal|0
block|,
name|__itt_collection_paused
init|=
literal|1
block|}
name|__itt_collection_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|__itt_thread_normal
init|=
literal|0
block|,
name|__itt_thread_ignored
init|=
literal|1
block|}
name|__itt_thread_state
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|8
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|___itt_thread_info
block|{
specifier|const
name|char
modifier|*
name|nameA
decl_stmt|;
comment|/*!< Copy of original name in ASCII. */
if|#
directive|if
name|defined
argument_list|(
name|UNICODE
argument_list|)
operator|||
name|defined
argument_list|(
name|_UNICODE
argument_list|)
specifier|const
name|wchar_t
modifier|*
name|nameW
decl_stmt|;
comment|/*!< Copy of original name in UNICODE. */
else|#
directive|else
comment|/* UNICODE || _UNICODE */
name|void
modifier|*
name|nameW
decl_stmt|;
endif|#
directive|endif
comment|/* UNICODE || _UNICODE */
name|TIDT
name|tid
decl_stmt|;
name|__itt_thread_state
name|state
decl_stmt|;
comment|/*!< Thread state (paused or normal) */
name|int
name|extra1
decl_stmt|;
comment|/*!< Reserved to the runtime */
name|void
modifier|*
name|extra2
decl_stmt|;
comment|/*!< Reserved to the runtime */
name|struct
name|___itt_thread_info
modifier|*
name|next
decl_stmt|;
block|}
name|__itt_thread_info
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"ittnotify_types.h"
end_include

begin_comment
comment|/* For __itt_group_id definition */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|___itt_api_info_20101001
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|void
modifier|*
modifier|*
name|func_ptr
decl_stmt|;
name|void
modifier|*
name|init_func
decl_stmt|;
name|__itt_group_id
name|group
decl_stmt|;
block|}
name|__itt_api_info_20101001
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|___itt_api_info
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|void
modifier|*
modifier|*
name|func_ptr
decl_stmt|;
name|void
modifier|*
name|init_func
decl_stmt|;
name|void
modifier|*
name|null_func
decl_stmt|;
name|__itt_group_id
name|group
decl_stmt|;
block|}
name|__itt_api_info
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|___itt_domain
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|___itt_string_handle
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|___itt_global
block|{
name|unsigned
name|char
name|magic
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|long
name|version_major
decl_stmt|;
name|unsigned
name|long
name|version_minor
decl_stmt|;
name|unsigned
name|long
name|version_build
decl_stmt|;
specifier|volatile
name|long
name|api_initialized
decl_stmt|;
specifier|volatile
name|long
name|mutex_initialized
decl_stmt|;
specifier|volatile
name|long
name|atomic_counter
decl_stmt|;
name|mutex_t
name|mutex
decl_stmt|;
name|lib_t
name|lib
decl_stmt|;
name|void
modifier|*
name|error_handler
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|dll_path_ptr
decl_stmt|;
name|__itt_api_info
modifier|*
name|api_list_ptr
decl_stmt|;
name|struct
name|___itt_global
modifier|*
name|next
decl_stmt|;
comment|/* Joinable structures below */
name|__itt_thread_info
modifier|*
name|thread_list
decl_stmt|;
name|struct
name|___itt_domain
modifier|*
name|domain_list
decl_stmt|;
name|struct
name|___itt_string_handle
modifier|*
name|string_list
decl_stmt|;
name|__itt_collection_state
name|state
decl_stmt|;
block|}
name|__itt_global
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_define
define|#
directive|define
name|NEW_THREAD_INFO_W
parameter_list|(
name|gptr
parameter_list|,
name|h
parameter_list|,
name|h_tail
parameter_list|,
name|t
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|{ \     h = (__itt_thread_info*)malloc(sizeof(__itt_thread_info)); \     if (h != NULL) { \         h->tid    = t; \         h->nameA  = NULL; \         h->nameW  = n ? _wcsdup(n) : NULL; \         h->state  = s; \         h->extra1 = 0;
comment|/* reserved */
value|\         h->extra2 = NULL;
comment|/* reserved */
value|\         h->next   = NULL; \         if (h_tail == NULL) \             (gptr)->thread_list = h; \         else \             h_tail->next = h; \     } \ }
end_define

begin_define
define|#
directive|define
name|NEW_THREAD_INFO_A
parameter_list|(
name|gptr
parameter_list|,
name|h
parameter_list|,
name|h_tail
parameter_list|,
name|t
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|{ \     h = (__itt_thread_info*)malloc(sizeof(__itt_thread_info)); \     if (h != NULL) { \         h->tid    = t; \         h->nameA  = n ? __itt_fstrdup(n) : NULL; \         h->nameW  = NULL; \         h->state  = s; \         h->extra1 = 0;
comment|/* reserved */
value|\         h->extra2 = NULL;
comment|/* reserved */
value|\         h->next   = NULL; \         if (h_tail == NULL) \             (gptr)->thread_list = h; \         else \             h_tail->next = h; \     } \ }
end_define

begin_define
define|#
directive|define
name|NEW_DOMAIN_W
parameter_list|(
name|gptr
parameter_list|,
name|h
parameter_list|,
name|h_tail
parameter_list|,
name|name
parameter_list|)
value|{ \     h = (__itt_domain*)malloc(sizeof(__itt_domain)); \     if (h != NULL) { \         h->flags  = 0;
comment|/* domain is disabled by default */
value|\         h->nameA  = NULL; \         h->nameW  = name ? _wcsdup(name) : NULL; \         h->extra1 = 0;
comment|/* reserved */
value|\         h->extra2 = NULL;
comment|/* reserved */
value|\         h->next   = NULL; \         if (h_tail == NULL) \             (gptr)->domain_list = h; \         else \             h_tail->next = h; \     } \ }
end_define

begin_define
define|#
directive|define
name|NEW_DOMAIN_A
parameter_list|(
name|gptr
parameter_list|,
name|h
parameter_list|,
name|h_tail
parameter_list|,
name|name
parameter_list|)
value|{ \     h = (__itt_domain*)malloc(sizeof(__itt_domain)); \     if (h != NULL) { \         h->flags  = 0;
comment|/* domain is disabled by default */
value|\         h->nameA  = name ? __itt_fstrdup(name) : NULL; \         h->nameW  = NULL; \         h->extra1 = 0;
comment|/* reserved */
value|\         h->extra2 = NULL;
comment|/* reserved */
value|\         h->next   = NULL; \         if (h_tail == NULL) \             (gptr)->domain_list = h; \         else \             h_tail->next = h; \     } \ }
end_define

begin_define
define|#
directive|define
name|NEW_STRING_HANDLE_W
parameter_list|(
name|gptr
parameter_list|,
name|h
parameter_list|,
name|h_tail
parameter_list|,
name|name
parameter_list|)
value|{ \     h = (__itt_string_handle*)malloc(sizeof(__itt_string_handle)); \     if (h != NULL) { \         h->strA   = NULL; \         h->strW   = name ? _wcsdup(name) : NULL; \         h->extra1 = 0;
comment|/* reserved */
value|\         h->extra2 = NULL;
comment|/* reserved */
value|\         h->next   = NULL; \         if (h_tail == NULL) \             (gptr)->string_list = h; \         else \             h_tail->next = h; \     } \ }
end_define

begin_define
define|#
directive|define
name|NEW_STRING_HANDLE_A
parameter_list|(
name|gptr
parameter_list|,
name|h
parameter_list|,
name|h_tail
parameter_list|,
name|name
parameter_list|)
value|{ \     h = (__itt_string_handle*)malloc(sizeof(__itt_string_handle)); \     if (h != NULL) { \         h->strA   = name ? __itt_fstrdup(name) : NULL; \         h->strW   = NULL; \         h->extra1 = 0;
comment|/* reserved */
value|\         h->extra2 = NULL;
comment|/* reserved */
value|\         h->next   = NULL; \         if (h_tail == NULL) \             (gptr)->string_list = h; \         else \             h_tail->next = h; \     } \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ITTNOTIFY_CONFIG_H_ */
end_comment

end_unit

