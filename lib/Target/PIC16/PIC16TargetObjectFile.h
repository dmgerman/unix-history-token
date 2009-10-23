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
file|"PIC16.h"
end_include

begin_include
include|#
directive|include
file|"PIC16ABINames.h"
end_include

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
name|PIC16Section
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
comment|/// FIXME: MOVE ALL THIS STUFF TO PIC16Section.
comment|///
comment|/// PIC16TargetObjectFile - PIC16 Object file. Contains data and code
comment|/// sections.
comment|// PIC16 Object File has two types of sections.
comment|// 1. Standard Sections
comment|//    1.1 un-initialized global data
comment|//    1.2 initialized global data
comment|//    1.3 program memory data
comment|//    1.4 local variables of functions.
comment|// 2. User defined sections
comment|//    2.1 Objects placed in a specific section. (By _Section() macro)
comment|//    2.2 Objects placed at a specific address. (By _Address() macro)
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
name|PIC16Section
operator|*
operator|>
name|SectionsByName
block|;
specifier|const
name|TargetMachine
operator|*
name|TM
block|;
comment|/// Lists of sections.
comment|/// Standard Data Sections.
name|mutable
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
name|UDATASections_
block|;
name|mutable
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
name|IDATASections_
block|;
name|mutable
name|PIC16Section
operator|*
name|ROMDATASection_
block|;
comment|/// Standard Auto Sections.
name|mutable
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
name|AUTOSections_
block|;
comment|/// User specified sections.
name|mutable
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
name|USERSections_
block|;
comment|/// Find or Create a PIC16 Section, without adding it to any
comment|/// section list.
name|PIC16Section
operator|*
name|getPIC16Section
argument_list|(
argument|const std::string&Name
argument_list|,
argument|PIC16SectionType Ty
argument_list|,
argument|const std::string&Address =
literal|""
argument_list|,
argument|int Color = -
literal|1
argument_list|)
specifier|const
block|;
comment|/// Convenience functions. These wrappers also take care of adding
comment|/// the newly created section to the appropriate sections list.
comment|/// Find or Create PIC16 Standard Data Section.
name|PIC16Section
operator|*
name|getPIC16DataSection
argument_list|(
argument|const std::string&Name
argument_list|,
argument|PIC16SectionType Ty
argument_list|,
argument|const std::string&Address =
literal|""
argument_list|,
argument|int Color = -
literal|1
argument_list|)
specifier|const
block|;
comment|/// Find or Create PIC16 Standard Auto Section.
name|PIC16Section
operator|*
name|getPIC16AutoSection
argument_list|(
argument|const std::string&Name
argument_list|,
argument|PIC16SectionType Ty = UDATA_OVR
argument_list|,
argument|const std::string&Address =
literal|""
argument_list|,
argument|int Color = -
literal|1
argument_list|)
specifier|const
block|;
comment|/// Find or Create PIC16 Standard Auto Section.
name|PIC16Section
operator|*
name|getPIC16UserSection
argument_list|(
argument|const std::string&Name
argument_list|,
argument|PIC16SectionType Ty
argument_list|,
argument|const std::string&Address =
literal|""
argument_list|,
argument|int Color = -
literal|1
argument_list|)
specifier|const
block|;
comment|/// Allocate Un-initialized data to a standard UDATA section.
specifier|const
name|MCSection
operator|*
name|allocateUDATA
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
comment|/// Allocate Initialized data to a standard IDATA section.
specifier|const
name|MCSection
operator|*
name|allocateIDATA
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
comment|/// Allocate ROM data to the standard ROMDATA section.
specifier|const
name|MCSection
operator|*
name|allocateROMDATA
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
comment|/// Allocate an AUTO variable to an AUTO section.
specifier|const
name|MCSection
operator|*
name|allocateAUTO
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
comment|/// Allocate DATA in user specified section.
specifier|const
name|MCSection
operator|*
name|allocateInGivenSection
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
specifier|const
block|;
comment|/// Allocate DATA at user specified address.
specifier|const
name|MCSection
operator|*
name|allocateAtGivenAddress
argument_list|(
argument|const GlobalVariable *GV
argument_list|,
argument|const std::string&Addr
argument_list|)
specifier|const
block|;
name|public
operator|:
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
comment|/// Return the section with the given Name. Null if not found.
name|PIC16Section
operator|*
name|findPIC16Section
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
block|;
comment|/// Override section allocations for user specified sections.
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
comment|/// Select sections for Data and Auto variables(globals).
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
comment|/// Return a code section for a function.
specifier|const
name|PIC16Section
operator|*
name|SectionForCode
argument_list|(
argument|const std::string&FnName
argument_list|)
specifier|const
block|;
comment|/// Return a frame section for a function.
specifier|const
name|PIC16Section
operator|*
name|SectionForFrame
argument_list|(
argument|const std::string&FnName
argument_list|)
specifier|const
block|;
comment|/// Accessors for various section lists.
specifier|const
name|std
operator|::
name|vector
operator|<
name|PIC16Section
operator|*
operator|>
operator|&
name|UDATASections
argument_list|()
specifier|const
block|{
return|return
name|UDATASections_
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
name|IDATASections
argument_list|()
specifier|const
block|{
return|return
name|IDATASections_
return|;
block|}
specifier|const
name|PIC16Section
operator|*
name|ROMDATASection
argument_list|()
specifier|const
block|{
return|return
name|ROMDATASection_
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
name|AUTOSections
argument_list|()
specifier|const
block|{
return|return
name|AUTOSections_
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
name|USERSections
argument_list|()
specifier|const
block|{
return|return
name|USERSections_
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

