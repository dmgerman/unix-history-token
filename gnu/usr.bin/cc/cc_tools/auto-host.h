begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD_version
end_ifndef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* auto-host.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define if using alloca.c.  */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.    This function is required for alloca.c support on those systems.  */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define to the type of elements in the array set by `getgroups'.    Usually this is either `int' or `gid_t'.  */
end_comment

begin_define
define|#
directive|define
name|GETGROUPS_T
value|gid_t
end_define

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef gid_t */
end_comment

begin_comment
comment|/* Define if you have alloca, as a function or macro.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_comment
comment|/* Define if you have<alloca.h> and it should be used (not on Ultrix).  */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Define if you have the ANSI # stringizing operator in cpp. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGIZE
value|1
end_define

begin_comment
comment|/* Define if you have<sys/wait.h> that is POSIX.1 compatible.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if you have<vfork.h>.  */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

begin_comment
comment|/* Define as __inline if that's what the C compiler calls it.  */
end_comment

begin_comment
comment|/* #undef inline */
end_comment

begin_comment
comment|/* Define if your C compiler doesn't accept -c and -o together.  */
end_comment

begin_comment
comment|/* #undef NO_MINUS_C_MINUS_O */
end_comment

begin_comment
comment|/* Define to `long' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define to `unsigned' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at run-time.  STACK_DIRECTION> 0 => grows toward higher addresses  STACK_DIRECTION< 0 => grows toward lower addresses  STACK_DIRECTION = 0 => direction of growth unknown  */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define if you have the ANSI C header files.  */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if you can safely include both<sys/time.h> and<time.h>.  */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef uid_t */
end_comment

begin_comment
comment|/* Define vfork as fork if vfork does not work.  */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

begin_comment
comment|/* Define if your assembler supports specifying the maximum number    of bytes to skip when using the GAS .p2align command.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GAS_MAX_SKIP_P2ALIGN
value|1
end_define

begin_comment
comment|/* Define if your assembler supports .balign and .p2align.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GAS_BALIGN_AND_P2ALIGN
value|1
end_define

begin_comment
comment|/* Define if your assembler uses the old HImode fild and fist notation.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GAS_FILDS_FISTS
value|1
end_define

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef ssize_t */
end_comment

begin_comment
comment|/* Define if cpp should also search $prefix/include.  */
end_comment

begin_comment
comment|/* #undef PREFIX_INCLUDE_DIR */
end_comment

begin_comment
comment|/* Define if you have the __argz_count function.  */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_COUNT */
end_comment

begin_comment
comment|/* Define if you have the __argz_next function.  */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_NEXT */
end_comment

begin_comment
comment|/* Define if you have the __argz_stringify function.  */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_STRINGIFY */
end_comment

begin_comment
comment|/* Define if you have the alphasort function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALPHASORT
value|1
end_define

begin_comment
comment|/* Define if you have the atoll function.  */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500027
end_if

begin_comment
comment|/* FreeBSD didn't always have atoll(3). */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATOLL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if you have the atoq function.  */
end_comment

begin_comment
comment|/* #undef HAVE_ATOQ */
end_comment

begin_comment
comment|/* Define if you have the clock function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK
value|1
end_define

begin_comment
comment|/* Define if you have the dcgettext function.  */
end_comment

begin_comment
comment|/* #undef HAVE_DCGETTEXT */
end_comment

begin_comment
comment|/* Define if you have the dup2 function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DUP2
value|1
end_define

begin_comment
comment|/* Define if you have the feof_unlocked function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FEOF_UNLOCKED
value|1
end_define

begin_comment
comment|/* Define if you have the fgets_unlocked function.  */
end_comment

begin_comment
comment|/* #undef HAVE_FGETS_UNLOCKED */
end_comment

begin_comment
comment|/* Define if you have the fprintf_unlocked function.  */
end_comment

begin_comment
comment|/* #undef HAVE_FPRINTF_UNLOCKED */
end_comment

begin_comment
comment|/* Define if you have the fputc_unlocked function.  */
end_comment

begin_comment
comment|/* #undef HAVE_FPUTC_UNLOCKED */
end_comment

begin_comment
comment|/* Define if you have the fputs_unlocked function.  */
end_comment

begin_comment
comment|/* #undef HAVE_FPUTS_UNLOCKED */
end_comment

begin_comment
comment|/* Define if you have the fwrite_unlocked function.  */
end_comment

