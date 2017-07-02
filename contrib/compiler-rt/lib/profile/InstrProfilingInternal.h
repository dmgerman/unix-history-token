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

begin_struct_decl
struct_decl|struct
name|ProfDataWriter
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|uint32_t
function_decl|(
modifier|*
name|WriterCallback
function_decl|)
parameter_list|(
name|struct
name|ProfDataWriter
modifier|*
name|This
parameter_list|,
name|ProfDataIOVec
modifier|*
parameter_list|,
name|uint32_t
name|NumIOVecs
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ProfDataWriter
block|{
name|WriterCallback
name|Write
decl_stmt|;
name|void
modifier|*
name|WriterCtx
decl_stmt|;
block|}
name|ProfDataWriter
typedef|;
end_typedef

begin_comment
comment|/*!  * The data structure for buffered IO of profile data.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ProfBufferIO
block|{
name|ProfDataWriter
modifier|*
name|FileWriter
decl_stmt|;
name|uint32_t
name|OwnFileWriter
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
name|lprofCreateBufferIOInternal
parameter_list|(
name|void
modifier|*
name|File
parameter_list|,
name|uint32_t
name|BufferSz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * This is the interface to create a handle for buffered IO.  */
end_comment

begin_function_decl
name|ProfBufferIO
modifier|*
name|lprofCreateBufferIO
parameter_list|(
name|ProfDataWriter
modifier|*
name|FileWriter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!  * The interface to destroy the bufferIO handle and reclaim  * the memory.  */
end_comment

begin_function_decl
name|void
name|lprofDeleteBufferIO
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
name|lprofBufferIOWrite
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
name|lprofBufferIOFlush
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
name|lprofBufferWriter
parameter_list|(
name|ProfDataWriter
modifier|*
name|This
parameter_list|,
name|ProfDataIOVec
modifier|*
name|IOVecs
parameter_list|,
name|uint32_t
name|NumIOVecs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|initBufferWriter
parameter_list|(
name|ProfDataWriter
modifier|*
name|BufferWriter
parameter_list|,
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ValueProfData
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ValueProfRecord
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|InstrProfValueData
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ValueProfNode
struct_decl|;
end_struct_decl

begin_comment
comment|/*!  * The class that defines a set of methods to read value profile  * data for streaming/serialization from the instrumentation runtime.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|VPDataReaderType
block|{
name|uint32_t
function_decl|(
modifier|*
name|InitRTRecord
function_decl|)
parameter_list|(
specifier|const
name|__llvm_profile_data
modifier|*
name|Data
parameter_list|,
name|uint8_t
modifier|*
name|SiteCountArray
index|[]
parameter_list|)
function_decl|;
comment|/* Function pointer to getValueProfRecordHeader method. */
name|uint32_t
function_decl|(
modifier|*
name|GetValueProfRecordHeaderSize
function_decl|)
parameter_list|(
name|uint32_t
name|NumSites
parameter_list|)
function_decl|;
comment|/* Function pointer to getFristValueProfRecord method. */
name|struct
name|ValueProfRecord
modifier|*
function_decl|(
modifier|*
name|GetFirstValueProfRecord
function_decl|)
parameter_list|(
name|struct
name|ValueProfData
modifier|*
parameter_list|)
function_decl|;
comment|/* Return the number of value data for site \p Site.  */
name|uint32_t
function_decl|(
modifier|*
name|GetNumValueDataForSite
function_decl|)
parameter_list|(
name|uint32_t
name|VK
parameter_list|,
name|uint32_t
name|Site
parameter_list|)
function_decl|;
comment|/* Return the total size of the value profile data of the     * current function.  */
name|uint32_t
function_decl|(
modifier|*
name|GetValueProfDataSize
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/*!     * Read the next \p N value data for site \p Site and store the data    * in \p Dst. \p StartNode is the first value node to start with if    * it is not null. The function returns the pointer to the value    * node pointer to be used as the \p StartNode of the next batch reading.    * If there is nothing left, it returns NULL.    */
name|struct
name|ValueProfNode
modifier|*
function_decl|(
modifier|*
name|GetValueData
function_decl|)
parameter_list|(
name|uint32_t
name|ValueKind
parameter_list|,
name|uint32_t
name|Site
parameter_list|,
name|struct
name|InstrProfValueData
modifier|*
name|Dst
parameter_list|,
name|struct
name|ValueProfNode
modifier|*
name|StartNode
parameter_list|,
name|uint32_t
name|N
parameter_list|)
function_decl|;
block|}
name|VPDataReaderType
typedef|;
end_typedef

begin_comment
comment|/* Write profile data to destinitation. If SkipNameDataWrite is set to 1,    the name data is already in destintation, we just skip over it. */
end_comment

begin_function_decl
name|int
name|lprofWriteData
parameter_list|(
name|ProfDataWriter
modifier|*
name|Writer
parameter_list|,
name|VPDataReaderType
modifier|*
name|VPDataReader
parameter_list|,
name|int
name|SkipNameDataWrite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lprofWriteDataImpl
parameter_list|(
name|ProfDataWriter
modifier|*
name|Writer
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
name|VPDataReaderType
modifier|*
name|VPDataReader
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
parameter_list|,
name|int
name|SkipNameDataWrite
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Merge value profile data pointed to by SrcValueProfData into  * in-memory profile counters pointed by to DstData.  */
end_comment

begin_function_decl
name|void
name|lprofMergeValueProfData
parameter_list|(
name|struct
name|ValueProfData
modifier|*
name|SrcValueProfData
parameter_list|,
name|__llvm_profile_data
modifier|*
name|DstData
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|VPDataReaderType
modifier|*
name|lprofGetVPDataReader
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Internal interface used by test to reset the max number of   * tracked values per value site to be \p MaxVals.  */
end_comment

begin_function_decl
name|void
name|lprofSetMaxValsPerSite
parameter_list|(
name|uint32_t
name|MaxVals
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lprofSetupValueProfiler
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the profile header 'signature' value associated with the current  * executable or shared library. The signature value can be used to for  * a profile name that is unique to this load module so that it does not  * collide with profiles from other binaries. It also allows shared libraries  * to dump merged profile data into its own profile file. */
end_comment

begin_function_decl
name|uint64_t
name|lprofGetLoadModuleSignature
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*   * Return non zero value if the profile data has already been  * dumped to the file.  */
end_comment

begin_function_decl
name|unsigned
name|lprofProfileDumped
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lprofSetProfileDumped
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_VISIBILITY
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

begin_decl_stmt
name|COMPILER_RT_VISIBILITY
specifier|extern
name|uint8_t
modifier|*
name|DynamicBufferIOBuffer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|COMPILER_RT_VISIBILITY
specifier|extern
name|uint32_t
name|VPBufferSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|COMPILER_RT_VISIBILITY
specifier|extern
name|uint32_t
name|VPMaxNumValsPerSite
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to the start of static value counters to be allocted. */
end_comment

begin_decl_stmt
name|COMPILER_RT_VISIBILITY
specifier|extern
name|ValueProfNode
modifier|*
name|CurrentVNode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|COMPILER_RT_VISIBILITY
specifier|extern
name|ValueProfNode
modifier|*
name|EndVNode
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|VPMergeHook
function_decl|)
parameter_list|(
name|struct
name|ValueProfData
modifier|*
parameter_list|,
name|__llvm_profile_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

