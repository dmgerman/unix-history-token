begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header file mkisofs.h - assorted structure definitions and typecasts.     Written by Eric Youngdale (1993).     Copyright 1993 Yggdrasil Computing, Incorporated     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* ADD_FILES changes made by Ross Biro biro@yggdrasil.com 2/23/95 */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* This symbol is used to indicate that we do not have things like    symlinks, devices, and so forth available.  Just files and dirs */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|NON_UNIXFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DJGPP
end_ifdef

begin_define
define|#
directive|define
name|NON_UNIXFS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strdup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|DECL
parameter_list|(
name|NAME
parameter_list|,
name|ARGS
parameter_list|)
value|NAME ARGS
end_define

begin_define
define|#
directive|define
name|FDECL1
parameter_list|(
name|NAME
parameter_list|,
name|TYPE0
parameter_list|,
name|ARG0
parameter_list|)
define|\
value|NAME(TYPE0 ARG0)
end_define

begin_define
define|#
directive|define
name|FDECL2
parameter_list|(
name|NAME
parameter_list|,
name|TYPE0
parameter_list|,
name|ARG0
parameter_list|,
name|TYPE1
parameter_list|,
name|ARG1
parameter_list|)
define|\
value|NAME(TYPE0 ARG0, TYPE1 ARG1)
end_define

begin_define
define|#
directive|define
name|FDECL3
parameter_list|(
name|NAME
parameter_list|,
name|TYPE0
parameter_list|,
name|ARG0
parameter_list|,
name|TYPE1
parameter_list|,
name|ARG1
parameter_list|,
name|TYPE2
parameter_list|,
name|ARG2
parameter_list|)
define|\
value|NAME(TYPE0 ARG0, TYPE1 ARG1, TYPE2 ARG2)
end_define

begin_define
define|#
directive|define
name|FDECL4
parameter_list|(
name|NAME
parameter_list|,
name|TYPE0
parameter_list|,
name|ARG0
parameter_list|,
name|TYPE1
parameter_list|,
name|ARG1
parameter_list|,
name|TYPE2
parameter_list|,
name|ARG2
parameter_list|,
name|TYPE3
parameter_list|,
name|ARG3
parameter_list|)
define|\
value|NAME(TYPE0 ARG0, TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3)
end_define

begin_define
define|#
directive|define
name|FDECL5
parameter_list|(
name|NAME
parameter_list|,
name|TYPE0
parameter_list|,
name|ARG0
parameter_list|,
name|TYPE1
parameter_list|,
name|ARG1
parameter_list|,
name|TYPE2
parameter_list|,
name|ARG2
parameter_list|,
name|TYPE3
parameter_list|,
name|ARG3
parameter_list|,
name|TYPE4
parameter_list|,
name|ARG4
parameter_list|)
define|\
value|NAME(TYPE0 ARG0, TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3, TYPE4 ARG4)
end_define

begin_define
define|#
directive|define
name|FDECL6
parameter_list|(
name|NAME
parameter_list|,
name|TYPE0
parameter_list|,
name|ARG0
parameter_list|,
name|TYPE1
parameter_list|,
name|ARG1
parameter_list|,
name|TYPE2
parameter_list|,
name|ARG2
parameter_list|,
name|TYPE3
parameter_list|,
name|ARG3
parameter_list|,
name|TYPE4
parameter_list|,
name|ARG4
parameter_list|,
name|TYPE5
parameter_list|,
name|ARG5
parameter_list|)
define|\
value|NAME(TYPE0 ARG0, TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3, TYPE4 ARG4, TYPE5 ARG5)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DECL
parameter_list|(
name|NAME
parameter_list|,
name|ARGS
parameter_list|)
value|NAME()
end_define

begin_define
define|#
directive|define
name|FDECL1
parameter_list|(
name|NAME
parameter_list|,
name|TYPE0
parameter_list|,
name|ARG0
parameter_list|)
value|NAME(ARG0) TYPE0 ARG0;
end_define

