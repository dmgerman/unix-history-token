begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Core/SharedLibraryFile.h - Models shared libraries as Atoms --------===//
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
name|LLD_CORE_SHARED_LIBRARY_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_SHARED_LIBRARY_FILE_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/File.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
comment|///
comment|/// The SharedLibraryFile subclass of File is used to represent dynamic
comment|/// shared libraries being linked against.
comment|///
name|class
name|SharedLibraryFile
range|:
name|public
name|File
block|{
name|public
operator|:
specifier|static
name|bool
name|classof
argument_list|(
argument|const File *f
argument_list|)
block|{
return|return
name|f
operator|->
name|kind
argument_list|()
operator|==
name|kindSharedLibrary
return|;
block|}
comment|/// Check if the shared library exports a symbol with the specified name.
comment|/// If so, return a SharedLibraryAtom which represents that exported
comment|/// symbol.  Otherwise return nullptr.
name|virtual
name|OwningAtomPtr
operator|<
name|SharedLibraryAtom
operator|>
name|exports
argument_list|(
argument|StringRef name
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// Returns the install name.
name|virtual
name|StringRef
name|getDSOName
argument_list|()
specifier|const
operator|=
literal|0
block|;
specifier|const
name|AtomRange
operator|<
name|DefinedAtom
operator|>
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
name|AtomRange
operator|<
name|UndefinedAtom
operator|>
name|undefined
argument_list|()
specifier|const
name|override
block|{
return|return
name|_undefinedAtoms
return|;
block|}
specifier|const
name|AtomRange
operator|<
name|SharedLibraryAtom
operator|>
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
name|AtomRange
operator|<
name|AbsoluteAtom
operator|>
name|absolute
argument_list|()
specifier|const
name|override
block|{
return|return
name|_absoluteAtoms
return|;
block|}
name|void
name|clearAtoms
argument_list|()
name|override
block|{
name|_definedAtoms
operator|.
name|clear
argument_list|()
block|;
name|_undefinedAtoms
operator|.
name|clear
argument_list|()
block|;
name|_sharedLibraryAtoms
operator|.
name|clear
argument_list|()
block|;
name|_absoluteAtoms
operator|.
name|clear
argument_list|()
block|;   }
name|protected
operator|:
comment|/// only subclasses of SharedLibraryFile can be instantiated
name|explicit
name|SharedLibraryFile
argument_list|(
argument|StringRef path
argument_list|)
operator|:
name|File
argument_list|(
argument|path
argument_list|,
argument|kindSharedLibrary
argument_list|)
block|{}
name|AtomVector
operator|<
name|DefinedAtom
operator|>
name|_definedAtoms
block|;
name|AtomVector
operator|<
name|UndefinedAtom
operator|>
name|_undefinedAtoms
block|;
name|AtomVector
operator|<
name|SharedLibraryAtom
operator|>
name|_sharedLibraryAtoms
block|;
name|AtomVector
operator|<
name|AbsoluteAtom
operator|>
name|_absoluteAtoms
block|; }
decl_stmt|;
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
comment|// LLD_CORE_SHARED_LIBRARY_FILE_H
end_comment

end_unit

