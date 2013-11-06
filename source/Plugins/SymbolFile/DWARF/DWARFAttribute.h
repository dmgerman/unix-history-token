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
name|SymbolFileDWARF_DWARFAttribute_h_
end_ifndef

begin_define
define|#
directive|define
name|SymbolFileDWARF_DWARFAttribute_h_
end_define

begin_include
include|#
directive|include
file|"DWARFDefines.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|class
name|DWARFAttribute
block|{
name|public
label|:
name|DWARFAttribute
argument_list|(
argument|dw_attr_t attr
argument_list|,
argument|dw_form_t form
argument_list|)
block|:
name|m_attr_form
argument_list|(
argument|attr<<
literal|16
argument|| form
argument_list|)
block|{     }
name|void
name|set
parameter_list|(
name|dw_attr_t
name|attr
parameter_list|,
name|dw_form_t
name|form
parameter_list|)
block|{
name|m_attr_form
operator|=
operator|(
name|attr
operator|<<
literal|16
operator|)
operator||
name|form
expr_stmt|;
block|}
name|void
name|set_attr
parameter_list|(
name|dw_attr_t
name|attr
parameter_list|)
block|{
name|m_attr_form
operator|=
operator|(
name|m_attr_form
operator|&
literal|0x0000ffffu
operator|)
operator||
operator|(
name|attr
operator|<<
literal|16
operator|)
expr_stmt|;
block|}
name|void
name|set_form
parameter_list|(
name|dw_form_t
name|form
parameter_list|)
block|{
name|m_attr_form
operator|=
operator|(
name|m_attr_form
operator|&
literal|0xffff0000u
operator|)
operator||
name|form
expr_stmt|;
block|}
name|dw_attr_t
name|get_attr
argument_list|()
specifier|const
block|{
return|return
name|m_attr_form
operator|>>
literal|16
return|;
block|}
name|dw_form_t
name|get_form
argument_list|()
specifier|const
block|{
return|return
operator|(
name|dw_form_t
operator|)
name|m_attr_form
return|;
block|}
name|void
name|get
argument_list|(
name|dw_attr_t
operator|&
name|attr
argument_list|,
name|dw_form_t
operator|&
name|form
argument_list|)
decl|const
block|{
name|uint32_t
name|attr_form
init|=
name|m_attr_form
decl_stmt|;
name|attr
operator|=
name|attr_form
operator|>>
literal|16
expr_stmt|;
name|form
operator|=
operator|(
name|dw_form_t
operator|)
name|attr_form
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|DWARFAttribute
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|m_attr_form
operator|==
name|rhs
operator|.
name|m_attr_form
return|;
block|}
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|DWARFAttribute
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|protected
label|:
name|uint32_t
name|m_attr_form
decl_stmt|;
comment|// Upper 16 bits is attribute, lower 16 bits is form
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SymbolFileDWARF_DWARFAttribute_h_
end_comment

end_unit

