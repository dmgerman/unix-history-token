begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCLabel.h - Machine Code Directional Local Labels --------*- C++ -*-===//
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
comment|// This file contains the declaration of the MCLabel class.
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
name|LLVM_MC_MCLABEL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCLABEL_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
comment|/// \brief Instances of this class represent a label name in the MC file,
comment|/// and MCLabel are created and uniqued by the MCContext class.  MCLabel
comment|/// should only be constructed for valid instances in the object file.
name|class
name|MCLabel
block|{
comment|// \brief The instance number of this Directional Local Label.
name|unsigned
name|Instance
decl_stmt|;
name|private
label|:
comment|// MCContext creates and uniques these.
name|friend
name|class
name|MCContext
decl_stmt|;
name|MCLabel
argument_list|(
argument|unsigned instance
argument_list|)
block|:
name|Instance
argument_list|(
argument|instance
argument_list|)
block|{}
name|public
label|:
name|MCLabel
argument_list|(
specifier|const
name|MCLabel
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|MCLabel
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCLabel
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|/// \brief Get the current instance of this Directional Local Label.
name|unsigned
name|getInstance
argument_list|()
specifier|const
block|{
return|return
name|Instance
return|;
block|}
comment|/// \brief Increment the current instance of this Directional Local Label.
name|unsigned
name|incInstance
parameter_list|()
block|{
return|return
operator|++
name|Instance
return|;
block|}
comment|/// \brief Print the value to the stream \p OS.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Print the value to stderr.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|MCLabel
operator|&
name|Label
operator|)
block|{
name|Label
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
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
comment|// LLVM_MC_MCLABEL_H
end_comment

end_unit

