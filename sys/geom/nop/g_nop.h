begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004-2006 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_G_NOP_H_
end_ifndef

begin_define
define|#
directive|define
name|_G_NOP_H_
end_define

begin_define
define|#
directive|define
name|G_NOP_CLASS_NAME
value|"NOP"
end_define

begin_define
define|#
directive|define
name|G_NOP_VERSION
value|4
end_define

begin_define
define|#
directive|define
name|G_NOP_SUFFIX
value|".nop"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|G_NOP_DEBUG
parameter_list|(
name|lvl
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	if (g_nop_debug>= (lvl)) {					\ 		printf("GEOM_NOP");					\ 		if (g_nop_debug> 0)					\ 			printf("[%u]", lvl);				\ 		printf(": ");						\ 		printf(__VA_ARGS__);					\ 		printf("\n");						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|G_NOP_LOGREQ
parameter_list|(
name|bp
parameter_list|,
modifier|...
parameter_list|)
value|G_NOP_LOGREQLVL(2, bp, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|G_NOP_LOGREQLVL
parameter_list|(
name|lvl
parameter_list|,
name|bp
parameter_list|,
modifier|...
parameter_list|)
value|do {				\ 	if (g_nop_debug>= (lvl)) {					\ 		printf("GEOM_NOP[%d]: ", (lvl));			\ 		printf(__VA_ARGS__);					\ 		printf(" ");						\ 		g_print_bio(bp);					\ 		printf("\n");						\ 	}								\ } while (0)
end_define

begin_struct
struct|struct
name|g_nop_softc
block|{
name|int
name|sc_error
decl_stmt|;
name|off_t
name|sc_offset
decl_stmt|;
name|off_t
name|sc_explicitsize
decl_stmt|;
name|u_int
name|sc_rfailprob
decl_stmt|;
name|u_int
name|sc_wfailprob
decl_stmt|;
name|uintmax_t
name|sc_reads
decl_stmt|;
name|uintmax_t
name|sc_writes
decl_stmt|;
name|uintmax_t
name|sc_readbytes
decl_stmt|;
name|uintmax_t
name|sc_wrotebytes
decl_stmt|;
name|struct
name|mtx
name|sc_lock
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* _G_NOP_H_ */
end_comment

end_unit

