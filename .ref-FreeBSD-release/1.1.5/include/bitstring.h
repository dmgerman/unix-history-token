begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Paul Vixie.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)bitstring.h	5.5 (Berkeley) 4/3/91  *	$Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BITSTRING_H_
end_ifndef

begin_define
define|#
directive|define
name|_BITSTRING_H_
end_define

begin_comment
comment|/* modified for SV/AT and bitstring bugfix by M.R.Murphy, 11oct91  * bitstr_size changed gratuitously, but shorter  * bit_alloc   spelling error fixed  * the following were efficient, but didn't work, they've been made to  * work, but are no longer as efficient :-)  * bit_nclear, bit_nset, bit_ffc, bit_ffs  */
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
value|(((nbits) + 7)>> 3)
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
value|(bitstr_t *)calloc((size_t)bitstr_size(nbits), sizeof(bitstr_t))
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
comment|/* clear bits start ... stop in bitstring */
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
value|{ \ 	register bitstr_t *_name = name; \ 	register int _start = start, _stop = stop; \ 	while (_start<= _stop) { \ 		bit_clear(_name, _start); \ 		_start++; \ 		} \ }
end_define

begin_comment
comment|/* set bits start ... stop in bitstring */
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
value|{ \ 	register bitstr_t *_name = name; \ 	register int _start = start, _stop = stop; \ 	while (_start<= _stop) { \ 		bit_set(_name, _start); \ 		_start++; \ 		} \ }
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
value|{ \ 	register bitstr_t *_name = name; \ 	register int _bit, _nbits = nbits, _value = -1; \ 	for (_bit = 0; _bit< _nbits; ++_bit) \ 		if (!bit_test(_name, _bit)) { \ 			_value = _bit; \ 			break; \ 		} \ 	*(value) = _value; \ }
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
value|{ \ 	register bitstr_t *_name = name; \ 	register int _bit, _nbits = nbits, _value = -1; \ 	for (_bit = 0; _bit< _nbits; ++_bit) \ 		if (bit_test(_name, _bit)) { \ 			_value = _bit; \ 			break; \ 		} \ 	*(value) = _value; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BITSTRING_H_ */
end_comment

end_unit

