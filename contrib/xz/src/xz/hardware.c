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

begin_include
include|#
directive|include
file|"tuklib_cpucores.h"
end_include

begin_comment
comment|/// Maximum number of free *coder* threads. This can be set with
end_comment

begin_comment
comment|/// the --threads=NUM command line option.
end_comment

begin_decl_stmt
specifier|static
name|uint32_t
name|threadlimit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Memory usage limit
end_comment

begin_decl_stmt
specifier|static
name|uint64_t
name|memlimit
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
name|hardware_threadlimit_set
parameter_list|(
name|uint32_t
name|new_threadlimit
parameter_list|)
block|{
if|if
condition|(
name|new_threadlimit
operator|==
literal|0
condition|)
block|{
comment|// The default is the number of available CPU cores.
name|threadlimit
operator|=
name|tuklib_cpucores
argument_list|()
expr_stmt|;
if|if
condition|(
name|threadlimit
operator|==
literal|0
condition|)
name|threadlimit
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|threadlimit
operator|=
name|new_threadlimit
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_function
specifier|extern
name|uint32_t
name|hardware_threadlimit_get
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|threadlimit
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
parameter_list|)
block|{
if|if
condition|(
name|new_memlimit
operator|!=
literal|0
condition|)
block|{
name|memlimit
operator|=
name|new_memlimit
expr_stmt|;
block|}
else|else
block|{
comment|// The default depends on the amount of RAM but so that
comment|// on "low-memory" systems the relative limit is higher
comment|// to make it more likely that files created with "xz -9"
comment|// will still decompress without overriding the limit
comment|// manually.
comment|//
comment|// If 40 % of RAM is 80 MiB or more, use 40 % of RAM as
comment|// the limit.
name|memlimit
operator|=
literal|40
operator|*
name|total_ram
operator|/
literal|100
expr_stmt|;
if|if
condition|(
name|memlimit
operator|<
name|UINT64_C
argument_list|(
literal|80
argument_list|)
operator|*
literal|1024
operator|*
literal|1024
condition|)
block|{
comment|// If 80 % of RAM is less than 80 MiB,
comment|// use 80 % of RAM as the limit.
name|memlimit
operator|=
literal|80
operator|*
name|total_ram
operator|/
literal|100
expr_stmt|;
if|if
condition|(
name|memlimit
operator|>
name|UINT64_C
argument_list|(
literal|80
argument_list|)
operator|*
literal|1024
operator|*
literal|1024
condition|)
block|{
comment|// Otherwise use 80 MiB as the limit.
name|memlimit
operator|=
name|UINT64_C
argument_list|(
literal|80
argument_list|)
operator|*
literal|1024
operator|*
literal|1024
expr_stmt|;
block|}
block|}
block|}
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|hardware_memlimit_set_percentage
parameter_list|(
name|uint32_t
name|percentage
parameter_list|)
block|{
name|assert
argument_list|(
name|percentage
operator|>
literal|0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|percentage
operator|<=
literal|100
argument_list|)
expr_stmt|;
name|memlimit
operator|=
name|percentage
operator|*
name|total_ram
operator|/
literal|100
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|uint64_t
name|hardware_memlimit_get
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|memlimit
return|;
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
argument_list|)
expr_stmt|;
name|hardware_threadlimit_set
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

