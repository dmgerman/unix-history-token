begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Phases.h - Transformations on Driver Types -------------*- C++ -*-===//
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
name|LLVM_CLANG_DRIVER_PHASES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DRIVER_PHASES_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|namespace
name|phases
block|{
comment|/// ID - Ordered values for successive stages in the
comment|/// compilation process which interact with user options.
enum|enum
name|ID
block|{
name|Preprocess
block|,
name|Precompile
block|,
name|Compile
block|,
name|Backend
block|,
name|Assemble
block|,
name|Link
block|}
enum|;
enum|enum
block|{
name|MaxNumberOfPhases
init|=
name|Link
operator|+
literal|1
block|}
enum|;
specifier|const
name|char
modifier|*
name|getPhaseName
parameter_list|(
name|ID
name|Id
parameter_list|)
function_decl|;
block|}
comment|// end namespace phases
block|}
comment|// end namespace driver
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

