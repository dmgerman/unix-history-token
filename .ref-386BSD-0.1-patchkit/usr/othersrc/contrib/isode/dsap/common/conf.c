begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* conf.c - DSAP Configuration */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/dsap/common/RCS/conf.c,v 7.3 91/02/22 09:18:50 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * $Header: /f/osi/dsap/common/RCS/conf.c,v 7.3 91/02/22 09:18:50 mrose Interim $  *  *  * $Log:	conf.c,v $  * Revision 7.3  91/02/22  09:18:50  mrose  * Interim 6.8  *   * Revision 7.2  90/10/17  11:41:31  mrose  * sync  *   * Revision 7.1  90/07/09  14:34:12  mrose  * sync  *   * Revision 7.0  89/11/23  21:47:42  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *                                NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_include
include|#
directive|include
file|"quipu/util.h"
end_include

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_decl_stmt
name|int
name|sizelimit
init|=
literal|20
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|timelimit
init|=
literal|30
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|oidtable
init|=
literal|"oidtable"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tailfile
init|=
literal|"dsaptailor"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|isotailor
init|=
name|NULLCP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dsa_address
init|=
name|NULLCP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|myname
init|=
name|NULLCP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|local_dit
init|=
name|NULLCP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the part of the tree local to the users */
end_comment

begin_decl_stmt
name|char
name|dishinit
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dsap_id
decl_stmt|,
comment|/* global last id sent */
name|dsap_ad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global association descriptor */
end_comment

begin_decl_stmt
name|time_t
name|cache_timeout
init|=
literal|21600
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keep cache entries for 6 hours */
end_comment

begin_decl_stmt
specifier|static
name|LLog
name|_ldsap_log
init|=
block|{
literal|"dsap.log"
block|,
name|NULLCP
block|,
name|NULLCP
block|,
name|LLOG_FATAL
operator||
name|LLOG_EXCEPTIONS
block|,
name|LLOG_NONE
block|,
operator|-
literal|1
block|,
name|LLOGZER
operator||
name|LLOGCRT
operator||
name|LLOGCLS
block|,
name|NOTOK
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LLog
modifier|*
name|log_dsap
init|=
operator|&
name|_ldsap_log
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NO_STATS
end_ifndef

begin_decl_stmt
specifier|static
name|LLog
name|lstat_log
init|=
block|{
literal|"quipu.log"
block|,
name|NULLCP
block|,
name|NULLCP
block|,
name|LLOG_ALL
block|,
name|LLOG_NONE
block|,
operator|-
literal|1
block|,
name|LLOGCRT
operator||
name|LLOGZER
block|,
name|NOTOK
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LLog
modifier|*
name|log_stat
init|=
operator|&
name|lstat_log
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|oidformat
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* oid format, 1=part, 2=full, 3=numeric */
end_comment

begin_comment
comment|/* a quick def incase quipu/malloc.c is not compiled in !!! */
end_comment

begin_decl_stmt
name|unsigned
name|mem_heap
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dsaoidtable
init|=
literal|"oidtable"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dsatailfile
init|=
literal|"quiputailor"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|treedir
init|=
literal|"quipu-db"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|no_dsp_chain
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|no_last_mod
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|startup_update
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|search_level
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do NOT allow country level searching */
end_comment

begin_decl_stmt
name|int
name|read_only
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prevent DIT modification */
end_comment

begin_comment
comment|/* admin limits */
end_comment

begin_decl_stmt
name|int
name|admin_size
init|=
literal|100
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 100 entries */
end_comment

begin_decl_stmt
name|time_t
name|admin_time
init|=
literal|120
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't spend more than 2 minutes on a task */
end_comment

begin_decl_stmt
name|time_t
name|conn_timeout
init|=
literal|300
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't hold an unused connection open for more than 5 minutes */
end_comment

begin_decl_stmt
name|time_t
name|nsap_timeout
init|=
literal|45
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* after 45 seconds assume nsap has failed */
end_comment

begin_decl_stmt
name|time_t
name|slave_timeout
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Update slaves every 'cache_time' seconds */
end_comment

begin_decl_stmt
name|time_t
name|retry_timeout
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Test DSA for reliability after 'cache_time' seconds */
end_comment

begin_decl_stmt
name|unsigned
name|watchdog_time
init|=
literal|5
operator|*
literal|60
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allow lower layers 5 minutes per *async* operation */
end_comment

begin_decl_stmt
name|unsigned
name|watchdog_delta
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allow 5 second for timeout to propagate */
end_comment

begin_decl_stmt
name|char
name|dsa_mode
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

end_unit

