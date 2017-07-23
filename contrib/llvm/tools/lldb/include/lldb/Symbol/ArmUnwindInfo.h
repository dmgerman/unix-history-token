begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ArmUnwindInfo.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_ArmUnwindInfo_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ArmUnwindInfo_h_
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/Core/RangeMap.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_comment
comment|/*  * Unwind information reader and parser for the ARM exception handling ABI  *  * Implemented based on:  *     Exception Handling ABI for the ARM Architecture  *     Document number: ARM IHI 0038A (current through ABI r2.09)  *     Date of Issue: 25th January 2007, reissued 30th November 2012  *     http://infocenter.arm.com/help/topic/com.arm.doc.ihi0038a/IHI0038A_ehabi.pdf  */
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ArmUnwindInfo
block|{
name|public
label|:
name|ArmUnwindInfo
argument_list|(
specifier|const
name|ObjectFile
operator|&
name|objfile
argument_list|,
name|lldb
operator|::
name|SectionSP
operator|&
name|arm_exidx
argument_list|,
name|lldb
operator|::
name|SectionSP
operator|&
name|arm_extab
argument_list|)
expr_stmt|;
operator|~
name|ArmUnwindInfo
argument_list|()
expr_stmt|;
name|bool
name|GetUnwindPlan
parameter_list|(
name|Target
modifier|&
name|target
parameter_list|,
specifier|const
name|Address
modifier|&
name|addr
parameter_list|,
name|UnwindPlan
modifier|&
name|unwind_plan
parameter_list|)
function_decl|;
name|private
label|:
struct|struct
name|ArmExidxEntry
block|{
name|ArmExidxEntry
argument_list|(
argument|uint32_t f
argument_list|,
argument|lldb::addr_t a
argument_list|,
argument|uint32_t d
argument_list|)
empty_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ArmExidxEntry
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|uint32_t
name|file_address
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|address
expr_stmt|;
name|uint32_t
name|data
decl_stmt|;
block|}
struct|;
specifier|const
name|uint8_t
modifier|*
name|GetExceptionHandlingTableEntry
parameter_list|(
specifier|const
name|Address
modifier|&
name|addr
parameter_list|)
function_decl|;
name|uint8_t
name|GetByteAtOffset
argument_list|(
specifier|const
name|uint32_t
operator|*
name|data
argument_list|,
name|uint16_t
name|offset
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|GetULEB128
argument_list|(
specifier|const
name|uint32_t
operator|*
name|data
argument_list|,
name|uint16_t
operator|&
name|offset
argument_list|,
name|uint16_t
name|max_offset
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|lldb
operator|::
name|ByteOrder
name|m_byte_order
expr_stmt|;
name|lldb
operator|::
name|SectionSP
name|m_arm_exidx_sp
expr_stmt|;
comment|// .ARM.exidx section
name|lldb
operator|::
name|SectionSP
name|m_arm_extab_sp
expr_stmt|;
comment|// .ARM.extab section
name|DataExtractor
name|m_arm_exidx_data
decl_stmt|;
comment|// .ARM.exidx section data
name|DataExtractor
name|m_arm_extab_data
decl_stmt|;
comment|// .ARM.extab section data
name|std
operator|::
name|vector
operator|<
name|ArmExidxEntry
operator|>
name|m_exidx_entries
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ArmUnwindInfo_h_
end_comment

end_unit

