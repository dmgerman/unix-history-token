begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_comment
comment|/* macros for getting at and setting the current argument count */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arg_supplied_p
decl_stmt|,
name|arg_count
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|arg_type
parameter_list|()
value|arg_supplied_p
end_define

begin_define
define|#
directive|define
name|arg_value
parameter_list|()
value|arg_count
end_define

begin_define
define|#
directive|define
name|set_is_an_arg
parameter_list|(
name|there_is
parameter_list|)
value|{ arg_supplied_p = (there_is); }
end_define

begin_define
define|#
directive|define
name|set_arg_value
parameter_list|(
name|n
parameter_list|)
value|{ arg_supplied_p = YES; arg_count = (n); }
end_define

begin_define
define|#
directive|define
name|negate_arg_value
parameter_list|()
value|{ arg_count = -arg_count; }
end_define

begin_define
define|#
directive|define
name|clr_arg_value
parameter_list|()
value|{ arg_supplied_p = NO; arg_count = 1; }
end_define

begin_define
define|#
directive|define
name|is_an_arg
parameter_list|()
value|(arg_supplied_p != NO)
end_define

end_unit

