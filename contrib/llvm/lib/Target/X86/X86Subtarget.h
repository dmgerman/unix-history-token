begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86Subtarget.h - Define Subtarget for the X86 ----------*- C++ -*--===//
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
comment|// This file declares the X86 specific subclass of TargetSubtargetInfo.
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
name|X86SUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|X86SUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtargetInfo.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"X86GenSubtargetInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|/// PICStyles - The X86 backend supports a number of different styles of PIC.
comment|///
name|namespace
name|PICStyles
block|{
enum|enum
name|Style
block|{
name|StubPIC
block|,
comment|// Used on i386-darwin in -fPIC mode.
name|StubDynamicNoPIC
block|,
comment|// Used on i386-darwin in -mdynamic-no-pic mode.
name|GOT
block|,
comment|// Used on many 32-bit unices in -fPIC mode.
name|RIPRel
block|,
comment|// Used on X86-64 when not in -static mode.
name|None
comment|// Set when in -static mode (not PIC or DynamicNoPIC mode).
block|}
enum|;
block|}
name|class
name|X86Subtarget
range|:
name|public
name|X86GenSubtargetInfo
block|{
name|protected
operator|:
expr|enum
name|X86SSEEnum
block|{
name|NoMMXSSE
block|,
name|MMX
block|,
name|SSE1
block|,
name|SSE2
block|,
name|SSE3
block|,
name|SSSE3
block|,
name|SSE41
block|,
name|SSE42
block|,
name|AVX
block|,
name|AVX2
block|}
block|;    enum
name|X863DNowEnum
block|{
name|NoThreeDNow
block|,
name|ThreeDNow
block|,
name|ThreeDNowA
block|}
block|;    enum
name|X86ProcFamilyEnum
block|{
name|Others
block|,
name|IntelAtom
block|}
block|;
comment|/// X86ProcFamily - X86 processor family: Intel Atom, and others
name|X86ProcFamilyEnum
name|X86ProcFamily
block|;
comment|/// PICStyle - Which PIC style to use
comment|///
name|PICStyles
operator|::
name|Style
name|PICStyle
block|;
comment|/// X86SSELevel - MMX, SSE1, SSE2, SSE3, SSSE3, SSE41, SSE42, or
comment|/// none supported.
name|X86SSEEnum
name|X86SSELevel
block|;
comment|/// X863DNowLevel - 3DNow or 3DNow Athlon, or none supported.
comment|///
name|X863DNowEnum
name|X863DNowLevel
block|;
comment|/// HasCMov - True if this processor has conditional move instructions
comment|/// (generally pentium pro+).
name|bool
name|HasCMov
block|;
comment|/// HasX86_64 - True if the processor supports X86-64 instructions.
comment|///
name|bool
name|HasX86_64
block|;
comment|/// HasPOPCNT - True if the processor supports POPCNT.
name|bool
name|HasPOPCNT
block|;
comment|/// HasSSE4A - True if the processor supports SSE4A instructions.
name|bool
name|HasSSE4A
block|;
comment|/// HasAES - Target has AES instructions
name|bool
name|HasAES
block|;
comment|/// HasPCLMUL - Target has carry-less multiplication
name|bool
name|HasPCLMUL
block|;
comment|/// HasFMA - Target has 3-operand fused multiply-add
name|bool
name|HasFMA
block|;
comment|/// HasFMA4 - Target has 4-operand fused multiply-add
name|bool
name|HasFMA4
block|;
comment|/// HasXOP - Target has XOP instructions
name|bool
name|HasXOP
block|;
comment|/// HasMOVBE - True if the processor has the MOVBE instruction.
name|bool
name|HasMOVBE
block|;
comment|/// HasRDRAND - True if the processor has the RDRAND instruction.
name|bool
name|HasRDRAND
block|;
comment|/// HasF16C - Processor has 16-bit floating point conversion instructions.
name|bool
name|HasF16C
block|;
comment|/// HasFSGSBase - Processor has FS/GS base insturctions.
name|bool
name|HasFSGSBase
block|;
comment|/// HasLZCNT - Processor has LZCNT instruction.
name|bool
name|HasLZCNT
block|;
comment|/// HasBMI - Processor has BMI1 instructions.
name|bool
name|HasBMI
block|;
comment|/// HasBMI2 - Processor has BMI2 instructions.
name|bool
name|HasBMI2
block|;
comment|/// HasRTM - Processor has RTM instructions.
name|bool
name|HasRTM
block|;
comment|/// HasHLE - Processor has HLE.
name|bool
name|HasHLE
block|;
comment|/// HasADX - Processor has ADX instructions.
name|bool
name|HasADX
block|;
comment|/// HasPRFCHW - Processor has PRFCHW instructions.
name|bool
name|HasPRFCHW
block|;
comment|/// HasRDSEED - Processor has RDSEED instructions.
name|bool
name|HasRDSEED
block|;
comment|/// IsBTMemSlow - True if BT (bit test) of memory instructions are slow.
name|bool
name|IsBTMemSlow
block|;
comment|/// IsUAMemFast - True if unaligned memory access is fast.
name|bool
name|IsUAMemFast
block|;
comment|/// HasVectorUAMem - True if SIMD operations can have unaligned memory
comment|/// operands. This may require setting a feature bit in the processor.
name|bool
name|HasVectorUAMem
block|;
comment|/// HasCmpxchg16b - True if this processor has the CMPXCHG16B instruction;
comment|/// this is true for most x86-64 chips, but not the first AMD chips.
name|bool
name|HasCmpxchg16b
block|;
comment|/// UseLeaForSP - True if the LEA instruction should be used for adjusting
comment|/// the stack pointer. This is an optimization for Intel Atom processors.
name|bool
name|UseLeaForSP
block|;
comment|/// HasSlowDivide - True if smaller divides are significantly faster than
comment|/// full divides and should be used when possible.
name|bool
name|HasSlowDivide
block|;
comment|/// PostRAScheduler - True if using post-register-allocation scheduler.
name|bool
name|PostRAScheduler
block|;
comment|/// PadShortFunctions - True if the short functions should be padded to prevent
comment|/// a stall when returning too early.
name|bool
name|PadShortFunctions
block|;
comment|/// CallRegIndirect - True if the Calls with memory reference should be converted
comment|/// to a register-based indirect call.
name|bool
name|CallRegIndirect
block|;
comment|/// stackAlignment - The minimum alignment known to hold of the stack frame on
comment|/// entry to the function and which must be maintained by every function.
name|unsigned
name|stackAlignment
block|;
comment|/// Max. memset / memcpy size that is turned into rep/movs, rep/stos ops.
comment|///
name|unsigned
name|MaxInlineSizeThreshold
block|;
comment|/// TargetTriple - What processor and OS we're targeting.
name|Triple
name|TargetTriple
block|;
comment|/// Instruction itineraries for scheduling
name|InstrItineraryData
name|InstrItins
block|;
name|private
operator|:
comment|/// StackAlignOverride - Override the stack alignment.
name|unsigned
name|StackAlignOverride
block|;
comment|/// In64BitMode - True if compiling for 64-bit, false for 32-bit.
name|bool
name|In64BitMode
block|;
name|public
operator|:
comment|/// This constructor initializes the data members to match that
comment|/// of the specified triple.
comment|///
name|X86Subtarget
argument_list|(
argument|const std::string&TT
argument_list|,
argument|const std::string&CPU
argument_list|,
argument|const std::string&FS
argument_list|,
argument|unsigned StackAlignOverride
argument_list|,
argument|bool is64Bit
argument_list|)
block|;
comment|/// getStackAlignment - Returns the minimum alignment known to hold of the
comment|/// stack frame on entry to the function and which must be maintained by every
comment|/// function for this subtarget.
name|unsigned
name|getStackAlignment
argument_list|()
specifier|const
block|{
return|return
name|stackAlignment
return|;
block|}
comment|/// getMaxInlineSizeThreshold - Returns the maximum memset / memcpy size
comment|/// that still makes it profitable to inline the call.
name|unsigned
name|getMaxInlineSizeThreshold
argument_list|()
specifier|const
block|{
return|return
name|MaxInlineSizeThreshold
return|;
block|}
comment|/// ParseSubtargetFeatures - Parses features string setting specified
comment|/// subtarget options.  Definition of function is auto generated by tblgen.
name|void
name|ParseSubtargetFeatures
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|)
block|;
comment|/// AutoDetectSubtargetFeatures - Auto-detect CPU features using CPUID
comment|/// instruction.
name|void
name|AutoDetectSubtargetFeatures
argument_list|()
block|;
comment|/// \brief Reset the features for the X86 target.
name|virtual
name|void
name|resetSubtargetFeatures
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
name|private
operator|:
name|void
name|initializeEnvironment
argument_list|()
block|;
name|void
name|resetSubtargetFeatures
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|)
block|;
name|public
operator|:
comment|/// Is this x86_64? (disregarding specific ABI / programming model)
name|bool
name|is64Bit
argument_list|()
specifier|const
block|{
return|return
name|In64BitMode
return|;
block|}
comment|/// Is this x86_64 with the ILP32 programming model (x32 ABI)?
name|bool
name|isTarget64BitILP32
argument_list|()
specifier|const
block|{
return|return
name|In64BitMode
operator|&&
operator|(
name|TargetTriple
operator|.
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|GNUX32
operator|)
return|;
block|}
comment|/// Is this x86_64 with the LP64 programming model (standard AMD64, no x32)?
name|bool
name|isTarget64BitLP64
argument_list|()
specifier|const
block|{
return|return
name|In64BitMode
operator|&&
operator|(
name|TargetTriple
operator|.
name|getEnvironment
argument_list|()
operator|!=
name|Triple
operator|::
name|GNUX32
operator|)
return|;
block|}
name|PICStyles
operator|::
name|Style
name|getPICStyle
argument_list|()
specifier|const
block|{
return|return
name|PICStyle
return|;
block|}
name|void
name|setPICStyle
argument_list|(
argument|PICStyles::Style Style
argument_list|)
block|{
name|PICStyle
operator|=
name|Style
block|; }
name|bool
name|hasCMov
argument_list|()
specifier|const
block|{
return|return
name|HasCMov
return|;
block|}
name|bool
name|hasMMX
argument_list|()
specifier|const
block|{
return|return
name|X86SSELevel
operator|>=
name|MMX
return|;
block|}
name|bool
name|hasSSE1
argument_list|()
specifier|const
block|{
return|return
name|X86SSELevel
operator|>=
name|SSE1
return|;
block|}
name|bool
name|hasSSE2
argument_list|()
specifier|const
block|{
return|return
name|X86SSELevel
operator|>=
name|SSE2
return|;
block|}
name|bool
name|hasSSE3
argument_list|()
specifier|const
block|{
return|return
name|X86SSELevel
operator|>=
name|SSE3
return|;
block|}
name|bool
name|hasSSSE3
argument_list|()
specifier|const
block|{
return|return
name|X86SSELevel
operator|>=
name|SSSE3
return|;
block|}
name|bool
name|hasSSE41
argument_list|()
specifier|const
block|{
return|return
name|X86SSELevel
operator|>=
name|SSE41
return|;
block|}
name|bool
name|hasSSE42
argument_list|()
specifier|const
block|{
return|return
name|X86SSELevel
operator|>=
name|SSE42
return|;
block|}
name|bool
name|hasAVX
argument_list|()
specifier|const
block|{
return|return
name|X86SSELevel
operator|>=
name|AVX
return|;
block|}
name|bool
name|hasAVX2
argument_list|()
specifier|const
block|{
return|return
name|X86SSELevel
operator|>=
name|AVX2
return|;
block|}
name|bool
name|hasFp256
argument_list|()
specifier|const
block|{
return|return
name|hasAVX
argument_list|()
return|;
block|}
name|bool
name|hasInt256
argument_list|()
specifier|const
block|{
return|return
name|hasAVX2
argument_list|()
return|;
block|}
name|bool
name|hasSSE4A
argument_list|()
specifier|const
block|{
return|return
name|HasSSE4A
return|;
block|}
name|bool
name|has3DNow
argument_list|()
specifier|const
block|{
return|return
name|X863DNowLevel
operator|>=
name|ThreeDNow
return|;
block|}
name|bool
name|has3DNowA
argument_list|()
specifier|const
block|{
return|return
name|X863DNowLevel
operator|>=
name|ThreeDNowA
return|;
block|}
name|bool
name|hasPOPCNT
argument_list|()
specifier|const
block|{
return|return
name|HasPOPCNT
return|;
block|}
name|bool
name|hasAES
argument_list|()
specifier|const
block|{
return|return
name|HasAES
return|;
block|}
name|bool
name|hasPCLMUL
argument_list|()
specifier|const
block|{
return|return
name|HasPCLMUL
return|;
block|}
name|bool
name|hasFMA
argument_list|()
specifier|const
block|{
return|return
name|HasFMA
return|;
block|}
comment|// FIXME: Favor FMA when both are enabled. Is this the right thing to do?
name|bool
name|hasFMA4
argument_list|()
specifier|const
block|{
return|return
name|HasFMA4
operator|&&
operator|!
name|HasFMA
return|;
block|}
name|bool
name|hasXOP
argument_list|()
specifier|const
block|{
return|return
name|HasXOP
return|;
block|}
name|bool
name|hasMOVBE
argument_list|()
specifier|const
block|{
return|return
name|HasMOVBE
return|;
block|}
name|bool
name|hasRDRAND
argument_list|()
specifier|const
block|{
return|return
name|HasRDRAND
return|;
block|}
name|bool
name|hasF16C
argument_list|()
specifier|const
block|{
return|return
name|HasF16C
return|;
block|}
name|bool
name|hasFSGSBase
argument_list|()
specifier|const
block|{
return|return
name|HasFSGSBase
return|;
block|}
name|bool
name|hasLZCNT
argument_list|()
specifier|const
block|{
return|return
name|HasLZCNT
return|;
block|}
name|bool
name|hasBMI
argument_list|()
specifier|const
block|{
return|return
name|HasBMI
return|;
block|}
name|bool
name|hasBMI2
argument_list|()
specifier|const
block|{
return|return
name|HasBMI2
return|;
block|}
name|bool
name|hasRTM
argument_list|()
specifier|const
block|{
return|return
name|HasRTM
return|;
block|}
name|bool
name|hasHLE
argument_list|()
specifier|const
block|{
return|return
name|HasHLE
return|;
block|}
name|bool
name|hasADX
argument_list|()
specifier|const
block|{
return|return
name|HasADX
return|;
block|}
name|bool
name|hasPRFCHW
argument_list|()
specifier|const
block|{
return|return
name|HasPRFCHW
return|;
block|}
name|bool
name|hasRDSEED
argument_list|()
specifier|const
block|{
return|return
name|HasRDSEED
return|;
block|}
name|bool
name|isBTMemSlow
argument_list|()
specifier|const
block|{
return|return
name|IsBTMemSlow
return|;
block|}
name|bool
name|isUnalignedMemAccessFast
argument_list|()
specifier|const
block|{
return|return
name|IsUAMemFast
return|;
block|}
name|bool
name|hasVectorUAMem
argument_list|()
specifier|const
block|{
return|return
name|HasVectorUAMem
return|;
block|}
name|bool
name|hasCmpxchg16b
argument_list|()
specifier|const
block|{
return|return
name|HasCmpxchg16b
return|;
block|}
name|bool
name|useLeaForSP
argument_list|()
specifier|const
block|{
return|return
name|UseLeaForSP
return|;
block|}
name|bool
name|hasSlowDivide
argument_list|()
specifier|const
block|{
return|return
name|HasSlowDivide
return|;
block|}
name|bool
name|padShortFunctions
argument_list|()
specifier|const
block|{
return|return
name|PadShortFunctions
return|;
block|}
name|bool
name|callRegIndirect
argument_list|()
specifier|const
block|{
return|return
name|CallRegIndirect
return|;
block|}
name|bool
name|isAtom
argument_list|()
specifier|const
block|{
return|return
name|X86ProcFamily
operator|==
name|IntelAtom
return|;
block|}
specifier|const
name|Triple
operator|&
name|getTargetTriple
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
return|;
block|}
name|bool
name|isTargetDarwin
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|isOSDarwin
argument_list|()
return|;
block|}
name|bool
name|isTargetFreeBSD
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|FreeBSD
return|;
block|}
name|bool
name|isTargetSolaris
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Solaris
return|;
block|}
name|bool
name|isTargetELF
argument_list|()
specifier|const
block|{
return|return
operator|(
name|TargetTriple
operator|.
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|ELF
operator|||
name|TargetTriple
operator|.
name|isOSBinFormatELF
argument_list|()
operator|)
return|;
block|}
name|bool
name|isTargetLinux
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Linux
return|;
block|}
name|bool
name|isTargetNaCl
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|NaCl
return|;
block|}
name|bool
name|isTargetNaCl32
argument_list|()
specifier|const
block|{
return|return
name|isTargetNaCl
argument_list|()
operator|&&
operator|!
name|is64Bit
argument_list|()
return|;
block|}
name|bool
name|isTargetNaCl64
argument_list|()
specifier|const
block|{
return|return
name|isTargetNaCl
argument_list|()
operator|&&
name|is64Bit
argument_list|()
return|;
block|}
name|bool
name|isTargetWindows
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Win32
return|;
block|}
name|bool
name|isTargetMingw
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|MinGW32
return|;
block|}
name|bool
name|isTargetCygwin
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Cygwin
return|;
block|}
name|bool
name|isTargetCygMing
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|isOSCygMing
argument_list|()
return|;
block|}
name|bool
name|isTargetCOFF
argument_list|()
specifier|const
block|{
return|return
operator|(
name|TargetTriple
operator|.
name|getEnvironment
argument_list|()
operator|!=
name|Triple
operator|::
name|ELF
operator|&&
name|TargetTriple
operator|.
name|isOSBinFormatCOFF
argument_list|()
operator|)
return|;
block|}
name|bool
name|isTargetEnvMacho
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|isEnvironmentMachO
argument_list|()
return|;
block|}
name|bool
name|isTargetWin64
argument_list|()
specifier|const
block|{
comment|// FIXME: x86_64-cygwin has not been released yet.
return|return
name|In64BitMode
operator|&&
name|TargetTriple
operator|.
name|isOSWindows
argument_list|()
return|;
block|}
name|bool
name|isTargetWin32
argument_list|()
specifier|const
block|{
comment|// FIXME: Cygwin is included for isTargetWin64 -- should it be included
comment|// here too?
return|return
operator|!
name|In64BitMode
operator|&&
operator|(
name|isTargetMingw
argument_list|()
operator|||
name|isTargetWindows
argument_list|()
operator|)
return|;
block|}
name|bool
name|isPICStyleSet
argument_list|()
specifier|const
block|{
return|return
name|PICStyle
operator|!=
name|PICStyles
operator|::
name|None
return|;
block|}
name|bool
name|isPICStyleGOT
argument_list|()
specifier|const
block|{
return|return
name|PICStyle
operator|==
name|PICStyles
operator|::
name|GOT
return|;
block|}
name|bool
name|isPICStyleRIPRel
argument_list|()
specifier|const
block|{
return|return
name|PICStyle
operator|==
name|PICStyles
operator|::
name|RIPRel
return|;
block|}
name|bool
name|isPICStyleStubPIC
argument_list|()
specifier|const
block|{
return|return
name|PICStyle
operator|==
name|PICStyles
operator|::
name|StubPIC
return|;
block|}
name|bool
name|isPICStyleStubNoDynamic
argument_list|()
specifier|const
block|{
return|return
name|PICStyle
operator|==
name|PICStyles
operator|::
name|StubDynamicNoPIC
return|;
block|}
name|bool
name|isPICStyleStubAny
argument_list|()
specifier|const
block|{
return|return
name|PICStyle
operator|==
name|PICStyles
operator|::
name|StubDynamicNoPIC
operator|||
name|PICStyle
operator|==
name|PICStyles
operator|::
name|StubPIC
return|;
block|}
comment|/// ClassifyGlobalReference - Classify a global variable reference for the
comment|/// current subtarget according to how we should reference it in a non-pcrel
comment|/// context.
name|unsigned
name|char
name|ClassifyGlobalReference
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
comment|/// ClassifyBlockAddressReference - Classify a blockaddress reference for the
comment|/// current subtarget according to how we should reference it in a non-pcrel
comment|/// context.
name|unsigned
name|char
name|ClassifyBlockAddressReference
argument_list|()
specifier|const
block|;
comment|/// IsLegalToCallImmediateAddr - Return true if the subtarget allows calls
comment|/// to immediate address.
name|bool
name|IsLegalToCallImmediateAddr
argument_list|(
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
comment|/// This function returns the name of a function which has an interface
comment|/// like the non-standard bzero function, if such a function exists on
comment|/// the current subtarget and it is considered prefereable over
comment|/// memset with zero passed as the second argument. Otherwise it
comment|/// returns null.
specifier|const
name|char
operator|*
name|getBZeroEntry
argument_list|()
specifier|const
block|;
comment|/// This function returns true if the target has sincos() routine in its
comment|/// compiler runtime or math libraries.
name|bool
name|hasSinCos
argument_list|()
specifier|const
block|;
comment|/// enablePostRAScheduler - run for Atom optimization.
name|bool
name|enablePostRAScheduler
argument_list|(
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|TargetSubtargetInfo::AntiDepBreakMode& Mode
argument_list|,
argument|RegClassVector& CriticalPathRCs
argument_list|)
specifier|const
block|;
name|bool
name|postRAScheduler
argument_list|()
specifier|const
block|{
return|return
name|PostRAScheduler
return|;
block|}
comment|/// getInstrItins = Return the instruction itineraries based on the
comment|/// subtarget selection.
specifier|const
name|InstrItineraryData
operator|&
name|getInstrItineraryData
argument_list|()
specifier|const
block|{
return|return
name|InstrItins
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

