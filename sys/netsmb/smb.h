begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Common definitions and structures for SMB/CIFS protocol  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETSMB_SMB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETSMB_SMB_H_
end_define

begin_define
define|#
directive|define
name|SMB_TCP_PORT
value|139
end_define

begin_comment
comment|/*  * SMB dialects that we have to deal with.  */
end_comment

begin_enum
enum|enum
name|smb_dialects
block|{
name|SMB_DIALECT_NONE
block|,
name|SMB_DIALECT_CORE
block|,
comment|/* PC NETWORK PROGRAM 1.0, PCLAN1.0 */
name|SMB_DIALECT_COREPLUS
block|,
comment|/* MICROSOFT NETWORKS 1.03 */
name|SMB_DIALECT_LANMAN1_0
block|,
comment|/* MICROSOFT NETWORKS 3.0, LANMAN1.0 */
name|SMB_DIALECT_LANMAN2_0
block|,
comment|/* LM1.2X002, DOS LM1.2X002, Samba */
name|SMB_DIALECT_LANMAN2_1
block|,
comment|/* DOS LANMAN2.1, LANMAN2.1 */
name|SMB_DIALECT_NTLM0_12
comment|/* NT LM 0.12, Windows for Workgroups 3.1a, 					 * NT LANMAN 1.0 */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Formats of data/string buffers  */
end_comment

begin_define
define|#
directive|define
name|SMB_DT_DATA
value|1
end_define

begin_define
define|#
directive|define
name|SMB_DT_DIALECT
value|2
end_define

begin_define
define|#
directive|define
name|SMB_DT_PATHNAME
value|3
end_define

begin_define
define|#
directive|define
name|SMB_DT_ASCII
value|4
end_define

begin_define
define|#
directive|define
name|SMB_DT_VARIABLE
value|5
end_define

begin_comment
comment|/*  * SMB header  */
end_comment

begin_define
define|#
directive|define
name|SMB_SIGNATURE
value|"\xFFSMB"
end_define

begin_define
define|#
directive|define
name|SMB_SIGLEN
value|4
end_define

begin_define
define|#
directive|define
name|SMB_HDRMID
parameter_list|(
name|p
parameter_list|)
value|(letohs(*(u_short*)((u_char*)(p) + 30)))
end_define

begin_define
define|#
directive|define
name|SMB_HDRLEN
value|32
end_define

begin_comment
comment|/*  * bits in the smb_flags field  */
end_comment

begin_define
define|#
directive|define
name|SMB_FLAGS_CASELESS
value|0x08
end_define

begin_define
define|#
directive|define
name|SMB_FLAGS_SERVER_RESP
value|0x80
end_define

begin_comment
comment|/* indicates a response */
end_comment

begin_comment
comment|/*  * bits in the smb_flags2 field  */
end_comment

begin_define
define|#
directive|define
name|SMB_FLAGS2_KNOWS_LONG_NAMES
value|0x0001
end_define

begin_define
define|#
directive|define
name|SMB_FLAGS2_KNOWS_EAS
value|0x0002
end_define

begin_comment
comment|/* client know about EAs */
end_comment

begin_define
define|#
directive|define
name|SMB_FLAGS2_SECURITY_SIGNATURE
value|0x0004
end_define

begin_comment
comment|/* check SMB integrity */
end_comment

begin_define
define|#
directive|define
name|SMB_FLAGS2_IS_LONG_NAME
value|0x0040
end_define

begin_comment
comment|/* any path name is a long name */
end_comment

begin_define
define|#
directive|define
name|SMB_FLAGS2_EXT_SEC
value|0x0800
end_define

begin_comment
comment|/* client aware of Extended 						 * Security negotiation */
end_comment

begin_define
define|#
directive|define
name|SMB_FLAGS2_DFS
value|0x1000
end_define

begin_comment
comment|/* resolve paths in DFS */
end_comment

begin_define
define|#
directive|define
name|SMB_FLAGS2_PAGING_IO
value|0x2000
end_define

begin_comment
comment|/* for exec */
end_comment

begin_define
define|#
directive|define
name|SMB_FLAGS2_ERR_STATUS
value|0x4000
end_define

begin_comment
comment|/* 1 - status.status */
end_comment

begin_define
define|#
directive|define
name|SMB_FLAGS2_UNICODE
value|0x8000
end_define

begin_comment
comment|/* use Unicode for all strings */
end_comment

begin_define
define|#
directive|define
name|SMB_UID_UNKNOWN
value|0xffff
end_define

begin_define
define|#
directive|define
name|SMB_TID_UNKNOWN
value|0xffff
end_define

begin_comment
comment|/*  * Security mode bits  */
end_comment

begin_define
define|#
directive|define
name|SMB_SM_USER
value|0x01
end_define

begin_comment
comment|/* server in the user security mode */
end_comment

begin_define
define|#
directive|define
name|SMB_SM_ENCRYPT
value|0x02
end_define

begin_comment
comment|/* use challenge/response */
end_comment

begin_comment
comment|/*  * NTLM capabilities  */
end_comment

begin_define
define|#
directive|define
name|SMB_CAP_RAW_MODE
value|0x0001
end_define

begin_define
define|#
directive|define
name|SMB_CAP_MPX_MODE
value|0x0002
end_define

begin_define
define|#
directive|define
name|SMB_CAP_UNICODE
value|0x0004
end_define

begin_define
define|#
directive|define
name|SMB_CAP_LARGE_FILES
value|0x0008
end_define

begin_comment
comment|/* 64 bit offsets supported */
end_comment

begin_define
define|#
directive|define
name|SMB_CAP_NT_SMBS
value|0x0010
end_define

begin_define
define|#
directive|define
name|SMB_CAP_NT_FIND
value|0x0200
end_define

begin_define
define|#
directive|define
name|SMB_CAP_EXT_SECURITY
value|0x80000000
end_define

begin_comment
comment|/*  * File attributes  */
end_comment

begin_define
define|#
directive|define
name|SMB_FA_RDONLY
value|0x01
end_define

begin_define
define|#
directive|define
name|SMB_FA_HIDDEN
value|0x02
end_define

begin_define
define|#
directive|define
name|SMB_FA_SYSTEM
value|0x04
end_define

begin_define
define|#
directive|define
name|SMB_FA_VOLUME
value|0x08
end_define

begin_define
define|#
directive|define
name|SMB_FA_DIR
value|0x10
end_define

begin_define
define|#
directive|define
name|SMB_FA_ARCHIVE
value|0x20
end_define

begin_comment
comment|/*  * Extended file attributes  */
end_comment

begin_define
define|#
directive|define
name|SMB_EFA_RDONLY
value|0x0001
end_define

begin_define
define|#
directive|define
name|SMB_EFA_HIDDEN
value|0x0002
end_define

begin_define
define|#
directive|define
name|SMB_EFA_SYSTEM
value|0x0004
end_define

begin_define
define|#
directive|define
name|SMB_EFA_ARCHIVE
value|0x0020
end_define

begin_define
define|#
directive|define
name|SMB_EFA_NORMAL
value|0x0080
end_define

begin_define
define|#
directive|define
name|SMB_EFA_TEMPORARY
value|0x0100
end_define

begin_define
define|#
directive|define
name|SMB_EFA_COMPRESSED
value|0x0800
end_define

begin_define
define|#
directive|define
name|SMB_EFA_POSIX_SEMANTICS
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SMB_EFA_BACKUP_SEMANTICS
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SMB_EFA_DELETE_ON_CLOSE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SMB_EFA_SEQUENTIAL_SCAN
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SMB_EFA_RANDOM_ACCESS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SMB_EFA_NO_BUFFERING
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SMB_EFA_WRITE_THROUGH
value|0x80000000
end_define

begin_comment
comment|/*  * Access Mode Encoding  */
end_comment

begin_define
define|#
directive|define
name|SMB_AM_OPENREAD
value|0x0000
end_define

begin_define
define|#
directive|define
name|SMB_AM_OPENWRITE
value|0x0001
end_define

begin_define
define|#
directive|define
name|SMB_AM_OPENRW
value|0x0002
end_define

begin_define
define|#
directive|define
name|SMB_AM_OPENEXEC
value|0x0003
end_define

begin_define
define|#
directive|define
name|SMB_SM_COMPAT
value|0x0000
end_define

begin_define
define|#
directive|define
name|SMB_SM_EXCLUSIVE
value|0x0010
end_define

begin_define
define|#
directive|define
name|SMB_SM_DENYWRITE
value|0x0020
end_define

begin_define
define|#
directive|define
name|SMB_SM_DENYREADEXEC
value|0x0030
end_define

begin_define
define|#
directive|define
name|SMB_SM_DENYNONE
value|0x0040
end_define

begin_comment
comment|/*  * SMB commands  */
end_comment

begin_define
define|#
directive|define
name|SMB_COM_CREATE_DIRECTORY
value|0x00
end_define

begin_define
define|#
directive|define
name|SMB_COM_DELETE_DIRECTORY
value|0x01
end_define

begin_define
define|#
directive|define
name|SMB_COM_OPEN
value|0x02
end_define

begin_define
define|#
directive|define
name|SMB_COM_CREATE
value|0x03
end_define

begin_define
define|#
directive|define
name|SMB_COM_CLOSE
value|0x04
end_define

begin_define
define|#
directive|define
name|SMB_COM_FLUSH
value|0x05
end_define

begin_define
define|#
directive|define
name|SMB_COM_DELETE
value|0x06
end_define

begin_define
define|#
directive|define
name|SMB_COM_RENAME
value|0x07
end_define

begin_define
define|#
directive|define
name|SMB_COM_QUERY_INFORMATION
value|0x08
end_define

begin_define
define|#
directive|define
name|SMB_COM_SET_INFORMATION
value|0x09
end_define

begin_define
define|#
directive|define
name|SMB_COM_READ
value|0x0A
end_define

begin_define
define|#
directive|define
name|SMB_COM_WRITE
value|0x0B
end_define

begin_define
define|#
directive|define
name|SMB_COM_LOCK_BYTE_RANGE
value|0x0C
end_define

begin_define
define|#
directive|define
name|SMB_COM_UNLOCK_BYTE_RANGE
value|0x0D
end_define

begin_define
define|#
directive|define
name|SMB_COM_CREATE_TEMPORARY
value|0x0E
end_define

begin_define
define|#
directive|define
name|SMB_COM_CREATE_NEW
value|0x0F
end_define

begin_define
define|#
directive|define
name|SMB_COM_CHECK_DIRECTORY
value|0x10
end_define

begin_define
define|#
directive|define
name|SMB_COM_PROCESS_EXIT
value|0x11
end_define

begin_define
define|#
directive|define
name|SMB_COM_SEEK
value|0x12
end_define

begin_define
define|#
directive|define
name|SMB_COM_LOCK_AND_READ
value|0x13
end_define

begin_define
define|#
directive|define
name|SMB_COM_WRITE_AND_UNLOCK
value|0x14
end_define

begin_define
define|#
directive|define
name|SMB_COM_READ_RAW
value|0x1A
end_define

begin_define
define|#
directive|define
name|SMB_COM_READ_MPX
value|0x1B
end_define

begin_define
define|#
directive|define
name|SMB_COM_READ_MPX_SECONDARY
value|0x1C
end_define

begin_define
define|#
directive|define
name|SMB_COM_WRITE_RAW
value|0x1D
end_define

begin_define
define|#
directive|define
name|SMB_COM_WRITE_MPX
value|0x1E
end_define

begin_define
define|#
directive|define
name|SMB_COM_WRITE_COMPLETE
value|0x20
end_define

begin_define
define|#
directive|define
name|SMB_COM_SET_INFORMATION2
value|0x22
end_define

begin_define
define|#
directive|define
name|SMB_COM_QUERY_INFORMATION2
value|0x23
end_define

begin_define
define|#
directive|define
name|SMB_COM_LOCKING_ANDX
value|0x24
end_define

begin_define
define|#
directive|define
name|SMB_COM_TRANSACTION
value|0x25
end_define

begin_define
define|#
directive|define
name|SMB_COM_TRANSACTION_SECONDARY
value|0x26
end_define

begin_define
define|#
directive|define
name|SMB_COM_IOCTL
value|0x27
end_define

begin_define
define|#
directive|define
name|SMB_COM_IOCTL_SECONDARY
value|0x28
end_define

begin_define
define|#
directive|define
name|SMB_COM_COPY
value|0x29
end_define

begin_define
define|#
directive|define
name|SMB_COM_MOVE
value|0x2A
end_define

begin_define
define|#
directive|define
name|SMB_COM_ECHO
value|0x2B
end_define

begin_define
define|#
directive|define
name|SMB_COM_WRITE_AND_CLOSE
value|0x2C
end_define

begin_define
define|#
directive|define
name|SMB_COM_OPEN_ANDX
value|0x2D
end_define

begin_define
define|#
directive|define
name|SMB_COM_READ_ANDX
value|0x2E
end_define

begin_define
define|#
directive|define
name|SMB_COM_WRITE_ANDX
value|0x2F
end_define

begin_define
define|#
directive|define
name|SMB_COM_CLOSE_AND_TREE_DISC
value|0x31
end_define

begin_define
define|#
directive|define
name|SMB_COM_TRANSACTION2
value|0x32
end_define

begin_define
define|#
directive|define
name|SMB_COM_TRANSACTION2_SECONDARY
value|0x33
end_define

begin_define
define|#
directive|define
name|SMB_COM_FIND_CLOSE2
value|0x34
end_define

begin_define
define|#
directive|define
name|SMB_COM_FIND_NOTIFY_CLOSE
value|0x35
end_define

begin_define
define|#
directive|define
name|SMB_COM_TREE_CONNECT
value|0x70
end_define

begin_define
define|#
directive|define
name|SMB_COM_TREE_DISCONNECT
value|0x71
end_define

begin_define
define|#
directive|define
name|SMB_COM_NEGOTIATE
value|0x72
end_define

begin_define
define|#
directive|define
name|SMB_COM_SESSION_SETUP_ANDX
value|0x73
end_define

begin_define
define|#
directive|define
name|SMB_COM_LOGOFF_ANDX
value|0x74
end_define

begin_define
define|#
directive|define
name|SMB_COM_TREE_CONNECT_ANDX
value|0x75
end_define

begin_define
define|#
directive|define
name|SMB_COM_QUERY_INFORMATION_DISK
value|0x80
end_define

begin_define
define|#
directive|define
name|SMB_COM_SEARCH
value|0x81
end_define

begin_define
define|#
directive|define
name|SMB_COM_FIND
value|0x82
end_define

begin_define
define|#
directive|define
name|SMB_COM_FIND_UNIQUE
value|0x83
end_define

begin_define
define|#
directive|define
name|SMB_COM_NT_TRANSACT
value|0xA0
end_define

begin_define
define|#
directive|define
name|SMB_COM_NT_TRANSACT_SECONDARY
value|0xA1
end_define

begin_define
define|#
directive|define
name|SMB_COM_NT_CREATE_ANDX
value|0xA2
end_define

begin_define
define|#
directive|define
name|SMB_COM_NT_CANCEL
value|0xA4
end_define

begin_define
define|#
directive|define
name|SMB_COM_OPEN_PRINT_FILE
value|0xC0
end_define

begin_define
define|#
directive|define
name|SMB_COM_WRITE_PRINT_FILE
value|0xC1
end_define

begin_define
define|#
directive|define
name|SMB_COM_CLOSE_PRINT_FILE
value|0xC2
end_define

begin_define
define|#
directive|define
name|SMB_COM_GET_PRINT_QUEUE
value|0xC3
end_define

begin_define
define|#
directive|define
name|SMB_COM_READ_BULK
value|0xD8
end_define

begin_define
define|#
directive|define
name|SMB_COM_WRITE_BULK
value|0xD9
end_define

begin_define
define|#
directive|define
name|SMB_COM_WRITE_BULK_DATA
value|0xDA
end_define

begin_comment
comment|/*  * TRANS2 commands  */
end_comment

begin_define
define|#
directive|define
name|SMB_TRANS2_OPEN2
value|0x00
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_FIND_FIRST2
value|0x01
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_FIND_NEXT2
value|0x02
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_QUERY_FS_INFORMATION
value|0x03
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_QUERY_PATH_INFORMATION
value|0x05
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_SET_PATH_INFORMATION
value|0x06
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_QUERY_FILE_INFORMATION
value|0x07
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_SET_FILE_INFORMATION
value|0x08
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_FSCTL
value|0x09
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_IOCTL2
value|0x0A
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_FIND_NOTIFY_FIRST
value|0x0B
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_FIND_NOTIFY_NEXT
value|0x0C
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_CREATE_DIRECTORY
value|0x0D
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_SESSION_SETUP
value|0x0E
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_GET_DFS_REFERRAL
value|0x10
end_define

begin_define
define|#
directive|define
name|SMB_TRANS2_REPORT_DFS_INCONSISTENCY
value|0x11
end_define

begin_comment
comment|/*  * SMB_TRANS2_QUERY_FS_INFORMATION levels  */
end_comment

begin_define
define|#
directive|define
name|SMB_INFO_ALLOCATION
value|1
end_define

begin_define
define|#
directive|define
name|SMB_INFO_VOLUME
value|2
end_define

begin_define
define|#
directive|define
name|SMB_QUERY_FS_VOLUME_INFO
value|0x102
end_define

begin_define
define|#
directive|define
name|SMB_QUERY_FS_SIZE_INFO
value|0x103
end_define

begin_define
define|#
directive|define
name|SMB_QUERY_FS_DEVICE_INFO
value|0x104
end_define

begin_define
define|#
directive|define
name|SMB_QUERY_FS_ATTRIBUTE_INFO
value|0x105
end_define

begin_comment
comment|/*  * SMB_TRANS2_FIND_FIRST2 information levels  */
end_comment

begin_define
define|#
directive|define
name|SMB_INFO_STANDARD
value|1
end_define

begin_define
define|#
directive|define
name|SMB_INFO_QUERY_EA_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|SMB_INFO_QUERY_EAS_FROM_LIST
value|3
end_define

begin_define
define|#
directive|define
name|SMB_FIND_FILE_DIRECTORY_INFO
value|0x101
end_define

begin_define
define|#
directive|define
name|SMB_FIND_FULL_DIRECTORY_INFO
value|0x102
end_define

begin_define
define|#
directive|define
name|SMB_FIND_FILE_NAMES_INFO
value|0x103
end_define

begin_define
define|#
directive|define
name|SMB_FIND_BOTH_DIRECTORY_INFO
value|0x104
end_define

begin_comment
comment|/*  * Set PATH/FILE information levels  */
end_comment

begin_define
define|#
directive|define
name|SMB_SET_FILE_BASIC_INFO
value|0x101
end_define

begin_define
define|#
directive|define
name|SMB_SET_FILE_END_OF_FILE_INFO
value|0x104
end_define

begin_comment
comment|/*  * LOCKING_ANDX LockType flags  */
end_comment

begin_define
define|#
directive|define
name|SMB_LOCKING_ANDX_SHARED_LOCK
value|0x01
end_define

begin_define
define|#
directive|define
name|SMB_LOCKING_ANDX_OPLOCK_RELEASE
value|0x02
end_define

begin_define
define|#
directive|define
name|SMB_LOCKING_ANDX_CHANGE_LOCKTYPE
value|0x04
end_define

begin_define
define|#
directive|define
name|SMB_LOCKING_ANDX_CANCEL_LOCK
value|0x08
end_define

begin_define
define|#
directive|define
name|SMB_LOCKING_ANDX_LARGE_FILES
value|0x10
end_define

begin_comment
comment|/*  * Some names length limitations. Some of them aren't declared by specs,  * but we need reasonable limits.  */
end_comment

begin_define
define|#
directive|define
name|SMB_MAXSRVNAMELEN
value|15
end_define

begin_comment
comment|/* NetBIOS limit */
end_comment

begin_define
define|#
directive|define
name|SMB_MAXUSERNAMELEN
value|128
end_define

begin_define
define|#
directive|define
name|SMB_MAXPASSWORDLEN
value|128
end_define

begin_define
define|#
directive|define
name|SMB_MAXSHARENAMELEN
value|128
end_define

begin_define
define|#
directive|define
name|SMB_MAXPKTLEN
value|0x1FFFF
end_define

begin_define
define|#
directive|define
name|SMB_MAXCHALLENGELEN
value|8
end_define

begin_define
define|#
directive|define
name|SMB_MAXFNAMELEN
value|255
end_define

begin_comment
comment|/* Keep in sync with MAXNAMLEN */
end_comment

begin_define
define|#
directive|define
name|SMB_MAXRCN
value|3
end_define

begin_comment
comment|/* number of reconnect attempts */
end_comment

begin_comment
comment|/*  * Error classes  */
end_comment

begin_define
define|#
directive|define
name|SMBSUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|ERRDOS
value|0x01
end_define

begin_define
define|#
directive|define
name|ERRSRV
value|0x02
end_define

begin_define
define|#
directive|define
name|ERRHRD
value|0x03
end_define

begin_comment
comment|/* Error is an hardware error. */
end_comment

begin_define
define|#
directive|define
name|ERRCMD
value|0xFF
end_define

begin_comment
comment|/* Command was not in the "SMB" format. */
end_comment

begin_comment
comment|/*  * Error codes for the ERRDOS class  */
end_comment

begin_define
define|#
directive|define
name|ERRbadfunc
value|1
end_define

begin_comment
comment|/* Invalid function */
end_comment

begin_define
define|#
directive|define
name|ERRbadfile
value|2
end_define

begin_comment
comment|/* File not found (last component) */
end_comment

begin_define
define|#
directive|define
name|ERRbadpath
value|3
end_define

begin_comment
comment|/* Directory invalid */
end_comment

begin_define
define|#
directive|define
name|ERRnofids
value|4
end_define

begin_comment
comment|/* Too many open files */
end_comment

begin_define
define|#
directive|define
name|ERRnoaccess
value|5
end_define

begin_comment
comment|/* Access denied */
end_comment

begin_define
define|#
directive|define
name|ERRbadfid
value|6
end_define

begin_comment
comment|/* Invalid file handle */
end_comment

begin_define
define|#
directive|define
name|ERRbadmcb
value|7
end_define

begin_comment
comment|/* Memory control blocks destroyed (huh ?) */
end_comment

begin_define
define|#
directive|define
name|ERRnomem
value|8
end_define

begin_comment
comment|/* Insufficient memory */
end_comment

begin_define
define|#
directive|define
name|ERRbadmem
value|9
end_define

begin_comment
comment|/* Invalid memory block address */
end_comment

begin_define
define|#
directive|define
name|ERRbadenv
value|10
end_define

begin_comment
comment|/* Invalid environment */
end_comment

begin_define
define|#
directive|define
name|ERRbadformat
value|11
end_define

begin_comment
comment|/* Invalid format */
end_comment

begin_define
define|#
directive|define
name|ERRbadaccess
value|12
end_define

begin_comment
comment|/* Invalid open mode */
end_comment

begin_define
define|#
directive|define
name|ERRbaddata
value|13
end_define

begin_comment
comment|/* Invalid data */
end_comment

begin_define
define|#
directive|define
name|ERRbaddrive
value|15
end_define

begin_comment
comment|/* Invalid drive specified */
end_comment

begin_define
define|#
directive|define
name|ERRremcd
value|16
end_define

begin_comment
comment|/* An attempt to delete current directory */
end_comment

begin_define
define|#
directive|define
name|ERRdiffdevice
value|17
end_define

begin_comment
comment|/* cross fs rename/move */
end_comment

begin_define
define|#
directive|define
name|ERRnofiles
value|18
end_define

begin_comment
comment|/* no more files found in file search */
end_comment

begin_define
define|#
directive|define
name|ERRbadshare
value|32
end_define

begin_comment
comment|/* Share mode can't be granted */
end_comment

begin_define
define|#
directive|define
name|ERRlock
value|33
end_define

begin_comment
comment|/* A lock request conflicts with existing lock */
end_comment

begin_define
define|#
directive|define
name|ERRfilexists
value|80
end_define

begin_comment
comment|/* The file named in the request already exists */
end_comment

begin_comment
comment|/*  * Error codes for the ERRSRV class  */
end_comment

begin_define
define|#
directive|define
name|ERRerror
value|1
end_define

begin_comment
comment|/* Non-specific error code */
end_comment

begin_define
define|#
directive|define
name|ERRbadpw
value|2
end_define

begin_comment
comment|/* Bad password */
end_comment

begin_define
define|#
directive|define
name|ERRaccess
value|4
end_define

begin_comment
comment|/* The client doesn't have enough access rights */
end_comment

begin_define
define|#
directive|define
name|ERRinvnid
value|5
end_define

begin_comment
comment|/* The Tid specified in a command is invalid */
end_comment

begin_define
define|#
directive|define
name|ERRinvnetname
value|6
end_define

begin_comment
comment|/* Invalid server name in the tree connect */
end_comment

begin_define
define|#
directive|define
name|ERRinvdevice
value|7
end_define

begin_comment
comment|/* Printer and not printer devices are mixed */
end_comment

begin_define
define|#
directive|define
name|ERRqfull
value|49
end_define

begin_comment
comment|/* Print queue full */
end_comment

begin_define
define|#
directive|define
name|ERRqtoobig
value|50
end_define

begin_comment
comment|/* Print queue full - no space */
end_comment

begin_define
define|#
directive|define
name|ERRinvpfid
value|52
end_define

begin_comment
comment|/* Invalid print file FID */
end_comment

begin_define
define|#
directive|define
name|ERRsmbcmd
value|64
end_define

begin_comment
comment|/* The server did not recognize the command */
end_comment

begin_define
define|#
directive|define
name|ERRsrverror
value|65
end_define

begin_comment
comment|/* The server encountered and internal error */
end_comment

begin_define
define|#
directive|define
name|ERRfilespecs
value|67
end_define

begin_comment
comment|/* The Fid and path name contains an invalid combination */
end_comment

begin_define
define|#
directive|define
name|ERRbadpermits
value|69
end_define

begin_comment
comment|/* Access mode invalid */
end_comment

begin_define
define|#
directive|define
name|ERRsetattrmode
value|71
end_define

begin_comment
comment|/* Attribute mode invalid */
end_comment

begin_define
define|#
directive|define
name|ERRpaused
value|81
end_define

begin_comment
comment|/* Server is paused */
end_comment

begin_define
define|#
directive|define
name|ERRmsgoff
value|82
end_define

begin_comment
comment|/* Not receiving messages */
end_comment

begin_define
define|#
directive|define
name|ERRnoroom
value|83
end_define

begin_comment
comment|/* No room to buffer message */
end_comment

begin_define
define|#
directive|define
name|ERRrmuns
value|87
end_define

begin_comment
comment|/* Too many remote user names */
end_comment

begin_define
define|#
directive|define
name|ERRtimeout
value|88
end_define

begin_comment
comment|/* Operation timed out */
end_comment

begin_define
define|#
directive|define
name|ERRnoresource
value|89
end_define

begin_comment
comment|/* No resources currently available for request */
end_comment

begin_define
define|#
directive|define
name|ERRtoomanyuids
value|90
end_define

begin_comment
comment|/* Too many UIDs active on this session */
end_comment

begin_define
define|#
directive|define
name|ERRbaduid
value|91
end_define

begin_comment
comment|/* The UID is not known in this session */
end_comment

begin_define
define|#
directive|define
name|ERRusempx
value|250
end_define

begin_comment
comment|/* Temporarily unable to support Raw, use MPX mode */
end_comment

begin_define
define|#
directive|define
name|ERRusestd
value|251
end_define

begin_comment
comment|/* Temporarily unable to support Raw, use standard r/w */
end_comment

begin_define
define|#
directive|define
name|ERRcontmpx
value|252
end_define

begin_comment
comment|/* Continue in MPX mode */
end_comment

begin_define
define|#
directive|define
name|ERRnosupport
value|65535
end_define

begin_comment
comment|/* Invalid function */
end_comment

begin_comment
comment|/*  * Error codes for the ERRHRD class  */
end_comment

begin_define
define|#
directive|define
name|ERRnowrite
value|19
end_define

begin_comment
comment|/* write protected media */
end_comment

begin_define
define|#
directive|define
name|ERRbadunit
value|20
end_define

begin_comment
comment|/* Unknown unit */
end_comment

begin_define
define|#
directive|define
name|ERRnotready
value|21
end_define

begin_comment
comment|/* Drive not ready */
end_comment

begin_define
define|#
directive|define
name|ERRbadcmd
value|22
end_define

begin_comment
comment|/* Unknown command */
end_comment

begin_define
define|#
directive|define
name|ERRdata
value|23
end_define

begin_comment
comment|/* Data error (CRC) */
end_comment

begin_define
define|#
directive|define
name|ERRbadreq
value|24
end_define

begin_comment
comment|/* Bad request structure length */
end_comment

begin_define
define|#
directive|define
name|ERRseek
value|25
end_define

begin_comment
comment|/* Seek error */
end_comment

begin_define
define|#
directive|define
name|ERRbadmedia
value|26
end_define

begin_comment
comment|/* Unknown media type */
end_comment

begin_define
define|#
directive|define
name|ERRbadsector
value|27
end_define

begin_comment
comment|/* Sector not found */
end_comment

begin_define
define|#
directive|define
name|ERRnopaper
value|28
end_define

begin_comment
comment|/* Printer out of paper */
end_comment

begin_define
define|#
directive|define
name|ERRwrite
value|29
end_define

begin_comment
comment|/* Write fault */
end_comment

begin_define
define|#
directive|define
name|ERRread
value|30
end_define

begin_comment
comment|/* Read fault */
end_comment

begin_define
define|#
directive|define
name|ERRgeneral
value|31
end_define

begin_comment
comment|/* General failure */
end_comment

begin_define
define|#
directive|define
name|ERRbadshare
value|32
end_define

begin_comment
comment|/* A open conflicts with an existing open */
end_comment

begin_define
define|#
directive|define
name|ERRlock
value|33
end_define

begin_comment
comment|/* lock/unlock conflict */
end_comment

begin_define
define|#
directive|define
name|ERRwrongdisk
value|34
end_define

begin_comment
comment|/* The wrong disk was found in a drive */
end_comment

begin_define
define|#
directive|define
name|ERRFCBunavail
value|35
end_define

begin_comment
comment|/* No FCBs available */
end_comment

begin_define
define|#
directive|define
name|ERRsharebufexc
value|36
end_define

begin_comment
comment|/* A sharing buffer has been exceeded */
end_comment

begin_comment
comment|/*  * RAP error codes (it seems that they returned not only by RAP)  */
end_comment

begin_define
define|#
directive|define
name|SMB_ERROR_ACCESS_DENIED
value|5
end_define

begin_define
define|#
directive|define
name|SMB_ERROR_NETWORK_ACCESS_DENIED
value|65
end_define

begin_define
define|#
directive|define
name|SMB_ERROR_MORE_DATA
value|234
end_define

begin_typedef
typedef|typedef
name|u_int16_t
name|smbfh
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETSMB_SMB_H_ */
end_comment

end_unit

