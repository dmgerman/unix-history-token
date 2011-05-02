begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CGVTables.h - Emit LLVM Code for C++ vtables -----------*- C++ -*-===//
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
file|"llvm/GlobalVariable.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/ABI.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/CharUnits.h"
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
name|CharUnits
name|BaseOffset
decl_stmt|;
name|public
label|:
name|BaseSubobject
argument_list|(
argument|const CXXRecordDecl *Base
argument_list|,
argument|CharUnits BaseOffset
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
name|CharUnits
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
name|clang
operator|::
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
name|DenseMapInfo
operator|<
name|int64_t
operator|>
operator|::
name|getEmptyKey
argument_list|()
argument_list|)
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
name|clang
operator|::
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
name|DenseMapInfo
operator|<
name|int64_t
operator|>
operator|::
name|getTombstoneKey
argument_list|()
argument_list|)
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
name|int64_t
operator|>
operator|::
name|getHashValue
argument_list|(
name|Base
operator|.
name|getBaseOffset
argument_list|()
operator|.
name|getQuantity
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
name|CodeGenVTables
block|{
name|CodeGenModule
operator|&
name|CGM
block|;
comment|/// MethodVTableIndices - Contains the index (relative to the vtable address
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
name|MethodVTableIndicesTy
expr_stmt|;
name|MethodVTableIndicesTy
name|MethodVTableIndices
block|;
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
comment|/// VirtualBaseClassOffsetOffsets - Contains the vtable offset (relative to
comment|/// the address point) in chars where the offsets for virtual bases of a class
comment|/// are stored.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|ClassPairTy
operator|,
name|CharUnits
operator|>
name|VirtualBaseClassOffsetOffsetsMapTy
expr_stmt|;
name|VirtualBaseClassOffsetOffsetsMapTy
name|VirtualBaseClassOffsetOffsets
expr_stmt|;
comment|/// VTables - All the vtables which have been defined.
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
name|VTables
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
name|SmallVector
operator|<
name|ThunkInfo
operator|,
literal|1
operator|>
name|ThunkInfoVectorTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXMethodDecl
operator|*
operator|,
name|ThunkInfoVectorTy
operator|>
name|ThunksMapTy
expr_stmt|;
comment|/// Thunks - Contains all thunks that a given method decl will need.
name|ThunksMapTy
name|Thunks
decl_stmt|;
comment|// The layout entry and a bool indicating whether we've actually emitted
comment|// the vtable.
typedef|typedef
name|llvm
operator|::
name|PointerIntPair
operator|<
name|uint64_t
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|VTableLayoutData
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
name|VTableLayoutData
operator|>
name|VTableLayoutMapTy
expr_stmt|;
comment|/// VTableLayoutMap - Stores the vtable layout for all record decls.
comment|/// The layout is stored as an array of 64-bit integers, where the first
comment|/// integer is the number of vtable entries in the layout, and the subsequent
comment|/// integers are the vtable components.
name|VTableLayoutMapTy
name|VTableLayoutMap
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
name|BaseSubobject
operator|>
name|BaseSubobjectPairTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|BaseSubobjectPairTy
operator|,
name|uint64_t
operator|>
name|AddressPointsMapTy
expr_stmt|;
comment|/// Address points - Address points for all vtables.
name|AddressPointsMapTy
name|AddressPoints
decl_stmt|;
comment|/// VTableAddressPointsMapTy - Address points for a single vtable.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|BaseSubobject
operator|,
name|uint64_t
operator|>
name|VTableAddressPointsMapTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|ThunkInfo
operator|>
operator|,
literal|1
operator|>
name|VTableThunksTy
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
name|VTableThunksTy
operator|>
name|VTableThunksMapTy
expr_stmt|;
comment|/// VTableThunksMap - Contains thunks needed by vtables.
name|VTableThunksMapTy
name|VTableThunksMap
decl_stmt|;
name|uint64_t
name|getNumVTableComponents
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|VTableLayoutMap
operator|.
name|count
argument_list|(
name|RD
argument_list|)
operator|&&
literal|"No vtable layout for this class!"
argument_list|)
expr_stmt|;
return|return
name|VTableLayoutMap
operator|.
name|lookup
argument_list|(
name|RD
argument_list|)
operator|.
name|getPointer
argument_list|()
index|[
literal|0
index|]
return|;
block|}
specifier|const
name|uint64_t
modifier|*
name|getVTableComponentsData
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|VTableLayoutMap
operator|.
name|count
argument_list|(
name|RD
argument_list|)
operator|&&
literal|"No vtable layout for this class!"
argument_list|)
expr_stmt|;
name|uint64_t
modifier|*
name|Components
init|=
name|VTableLayoutMap
operator|.
name|lookup
argument_list|(
name|RD
argument_list|)
operator|.
name|getPointer
argument_list|()
decl_stmt|;
return|return
operator|&
name|Components
index|[
literal|1
index|]
return|;
block|}
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|BaseSubobjectPairTy
operator|,
name|uint64_t
operator|>
name|SubVTTIndiciesMapTy
expr_stmt|;
comment|/// SubVTTIndicies - Contains indices into the various sub-VTTs.
name|SubVTTIndiciesMapTy
name|SubVTTIndicies
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|BaseSubobjectPairTy
operator|,
name|uint64_t
operator|>
name|SecondaryVirtualPointerIndicesMapTy
expr_stmt|;
comment|/// SecondaryVirtualPointerIndices - Contains the secondary virtual pointer
comment|/// indices.
name|SecondaryVirtualPointerIndicesMapTy
name|SecondaryVirtualPointerIndices
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
name|ComputeMethodVTableIndices
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
comment|/// EmitThunk - Emit a single thunk.
name|void
name|EmitThunk
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|,
specifier|const
name|ThunkInfo
modifier|&
name|Thunk
parameter_list|,
name|bool
name|UseAvailableExternallyLinkage
parameter_list|)
function_decl|;
comment|/// MaybeEmitThunkAvailableExternally - Try to emit the given thunk with
comment|/// available_externally linkage to allow for inlining of thunks.
comment|/// This will be done iff optimizations are enabled and the member function
comment|/// doesn't contain any incomplete types.
name|void
name|MaybeEmitThunkAvailableExternally
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|,
specifier|const
name|ThunkInfo
modifier|&
name|Thunk
parameter_list|)
function_decl|;
comment|/// ComputeVTableRelatedInformation - Compute and store all vtable related
comment|/// information (vtable layout, vbase offset offsets, thunks etc) for the
comment|/// given record decl.
name|void
name|ComputeVTableRelatedInformation
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
name|bool
name|VTableRequired
parameter_list|)
function_decl|;
comment|/// CreateVTableInitializer - Create a vtable initializer for the given record
comment|/// decl.
comment|/// \param Components - The vtable components; this is really an array of
comment|/// VTableComponents.
name|llvm
operator|::
name|Constant
operator|*
name|CreateVTableInitializer
argument_list|(
argument|const CXXRecordDecl *RD
argument_list|,
argument|const uint64_t *Components
argument_list|,
argument|unsigned NumComponents
argument_list|,
argument|const VTableThunksTy&VTableThunks
argument_list|)
expr_stmt|;
name|public
label|:
name|CodeGenVTables
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
comment|/// \brief True if the VTable of this record must be emitted in the
comment|/// translation unit.
name|bool
name|ShouldEmitVTableInThisTU
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
expr_stmt|;
comment|/// needsVTTParameter - Return whether the given global decl needs a VTT
comment|/// parameter, which it does if it's a base constructor or destructor with
comment|/// virtual bases.
specifier|static
name|bool
name|needsVTTParameter
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
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
name|BaseSubobject
name|Base
parameter_list|)
function_decl|;
comment|/// getSecondaryVirtualPointerIndex - Return the index in the VTT where the
comment|/// virtual pointer for the given subobject is located.
name|uint64_t
name|getSecondaryVirtualPointerIndex
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
name|BaseSubobject
name|Base
parameter_list|)
function_decl|;
comment|/// getMethodVTableIndex - Return the index (relative to the vtable address
comment|/// point) where the function pointer for the given virtual function is
comment|/// stored.
name|uint64_t
name|getMethodVTableIndex
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
comment|/// getVirtualBaseOffsetOffset - Return the offset in chars (relative to the
comment|/// vtable address point) where the offset of the virtual base that contains
comment|/// the given base is stored, otherwise, if no virtual base contains the given
comment|/// class, return 0.  Base must be a virtual base class or an unambigious
comment|/// base.
name|CharUnits
name|getVirtualBaseOffsetOffset
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
comment|/// getAddressPoint - Get the address point of the given subobject in the
comment|/// class decl.
name|uint64_t
name|getAddressPoint
parameter_list|(
name|BaseSubobject
name|Base
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
comment|/// GetAddrOfVTable - Get the address of the vtable for the given record decl.
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GetAddrOfVTable
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
expr_stmt|;
comment|/// EmitVTableDefinition - Emit the definition of the given vtable.
name|void
name|EmitVTableDefinition
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|VTable
argument_list|,
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
comment|/// GenerateConstructionVTable - Generate a construction vtable for the given
comment|/// base subobject.
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GenerateConstructionVTable
argument_list|(
argument|const CXXRecordDecl *RD
argument_list|,
argument|const BaseSubobject&Base
argument_list|,
argument|bool BaseIsVirtual
argument_list|,
argument|llvm::GlobalVariable::LinkageTypes Linkage
argument_list|,
argument|VTableAddressPointsMapTy& AddressPoints
argument_list|)
expr_stmt|;
comment|/// GetAddrOfVTable - Get the address of the VTT for the given record decl.
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GetAddrOfVTT
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
expr_stmt|;
comment|/// EmitVTTDefinition - Emit the definition of the given vtable.
name|void
name|EmitVTTDefinition
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|VTT
argument_list|,
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
comment|/// EmitThunks - Emit the associated thunks for the given global decl.
name|void
name|EmitThunks
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
comment|/// GenerateClassData - Generate all the class data required to be generated
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

