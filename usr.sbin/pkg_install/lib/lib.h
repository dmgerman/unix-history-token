begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: lib.h,v 1.22.2.1 1997/10/09 07:10:05 charnier Exp $ */
end_comment

begin_comment
comment|/*  * FreeBSD install - a package for the installation and maintainance  * of non-core utilities.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * Jordan K. Hubbard  * 18 July 1993  *  * Include and define various things wanted by the library routines.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INST_LIB_LIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_INST_LIB_LIB_H_
end_define

begin_comment
comment|/* Includes */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_comment
comment|/* Macros */
end_comment

begin_define
define|#
directive|define
name|SUCCESS
value|(0)
end_define

begin_define
define|#
directive|define
name|FAIL
value|(-1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|YES
value|2
end_define

begin_define
define|#
directive|define
name|NO
value|1
end_define

begin_comment
comment|/* Usually "rm", but often "echo" during debugging! */
end_comment

begin_define
define|#
directive|define
name|REMOVE_CMD
value|"rm"
end_define

begin_comment
comment|/* Usually "rm", but often "echo" during debugging! */
end_comment

begin_define
define|#
directive|define
name|RMDIR_CMD
value|"rmdir"
end_define

begin_comment
comment|/* Where we put logging information by default, else ${PKG_DBDIR} if set */
end_comment

begin_define
define|#
directive|define
name|DEF_LOG_DIR
value|"/var/db/pkg"
end_define

begin_comment
comment|/* just in case we change the environment variable name */
end_comment

begin_define
define|#
directive|define
name|PKG_DBDIR
value|"PKG_DBDIR"
end_define

begin_comment
comment|/* The names of our "special" files */
end_comment

begin_define
define|#
directive|define
name|CONTENTS_FNAME
value|"+CONTENTS"
end_define

begin_define
define|#
directive|define
name|COMMENT_FNAME
value|"+COMMENT"
end_define

begin_define
define|#
directive|define
name|DESC_FNAME
value|"+DESC"
end_define

begin_define
define|#
directive|define
name|INSTALL_FNAME
value|"+INSTALL"
end_define

begin_define
define|#
directive|define
name|DEINSTALL_FNAME
value|"+DEINSTALL"
end_define

begin_define
define|#
directive|define
name|REQUIRE_FNAME
value|"+REQUIRE"
end_define

begin_define
define|#
directive|define
name|REQUIRED_BY_FNAME
value|"+REQUIRED_BY"
end_define

begin_define
define|#
directive|define
name|DISPLAY_FNAME
value|"+DISPLAY"
end_define

begin_define
define|#
directive|define
name|MTREE_FNAME
value|"+MTREE_DIRS"
end_define

begin_define
define|#
directive|define
name|CMD_CHAR
value|'@'
end_define

begin_comment
comment|/* prefix for extended PLIST cmd */
end_comment

begin_comment
comment|/* The name of the "prefix" environment variable given to scripts */
end_comment

begin_define
define|#
directive|define
name|PKG_PREFIX_VNAME
value|"PKG_PREFIX"
end_define

begin_enum
enum|enum
name|_plist_t
block|{
name|PLIST_FILE
block|,
name|PLIST_CWD
block|,
name|PLIST_CMD
block|,
name|PLIST_CHMOD
block|,
name|PLIST_CHOWN
block|,
name|PLIST_CHGRP
block|,
name|PLIST_COMMENT
block|,
name|PLIST_IGNORE
block|,
name|PLIST_NAME
block|,
name|PLIST_UNEXEC
block|,
name|PLIST_SRC
block|,
name|PLIST_DISPLAY
block|,
name|PLIST_PKGDEP
block|,
name|PLIST_MTREE
block|,
name|PLIST_DIR_RM
block|,
name|PLIST_IGNORE_INST
block|,
name|PLIST_OPTION
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_plist_t
name|plist_t
typedef|;
end_typedef

begin_comment
comment|/* Types */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|Boolean
typedef|;
end_typedef

begin_struct
struct|struct
name|_plist
block|{
name|struct
name|_plist
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|Boolean
name|marked
decl_stmt|;
name|plist_t
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_plist
modifier|*
name|PackingList
typedef|;
end_typedef

begin_struct
struct|struct
name|_pack
block|{
name|struct
name|_plist
modifier|*
name|head
decl_stmt|,
modifier|*
name|tail
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_pack
name|Package
typedef|;
end_typedef

begin_comment
comment|/* Prototypes */
end_comment

begin_comment
comment|/* Misc */
end_comment

begin_function_decl
name|int
name|vsystem
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cleanup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|make_playpen
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|where_playpen
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|leave_playpen
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|min_free
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* String */
end_comment

begin_function_decl
name|char
modifier|*
name|get_dash_string
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|copy_string
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|suffix
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nuke_suffix
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_lowercase
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|basename_of
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strconcat
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* File */
end_comment

begin_function_decl
name|Boolean
name|fexists
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|isdir
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|isemptydir
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|isemptyfile
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|isfile
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|isempty
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|isURL
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fileGetURL
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fileURLFilename
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fileURLHost
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fileFindByPath
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fileGetContents
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_file
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_file
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|move_file
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_hierarchy
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|delete_hierarchy
parameter_list|(
name|char
modifier|*
parameter_list|,
name|Boolean
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unpack
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|format_cmd
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Msg */
end_comment

begin_function_decl
name|void
name|upchuck
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|barf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|whinge
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|y_or_n
parameter_list|(
name|Boolean
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Packing list */
end_comment

begin_function_decl
name|PackingList
name|new_plist_entry
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PackingList
name|last_plist
parameter_list|(
name|Package
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PackingList
name|find_plist
parameter_list|(
name|Package
modifier|*
parameter_list|,
name|plist_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|find_plist_option
parameter_list|(
name|Package
modifier|*
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|plist_delete
parameter_list|(
name|Package
modifier|*
parameter_list|,
name|Boolean
parameter_list|,
name|plist_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_plist
parameter_list|(
name|Package
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mark_plist
parameter_list|(
name|Package
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|csum_plist_entry
parameter_list|(
name|char
modifier|*
parameter_list|,
name|PackingList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_plist
parameter_list|(
name|Package
modifier|*
parameter_list|,
name|plist_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_plist_top
parameter_list|(
name|Package
modifier|*
parameter_list|,
name|plist_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delete_plist
parameter_list|(
name|Package
modifier|*
name|pkg
parameter_list|,
name|Boolean
name|all
parameter_list|,
name|plist_t
name|type
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_plist
parameter_list|(
name|Package
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_plist
parameter_list|(
name|Package
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|plist_cmd
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|delete_package
parameter_list|(
name|Boolean
parameter_list|,
name|Boolean
parameter_list|,
name|Package
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For all */
end_comment

begin_function_decl
name|int
name|pkg_perform
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Externs */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|Verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Boolean
name|Fake
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Boolean
name|Force
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|AutoAnswer
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _INST_LIB_LIB_H_ */
end_comment

end_unit

