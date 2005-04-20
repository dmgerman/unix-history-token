begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) KATO Takenori, 1999.  *  * All rights reserved.  Unpublished rights reserved under the copyright  * laws of Japan.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_BUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_BUS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_comment
comment|/* NEC PC-98 */
end_comment

begin_include
include|#
directive|include
file|<machine/bus_pc98.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IBM-PC */
end_comment

begin_include
include|#
directive|include
file|<machine/bus_at386.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/bus_dma.h>
end_include

begin_comment
comment|/*  * Stream accesses are the same as normal accesses on i386/pc98; there are no  * supported bus systems with an endianess different from the host one.  */
end_comment

begin_define
define|#
directive|define
name|bus_space_read_stream_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
value|bus_space_read_1((t), (h), (o))
end_define

begin_define
define|#
directive|define
name|bus_space_read_stream_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
value|bus_space_read_2((t), (h), (o))
end_define

begin_define
define|#
directive|define
name|bus_space_read_stream_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|)
value|bus_space_read_4((t), (h), (o))
end_define

begin_define
define|#
directive|define
name|bus_space_read_multi_stream_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_multi_1((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_multi_stream_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_multi_2((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_multi_stream_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_multi_4((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_stream_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_space_write_1((t), (h), (o), (v))
end_define

begin_define
define|#
directive|define
name|bus_space_write_stream_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_space_write_2((t), (h), (o), (v))
end_define

begin_define
define|#
directive|define
name|bus_space_write_stream_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_space_write_4((t), (h), (o), (v))
end_define

begin_define
define|#
directive|define
name|bus_space_write_multi_stream_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_multi_1((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_multi_stream_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_multi_2((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_multi_stream_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_multi_4((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_multi_stream_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_multi_1((t), (h), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_multi_stream_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_multi_2((t), (h), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_multi_stream_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_multi_4((t), (h), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_region_stream_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_region_1((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_region_stream_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_region_2((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_read_region_stream_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_region_4((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_region_stream_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_region_1((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_region_stream_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_region_2((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_write_region_stream_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_region_4((t), (h), (o), (a), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_region_stream_1
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_1((t), (h), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_region_stream_2
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_2((t), (h), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_set_region_stream_4
parameter_list|(
name|t
parameter_list|,
name|h
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_4((t), (h), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_copy_region_stream_1
parameter_list|(
name|t
parameter_list|,
name|h1
parameter_list|,
name|o1
parameter_list|,
name|h2
parameter_list|,
name|o2
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_copy_region_1((t), (h1), (o1), (h2), (o2), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_copy_region_stream_2
parameter_list|(
name|t
parameter_list|,
name|h1
parameter_list|,
name|o1
parameter_list|,
name|h2
parameter_list|,
name|o2
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_copy_region_2((t), (h1), (o1), (h2), (o2), (c))
end_define

begin_define
define|#
directive|define
name|bus_space_copy_region_stream_4
parameter_list|(
name|t
parameter_list|,
name|h1
parameter_list|,
name|o1
parameter_list|,
name|h2
parameter_list|,
name|o2
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_copy_region_4((t), (h1), (o1), (h2), (o2), (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_BUS_H_ */
end_comment

end_unit

