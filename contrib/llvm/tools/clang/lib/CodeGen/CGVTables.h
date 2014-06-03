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
file|"clang/AST/BaseSubobject.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/CharUnits.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/GlobalDecl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/VTableBuilder.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/ABI.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalVariable.h"
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
name|class
name|CodeGenVTables
block|{
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
comment|// FIXME: Consider moving ItaniumVTContext and MicrosoftVTContext into
comment|// respective CXXABI classes?
name|ItaniumVTableContext
name|ItaniumVTContext
decl_stmt|;
name|OwningPtr
operator|<
name|MicrosoftVTableContext
operator|>
name|MicrosoftVTContext
expr_stmt|;
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
comment|/// emitThunk - Emit a single thunk.
name|void
name|emitThunk
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
name|ForVTable
parameter_list|)
function_decl|;
comment|/// maybeEmitThunkForVTable - Emit the given thunk for the vtable if needed by
comment|/// the ABI.
name|void
name|maybeEmitThunkForVTable
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
name|public
label|:
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
argument|const VTableComponent *Components
argument_list|,
argument|unsigned NumComponents
argument_list|,
argument|const VTableLayout::VTableThunkTy *VTableThunks
argument_list|,
argument|unsigned NumVTableThunks
argument_list|)
expr_stmt|;
name|CodeGenVTables
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
expr_stmt|;
name|ItaniumVTableContext
modifier|&
name|getItaniumVTableContext
parameter_list|()
block|{
return|return
name|ItaniumVTContext
return|;
block|}
name|MicrosoftVTableContext
modifier|&
name|getMicrosoftVTableContext
parameter_list|()
block|{
return|return
operator|*
name|MicrosoftVTContext
operator|.
name|get
argument_list|()
return|;
block|}
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
comment|/// GenerateClassData - Generate all the class data required to be
comment|/// generated upon definition of a KeyFunction.  This includes the
comment|/// vtable, the RTTI data structure (if RTTI is enabled) and the VTT
comment|/// (if the class has virtual bases).
name|void
name|GenerateClassData
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|bool
name|isVTableExternal
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
comment|// end namespace CodeGen
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

