begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b2syn.h,v 1.4 85/08/22 16:43:04 timo Exp $ */
end_comment

begin_comment
comment|/* General parsing routines */
end_comment

begin_define
define|#
directive|define
name|Eotc
value|'\0'
end_define

begin_define
define|#
directive|define
name|Char
parameter_list|(
name|tx
parameter_list|)
value|(*(tx))
end_define

begin_define
define|#
directive|define
name|Eol
parameter_list|(
name|tx
parameter_list|)
value|(Char(tx) == '\n')
end_define

begin_define
define|#
directive|define
name|Ceol
parameter_list|(
name|tx
parameter_list|)
value|(Char(tx) == '\\' || Eol(tx))
end_define

begin_define
define|#
directive|define
name|Text
parameter_list|(
name|q
parameter_list|)
value|(tx< q)
end_define

begin_define
define|#
directive|define
name|Space
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || (c) == '\t')
end_define

begin_define
define|#
directive|define
name|Letter
parameter_list|(
name|c
parameter_list|)
value|('a'<=c&&c<='z')
end_define

begin_define
define|#
directive|define
name|Cap
parameter_list|(
name|c
parameter_list|)
value|('A'<=c&&c<='Z')
end_define

begin_define
define|#
directive|define
name|Dig
parameter_list|(
name|c
parameter_list|)
value|('0'<=c&&c<='9')
end_define

begin_comment
comment|/* Procedure skipsp(); */
end_comment

begin_comment
comment|/* Procedure upto(); */
end_comment

begin_comment
comment|/* Procedure need(); */
end_comment

begin_comment
comment|/* Procedure findceol(); */
end_comment

begin_comment
comment|/* Procedure req(); */
end_comment

begin_comment
comment|/* Procedure veli(); */
end_comment

begin_function_decl
name|bool
name|keymark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|txptr
name|fcol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|nothing
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ateol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|findkw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|tag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|find
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|txptr
name|tx
decl_stmt|,
name|ceol
decl_stmt|,
name|first_col
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|intlet
name|cur_ilev
decl_stmt|;
end_decl_stmt

begin_function_decl
name|intlet
name|ilev
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|value
name|kwlist
decl_stmt|;
end_decl_stmt

begin_function_decl
name|value
name|cr_text
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|is_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|is_tag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|findrel
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|string
name|textsign
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|is_expr
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NOT_USED
end_ifdef

begin_function_decl
name|bool
name|colon_sign
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|bool
name|comment_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|nwl_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|open_sign
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NOT_USED
end_ifdef

begin_function_decl
name|bool
name|close_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|comma_sign
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|bool
name|point_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|apostrophe_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|quote_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|conv_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|curlyopen_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|curlyclose_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|sub_sign
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NOT_USED
end_ifdef

begin_function_decl
name|bool
name|bus_sign
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|bool
name|behead_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|curtl_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|about_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|plus_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|minus_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|times_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|over_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|power_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|numtor_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|denomtor_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|join_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|reptext_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|leftadj_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|center_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|rightadj_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|number_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|less_than_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|at_most_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|equals_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|unequal_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|at_least_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|greater_than_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|dyamon_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|dya_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|mon_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|trim_sign
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|check_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|choose_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|delete_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|draw_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|insert_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|put_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|read_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|remove_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|setrandom_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|write_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|fail_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|quit_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|return_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|report_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|succeed_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|if_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|select_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|while_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|for_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|else_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NOT_USED
end_ifdef

begin_function_decl
name|bool
name|and_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|or_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|bool
name|not_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|some_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|each_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|no_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|how_to_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|yield_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|test_keyword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|share_keyword
parameter_list|()
function_decl|;
end_function_decl

end_unit

