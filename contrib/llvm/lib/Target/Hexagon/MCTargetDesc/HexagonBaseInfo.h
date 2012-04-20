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
comment|// Insn types.
comment|// *** Must match HexagonInstrFormat*.td ***
enum|enum
name|Type
block|{
name|TypePSEUDO
init|=
literal|0
block|,
name|TypeALU32
init|=
literal|1
block|,
name|TypeCR
init|=
literal|2
block|,
name|TypeJR
init|=
literal|3
block|,
name|TypeJ
init|=
literal|4
block|,
name|TypeLD
init|=
literal|5
block|,
name|TypeST
init|=
literal|6
block|,
name|TypeSYSTEM
init|=
literal|7
block|,
name|TypeXTYPE
init|=
literal|8
block|,
name|TypeMEMOP
init|=
literal|9
block|,
name|TypeNV
init|=
literal|10
block|,
name|TypePREFIX
init|=
literal|30
block|,
comment|// Such as extenders.
name|TypeMARKER
init|=
literal|31
comment|// Such as end of a HW loop.
block|}
enum|;
comment|// MCInstrDesc TSFlags
comment|// *** Must match HexagonInstrFormat*.td ***
enum|enum
block|{
comment|// This 5-bit field describes the insn type.
name|TypePos
init|=
literal|0
block|,
name|TypeMask
init|=
literal|0x1f
block|,
comment|// Solo instructions.
name|SoloPos
init|=
literal|5
block|,
name|SoloMask
init|=
literal|0x1
block|,
comment|// Predicated instructions.
name|PredicatedPos
init|=
literal|6
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

