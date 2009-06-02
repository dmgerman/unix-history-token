begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SPUTargetAsmInfo.h - Cell SPU asm properties -----------*- C++ -*--===//
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
comment|// This file contains the declaration of the SPUTargetAsmInfo class.
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
name|SPUTARGETASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|SPUTARGETASMINFO_H
end_define

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
file|"SPUTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"SPUSubtarget.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declaration.
name|class
name|SPUTargetMachine
decl_stmt|;
name|template
operator|<
name|class
name|BaseTAI
operator|>
expr|struct
name|SPUTargetAsmInfo
operator|:
name|public
name|BaseTAI
block|{
name|explicit
name|SPUTargetAsmInfo
argument_list|(
specifier|const
name|SPUTargetMachine
operator|&
name|TM
argument_list|)
operator|:
name|BaseTAI
argument_list|(
argument|TM
argument_list|)
block|{
comment|/* (unused today)        * const SPUSubtarget *Subtarget =&TM.getSubtarget<SPUSubtarget>(); */
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
literal|"\t.quad\t"
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
block|;     }
block|}
expr_stmt|;
name|struct
name|SPULinuxTargetAsmInfo
range|:
name|public
name|SPUTargetAsmInfo
operator|<
name|ELFTargetAsmInfo
operator|>
block|{
name|explicit
name|SPULinuxTargetAsmInfo
argument_list|(
specifier|const
name|SPUTargetMachine
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

begin_comment
comment|/* SPUTARGETASMINFO_H */
end_comment

end_unit

