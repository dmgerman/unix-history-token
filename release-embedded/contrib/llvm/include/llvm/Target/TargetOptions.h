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

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
comment|// Possible float ABI settings. Used with FloatABIType in TargetOptions.h.
name|namespace
name|FloatABI
block|{
enum|enum
name|ABIType
block|{
name|Default
block|,
comment|// Target-specific (either soft or hard depending on triple,etc).
name|Soft
block|,
comment|// Soft float.
name|Hard
comment|// Hard float.
block|}
enum|;
block|}
name|namespace
name|FPOpFusion
block|{
enum|enum
name|FPOpFusionMode
block|{
name|Fast
block|,
comment|// Enable fusion of FP ops wherever it's profitable.
name|Standard
block|,
comment|// Only allow fusion of 'blessed' ops (currently just fmuladd).
name|Strict
comment|// Never fuse FP-ops.
block|}
enum|;
block|}
name|class
name|TargetOptions
block|{
name|public
label|:
name|TargetOptions
argument_list|()
operator|:
name|PrintMachineCode
argument_list|(
name|false
argument_list|)
operator|,
name|NoFramePointerElim
argument_list|(
name|false
argument_list|)
operator|,
name|LessPreciseFPMADOption
argument_list|(
name|false
argument_list|)
operator|,
name|UnsafeFPMath
argument_list|(
name|false
argument_list|)
operator|,
name|NoInfsFPMath
argument_list|(
name|false
argument_list|)
operator|,
name|NoNaNsFPMath
argument_list|(
name|false
argument_list|)
operator|,
name|HonorSignDependentRoundingFPMathOption
argument_list|(
name|false
argument_list|)
operator|,
name|UseSoftFloat
argument_list|(
name|false
argument_list|)
operator|,
name|NoZerosInBSS
argument_list|(
name|false
argument_list|)
operator|,
name|JITEmitDebugInfo
argument_list|(
name|false
argument_list|)
operator|,
name|JITEmitDebugInfoToDisk
argument_list|(
name|false
argument_list|)
operator|,
name|GuaranteedTailCallOpt
argument_list|(
name|false
argument_list|)
operator|,
name|DisableTailCalls
argument_list|(
name|false
argument_list|)
operator|,
name|StackAlignmentOverride
argument_list|(
literal|0
argument_list|)
operator|,
name|EnableFastISel
argument_list|(
name|false
argument_list|)
operator|,
name|PositionIndependentExecutable
argument_list|(
name|false
argument_list|)
operator|,
name|EnableSegmentedStacks
argument_list|(
name|false
argument_list|)
operator|,
name|UseInitArray
argument_list|(
name|false
argument_list|)
operator|,
name|TrapFuncName
argument_list|(
literal|""
argument_list|)
operator|,
name|FloatABIType
argument_list|(
name|FloatABI
operator|::
name|Default
argument_list|)
operator|,
name|AllowFPOpFusion
argument_list|(
argument|FPOpFusion::Standard
argument_list|)
block|{}
comment|/// PrintMachineCode - This flag is enabled when the -print-machineinstrs
comment|/// option is specified on the command line, and should enable debugging
comment|/// output from the code generator.
name|unsigned
name|PrintMachineCode
operator|:
literal|1
expr_stmt|;
comment|/// NoFramePointerElim - This flag is enabled when the -disable-fp-elim is
comment|/// specified on the command line.  If the target supports the frame pointer
comment|/// elimination optimization, this option should disable it.
name|unsigned
name|NoFramePointerElim
range|:
literal|1
decl_stmt|;
comment|/// DisableFramePointerElim - This returns true if frame pointer elimination
comment|/// optimization should be disabled for the given machine function.
name|bool
name|DisableFramePointerElim
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
decl_stmt|;
comment|/// LessPreciseFPMAD - This flag is enabled when the
comment|/// -enable-fp-mad is specified on the command line.  When this flag is off
comment|/// (the default), the code generator is not allowed to generate mad
comment|/// (multiply add) if the result is "less precise" than doing those
comment|/// operations individually.
name|unsigned
name|LessPreciseFPMADOption
range|:
literal|1
decl_stmt|;
name|bool
name|LessPreciseFPMAD
argument_list|()
specifier|const
expr_stmt|;
comment|/// UnsafeFPMath - This flag is enabled when the
comment|/// -enable-unsafe-fp-math flag is specified on the command line.  When
comment|/// this flag is off (the default), the code generator is not allowed to
comment|/// produce results that are "less precise" than IEEE allows.  This includes
comment|/// use of X86 instructions like FSIN and FCOS instead of libcalls.
comment|/// UnsafeFPMath implies LessPreciseFPMAD.
name|unsigned
name|UnsafeFPMath
range|:
literal|1
decl_stmt|;
comment|/// NoInfsFPMath - This flag is enabled when the
comment|/// -enable-no-infs-fp-math flag is specified on the command line. When
comment|/// this flag is off (the default), the code generator is not allowed to
comment|/// assume the FP arithmetic arguments and results are never +-Infs.
name|unsigned
name|NoInfsFPMath
range|:
literal|1
decl_stmt|;
comment|/// NoNaNsFPMath - This flag is enabled when the
comment|/// -enable-no-nans-fp-math flag is specified on the command line. When
comment|/// this flag is off (the default), the code generator is not allowed to
comment|/// assume the FP arithmetic arguments and results are never NaNs.
name|unsigned
name|NoNaNsFPMath
range|:
literal|1
decl_stmt|;
comment|/// HonorSignDependentRoundingFPMath - This returns true when the
comment|/// -enable-sign-dependent-rounding-fp-math is specified.  If this returns
comment|/// false (the default), the code generator is allowed to assume that the
comment|/// rounding behavior is the default (round-to-zero for all floating point
comment|/// to integer conversions, and round-to-nearest for all other arithmetic
comment|/// truncations).  If this is enabled (set to true), the code generator must
comment|/// assume that the rounding mode may dynamically change.
name|unsigned
name|HonorSignDependentRoundingFPMathOption
range|:
literal|1
decl_stmt|;
name|bool
name|HonorSignDependentRoundingFPMath
argument_list|()
specifier|const
expr_stmt|;
comment|/// UseSoftFloat - This flag is enabled when the -soft-float flag is
comment|/// specified on the command line.  When this flag is on, the code generator
comment|/// will generate libcalls to the software floating point library instead of
comment|/// target FP instructions.
name|unsigned
name|UseSoftFloat
range|:
literal|1
decl_stmt|;
comment|/// NoZerosInBSS - By default some codegens place zero-initialized data to
comment|/// .bss section. This flag disables such behaviour (necessary, e.g. for
comment|/// crt*.o compiling).
name|unsigned
name|NoZerosInBSS
range|:
literal|1
decl_stmt|;
comment|/// JITEmitDebugInfo - This flag indicates that the JIT should try to emit
comment|/// debug information and notify a debugger about it.
name|unsigned
name|JITEmitDebugInfo
range|:
literal|1
decl_stmt|;
comment|/// JITEmitDebugInfoToDisk - This flag indicates that the JIT should write
comment|/// the object files generated by the JITEmitDebugInfo flag to disk.  This
comment|/// flag is hidden and is only for debugging the debug info.
name|unsigned
name|JITEmitDebugInfoToDisk
range|:
literal|1
decl_stmt|;
comment|/// GuaranteedTailCallOpt - This flag is enabled when -tailcallopt is
comment|/// specified on the commandline. When the flag is on, participating targets
comment|/// will perform tail call optimization on all calls which use the fastcc
comment|/// calling convention and which satisfy certain target-independent
comment|/// criteria (being at the end of a function, having the same return type
comment|/// as their parent function, etc.), using an alternate ABI if necessary.
name|unsigned
name|GuaranteedTailCallOpt
range|:
literal|1
decl_stmt|;
comment|/// DisableTailCalls - This flag controls whether we will use tail calls.
comment|/// Disabling them may be useful to maintain a correct call stack.
name|unsigned
name|DisableTailCalls
range|:
literal|1
decl_stmt|;
comment|/// StackAlignmentOverride - Override default stack alignment for target.
name|unsigned
name|StackAlignmentOverride
decl_stmt|;
comment|/// EnableFastISel - This flag enables fast-path instruction selection
comment|/// which trades away generated code quality in favor of reducing
comment|/// compile time.
name|unsigned
name|EnableFastISel
range|:
literal|1
decl_stmt|;
comment|/// PositionIndependentExecutable - This flag indicates whether the code
comment|/// will eventually be linked into a single executable, despite the PIC
comment|/// relocation model being in use. It's value is undefined (and irrelevant)
comment|/// if the relocation model is anything other than PIC.
name|unsigned
name|PositionIndependentExecutable
range|:
literal|1
decl_stmt|;
name|unsigned
name|EnableSegmentedStacks
range|:
literal|1
decl_stmt|;
comment|/// UseInitArray - Use .init_array instead of .ctors for static
comment|/// constructors.
name|unsigned
name|UseInitArray
range|:
literal|1
decl_stmt|;
comment|/// getTrapFunctionName - If this returns a non-empty string, this means
comment|/// isel should lower Intrinsic::trap to a call to the specified function
comment|/// name instead of an ISD::TRAP node.
name|std
operator|::
name|string
name|TrapFuncName
expr_stmt|;
name|StringRef
name|getTrapFunctionName
argument_list|()
specifier|const
expr_stmt|;
comment|/// FloatABIType - This setting is set by -float-abi=xxx option is specfied
comment|/// on the command line. This setting may either be Default, Soft, or Hard.
comment|/// Default selects the target's default behavior. Soft selects the ABI for
comment|/// UseSoftFloat, but does not indicate that FP hardware may not be used.
comment|/// Such a combination is unfortunately popular (e.g. arm-apple-darwin).
comment|/// Hard presumes that the normal FP ABI is used.
name|FloatABI
operator|::
name|ABIType
name|FloatABIType
expr_stmt|;
comment|/// AllowFPOpFusion - This flag is set by the -fuse-fp-ops=xxx option.
comment|/// This controls the creation of fused FP ops that store intermediate
comment|/// results in higher precision than IEEE allows (E.g. FMAs).
comment|///
comment|/// Fast mode - allows formation of fused FP ops whenever they're
comment|/// profitable.
comment|/// Standard mode - allow fusion only for 'blessed' FP ops. At present the
comment|/// only blessed op is the fmuladd intrinsic. In the future more blessed ops
comment|/// may be added.
comment|/// Strict mode - allow fusion only if/when it can be proven that the excess
comment|/// precision won't effect the result.
comment|///
comment|/// Note: This option only controls formation of fused ops by the
comment|/// optimizers.  Fused operations that are explicitly specified (e.g. FMA
comment|/// via the llvm.fma.* intrinsic) will always be honored, regardless of
comment|/// the value of this option.
name|FPOpFusion
operator|::
name|FPOpFusionMode
name|AllowFPOpFusion
expr_stmt|;
block|}
empty_stmt|;
comment|// Comparison operators:
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|TargetOptions
operator|&
name|LHS
operator|,
specifier|const
name|TargetOptions
operator|&
name|RHS
operator|)
block|{
define|#
directive|define
name|ARE_EQUAL
parameter_list|(
name|X
parameter_list|)
value|LHS.X == RHS.X
return|return
name|ARE_EQUAL
argument_list|(
name|UnsafeFPMath
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|NoInfsFPMath
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|NoNaNsFPMath
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|HonorSignDependentRoundingFPMathOption
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|UseSoftFloat
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|NoZerosInBSS
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|JITEmitDebugInfo
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|JITEmitDebugInfoToDisk
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|GuaranteedTailCallOpt
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|DisableTailCalls
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|StackAlignmentOverride
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|EnableFastISel
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|PositionIndependentExecutable
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|EnableSegmentedStacks
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|UseInitArray
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|TrapFuncName
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|FloatABIType
argument_list|)
operator|&&
name|ARE_EQUAL
argument_list|(
name|AllowFPOpFusion
argument_list|)
return|;
undef|#
directive|undef
name|ARE_EQUAL
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|TargetOptions
operator|&
name|LHS
operator|,
specifier|const
name|TargetOptions
operator|&
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
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

