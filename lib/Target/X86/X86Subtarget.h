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
file|"llvm/Target/TargetSubtarget.h"
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
name|Module
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|namespace
name|PICStyles
block|{
enum|enum
name|Style
block|{
name|Stub
block|,
name|GOT
block|,
name|RIPRel
block|,
name|WinPIC
block|,
name|None
block|}
enum|;
block|}
name|class
name|X86Subtarget
range|:
name|public
name|TargetSubtarget
block|{
name|public
operator|:
expr|enum
name|AsmWriterFlavorTy
block|{
comment|// Note: This numbering has to match the GCC assembler dialects for inline
comment|// asm alternatives to work right.
name|ATT
operator|=
literal|0
block|,
name|Intel
operator|=
literal|1
block|,
name|Unset
block|}
block|;
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
comment|/// AsmFlavor - Which x86 asm dialect to use.
comment|///
name|AsmWriterFlavorTy
name|AsmFlavor
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
comment|/// HasX86_64 - True if the processor supports X86-64 instructions.
comment|///
name|bool
name|HasX86_64
block|;
comment|/// HasSSE4A - True if the processor supports SSE4A instructions.
name|bool
name|HasSSE4A
block|;
comment|/// HasAVX - Target has AVX instructions
name|bool
name|HasAVX
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
comment|/// DarwinVers - Nonzero if this is a darwin platform: the numeric
comment|/// version of the platform, e.g. 8 = 10.4 (Tiger), 9 = 10.5 (Leopard), etc.
name|unsigned
name|char
name|DarwinVers
block|;
comment|// Is any darwin-x86 platform.
comment|/// isLinux - true if this is a "linux" platform.
name|bool
name|IsLinux
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
name|private
operator|:
comment|/// Is64Bit - True if the processor supports 64-bit instructions and module
comment|/// pointer size is 64 bit.
name|bool
name|Is64Bit
block|;
name|public
operator|:
expr|enum
block|{
name|isELF
block|,
name|isCygwin
block|,
name|isDarwin
block|,
name|isWindows
block|,
name|isMingw
block|}
name|TargetType
block|;
comment|/// This constructor initializes the data members to match that
comment|/// of the specified module.
comment|///
name|X86Subtarget
argument_list|(
argument|const Module&M
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
name|hasAVX
argument_list|()
specifier|const
block|{
return|return
name|hasAVX
argument_list|()
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
name|unsigned
name|getAsmFlavor
argument_list|()
specifier|const
block|{
return|return
name|AsmFlavor
operator|!=
name|Unset
operator|?
name|unsigned
argument_list|(
name|AsmFlavor
argument_list|)
operator|:
literal|0
return|;
block|}
name|bool
name|isFlavorAtt
argument_list|()
specifier|const
block|{
return|return
name|AsmFlavor
operator|==
name|ATT
return|;
block|}
name|bool
name|isFlavorIntel
argument_list|()
specifier|const
block|{
return|return
name|AsmFlavor
operator|==
name|Intel
return|;
block|}
name|bool
name|isTargetDarwin
argument_list|()
specifier|const
block|{
return|return
name|TargetType
operator|==
name|isDarwin
return|;
block|}
name|bool
name|isTargetELF
argument_list|()
specifier|const
block|{
return|return
name|TargetType
operator|==
name|isELF
return|;
block|}
name|bool
name|isTargetWindows
argument_list|()
specifier|const
block|{
return|return
name|TargetType
operator|==
name|isWindows
return|;
block|}
name|bool
name|isTargetMingw
argument_list|()
specifier|const
block|{
return|return
name|TargetType
operator|==
name|isMingw
return|;
block|}
name|bool
name|isTargetCygMing
argument_list|()
specifier|const
block|{
return|return
operator|(
name|TargetType
operator|==
name|isMingw
operator|||
name|TargetType
operator|==
name|isCygwin
operator|)
return|;
block|}
name|bool
name|isTargetCygwin
argument_list|()
specifier|const
block|{
return|return
name|TargetType
operator|==
name|isCygwin
return|;
block|}
name|bool
name|isTargetWin64
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Is64Bit
operator|&&
operator|(
name|TargetType
operator|==
name|isMingw
operator|||
name|TargetType
operator|==
name|isWindows
operator|)
operator|)
return|;
block|}
name|std
operator|::
name|string
name|getDataLayout
argument_list|()
specifier|const
block|{
specifier|const
name|char
operator|*
name|p
block|;
if|if
condition|(
name|is64Bit
argument_list|()
condition|)
name|p
operator|=
literal|"e-p:64:64-s:64-f64:64:64-i64:64:64-f80:128:128"
expr_stmt|;
else|else
block|{
if|if
condition|(
name|isTargetDarwin
argument_list|()
condition|)
name|p
operator|=
literal|"e-p:32:32-f64:32:64-i64:32:64-f80:128:128"
expr_stmt|;
else|else
name|p
operator|=
literal|"e-p:32:32-f64:32:64-i64:32:64-f80:32:32"
expr_stmt|;
block|}
return|return
name|std
operator|::
name|string
argument_list|(
name|p
argument_list|)
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
name|isPICStyleStub
argument_list|()
specifier|const
block|{
return|return
name|PICStyle
operator|==
name|PICStyles
operator|::
name|Stub
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
name|isPICStyleWinPIC
argument_list|()
specifier|const
block|{
return|return
name|PICStyle
operator|==
name|PICStyles
operator|::
name|WinPIC
return|;
block|}
comment|/// getDarwinVers - Return the darwin version number, 8 = tiger, 9 = leopard.
name|unsigned
name|getDarwinVers
argument_list|()
specifier|const
block|{
return|return
name|DarwinVers
return|;
block|}
comment|/// isLinux - Return true if the target is "Linux".
name|bool
name|isLinux
argument_list|()
specifier|const
block|{
return|return
name|IsLinux
return|;
block|}
comment|/// True if accessing the GV requires an extra load. For Windows, dllimported
comment|/// symbols are indirect, loading the value at address GV rather then the
comment|/// value of GV itself. This means that the GlobalAddress must be in the base
comment|/// or index register of the address, not the GV offset field.
name|bool
name|GVRequiresExtraLoad
argument_list|(
argument|const GlobalValue* GV
argument_list|,
argument|const TargetMachine& TM
argument_list|,
argument|bool isDirectCall
argument_list|)
specifier|const
block|;
comment|/// True if accessing the GV requires a register.  This is a superset of the
comment|/// cases where GVRequiresExtraLoad is true.  Some variations of PIC require
comment|/// a register, but not an extra load.
name|bool
name|GVRequiresRegister
argument_list|(
argument|const GlobalValue* GV
argument_list|,
argument|const TargetMachine& TM
argument_list|,
argument|bool isDirectCall
argument_list|)
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
block|; }
decl_stmt|;
name|namespace
name|X86
block|{
comment|/// GetCpuIDAndInfo - Execute the specified cpuid and return the 4 values in
comment|/// the specified arguments.  If we can't run cpuid on the host, return true.
name|bool
name|GetCpuIDAndInfo
parameter_list|(
name|unsigned
name|value
parameter_list|,
name|unsigned
modifier|*
name|rEAX
parameter_list|,
name|unsigned
modifier|*
name|rEBX
parameter_list|,
name|unsigned
modifier|*
name|rECX
parameter_list|,
name|unsigned
modifier|*
name|rEDX
parameter_list|)
function_decl|;
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

