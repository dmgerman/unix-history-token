begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===- InstrProfilingPlatformDarwin.c - Profile data on Darwin ------------===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source |* License. See LICENSE.TXT for details. |* \*===----------------------------------------------------------------------===*/
end_comment

begin_include
include|#
directive|include
file|"InstrProfiling.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_comment
comment|/* Use linker magic to find the bounds of the Data section. */
end_comment

begin_function
name|COMPILER_RT_VISIBILITY
specifier|extern
name|__llvm_profile_data
name|DataStart
asm|__asm("section$start$__DATA$" INSTR_PROF_DATA_SECT_NAME_STR);
name|COMPILER_RT_VISIBILITY
specifier|extern
name|__llvm_profile_data
name|DataEnd
asm|__asm("section$end$__DATA$" INSTR_PROF_DATA_SECT_NAME_STR);
name|COMPILER_RT_VISIBILITY
specifier|extern
name|char
name|NamesStart
asm|__asm("section$start$__DATA$" INSTR_PROF_NAME_SECT_NAME_STR);
name|COMPILER_RT_VISIBILITY
specifier|extern
name|char
name|NamesEnd
asm|__asm("section$end$__DATA$" INSTR_PROF_NAME_SECT_NAME_STR);
name|COMPILER_RT_VISIBILITY
specifier|extern
name|uint64_t
name|CountersStart
asm|__asm("section$start$__DATA$" INSTR_PROF_CNTS_SECT_NAME_STR);
name|COMPILER_RT_VISIBILITY
specifier|extern
name|uint64_t
name|CountersEnd
asm|__asm("section$end$__DATA$" INSTR_PROF_CNTS_SECT_NAME_STR);
name|COMPILER_RT_VISIBILITY
specifier|const
name|__llvm_profile_data
modifier|*
name|__llvm_profile_begin_data
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|&
name|DataStart
return|;
block|}
end_function

begin_function
name|COMPILER_RT_VISIBILITY
specifier|const
name|__llvm_profile_data
modifier|*
name|__llvm_profile_end_data
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|&
name|DataEnd
return|;
block|}
end_function

begin_function
name|COMPILER_RT_VISIBILITY
specifier|const
name|char
modifier|*
name|__llvm_profile_begin_names
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|&
name|NamesStart
return|;
block|}
end_function

begin_function
name|COMPILER_RT_VISIBILITY
specifier|const
name|char
modifier|*
name|__llvm_profile_end_names
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|&
name|NamesEnd
return|;
block|}
end_function

begin_function
name|COMPILER_RT_VISIBILITY
name|uint64_t
modifier|*
name|__llvm_profile_begin_counters
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|&
name|CountersStart
return|;
block|}
end_function

begin_function
name|COMPILER_RT_VISIBILITY
name|uint64_t
modifier|*
name|__llvm_profile_end_counters
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|&
name|CountersEnd
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

