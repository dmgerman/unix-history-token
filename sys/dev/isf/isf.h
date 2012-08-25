begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Robert N. M. Watson  * Copyright (c) 2012 SRI International  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ISF_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ISF_H_
end_define

begin_struct
struct|struct
name|isf_range
block|{
name|off_t
name|ir_off
decl_stmt|;
comment|/* Offset of range to delete (set to 0xFF) */
name|size_t
name|ir_size
decl_stmt|;
comment|/* Size of range */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISF_ERASE
value|_IOW('I', 1, struct isf_range)
end_define

begin_comment
comment|/*  * Ordinary read and write operations are limited to 512 bytes.  * We support erasing 128K blocks and ignore the fact that portions of the  * flash are in fact divided into 32K blocks.  */
end_comment

begin_define
define|#
directive|define
name|ISF_SECTORSIZE
value|(512)
end_define

begin_define
define|#
directive|define
name|ISF_ERASE_BLOCK
value|(128 * 1024)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ISF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
name|bstate
block|{
name|BS_STEADY
init|=
literal|0
block|,
name|BS_ERASING
block|}
enum|;
end_enum

begin_struct
struct|struct
name|isf_softc
block|{
name|device_t
name|isf_dev
decl_stmt|;
name|int
name|isf_unit
decl_stmt|;
name|struct
name|resource
modifier|*
name|isf_res
decl_stmt|;
name|int
name|isf_rid
decl_stmt|;
name|struct
name|mtx
name|isf_lock
decl_stmt|;
name|struct
name|disk
modifier|*
name|isf_disk
decl_stmt|;
name|struct
name|proc
modifier|*
name|isf_proc
decl_stmt|;
name|int
name|isf_doomed
decl_stmt|;
comment|/* 	 * Fields relating to in-progress and pending I/O, if any. 	 */
name|struct
name|bio_queue_head
name|isf_bioq
decl_stmt|;
name|uint16_t
name|isf_rbuf
index|[
name|ISF_SECTORSIZE
operator|/
literal|2
index|]
decl_stmt|;
name|int
name|isf_erasing
decl_stmt|;
name|enum
name|bstate
modifier|*
name|isf_bstate
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISF_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->isf_lock)
end_define

begin_define
define|#
directive|define
name|ISF_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->isf_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ISF_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->isf_lock)
end_define

begin_define
define|#
directive|define
name|ISF_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
value|mtx_init(&(sc)->isf_lock, "isf", NULL,	\ 				    MTX_DEF)
end_define

begin_define
define|#
directive|define
name|ISF_SLEEP
parameter_list|(
name|sc
parameter_list|,
name|wait
parameter_list|,
name|timo
parameter_list|)
value|mtx_sleep((wait), 		\&(sc)->isf_lock, PRIBIO, 	\ 					    "isf", (timo))
end_define

begin_define
define|#
directive|define
name|ISF_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->isf_lock)
end_define

begin_define
define|#
directive|define
name|ISF_WAKEUP
parameter_list|(
name|sc
parameter_list|)
value|wakeup((sc))
end_define

begin_function_decl
name|int
name|isf_attach
parameter_list|(
name|struct
name|isf_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isf_detach
parameter_list|(
name|struct
name|isf_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ISF_H_ */
end_comment

end_unit

