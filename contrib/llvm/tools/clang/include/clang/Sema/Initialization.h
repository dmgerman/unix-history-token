begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SemaInit.h - Semantic Analysis for Initializers --------*- C++ -*-===//
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
file|"clang/Sema/Ownership.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Overload.h"
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
file|"llvm/ADT/PointerIntPair.h"
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
name|llvm
block|{
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
union|union
block|{
comment|/// \brief When Kind == EK_Variable, EK_Parameter, or EK_Member,
comment|/// the VarDecl, ParmVarDecl, or FieldDecl, respectively.
name|DeclaratorDecl
modifier|*
name|VariableOrMember
decl_stmt|;
comment|/// \brief When Kind == EK_Temporary, the type source information for
comment|/// the temporary.
name|TypeSourceInfo
modifier|*
name|TypeInfo
decl_stmt|;
struct|struct
block|{
comment|/// \brief When Kind == EK_Result, EK_Exception, or EK_New, the
comment|/// location of the 'return', 'throw', or 'new' keyword,
comment|/// respectively. When Kind == EK_Temporary, the location where
comment|/// the temporary is being created.
name|unsigned
name|Location
decl_stmt|;
comment|/// \brief Whether the
name|bool
name|NRVO
decl_stmt|;
block|}
name|LocAndNRVO
struct|;
comment|/// \brief When Kind == EK_Base, the base specifier that provides the
comment|/// base class. The lower bit specifies whether the base is an inherited
comment|/// virtual base.
name|uintptr_t
name|Base
decl_stmt|;
comment|/// \brief When Kind == EK_ArrayElement or EK_VectorElement, the
comment|/// index of the array or vector element being initialized.
name|unsigned
name|Index
decl_stmt|;
block|}
union|;
name|InitializedEntity
argument_list|()
block|{ }
comment|/// \brief Create the initialization entity for a variable.
name|InitializedEntity
argument_list|(
name|VarDecl
operator|*
name|Var
argument_list|)
operator|:
name|Kind
argument_list|(
name|EK_Variable
argument_list|)
operator|,
name|Parent
argument_list|(
literal|0
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
name|VariableOrMember
argument_list|(
argument|Var
argument_list|)
block|{ }
comment|/// \brief Create the initialization entity for a parameter.
name|InitializedEntity
argument_list|(
name|ParmVarDecl
operator|*
name|Parm
argument_list|)
operator|:
name|Kind
argument_list|(
name|EK_Parameter
argument_list|)
operator|,
name|Parent
argument_list|(
literal|0
argument_list|)
operator|,
name|Type
argument_list|(
name|Parm
operator|->
name|getType
argument_list|()
operator|.
name|getUnqualifiedType
argument_list|()
argument_list|)
operator|,
name|VariableOrMember
argument_list|(
argument|Parm
argument_list|)
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
literal|0
argument_list|)
operator|,
name|Type
argument_list|(
argument|Type
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
name|FieldDecl
operator|*
name|Member
argument_list|,
specifier|const
name|InitializedEntity
operator|*
name|Parent
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
name|VariableOrMember
argument_list|(
argument|Member
argument_list|)
block|{ }
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
name|public
label|:
comment|/// \brief Create the initialization entity for a variable.
specifier|static
name|InitializedEntity
name|InitializeVariable
parameter_list|(
name|VarDecl
modifier|*
name|Var
parameter_list|)
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
name|ParmVarDecl
modifier|*
name|Parm
parameter_list|)
block|{
name|InitializedEntity
name|Res
argument_list|(
name|Parm
argument_list|)
decl_stmt|;
name|Res
operator|.
name|Type
operator|=
name|Context
operator|.
name|getVariableArrayDecayedType
argument_list|(
name|Res
operator|.
name|Type
argument_list|)
expr_stmt|;
return|return
name|Res
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
literal|0
expr_stmt|;
name|Entity
operator|.
name|VariableOrMember
operator|=
literal|0
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
name|InitializedEntity
argument_list|(
name|EK_Temporary
argument_list|,
name|SourceLocation
argument_list|()
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
name|InitializedEntity
name|Result
argument_list|(
name|EK_Temporary
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|TypeInfo
operator|->
name|getType
argument_list|()
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
comment|/// \brief Create the initialization entity for a base class subobject.
specifier|static
name|InitializedEntity
name|InitializeBase
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|CXXBaseSpecifier
modifier|*
name|Base
parameter_list|,
name|bool
name|IsInheritedVirtualBase
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
literal|0
parameter_list|)
block|{
return|return
name|InitializedEntity
argument_list|(
name|Member
argument_list|,
name|Parent
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
literal|0
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
condition|)
return|return
name|TypeInfo
return|;
return|return
literal|0
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
name|DeclaratorDecl
operator|*
name|getDecl
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine whether this initialization allows the named return
comment|/// value optimization, which also applies to thrown objects.
name|bool
name|allowsNRVO
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the base specifier.
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
argument_list|)
expr_stmt|;
name|this
operator|->
name|Index
operator|=
name|Index
expr_stmt|;
block|}
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
comment|/// \brief The kind of initialization that we're storing.
enum|enum
name|StoredInitKind
block|{
name|SIK_Direct
init|=
name|IK_Direct
block|,
comment|///< Direct initialization
name|SIK_Copy
init|=
name|IK_Copy
block|,
comment|///< Copy initialization
name|SIK_Default
init|=
name|IK_Default
block|,
comment|///< Default initialization
name|SIK_Value
init|=
name|IK_Value
block|,
comment|///< Value initialization
name|SIK_ImplicitValue
block|,
comment|///< Implicit value initialization
name|SIK_DirectCast
block|,
comment|///< Direct initialization due to a cast
comment|/// \brief Direct initialization due to a C-style or functional cast.
name|SIK_DirectCStyleOrFunctionalCast
block|}
enum|;
comment|/// \brief The kind of initialization being performed.
name|StoredInitKind
name|Kind
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
argument|StoredInitKind Kind
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
argument|Kind
argument_list|)
block|{
name|Locations
index|[
literal|0
index|]
operator|=
name|Loc1
expr_stmt|;
name|Locations
index|[
literal|1
index|]
operator|=
name|Loc2
expr_stmt|;
name|Locations
index|[
literal|2
index|]
operator|=
name|Loc3
expr_stmt|;
block|}
name|public
label|:
comment|/// \brief Create a direct initialization.
specifier|static
name|InitializationKind
name|CreateDirect
parameter_list|(
name|SourceLocation
name|InitLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
block|{
return|return
name|InitializationKind
argument_list|(
name|SIK_Direct
argument_list|,
name|InitLoc
argument_list|,
name|LParenLoc
argument_list|,
name|RParenLoc
argument_list|)
return|;
block|}
comment|/// \brief Create a direct initialization due to a cast.
specifier|static
name|InitializationKind
name|CreateCast
parameter_list|(
name|SourceRange
name|TypeRange
parameter_list|,
name|bool
name|IsCStyleCast
parameter_list|)
block|{
return|return
name|InitializationKind
argument_list|(
name|IsCStyleCast
condition|?
name|SIK_DirectCStyleOrFunctionalCast
else|:
name|SIK_DirectCast
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
parameter_list|)
block|{
return|return
name|InitializationKind
argument_list|(
name|SIK_Copy
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
name|SIK_Default
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
name|isImplicit
condition|?
name|SIK_ImplicitValue
else|:
name|SIK_Value
argument_list|,
name|InitLoc
argument_list|,
name|LParenLoc
argument_list|,
name|RParenLoc
argument_list|)
return|;
block|}
comment|/// \brief Determine the initialization kind.
name|InitKind
name|getKind
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Kind
operator|>
name|SIK_ImplicitValue
condition|)
return|return
name|IK_Direct
return|;
if|if
condition|(
name|Kind
operator|==
name|SIK_ImplicitValue
condition|)
return|return
name|IK_Value
return|;
return|return
operator|(
name|InitKind
operator|)
name|Kind
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this initialization is an explicit cast.
end_comment

begin_expr_stmt
name|bool
name|isExplicitCast
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|SIK_DirectCast
operator|||
name|Kind
operator|==
name|SIK_DirectCStyleOrFunctionalCast
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this initialization is a C-style cast.
end_comment

begin_expr_stmt
name|bool
name|isCStyleOrFunctionalCast
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|SIK_DirectCStyleOrFunctionalCast
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this initialization is an implicit
end_comment

begin_comment
comment|/// value-initialization, e.g., as occurs during aggregate
end_comment

begin_comment
comment|/// initialization.
end_comment

begin_expr_stmt
name|bool
name|isImplicitValueInit
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|SIK_ImplicitValue
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the location at which initialization is occurring.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the source range that covers the initialization.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the location of the equal sign for copy initialization
end_comment

begin_comment
comment|/// (if present).
end_comment

begin_expr_stmt
name|SourceLocation
name|getEqualLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|SIK_Copy
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
end_expr_stmt

begin_expr_stmt
name|bool
name|isCopyInit
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|SIK_Copy
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the source range containing the locations of the open
end_comment

begin_comment
comment|/// and closing parentheses for value and direct initializations.
end_comment

begin_expr_stmt
name|SourceRange
name|getParenRange
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|getKind
argument_list|()
operator|==
name|IK_Direct
operator|||
name|Kind
operator|==
name|SIK_Value
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
end_expr_stmt

begin_comment
unit|};
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
comment|///
comment|/// FIXME: Much of this information is in the initialization steps... why is
comment|/// it duplicated here?
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
comment|/// dependently-type expressions.
name|DependentSequence
block|,
comment|/// \brief A user-defined conversion sequence.
name|UserDefinedConversion
block|,
comment|/// \brief A constructor call.
name|ConstructorInitialization
block|,
comment|/// \brief A reference binding.
name|ReferenceBinding
block|,
comment|/// \brief List initialization
name|ListInitialization
block|,
comment|/// \brief Zero-initialization.
name|ZeroInitialization
block|,
comment|/// \brief No initialization required.
name|NoInitialization
block|,
comment|/// \brief Standard conversion sequence.
name|StandardConversion
block|,
comment|/// \brief C conversion sequence.
name|CAssignment
block|,
comment|/// \brief String initialization
name|StringInit
block|,
comment|/// \brief Array initialization from another array (GNU C extension).
name|ArrayInit
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
comment|/// \brief Perform an implicit conversion sequence.
name|SK_ConversionSequence
block|,
comment|/// \brief Perform list-initialization
name|SK_ListInitialization
block|,
comment|/// \brief Perform initialization via a constructor.
name|SK_ConstructorInitialization
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
comment|/// \brief Array initialization (from an array rvalue).
comment|/// This is a GNU C extension.
name|SK_ArrayInit
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
union|union
block|{
comment|/// \brief When Kind == SK_ResolvedOverloadedFunction or Kind ==
comment|/// SK_UserConversion, the function that the expression should be
comment|/// resolved to or the conversion function to call, respectively.
comment|///
comment|/// Always a FunctionDecl.
comment|/// For conversion decls, the naming class is the source type.
comment|/// For construct decls, the naming class is the target type.
struct|struct
block|{
name|FunctionDecl
modifier|*
name|Function
decl_stmt|;
name|DeclAccessPair
name|FoundDecl
decl_stmt|;
block|}
name|Function
struct|;
comment|/// \brief When Kind = SK_ConversionSequence, the implicit conversion
comment|/// sequence
name|ImplicitConversionSequence
modifier|*
name|ICS
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
name|llvm
operator|::
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
comment|/// \brief Array must be initialized with an initializer list.
name|FK_ArrayNeedsInitList
block|,
comment|/// \brief Array must be initialized with an initializer list or a
comment|/// string literal.
name|FK_ArrayNeedsInitListOrStringLiteral
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
comment|/// \brief Overloaded for initialization by constructor failed.
name|FK_ConstructorOverloadFailed
block|,
comment|/// \brief Default-initialization of a 'const' object.
name|FK_DefaultInitOfConst
block|,
comment|/// \brief Initialization of an incomplete type.
name|FK_Incomplete
block|}
enum|;
name|private
label|:
comment|/// \brief The reason why initialization failued.
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
comment|/// \param NumArgs the number of arguments provided for initialization.
name|InitializationSequence
argument_list|(
argument|Sema&S
argument_list|,
argument|const InitializedEntity&Entity
argument_list|,
argument|const InitializationKind&Kind
argument_list|,
argument|Expr **Args
argument_list|,
argument|unsigned NumArgs
argument_list|)
empty_stmt|;
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
literal|0
parameter_list|)
function_decl|;
comment|/// \brief Diagnose an potentially-invalid initialization sequence.
comment|///
comment|/// \returns true if the initialization sequence was ill-formed,
comment|/// false otherwise.
name|bool
name|Diagnose
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
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|)
function_decl|;
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
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|SequenceKind
operator|!=
name|FailedSequence
return|;
block|}
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|Step
operator|,
literal|4
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
parameter_list|)
function_decl|;
comment|/// \brief Add a new step in the initialization that performs a derived-to-
comment|/// base cast.
comment|///
comment|/// \param BaseType the base type to which we will be casting.
comment|///
comment|/// \param IsLValue true if the result of this cast will be treated as
comment|/// an lvalue.
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
comment|///
comment|/// \param UnnecessaryCopy True if we should check for a copy
comment|/// constructor for a completely unnecessary but
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
parameter_list|)
function_decl|;
comment|/// \brief Add a list-initialiation step
name|void
name|AddListInitializationStep
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Add a constructor-initialization step.
name|void
name|AddConstructorInitializationStep
parameter_list|(
name|CXXConstructorDecl
modifier|*
name|Constructor
parameter_list|,
name|AccessSpecifier
name|Access
parameter_list|,
name|QualType
name|T
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
comment|/// \brief Add an array initialization step.
name|void
name|AddArrayInitStep
parameter_list|(
name|QualType
name|T
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
comment|/// brief Get the overloading result, for when the initialization
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
comment|/// \brief Determine why initialization failed.
name|FailureKind
name|getFailureKind
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|FailedSequence
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
name|llvm
operator|::
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

