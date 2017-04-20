begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_H
end_define

begin_comment
comment|/* Get __FreeBSD_version. */
end_comment

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_comment
comment|/* Exported configuration */
end_comment

begin_include
include|#
directive|include
file|"llvm/Config/llvm-config.h"
end_include

begin_comment
comment|/* Bug report URL. */
end_comment

begin_define
define|#
directive|define
name|BUG_REPORT_URL
value|"https://bugs.freebsd.org/submit/"
end_define

begin_comment
comment|/* Define to 1 to enable backtraces, and to 0 otherwise. */
end_comment

begin_define
define|#
directive|define
name|ENABLE_BACKTRACES
value|0
end_define

begin_comment
comment|/* Define to 1 to enable crash overrides, and to 0 otherwise. */
end_comment

begin_define
define|#
directive|define
name|ENABLE_CRASH_OVERRIDES
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `backtrace' function. */
end_comment

begin_comment
comment|/* #undef HAVE_BACKTRACE */
end_comment

begin_comment
comment|/* Define to 1 if you have the<CrashReporterClient.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_CRASHREPORTERCLIENT_H */
end_comment

begin_comment
comment|/* can use __crashreporter_info__ */
end_comment

begin_define
define|#
directive|define
name|HAVE_CRASHREPORTER_INFO
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `arc4random', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_ARC4RANDOM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `FE_ALL_EXCEPT', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FE_ALL_EXCEPT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `FE_INEXACT', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FE_INEXACT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `strerror_s', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRERROR_S
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the DIA SDK installed, and to 0 if you don't. */
end_comment

begin_define
define|#
directive|define
name|LLVM_ENABLE_DIA_SDK
value|0
end_define

begin_comment
comment|/* Define to 1 if you have the<dirent.h> header file, and it defines `DIR'.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dlfcn.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLFCN_H
value|1
end_define

begin_comment
comment|/* Define if dlopen() is available on this platform. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLOPEN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<errno.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<execinfo.h> header file. */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|1000052
end_if

begin_define
define|#
directive|define
name|HAVE_EXECINFO_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to 1 if you have the<fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<fenv.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FENV_H
value|1
end_define

begin_comment
comment|/* Define if libffi is available on this platform. */
end_comment

begin_comment
comment|/* #undef HAVE_FFI_CALL */
end_comment

begin_comment
comment|/* Define to 1 if you have the<ffi/ffi.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_FFI_FFI_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<ffi.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_FFI_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `futimens' function. */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|1100056
end_if

begin_define
define|#
directive|define
name|HAVE_FUTIMENS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to 1 if you have the `futimes' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FUTIMES
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getcwd' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpagesize' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getrlimit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRLIMIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getrusage' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRUSAGE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gettimeofday' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `int64_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INT64_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `isatty' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISATTY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `edit' library (-ledit). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBEDIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `psapi' library (-lpsapi). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBPSAPI */
end_comment

begin_comment
comment|/* Define to 1 if you have the `pthread' library (-lpthread). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBPTHREAD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `shell32' library (-lshell32). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSHELL32 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `z' library (-lz). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBZ
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<link.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LINK_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `lseek64' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LSEEK64 */
end_comment

begin_comment
comment|/* Define to 1 if you have the<mach/mach.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MACH_MACH_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `mallctl' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MALLCTL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mallinfo' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MALLINFO */
end_comment

begin_comment
comment|/* Define to 1 if you have the<malloc.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<malloc/malloc.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_MALLOC_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `malloc_zone_statistics' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_ZONE_STATISTICS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `mkdtemp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKDTEMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mkstemp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mktemp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKTEMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<ndir.h> header file, and it defines `DIR'. */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `posix_fallocate' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POSIX_FALLOCATE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `posix_spawn' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POSIX_SPAWN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pread' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PREAD
value|1
end_define

begin_comment
comment|/* Have pthread_getspecific */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_GETSPECIFIC
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<pthread.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_H
value|1
end_define

begin_comment
comment|/* Have pthread_mutex_lock */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_MUTEX_LOCK
value|1
end_define

begin_comment
comment|/* Have pthread_rwlock_init */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_RWLOCK_INIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `realpath' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REALPATH
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sbrk' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SBRK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setrlimit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETRLIMIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sigaltstack' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGALTSTACK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<signal.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGNAL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strerror_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strtoll' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOLL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sysconf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/dir.h> header file, and it defines `DIR'.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_DIR_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ioctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/mman.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MMAN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ndir.h> header file, and it defines `DIR'.    */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/param.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/resource.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_RESOURCE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/uio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UIO_H
value|1
end_define

begin_comment
comment|/* Define if the setupterm() function is supported this platform. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMINFO
value|1
end_define

begin_comment
comment|/* Define if the xar_open() function is supported this platform. */
end_comment

