begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1983, 1995-1997 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: bitops.h,v 1.2 2001/09/22 22:05:42 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_BITOPS_H
end_ifndef

begin_define
define|#
directive|define
name|SM_BITOPS_H
end_define

begin_comment
comment|/* **  Data structure for bit maps. ** **	Each bit in this map can be referenced by an ascii character. **	This is 256 possible bits, or 32 8-bit bytes. */
end_comment

begin_define
define|#
directive|define
name|BITMAPBITS
value|256
end_define

begin_comment
comment|/* number of bits in a bit map */
end_comment

begin_define
define|#
directive|define
name|BYTEBITS
value|8
end_define

begin_comment
comment|/* number of bits in a byte */
end_comment

begin_define
define|#
directive|define
name|BITMAPBYTES
value|(BITMAPBITS / BYTEBITS)
end_define

begin_comment
comment|/* number of bytes in bit map */
end_comment

begin_define
define|#
directive|define
name|BITMAPMAX
value|((BITMAPBYTES / sizeof (int)) - 1)
end_define

begin_comment
comment|/* internal macros */
end_comment

begin_comment
comment|/* make sure this index never leaves the allowed range: 0 to BITMAPMAX */
end_comment

begin_define
define|#
directive|define
name|_BITWORD
parameter_list|(
name|bit
parameter_list|)
value|(((unsigned char)(bit) / (BYTEBITS * sizeof (int)))& BITMAPMAX)
end_define

begin_define
define|#
directive|define
name|_BITBIT
parameter_list|(
name|bit
parameter_list|)
value|((unsigned int)1<< ((unsigned char)(bit) % (BYTEBITS * sizeof (int))))
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|BITMAP256
index|[
name|BITMAPBYTES
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
index|]
typedef|;
end_typedef

begin_comment
comment|/* properly case and truncate bit */
end_comment

begin_define
define|#
directive|define
name|bitidx
parameter_list|(
name|bit
parameter_list|)
value|((unsigned int) (bit)& 0xff)
end_define

begin_comment
comment|/* test bit number N */
end_comment

begin_define
define|#
directive|define
name|bitnset
parameter_list|(
name|bit
parameter_list|,
name|map
parameter_list|)
value|((map)[_BITWORD(bit)]& _BITBIT(bit))
end_define

begin_comment
comment|/* set bit number N */
end_comment

begin_define
define|#
directive|define
name|setbitn
parameter_list|(
name|bit
parameter_list|,
name|map
parameter_list|)
value|(map)[_BITWORD(bit)] |= _BITBIT(bit)
end_define

begin_comment
comment|/* clear bit number N */
end_comment

begin_define
define|#
directive|define
name|clrbitn
parameter_list|(
name|bit
parameter_list|,
name|map
parameter_list|)
value|(map)[_BITWORD(bit)]&= ~_BITBIT(bit)
end_define

begin_comment
comment|/* clear an entire bit map */
end_comment

begin_define
define|#
directive|define
name|clrbitmap
parameter_list|(
name|map
parameter_list|)
value|memset((char *) map, '\0', BITMAPBYTES)
end_define

begin_comment
comment|/* bit hacking */
end_comment

begin_define
define|#
directive|define
name|bitset
parameter_list|(
name|bit
parameter_list|,
name|word
parameter_list|)
value|(((word)& (bit)) != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_BITOPS_H */
end_comment

end_unit

