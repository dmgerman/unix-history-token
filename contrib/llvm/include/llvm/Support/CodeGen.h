begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/CodeGen.h - CodeGen Concepts ---------------*- C++ -*-===//
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
comment|// This file define some types which define code generation concepts. For
end_comment

begin_comment
comment|// example, relocation model.
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
name|LLVM_SUPPORT_CODEGEN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_CODEGEN_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Relocation model types.
name|namespace
name|Reloc
block|{
enum|enum
name|Model
block|{
name|Static
block|,
name|PIC_
block|,
name|DynamicNoPIC
block|,
name|ROPI
block|,
name|RWPI
block|,
name|ROPI_RWPI
block|}
enum|;
block|}
comment|// Code model types.
name|namespace
name|CodeModel
block|{
comment|// Sync changes with CodeGenCWrappers.h.
enum|enum
name|Model
block|{
name|Default
block|,
name|JITDefault
block|,
name|Small
block|,
name|Kernel
block|,
name|Medium
block|,
name|Large
block|}
enum|;
block|}
name|namespace
name|PICLevel
block|{
comment|// This is used to map -fpic/-fPIC.
enum|enum
name|Level
block|{
name|NotPIC
init|=
literal|0
block|,
name|SmallPIC
init|=
literal|1
block|,
name|BigPIC
init|=
literal|2
block|}
enum|;
block|}
name|namespace
name|PIELevel
block|{
enum|enum
name|Level
block|{
name|Default
init|=
literal|0
block|,
name|Small
init|=
literal|1
block|,
name|Large
init|=
literal|2
block|}
enum|;
block|}
comment|// TLS models.
name|namespace
name|TLSModel
block|{
enum|enum
name|Model
block|{
name|GeneralDynamic
block|,
name|LocalDynamic
block|,
name|InitialExec
block|,
name|LocalExec
block|}
enum|;
block|}
comment|// Code generation optimization level.
name|namespace
name|CodeGenOpt
block|{
enum|enum
name|Level
block|{
name|None
block|,
comment|// -O0
name|Less
block|,
comment|// -O1
name|Default
block|,
comment|// -O2, -Os
name|Aggressive
comment|// -O3
block|}
enum|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

