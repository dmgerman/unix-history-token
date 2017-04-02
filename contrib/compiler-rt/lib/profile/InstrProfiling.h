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

begin_define
define|#
directive|define
name|INSTR_PROF_VISIBILITY
value|COMPILER_RT_VISIBILITY
end_define

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

begin_typedef
typedef|typedef
name|struct
name|ValueProfNode
modifier|*
name|PtrToNodeT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ValueProfNode
block|{
define|#
directive|define
name|INSTR_PROF_VALUE_NODE
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
name|ValueProfNode
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

begin_function_decl
name|ValueProfNode
modifier|*
name|__llvm_profile_begin_vnodes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ValueProfNode
modifier|*
name|__llvm_profile_end_vnodes
parameter_list|()
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
comment|/*!  * \brief Merge profile data from buffer.  *  * Read profile data form buffer \p Profile  and merge with  * in-process profile counters. The client is expected to  * have checked or already knows the profile data in the  * buffer matches the in-process counter structure before  * calling it.  */
end_comment

begin_function_decl
name|void
name|__llvm_profile_merge_from_buffer
parameter_list|(
specifier|const
name|char
modifier|*
name|Profile
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*! \brief Check if profile in buffer matches the current binary.  *  *  Returns 0 (success) if the profile data in buffer \p Profile with size  *  \p Size was generated by the same binary and therefore matches  *  structurally the in-process counters. If the profile data in buffer is  *  not compatible, the interface returns 1 (failure).  */
end_comment

begin_function_decl
name|int
name|__llvm_profile_check_compatibility
parameter_list|(
specifier|const
name|char
modifier|*
name|Profile
parameter_list|,
name|uint64_t
name|Size
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
comment|/*!  * \brief Write instrumentation data to the current file.  *  * Writes to the file with the last name given to \a *  * __llvm_profile_set_filename(),  * or if it hasn't been called, the \c LLVM_PROFILE_FILE environment variable,  * or if that's not set, the last name set to INSTR_PROF_PROFILE_NAME_VAR,  * or if that's not set,  \c "default.profraw".  */
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
comment|/*!  * \brief this is a wrapper interface to \c __llvm_profile_write_file.  * After this interface is invoked, a arleady dumped flag will be set  * so that profile won't be dumped again during program exit.   * Invocation of interface __llvm_profile_reset_counters will clear  * the flag. This interface is designed to be used to collect profile  * data from user selected hot regions. The use model is  *      __llvm_profile_reset_counters();  *      ... hot region 1  *      __llvm_profile_dump();  *      .. some other code  *      __llvm_profile_reset_counters();  *       ... hot region 2  *      __llvm_profile_dump();  *  *  It is expected that on-line profile merging is on with \c %m specifier  *  used in profile filename . If merging is  not turned on, user is expected  *  to invoke __llvm_profile_set_filename  to specify different profile names  *  for different regions before dumping to avoid profile write clobbering.  */
end_comment

begin_function_decl
name|int
name|__llvm_profile_dump
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
comment|/*!  * \brief Return path prefix (excluding the base filename) of the profile data.  * This is useful for users using \c -fprofile-generate=./path_prefix who do  * not care about the default raw profile name. It is also useful to collect  * more than more profile data files dumped in the same directory (Online  * merge mode is turned on for instrumented programs with shared libs).  * Side-effect: this API call will invoke malloc with dynamic memory allocation.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|__llvm_profile_get_path_prefix
parameter_list|()
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

begin_comment
comment|/*! \brief Get the number of entries in the profile data section. */
end_comment

begin_function_decl
name|uint64_t
name|__llvm_profile_get_data_size
parameter_list|(
specifier|const
name|__llvm_profile_data
modifier|*
name|Begin
parameter_list|,
specifier|const
name|__llvm_profile_data
modifier|*
name|End
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * This variable is defined in InstrProfilingRuntime.cc as a hidden  * symbol. Its main purpose is to enable profile runtime user to  * bypass runtime initialization code -- if the client code explicitly  * define this variable, then InstProfileRuntime.o won't be linked in.  * Note that this variable's visibility needs to be hidden so that the  * definition of this variable in an instrumented shared library won't  * affect runtime initialization decision of the main program.  *  __llvm_profile_profile_runtime. */
end_comment

begin_decl_stmt
name|COMPILER_RT_VISIBILITY
specifier|extern
name|int
name|INSTR_PROF_PROFILE_RUNTIME_VAR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*!  * This variable is defined in InstrProfiling.c. Its main purpose is to  * encode the raw profile version value and other format related information  * such as whether the profile is from IR based instrumentation. The variable  * is defined as weak so that compiler can emit an overriding definition  * depending on user option.  Since we don't support mixing FE and IR based  * data in the same raw profile data file (in other words, shared libs and  * main program are expected to be instrumented in the same way), there is  * no need for this variable to be hidden.  */
end_comment

begin_decl_stmt
specifier|extern
name|uint64_t
name|INSTR_PROF_RAW_VERSION_VAR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* __llvm_profile_raw_version */
end_comment

begin_comment
comment|/*!  * This variable is a weak symbol defined in InstrProfiling.c. It allows  * compiler instrumentation to provide overriding definition with value  * from compiler command line. This variable has default visibility.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|INSTR_PROF_PROFILE_NAME_VAR
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* __llvm_profile_filename. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROFILE_INSTRPROFILING_H_ */
end_comment

end_unit

