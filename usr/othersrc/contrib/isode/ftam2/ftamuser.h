begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ftamuser.h - include file for interactive FTAM initiator */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/ftam2/RCS/ftamuser.h,v 7.5 91/02/22 09:24:14 mrose Interim $  *  *  * $Log:	ftamuser.h,v $  * Revision 7.5  91/02/22  09:24:14  mrose  * Interim 6.8  *   * Revision 7.4  90/12/23  18:40:24  mrose  * update  *   * Revision 7.3  90/11/21  11:30:59  mrose  * sun  *   * Revision 7.2  90/09/07  11:14:13  mrose  * update  *   * Revision 7.1  90/07/09  14:37:30  mrose  * sync  *   * Revision 7.0  89/11/23  21:54:45  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"ftamsbr.h"
end_include

begin_comment
comment|/*
comment|MAIN */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ontty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|interrupted
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|adios
argument_list|()
decl_stmt|,
name|advise
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|BRIDGE
end_ifndef

begin_decl_stmt
name|int
name|ask
argument_list|()
decl_stmt|,
name|getline
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|strdup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|DATA */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ftamfd
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BRIDGE
end_ifdef

begin_function_decl
specifier|extern
name|int
name|dataconn
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|host
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|user
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|account
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|BRIDGE
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|userdn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|storename
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|bell
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|concurrency
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Olivier Dubois */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|globbing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hash
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|marks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|omode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|query
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|runcom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|trace
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
name|watch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|myhome
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|myuser
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|realstore
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RFS_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|RFS_UNIX
value|1
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rs_unknown
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rs_support
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rcwd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|QOStype
name|myqos
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|str2file
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|DISPATCH */
end_comment

begin_struct
struct|struct
name|dispatch
block|{
name|char
modifier|*
name|ds_name
decl_stmt|;
name|IFP
name|ds_fnx
decl_stmt|;
name|int
name|ds_flags
decl_stmt|;
define|#
directive|define
name|DS_NULL
value|0x00
define|#
directive|define
name|DS_OPEN
value|0x01
comment|/* association required */
define|#
directive|define
name|DS_CLOSE
value|0x02
comment|/* association avoided */
define|#
directive|define
name|DS_MODES
value|0x04
comment|/* class/units meaningful */
name|int
name|ds_class
decl_stmt|;
name|int
name|ds_units
decl_stmt|;
name|char
modifier|*
name|ds_help
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|dispatch
modifier|*
name|getds
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|FTAM */
end_comment

begin_define
define|#
directive|define
name|UMASK
value|"\020\01READ\02WRITE\03ACCESS\04LIMITED\05ENHANCED\06GROUPING\ \07RECOVERY\08RESTART"
end_define

begin_decl_stmt
specifier|extern
name|OID
name|context
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fqos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|class
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|units
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|attrs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fadusize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vfsmap
name|vfs
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ordering depends on char *tmodes[] */
end_comment

begin_define
define|#
directive|define
name|VFS_DEF
value|0
end_define

begin_comment
comment|/* try to default it */
end_comment

begin_define
define|#
directive|define
name|VFS_UBF
value|1
end_define

begin_comment
comment|/* offset to unstructured binary file */
end_comment

begin_define
define|#
directive|define
name|VFS_UTF
value|2
end_define

begin_comment
comment|/*   ..	     unstructured text file */
end_comment

begin_define
define|#
directive|define
name|VFS_FDF
value|3
end_define

begin_comment
comment|/*   ..	     file directory file */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vfsmap
modifier|*
name|myvf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ftam_advise
argument_list|()
decl_stmt|,
name|ftam_chrg
argument_list|()
decl_stmt|,
name|ftam_diag
argument_list|()
decl_stmt|,
name|ftam_watch
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|FILES */
end_comment

begin_struct
struct|struct
name|filent
block|{
name|char
modifier|*
name|fi_name
decl_stmt|;
name|OID
name|fi_oid
decl_stmt|;
name|char
modifier|*
name|fi_entry
decl_stmt|;
name|struct
name|filent
modifier|*
name|fi_next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|toomany
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfilent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|filent
modifier|*
name|filents
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|fdffnx
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|GLOB */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xglobbed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|globerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|blkfree
argument_list|()
decl_stmt|,
name|blklen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
modifier|*
name|blkcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xglob1val
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|xglob
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|isodeversion
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BRIDGE
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|ftam_error
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

