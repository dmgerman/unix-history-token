begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Poul-Henning Kamp  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GEOM_GEOM_STATS_H_
end_ifndef

begin_define
define|#
directive|define
name|_GEOM_GEOM_STATS_H_
end_define

begin_define
define|#
directive|define
name|GEOM_STATS_DEVICE
value|"geom.stats"
end_define

begin_comment
comment|/*  * A g_stat contains the statistics the kernel collect on consumers and  * providers.  See libgeom(3) for how to get hold of these.  */
end_comment

begin_struct
struct|struct
name|g_stat
block|{
name|int
name|updating
decl_stmt|;
comment|/* 				 * If non-zero, the structure is being 				 * updated by the kernel and the contents 				 * should not be used. 				 */
name|void
modifier|*
name|id
decl_stmt|;
comment|/* GEOM-identifier for the consumer/provider */
name|uint64_t
name|nop
decl_stmt|;
comment|/* Number of requests started */
name|uint64_t
name|nend
decl_stmt|;
comment|/* Number of requests completed */
name|struct
name|bintime
name|bt
decl_stmt|;
comment|/* Accumulated busy time */
name|struct
name|bintime
name|wentbusy
decl_stmt|;
comment|/* Busy time accounted for until here */
struct|struct
block|{
name|uint64_t
name|nop
decl_stmt|;
comment|/* Number of requests completed */
name|uint64_t
name|nbyte
decl_stmt|;
comment|/* Number of bytes completed */
name|uint64_t
name|nmem
decl_stmt|;
comment|/* Number of ENOMEM request errors */
name|uint64_t
name|nerr
decl_stmt|;
comment|/* Number of other request errors */
name|struct
name|bintime
name|dt
decl_stmt|;
comment|/* Accumulated request processing time */
block|}
name|ops
index|[
literal|3
index|]
struct|;
define|#
directive|define
name|G_STAT_IDX_READ
value|0
define|#
directive|define
name|G_STAT_IDX_WRITE
value|1
define|#
directive|define
name|G_STAT_IDX_DELETE
value|2
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GEOM_GEOM_STATS_H_ */
end_comment

end_unit

