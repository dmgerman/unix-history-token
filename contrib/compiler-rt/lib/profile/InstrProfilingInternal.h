begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===- InstrProfiling.h- Support library for PGO instrumentation ----------===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source |* License. See LICENSE.TXT for details. |* \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROFILE_INSTRPROFILING_INTERNALH_
end_ifndef

begin_define
define|#
directive|define
name|PROFILE_INSTRPROFILING_INTERNALH_
end_define

begin_include
include|#
directive|include
file|"InstrProfiling.h"
end_include

begin_comment
comment|/*!  * \brief Write instrumentation data to the given buffer, given explicit  * pointers to the live data in memory.  This function is probably not what you  * want.  Use __llvm_profile_get_size_for_buffer instead.  Use this function if  * your program has a custom memory layout.  */
end_comment

begin_function_decl
name|uint64_t
name|__llvm_profile_get_size_for_buffer_internal
parameter_list|(
specifier|const
name|__llvm_profile_data
modifier|*
name|DataBegin
parameter_list|,
specifier|const
name|__llvm_profile_data
modifier|*
name|DataEnd
parameter_list|,
specifier|const
name|uint64_t
modifier|*
name|CountersBegin
parameter_list|,
specifier|const
name|uint64_t
modifier|*
name|CountersEnd
parameter_list|,
specifier|const
name|char
modifier|*
name|NamesBegin
parameter_list|,
specifier|const
name|char
modifier|*
name|NamesEnd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * \brief Write instrumentation data to the given buffer, given explicit  * pointers to the live data in memory.  This function is probably not what you  * want.  Use __llvm_profile_write_buffer instead.  Use this function if your  * program has a custom memory layout.  *  * \pre \c Buffer is the start of a buffer at least as big as \a  * __llvm_profile_get_size_for_buffer_internal().  */
end_comment

begin_function_decl
name|int
name|__llvm_profile_write_buffer_internal
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
specifier|const
name|__llvm_profile_data
modifier|*
name|DataBegin
parameter_list|,
specifier|const
name|__llvm_profile_data
modifier|*
name|DataEnd
parameter_list|,
specifier|const
name|uint64_t
modifier|*
name|CountersBegin
parameter_list|,
specifier|const
name|uint64_t
modifier|*
name|CountersEnd
parameter_list|,
specifier|const
name|char
modifier|*
name|NamesBegin
parameter_list|,
specifier|const
name|char
modifier|*
name|NamesEnd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

