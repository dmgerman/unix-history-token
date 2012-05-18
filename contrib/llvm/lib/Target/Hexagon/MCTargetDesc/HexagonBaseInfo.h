begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonBaseInfo.h - Top level definitions for Hexagon --*- C++ -*--===//
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
comment|// This file contains small standalone helper functions and enum definitions for
end_comment

begin_comment
comment|// the Hexagon target useful for the compiler back-end and the MC libraries.
end_comment

begin_comment
comment|// As such, it deliberately does not include references to LLVM core
end_comment

begin_comment
comment|// code gen types, passes, etc..
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
name|HEXAGONBASEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|HEXAGONBASEINFO_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// HexagonII - This namespace holds all of the target specific flags that
comment|/// instruction info tracks.
comment|///
name|namespace
name|HexagonII
block|{
comment|// *** The code below must match HexagonInstrFormat*.td *** //
comment|// MCInstrDesc TSFlags
enum|enum
block|{
comment|// Predicated instructions.
name|PredicatedPos
init|=
literal|1
block|,
name|PredicatedMask
init|=
literal|0x1
block|}
enum|;
comment|// *** The code above must match HexagonInstrFormat*.td *** //
block|}
comment|// End namespace HexagonII.
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

