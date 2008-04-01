begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_ACL_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_ACL_H_
end_define

begin_empty
empty|#include_next<sys/acl.h>
end_empty

begin_define
define|#
directive|define
name|MAX_ACL_ENTRIES
value|(1024)
end_define

begin_comment
comment|/* max entries of each type */
end_comment

begin_typedef
typedef|typedef
name|struct
name|acl_entry
name|aclent_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|a_type
value|ae_tag
end_define

begin_define
define|#
directive|define
name|a_id
value|ae_id
end_define

begin_define
define|#
directive|define
name|a_perm
value|ae_perm
end_define

begin_typedef
typedef|typedef
struct|struct
name|ace
block|{
name|uid_t
name|a_who
decl_stmt|;
comment|/* uid or gid */
name|uint32_t
name|a_access_mask
decl_stmt|;
comment|/* read,write,... */
name|uint16_t
name|a_flags
decl_stmt|;
comment|/* see below */
name|uint16_t
name|a_type
decl_stmt|;
comment|/* allow or deny */
block|}
name|ace_t
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * The following are Defined types for an aclent_t.  */
end_comment

begin_define
define|#
directive|define
name|USER_OBJ
value|(0x01)
end_define

begin_comment
comment|/* object owner */
end_comment

begin_define
define|#
directive|define
name|USER
value|(0x02)
end_define

begin_comment
comment|/* additional users */
end_comment

begin_define
define|#
directive|define
name|GROUP_OBJ
value|(0x04)
end_define

begin_comment
comment|/* owning group of the object */
end_comment

begin_define
define|#
directive|define
name|GROUP
value|(0x08)
end_define

begin_comment
comment|/* additional groups */
end_comment

begin_define
define|#
directive|define
name|CLASS_OBJ
value|(0x10)
end_define

begin_comment
comment|/* file group class and mask entry */
end_comment

begin_define
define|#
directive|define
name|OTHER_OBJ
value|(0x20)
end_define

begin_comment
comment|/* other entry for the object */
end_comment

begin_define
define|#
directive|define
name|ACL_DEFAULT
value|(0x1000)
end_define

begin_comment
comment|/* default flag */
end_comment

begin_comment
comment|/* default object owner */
end_comment

begin_define
define|#
directive|define
name|DEF_USER_OBJ
value|(ACL_DEFAULT | USER_OBJ)
end_define

begin_comment
comment|/* defalut additional users */
end_comment

begin_define
define|#
directive|define
name|DEF_USER
value|(ACL_DEFAULT | USER)
end_define

begin_comment
comment|/* default owning group */
end_comment

begin_define
define|#
directive|define
name|DEF_GROUP_OBJ
value|(ACL_DEFAULT | GROUP_OBJ)
end_define

begin_comment
comment|/* default additional groups */
end_comment

begin_define
define|#
directive|define
name|DEF_GROUP
value|(ACL_DEFAULT | GROUP)
end_define

begin_comment
comment|/* default mask entry */
end_comment

begin_define
define|#
directive|define
name|DEF_CLASS_OBJ
value|(ACL_DEFAULT | CLASS_OBJ)
end_define

begin_comment
comment|/* default other entry */
end_comment

