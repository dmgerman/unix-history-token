begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* include/llvm/Config/llvm-config.h.  Generated from llvm-config.h.in by configure.  */
end_comment

begin_comment
comment|/*===-- llvm/config/llvm-config.h - llvm configure variable -------*- C -*-===*/
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*                     The LLVM Compiler Infrastructure                       */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/* This file is distributed under the University of Illinois Open Source      */
end_comment

begin_comment
comment|/* License. See LICENSE.TXT for details.                                      */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*===----------------------------------------------------------------------===*/
end_comment

begin_comment
comment|/* This file enumerates all of the llvm variables from configure so that    they can be in exported headers and won't override package specific    directives.  This is a C file so we can include it in the llvm-c headers.  */
end_comment

begin_comment
comment|/* To avoid multiple inclusions of these variables when we include the exported    headers and config.h, conditionally include these.  */
end_comment

begin_comment
comment|/* TODO: This is a bit of a hack.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_H
end_ifndef

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
comment|/* Installation directory for documentation */
end_comment

begin_comment
comment|/* #undef LLVM_DOCSDIR */
end_comment

begin_comment
comment|/* Installation directory for config files */
end_comment

begin_comment
comment|/* #undef LLVM_ETCDIR */
end_comment

begin_comment
comment|/* Host triple we were built on */
end_comment

begin_comment
comment|/* #undef LLVM_HOSTTRIPLE */
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
comment|/* Installation directory for libraries */
end_comment

begin_comment
comment|/* #undef LLVM_LIBDIR */
end_comment

begin_comment
comment|/* Installation directory for man pages */
end_comment

begin_comment
comment|/* #undef LLVM_MANDIR */
end_comment

begin_comment
comment|/* Build multithreading support into LLVM */
end_comment

begin_define
define|#
directive|define
name|LLVM_MULTITHREADED
value|0
end_define

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
comment|/* LLVM name for the native AsmPrinter init function, if available */
end_comment

begin_define
define|#
directive|define
name|LLVM_NATIVE_ASMPRINTER
value|LLVMInitializeX86AsmPrinter
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
comment|/* Installation prefix directory */
end_comment

begin_comment
comment|/* #undef LLVM_PREFIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

