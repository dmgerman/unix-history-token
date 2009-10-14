begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Entity.h - Cross-translation-unit "token" for decls ----*- C++ -*-===//
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
comment|//  Entity is a ASTContext-independent way to refer to declarations that are
end_comment

begin_comment
comment|//  visible across translation units.
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
name|LLVM_CLANG_INDEX_ENTITY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_ENTITY_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
name|class
name|ASTContext
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|namespace
name|idx
block|{
name|class
name|Program
decl_stmt|;
name|class
name|EntityImpl
decl_stmt|;
comment|/// \brief A ASTContext-independent way to refer to declarations.
comment|///
comment|/// Entity is basically the link for declarations that are semantically the same
comment|/// in multiple ASTContexts. A client will convert a Decl into an Entity and
comment|/// later use that Entity to find the "same" Decl into another ASTContext.
comment|/// Declarations that are semantically the same and visible across translation
comment|/// units will be associated with the same Entity.
comment|///
comment|/// An Entity may also refer to declarations that cannot be visible across
comment|/// translation units, e.g. static functions with the same name in multiple
comment|/// translation units will be associated with different Entities.
comment|///
comment|/// Entities can be checked for equality but note that the same Program object
comment|/// should be used when getting Entities.
comment|///
name|class
name|Entity
block|{
comment|/// \brief Stores the Decl directly if it is not visible outside of its own
comment|/// translation unit, otherwise it stores the associated EntityImpl.
name|llvm
operator|::
name|PointerUnion
operator|<
name|Decl
operator|*
operator|,
name|EntityImpl
operator|*
operator|>
name|Val
expr_stmt|;
name|explicit
name|Entity
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|explicit
name|Entity
argument_list|(
name|EntityImpl
operator|*
name|impl
argument_list|)
operator|:
name|Val
argument_list|(
argument|impl
argument_list|)
block|{ }
name|friend
name|class
name|EntityGetter
expr_stmt|;
name|public
label|:
name|Entity
argument_list|()
block|{ }
comment|/// \brief Find the Decl that can be referred to by this entity.
name|Decl
modifier|*
name|getDecl
argument_list|(
name|ASTContext
operator|&
name|AST
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief If this Entity represents a declaration that is internal to its
comment|/// translation unit, getInternalDecl() returns it.
name|Decl
operator|*
name|getInternalDecl
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isInternalToTU
argument_list|()
operator|&&
literal|"This Entity is not internal!"
argument_list|)
block|;
return|return
name|Val
operator|.
name|get
operator|<
name|Decl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Get a printable name for debugging purpose.
name|std
operator|::
name|string
name|getPrintableName
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Get an Entity associated with the given Decl.
comment|/// \returns invalid Entity if an Entity cannot refer to this Decl.
specifier|static
name|Entity
name|get
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|Program
modifier|&
name|Prog
parameter_list|)
function_decl|;
comment|/// \brief true if the Entity is not visible outside the trasnlation unit.
name|bool
name|isInternalToTU
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isValid
argument_list|()
operator|&&
literal|"This Entity is not valid!"
argument_list|)
block|;
return|return
name|Val
operator|.
name|is
operator|<
name|Decl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Val
operator|.
name|isNull
argument_list|()
return|;
block|}
name|bool
name|isInvalid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isValid
argument_list|()
return|;
block|}
name|void
operator|*
name|getAsOpaquePtr
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
specifier|static
name|Entity
name|getFromOpaquePtr
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
block|{
name|Entity
name|Ent
decl_stmt|;
name|Ent
operator|.
name|Val
operator|=
name|llvm
operator|::
name|PointerUnion
operator|<
name|Decl
operator|*
operator|,
name|EntityImpl
operator|*
operator|>
operator|::
name|getFromOpaqueValue
argument_list|(
name|Ptr
argument_list|)
expr_stmt|;
return|return
name|Ent
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Entity
operator|&
name|LHS
operator|,
specifier|const
name|Entity
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|getAsOpaquePtr
argument_list|()
operator|==
name|RHS
operator|.
name|getAsOpaquePtr
argument_list|()
return|;
block|}
comment|// For use in a std::map.
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Entity
operator|&
name|LHS
operator|,
specifier|const
name|Entity
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|getAsOpaquePtr
argument_list|()
operator|<
name|RHS
operator|.
name|getAsOpaquePtr
argument_list|()
return|;
block|}
comment|// For use in DenseMap/DenseSet.
specifier|static
name|Entity
name|getEmptyMarker
parameter_list|()
block|{
name|Entity
name|Ent
decl_stmt|;
name|Ent
operator|.
name|Val
operator|=
name|llvm
operator|::
name|PointerUnion
operator|<
name|Decl
operator|*
operator|,
name|EntityImpl
operator|*
operator|>
operator|::
name|getFromOpaqueValue
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|Ent
return|;
block|}
specifier|static
name|Entity
name|getTombstoneMarker
parameter_list|()
block|{
name|Entity
name|Ent
decl_stmt|;
name|Ent
operator|.
name|Val
operator|=
name|llvm
operator|::
name|PointerUnion
operator|<
name|Decl
operator|*
operator|,
name|EntityImpl
operator|*
operator|>
operator|::
name|getFromOpaqueValue
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|-
literal|2
argument_list|)
expr_stmt|;
return|return
name|Ent
return|;
block|}
block|}
empty_stmt|;
block|}
comment|// namespace idx
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Define DenseMapInfo so that Entities can be used as keys in DenseMap and
comment|/// DenseSets.
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|clang
operator|::
name|idx
operator|::
name|Entity
operator|>
block|{
specifier|static
specifier|inline
name|clang
operator|::
name|idx
operator|::
name|Entity
name|getEmptyKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|idx
operator|::
name|Entity
operator|::
name|getEmptyMarker
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|clang
operator|::
name|idx
operator|::
name|Entity
name|getTombstoneKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|idx
operator|::
name|Entity
operator|::
name|getTombstoneMarker
argument_list|()
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
name|clang
operator|::
name|idx
operator|::
name|Entity
argument_list|)
block|;
specifier|static
specifier|inline
name|bool
name|isEqual
argument_list|(
argument|clang::idx::Entity LHS
argument_list|,
argument|clang::idx::Entity RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isPod
argument_list|()
block|{
return|return
name|true
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

