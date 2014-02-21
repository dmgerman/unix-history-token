begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       hardware_physmem.c
end_comment

begin_comment
comment|/// \brief      Get the total amount of physical memory (RAM)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Jonathan Nieder
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
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"tuklib_physmem.h"
end_include

begin_extern
extern|extern LZMA_API(uint64_t
end_extern

begin_macro
unit|)
name|lzma_physmem
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
comment|// It is simpler to make lzma_physmem() a wrapper for
comment|// tuklib_physmem() than to hack appropriate symbol visiblity
comment|// support for the tuklib modules.
return|return
name|tuklib_physmem
argument_list|()
return|;
block|}
end_block

end_unit

