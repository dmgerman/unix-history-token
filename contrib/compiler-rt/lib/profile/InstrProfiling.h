begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===- InstrProfiling.h- Support library for PGO instrumentation ----------===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source |* License. See LICENSE.TXT for details. |* \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROFILE_INSTRPROFILING_H_
end_ifndef

begin_define
define|#
directive|define
name|PROFILE_INSTRPROFILING_H_
end_define

begin_include
include|#
directive|include
file|"InstrProfilingPort.h"
end_include

begin_include
include|#
directive|include
file|"InstrProfData.inc"
end_include

begin_enum
enum|enum
name|ValueKind
block|{
define|#
directive|define
name|VALUE_PROF_KIND
parameter_list|(
name|Enumerator
parameter_list|,
name|Value
parameter_list|)
value|Enumerator = Value,
include|#
directive|include
file|"InstrProfData.inc"
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|void
modifier|*
name|IntPtrT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|COMPILER_RT_ALIGNAS
argument_list|(
argument|INSTR_PROF_DATA_ALIGNMENT
argument_list|)
name|__llvm_profile_data
block|{
define|#
directive|define
name|INSTR_PROF_DATA
parameter_list|(
name|Type
parameter_list|,
name|LLVMType
parameter_list|,
name|Name
parameter_list|,
name|Initializer
parameter_list|)
value|Type Name;
include|#
directive|include
file|"InstrProfData.inc"
block|}
name|__llvm_profile_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__llvm_profile_header
block|{
define|#
directive|define
name|INSTR_PROF_RAW_HEADER
parameter_list|(
name|Type
parameter_list|,
name|Name
parameter_list|,
name|Initializer
parameter_list|)
value|Type Name;
include|#
directive|include
file|"InstrProfData.inc"
block|}
name|__llvm_profile_header
typedef|;
end_typedef

begin_comment
comment|/*!  * \brief Get number of bytes necessary to pad the argument to eight  * byte boundary.  */
end_comment

begin_function_decl
name|uint8_t
name|__llvm_profile_get_num_padding_bytes
parameter_list|(
name|uint64_t
name|SizeInBytes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * \brief Get required size for profile buffer.  */
end_comment

begin_function_decl
name|uint64_t
name|__llvm_profile_get_size_for_buffer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * \brief Write instrumentation data to the given buffer.  *  * \pre \c Buffer is the start of a buffer at least as big as \a  * __llvm_profile_get_size_for_buffer().  */
end_comment

begin_function_decl
name|int
name|__llvm_profile_write_buffer
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|__llvm_profile_data
modifier|*
name|__llvm_profile_begin_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|__llvm_profile_data
modifier|*
name|__llvm_profile_end_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|__llvm_profile_begin_names
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|__llvm_profile_end_names
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
modifier|*
name|__llvm_profile_begin_counters
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
modifier|*
name|__llvm_profile_end_counters
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * \brief Clear profile counters to zero.  *  */
end_comment

begin_function_decl
name|void
name|__llvm_profile_reset_counters
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * \brief Counts the number of times a target value is seen.  *  * Records the target value for the CounterIndex if not seen before. Otherwise,  * increments the counter associated w/ the target value.  * void __llvm_profile_instrument_target(uint64_t TargetValue, void *Data,  *                                       uint32_t CounterIndex);  */
end_comment

begin_function_decl
name|void
name|INSTR_PROF_VALUE_PROF_FUNC
parameter_list|(
define|#
directive|define
name|VALUE_PROF_FUNC_PARAM
parameter_list|(
name|ArgType
parameter_list|,
name|ArgName
parameter_list|,
name|ArgLLVMType
parameter_list|)
value|ArgType ArgName
include|#
directive|include
file|"InstrProfData.inc"
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * \brief Prepares the value profiling data for output.  *  * Returns an array of pointers to value profile data.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ValueProfData
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|ValueProfData
modifier|*
modifier|*
name|__llvm_profile_gather_value_data
parameter_list|(
name|uint64_t
modifier|*
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * \brief Write instrumentation data to the current file.  *  * Writes to the file with the last name given to \a *  * __llvm_profile_set_filename(),  * or if it hasn't been called, the \c LLVM_PROFILE_FILE environment variable,  * or if that's not set, the last name given to  * \a __llvm_profile_override_default_filename(), or if that's not set,  * \c "default.profraw".  */
end_comment

begin_function_decl
name|int
name|__llvm_profile_write_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * \brief Set the filename for writing instrumentation data.  *  * Sets the filename to be used for subsequent calls to  * \a __llvm_profile_write_file().  *  * \c Name is not copied, so it must remain valid.  Passing NULL resets the  * filename logic to the default behaviour.  */
end_comment

begin_function_decl
name|void
name|__llvm_profile_set_filename
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * \brief Set the filename for writing instrumentation data, unless the  * \c LLVM_PROFILE_FILE environment variable was set.  *  * Unless overridden, sets the filename to be used for subsequent calls to  * \a __llvm_profile_write_file().  *  * \c Name is not copied, so it must remain valid.  Passing NULL resets the  * filename logic to the default behaviour (unless the \c LLVM_PROFILE_FILE  * was set in which case it has no effect).  */
end_comment

begin_function_decl
name|void
name|__llvm_profile_override_default_filename
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*! \brief Register to write instrumentation data to file at exit. */
end_comment

begin_function_decl
name|int
name|__llvm_profile_register_write_file_atexit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*! \brief Initialize file handling. */
end_comment

begin_function_decl
name|void
name|__llvm_profile_initialize_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*! \brief Get the magic token for the file format. */
end_comment

begin_function_decl
name|uint64_t
name|__llvm_profile_get_magic
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*! \brief Get the version of the file format. */
end_comment

begin_function_decl
name|uint64_t
name|__llvm_profile_get_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROFILE_INSTRPROFILING_H_ */
end_comment

end_unit

