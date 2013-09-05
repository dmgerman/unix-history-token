begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CallingConv.h - LLVM Calling Conventions -----------*- C++ -*-===//
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
comment|// This file defines LLVM's set of calling conventions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_IR_CALLINGCONV_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_CALLINGCONV_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// CallingConv Namespace - This namespace contains an enum with a value for
comment|/// the well-known calling conventions.
comment|///
name|namespace
name|CallingConv
block|{
comment|/// A set of enums which specify the assigned numeric values for known llvm
comment|/// calling conventions.
comment|/// @brief LLVM Calling Convention Representation
enum|enum
name|ID
block|{
comment|/// C - The default llvm calling convention, compatible with C.  This
comment|/// convention is the only calling convention that supports varargs calls.
comment|/// As with typical C calling conventions, the callee/caller have to
comment|/// tolerate certain amounts of prototype mismatch.
name|C
init|=
literal|0
block|,
comment|// Generic LLVM calling conventions.  None of these calling conventions
comment|// support varargs calls, and all assume that the caller and callee
comment|// prototype exactly match.
comment|/// Fast - This calling convention attempts to make calls as fast as
comment|/// possible (e.g. by passing things in registers).
name|Fast
init|=
literal|8
block|,
comment|// Cold - This calling convention attempts to make code in the caller as
comment|// efficient as possible under the assumption that the call is not commonly
comment|// executed.  As such, these calls often preserve all registers so that the
comment|// call does not break any live ranges in the caller side.
name|Cold
init|=
literal|9
block|,
comment|// GHC - Calling convention used by the Glasgow Haskell Compiler (GHC).
name|GHC
init|=
literal|10
block|,
comment|// HiPE - Calling convention used by the High-Performance Erlang Compiler
comment|// (HiPE).
name|HiPE
init|=
literal|11
block|,
comment|// Target - This is the start of the target-specific calling conventions,
comment|// e.g. fastcall and thiscall on X86.
name|FirstTargetCC
init|=
literal|64
block|,
comment|/// X86_StdCall - stdcall is the calling conventions mostly used by the
comment|/// Win32 API. It is basically the same as the C convention with the
comment|/// difference in that the callee is responsible for popping the arguments
comment|/// from the stack.
name|X86_StdCall
init|=
literal|64
block|,
comment|/// X86_FastCall - 'fast' analog of X86_StdCall. Passes first two arguments
comment|/// in ECX:EDX registers, others - via stack. Callee is responsible for
comment|/// stack cleaning.
name|X86_FastCall
init|=
literal|65
block|,
comment|/// ARM_APCS - ARM Procedure Calling Standard calling convention (obsolete,
comment|/// but still used on some targets).
name|ARM_APCS
init|=
literal|66
block|,
comment|/// ARM_AAPCS - ARM Architecture Procedure Calling Standard calling
comment|/// convention (aka EABI). Soft float variant.
name|ARM_AAPCS
init|=
literal|67
block|,
comment|/// ARM_AAPCS_VFP - Same as ARM_AAPCS, but uses hard floating point ABI.
name|ARM_AAPCS_VFP
init|=
literal|68
block|,
comment|/// MSP430_INTR - Calling convention used for MSP430 interrupt routines.
name|MSP430_INTR
init|=
literal|69
block|,
comment|/// X86_ThisCall - Similar to X86_StdCall. Passes first argument in ECX,
comment|/// others via stack. Callee is responsible for stack cleaning. MSVC uses
comment|/// this by default for methods in its ABI.
name|X86_ThisCall
init|=
literal|70
block|,
comment|/// PTX_Kernel - Call to a PTX kernel.
comment|/// Passes all arguments in parameter space.
name|PTX_Kernel
init|=
literal|71
block|,
comment|/// PTX_Device - Call to a PTX device function.
comment|/// Passes all arguments in register or parameter space.
name|PTX_Device
init|=
literal|72
block|,
comment|/// MBLAZE_INTR - Calling convention used for MBlaze interrupt routines.
name|MBLAZE_INTR
init|=
literal|73
block|,
comment|/// MBLAZE_INTR - Calling convention used for MBlaze interrupt support
comment|/// routines (i.e. GCC's save_volatiles attribute).
name|MBLAZE_SVOL
init|=
literal|74
block|,
comment|/// SPIR_FUNC - Calling convention for SPIR non-kernel device functions.
comment|/// No lowering or expansion of arguments.
comment|/// Structures are passed as a pointer to a struct with the byval attribute.
comment|/// Functions can only call SPIR_FUNC and SPIR_KERNEL functions.
comment|/// Functions can only have zero or one return values.
comment|/// Variable arguments are not allowed, except for printf.
comment|/// How arguments/return values are lowered are not specified.
comment|/// Functions are only visible to the devices.
name|SPIR_FUNC
init|=
literal|75
block|,
comment|/// SPIR_KERNEL - Calling convention for SPIR kernel functions.
comment|/// Inherits the restrictions of SPIR_FUNC, except
comment|/// Cannot have non-void return values.
comment|/// Cannot have variable arguments.
comment|/// Can also be called by the host.
comment|/// Is externally visible.
name|SPIR_KERNEL
init|=
literal|76
block|,
comment|/// Intel_OCL_BI - Calling conventions for Intel OpenCL built-ins
name|Intel_OCL_BI
init|=
literal|77
block|}
enum|;
block|}
comment|// End CallingConv namespace
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

