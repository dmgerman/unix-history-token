begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * crc32.h  *  * Author: Tatu Ylonen<ylo@cs.hut.fi>  *  * Copyright (c) 1992 Tatu Ylonen, Espoo, Finland  *                    All rights reserved  *  * Created: Tue Feb 11 14:37:27 1992 ylo  *  * Functions for computing 32-bit CRC.  *  */
end_comment

begin_comment
comment|/* RCSID("$Id: crc32.h,v 1.5 2000/04/14 10:30:31 markus Exp $"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CRC32_H
end_ifndef

begin_define
define|#
directive|define
name|CRC32_H
end_define

begin_comment
comment|/*  * This computes a 32 bit CRC of the data in the buffer, and returns the CRC.  * The polynomial used is 0xedb88320.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|crc32
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRC32_H */
end_comment

end_unit

