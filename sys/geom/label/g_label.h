begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004-2005 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_G_LABEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_G_LABEL_H_
end_define

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|G_LABEL_CLASS_NAME
value|"LABEL"
end_define

begin_define
define|#
directive|define
name|G_LABEL_MAGIC
value|"GEOM::LABEL"
end_define

begin_comment
comment|/*  * Version history:  * 1 - Initial version number.  * 2 - Added md_provsize field to metadata.  */
end_comment

begin_define
define|#
directive|define
name|G_LABEL_VERSION
value|2
end_define

begin_define
define|#
directive|define
name|G_LABEL_DIR
value|"label"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|u_int
name|g_label_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|G_LABEL_DEBUG
parameter_list|(
name|lvl
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	if (g_label_debug>= (lvl)) {					\ 		printf("GEOM_LABEL");					\ 		if (g_label_debug> 0)					\ 			printf("[%u]", lvl);				\ 		printf(": ");						\ 		printf(__VA_ARGS__);					\ 		printf("\n");						\ 	}								\ } while (0)
end_define

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_geom_label
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|G_LABEL_INIT
parameter_list|(
name|kind
parameter_list|,
name|label
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_NODE(_kern_geom_label, OID_AUTO, kind, CTLFLAG_RD,	\ 	    NULL, "");							\ 	SYSCTL_INT(_kern_geom_label_##kind, OID_AUTO, enable, 		\ 	    CTLFLAG_RW,&label.ld_enabled, 1, descr);			\ 	TUNABLE_INT("kern.geom.label." __XSTRING(kind) ".enable",	\&label.ld_enabled)
end_define

begin_typedef
typedef|typedef
name|void
name|g_label_taste_t
parameter_list|(
name|struct
name|g_consumer
modifier|*
name|cp
parameter_list|,
name|char
modifier|*
name|label
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|g_label_desc
block|{
name|g_label_taste_t
modifier|*
name|ld_taste
decl_stmt|;
name|char
modifier|*
name|ld_dir
decl_stmt|;
name|int
name|ld_enabled
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Supported labels. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|g_label_desc
name|g_label_ufs_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|g_label_desc
name|g_label_ufs_volume
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|g_label_desc
name|g_label_iso9660
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|g_label_desc
name|g_label_msdosfs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|g_label_desc
name|g_label_ext2fs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|g_label_desc
name|g_label_reiserfs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|g_label_desc
name|g_label_ntfs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|g_label_desc
name|g_label_gpt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|g_label_desc
name|g_label_gpt_uuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_struct
struct|struct
name|g_label_metadata
block|{
name|char
name|md_magic
index|[
literal|16
index|]
decl_stmt|;
comment|/* Magic value. */
name|uint32_t
name|md_version
decl_stmt|;
comment|/* Version number. */
name|char
name|md_label
index|[
literal|16
index|]
decl_stmt|;
comment|/* Label. */
name|uint64_t
name|md_provsize
decl_stmt|;
comment|/* Provider's size. */
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|void
name|label_metadata_encode
parameter_list|(
specifier|const
name|struct
name|g_label_metadata
modifier|*
name|md
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|)
block|{
name|bcopy
argument_list|(
name|md
operator|->
name|md_magic
argument_list|,
name|data
argument_list|,
sizeof|sizeof
argument_list|(
name|md
operator|->
name|md_magic
argument_list|)
argument_list|)
expr_stmt|;
name|le32enc
argument_list|(
name|data
operator|+
literal|16
argument_list|,
name|md
operator|->
name|md_version
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|md
operator|->
name|md_label
argument_list|,
name|data
operator|+
literal|20
argument_list|,
sizeof|sizeof
argument_list|(
name|md
operator|->
name|md_label
argument_list|)
argument_list|)
expr_stmt|;
name|le64enc
argument_list|(
name|data
operator|+
literal|36
argument_list|,
name|md
operator|->
name|md_provsize
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|label_metadata_decode
parameter_list|(
specifier|const
name|u_char
modifier|*
name|data
parameter_list|,
name|struct
name|g_label_metadata
modifier|*
name|md
parameter_list|)
block|{
name|bcopy
argument_list|(
name|data
argument_list|,
name|md
operator|->
name|md_magic
argument_list|,
sizeof|sizeof
argument_list|(
name|md
operator|->
name|md_magic
argument_list|)
argument_list|)
expr_stmt|;
name|md
operator|->
name|md_version
operator|=
name|le32dec
argument_list|(
name|data
operator|+
literal|16
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|data
operator|+
literal|20
argument_list|,
name|md
operator|->
name|md_label
argument_list|,
sizeof|sizeof
argument_list|(
name|md
operator|->
name|md_label
argument_list|)
argument_list|)
expr_stmt|;
name|md
operator|->
name|md_provsize
operator|=
name|le64dec
argument_list|(
name|data
operator|+
literal|36
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _G_LABEL_H_ */
end_comment

end_unit

