begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       crc32_table.c
end_comment

begin_comment
comment|/// \brief      Precalculated CRC32 table with correct endianness
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

begin_ifdef
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
end_ifdef

begin_include
include|#
directive|include
file|"crc32_table_be.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"crc32_table_le.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

