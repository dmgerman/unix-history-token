begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* include/llvm/Config/config.h.  Generated from config.h.in by configure.  */
end_comment

begin_comment
comment|/* include/llvm/Config/config.h.in.  Generated from autoconf/configure.ac by autoheader.  */
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
comment|/* Bug report URL. */
end_comment

begin_define
define|#
directive|define
name|BUG_REPORT_URL
value|"https://bugs.freebsd.org/submit/"
end_define

begin_comment
comment|/* Define if we have libxml2 */
end_comment

begin_comment
comment|/* #undef CLANG_HAVE_LIBXML */
end_comment

begin_comment
comment|/* Relative directory for resource files */
end_comment

begin_define
define|#
directive|define
name|CLANG_RESOURCE_DIR
value|""
end_define

begin_comment
comment|/* Directories clang will search for headers */
end_comment

begin_define
define|#
directive|define
name|C_INCLUDE_DIRS
value|""
end_define

begin_comment
comment|/* Default<path> to all compiler invocations for --sysroot=<path>. */
end_comment

begin_comment
comment|/* #undef DEFAULT_SYSROOT */
end_comment

begin_comment
comment|/* Define if you want backtraces on crash */
end_comment

begin_define
define|#
directive|define
name|ENABLE_BACKTRACES
value|0
end_define

begin_comment
comment|/* Define to enable crash handling overrides */
end_comment

begin_define
define|#
directive|define
name|ENABLE_CRASH_OVERRIDES
value|1
end_define

begin_comment
comment|/* Define if position independent code is enabled */
end_comment

begin_define
define|#
directive|define
name|ENABLE_PIC
value|0
end_define

begin_comment
comment|/* Define if timestamp information (e.g., __DATE__) is allowed */
end_comment

begin_define
define|#
directive|define
name|ENABLE_TIMESTAMPS
value|0
end_define

begin_comment
comment|/* Directory where gcc is installed. */
end_comment

begin_define
define|#
directive|define
name|GCC_INSTALL_PREFIX
value|""
end_define

begin_comment
comment|/* Define to 1 if you have the `arc4random' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARC4RANDOM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `argz_append' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ARGZ_APPEND */
end_comment

begin_comment
comment|/* Define to 1 if you have the `argz_create_sep' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ARGZ_CREATE_SEP */
end_comment

begin_comment
comment|/* Define to 1 if you have the<argz.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_ARGZ_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `argz_insert' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ARGZ_INSERT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `argz_next' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ARGZ_NEXT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `argz_stringify' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ARGZ_STRINGIFY */
end_comment

begin_comment
comment|/* Define to 1 if you have the `backtrace' function. */
end_comment

begin_comment
comment|/* #undef HAVE_BACKTRACE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `ceilf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CEILF
value|1
end_define

begin_comment
comment|/* Define if the neat program is available */
end_comment

begin_comment
comment|/* #undef HAVE_CIRCO */
end_comment

begin_comment
comment|/* Define to 1 if you have the `closedir' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOSEDIR
value|1
end_define

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
comment|/* Define to 1 if you have the<cxxabi.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CXXABI_H
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
comment|/* Define to 1 if you have the<dirent.h> header file, and it defines `DIR'.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define if you have the GNU dld library. */
end_comment

begin_comment
comment|/* #undef HAVE_DLD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `dlerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLERROR
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
comment|/* Define if the dot program is available */
end_comment

begin_comment
comment|/* #undef HAVE_DOT */
end_comment

begin_comment
comment|/* Define if the dotty program is available */
end_comment

begin_comment
comment|/* #undef HAVE_DOTTY */
end_comment

begin_comment
comment|/* Define if you have the _dyld_func_lookup function. */
end_comment

begin_comment
comment|/* #undef HAVE_DYLD */
end_comment

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
comment|/* Define to 1 if the system has the type `error_t'. */
end_comment

begin_comment
comment|/* #undef HAVE_ERROR_T */
end_comment

begin_comment
comment|/* Define to 1 if you have the<execinfo.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_EXECINFO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `exp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `exp2' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_EXP2
value|1
end_define

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
comment|/* Define if the neat program is available */
end_comment

