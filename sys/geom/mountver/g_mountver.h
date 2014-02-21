begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Edward Tomasz Napierala<trasz@FreeBSD.org>  * Copyright (c) 2004-2006 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_G_MOUNTVER_H_
end_ifndef

begin_define
define|#
directive|define
name|_G_MOUNTVER_H_
end_define

begin_define
define|#
directive|define
name|G_MOUNTVER_CLASS_NAME
value|"MOUNTVER"
end_define

begin_define
define|#
directive|define
name|G_MOUNTVER_VERSION
value|4
end_define

begin_define
define|#
directive|define
name|G_MOUNTVER_SUFFIX
value|".mountver"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|G_MOUNTVER_DEBUG
parameter_list|(
name|lvl
parameter_list|,
modifier|...
parameter_list|)
value|do {				\ 	if (g_mountver_debug>= (lvl)) {				\ 		printf("GEOM_MOUNTVER");				\ 		if (g_mountver_debug> 0)				\ 			printf("[%u]", lvl);				\ 		printf(": ");						\ 		printf(__VA_ARGS__);					\ 		printf("\n");						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|G_MOUNTVER_LOGREQ
parameter_list|(
name|bp
parameter_list|,
modifier|...
parameter_list|)
value|do {				\ 	if (g_mountver_debug>= 2) {					\ 		printf("GEOM_MOUNTVER[2]: ");				\ 		printf(__VA_ARGS__);					\ 		printf(" ");						\ 		g_print_bio(bp);					\ 		printf("\n");						\ 	}								\ } while (0)
end_define

begin_struct
struct|struct
name|g_mountver_softc
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|bio
argument_list|)
name|sc_queue
expr_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|char
modifier|*
name|sc_provider_name
decl_stmt|;
name|char
name|sc_ident
index|[
name|DISK_IDENT_SIZE
index|]
decl_stmt|;
name|int
name|sc_orphaned
decl_stmt|;
name|int
name|sc_access_r
decl_stmt|;
name|int
name|sc_access_w
decl_stmt|;
name|int
name|sc_access_e
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
comment|/* _G_MOUNTVER_H_ */
end_comment

end_unit

