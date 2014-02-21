begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTMutationListener.h - AST Mutation Interface --------*- C++ -*-===//
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
comment|//  This file defines the ASTMutationListener interface.
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
name|LLVM_CLANG_AST_ASTMUTATIONLISTENER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_ASTMUTATIONLISTENER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|ClassTemplateDecl
decl_stmt|;
name|class
name|ClassTemplateSpecializationDecl
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|FunctionTemplateDecl
decl_stmt|;
name|class
name|ObjCCategoryDecl
decl_stmt|;
name|class
name|ObjCContainerDecl
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|ObjCPropertyDecl
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|TagDecl
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|class
name|VarTemplateDecl
decl_stmt|;
name|class
name|VarTemplateSpecializationDecl
decl_stmt|;
comment|/// \brief An abstract interface that should be implemented by listeners
comment|/// that want to be notified when an AST entity gets modified after its
comment|/// initial creation.
name|class
name|ASTMutationListener
block|{
name|public
label|:
name|virtual
operator|~
name|ASTMutationListener
argument_list|()
expr_stmt|;
comment|/// \brief A new TagDecl definition was completed.
name|virtual
name|void
name|CompletedTagDefinition
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|D
parameter_list|)
block|{ }
comment|/// \brief A new declaration with name has been added to a DeclContext.
name|virtual
name|void
name|AddedVisibleDecl
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|,
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// \brief An implicit member was added after the definition was completed.
name|virtual
name|void
name|AddedCXXImplicitMember
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// \brief A template specialization (or partial one) was added to the
comment|/// template declaration.
name|virtual
name|void
name|AddedCXXTemplateSpecialization
parameter_list|(
specifier|const
name|ClassTemplateDecl
modifier|*
name|TD
parameter_list|,
specifier|const
name|ClassTemplateSpecializationDecl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// \brief A template specialization (or partial one) was added to the
comment|/// template declaration.
name|virtual
name|void
name|AddedCXXTemplateSpecialization
parameter_list|(
specifier|const
name|VarTemplateDecl
modifier|*
name|TD
parameter_list|,
specifier|const
name|VarTemplateSpecializationDecl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// \brief A template specialization (or partial one) was added to the
comment|/// template declaration.
name|virtual
name|void
name|AddedCXXTemplateSpecialization
parameter_list|(
specifier|const
name|FunctionTemplateDecl
modifier|*
name|TD
parameter_list|,
specifier|const
name|FunctionDecl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// \brief A function's return type has been deduced.
name|virtual
name|void
name|DeducedReturnType
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|QualType
name|ReturnType
parameter_list|)
function_decl|;
comment|/// \brief An implicit member got a definition.
name|virtual
name|void
name|CompletedImplicitDefinition
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// \brief A static data member was implicitly instantiated.
name|virtual
name|void
name|StaticDataMemberInstantiated
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// \brief A new objc category class was added for an interface.
name|virtual
name|void
name|AddedObjCCategoryToInterface
parameter_list|(
specifier|const
name|ObjCCategoryDecl
modifier|*
name|CatD
parameter_list|,
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|IFD
parameter_list|)
block|{}
comment|/// \brief A objc class extension redeclared or introduced a property.
comment|///
comment|/// \param Prop the property in the class extension
comment|///
comment|/// \param OrigProp the property from the original interface that was declared
comment|/// or null if the property was introduced.
comment|///
comment|/// \param ClassExt the class extension.
name|virtual
name|void
name|AddedObjCPropertyInClassExtension
parameter_list|(
specifier|const
name|ObjCPropertyDecl
modifier|*
name|Prop
parameter_list|,
specifier|const
name|ObjCPropertyDecl
modifier|*
name|OrigProp
parameter_list|,
specifier|const
name|ObjCCategoryDecl
modifier|*
name|ClassExt
parameter_list|)
block|{}
comment|/// \brief A declaration is marked used which was not previously marked used.
comment|///
comment|/// \param D the declaration marked used
name|virtual
name|void
name|DeclarationMarkedUsed
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{}
comment|// NOTE: If new methods are added they should also be added to
comment|// MultiplexASTMutationListener.
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

end_unit

