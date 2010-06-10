begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Pragma.h - Pragma registration and handling ------------*- C++ -*-===//
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
comment|// This file defines the PragmaHandler and PragmaTable interfaces.
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
name|LLVM_CLANG_PRAGMA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_PRAGMA_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Preprocessor
decl_stmt|;
name|class
name|Token
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|PragmaNamespace
decl_stmt|;
comment|/// PragmaHandler - Instances of this interface defined to handle the various
comment|/// pragmas that the language front-end uses.  Each handler optionally has a
comment|/// name (e.g. "pack") and the HandlePragma method is invoked when a pragma with
comment|/// that identifier is found.  If a handler does not match any of the declared
comment|/// pragmas the handler with a null identifier is invoked, if it exists.
comment|///
comment|/// Note that the PragmaNamespace class can be used to subdivide pragmas, e.g.
comment|/// we treat "#pragma STDC" and "#pragma GCC" as namespaces that contain other
comment|/// pragmas.
name|class
name|PragmaHandler
block|{
specifier|const
name|IdentifierInfo
modifier|*
name|Name
decl_stmt|;
name|public
label|:
name|PragmaHandler
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|name
argument_list|)
operator|:
name|Name
argument_list|(
argument|name
argument_list|)
block|{}
name|virtual
operator|~
name|PragmaHandler
argument_list|()
expr_stmt|;
specifier|const
name|IdentifierInfo
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|virtual
name|void
name|HandlePragma
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|Token
modifier|&
name|FirstToken
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// getIfNamespace - If this is a namespace, return it.  This is equivalent to
comment|/// using a dynamic_cast, but doesn't require RTTI.
name|virtual
name|PragmaNamespace
modifier|*
name|getIfNamespace
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
block|}
empty_stmt|;
comment|/// PragmaNamespace - This PragmaHandler subdivides the namespace of pragmas,
comment|/// allowing hierarchical pragmas to be defined.  Common examples of namespaces
comment|/// are "#pragma GCC", "#pragma STDC", and "#pragma omp", but any namespaces may
comment|/// be (potentially recursively) defined.
name|class
name|PragmaNamespace
range|:
name|public
name|PragmaHandler
block|{
comment|/// Handlers - This is the list of handlers in this namespace.
comment|///
name|std
operator|::
name|vector
operator|<
name|PragmaHandler
operator|*
operator|>
name|Handlers
block|;
name|public
operator|:
name|PragmaNamespace
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|Name
argument_list|)
operator|:
name|PragmaHandler
argument_list|(
argument|Name
argument_list|)
block|{}
name|virtual
operator|~
name|PragmaNamespace
argument_list|()
block|;
comment|/// FindHandler - Check to see if there is already a handler for the
comment|/// specified name.  If not, return the handler for the null identifier if it
comment|/// exists, otherwise return null.  If IgnoreNull is true (the default) then
comment|/// the null handler isn't returned on failure to match.
name|PragmaHandler
operator|*
name|FindHandler
argument_list|(
argument|const IdentifierInfo *Name
argument_list|,
argument|bool IgnoreNull = true
argument_list|)
specifier|const
block|;
comment|/// AddPragma - Add a pragma to this namespace.
comment|///
name|void
name|AddPragma
argument_list|(
argument|PragmaHandler *Handler
argument_list|)
block|{
name|Handlers
operator|.
name|push_back
argument_list|(
name|Handler
argument_list|)
block|;   }
comment|/// RemovePragmaHandler - Remove the given handler from the
comment|/// namespace.
name|void
name|RemovePragmaHandler
argument_list|(
name|PragmaHandler
operator|*
name|Handler
argument_list|)
block|;
name|bool
name|IsEmpty
argument_list|()
block|{
return|return
name|Handlers
operator|.
name|empty
argument_list|()
return|;
block|}
name|virtual
name|void
name|HandlePragma
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|Token
operator|&
name|FirstToken
argument_list|)
block|;
name|virtual
name|PragmaNamespace
operator|*
name|getIfNamespace
argument_list|()
block|{
return|return
name|this
return|;
block|}
expr|}
block|;   }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

