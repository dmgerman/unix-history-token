begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
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
file|<stdarg.h>
end_include

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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
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
value|"/bin/rm"
end_define

begin_comment
comment|/* Usually "rm", but often "echo" during debugging! */
end_comment

begin_define
define|#
directive|define
name|RMDIR_CMD
value|"/bin/rmdir"
end_define

begin_comment
comment|/* Where the ports lives by default */
end_comment

begin_define
define|#
directive|define
name|DEF_PORTS_DIR
value|"/usr/ports"
end_define

begin_comment
comment|/* just in case we change the environment variable name */
end_comment

begin_define
define|#
directive|define
name|PORTSDIR
value|"PORTSDIR"
end_define

begin_comment
comment|/* macro to get name of directory where the ports lives */
end_comment

begin_define
define|#
directive|define
name|PORTS_DIR
value|(getenv(PORTSDIR) ? getenv(PORTSDIR) : DEF_PORTS_DIR)
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
comment|/* macro to get name of directory where we put logging information */
end_comment

begin_define
define|#
directive|define
name|LOG_DIR
value|(getenv(PKG_DBDIR) ? getenv(PKG_DBDIR) : DEF_LOG_DIR)
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
name|POST_INSTALL_FNAME
value|"+POST-INSTALL"
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
name|POST_DEINSTALL_FNAME
value|"+POST-DEINSTALL"
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>=
literal|900000
end_if

begin_define
define|#
directive|define
name|INDEX_FNAME
value|"INDEX-9"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>=
literal|800000
end_elif

begin_define
define|#
directive|define
name|INDEX_FNAME
value|"INDEX-8"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>=
literal|700000
end_elif

begin_define
define|#
directive|define
name|INDEX_FNAME
value|"INDEX-7"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>=
literal|600000
end_elif

begin_define
define|#
directive|define
name|INDEX_FNAME
value|"INDEX-6"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INDEX_FNAME
value|"INDEX"
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * Version of the package tools - increase only when some  * functionality used by bsd.port.mk is changed, added or removed  */
end_comment

begin_define
define|#
directive|define
name|PKG_INSTALL_VERSION
value|20090519
end_define

begin_define
define|#
directive|define
name|PKG_WRAPCONF_FNAME
value|"/var/db/pkg_install.conf"
end_define

begin_define
define|#
directive|define
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
value|real_main(argc, argv)
end_define

begin_comment
comment|/* Version numbers to assist with changes in package file format */
end_comment

begin_define
define|#
directive|define
name|PLIST_FMT_VER_MAJOR
value|1
end_define

begin_define
define|#
directive|define
name|PLIST_FMT_VER_MINOR
value|1
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
name|PLIST_CONFLICTS
block|,
name|PLIST_MTREE
block|,
name|PLIST_DIR_RM
block|,
name|PLIST_IGNORE_INST
block|,
name|PLIST_OPTION
block|,
name|PLIST_ORIGIN
block|,
name|PLIST_DEPORIGIN
block|,
name|PLIST_NOINST
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

begin_enum
enum|enum
name|_match_t
block|{
name|MATCH_ALL
block|,
name|MATCH_EXACT
block|,
name|MATCH_GLOB
block|,
name|MATCH_NGLOB
block|,
name|MATCH_EREGEX
block|,
name|MATCH_REGEX
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_match_t
name|match_t
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
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|origin
decl_stmt|;
name|int
name|fmtver_maj
decl_stmt|,
name|fmtver_mnr
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

begin_struct
struct|struct
name|reqr_by_entry
block|{
name|STAILQ_ENTRY
argument_list|(
argument|reqr_by_entry
argument_list|)
name|link
expr_stmt|;
name|char
name|pkgname
index|[
name|PATH_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|reqr_by_head
argument_list|,
name|reqr_by_entry
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|char
modifier|*
name|vpipe
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
specifier|const
name|char
modifier|*
name|make_playpen
parameter_list|(
name|char
modifier|*
parameter_list|,
name|off_t
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
name|int
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
specifier|const
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
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|copy_string_adds_newline
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|suffix
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
name|strconcat
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
name|char
modifier|*
name|get_string
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
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
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|isdir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|isemptydir
parameter_list|(
specifier|const
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
specifier|const
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
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|isempty
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|issymlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|isURL
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|fileGetURL
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
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
name|char
modifier|*
name|fileGetContents
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_file
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
name|void
name|copy_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
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
name|void
name|move_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
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
name|void
name|copy_hierarchy
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
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
specifier|const
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
name|void
name|format_cmd
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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

begin_function_decl
name|Boolean
name|make_preserve_name
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
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

begin_function_decl
name|int
name|real_main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Query installed packages */
end_comment

begin_function_decl
name|char
modifier|*
modifier|*
name|matchinstalled
parameter_list|(
name|match_t
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|matchbyorigin
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
modifier|*
name|matchallbyorigin
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isinstalledpkg
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pattern_match
parameter_list|(
name|match_t
name|MatchType
parameter_list|,
name|char
modifier|*
name|pattern
parameter_list|,
specifier|const
name|char
modifier|*
name|pkgname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Dependencies */
end_comment

begin_function_decl
name|int
name|sortdeps
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chkifdepends
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
name|int
name|requiredby
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|reqr_by_head
modifier|*
modifier|*
parameter_list|,
name|Boolean
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Version */
end_comment

begin_function_decl
name|int
name|verscmp
parameter_list|(
name|Package
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|version_cmp
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

begin_comment
comment|/* Externs */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|Quiet
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

begin_decl_stmt
specifier|extern
name|int
name|Verbose
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

