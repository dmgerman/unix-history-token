begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFAttribute.h ----------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARFATTRIBUTE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARFATTRIBUTE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DWARFAttribute
block|{
name|uint16_t
name|Attribute
decl_stmt|;
name|uint16_t
name|Form
decl_stmt|;
name|public
label|:
name|DWARFAttribute
argument_list|(
argument|uint16_t attr
argument_list|,
argument|uint16_t form
argument_list|)
block|:
name|Attribute
argument_list|(
name|attr
argument_list|)
operator|,
name|Form
argument_list|(
argument|form
argument_list|)
block|{}
name|uint16_t
name|getAttribute
argument_list|()
specifier|const
block|{
return|return
name|Attribute
return|;
block|}
name|uint16_t
name|getForm
argument_list|()
specifier|const
block|{
return|return
name|Form
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

