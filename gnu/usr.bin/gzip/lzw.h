begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lzw.h -- define the lzw functions.  * Copyright (C) 1992-1993 Jean-loup Gailly.  * This is free software; you can redistribute it and/or modify it under the  * terms of the GNU General Public License, see the file COPYING.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|OF
argument_list|)
operator|&&
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_include
include|#
directive|include
file|"gzip.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BITS
end_ifndef

begin_define
define|#
directive|define
name|BITS
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INIT_BITS
value|9
end_define

begin_comment
comment|/* Initial number of bits per code */
end_comment

begin_define
define|#
directive|define
name|LZW_MAGIC
value|"\037\235"
end_define

begin_comment
comment|/* Magic header for lzw files, 1F 9D */
end_comment

begin_define
define|#
directive|define
name|BIT_MASK
value|0x1f
end_define

begin_comment
comment|/* Mask for 'number of compression bits' */
end_comment

begin_comment
comment|/* Mask 0x20 is reserved to mean a fourth header byte, and 0x40 is free.  * It's a pity that old uncompress does not check bit 0x20. That makes  * extension of the format actually undesirable because old compress  * would just crash on the new format instead of giving a meaningful  * error message. It does check the number of bits, but it's more  * helpful to say "unsupported format, get a new version" than  * "can only handle 16 bits".  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_MODE
value|0x80
end_define

begin_comment
comment|/* Block compression: if table is full and compression rate is dropping,  * clear the dictionary.  */
end_comment

begin_define
define|#
directive|define
name|LZW_RESERVED
value|0x60
end_define

begin_comment
comment|/* reserved bits */
end_comment

begin_define
define|#
directive|define
name|CLEAR
value|256
end_define

begin_comment
comment|/* flush the dictionary */
end_comment

begin_define
define|#
directive|define
name|FIRST
value|(CLEAR+1)
end_define

begin_comment
comment|/* first free entry */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxbits
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max bits per code for LZW */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|block_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* block compress mode -C compatible with 2.0 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lzw
name|OF
argument_list|(
operator|(
name|int
name|in
operator|,
name|int
name|out
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|unlzw
name|OF
argument_list|(
operator|(
name|int
name|in
operator|,
name|int
name|out
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