begin_define
define|#
directive|define
name|DEF_OTHER_OBJ
value|(ACL_DEFAULT | OTHER_OBJ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following are defined for ace_t.  */
end_comment

begin_define
define|#
directive|define
name|ACE_READ_DATA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ACE_LIST_DIRECTORY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ACE_WRITE_DATA
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ACE_ADD_FILE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ACE_APPEND_DATA
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ACE_ADD_SUBDIRECTORY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ACE_READ_NAMED_ATTRS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ACE_WRITE_NAMED_ATTRS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ACE_EXECUTE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ACE_DELETE_CHILD
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ACE_READ_ATTRIBUTES
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ACE_WRITE_ATTRIBUTES
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ACE_DELETE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ACE_READ_ACL
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ACE_WRITE_ACL
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ACE_WRITE_OWNER
value|0x00080000
end_define

begin_define
define|#
directive|define
name|ACE_SYNCHRONIZE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ACE_FILE_INHERIT_ACE
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACE_DIRECTORY_INHERIT_ACE
value|0x0002
end_define

begin_define
define|#
directive|define
name|ACE_NO_PROPAGATE_INHERIT_ACE
value|0x0004
end_define

begin_define
define|#
directive|define
name|ACE_INHERIT_ONLY_ACE
value|0x0008
end_define

begin_define
define|#
directive|define
name|ACE_SUCCESSFUL_ACCESS_ACE_FLAG
value|0x0010
end_define

begin_define
define|#
directive|define
name|ACE_FAILED_ACCESS_ACE_FLAG
value|0x0020
end_define

begin_define
define|#
directive|define
name|ACE_IDENTIFIER_GROUP
value|0x0040
end_define

begin_define
define|#
directive|define
name|ACE_OWNER
value|0x1000
end_define

begin_define
define|#
directive|define
name|ACE_GROUP
value|0x2000
end_define

begin_define
define|#
directive|define
name|ACE_EVERYONE
value|0x4000
end_define

begin_define
define|#
directive|define
name|ACE_ACCESS_ALLOWED_ACE_TYPE
value|0x0000
end_define

begin_define
define|#
directive|define
name|ACE_ACCESS_DENIED_ACE_TYPE
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACE_SYSTEM_AUDIT_ACE_TYPE
value|0x0002
end_define

begin_define
define|#
directive|define
name|ACE_SYSTEM_ALARM_ACE_TYPE
value|0x0003
end_define

begin_define
define|#
directive|define
name|ACE_ALL_PERMS
value|(ACE_READ_DATA|ACE_LIST_DIRECTORY|ACE_WRITE_DATA| \     ACE_ADD_FILE|ACE_APPEND_DATA|ACE_ADD_SUBDIRECTORY|ACE_READ_NAMED_ATTRS| \     ACE_WRITE_NAMED_ATTRS|ACE_EXECUTE|ACE_DELETE_CHILD|ACE_READ_ATTRIBUTES| \     ACE_WRITE_ATTRIBUTES|ACE_DELETE|ACE_READ_ACL|ACE_WRITE_ACL| \     ACE_WRITE_OWNER|ACE_SYNCHRONIZE)
end_define

begin_comment
comment|/*  * The following flags are supported by both NFSv4 ACLs and ace_t.  */
end_comment

begin_define
define|#
directive|define
name|ACE_NFSV4_SUP_FLAGS
value|(ACE_FILE_INHERIT_ACE | \     ACE_DIRECTORY_INHERIT_ACE | \     ACE_NO_PROPAGATE_INHERIT_ACE | \     ACE_INHERIT_ONLY_ACE | \     ACE_IDENTIFIER_GROUP)
end_define

begin_define
define|#
directive|define
name|ACE_TYPE_FLAGS
value|(ACE_OWNER|ACE_GROUP|ACE_EVERYONE|ACE_IDENTIFIER_GROUP)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* cmd args to acl(2) for aclent_t  */
end_comment

begin_define
define|#
directive|define
name|GETACL
value|1
end_define

begin_define
define|#
directive|define
name|SETACL
value|2
end_define

begin_define
define|#
directive|define
name|GETACLCNT
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* cmd's to manipulate ace acls. */
end_comment

begin_define
define|#
directive|define
name|ACE_GETACL
value|4
end_define

begin_define
define|#
directive|define
name|ACE_SETACL
value|5
end_define

begin_define
define|#
directive|define
name|ACE_GETACLCNT
value|6
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* minimal acl entries from GETACLCNT */
end_comment

begin_define
define|#
directive|define
name|MIN_ACL_ENTRIES
value|4
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_comment
comment|/* acl check errors */
end_comment

begin_define
define|#
directive|define
name|GRP_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|USER_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|OTHER_ERROR
value|3
end_define

begin_define
define|#
directive|define
name|CLASS_ERROR
value|4
end_define

begin_define
define|#
directive|define
name|DUPLICATE_ERROR
value|5
end_define

begin_define
define|#
directive|define
name|MISS_ERROR
value|6
end_define

begin_define
define|#
directive|define
name|MEM_ERROR
value|7
end_define

begin_define
define|#
directive|define
name|ENTRY_ERROR
value|8
end_define

begin_comment
comment|/*  * similar to ufs_acl.h: changed to char type for user commands (tar, cpio)  * Attribute types  */
end_comment

begin_define
define|#
directive|define
name|UFSD_FREE
value|('0')
end_define

begin_comment
comment|/* Free entry */
end_comment

begin_define
define|#
directive|define
name|UFSD_ACL
value|('1')
end_define

begin_comment
comment|/* Access Control Lists */
end_comment

begin_define
define|#
directive|define
name|UFSD_DFACL
value|('2')
end_define

begin_comment
comment|/* reserved for future use */
end_comment

begin_define
define|#
directive|define
name|ACE_ACL
value|('3')
end_define

begin_comment
comment|/* ace_t style acls */
end_comment

begin_comment
comment|/*  * flag to [f]acl_get()  * controls whether a trivial acl should be returned.  */
end_comment

begin_define
define|#
directive|define
name|ACL_NO_TRIVIAL
value|0x2
end_define

begin_comment
comment|/*  * Flags to control acl_totext()  */
end_comment

begin_define
define|#
directive|define
name|ACL_APPEND_ID
value|0x1
end_define

begin_comment
comment|/* append uid/gid to user/group entries */
end_comment

begin_define
define|#
directive|define
name|ACL_COMPACT_FMT
value|0x2
end_define

begin_comment
comment|/* build ACL in ls -V format */
end_comment

begin_define
define|#
directive|define
name|ACL_NORESOLVE
value|0x4
end_define

begin_comment
comment|/* don't do name service lookups */
end_comment

begin_comment
comment|/*  * Legacy aclcheck errors for aclent_t ACLs  */
end_comment

begin_define
define|#
directive|define
name|EACL_GRP_ERROR
value|GRP_ERROR
end_define

begin_define
define|#
directive|define
name|EACL_USER_ERROR
value|USER_ERROR
end_define

begin_define
define|#
directive|define
name|EACL_OTHER_ERROR
value|OTHER_ERROR
end_define

begin_define
define|#
directive|define
name|EACL_CLASS_ERROR
value|CLASS_ERROR
end_define

begin_define
define|#
directive|define
name|EACL_DUPLICATE_ERROR
value|DUPLICATE_ERROR
end_define

begin_define
define|#
directive|define
name|EACL_MISS_ERROR
value|MISS_ERROR
end_define

begin_define
define|#
directive|define
name|EACL_MEM_ERROR
value|MEM_ERROR
end_define

begin_define
define|#
directive|define
name|EACL_ENTRY_ERROR
value|ENTRY_ERROR
end_define

begin_define
define|#
directive|define
name|EACL_INHERIT_ERROR
value|9
end_define

begin_comment
comment|/* invalid inherit flags */
end_comment

begin_define
define|#
directive|define
name|EACL_FLAGS_ERROR
value|10
end_define

begin_comment
comment|/* unknown flag value */
end_comment

begin_define
define|#
directive|define
name|EACL_PERM_MASK_ERROR
value|11
end_define

begin_comment
comment|/* unknown permission */
end_comment

begin_define
define|#
directive|define
name|EACL_COUNT_ERROR
value|12
end_define

begin_comment
comment|/* invalid acl count */
end_comment

begin_define
define|#
directive|define
name|EACL_INVALID_SLOT
value|13
end_define

begin_comment
comment|/* invalid acl slot */
end_comment

begin_define
define|#
directive|define
name|EACL_NO_ACL_ENTRY
value|14
end_define

begin_comment
comment|/* Entry doesn't exist */
end_comment

begin_define
define|#
directive|define
name|EACL_DIFF_TYPE
value|15
end_define

begin_comment
comment|/* acls aren't same type */
end_comment

begin_define
define|#
directive|define
name|EACL_INVALID_USER_GROUP
value|16
end_define

begin_comment
comment|/* need user/group name */
end_comment

begin_define
define|#
directive|define
name|EACL_INVALID_STR
value|17
end_define

begin_comment
comment|/* invalid acl string */
end_comment

begin_define
define|#
directive|define
name|EACL_FIELD_NOT_BLANK
value|18
end_define

begin_comment
comment|/* can't have blank field */
end_comment

begin_define
define|#
directive|define
name|EACL_INVALID_ACCESS_TYPE
value|19
end_define

begin_comment
comment|/* invalid access type */
end_comment

begin_define
define|#
directive|define
name|EACL_UNKNOWN_DATA
value|20
end_define

begin_comment
comment|/* Unrecognized data in ACL */
end_comment

begin_define
define|#
directive|define
name|EACL_MISSING_FIELDS
value|21
end_define

begin_comment
comment|/* missing fields in acl */
end_comment

begin_define
define|#
directive|define
name|EACL_INHERIT_NOTDIR
value|22
end_define

begin_comment
comment|/* Need dir for inheritance */
end_comment

begin_else
unit|extern int aclcheck(aclent_t *, int, int *); extern int acltomode(aclent_t *, int, mode_t *); extern int aclfrommode(aclent_t *, int, mode_t *); extern int aclsort(int, int, aclent_t *); extern char *acltotext(aclent_t *, int); extern aclent_t *aclfromtext(char *, int *); extern void acl_free(acl_t *); extern int acl_get(const char *, int, acl_t **); extern int facl_get(int, int, acl_t **); extern int acl_set(const char *, acl_t *acl); extern int facl_set(int, acl_t *acl); extern int acl_strip(const char *, uid_t, gid_t, mode_t); extern int acl_trivial(const char *); extern char *acl_totext(acl_t *, int); extern int acl_fromtext(const char *, acl_t **); extern int acl_check(acl_t *, int);
else|#
directive|else
end_else

begin_comment
comment|/* !defined(_KERNEL) */
end_comment

begin_endif
unit|extern void ksort(caddr_t, int, int, int (*)(void *, void *)); extern int cmp2acls(void *, void *);
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_KERNEL) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_else
unit|extern int acl(const char *path, int cmd, int cnt, void *buf); extern int facl(int fd, int cmd, int cnt, void *buf);
else|#
directive|else
end_else

begin_comment
comment|/* !__STDC__ */
end_comment

begin_endif
unit|extern int acl(); extern int facl();
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__STDC__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENSOLARIS_SYS_ACL_H */
end_comment

end_unit

