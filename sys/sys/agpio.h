begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_AGPIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_AGPIO_H_
end_define

begin_comment
comment|/*  * The AGP gatt uses 4k pages irrespective of the host page size.  */
end_comment

begin_define
define|#
directive|define
name|AGP_PAGE_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|AGP_PAGE_SHIFT
value|12
end_define

begin_comment
comment|/*  * Macros to manipulate AGP mode words.  */
end_comment

begin_define
define|#
directive|define
name|AGP_MODE_GET_RQ
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xff000000U)>> 24)
end_define

begin_define
define|#
directive|define
name|AGP_MODE_GET_SBA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x00000200U)>> 9)
end_define

begin_define
define|#
directive|define
name|AGP_MODE_GET_AGP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x00000100U)>> 8)
end_define

begin_define
define|#
directive|define
name|AGP_MODE_GET_4G
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x00000020U)>> 5)
end_define

begin_define
define|#
directive|define
name|AGP_MODE_GET_FW
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x00000010U)>> 4)
end_define

begin_define
define|#
directive|define
name|AGP_MODE_GET_RATE
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x00000007U)
end_define

begin_define
define|#
directive|define
name|AGP_MODE_SET_RQ
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|(((x)& ~0xff000000U) | ((v)<< 24))
end_define

begin_define
define|#
directive|define
name|AGP_MODE_SET_SBA
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|(((x)& ~0x00000200U) | ((v)<< 9))
end_define

begin_define
define|#
directive|define
name|AGP_MODE_SET_AGP
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|(((x)& ~0x00000100U) | ((v)<< 8))
end_define

begin_define
define|#
directive|define
name|AGP_MODE_SET_4G
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|(((x)& ~0x00000020U) | ((v)<< 5))
end_define

begin_define
define|#
directive|define
name|AGP_MODE_SET_FW
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|(((x)& ~0x00000010U) | ((v)<< 4))
end_define

begin_define
define|#
directive|define
name|AGP_MODE_SET_RATE
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|(((x)& ~0x00000007U) | (v))
end_define

begin_define
define|#
directive|define
name|AGP_MODE_RATE_1x
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AGP_MODE_RATE_2x
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AGP_MODE_RATE_4x
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AGPIOC_BASE
value|'A'
end_define

begin_define
define|#
directive|define
name|AGPIOC_INFO
value|_IOR (AGPIOC_BASE, 0, agp_info)
end_define

begin_define
define|#
directive|define
name|AGPIOC_ACQUIRE
value|_IO  (AGPIOC_BASE, 1)
end_define

begin_define
define|#
directive|define
name|AGPIOC_RELEASE
value|_IO  (AGPIOC_BASE, 2)
end_define

begin_define
define|#
directive|define
name|AGPIOC_SETUP
value|_IOW (AGPIOC_BASE, 3, agp_setup)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|AGPIOC_RESERVE
value|_IOW (AGPIOC_BASE, 4, agp_region)
end_define

begin_define
define|#
directive|define
name|AGPIOC_PROTECT
value|_IOW (AGPIOC_BASE, 5, agp_region)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AGPIOC_ALLOCATE
value|_IOWR(AGPIOC_BASE, 6, agp_allocate)
end_define

begin_define
define|#
directive|define
name|AGPIOC_DEALLOCATE
value|_IOW (AGPIOC_BASE, 7, int)
end_define

begin_define
define|#
directive|define
name|AGPIOC_BIND
value|_IOW (AGPIOC_BASE, 8, agp_bind)
end_define

begin_define
define|#
directive|define
name|AGPIOC_UNBIND
value|_IOW (AGPIOC_BASE, 9, agp_unbind)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_agp_version
block|{
name|u_int16_t
name|major
decl_stmt|;
name|u_int16_t
name|minor
decl_stmt|;
block|}
name|agp_version
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_agp_info
block|{
name|agp_version
name|version
decl_stmt|;
comment|/* version of the driver        */
name|u_int32_t
name|bridge_id
decl_stmt|;
comment|/* bridge vendor/device         */
name|u_int32_t
name|agp_mode
decl_stmt|;
comment|/* mode info of bridge          */
name|off_t
name|aper_base
decl_stmt|;
comment|/* base of aperture             */
name|size_t
name|aper_size
decl_stmt|;
comment|/* size of aperture             */
name|size_t
name|pg_total
decl_stmt|;
comment|/* max pages (swap + system)    */
name|size_t
name|pg_system
decl_stmt|;
comment|/* max pages (system)           */
name|size_t
name|pg_used
decl_stmt|;
comment|/* current pages used           */
block|}
name|agp_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_agp_setup
block|{
name|u_int32_t
name|agp_mode
decl_stmt|;
comment|/* mode info of bridge          */
block|}
name|agp_setup
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * The "prot" down below needs still a "sleep" flag somehow ...  */
end_comment

begin_comment
unit|typedef struct _agp_segment { 	off_t pg_start;
comment|/* starting page to populate    */
end_comment

begin_comment
unit|size_t pg_count;
comment|/* number of pages              */
end_comment

begin_comment
unit|int prot;
comment|/* prot flags for mmap          */
end_comment

begin_comment
unit|} agp_segment;  typedef struct _agp_region { 	pid_t pid;
comment|/* pid of process               */
end_comment

begin_comment
unit|size_t seg_count;
comment|/* number of segments           */
end_comment

begin_endif
unit|struct _agp_segment *seg_list; } agp_region;
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_agp_allocate
block|{
name|int
name|key
decl_stmt|;
comment|/* tag of allocation            */
name|size_t
name|pg_count
decl_stmt|;
comment|/* number of pages              */
name|u_int32_t
name|type
decl_stmt|;
comment|/* 0 == normal, other devspec   */
name|u_int32_t
name|physical
decl_stmt|;
comment|/* device specific (some devices   				 * need a phys address of the      				 * actual page behind the gatt     				 * table)                        */
block|}
name|agp_allocate
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_agp_bind
block|{
name|int
name|key
decl_stmt|;
comment|/* tag of allocation            */
name|off_t
name|pg_start
decl_stmt|;
comment|/* starting page to populate    */
block|}
name|agp_bind
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_agp_unbind
block|{
name|int
name|key
decl_stmt|;
comment|/* tag of allocation            */
name|u_int32_t
name|priority
decl_stmt|;
comment|/* priority for paging out      */
block|}
name|agp_unbind
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_AGPIO_H_ */
end_comment

end_unit

