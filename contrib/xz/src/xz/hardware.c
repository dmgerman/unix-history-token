begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       hardware.c
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

begin_include
include|#
directive|include
file|"private.h"
end_include

begin_comment
comment|/// Maximum number of worker threads. This can be set with
end_comment

begin_comment
comment|/// the --threads=NUM command line option.
end_comment

begin_decl_stmt
specifier|static
name|uint32_t
name|threads_max
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Memory usage limit for compression
end_comment

begin_decl_stmt
specifier|static
name|uint64_t
name|memlimit_compress
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Memory usage limit for decompression
end_comment

begin_decl_stmt
specifier|static
name|uint64_t
name|memlimit_decompress
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Total amount of physical RAM
end_comment

begin_decl_stmt
specifier|static
name|uint64_t
name|total_ram
decl_stmt|;
end_decl_stmt

begin_function
specifier|extern
name|void
name|hardware_threads_set
parameter_list|(
name|uint32_t
name|n
parameter_list|)
block|{
if|if
condition|(
name|n
operator|==
literal|0
condition|)
block|{
comment|// Automatic number of threads was requested.
comment|// If threading support was enabled at build time,
comment|// use the number of available CPU cores. Otherwise
comment|// use one thread since disabling threading support
comment|// omits lzma_cputhreads() from liblzma.
ifdef|#
directive|ifdef
name|MYTHREAD_ENABLED
name|threads_max
operator|=
name|lzma_cputhreads
argument_list|()
expr_stmt|;
if|if
condition|(
name|threads_max
operator|==
literal|0
condition|)
name|threads_max
operator|=
literal|1
expr_stmt|;
else|#
directive|else
name|threads_max
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
name|threads_max
operator|=
name|n
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_function
specifier|extern
name|uint32_t
name|hardware_threads_get
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|threads_max
return|;
block|}
end_function

begin_function
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
block|{
if|if
condition|(
name|is_percentage
condition|)
block|{
name|assert
argument_list|(
name|new_memlimit
operator|>
literal|0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|new_memlimit
operator|<=
literal|100
argument_list|)
expr_stmt|;
name|new_memlimit
operator|=
operator|(
name|uint32_t
operator|)
name|new_memlimit
operator|*
name|total_ram
operator|/
literal|100
expr_stmt|;
block|}
if|if
condition|(
name|set_compress
condition|)
name|memlimit_compress
operator|=
name|new_memlimit
expr_stmt|;
if|if
condition|(
name|set_decompress
condition|)
name|memlimit_decompress
operator|=
name|new_memlimit
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|uint64_t
name|hardware_memlimit_get
parameter_list|(
name|enum
name|operation_mode
name|mode
parameter_list|)
block|{
comment|// Zero is a special value that indicates the default. Currently
comment|// the default simply disables the limit. Once there is threading
comment|// support, this might be a little more complex, because there will
comment|// probably be a special case where a user asks for "optimal" number
comment|// of threads instead of a specific number (this might even become
comment|// the default mode). Each thread may use a significant amount of
comment|// memory. When there are no memory usage limits set, we need some
comment|// default soft limit for calculating the "optimal" number of
comment|// threads.
specifier|const
name|uint64_t
name|memlimit
init|=
name|mode
operator|==
name|MODE_COMPRESS
condition|?
name|memlimit_compress
else|:
name|memlimit_decompress
decl_stmt|;
return|return
name|memlimit
operator|!=
literal|0
condition|?
name|memlimit
else|:
name|UINT64_MAX
return|;
block|}
end_function

begin_comment
comment|/// Helper for hardware_memlimit_show() to print one human-readable info line.
end_comment

begin_function
specifier|static
name|void
name|memlimit_show
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|uint64_t
name|value
parameter_list|)
block|{
comment|// The memory usage limit is considered to be disabled if value
comment|// is 0 or UINT64_MAX. This might get a bit more complex once there
comment|// is threading support. See the comment in hardware_memlimit_get().
if|if
condition|(
name|value
operator|==
literal|0
operator|||
name|value
operator|==
name|UINT64_MAX
condition|)
name|printf
argument_list|(
literal|"%s %s\n"
argument_list|,
name|str
argument_list|,
name|_
argument_list|(
literal|"Disabled"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"%s %s MiB (%s B)\n"
argument_list|,
name|str
argument_list|,
name|uint64_to_str
argument_list|(
name|round_up_to_mib
argument_list|(
name|value
argument_list|)
argument_list|,
literal|0
argument_list|)
argument_list|,
name|uint64_to_str
argument_list|(
name|value
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|hardware_memlimit_show
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|opt_robot
condition|)
block|{
name|printf
argument_list|(
literal|"%"
name|PRIu64
literal|"\t%"
name|PRIu64
literal|"\t%"
name|PRIu64
literal|"\n"
argument_list|,
name|total_ram
argument_list|,
name|memlimit_compress
argument_list|,
name|memlimit_decompress
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// TRANSLATORS: Test with "xz --info-memory" to see if
comment|// the alignment looks nice.
name|memlimit_show
argument_list|(
name|_
argument_list|(
literal|"Total amount of physical memory (RAM): "
argument_list|)
argument_list|,
name|total_ram
argument_list|)
expr_stmt|;
name|memlimit_show
argument_list|(
name|_
argument_list|(
literal|"Memory usage limit for compression:    "
argument_list|)
argument_list|,
name|memlimit_compress
argument_list|)
expr_stmt|;
name|memlimit_show
argument_list|(
name|_
argument_list|(
literal|"Memory usage limit for decompression:  "
argument_list|)
argument_list|,
name|memlimit_decompress
argument_list|)
expr_stmt|;
block|}
name|tuklib_exit
argument_list|(
name|E_SUCCESS
argument_list|,
name|E_ERROR
argument_list|,
name|message_verbosity_get
argument_list|()
operator|!=
name|V_SILENT
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|extern
name|void
name|hardware_init
parameter_list|(
name|void
parameter_list|)
block|{
comment|// Get the amount of RAM. If we cannot determine it,
comment|// use the assumption defined by the configure script.
name|total_ram
operator|=
name|lzma_physmem
argument_list|()
expr_stmt|;
if|if
condition|(
name|total_ram
operator|==
literal|0
condition|)
name|total_ram
operator|=
call|(
name|uint64_t
call|)
argument_list|(
name|ASSUME_RAM
argument_list|)
operator|*
literal|1024
operator|*
literal|1024
expr_stmt|;
comment|// Set the defaults.
name|hardware_memlimit_set
argument_list|(
literal|0
argument_list|,
name|true
argument_list|,
name|true
argument_list|,
name|false
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

