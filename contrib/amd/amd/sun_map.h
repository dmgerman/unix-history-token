begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2014 Erez Zadok  * Copyright (c) 2005 Daniel P. Ottavio  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/amd/sun_map.h  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SUN_MAP_H
end_ifndef

begin_define
define|#
directive|define
name|_SUN_MAP_H
end_define

begin_comment
comment|/* host */
end_comment

begin_struct
struct|struct
name|sun_host
block|{
name|qelem
name|head
decl_stmt|;
comment|/* link-list header */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* hostname */
name|int
name|weight
decl_stmt|;
comment|/* weight given to the host */
block|}
struct|;
end_struct

begin_comment
comment|/* location */
end_comment

begin_struct
struct|struct
name|sun_location
block|{
name|qelem
name|head
decl_stmt|;
comment|/* link-list header */
name|char
modifier|*
name|path
decl_stmt|;
comment|/* server path */
name|struct
name|sun_host
modifier|*
name|host_list
decl_stmt|;
comment|/* list of hosts */
block|}
struct|;
end_struct

begin_comment
comment|/* sun mount option */
end_comment

begin_struct
struct|struct
name|sun_opt
block|{
name|qelem
name|head
decl_stmt|;
comment|/* link-list header */
name|char
modifier|*
name|str
decl_stmt|;
comment|/* option string */
block|}
struct|;
end_struct

begin_comment
comment|/* mount point */
end_comment

begin_struct
struct|struct
name|sun_mountpt
block|{
name|qelem
name|head
decl_stmt|;
comment|/* link-list header */
name|char
modifier|*
name|path
decl_stmt|;
comment|/* optional mount point path */
name|char
modifier|*
name|fstype
decl_stmt|;
comment|/* filesystem type */
name|struct
name|sun_opt
modifier|*
name|opt_list
decl_stmt|;
comment|/* list of option strings */
name|struct
name|sun_location
modifier|*
name|location_list
decl_stmt|;
comment|/* list of 'struct s2a_location' */
block|}
struct|;
end_struct

begin_comment
comment|/* automount entry */
end_comment

begin_struct
struct|struct
name|sun_entry
block|{
name|qelem
name|head
decl_stmt|;
comment|/* link-list header */
name|char
modifier|*
name|key
decl_stmt|;
comment|/* auto map key */
name|char
modifier|*
name|fstype
decl_stmt|;
comment|/* filesystem type */
name|struct
name|sun_opt
modifier|*
name|opt_list
decl_stmt|;
comment|/* list of mount options */
name|struct
name|sun_location
modifier|*
name|location_list
decl_stmt|;
comment|/* list of mount locations */
name|struct
name|sun_mountpt
modifier|*
name|mountpt_list
decl_stmt|;
comment|/* list of mount points */
block|}
struct|;
end_struct

begin_comment
comment|/*  * automount map file  *  * XXX: Only a place holder structure, not implemented yet.  */
end_comment

begin_struct
struct|struct
name|sun_map
block|{
name|qelem
name|head
decl_stmt|;
comment|/* link-list header */
name|char
modifier|*
name|path
decl_stmt|;
comment|/* directory path of the map file */
name|char
modifier|*
name|mount_dir
decl_stmt|;
comment|/* top level mount point for this map */
name|int
name|lookup
decl_stmt|;
comment|/* lookup type i.e file, yp, program, etc. */
name|int
name|direct_bool
decl_stmt|;
comment|/* set true if this map is a direct map */
name|struct
name|sun_opt
modifier|*
name|opt_list
decl_stmt|;
comment|/* list of global map options */
name|struct
name|sun_opt
modifier|*
name|include_list
decl_stmt|;
comment|/* list of included map files  */
name|struct
name|sun_entry
modifier|*
name|entry_list
decl_stmt|;
comment|/* list of 'struct s2a_entry' */
block|}
struct|;
end_struct

begin_comment
comment|/*  * master map file  *  * XXX: Only a place holder structure, not implemented yet.  */
end_comment

begin_struct
struct|struct
name|sun_mmap
block|{
name|qelem
name|head
decl_stmt|;
comment|/* link-list header */
name|struct
name|sun_opt
modifier|*
name|include_list
decl_stmt|;
comment|/* list of included master maps */
name|struct
name|sun_map
modifier|*
name|amap_list
decl_stmt|;
comment|/* list of 'struct s2a_amap' */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sun_list
block|{
name|qelem
modifier|*
name|first
decl_stmt|;
name|qelem
modifier|*
name|last
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * EXTERNS  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|sun_entry2amd
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|sun_entry
modifier|*
name|sun_map_parse_read
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sun_list_add
parameter_list|(
name|struct
name|sun_list
modifier|*
parameter_list|,
name|qelem
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _SUN_MAP_H */
end_comment

end_unit

