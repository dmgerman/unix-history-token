begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * RFA - Remote File Access  *  * Access and Management for a partial file system tree that exists  * at two sites either as master files or slave files  *  * rfa.h : common definitions for RFA  *  * Contributed by Oliver Wenzel, GMD Berlin, 1990  *  * $Header: /f/osi/others/rfa/RCS/rfa.h,v 7.3 91/02/22 09:28:15 mrose Interim $  *  * $Log:	rfa.h,v $  * Revision 7.3  91/02/22  09:28:15  mrose  * Interim 6.8  *   * Revision 7.2  91/01/14  13:54:50  mrose  * update  *   * Revision 1.1  91/01/04  16:09:45  ow  * Initial revision  *   */
end_comment

begin_comment
comment|/*  *                              NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OK
end_ifndef

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_define
define|#
directive|define
name|NOTOK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NOTOK_LOCAL_LOCK
value|2
end_define

begin_define
define|#
directive|define
name|NOTOK_LOCAL_ERROR
value|3
end_define

begin_define
define|#
directive|define
name|NOTOK_REMOTE_ERROR
value|4
end_define

begin_define
define|#
directive|define
name|NOTOK_LOCKED
value|5
end_define

begin_define
define|#
directive|define
name|NOTOK_FILEACCESS
value|6
end_define

begin_define
define|#
directive|define
name|NOTOK_NOTREGULAR
value|7
end_define

begin_define
define|#
directive|define
name|NOTOK_GETMASTER
value|8
end_define

begin_define
define|#
directive|define
name|NOTOK_OUTOFSUBTREE
value|9
end_define

begin_define
define|#
directive|define
name|NOTOK_NOTLOCKED
value|10
end_define

begin_define
define|#
directive|define
name|NOTOK_ALREADY_SLAVE
value|11
end_define

begin_define
define|#
directive|define
name|NOTOK_ALREADY_MASTER
value|12
end_define

begin_define
define|#
directive|define
name|NOTOK_ALREADY_UNREG
value|13
end_define

begin_define
define|#
directive|define
name|NOTOK_REMOTE_NOT_MASTER
value|14
end_define

begin_define
define|#
directive|define
name|NOTOK_REMOTE_MASTER_OLDER
value|15
end_define

begin_define
define|#
directive|define
name|NOTOK_UNREG_LOCAL_FILE
value|16
end_define

begin_define
define|#
directive|define
name|NOTOK_IS_SLAVE
value|17
end_define

begin_define
define|#
directive|define
name|NOTOK_SYS
value|18
end_define

begin_define
define|#
directive|define
name|NOTOK_INCONSISTENCY
value|19
end_define

begin_define
define|#
directive|define
name|NOTOK_NOT_ALLOWED
value|20
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|makeFN2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|makeFN
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|basename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|dirname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|expandSymLinks
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|realPath
argument_list|()
decl_stmt|,
modifier|*
name|realPath3
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|rfaErrStr
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|errMsg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*--- tailor variables ---*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|default_transfer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|doChown
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|doChgrp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|doChmod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|doClearSUID
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|doRmWidows
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|doRfaExec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timeSlave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|compLimit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|passwd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|user
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|host
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|backup
decl_stmt|;
end_decl_stmt

end_unit

