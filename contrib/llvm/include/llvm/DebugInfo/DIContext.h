begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DIContext.h ---------------------------------------------*- C++ -*-===//
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
comment|// This file defines DIContext, an abstract data structure that holds
end_comment

begin_comment
comment|// debug information data.
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
name|LLVM_DEBUGINFO_DICONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DICONTEXT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
comment|/// DILineInfo - a format-neutral container for source line information.
name|class
name|DILineInfo
block|{
specifier|const
name|char
modifier|*
name|FileName
decl_stmt|;
name|uint32_t
name|Line
decl_stmt|;
name|uint32_t
name|Column
decl_stmt|;
name|public
label|:
name|DILineInfo
argument_list|()
operator|:
name|FileName
argument_list|(
literal|"<invalid>"
argument_list|)
operator|,
name|Line
argument_list|(
literal|0
argument_list|)
operator|,
name|Column
argument_list|(
literal|0
argument_list|)
block|{}
name|DILineInfo
argument_list|(
argument|const char *fileName
argument_list|,
argument|uint32_t line
argument_list|,
argument|uint32_t column
argument_list|)
operator|:
name|FileName
argument_list|(
name|fileName
argument_list|)
operator|,
name|Line
argument_list|(
name|line
argument_list|)
operator|,
name|Column
argument_list|(
argument|column
argument_list|)
block|{}
specifier|const
name|char
operator|*
name|getFileName
argument_list|()
specifier|const
block|{
return|return
name|FileName
return|;
block|}
name|uint32_t
name|getLine
argument_list|()
specifier|const
block|{
return|return
name|Line
return|;
block|}
name|uint32_t
name|getColumn
argument_list|()
specifier|const
block|{
return|return
name|Column
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|DILineInfo
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Line
operator|==
name|RHS
operator|.
name|Line
operator|&&
name|Column
operator|==
name|RHS
operator|.
name|Column
operator|&&
name|std
operator|::
name|strcmp
argument_list|(
name|FileName
argument_list|,
name|RHS
operator|.
name|FileName
argument_list|)
operator|==
literal|0
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|DILineInfo
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
block|}
empty_stmt|;
name|class
name|DIContext
block|{
name|public
label|:
name|virtual
operator|~
name|DIContext
argument_list|()
expr_stmt|;
comment|/// getDWARFContext - get a context for binary DWARF data.
specifier|static
name|DIContext
modifier|*
name|getDWARFContext
parameter_list|(
name|bool
name|isLittleEndian
parameter_list|,
name|StringRef
name|infoSection
parameter_list|,
name|StringRef
name|abbrevSection
parameter_list|,
name|StringRef
name|aRangeSection
init|=
name|StringRef
argument_list|()
parameter_list|,
name|StringRef
name|lineSection
init|=
name|StringRef
argument_list|()
parameter_list|,
name|StringRef
name|stringSection
init|=
name|StringRef
argument_list|()
parameter_list|)
function_decl|;
name|virtual
name|void
name|dump
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|DILineInfo
name|getLineInfoForAddress
parameter_list|(
name|uint64_t
name|address
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

