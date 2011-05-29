begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====---- X86Subtarget.h - Define Subtarget for the X86 -----*- C++ -*--====//
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
comment|// This file declares the X86 specific subclass of TargetSubtarget.
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
file|"llvm/Target/TargetSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CallingConv.h"
end_include

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
name|GlobalValue
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
name|TargetSubtarget
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
comment|/// HasAVX - Target has AVX instructions
name|bool
name|HasAVX
block|;
comment|/// HasAES - Target has AES instructions
name|bool
name|HasAES
block|;
comment|/// HasCLMUL - Target has carry-less multiplication
name|bool
name|HasCLMUL
block|;
comment|/// HasFMA3 - Target has 3-operand fused multiply-add
name|bool
name|HasFMA3
block|;
comment|/// HasFMA4 - Target has 4-operand fused multiply-add
name|bool
name|HasFMA4
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
name|private
operator|:
comment|/// Is64Bit - True if the processor supports 64-bit instructions and
comment|/// pointer size is 64 bit.
name|bool
name|Is64Bit
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
argument|const std::string&FS
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
name|std
operator|::
name|string
name|ParseSubtargetFeatures
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|FS
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|CPU
argument_list|)
block|;
comment|/// AutoDetectSubtargetFeatures - Auto-detect CPU features using CPUID
comment|/// instruction.
name|void
name|AutoDetectSubtargetFeatures
argument_list|()
block|;
name|bool
name|is64Bit
argument_list|()
specifier|const
block|{
return|return
name|Is64Bit
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
name|hasAVX
argument_list|()
specifier|const
block|{
return|return
name|HasAVX
return|;
block|}
name|bool
name|hasXMM
argument_list|()
specifier|const
block|{
return|return
name|hasSSE1
argument_list|()
operator|||
name|hasAVX
argument_list|()
return|;
block|}
name|bool
name|hasXMMInt
argument_list|()
specifier|const
block|{
return|return
name|hasSSE2
argument_list|()
operator|||
name|hasAVX
argument_list|()
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
name|hasCLMUL
argument_list|()
specifier|const
block|{
return|return
name|HasCLMUL
return|;
block|}
name|bool
name|hasFMA3
argument_list|()
specifier|const
block|{
return|return
name|HasFMA3
return|;
block|}
name|bool
name|hasFMA4
argument_list|()
specifier|const
block|{
return|return
name|HasFMA4
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
comment|// ELF is a reasonably sane default and the only other X86 targets we
comment|// support are Darwin and Windows. Just use "not those".
name|bool
name|isTargetELF
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isTargetDarwin
argument_list|()
operator|&&
operator|!
name|isTargetWindows
argument_list|()
operator|&&
operator|!
name|isTargetCygMing
argument_list|()
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
name|isTargetMingw
argument_list|()
operator|||
name|isTargetCygwin
argument_list|()
return|;
block|}
comment|/// isTargetCOFF - Return true if this is any COFF/Windows target variant.
name|bool
name|isTargetCOFF
argument_list|()
specifier|const
block|{
return|return
name|isTargetMingw
argument_list|()
operator|||
name|isTargetCygwin
argument_list|()
operator|||
name|isTargetWindows
argument_list|()
return|;
block|}
name|bool
name|isTargetWin64
argument_list|()
specifier|const
block|{
return|return
name|Is64Bit
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
name|isTargetEnvMacho
argument_list|()
specifier|const
block|{
return|return
name|isTargetDarwin
argument_list|()
operator|||
operator|(
name|TargetTriple
operator|.
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|MachO
operator|)
return|;
block|}
name|bool
name|isTargetWin32
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Is64Bit
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
comment|/// getSpecialAddressLatency - For targets where it is beneficial to
comment|/// backschedule instructions that compute addresses, return a value
comment|/// indicating the number of scheduling cycles of backscheduling that
comment|/// should be attempted.
name|unsigned
name|getSpecialAddressLatency
argument_list|()
specifier|const
block|;
comment|/// IsCalleePop - Test whether a function should pop its own arguments.
name|bool
name|IsCalleePop
argument_list|(
argument|bool isVarArg
argument_list|,
argument|CallingConv::ID CallConv
argument_list|)
specifier|const
block|; }
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

