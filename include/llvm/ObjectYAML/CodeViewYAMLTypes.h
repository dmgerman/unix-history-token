begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- CodeViewYAMLTypes.h - CodeView YAMLIO Type implementation --*- C++ -*-==//
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
comment|// This file defines classes for handling the YAML representation of CodeView
end_comment

begin_comment
comment|// Debug Info.
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
name|LLVM_OBJECTYAML_CODEVIEWYAMLTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECTYAML_CODEVIEWYAMLTYPES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/YAMLTraits.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|TypeTableBuilder
decl_stmt|;
block|}
comment|// end namespace codeview
name|namespace
name|CodeViewYAML
block|{
name|namespace
name|detail
block|{
struct_decl|struct
name|LeafRecordBase
struct_decl|;
struct_decl|struct
name|MemberRecordBase
struct_decl|;
block|}
comment|// end namespace detail
struct|struct
name|MemberRecord
block|{
name|std
operator|::
name|shared_ptr
operator|<
name|detail
operator|::
name|MemberRecordBase
operator|>
name|Member
expr_stmt|;
block|}
struct|;
struct|struct
name|LeafRecord
block|{
name|std
operator|::
name|shared_ptr
operator|<
name|detail
operator|::
name|LeafRecordBase
operator|>
name|Leaf
expr_stmt|;
name|codeview
operator|::
name|CVType
name|toCodeViewRecord
argument_list|(
argument|BumpPtrAllocator&Allocator
argument_list|)
specifier|const
expr_stmt|;
name|codeview
operator|::
name|CVType
name|toCodeViewRecord
argument_list|(
argument|codeview::TypeTableBuilder&TS
argument_list|)
specifier|const
expr_stmt|;
specifier|static
name|Expected
operator|<
name|LeafRecord
operator|>
name|fromCodeViewRecord
argument_list|(
argument|codeview::CVType Type
argument_list|)
expr_stmt|;
block|}
struct|;
name|std
operator|::
name|vector
operator|<
name|LeafRecord
operator|>
name|fromDebugT
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|DebugT
argument_list|)
expr_stmt|;
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|toDebugT
argument_list|(
name|ArrayRef
operator|<
name|LeafRecord
operator|>
argument_list|,
name|BumpPtrAllocator
operator|&
name|Alloc
argument_list|)
expr_stmt|;
block|}
comment|// end namespace CodeViewYAML
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_macro
name|LLVM_YAML_DECLARE_MAPPING_TRAITS
argument_list|(
argument|CodeViewYAML::LeafRecord
argument_list|)
end_macro

begin_macro
name|LLVM_YAML_DECLARE_MAPPING_TRAITS
argument_list|(
argument|CodeViewYAML::MemberRecord
argument_list|)
end_macro

begin_macro
name|LLVM_YAML_IS_SEQUENCE_VECTOR
argument_list|(
argument|CodeViewYAML::LeafRecord
argument_list|)
end_macro

begin_macro
name|LLVM_YAML_IS_SEQUENCE_VECTOR
argument_list|(
argument|CodeViewYAML::MemberRecord
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_OBJECTYAML_CODEVIEWYAMLTYPES_H
end_comment

end_unit

