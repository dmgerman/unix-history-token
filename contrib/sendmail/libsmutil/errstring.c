begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2000 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1983, 1995-1997 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|id
index|[]
init|=
literal|"@(#)$Id: errstring.c,v 8.8.4.1 2000/05/26 18:16:28 geir Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! lint */
end_comment

begin_include
include|#
directive|include
file|<sendmail.h>
end_include

begin_comment
comment|/* **  ERRSTRING -- return string description of error code ** **	Parameters: **		errnum -- the error number to translate ** **	Returns: **		A string description of errnum. ** **	Side Effects: **		none. */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|errstring
parameter_list|(
name|errnum
parameter_list|)
name|int
name|errnum
decl_stmt|;
block|{
if|#
directive|if
operator|!
name|HASSTRERROR
operator|&&
operator|!
name|defined
argument_list|(
name|ERRLIST_PREDEFINED
argument_list|)
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
endif|#
directive|endif
comment|/* !HASSTRERROR&& !defined(ERRLIST_PREDEFINED) */
comment|/* 	**  Handle special network error codes. 	** 	**	These are 4.2/4.3bsd specific; they should be in daemon.c. 	*/
switch|switch
condition|(
name|errnum
condition|)
block|{
case|case
name|EPERM
case|:
comment|/* SunOS gives "Not owner" -- this is the POSIX message */
return|return
literal|"Operation not permitted"
return|;
comment|/* 	**  Error messages used internally in sendmail. 	*/
case|case
name|E_SM_OPENTIMEOUT
case|:
return|return
literal|"Timeout on file open"
return|;
case|case
name|E_SM_NOSLINK
case|:
return|return
literal|"Symbolic links not allowed"
return|;
case|case
name|E_SM_NOHLINK
case|:
return|return
literal|"Hard links not allowed"
return|;
case|case
name|E_SM_REGONLY
case|:
return|return
literal|"Regular files only"
return|;
case|case
name|E_SM_ISEXEC
case|:
return|return
literal|"Executable files not allowed"
return|;
case|case
name|E_SM_WWDIR
case|:
return|return
literal|"World writable directory"
return|;
case|case
name|E_SM_GWDIR
case|:
return|return
literal|"Group writable directory"
return|;
case|case
name|E_SM_FILECHANGE
case|:
return|return
literal|"File changed after open"
return|;
case|case
name|E_SM_WWFILE
case|:
return|return
literal|"World writable file"
return|;
case|case
name|E_SM_GWFILE
case|:
return|return
literal|"Group writable file"
return|;
case|case
name|E_SM_GRFILE
case|:
return|return
literal|"Group readable file"
return|;
case|case
name|E_SM_WRFILE
case|:
return|return
literal|"World readable file"
return|;
comment|/* 	**  DNS error messages. 	*/
if|#
directive|if
name|NAMED_BIND
case|case
name|HOST_NOT_FOUND
operator|+
name|E_DNSBASE
case|:
return|return
literal|"Name server: host not found"
return|;
case|case
name|TRY_AGAIN
operator|+
name|E_DNSBASE
case|:
return|return
literal|"Name server: host name lookup failure"
return|;
case|case
name|NO_RECOVERY
operator|+
name|E_DNSBASE
case|:
return|return
literal|"Name server: non-recoverable error"
return|;
case|case
name|NO_DATA
operator|+
name|E_DNSBASE
case|:
return|return
literal|"Name server: no data known"
return|;
endif|#
directive|endif
comment|/* NAMED_BIND */
comment|/* 	**  libsmdb error messages. 	*/
case|case
name|SMDBE_MALLOC
case|:
return|return
literal|"Memory allocation failed"
return|;
case|case
name|SMDBE_GDBM_IS_BAD
case|:
return|return
literal|"GDBM is not supported"
return|;
case|case
name|SMDBE_UNSUPPORTED
case|:
return|return
literal|"Unsupported action"
return|;
case|case
name|SMDBE_DUPLICATE
case|:
return|return
literal|"Key already exists"
return|;
case|case
name|SMDBE_BAD_OPEN
case|:
return|return
literal|"Database open failed"
return|;
case|case
name|SMDBE_NOT_FOUND
case|:
return|return
literal|"Key not found"
return|;
case|case
name|SMDBE_UNKNOWN_DB_TYPE
case|:
return|return
literal|"Unknown database type"
return|;
case|case
name|SMDBE_UNSUPPORTED_DB_TYPE
case|:
return|return
literal|"Support for database type not compiled into this program"
return|;
case|case
name|SMDBE_INCOMPLETE
case|:
return|return
literal|"DB sync did not finish"
return|;
case|case
name|SMDBE_KEY_EMPTY
case|:
return|return
literal|"Key is empty"
return|;
case|case
name|SMDBE_KEY_EXIST
case|:
return|return
literal|"Key already exists"
return|;
case|case
name|SMDBE_LOCK_DEADLOCK
case|:
return|return
literal|"Locker killed to resolve deadlock"
return|;
case|case
name|SMDBE_LOCK_NOT_GRANTED
case|:
return|return
literal|"Lock unavailable"
return|;
case|case
name|SMDBE_LOCK_NOT_HELD
case|:
return|return
literal|"Lock not held by locker"
return|;
case|case
name|SMDBE_RUN_RECOVERY
case|:
return|return
literal|"Database panic, run recovery"
return|;
case|case
name|SMDBE_IO_ERROR
case|:
return|return
literal|"I/O error"
return|;
case|case
name|SMDBE_READ_ONLY
case|:
return|return
literal|"Database opened read-only"
return|;
case|case
name|SMDBE_DB_NAME_TOO_LONG
case|:
return|return
literal|"Name too long"
return|;
case|case
name|SMDBE_INVALID_PARAMETER
case|:
return|return
literal|"Invalid parameter"
return|;
case|case
name|SMDBE_ONLY_SUPPORTS_ONE_CURSOR
case|:
return|return
literal|"Only one cursor allowed"
return|;
case|case
name|SMDBE_NOT_A_VALID_CURSOR
case|:
return|return
literal|"Invalid cursor"
return|;
case|case
name|SMDBE_OLD_VERSION
case|:
return|return
literal|"Berkeley DB file is an old version, recreate it"
return|;
block|}
comment|/* 	**  LDAP error messages. 	*/
ifdef|#
directive|ifdef
name|LDAPMAP
if|if
condition|(
name|errnum
operator|>=
name|E_LDAPBASE
condition|)
return|return
name|ldap_err2string
argument_list|(
name|errnum
operator|-
name|E_LDAPBASE
argument_list|)
return|;
endif|#
directive|endif
comment|/* LDAPMAP */
if|#
directive|if
name|HASSTRERROR
return|return
name|strerror
argument_list|(
name|errnum
argument_list|)
return|;
else|#
directive|else
comment|/* HASSTRERROR */
if|if
condition|(
name|errnum
operator|>
literal|0
operator|&&
name|errnum
operator|<
name|sys_nerr
condition|)
return|return
name|sys_errlist
index|[
name|errnum
index|]
return|;
else|else
block|{
specifier|static
name|char
name|buf
index|[
name|MAXLINE
index|]
decl_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
literal|"Error %d"
argument_list|,
name|errnum
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
endif|#
directive|endif
comment|/* HASSTRERROR */
block|}
end_function

end_unit

