begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: ng.h,v 4.3 85/05/01 11:44:29 lwall Exp $  *  * $Log:	ng.h,v $  * Revision 4.3  85/05/01  11:44:29  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_decl_stmt
name|EXT
name|ART_NUM
name|art
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current or prospective article # */
end_comment

begin_decl_stmt
name|EXT
name|int
name|checkcount
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how many articles have we read */
end_comment

begin_comment
comment|/*   in the current newsgroup since */
end_comment

begin_comment
comment|/*   the last checkpoint? */
end_comment

begin_decl_stmt
name|EXT
name|int
name|docheckwhen
name|INIT
argument_list|(
literal|20
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how often to do checkpoint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAILCALL
end_ifdef

begin_decl_stmt
name|EXT
name|int
name|mailcount
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* check for mail when 0 mod 10 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|EXT
name|char
modifier|*
name|mailcall
name|INIT
parameter_list|(
name|nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|forcelast
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ought we show "End of newsgroup"? */
end_comment

begin_function_decl
name|EXT
name|bool
name|forcegrow
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* do we want to recalculate size */
end_comment

begin_comment
comment|/* of newsgroup, e.g. after posting? */
end_comment

begin_define
define|#
directive|define
name|NG_ERROR
value|-1
end_define

begin_define
define|#
directive|define
name|NG_NORM
value|0
end_define

begin_define
define|#
directive|define
name|NG_ASK
value|1
end_define

begin_define
define|#
directive|define
name|NG_MINUS
value|2
end_define

begin_function_decl
name|void
name|ng_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_newsgroup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|art_switch
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|MAILCALL
end_ifdef

begin_function_decl
name|void
name|setmail
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|setdfltcmd
parameter_list|()
function_decl|;
end_function_decl

end_unit

