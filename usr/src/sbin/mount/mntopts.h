begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994  *      The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)mntopts.h	8.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|mntopt
block|{
specifier|const
name|char
modifier|*
name|m_option
decl_stmt|;
comment|/* option name */
name|int
name|m_inverse
decl_stmt|;
comment|/* if a negative option, eg "dev" */
name|int
name|m_flag
decl_stmt|;
comment|/* bit to set, eg. MNT_RDONLY */
block|}
struct|;
end_struct

begin_comment
comment|/* User-visible MNT_ flags. */
end_comment

begin_define
define|#
directive|define
name|MOPT_ASYNC
value|{ "async",	 0, MNT_ASYNC }
end_define

begin_define
define|#
directive|define
name|MOPT_NODEV
value|{ "dev",	 1, MNT_NODEV }
end_define

begin_define
define|#
directive|define
name|MOPT_NOEXEC
value|{ "exec",	 1, MNT_NOEXEC }
end_define

begin_define
define|#
directive|define
name|MOPT_NOSUID
value|{ "suid",	 1, MNT_NOSUID }
end_define

begin_define
define|#
directive|define
name|MOPT_RDONLY
value|{ "rdonly",	 0, MNT_RDONLY }
end_define

begin_define
define|#
directive|define
name|MOPT_SYNCHRONOUS
value|{ "synchronous", 0, MNT_SYNCHRONOUS }
end_define

begin_define
define|#
directive|define
name|MOPT_UNION
value|{ "union",	 0, MNT_UNION }
end_define

begin_comment
comment|/* Control flags. */
end_comment

begin_define
define|#
directive|define
name|MOPT_FORCE
value|{ "exec",	 1, MNT_FORCE }
end_define

begin_define
define|#
directive|define
name|MOPT_UPDATE
value|{ "update",	 0, MNT_UPDATE }
end_define

begin_comment
comment|/* Support for old-style "ro", "rw" flags. */
end_comment

begin_define
define|#
directive|define
name|MOPT_RO
value|{ "ro",		 0, MNT_RDONLY }
end_define

begin_define
define|#
directive|define
name|MOPT_RW
value|{ "rw",		 1, MNT_RDONLY }
end_define

begin_define
define|#
directive|define
name|MOPT_FSTAB_COMPAT
define|\
value|MOPT_RO,							\ 	MOPT_RW
end_define

begin_comment
comment|/* Standard options which all mounts can understand. */
end_comment

begin_define
define|#
directive|define
name|MOPT_STDOPTS
define|\
value|MOPT_FSTAB_COMPAT,						\ 	MOPT_NODEV,							\ 	MOPT_NOEXEC,							\ 	MOPT_NOSUID,							\ 	MOPT_RDONLY,							\ 	MOPT_UNION
end_define

begin_decl_stmt
name|void
name|getmntopts
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
expr|struct
name|mntopt
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

