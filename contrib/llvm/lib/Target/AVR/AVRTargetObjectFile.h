begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AVRTargetObjectFile.h - AVR Object Info -----------------*- C++ -*-===//
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
name|LLVM_AVR_TARGET_OBJECT_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_TARGET_OBJECT_FILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/TargetLoweringObjectFileImpl.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/**  * Lowering for an AVR ELF32 object file.  */
name|class
name|AVRTargetObjectFile
range|:
name|public
name|TargetLoweringObjectFileELF
block|{
typedef|typedef
name|TargetLoweringObjectFileELF
name|Base
typedef|;
name|public
operator|:
name|void
name|Initialize
argument_list|(
argument|MCContext&ctx
argument_list|,
argument|const TargetMachine&TM
argument_list|)
name|override
decl_stmt|;
name|MCSection
modifier|*
name|SelectSectionForGlobal
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|SectionKind
name|Kind
argument_list|,
name|Mangler
operator|&
name|Mang
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
decl|const
name|override
decl_stmt|;
name|private
label|:
name|MCSection
modifier|*
name|ProgmemDataSection
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_AVR_TARGET_OBJECT_FILE_H
end_comment

end_unit

