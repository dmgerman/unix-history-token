begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- X86InstComments.h - Generate verbose-asm comments for instrs -*- C++ -*-=//
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
comment|// This defines functionality used to emit comments about X86 instructions to
end_comment

begin_comment
comment|// an output stream for -fverbose-asm.
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
name|LLVM_LIB_TARGET_X86_INSTPRINTER_X86INSTCOMMENTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_INSTPRINTER_X86INSTCOMMENTS_H
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
name|bool
name|EmitAnyX86InstComments
parameter_list|(
specifier|const
name|MCInst
modifier|*
name|MI
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|getRegName
function_decl|)
parameter_list|(
name|unsigned
parameter_list|)
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

