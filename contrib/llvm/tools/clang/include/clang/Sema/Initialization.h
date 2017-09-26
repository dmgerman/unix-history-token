begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Initialization.h - Semantic Analysis for Initializers --*- C++ -*-===//
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
comment|// This file provides supporting data types for initialization of objects.
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
name|LLVM_CLANG_SEMA_INITIALIZATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_INITIALIZATION_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Attr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/UnresolvedSet.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Overload.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Ownership.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
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
name|CXXBaseSpecifier
decl_stmt|;
name|class
name|DeclaratorDecl
decl_stmt|;
name|class
name|DeclaratorInfo
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|ParmVarDecl
decl_stmt|;
name|class
name|Sema
decl_stmt|;
name|class
name|TypeLoc
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
comment|/// \brief Describes an entity that is being initialized.
name|class
name|InitializedEntity
block|{
name|public
label|:
comment|/// \brief Specifies the kind of entity being initialized.
enum|enum
name|EntityKind
block|{
comment|/// \brief The entity being initialized is a variable.
name|EK_Variable
block|,
comment|/// \brief The entity being initialized is a function parameter.
name|EK_Parameter
block|,
comment|/// \brief The entity being initialized is the result of a function call.
name|EK_Result
block|,
comment|/// \brief The entity being initialized is an exception object that
comment|/// is being thrown.
name|EK_Exception
block|,
comment|/// \brief The entity being initialized is a non-static data member
comment|/// subobject.
name|EK_Member
block|,
comment|/// \brief The entity being initialized is an element of an array.
name|EK_ArrayElement
block|,
comment|/// \brief The entity being initialized is an object (or array of
comment|/// objects) allocated via new.
name|EK_New
block|,
comment|/// \brief The entity being initialized is a temporary object.
name|EK_Temporary
block|,
comment|/// \brief The entity being initialized is a base member subobject.
name|EK_Base
block|,
comment|/// \brief The initialization is being done by a delegating constructor.
name|EK_Delegating
block|,
comment|/// \brief The entity being initialized is an element of a vector.
comment|/// or vector.
name|EK_VectorElement
block|,
comment|/// \brief The entity being initialized is a field of block descriptor for
comment|/// the copied-in c++ object.
name|EK_BlockElement
block|,
comment|/// The entity being initialized is a field of block descriptor for the
comment|/// copied-in lambda object that's used in the lambda to block conversion.
name|EK_LambdaToBlockConversionBlockElement
block|,
comment|/// \brief The entity being initialized is the real or imaginary part of a
comment|/// complex number.
name|EK_ComplexElement
block|,
comment|/// \brief The entity being initialized is the field that captures a
comment|/// variable in a lambda.
name|EK_LambdaCapture
block|,
comment|/// \brief The entity being initialized is the initializer for a compound
comment|/// literal.
name|EK_CompoundLiteralInit
block|,
comment|/// \brief The entity being implicitly initialized back to the formal
comment|/// result type.
name|EK_RelatedResult
block|,
comment|/// \brief The entity being initialized is a function parameter; function
comment|/// is member of group of audited CF APIs.
name|EK_Parameter_CF_Audited
block|,
comment|/// \brief The entity being initialized is a structured binding of a
comment|/// decomposition declaration.
name|EK_Binding
block|,
comment|// Note: err_init_conversion_failed in DiagnosticSemaKinds.td uses this
comment|// enum as an index for its first %select.  When modifying this list,
comment|// that diagnostic text needs to be updated as well.
block|}
enum|;
name|private
label|:
comment|/// \brief The kind of entity being initialized.
name|EntityKind
name|Kind
decl_stmt|;
comment|/// \brief If non-NULL, the parent entity in which this
comment|/// initialization occurs.
specifier|const
name|InitializedEntity
modifier|*
name|Parent
decl_stmt|;
comment|/// \brief The type of the object or reference being initialized.
name|QualType
name|Type
decl_stmt|;
comment|/// \brief The mangling number for the next reference temporary to be created.
name|mutable
name|unsigned
name|ManglingNumber
decl_stmt|;
struct|struct
name|LN
block|{
comment|/// \brief When Kind == EK_Result, EK_Exception, EK_New, the
comment|/// location of the 'return', 'throw', or 'new' keyword,
comment|/// respectively. When Kind == EK_Temporary, the location where
comment|/// the temporary is being created.
name|unsigned
name|Location
decl_stmt|;
comment|/// \brief Whether the entity being initialized may end up using the
comment|/// named return value optimization (NRVO).
name|bool
name|NRVO
decl_stmt|;
block|}
struct|;
struct|struct
name|VD
block|{
comment|/// \brief The VarDecl, FieldDecl, or BindingDecl being initialized.
name|ValueDecl
modifier|*
name|VariableOrMember
decl_stmt|;
comment|/// \brief When Kind == EK_Member, whether this is an implicit member
comment|/// initialization in a copy or move constructor. These can perform array
comment|/// copies.
name|bool
name|IsImplicitFieldInit
decl_stmt|;
block|}
struct|;
struct|struct
name|C
block|{
comment|/// \brief The name of the variable being captured by an EK_LambdaCapture.
name|IdentifierInfo
modifier|*
name|VarID
decl_stmt|;
comment|/// \brief The source location at which the capture occurs.
name|unsigned
name|Location
decl_stmt|;
block|}
struct|;
union|union
block|{
comment|/// \brief When Kind == EK_Variable, EK_Member or EK_Binding, the variable.
name|VD
name|Variable
decl_stmt|;
comment|/// \brief When Kind == EK_RelatedResult, the ObjectiveC method where
comment|/// result type was implicitly changed to accommodate ARC semantics.
name|ObjCMethodDecl
modifier|*
name|MethodDecl
decl_stmt|;
comment|/// \brief When Kind == EK_Parameter, the ParmVarDecl, with the
comment|/// low bit indicating whether the parameter is "consumed".
name|uintptr_t
name|Parameter
decl_stmt|;
comment|/// \brief When Kind == EK_Temporary or EK_CompoundLiteralInit, the type
comment|/// source information for the temporary.
name|TypeSourceInfo
modifier|*
name|TypeInfo
decl_stmt|;
name|struct
name|LN
name|LocAndNRVO
decl_stmt|;
comment|/// \brief When Kind == EK_Base, the base specifier that provides the
comment|/// base class. The lower bit specifies whether the base is an inherited
comment|/// virtual base.
name|uintptr_t
name|Base
decl_stmt|;
comment|/// \brief When Kind == EK_ArrayElement, EK_VectorElement, or
comment|/// EK_ComplexElement, the index of the array or vector element being
comment|/// initialized.
name|unsigned
name|Index
decl_stmt|;
name|struct
name|C
name|Capture
decl_stmt|;
block|}
union|;
name|InitializedEntity
argument_list|()
operator|:
name|ManglingNumber
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// \brief Create the initialization entity for a variable.
name|InitializedEntity
argument_list|(
argument|VarDecl *Var
argument_list|,
argument|EntityKind EK = EK_Variable
argument_list|)
operator|:
name|Kind
argument_list|(
name|EK
argument_list|)
operator|,
name|Parent
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Type
argument_list|(
name|Var
operator|->
name|getType
argument_list|()
argument_list|)
operator|,
name|ManglingNumber
argument_list|(
literal|0
argument_list|)
operator|,
name|Variable
block|{
name|Var
block|,
name|false
block|}
block|{ }
comment|/// \brief Create the initialization entity for the result of a
comment|/// function, throwing an object, performing an explicit cast, or
comment|/// initializing a parameter for which there is no declaration.
name|InitializedEntity
argument_list|(
argument|EntityKind Kind
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|QualType Type
argument_list|,
argument|bool NRVO = false
argument_list|)
operator|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|Parent
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Type
argument_list|(
name|Type
argument_list|)
operator|,
name|ManglingNumber
argument_list|(
literal|0
argument_list|)
block|{
name|LocAndNRVO
operator|.
name|Location
operator|=
name|Loc
operator|.
name|getRawEncoding
argument_list|()
block|;
name|LocAndNRVO
operator|.
name|NRVO
operator|=
name|NRVO
block|;   }
comment|/// \brief Create the initialization entity for a member subobject.
name|InitializedEntity
argument_list|(
argument|FieldDecl *Member
argument_list|,
argument|const InitializedEntity *Parent
argument_list|,
argument|bool Implicit
argument_list|)
operator|:
name|Kind
argument_list|(
name|EK_Member
argument_list|)
operator|,
name|Parent
argument_list|(
name|Parent
argument_list|)
operator|,
name|Type
argument_list|(
name|Member
operator|->
name|getType
argument_list|()
argument_list|)
operator|,
name|ManglingNumber
argument_list|(
literal|0
argument_list|)
operator|,
name|Variable
block|{
name|Member
block|,
name|Implicit
block|}
block|{   }
comment|/// \brief Create the initialization entity for an array element.
name|InitializedEntity
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|unsigned Index
argument_list|,
argument|const InitializedEntity&Parent
argument_list|)
expr_stmt|;
comment|/// \brief Create the initialization entity for a lambda capture.
name|InitializedEntity
argument_list|(
argument|IdentifierInfo *VarID
argument_list|,
argument|QualType FieldType
argument_list|,
argument|SourceLocation Loc
argument_list|)
block|:
name|Kind
argument_list|(
name|EK_LambdaCapture
argument_list|)
operator|,
name|Parent
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Type
argument_list|(
name|FieldType
argument_list|)
operator|,
name|ManglingNumber
argument_list|(
literal|0
argument_list|)
block|{
name|Capture
operator|.
name|VarID
operator|=
name|VarID
block|;
name|Capture
operator|.
name|Location
operator|=
name|Loc
operator|.
name|getRawEncoding
argument_list|()
block|;   }
name|public
operator|:
comment|/// \brief Create the initialization entity for a variable.
specifier|static
name|InitializedEntity
name|InitializeVariable
argument_list|(
argument|VarDecl *Var
argument_list|)
block|{
return|return
name|InitializedEntity
argument_list|(
name|Var
argument_list|)
return|;
block|}
comment|/// \brief Create the initialization entity for a parameter.
specifier|static
name|InitializedEntity
name|InitializeParameter
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
specifier|const
name|ParmVarDecl
modifier|*
name|Parm
parameter_list|)
block|{
return|return
name|InitializeParameter
argument_list|(
name|Context
argument_list|,
name|Parm
argument_list|,
name|Parm
operator|->
name|getType
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Create the initialization entity for a parameter, but use
comment|/// another type.
specifier|static
name|InitializedEntity
name|InitializeParameter
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
specifier|const
name|ParmVarDecl
modifier|*
name|Parm
parameter_list|,
name|QualType
name|Type
parameter_list|)
block|{
name|bool
name|Consumed
init|=
operator|(
name|Context
operator|.
name|getLangOpts
argument_list|()
operator|.
name|ObjCAutoRefCount
operator|&&
name|Parm
operator|->
name|hasAttr
operator|<
name|NSConsumedAttr
operator|>
operator|(
operator|)
operator|)
decl_stmt|;
name|InitializedEntity
name|Entity
decl_stmt|;
name|Entity
operator|.
name|Kind
operator|=
name|EK_Parameter
expr_stmt|;
name|Entity
operator|.
name|Type
operator|=
name|Context
operator|.
name|getVariableArrayDecayedType
argument_list|(
name|Type
operator|.
name|getUnqualifiedType
argument_list|()
argument_list|)
expr_stmt|;
name|Entity
operator|.
name|Parent
operator|=
name|nullptr
expr_stmt|;
name|Entity
operator|.
name|Parameter
operator|=
operator|(
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Consumed
operator|)
operator||
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Parm
operator|)
operator|)
expr_stmt|;
return|return
name|Entity
return|;
block|}
comment|/// \brief Create the initialization entity for a parameter that is
comment|/// only known by its type.
specifier|static
name|InitializedEntity
name|InitializeParameter
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|QualType
name|Type
parameter_list|,
name|bool
name|Consumed
parameter_list|)
block|{
name|InitializedEntity
name|Entity
decl_stmt|;
name|Entity
operator|.
name|Kind
operator|=
name|EK_Parameter
expr_stmt|;
name|Entity
operator|.
name|Type
operator|=
name|Context
operator|.
name|getVariableArrayDecayedType
argument_list|(
name|Type
argument_list|)
expr_stmt|;
name|Entity
operator|.
name|Parent
operator|=
name|nullptr
expr_stmt|;
name|Entity
operator|.
name|Parameter
operator|=
operator|(
name|Consumed
operator|)
expr_stmt|;
return|return
name|Entity
return|;
block|}
comment|/// \brief Create the initialization entity for the result of a function.
specifier|static
name|InitializedEntity
name|InitializeResult
parameter_list|(
name|SourceLocation
name|ReturnLoc
parameter_list|,
name|QualType
name|Type
parameter_list|,
name|bool
name|NRVO
parameter_list|)
block|{
return|return
name|InitializedEntity
argument_list|(
name|EK_Result
argument_list|,
name|ReturnLoc
argument_list|,
name|Type
argument_list|,
name|NRVO
argument_list|)
return|;
block|}
specifier|static
name|InitializedEntity
name|InitializeBlock
parameter_list|(
name|SourceLocation
name|BlockVarLoc
parameter_list|,
name|QualType
name|Type
parameter_list|,
name|bool
name|NRVO
parameter_list|)
block|{
return|return
name|InitializedEntity
argument_list|(
name|EK_BlockElement
argument_list|,
name|BlockVarLoc
argument_list|,
name|Type
argument_list|,
name|NRVO
argument_list|)
return|;
block|}
specifier|static
name|InitializedEntity
name|InitializeLambdaToBlock
parameter_list|(
name|SourceLocation
name|BlockVarLoc
parameter_list|,
name|QualType
name|Type
parameter_list|,
name|bool
name|NRVO
parameter_list|)
block|{
return|return
name|InitializedEntity
argument_list|(
name|EK_LambdaToBlockConversionBlockElement
argument_list|,
name|BlockVarLoc
argument_list|,
name|Type
argument_list|,
name|NRVO
argument_list|)
return|;
block|}
comment|/// \brief Create the initialization entity for an exception object.
specifier|static
name|InitializedEntity
name|InitializeException
parameter_list|(
name|SourceLocation
name|ThrowLoc
parameter_list|,
name|QualType
name|Type
parameter_list|,
name|bool
name|NRVO
parameter_list|)
block|{
return|return
name|InitializedEntity
argument_list|(
name|EK_Exception
argument_list|,
name|ThrowLoc
argument_list|,
name|Type
argument_list|,
name|NRVO
argument_list|)
return|;
block|}
comment|/// \brief Create the initialization entity for an object allocated via new.
specifier|static
name|InitializedEntity
name|InitializeNew
parameter_list|(
name|SourceLocation
name|NewLoc
parameter_list|,
name|QualType
name|Type
parameter_list|)
block|{
return|return
name|InitializedEntity
argument_list|(
name|EK_New
argument_list|,
name|NewLoc
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// \brief Create the initialization entity for a temporary.
specifier|static
name|InitializedEntity
name|InitializeTemporary
parameter_list|(
name|QualType
name|Type
parameter_list|)
block|{
return|return
name|InitializeTemporary
argument_list|(
name|nullptr
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// \brief Create the initialization entity for a temporary.
specifier|static
name|InitializedEntity
name|InitializeTemporary
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TypeInfo
parameter_list|)
block|{
return|return
name|InitializeTemporary
argument_list|(
name|TypeInfo
argument_list|,
name|TypeInfo
operator|->
name|getType
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Create the initialization entity for a temporary.
specifier|static
name|InitializedEntity
name|InitializeTemporary
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TypeInfo
parameter_list|,
name|QualType
name|Type
parameter_list|)
block|{
name|InitializedEntity
name|Result
argument_list|(
name|EK_Temporary
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|Type
argument_list|)
decl_stmt|;
name|Result
operator|.
name|TypeInfo
operator|=
name|TypeInfo
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|/// \brief Create the initialization entity for a related result.
specifier|static
name|InitializedEntity
name|InitializeRelatedResult
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|MD
parameter_list|,
name|QualType
name|Type
parameter_list|)
block|{
name|InitializedEntity
name|Result
argument_list|(
name|EK_RelatedResult
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|Type
argument_list|)
decl_stmt|;
name|Result
operator|.
name|MethodDecl
operator|=
name|MD
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|/// \brief Create the initialization entity for a base class subobject.
specifier|static
name|InitializedEntity
name|InitializeBase
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
specifier|const
name|CXXBaseSpecifier
modifier|*
name|Base
parameter_list|,
name|bool
name|IsInheritedVirtualBase
parameter_list|,
specifier|const
name|InitializedEntity
modifier|*
name|Parent
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Create the initialization entity for a delegated constructor.
specifier|static
name|InitializedEntity
name|InitializeDelegation
parameter_list|(
name|QualType
name|Type
parameter_list|)
block|{
return|return
name|InitializedEntity
argument_list|(
name|EK_Delegating
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|Type
argument_list|)
return|;
block|}
comment|/// \brief Create the initialization entity for a member subobject.
specifier|static
name|InitializedEntity
name|InitializeMember
parameter_list|(
name|FieldDecl
modifier|*
name|Member
parameter_list|,
specifier|const
name|InitializedEntity
modifier|*
name|Parent
init|=
name|nullptr
parameter_list|,
name|bool
name|Implicit
init|=
name|false
parameter_list|)
block|{
return|return
name|InitializedEntity
argument_list|(
name|Member
argument_list|,
name|Parent
argument_list|,
name|Implicit
argument_list|)
return|;
block|}
comment|/// \brief Create the initialization entity for a member subobject.
specifier|static
name|InitializedEntity
name|InitializeMember
parameter_list|(
name|IndirectFieldDecl
modifier|*
name|Member
parameter_list|,
specifier|const
name|InitializedEntity
modifier|*
name|Parent
init|=
name|nullptr
parameter_list|,
name|bool
name|Implicit
init|=
name|false
parameter_list|)
block|{
return|return
name|InitializedEntity
argument_list|(
name|Member
operator|->
name|getAnonField
argument_list|()
argument_list|,
name|Parent
argument_list|,
name|Implicit
argument_list|)
return|;
block|}
comment|/// \brief Create the initialization entity for an array element.
specifier|static
name|InitializedEntity
name|InitializeElement
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|unsigned
name|Index
parameter_list|,
specifier|const
name|InitializedEntity
modifier|&
name|Parent
parameter_list|)
block|{
return|return
name|InitializedEntity
argument_list|(
name|Context
argument_list|,
name|Index
argument_list|,
name|Parent
argument_list|)
return|;
block|}
comment|/// \brief Create the initialization entity for a structured binding.
specifier|static
name|InitializedEntity
name|InitializeBinding
parameter_list|(
name|VarDecl
modifier|*
name|Binding
parameter_list|)
block|{
return|return
name|InitializedEntity
argument_list|(
name|Binding
argument_list|,
name|EK_Binding
argument_list|)
return|;
block|}
comment|/// \brief Create the initialization entity for a lambda capture.
specifier|static
name|InitializedEntity
name|InitializeLambdaCapture
parameter_list|(
name|IdentifierInfo
modifier|*
name|VarID
parameter_list|,
name|QualType
name|FieldType
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
block|{
return|return
name|InitializedEntity
argument_list|(
name|VarID
argument_list|,
name|FieldType
argument_list|,
name|Loc
argument_list|)
return|;
block|}
comment|/// \brief Create the entity for a compound literal initializer.
specifier|static
name|InitializedEntity
name|InitializeCompoundLiteralInit
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TSI
parameter_list|)
block|{
name|InitializedEntity
name|Result
argument_list|(
name|EK_CompoundLiteralInit
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|TSI
operator|->
name|getType
argument_list|()
argument_list|)
decl_stmt|;
name|Result
operator|.
name|TypeInfo
operator|=
name|TSI
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|/// \brief Determine the kind of initialization.
name|EntityKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// \brief Retrieve the parent of the entity being initialized, when
comment|/// the initialization itself is occurring within the context of a
comment|/// larger initialization.
specifier|const
name|InitializedEntity
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|Parent
return|;
block|}
comment|/// \brief Retrieve type being initialized.
name|QualType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
comment|/// \brief Retrieve complete type-source information for the object being
comment|/// constructed, if known.
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Kind
operator|==
name|EK_Temporary
operator|||
name|Kind
operator|==
name|EK_CompoundLiteralInit
condition|)
return|return
name|TypeInfo
return|;
return|return
name|nullptr
return|;
block|}
comment|/// \brief Retrieve the name of the entity being initialized.
name|DeclarationName
name|getName
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the variable, parameter, or field being
comment|/// initialized.
name|ValueDecl
operator|*
name|getDecl
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the ObjectiveC method being initialized.
name|ObjCMethodDecl
operator|*
name|getMethodDecl
argument_list|()
specifier|const
block|{
return|return
name|MethodDecl
return|;
block|}
comment|/// \brief Determine whether this initialization allows the named return
comment|/// value optimization, which also applies to thrown objects.
name|bool
name|allowsNRVO
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isParameterKind
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getKind
argument_list|()
operator|==
name|EK_Parameter
operator|||
name|getKind
argument_list|()
operator|==
name|EK_Parameter_CF_Audited
operator|)
return|;
block|}
comment|/// \brief Determine whether this initialization consumes the
comment|/// parameter.
name|bool
name|isParameterConsumed
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isParameterKind
argument_list|()
operator|&&
literal|"Not a parameter"
argument_list|)
block|;
return|return
operator|(
name|Parameter
operator|&
literal|1
operator|)
return|;
block|}
comment|/// \brief Retrieve the base specifier.
specifier|const
name|CXXBaseSpecifier
operator|*
name|getBaseSpecifier
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|EK_Base
operator|&&
literal|"Not a base specifier"
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
specifier|const
name|CXXBaseSpecifier
operator|*
operator|>
operator|(
name|Base
operator|&
operator|~
literal|0x1
operator|)
return|;
block|}
comment|/// \brief Return whether the base is an inherited virtual base.
name|bool
name|isInheritedVirtualBase
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|EK_Base
operator|&&
literal|"Not a base specifier"
argument_list|)
block|;
return|return
name|Base
operator|&
literal|0x1
return|;
block|}
comment|/// \brief Determine whether this is an array new with an unknown bound.
name|bool
name|isVariableLengthArrayNew
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|EK_New
operator|&&
name|dyn_cast_or_null
operator|<
name|IncompleteArrayType
operator|>
operator|(
name|getType
argument_list|()
operator|->
name|getAsArrayTypeUnsafe
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Is this the implicit initialization of a member of a class from
comment|/// a defaulted constructor?
name|bool
name|isImplicitMemberInitializer
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|EK_Member
operator|&&
name|Variable
operator|.
name|IsImplicitFieldInit
return|;
block|}
comment|/// \brief Determine the location of the 'return' keyword when initializing
comment|/// the result of a function call.
name|SourceLocation
name|getReturnLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|EK_Result
operator|&&
literal|"No 'return' location!"
argument_list|)
block|;
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|LocAndNRVO
operator|.
name|Location
argument_list|)
return|;
block|}
comment|/// \brief Determine the location of the 'throw' keyword when initializing
comment|/// an exception object.
name|SourceLocation
name|getThrowLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|EK_Exception
operator|&&
literal|"No 'throw' location!"
argument_list|)
block|;
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|LocAndNRVO
operator|.
name|Location
argument_list|)
return|;
block|}
comment|/// \brief If this is an array, vector, or complex number element, get the
comment|/// element's index.
name|unsigned
name|getElementIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|EK_ArrayElement
operator|||
name|getKind
argument_list|()
operator|==
name|EK_VectorElement
operator|||
name|getKind
argument_list|()
operator|==
name|EK_ComplexElement
argument_list|)
block|;
return|return
name|Index
return|;
block|}
comment|/// \brief If this is already the initializer for an array or vector
comment|/// element, sets the element index.
name|void
name|setElementIndex
parameter_list|(
name|unsigned
name|Index
parameter_list|)
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|EK_ArrayElement
operator|||
name|getKind
argument_list|()
operator|==
name|EK_VectorElement
operator|||
name|getKind
argument_list|()
operator|==
name|EK_ComplexElement
argument_list|)
expr_stmt|;
name|this
operator|->
name|Index
operator|=
name|Index
expr_stmt|;
block|}
comment|/// \brief For a lambda capture, return the capture's name.
name|StringRef
name|getCapturedVarName
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|EK_LambdaCapture
operator|&&
literal|"Not a lambda capture!"
argument_list|)
block|;
return|return
name|Capture
operator|.
name|VarID
operator|->
name|getName
argument_list|()
return|;
block|}
comment|/// \brief Determine the location of the capture when initializing
comment|/// field from a captured variable in a lambda.
name|SourceLocation
name|getCaptureLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|EK_LambdaCapture
operator|&&
literal|"Not a lambda capture!"
argument_list|)
block|;
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|Capture
operator|.
name|Location
argument_list|)
return|;
block|}
name|void
name|setParameterCFAudited
parameter_list|()
block|{
name|Kind
operator|=
name|EK_Parameter_CF_Audited
expr_stmt|;
block|}
name|unsigned
name|allocateManglingNumber
argument_list|()
specifier|const
block|{
return|return
operator|++
name|ManglingNumber
return|;
block|}
comment|/// Dump a representation of the initialized entity to standard error,
comment|/// for debugging purposes.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|unsigned
name|dumpImpl
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Describes the kind of initialization being performed, along with
end_comment

