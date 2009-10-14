begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- ProfileInfoTypes.h - Profiling info shared constants ------*- C -*-===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source |* License. See LICENSE.TXT for details. |* |*===----------------------------------------------------------------------===*| |* |* This file defines constants shared by the various different profiling |* runtime libraries and the LLVM C++ profile info loader. It must be a |* C header because, at present, the profiling runtimes are written in C. |* \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_PROFILEINFOTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_PROFILEINFOTYPES_H
end_define

begin_enum
enum|enum
name|ProfilingType
block|{
name|ArgumentInfo
init|=
literal|1
block|,
comment|/* The command line argument block */
name|FunctionInfo
init|=
literal|2
block|,
comment|/* Function profiling information  */
name|BlockInfo
init|=
literal|3
block|,
comment|/* Block profiling information     */
name|EdgeInfo
init|=
literal|4
block|,
comment|/* Edge profiling information      */
name|PathInfo
init|=
literal|5
block|,
comment|/* Path profiling information      */
name|BBTraceInfo
init|=
literal|6
block|,
comment|/* Basic block trace information   */
name|OptEdgeInfo
init|=
literal|7
comment|/* Edge profiling information, optimal version */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_ANALYSIS_PROFILEINFOTYPES_H */
end_comment

end_unit

