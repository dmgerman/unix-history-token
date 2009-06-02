begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====-- ARMTargetAsmInfo.h - ARM asm properties -------------*- C++ -*--====//
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
comment|// This file contains the declaration of the ARMTargetAsmInfo class.
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
name|ARMTARGETASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|ARMTARGETASMINFO_H
end_define

begin_include
include|#
directive|include
file|"ARMTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetAsmInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/ELFTargetAsmInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/DarwinTargetAsmInfo.h"
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
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|arm_asm_table
index|[]
decl_stmt|;
name|template
operator|<
name|class
name|BaseTAI
operator|>
expr|struct
name|ARMTargetAsmInfo
operator|:
name|public
name|BaseTAI
block|{
name|explicit
name|ARMTargetAsmInfo
argument_list|(
specifier|const
name|ARMTargetMachine
operator|&
name|TM
argument_list|)
operator|:
name|BaseTAI
argument_list|(
argument|TM
argument_list|)
block|{
name|BaseTAI
operator|::
name|AsmTransCBE
operator|=
name|arm_asm_table
block|;
name|BaseTAI
operator|::
name|AlignmentIsInBytes
operator|=
name|false
block|;
name|BaseTAI
operator|::
name|Data64bitsDirective
operator|=
literal|0
block|;
name|BaseTAI
operator|::
name|CommentString
operator|=
literal|"@"
block|;
name|BaseTAI
operator|::
name|ConstantPoolSection
operator|=
literal|"\t.text\n"
block|;
name|BaseTAI
operator|::
name|COMMDirectiveTakesAlignment
operator|=
name|false
block|;
name|BaseTAI
operator|::
name|InlineAsmStart
operator|=
literal|"@ InlineAsm Start"
block|;
name|BaseTAI
operator|::
name|InlineAsmEnd
operator|=
literal|"@ InlineAsm End"
block|;
name|BaseTAI
operator|::
name|LCOMMDirective
operator|=
literal|"\t.lcomm\t"
block|;     }
specifier|const
name|ARMSubtarget
operator|*
name|Subtarget
block|;
name|virtual
name|unsigned
name|getInlineAsmLength
argument_list|(
argument|const char *Str
argument_list|)
specifier|const
block|;
name|unsigned
name|countArguments
argument_list|(
argument|const char *p
argument_list|)
specifier|const
block|;
name|unsigned
name|countString
argument_list|(
argument|const char *p
argument_list|)
specifier|const
block|;   }
expr_stmt|;
typedef|typedef
name|ARMTargetAsmInfo
operator|<
name|TargetAsmInfo
operator|>
name|ARMGenericTargetAsmInfo
expr_stmt|;
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class ARMTargetAsmInfo<TargetAsmInfo>
argument_list|)
empty_stmt|;
name|struct
name|ARMDarwinTargetAsmInfo
range|:
name|public
name|ARMTargetAsmInfo
operator|<
name|DarwinTargetAsmInfo
operator|>
block|{
name|explicit
name|ARMDarwinTargetAsmInfo
argument_list|(
specifier|const
name|ARMTargetMachine
operator|&
name|TM
argument_list|)
block|;   }
decl_stmt|;
name|struct
name|ARMELFTargetAsmInfo
range|:
name|public
name|ARMTargetAsmInfo
operator|<
name|ELFTargetAsmInfo
operator|>
block|{
name|explicit
name|ARMELFTargetAsmInfo
argument_list|(
specifier|const
name|ARMTargetMachine
operator|&
name|TM
argument_list|)
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