begin_comment
comment|/* #undef HAVE_FWRITE_UNLOCKED */
end_comment

begin_comment
comment|/* Define if you have the getcwd function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_comment
comment|/* Define if you have the getegid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETEGID
value|1
end_define

begin_comment
comment|/* Define if you have the geteuid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETEUID
value|1
end_define

begin_comment
comment|/* Define if you have the getgid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGID
value|1
end_define

begin_comment
comment|/* Define if you have the getpagesize function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define if you have the getrlimit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRLIMIT
value|1
end_define

begin_comment
comment|/* Define if you have the getrusage function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRUSAGE
value|1
end_define

begin_comment
comment|/* Define if you have the getuid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUID
value|1
end_define

begin_comment
comment|/* Define if you have the kill function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_KILL
value|1
end_define

begin_comment
comment|/* Define if you have the lstat function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LSTAT
value|1
end_define

begin_comment
comment|/* Define if you have the mempcpy function.  */
end_comment

begin_comment
comment|/* #undef HAVE_MEMPCPY */
end_comment

begin_comment
comment|/* Define if you have the munmap function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MUNMAP
value|1
end_define

begin_comment
comment|/* Define if you have the nl_langinfo function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NL_LANGINFO
value|1
end_define

begin_comment
comment|/* Define if you have the putc_unlocked function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTC_UNLOCKED
value|1
end_define

begin_comment
comment|/* Define if you have the putenv function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTENV
value|1
end_define

begin_comment
comment|/* Define if you have the scandir function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SCANDIR
value|1
end_define

begin_comment
comment|/* Define if you have the setenv function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define if you have the setlocale function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|1
end_define

begin_comment
comment|/* Define if you have the setrlimit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETRLIMIT
value|1
end_define

begin_comment
comment|/* Define if you have the stpcpy function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STPCPY
value|1
end_define

begin_comment
comment|/* Define if you have the strcasecmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the strchr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_comment
comment|/* Define if you have the strdup function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define if you have the strsignal function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSIGNAL
value|1
end_define

begin_comment
comment|/* Define if you have the strtoul function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOUL
value|1
end_define

begin_comment
comment|/* Define if you have the sysconf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|1
end_define

begin_comment
comment|/* Define if you have the times function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMES
value|1
end_define

begin_comment
comment|/* Define if you have the tsearch function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TSEARCH
value|1
end_define

begin_comment
comment|/* Define if you have the<argz.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_ARGZ_H */
end_comment

begin_comment
comment|/* Define if you have the<direct.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_DIRECT_H */
end_comment

begin_comment
comment|/* Define if you have the<fcntl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<langinfo.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LANGINFO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<limits.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<locale.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<malloc.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_H */
end_comment

begin_comment
comment|/* Define if you have the<nl_types.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NL_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stddef.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stdlib.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<string.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the<strings.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/file.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/param.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/resource.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_RESOURCE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/stat.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/times.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<unistd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define to enable the use of a default linker. */
end_comment

begin_comment
comment|/* #undef DEFAULT_LINKER */
end_comment

begin_comment
comment|/* Define to enable the use of a default assembler. */
end_comment

begin_comment
comment|/* #undef DEFAULT_ASSEMBLER */
end_comment

begin_comment
comment|/* Define if your compiler understands volatile. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VOLATILE
value|1
end_define

begin_comment
comment|/* Define if your compiler supports the `long double' type. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_DOUBLE
value|1
end_define

begin_comment
comment|/* Define if your compiler supports the `long long' type. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define if your compiler supports the `__int64' type. */
end_comment

begin_comment
comment|/* #undef HAVE___INT64 */
end_comment

begin_comment
comment|/* Define if the `_Bool' type is built-in. */
end_comment

begin_define
define|#
directive|define
name|HAVE__BOOL
value|1
end_define

begin_comment
comment|/* The number of bytes in type short */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_SHORT
value|2
end_define

begin_comment
comment|/* The number of bytes in type int */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_INT
value|4
end_define

begin_comment
comment|/* The number of bytes in type long */
end_comment

begin_comment
comment|/* #define SIZEOF_LONG 4 */
end_comment

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
name|__powerpc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__strongarm__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|SIZEOF_INT
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ia64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|SIZEOF_LONG_LONG
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"I don't know what arch this is."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The number of bytes in type long long */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_LONG_LONG
value|8
end_define

