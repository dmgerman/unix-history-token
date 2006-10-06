begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Ruslan Ermilov<ru@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_G_CACHE_H_
end_ifndef

begin_define
define|#
directive|define
name|_G_CACHE_H_
end_define

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_define
define|#
directive|define
name|G_CACHE_CLASS_NAME
value|"CACHE"
end_define

begin_define
define|#
directive|define
name|G_CACHE_MAGIC
value|"GEOM::CACHE"
end_define

begin_define
define|#
directive|define
name|G_CACHE_VERSION
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|G_CACHE_TYPE_MANUAL
value|0
end_define

begin_define
define|#
directive|define
name|G_CACHE_TYPE_AUTOMATIC
value|1
end_define

begin_define
define|#
directive|define
name|G_CACHE_DEBUG
parameter_list|(
name|lvl
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	if (g_cache_debug>= (lvl)) {					\ 		printf("GEOM_CACHE");					\ 		if (g_cache_debug> 0)					\ 			printf("[%u]", lvl);				\ 		printf(": ");						\ 		printf(__VA_ARGS__);					\ 		printf("\n");						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|G_CACHE_LOGREQ
parameter_list|(
name|bp
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	if (g_cache_debug>= 2) {					\ 		printf("GEOM_CACHE[2]: ");				\ 		printf(__VA_ARGS__);					\ 		printf(" ");						\ 		g_print_bio(bp);					\ 		printf("\n");						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|G_CACHE_BUCKETS
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|G_CACHE_BUCKET
parameter_list|(
name|bno
parameter_list|)
value|((bno)& (G_CACHE_BUCKETS - 1))
end_define

begin_struct
struct|struct
name|g_cache_softc
block|{
name|struct
name|g_geom
modifier|*
name|sc_geom
decl_stmt|;
name|int
name|sc_type
decl_stmt|;
name|u_int
name|sc_bshift
decl_stmt|;
name|u_int
name|sc_bsize
decl_stmt|;
name|off_t
name|sc_tail
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|callout
name|sc_callout
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|g_cache_desc
argument_list|)
name|sc_desclist
index|[
name|G_CACHE_BUCKETS
index|]
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|g_cache_desc
argument_list|)
name|sc_usedlist
expr_stmt|;
name|uma_zone_t
name|sc_zone
decl_stmt|;
name|u_int
name|sc_maxent
decl_stmt|;
comment|/* max entries */
name|u_int
name|sc_nent
decl_stmt|;
comment|/* allocated entries */
name|u_int
name|sc_nused
decl_stmt|;
comment|/* re-useable entries */
name|u_int
name|sc_invalid
decl_stmt|;
comment|/* invalid entries */
name|uintmax_t
name|sc_reads
decl_stmt|;
comment|/* #reads */
name|uintmax_t
name|sc_readbytes
decl_stmt|;
comment|/* bytes read */
name|uintmax_t
name|sc_cachereads
decl_stmt|;
comment|/* #reads from cache */
name|uintmax_t
name|sc_cachereadbytes
decl_stmt|;
comment|/* bytes read from cache */
name|uintmax_t
name|sc_cachehits
decl_stmt|;
comment|/* cache hits */
name|uintmax_t
name|sc_cachemisses
decl_stmt|;
comment|/* cache misses */
name|uintmax_t
name|sc_cachefull
decl_stmt|;
comment|/* #times a cache was full */
name|uintmax_t
name|sc_writes
decl_stmt|;
comment|/* #writes */
name|uintmax_t
name|sc_wrotebytes
decl_stmt|;
comment|/* bytes written */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sc_name
value|sc_geom->name
end_define

begin_struct
struct|struct
name|g_cache_desc
block|{
name|off_t
name|d_bno
decl_stmt|;
comment|/* block number */
name|caddr_t
name|d_data
decl_stmt|;
comment|/* data area */
name|struct
name|bio
modifier|*
name|d_biolist
decl_stmt|;
comment|/* waiters */
name|time_t
name|d_atime
decl_stmt|;
comment|/* access time */
name|int
name|d_flags
decl_stmt|;
comment|/* flags */
define|#
directive|define
name|D_FLAG_USED
value|(1<< 0)
comment|/* can be reused */
define|#
directive|define
name|D_FLAG_INVALID
value|(1<< 1)
comment|/* invalid */
name|LIST_ENTRY
argument_list|(
argument|g_cache_desc
argument_list|)
name|d_next
expr_stmt|;
comment|/* list */
name|TAILQ_ENTRY
argument_list|(
argument|g_cache_desc
argument_list|)
name|d_used
expr_stmt|;
comment|/* used list */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|G_CACHE_NEXT_BIO1
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_driver1
end_define

begin_define
define|#
directive|define
name|G_CACHE_NEXT_BIO2
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_driver2
end_define

begin_define
define|#
directive|define
name|G_CACHE_DESC1
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_caller1
end_define

begin_define
define|#
directive|define
name|G_CACHE_DESC2
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_caller2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_struct
struct|struct
name|g_cache_metadata
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
name|md_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* Cache value. */
name|uint32_t
name|md_bsize
decl_stmt|;
comment|/* Cache block size. */
name|uint32_t
name|md_size
decl_stmt|;
comment|/* Cache size. */
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
name|cache_metadata_encode
parameter_list|(
specifier|const
name|struct
name|g_cache_metadata
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
name|md_name
argument_list|,
name|data
operator|+
literal|20
argument_list|,
sizeof|sizeof
argument_list|(
name|md
operator|->
name|md_name
argument_list|)
argument_list|)
expr_stmt|;
name|le32enc
argument_list|(
name|data
operator|+
literal|36
argument_list|,
name|md
operator|->
name|md_bsize
argument_list|)
expr_stmt|;
name|le32enc
argument_list|(
name|data
operator|+
literal|40
argument_list|,
name|md
operator|->
name|md_size
argument_list|)
expr_stmt|;
name|le64enc
argument_list|(
name|data
operator|+
literal|44
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
name|cache_metadata_decode
parameter_list|(
specifier|const
name|u_char
modifier|*
name|data
parameter_list|,
name|struct
name|g_cache_metadata
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
name|md_name
argument_list|,
sizeof|sizeof
argument_list|(
name|md
operator|->
name|md_name
argument_list|)
argument_list|)
expr_stmt|;
name|md
operator|->
name|md_bsize
operator|=
name|le32dec
argument_list|(
name|data
operator|+
literal|36
argument_list|)
expr_stmt|;
name|md
operator|->
name|md_size
operator|=
name|le16dec
argument_list|(
name|data
operator|+
literal|40
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
literal|44
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _G_CACHE_H_ */
end_comment

end_unit

