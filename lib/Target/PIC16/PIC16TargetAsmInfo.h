begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====-- PIC16TargetAsmInfo.h - PIC16 asm properties ---------*- C++ -*--====//
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
comment|// This file contains the declaration of the PIC16TargetAsmInfo class.
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
name|PIC16TARGETASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|PIC16TARGETASMINFO_H
end_define

begin_include
include|#
directive|include
file|"PIC16.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetAsmInfo.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"llvm/Module.h"
end_include

begin_define
define|#
directive|define
name|DataBankSize
value|80
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declaration.
name|class
name|PIC16TargetMachine
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
comment|// PIC16 Splits the global data into mulitple udata and idata sections.
comment|// Each udata and idata section needs to contain a list of globals that
comment|// they contain, in order to avoid scanning over all the global values
comment|// again and printing only those that match the current section.
comment|// Keeping values inside the sections make printing a section much easier.
struct|struct
name|PIC16Section
block|{
specifier|const
name|Section
modifier|*
name|S_
decl_stmt|;
comment|// Connection to actual Section.
name|unsigned
name|Size
decl_stmt|;
comment|// Total size of the objects contained.
name|bool
name|SectionPrinted
decl_stmt|;
name|std
operator|::
name|vector
operator|<
specifier|const
name|GlobalVariable
operator|*
operator|>
name|Items
expr_stmt|;
name|PIC16Section
argument_list|(
argument|const Section *s
argument_list|)
block|{
name|S_
operator|=
name|s
expr_stmt|;
name|Size
operator|=
literal|0
expr_stmt|;
name|SectionPrinted
operator|=
name|false
expr_stmt|;
block|}
name|bool
name|isPrinted
parameter_list|()
block|{
return|return
name|SectionPrinted
return|;
block|}
name|void
name|setPrintedStatus
parameter_list|(
name|bool
name|status
parameter_list|)
block|{
name|SectionPrinted
operator|=
name|status
expr_stmt|;
block|}
block|}
struct|;
name|struct
name|PIC16TargetAsmInfo
range|:
name|public
name|TargetAsmInfo
block|{
name|std
operator|::
name|string
name|getSectionNameForSym
argument_list|(
argument|const std::string&Sym
argument_list|)
specifier|const
block|;
name|PIC16TargetAsmInfo
argument_list|(
specifier|const
name|PIC16TargetMachine
operator|&
name|TM
argument_list|)
block|;
name|mutable
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
name|BSSSections
block|;
name|mutable
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
name|IDATASections
block|;
name|mutable
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
name|AutosSections
block|;
name|mutable
name|PIC16Section
operator|*
name|ROSection
block|;
name|mutable
name|PIC16Section
operator|*
name|ExternalVarDecls
block|;
name|mutable
name|PIC16Section
operator|*
name|ExternalVarDefs
block|;
name|virtual
operator|~
name|PIC16TargetAsmInfo
argument_list|()
block|;
name|private
operator|:
specifier|const
name|char
operator|*
name|RomData8bitsDirective
block|;
specifier|const
name|char
operator|*
name|RomData16bitsDirective
block|;
specifier|const
name|char
operator|*
name|RomData32bitsDirective
block|;
specifier|const
name|char
operator|*
name|getRomDirective
argument_list|(
argument|unsigned size
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|getASDirective
argument_list|(
argument|unsigned size
argument_list|,
argument|unsigned AS
argument_list|)
specifier|const
block|;
specifier|const
name|Section
operator|*
name|getBSSSectionForGlobal
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
specifier|const
name|Section
operator|*
name|getIDATASectionForGlobal
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
specifier|const
name|Section
operator|*
name|getSectionForAuto
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|Section
operator|*
name|SelectSectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|)
specifier|const
block|;
name|public
operator|:
name|void
name|SetSectionForGVs
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
name|getBSSSections
argument_list|()
specifier|const
block|{
return|return
name|BSSSections
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
name|getIDATASections
argument_list|()
specifier|const
block|{
return|return
name|IDATASections
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
name|getAutosSections
argument_list|()
specifier|const
block|{
return|return
name|AutosSections
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

