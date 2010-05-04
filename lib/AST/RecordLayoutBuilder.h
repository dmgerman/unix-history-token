begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ASTRecordLayoutBuilder.h - Helper class for building record layouts ===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_AST_RECORDLAYOUTBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_RECORDLAYOUTBUILDER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/RecordLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|ASTRecordLayout
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|ObjCImplementationDecl
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|RecordDecl
decl_stmt|;
name|class
name|ASTRecordLayoutBuilder
block|{
name|ASTContext
modifier|&
name|Context
decl_stmt|;
comment|/// Size - The current size of the record layout.
name|uint64_t
name|Size
decl_stmt|;
comment|/// Alignment - The current alignment of the record layout.
name|unsigned
name|Alignment
decl_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|FieldOffsets
expr_stmt|;
comment|/// Packed - Whether the record is packed or not.
name|bool
name|Packed
decl_stmt|;
comment|/// UnfilledBitsInLastByte - If the last field laid out was a bitfield,
comment|/// this contains the number of bits in the last byte that can be used for
comment|/// an adjacent bitfield if necessary.
name|unsigned
name|char
name|UnfilledBitsInLastByte
decl_stmt|;
comment|/// MaxFieldAlignment - The maximum allowed field alignment. This is set by
comment|/// #pragma pack.
name|unsigned
name|MaxFieldAlignment
decl_stmt|;
comment|/// DataSize - The data size of the record being laid out.
name|uint64_t
name|DataSize
decl_stmt|;
name|bool
name|IsUnion
decl_stmt|;
name|uint64_t
name|NonVirtualSize
decl_stmt|;
name|unsigned
name|NonVirtualAlignment
decl_stmt|;
comment|/// PrimaryBase - the primary base class (if one exists) of the class
comment|/// we're laying out.
name|ASTRecordLayout
operator|::
name|PrimaryBaseInfo
name|PrimaryBase
expr_stmt|;
comment|/// Bases - base classes and their offsets in the record.
name|ASTRecordLayout
operator|::
name|BaseOffsetsMapTy
name|Bases
expr_stmt|;
comment|// VBases - virtual base classes and their offsets in the record.
name|ASTRecordLayout
operator|::
name|BaseOffsetsMapTy
name|VBases
expr_stmt|;
comment|/// IndirectPrimaryBases - Virtual base classes, direct or indirect, that are
comment|/// primary base classes for some other direct or indirect base class.
name|llvm
operator|::
name|SmallSet
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
literal|32
operator|>
name|IndirectPrimaryBases
expr_stmt|;
comment|/// FirstNearlyEmptyVBase - The first nearly empty virtual base class in
comment|/// inheritance graph order. Used for determining the primary base class.
specifier|const
name|CXXRecordDecl
modifier|*
name|FirstNearlyEmptyVBase
decl_stmt|;
comment|/// VisitedVirtualBases - A set of all the visited virtual bases, used to
comment|/// avoid visiting virtual bases more than once.
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
name|VisitedVirtualBases
expr_stmt|;
comment|/// EmptyClassOffsets - A map from offsets to empty record decls.
typedef|typedef
name|std
operator|::
name|multimap
operator|<
name|uint64_t
operator|,
specifier|const
name|CXXRecordDecl
operator|*
operator|>
name|EmptyClassOffsetsTy
expr_stmt|;
name|EmptyClassOffsetsTy
name|EmptyClassOffsets
decl_stmt|;
name|ASTRecordLayoutBuilder
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
expr_stmt|;
name|void
name|Layout
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|Layout
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|Layout
parameter_list|(
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|D
parameter_list|,
specifier|const
name|ObjCImplementationDecl
modifier|*
name|Impl
parameter_list|)
function_decl|;
name|void
name|LayoutFields
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|LayoutField
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|LayoutWideBitField
parameter_list|(
name|uint64_t
name|FieldSize
parameter_list|,
name|uint64_t
name|TypeSize
parameter_list|)
function_decl|;
name|void
name|LayoutBitField
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// DeterminePrimaryBase - Determine the primary base of the given class.
name|void
name|DeterminePrimaryBase
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|void
name|SelectPrimaryVBase
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
comment|/// IdentifyPrimaryBases - Identify all virtual base classes, direct or
comment|/// indirect, that are primary base classes for some other direct or indirect
comment|/// base class.
name|void
name|IdentifyPrimaryBases
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|bool
name|IsNearlyEmpty
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
decl|const
decl_stmt|;
comment|/// LayoutNonVirtualBases - Determines the primary base class (if any) and
comment|/// lays it out. Will then proceed to lay out all non-virtual base clasess.
name|void
name|LayoutNonVirtualBases
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
comment|/// LayoutNonVirtualBase - Lays out a single non-virtual base.
name|void
name|LayoutNonVirtualBase
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|void
name|AddPrimaryVirtualBaseOffsets
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
name|uint64_t
name|Offset
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|MostDerivedClass
parameter_list|)
function_decl|;
comment|/// LayoutVirtualBases - Lays out all the virtual bases.
name|void
name|LayoutVirtualBases
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|MostDerivedClass
parameter_list|)
function_decl|;
comment|/// LayoutVirtualBase - Lays out a single virtual base.
name|void
name|LayoutVirtualBase
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
comment|/// LayoutBase - Will lay out a base and return the offset where it was
comment|/// placed, in bits.
name|uint64_t
name|LayoutBase
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
comment|/// canPlaceRecordAtOffset - Return whether a record (either a base class
comment|/// or a field) can be placed at the given offset.
comment|/// Returns false if placing the record will result in two components
comment|/// (direct or indirect) of the same type having the same offset.
name|bool
name|canPlaceRecordAtOffset
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|,
name|uint64_t
name|Offset
argument_list|)
decl|const
decl_stmt|;
comment|/// canPlaceFieldAtOffset - Return whether a field can be placed at the given
comment|/// offset.
name|bool
name|canPlaceFieldAtOffset
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|FD
parameter_list|,
name|uint64_t
name|Offset
parameter_list|)
function_decl|const;
comment|/// UpdateEmptyClassOffsets - Called after a record (either a base class
comment|/// or a field) has been placed at the given offset. Will update the
comment|/// EmptyClassOffsets map if the class is empty or has any empty bases or
comment|/// fields.
name|void
name|UpdateEmptyClassOffsets
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
comment|/// UpdateEmptyClassOffsets - Called after a field has been placed at the
comment|/// given offset.
name|void
name|UpdateEmptyClassOffsets
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|FD
parameter_list|,
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
comment|/// FinishLayout - Finalize record layout. Adjust record size based on the
comment|/// alignment.
name|void
name|FinishLayout
parameter_list|()
function_decl|;
name|void
name|UpdateAlignment
parameter_list|(
name|unsigned
name|NewAlignment
parameter_list|)
function_decl|;
name|ASTRecordLayoutBuilder
argument_list|(
specifier|const
name|ASTRecordLayoutBuilder
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|ASTRecordLayoutBuilder
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
specifier|static
specifier|const
name|ASTRecordLayout
modifier|*
name|ComputeLayout
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|,
specifier|const
name|RecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|ASTRecordLayout
modifier|*
name|ComputeLayout
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|,
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|D
parameter_list|,
specifier|const
name|ObjCImplementationDecl
modifier|*
name|Impl
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|CXXMethodDecl
modifier|*
name|ComputeKeyFunction
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
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

