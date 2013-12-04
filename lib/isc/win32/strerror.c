begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2007  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001, 2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: strerror.c,v 1.8 2007/06/19 23:47:19 tbox Exp $ */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/once.h>
end_include

begin_include
include|#
directive|include
file|<isc/print.h>
end_include

begin_include
include|#
directive|include
file|<isc/strerror.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_comment
comment|/*  * Forward declarations  */
end_comment

begin_function_decl
name|char
modifier|*
name|FormatError
parameter_list|(
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|GetWSAErrorMessage
parameter_list|(
name|int
name|errval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|NTstrerror
parameter_list|(
name|int
name|err
parameter_list|,
name|BOOL
modifier|*
name|bfreebuf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * We need to do this this way for profiled locks.  */
end_comment

begin_decl_stmt
specifier|static
name|isc_mutex_t
name|isc_strerror_lock
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|init_lock
parameter_list|(
name|void
parameter_list|)
block|{
name|RUNTIME_CHECK
argument_list|(
name|isc_mutex_init
argument_list|(
operator|&
name|isc_strerror_lock
argument_list|)
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * This routine needs to free up any buffer allocated by FormatMessage  * if that routine gets used.  */
end_comment

begin_function
name|void
name|isc__strerror
parameter_list|(
name|int
name|num
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|char
modifier|*
name|msg
decl_stmt|;
name|BOOL
name|freebuf
decl_stmt|;
name|unsigned
name|int
name|unum
init|=
name|num
decl_stmt|;
specifier|static
name|isc_once_t
name|once
init|=
name|ISC_ONCE_INIT
decl_stmt|;
name|REQUIRE
argument_list|(
name|buf
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|RUNTIME_CHECK
argument_list|(
name|isc_once_do
argument_list|(
operator|&
name|once
argument_list|,
name|init_lock
argument_list|)
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
name|LOCK
argument_list|(
operator|&
name|isc_strerror_lock
argument_list|)
expr_stmt|;
name|freebuf
operator|=
name|FALSE
expr_stmt|;
name|msg
operator|=
name|NTstrerror
argument_list|(
name|num
argument_list|,
operator|&
name|freebuf
argument_list|)
expr_stmt|;
if|if
condition|(
name|msg
operator|!=
name|NULL
condition|)
name|snprintf
argument_list|(
name|buf
argument_list|,
name|size
argument_list|,
literal|"%s"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
else|else
name|snprintf
argument_list|(
name|buf
argument_list|,
name|size
argument_list|,
literal|"Unknown error: %u"
argument_list|,
name|unum
argument_list|)
expr_stmt|;
if|if
condition|(
name|freebuf
operator|&&
name|msg
operator|!=
name|NULL
condition|)
block|{
name|LocalFree
argument_list|(
name|msg
argument_list|)
expr_stmt|;
block|}
name|UNLOCK
argument_list|(
operator|&
name|isc_strerror_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Note this will cause a memory leak unless the memory allocated here  * is freed by calling LocalFree.  isc__strerror does this before unlocking.  * This only gets called if there is a system type of error and will likely  * be an unusual event.  */
end_comment

begin_function
name|char
modifier|*
name|FormatError
parameter_list|(
name|int
name|error
parameter_list|)
block|{
name|LPVOID
name|lpMsgBuf
init|=
name|NULL
decl_stmt|;
name|FormatMessage
argument_list|(
name|FORMAT_MESSAGE_ALLOCATE_BUFFER
operator||
name|FORMAT_MESSAGE_FROM_SYSTEM
operator||
name|FORMAT_MESSAGE_IGNORE_INSERTS
argument_list|,
name|NULL
argument_list|,
name|error
argument_list|,
comment|/* Default language */
name|MAKELANGID
argument_list|(
name|LANG_NEUTRAL
argument_list|,
name|SUBLANG_DEFAULT
argument_list|)
argument_list|,
operator|(
name|LPTSTR
operator|)
operator|&
name|lpMsgBuf
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
operator|(
name|lpMsgBuf
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * This routine checks the error value and calls the WSA Windows Sockets  * Error message function GetWSAErrorMessage below if it's within that range  * since those messages are not available in the system error messages.  */
end_comment

begin_function
name|char
modifier|*
name|NTstrerror
parameter_list|(
name|int
name|err
parameter_list|,
name|BOOL
modifier|*
name|bfreebuf
parameter_list|)
block|{
name|char
modifier|*
name|retmsg
init|=
name|NULL
decl_stmt|;
comment|/* Copy the error value first in case of other errors */
name|DWORD
name|errval
init|=
name|err
decl_stmt|;
operator|*
name|bfreebuf
operator|=
name|FALSE
expr_stmt|;
comment|/* Get the Winsock2 error messages */
if|if
condition|(
name|errval
operator|>=
name|WSABASEERR
operator|&&
name|errval
operator|<=
operator|(
name|WSABASEERR
operator|+
literal|1015
operator|)
condition|)
block|{
name|retmsg
operator|=
name|GetWSAErrorMessage
argument_list|(
name|errval
argument_list|)
expr_stmt|;
if|if
condition|(
name|retmsg
operator|!=
name|NULL
condition|)
return|return
operator|(
name|retmsg
operator|)
return|;
block|}
comment|/* 	 * If it's not one of the standard Unix error codes, 	 * try a system error message 	 */
if|if
condition|(
name|errval
operator|>
operator|(
name|DWORD
operator|)
name|_sys_nerr
condition|)
block|{
operator|*
name|bfreebuf
operator|=
name|TRUE
expr_stmt|;
return|return
operator|(
name|FormatError
argument_list|(
name|errval
argument_list|)
operator|)
return|;
block|}
else|else
block|{
return|return
operator|(
name|strerror
argument_list|(
name|errval
argument_list|)
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * This is a replacement for perror  */
end_comment

begin_function
name|void
name|__cdecl
name|NTperror
parameter_list|(
name|char
modifier|*
name|errmsg
parameter_list|)
block|{
comment|/* Copy the error value first in case of other errors */
name|int
name|errval
init|=
name|errno
decl_stmt|;
name|BOOL
name|bfreebuf
init|=
name|FALSE
decl_stmt|;
name|char
modifier|*
name|msg
decl_stmt|;
name|msg
operator|=
name|NTstrerror
argument_list|(
name|errval
argument_list|,
operator|&
name|bfreebuf
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s\n"
argument_list|,
name|errmsg
argument_list|,
name|msg
argument_list|)
expr_stmt|;
if|if
condition|(
name|bfreebuf
operator|==
name|TRUE
condition|)
block|{
name|LocalFree
argument_list|(
name|msg
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Return the error string related to Winsock2 errors.  * This function is necessary since FormatMessage knows nothing about them  * and there is no function to get them.  */
end_comment

begin_function
name|char
modifier|*
name|GetWSAErrorMessage
parameter_list|(
name|int
name|errval
parameter_list|)
block|{
name|char
modifier|*
name|msg
decl_stmt|;
switch|switch
condition|(
name|errval
condition|)
block|{
case|case
name|WSAEINTR
case|:
name|msg
operator|=
literal|"Interrupted system call"
expr_stmt|;
break|break;
case|case
name|WSAEBADF
case|:
name|msg
operator|=
literal|"Bad file number"
expr_stmt|;
break|break;
case|case
name|WSAEACCES
case|:
name|msg
operator|=
literal|"Permission denied"
expr_stmt|;
break|break;
case|case
name|WSAEFAULT
case|:
name|msg
operator|=
literal|"Bad address"
expr_stmt|;
break|break;
case|case
name|WSAEINVAL
case|:
name|msg
operator|=
literal|"Invalid argument"
expr_stmt|;
break|break;
case|case
name|WSAEMFILE
case|:
name|msg
operator|=
literal|"Too many open sockets"
expr_stmt|;
break|break;
case|case
name|WSAEWOULDBLOCK
case|:
name|msg
operator|=
literal|"Operation would block"
expr_stmt|;
break|break;
case|case
name|WSAEINPROGRESS
case|:
name|msg
operator|=
literal|"Operation now in progress"
expr_stmt|;
break|break;
case|case
name|WSAEALREADY
case|:
name|msg
operator|=
literal|"Operation already in progress"
expr_stmt|;
break|break;
case|case
name|WSAENOTSOCK
case|:
name|msg
operator|=
literal|"Socket operation on non-socket"
expr_stmt|;
break|break;
case|case
name|WSAEDESTADDRREQ
case|:
name|msg
operator|=
literal|"Destination address required"
expr_stmt|;
break|break;
case|case
name|WSAEMSGSIZE
case|:
name|msg
operator|=
literal|"Message too long"
expr_stmt|;
break|break;
case|case
name|WSAEPROTOTYPE
case|:
name|msg
operator|=
literal|"Protocol wrong type for socket"
expr_stmt|;
break|break;
case|case
name|WSAENOPROTOOPT
case|:
name|msg
operator|=
literal|"Bad protocol option"
expr_stmt|;
break|break;
case|case
name|WSAEPROTONOSUPPORT
case|:
name|msg
operator|=
literal|"Protocol not supported"
expr_stmt|;
break|break;
case|case
name|WSAESOCKTNOSUPPORT
case|:
name|msg
operator|=
literal|"Socket type not supported"
expr_stmt|;
break|break;
case|case
name|WSAEOPNOTSUPP
case|:
name|msg
operator|=
literal|"Operation not supported on socket"
expr_stmt|;
break|break;
case|case
name|WSAEPFNOSUPPORT
case|:
name|msg
operator|=
literal|"Protocol family not supported"
expr_stmt|;
break|break;
case|case
name|WSAEAFNOSUPPORT
case|:
name|msg
operator|=
literal|"Address family not supported"
expr_stmt|;
break|break;
case|case
name|WSAEADDRINUSE
case|:
name|msg
operator|=
literal|"Address already in use"
expr_stmt|;
break|break;
case|case
name|WSAEADDRNOTAVAIL
case|:
name|msg
operator|=
literal|"Can't assign requested address"
expr_stmt|;
break|break;
case|case
name|WSAENETDOWN
case|:
name|msg
operator|=
literal|"Network is down"
expr_stmt|;
break|break;
case|case
name|WSAENETUNREACH
case|:
name|msg
operator|=
literal|"Network is unreachable"
expr_stmt|;
break|break;
case|case
name|WSAENETRESET
case|:
name|msg
operator|=
literal|"Net connection reset"
expr_stmt|;
break|break;
case|case
name|WSAECONNABORTED
case|:
name|msg
operator|=
literal|"Software caused connection abort"
expr_stmt|;
break|break;
case|case
name|WSAECONNRESET
case|:
name|msg
operator|=
literal|"Connection reset by peer"
expr_stmt|;
break|break;
case|case
name|WSAENOBUFS
case|:
name|msg
operator|=
literal|"No buffer space available"
expr_stmt|;
break|break;
case|case
name|WSAEISCONN
case|:
name|msg
operator|=
literal|"Socket is already connected"
expr_stmt|;
break|break;
case|case
name|WSAENOTCONN
case|:
name|msg
operator|=
literal|"Socket is not connected"
expr_stmt|;
break|break;
case|case
name|WSAESHUTDOWN
case|:
name|msg
operator|=
literal|"Can't send after socket shutdown"
expr_stmt|;
break|break;
case|case
name|WSAETOOMANYREFS
case|:
name|msg
operator|=
literal|"Too many references: can't splice"
expr_stmt|;
break|break;
case|case
name|WSAETIMEDOUT
case|:
name|msg
operator|=
literal|"Connection timed out"
expr_stmt|;
break|break;
case|case
name|WSAECONNREFUSED
case|:
name|msg
operator|=
literal|"Connection refused"
expr_stmt|;
break|break;
case|case
name|WSAELOOP
case|:
name|msg
operator|=
literal|"Too many levels of symbolic links"
expr_stmt|;
break|break;
case|case
name|WSAENAMETOOLONG
case|:
name|msg
operator|=
literal|"File name too long"
expr_stmt|;
break|break;
case|case
name|WSAEHOSTDOWN
case|:
name|msg
operator|=
literal|"Host is down"
expr_stmt|;
break|break;
case|case
name|WSAEHOSTUNREACH
case|:
name|msg
operator|=
literal|"No route to host"
expr_stmt|;
break|break;
case|case
name|WSAENOTEMPTY
case|:
name|msg
operator|=
literal|"Directory not empty"
expr_stmt|;
break|break;
case|case
name|WSAEPROCLIM
case|:
name|msg
operator|=
literal|"Too many processes"
expr_stmt|;
break|break;
case|case
name|WSAEUSERS
case|:
name|msg
operator|=
literal|"Too many users"
expr_stmt|;
break|break;
case|case
name|WSAEDQUOT
case|:
name|msg
operator|=
literal|"Disc quota exceeded"
expr_stmt|;
break|break;
case|case
name|WSAESTALE
case|:
name|msg
operator|=
literal|"Stale NFS file handle"
expr_stmt|;
break|break;
case|case
name|WSAEREMOTE
case|:
name|msg
operator|=
literal|"Too many levels of remote in path"
expr_stmt|;
break|break;
case|case
name|WSASYSNOTREADY
case|:
name|msg
operator|=
literal|"Network system is unavailable"
expr_stmt|;
break|break;
case|case
name|WSAVERNOTSUPPORTED
case|:
name|msg
operator|=
literal|"Winsock version out of range"
expr_stmt|;
break|break;
case|case
name|WSANOTINITIALISED
case|:
name|msg
operator|=
literal|"WSAStartup not yet called"
expr_stmt|;
break|break;
case|case
name|WSAEDISCON
case|:
name|msg
operator|=
literal|"Graceful shutdown in progress"
expr_stmt|;
break|break;
comment|/* 	case WSAHOST_NOT_FOUND: 		msg = "Host not found"; 		break;  	case WSANO_DATA: 		msg = "No host data of that type was found"; 		break; */
default|default:
name|msg
operator|=
name|NULL
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|msg
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * These error messages are more informative about CryptAPI Errors than the  * standard error messages  */
end_comment

begin_function
name|char
modifier|*
name|GetCryptErrorMessage
parameter_list|(
name|int
name|errval
parameter_list|)
block|{
name|char
modifier|*
name|msg
decl_stmt|;
switch|switch
condition|(
name|errval
condition|)
block|{
case|case
name|NTE_BAD_FLAGS
case|:
name|msg
operator|=
literal|"The dwFlags parameter has an illegal value."
expr_stmt|;
break|break;
case|case
name|NTE_BAD_KEYSET
case|:
name|msg
operator|=
literal|"The Registry entry for the key container "
literal|"could not be opened and may not exist."
expr_stmt|;
break|break;
case|case
name|NTE_BAD_KEYSET_PARAM
case|:
name|msg
operator|=
literal|"The pszContainer or pszProvider parameter "
literal|"is set to an illegal value."
expr_stmt|;
break|break;
case|case
name|NTE_BAD_PROV_TYPE
case|:
name|msg
operator|=
literal|"The value of the dwProvType parameter is out "
literal|"of range. All provider types must be from "
literal|"1 to 999, inclusive."
expr_stmt|;
break|break;
case|case
name|NTE_BAD_SIGNATURE
case|:
name|msg
operator|=
literal|"The provider DLL signature did not verify "
literal|"correctly. Either the DLL or the digital "
literal|"signature has been tampered with."
expr_stmt|;
break|break;
case|case
name|NTE_EXISTS
case|:
name|msg
operator|=
literal|"The dwFlags parameter is CRYPT_NEWKEYSET, but the key"
literal|" container already exists."
expr_stmt|;
break|break;
case|case
name|NTE_KEYSET_ENTRY_BAD
case|:
name|msg
operator|=
literal|"The Registry entry for the pszContainer key container "
literal|"was found (in the HKEY_CURRENT_USER window), but is "
literal|"corrupt. See the section System Administration for "
literal|" etails about CryptoAPI's Registry usage."
expr_stmt|;
break|break;
case|case
name|NTE_KEYSET_NOT_DEF
case|:
name|msg
operator|=
literal|"No Registry entry exists in the HKEY_CURRENT_USER "
literal|"window for the key container specified by "
literal|"pszContainer."
expr_stmt|;
break|break;
case|case
name|NTE_NO_MEMORY
case|:
name|msg
operator|=
literal|"The CSP ran out of memory during the operation."
expr_stmt|;
break|break;
case|case
name|NTE_PROV_DLL_NOT_FOUND
case|:
name|msg
operator|=
literal|"The provider DLL file does not exist or is not on the "
literal|"current path."
expr_stmt|;
break|break;
case|case
name|NTE_PROV_TYPE_ENTRY_BAD
case|:
name|msg
operator|=
literal|"The Registry entry for the provider type specified by "
literal|"dwProvType is corrupt. This error may relate to "
literal|"either the user default CSP list or the machine "
literal|"default CSP list. See the section System "
literal|"Administration for details about CryptoAPI's "
literal|"Registry usage."
expr_stmt|;
break|break;
case|case
name|NTE_PROV_TYPE_NO_MATCH
case|:
name|msg
operator|=
literal|"The provider type specified by dwProvType does not "
literal|"match the provider type found in the Registry. Note "
literal|"that this error can only occur when pszProvider "
literal|"specifies an actual CSP name."
expr_stmt|;
break|break;
case|case
name|NTE_PROV_TYPE_NOT_DEF
case|:
name|msg
operator|=
literal|"No Registry entry exists for the provider type "
literal|"specified by dwProvType."
expr_stmt|;
break|break;
case|case
name|NTE_PROVIDER_DLL_FAIL
case|:
name|msg
operator|=
literal|"The provider DLL file could not be loaded, and "
literal|"may not exist. If it exists, then the file is "
literal|"not a valid DLL."
expr_stmt|;
break|break;
case|case
name|NTE_SIGNATURE_FILE_BAD
case|:
name|msg
operator|=
literal|"An error occurred while loading the DLL file image, "
literal|"prior to verifying its signature."
expr_stmt|;
break|break;
default|default:
name|msg
operator|=
name|NULL
expr_stmt|;
break|break;
block|}
return|return
name|msg
return|;
block|}
end_function

end_unit

