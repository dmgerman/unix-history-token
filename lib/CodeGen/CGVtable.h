begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CGVtable.h - Emit LLVM Code for C++ vtables ----------------------===//
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
comment|// This contains code dealing with C++ code generation of virtual tables.
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
name|CLANG_CODEGEN_CGVTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CGVTABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/GlobalVariable.h"
end_include

begin_include
include|#
directive|include
file|"GlobalDecl.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CXXRecordDecl
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenModule
decl_stmt|;
comment|/// ThunkAdjustment - Virtual and non-virtual adjustment for thunks.
name|class
name|ThunkAdjustment
block|{
name|public
label|:
name|ThunkAdjustment
argument_list|(
argument|int64_t NonVirtual
argument_list|,
argument|int64_t Virtual
argument_list|)
block|:
name|NonVirtual
argument_list|(
name|NonVirtual
argument_list|)
operator|,
name|Virtual
argument_list|(
argument|Virtual
argument_list|)
block|{ }
name|ThunkAdjustment
argument_list|()
operator|:
name|NonVirtual
argument_list|(
literal|0
argument_list|)
operator|,
name|Virtual
argument_list|(
literal|0
argument_list|)
block|{ }
comment|// isEmpty - Return whether this thunk adjustment is empty.
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|NonVirtual
operator|==
literal|0
operator|&&
name|Virtual
operator|==
literal|0
return|;
block|}
comment|/// NonVirtual - The non-virtual adjustment.
name|int64_t
name|NonVirtual
decl_stmt|;
comment|/// Virtual - The virtual adjustment.
name|int64_t
name|Virtual
decl_stmt|;
block|}
empty_stmt|;
comment|/// CovariantThunkAdjustment - Adjustment of the 'this' pointer and the
comment|/// return pointer for covariant thunks.
name|class
name|CovariantThunkAdjustment
block|{
name|public
label|:
name|CovariantThunkAdjustment
argument_list|(
specifier|const
name|ThunkAdjustment
operator|&
name|ThisAdjustment
argument_list|,
specifier|const
name|ThunkAdjustment
operator|&
name|ReturnAdjustment
argument_list|)
operator|:
name|ThisAdjustment
argument_list|(
name|ThisAdjustment
argument_list|)
operator|,
name|ReturnAdjustment
argument_list|(
argument|ReturnAdjustment
argument_list|)
block|{ }
name|CovariantThunkAdjustment
argument_list|()
block|{ }
name|ThunkAdjustment
name|ThisAdjustment
expr_stmt|;
name|ThunkAdjustment
name|ReturnAdjustment
decl_stmt|;
block|}
empty_stmt|;
comment|// BaseSubobject - Uniquely identifies a direct or indirect base class.
comment|// Stores both the base class decl and the offset from the most derived class to
comment|// the base class.
name|class
name|BaseSubobject
block|{
comment|/// Base - The base class declaration.
specifier|const
name|CXXRecordDecl
modifier|*
name|Base
decl_stmt|;
comment|/// BaseOffset - The offset from the most derived class to the base class.
name|uint64_t
name|BaseOffset
decl_stmt|;
name|public
label|:
name|BaseSubobject
argument_list|(
argument|const CXXRecordDecl *Base
argument_list|,
argument|uint64_t BaseOffset
argument_list|)
block|:
name|Base
argument_list|(
name|Base
argument_list|)
operator|,
name|BaseOffset
argument_list|(
argument|BaseOffset
argument_list|)
block|{ }
comment|/// getBase - Returns the base class declaration.
specifier|const
name|CXXRecordDecl
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|Base
return|;
block|}
comment|/// getBaseOffset - Returns the base class offset.
name|uint64_t
name|getBaseOffset
argument_list|()
specifier|const
block|{
return|return
name|BaseOffset
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|BaseSubobject
operator|&
name|LHS
operator|,
specifier|const
name|BaseSubobject
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Base
operator|==
name|RHS
operator|.
name|Base
operator|&&
name|LHS
operator|.
name|BaseOffset
operator|==
name|RHS
operator|.
name|BaseOffset
return|;
block|}
block|}
empty_stmt|;
block|}
comment|// end namespace CodeGen
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|clang
operator|::
name|CodeGen
operator|::
name|BaseSubobject
operator|>
block|{
specifier|static
name|clang
operator|::
name|CodeGen
operator|::
name|BaseSubobject
name|getEmptyKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|CodeGen
operator|::
name|BaseSubobject
argument_list|(
name|DenseMapInfo
operator|<
specifier|const
name|clang
operator|::
name|CXXRecordDecl
operator|*
operator|>
operator|::
name|getEmptyKey
argument_list|()
argument_list|,
name|DenseMapInfo
operator|<
name|uint64_t
operator|>
operator|::
name|getEmptyKey
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|clang
operator|::
name|CodeGen
operator|::
name|BaseSubobject
name|getTombstoneKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|CodeGen
operator|::
name|BaseSubobject
argument_list|(
name|DenseMapInfo
operator|<
specifier|const
name|clang
operator|::
name|CXXRecordDecl
operator|*
operator|>
operator|::
name|getTombstoneKey
argument_list|()
argument_list|,
name|DenseMapInfo
operator|<
name|uint64_t
operator|>
operator|::
name|getTombstoneKey
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|const clang::CodeGen::BaseSubobject&Base
argument_list|)
block|{
return|return
name|DenseMapInfo
operator|<
specifier|const
name|clang
operator|::
name|CXXRecordDecl
operator|*
operator|>
operator|::
name|getHashValue
argument_list|(
name|Base
operator|.
name|getBase
argument_list|()
argument_list|)
operator|^
name|DenseMapInfo
operator|<
name|uint64_t
operator|>
operator|::
name|getHashValue
argument_list|(
name|Base
operator|.
name|getBaseOffset
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|const clang::CodeGen::BaseSubobject&LHS
argument_list|,
argument|const clang::CodeGen::BaseSubobject&RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
expr|}
block|;
comment|// It's OK to treat BaseSubobject as a POD type.
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|clang
operator|::
name|CodeGen
operator|::
name|BaseSubobject
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
block|;  }
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
name|class
name|CGVtableInfo
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|GlobalDecl
operator|,
name|ThunkAdjustment
operator|>
expr|>
name|AdjustmentVectorTy
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|uint64_t
operator|>
name|CtorVtable_t
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|CtorVtable_t
operator|,
name|int64_t
operator|>
name|AddrSubMap_t
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|AddrSubMap_t
operator|*
operator|>
name|AddrMap_t
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|AddrMap_t
operator|*
operator|>
name|AddressPoints
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|BaseSubobject
operator|,
name|uint64_t
operator|>
name|AddressPointsMapTy
expr_stmt|;
name|private
label|:
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
comment|/// MethodVtableIndices - Contains the index (relative to the vtable address
comment|/// point) where the function pointer for a virtual function is stored.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|GlobalDecl
operator|,
name|int64_t
operator|>
name|MethodVtableIndicesTy
expr_stmt|;
name|MethodVtableIndicesTy
name|MethodVtableIndices
decl_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
specifier|const
name|CXXRecordDecl
operator|*
operator|>
name|ClassPairTy
expr_stmt|;
comment|/// VirtualBaseClassIndicies - Contains the index into the vtable where the
comment|/// offsets for virtual bases of a class are stored.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|ClassPairTy
operator|,
name|int64_t
operator|>
name|VirtualBaseClassIndiciesTy
expr_stmt|;
name|VirtualBaseClassIndiciesTy
name|VirtualBaseClassIndicies
decl_stmt|;
comment|/// Vtables - All the vtables which have been defined.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|llvm
operator|::
name|GlobalVariable
operator|*
operator|>
name|Vtables
expr_stmt|;
comment|/// NumVirtualFunctionPointers - Contains the number of virtual function
comment|/// pointers in the vtable for a given record decl.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|uint64_t
operator|>
name|NumVirtualFunctionPointers
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|GlobalDecl
operator|,
name|AdjustmentVectorTy
operator|>
name|SavedAdjustmentsTy
expr_stmt|;
name|SavedAdjustmentsTy
name|SavedAdjustments
decl_stmt|;
name|llvm
operator|::
name|DenseSet
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|>
name|SavedAdjustmentRecords
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|ClassPairTy
operator|,
name|uint64_t
operator|>
name|SubVTTIndiciesTy
expr_stmt|;
name|SubVTTIndiciesTy
name|SubVTTIndicies
decl_stmt|;
comment|/// getNumVirtualFunctionPointers - Return the number of virtual function
comment|/// pointers in the vtable for a given record decl.
name|uint64_t
name|getNumVirtualFunctionPointers
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|void
name|ComputeMethodVtableIndices
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
comment|/// GenerateClassData - Generate all the class data requires to be generated
comment|/// upon definition of a KeyFunction.  This includes the vtable, the
comment|/// rtti data structure and the VTT.
comment|///
comment|/// \param Linkage - The desired linkage of the vtable, the RTTI and the VTT.
name|void
name|GenerateClassData
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|::
name|LinkageTypes
name|Linkage
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
decl_stmt|;
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GenerateVtable
argument_list|(
argument|llvm::GlobalVariable::LinkageTypes Linkage
argument_list|,
argument|bool GenerateDefinition
argument_list|,
argument|const CXXRecordDecl *LayoutClass
argument_list|,
argument|const CXXRecordDecl *RD
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|AddressPointsMapTy& AddressPoints
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GenerateVTT
argument_list|(
argument|llvm::GlobalVariable::LinkageTypes Linkage
argument_list|,
argument|bool GenerateDefinition
argument_list|,
argument|const CXXRecordDecl *RD
argument_list|)
expr_stmt|;
name|public
label|:
name|CGVtableInfo
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
operator|:
name|CGM
argument_list|(
argument|CGM
argument_list|)
block|{ }
comment|/// needsVTTParameter - Return whether the given global decl needs a VTT
comment|/// parameter, which it does if it's a base constructor or destructor with
comment|/// virtual bases.
specifier|static
name|bool
name|needsVTTParameter
argument_list|(
argument|GlobalDecl GD
argument_list|)
expr_stmt|;
comment|/// getSubVTTIndex - Return the index of the sub-VTT for the base class of the
comment|/// given record decl.
name|uint64_t
name|getSubVTTIndex
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|Base
parameter_list|)
function_decl|;
comment|/// getMethodVtableIndex - Return the index (relative to the vtable address
comment|/// point) where the function pointer for the given virtual function is
comment|/// stored.
name|uint64_t
name|getMethodVtableIndex
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
comment|/// getVirtualBaseOffsetIndex - Return the index (relative to the vtable
comment|/// address point) where the offset of the virtual base that contains the
comment|/// given Base is stored, otherwise, if no virtual base contains the given
comment|/// class, return 0.  Base must be a virtual base class or an unambigious
comment|/// base.
name|int64_t
name|getVirtualBaseOffsetIndex
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|VBase
parameter_list|)
function_decl|;
name|AdjustmentVectorTy
modifier|*
name|getAdjustments
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
comment|/// getVtableAddressPoint - returns the address point of the vtable for the
comment|/// given record decl.
comment|/// FIXME: This should return a list of address points.
name|uint64_t
name|getVtableAddressPoint
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
name|getVtable
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
expr_stmt|;
comment|/// CtorVtableInfo - Information about a constructor vtable.
struct|struct
name|CtorVtableInfo
block|{
comment|/// Vtable - The vtable itself.
name|llvm
operator|::
name|GlobalVariable
operator|*
name|Vtable
expr_stmt|;
comment|/// AddressPoints - The address points in this constructor vtable.
name|AddressPointsMapTy
name|AddressPoints
decl_stmt|;
name|CtorVtableInfo
argument_list|()
operator|:
name|Vtable
argument_list|(
literal|0
argument_list|)
block|{ }
block|}
struct|;
name|CtorVtableInfo
name|getCtorVtable
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
specifier|const
name|BaseSubobject
modifier|&
name|Base
parameter_list|)
function_decl|;
name|llvm
operator|::
name|GlobalVariable
operator|*
name|getVTT
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
expr_stmt|;
name|void
name|MaybeEmitVtable
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace CodeGen
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