begin_define
define|#
directive|define
name|FDECL2
parameter_list|(
name|NAME
parameter_list|,
name|TYPE0
parameter_list|,
name|ARG0
parameter_list|,
name|TYPE1
parameter_list|,
name|ARG1
parameter_list|)
value|NAME(ARG0, ARG1) TYPE0 ARG0; TYPE1 ARG1;
end_define

begin_define
define|#
directive|define
name|FDECL3
parameter_list|(
name|NAME
parameter_list|,
name|TYPE0
parameter_list|,
name|ARG0
parameter_list|,
name|TYPE1
parameter_list|,
name|ARG1
parameter_list|,
name|TYPE2
parameter_list|,
name|ARG2
parameter_list|)
define|\
value|NAME(ARG0, ARG1, ARG2) TYPE0 ARG0; TYPE1 ARG1; TYPE2 ARG2;
end_define

begin_define
define|#
directive|define
name|FDECL4
parameter_list|(
name|NAME
parameter_list|,
name|TYPE0
parameter_list|,
name|ARG0
parameter_list|,
name|TYPE1
parameter_list|,
name|ARG1
parameter_list|,
name|TYPE2
parameter_list|,
name|ARG2
parameter_list|,
name|TYPE3
parameter_list|,
name|ARG3
parameter_list|)
define|\
value|NAME(ARG0, ARG1, ARG2, ARG3, ARG4) TYPE0 ARG0; TYPE1 ARG1; TYPE2 ARG2; TYPE3 ARG3;
end_define

begin_define
define|#
directive|define
name|FDECL5
parameter_list|(
name|NAME
parameter_list|,
name|TYPE0
parameter_list|,
name|ARG0
parameter_list|,
name|TYPE1
parameter_list|,
name|ARG1
parameter_list|,
name|TYPE2
parameter_list|,
name|ARG2
parameter_list|,
name|TYPE3
parameter_list|,
name|ARG3
parameter_list|,
name|TYPE4
parameter_list|,
name|ARG4
parameter_list|)
define|\
value|NAME(ARG0, ARG1, ARG2, ARG3, ARG4) TYPE0 ARG0; TYPE1 ARG1; TYPE2 ARG2; TYPE3 ARG3; TYPE4 ARG4;
end_define

begin_define
define|#
directive|define
name|FDECL6
parameter_list|(
name|NAME
parameter_list|,
name|TYPE0
parameter_list|,
name|ARG0
parameter_list|,
name|TYPE1
parameter_list|,
name|ARG1
parameter_list|,
name|TYPE2
parameter_list|,
name|ARG2
parameter_list|,
name|TYPE3
parameter_list|,
name|ARG3
parameter_list|,
name|TYPE4
parameter_list|,
name|ARG4
parameter_list|,
name|TYPE5
parameter_list|,
name|ARG5
parameter_list|)
define|\
value|NAME(ARG0, ARG1, ARG2, ARG3, ARG4, ARG5) TYPE0 ARG0; TYPE1 ARG1; TYPE2 ARG2; TYPE3 ARG3; TYPE4 ARG4; TYPE5 ARG5;
end_define

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__svr4__
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extern int getopt (int __argc, char **__argv, char *__optstring); */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"iso9660.h"
end_include

begin_include
include|#
directive|include
file|"defaults.h"
end_include

