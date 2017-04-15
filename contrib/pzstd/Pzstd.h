begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_include
include|#
directive|include
file|"ErrorHolder.h"
end_include

begin_include
include|#
directive|include
file|"Logging.h"
end_include

begin_include
include|#
directive|include
file|"Options.h"
end_include

begin_include
include|#
directive|include
file|"utils/Buffer.h"
end_include

begin_include
include|#
directive|include
file|"utils/Range.h"
end_include

begin_include
include|#
directive|include
file|"utils/ResourcePool.h"
end_include

begin_include
include|#
directive|include
file|"utils/ThreadPool.h"
end_include

begin_include
include|#
directive|include
file|"utils/WorkQueue.h"
end_include

begin_define
define|#
directive|define
name|ZSTD_STATIC_LINKING_ONLY
end_define

begin_include
include|#
directive|include
file|"zstd.h"
end_include

begin_undef
undef|#
directive|undef
name|ZSTD_STATIC_LINKING_ONLY
end_undef

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|pzstd
block|{
comment|/**  * Runs pzstd with `options` and returns the number of bytes written.  * An error occurred if `errorHandler.hasError()`.  *  * @param options      The pzstd options to use for (de)compression  * @returns            0 upon success and non-zero on failure.  */
name|int
name|pzstdMain
parameter_list|(
specifier|const
name|Options
modifier|&
name|options
parameter_list|)
function_decl|;
name|class
name|SharedState
block|{
name|public
label|:
name|SharedState
argument_list|(
specifier|const
name|Options
operator|&
name|options
argument_list|)
operator|:
name|log
argument_list|(
argument|options.verbosity
argument_list|)
block|{
if|if
condition|(
operator|!
name|options
operator|.
name|decompress
condition|)
block|{
name|auto
name|parameters
init|=
name|options
operator|.
name|determineParameters
argument_list|()
decl_stmt|;
name|cStreamPool
operator|.
name|reset
argument_list|(
argument|new ResourcePool<ZSTD_CStream>{           [this
argument_list|,
argument|parameters]() -> ZSTD_CStream* {             this->log(VERBOSE,
literal|"%s\n"
argument|,
literal|"Creating new ZSTD_CStream"
argument|);             auto zcs = ZSTD_createCStream();             if (zcs) {               auto err = ZSTD_initCStream_advanced(                   zcs, nullptr,
literal|0
argument|, parameters,
literal|0
argument|);               if (ZSTD_isError(err)) {                 ZSTD_freeCStream(zcs);                 return nullptr;               }             }             return zcs;           }
argument_list|,
argument|[](ZSTD_CStream *zcs) {             ZSTD_freeCStream(zcs);           }}
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|dStreamPool
operator|.
name|reset
argument_list|(
argument|new ResourcePool<ZSTD_DStream>{           [this]() -> ZSTD_DStream* {             this->log(VERBOSE,
literal|"%s\n"
argument|,
literal|"Creating new ZSTD_DStream"
argument|);             auto zds = ZSTD_createDStream();             if (zds) {               auto err = ZSTD_initDStream(zds);               if (ZSTD_isError(err)) {                 ZSTD_freeDStream(zds);                 return nullptr;               }             }             return zds;           }
argument_list|,
argument|[](ZSTD_DStream *zds) {             ZSTD_freeDStream(zds);           }}
argument_list|)
expr_stmt|;
block|}
block|}
operator|~
name|SharedState
argument_list|()
block|{
comment|// The resource pools have references to this, so destroy them first.
name|cStreamPool
operator|.
name|reset
argument_list|()
block|;
name|dStreamPool
operator|.
name|reset
argument_list|()
block|;   }
name|Logger
name|log
expr_stmt|;
name|ErrorHolder
name|errorHolder
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ResourcePool
operator|<
name|ZSTD_CStream
operator|>>
name|cStreamPool
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ResourcePool
operator|<
name|ZSTD_DStream
operator|>>
name|dStreamPool
expr_stmt|;
block|}
empty_stmt|;
comment|/**  * Streams input from `fd`, breaks input up into chunks, and compresses each  * chunk independently.  Output of each chunk gets streamed to a queue, and  * the output queues get put into `chunks` in order.  *  * @param state        The shared state  * @param chunks       Each compression jobs output queue gets `pushed()` here  *                      as soon as it is available  * @param executor     The thread pool to run compression jobs in  * @param fd           The input file descriptor  * @param size         The size of the input file if known, 0 otherwise  * @param numThreads   The number of threads in the thread pool  * @param parameters   The zstd parameters to use for compression  * @returns            The number of bytes read from the file  */
name|std
operator|::
name|uint64_t
name|asyncCompressChunks
argument_list|(
argument|SharedState& state
argument_list|,
argument|WorkQueue<std::shared_ptr<BufferWorkQueue>>& chunks
argument_list|,
argument|ThreadPool& executor
argument_list|,
argument|FILE* fd
argument_list|,
argument|std::uintmax_t size
argument_list|,
argument|std::size_t numThreads
argument_list|,
argument|ZSTD_parameters parameters
argument_list|)
expr_stmt|;
comment|/**  * Streams input from `fd`.  If pzstd headers are available it breaks the input  * up into independent frames.  It sends each frame to an independent  * decompression job.  Output of each frame gets streamed to a queue, and  * the output queues get put into `frames` in order.  *  * @param state        The shared state  * @param frames       Each decompression jobs output queue gets `pushed()` here  *                      as soon as it is available  * @param executor     The thread pool to run compression jobs in  * @param fd           The input file descriptor  * @returns            The number of bytes read from the file  */
name|std
operator|::
name|uint64_t
name|asyncDecompressFrames
argument_list|(
name|SharedState
operator|&
name|state
argument_list|,
name|WorkQueue
operator|<
name|std
operator|::
name|shared_ptr
operator|<
name|BufferWorkQueue
operator|>>
operator|&
name|frames
argument_list|,
name|ThreadPool
operator|&
name|executor
argument_list|,
name|FILE
operator|*
name|fd
argument_list|)
expr_stmt|;
comment|/**  * Streams input in from each queue in `outs` in order, and writes the data to  * `outputFd`.  *  * @param state        The shared state  * @param outs         A queue of output queues, one for each  *                      (de)compression job.  * @param outputFd     The file descriptor to write to  * @param decompress   Are we decompressing?  * @returns            The number of bytes written  */
name|std
operator|::
name|uint64_t
name|writeFile
argument_list|(
argument|SharedState& state
argument_list|,
argument|WorkQueue<std::shared_ptr<BufferWorkQueue>>& outs
argument_list|,
argument|FILE* outputFd
argument_list|,
argument|bool decompress
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

end_unit

