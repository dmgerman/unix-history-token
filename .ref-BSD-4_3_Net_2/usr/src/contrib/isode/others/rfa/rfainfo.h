begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * RFA - Remote File Access  *  * Access and Management for a partial file system tree that exists  * at two sites either as master files or slave files  *  * rfainfo.h : data structures to represent content of ".rfainfo" files  *             and stat info of files  *  * Contributed by Oliver Wenzel, GMD Berlin, 1990  *  * $Header: /f/osi/others/rfa/RCS/rfainfo.h,v 7.3 91/02/22 09:28:25 mrose Interim $  *  * $Log:	rfainfo.h,v $  * Revision 7.3  91/02/22  09:28:25  mrose  * Interim 6.8  *   * Revision 7.2  91/01/14  13:55:02  mrose  * update  *   * Revision 1.1  91/01/04  16:09:53  ow  * Initial revision  *   */
end_comment

begin_comment
comment|/*  *                              NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_struct
struct|struct
name|RfaInfo
block|{
name|char
modifier|*
name|ri_filename
decl_stmt|;
name|int
name|ri_status
decl_stmt|;
name|time_t
name|ri_lastChange
decl_stmt|;
comment|/* time when status change was done */
name|char
modifier|*
name|ri_lckname
decl_stmt|;
comment|/* name of user that locked file   */
name|time_t
name|ri_lcksince
decl_stmt|;
comment|/* time when file has been locked  */
name|char
modifier|*
name|ri_owner
decl_stmt|;
comment|/* file info as per stat(2) */
name|char
modifier|*
name|ri_group
decl_stmt|;
name|int
name|ri_mode
decl_stmt|;
name|int
name|ri_size
decl_stmt|;
name|time_t
name|ri_modTime
decl_stmt|;
name|time_t
name|ri_accTime
decl_stmt|;
name|char
modifier|*
name|ri_lnkName
decl_stmt|;
name|struct
name|RfaInfo
modifier|*
name|ri_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RI_STATUS
parameter_list|(
name|s
parameter_list|)
value|((s)& 07)
end_define

begin_define
define|#
directive|define
name|SET_STATUS
parameter_list|(
name|v
parameter_list|,
name|s
parameter_list|)
value|(v)=(((v)& ~07) | (s))
end_define

begin_define
define|#
directive|define
name|RI_UNREGISTERED
value|0
end_define

begin_define
define|#
directive|define
name|IS_UNREGISTERED
parameter_list|(
name|s
parameter_list|)
value|(RI_STATUS(s) == RI_UNREGISTERED)
end_define

begin_define
define|#
directive|define
name|RI_MASTER
value|1
end_define

begin_define
define|#
directive|define
name|IS_MASTER
parameter_list|(
name|s
parameter_list|)
value|(RI_STATUS(s) == RI_MASTER)
end_define

begin_define
define|#
directive|define
name|RI_SLAVE
value|2
end_define

begin_define
define|#
directive|define
name|IS_SLAVE
parameter_list|(
name|s
parameter_list|)
value|(RI_STATUS(s) == RI_SLAVE)
end_define

begin_define
define|#
directive|define
name|RI_LOCKINFO
parameter_list|(
name|s
parameter_list|)
value|((s)& 070)
end_define

begin_define
define|#
directive|define
name|SET_LOCKINFO
parameter_list|(
name|v
parameter_list|,
name|s
parameter_list|)
value|(v)=(((v)& ~070) | (s))
end_define

begin_define
define|#
directive|define
name|RI_LOCKED
value|010
end_define

begin_define
define|#
directive|define
name|IS_LOCKED
parameter_list|(
name|s
parameter_list|)
value|(RI_LOCKINFO(s) == RI_LOCKED)
end_define

begin_define
define|#
directive|define
name|RI_UNLOCKED
value|020
end_define

begin_define
define|#
directive|define
name|IS_UNLOCKED
parameter_list|(
name|s
parameter_list|)
value|(RI_LOCKINFO(s) == RI_UNLOCKED)
end_define

begin_define
define|#
directive|define
name|RI_TRANSFER
parameter_list|(
name|s
parameter_list|)
value|((s)& 0700)
end_define

begin_define
define|#
directive|define
name|SET_TRANSFER
parameter_list|(
name|v
parameter_list|,
name|s
parameter_list|)
value|(v)=(((v)& ~0700) | (s))
end_define

begin_define
define|#
directive|define
name|RI_TR_AUTO
value|0100
end_define

begin_define
define|#
directive|define
name|IS_TR_AUTO
parameter_list|(
name|s
parameter_list|)
value|(RI_TRANSFER(s) == RI_TR_AUTO)
end_define

begin_define
define|#
directive|define
name|RI_TR_REQ
value|0200
end_define

begin_define
define|#
directive|define
name|IS_TR_REQ
parameter_list|(
name|s
parameter_list|)
value|(RI_TRANSFER(s) == RI_TR_REQ)
end_define

begin_decl_stmt
specifier|extern
name|int
name|getLockedRfaInfoList
argument_list|()
decl_stmt|,
name|getRfaInfoList
argument_list|()
decl_stmt|,
name|putRfaInfoList
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|remRfaInfo
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|RfaInfo
modifier|*
name|mallocRfaInfo
argument_list|()
decl_stmt|,
modifier|*
name|findRfaInfo
argument_list|()
decl_stmt|,
modifier|*
name|extractRfaInfo
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|str2status
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|status2str
argument_list|()
decl_stmt|,
modifier|*
name|status2sstr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|RfaInfo
modifier|*
name|fi2rfa
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type_RFA_FileInfoList
modifier|*
name|rfa2fil
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type_RFA_FileInfo
modifier|*
name|rfa2fi
parameter_list|()
function_decl|;
end_function_decl

end_unit

