begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsDirectObjLower.h - Mips LLVM direct object lowering *- C++ -*--===//
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
name|MIPSDIRECTOBJLOWER_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSDIRECTOBJLOWER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInst
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|namespace
name|Mips
block|{
comment|/// MipsDirectObjLower - This name space is used to lower MCInstr in cases
comment|//                       where the assembler usually finishes the lowering
comment|//                       such as large shifts.
name|void
name|LowerLargeShift
parameter_list|(
name|MCInst
modifier|&
name|Inst
parameter_list|)
function_decl|;
name|void
name|LowerDextDins
parameter_list|(
name|MCInst
modifier|&
name|Inst
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