begin_comment
comment|/* #undef HAVE_LIBXAR */
end_comment

begin_comment
comment|/* Define to 1 if you have the<termios.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `uint64_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINT64_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `u_int64_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_U_INT64_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<valgrind/valgrind.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_VALGRIND_VALGRIND_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `writev' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WRITEV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<zlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ZLIB_H
value|1
end_define

begin_comment
comment|/* Have host's _alloca */
end_comment

begin_comment
comment|/* #undef HAVE__ALLOCA */
end_comment

begin_comment
comment|/* Define to 1 if you have the `_chsize_s' function. */
end_comment

begin_comment
comment|/* #undef HAVE__CHSIZE_S */
end_comment

begin_comment
comment|/* Define to 1 if you have the `_Unwind_Backtrace' function. */
end_comment

begin_comment
comment|/* #undef HAVE__UNWIND_BACKTRACE */
end_comment

begin_comment
comment|/* Have host's __alloca */
end_comment

begin_comment
comment|/* #undef HAVE___ALLOCA */
end_comment

begin_comment
comment|/* Have host's __ashldi3 */
end_comment

begin_comment
comment|/* #undef HAVE___ASHLDI3 */
end_comment

begin_comment
comment|/* Have host's __ashrdi3 */
end_comment

begin_comment
comment|/* #undef HAVE___ASHRDI3 */
end_comment

begin_comment
comment|/* Have host's __chkstk */
end_comment

begin_comment
comment|/* #undef HAVE___CHKSTK */
end_comment

begin_comment
comment|/* Have host's __chkstk_ms */
end_comment

begin_comment
comment|/* #undef HAVE___CHKSTK_MS */
end_comment

begin_comment
comment|/* Have host's __cmpdi2 */
end_comment

begin_comment
comment|/* #undef HAVE___CMPDI2 */
end_comment

begin_comment
comment|/* Have host's __divdi3 */
end_comment

begin_comment
comment|/* #undef HAVE___DIVDI3 */
end_comment

begin_comment
comment|/* Have host's __fixdfdi */
end_comment

begin_comment
comment|/* #undef HAVE___FIXDFDI */
end_comment

begin_comment
comment|/* Have host's __fixsfdi */
end_comment

begin_comment
comment|/* #undef HAVE___FIXSFDI */
end_comment

begin_comment
comment|/* Have host's __floatdidf */
end_comment

begin_comment
comment|/* #undef HAVE___FLOATDIDF */
end_comment

begin_comment
comment|/* Have host's __lshrdi3 */
end_comment

begin_comment
comment|/* #undef HAVE___LSHRDI3 */
end_comment

begin_comment
comment|/* Have host's __main */
end_comment

begin_comment
comment|/* #undef HAVE___MAIN */
end_comment

begin_comment
comment|/* Have host's __moddi3 */
end_comment

begin_comment
comment|/* #undef HAVE___MODDI3 */
end_comment

begin_comment
comment|/* Have host's __udivdi3 */
end_comment

begin_comment
comment|/* #undef HAVE___UDIVDI3 */
end_comment

begin_comment
comment|/* Have host's __umoddi3 */
end_comment

begin_comment
comment|/* #undef HAVE___UMODDI3 */
end_comment

begin_comment
comment|/* Have host's ___chkstk */
end_comment

begin_comment
comment|/* #undef HAVE____CHKSTK */
end_comment

begin_comment
comment|/* Have host's ___chkstk_ms */
end_comment

begin_comment
comment|/* #undef HAVE____CHKSTK_MS */
end_comment

begin_comment
comment|/* Linker version detected at compile time. */
end_comment

begin_comment
comment|/* #undef HOST_LINK_VERSION */
end_comment

begin_comment
comment|/* Define if we link Polly to the tools */
end_comment

begin_comment
comment|/* #undef LINK_POLLY_INTO_TOOLS */
end_comment

begin_comment
comment|/* Target triple LLVM will generate code for by default */
end_comment

begin_comment
comment|/* Doesn't use `cmakedefine` because it is allowed to be empty. */
end_comment

begin_comment
comment|/* #undef LLVM_DEFAULT_TARGET_TRIPLE */
end_comment

begin_comment
comment|/* Define if threads enabled */
end_comment

begin_define
define|#
directive|define
name|LLVM_ENABLE_THREADS
value|1
end_define

begin_comment
comment|/* Define if zlib compression is available */
end_comment

begin_define
define|#
directive|define
name|LLVM_ENABLE_ZLIB
value|1
end_define

begin_comment
comment|/* Has gcc/MSVC atomic intrinsics */
end_comment

