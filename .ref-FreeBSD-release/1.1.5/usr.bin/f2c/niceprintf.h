begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* niceprintf.h -- contains constants and macros from the output filter    for the generated C code.  We use macros for increased speed, less    function overhead.  */
end_comment

begin_define
define|#
directive|define
name|MAX_OUTPUT_SIZE
value|6000
end_define

begin_comment
comment|/* Number of chars on one output line PLUS 				   the length of the longest string 				   printed using   nice_printf   */
end_comment

begin_define
define|#
directive|define
name|next_tab
parameter_list|(
name|fp
parameter_list|)
value|(indent += tab_size)
end_define

begin_define
define|#
directive|define
name|prev_tab
parameter_list|(
name|fp
parameter_list|)
value|(indent -= tab_size)
end_define

end_unit

