begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016 Maxim Sobolev<sobomax@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct_decl
struct_decl|struct
name|mkuz_fifo_queue
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|ITEMS_PER_WORKER
value|4
end_define

begin_define
define|#
directive|define
name|MAX_WORKERS_AUTO
value|24
end_define

begin_struct
struct|struct
name|mkuz_conveyor
block|{
comment|/*      * Work items are places in here, and picked up by workers in a FIFO      * fashion.      */
name|struct
name|mkuz_fifo_queue
modifier|*
name|wrk_queue
decl_stmt|;
comment|/*      * Results are dropped into this FIFO and consumer is buzzed to pick them      * up      */
name|struct
name|mkuz_fifo_queue
modifier|*
name|results
decl_stmt|;
name|pthread_t
name|wthreads
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|mkuz_cfg
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|mkuz_conveyor
modifier|*
name|mkuz_conveyor_ctor
parameter_list|(
name|struct
name|mkuz_cfg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

