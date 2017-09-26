begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*===------- llvm/Config/llvm-config.h - llvm configuration -------*- C -*-===*/
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
comment|/* This file enumerates variables from the LLVM configuration so that they    can be in exported headers and won't override package specific directives.    This is a C header that can be included in the llvm-c headers. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CONFIG_H
end_define

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
value|5
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
value|"5.0.0svn"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

