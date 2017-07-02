begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InstrProfilingNameVar.c - profile name variable setup --------------===//
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

begin_include
include|#
directive|include
file|"InstrProfiling.h"
end_include

begin_comment
comment|/* char __llvm_profile_filename[1]  *  * The runtime should only provide its own definition of this symbol when the  * user has not specified one. Set this up by moving the runtime's copy of this  * symbol to an object file within the archive.  */
end_comment

begin_decl_stmt
name|COMPILER_RT_WEAK
name|char
name|INSTR_PROF_PROFILE_NAME_VAR
index|[
literal|1
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