begin_comment
comment|/// location information for tokens related to the initialization (equal sign,
end_comment

begin_comment
comment|/// parentheses).
end_comment

begin_decl_stmt
name|class
name|InitializationKind
block|{
name|public
label|:
comment|/// \brief The kind of initialization being performed.
enum|enum
name|InitKind
block|{
name|IK_Direct
block|,
comment|///< Direct initialization
name|IK_DirectList
block|,
comment|///< Direct list-initialization
name|IK_Copy
block|,
comment|///< Copy initialization
name|IK_Default
block|,
comment|///< Default initialization
name|IK_Value
comment|///< Value initialization
block|}
enum|;
name|private
label|:
comment|/// \brief The context of the initialization.
enum|enum
name|InitContext
block|{
name|IC_Normal
block|,
comment|///< Normal context
name|IC_ExplicitConvs
block|,
comment|///< Normal context, but allows explicit conversion funcs
name|IC_Implicit
block|,
comment|///< Implicit context (value initialization)
name|IC_StaticCast
block|,
comment|///< Static cast context
name|IC_CStyleCast
block|,
comment|///< C-style cast context
name|IC_FunctionalCast
comment|///< Functional cast context
block|}
enum|;
comment|/// \brief The kind of initialization being performed.
name|InitKind
name|Kind
range|:
literal|8
decl_stmt|;
comment|/// \brief The context of the initialization.
name|InitContext
name|Context
range|:
literal|8
decl_stmt|;
comment|/// \brief The source locations involved in the initialization.
name|SourceLocation
name|Locations
index|[
literal|3
index|]
decl_stmt|;
name|InitializationKind
argument_list|(
argument|InitKind Kind
argument_list|,
argument|InitContext Context
argument_list|,
argument|SourceLocation Loc1
argument_list|,
argument|SourceLocation Loc2
argument_list|,
argument|SourceLocation Loc3
argument_list|)
block|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|Context
argument_list|(
argument|Context
argument_list|)
block|{
name|Locations
index|[
literal|0
index|]
operator|=
name|Loc1
block|;
name|Locations
index|[
literal|1
index|]
operator|=
name|Loc2
block|;
name|Locations
index|[
literal|2
index|]
operator|=
name|Loc3
block|;   }
name|public
operator|:
comment|/// \brief Create a direct initialization.
specifier|static
name|InitializationKind
name|CreateDirect
argument_list|(
argument|SourceLocation InitLoc
argument_list|,
argument|SourceLocation LParenLoc
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
block|{
return|return
name|InitializationKind
argument_list|(
name|IK_Direct
argument_list|,
name|IC_Normal
argument_list|,
name|InitLoc
argument_list|,
name|LParenLoc
argument_list|,
name|RParenLoc
argument_list|)
return|;
block|}
specifier|static
name|InitializationKind
name|CreateDirectList
parameter_list|(
name|SourceLocation
name|InitLoc
parameter_list|)
block|{
return|return
name|InitializationKind
argument_list|(
name|IK_DirectList
argument_list|,
name|IC_Normal
argument_list|,
name|InitLoc
argument_list|,
name|InitLoc
argument_list|,
name|InitLoc
argument_list|)
return|;
block|}
comment|/// \brief Create a direct initialization due to a cast that isn't a C-style
comment|/// or functional cast.
specifier|static
name|InitializationKind
name|CreateCast
parameter_list|(
name|SourceRange
name|TypeRange
parameter_list|)
block|{
return|return
name|InitializationKind
argument_list|(
name|IK_Direct
argument_list|,
name|IC_StaticCast
argument_list|,
name|TypeRange
operator|.
name|getBegin
argument_list|()
argument_list|,
name|TypeRange
operator|.
name|getBegin
argument_list|()
argument_list|,
name|TypeRange
operator|.
name|getEnd
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Create a direct initialization for a C-style cast.
specifier|static
name|InitializationKind
name|CreateCStyleCast
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceRange
name|TypeRange
parameter_list|,
name|bool
name|InitList
parameter_list|)
block|{
comment|// C++ cast syntax doesn't permit init lists, but C compound literals are
comment|// exactly that.
return|return
name|InitializationKind
argument_list|(
name|InitList
condition|?
name|IK_DirectList
else|:
name|IK_Direct
argument_list|,
name|IC_CStyleCast
argument_list|,
name|StartLoc
argument_list|,
name|TypeRange
operator|.
name|getBegin
argument_list|()
argument_list|,
name|TypeRange
operator|.
name|getEnd
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Create a direct initialization for a functional cast.
specifier|static
name|InitializationKind
name|CreateFunctionalCast
parameter_list|(
name|SourceRange
name|TypeRange
parameter_list|,
name|bool
name|InitList
parameter_list|)
block|{
return|return
name|InitializationKind
argument_list|(
name|InitList
condition|?
name|IK_DirectList
else|:
name|IK_Direct
argument_list|,
name|IC_FunctionalCast
argument_list|,
name|TypeRange
operator|.
name|getBegin
argument_list|()
argument_list|,
name|TypeRange
operator|.
name|getBegin
argument_list|()
argument_list|,
name|TypeRange
operator|.
name|getEnd
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Create a copy initialization.
specifier|static
name|InitializationKind
name|CreateCopy
parameter_list|(
name|SourceLocation
name|InitLoc
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|bool
name|AllowExplicitConvs
init|=
name|false
parameter_list|)
block|{
return|return
name|InitializationKind
argument_list|(
name|IK_Copy
argument_list|,
name|AllowExplicitConvs
condition|?
name|IC_ExplicitConvs
else|:
name|IC_Normal
argument_list|,
name|InitLoc
argument_list|,
name|EqualLoc
argument_list|,
name|EqualLoc
argument_list|)
return|;
block|}
comment|/// \brief Create a default initialization.
specifier|static
name|InitializationKind
name|CreateDefault
parameter_list|(
name|SourceLocation
name|InitLoc
parameter_list|)
block|{
return|return
name|InitializationKind
argument_list|(
name|IK_Default
argument_list|,
name|IC_Normal
argument_list|,
name|InitLoc
argument_list|,
name|InitLoc
argument_list|,
name|InitLoc
argument_list|)
return|;
block|}
comment|/// \brief Create a value initialization.
specifier|static
name|InitializationKind
name|CreateValue
parameter_list|(
name|SourceLocation
name|InitLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|bool
name|isImplicit
init|=
name|false
parameter_list|)
block|{
return|return
name|InitializationKind
argument_list|(
name|IK_Value
argument_list|,
name|isImplicit
condition|?
name|IC_Implicit
else|:
name|IC_Normal
argument_list|,
name|InitLoc
argument_list|,
name|LParenLoc
argument_list|,
name|RParenLoc
argument_list|)
return|;
block|}
comment|/// \brief Create an initialization from an initializer (which, for direct
comment|/// initialization from a parenthesized list, will be a ParenListExpr).
specifier|static
name|InitializationKind
name|CreateForInit
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|DirectInit
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|)
block|{
if|if
condition|(
operator|!
name|Init
condition|)
return|return
name|CreateDefault
argument_list|(
name|Loc
argument_list|)
return|;
if|if
condition|(
operator|!
name|DirectInit
condition|)
return|return
name|CreateCopy
argument_list|(
name|Loc
argument_list|,
name|Init
operator|->
name|getLocStart
argument_list|()
argument_list|)
return|;
if|if
condition|(
name|isa
operator|<
name|InitListExpr
operator|>
operator|(
name|Init
operator|)
condition|)
return|return
name|CreateDirectList
argument_list|(
name|Loc
argument_list|)
return|;
return|return
name|CreateDirect
argument_list|(
name|Loc
argument_list|,
name|Init
operator|->
name|getLocStart
argument_list|()
argument_list|,
name|Init
operator|->
name|getLocEnd
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Determine the initialization kind.
name|InitKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// \brief Determine whether this initialization is an explicit cast.
name|bool
name|isExplicitCast
argument_list|()
specifier|const
block|{
return|return
name|Context
operator|>=
name|IC_StaticCast
return|;
block|}
comment|/// \brief Determine whether this initialization is a C-style cast.
name|bool
name|isCStyleOrFunctionalCast
argument_list|()
specifier|const
block|{
return|return
name|Context
operator|>=
name|IC_CStyleCast
return|;
block|}
comment|/// \brief Determine whether this is a C-style cast.
name|bool
name|isCStyleCast
argument_list|()
specifier|const
block|{
return|return
name|Context
operator|==
name|IC_CStyleCast
return|;
block|}
comment|/// \brief Determine whether this is a functional-style cast.
name|bool
name|isFunctionalCast
argument_list|()
specifier|const
block|{
return|return
name|Context
operator|==
name|IC_FunctionalCast
return|;
block|}
comment|/// \brief Determine whether this initialization is an implicit
comment|/// value-initialization, e.g., as occurs during aggregate
comment|/// initialization.
name|bool
name|isImplicitValueInit
argument_list|()
specifier|const
block|{
return|return
name|Context
operator|==
name|IC_Implicit
return|;
block|}
comment|/// \brief Retrieve the location at which initialization is occurring.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Locations
index|[
literal|0
index|]
return|;
block|}
comment|/// \brief Retrieve the source range that covers the initialization.
name|SourceRange
name|getRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|Locations
index|[
literal|0
index|]
argument_list|,
name|Locations
index|[
literal|2
index|]
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the location of the equal sign for copy initialization
comment|/// (if present).
name|SourceLocation
name|getEqualLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|IK_Copy
operator|&&
literal|"Only copy initialization has an '='"
argument_list|)
block|;
return|return
name|Locations
index|[
literal|1
index|]
return|;
block|}
name|bool
name|isCopyInit
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|IK_Copy
return|;
block|}
comment|/// \brief Retrieve whether this initialization allows the use of explicit
comment|///        constructors.
name|bool
name|AllowExplicit
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isCopyInit
argument_list|()
return|;
block|}
comment|/// \brief Retrieve whether this initialization allows the use of explicit
comment|/// conversion functions when binding a reference. If the reference is the
comment|/// first parameter in a copy or move constructor, such conversions are
comment|/// permitted even though we are performing copy-initialization.
name|bool
name|allowExplicitConversionFunctionsInRefBinding
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isCopyInit
argument_list|()
operator|||
name|Context
operator|==
name|IC_ExplicitConvs
return|;
block|}
comment|/// \brief Retrieve the source range containing the locations of the open
comment|/// and closing parentheses for value and direct initializations.
name|SourceRange
name|getParenRange
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|Kind
operator|==
name|IK_Direct
operator|||
name|Kind
operator|==
name|IK_Value
operator|)
operator|&&
literal|"Only direct- and value-initialization have parentheses"
argument_list|)
block|;
return|return
name|SourceRange
argument_list|(
name|Locations
index|[
literal|1
index|]
argument_list|,
name|Locations
index|[
literal|2
index|]
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Describes the sequence of initializations required to initialize
end_comment

begin_comment
comment|/// a given object or reference with a set of arguments.
end_comment

begin_decl_stmt
name|class
name|InitializationSequence
block|{
name|public
label|:
comment|/// \brief Describes the kind of initialization sequence computed.
enum|enum
name|SequenceKind
block|{
comment|/// \brief A failed initialization sequence. The failure kind tells what
comment|/// happened.
name|FailedSequence
init|=
literal|0
block|,
comment|/// \brief A dependent initialization, which could not be
comment|/// type-checked due to the presence of dependent types or
comment|/// dependently-typed expressions.
name|DependentSequence
block|,
comment|/// \brief A normal sequence.
name|NormalSequence
block|}
enum|;
comment|/// \brief Describes the kind of a particular step in an initialization
comment|/// sequence.
enum|enum
name|StepKind
block|{
comment|/// \brief Resolve the address of an overloaded function to a specific
comment|/// function declaration.
name|SK_ResolveAddressOfOverloadedFunction
block|,
comment|/// \brief Perform a derived-to-base cast, producing an rvalue.
name|SK_CastDerivedToBaseRValue
block|,
comment|/// \brief Perform a derived-to-base cast, producing an xvalue.
name|SK_CastDerivedToBaseXValue
block|,
comment|/// \brief Perform a derived-to-base cast, producing an lvalue.
name|SK_CastDerivedToBaseLValue
block|,
comment|/// \brief Reference binding to an lvalue.
name|SK_BindReference
block|,
comment|/// \brief Reference binding to a temporary.
name|SK_BindReferenceToTemporary
block|,
comment|/// \brief An optional copy of a temporary object to another
comment|/// temporary object, which is permitted (but not required) by
comment|/// C++98/03 but not C++0x.
name|SK_ExtraneousCopyToTemporary
block|,
comment|/// \brief Direct-initialization from a reference-related object in the
comment|/// final stage of class copy-initialization.
name|SK_FinalCopy
block|,
comment|/// \brief Perform a user-defined conversion, either via a conversion
comment|/// function or via a constructor.
name|SK_UserConversion
block|,
comment|/// \brief Perform a qualification conversion, producing an rvalue.
name|SK_QualificationConversionRValue
block|,
comment|/// \brief Perform a qualification conversion, producing an xvalue.
name|SK_QualificationConversionXValue
block|,
comment|/// \brief Perform a qualification conversion, producing an lvalue.
name|SK_QualificationConversionLValue
block|,
comment|/// \brief Perform a conversion adding _Atomic to a type.
name|SK_AtomicConversion
block|,
comment|/// \brief Perform a load from a glvalue, producing an rvalue.
name|SK_LValueToRValue
block|,
comment|/// \brief Perform an implicit conversion sequence.
name|SK_ConversionSequence
block|,
comment|/// \brief Perform an implicit conversion sequence without narrowing.
name|SK_ConversionSequenceNoNarrowing
block|,
comment|/// \brief Perform list-initialization without a constructor.
name|SK_ListInitialization
block|,
comment|/// \brief Unwrap the single-element initializer list for a reference.
name|SK_UnwrapInitList
block|,
comment|/// \brief Rewrap the single-element initializer list for a reference.
name|SK_RewrapInitList
block|,
comment|/// \brief Perform initialization via a constructor.
name|SK_ConstructorInitialization
block|,
comment|/// \brief Perform initialization via a constructor, taking arguments from
comment|/// a single InitListExpr.
name|SK_ConstructorInitializationFromList
block|,
comment|/// \brief Zero-initialize the object
name|SK_ZeroInitialization
block|,
comment|/// \brief C assignment
name|SK_CAssignment
block|,
comment|/// \brief Initialization by string
name|SK_StringInit
block|,
comment|/// \brief An initialization that "converts" an Objective-C object
comment|/// (not a point to an object) to another Objective-C object type.
name|SK_ObjCObjectConversion
block|,
comment|/// \brief Array indexing for initialization by elementwise copy.
name|SK_ArrayLoopIndex
block|,
comment|/// \brief Array initialization by elementwise copy.
name|SK_ArrayLoopInit
block|,
comment|/// \brief Array initialization (from an array rvalue).
name|SK_ArrayInit
block|,
comment|/// \brief Array initialization (from an array rvalue) as a GNU extension.
name|SK_GNUArrayInit
block|,
comment|/// \brief Array initialization from a parenthesized initializer list.
comment|/// This is a GNU C++ extension.
name|SK_ParenthesizedArrayInit
block|,
comment|/// \brief Pass an object by indirect copy-and-restore.
name|SK_PassByIndirectCopyRestore
block|,
comment|/// \brief Pass an object by indirect restore.
name|SK_PassByIndirectRestore
block|,
comment|/// \brief Produce an Objective-C object pointer.
name|SK_ProduceObjCObject
block|,
comment|/// \brief Construct a std::initializer_list from an initializer list.
name|SK_StdInitializerList
block|,
comment|/// \brief Perform initialization via a constructor taking a single
comment|/// std::initializer_list argument.
name|SK_StdInitializerListConstructorCall
block|,
comment|/// \brief Initialize an OpenCL sampler from an integer.
name|SK_OCLSamplerInit
block|,
comment|/// \brief Initialize queue_t from 0.
name|SK_OCLZeroQueue
block|,
comment|/// \brief Passing zero to a function where OpenCL event_t is expected.
name|SK_OCLZeroEvent
block|}
enum|;
comment|/// \brief A single step in the initialization sequence.
name|class
name|Step
block|{
name|public
label|:
comment|/// \brief The kind of conversion or initialization step we are taking.
name|StepKind
name|Kind
decl_stmt|;
comment|// \brief The type that results from this initialization.
name|QualType
name|Type
decl_stmt|;
struct|struct
name|F
block|{
name|bool
name|HadMultipleCandidates
decl_stmt|;
name|FunctionDecl
modifier|*
name|Function
decl_stmt|;
name|DeclAccessPair
name|FoundDecl
decl_stmt|;
block|}
struct|;
union|union
block|{
comment|/// \brief When Kind == SK_ResolvedOverloadedFunction or Kind ==
comment|/// SK_UserConversion, the function that the expression should be
comment|/// resolved to or the conversion function to call, respectively.
comment|/// When Kind == SK_ConstructorInitialization or SK_ListConstruction,
comment|/// the constructor to be called.
comment|///
comment|/// Always a FunctionDecl, plus a Boolean flag telling if it was
comment|/// selected from an overloaded set having size greater than 1.
comment|/// For conversion decls, the naming class is the source type.
comment|/// For construct decls, the naming class is the target type.
name|struct
name|F
name|Function
decl_stmt|;
comment|/// \brief When Kind = SK_ConversionSequence, the implicit conversion
comment|/// sequence.
name|ImplicitConversionSequence
modifier|*
name|ICS
decl_stmt|;
comment|/// \brief When Kind = SK_RewrapInitList, the syntactic form of the
comment|/// wrapping list.
name|InitListExpr
modifier|*
name|WrappingSyntacticList
decl_stmt|;
block|}
union|;
name|void
name|Destroy
parameter_list|()
function_decl|;
block|}
empty_stmt|;
name|private
label|:
comment|/// \brief The kind of initialization sequence computed.
name|enum
name|SequenceKind
name|SequenceKind
decl_stmt|;
comment|/// \brief Steps taken by this initialization.
name|SmallVector
operator|<
name|Step
operator|,
literal|4
operator|>
name|Steps
expr_stmt|;
name|public
label|:
comment|/// \brief Describes why initialization failed.
enum|enum
name|FailureKind
block|{
comment|/// \brief Too many initializers provided for a reference.
name|FK_TooManyInitsForReference
block|,
comment|/// \brief Reference initialized from a parenthesized initializer list.
name|FK_ParenthesizedListInitForReference
block|,
comment|/// \brief Array must be initialized with an initializer list.
name|FK_ArrayNeedsInitList
block|,
comment|/// \brief Array must be initialized with an initializer list or a
comment|/// string literal.
name|FK_ArrayNeedsInitListOrStringLiteral
block|,
comment|/// \brief Array must be initialized with an initializer list or a
comment|/// wide string literal.
name|FK_ArrayNeedsInitListOrWideStringLiteral
block|,
comment|/// \brief Initializing a wide char array with narrow string literal.
name|FK_NarrowStringIntoWideCharArray
block|,
comment|/// \brief Initializing char array with wide string literal.
name|FK_WideStringIntoCharArray
block|,
comment|/// \brief Initializing wide char array with incompatible wide string
comment|/// literal.
name|FK_IncompatWideStringIntoWideChar
block|,
comment|/// \brief Array type mismatch.
name|FK_ArrayTypeMismatch
block|,
comment|/// \brief Non-constant array initializer
name|FK_NonConstantArrayInit
block|,
comment|/// \brief Cannot resolve the address of an overloaded function.
name|FK_AddressOfOverloadFailed
block|,
comment|/// \brief Overloading due to reference initialization failed.
name|FK_ReferenceInitOverloadFailed
block|,
comment|/// \brief Non-const lvalue reference binding to a temporary.
name|FK_NonConstLValueReferenceBindingToTemporary
block|,
comment|/// \brief Non-const lvalue reference binding to a bit-field.
name|FK_NonConstLValueReferenceBindingToBitfield
block|,
comment|/// \brief Non-const lvalue reference binding to a vector element.
name|FK_NonConstLValueReferenceBindingToVectorElement
block|,
comment|/// \brief Non-const lvalue reference binding to an lvalue of unrelated
comment|/// type.
name|FK_NonConstLValueReferenceBindingToUnrelated
block|,
comment|/// \brief Rvalue reference binding to an lvalue.
name|FK_RValueReferenceBindingToLValue
block|,
comment|/// \brief Reference binding drops qualifiers.
name|FK_ReferenceInitDropsQualifiers
block|,
comment|/// \brief Reference binding failed.
name|FK_ReferenceInitFailed
block|,
comment|/// \brief Implicit conversion failed.
name|FK_ConversionFailed
block|,
comment|/// \brief Implicit conversion failed.
name|FK_ConversionFromPropertyFailed
block|,
comment|/// \brief Too many initializers for scalar
name|FK_TooManyInitsForScalar
block|,
comment|/// \brief Scalar initialized from a parenthesized initializer list.
name|FK_ParenthesizedListInitForScalar
block|,
comment|/// \brief Reference initialization from an initializer list
name|FK_ReferenceBindingToInitList
block|,
comment|/// \brief Initialization of some unused destination type with an
comment|/// initializer list.
name|FK_InitListBadDestinationType
block|,
comment|/// \brief Overloading for a user-defined conversion failed.
name|FK_UserConversionOverloadFailed
block|,
comment|/// \brief Overloading for initialization by constructor failed.
name|FK_ConstructorOverloadFailed
block|,
comment|/// \brief Overloading for list-initialization by constructor failed.
name|FK_ListConstructorOverloadFailed
block|,
comment|/// \brief Default-initialization of a 'const' object.
name|FK_DefaultInitOfConst
block|,
comment|/// \brief Initialization of an incomplete type.
name|FK_Incomplete
block|,
comment|/// \brief Variable-length array must not have an initializer.
name|FK_VariableLengthArrayHasInitializer
block|,
comment|/// \brief List initialization failed at some point.
name|FK_ListInitializationFailed
block|,
comment|/// \brief Initializer has a placeholder type which cannot be
comment|/// resolved by initialization.
name|FK_PlaceholderType
block|,
comment|/// \brief Trying to take the address of a function that doesn't support
comment|/// having its address taken.
name|FK_AddressOfUnaddressableFunction
block|,
comment|/// \brief List-copy-initialization chose an explicit constructor.
name|FK_ExplicitConstructor
block|,   }
enum|;
name|private
label|:
comment|/// \brief The reason why initialization failed.
name|FailureKind
name|Failure
decl_stmt|;
comment|/// \brief The failed result of overload resolution.
name|OverloadingResult
name|FailedOverloadResult
decl_stmt|;
comment|/// \brief The candidate set created when initialization failed.
name|OverloadCandidateSet
name|FailedCandidateSet
decl_stmt|;
comment|/// \brief The incomplete type that caused a failure.
name|QualType
name|FailedIncompleteType
decl_stmt|;
comment|/// \brief The fixit that needs to be applied to make this initialization
comment|/// succeed.
name|std
operator|::
name|string
name|ZeroInitializationFixit
expr_stmt|;
name|SourceLocation
name|ZeroInitializationFixitLoc
decl_stmt|;
name|public
label|:
comment|/// \brief Call for initializations are invalid but that would be valid
comment|/// zero initialzations if Fixit was applied.
name|void
name|SetZeroInitializationFixit
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Fixit
argument_list|,
name|SourceLocation
name|L
argument_list|)
block|{
name|ZeroInitializationFixit
operator|=
name|Fixit
expr_stmt|;
name|ZeroInitializationFixitLoc
operator|=
name|L
expr_stmt|;
block|}
name|private
label|:
comment|/// \brief Prints a follow-up note that highlights the location of
comment|/// the initialized entity, if it's remote.
name|void
name|PrintInitLocationNote
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
specifier|const
name|InitializedEntity
modifier|&
name|Entity
parameter_list|)
function_decl|;
name|public
label|:
comment|/// \brief Try to perform initialization of the given entity, creating a
comment|/// record of the steps required to perform the initialization.
comment|///
comment|/// The generated initialization sequence will either contain enough
comment|/// information to diagnose
comment|///
comment|/// \param S the semantic analysis object.
comment|///
comment|/// \param Entity the entity being initialized.
comment|///
comment|/// \param Kind the kind of initialization being performed.
comment|///
comment|/// \param Args the argument(s) provided for initialization.
comment|///
comment|/// \param TopLevelOfInitList true if we are initializing from an expression
comment|///        at the top level inside an initializer list. This disallows
comment|///        narrowing conversions in C++11 onwards.
comment|/// \param TreatUnavailableAsInvalid true if we want to treat unavailable
comment|///        as invalid.
name|InitializationSequence
argument_list|(
argument|Sema&S
argument_list|,
argument|const InitializedEntity&Entity
argument_list|,
argument|const InitializationKind&Kind
argument_list|,
argument|MultiExprArg Args
argument_list|,
argument|bool TopLevelOfInitList = false
argument_list|,
argument|bool TreatUnavailableAsInvalid = true
argument_list|)
empty_stmt|;
name|void
name|InitializeFrom
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
specifier|const
name|InitializedEntity
modifier|&
name|Entity
parameter_list|,
specifier|const
name|InitializationKind
modifier|&
name|Kind
parameter_list|,
name|MultiExprArg
name|Args
parameter_list|,
name|bool
name|TopLevelOfInitList
parameter_list|,
name|bool
name|TreatUnavailableAsInvalid
parameter_list|)
function_decl|;
operator|~
name|InitializationSequence
argument_list|()
expr_stmt|;
comment|/// \brief Perform the actual initialization of the given entity based on
comment|/// the computed initialization sequence.
comment|///
comment|/// \param S the semantic analysis object.
comment|///
comment|/// \param Entity the entity being initialized.
comment|///
comment|/// \param Kind the kind of initialization being performed.
comment|///
comment|/// \param Args the argument(s) provided for initialization, ownership of
comment|/// which is transferred into the routine.
comment|///
comment|/// \param ResultType if non-NULL, will be set to the type of the
comment|/// initialized object, which is the type of the declaration in most
comment|/// cases. However, when the initialized object is a variable of
comment|/// incomplete array type and the initializer is an initializer
comment|/// list, this type will be set to the completed array type.
comment|///
comment|/// \returns an expression that performs the actual object initialization, if
comment|/// the initialization is well-formed. Otherwise, emits diagnostics
comment|/// and returns an invalid expression.
name|ExprResult
name|Perform
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
specifier|const
name|InitializedEntity
modifier|&
name|Entity
parameter_list|,
specifier|const
name|InitializationKind
modifier|&
name|Kind
parameter_list|,
name|MultiExprArg
name|Args
parameter_list|,
name|QualType
modifier|*
name|ResultType
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Diagnose an potentially-invalid initialization sequence.
comment|///
comment|/// \returns true if the initialization sequence was ill-formed,
comment|/// false otherwise.
name|bool
name|Diagnose
argument_list|(
name|Sema
operator|&
name|S
argument_list|,
specifier|const
name|InitializedEntity
operator|&
name|Entity
argument_list|,
specifier|const
name|InitializationKind
operator|&
name|Kind
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|)
decl_stmt|;
comment|/// \brief Determine the kind of initialization sequence computed.
block|enum
name|SequenceKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|SequenceKind
return|;
block|}
comment|/// \brief Set the kind of sequence computed.
name|void
name|setSequenceKind
parameter_list|(
name|enum
name|SequenceKind
name|SK
parameter_list|)
block|{
name|SequenceKind
operator|=
name|SK
expr_stmt|;
block|}
comment|/// \brief Determine whether the initialization sequence is valid.
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Failed
argument_list|()
return|;
block|}
comment|/// \brief Determine whether the initialization sequence is invalid.
name|bool
name|Failed
argument_list|()
specifier|const
block|{
return|return
name|SequenceKind
operator|==
name|FailedSequence
return|;
block|}
typedef|typedef
name|SmallVectorImpl
operator|<
name|Step
operator|>
operator|::
name|const_iterator
name|step_iterator
expr_stmt|;
name|step_iterator
name|step_begin
argument_list|()
specifier|const
block|{
return|return
name|Steps
operator|.
name|begin
argument_list|()
return|;
block|}
name|step_iterator
name|step_end
argument_list|()
specifier|const
block|{
return|return
name|Steps
operator|.
name|end
argument_list|()
return|;
block|}
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|step_iterator
operator|>
name|step_range
expr_stmt|;
name|step_range
name|steps
argument_list|()
specifier|const
block|{
return|return
block|{
name|step_begin
argument_list|()
block|,
name|step_end
argument_list|()
block|}
return|;
block|}
comment|/// \brief Determine whether this initialization is a direct reference
comment|/// binding (C++ [dcl.init.ref]).
name|bool
name|isDirectReferenceBinding
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine whether this initialization failed due to an ambiguity.
name|bool
name|isAmbiguous
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine whether this initialization is direct call to a
comment|/// constructor.
name|bool
name|isConstructorInitialization
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns whether the last step in this initialization sequence is a
comment|/// narrowing conversion, defined by C++0x [dcl.init.list]p7.
comment|///
comment|/// If this function returns true, *isInitializerConstant will be set to
comment|/// describe whether *Initializer was a constant expression.  If
comment|/// *isInitializerConstant is set to true, *ConstantValue will be set to the
comment|/// evaluated value of *Initializer.
name|bool
name|endsWithNarrowing
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|Expr
operator|*
name|Initializer
argument_list|,
name|bool
operator|*
name|isInitializerConstant
argument_list|,
name|APValue
operator|*
name|ConstantValue
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Add a new step in the initialization that resolves the address
comment|/// of an overloaded function to a specific function declaration.
comment|///
comment|/// \param Function the function to which the overloaded function reference
comment|/// resolves.
name|void
name|AddAddressOverloadResolutionStep
parameter_list|(
name|FunctionDecl
modifier|*
name|Function
parameter_list|,
name|DeclAccessPair
name|Found
parameter_list|,
name|bool
name|HadMultipleCandidates
parameter_list|)
function_decl|;
comment|/// \brief Add a new step in the initialization that performs a derived-to-
comment|/// base cast.
comment|///
comment|/// \param BaseType the base type to which we will be casting.
comment|///
comment|/// \param Category Indicates whether the result will be treated as an
comment|/// rvalue, an xvalue, or an lvalue.
name|void
name|AddDerivedToBaseCastStep
parameter_list|(
name|QualType
name|BaseType
parameter_list|,
name|ExprValueKind
name|Category
parameter_list|)
function_decl|;
comment|/// \brief Add a new step binding a reference to an object.
comment|///
comment|/// \param BindingTemporary True if we are binding a reference to a temporary
comment|/// object (thereby extending its lifetime); false if we are binding to an
comment|/// lvalue or an lvalue treated as an rvalue.
name|void
name|AddReferenceBindingStep
parameter_list|(
name|QualType
name|T
parameter_list|,
name|bool
name|BindingTemporary
parameter_list|)
function_decl|;
comment|/// \brief Add a new step that makes an extraneous copy of the input
comment|/// to a temporary of the same class type.
comment|///
comment|/// This extraneous copy only occurs during reference binding in
comment|/// C++98/03, where we are permitted (but not required) to introduce
comment|/// an extra copy. At a bare minimum, we must check that we could
comment|/// call the copy constructor, and produce a diagnostic if the copy
comment|/// constructor is inaccessible or no copy constructor matches.
comment|//
comment|/// \param T The type of the temporary being created.
name|void
name|AddExtraneousCopyToTemporary
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add a new step that makes a copy of the input to an object of
comment|/// the given type, as the final step in class copy-initialization.
name|void
name|AddFinalCopy
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add a new step invoking a conversion function, which is either
comment|/// a constructor or a conversion function.
name|void
name|AddUserConversionStep
parameter_list|(
name|FunctionDecl
modifier|*
name|Function
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|,
name|QualType
name|T
parameter_list|,
name|bool
name|HadMultipleCandidates
parameter_list|)
function_decl|;
comment|/// \brief Add a new step that performs a qualification conversion to the
comment|/// given type.
name|void
name|AddQualificationConversionStep
parameter_list|(
name|QualType
name|Ty
parameter_list|,
name|ExprValueKind
name|Category
parameter_list|)
function_decl|;
comment|/// \brief Add a new step that performs conversion from non-atomic to atomic
comment|/// type.
name|void
name|AddAtomicConversionStep
parameter_list|(
name|QualType
name|Ty
parameter_list|)
function_decl|;
comment|/// \brief Add a new step that performs a load of the given type.
comment|///
comment|/// Although the term "LValueToRValue" is conventional, this applies to both
comment|/// lvalues and xvalues.
name|void
name|AddLValueToRValueStep
parameter_list|(
name|QualType
name|Ty
parameter_list|)
function_decl|;
comment|/// \brief Add a new step that applies an implicit conversion sequence.
name|void
name|AddConversionSequenceStep
parameter_list|(
specifier|const
name|ImplicitConversionSequence
modifier|&
name|ICS
parameter_list|,
name|QualType
name|T
parameter_list|,
name|bool
name|TopLevelOfInitList
init|=
name|false
parameter_list|)
function_decl|;
comment|/// \brief Add a list-initialization step.
name|void
name|AddListInitializationStep
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add a constructor-initialization step.
comment|///
comment|/// \param FromInitList The constructor call is syntactically an initializer
comment|/// list.
comment|/// \param AsInitList The constructor is called as an init list constructor.
name|void
name|AddConstructorInitializationStep
parameter_list|(
name|DeclAccessPair
name|FoundDecl
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|Constructor
parameter_list|,
name|QualType
name|T
parameter_list|,
name|bool
name|HadMultipleCandidates
parameter_list|,
name|bool
name|FromInitList
parameter_list|,
name|bool
name|AsInitList
parameter_list|)
function_decl|;
comment|/// \brief Add a zero-initialization step.
name|void
name|AddZeroInitializationStep
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add a C assignment step.
comment|//
comment|// FIXME: It isn't clear whether this should ever be needed;
comment|// ideally, we would handle everything needed in C in the common
comment|// path. However, that isn't the case yet.
name|void
name|AddCAssignmentStep
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add a string init step.
name|void
name|AddStringInitStep
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add an Objective-C object conversion step, which is
comment|/// always a no-op.
name|void
name|AddObjCObjectConversionStep
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add an array initialization loop step.
name|void
name|AddArrayInitLoopStep
parameter_list|(
name|QualType
name|T
parameter_list|,
name|QualType
name|EltTy
parameter_list|)
function_decl|;
comment|/// \brief Add an array initialization step.
name|void
name|AddArrayInitStep
parameter_list|(
name|QualType
name|T
parameter_list|,
name|bool
name|IsGNUExtension
parameter_list|)
function_decl|;
comment|/// \brief Add a parenthesized array initialization step.
name|void
name|AddParenthesizedArrayInitStep
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add a step to pass an object by indirect copy-restore.
name|void
name|AddPassByIndirectCopyRestoreStep
parameter_list|(
name|QualType
name|T
parameter_list|,
name|bool
name|shouldCopy
parameter_list|)
function_decl|;
comment|/// \brief Add a step to "produce" an Objective-C object (by
comment|/// retaining it).
name|void
name|AddProduceObjCObjectStep
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add a step to construct a std::initializer_list object from an
comment|/// initializer list.
name|void
name|AddStdInitializerListConstructionStep
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add a step to initialize an OpenCL sampler from an integer
comment|/// constant.
name|void
name|AddOCLSamplerInitStep
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add a step to initialize an OpenCL event_t from a NULL
comment|/// constant.
name|void
name|AddOCLZeroEventStep
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add a step to initialize an OpenCL queue_t from 0.
name|void
name|AddOCLZeroQueueStep
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add steps to unwrap a initializer list for a reference around a
comment|/// single element and rewrap it at the end.
name|void
name|RewrapReferenceInitList
parameter_list|(
name|QualType
name|T
parameter_list|,
name|InitListExpr
modifier|*
name|Syntactic
parameter_list|)
function_decl|;
comment|/// \brief Note that this initialization sequence failed.
name|void
name|SetFailed
parameter_list|(
name|FailureKind
name|Failure
parameter_list|)
block|{
name|SequenceKind
operator|=
name|FailedSequence
expr_stmt|;
name|this
operator|->
name|Failure
operator|=
name|Failure
expr_stmt|;
name|assert
argument_list|(
operator|(
name|Failure
operator|!=
name|FK_Incomplete
operator|||
operator|!
name|FailedIncompleteType
operator|.
name|isNull
argument_list|()
operator|)
operator|&&
literal|"Incomplete type failure requires a type!"
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Note that this initialization sequence failed due to failed
comment|/// overload resolution.
name|void
name|SetOverloadFailure
parameter_list|(
name|FailureKind
name|Failure
parameter_list|,
name|OverloadingResult
name|Result
parameter_list|)
function_decl|;
comment|/// \brief Retrieve a reference to the candidate set when overload
comment|/// resolution fails.
name|OverloadCandidateSet
modifier|&
name|getFailedCandidateSet
parameter_list|()
block|{
return|return
name|FailedCandidateSet
return|;
block|}
comment|/// \brief Get the overloading result, for when the initialization
comment|/// sequence failed due to a bad overload.
name|OverloadingResult
name|getFailedOverloadResult
argument_list|()
specifier|const
block|{
return|return
name|FailedOverloadResult
return|;
block|}
comment|/// \brief Note that this initialization sequence failed due to an
comment|/// incomplete type.
name|void
name|setIncompleteTypeFailure
parameter_list|(
name|QualType
name|IncompleteType
parameter_list|)
block|{
name|FailedIncompleteType
operator|=
name|IncompleteType
expr_stmt|;
name|SetFailed
argument_list|(
name|FK_Incomplete
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Determine why initialization failed.
name|FailureKind
name|getFailureKind
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Failed
argument_list|()
operator|&&
literal|"Not an initialization failure!"
argument_list|)
block|;
return|return
name|Failure
return|;
block|}
comment|/// \brief Dump a representation of this initialization sequence to
comment|/// the given stream, for debugging purposes.
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Dump a representation of this initialization sequence to
comment|/// standard error, for debugging purposes.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_SEMA_INITIALIZATION_H
end_comment

end_unit

