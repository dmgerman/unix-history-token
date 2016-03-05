begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TestModuleFileExtension.h - Module Extension Tester -----*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_TESTMODULEFILEEXTENSION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_TESTMODULEFILEEXTENSION_H
end_define

begin_include
include|#
directive|include
file|"clang/Serialization/ModuleFileExtension.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Bitcode/BitstreamReader.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// A module file extension used for testing purposes.
name|class
name|TestModuleFileExtension
range|:
name|public
name|ModuleFileExtension
block|{
name|std
operator|::
name|string
name|BlockName
block|;
name|unsigned
name|MajorVersion
block|;
name|unsigned
name|MinorVersion
block|;
name|bool
name|Hashed
block|;
name|std
operator|::
name|string
name|UserInfo
block|;
name|class
name|Writer
operator|:
name|public
name|ModuleFileExtensionWriter
block|{
name|public
operator|:
name|Writer
argument_list|(
name|ModuleFileExtension
operator|*
name|Ext
argument_list|)
operator|:
name|ModuleFileExtensionWriter
argument_list|(
argument|Ext
argument_list|)
block|{ }
operator|~
name|Writer
argument_list|()
name|override
block|;
name|void
name|writeExtensionContents
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|llvm::BitstreamWriter&Stream
argument_list|)
name|override
block|;   }
block|;
name|class
name|Reader
operator|:
name|public
name|ModuleFileExtensionReader
block|{
name|llvm
operator|::
name|BitstreamCursor
name|Stream
block|;
name|public
operator|:
operator|~
name|Reader
argument_list|()
name|override
block|;
name|Reader
argument_list|(
name|ModuleFileExtension
operator|*
name|Ext
argument_list|,
specifier|const
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|InStream
argument_list|)
block|;   }
block|;
name|public
operator|:
name|TestModuleFileExtension
argument_list|(
argument|StringRef BlockName
argument_list|,
argument|unsigned MajorVersion
argument_list|,
argument|unsigned MinorVersion
argument_list|,
argument|bool Hashed
argument_list|,
argument|StringRef UserInfo
argument_list|)
operator|:
name|BlockName
argument_list|(
name|BlockName
argument_list|)
block|,
name|MajorVersion
argument_list|(
name|MajorVersion
argument_list|)
block|,
name|MinorVersion
argument_list|(
name|MinorVersion
argument_list|)
block|,
name|Hashed
argument_list|(
name|Hashed
argument_list|)
block|,
name|UserInfo
argument_list|(
argument|UserInfo
argument_list|)
block|{ }
operator|~
name|TestModuleFileExtension
argument_list|()
name|override
block|;
name|ModuleFileExtensionMetadata
name|getExtensionMetadata
argument_list|()
specifier|const
name|override
block|;
name|llvm
operator|::
name|hash_code
name|hashExtension
argument_list|(
argument|llvm::hash_code Code
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleFileExtensionWriter
operator|>
name|createExtensionWriter
argument_list|(
argument|ASTWriter&Writer
argument_list|)
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleFileExtensionReader
operator|>
name|createExtensionReader
argument_list|(
argument|const ModuleFileExtensionMetadata&Metadata
argument_list|,
argument|ASTReader&Reader
argument_list|,
argument|serialization::ModuleFile&Mod
argument_list|,
argument|const llvm::BitstreamCursor&Stream
argument_list|)
name|override
block|; }
decl_stmt|;
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
comment|// LLVM_CLANG_FRONTEND_TESTMODULEFILEEXTENSION_H
end_comment

end_unit