begin_struct
struct|struct
name|directory_entry
block|{
name|struct
name|directory_entry
modifier|*
name|next
decl_stmt|;
name|struct
name|iso_directory_record
name|isorec
decl_stmt|;
name|unsigned
name|int
name|starting_block
decl_stmt|;
name|unsigned
name|int
name|size
decl_stmt|;
name|unsigned
name|int
name|priority
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|table
decl_stmt|;
name|char
modifier|*
name|whole_name
decl_stmt|;
name|struct
name|directory
modifier|*
name|filedir
decl_stmt|;
name|struct
name|directory_entry
modifier|*
name|parent_rec
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
name|ino_t
name|inode
decl_stmt|;
comment|/* Used in the hash table */
name|dev_t
name|dev
decl_stmt|;
comment|/* Used in the hash table */
name|unsigned
name|char
modifier|*
name|rr_attributes
decl_stmt|;
name|unsigned
name|int
name|rr_attr_size
decl_stmt|;
name|unsigned
name|int
name|total_rr_attr_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|file_hash
block|{
name|struct
name|file_hash
modifier|*
name|next
decl_stmt|;
name|ino_t
name|inode
decl_stmt|;
comment|/* Used in the hash table */
name|dev_t
name|dev
decl_stmt|;
comment|/* Used in the hash table */
name|unsigned
name|int
name|starting_block
decl_stmt|;
name|unsigned
name|int
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|directory
block|{
name|struct
name|directory
modifier|*
name|next
decl_stmt|;
comment|/* Next directory at same level as this one */
name|struct
name|directory
modifier|*
name|subdir
decl_stmt|;
comment|/* First subdirectory in this directory */
name|struct
name|directory
modifier|*
name|parent
decl_stmt|;
name|struct
name|directory_entry
modifier|*
name|contents
decl_stmt|;
name|struct
name|directory_entry
modifier|*
name|self
decl_stmt|;
name|char
modifier|*
name|whole_name
decl_stmt|;
comment|/* Entire path */
name|char
modifier|*
name|de_name
decl_stmt|;
comment|/* Entire path */
name|unsigned
name|int
name|ce_bytes
decl_stmt|;
comment|/* Number of bytes of CE entries reqd for this dir */
name|unsigned
name|int
name|depth
decl_stmt|;
name|unsigned
name|int
name|size
decl_stmt|;
name|unsigned
name|int
name|extent
decl_stmt|;
name|unsigned
name|short
name|path_index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|deferred
block|{
name|struct
name|deferred
modifier|*
name|next
decl_stmt|;
name|unsigned
name|int
name|starting_block
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|directory
modifier|*
name|filedir
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|ADD_FILES
end_ifdef

begin_struct
struct|struct
name|file_adds
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|file_adds
modifier|*
name|child
decl_stmt|;
name|struct
name|file_adds
modifier|*
name|next
decl_stmt|;
name|int
name|add_count
decl_stmt|;
name|int
name|used
decl_stmt|;
name|struct
name|dirent
name|de
decl_stmt|;
struct|struct
block|{
name|char
modifier|*
name|path
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
modifier|*
name|adds
struct|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|file_adds
modifier|*
name|root_file_adds
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|DECL
argument_list|(
name|sort_n_finish
argument_list|,
operator|(
expr|struct
name|directory
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|goof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|directory
modifier|*
name|root
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|directory
modifier|*
name|reloc_dir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|next_extent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|last_extent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|path_table_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|path_table
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|path_blocks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|path_table_l
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|path_table_m
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|iso_directory_record
name|root_record
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|use_RockRidge
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|follow_links
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|all_files
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|generate_tables
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|omit_period
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|omit_version_number
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|transparent_compression
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|RR_relocation_depth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|full_iso9660_filenames
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|DECL
argument_list|(
name|scan_directory_tree
argument_list|,
operator|(
name|char
operator|*
name|path
operator|,
expr|struct
name|directory_entry
operator|*
name|self
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|DECL
argument_list|(
name|dump_tree
argument_list|,
operator|(
expr|struct
name|directory
operator|*
name|node
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|DECL
argument_list|(
name|assign_directory_addresses
argument_list|,
operator|(
expr|struct
name|directory
operator|*
name|root
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|DECL
argument_list|(
name|iso9660_file_length
argument_list|,
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
expr|struct
name|directory_entry
operator|*
name|sresult
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|DECL
argument_list|(
name|iso_write
argument_list|,
operator|(
name|FILE
operator|*
name|outfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|generate_path_tables
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|DECL
argument_list|(
name|generate_iso9660_directories
argument_list|,
operator|(
expr|struct
name|directory
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|DECL
argument_list|(
name|generate_one_directory
argument_list|,
operator|(
expr|struct
name|directory
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|generate_root_record
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|DECL
argument_list|(
name|iso9660_date
argument_list|,
operator|(
name|char
operator|*
operator|,
name|time_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|DECL
argument_list|(
name|add_hash
argument_list|,
operator|(
expr|struct
name|directory_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|file_hash
modifier|*
name|DECL
argument_list|(
name|find_hash
argument_list|,
operator|(
name|dev_t
operator|,
name|ino_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|DECL
argument_list|(
name|add_directory_hash
argument_list|,
operator|(
name|dev_t
operator|,
name|ino_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|file_hash
modifier|*
name|DECL
argument_list|(
name|find_directory_hash
argument_list|,
operator|(
name|dev_t
operator|,
name|ino_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|flush_file_hash
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|DECL
argument_list|(
name|delete_file_hash
argument_list|,
operator|(
expr|struct
name|directory_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|directory_entry
modifier|*
name|DECL
argument_list|(
name|find_file_hash
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|DECL
argument_list|(
name|add_file_hash
argument_list|,
operator|(
expr|struct
name|directory_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|finish_cl_pl_entries
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|DECL
argument_list|(
name|get_733
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|DECL
argument_list|(
name|set_723
argument_list|,
operator|(
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|DECL
argument_list|(
name|set_733
argument_list|,
operator|(
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|DECL
argument_list|(
name|sort_directory
argument_list|,
operator|(
expr|struct
name|directory_entry
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|DECL
argument_list|(
name|generate_rock_ridge_attributes
argument_list|,
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
expr|struct
name|directory_entry
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|,
name|int
name|deep_flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|DECL
argument_list|(
name|generate_rr_extension_record
argument_list|,
operator|(
name|char
operator|*
name|id
operator|,
name|char
operator|*
name|descriptor
operator|,
name|char
operator|*
name|source
operator|,
name|int
operator|*
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|extension_record
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|extension_record_extent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|n_data_extents
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These are a few goodies that can be specified on the command line, and  are    filled into the root record */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|preparer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|publisher
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|copyright
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|biblio
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|abstract
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|appid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|volset_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|system_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|volume_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|DECL
argument_list|(
name|e_malloc
argument_list|,
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SECTOR_SIZE
value|(2048)
end_define

begin_define
define|#
directive|define
name|ROUND_UP
parameter_list|(
name|X
parameter_list|)
value|((X + (SECTOR_SIZE - 1))& ~(SECTOR_SIZE - 1))
end_define

begin_define
define|#
directive|define
name|NEED_RE
value|1
end_define

begin_define
define|#
directive|define
name|NEED_PL
value|2
end_define

begin_define
define|#
directive|define
name|NEED_CL
value|4
end_define

begin_define
define|#
directive|define
name|NEED_CE
value|8
end_define

begin_define
define|#
directive|define
name|NEED_SP
value|16
end_define

begin_define
define|#
directive|define
name|TABLE_INODE
value|(sizeof(ino_t)>= 4 ? 0x7ffffffe : 0x7ffe)
end_define

begin_define
define|#
directive|define
name|UNCACHED_INODE
value|(sizeof(ino_t)>= 4 ? 0x7fffffff : 0x7fff)
end_define

begin_define
define|#
directive|define
name|UNCACHED_DEVICE
value|(sizeof(dev_t)>= 4 ? 0x7fffffff : 0x7fff)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|STAT_INODE
parameter_list|(
name|X
parameter_list|)
value|(X.st_ino[0])
end_define

begin_define
define|#
directive|define
name|PATH_SEPARATOR
value|']'
end_define

begin_define
define|#
directive|define
name|SPATH_SEPARATOR
value|""
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STAT_INODE
parameter_list|(
name|X
parameter_list|)
value|(X.st_ino)
end_define

begin_define
define|#
directive|define
name|PATH_SEPARATOR
value|'/'
end_define

begin_define
define|#
directive|define
name|SPATH_SEPARATOR
value|"/"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

