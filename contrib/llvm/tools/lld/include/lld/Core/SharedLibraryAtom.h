begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Core/SharedLibraryAtom.h - A Shared Library Atom -------------------===//
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
name|LLD_CORE_SHARED_LIBRARY_ATOM_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_SHARED_LIBRARY_ATOM_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/Atom.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
comment|/// A SharedLibraryAtom has no content.
comment|/// It exists to represent a symbol which will be bound at runtime.
name|class
name|SharedLibraryAtom
range|:
name|public
name|Atom
block|{
name|public
operator|:
expr|enum
name|class
name|Type
operator|:
name|uint32_t
block|{
name|Unknown
block|,
name|Code
block|,
name|Data
block|,   }
block|;
comment|/// Returns shared library name used to load it at runtime.
comment|/// On Darwin it is the LC_DYLIB_LOAD dylib name.
name|virtual
name|StringRef
name|loadName
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// Returns if shared library symbol can be missing at runtime and if
comment|/// so the loader should silently resolve address of symbol to be nullptr.
name|virtual
name|bool
name|canBeNullAtRuntime
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|Type
name|type
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|uint64_t
name|size
argument_list|()
specifier|const
operator|=
literal|0
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Atom *a
argument_list|)
block|{
return|return
name|a
operator|->
name|definition
argument_list|()
operator|==
name|definitionSharedLibrary
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SharedLibraryAtom *
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|protected
operator|:
name|SharedLibraryAtom
argument_list|()
operator|:
name|Atom
argument_list|(
argument|definitionSharedLibrary
argument_list|)
block|{}
operator|~
name|SharedLibraryAtom
argument_list|()
name|override
operator|=
expr|default
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
comment|// LLD_CORE_SHARED_LIBRARY_ATOM_H
end_comment

end_unit

