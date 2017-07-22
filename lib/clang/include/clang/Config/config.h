begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* This generated file is for internal use. Do not include it from headers. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CLANG_CONFIG_H
end_ifdef

begin_error
error|#
directive|error
error|config.h can only be included once
end_error

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CLANG_CONFIG_H
end_define

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
comment|/* Default linker to use. */
end_comment

begin_define
define|#
directive|define
name|CLANG_DEFAULT_LINKER
value|""
end_define

begin_comment
comment|/* Default C++ stdlib to use. */
end_comment

begin_define
define|#
directive|define
name|CLANG_DEFAULT_CXX_STDLIB
value|""
end_define

begin_comment
comment|/* Default runtime library to use. */
end_comment

begin_define
define|#
directive|define
name|CLANG_DEFAULT_RTLIB
value|""
end_define

begin_comment
comment|/* Default OpenMP runtime used by -fopenmp. */
end_comment

begin_define
define|#
directive|define
name|CLANG_DEFAULT_OPENMP_RUNTIME
value|"libomp"
end_define

begin_comment
comment|/* Multilib suffix for libdir. */
end_comment

begin_define
define|#
directive|define
name|CLANG_LIBDIR_SUFFIX
value|""
end_define

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
comment|/* Directory where gcc is installed. */
end_comment

begin_define
define|#
directive|define
name|GCC_INSTALL_PREFIX
value|""
end_define

begin_comment
comment|/* Define if we have libxml2 */
end_comment

begin_comment
comment|/* #undef CLANG_HAVE_LIBXML */
end_comment

begin_comment
comment|/* Define if we have z3 and want to build it */
end_comment

begin_comment
comment|/* #undef CLANG_ANALYZER_WITH_Z3 */
end_comment

begin_comment
comment|/* Define if we have sys/resource.h (rlimits) */
end_comment

begin_define
define|#
directive|define
name|CLANG_HAVE_RLIMITS
value|1
end_define

begin_comment
comment|/* The LLVM product name and version */
end_comment

begin_define
define|#
directive|define
name|BACKEND_PACKAGE_STRING
value|"LLVM 5.0.0svn"
end_define

begin_comment
comment|/* Linker version detected at compile time. */
end_comment

begin_comment
comment|/* #undef HOST_LINK_VERSION */
end_comment

begin_comment
comment|/* pass --build-id to ld */
end_comment

begin_comment
comment|/* #undef ENABLE_LINKER_BUILD_ID */
end_comment

begin_comment
comment|/* enable x86 relax relocations by default */
end_comment

begin_define
define|#
directive|define
name|ENABLE_X86_RELAX_RELOCATIONS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

