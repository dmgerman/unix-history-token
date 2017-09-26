begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDebugPubnamesSet.h ---------------------------------*- C++ -*-===//
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
name|SymbolFileDWARF_DWARFDebugPubnamesSet_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFDebugPubnamesSet_h_
end_define

begin_include
include|#
directive|include
file|"SymbolFileDWARF.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_if
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
operator|||
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<ext/hash_map>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"lldb/Core/STLUtils.h"
end_include

begin_decl_stmt
name|class
name|DWARFDebugPubnamesSet
block|{
name|public
label|:
struct|struct
name|Header
block|{
name|uint32_t
name|length
decl_stmt|;
comment|// length of the set of entries for this compilation unit,
comment|// not including the length field itself
name|uint16_t
name|version
decl_stmt|;
comment|// The DWARF version number
name|uint32_t
name|die_offset
decl_stmt|;
comment|// compile unit .debug_info offset
name|uint32_t
name|die_length
decl_stmt|;
comment|// compile unit .debug_info length
name|Header
argument_list|()
operator|:
name|length
argument_list|(
literal|10
argument_list|)
operator|,
name|version
argument_list|(
literal|2
argument_list|)
operator|,
name|die_offset
argument_list|(
name|DW_INVALID_OFFSET
argument_list|)
operator|,
name|die_length
argument_list|(
literal|0
argument_list|)
block|{     }
block|}
struct|;
struct|struct
name|Descriptor
block|{
name|Descriptor
argument_list|()
operator|:
name|offset
argument_list|()
operator|,
name|name
argument_list|()
block|{}
name|Descriptor
argument_list|(
argument|dw_offset_t the_offset
argument_list|,
argument|const char *the_name
argument_list|)
operator|:
name|offset
argument_list|(
name|the_offset
argument_list|)
operator|,
name|name
argument_list|(
argument|the_name ? the_name :
literal|""
argument_list|)
block|{}
name|dw_offset_t
name|offset
expr_stmt|;
name|std
operator|::
name|string
name|name
expr_stmt|;
block|}
struct|;
name|DWARFDebugPubnamesSet
argument_list|()
expr_stmt|;
name|DWARFDebugPubnamesSet
argument_list|(
argument|dw_offset_t debug_aranges_offset
argument_list|,
argument|dw_offset_t cu_die_offset
argument_list|,
argument|dw_offset_t die_length
argument_list|)
empty_stmt|;
name|dw_offset_t
name|GetOffset
argument_list|()
specifier|const
block|{
return|return
name|m_offset
return|;
block|}
name|void
name|SetOffset
parameter_list|(
name|dw_offset_t
name|offset
parameter_list|)
block|{
name|m_offset
operator|=
name|offset
expr_stmt|;
block|}
name|DWARFDebugPubnamesSet
operator|::
name|Header
operator|&
name|GetHeader
argument_list|()
block|{
return|return
name|m_header
return|;
block|}
specifier|const
name|DWARFDebugPubnamesSet
operator|::
name|Header
operator|&
name|GetHeader
argument_list|()
specifier|const
block|{
return|return
name|m_header
return|;
block|}
specifier|const
name|DWARFDebugPubnamesSet
operator|::
name|Descriptor
operator|*
name|GetDescriptor
argument_list|(
argument|uint32_t i
argument_list|)
specifier|const
block|{
if|if
condition|(
name|i
operator|<
name|m_descriptors
operator|.
name|size
argument_list|()
condition|)
return|return
operator|&
name|m_descriptors
index|[
name|i
index|]
return|;
return|return
name|NULL
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|uint32_t
name|NumDescriptors
argument_list|()
specifier|const
block|{
return|return
name|m_descriptors
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|AddDescriptor
parameter_list|(
name|dw_offset_t
name|cu_rel_offset
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Clear
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|Extract
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DWARFDataExtractor
operator|&
name|debug_pubnames_data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|void
name|InitNameIndexes
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|Find
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|bool
name|ignore_case
argument_list|,
name|std
operator|::
name|vector
operator|<
name|dw_offset_t
operator|>
operator|&
name|die_offset_coll
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Find
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegularExpression
operator|&
name|regex
argument_list|,
name|std
operator|::
name|vector
operator|<
name|dw_offset_t
operator|>
operator|&
name|die_offsets
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|dw_offset_t
name|GetOffsetOfNextEntry
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Descriptor
operator|>
name|DescriptorColl
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DescriptorColl
operator|::
name|iterator
name|DescriptorIter
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DescriptorColl
operator|::
name|const_iterator
name|DescriptorConstIter
expr_stmt|;
end_typedef

begin_decl_stmt
name|dw_offset_t
name|m_offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Header
name|m_header
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
operator|||
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_typedef
typedef|typedef
name|std
operator|::
name|unordered_multimap
operator|<
specifier|const
name|char
operator|*
operator|,
name|uint32_t
operator|,
name|std
operator|::
name|hash
operator|<
specifier|const
name|char
operator|*
operator|>
operator|,
name|CStringEqualBinaryPredicate
operator|>
name|cstr_to_index_mmap
expr_stmt|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__gnu_cxx
operator|::
name|hash_multimap
operator|<
specifier|const
name|char
operator|*
operator|,
name|uint32_t
operator|,
name|__gnu_cxx
operator|::
name|hash
operator|<
specifier|const
name|char
operator|*
operator|>
operator|,
name|CStringEqualBinaryPredicate
operator|>
name|cstr_to_index_mmap
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|DescriptorColl
name|m_descriptors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mutable
name|cstr_to_index_mmap
name|m_name_to_descriptor_index
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// SymbolFileDWARF_DWARFDebugPubnamesSet_h_
end_comment

end_unit

