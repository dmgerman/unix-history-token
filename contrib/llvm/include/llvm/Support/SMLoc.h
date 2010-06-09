begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SMLoc.h - Source location for use with diagnostics -------*- C++ -*-===//
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
comment|// This file declares the SMLoc class.  This class encapsulates a location in
end_comment

begin_comment
comment|// source code for use in diagnostics.
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
name|SUPPORT_SMLOC_H
end_ifndef

begin_define
define|#
directive|define
name|SUPPORT_SMLOC_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// SMLoc - Represents a location in source code.
name|class
name|SMLoc
block|{
specifier|const
name|char
modifier|*
name|Ptr
decl_stmt|;
name|public
label|:
name|SMLoc
argument_list|()
operator|:
name|Ptr
argument_list|(
literal|0
argument_list|)
block|{}
name|SMLoc
argument_list|(
specifier|const
name|SMLoc
operator|&
name|RHS
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|RHS.Ptr
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Ptr
operator|!=
literal|0
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SMLoc
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|RHS
operator|.
name|Ptr
operator|==
name|Ptr
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SMLoc
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|RHS
operator|.
name|Ptr
operator|!=
name|Ptr
return|;
block|}
specifier|const
name|char
operator|*
name|getPointer
argument_list|()
specifier|const
block|{
return|return
name|Ptr
return|;
block|}
specifier|static
name|SMLoc
name|getFromPointer
parameter_list|(
specifier|const
name|char
modifier|*
name|Ptr
parameter_list|)
block|{
name|SMLoc
name|L
decl_stmt|;
name|L
operator|.
name|Ptr
operator|=
name|Ptr
expr_stmt|;
return|return
name|L
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

