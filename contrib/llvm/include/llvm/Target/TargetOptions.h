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
file|"llvm/MC/MCTargetOptions.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|namespace
name|FloatABI
block|{
enum|enum
name|ABIType
block|{
name|Default
block|,
comment|// Target-specific (either soft or hard depending on triple, etc).
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
name|namespace
name|JumpTable
block|{
enum|enum
name|JumpTableType
block|{
name|Single
block|,
comment|// Use a single table for all indirect jumptable calls.
name|Arity
block|,
comment|// Use one table per number of function parameters.
name|Simplified
block|,
comment|// Use one table per function type, with types projected
comment|// into 4 types: pointer to non-function, struct,
comment|// primitive, and function pointer.
name|Full
comment|// Use one table per unique function type
block|}
enum|;
block|}
name|namespace
name|ThreadModel
block|{
enum|enum
name|Model
block|{
name|POSIX
block|,
comment|// POSIX Threads
name|Single
comment|// Single Threaded Environment
block|}
enum|;
block|}
name|namespace
name|FPDenormal
block|{
enum|enum
name|DenormalMode
block|{
name|IEEE
block|,
comment|// IEEE 754 denormal numbers
name|PreserveSign
block|,
comment|// the sign of a flushed-to-zero number is preserved in
comment|// the sign of 0
name|PositiveZero
comment|// denormals are flushed to positive zero
block|}
enum|;
block|}
name|enum
name|class
name|EABI
block|{
name|Unknown
operator|,
name|Default
operator|,
comment|// Default means not specified
name|EABI4
operator|,
comment|// Target-specific (either 4, 5 or gnu depending on triple).
name|EABI5
operator|,
name|GNU
block|}
empty_stmt|;
comment|/// Identify a debugger for "tuning" the debug info.
comment|///
comment|/// The "debugger tuning" concept allows us to present a more intuitive
comment|/// interface that unpacks into different sets of defaults for the various
comment|/// individual feature-flag settings, that suit the preferences of the
comment|/// various debuggers.  However, it's worth remembering that debuggers are
comment|/// not the only consumers of debug info, and some variations in DWARF might
comment|/// better be treated as target/platform issues. Fundamentally,
comment|/// o if the feature is useful (or not) to a particular debugger, regardless
comment|///   of the target, that's a tuning decision;
comment|/// o if the feature is useful (or not) on a particular platform, regardless
comment|///   of the debugger, that's a target decision.
comment|/// It's not impossible to see both factors in some specific case.
comment|///
comment|/// The "tuning" should be used to set defaults for individual feature flags
comment|/// in DwarfDebug; if a given feature has a more specific command-line option,
comment|/// that option should take precedence over the tuning.
name|enum
name|class
name|DebuggerKind
block|{
name|Default
operator|,
comment|// No specific tuning requested.
name|GDB
operator|,
comment|// Tune debug info for gdb.
name|LLDB
operator|,
comment|// Tune debug info for lldb.
name|SCE
comment|// Tune debug info for SCE targets (e.g. PS4).
block|}
empty_stmt|;
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
name|NoTrappingFPMath
argument_list|(
name|false
argument_list|)
operator|,
name|NoSignedZerosFPMath
argument_list|(
name|false
argument_list|)
operator|,
name|HonorSignDependentRoundingFPMathOption
argument_list|(
name|false
argument_list|)
operator|,
name|NoZerosInBSS
argument_list|(
name|false
argument_list|)
operator|,
name|GuaranteedTailCallOpt
argument_list|(
name|false
argument_list|)
operator|,
name|StackSymbolOrdering
argument_list|(
name|true
argument_list|)
operator|,
name|EnableFastISel
argument_list|(
name|false
argument_list|)
operator|,
name|UseInitArray
argument_list|(
name|false
argument_list|)
operator|,
name|DisableIntegratedAS
argument_list|(
name|false
argument_list|)
operator|,
name|RelaxELFRelocations
argument_list|(
name|false
argument_list|)
operator|,
name|FunctionSections
argument_list|(
name|false
argument_list|)
operator|,
name|DataSections
argument_list|(
name|false
argument_list|)
operator|,
name|UniqueSectionNames
argument_list|(
name|true
argument_list|)
operator|,
name|TrapUnreachable
argument_list|(
name|false
argument_list|)
operator|,
name|EmulatedTLS
argument_list|(
name|false
argument_list|)
operator|,
name|EnableIPRA
argument_list|(
argument|false
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
comment|/// UnsafeFPMath - This flag is enabled when the
comment|/// -enable-unsafe-fp-math flag is specified on the command line.  When
comment|/// this flag is off (the default), the code generator is not allowed to
comment|/// produce results that are "less precise" than IEEE allows.  This includes
comment|/// use of X86 instructions like FSIN and FCOS instead of libcalls.
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
comment|/// NoTrappingFPMath - This flag is enabled when the
comment|/// -enable-no-trapping-fp-math is specified on the command line. This
comment|/// specifies that there are no trap handlers to handle exceptions.
name|unsigned
name|NoTrappingFPMath
range|:
literal|1
decl_stmt|;
comment|/// NoSignedZerosFPMath - This flag is enabled when the
comment|/// -enable-no-signed-zeros-fp-math is specified on the command line. This
comment|/// specifies that optimizations are allowed to treat the sign of a zero
comment|/// argument or result as insignificant.
name|unsigned
name|NoSignedZerosFPMath
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
comment|/// NoZerosInBSS - By default some codegens place zero-initialized data to
comment|/// .bss section. This flag disables such behaviour (necessary, e.g. for
comment|/// crt*.o compiling).
name|unsigned
name|NoZerosInBSS
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
comment|/// StackAlignmentOverride - Override default stack alignment for target.
name|unsigned
name|StackAlignmentOverride
init|=
literal|0
decl_stmt|;
comment|/// StackSymbolOrdering - When true, this will allow CodeGen to order
comment|/// the local stack symbols (for code size, code locality, or any other
comment|/// heuristics). When false, the local symbols are left in whatever order
comment|/// they were generated. Default is true.
name|unsigned
name|StackSymbolOrdering
range|:
literal|1
decl_stmt|;
comment|/// EnableFastISel - This flag enables fast-path instruction selection
comment|/// which trades away generated code quality in favor of reducing
comment|/// compile time.
name|unsigned
name|EnableFastISel
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
comment|/// Disable the integrated assembler.
name|unsigned
name|DisableIntegratedAS
range|:
literal|1
decl_stmt|;
comment|/// Compress DWARF debug sections.
name|DebugCompressionType
name|CompressDebugSections
init|=
name|DebugCompressionType
operator|::
name|None
decl_stmt|;
name|unsigned
name|RelaxELFRelocations
range|:
literal|1
decl_stmt|;
comment|/// Emit functions into separate sections.
name|unsigned
name|FunctionSections
range|:
literal|1
decl_stmt|;
comment|/// Emit data into separate sections.
name|unsigned
name|DataSections
range|:
literal|1
decl_stmt|;
name|unsigned
name|UniqueSectionNames
range|:
literal|1
decl_stmt|;
comment|/// Emit target-specific trap instruction for 'unreachable' IR instructions.
name|unsigned
name|TrapUnreachable
range|:
literal|1
decl_stmt|;
comment|/// EmulatedTLS - This flag enables emulated TLS model, using emutls
comment|/// function in the runtime library..
name|unsigned
name|EmulatedTLS
range|:
literal|1
decl_stmt|;
comment|/// This flag enables InterProcedural Register Allocation (IPRA).
name|unsigned
name|EnableIPRA
range|:
literal|1
decl_stmt|;
comment|/// FloatABIType - This setting is set by -float-abi=xxx option is specfied
comment|/// on the command line. This setting may either be Default, Soft, or Hard.
comment|/// Default selects the target's default behavior. Soft selects the ABI for
comment|/// software floating point, but does not indicate that FP hardware may not
comment|/// be used. Such a combination is unfortunately popular (e.g.
comment|/// arm-apple-darwin). Hard presumes that the normal FP ABI is used.
name|FloatABI
operator|::
name|ABIType
name|FloatABIType
operator|=
name|FloatABI
operator|::
name|Default
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
operator|=
name|FPOpFusion
operator|::
name|Standard
expr_stmt|;
comment|/// ThreadModel - This flag specifies the type of threading model to assume
comment|/// for things like atomics
name|ThreadModel
operator|::
name|Model
name|ThreadModel
operator|=
name|ThreadModel
operator|::
name|POSIX
expr_stmt|;
comment|/// EABIVersion - This flag specifies the EABI version
name|EABI
name|EABIVersion
init|=
name|EABI
operator|::
name|Default
decl_stmt|;
comment|/// Which debugger to tune for.
name|DebuggerKind
name|DebuggerTuning
init|=
name|DebuggerKind
operator|::
name|Default
decl_stmt|;
comment|/// FPDenormalMode - This flags specificies which denormal numbers the code
comment|/// is permitted to require.
name|FPDenormal
operator|::
name|DenormalMode
name|FPDenormalMode
operator|=
name|FPDenormal
operator|::
name|IEEE
expr_stmt|;
comment|/// What exception model to use
name|ExceptionHandling
name|ExceptionModel
init|=
name|ExceptionHandling
operator|::
name|None
decl_stmt|;
comment|/// Machine level options.
name|MCTargetOptions
name|MCOptions
decl_stmt|;
block|}
empty_stmt|;
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

