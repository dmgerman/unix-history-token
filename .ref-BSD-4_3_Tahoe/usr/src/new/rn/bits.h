begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: bits.h,v 4.3.1.2 86/11/03 09:49:58 lwall Exp $  *  * $Log:	bits.h,v $  * Revision 4.3.1.2  86/11/03  09:49:58  lwall  * Added firstbit variable.  *   * Revision 4.3.1.1  85/05/10  11:31:52  lwall  * Branch for patches.  *   * Revision 4.3  85/05/01  11:36:39  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|ctlarea
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* one bit for each article in current newsgroup */
end_comment

begin_comment
comment|/* with the following interpretation: */
end_comment

begin_comment
comment|/*	0 => unread  */
end_comment

begin_comment
comment|/*	1 => read    */
end_comment

begin_comment
comment|/* if subscripting is faster than shifting on your machine, define this */
end_comment

begin_undef
undef|#
directive|undef
name|USESUBSCRIPT
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|USESUBSCRIPT
end_ifdef

begin_decl_stmt
name|EXT
name|char
name|powerof2
index|[]
name|INIT
argument_list|(
block|{
literal|1
operator|,
literal|2
operator|,
literal|4
operator|,
literal|8
operator|,
literal|16
operator|,
literal|32
operator|,
literal|64
operator|,
literal|128
block|}
end_decl_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|pow2
parameter_list|(
name|x
parameter_list|)
value|powerof2[x]
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|pow2
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_function_decl
name|EXT
name|bool
name|nonesuch
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ctl_set
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ctl_clear
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ctl_read
parameter_list|(
name|a
parameter_list|)
value|nonesuch
end_define

begin_define
define|#
directive|define
name|was_read
parameter_list|(
name|a
parameter_list|)
value|nonesuch
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ctl_set
parameter_list|(
name|a
parameter_list|)
value|(ctlarea[(OFFSET(a)) / BITSPERBYTE] |= pow2((OFFSET(a)) % BITSPERBYTE))
end_define

begin_define
define|#
directive|define
name|ctl_clear
parameter_list|(
name|a
parameter_list|)
value|(ctlarea[(OFFSET(a)) / BITSPERBYTE]&= ~pow2((OFFSET(a)) % BITSPERBYTE))
end_define

begin_define
define|#
directive|define
name|ctl_read
parameter_list|(
name|a
parameter_list|)
value|((ctlarea[(OFFSET(a)) / BITSPERBYTE]& pow2((OFFSET(a)) % BITSPERBYTE)) != 0)
end_define

begin_define
define|#
directive|define
name|was_read
parameter_list|(
name|a
parameter_list|)
value|((a)<firstbit || ctl_read(a))
end_define

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_decl_stmt
name|EXT
name|ART_NUM
name|absfirst
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1st real article in current newsgroup */
end_comment

begin_decl_stmt
name|EXT
name|ART_NUM
name|firstart
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum unread article number in newsgroup */
end_comment

begin_decl_stmt
name|EXT
name|ART_NUM
name|firstbit
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum valid bit, usually == firstart */
end_comment

begin_decl_stmt
name|EXT
name|ART_NUM
name|lastart
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum article number in newsgroup */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DELAYMARK
end_ifdef

begin_function_decl
name|EXT
name|FILE
modifier|*
name|dmfp
name|INIT
parameter_list|(
name|Nullfp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|char
modifier|*
name|dmname
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|int
name|dmcount
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|bits_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|checkpoint_rc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|restore_ng
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|onemore
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|oneless
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unmark_as_read
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delay_unmark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mark_as_read
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|check_first
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DELAYMARK
end_ifdef

begin_function_decl
name|void
name|yankback
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|chase_xrefs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initctl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|grow_ctl
parameter_list|()
function_decl|;
end_function_decl

end_unit