begin_comment
comment|/* The number of bytes in type __int64 */
end_comment

begin_comment
comment|/* #undef SIZEOF___INT64 */
end_comment

begin_comment
comment|/* Define if the host execution character set is EBCDIC. */
end_comment

begin_comment
comment|/* #undef HOST_EBCDIC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WANT_COMPILER_INVARIANTS
end_ifdef

begin_comment
comment|//#warning WANT_COMPILER_INVARIANTS turned on
end_comment

begin_comment
comment|/* Define if you want more run-time sanity checks.  This one gets a grab    bag of miscellaneous but relatively cheap checks. */
end_comment

begin_define
define|#
directive|define
name|ENABLE_CHECKING
value|1
end_define

begin_comment
comment|/* Define if you want all operations on trees (the basic data    structure of the front ends) to be checked for dynamic type safety    at runtime.  This is moderately expensive. */
end_comment

begin_define
define|#
directive|define
name|ENABLE_TREE_CHECKING
value|1
end_define

begin_comment
comment|/* Define if you want all operations on RTL (the basic data structure    of the optimizer and back end) to be checked for dynamic type safety    at runtime.  This is quite expensive. */
end_comment

begin_define
define|#
directive|define
name|ENABLE_RTL_CHECKING
value|1
end_define

begin_comment
comment|/* Define if you want RTL flag accesses to be checked against the RTL    codes that are supported for each access macro.  This is relatively    cheap. */
end_comment

begin_define
define|#
directive|define
name|ENABLE_RTL_FLAG_CHECKING
value|1
end_define

begin_comment
comment|/* Define if you want the garbage collector to do object poisoning and    other memory allocation checks.  This is quite expensive. */
end_comment

begin_define
define|#
directive|define
name|ENABLE_GC_CHECKING
value|1
end_define

begin_comment
comment|/* Define if you want the garbage collector to operate in maximally    paranoid mode, validating the entire heap and collecting garbage at    every opportunity.  This is extremely expensive. */
end_comment

begin_define
define|#
directive|define
name|ENABLE_GC_ALWAYS_COLLECT
value|1
end_define

begin_comment
comment|/* Define if you want to run subprograms and generated programs    through valgrind (a memory checker).  This is extremely expensive. */
end_comment

begin_comment
comment|/* #undef ENABLE_VALGRIND_CHECKING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WANT_COMPILER_INVARIANTS */
end_comment

begin_comment
comment|/* Define if you want to use __cxa_atexit, rather than atexit, to    register C++ destructors for local statics and global objects.    This is essential for fully standards-compliant handling of    destructors, but requires __cxa_atexit in libc. */
end_comment

begin_comment
comment|/* #undef DEFAULT_USE_CXA_ATEXIT */
end_comment

begin_comment
comment|/* Define if you want the C and C++ compilers to support multibyte    character sets for source code. */
end_comment

begin_comment
comment|/* #undef MULTIBYTE_CHARS */
end_comment

begin_comment
comment|/* Always define this when using the GNU C Library */
end_comment

begin_comment
comment|/* #undef _GNU_SOURCE */
end_comment

begin_comment
comment|/* Define if you have a working<stdbool.h> header file. */
end_comment

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|440003
operator|&&
name|__FreeBSD_version
operator|<
literal|500000
operator|)
operator|||
expr|\
name|__FreeBSD_version
operator|>=
literal|500014
end_if

begin_define
define|#
directive|define
name|HAVE_STDBOOL_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if you can safely include both<string.h> and<strings.h>. */
end_comment

begin_define
define|#
directive|define
name|STRING_WITH_STRINGS
value|1
end_define

begin_comment
comment|/* Define as the number of bits in a byte, if `limits.h' doesn't. */
end_comment

begin_comment
comment|/* #undef CHAR_BIT */
end_comment

begin_comment
comment|/* Define if the host machine stores words of multi-word integers in    big-endian order. */
end_comment

begin_comment
comment|/* #undef HOST_WORDS_BIG_ENDIAN */
end_comment

begin_comment
comment|/* Define to the floating point format of the host machine, if not IEEE. */
end_comment

begin_comment
comment|/* #undef HOST_FLOAT_FORMAT */
end_comment

begin_comment
comment|/* Define to 1 if the host machine stores floating point numbers in    memory with the word containing the sign bit at the lowest address,    or to 0 if it does it the other way around.     This macro should not be defined if the ordering is the same as for    multi-word integers. */
end_comment

