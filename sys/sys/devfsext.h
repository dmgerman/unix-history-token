begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* usual BSD style copyright here */
end_comment

begin_comment
comment|/* Written by Julian Elischer (julian@dialix.oz.au)*/
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
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
value|1
end_define

begin_function_decl
name|void
modifier|*
name|devfs_add_devswf
parameter_list|(
name|void
modifier|*
name|devsw
parameter_list|,
name|int
name|minor
parameter_list|,
name|int
name|chrblk
parameter_list|,
name|uid_t
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|,
name|int
name|perms
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|devfs_link
parameter_list|(
name|void
modifier|*
name|original
parameter_list|,
comment|/* the result of a previous dev_link */
name|char
modifier|*
name|fmt
parameter_list|,
comment|/*		or dev_add operation */
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* remove the device the cookie represents */
end_comment

begin_function_decl
name|void
name|devfs_remove_dev
parameter_list|(
name|void
modifier|*
name|devnmp
parameter_list|)
function_decl|;
end_function_decl

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
comment|/*_SYS_DEVFSECT_H_*/
end_comment

end_unit

