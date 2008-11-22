begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  ncp.h  */
end_comment

begin_comment
comment|/*-  *  Copyright (C) 1995 by Volker Lendecke  *  New version derived from original ncp.h, 1998 Boris Popov  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNCP_NCP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNCP_NCP_H_
end_define

begin_define
define|#
directive|define
name|NCP_VERMAJ
value|1
end_define

begin_define
define|#
directive|define
name|NCP_VERMIN
value|3500
end_define

begin_define
define|#
directive|define
name|NCP_VERSION
value|(NCP_VERMAJ*100000 + NCP_VERMIN)
end_define

begin_typedef
typedef|typedef
name|u_int32_t
name|nwdirent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|nstr8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|nstr8
modifier|*
name|pnstr8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int8_t
name|nuint8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int8_t
modifier|*
name|pnuint8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|nuint16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|nuint16
modifier|*
name|pnuint16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|nuint32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|nuint32
modifier|*
name|pnuint32
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NCP_DEFAULT_BUFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|NCP_MAX_BUFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|NCP_MAX_PACKET_SIZE
value|4070
end_define

begin_define
define|#
directive|define
name|NCP_MAXUSERNAMELEN
value|255
end_define

begin_define
define|#
directive|define
name|NCP_MAXPASSWORDLEN
value|255
end_define

begin_define
define|#
directive|define
name|NCP_MAXPATHLEN
value|255
end_define

begin_define
define|#
directive|define
name|NCP_MAX_FILENAME
value|14
end_define

begin_define
define|#
directive|define
name|NCP_FILE_ID_LEN
value|6
end_define

begin_define
define|#
directive|define
name|NCP_BINDERY_USER
value|0x0001
end_define

begin_define
define|#
directive|define
name|NCP_BINDERY_UGROUP
value|0x0002
end_define

begin_define
define|#
directive|define
name|NCP_BINDERY_PQUEUE
value|0x0003
end_define

begin_define
define|#
directive|define
name|NCP_BINDERY_FSERVER
value|0x0004
end_define

begin_define
define|#
directive|define
name|NCP_BINDERY_PSERVER
value|0x0007
end_define

begin_define
define|#
directive|define
name|NCP_BINDERY_NAME_LEN
value|48
end_define

begin_comment
comment|/* Handle Flags */
end_comment

begin_define
define|#
directive|define
name|NCP_HF_DIRSHORT
value|0
end_define

begin_comment
comment|/* short directory handle */
end_comment

begin_define
define|#
directive|define
name|NCP_HF_DIRBASE
value|1
end_define

begin_comment
comment|/* directory base */
end_comment

begin_define
define|#
directive|define
name|NCP_HF_NONE
value|0xff
end_define

begin_comment
comment|/* no handle or dirbase */
end_comment

begin_comment
comment|/* Options to negotiate */
end_comment

begin_define
define|#
directive|define
name|NCP_IPX_CHECKSUM
value|1
end_define

begin_define
define|#
directive|define
name|NCP_SECURITY_LEVEL_SIGN_HEADERS
value|2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NWCONN_HANDLE
end_ifndef

begin_define
define|#
directive|define
name|NWCONN_HANDLE
value|unsigned int
end_define

begin_define
define|#
directive|define
name|pNWCONN_HANDLE
value|(unsigned int*)
end_define

begin_define
define|#
directive|define
name|NWCONN_NUM
value|u_int16_t
end_define

begin_define
define|#
directive|define
name|NWCCODE
value|unsigned int
end_define

begin_define
define|#
directive|define
name|NWDIR_HANDLE
value|u_int8_t
end_define

