begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- ProfileInfoTypes.h - Profiling info shared constants --------------===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source |* License. See LICENSE.TXT for details. |* |*===----------------------------------------------------------------------===*| |* |* This file defines constants shared by the various different profiling |* runtime libraries and the LLVM C++ profile info loader. It must be a |* C header because, at present, the profiling runtimes are written in C. |* \*===----------------------------------------------------------------------===*/
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
comment|/* IDs to distinguish between those path counters stored in hashses vs arrays */
enum|enum
name|ProfilingStorageType
block|{
name|ProfilingArray
init|=
literal|1
block|,
name|ProfilingHash
init|=
literal|2
block|}
enum|;
include|#
directive|include
file|"llvm/Analysis/ProfileDataTypes.h"
comment|/*  * The header for tables that map path numbers to path counters.  */
typedef|typedef
struct|struct
block|{
name|unsigned
name|fnNumber
decl_stmt|;
comment|/* function number for these counters */
name|unsigned
name|numEntries
decl_stmt|;
comment|/* number of entries stored */
block|}
name|PathProfileHeader
typedef|;
comment|/*  * Describes an entry in a tagged table for path counters.  */
typedef|typedef
struct|struct
block|{
name|unsigned
name|pathNumber
decl_stmt|;
name|unsigned
name|pathCounter
decl_stmt|;
block|}
name|PathProfileTableEntry
typedef|;
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
comment|/* LLVM_ANALYSIS_PROFILEINFOTYPES_H */
end_comment

end_unit

