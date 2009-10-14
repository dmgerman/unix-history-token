begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PIC16TargetObjectFile.h - PIC16 Object Info -------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TARGET_PIC16_TARGETOBJECTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_PIC16_TARGETOBJECTFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetLoweringObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|<vector>
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
name|GlobalVariable
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|PIC16TargetMachine
decl_stmt|;
name|class
name|MCSectionPIC16
decl_stmt|;
enum|enum
block|{
name|DataBankSize
init|=
literal|80
block|}
enum|;
comment|/// PIC16 Splits the global data into mulitple udata and idata sections.
comment|/// Each udata and idata section needs to contain a list of globals that
comment|/// they contain, in order to avoid scanning over all the global values
comment|/// again and printing only those that match the current section.
comment|/// Keeping values inside the sections make printing a section much easier.
comment|///
comment|/// FIXME: MOVE ALL THIS STUFF TO MCSectionPIC16.
comment|///
struct|struct
name|PIC16Section
block|{
specifier|const
name|MCSectionPIC16
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
argument|const MCSectionPIC16 *s
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
argument_list|()
specifier|const
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
name|class
name|PIC16TargetObjectFile
range|:
name|public
name|TargetLoweringObjectFile
block|{
comment|/// SectionsByName - Bindings of names to allocated sections.
name|mutable
name|StringMap
operator|<
name|MCSectionPIC16
operator|*
operator|>
name|SectionsByName
block|;
specifier|const
name|TargetMachine
operator|*
name|TM
block|;
specifier|const
name|MCSectionPIC16
operator|*
name|getPIC16Section
argument_list|(
argument|const char *Name
argument_list|,
argument|SectionKind K
argument_list|,
argument|int Address = -
literal|1
argument_list|,
argument|int Color = -
literal|1
argument_list|)
specifier|const
block|;
name|public
operator|:
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
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
name|ROSections
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
name|PIC16TargetObjectFile
argument_list|()
block|;
operator|~
name|PIC16TargetObjectFile
argument_list|()
block|;
name|void
name|Initialize
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
specifier|const
name|MCSection
operator|*
name|getExplicitSectionGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|MCSection
operator|*
name|SelectSectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|const TargetMachine&
argument_list|)
specifier|const
block|;
specifier|const
name|MCSection
operator|*
name|getSectionForFunction
argument_list|(
argument|const std::string&FnName
argument_list|)
specifier|const
block|;
specifier|const
name|MCSection
operator|*
name|getSectionForFunctionFrame
argument_list|(
argument|const std::string&FnName
argument_list|)
specifier|const
block|;
name|private
operator|:
name|std
operator|::
name|string
name|getSectionNameForSym
argument_list|(
argument|const std::string&Sym
argument_list|)
specifier|const
block|;
specifier|const
name|MCSection
operator|*
name|getBSSSectionForGlobal
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
specifier|const
name|MCSection
operator|*
name|getIDATASectionForGlobal
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
specifier|const
name|MCSection
operator|*
name|getSectionForAuto
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
specifier|const
name|MCSection
operator|*
name|CreateBSSSectionForGlobal
argument_list|(
argument|const GlobalVariable *GV
argument_list|,
argument|std::string Addr =
literal|""
argument_list|)
specifier|const
block|;
specifier|const
name|MCSection
operator|*
name|CreateIDATASectionForGlobal
argument_list|(
argument|const GlobalVariable *GV
argument_list|,
argument|std::string Addr =
literal|""
argument_list|)
specifier|const
block|;
specifier|const
name|MCSection
operator|*
name|getROSectionForGlobal
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
specifier|const
name|MCSection
operator|*
name|CreateROSectionForGlobal
argument_list|(
argument|const GlobalVariable *GV
argument_list|,
argument|std::string Addr =
literal|""
argument_list|)
specifier|const
block|;
specifier|const
name|MCSection
operator|*
name|CreateSectionForGlobal
argument_list|(
argument|const GlobalVariable *GV
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|const std::string&Addr =
literal|""
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
specifier|const
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
operator|&
name|getBSSSections
argument_list|()
specifier|const
block|{
return|return
name|BSSSections
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
operator|&
name|getIDATASections
argument_list|()
specifier|const
block|{
return|return
name|IDATASections
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
operator|&
name|getAutosSections
argument_list|()
specifier|const
block|{
return|return
name|AutosSections
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
operator|&
name|getROSections
argument_list|()
specifier|const
block|{
return|return
name|ROSections
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

