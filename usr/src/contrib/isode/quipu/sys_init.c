begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sys_init.c - System tailoring initialisation */
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
literal|"$Header: /f/osi/quipu/RCS/sys_init.c,v 7.2 91/02/22 09:39:52 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * $Header: /f/osi/quipu/RCS/sys_init.c,v 7.2 91/02/22 09:39:52 mrose Interim $  *  *  * $Log:	sys_init.c,v $  * Revision 7.2  91/02/22  09:39:52  mrose  * Interim 6.8  *   * Revision 7.1  90/10/17  11:54:45  mrose  * sync  *   * Revision 7.0  89/11/23  22:18:07  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *                                NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"quipu/oid.h"
end_include

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dsaoidtable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
modifier|*
name|log_dsap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|cache_timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|retry_timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|slave_timeout
decl_stmt|;
end_decl_stmt

begin_macro
name|dsa_sys_init
argument_list|(
argument|acptr
argument_list|,
argument|avptr
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|acptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
modifier|*
name|avptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
modifier|*
name|ptr
decl_stmt|;
name|int
name|cnt
decl_stmt|;
specifier|extern
name|int
name|parse_line
decl_stmt|;
specifier|extern
name|char
name|dsa_mode
decl_stmt|;
name|parse_line
operator|=
literal|0
expr_stmt|;
comment|/* stop 'line 1:' being printed in tailor file errors */
name|dsa_mode
operator|=
literal|1
expr_stmt|;
name|name
operator|=
operator|*
operator|*
name|avptr
expr_stmt|;
name|DLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_TRACE
argument_list|,
operator|(
literal|"Initialisation"
operator|)
argument_list|)
expr_stmt|;
name|cnt
operator|=
operator|*
name|acptr
expr_stmt|;
name|ptr
operator|=
operator|*
name|avptr
expr_stmt|;
name|dsa_tai_args
argument_list|(
name|acptr
argument_list|,
name|avptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|dsa_tai_init
argument_list|(
name|name
argument_list|)
operator|!=
name|OK
condition|)
name|fatal
argument_list|(
operator|-
literal|43
argument_list|,
literal|"Tailoring failed"
argument_list|)
expr_stmt|;
name|dsa_tai_args
argument_list|(
operator|&
name|cnt
argument_list|,
operator|&
name|ptr
argument_list|)
expr_stmt|;
comment|/* second call IS needed !!! */
name|DLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_TRACE
argument_list|,
operator|(
literal|"Loading oid table (%s)"
operator|,
name|dsaoidtable
operator|)
argument_list|)
expr_stmt|;
name|load_oid_table
argument_list|(
name|dsaoidtable
argument_list|)
expr_stmt|;
if|if
condition|(
name|retry_timeout
operator|==
operator|(
name|time_t
operator|)
literal|0
condition|)
name|retry_timeout
operator|=
name|cache_timeout
expr_stmt|;
if|if
condition|(
name|slave_timeout
operator|==
operator|(
name|time_t
operator|)
literal|0
condition|)
name|slave_timeout
operator|=
name|cache_timeout
expr_stmt|;
name|DLOG
argument_list|(
name|log_dsap
argument_list|,
name|LLOG_TRACE
argument_list|,
operator|(
literal|"*** Starting ***"
operator|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

