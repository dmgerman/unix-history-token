begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/MachO/FlatNamespaceFile.h -------------------------===//
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
name|LLD_READER_WRITER_MACHO_FLAT_NAMESPACE_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_MACHO_FLAT_NAMESPACE_FILE_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/SharedLibraryFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|mach_o
block|{
comment|//
comment|// A FlateNamespaceFile instance may be added as a resolution source of last
comment|// resort, depending on how -flat_namespace and -undefined are set.
comment|//
name|class
name|FlatNamespaceFile
range|:
name|public
name|SharedLibraryFile
block|{
name|public
operator|:
name|FlatNamespaceFile
argument_list|(
specifier|const
name|MachOLinkingContext
operator|&
name|context
argument_list|)
operator|:
name|SharedLibraryFile
argument_list|(
literal|"flat namespace"
argument_list|)
block|{ }
specifier|const
name|SharedLibraryAtom
operator|*
name|exports
argument_list|(
argument|StringRef name
argument_list|,
argument|bool dataSymbolOnly
argument_list|)
specifier|const
name|override
block|{
name|_sharedLibraryAtoms
operator|.
name|push_back
argument_list|(
name|new
argument_list|(
argument|allocator()
argument_list|)
name|MachOSharedLibraryAtom
argument_list|(
operator|*
name|this
argument_list|,
name|name
argument_list|,
name|getDSOName
argument_list|()
argument_list|,
name|false
argument_list|)
argument_list|)
block|;
return|return
name|_sharedLibraryAtoms
operator|.
name|back
argument_list|()
return|;
block|}
name|StringRef
name|getDSOName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"flat-namespace"
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
name|_noDefinedAtoms
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
name|_sharedLibraryAtoms
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
name|SharedLibraryAtom
operator|>
name|_sharedLibraryAtoms
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
comment|// LLD_READER_WRITER_MACHO_FLAT_NAMESPACE_FILE_H
end_comment

end_unit

