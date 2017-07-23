begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ASTDeserializationListener.h - Decl/Type PCH Read Events -*- C++ -*-===//
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
comment|//  This file defines the ASTDeserializationListener class, which is notified
end_comment

begin_comment
comment|//  by the ASTReader whenever a type or declaration is deserialized.
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
name|LLVM_CLANG_SERIALIZATION_ASTDESERIALIZATIONLISTENER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SERIALIZATION_ASTDESERIALIZATIONLISTENER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/ASTBitCodes.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|class
name|ASTReader
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|MacroDefinitionRecord
decl_stmt|;
name|class
name|MacroInfo
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|SourceLocation
decl_stmt|;
name|class
name|ASTDeserializationListener
block|{
name|public
label|:
name|virtual
operator|~
name|ASTDeserializationListener
argument_list|()
expr_stmt|;
comment|/// \brief The ASTReader was initialized.
name|virtual
name|void
name|ReaderInitialized
parameter_list|(
name|ASTReader
modifier|*
name|Reader
parameter_list|)
block|{ }
comment|/// \brief An identifier was deserialized from the AST file.
name|virtual
name|void
name|IdentifierRead
argument_list|(
name|serialization
operator|::
name|IdentID
name|ID
argument_list|,
name|IdentifierInfo
operator|*
name|II
argument_list|)
block|{ }
comment|/// \brief A macro was read from the AST file.
name|virtual
name|void
name|MacroRead
argument_list|(
name|serialization
operator|::
name|MacroID
name|ID
argument_list|,
name|MacroInfo
operator|*
name|MI
argument_list|)
block|{ }
comment|/// \brief A type was deserialized from the AST file. The ID here has the
comment|///        qualifier bits already removed, and T is guaranteed to be locally
comment|///        unqualified.
name|virtual
name|void
name|TypeRead
argument_list|(
name|serialization
operator|::
name|TypeIdx
name|Idx
argument_list|,
name|QualType
name|T
argument_list|)
block|{ }
comment|/// \brief A decl was deserialized from the AST file.
name|virtual
name|void
name|DeclRead
argument_list|(
name|serialization
operator|::
name|DeclID
name|ID
argument_list|,
specifier|const
name|Decl
operator|*
name|D
argument_list|)
block|{ }
comment|/// \brief A selector was read from the AST file.
name|virtual
name|void
name|SelectorRead
argument_list|(
name|serialization
operator|::
name|SelectorID
name|iD
argument_list|,
name|Selector
name|Sel
argument_list|)
block|{}
comment|/// \brief A macro definition was read from the AST file.
name|virtual
name|void
name|MacroDefinitionRead
argument_list|(
name|serialization
operator|::
name|PreprocessedEntityID
argument_list|,
name|MacroDefinitionRecord
operator|*
name|MD
argument_list|)
block|{}
comment|/// \brief A module definition was read from the AST file.
name|virtual
name|void
name|ModuleRead
argument_list|(
name|serialization
operator|::
name|SubmoduleID
name|ID
argument_list|,
name|Module
operator|*
name|Mod
argument_list|)
block|{}
comment|/// \brief A module import was read from the AST file.
name|virtual
name|void
name|ModuleImportRead
argument_list|(
name|serialization
operator|::
name|SubmoduleID
name|ID
argument_list|,
name|SourceLocation
name|ImportLoc
argument_list|)
block|{}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

