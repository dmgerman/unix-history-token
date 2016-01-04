begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARM_ehframe_Registers.h -------------------------------------*- C++ -*-===//
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
name|utility_ARM_ehframe_Registers_h_
end_ifndef

begin_define
define|#
directive|define
name|utility_ARM_ehframe_Registers_h_
end_define

begin_comment
comment|// The register numbers used in the eh_frame unwind information.
end_comment

begin_comment
comment|// Should be the same as DWARF register numbers.
end_comment

begin_enum
enum|enum
block|{
name|ehframe_r0
init|=
literal|0
block|,
name|ehframe_r1
block|,
name|ehframe_r2
block|,
name|ehframe_r3
block|,
name|ehframe_r4
block|,
name|ehframe_r5
block|,
name|ehframe_r6
block|,
name|ehframe_r7
block|,
name|ehframe_r8
block|,
name|ehframe_r9
block|,
name|ehframe_r10
block|,
name|ehframe_r11
block|,
name|ehframe_r12
block|,
name|ehframe_sp
block|,
name|ehframe_lr
block|,
name|ehframe_pc
block|,
name|ehframe_cpsr
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// utility_ARM_ehframe_Registers_h_
end_comment

end_unit

