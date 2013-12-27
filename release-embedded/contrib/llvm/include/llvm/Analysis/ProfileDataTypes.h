begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- ProfileDataTypes.h - Profiling info shared constants --------------===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source |* License. See LICENSE.TXT for details. |* |*===----------------------------------------------------------------------===*| |* |* This file defines constants shared by the various different profiling |* runtime libraries and the LLVM C++ profile metadata loader. It must be a |* C header because, at present, the profiling runtimes are written in C. |* \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_PROFILEDATATYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_PROFILEDATATYPES_H
end_define

begin_comment
comment|/* Included by libprofile. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* TODO: Strip out unused entries once ProfileInfo etc has been removed. */
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
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_ANALYSIS_PROFILEDATATYPES_H */
end_comment

end_unit