begin_comment
comment|/* #undef HOST_FLOAT_WORDS_BIG_ENDIAN */
end_comment

begin_comment
comment|/* Define if you have a working<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define if printf supports %p. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PRINTF_PTR
value|1
end_define

begin_comment
comment|/* Define if mmap can get us zeroed pages from /dev/zero. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP_DEV_ZERO
value|1
end_define

begin_comment
comment|/* Define if mmap can get us zeroed pages using MAP_ANON(YMOUS). */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP_ANON
value|1
end_define

begin_comment
comment|/* Define if read-only mmap of a plain file works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP_FILE
value|1
end_define

begin_comment
comment|/* Define if you have the iconv() function. */
end_comment

begin_comment
comment|/* #undef HAVE_ICONV */
end_comment

begin_comment
comment|/* Define as const if the declaration of iconv() needs const. */
end_comment

begin_comment
comment|/* #undef ICONV_CONST */
end_comment

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETENV
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_ATOL
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_SBRK
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_ABORT
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_ATOF
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETCWD
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETWD
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRSIGNAL
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_PUTC_UNLOCKED
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FPUTS_UNLOCKED
value|0
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FWRITE_UNLOCKED
value|0
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FPRINTF_UNLOCKED
value|0
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRSTR
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_ERRNO
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_VASPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_MALLOC
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_REALLOC
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_CALLOC
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_FREE
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_BASENAME
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETOPT
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_CLOCK
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETRLIMIT
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_SETRLIMIT
value|1
end_define

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_GETRUSAGE
value|1
end_define

begin_comment
comment|/* Define to `long' if<sys/resource.h> doesn't define. */
end_comment

begin_comment
comment|/* #undef rlim_t */
end_comment

begin_comment
comment|/* Define to 1 if we found this declaration otherwise define to 0. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_TIMES
value|1
end_define

begin_comment
comment|/* Define if<sys/times.h> defines struct tms. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_TMS
value|1
end_define

begin_comment
comment|/* Define if<time.h> defines clock_t. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK_T
value|1
end_define

begin_comment
comment|/* Define .init_array/.fini_array sections are available and working. */
end_comment

begin_comment
comment|/* #undef HAVE_INITFINI_ARRAY */
end_comment

begin_comment
comment|/* Define if host mkdir takes a single argument. */
end_comment

begin_comment
comment|/* #undef MKDIR_TAKES_ONE_ARG */
end_comment

begin_comment
comment|/* Define if you have the iconv() function. */
end_comment

begin_comment
comment|/* #undef HAVE_ICONV */
end_comment

begin_comment
comment|/* Define as const if the declaration of iconv() needs const. */
end_comment

begin_comment
comment|/* #undef ICONV_CONST */
end_comment

begin_comment
comment|/* Define if you have<langinfo.h> and nl_langinfo(CODESET). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LANGINFO_CODESET
value|1
end_define

begin_comment
comment|/* Define if your<locale.h> file defines LC_MESSAGES. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LC_MESSAGES
value|1
end_define

begin_comment
comment|/* Define to 1 if translation of program messages to the user's native language    is requested. */
end_comment

begin_comment
comment|/* #undef ENABLE_NLS */
end_comment

begin_comment
comment|/* Define if you have the<libintl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LIBINTL_H */
end_comment

begin_comment
comment|/* Define if the GNU gettext() function is already present or preinstalled. */
end_comment

begin_comment
comment|/* #undef HAVE_GETTEXT */
end_comment

begin_comment
comment|/* Define to use the libintl included with this package instead of any    version in the system libraries. */
end_comment

begin_comment
comment|/* #undef USE_INCLUDED_LIBINTL */
end_comment

begin_comment
comment|/* Define to 1 if installation paths should be looked up in Windows32    Registry. Ignored on non windows32 hosts. */
end_comment

begin_comment
comment|/* #undef ENABLE_WIN32_REGISTRY */
end_comment

begin_comment
comment|/* Define to be the last portion of registry key on windows hosts. */
end_comment

begin_comment
comment|/* #undef WIN32_REGISTRY_KEY */
end_comment

