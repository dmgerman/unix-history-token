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
comment|/// Set custom value for maximum number of coder threads.
end_comment

begin_function_decl
specifier|extern
name|void
name|hardware_threadlimit_set
parameter_list|(
name|uint32_t
name|threadlimit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the maximum number of coder threads. Some additional helper threads
end_comment

begin_comment
comment|/// are allowed on top of this).
end_comment

begin_function_decl
specifier|extern
name|uint32_t
name|hardware_threadlimit_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Set custom memory usage limit. This is used for both encoding and
end_comment

begin_comment
comment|/// decoding. Zero indicates resetting the limit back to defaults.
end_comment

begin_function_decl
specifier|extern
name|void
name|hardware_memlimit_set
parameter_list|(
name|uint64_t
name|memlimit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Set custom memory usage limit as a percentage of installed RAM.
end_comment

begin_comment
comment|/// The percentage must be in the range [1, 100].
end_comment

begin_function_decl
specifier|extern
name|void
name|hardware_memlimit_set_percentage
parameter_list|(
name|uint32_t
name|percentage
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the current memory usage limit.
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|hardware_memlimit_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

