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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_comment
comment|/* System headers define 'size_t' incorrectly on x64 FreeBSD (prior to  * FreeBSD 10, r232261) when compiled in 32-bit mode.  */
end_comment

begin_define
define|#
directive|define
name|PRIu64
value|"llu"
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|uintptr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(__FreeBSD__)&& defined(__i386__) */
end_comment

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__FreeBSD__)&& defined(__i386__) */
end_comment

begin_define
define|#
directive|define
name|PROFILE_HEADER_SIZE
value|7
end_define

begin_typedef
typedef|typedef
struct|struct
name|__llvm_profile_data
block|{
specifier|const
name|uint32_t
name|NameSize
decl_stmt|;
specifier|const
name|uint32_t
name|NumCounters
decl_stmt|;
specifier|const
name|uint64_t
name|FuncHash
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|Name
decl_stmt|;
name|uint64_t
modifier|*
specifier|const
name|Counters
decl_stmt|;
block|}
name|__llvm_profile_data
typedef|;
end_typedef

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
comment|/*!  * \brief Write instrumentation data to the current file.  *  * Writes to the file with the last name given to \a __llvm_profile_set_filename(),  * or if it hasn't been called, the \c LLVM_PROFILE_FILE environment variable,  * or if that's not set, \c "default.profdata".  */
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

