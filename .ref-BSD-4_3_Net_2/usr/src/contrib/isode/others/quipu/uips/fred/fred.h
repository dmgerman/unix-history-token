begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fred.h - definitions for fred */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/others/quipu/uips/fred/RCS/fred.h,v 7.12 91/03/09 11:54:52 mrose Exp $  *  *  * $Log:	fred.h,v $  * Revision 7.12  91/03/09  11:54:52  mrose  * update  *   * Revision 7.11  91/02/22  09:30:45  mrose  * Interim 6.8  *   * Revision 7.10  91/02/19  09:21:15  mrose  * ufn  *   * Revision 7.9  91/01/10  04:02:58  mrose  * update  *   * Revision 7.8  90/11/01  22:02:47  mrose  * update  *   * Revision 7.7  90/10/28  23:21:05  mrose  * server  *   * Revision 7.6  90/06/11  10:55:21  mrose  * UFN  *   * Revision 7.5  90/03/08  08:05:08  mrose  * phone  *   * Revision 7.4  90/01/16  20:43:29  mrose  * last check-out  *   * Revision 7.3  90/01/11  18:36:33  mrose  * real-sync  *   * Revision 7.2  89/12/14  18:49:03  mrose  * KIS project  *   * Revision 7.1  89/12/13  20:01:49  mrose  * errfp  *   * Revision 7.0  89/11/23  22:08:57  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"general.h"
end_include

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_comment
comment|/*
comment|MAIN */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interrupted
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|oneshot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SFP
name|istat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SFP
name|qstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
name|_fred_log
decl_stmt|,
modifier|*
name|fred_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|adios
argument_list|()
decl_stmt|,
name|advise
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ask
argument_list|()
decl_stmt|,
name|getline
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|strdup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|DATA */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|boundP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|kflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nametype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|network
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|phone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|query
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|readonly
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|soundex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|timelimit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ufn_options
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|watch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|didbind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dontpage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rcmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|runcom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|runsys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|manager
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pager
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|server
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|myarea
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mydn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|myhome
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|myuser
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|stdfp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|errfp
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|EOLN
value|(network&& !mail ? "\r\n" : "\n")
end_define

begin_comment
comment|/*
comment|DISPATCH */
end_comment

begin_struct
struct|struct
name|dispatch
block|{
name|char
modifier|*
name|ds_name
decl_stmt|;
name|IFP
name|ds_fnx
decl_stmt|;
name|int
name|ds_flags
decl_stmt|;
define|#
directive|define
name|DS_NULL
value|0x00
define|#
directive|define
name|DS_USER
value|0x01
define|#
directive|define
name|DS_SYOK
value|0x02
name|char
modifier|*
name|ds_help
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*
comment|MISCELLANY */
end_comment

begin_struct
struct|struct
name|area_guide
block|{
name|int
name|ag_record
decl_stmt|;
define|#
directive|define
name|W_ORGANIZATION
value|0x01
define|#
directive|define
name|W_UNIT
value|0x02
define|#
directive|define
name|W_LOCALITY
value|0x03
define|#
directive|define
name|W_PERSON
value|0x04
define|#
directive|define
name|W_DSA
value|0x05
define|#
directive|define
name|W_ROLE
value|0x06
name|char
modifier|*
name|ag_key
decl_stmt|;
name|char
modifier|*
name|ag_search
decl_stmt|;
name|char
modifier|*
name|ag_class
decl_stmt|;
name|char
modifier|*
name|ag_rdn
decl_stmt|;
name|char
modifier|*
name|ag_area
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|area_quantum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|area_guide
name|areas
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|WHOIS */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|whois_help
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

end_unit

