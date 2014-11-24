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
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
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
comment|/**    * \brief Describes how the pragma was introduced, e.g., with \#pragma,    * _Pragma, or __pragma.    */
enum|enum
name|PragmaIntroducerKind
block|{
comment|/**      * \brief The pragma was introduced via \#pragma.      */
name|PIK_HashPragma
block|,
comment|/**      * \brief The pragma was introduced via the C99 _Pragma(string-literal).      */
name|PIK__Pragma
block|,
comment|/**      * \brief The pragma was introduced via the Microsoft       * __pragma(token-string).      */
name|PIK___pragma
block|}
enum|;
comment|/// PragmaHandler - Instances of this interface defined to handle the various
comment|/// pragmas that the language front-end uses.  Each handler optionally has a
comment|/// name (e.g. "pack") and the HandlePragma method is invoked when a pragma with
comment|/// that identifier is found.  If a handler does not match any of the declared
comment|/// pragmas the handler with a null identifier is invoked, if it exists.
comment|///
comment|/// Note that the PragmaNamespace class can be used to subdivide pragmas, e.g.
comment|/// we treat "\#pragma STDC" and "\#pragma GCC" as namespaces that contain other
comment|/// pragmas.
name|class
name|PragmaHandler
block|{
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|public
label|:
name|explicit
name|PragmaHandler
argument_list|(
argument|StringRef name
argument_list|)
block|:
name|Name
argument_list|(
argument|name
argument_list|)
block|{}
name|PragmaHandler
argument_list|()
block|{}
name|virtual
operator|~
name|PragmaHandler
argument_list|()
expr_stmt|;
name|StringRef
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
name|PragmaIntroducerKind
name|Introducer
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
name|nullptr
return|;
block|}
block|}
empty_stmt|;
comment|/// EmptyPragmaHandler - A pragma handler which takes no action, which can be
comment|/// used to ignore particular pragmas.
name|class
name|EmptyPragmaHandler
range|:
name|public
name|PragmaHandler
block|{
name|public
operator|:
name|EmptyPragmaHandler
argument_list|()
block|;
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
name|override
block|; }
decl_stmt|;
comment|/// PragmaNamespace - This PragmaHandler subdivides the namespace of pragmas,
comment|/// allowing hierarchical pragmas to be defined.  Common examples of namespaces
comment|/// are "\#pragma GCC", "\#pragma STDC", and "\#pragma omp", but any namespaces
comment|/// may be (potentially recursively) defined.
name|class
name|PragmaNamespace
range|:
name|public
name|PragmaHandler
block|{
comment|/// Handlers - This is a map of the handlers in this namespace with their name
comment|/// as key.
comment|///
name|llvm
operator|::
name|StringMap
operator|<
name|PragmaHandler
operator|*
operator|>
name|Handlers
block|;
name|public
operator|:
name|explicit
name|PragmaNamespace
argument_list|(
argument|StringRef Name
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
comment|/// specified name.  If not, return the handler for the null name if it
comment|/// exists, otherwise return null.  If IgnoreNull is true (the default) then
comment|/// the null handler isn't returned on failure to match.
name|PragmaHandler
operator|*
name|FindHandler
argument_list|(
argument|StringRef Name
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
name|PragmaHandler
operator|*
name|Handler
argument_list|)
block|;
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
name|void
name|HandlePragma
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|PragmaIntroducerKind Introducer
argument_list|,
argument|Token&FirstToken
argument_list|)
name|override
block|;
name|PragmaNamespace
operator|*
name|getIfNamespace
argument_list|()
name|override
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

