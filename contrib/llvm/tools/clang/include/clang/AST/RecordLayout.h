begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- RecordLayout.h - Layout information for a struct/union -*- C++ -*-===//
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
comment|//  This file defines the RecordLayout interface.
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
name|LLVM_CLANG_AST_LAYOUTINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_LAYOUTINFO_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/CharUnits.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|RecordDecl
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
comment|/// ASTRecordLayout -
comment|/// This class contains layout information for one RecordDecl,
comment|/// which is a struct/union/class.  The decl represented must be a definition,
comment|/// not a forward declaration.
comment|/// This class is also used to contain layout information for one
comment|/// ObjCInterfaceDecl. FIXME - Find appropriate name.
comment|/// These objects are managed by ASTContext.
name|class
name|ASTRecordLayout
block|{
name|public
label|:
struct|struct
name|VBaseInfo
block|{
comment|/// The offset to this virtual base in the complete-object layout
comment|/// of this class.
name|CharUnits
name|VBaseOffset
decl_stmt|;
name|private
label|:
comment|/// Whether this virtual base requires a vtordisp field in the
comment|/// Microsoft ABI.  These fields are required for certain operations
comment|/// in constructors and destructors.
name|bool
name|HasVtorDisp
decl_stmt|;
name|public
label|:
name|bool
name|hasVtorDisp
argument_list|()
specifier|const
block|{
return|return
name|HasVtorDisp
return|;
block|}
name|VBaseInfo
argument_list|()
operator|:
name|HasVtorDisp
argument_list|(
argument|false
argument_list|)
block|{}
name|VBaseInfo
argument_list|(
argument|CharUnits VBaseOffset
argument_list|,
argument|bool hasVtorDisp
argument_list|)
operator|:
name|VBaseOffset
argument_list|(
name|VBaseOffset
argument_list|)
operator|,
name|HasVtorDisp
argument_list|(
argument|hasVtorDisp
argument_list|)
block|{}
block|}
struct|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|VBaseInfo
operator|>
name|VBaseOffsetsMapTy
expr_stmt|;
name|private
label|:
comment|/// Size - Size of record in characters.
name|CharUnits
name|Size
decl_stmt|;
comment|/// DataSize - Size of record in characters without tail padding.
name|CharUnits
name|DataSize
decl_stmt|;
comment|// Alignment - Alignment of record in characters.
name|CharUnits
name|Alignment
decl_stmt|;
comment|/// FieldOffsets - Array of field offsets in bits.
name|uint64_t
modifier|*
name|FieldOffsets
decl_stmt|;
comment|// FieldCount - Number of fields.
name|unsigned
name|FieldCount
decl_stmt|;
comment|/// CXXRecordLayoutInfo - Contains C++ specific layout information.
struct|struct
name|CXXRecordLayoutInfo
block|{
comment|/// NonVirtualSize - The non-virtual size (in chars) of an object, which is
comment|/// the size of the object without virtual bases.
name|CharUnits
name|NonVirtualSize
decl_stmt|;
comment|/// NonVirtualAlign - The non-virtual alignment (in chars) of an object,
comment|/// which is the alignment of the object without virtual bases.
name|CharUnits
name|NonVirtualAlign
decl_stmt|;
comment|/// SizeOfLargestEmptySubobject - The size of the largest empty subobject
comment|/// (either a base or a member). Will be zero if the class doesn't contain
comment|/// any empty subobjects.
name|CharUnits
name|SizeOfLargestEmptySubobject
decl_stmt|;
comment|/// VBPtrOffset - Virtual base table offset (Microsoft-only).
name|CharUnits
name|VBPtrOffset
decl_stmt|;
comment|/// HasOwnVFPtr - Does this class provide a virtual function table
comment|/// (vtable in Itanium, vftbl in Microsoft) that is independent from
comment|/// its base classes?
name|bool
name|HasOwnVFPtr
range|:
literal|1
decl_stmt|;
comment|/// HasVFPtr - Does this class have a vftable that could be extended by
comment|/// a derived class.  The class may have inherited this pointer from
comment|/// a primary base class.
name|bool
name|HasExtendableVFPtr
range|:
literal|1
decl_stmt|;
comment|/// AlignAfterVBases - Force appropriate alignment after virtual bases are
comment|/// laid out in MS-C++-ABI.
name|bool
name|AlignAfterVBases
range|:
literal|1
decl_stmt|;
comment|/// PrimaryBase - The primary base info for this record.
name|llvm
operator|::
name|PointerIntPair
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|PrimaryBase
expr_stmt|;
comment|/// BaseSharingVBPtr - The base we share vbptr with.
specifier|const
name|CXXRecordDecl
modifier|*
name|BaseSharingVBPtr
decl_stmt|;
comment|/// FIXME: This should really use a SmallPtrMap, once we have one in LLVM :)
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|CharUnits
operator|>
name|BaseOffsetsMapTy
expr_stmt|;
comment|/// BaseOffsets - Contains a map from base classes to their offset.
name|BaseOffsetsMapTy
name|BaseOffsets
decl_stmt|;
comment|/// VBaseOffsets - Contains a map from vbase classes to their offset.
name|VBaseOffsetsMapTy
name|VBaseOffsets
decl_stmt|;
block|}
struct|;
comment|/// CXXInfo - If the record layout is for a C++ record, this will have
comment|/// C++ specific information about the record.
name|CXXRecordLayoutInfo
modifier|*
name|CXXInfo
decl_stmt|;
name|friend
name|class
name|ASTContext
decl_stmt|;
name|ASTRecordLayout
argument_list|(
argument|const ASTContext&Ctx
argument_list|,
argument|CharUnits size
argument_list|,
argument|CharUnits alignment
argument_list|,
argument|CharUnits datasize
argument_list|,
argument|const uint64_t *fieldoffsets
argument_list|,
argument|unsigned fieldcount
argument_list|)
empty_stmt|;
comment|// Constructor for C++ records.
typedef|typedef
name|CXXRecordLayoutInfo
operator|::
name|BaseOffsetsMapTy
name|BaseOffsetsMapTy
expr_stmt|;
name|ASTRecordLayout
argument_list|(
argument|const ASTContext&Ctx
argument_list|,
argument|CharUnits size
argument_list|,
argument|CharUnits alignment
argument_list|,
argument|bool hasOwnVFPtr
argument_list|,
argument|bool hasExtendableVFPtr
argument_list|,
argument|CharUnits vbptroffset
argument_list|,
argument|CharUnits datasize
argument_list|,
argument|const uint64_t *fieldoffsets
argument_list|,
argument|unsigned fieldcount
argument_list|,
argument|CharUnits nonvirtualsize
argument_list|,
argument|CharUnits nonvirtualalign
argument_list|,
argument|CharUnits SizeOfLargestEmptySubobject
argument_list|,
argument|const CXXRecordDecl *PrimaryBase
argument_list|,
argument|bool IsPrimaryBaseVirtual
argument_list|,
argument|const CXXRecordDecl *BaseSharingVBPtr
argument_list|,
argument|bool ForceAlign
argument_list|,
argument|const BaseOffsetsMapTy& BaseOffsets
argument_list|,
argument|const VBaseOffsetsMapTy& VBaseOffsets
argument_list|)
empty_stmt|;
operator|~
name|ASTRecordLayout
argument_list|()
block|{}
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
expr_stmt|;
name|ASTRecordLayout
argument_list|(
argument|const ASTRecordLayout&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|ASTRecordLayout
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
comment|/// getAlignment - Get the record alignment in characters.
name|CharUnits
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|Alignment
return|;
block|}
comment|/// getSize - Get the record size in characters.
name|CharUnits
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
comment|/// getFieldCount - Get the number of fields in the layout.
name|unsigned
name|getFieldCount
argument_list|()
specifier|const
block|{
return|return
name|FieldCount
return|;
block|}
comment|/// getFieldOffset - Get the offset of the given field index, in
comment|/// bits.
name|uint64_t
name|getFieldOffset
argument_list|(
name|unsigned
name|FieldNo
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|FieldNo
operator|<
name|FieldCount
operator|&&
literal|"Invalid Field No"
argument_list|)
expr_stmt|;
return|return
name|FieldOffsets
index|[
name|FieldNo
index|]
return|;
block|}
comment|/// getDataSize() - Get the record data size, which is the record size
comment|/// without tail padding, in characters.
name|CharUnits
name|getDataSize
argument_list|()
specifier|const
block|{
return|return
name|DataSize
return|;
block|}
comment|/// getNonVirtualSize - Get the non-virtual size (in chars) of an object,
comment|/// which is the size of the object without virtual bases.
name|CharUnits
name|getNonVirtualSize
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|NonVirtualSize
return|;
block|}
comment|/// getNonVirtualSize - Get the non-virtual alignment (in chars) of an object,
comment|/// which is the alignment of the object without virtual bases.
name|CharUnits
name|getNonVirtualAlign
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|NonVirtualAlign
return|;
block|}
comment|/// getPrimaryBase - Get the primary base for this record.
specifier|const
name|CXXRecordDecl
operator|*
name|getPrimaryBase
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|PrimaryBase
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// isPrimaryBaseVirtual - Get whether the primary base for this record
comment|/// is virtual or not.
name|bool
name|isPrimaryBaseVirtual
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|PrimaryBase
operator|.
name|getInt
argument_list|()
return|;
block|}
comment|/// getBaseClassOffset - Get the offset, in chars, for the given base class.
name|CharUnits
name|getBaseClassOffset
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|Base
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|CXXInfo
operator|->
name|BaseOffsets
operator|.
name|count
argument_list|(
name|Base
argument_list|)
operator|&&
literal|"Did not find base!"
argument_list|)
expr_stmt|;
return|return
name|CXXInfo
operator|->
name|BaseOffsets
index|[
name|Base
index|]
return|;
block|}
comment|/// getVBaseClassOffset - Get the offset, in chars, for the given base class.
name|CharUnits
name|getVBaseClassOffset
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|VBase
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|CXXInfo
operator|->
name|VBaseOffsets
operator|.
name|count
argument_list|(
name|VBase
argument_list|)
operator|&&
literal|"Did not find base!"
argument_list|)
expr_stmt|;
return|return
name|CXXInfo
operator|->
name|VBaseOffsets
index|[
name|VBase
index|]
operator|.
name|VBaseOffset
return|;
block|}
name|CharUnits
name|getSizeOfLargestEmptySubobject
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|SizeOfLargestEmptySubobject
return|;
block|}
comment|/// hasOwnVFPtr - Does this class provide its own virtual-function
comment|/// table pointer, rather than inheriting one from a primary base
comment|/// class?  If so, it is at offset zero.
comment|///
comment|/// This implies that the ABI has no primary base class, meaning
comment|/// that it has no base classes that are suitable under the conditions
comment|/// of the ABI.
name|bool
name|hasOwnVFPtr
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|HasOwnVFPtr
return|;
block|}
comment|/// hasVFPtr - Does this class have a virtual function table pointer
comment|/// that can be extended by a derived class?  This is synonymous with
comment|/// this class having a VFPtr at offset zero.
name|bool
name|hasExtendableVFPtr
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|HasExtendableVFPtr
return|;
block|}
comment|/// hasOwnVBPtr - Does this class provide its own virtual-base
comment|/// table pointer, rather than inheriting one from a primary base
comment|/// class?
comment|///
comment|/// This implies that the ABI has no primary base class, meaning
comment|/// that it has no base classes that are suitable under the conditions
comment|/// of the ABI.
name|bool
name|hasOwnVBPtr
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|hasVBPtr
argument_list|()
operator|&&
operator|!
name|CXXInfo
operator|->
name|BaseSharingVBPtr
return|;
block|}
comment|/// hasVBPtr - Does this class have a virtual function table pointer.
name|bool
name|hasVBPtr
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
operator|!
name|CXXInfo
operator|->
name|VBPtrOffset
operator|.
name|isNegative
argument_list|()
return|;
block|}
name|bool
name|getAlignAfterVBases
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|AlignAfterVBases
return|;
block|}
comment|/// getVBPtrOffset - Get the offset for virtual base table pointer.
comment|/// This is only meaningful with the Microsoft ABI.
name|CharUnits
name|getVBPtrOffset
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|VBPtrOffset
return|;
block|}
specifier|const
name|CXXRecordDecl
operator|*
name|getBaseSharingVBPtr
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|BaseSharingVBPtr
return|;
block|}
specifier|const
name|VBaseOffsetsMapTy
operator|&
name|getVBaseOffsetsMap
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|VBaseOffsets
return|;
block|}
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

