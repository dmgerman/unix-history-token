begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====-- PPCTargetAsmInfo.h - PPC asm properties -------------*- C++ -*--====//
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
comment|// This file contains the declaration of the DarwinTargetAsmInfo class.
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
name|PPCTARGETASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|PPCTARGETASMINFO_H
end_define

begin_include
include|#
directive|include
file|"PPCTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetAsmInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/DarwinTargetAsmInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/ELFTargetAsmInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|class
name|BaseTAI
operator|>
expr|struct
name|PPCTargetAsmInfo
operator|:
name|public
name|BaseTAI
block|{
name|explicit
name|PPCTargetAsmInfo
argument_list|(
specifier|const
name|PPCTargetMachine
operator|&
name|TM
argument_list|)
operator|:
name|BaseTAI
argument_list|(
argument|TM
argument_list|)
block|{
specifier|const
name|PPCSubtarget
operator|*
name|Subtarget
operator|=
operator|&
name|TM
operator|.
name|getSubtarget
operator|<
name|PPCSubtarget
operator|>
operator|(
operator|)
block|;
name|bool
name|isPPC64
operator|=
name|Subtarget
operator|->
name|isPPC64
argument_list|()
block|;
name|BaseTAI
operator|::
name|ZeroDirective
operator|=
literal|"\t.space\t"
block|;
name|BaseTAI
operator|::
name|SetDirective
operator|=
literal|"\t.set"
block|;
name|BaseTAI
operator|::
name|Data64bitsDirective
operator|=
name|isPPC64
condition|?
literal|"\t.quad\t"
else|:
literal|0
block|;
name|BaseTAI
operator|::
name|AlignmentIsInBytes
operator|=
name|false
block|;
name|BaseTAI
operator|::
name|LCOMMDirective
operator|=
literal|"\t.lcomm\t"
block|;
name|BaseTAI
operator|::
name|InlineAsmStart
operator|=
literal|"# InlineAsm Start"
block|;
name|BaseTAI
operator|::
name|InlineAsmEnd
operator|=
literal|"# InlineAsm End"
block|;
name|BaseTAI
operator|::
name|AssemblerDialect
operator|=
name|Subtarget
operator|->
name|getAsmFlavor
argument_list|()
block|;     }
block|}
expr_stmt|;
typedef|typedef
name|PPCTargetAsmInfo
operator|<
name|TargetAsmInfo
operator|>
name|PPCGenericTargetAsmInfo
expr_stmt|;
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class PPCTargetAsmInfo<TargetAsmInfo>
argument_list|)
empty_stmt|;
name|struct
name|PPCDarwinTargetAsmInfo
range|:
name|public
name|PPCTargetAsmInfo
operator|<
name|DarwinTargetAsmInfo
operator|>
block|{
name|explicit
name|PPCDarwinTargetAsmInfo
argument_list|(
specifier|const
name|PPCTargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
name|unsigned
name|PreferredEHDataFormat
argument_list|(
argument|DwarfEncoding::Target Reason
argument_list|,
argument|bool Global
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|getEHGlobalPrefix
argument_list|()
specifier|const
block|;   }
decl_stmt|;
name|struct
name|PPCLinuxTargetAsmInfo
range|:
name|public
name|PPCTargetAsmInfo
operator|<
name|ELFTargetAsmInfo
operator|>
block|{
name|explicit
name|PPCLinuxTargetAsmInfo
argument_list|(
specifier|const
name|PPCTargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
name|unsigned
name|PreferredEHDataFormat
argument_list|(
argument|DwarfEncoding::Target Reason
argument_list|,
argument|bool Global
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

