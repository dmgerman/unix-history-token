begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUNoteType.h - AMDGPU ELF PT_NOTE section info-------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enums and constants for AMDGPU PT_NOTE sections.
end_comment

begin_comment
comment|///
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUPTNOTE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUPTNOTE_H
end_define

begin_decl_stmt
name|namespace
name|AMDGPU
block|{
name|namespace
name|ElfNote
block|{
specifier|const
name|char
name|SectionName
index|[]
init|=
literal|".note"
decl_stmt|;
specifier|const
name|char
name|NoteName
index|[]
init|=
literal|"AMD"
decl_stmt|;
comment|// TODO: Move this enum to include/llvm/Support so it can be used in tools?
enum|enum
name|NoteType
block|{
name|NT_AMDGPU_HSA_CODE_OBJECT_VERSION
init|=
literal|1
block|,
name|NT_AMDGPU_HSA_HSAIL
init|=
literal|2
block|,
name|NT_AMDGPU_HSA_ISA
init|=
literal|3
block|,
name|NT_AMDGPU_HSA_PRODUCER
init|=
literal|4
block|,
name|NT_AMDGPU_HSA_PRODUCER_OPTIONS
init|=
literal|5
block|,
name|NT_AMDGPU_HSA_EXTENSION
init|=
literal|6
block|,
name|NT_AMDGPU_HSA_CODE_OBJECT_METADATA
init|=
literal|10
block|,
name|NT_AMDGPU_HSA_HLDEBUG_DEBUG
init|=
literal|101
block|,
name|NT_AMDGPU_HSA_HLDEBUG_TARGET
init|=
literal|102
block|}
enum|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_AMDGPU_AMDGPUNOTETYPE_H
end_comment

end_unit

