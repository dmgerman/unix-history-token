begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * aux_conf.h:  * This file gets "filled in" for each architecture.  * Generated automatically from aux_conf.h.in by configure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AUX_CONF_H
end_ifndef

begin_define
define|#
directive|define
name|_AUX_CONF_H
end_define

begin_comment
comment|/*  * The next line is a literal inclusion of a file which includes a  * definition for the MOUNT_TRAP macro for a particular architecture.  * If it defines the wrong entry, check the AC_CHECK_MOUNT_TRAP m4 macro  * in $srcdir/aux/macros.  */
end_comment

begin_comment
comment|/* $srcdir/conf/trap/trap_default.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT_GET_DIRECTLY_FROM_FILE
end_ifdef

begin_define
define|#
directive|define
name|MOUNT_TRAP
parameter_list|(
name|type
parameter_list|,
name|mnt
parameter_list|,
name|flags
parameter_list|,
name|mnt_data
parameter_list|)
value|mount(type, mnt->mnt_dir, flags, mnt_data)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT_GET_DIRECTLY_FROM_FILE */
end_comment

begin_include
include|#
directive|include
file|"conf/trap/trap_default.h"
end_include

begin_comment
comment|/* End of included MOUNT_TRAP macro definition file */
end_comment

begin_comment
comment|/*  * The next line is a literal replacement of a variable which defines the  * the UNMOUNT_TRAP macro for a particular architecture.  * If it defines the wrong entry, check the AC_CHECK_UNMOUNT_CALL m4 macro  * in $srcdir/aclocal.m4.  If the arguments are being defined wrong, check  * the macro AC_CHECK_UNMOUNT_ARGS in $srcdir/aux/macros.  */
end_comment

begin_define
define|#
directive|define
name|UNMOUNT_TRAP
parameter_list|(
name|mnt
parameter_list|)
value|unmount(mnt->mnt_dir)
end_define

begin_comment
comment|/* End of replaced UNMOUNT_TRAP macro definition */
end_comment

begin_comment
comment|/*  * The next line is a literal inclusion of a file which includes a  * definition for the NFS_FH_DREF macro for a particular architecture.  * If it defines the wrong entry, check the AC_CHECK_NFS_FH_DREF m4 macro  * in $srcdir/aux/macros.  */
end_comment

begin_comment
comment|/* $srcdir/conf/fh_dref/fh_dref_freebsd22.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT_GET_DIRECTLY_FROM_FILE
end_ifdef

begin_define
define|#
directive|define
name|NFS_FH_DREF
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|(dst) = (u_char *) (src)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT_GET_DIRECTLY_FROM_FILE */
end_comment

begin_include
include|#
directive|include
file|"conf/fh_dref/fh_dref_freebsd22.h"
end_include

begin_comment
comment|/* End of included NFS_FH_DREF macro definition file */
end_comment

begin_comment
comment|/*  * The next line is a literal inclusion of a file which includes a  * definition for the NFS_SA_DREF macro for a particular architecture.  * If it defines the wrong entry, check the AC_CHECK_NFS_SA_DREF m4 macro  * in $srcdir/aux/macros.  */
end_comment

begin_comment
comment|/* $srcdir/conf/sa_dref/sa_dref_bsd44.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT_GET_DIRECTLY_FROM_FILE
end_ifdef

begin_define
define|#
directive|define
name|NFS_SA_DREF
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|{ \ 		(dst)->addr = (struct sockaddr *) (src); \ 		(dst)->addrlen = sizeof(*src); \ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT_GET_DIRECTLY_FROM_FILE */
end_comment

begin_include
include|#
directive|include
file|"conf/sa_dref/sa_dref_bsd44.h"
end_include

begin_comment
comment|/* End of included NFS_SA_DREF macro definition file */
end_comment

begin_comment
comment|/*  * The next line is a literal inclusion of a file which includes a  * definition for the NFS_HN_DREF macro for a particular architecture.  * If it defines the wrong entry, check the AC_CHECK_NFS_HN_DREF m4 macro  * in $srcdir/aux/macros.  */
end_comment

begin_comment
comment|/* $srcdir/conf/hn_dref/hn_dref_default.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT_GET_DIRECTLY_FROM_FILE
end_ifdef

begin_define
define|#
directive|define
name|NFS_HN_DREF
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|(dst) = (src)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT_GET_DIRECTLY_FROM_FILE */
end_comment

begin_include
include|#
directive|include
file|"conf/hn_dref/hn_dref_default.h"
end_include

begin_comment
comment|/* End of included NFS_HN_DREF macro definition file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AUX_CONF_H */
end_comment

end_unit