begin_comment
comment|/* Define if your assembler supports .subsection and .subsection -1 starts    emitting at the beginning of your section. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GAS_SUBSECTION_ORDERING
value|1
end_define

begin_comment
comment|/* Define if your assembler supports .weak. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GAS_WEAK
value|1
end_define

begin_comment
comment|/* Define if your assembler supports .hidden. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GAS_HIDDEN
value|1
end_define

begin_comment
comment|/* Define if your assembler supports .uleb128. */
end_comment

begin_define
define|#
directive|define
name|HAVE_AS_LEB128
value|1
end_define

begin_comment
comment|/* Define if your assembler mis-optimizes .eh_frame data. */
end_comment

begin_comment
comment|/* #undef USE_AS_TRADITIONAL_FORMAT */
end_comment

begin_comment
comment|/* Define if your assembler supports marking sections with SHF_MERGE flag. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GAS_SHF_MERGE
value|1
end_define

begin_comment
comment|/* Define if your assembler supports thread-local storage. */
end_comment

begin_define
define|#
directive|define
name|HAVE_AS_TLS
value|1
end_define

begin_comment
comment|/* Define if your assembler supports explicit relocations. */
end_comment

begin_comment
comment|/* #undef HAVE_AS_EXPLICIT_RELOCS */
end_comment

begin_comment
comment|/* Define if your assembler supports .register. */
end_comment

begin_comment
comment|/* #undef HAVE_AS_REGISTER_PSEUDO_OP */
end_comment

begin_comment
comment|/* Define if your assembler supports -relax option. */
end_comment

begin_comment
comment|/* #undef HAVE_AS_RELAX_OPTION */
end_comment

begin_comment
comment|/* Define if your assembler and linker support unaligned PC relative relocs. */
end_comment

begin_comment
comment|/* #undef HAVE_AS_SPARC_UA_PCREL */
end_comment

begin_comment
comment|/* Define if your assembler and linker support unaligned PC relative relocs against hidden symbols. */
end_comment

begin_comment
comment|/* #undef HAVE_AS_SPARC_UA_PCREL_HIDDEN */
end_comment

begin_comment
comment|/* Define if your assembler supports offsetable %lo(). */
end_comment

begin_comment
comment|/* #undef HAVE_AS_OFFSETABLE_LO10 */
end_comment

begin_comment
comment|/* Define true if the assembler supports '.long foo@GOTOFF'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_AS_GOTOFF_IN_DATA
value|1
end_define

begin_comment
comment|/* Define if your assembler supports ltoffx and ldxmov relocations. */
end_comment

begin_comment
comment|/* #undef HAVE_AS_LTOFFX_LDXMOV_RELOCS */
end_comment

begin_comment
comment|/* Define if your assembler supports dwarf2 .file/.loc directives,    and preserves file table indices exactly as given. */
end_comment

begin_define
define|#
directive|define
name|HAVE_AS_DWARF2_DEBUG_LINE
value|1
end_define

begin_comment
comment|/* Define if your assembler supports the --gdwarf2 option. */
end_comment

begin_define
define|#
directive|define
name|HAVE_AS_GDWARF2_DEBUG_FLAG
value|1
end_define

begin_comment
comment|/* Define if your assembler supports the --gstabs option. */
end_comment

begin_define
define|#
directive|define
name|HAVE_AS_GSTABS_DEBUG_FLAG
value|1
end_define

begin_comment
comment|/* Define if your linker links a mix of read-only    and read-write sections into a read-write section. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LD_RO_RW_SECTION_MIXING
value|1
end_define

begin_comment
comment|/* Define if your linker supports --eh-frame-hdr option. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LD_EH_FRAME_HDR
value|1
end_define

begin_comment
comment|/* Define if your MIPS libgloss linker scripts consistently include STARTUP directives. */
end_comment

begin_comment
comment|/* #undef HAVE_MIPS_LIBGLOSS_STARTUP_DIRECTIVES */
end_comment

begin_comment
comment|/* Define 0/1 to force the choice for exception handling model. */
end_comment

begin_comment
comment|/* #undef CONFIG_SJLJ_EXCEPTIONS */
end_comment

begin_comment
comment|/* Define if gcc should use -lunwind. */
end_comment

begin_comment
comment|/* #undef USE_LIBUNWIND_EXCEPTIONS */
end_comment

begin_comment
comment|/* Bison unconditionally undefines `const' if neither `__STDC__' nor    __cplusplus are defined.  That's a problem since we use `const' in    the GCC headers, and the resulting bison code is therefore type    unsafe.  Thus, we must match the bison behavior here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_comment
comment|/* #undef const */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

