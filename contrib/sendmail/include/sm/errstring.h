begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2001, 2003 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: errstring.h,v 1.10 2007/03/21 23:56:19 ca Exp $  */
end_comment

begin_comment
comment|/* **  Error codes. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_ERRSTRING_H
end_ifndef

begin_define
define|#
directive|define
name|SM_ERRSTRING_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__QNX__
argument_list|)
end_if

begin_define
define|#
directive|define
name|E_PSEUDOBASE
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__QNX__) */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|NEEDINTERRNO
end_if

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEEDINTERRNO */
end_comment

begin_comment
comment|/* **  These are used in a few cases where we need some special **  error codes, but where the system doesn't provide something **  reasonable.  They are printed in sm_errstring. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|E_PSEUDOBASE
end_ifndef

begin_define
define|#
directive|define
name|E_PSEUDOBASE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! E_PSEUDOBASE */
end_comment

begin_define
define|#
directive|define
name|E_SM_OPENTIMEOUT
value|(E_PSEUDOBASE + 0)
end_define

begin_comment
comment|/* Timeout on file open */
end_comment

begin_define
define|#
directive|define
name|E_SM_NOSLINK
value|(E_PSEUDOBASE + 1)
end_define

begin_comment
comment|/* Symbolic links not allowed */
end_comment

begin_define
define|#
directive|define
name|E_SM_NOHLINK
value|(E_PSEUDOBASE + 2)
end_define

begin_comment
comment|/* Hard links not allowed */
end_comment

begin_define
define|#
directive|define
name|E_SM_REGONLY
value|(E_PSEUDOBASE + 3)
end_define

begin_comment
comment|/* Regular files only */
end_comment

begin_define
define|#
directive|define
name|E_SM_ISEXEC
value|(E_PSEUDOBASE + 4)
end_define

begin_comment
comment|/* Executable files not allowed */
end_comment

begin_define
define|#
directive|define
name|E_SM_WWDIR
value|(E_PSEUDOBASE + 5)
end_define

begin_comment
comment|/* World writable directory */
end_comment

begin_define
define|#
directive|define
name|E_SM_GWDIR
value|(E_PSEUDOBASE + 6)
end_define

begin_comment
comment|/* Group writable directory */
end_comment

begin_define
define|#
directive|define
name|E_SM_FILECHANGE
value|(E_PSEUDOBASE + 7)
end_define

begin_comment
comment|/* File changed after open */
end_comment

begin_define
define|#
directive|define
name|E_SM_WWFILE
value|(E_PSEUDOBASE + 8)
end_define

begin_comment
comment|/* World writable file */
end_comment

begin_define
define|#
directive|define
name|E_SM_GWFILE
value|(E_PSEUDOBASE + 9)
end_define

begin_comment
comment|/* Group writable file */
end_comment

begin_define
define|#
directive|define
name|E_SM_GRFILE
value|(E_PSEUDOBASE + 10)
end_define

begin_comment
comment|/* g readable file */
end_comment

begin_define
define|#
directive|define
name|E_SM_WRFILE
value|(E_PSEUDOBASE + 11)
end_define

begin_comment
comment|/* o readable file */
end_comment

begin_define
define|#
directive|define
name|E_DNSBASE
value|(E_PSEUDOBASE + 20)
end_define

begin_comment
comment|/* base for DNS h_errno */
end_comment

begin_define
define|#
directive|define
name|E_SMDBBASE
value|(E_PSEUDOBASE + 40)
end_define

begin_comment
comment|/* base for libsmdb errors */
end_comment

begin_define
define|#
directive|define
name|E_LDAPBASE
value|(E_PSEUDOBASE + 70)
end_define

begin_comment
comment|/* base for LDAP errors */
end_comment

begin_define
define|#
directive|define
name|E_LDAPURLBASE
value|(E_PSEUDOBASE + 200)
end_define

begin_comment
comment|/* base for LDAP URL errors */
end_comment

begin_comment
comment|/* libsmdb */
end_comment

begin_define
define|#
directive|define
name|SMDBE_OK
value|0
end_define

begin_define
define|#
directive|define
name|SMDBE_MALLOC
value|(E_SMDBBASE + 1)
end_define

begin_define
define|#
directive|define
name|SMDBE_GDBM_IS_BAD
value|(E_SMDBBASE + 2)
end_define

begin_define
define|#
directive|define
name|SMDBE_UNSUPPORTED
value|(E_SMDBBASE + 3)
end_define

begin_define
define|#
directive|define
name|SMDBE_DUPLICATE
value|(E_SMDBBASE + 4)
end_define

begin_define
define|#
directive|define
name|SMDBE_BAD_OPEN
value|(E_SMDBBASE + 5)
end_define

begin_define
define|#
directive|define
name|SMDBE_NOT_FOUND
value|(E_SMDBBASE + 6)
end_define

begin_define
define|#
directive|define
name|SMDBE_UNKNOWN_DB_TYPE
value|(E_SMDBBASE + 7)
end_define

begin_define
define|#
directive|define
name|SMDBE_UNSUPPORTED_DB_TYPE
value|(E_SMDBBASE + 8)
end_define

begin_define
define|#
directive|define
name|SMDBE_INCOMPLETE
value|(E_SMDBBASE + 9)
end_define

begin_define
define|#
directive|define
name|SMDBE_KEY_EMPTY
value|(E_SMDBBASE + 10)
end_define

begin_define
define|#
directive|define
name|SMDBE_KEY_EXIST
value|(E_SMDBBASE + 11)
end_define

begin_define
define|#
directive|define
name|SMDBE_LOCK_DEADLOCK
value|(E_SMDBBASE + 12)
end_define

begin_define
define|#
directive|define
name|SMDBE_LOCK_NOT_GRANTED
value|(E_SMDBBASE + 13)
end_define

begin_define
define|#
directive|define
name|SMDBE_LOCK_NOT_HELD
value|(E_SMDBBASE + 14)
end_define

begin_define
define|#
directive|define
name|SMDBE_RUN_RECOVERY
value|(E_SMDBBASE + 15)
end_define

begin_define
define|#
directive|define
name|SMDBE_IO_ERROR
value|(E_SMDBBASE + 16)
end_define

begin_define
define|#
directive|define
name|SMDBE_READ_ONLY
value|(E_SMDBBASE + 17)
end_define

begin_define
define|#
directive|define
name|SMDBE_DB_NAME_TOO_LONG
value|(E_SMDBBASE + 18)
end_define

begin_define
define|#
directive|define
name|SMDBE_INVALID_PARAMETER
value|(E_SMDBBASE + 19)
end_define

begin_define
define|#
directive|define
name|SMDBE_ONLY_SUPPORTS_ONE_CURSOR
value|(E_SMDBBASE + 20)
end_define

begin_define
define|#
directive|define
name|SMDBE_NOT_A_VALID_CURSOR
value|(E_SMDBBASE + 21)
end_define

begin_define
define|#
directive|define
name|SMDBE_LAST_ENTRY
value|(E_SMDBBASE + 22)
end_define

begin_define
define|#
directive|define
name|SMDBE_OLD_VERSION
value|(E_SMDBBASE + 23)
end_define

begin_define
define|#
directive|define
name|SMDBE_VERSION_MISMATCH
value|(E_SMDBBASE + 24)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|sm_errstring
name|__P
argument_list|(
operator|(
name|int
name|_errno
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_ERRSTRING_H */
end_comment

end_unit

