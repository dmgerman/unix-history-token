begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- MicrosoftVBTables.h - Virtual Base Table Emission ----------------===//
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
comment|// This class generates data about MSVC virtual base tables.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"clang/AST/BaseSubobject.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalVariable.h"
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
name|ASTRecordLayout
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenModule
decl_stmt|;
struct|struct
name|VBTableInfo
block|{
name|VBTableInfo
argument_list|(
argument|const CXXRecordDecl *ReusingBase
argument_list|,
argument|BaseSubobject VBPtrSubobject
argument_list|,
argument|llvm::GlobalVariable *GV
argument_list|)
block|:
name|ReusingBase
argument_list|(
name|ReusingBase
argument_list|)
operator|,
name|VBPtrSubobject
argument_list|(
name|VBPtrSubobject
argument_list|)
operator|,
name|GV
argument_list|(
argument|GV
argument_list|)
block|{ }
comment|/// The vbtable will hold all of the virtual bases of ReusingBase.  This may
comment|/// or may not be the same class as VBPtrSubobject.Base.  A derived class will
comment|/// reuse the vbptr of the first non-virtual base subobject that has one.
specifier|const
name|CXXRecordDecl
operator|*
name|ReusingBase
expr_stmt|;
comment|/// The vbptr is stored inside this subobject.
name|BaseSubobject
name|VBPtrSubobject
decl_stmt|;
comment|/// The GlobalVariable for this vbtable.
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GV
expr_stmt|;
comment|/// \brief Emits a definition for GV by setting it's initializer.
name|void
name|EmitVBTableDefinition
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|::
name|LinkageTypes
name|Linkage
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
comment|// These are embedded in a DenseMap and the elements are large, so we don't want
comment|// SmallVector.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|VBTableInfo
operator|>
name|VBTableVector
expr_stmt|;
struct_decl|struct
name|VBTablePath
struct_decl|;
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|VBTablePath
operator|*
operator|,
literal|6
operator|>
name|VBTablePathVector
expr_stmt|;
comment|/// Produces MSVC-compatible vbtable data.  The symbols produced by this builder
comment|/// match those produced by MSVC 2012, which is different from MSVC 2010.
comment|///
comment|/// Unlike Itanium, which uses only one vtable per class, MSVC uses a different
comment|/// symbol for every "address point" installed in base subobjects.  As a result,
comment|/// we have to compute unique symbols for every table.  Since there can be
comment|/// multiple non-virtual base subobjects of the same class, combining the most
comment|/// derived class with the base containing the vtable is insufficient.  The most
comment|/// trivial algorithm would be to mangle in the entire path from base to most
comment|/// derived, but that would be too easy and would create unnecessarily large
comment|/// symbols.  ;)
comment|///
comment|/// MSVC 2012 appears to minimize the vbtable names using the following
comment|/// algorithm.  First, walk the class hierarchy in the usual order, depth first,
comment|/// left to right, to find all of the subobjects which contain a vbptr field.
comment|/// Visiting each class node yields a list of inheritance paths to vbptrs.  Each
comment|/// record with a vbptr creates an initially empty path.
comment|///
comment|/// To combine paths from child nodes, the paths are compared to check for
comment|/// ambiguity.  Paths are "ambiguous" if multiple paths have the same set of
comment|/// components in the same order.  Each group of ambiguous paths is extended by
comment|/// appending the class of the base from which it came.  If the current class
comment|/// node produced an ambiguous path, its path is extended with the current class.
comment|/// After extending paths, MSVC again checks for ambiguity, and extends any
comment|/// ambiguous path which wasn't already extended.  Because each node yields an
comment|/// unambiguous set of paths, MSVC doesn't need to extend any path more than once
comment|/// to produce an unambiguous set of paths.
comment|///
comment|/// The VBTableBuilder class attempts to implement this algorithm by repeatedly
comment|/// bucketing paths together by sorting them.
comment|///
comment|/// TODO: Presumably vftables use the same algorithm.
comment|///
comment|/// TODO: Implement the MSVC 2010 name mangling scheme to avoid emitting
comment|/// duplicate vbtables with different symbols.
name|class
name|VBTableBuilder
block|{
name|public
label|:
name|VBTableBuilder
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|MostDerived
argument_list|)
expr_stmt|;
name|void
name|enumerateVBTables
parameter_list|(
name|VBTableVector
modifier|&
name|VBTables
parameter_list|)
function_decl|;
name|private
label|:
name|bool
name|hasVBPtr
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|llvm
operator|::
name|GlobalVariable
operator|*
name|getAddrOfVBTable
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|ReusingBase
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|>
name|BasePath
argument_list|)
expr_stmt|;
comment|/// Enumerates paths to bases with vbptrs.  The paths elements are compressed
comment|/// to contain only the classes necessary to form an unambiguous path.
name|void
name|findUnambiguousPaths
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|ReusingBase
parameter_list|,
name|BaseSubobject
name|CurSubobject
parameter_list|,
name|VBTablePathVector
modifier|&
name|Paths
parameter_list|)
function_decl|;
name|void
name|extendPath
parameter_list|(
name|VBTablePath
modifier|*
name|Info
parameter_list|,
name|bool
name|SecondPass
parameter_list|)
function_decl|;
name|bool
name|rebucketPaths
parameter_list|(
name|VBTablePathVector
modifier|&
name|Paths
parameter_list|,
name|size_t
name|PathsStart
parameter_list|,
name|bool
name|SecondPass
init|=
name|false
parameter_list|)
function_decl|;
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
specifier|const
name|CXXRecordDecl
modifier|*
name|MostDerived
decl_stmt|;
comment|/// Caches the layout of the most derived class.
specifier|const
name|ASTRecordLayout
modifier|&
name|DerivedLayout
decl_stmt|;
comment|/// Set of vbases to avoid re-visiting the same vbases.
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
literal|4
operator|>
name|VBasesSeen
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace CodeGen
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

end_unit

