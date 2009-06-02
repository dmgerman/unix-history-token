begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- Profiling.h - Profiling support library support routines --*- C -*-===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source       |* License. See LICENSE.TXT for details.                                       |* |*===----------------------------------------------------------------------===*| |* |* This file defines functions shared by the various different profiling |* implementations. |* \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROFILING_H
end_ifndef

begin_define
define|#
directive|define
name|PROFILING_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/ProfileInfoTypes.h"
end_include

begin_comment
comment|/* for enum ProfilingType */
end_comment

begin_comment
comment|/* save_arguments - Save argc and argv as passed into the program for the file  * we output.  */
end_comment

begin_function_decl
name|int
name|save_arguments
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* write_profiling_data - Write out a typed packet of profiling data to the  * current output file.  */
end_comment

begin_function_decl
name|void
name|write_profiling_data
parameter_list|(
name|enum
name|ProfilingType
name|PT
parameter_list|,
name|unsigned
modifier|*
name|Start
parameter_list|,
name|unsigned
name|NumElements
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

