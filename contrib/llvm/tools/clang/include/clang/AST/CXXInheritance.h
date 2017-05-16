begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------ CXXInheritance.h - C++ Inheritance ------------------*- C++ -*-===//
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
comment|// This file provides routines that help analyzing C++ inheritance hierarchies.
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
name|LLVM_CLANG_AST_CXXINHERITANCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_CXXINHERITANCE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclBase.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TypeOrdering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
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

begin_include
include|#
directive|include
file|<list>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CXXBaseSpecifier
decl_stmt|;
name|class
name|CXXMethodDecl
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
comment|/// \brief Represents an element in a path from a derived class to a
comment|/// base class.
comment|///
comment|/// Each step in the path references the link from a
comment|/// derived class to one of its direct base classes, along with a
comment|/// base "number" that identifies which base subobject of the
comment|/// original derived class we are referencing.
struct|struct
name|CXXBasePathElement
block|{
comment|/// \brief The base specifier that states the link from a derived
comment|/// class to a base class, which will be followed by this base
comment|/// path element.
specifier|const
name|CXXBaseSpecifier
modifier|*
name|Base
decl_stmt|;
comment|/// \brief The record decl of the class that the base is a base of.
specifier|const
name|CXXRecordDecl
modifier|*
name|Class
decl_stmt|;
comment|/// \brief Identifies which base class subobject (of type
comment|/// \c Base->getType()) this base path element refers to.
comment|///
comment|/// This value is only valid if \c !Base->isVirtual(), because there
comment|/// is no base numbering for the zero or one virtual bases of a
comment|/// given type.
name|int
name|SubobjectNumber
decl_stmt|;
block|}
struct|;
comment|/// \brief Represents a path from a specific derived class
comment|/// (which is not represented as part of the path) to a particular
comment|/// (direct or indirect) base class subobject.
comment|///
comment|/// Individual elements in the path are described by the \c CXXBasePathElement
comment|/// structure, which captures both the link from a derived class to one of its
comment|/// direct bases and identification describing which base class
comment|/// subobject is being used.
name|class
name|CXXBasePath
range|:
name|public
name|SmallVector
operator|<
name|CXXBasePathElement
decl_stmt|, 4>
block|{
name|public
label|:
name|CXXBasePath
argument_list|()
operator|:
name|Access
argument_list|(
argument|AS_public
argument_list|)
block|{}
comment|/// \brief The access along this inheritance path.  This is only
comment|/// calculated when recording paths.  AS_none is a special value
comment|/// used to indicate a path which permits no legal access.
name|AccessSpecifier
name|Access
expr_stmt|;
comment|/// \brief The set of declarations found inside this base class
comment|/// subobject.
name|DeclContext
operator|::
name|lookup_result
name|Decls
expr_stmt|;
name|void
name|clear
parameter_list|()
block|{
name|SmallVectorImpl
operator|<
name|CXXBasePathElement
operator|>
operator|::
name|clear
argument_list|()
expr_stmt|;
name|Access
operator|=
name|AS_public
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// BasePaths - Represents the set of paths from a derived class to
comment|/// one of its (direct or indirect) bases. For example, given the
comment|/// following class hierarchy:
comment|///
comment|/// @code
comment|/// class A { };
comment|/// class B : public A { };
comment|/// class C : public A { };
comment|/// class D : public B, public C{ };
comment|/// @endcode
comment|///
comment|/// There are two potential BasePaths to represent paths from D to a
comment|/// base subobject of type A. One path is (D,0) -> (B,0) -> (A,0)
comment|/// and another is (D,0)->(C,0)->(A,1). These two paths actually
comment|/// refer to two different base class subobjects of the same type,
comment|/// so the BasePaths object refers to an ambiguous path. On the
comment|/// other hand, consider the following class hierarchy:
comment|///
comment|/// @code
comment|/// class A { };
comment|/// class B : public virtual A { };
comment|/// class C : public virtual A { };
comment|/// class D : public B, public C{ };
comment|/// @endcode
comment|///
comment|/// Here, there are two potential BasePaths again, (D, 0) -> (B, 0)
comment|/// -> (A,v) and (D, 0) -> (C, 0) -> (A, v), but since both of them
comment|/// refer to the same base class subobject of type A (the virtual
comment|/// one), there is no ambiguity.
name|class
name|CXXBasePaths
block|{
comment|/// \brief The type from which this search originated.
name|CXXRecordDecl
modifier|*
name|Origin
decl_stmt|;
comment|/// Paths - The actual set of paths that can be taken from the
comment|/// derived class to the same base class.
name|std
operator|::
name|list
operator|<
name|CXXBasePath
operator|>
name|Paths
expr_stmt|;
comment|/// ClassSubobjects - Records the class subobjects for each class
comment|/// type that we've seen. The first element in the pair says
comment|/// whether we found a path to a virtual base for that class type,
comment|/// while the element contains the number of non-virtual base
comment|/// class subobjects for that class type. The key of the map is
comment|/// the cv-unqualified canonical type of the base class subobject.
name|llvm
operator|::
name|SmallDenseMap
operator|<
name|QualType
operator|,
name|std
operator|::
name|pair
operator|<
name|bool
operator|,
name|unsigned
operator|>
operator|,
literal|8
operator|>
name|ClassSubobjects
expr_stmt|;
comment|/// FindAmbiguities - Whether Sema::IsDerivedFrom should try find
comment|/// ambiguous paths while it is looking for a path from a derived
comment|/// type to a base type.
name|bool
name|FindAmbiguities
decl_stmt|;
comment|/// RecordPaths - Whether Sema::IsDerivedFrom should record paths
comment|/// while it is determining whether there are paths from a derived
comment|/// type to a base type.
name|bool
name|RecordPaths
decl_stmt|;
comment|/// DetectVirtual - Whether Sema::IsDerivedFrom should abort the search
comment|/// if it finds a path that goes across a virtual base. The virtual class
comment|/// is also recorded.
name|bool
name|DetectVirtual
decl_stmt|;
comment|/// ScratchPath - A BasePath that is used by Sema::lookupInBases
comment|/// to help build the set of paths.
name|CXXBasePath
name|ScratchPath
decl_stmt|;
comment|/// DetectedVirtual - The base class that is virtual.
specifier|const
name|RecordType
modifier|*
name|DetectedVirtual
decl_stmt|;
comment|/// \brief Array of the declarations that have been found. This
comment|/// array is constructed only if needed, e.g., to iterate over the
comment|/// results within LookupResult.
name|std
operator|::
name|unique_ptr
operator|<
name|NamedDecl
operator|*
index|[]
operator|>
name|DeclsFound
expr_stmt|;
name|unsigned
name|NumDeclsFound
decl_stmt|;
name|friend
name|class
name|CXXRecordDecl
decl_stmt|;
name|void
name|ComputeDeclsFound
parameter_list|()
function_decl|;
name|bool
name|lookupInBases
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|Record
argument_list|,
name|CXXRecordDecl
operator|::
name|BaseMatchesCallback
name|BaseMatches
argument_list|,
name|bool
name|LookupInDependent
operator|=
name|false
argument_list|)
decl_stmt|;
name|public
label|:
typedef|typedef
name|std
operator|::
name|list
operator|<
name|CXXBasePath
operator|>
operator|::
name|iterator
name|paths_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|list
operator|<
name|CXXBasePath
operator|>
operator|::
name|const_iterator
name|const_paths_iterator
expr_stmt|;
typedef|typedef
name|NamedDecl
modifier|*
modifier|*
name|decl_iterator
typedef|;
comment|/// BasePaths - Construct a new BasePaths structure to record the
comment|/// paths for a derived-to-base search.
name|explicit
name|CXXBasePaths
argument_list|(
argument|bool FindAmbiguities = true
argument_list|,
argument|bool RecordPaths = true
argument_list|,
argument|bool DetectVirtual = true
argument_list|)
block|:
name|Origin
argument_list|()
operator|,
name|FindAmbiguities
argument_list|(
name|FindAmbiguities
argument_list|)
operator|,
name|RecordPaths
argument_list|(
name|RecordPaths
argument_list|)
operator|,
name|DetectVirtual
argument_list|(
name|DetectVirtual
argument_list|)
operator|,
name|DetectedVirtual
argument_list|(
name|nullptr
argument_list|)
operator|,
name|NumDeclsFound
argument_list|(
literal|0
argument_list|)
block|{}
name|paths_iterator
name|begin
argument_list|()
block|{
return|return
name|Paths
operator|.
name|begin
argument_list|()
return|;
block|}
name|paths_iterator
name|end
parameter_list|()
block|{
return|return
name|Paths
operator|.
name|end
argument_list|()
return|;
block|}
name|const_paths_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Paths
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_paths_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Paths
operator|.
name|end
argument_list|()
return|;
block|}
name|CXXBasePath
modifier|&
name|front
parameter_list|()
block|{
return|return
name|Paths
operator|.
name|front
argument_list|()
return|;
block|}
specifier|const
name|CXXBasePath
operator|&
name|front
argument_list|()
specifier|const
block|{
return|return
name|Paths
operator|.
name|front
argument_list|()
return|;
block|}
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|decl_iterator
operator|>
name|decl_range
expr_stmt|;
name|decl_range
name|found_decls
parameter_list|()
function_decl|;
comment|/// \brief Determine whether the path from the most-derived type to the
comment|/// given base type is ambiguous (i.e., it refers to multiple subobjects of
comment|/// the same base type).
name|bool
name|isAmbiguous
parameter_list|(
name|CanQualType
name|BaseType
parameter_list|)
function_decl|;
comment|/// \brief Whether we are finding multiple paths to detect ambiguities.
name|bool
name|isFindingAmbiguities
argument_list|()
specifier|const
block|{
return|return
name|FindAmbiguities
return|;
block|}
comment|/// \brief Whether we are recording paths.
name|bool
name|isRecordingPaths
argument_list|()
specifier|const
block|{
return|return
name|RecordPaths
return|;
block|}
comment|/// \brief Specify whether we should be recording paths or not.
name|void
name|setRecordingPaths
parameter_list|(
name|bool
name|RP
parameter_list|)
block|{
name|RecordPaths
operator|=
name|RP
expr_stmt|;
block|}
comment|/// \brief Whether we are detecting virtual bases.
name|bool
name|isDetectingVirtual
argument_list|()
specifier|const
block|{
return|return
name|DetectVirtual
return|;
block|}
comment|/// \brief The virtual base discovered on the path (if we are merely
comment|/// detecting virtuals).
specifier|const
name|RecordType
operator|*
name|getDetectedVirtual
argument_list|()
specifier|const
block|{
return|return
name|DetectedVirtual
return|;
block|}
comment|/// \brief Retrieve the type from which this base-paths search
comment|/// began
name|CXXRecordDecl
operator|*
name|getOrigin
argument_list|()
specifier|const
block|{
return|return
name|Origin
return|;
block|}
name|void
name|setOrigin
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Rec
parameter_list|)
block|{
name|Origin
operator|=
name|Rec
expr_stmt|;
block|}
comment|/// \brief Clear the base-paths results.
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// \brief Swap this data structure's contents with another CXXBasePaths
comment|/// object.
name|void
name|swap
parameter_list|(
name|CXXBasePaths
modifier|&
name|Other
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// \brief Uniquely identifies a virtual method within a class
comment|/// hierarchy by the method itself and a class subobject number.
struct|struct
name|UniqueVirtualMethod
block|{
name|UniqueVirtualMethod
argument_list|()
operator|:
name|Method
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Subobject
argument_list|(
literal|0
argument_list|)
operator|,
name|InVirtualSubobject
argument_list|(
argument|nullptr
argument_list|)
block|{ }
name|UniqueVirtualMethod
argument_list|(
argument|CXXMethodDecl *Method
argument_list|,
argument|unsigned Subobject
argument_list|,
argument|const CXXRecordDecl *InVirtualSubobject
argument_list|)
operator|:
name|Method
argument_list|(
name|Method
argument_list|)
operator|,
name|Subobject
argument_list|(
name|Subobject
argument_list|)
operator|,
name|InVirtualSubobject
argument_list|(
argument|InVirtualSubobject
argument_list|)
block|{ }
comment|/// \brief The overriding virtual method.
name|CXXMethodDecl
operator|*
name|Method
expr_stmt|;
comment|/// \brief The subobject in which the overriding virtual method
comment|/// resides.
name|unsigned
name|Subobject
decl_stmt|;
comment|/// \brief The virtual base class subobject of which this overridden
comment|/// virtual method is a part. Note that this records the closest
comment|/// derived virtual base class subobject.
specifier|const
name|CXXRecordDecl
modifier|*
name|InVirtualSubobject
decl_stmt|;
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|UniqueVirtualMethod
operator|&
name|X
operator|,
specifier|const
name|UniqueVirtualMethod
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Method
operator|==
name|Y
operator|.
name|Method
operator|&&
name|X
operator|.
name|Subobject
operator|==
name|Y
operator|.
name|Subobject
operator|&&
name|X
operator|.
name|InVirtualSubobject
operator|==
name|Y
operator|.
name|InVirtualSubobject
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|UniqueVirtualMethod
operator|&
name|X
operator|,
specifier|const
name|UniqueVirtualMethod
operator|&
name|Y
operator|)
block|{
return|return
operator|!
operator|(
name|X
operator|==
name|Y
operator|)
return|;
block|}
block|}
struct|;
comment|/// \brief The set of methods that override a given virtual method in
comment|/// each subobject where it occurs.
comment|///
comment|/// The first part of the pair is the subobject in which the
comment|/// overridden virtual function occurs, while the second part of the
comment|/// pair is the virtual method that overrides it (including the
comment|/// subobject in which that virtual function occurs).
name|class
name|OverridingMethods
block|{
typedef|typedef
name|SmallVector
operator|<
name|UniqueVirtualMethod
operator|,
literal|4
operator|>
name|ValuesT
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|MapVector
operator|<
name|unsigned
operator|,
name|ValuesT
operator|>
name|MapType
expr_stmt|;
name|MapType
name|Overrides
decl_stmt|;
name|public
label|:
comment|// Iterate over the set of subobjects that have overriding methods.
typedef|typedef
name|MapType
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|MapType
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Overrides
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Overrides
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|Overrides
operator|.
name|end
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Overrides
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Overrides
operator|.
name|size
argument_list|()
return|;
block|}
comment|// Iterate over the set of overriding virtual methods in a given
comment|// subobject.
typedef|typedef
name|SmallVectorImpl
operator|<
name|UniqueVirtualMethod
operator|>
operator|::
name|iterator
name|overriding_iterator
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|UniqueVirtualMethod
operator|>
operator|::
name|const_iterator
name|overriding_const_iterator
expr_stmt|;
comment|// Add a new overriding method for a particular subobject.
name|void
name|add
parameter_list|(
name|unsigned
name|OverriddenSubobject
parameter_list|,
name|UniqueVirtualMethod
name|Overriding
parameter_list|)
function_decl|;
comment|// Add all of the overriding methods from "other" into overrides for
comment|// this method. Used when merging the overrides from multiple base
comment|// class subobjects.
name|void
name|add
parameter_list|(
specifier|const
name|OverridingMethods
modifier|&
name|Other
parameter_list|)
function_decl|;
comment|// Replace all overriding virtual methods in all subobjects with the
comment|// given virtual method.
name|void
name|replaceAll
parameter_list|(
name|UniqueVirtualMethod
name|Overriding
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// \brief A mapping from each virtual member function to its set of
comment|/// final overriders.
comment|///
comment|/// Within a class hierarchy for a given derived class, each virtual
comment|/// member function in that hierarchy has one or more "final
comment|/// overriders" (C++ [class.virtual]p2). A final overrider for a
comment|/// virtual function "f" is the virtual function that will actually be
comment|/// invoked when dispatching a call to "f" through the
comment|/// vtable. Well-formed classes have a single final overrider for each
comment|/// virtual function; in abstract classes, the final overrider for at
comment|/// least one virtual function is a pure virtual function. Due to
comment|/// multiple, virtual inheritance, it is possible for a class to have
comment|/// more than one final overrider. Athough this is an error (per C++
comment|/// [class.virtual]p2), it is not considered an error here: the final
comment|/// overrider map can represent multiple final overriders for a
comment|/// method, and it is up to the client to determine whether they are
comment|/// problem. For example, the following class \c D has two final
comment|/// overriders for the virtual function \c A::f(), one in \c C and one
comment|/// in \c D:
comment|///
comment|/// \code
comment|///   struct A { virtual void f(); };
comment|///   struct B : virtual A { virtual void f(); };
comment|///   struct C : virtual A { virtual void f(); };
comment|///   struct D : B, C { };
comment|/// \endcode
comment|///
comment|/// This data structure contains a mapping from every virtual
comment|/// function *that does not override an existing virtual function* and
comment|/// in every subobject where that virtual function occurs to the set
comment|/// of virtual functions that override it. Thus, the same virtual
comment|/// function \c A::f can actually occur in multiple subobjects of type
comment|/// \c A due to multiple inheritance, and may be overridden by
comment|/// different virtual functions in each, as in the following example:
comment|///
comment|/// \code
comment|///   struct A { virtual void f(); };
comment|///   struct B : A { virtual void f(); };
comment|///   struct C : A { virtual void f(); };
comment|///   struct D : B, C { };
comment|/// \endcode
comment|///
comment|/// Unlike in the previous example, where the virtual functions \c
comment|/// B::f and \c C::f both overrode \c A::f in the same subobject of
comment|/// type \c A, in this example the two virtual functions both override
comment|/// \c A::f but in *different* subobjects of type A. This is
comment|/// represented by numbering the subobjects in which the overridden
comment|/// and the overriding virtual member functions are located. Subobject
comment|/// 0 represents the virtual base class subobject of that type, while
comment|/// subobject numbers greater than 0 refer to non-virtual base class
comment|/// subobjects of that type.
name|class
name|CXXFinalOverriderMap
range|:
name|public
name|llvm
operator|::
name|MapVector
operator|<
specifier|const
name|CXXMethodDecl
operator|*
decl_stmt|,
name|OverridingMethods
decl|>
block|{ }
empty_stmt|;
comment|/// \brief A set of all the primary bases for a class.
name|class
name|CXXIndirectPrimaryBaseSet
range|:
name|public
name|llvm
operator|::
name|SmallSet
operator|<
specifier|const
name|CXXRecordDecl
operator|*
decl_stmt|, 32>
block|{ }
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

