begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is tc-i860.h.  */
end_comment

begin_define
define|#
directive|define
name|TC_I860
value|1
end_define

begin_define
define|#
directive|define
name|NO_LISTING
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_GAS
end_ifdef

begin_define
define|#
directive|define
name|REVERSE_SORT_RELOCS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OLD_GAS */
end_comment

begin_define
define|#
directive|define
name|tc_headers_hook
parameter_list|(
name|a
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_crawl_symbol_chain
parameter_list|(
name|a
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_aout_pre_write_hook
parameter_list|(
name|x
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of tc-i860.h */
end_comment

end_unit

