begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Paul Vixie.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
value|((name)[bitstr_size(nbits)])
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
value|((name)[_bit_byte(bit)] |= _bit_mask(bit))
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
value|((name)[_bit_byte(bit)]&= ~_bit_mask(bit))
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
value|do { \ 	register bitstr_t *_name = (name); \ 	register int _start = (start), _stop = (stop); \ 	register int _startbyte = _bit_byte(_start); \ 	register int _stopbyte = _bit_byte(_stop); \ 	if (_startbyte == _stopbyte) { \ 		_name[_startbyte]&= ((0xff>> (8 - (_start&0x7))) | \ 				      (0xff<< ((_stop&0x7) + 1))); \ 	} else { \ 		_name[_startbyte]&= 0xff>> (8 - (_start&0x7)); \ 		while (++_startbyte< _stopbyte) \ 			_name[_startbyte] = 0; \ 		_name[_stopbyte]&= 0xff<< ((_stop&0x7) + 1); \ 	} \ } while (0)
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
value|do { \ 	register bitstr_t *_name = (name); \ 	register int _start = (start), _stop = (stop); \ 	register int _startbyte = _bit_byte(_start); \ 	register int _stopbyte = _bit_byte(_stop); \ 	if (_startbyte == _stopbyte) { \ 		_name[_startbyte] |= ((0xff<< (_start&0x7))& \ 				    (0xff>> (7 - (_stop&0x7)))); \ 	} else { \ 		_name[_startbyte] |= 0xff<< ((_start)&0x7); \ 		while (++_startbyte< _stopbyte) \ 	    		_name[_startbyte] = 0xff; \ 		_name[_stopbyte] |= 0xff>> (7 - (_stop&0x7)); \ 	} \ } while (0)
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
value|do { \ 	register bitstr_t *_name = (name); \ 	register int _byte, _nbits = (nbits); \ 	register int _stopbyte = _bit_byte(_nbits - 1), _value = -1; \ 	if (_nbits> 0) \ 		for (_byte = 0; _byte<= _stopbyte; ++_byte) \ 			if (_name[_byte] != 0xff) { \ 				bitstr_t _lb; \ 				_value = _byte<< 3; \ 				for (_lb = _name[_byte]; (_lb&0x1); \ 				    ++_value, _lb>>= 1); \ 				break; \ 			} \ 	if (_value>= nbits) \ 		_value = -1; \ 	*(value) = _value; \ } while (0)
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
value|do { \ 	register bitstr_t *_name = (name); \ 	register int _byte, _nbits = (nbits); \ 	register int _stopbyte = _bit_byte(_nbits - 1), _value = -1; \ 	if (_nbits> 0) \ 		for (_byte = 0; _byte<= _stopbyte; ++_byte) \ 			if (_name[_byte]) { \ 				bitstr_t _lb; \ 				_value = _byte<< 3; \ 				for (_lb = _name[_byte]; !(_lb&0x1); \ 				    ++_value, _lb>>= 1); \ 				break; \ 			} \ 	if (_value>= nbits) \ 		_value = -1; \ 	*(value) = _value; \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BITSTRING_H_ */
end_comment

end_unit

