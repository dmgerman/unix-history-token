begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Paul Vixie.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)bitstring.h	5.1 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|bitstr_t
typedef|;
end_typedef

begin_comment
comment|/* internal macros */
end_comment

begin_comment
comment|/* byte of the bitstring bit is in */
end_comment

begin_define
define|#
directive|define
name|_bit_byte
parameter_list|(
name|bit
parameter_list|)
define|\
value|((bit)>> 3)
end_define

begin_comment
comment|/* mask for the bit within its byte */
end_comment

begin_define
define|#
directive|define
name|_bit_mask
parameter_list|(
name|bit
parameter_list|)
define|\
value|(1<< ((bit)&0x7))
end_define

begin_comment
comment|/* external macros */
end_comment

begin_comment
comment|/* bytes in a bitstring of nbits bits */
end_comment

begin_define
define|#
directive|define
name|bitstr_size
parameter_list|(
name|nbits
parameter_list|)
define|\
value|((((nbits) - 1)>> 3) + 1)
end_define

begin_comment
comment|/* allocate a bitstring */
end_comment

begin_define
define|#
directive|define
name|bit_alloc
parameter_list|(
name|nbits
parameter_list|)
define|\
value|(bitstr_t *)malloc(1, \ 	    (unsigned int)_bitstr_size(nbits) * sizeof(bitstr_t))
end_define

begin_comment
comment|/* allocate a bitstring on the stack */
end_comment

begin_define
define|#
directive|define
name|bit_decl
parameter_list|(
name|name
parameter_list|,
name|nbits
parameter_list|)
define|\
value|(name)[bitstr_size(nbits)]
end_define

begin_comment
comment|/* is bit N of bitstring name set? */
end_comment

begin_define
define|#
directive|define
name|bit_test
parameter_list|(
name|name
parameter_list|,
name|bit
parameter_list|)
define|\
value|((name)[_bit_byte(bit)]& _bit_mask(bit))
end_define

begin_comment
comment|/* set bit N of bitstring name */
end_comment

begin_define
define|#
directive|define
name|bit_set
parameter_list|(
name|name
parameter_list|,
name|bit
parameter_list|)
define|\
value|(name)[_bit_byte(bit)] |= _bit_mask(bit)
end_define

begin_comment
comment|/* clear bit N of bitstring name */
end_comment

begin_define
define|#
directive|define
name|bit_clear
parameter_list|(
name|name
parameter_list|,
name|bit
parameter_list|)
define|\
value|(name)[_bit_byte(bit)]&= ~_bit_mask(bit)
end_define

begin_comment
comment|/* clear bits 0 ... N in bitstring name */
end_comment

begin_define
define|#
directive|define
name|bit_nclear
parameter_list|(
name|name
parameter_list|,
name|start
parameter_list|,
name|stop
parameter_list|)
value|{ \ 	register int _startbyte, _stopbyte; \ 	_startbyte = _bit_byte(start); \ 	(name)[_startbyte]&= 0xff>> (8 - ((start)&0x7)); \ 	for (_stopbyte = _bit_byte(stop); ++_startbyte< _stopbyte; \ 	    (name)[_startbyte] = 0); \ 	(name)[_stopbyte]&= 0xff<< (((stop)&0x7) + 1); \ }
end_define

begin_comment
comment|/* set bits 0 ... N in string name */
end_comment

begin_define
define|#
directive|define
name|bit_nset
parameter_list|(
name|name
parameter_list|,
name|start
parameter_list|,
name|stop
parameter_list|)
value|{ \ 	register int _startbyte, _stopbyte; \ 	_startbyte = _bit_byte(start); \ 	(name)[_startbyte] |= 0xff<< ((start)&0x7); \ 	for (_stopbyte = _bit_byte(stop); ++_startbyte< _stopbyte; \ 	    (name)[_startbyte] = 0xff); \ 	(name)[_stopbyte] |= 0xff>> (7 - ((stop)&0x7)); \ }
end_define

begin_comment
comment|/* find first bit clear in name */
end_comment

begin_define
define|#
directive|define
name|bit_ffc
parameter_list|(
name|name
parameter_list|,
name|nbits
parameter_list|,
name|value
parameter_list|)
value|{ \ 	register int _byte, _stopbyte; \ 	for ((value) = -1, _byte = 0, _stopbyte = _bit_byte(nbits); \ 	    _byte<= _stopbyte; _byte++) \ 		if ((name)[_byte] != 0xff) { \ 			(value) = _byte<< 3; \ 			for (_stopbyte = (name)[_byte]; (_stopbyte&0x1); \ 			    ++(value), _stopbyte>>= 1); \ 			break; \ 		} \ }
end_define

begin_comment
comment|/* find first bit set in name */
end_comment

begin_define
define|#
directive|define
name|bit_ffs
parameter_list|(
name|name
parameter_list|,
name|nbits
parameter_list|,
name|value
parameter_list|)
value|{ \ 	register int _byte, _stopbyte; \ 	for ((value) = -1, _byte = 0, _stopbyte = _bit_byte(nbits); \ 	    _byte<= _stopbyte; _byte++) \ 		if ((name)[_byte]) { \ 			(value) = _byte<< 3; \ 			for (_stopbyte = (name)[_byte]; !(_stopbyte&0x1); \ 			    ++(value), _stopbyte>>= 1); \ 			break; \ 		} \ }
end_define

end_unit

