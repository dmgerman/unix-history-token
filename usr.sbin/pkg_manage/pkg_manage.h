begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * include file for pkg_manage   *  *  * Copyright (c) 1995, Marc van Kempen  *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  *   */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/dirent.h>
end_include

begin_include
include|#
directive|include
file|<ncurses.h>
end_include

begin_include
include|#
directive|include
file|<dialog.h>
end_include

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

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|N
decl_stmt|;
comment|/* size of buf in bytes */
name|int
name|Nitems
decl_stmt|;
comment|/* # of packages */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* buffer to hold package info */
name|char
modifier|*
modifier|*
name|name
decl_stmt|;
comment|/* array of char pointer to locations in buf */
name|char
modifier|*
modifier|*
name|comment
decl_stmt|;
comment|/* idem */
name|char
modifier|*
modifier|*
name|description
decl_stmt|;
comment|/* idem */
name|unsigned
name|char
modifier|*
modifier|*
name|mnu
decl_stmt|;
comment|/* pointers to be used with dialog_menu() */
block|}
name|PKG_info
typedef|;
end_typedef

begin_comment
comment|/* Names of the description and comment files in the package */
end_comment

begin_define
define|#
directive|define
name|DESC
value|"+DESC"
end_define

begin_define
define|#
directive|define
name|COMMENT
value|"+COMMENT"
end_define

begin_define
define|#
directive|define
name|CONTENTS
value|"+CONTENTS"
end_define

begin_comment
comment|/* some programs */
end_comment

begin_define
define|#
directive|define
name|PKG_DELETE
value|"/usr/sbin/pkg_delete"
end_define

begin_define
define|#
directive|define
name|PKG_INFO
value|"/usr/sbin/pkg_info"
end_define

begin_define
define|#
directive|define
name|PKG_ADD
value|"/usr/sbin/pkg_add"
end_define

begin_define
define|#
directive|define
name|TAR
value|"/usr/bin/tar"
end_define

begin_define
define|#
directive|define
name|GUNZIP
value|"/usr/bin/gunzip"
end_define

begin_comment
comment|/* HELP_PATH must have a trailing '/' */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HELP_PATH
end_ifndef

begin_define
define|#
directive|define
name|HELP_PATH
value|"/home/marc/src/dialog/pkg_manage/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VIEW_INST_HLP
value|HELP_PATH##"pkg_view_inst.hlp"
end_define

begin_define
define|#
directive|define
name|DEL_INST_HLP
value|HELP_PATH##"pkg_del_inst.hlp"
end_define

begin_define
define|#
directive|define
name|INSTALL_HLP
value|HELP_PATH##"pkg_install.hlp"
end_define

begin_define
define|#
directive|define
name|MAIN_HLP
value|HELP_PATH##"pkg_main.hlp"
end_define

begin_define
define|#
directive|define
name|DS_INSTALL_HLP
value|HELP_PATH##"pkg_ds_install.hlp"
end_define

begin_comment
comment|/*  * prototypes  */
end_comment

begin_function_decl
name|void
name|run_menu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_pkginfo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FreeMnu
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
name|mnu
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FreeInfo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|install_package
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_pkg_index
parameter_list|(
name|char
modifier|*
name|selection
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|install_batch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_desc
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|,
name|char
modifier|*
modifier|*
name|name
parameter_list|,
name|char
modifier|*
modifier|*
name|comment
parameter_list|,
name|char
modifier|*
modifier|*
name|desc
parameter_list|,
name|long
modifier|*
name|size
parameter_list|,
name|char
modifier|*
name|tmp_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|exec_catch_errors
parameter_list|(
name|char
modifier|*
name|prog
parameter_list|,
name|char
modifier|*
name|arg
parameter_list|,
name|char
modifier|*
name|fout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|already_installed
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

end_unit

