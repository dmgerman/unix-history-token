begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NecBSD: busiosubr.c,v 1.30.4.4 1999/08/28 02:25:35 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1996, 1997, 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *  * [Ported for FreeBSD]  *  Copyright (c) 2001  *	TAKAHASHI Yoshihiro. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997, 1998  *	Naofumi HONDA.  All rights reserved.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|SBUS_DA_io
argument_list|,
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|SBUS_DA_io
argument_list|,
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|SBUS_DA_io
argument_list|,
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|SBUS_DA_mem
argument_list|,
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|SBUS_DA_mem
argument_list|,
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|SBUS_DA_mem
argument_list|,
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|SBUS_RA_io
argument_list|,
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|SBUS_RA_io
argument_list|,
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|SBUS_RA_io
argument_list|,
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|SBUS_RA_mem
argument_list|,
argument|u_int8_t
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|SBUS_RA_mem
argument_list|,
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|SBUS_RA_mem
argument_list|,
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|bus_space_tag
name|SBUS_io_space_tag
init|=
block|{
name|BUS_SPACE_IO
block|,
comment|/* direct bus access methods */
block|{
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_DA_io
argument_list|,
name|u_int8_t
argument_list|,
literal|1
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_DA_io
argument_list|,
name|u_int16_t
argument_list|,
literal|2
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_DA_io
argument_list|,
name|u_int32_t
argument_list|,
literal|4
argument_list|)
block|, 	}
block|,
comment|/* relocate bus access methods */
block|{
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_RA_io
argument_list|,
name|u_int8_t
argument_list|,
literal|1
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_RA_io
argument_list|,
name|u_int16_t
argument_list|,
literal|2
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_RA_io
argument_list|,
name|u_int32_t
argument_list|,
literal|4
argument_list|)
block|, 	}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bus_space_tag
name|SBUS_mem_space_tag
init|=
block|{
name|BUS_SPACE_MEM
block|,
comment|/* direct bus access methods */
block|{
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_DA_mem
argument_list|,
name|u_int8_t
argument_list|,
literal|1
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_DA_mem
argument_list|,
name|u_int16_t
argument_list|,
literal|2
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_DA_mem
argument_list|,
name|u_int32_t
argument_list|,
literal|4
argument_list|)
block|, 	}
block|,
comment|/* relocate bus access methods */
block|{
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_RA_mem
argument_list|,
name|u_int8_t
argument_list|,
literal|1
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_RA_mem
argument_list|,
name|u_int16_t
argument_list|,
literal|2
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_RA_mem
argument_list|,
name|u_int32_t
argument_list|,
literal|4
argument_list|)
block|, 	}
block|}
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"opt_mecia.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEV_MECIA
end_ifdef

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|NEPC_DA_io
argument_list|,
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|NEPC_DA_io
argument_list|,
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|NEPC_RA_io
argument_list|,
argument|u_int16_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|_BUS_SPACE_CALL_FUNCS_PROTO
argument_list|(
argument|NEPC_RA_io
argument_list|,
argument|u_int32_t
argument_list|,
literal|4
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|bus_space_tag
name|NEPC_io_space_tag
init|=
block|{
name|BUS_SPACE_IO
block|,
comment|/* direct bus access methods */
block|{
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_DA_io
argument_list|,
name|u_int8_t
argument_list|,
literal|1
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|NEPC_DA_io
argument_list|,
name|u_int16_t
argument_list|,
literal|2
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|NEPC_DA_io
argument_list|,
name|u_int32_t
argument_list|,
literal|4
argument_list|)
block|, 	}
block|,
comment|/* relocate bus access methods */
block|{
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_RA_io
argument_list|,
name|u_int8_t
argument_list|,
literal|1
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|NEPC_RA_io
argument_list|,
name|u_int16_t
argument_list|,
literal|2
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|NEPC_RA_io
argument_list|,
name|u_int32_t
argument_list|,
literal|4
argument_list|)
block|, 	}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bus_space_tag
name|NEPC_mem_space_tag
init|=
block|{
name|BUS_SPACE_MEM
block|,
comment|/* direct bus access methods */
block|{
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_DA_mem
argument_list|,
name|u_int8_t
argument_list|,
literal|1
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_DA_mem
argument_list|,
name|u_int16_t
argument_list|,
literal|2
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_DA_mem
argument_list|,
name|u_int32_t
argument_list|,
literal|4
argument_list|)
block|, 	}
block|,
comment|/* relocate bus access methods */
block|{
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_RA_mem
argument_list|,
name|u_int8_t
argument_list|,
literal|1
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_RA_mem
argument_list|,
name|u_int16_t
argument_list|,
literal|2
argument_list|)
block|,
name|_BUS_SPACE_CALL_FUNCS_TAB
argument_list|(
name|SBUS_RA_mem
argument_list|,
name|u_int32_t
argument_list|,
literal|4
argument_list|)
block|, 	}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_MECIA */
end_comment

end_unit

