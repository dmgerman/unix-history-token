begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====-- X86TargetAsmInfo.h - X86 asm properties -------------*- C++ -*--====//
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
comment|// This file contains the declaration of the X86TargetAsmInfo class.
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
name|X86TARGETASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|X86TARGETASMINFO_H
end_define

begin_include
include|#
directive|include
file|"X86TargetMachine.h"
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
name|x86_asm_table
index|[]
decl_stmt|;
name|template
operator|<
name|class
name|BaseTAI
operator|>
expr|struct
name|X86TargetAsmInfo
operator|:
name|public
name|BaseTAI
block|{
name|explicit
name|X86TargetAsmInfo
argument_list|(
specifier|const
name|X86TargetMachine
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
name|X86Subtarget
operator|*
name|Subtarget
operator|=
operator|&
name|TM
operator|.
name|getSubtarget
operator|<
name|X86Subtarget
operator|>
operator|(
operator|)
block|;
name|BaseTAI
operator|::
name|AsmTransCBE
operator|=
name|x86_asm_table
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
name|virtual
name|bool
name|ExpandInlineAsm
argument_list|(
argument|CallInst *CI
argument_list|)
specifier|const
block|;
name|private
operator|:
name|bool
name|LowerToBSwap
argument_list|(
argument|CallInst *CI
argument_list|)
specifier|const
block|;   }
expr_stmt|;
typedef|typedef
name|X86TargetAsmInfo
operator|<
name|TargetAsmInfo
operator|>
name|X86GenericTargetAsmInfo
expr_stmt|;
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class X86TargetAsmInfo<TargetAsmInfo>
argument_list|)
empty_stmt|;
name|struct
name|X86DarwinTargetAsmInfo
range|:
name|public
name|X86TargetAsmInfo
operator|<
name|DarwinTargetAsmInfo
operator|>
block|{
name|explicit
name|X86DarwinTargetAsmInfo
argument_list|(
specifier|const
name|X86TargetMachine
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
name|X86ELFTargetAsmInfo
range|:
name|public
name|X86TargetAsmInfo
operator|<
name|ELFTargetAsmInfo
operator|>
block|{
name|explicit
name|X86ELFTargetAsmInfo
argument_list|(
specifier|const
name|X86TargetMachine
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
name|struct
name|X86COFFTargetAsmInfo
range|:
name|public
name|X86GenericTargetAsmInfo
block|{
name|explicit
name|X86COFFTargetAsmInfo
argument_list|(
specifier|const
name|X86TargetMachine
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
name|std
operator|::
name|string
name|UniqueSectionForGlobal
argument_list|(
argument|const GlobalValue* GV
argument_list|,
argument|SectionKind::Kind kind
argument_list|)
specifier|const
block|;
name|virtual
name|std
operator|::
name|string
name|printSectionFlags
argument_list|(
argument|unsigned flags
argument_list|)
specifier|const
block|;   }
decl_stmt|;
name|struct
name|X86WinTargetAsmInfo
range|:
name|public
name|X86GenericTargetAsmInfo
block|{
name|explicit
name|X86WinTargetAsmInfo
argument_list|(
specifier|const
name|X86TargetMachine
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

