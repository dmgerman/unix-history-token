begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* usual BSD style copyright here */
end_comment

begin_comment
comment|/* Written by Julian Elischer (julian@dialix.oz.au)*/
end_comment

begin_comment
comment|/*  * $Id: devfsext.h,v 1.15 1997/02/22 09:44:59 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DEVFSECT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DEVFSECT_H_
end_define

begin_decl_stmt
name|void
modifier|*
name|devfs_add_devswf
name|__P
argument_list|(
operator|(
name|void
operator|*
name|devsw
operator|,
name|int
name|minor
operator|,
name|int
name|chrblk
operator|,
name|uid_t
name|uid
operator|,
name|gid_t
name|gid
operator|,
name|int
name|perms
operator|,
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|devfs_link
name|__P
argument_list|(
operator|(
name|void
operator|*
name|original
operator|,
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|devfs_remove_dev
name|__P
argument_list|(
operator|(
name|void
operator|*
name|devnmp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DV_CHR
value|0
end_define

begin_define
define|#
directive|define
name|DV_BLK
value|1
end_define

begin_define
define|#
directive|define
name|DV_DEV
value|2
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|UID_ROOT
value|0
end_define

begin_define
define|#
directive|define
name|UID_BIN
value|3
end_define

begin_define
define|#
directive|define
name|UID_UUCP
value|66
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|GID_WHEEL
value|0
end_define

begin_define
define|#
directive|define
name|GID_KMEM
value|2
end_define

begin_define
define|#
directive|define
name|GID_OPERATOR
value|5
end_define

begin_define
define|#
directive|define
name|GID_BIN
value|7
end_define

begin_define
define|#
directive|define
name|GID_DIALER
value|68
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DEVFSECT_H_ */
end_comment

end_unit