begin_define
define|#
directive|define
name|LLVM_HAS_ATOMICS
value|1
end_define

begin_comment
comment|/* Host triple LLVM will be executed on */
end_comment

begin_comment
comment|/* #undef LLVM_HOST_TRIPLE */
end_comment

begin_comment
comment|/* LLVM architecture name for the native architecture, if available */
end_comment

begin_define
define|#
directive|define
name|LLVM_NATIVE_ARCH
value|X86
end_define

begin_comment
comment|/* LLVM name for the native AsmParser init function, if available */
end_comment

begin_define
define|#
directive|define
name|LLVM_NATIVE_ASMPARSER
value|LLVMInitializeX86AsmParser
end_define

begin_comment
comment|/* LLVM name for the native AsmPrinter init function, if available */
end_comment

begin_define
define|#
directive|define
name|LLVM_NATIVE_ASMPRINTER
value|LLVMInitializeX86AsmPrinter
end_define

begin_comment
comment|/* LLVM name for the native Disassembler init function, if available */
end_comment

begin_define
define|#
directive|define
name|LLVM_NATIVE_DISASSEMBLER
value|LLVMInitializeX86Disassembler
end_define

begin_comment
comment|/* LLVM name for the native Target init function, if available */
end_comment

begin_define
define|#
directive|define
name|LLVM_NATIVE_TARGET
value|LLVMInitializeX86Target
end_define

begin_comment
comment|/* LLVM name for the native TargetInfo init function, if available */
end_comment

begin_define
define|#
directive|define
name|LLVM_NATIVE_TARGETINFO
value|LLVMInitializeX86TargetInfo
end_define

begin_comment
comment|/* LLVM name for the native target MC init function, if available */
end_comment

begin_define
define|#
directive|define
name|LLVM_NATIVE_TARGETMC
value|LLVMInitializeX86TargetMC
end_define

begin_comment
comment|/* Define if this is Unixish platform */
end_comment

begin_define
define|#
directive|define
name|LLVM_ON_UNIX
value|1
end_define

begin_comment
comment|/* Define if this is Win32ish platform */
end_comment

begin_comment
comment|/* #undef LLVM_ON_WIN32 */
end_comment

begin_comment
comment|/* Installation prefix directory */
end_comment

begin_define
define|#
directive|define
name|LLVM_PREFIX
value|"/usr"
end_define

begin_comment
comment|/* Define if we have the Intel JIT API runtime support library */
end_comment

begin_define
define|#
directive|define
name|LLVM_USE_INTEL_JITEVENTS
value|0
end_define

begin_comment
comment|/* Define if we have the oprofile JIT-support library */
end_comment

begin_define
define|#
directive|define
name|LLVM_USE_OPROFILE
value|0
end_define

begin_comment
comment|/* LLVM version information */
end_comment

begin_comment
comment|/* #undef LLVM_VERSION_INFO */
end_comment

begin_comment
comment|/* Major version of the LLVM API */
end_comment

begin_define
define|#
directive|define
name|LLVM_VERSION_MAJOR
value|4
end_define

begin_comment
comment|/* Minor version of the LLVM API */
end_comment

begin_define
define|#
directive|define
name|LLVM_VERSION_MINOR
value|0
end_define

begin_comment
comment|/* Patch version of the LLVM API */
end_comment

begin_define
define|#
directive|define
name|LLVM_VERSION_PATCH
value|0
end_define

begin_comment
comment|/* LLVM version string */
end_comment

begin_define
define|#
directive|define
name|LLVM_VERSION_STRING
value|"4.0.0"
end_define

begin_comment
comment|/* Define to the extension used for shared libraries, say, ".so". */
end_comment

begin_define
define|#
directive|define
name|LTDL_SHLIB_EXT
value|".so"
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"https://bugs.freebsd.org/submit/"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"LLVM"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"LLVM 4.0.0"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_undef
undef|#
directive|undef
name|PACKAGE_TARNAME
end_undef

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"4.0.0"
end_define

begin_comment
comment|/* Define to the vendor of this package. */
end_comment

begin_comment
comment|/* #undef PACKAGE_VENDOR */
end_comment

begin_comment
comment|/* Define as the return type of signal handlers (`int' or `void'). */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* Define to a function replacing strtoll */
end_comment

begin_comment
comment|/* #undef strtoll */
end_comment

begin_comment
comment|/* Define to a function implementing strtoull */
end_comment

begin_comment
comment|/* #undef strtoull */
end_comment

begin_comment
comment|/* Define to a function implementing stricmp */
end_comment

begin_comment
comment|/* #undef stricmp */
end_comment

begin_comment
comment|/* Define to a function implementing strdup */
end_comment

begin_comment
comment|/* #undef strdup */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

