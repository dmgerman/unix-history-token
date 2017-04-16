begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFDebugFrame.h - Parsing of .debug_frame --------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARF_DWARFDEBUGFRAME_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARF_DWARFDEBUGFRAME_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataExtractor.h"
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
name|class
name|FrameEntry
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// \brief A parsed .debug_frame or .eh_frame section
comment|///
name|class
name|DWARFDebugFrame
block|{
comment|// True if this is parsing an eh_frame section.
name|bool
name|IsEH
decl_stmt|;
name|public
label|:
name|DWARFDebugFrame
argument_list|(
argument|bool IsEH
argument_list|)
empty_stmt|;
operator|~
name|DWARFDebugFrame
argument_list|()
expr_stmt|;
comment|/// \brief Dump the section data into the given stream.
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Parse the section from raw data.
comment|/// data is assumed to be pointing to the beginning of the section.
name|void
name|parse
parameter_list|(
name|DataExtractor
name|Data
parameter_list|)
function_decl|;
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|FrameEntry
operator|>>
name|Entries
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_DWARF_DWARFDEBUGFRAME_H
end_comment

end_unit

