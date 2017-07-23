begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2007 Ivan Voras<ivoras@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_G_VIRSTOR_H_
end_ifndef

begin_define
define|#
directive|define
name|_G_VIRSTOR_H_
end_define

begin_define
define|#
directive|define
name|G_VIRSTOR_CLASS_NAME
value|"VIRSTOR"
end_define

begin_define
define|#
directive|define
name|VIRSTOR_MAP_ALLOCATED
value|1
end_define

begin_struct
struct|struct
name|virstor_map_entry
block|{
name|uint16_t
name|flags
decl_stmt|;
name|uint16_t
name|provider_no
decl_stmt|;
name|uint32_t
name|provider_chunk
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VIRSTOR_MAP_ENTRY_SIZE
value|(sizeof(struct virstor_map_entry))
end_define

begin_define
define|#
directive|define
name|VIRSTOR_MAP_BLOCK_ENTRIES
value|(MAXPHYS / VIRSTOR_MAP_ENTRY_SIZE)
end_define

begin_comment
comment|/* Struct size is guarded by CTASSERT in main source */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|LOG_MSG
parameter_list|(
name|lvl
parameter_list|,
modifier|...
parameter_list|)
value|do {					\         if (g_virstor_debug>= (lvl)) {					\                 printf("GEOM_" G_VIRSTOR_CLASS_NAME);			\                 if ((lvl)> 0)						\                         printf("[%u]", (lvl));				\                 printf(": ");						\                 printf(__VA_ARGS__);					\                 printf("\n");						\         }								\ } while (0)
end_define

begin_define
define|#
directive|define
name|LOG_MESSAGE
value|LOG_MSG
end_define

begin_define
define|#
directive|define
name|LOG_REQ
parameter_list|(
name|lvl
parameter_list|,
name|bp
parameter_list|,
modifier|...
parameter_list|)
value|do {					\         if (g_virstor_debug>= (lvl)) {					\                 printf("GEOM_" G_VIRSTOR_CLASS_NAME);			\                 if ((lvl)> 0)						\                         printf("[%u]", (lvl));				\                 printf(": ");						\                 printf(__VA_ARGS__);					\                 printf(" ");						\                 g_print_bio(bp);					\                 printf("\n");						\         }								\ } while (0)
end_define

begin_define
define|#
directive|define
name|LOG_REQUEST
value|LOG_REQ
end_define

begin_comment
comment|/* "critical" system announcements (e.g. "geom is up") */
end_comment

begin_define
define|#
directive|define
name|LVL_ANNOUNCE
value|0
end_define

begin_comment
comment|/* errors */
end_comment

begin_define
define|#
directive|define
name|LVL_ERROR
value|1
end_define

begin_comment
comment|/* warnings */
end_comment

begin_define
define|#
directive|define
name|LVL_WARNING
value|2
end_define

begin_comment
comment|/* info, noncritical for system operation (user doesn't have to see it */
end_comment

begin_define
define|#
directive|define
name|LVL_INFO
value|5
end_define

begin_comment
comment|/* debug info */
end_comment

begin_define
define|#
directive|define
name|LVL_DEBUG
value|10
end_define

begin_comment
comment|/* more debug info */
end_comment

begin_define
define|#
directive|define
name|LVL_DEBUG2
value|12
end_define

begin_comment
comment|/* superfluous debug info (large volumes of data) */
end_comment

begin_define
define|#
directive|define
name|LVL_MOREDEBUG
value|15
end_define

begin_comment
comment|/* Component data */
end_comment

begin_struct
struct|struct
name|g_virstor_component
block|{
name|struct
name|g_consumer
modifier|*
name|gcons
decl_stmt|;
name|struct
name|g_virstor_softc
modifier|*
name|sc
decl_stmt|;
name|unsigned
name|int
name|index
decl_stmt|;
comment|/* Component index in array */
name|unsigned
name|int
name|chunk_count
decl_stmt|;
name|unsigned
name|int
name|chunk_next
decl_stmt|;
name|unsigned
name|int
name|chunk_reserved
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Internal geom instance data */
end_comment

begin_struct
struct|struct
name|g_virstor_softc
block|{
name|struct
name|g_geom
modifier|*
name|geom
decl_stmt|;
name|struct
name|g_provider
modifier|*
name|provider
decl_stmt|;
name|struct
name|g_virstor_component
modifier|*
name|components
decl_stmt|;
name|u_int
name|n_components
decl_stmt|;
name|u_int
name|curr_component
decl_stmt|;
comment|/* Component currently used */
name|uint32_t
name|id
decl_stmt|;
comment|/* Unique ID of this geom */
name|off_t
name|virsize
decl_stmt|;
comment|/* Total size of virstor */
name|off_t
name|sectorsize
decl_stmt|;
name|size_t
name|chunk_size
decl_stmt|;
name|size_t
name|chunk_count
decl_stmt|;
comment|/* governs map_size */
name|struct
name|virstor_map_entry
modifier|*
name|map
decl_stmt|;
name|size_t
name|map_size
decl_stmt|;
comment|/* (in bytes) */
name|size_t
name|map_sectors
decl_stmt|;
comment|/* Size of map in sectors */
name|size_t
name|me_per_sector
decl_stmt|;
comment|/* # map entries in a sector */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|g_virstor_bio_q
argument_list|)
name|delayed_bio_q
expr_stmt|;
comment|/* Queue of delayed BIOs */
name|struct
name|mtx
name|delayed_bio_q_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* "delayed BIOs" Queue element */
end_comment

begin_struct
struct|struct
name|g_virstor_bio_q
block|{
name|struct
name|bio
modifier|*
name|bio
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|g_virstor_bio_q
argument_list|)
name|linkage
expr_stmt|;
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

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEV
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEV
value|"/dev/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_G_VIRSTOR_H_ */
end_comment

end_unit

