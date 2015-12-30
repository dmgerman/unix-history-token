begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/MachO/ExecutableAtoms.h ---------------------------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_MACHO_EXECUTABLE_ATOMS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_MACHO_EXECUTABLE_ATOMS_H
end_define

begin_include
include|#
directive|include
file|"Atoms.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MachO.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/ArchiveLibraryFile.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/DefinedAtom.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/File.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/LinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Reference.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Simple.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/UndefinedAtom.h"
end_include

begin_include
include|#
directive|include
file|"lld/ReaderWriter/MachOLinkingContext.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|mach_o
block|{
comment|//
comment|// CEntryFile adds an UndefinedAtom for "_main" so that the Resolving
comment|// phase will fail if "_main" is undefined.
comment|//
name|class
name|CEntryFile
range|:
name|public
name|SimpleFile
block|{
name|public
operator|:
name|CEntryFile
argument_list|(
specifier|const
name|MachOLinkingContext
operator|&
name|context
argument_list|)
operator|:
name|SimpleFile
argument_list|(
literal|"C entry"
argument_list|)
block|,
name|_undefMain
argument_list|(
argument|*this
argument_list|,
argument|context.entrySymbolName()
argument_list|)
block|{
name|this
operator|->
name|addAtom
argument_list|(
name|_undefMain
argument_list|)
block|;   }
name|private
operator|:
name|SimpleUndefinedAtom
name|_undefMain
block|; }
decl_stmt|;
comment|//
comment|// StubHelperFile adds an UndefinedAtom for "dyld_stub_binder" so that
comment|// the Resolveing phase will fail if "dyld_stub_binder" is undefined.
comment|//
name|class
name|StubHelperFile
range|:
name|public
name|SimpleFile
block|{
name|public
operator|:
name|StubHelperFile
argument_list|(
specifier|const
name|MachOLinkingContext
operator|&
name|context
argument_list|)
operator|:
name|SimpleFile
argument_list|(
literal|"stub runtime"
argument_list|)
block|,
name|_undefBinder
argument_list|(
argument|*this
argument_list|,
argument|context.binderSymbolName()
argument_list|)
block|{
name|this
operator|->
name|addAtom
argument_list|(
name|_undefBinder
argument_list|)
block|;   }
name|private
operator|:
name|SimpleUndefinedAtom
name|_undefBinder
block|; }
decl_stmt|;
comment|//
comment|// MachHeaderAliasFile lazily instantiates the magic symbols that mark the start
comment|// of the mach_header for final linked images.
comment|//
name|class
name|MachHeaderAliasFile
range|:
name|public
name|ArchiveLibraryFile
block|{
name|public
operator|:
name|MachHeaderAliasFile
argument_list|(
specifier|const
name|MachOLinkingContext
operator|&
name|context
argument_list|)
operator|:
name|ArchiveLibraryFile
argument_list|(
literal|"mach_header symbols"
argument_list|)
block|{
switch|switch
condition|(
name|context
operator|.
name|outputMachOType
argument_list|()
condition|)
block|{
case|case
name|llvm
operator|::
name|MachO
operator|::
name|MH_EXECUTE
case|:
name|_machHeaderSymbolName
operator|=
literal|"__mh_execute_header"
expr_stmt|;
break|break;
case|case
name|llvm
operator|::
name|MachO
operator|::
name|MH_DYLIB
case|:
name|_machHeaderSymbolName
operator|=
literal|"__mh_dylib_header"
expr_stmt|;
break|break;
case|case
name|llvm
operator|::
name|MachO
operator|::
name|MH_BUNDLE
case|:
name|_machHeaderSymbolName
operator|=
literal|"__mh_bundle_header"
expr_stmt|;
break|break;
case|case
name|llvm
operator|::
name|MachO
operator|::
name|MH_DYLINKER
case|:
name|_machHeaderSymbolName
operator|=
literal|"__mh_dylinker_header"
expr_stmt|;
break|break;
case|case
name|llvm
operator|::
name|MachO
operator|::
name|MH_PRELOAD
case|:
name|_machHeaderSymbolName
operator|=
literal|"__mh_preload_header"
expr_stmt|;
break|break;
default|default:
name|llvm_unreachable
argument_list|(
literal|"no mach_header symbol for file type"
argument_list|)
expr_stmt|;
block|}
block|}
name|std
operator|::
name|error_code
name|parseAllMembers
argument_list|(
argument|std::vector<std::unique_ptr<File>>&result
argument_list|)
name|override
block|{
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
name|File
operator|*
name|find
argument_list|(
argument|StringRef sym
argument_list|,
argument|bool dataSymbolOnly
argument_list|)
name|override
block|{
if|if
condition|(
name|sym
operator|.
name|equals
argument_list|(
literal|"___dso_handle"
argument_list|)
operator|||
name|sym
operator|.
name|equals
argument_list|(
name|_machHeaderSymbolName
argument_list|)
condition|)
block|{
name|_definedAtoms
operator|.
name|push_back
argument_list|(
name|new
argument_list|(
argument|allocator()
argument_list|)
name|MachODefinedAtom
argument_list|(
operator|*
name|this
argument_list|,
name|sym
argument_list|,
name|DefinedAtom
operator|::
name|scopeLinkageUnit
argument_list|,
name|DefinedAtom
operator|::
name|typeMachHeader
argument_list|,
name|DefinedAtom
operator|::
name|mergeNo
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|(
operator|)
argument_list|,
name|DefinedAtom
operator|::
name|Alignment
argument_list|(
literal|4096
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|this
return|;
block|}
return|return
name|nullptr
return|;
block|}
specifier|const
name|AtomVector
operator|<
name|DefinedAtom
operator|>
operator|&
name|defined
argument_list|()
specifier|const
name|override
block|{
return|return
name|_definedAtoms
return|;
block|}
specifier|const
name|AtomVector
operator|<
name|UndefinedAtom
operator|>
operator|&
name|undefined
argument_list|()
specifier|const
name|override
block|{
return|return
name|_noUndefinedAtoms
return|;
block|}
specifier|const
name|AtomVector
operator|<
name|SharedLibraryAtom
operator|>
operator|&
name|sharedLibrary
argument_list|()
specifier|const
name|override
block|{
return|return
name|_noSharedLibraryAtoms
return|;
block|}
specifier|const
name|AtomVector
operator|<
name|AbsoluteAtom
operator|>
operator|&
name|absolute
argument_list|()
specifier|const
name|override
block|{
return|return
name|_noAbsoluteAtoms
return|;
block|}
name|private
operator|:
name|mutable
name|AtomVector
operator|<
name|DefinedAtom
operator|>
name|_definedAtoms
block|;
name|StringRef
name|_machHeaderSymbolName
block|; }
decl_stmt|;
block|}
comment|// namespace mach_o
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_MACHO_EXECUTABLE_ATOMS_H
end_comment

end_unit

