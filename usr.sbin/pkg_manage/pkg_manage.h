begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * include file for pkg.c   *  *  * Copyright (c) 1995, Marc van Kempen  *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  *   */
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

begin_typedef
typedef|typedef
struct|struct
name|DirList
block|{
comment|/* structure to hold the directory entries */
name|char
name|filename
index|[
name|MAXNAMLEN
index|]
decl_stmt|;
comment|/* together with the stat-info per file */
name|struct
name|stat
name|filestatus
decl_stmt|;
comment|/* filename, or the name to which it points */
name|int
name|link
decl_stmt|;
comment|/* is it a link ? */
name|char
modifier|*
name|linkname
decl_stmt|;
comment|/* the name of the file the link points to */
block|}
name|DirList
typedef|;
end_typedef

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
value|"/home/marc/src/pkg_manage/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VIEW_INST_HLP
value|HELP_PATH##"pkg_view-inst.hlp"
end_define

begin_define
define|#
directive|define
name|DEL_INST_HLP
value|HELP_PATH##"pkg_del-inst.hlp"
end_define

begin_define
define|#
directive|define
name|PREVIEW_HLP
value|HELP_PATH##"pkg_preview.hlp"
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

end_unit

