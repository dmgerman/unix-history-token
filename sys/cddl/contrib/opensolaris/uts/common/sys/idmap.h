begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_IDMAP_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_IDMAP_H
end_define

begin_comment
comment|/* Idmap status codes */
end_comment

begin_define
define|#
directive|define
name|IDMAP_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|IDMAP_NEXT
value|1
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_OTHER
value|-10000
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_INTERNAL
value|-9999
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_MEMORY
value|-9998
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NORESULT
value|-9997
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NOTUSER
value|-9996
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NOTGROUP
value|-9995
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NOTSUPPORTED
value|-9994
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_W2U_NAMERULE
value|-9993
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_U2W_NAMERULE
value|-9992
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_CACHE
value|-9991
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_DB
value|-9990
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_ARG
value|-9989
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_SID
value|-9988
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_IDTYPE
value|-9987
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_RPC_HANDLE
value|-9986
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_RPC
value|-9985
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_CLIENT_HANDLE
value|-9984
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_BUSY
value|-9983
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_PERMISSION_DENIED
value|-9982
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NOMAPPING
value|-9981
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NEW_ID_ALLOC_REQD
value|-9980
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_DOMAIN
value|-9979
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_SECURITY
value|-9978
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NOTFOUND
value|-9977
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_DOMAIN_NOTFOUND
value|-9976
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_UPDATE_NOTALLOWED
value|-9975
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_CFG
value|-9974
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_CFG_CHANGE
value|-9973
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NOTMAPPED_WELLKNOWN
value|-9972
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_RETRIABLE_NET_ERR
value|-9971
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_W2U_NAMERULE_CONFLICT
value|-9970
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_U2W_NAMERULE_CONFLICT
value|-9969
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_BAD_UTF8
value|-9968
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NONE_GENERATED
value|-9967
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_PROP_UNKNOWN
value|-9966
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NS_LDAP_OP_FAILED
value|-9965
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NS_LDAP_PARTIAL
value|-9964
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NS_LDAP_CFG
value|-9963
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NS_LDAP_BAD_WINNAME
value|-9962
end_define

begin_define
define|#
directive|define
name|IDMAP_ERR_NO_ACTIVEDIRECTORY
value|-9961
end_define

begin_comment
comment|/* Reserved GIDs for some well-known SIDs */
end_comment

begin_define
define|#
directive|define
name|IDMAP_WK_LOCAL_SYSTEM_GID
value|2147483648U
end_define

begin_comment
comment|/* 0x80000000 */
end_comment

begin_define
define|#
directive|define
name|IDMAP_WK_CREATOR_GROUP_GID
value|2147483649U
end_define

begin_define
define|#
directive|define
name|IDMAP_WK__MAX_GID
value|2147483649U
end_define

begin_comment
comment|/* Reserved UIDs for some well-known SIDs */
end_comment

begin_define
define|#
directive|define
name|IDMAP_WK_CREATOR_OWNER_UID
value|2147483648U
end_define

begin_define
define|#
directive|define
name|IDMAP_WK__MAX_UID
value|2147483648U
end_define

begin_comment
comment|/* Reserved SIDs */
end_comment

begin_define
define|#
directive|define
name|IDMAP_WK_CREATOR_SID_AUTHORITY
value|"S-1-3"
end_define

begin_comment
comment|/*  * Max door RPC size for ID mapping (can't be too large relative to the  * default user-land thread stack size, since clnt_door_call()  * alloca()s).  See libidmap:idmap_init().  */
end_comment

begin_define
define|#
directive|define
name|IDMAP_MAX_DOOR_RPC
value|(256 * 1024)
end_define

begin_define
define|#
directive|define
name|IDMAP_SENTINEL_PID
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|IDMAP_ID_IS_EPHEMERAL
parameter_list|(
name|pid
parameter_list|)
define|\
value|(((pid)> INT32_MAX)&& ((pid) != IDMAP_SENTINEL_PID))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_IDMAP_H */
end_comment

end_unit