begin_comment
comment|/* #undef HAVE_FDP */
end_comment

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
comment|/* Set to 1 if the finite function is found in<ieeefp.h> */
end_comment

begin_comment
comment|/* #undef HAVE_FINITE_IN_IEEEFP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `floorf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FLOORF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fmodf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FMODF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `futimens' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FUTIMENS */
end_comment

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
comment|/* Define if the Graphviz program is available */
end_comment

begin_comment
comment|/* #undef HAVE_GRAPHVIZ */
end_comment

begin_comment
comment|/* Define if the gv program is available */
end_comment

begin_comment
comment|/* #undef HAVE_GV */
end_comment

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
comment|/* Set to 1 if the isinf function is found in<cmath> */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISINF_IN_CMATH
value|1
end_define

begin_comment
comment|/* Set to 1 if the isinf function is found in<math.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISINF_IN_MATH_H
value|1
end_define

begin_comment
comment|/* Set to 1 if the isnan function is found in<cmath> */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISNAN_IN_CMATH
value|1
end_define

begin_comment
comment|/* Set to 1 if the isnan function is found in<math.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISNAN_IN_MATH_H
value|1
end_define

begin_comment
comment|/* Define if you have the libdl library or equivalent. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBDL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `imagehlp' library (-limagehlp). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBIMAGEHLP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `m' library (-lm). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBM
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

begin_comment
comment|/* #undef HAVE_LIBPTHREAD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `shell32' library (-lshell32). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSHELL32 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `udis86' library (-ludis86). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBUDIS86 */
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
comment|/* Define if you can use -rdynamic. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LINK_EXPORT_DYNAMIC
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
comment|/* Define if you can use -Wl,-R. to pass -R. to the linker, in order to add    the current directory to the dynamic linker search path. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LINK_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `log' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `log10' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOG10
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `log2' function. */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|900027
operator|||
operator|(
name|__FreeBSD_version
operator|<
literal|900000
operator|&&
name|__FreeBSD_version
operator|>=
literal|802502
operator|)
end_if

begin_define
define|#
directive|define
name|HAVE_LOG2
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to 1 if you have the `longjmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONGJMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<mach/mach.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MACH_MACH_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<mach-o/dyld.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MACH_O_DYLD_H */
end_comment

begin_comment
comment|/* Define if mallinfo() is available on this platform. */
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
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

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
comment|/* Define to 1 if you have a working `mmap' system call. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
value|1
end_define

begin_comment
comment|/* Define if mmap() uses MAP_ANONYMOUS to map anonymous pages, or undefine if    it uses MAP_ANON */
end_comment

begin_comment
comment|/* #undef HAVE_MMAP_ANONYMOUS */
end_comment

begin_comment
comment|/* Define if mmap() can map files into memory */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP_FILE
end_define

begin_comment
comment|/* Define to 1 if you have the<ndir.h> header file, and it defines `DIR'. */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `nearbyintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NEARBYINTF
value|1
end_define

begin_comment
comment|/* Define if the neat program is available */
end_comment

begin_comment
comment|/* #undef HAVE_NEATO */
end_comment

begin_comment
comment|/* Define to 1 if you have the `opendir' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPENDIR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `posix_spawn' function. */
end_comment

begin_comment
comment|/* #undef HAVE_POSIX_SPAWN */
end_comment

begin_comment
comment|/* Define to 1 if you have the `powf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POWF
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
comment|/* Define if libtool can extract symbol lists from object files. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PRELOADED_SYMBOLS
value|1
end_define

begin_comment
comment|/* Define to have the %a format string */
end_comment

begin_define
define|#
directive|define
name|HAVE_PRINTF_A
value|1
end_define

begin_comment
comment|/* Have pthread_getspecific */
end_comment

begin_comment
comment|/* #undef HAVE_PTHREAD_GETSPECIFIC */
end_comment

begin_comment
comment|/* Define to 1 if you have the<pthread.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PTHREAD_H */
end_comment

begin_comment
comment|/* Have pthread_mutex_lock */
end_comment

begin_comment
comment|/* #undef HAVE_PTHREAD_MUTEX_LOCK */
end_comment

begin_comment
comment|/* Have pthread_rwlock_init */
end_comment

