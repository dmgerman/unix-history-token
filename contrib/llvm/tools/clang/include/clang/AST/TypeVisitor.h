begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TypeVisitor.h - Visitor for Type subclasses ------------*- C++ -*-===//
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
comment|//  This file defines the TypeVisitor interface.
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
name|LLVM_CLANG_AST_TYPEVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_TYPEVISITOR_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
define|#
directive|define
name|DISPATCH
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|return static_cast<ImplClass*>(this)-> \            Visit##CLASS(static_cast<const CLASS*>(T))
comment|/// \brief An operation on a type.
comment|///
comment|/// \tparam ImplClass Class implementing the operation. Must be inherited from
comment|///         TypeVisitor.
comment|/// \tparam RetTy %Type of result produced by the operation.
comment|///
comment|/// The class implements polymorphic operation on an object of type derived
comment|/// from Type. The operation is performed by calling method Visit. It then
comment|/// dispatches the call to function \c VisitFooType, if actual argument type
comment|/// is \c FooType.
comment|///
comment|/// The class implements static polymorphism using Curiously Recurring
comment|/// Template Pattern. It is designed to be a base class for some concrete
comment|/// class:
comment|///
comment|/// \code
comment|///     class SomeVisitor : public TypeVisitor<SomeVisitor,sometype> { ... };
comment|///     ...
comment|///     Type *atype = ...
comment|///     ...
comment|///     SomeVisitor avisitor;
comment|///     sometype result = avisitor.Visit(atype);
comment|/// \endcode
comment|///
comment|/// Actual treatment is made by methods of the derived class, TypeVisitor only
comment|/// dispatches call to the appropriate method. If the implementation class
comment|/// \c ImplClass provides specific action for some type, say
comment|/// \c ConstantArrayType, it should define method
comment|///<tt>VisitConstantArrayType(const ConstantArrayType*)</tt>. Otherwise
comment|/// \c TypeVisitor dispatches call to the method that handles parent type. In
comment|/// this example handlers are tried in the sequence:
comment|///
comment|/// \li<tt>ImplClass::VisitConstantArrayType(const ConstantArrayType*)</tt>
comment|/// \li<tt>ImplClass::VisitArrayType(const ArrayType*)</tt>
comment|/// \li<tt>ImplClass::VisitType(const Type*)</tt>
comment|/// \li<tt>TypeVisitor::VisitType(const Type*)</tt>
comment|///
comment|/// The first function of this sequence that is defined will handle object of
comment|/// type \c ConstantArrayType.
name|template
operator|<
name|typename
name|ImplClass
operator|,
name|typename
name|RetTy
operator|=
name|void
operator|>
name|class
name|TypeVisitor
block|{
name|public
operator|:
comment|/// \brief Performs the operation associated with this visitor object.
name|RetTy
name|Visit
argument_list|(
argument|const Type *T
argument_list|)
block|{
comment|// Top switch stmt: dispatch to VisitFooType for each FooType.
switch|switch
condition|(
name|T
operator|->
name|getTypeClass
argument_list|()
condition|)
block|{
define|#
directive|define
name|ABSTRACT_TYPE
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
define|#
directive|define
name|TYPE
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
value|case Type::CLASS: DISPATCH(CLASS##Type);
include|#
directive|include
file|"clang/AST/TypeNodes.def"
block|}
name|llvm_unreachable
argument_list|(
literal|"Unknown type class!"
argument_list|)
expr_stmt|;
block|}
comment|// If the implementation chooses not to implement a certain visit method, fall
comment|// back on superclass.
define|#
directive|define
name|TYPE
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
value|RetTy Visit##CLASS##Type(const CLASS##Type *T) { \   DISPATCH(PARENT);                                                          \ }
include|#
directive|include
file|"clang/AST/TypeNodes.def"
comment|/// \brief Method called if \c ImpClass doesn't provide specific handler
comment|/// for some type class.
name|RetTy
name|VisitType
argument_list|(
argument|const Type*
argument_list|)
block|{
return|return
name|RetTy
argument_list|()
return|;
block|}
expr|}
block|;
undef|#
directive|undef
name|DISPATCH
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

