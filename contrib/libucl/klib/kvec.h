begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* The MIT License     Copyright (c) 2008, by Attractive Chaos<attractor@live.co.uk>     Permission is hereby granted, free of charge, to any person obtaining    a copy of this software and associated documentation files (the    "Software"), to deal in the Software without restriction, including    without limitation the rights to use, copy, modify, merge, publish,    distribute, sublicense, and/or sell copies of the Software, and to    permit persons to whom the Software is furnished to do so, subject to    the following conditions:     The above copyright notice and this permission notice shall be    included in all copies or substantial portions of the Software.     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS    BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN    ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE    SOFTWARE. */
end_comment

begin_comment
comment|/*   An example:  #include "kvec.h" int main() { 	kvec_t(int) array; 	kv_init(array); 	kv_push(int, array, 10); // append 	kv_a(int, array, 20) = 5; // dynamic 	kv_A(array, 20) = 4; // static 	kv_destroy(array); 	return 0; } */
end_comment

begin_comment
comment|/*   2008-09-22 (0.1.0):  	* The initial version.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AC_KVEC_H
end_ifndef

begin_define
define|#
directive|define
name|AC_KVEC_H
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|kv_roundup32
parameter_list|(
name|x
parameter_list|)
value|(--(x), (x)|=(x)>>1, (x)|=(x)>>2, (x)|=(x)>>4, (x)|=(x)>>8, (x)|=(x)>>16, ++(x))
end_define

begin_define
define|#
directive|define
name|kvec_t
parameter_list|(
name|type
parameter_list|)
value|struct { size_t n, m; type *a; }
end_define

begin_define
define|#
directive|define
name|kv_init
parameter_list|(
name|v
parameter_list|)
value|((v).n = (v).m = 0, (v).a = 0)
end_define

begin_define
define|#
directive|define
name|kv_destroy
parameter_list|(
name|v
parameter_list|)
value|free((v).a)
end_define

begin_define
define|#
directive|define
name|kv_A
parameter_list|(
name|v
parameter_list|,
name|i
parameter_list|)
value|((v).a[(i)])
end_define

begin_define
define|#
directive|define
name|kv_pop
parameter_list|(
name|v
parameter_list|)
value|((v).a[--(v).n])
end_define

begin_define
define|#
directive|define
name|kv_size
parameter_list|(
name|v
parameter_list|)
value|((v).n)
end_define

begin_define
define|#
directive|define
name|kv_max
parameter_list|(
name|v
parameter_list|)
value|((v).m)
end_define

begin_define
define|#
directive|define
name|kv_resize
parameter_list|(
name|type
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
value|((v).m = (s), (v).a = (type*)realloc((v).a, sizeof(type) * (v).m))
end_define

begin_define
define|#
directive|define
name|kv_grow_factor
value|1.5
end_define

begin_define
define|#
directive|define
name|kv_grow
parameter_list|(
name|type
parameter_list|,
name|v
parameter_list|)
value|((v).m = ((v).m> 1 ? (v).m * kv_grow_factor : 2), \ 		(v).a = (type*)realloc((v).a, sizeof(type) * (v).m))
end_define

begin_define
define|#
directive|define
name|kv_copy
parameter_list|(
name|type
parameter_list|,
name|v1
parameter_list|,
name|v0
parameter_list|)
value|do {											\ 		if ((v1).m< (v0).n) kv_resize(type, v1, (v0).n);					\ 		(v1).n = (v0).n;													\ 		memcpy((v1).a, (v0).a, sizeof(type) * (v0).n);						\ 	} while (0)																\  #define kv_push(type, v, x) do {											\ 		if ((v).n == (v).m) {												\ 			kv_grow(type, v);												\ 		}																	\ 		(v).a[(v).n++] = (x);												\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|kv_prepend
parameter_list|(
name|type
parameter_list|,
name|v
parameter_list|,
name|x
parameter_list|)
value|do {											\ 	if ((v).n == (v).m) {													\ 		kv_grow(type, v);													\ 	}																		\ 	memmove((v).a + 1, (v).a, sizeof(type) * (v).n);							\ 	(v).a[0] = (x);															\ 	(v).n ++;																\ } while (0)
end_define

begin_define
define|#
directive|define
name|kv_concat
parameter_list|(
name|type
parameter_list|,
name|v1
parameter_list|,
name|v0
parameter_list|)
value|do {										\ 	if ((v1).m< (v0).n + (v1).n) kv_resize(type, v1, (v0).n + (v1).n);		\ 		memcpy((v1).a + (v1).n, (v0).a, sizeof(type) * (v0).n);	\ 		(v1).n = (v0).n + (v1).n;											\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|kv_del
parameter_list|(
name|type
parameter_list|,
name|v
parameter_list|,
name|i
parameter_list|)
value|do {												\ 	if ((i)< (v).n) {														\ 		memmove((v).a + (i), (v).a + ((i) + 1), sizeof(type) * ((v).n - (i) - 1)); \ 		(v).n --;															\ 	}																		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

