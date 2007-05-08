begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006, 2007 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GEOM_PART_H_
end_ifndef

begin_define
define|#
directive|define
name|_GEOM_PART_H_
end_define

begin_define
define|#
directive|define
name|G_PART_TRACE
parameter_list|(
name|args
parameter_list|)
value|g_trace args
end_define

begin_define
define|#
directive|define
name|G_PART_PROBE_PRI_LOW
value|-10
end_define

begin_define
define|#
directive|define
name|G_PART_PROBE_PRI_NORM
value|-5
end_define

begin_define
define|#
directive|define
name|G_PART_PROBE_PRI_HIGH
value|0
end_define

begin_enum
enum|enum
name|g_part_alias
block|{
name|G_PART_ALIAS_EFI
block|,
comment|/* A EFI system partition entry. */
name|G_PART_ALIAS_FREEBSD
block|,
comment|/* A BSD labeled partition entry. */
name|G_PART_ALIAS_FREEBSD_SWAP
block|,
comment|/* A swap partition entry. */
name|G_PART_ALIAS_FREEBSD_UFS
block|,
comment|/* A UFS/UFS2 file system entry. */
name|G_PART_ALIAS_FREEBSD_VINUM
block|,
comment|/* A Vinum partition entry. */
name|G_PART_ALIAS_MBR
block|,
comment|/* A MBR (extended) partition entry. */
comment|/* Keep the following last */
name|G_PART_ALIAS_COUNT
block|}
enum|;
end_enum

begin_function_decl
specifier|const
name|char
modifier|*
name|g_part_alias_name
parameter_list|(
name|enum
name|g_part_alias
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* G_PART scheme (KOBJ class). */
end_comment

begin_struct
struct|struct
name|g_part_scheme
block|{
name|KOBJ_CLASS_FIELDS
expr_stmt|;
name|size_t
name|gps_entrysz
decl_stmt|;
name|int
name|gps_minent
decl_stmt|;
name|int
name|gps_maxent
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|G_PART_SCHEME_DECLARE
parameter_list|(
name|s
parameter_list|)
value|DATA_SET(g_part_scheme_set, s)
end_define

begin_struct
struct|struct
name|g_part_entry
block|{
name|LIST_ENTRY
argument_list|(
argument|g_part_entry
argument_list|)
name|gpe_entry
expr_stmt|;
name|struct
name|g_provider
modifier|*
name|gpe_pp
decl_stmt|;
comment|/* Corresponding provider. */
name|off_t
name|gpe_offset
decl_stmt|;
comment|/* Byte offset. */
name|quad_t
name|gpe_start
decl_stmt|;
comment|/* First LBA of partition. */
name|quad_t
name|gpe_end
decl_stmt|;
comment|/* Last LBA of partition. */
name|int
name|gpe_index
decl_stmt|;
name|int
name|gpe_created
range|:
literal|1
decl_stmt|;
comment|/* Entry is newly created. */
name|int
name|gpe_deleted
range|:
literal|1
decl_stmt|;
comment|/* Entry has been deleted. */
name|int
name|gpe_modified
range|:
literal|1
decl_stmt|;
comment|/* Entry has been modified. */
block|}
struct|;
end_struct

begin_comment
comment|/* G_PART table (KOBJ instance). */
end_comment

begin_struct
struct|struct
name|g_part_table
block|{
name|KOBJ_FIELDS
expr_stmt|;
name|struct
name|g_part_scheme
modifier|*
name|gpt_scheme
decl_stmt|;
name|struct
name|g_geom
modifier|*
name|gpt_gp
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|g_part_entry
argument_list|)
name|gpt_entry
expr_stmt|;
name|quad_t
name|gpt_first
decl_stmt|;
comment|/* First allocatable LBA */
name|quad_t
name|gpt_last
decl_stmt|;
comment|/* Last allocatable LBA */
name|int
name|gpt_entries
decl_stmt|;
comment|/* 	 * gpt_smhead and gpt_smtail are bitmaps representing the first 	 * 32 sectors on the disk (gpt_smhead) and the last 32 sectors 	 * on the disk (gpt_smtail). These maps are used by the commit 	 * verb to clear sectors previously used by a scheme after the 	 * partitioning scheme has been destroyed. 	 */
name|uint32_t
name|gpt_smhead
decl_stmt|;
name|uint32_t
name|gpt_smtail
decl_stmt|;
name|int
name|gpt_depth
decl_stmt|;
comment|/* Sub-partitioning level. */
name|int
name|gpt_isleaf
range|:
literal|1
decl_stmt|;
comment|/* Cannot be sub-partitioned. */
name|int
name|gpt_created
range|:
literal|1
decl_stmt|;
comment|/* Newly created. */
name|int
name|gpt_modified
range|:
literal|1
decl_stmt|;
comment|/* Table changes have been made. */
name|int
name|gpt_opened
range|:
literal|1
decl_stmt|;
comment|/* Permissions obtained. */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|g_part_entry
modifier|*
name|g_part_new_entry
parameter_list|(
name|struct
name|g_part_table
modifier|*
parameter_list|,
name|int
parameter_list|,
name|quad_t
parameter_list|,
name|quad_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* G_PART ctlreq parameters. */
end_comment

begin_define
define|#
directive|define
name|G_PART_PARM_ENTRIES
value|0x0001
end_define

begin_define
define|#
directive|define
name|G_PART_PARM_FLAGS
value|0x0002
end_define

begin_define
define|#
directive|define
name|G_PART_PARM_GEOM
value|0x0004
end_define

begin_define
define|#
directive|define
name|G_PART_PARM_INDEX
value|0x0008
end_define

begin_define
define|#
directive|define
name|G_PART_PARM_LABEL
value|0x0010
end_define

begin_define
define|#
directive|define
name|G_PART_PARM_OUTPUT
value|0x0020
end_define

begin_define
define|#
directive|define
name|G_PART_PARM_PROVIDER
value|0x0040
end_define

begin_define
define|#
directive|define
name|G_PART_PARM_SCHEME
value|0x0080
end_define

begin_define
define|#
directive|define
name|G_PART_PARM_SIZE
value|0x0100
end_define

begin_define
define|#
directive|define
name|G_PART_PARM_START
value|0x0200
end_define

begin_define
define|#
directive|define
name|G_PART_PARM_TYPE
value|0x0400
end_define

begin_define
define|#
directive|define
name|G_PART_PARM_VERSION
value|0x0800
end_define

begin_struct
struct|struct
name|g_part_parms
block|{
name|unsigned
name|int
name|gpp_parms
decl_stmt|;
name|unsigned
name|int
name|gpp_entries
decl_stmt|;
specifier|const
name|char
modifier|*
name|gpp_flags
decl_stmt|;
name|struct
name|g_geom
modifier|*
name|gpp_geom
decl_stmt|;
name|unsigned
name|int
name|gpp_index
decl_stmt|;
specifier|const
name|char
modifier|*
name|gpp_label
decl_stmt|;
name|struct
name|g_provider
modifier|*
name|gpp_provider
decl_stmt|;
name|struct
name|g_part_scheme
modifier|*
name|gpp_scheme
decl_stmt|;
name|quad_t
name|gpp_size
decl_stmt|;
name|quad_t
name|gpp_start
decl_stmt|;
specifier|const
name|char
modifier|*
name|gpp_type
decl_stmt|;
name|unsigned
name|int
name|gpp_version
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_GEOM_PART_H_ */
end_comment

end_unit

