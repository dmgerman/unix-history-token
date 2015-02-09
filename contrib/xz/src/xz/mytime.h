begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       mytime.h
end_comment

begin_comment
comment|/// \brief      Time handling functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|/// \brief      Number of milliseconds to between LZMA_SYNC_FLUSHes
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If 0, timed flushing is disabled. Otherwise if no more input is available
end_comment

begin_comment
comment|/// and not at the end of the file and at least opt_flush_timeout milliseconds
end_comment

begin_comment
comment|/// has elapsed since the start of compression or the previous flushing
end_comment

begin_comment
comment|/// (LZMA_SYNC_FLUSH or LZMA_FULL_FLUSH), set LZMA_SYNC_FLUSH to flush
end_comment

begin_comment
comment|/// the pending data.
end_comment

begin_decl_stmt
specifier|extern
name|uint64_t
name|opt_flush_timeout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief      True when flushing is needed due to expired timeout
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|flush_needed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief      Store the time when (de)compression was started
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The start time is also stored as the time of the first flush.
end_comment

begin_function_decl
specifier|extern
name|void
name|mytime_set_start_time
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Get the number of milliseconds since the operation started
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|mytime_get_elapsed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Store the time of when compressor was flushed
end_comment

begin_function_decl
specifier|extern
name|void
name|mytime_set_flush_time
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Get the number of milliseconds until the next flush
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This returns -1 if no timed flushing is used.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The return value is inteded for use with poll().
end_comment

begin_function_decl
specifier|extern
name|int
name|mytime_get_flush_timeout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

