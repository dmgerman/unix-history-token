begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCAsmLayout.h - Assembly Layout Object -------------------*- C++ -*-===//
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
name|LLVM_MC_MCASMLAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCASMLAYOUT_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAssembler
decl_stmt|;
comment|/// Encapsulates the layout of an assembly file at a particular point in time.
comment|///
comment|/// Assembly may requiring compute multiple layouts for a particular assembly
comment|/// file as part of the relaxation process. This class encapsulates the layout
comment|/// at a single point in time in such a way that it is always possible to
comment|/// efficiently compute the exact addresses of any symbol in the assembly file,
comment|/// even during the relaxation process.
name|class
name|MCAsmLayout
block|{
name|private
label|:
name|MCAssembler
modifier|&
name|Assembler
decl_stmt|;
name|public
label|:
name|MCAsmLayout
argument_list|(
name|MCAssembler
operator|&
name|_Assembler
argument_list|)
operator|:
name|Assembler
argument_list|(
argument|_Assembler
argument_list|)
block|{}
comment|/// Get the assembler object this is a layout for.
name|MCAssembler
operator|&
name|getAssembler
argument_list|()
specifier|const
block|{
return|return
name|Assembler
return|;
block|}
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

end_unit

