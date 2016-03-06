begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ModuleFileExtension.h - Module File Extensions ----------*- C++ -*-===//
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
name|LLVM_CLANG_SERIALIZATION_MODULEFILEEXTENSION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SERIALIZATION_MODULEFILEEXTENSION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|BitstreamCursor
decl_stmt|;
name|class
name|BitstreamWriter
decl_stmt|;
name|class
name|hash_code
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTReader
decl_stmt|;
name|class
name|ASTWriter
decl_stmt|;
name|class
name|Sema
decl_stmt|;
name|namespace
name|serialization
block|{
name|class
name|ModuleFile
decl_stmt|;
block|}
comment|// end namespace serialization
comment|/// Metadata for a module file extension.
struct|struct
name|ModuleFileExtensionMetadata
block|{
comment|/// The name used to identify this particular extension block within
comment|/// the resulting module file. It should be unique to the particular
comment|/// extension, because this name will be used to match the name of
comment|/// an extension block to the appropriate reader.
name|std
operator|::
name|string
name|BlockName
expr_stmt|;
comment|/// The major version of the extension data.
name|unsigned
name|MajorVersion
decl_stmt|;
comment|/// The minor version of the extension data.
name|unsigned
name|MinorVersion
decl_stmt|;
comment|/// A string containing additional user information that will be
comment|/// stored with the metadata.
name|std
operator|::
name|string
name|UserInfo
expr_stmt|;
block|}
struct|;
name|class
name|ModuleFileExtensionReader
decl_stmt|;
name|class
name|ModuleFileExtensionWriter
decl_stmt|;
comment|/// An abstract superclass that describes a custom extension to the
comment|/// module/precompiled header file format.
comment|///
comment|/// A module file extension can introduce additional information into
comment|/// compiled module files (.pcm) and precompiled headers (.pch) via a
comment|/// custom writer that can then be accessed via a custom reader when
comment|/// the module file or precompiled header is loaded.
name|class
name|ModuleFileExtension
range|:
name|public
name|llvm
operator|::
name|RefCountedBase
operator|<
name|ModuleFileExtension
operator|>
block|{
name|public
operator|:
name|virtual
operator|~
name|ModuleFileExtension
argument_list|()
block|;
comment|/// Retrieves the metadata for this module file extension.
name|virtual
name|ModuleFileExtensionMetadata
name|getExtensionMetadata
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// Hash information about the presence of this extension into the
comment|/// module hash code.
comment|///
comment|/// The module hash code is used to distinguish different variants
comment|/// of a module that are incompatible. If the presence, absence, or
comment|/// version of the module file extension should force the creation
comment|/// of a separate set of module files, override this method to
comment|/// combine that distinguishing information into the module hash
comment|/// code.
comment|///
comment|/// The default implementation of this function simply returns the
comment|/// hash code as given, so the presence/absence of this extension
comment|/// does not distinguish module files.
name|virtual
name|llvm
operator|::
name|hash_code
name|hashExtension
argument_list|(
argument|llvm::hash_code c
argument_list|)
specifier|const
block|;
comment|/// Create a new module file extension writer, which will be
comment|/// responsible for writing the extension contents into a particular
comment|/// module file.
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleFileExtensionWriter
operator|>
name|createExtensionWriter
argument_list|(
name|ASTWriter
operator|&
name|Writer
argument_list|)
operator|=
literal|0
block|;
comment|/// Create a new module file extension reader, given the
comment|/// metadata read from the block and the cursor into the extension
comment|/// block.
comment|///
comment|/// May return null to indicate that an extension block with the
comment|/// given metadata cannot be read.
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleFileExtensionReader
operator|>
name|createExtensionReader
argument_list|(
specifier|const
name|ModuleFileExtensionMetadata
operator|&
name|Metadata
argument_list|,
name|ASTReader
operator|&
name|Reader
argument_list|,
name|serialization
operator|::
name|ModuleFile
operator|&
name|Mod
argument_list|,
specifier|const
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Stream
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
comment|/// Abstract base class that writes a module file extension block into
comment|/// a module file.
name|class
name|ModuleFileExtensionWriter
block|{
name|ModuleFileExtension
modifier|*
name|Extension
decl_stmt|;
name|protected
label|:
name|ModuleFileExtensionWriter
argument_list|(
name|ModuleFileExtension
operator|*
name|Extension
argument_list|)
operator|:
name|Extension
argument_list|(
argument|Extension
argument_list|)
block|{ }
name|public
operator|:
name|virtual
operator|~
name|ModuleFileExtensionWriter
argument_list|()
expr_stmt|;
comment|/// Retrieve the module file extension with which this writer is
comment|/// associated.
name|ModuleFileExtension
operator|*
name|getExtension
argument_list|()
specifier|const
block|{
return|return
name|Extension
return|;
block|}
comment|/// Write the contents of the extension block into the given bitstream.
comment|///
comment|/// Responsible for writing the contents of the extension into the
comment|/// given stream. All of the contents should be written into custom
comment|/// records with IDs>= FIRST_EXTENSION_RECORD_ID.
name|virtual
name|void
name|writeExtensionContents
argument_list|(
name|Sema
operator|&
name|SemaRef
argument_list|,
name|llvm
operator|::
name|BitstreamWriter
operator|&
name|Stream
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// Abstract base class that reads a module file extension block from
comment|/// a module file.
comment|///
comment|/// Subclasses
name|class
name|ModuleFileExtensionReader
block|{
name|ModuleFileExtension
modifier|*
name|Extension
decl_stmt|;
name|protected
label|:
name|ModuleFileExtensionReader
argument_list|(
name|ModuleFileExtension
operator|*
name|Extension
argument_list|)
operator|:
name|Extension
argument_list|(
argument|Extension
argument_list|)
block|{ }
name|public
operator|:
comment|/// Retrieve the module file extension with which this reader is
comment|/// associated.
name|ModuleFileExtension
operator|*
name|getExtension
argument_list|()
specifier|const
block|{
return|return
name|Extension
return|;
block|}
name|virtual
operator|~
name|ModuleFileExtensionReader
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_FRONTEND_MODULEFILEEXTENSION_H
end_comment

end_unit