begin_comment
comment|/* #undef HAVE_PTHREAD_RWLOCK_INIT */
end_comment

begin_comment
comment|/* Define to 1 if srand48/lrand48/drand48 exist in<stdlib.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_RAND48
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `readdir' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_READDIR
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
comment|/* Define to 1 if you have the `rintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `round' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ROUND
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `roundf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ROUNDF
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
comment|/* Define to 1 if you have the `setjmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETJMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<setjmp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETJMP_H
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
comment|/* Define if you have the shl_load function. */
end_comment

begin_comment
comment|/* #undef HAVE_SHL_LOAD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `siglongjmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGLONGJMP
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
comment|/* Define to 1 if you have the `sigsetjmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGSETJMP
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
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Set to 1 if the std::isinf function is found in<cmath> */
end_comment

begin_define
define|#
directive|define
name|HAVE_STD_ISINF_IN_CMATH
value|1
end_define

begin_comment
comment|/* Set to 1 if the std::isnan function is found in<cmath> */
end_comment

begin_define
define|#
directive|define
name|HAVE_STD_ISNAN_IN_CMATH
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
comment|/* Define to 1 if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strtof' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOF
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
comment|/* Define to 1 if you have the `strtoq' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOQ
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

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

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
comment|/* Define to 1 if you have<sys/wait.h> that is POSIX.1 compatible. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
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
comment|/* Define to 1 if you have the<termios.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define if the neat program is available */
end_comment

begin_comment
comment|/* #undef HAVE_TWOPI */
end_comment

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
comment|/* Define to 1 if you have the<utime.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `u_int64_t'. */
end_comment

begin_comment
comment|/* #undef HAVE_U_INT64_T */
end_comment

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
comment|/* Define if the xdot program is available */
end_comment

begin_comment
comment|/* #undef HAVE_XDOT */
end_comment

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
comment|/* Define to 1 if you have the `__dso_handle' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE___DSO_HANDLE
value|1
end_define

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
comment|/* Linker version detected at compile time. */
end_comment

begin_comment
comment|/* #undef HOST_LINK_VERSION */
end_comment

begin_comment
comment|/* Installation directory for binary executables */
end_comment

begin_comment
comment|/* #undef LLVM_BINDIR */
end_comment

begin_comment
comment|/* Time at which LLVM was configured */
end_comment

begin_comment
comment|/* #undef LLVM_CONFIGTIME */
end_comment

begin_comment
comment|/* Installation directory for data files */
end_comment

begin_comment
comment|/* #undef LLVM_DATADIR */
end_comment

begin_comment
comment|/* Target triple LLVM will generate code for by default */
end_comment

begin_comment
comment|/* #undef LLVM_DEFAULT_TARGET_TRIPLE */
end_comment

begin_comment
comment|/* Installation directory for documentation */
end_comment

begin_comment
comment|/* #undef LLVM_DOCSDIR */
end_comment

begin_comment
comment|/* Define if threads enabled */
end_comment

begin_define
define|#
directive|define
name|LLVM_ENABLE_THREADS
value|0
end_define

begin_comment
comment|/* Define if zlib is enabled */
end_comment

begin_define
define|#
directive|define
name|LLVM_ENABLE_ZLIB
value|1
end_define

begin_comment
comment|/* Installation directory for config files */
end_comment

begin_comment
comment|/* #undef LLVM_ETCDIR */
end_comment

begin_comment
comment|/* Has gcc/MSVC atomic intrinsics */
end_comment

begin_define
define|#
directive|define
name|LLVM_HAS_ATOMICS
value|0
end_define

begin_comment
comment|/* Host triple LLVM will be executed on */
end_comment

begin_comment
comment|/* #undef LLVM_HOST_TRIPLE */
end_comment

begin_comment
comment|/* Installation directory for include files */
end_comment

begin_comment
comment|/* #undef LLVM_INCLUDEDIR */
end_comment

begin_comment
comment|/* Installation directory for .info files */
end_comment

begin_comment
comment|/* #undef LLVM_INFODIR */
end_comment

begin_comment
comment|/* Installation directory for man pages */
end_comment

