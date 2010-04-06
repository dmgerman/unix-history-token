begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MCInstPrinter.h - Convert an MCInst to target assembly syntax -----===//
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
name|LLVM_MC_MCINSTPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCINSTPRINTER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInst
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
comment|/// MCInstPrinter - This is an instance of a target assembly language printer
comment|/// that converts an MCInst to valid target assembly syntax.
name|class
name|MCInstPrinter
block|{
name|protected
label|:
comment|/// CommentStream - a stream that comments can be emitted to if desired.
comment|/// Each comment must end with a newline.  This will be null if verbose
comment|/// assembly emission is disable.
name|raw_ostream
modifier|*
name|CommentStream
decl_stmt|;
specifier|const
name|MCAsmInfo
modifier|&
name|MAI
decl_stmt|;
name|public
label|:
name|MCInstPrinter
argument_list|(
specifier|const
name|MCAsmInfo
operator|&
name|mai
argument_list|)
operator|:
name|CommentStream
argument_list|(
literal|0
argument_list|)
operator|,
name|MAI
argument_list|(
argument|mai
argument_list|)
block|{}
name|virtual
operator|~
name|MCInstPrinter
argument_list|()
expr_stmt|;
comment|/// setCommentStream - Specify a stream to emit comments to.
name|void
name|setCommentStream
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
block|{
name|CommentStream
operator|=
operator|&
name|OS
expr_stmt|;
block|}
comment|/// printInst - Print the specified MCInst to the specified raw_ostream.
comment|///
name|virtual
name|void
name|printInst
parameter_list|(
specifier|const
name|MCInst
modifier|*
name|MI
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// getOpcodeName - Return the name of the specified opcode enum (e.g.
comment|/// "MOV32ri") or empty if we can't resolve it.
name|virtual
name|StringRef
name|getOpcodeName
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

