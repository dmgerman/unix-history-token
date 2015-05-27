begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       hardware.h
end_comment

begin_comment
comment|/// \brief      Detection of available hardware resources
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
comment|/// Initialize some hardware-specific variables, which are needed by other
end_comment

begin_comment
comment|/// hardware_* functions.
end_comment

begin_function_decl
specifier|extern
name|void
name|hardware_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Set the maximum number of worker threads.
end_comment

begin_function_decl
specifier|extern
name|void
name|hardware_threads_set
parameter_list|(
name|uint32_t
name|threadlimit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the maximum number of worker threads.
end_comment

begin_function_decl
specifier|extern
name|uint32_t
name|hardware_threads_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Set the memory usage limit. There are separate limits for compression
end_comment

begin_comment
comment|/// and decompression (the latter includes also --list), one or both can
end_comment

begin_comment
comment|/// be set with a single call to this function. Zero indicates resetting
end_comment

begin_comment
comment|/// the limit back to the defaults. The limit can also be set as a percentage
end_comment

begin_comment
comment|/// of installed RAM; the percentage must be in the range [1, 100].
end_comment

begin_function_decl
specifier|extern
name|void
name|hardware_memlimit_set
parameter_list|(
name|uint64_t
name|new_memlimit
parameter_list|,
name|bool
name|set_compress
parameter_list|,
name|bool
name|set_decompress
parameter_list|,
name|bool
name|is_percentage
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the current memory usage limit for compression or decompression.
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|hardware_memlimit_get
parameter_list|(
name|enum
name|operation_mode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Display the amount of RAM and memory usage limits and exit.
end_comment

begin_function_decl
specifier|extern
name|void
name|hardware_memlimit_show
parameter_list|(
name|void
parameter_list|)
function_decl|lzma_attribute
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

end_unit