begin_comment
comment|/* #undef LLVM_MANDIR */
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
comment|/* Define to path to circo program if found or 'echo circo' otherwise */
end_comment

begin_comment
comment|/* #undef LLVM_PATH_CIRCO */
end_comment

begin_comment
comment|/* Define to path to dot program if found or 'echo dot' otherwise */
end_comment

begin_comment
comment|/* #undef LLVM_PATH_DOT */
end_comment

begin_comment
comment|/* Define to path to dotty program if found or 'echo dotty' otherwise */
end_comment

begin_comment
comment|/* #undef LLVM_PATH_DOTTY */
end_comment

begin_comment
comment|/* Define to path to fdp program if found or 'echo fdp' otherwise */
end_comment

begin_comment
comment|/* #undef LLVM_PATH_FDP */
end_comment

begin_comment
comment|/* Define to path to Graphviz program if found or 'echo Graphviz' otherwise */
end_comment

begin_comment
comment|/* #undef LLVM_PATH_GRAPHVIZ */
end_comment

begin_comment
comment|/* Define to path to gv program if found or 'echo gv' otherwise */
end_comment

begin_comment
comment|/* #undef LLVM_PATH_GV */
end_comment

begin_comment
comment|/* Define to path to neato program if found or 'echo neato' otherwise */
end_comment

begin_comment
comment|/* #undef LLVM_PATH_NEATO */
end_comment

begin_comment
comment|/* Define to path to twopi program if found or 'echo twopi' otherwise */
end_comment

begin_comment
comment|/* #undef LLVM_PATH_TWOPI */
end_comment

begin_comment
comment|/* Define to path to xdot program if found or 'echo xdot' otherwise */
end_comment

begin_comment
comment|/* #undef LLVM_PATH_XDOT */
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
comment|/* Major version of the LLVM API */
end_comment

begin_define
define|#
directive|define
name|LLVM_VERSION_MAJOR
value|3
end_define

begin_comment
comment|/* Minor version of the LLVM API */
end_comment

begin_define
define|#
directive|define
name|LLVM_VERSION_MINOR
value|4
end_define

begin_comment
comment|/* Patch version of the LLVM API */
end_comment

begin_define
define|#
directive|define
name|LLVM_VERSION_PATCH
value|1
end_define

begin_comment
comment|/* Define if the OS needs help to load dependent libraries for dlopen(). */
end_comment

begin_define
define|#
directive|define
name|LTDL_DLOPEN_DEPLIBS
value|1
end_define

begin_comment
comment|/* Define to the sub-directory in which libtool stores uninstalled libraries.    */
end_comment

begin_define
define|#
directive|define
name|LTDL_OBJDIR
value|".libs/"
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
comment|/* Define to the system default library search path. */
end_comment

begin_define
define|#
directive|define
name|LTDL_SYSSEARCHPATH
value|"/lib:/usr/lib"
end_define

begin_comment
comment|/* Define if /dev/zero should be used when mapping RWX memory, or undefine if    its not necessary */
end_comment

begin_comment
comment|/* #undef NEED_DEV_ZERO_FOR_MMAP */
end_comment

begin_comment
comment|/* Define if dlsym() requires a leading underscore in symbol names. */
end_comment

begin_comment
comment|/* #undef NEED_USCORE */
end_comment

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"http://llvm.org/bugs/"
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
value|"LLVM 3.4.1"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"llvm"
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"3.4.1"
end_define

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
comment|/* Define to 1 if the `S_IS*' macros in<sys/stat.h> do not work properly. */
end_comment

begin_comment
comment|/* #undef STAT_MACROS_BROKEN */
end_comment

begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define to 1 if you can safely include both<sys/time.h> and<time.h>. */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define to 1 if your<sys/time.h> declares `struct tm'. */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Define if use udis86 library */
end_comment

begin_define
define|#
directive|define
name|USE_UDIS86
value|0
end_define

begin_comment
comment|/* Type of 1st arg on ELM Callback */
end_comment

begin_comment
comment|/* #undef WIN32_ELMCB_PCSTR */
end_comment

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to a type to use for `error_t' if it is not otherwise available. */
end_comment

begin_define
define|#
directive|define
name|error_t
value|int
end_define

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

