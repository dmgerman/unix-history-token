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

begin_include
include|#
directive|include
file|"stddef.h"
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

begin_comment
comment|/*!  * The data structure describing the data to be written by the  * low level writer callback function.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ProfDataIOVec
block|{
specifier|const
name|void
modifier|*
name|Data
decl_stmt|;
name|size_t
name|ElmSize
decl_stmt|;
name|size_t
name|NumElm
decl_stmt|;
block|}
name|ProfDataIOVec
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
function_decl|(
modifier|*
name|WriterCallback
function_decl|)
parameter_list|(
name|ProfDataIOVec
modifier|*
parameter_list|,
name|uint32_t
name|NumIOVecs
parameter_list|,
name|void
modifier|*
modifier|*
name|WriterCtx
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*!  * The data structure for buffered IO of profile data.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ProfBufferIO
block|{
comment|/* File handle.  */
name|void
modifier|*
name|File
decl_stmt|;
comment|/* Low level IO callback. */
name|WriterCallback
name|FileWriter
decl_stmt|;
comment|/* The start of the buffer. */
name|uint8_t
modifier|*
name|BufferStart
decl_stmt|;
comment|/* Total size of the buffer. */
name|uint32_t
name|BufferSz
decl_stmt|;
comment|/* Current byte offset from the start of the buffer. */
name|uint32_t
name|CurOffset
decl_stmt|;
block|}
name|ProfBufferIO
typedef|;
end_typedef

begin_comment
comment|/* The creator interface used by testing.  */
end_comment

begin_function_decl
name|ProfBufferIO
modifier|*
name|llvmCreateBufferIOInternal
parameter_list|(
name|void
modifier|*
name|File
parameter_list|,
name|uint32_t
name|DefaultBufferSz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * This is the interface to create a handle for buffered IO.  */
end_comment

begin_function_decl
name|ProfBufferIO
modifier|*
name|llvmCreateBufferIO
parameter_list|(
name|WriterCallback
name|FileWriter
parameter_list|,
name|void
modifier|*
name|File
parameter_list|,
name|uint32_t
name|DefaultBufferSz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * The interface to destroy the bufferIO handle and reclaim  * the memory.  */
end_comment

begin_function_decl
name|void
name|llvmDeleteBufferIO
parameter_list|(
name|ProfBufferIO
modifier|*
name|BufferIO
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * This is the interface to write \c Data of \c Size bytes through  * \c BufferIO. Returns 0 if successful, otherwise return -1.  */
end_comment

begin_function_decl
name|int
name|llvmBufferIOWrite
parameter_list|(
name|ProfBufferIO
modifier|*
name|BufferIO
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|Data
parameter_list|,
name|uint32_t
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * The interface to flush the remaining data in the buffer.  * through the low level writer callback.  */
end_comment

begin_function_decl
name|int
name|llvmBufferIOFlush
parameter_list|(
name|ProfBufferIO
modifier|*
name|BufferIO
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The low level interface to write data into a buffer. It is used as the  * callback by other high level writer methods such as buffered IO writer  * and profile data writer.  */
end_comment

begin_function_decl
name|uint32_t
name|llvmBufferWriter
parameter_list|(
name|ProfDataIOVec
modifier|*
name|IOVecs
parameter_list|,
name|uint32_t
name|NumIOVecs
parameter_list|,
name|void
modifier|*
modifier|*
name|WriterCtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|llvmWriteProfData
parameter_list|(
name|WriterCallback
name|Writer
parameter_list|,
name|void
modifier|*
name|WriterCtx
parameter_list|,
name|struct
name|ValueProfData
modifier|*
modifier|*
name|ValueDataArray
parameter_list|,
specifier|const
name|uint64_t
name|ValueDataSize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|llvmWriteProfDataImpl
parameter_list|(
name|WriterCallback
name|Writer
parameter_list|,
name|void
modifier|*
name|WriterCtx
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
name|struct
name|ValueProfData
modifier|*
modifier|*
name|ValueDataBeginArray
parameter_list|,
specifier|const
name|uint64_t
name|ValueDataSize
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

begin_function_decl
specifier|extern
name|char
modifier|*
function_decl|(
modifier|*
name|GetEnvHook
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|FreeHook
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
function_decl|(
modifier|*
name|CallocHook
function_decl|)
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|uint32_t
name|VPBufferSize
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

