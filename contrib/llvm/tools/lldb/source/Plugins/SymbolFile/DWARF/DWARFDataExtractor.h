begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFDataExtractor.h ------------------------------------*- C++ -*-===//
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
name|liblldb_DWARFDataExtractor_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DWARFDataExtractor_h_
end_define

begin_comment
comment|// Other libraries and framework includes.
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/dwarf.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/DataExtractor.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|DWARFDataExtractor
range|:
name|public
name|DataExtractor
block|{
name|public
operator|:
name|DWARFDataExtractor
argument_list|()
operator|:
name|DataExtractor
argument_list|()
block|,
name|m_is_dwarf64
argument_list|(
argument|false
argument_list|)
block|{}
name|DWARFDataExtractor
argument_list|(
argument|const DWARFDataExtractor&data
argument_list|,
argument|lldb::offset_t offset
argument_list|,
argument|lldb::offset_t length
argument_list|)
operator|:
name|DataExtractor
argument_list|(
name|data
argument_list|,
name|offset
argument_list|,
name|length
argument_list|)
block|,
name|m_is_dwarf64
argument_list|(
argument|false
argument_list|)
block|{}
name|uint64_t
name|GetDWARFInitialLength
argument_list|(
argument|lldb::offset_t *offset_ptr
argument_list|)
specifier|const
block|;
name|dw_offset_t
name|GetDWARFOffset
argument_list|(
argument|lldb::offset_t *offset_ptr
argument_list|)
specifier|const
block|;
name|size_t
name|GetDWARFSizeofInitialLength
argument_list|()
specifier|const
block|{
return|return
name|m_is_dwarf64
operator|?
literal|12
operator|:
literal|4
return|;
block|}
name|bool
name|IsDWARF64
argument_list|()
specifier|const
block|{
return|return
name|m_is_dwarf64
return|;
block|}
name|protected
operator|:
name|mutable
name|bool
name|m_is_dwarf64
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_DWARFDataExtractor_h_
end_comment

end_unit

