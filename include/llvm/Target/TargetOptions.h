begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetOptions.h - Target Options ------------*- C++ -*-===//
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
comment|// This file defines command line option flags that are shared across various
end_comment

begin_comment
comment|// targets.
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
name|LLVM_TARGET_TARGETOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETOPTIONS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PrintMachineCode - This flag is enabled when the -print-machineinstrs
comment|/// option is specified on the command line, and should enable debugging
comment|/// output from the code generator.
specifier|extern
name|bool
name|PrintMachineCode
decl_stmt|;
comment|/// NoFramePointerElim - This flag is enabled when the -disable-fp-elim is
comment|/// specified on the command line.  If the target supports the frame pointer
comment|/// elimination optimization, this option should disable it.
specifier|extern
name|bool
name|NoFramePointerElim
decl_stmt|;
comment|/// LessPreciseFPMAD - This flag is enabled when the
comment|/// -enable-fp-mad is specified on the command line.  When this flag is off
comment|/// (the default), the code generator is not allowed to generate mad
comment|/// (multiply add) if the result is "less precise" than doing those operations
comment|/// individually.
specifier|extern
name|bool
name|LessPreciseFPMADOption
decl_stmt|;
specifier|extern
name|bool
name|LessPreciseFPMAD
parameter_list|()
function_decl|;
comment|/// NoExcessFPPrecision - This flag is enabled when the
comment|/// -disable-excess-fp-precision flag is specified on the command line.  When
comment|/// this flag is off (the default), the code generator is allowed to produce
comment|/// results that are "more precise" than IEEE allows.  This includes use of
comment|/// FMA-like operations and use of the X86 FP registers without rounding all
comment|/// over the place.
specifier|extern
name|bool
name|NoExcessFPPrecision
decl_stmt|;
comment|/// UnsafeFPMath - This flag is enabled when the
comment|/// -enable-unsafe-fp-math flag is specified on the command line.  When
comment|/// this flag is off (the default), the code generator is not allowed to
comment|/// produce results that are "less precise" than IEEE allows.  This includes
comment|/// use of X86 instructions like FSIN and FCOS instead of libcalls.
comment|/// UnsafeFPMath implies FiniteOnlyFPMath and LessPreciseFPMAD.
specifier|extern
name|bool
name|UnsafeFPMath
decl_stmt|;
comment|/// FiniteOnlyFPMath - This returns true when the -enable-finite-only-fp-math
comment|/// option is specified on the command line. If this returns false (default),
comment|/// the code generator is not allowed to assume that FP arithmetic arguments
comment|/// and results are never NaNs or +-Infs.
specifier|extern
name|bool
name|FiniteOnlyFPMathOption
decl_stmt|;
specifier|extern
name|bool
name|FiniteOnlyFPMath
parameter_list|()
function_decl|;
comment|/// HonorSignDependentRoundingFPMath - This returns true when the
comment|/// -enable-sign-dependent-rounding-fp-math is specified.  If this returns
comment|/// false (the default), the code generator is allowed to assume that the
comment|/// rounding behavior is the default (round-to-zero for all floating point to
comment|/// integer conversions, and round-to-nearest for all other arithmetic
comment|/// truncations).  If this is enabled (set to true), the code generator must
comment|/// assume that the rounding mode may dynamically change.
specifier|extern
name|bool
name|HonorSignDependentRoundingFPMathOption
decl_stmt|;
specifier|extern
name|bool
name|HonorSignDependentRoundingFPMath
parameter_list|()
function_decl|;
comment|/// UseSoftFloat - This flag is enabled when the -soft-float flag is specified
comment|/// on the command line.  When this flag is on, the code generator will
comment|/// generate libcalls to the software floating point library instead of
comment|/// target FP instructions.
specifier|extern
name|bool
name|UseSoftFloat
decl_stmt|;
comment|/// FloatABIType - This setting is set by -float-abi=xxx option is specfied
comment|/// on the command line. This setting may either be Default, Soft, or Hard.
comment|/// Default selects the target's default behavior. Soft selects the ABI for
comment|/// UseSoftFloat, but does not inidcate that FP hardware may not be used.
comment|/// Such a combination is unfortunately popular (e.g. arm-apple-darwin).
comment|/// Hard presumes that the normal FP ABI is used.
extern|extern FloatABI::ABIType FloatABIType;
comment|/// NoZerosInBSS - By default some codegens place zero-initialized data to
comment|/// .bss section. This flag disables such behaviour (necessary, e.g. for
comment|/// crt*.o compiling).
specifier|extern
name|bool
name|NoZerosInBSS
decl_stmt|;
comment|/// ExceptionHandling - This flag indicates that exception information should
comment|/// be emitted.
specifier|extern
name|bool
name|ExceptionHandling
decl_stmt|;
comment|/// UnwindTablesMandatory - This flag indicates that unwind tables should
comment|/// be emitted for all functions.
specifier|extern
name|bool
name|UnwindTablesMandatory
decl_stmt|;
comment|/// PerformTailCallOpt - This flag is enabled when -tailcallopt is specified
comment|/// on the commandline. When the flag is on, the target will perform tail call
comment|/// optimization (pop the caller's stack) providing it supports it.
specifier|extern
name|bool
name|PerformTailCallOpt
decl_stmt|;
comment|/// StackAlignment - Override default stack alignment for target.
specifier|extern
name|unsigned
name|StackAlignment
decl_stmt|;
comment|/// RealignStack - This flag indicates, whether stack should be automatically
comment|/// realigned, if needed.
specifier|extern
name|bool
name|RealignStack
decl_stmt|;
comment|/// DisableJumpTables - This flag indicates jump tables should not be
comment|/// generated.
specifier|extern
name|bool
name|DisableJumpTables
decl_stmt|;
comment|/// EnableFastISel - This flag enables fast-path instruction selection
comment|/// which trades away generated code quality in favor of reducing
comment|/// compile time.
specifier|extern
name|bool
name|EnableFastISel
decl_stmt|;
comment|/// StrongPHIElim - This flag enables more aggressive PHI elimination
comment|/// wth earlier copy coalescing.
specifier|extern
name|bool
name|StrongPHIElim
decl_stmt|;
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