begin_define
define|#
directive|define
name|NWFILE_HANDLE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ncp_fh_s
block|{
name|u_int16_t
name|val1
decl_stmt|;
union|union
block|{
name|u_int32_t
name|val32
decl_stmt|;
name|u_int16_t
name|val16
decl_stmt|;
block|}
name|val
union|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ncp_fh_s
name|ncp_fh
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ncpfid_s
block|{
name|nwdirent
name|f_parent
decl_stmt|;
name|nwdirent
name|f_id
decl_stmt|;
block|}
name|ncpfid
typedef|;
end_typedef

begin_comment
comment|/* -- Bindery properties -- */
end_comment

begin_struct
struct|struct
name|ncp_bindery_object
block|{
name|u_int32_t
name|object_id
decl_stmt|;
name|u_int16_t
name|object_type
decl_stmt|;
name|u_int8_t
name|object_name
index|[
name|NCP_BINDERY_NAME_LEN
index|]
decl_stmt|;
name|u_int8_t
name|object_flags
decl_stmt|;
name|u_int8_t
name|object_security
decl_stmt|;
name|u_int8_t
name|object_has_prop
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nw_property
block|{
name|u_int8_t
name|value
index|[
literal|128
index|]
decl_stmt|;
name|u_int8_t
name|more_flag
decl_stmt|;
name|u_int8_t
name|property_flag
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ncp_filesearch_info
block|{
name|u_int8_t
name|volume_number
decl_stmt|;
name|u_int16_t
name|directory_id
decl_stmt|;
name|u_int16_t
name|sequence_no
decl_stmt|;
name|u_int8_t
name|access_rights
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ncp_file_info
block|{
name|u_int8_t
name|file_id
index|[
name|NCP_FILE_ID_LEN
index|]
decl_stmt|;
name|char
name|file_name
index|[
name|NCP_MAX_FILENAME
operator|+
literal|1
index|]
decl_stmt|;
name|u_int8_t
name|file_attributes
decl_stmt|;
name|u_int8_t
name|file_mode
decl_stmt|;
name|u_int32_t
name|file_length
decl_stmt|;
name|u_int16_t
name|creation_date
decl_stmt|;
name|u_int16_t
name|access_date
decl_stmt|;
name|u_int16_t
name|update_date
decl_stmt|;
name|u_int16_t
name|update_time
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nw_queue_job_entry
block|{
name|u_int16_t
name|InUse
decl_stmt|;
name|u_int32_t
name|prev
decl_stmt|;
name|u_int32_t
name|next
decl_stmt|;
name|u_int32_t
name|ClientStation
decl_stmt|;
name|u_int32_t
name|ClientTask
decl_stmt|;
name|u_int32_t
name|ClientObjectID
decl_stmt|;
name|u_int32_t
name|TargetServerID
decl_stmt|;
name|u_int8_t
name|TargetExecTime
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|JobEntryTime
index|[
literal|6
index|]
decl_stmt|;
name|u_int32_t
name|JobNumber
decl_stmt|;
name|u_int16_t
name|JobType
decl_stmt|;
name|u_int16_t
name|JobPosition
decl_stmt|;
name|u_int16_t
name|JobControlFlags
decl_stmt|;
name|u_int8_t
name|FileNameLen
decl_stmt|;
name|char
name|JobFileName
index|[
literal|13
index|]
decl_stmt|;
name|u_int32_t
name|JobFileHandle
decl_stmt|;
name|u_int32_t
name|ServerStation
decl_stmt|;
name|u_int32_t
name|ServerTaskNumber
decl_stmt|;
name|u_int32_t
name|ServerObjectID
decl_stmt|;
name|char
name|JobTextDescription
index|[
literal|50
index|]
decl_stmt|;
name|char
name|ClientRecordArea
index|[
literal|152
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|queue_job
block|{
name|struct
name|nw_queue_job_entry
name|j
decl_stmt|;
name|ncp_fh
name|file_handle
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|QJE_OPER_HOLD
value|0x80
end_define

begin_define
define|#
directive|define
name|QJE_USER_HOLD
value|0x40
end_define

begin_define
define|#
directive|define
name|QJE_ENTRYOPEN
value|0x20
end_define

begin_define
define|#
directive|define
name|QJE_SERV_RESTART
value|0x10
end_define

begin_define
define|#
directive|define
name|QJE_SERV_AUTO
value|0x08
end_define

begin_comment
comment|/* ClientRecordArea for print jobs */
end_comment

begin_define
define|#
directive|define
name|KEEP_ON
value|0x0400
end_define

begin_define
define|#
directive|define
name|NO_FORM_FEED
value|0x0800
end_define

begin_define
define|#
directive|define
name|NOTIFICATION
value|0x1000
end_define

begin_define
define|#
directive|define
name|DELETE_FILE
value|0x2000
end_define

begin_define
define|#
directive|define
name|EXPAND_TABS
value|0x4000
end_define

begin_define
define|#
directive|define
name|PRINT_BANNER
value|0x8000
end_define

begin_struct
struct|struct
name|print_job_record
block|{
name|u_int8_t
name|Version
decl_stmt|;
name|u_int8_t
name|TabSize
decl_stmt|;
name|u_int16_t
name|Copies
decl_stmt|;
name|u_int16_t
name|CtrlFlags
decl_stmt|;
name|u_int16_t
name|Lines
decl_stmt|;
name|u_int16_t
name|Rows
decl_stmt|;
name|char
name|FormName
index|[
literal|16
index|]
decl_stmt|;
name|u_int8_t
name|Reserved
index|[
literal|6
index|]
decl_stmt|;
name|char
name|BannerName
index|[
literal|13
index|]
decl_stmt|;
name|char
name|FnameBanner
index|[
literal|13
index|]
decl_stmt|;
name|char
name|FnameHeader
index|[
literal|14
index|]
decl_stmt|;
name|char
name|Path
index|[
literal|80
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ncp_station_addr
block|{
name|u_int32_t
name|NetWork
decl_stmt|;
name|u_int8_t
name|Node
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|Socket
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ncp_prop_login_control
block|{
name|u_int8_t
name|AccountExpireDate
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|Disabled
decl_stmt|;
name|u_int8_t
name|PasswordExpireDate
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|GraceLogins
decl_stmt|;
name|u_int16_t
name|PasswordExpireInterval
decl_stmt|;
name|u_int8_t
name|MaxGraceLogins
decl_stmt|;
name|u_int8_t
name|MinPasswordLength
decl_stmt|;
name|u_int16_t
name|MaxConnections
decl_stmt|;
name|u_int8_t
name|ConnectionTimeMask
index|[
literal|42
index|]
decl_stmt|;
name|u_int8_t
name|LastLogin
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|RestrictionMask
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int32_t
name|MaxDiskUsage
decl_stmt|;
name|u_int16_t
name|BadLoginCount
decl_stmt|;
name|u_int32_t
name|BadLoginCountDown
decl_stmt|;
name|struct
name|ncp_station_addr
name|LastIntruder
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|NCP_VOLNAME_LEN
value|(16)
end_define

begin_define
define|#
directive|define
name|NCP_NUMBER_OF_VOLUMES
value|(64)
end_define

begin_struct
struct|struct
name|ncp_volume_info
block|{
name|u_int32_t
name|total_blocks
decl_stmt|;
name|u_int32_t
name|free_blocks
decl_stmt|;
name|u_int32_t
name|purgeable_blocks
decl_stmt|;
name|u_int32_t
name|not_yet_purgeable_blocks
decl_stmt|;
name|u_int32_t
name|total_dir_entries
decl_stmt|;
name|u_int32_t
name|available_dir_entries
decl_stmt|;
name|u_int8_t
name|sectors_per_block
decl_stmt|;
name|char
name|volume_name
index|[
name|NCP_VOLNAME_LEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Name space constants, taken from NDK  */
end_comment

begin_define
define|#
directive|define
name|aRONLY
value|(ntohl(0x01000000))
end_define

begin_define
define|#
directive|define
name|aHIDDEN
value|(ntohl(0x02000000))
end_define

begin_define
define|#
directive|define
name|aSYSTEM
value|(ntohl(0x04000000))
end_define

begin_define
define|#
directive|define
name|aEXECUTE
value|(ntohl(0x08000000))
end_define

begin_define
define|#
directive|define
name|aDIR
value|(ntohl(0x10000000))
end_define

begin_define
define|#
directive|define
name|aARCH
value|(ntohl(0x20000000))
end_define

begin_comment
comment|/* Defines for Name Spaces */
end_comment

begin_define
define|#
directive|define
name|NW_NS_DOS
value|0
end_define

begin_define
define|#
directive|define
name|NW_NS_MAC
value|1
end_define

begin_define
define|#
directive|define
name|NW_NS_NFS
value|2
end_define

begin_define
define|#
directive|define
name|NW_NS_FTAM
value|3
end_define

begin_define
define|#
directive|define
name|NW_NS_OS2
value|4
end_define

begin_comment
comment|/* for _ScanNSEntryInfo */
end_comment

begin_define
define|#
directive|define
name|IM_NAME
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IM_SPACE_ALLOCATED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IM_ATTRIBUTES
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IM_SIZE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IM_TOTAL_SIZE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IM_EA
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IM_ARCHIVE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IM_MODIFY
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IM_CREATION
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IM_OWNING_NAMESPACE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IM_DIRECTORY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IM_RIGHTS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IM_ALMOST_ALL
value|0x00000FED
end_define

begin_define
define|#
directive|define
name|IM_ALL
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|IM_REFERENCE_ID
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IM_NS_ATTRIBUTES
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IM_COMPRESSED_INFO
value|0x80000000UL
end_define

begin_comment
comment|/* open/create modes */
end_comment

begin_define
define|#
directive|define
name|OC_MODE_OPEN
value|0x01
end_define

begin_define
define|#
directive|define
name|OC_MODE_TRUNCATE
value|0x02
end_define

begin_define
define|#
directive|define
name|OC_MODE_REPLACE
value|0x02
end_define

begin_define
define|#
directive|define
name|OC_MODE_CREATE
value|0x08
end_define

begin_comment
comment|/* open/create results */
end_comment

begin_define
define|#
directive|define
name|OC_ACTION_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|OC_ACTION_OPEN
value|0x01
end_define

begin_define
define|#
directive|define
name|OC_ACTION_CREATE
value|0x02
end_define

begin_define
define|#
directive|define
name|OC_ACTION_TRUNCATE
value|0x04
end_define

begin_define
define|#
directive|define
name|OC_ACTION_REPLACE
value|0x04
end_define

begin_comment
comment|/* renameFlag in NSRename */
end_comment

begin_define
define|#
directive|define
name|NW_TYPE_FILE
value|0x8000
end_define

begin_define
define|#
directive|define
name|NW_TYPE_SUBDIR
value|0x0010
end_define

begin_define
define|#
directive|define
name|NW_NAME_CONVERT
value|0x0003
end_define

begin_comment
comment|/* don't report error and set comp mode */
end_comment

begin_define
define|#
directive|define
name|NW_NO_NAME_CONVERT
value|0x0004
end_define

begin_comment
comment|/* only in specified name space */
end_comment

begin_comment
comment|/* search attributes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SA_HIDDEN
end_ifndef

begin_define
define|#
directive|define
name|SA_NORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|SA_HIDDEN
value|0x0002
end_define

begin_define
define|#
directive|define
name|SA_SYSTEM
value|0x0004
end_define

begin_define
define|#
directive|define
name|SA_SUBDIR_ONLY
value|0x0010
end_define

begin_define
define|#
directive|define
name|SA_SUBDIR_FILES
value|0x8000
end_define

begin_define
define|#
directive|define
name|SA_ALL
value|0x8006
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* access rights attributes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AR_READ
end_ifndef

begin_define
define|#
directive|define
name|AR_READ
value|0x0001
end_define

begin_define
define|#
directive|define
name|AR_WRITE
value|0x0002
end_define

begin_define
define|#
directive|define
name|AR_READ_ONLY
value|0x0001
end_define

begin_define
define|#
directive|define
name|AR_WRITE_ONLY
value|0x0002
end_define

begin_define
define|#
directive|define
name|AR_DENY_READ
value|0x0004
end_define

begin_define
define|#
directive|define
name|AR_DENY_WRITE
value|0x0008
end_define

begin_define
define|#
directive|define
name|AR_COMPATIBILITY
value|0x0010
end_define

begin_define
define|#
directive|define
name|AR_WRITE_THROUGH
value|0x0040
end_define

begin_define
define|#
directive|define
name|AR_OPEN_COMPRESSED
value|0x0100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|nw_entry_info
block|{
name|u_int32_t
name|spaceAlloc
decl_stmt|;
name|u_int32_t
name|attributes
decl_stmt|;
comment|/* LH */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* internal */
name|u_int32_t
name|dataStreamSize
decl_stmt|;
name|u_int32_t
name|totalStreamSize
decl_stmt|;
name|u_int16_t
name|numberOfStreams
decl_stmt|;
name|u_int16_t
name|creationTime
decl_stmt|;
comment|/* LH */
name|u_int16_t
name|creationDate
decl_stmt|;
comment|/* LH */
name|u_int32_t
name|creatorID
decl_stmt|;
comment|/* HL */
name|u_int16_t
name|modifyTime
decl_stmt|;
comment|/* LH */
name|u_int16_t
name|modifyDate
decl_stmt|;
comment|/* LH */
name|u_int32_t
name|modifierID
decl_stmt|;
comment|/* HL */
name|u_int16_t
name|lastAccessDate
decl_stmt|;
comment|/* LH */
name|u_int16_t
name|archiveTime
decl_stmt|;
comment|/* LH */
name|u_int16_t
name|archiveDate
decl_stmt|;
comment|/* LH */
name|u_int32_t
name|archiverID
decl_stmt|;
comment|/* HL */
name|u_int16_t
name|inheritedRightsMask
decl_stmt|;
comment|/* LH */
name|u_int32_t
name|dirEntNum
decl_stmt|;
name|u_int32_t
name|DosDirNum
decl_stmt|;
name|u_int32_t
name|volNumber
decl_stmt|;
name|u_int32_t
name|EADataSize
decl_stmt|;
name|u_int32_t
name|EAKeyCount
decl_stmt|;
name|u_int32_t
name|EAKeySize
decl_stmt|;
name|u_int32_t
name|NSCreator
decl_stmt|;
name|u_int8_t
name|nameLen
decl_stmt|;
name|u_int8_t
name|entryName
index|[
literal|256
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nw_entry_info
name|NW_ENTRY_INFO
typedef|;
end_typedef

begin_comment
comment|/* modify mask - use with MODIFY_DOS_INFO structure */
end_comment

begin_define
define|#
directive|define
name|DM_ATTRIBUTES
value|0x0002L
end_define

begin_define
define|#
directive|define
name|DM_CREATE_DATE
value|0x0004L
end_define

begin_define
define|#
directive|define
name|DM_CREATE_TIME
value|0x0008L
end_define

begin_define
define|#
directive|define
name|DM_CREATOR_ID
value|0x0010L
end_define

begin_define
define|#
directive|define
name|DM_ARCHIVE_DATE
value|0x0020L
end_define

begin_define
define|#
directive|define
name|DM_ARCHIVE_TIME
value|0x0040L
end_define

begin_define
define|#
directive|define
name|DM_ARCHIVER_ID
value|0x0080L
end_define

begin_define
define|#
directive|define
name|DM_MODIFY_DATE
value|0x0100L
end_define

begin_define
define|#
directive|define
name|DM_MODIFY_TIME
value|0x0200L
end_define

begin_define
define|#
directive|define
name|DM_MODIFIER_ID
value|0x0400L
end_define

begin_define
define|#
directive|define
name|DM_LAST_ACCESS_DATE
value|0x0800L
end_define

begin_define
define|#
directive|define
name|DM_INHERITED_RIGHTS_MASK
value|0x1000L
end_define

begin_define
define|#
directive|define
name|DM_MAXIMUM_SPACE
value|0x2000L
end_define

begin_struct
struct|struct
name|nw_modify_dos_info
block|{
name|u_int32_t
name|attributes
decl_stmt|;
name|u_int16_t
name|creationDate
decl_stmt|;
name|u_int16_t
name|creationTime
decl_stmt|;
name|u_int32_t
name|creatorID
decl_stmt|;
name|u_int16_t
name|modifyDate
decl_stmt|;
name|u_int16_t
name|modifyTime
decl_stmt|;
name|u_int32_t
name|modifierID
decl_stmt|;
name|u_int16_t
name|archiveDate
decl_stmt|;
name|u_int16_t
name|archiveTime
decl_stmt|;
name|u_int32_t
name|archiverID
decl_stmt|;
name|u_int16_t
name|lastAccessDate
decl_stmt|;
name|u_int16_t
name|inheritanceGrantMask
decl_stmt|;
name|u_int16_t
name|inheritanceRevokeMask
decl_stmt|;
name|u_int32_t
name|maximumSpace
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|nw_search_seq
block|{
name|u_int8_t
name|volNumber
decl_stmt|;
name|u_int32_t
name|dirNumber
decl_stmt|;
name|u_int32_t
name|searchDirNumber
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nw_search_seq
name|SEARCH_SEQUENCE
typedef|;
end_typedef

begin_struct
struct|struct
name|ncp_file_server_info
block|{
name|u_int8_t
name|ServerName
index|[
literal|48
index|]
decl_stmt|;
name|u_int8_t
name|FileServiceVersion
decl_stmt|;
name|u_int8_t
name|FileServiceSubVersion
decl_stmt|;
name|u_int16_t
name|MaximumServiceConnections
decl_stmt|;
name|u_int16_t
name|ConnectionsInUse
decl_stmt|;
name|u_int16_t
name|NumberMountedVolumes
decl_stmt|;
name|u_int8_t
name|Revision
decl_stmt|;
name|u_int8_t
name|SFTLevel
decl_stmt|;
name|u_int8_t
name|TTSLevel
decl_stmt|;
name|u_int16_t
name|MaxConnectionsEverUsed
decl_stmt|;
name|u_int8_t
name|AccountVersion
decl_stmt|;
name|u_int8_t
name|VAPVersion
decl_stmt|;
name|u_int8_t
name|QueueVersion
decl_stmt|;
name|u_int8_t
name|PrintVersion
decl_stmt|;
name|u_int8_t
name|VirtualConsoleVersion
decl_stmt|;
name|u_int8_t
name|RestrictionLevel
decl_stmt|;
name|u_int8_t
name|InternetBridge
decl_stmt|;
name|u_int8_t
name|Reserved
index|[
literal|60
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|nw_time_buffer
block|{
name|u_int8_t
name|year
decl_stmt|;
name|u_int8_t
name|month
decl_stmt|;
name|u_int8_t
name|day
decl_stmt|;
name|u_int8_t
name|hour
decl_stmt|;
name|u_int8_t
name|minute
decl_stmt|;
name|u_int8_t
name|second
decl_stmt|;
name|u_int8_t
name|wday
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_NCP_H_ */
end_comment

end_unit

