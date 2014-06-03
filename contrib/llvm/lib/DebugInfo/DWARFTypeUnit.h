begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFTypeUnit.h -----------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARFTYPEUNIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARFTYPEUNIT_H
end_define

begin_include
include|#
directive|include
file|"DWARFUnit.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DWARFTypeUnit
range|:
name|public
name|DWARFUnit
block|{
name|private
operator|:
name|uint64_t
name|TypeHash
block|;
name|uint32_t
name|TypeOffset
block|;
name|public
operator|:
name|DWARFTypeUnit
argument_list|(
argument|const DWARFDebugAbbrev *DA
argument_list|,
argument|StringRef IS
argument_list|,
argument|StringRef AS
argument_list|,
argument|StringRef RS
argument_list|,
argument|StringRef SS
argument_list|,
argument|StringRef SOS
argument_list|,
argument|StringRef AOS
argument_list|,
argument|const RelocAddrMap *M
argument_list|,
argument|bool LE
argument_list|)
operator|:
name|DWARFUnit
argument_list|(
argument|DA
argument_list|,
argument|IS
argument_list|,
argument|AS
argument_list|,
argument|RS
argument_list|,
argument|SS
argument_list|,
argument|SOS
argument_list|,
argument|AOS
argument_list|,
argument|M
argument_list|,
argument|LE
argument_list|)
block|{}
name|uint32_t
name|getSize
argument_list|()
specifier|const
name|LLVM_OVERRIDE
block|{
return|return
name|DWARFUnit
operator|::
name|getSize
argument_list|()
operator|+
literal|12
return|;
block|}
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|protected
operator|:
name|bool
name|extractImpl
argument_list|(
argument|DataExtractor debug_info
argument_list|,
argument|uint32_t *offset_ptr
argument_list|)
name|LLVM_OVERRIDE
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

