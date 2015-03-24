begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/PECOFF/IdataPass.h---------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
comment|///
end_comment

begin_comment
comment|/// \file \brief This linker pass creates atoms for the DLL import
end_comment

begin_comment
comment|/// information. The defined atoms constructed in this pass will go into .idata
end_comment

begin_comment
comment|/// section, unless .idata section is merged with other section such as .data.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For the details of the .idata section format, see Microsoft PE/COFF
end_comment

begin_comment
comment|/// Specification section 5.4, The .idata Section.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_PE_COFF_IDATA_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_PE_COFF_IDATA_PASS_H
end_define

begin_include
include|#
directive|include
file|"Atoms.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/File.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Pass.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Simple.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/PECOFFLinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/COFF.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_expr_stmt
name|using
name|llvm
operator|::
name|COFF
operator|::
name|ImportDirectoryTableEntry
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|pecoff
block|{
name|namespace
name|idata
block|{
name|class
name|DLLNameAtom
decl_stmt|;
name|class
name|HintNameAtom
decl_stmt|;
name|class
name|ImportTableEntryAtom
decl_stmt|;
comment|// A state object of this pass.
struct|struct
name|IdataContext
block|{
name|IdataContext
argument_list|(
name|MutableFile
operator|&
name|f
argument_list|,
name|VirtualFile
operator|&
name|g
argument_list|,
specifier|const
name|PECOFFLinkingContext
operator|&
name|c
argument_list|)
operator|:
name|file
argument_list|(
name|f
argument_list|)
operator|,
name|dummyFile
argument_list|(
name|g
argument_list|)
operator|,
name|ctx
argument_list|(
argument|c
argument_list|)
block|{}
name|MutableFile
operator|&
name|file
expr_stmt|;
name|VirtualFile
modifier|&
name|dummyFile
decl_stmt|;
specifier|const
name|PECOFFLinkingContext
modifier|&
name|ctx
decl_stmt|;
block|}
struct|;
comment|/// The root class of all idata atoms.
name|class
name|IdataAtom
range|:
name|public
name|COFFLinkerInternalAtom
block|{
name|public
operator|:
name|SectionChoice
name|sectionChoice
argument_list|()
specifier|const
name|override
block|{
return|return
name|sectionCustomRequired
return|;
block|}
name|StringRef
name|customSectionName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|".idata"
return|;
block|}
name|ContentType
name|contentType
argument_list|()
specifier|const
name|override
block|{
return|return
name|typeData
return|;
block|}
name|ContentPermissions
name|permissions
argument_list|()
specifier|const
name|override
block|{
return|return
name|permR__
return|;
block|}
name|protected
operator|:
name|IdataAtom
argument_list|(
name|IdataContext
operator|&
name|context
argument_list|,
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|data
argument_list|)
block|; }
decl_stmt|;
comment|/// A HintNameAtom represents a symbol that will be imported from a DLL at
comment|/// runtime. It consists with an optional hint, which is a small integer, and a
comment|/// symbol name.
comment|///
comment|/// A hint is an index of the export pointer table in a DLL. If the import
comment|/// library and DLL is in sync (i.e., ".lib" and ".dll" is for the same version
comment|/// or the symbol ordinal is maintained by hand with ".exp" file), the PE/COFF
comment|/// loader can find the symbol quickly.
name|class
name|HintNameAtom
range|:
name|public
name|IdataAtom
block|{
name|public
operator|:
name|HintNameAtom
argument_list|(
argument|IdataContext&context
argument_list|,
argument|uint16_t hint
argument_list|,
argument|StringRef importName
argument_list|)
block|;
name|StringRef
name|getContentString
argument_list|()
block|{
return|return
name|_importName
return|;
block|}
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|assembleRawContent
argument_list|(
argument|uint16_t hint
argument_list|,
argument|StringRef importName
argument_list|)
block|;
name|StringRef
name|_importName
block|; }
decl_stmt|;
name|class
name|ImportTableEntryAtom
range|:
name|public
name|IdataAtom
block|{
name|public
operator|:
name|ImportTableEntryAtom
argument_list|(
argument|IdataContext&ctx
argument_list|,
argument|uint64_t contents
argument_list|,
argument|StringRef sectionName
argument_list|)
operator|:
name|IdataAtom
argument_list|(
name|ctx
argument_list|,
name|assembleRawContent
argument_list|(
name|contents
argument_list|,
name|ctx
operator|.
name|ctx
operator|.
name|is64Bit
argument_list|()
argument_list|)
argument_list|)
block|,
name|_sectionName
argument_list|(
argument|sectionName
argument_list|)
block|{}
name|StringRef
name|customSectionName
argument_list|()
specifier|const
name|override
block|{
return|return
name|_sectionName
return|;
block|}
block|;
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|assembleRawContent
argument_list|(
argument|uint64_t contents
argument_list|,
argument|bool is64
argument_list|)
block|;
name|StringRef
name|_sectionName
block|; }
decl_stmt|;
comment|/// An ImportDirectoryAtom includes information to load a DLL, including a DLL
comment|/// name, symbols that will be resolved from the DLL, and the import address
comment|/// table that are overwritten by the loader with the pointers to the referenced
comment|/// items. The executable has one ImportDirectoryAtom per one imported DLL.
name|class
name|ImportDirectoryAtom
range|:
name|public
name|IdataAtom
block|{
name|public
operator|:
name|ImportDirectoryAtom
argument_list|(
argument|IdataContext&context
argument_list|,
argument|StringRef loadName
argument_list|,
argument|const std::vector<COFFSharedLibraryAtom *>&sharedAtoms
argument_list|)
operator|:
name|IdataAtom
argument_list|(
argument|context
argument_list|,
argument|std::vector<uint8_t>(
literal|20
argument|,
literal|0
argument|)
argument_list|)
block|{
name|addRelocations
argument_list|(
name|context
argument_list|,
name|loadName
argument_list|,
name|sharedAtoms
argument_list|)
block|;   }
name|StringRef
name|customSectionName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|".idata.d"
return|;
block|}
name|private
operator|:
name|void
name|addRelocations
argument_list|(
argument|IdataContext&context
argument_list|,
argument|StringRef loadName
argument_list|,
argument|const std::vector<COFFSharedLibraryAtom *>&sharedAtoms
argument_list|)
block|;
name|mutable
name|llvm
operator|::
name|BumpPtrAllocator
name|_alloc
block|; }
decl_stmt|;
comment|/// The last NULL entry in the import directory.
name|class
name|NullImportDirectoryAtom
range|:
name|public
name|IdataAtom
block|{
name|public
operator|:
name|explicit
name|NullImportDirectoryAtom
argument_list|(
name|IdataContext
operator|&
name|context
argument_list|)
operator|:
name|IdataAtom
argument_list|(
argument|context
argument_list|,
argument|std::vector<uint8_t>(
literal|20
argument|,
literal|0
argument|)
argument_list|)
block|{}
name|StringRef
name|customSectionName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|".idata.d"
return|;
block|}
expr|}
block|;
comment|/// The class for the the delay-load import table.
name|class
name|DelayImportDirectoryAtom
operator|:
name|public
name|IdataAtom
block|{
name|public
operator|:
name|DelayImportDirectoryAtom
argument_list|(
argument|IdataContext&context
argument_list|,
argument|StringRef loadName
argument_list|,
argument|const std::vector<COFFSharedLibraryAtom *>&sharedAtoms
argument_list|)
operator|:
name|IdataAtom
argument_list|(
argument|context
argument_list|,
argument|createContent()
argument_list|)
block|{
name|addRelocations
argument_list|(
name|context
argument_list|,
name|loadName
argument_list|,
name|sharedAtoms
argument_list|)
block|;   }
name|StringRef
name|customSectionName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|".didat.d"
return|;
block|}
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|createContent
argument_list|()
block|;
name|void
name|addRelocations
argument_list|(
argument|IdataContext&context
argument_list|,
argument|StringRef loadName
argument_list|,
argument|const std::vector<COFFSharedLibraryAtom *>&sharedAtoms
argument_list|)
block|;
name|mutable
name|llvm
operator|::
name|BumpPtrAllocator
name|_alloc
block|; }
block|;
comment|/// Terminator of the delay-load import table. The content of this atom is all
comment|/// zero.
name|class
name|DelayNullImportDirectoryAtom
operator|:
name|public
name|IdataAtom
block|{
name|public
operator|:
name|explicit
name|DelayNullImportDirectoryAtom
argument_list|(
name|IdataContext
operator|&
name|context
argument_list|)
operator|:
name|IdataAtom
argument_list|(
argument|context
argument_list|,
argument|createContent()
argument_list|)
block|{}
name|StringRef
name|customSectionName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|".didat.d"
return|;
block|}
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|createContent
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
operator|(
sizeof|sizeof
argument_list|(
name|llvm
operator|::
name|object
operator|::
name|delay_import_directory_table_entry
argument_list|)
expr|,
literal|0
operator|)
return|;
block|}
expr|}
block|;
name|class
name|DelayImportAddressAtom
operator|:
name|public
name|IdataAtom
block|{
name|public
operator|:
name|explicit
name|DelayImportAddressAtom
argument_list|(
name|IdataContext
operator|&
name|context
argument_list|)
operator|:
name|IdataAtom
argument_list|(
name|context
argument_list|,
name|createContent
argument_list|(
name|context
operator|.
name|ctx
argument_list|)
argument_list|)
block|,
name|_align
argument_list|(
argument|Alignment(context.ctx.is64Bit() ?
literal|3
argument|:
literal|2
argument|)
argument_list|)
block|{}
name|StringRef
name|customSectionName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|".data"
return|;
block|}
name|ContentPermissions
name|permissions
argument_list|()
specifier|const
name|override
block|{
return|return
name|permRW_
return|;
block|}
name|Alignment
name|alignment
argument_list|()
specifier|const
name|override
block|{
return|return
name|_align
return|;
block|}
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|createContent
argument_list|(
argument|const PECOFFLinkingContext&ctx
argument_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
operator|(
name|ctx
operator|.
name|is64Bit
argument_list|()
operator|?
literal|8
operator|:
literal|4
expr|,
literal|0
operator|)
return|;
block|}
name|Alignment
name|_align
block|; }
block|;
comment|// DelayLoaderAtom contains a wrapper function for __delayLoadHelper2.
name|class
name|DelayLoaderAtom
operator|:
name|public
name|IdataAtom
block|{
name|public
operator|:
name|DelayLoaderAtom
argument_list|(
name|IdataContext
operator|&
name|context
argument_list|,
specifier|const
name|Atom
operator|*
name|impAtom
argument_list|,
specifier|const
name|Atom
operator|*
name|descAtom
argument_list|,
specifier|const
name|Atom
operator|*
name|delayLoadHelperAtom
argument_list|)
block|;
name|StringRef
name|customSectionName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|".text"
return|;
block|}
name|ContentPermissions
name|permissions
argument_list|()
specifier|const
name|override
block|{
return|return
name|permR_X
return|;
block|}
name|Alignment
name|alignment
argument_list|()
specifier|const
name|override
block|{
return|return
name|Alignment
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|createContent
argument_list|(
argument|MachineTypes machine
argument_list|)
specifier|const
block|; }
block|;  }
comment|// namespace idata
name|class
name|IdataPass
operator|:
name|public
name|lld
operator|::
name|Pass
block|{
name|public
operator|:
name|IdataPass
argument_list|(
specifier|const
name|PECOFFLinkingContext
operator|&
name|ctx
argument_list|)
operator|:
name|_dummyFile
argument_list|(
name|ctx
argument_list|)
block|,
name|_ctx
argument_list|(
argument|ctx
argument_list|)
block|{}
name|void
name|perform
argument_list|(
argument|std::unique_ptr<MutableFile>&file
argument_list|)
name|override
block|;
name|private
operator|:
name|std
operator|::
name|map
operator|<
name|StringRef
block|,
name|std
operator|::
name|vector
operator|<
name|COFFSharedLibraryAtom
operator|*
operator|>>
name|groupByLoadName
argument_list|(
name|MutableFile
operator|&
name|file
argument_list|)
block|;
name|void
name|replaceSharedLibraryAtoms
argument_list|(
name|MutableFile
operator|&
name|file
argument_list|)
block|;
comment|// A dummy file with which all the atoms created in the pass will be
comment|// associated. Atoms need to be associated to an input file even if it's not
comment|// read from a file, so we use this object.
name|VirtualFile
name|_dummyFile
block|;
specifier|const
name|PECOFFLinkingContext
operator|&
name|_ctx
block|;
name|llvm
operator|::
name|BumpPtrAllocator
name|_alloc
block|; }
block|;  }
comment|// namespace pecoff
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

