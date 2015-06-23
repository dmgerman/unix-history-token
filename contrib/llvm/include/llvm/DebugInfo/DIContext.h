begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DIContext.h ---------------------------------------------*- C++ -*-===//
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
comment|// This file defines DIContext, an abstract data structure that holds
end_comment

begin_comment
comment|// debug information data.
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
name|LLVM_DEBUGINFO_DICONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DICONTEXT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/RelocVisitor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
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
name|raw_ostream
decl_stmt|;
comment|/// DILineInfo - a format-neutral container for source line information.
struct|struct
name|DILineInfo
block|{
name|std
operator|::
name|string
name|FileName
expr_stmt|;
name|std
operator|::
name|string
name|FunctionName
expr_stmt|;
name|uint32_t
name|Line
decl_stmt|;
name|uint32_t
name|Column
decl_stmt|;
name|DILineInfo
argument_list|()
operator|:
name|FileName
argument_list|(
literal|"<invalid>"
argument_list|)
operator|,
name|FunctionName
argument_list|(
literal|"<invalid>"
argument_list|)
operator|,
name|Line
argument_list|(
literal|0
argument_list|)
operator|,
name|Column
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|DILineInfo
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Line
operator|==
name|RHS
operator|.
name|Line
operator|&&
name|Column
operator|==
name|RHS
operator|.
name|Column
operator|&&
name|FileName
operator|==
name|RHS
operator|.
name|FileName
operator|&&
name|FunctionName
operator|==
name|RHS
operator|.
name|FunctionName
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|DILineInfo
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
block|}
struct|;
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|DILineInfo
operator|>
operator|,
literal|16
operator|>
name|DILineInfoTable
expr_stmt|;
comment|/// DIInliningInfo - a format-neutral container for inlined code description.
name|class
name|DIInliningInfo
block|{
name|SmallVector
operator|<
name|DILineInfo
operator|,
literal|4
operator|>
name|Frames
expr_stmt|;
name|public
label|:
name|DIInliningInfo
argument_list|()
block|{}
name|DILineInfo
name|getFrame
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Index
operator|<
name|Frames
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|Frames
index|[
name|Index
index|]
return|;
block|}
name|uint32_t
name|getNumberOfFrames
argument_list|()
specifier|const
block|{
return|return
name|Frames
operator|.
name|size
argument_list|()
return|;
block|}
name|void
name|addFrame
parameter_list|(
specifier|const
name|DILineInfo
modifier|&
name|Frame
parameter_list|)
block|{
name|Frames
operator|.
name|push_back
argument_list|(
name|Frame
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// A DINameKind is passed to name search methods to specify a
comment|/// preference regarding the type of name resolution the caller wants.
name|enum
name|class
name|DINameKind
block|{
name|None
operator|,
name|ShortName
operator|,
name|LinkageName
block|}
empty_stmt|;
comment|/// DILineInfoSpecifier - controls which fields of DILineInfo container
comment|/// should be filled with data.
struct|struct
name|DILineInfoSpecifier
block|{
name|enum
name|class
name|FileLineInfoKind
block|{
name|None
operator|,
name|Default
operator|,
name|AbsoluteFilePath
block|}
empty_stmt|;
typedef|typedef
name|DINameKind
name|FunctionNameKind
typedef|;
name|FileLineInfoKind
name|FLIKind
decl_stmt|;
name|FunctionNameKind
name|FNKind
decl_stmt|;
name|DILineInfoSpecifier
argument_list|(
argument|FileLineInfoKind FLIKind = FileLineInfoKind::Default
argument_list|,
argument|FunctionNameKind FNKind = FunctionNameKind::None
argument_list|)
block|:
name|FLIKind
argument_list|(
name|FLIKind
argument_list|)
operator|,
name|FNKind
argument_list|(
argument|FNKind
argument_list|)
block|{}
block|}
struct|;
comment|/// Selects which debug sections get dumped.
enum|enum
name|DIDumpType
block|{
name|DIDT_Null
block|,
name|DIDT_All
block|,
name|DIDT_Abbrev
block|,
name|DIDT_AbbrevDwo
block|,
name|DIDT_Aranges
block|,
name|DIDT_Frames
block|,
name|DIDT_Info
block|,
name|DIDT_InfoDwo
block|,
name|DIDT_Types
block|,
name|DIDT_TypesDwo
block|,
name|DIDT_Line
block|,
name|DIDT_LineDwo
block|,
name|DIDT_Loc
block|,
name|DIDT_LocDwo
block|,
name|DIDT_Ranges
block|,
name|DIDT_Pubnames
block|,
name|DIDT_Pubtypes
block|,
name|DIDT_GnuPubnames
block|,
name|DIDT_GnuPubtypes
block|,
name|DIDT_Str
block|,
name|DIDT_StrDwo
block|,
name|DIDT_StrOffsetsDwo
block|,
name|DIDT_AppleNames
block|,
name|DIDT_AppleTypes
block|,
name|DIDT_AppleNamespaces
block|,
name|DIDT_AppleObjC
block|}
enum|;
name|class
name|DIContext
block|{
name|public
label|:
enum|enum
name|DIContextKind
block|{
name|CK_DWARF
block|,
name|CK_PDB
block|}
enum|;
name|DIContextKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|DIContext
argument_list|(
argument|DIContextKind K
argument_list|)
block|:
name|Kind
argument_list|(
argument|K
argument_list|)
block|{}
name|virtual
operator|~
name|DIContext
argument_list|()
block|{}
name|virtual
name|void
name|dump
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|DIDumpType DumpType = DIDT_All
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|DILineInfo
name|getLineInfoForAddress
parameter_list|(
name|uint64_t
name|Address
parameter_list|,
name|DILineInfoSpecifier
name|Specifier
init|=
name|DILineInfoSpecifier
argument_list|()
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|DILineInfoTable
name|getLineInfoForAddressRange
parameter_list|(
name|uint64_t
name|Address
parameter_list|,
name|uint64_t
name|Size
parameter_list|,
name|DILineInfoSpecifier
name|Specifier
init|=
name|DILineInfoSpecifier
argument_list|()
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|DIInliningInfo
name|getInliningInfoForAddress
parameter_list|(
name|uint64_t
name|Address
parameter_list|,
name|DILineInfoSpecifier
name|Specifier
init|=
name|DILineInfoSpecifier
argument_list|()
parameter_list|)
init|=
literal|0
function_decl|;
name|private
label|:
specifier|const
name|DIContextKind
name|Kind
decl_stmt|;
block|}
empty_stmt|;
comment|/// An inferface for inquiring the load address of a loaded object file
comment|/// to be used by the DIContext implementations when applying relocations
comment|/// on the fly.
name|class
name|LoadedObjectInfo
block|{
name|public
label|:
name|virtual
operator|~
name|LoadedObjectInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Obtain the Load Address of a section by Name.
comment|///
comment|/// Calculate the address of the section identified by the passed in Name.
comment|/// The section need not be present in the local address space. The addresses
comment|/// need to be consistent with the addresses used to query the DIContext and
comment|/// the output of this function should be deterministic, i.e. repeated calls with
comment|/// the same Name should give the same address.
name|virtual
name|uint64_t
name|getSectionLoadAddress
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// If conveniently available, return the content of the given Section.
comment|///
comment|/// When the section is available in the local address space, in relocated (loaded)
comment|/// form, e.g. because it was relocated by a JIT for execution, this function
comment|/// should provide the contents of said section in `Data`. If the loaded section
comment|/// is not available, or the cost of retrieving it would be prohibitive, this
comment|/// function should return false. In that case, relocations will be read from the
comment|/// local (unrelocated) object file and applied on the fly. Note that this method
comment|/// is used purely for optimzation purposes in the common case of JITting in the
comment|/// local address space, so returning false should always be correct.
name|virtual
name|bool
name|getLoadedSectionContents
argument_list|(
name|StringRef
name|Name
argument_list|,
name|StringRef
operator|&
name|Data
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Obtain a copy of this LoadedObjectInfo.
comment|///
comment|/// The caller is responsible for deallocation once the copy is no longer required.
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|LoadedObjectInfo
operator|>
name|clone
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
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

