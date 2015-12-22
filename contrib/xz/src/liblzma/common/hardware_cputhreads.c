begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       hardware_cputhreads.c
end_comment

begin_comment
comment|/// \brief      Get the number of CPU threads or cores
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
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"tuklib_cpucores.h"
end_include

begin_extern
extern|extern LZMA_API(uint32_t
end_extern

begin_macro
unit|)
name|lzma_cputhreads
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
return|return
name|tuklib_cpucores
argument_list|()
return|;
block|}
end_block

end_unit

