begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * common definitions for the pepsy driver routines  */
end_comment

begin_define
define|#
directive|define
name|PEPSY_VERSION
value|2
end_define

begin_comment
comment|/* find the default entry for this entry - for decoding  * - assumes its the next or the one after or the one after that.  * old version #define FDFLT_B(p)	((((p) + 1)->pe_type == DFLT_B) ? ((p) + 1) : \ 			((((p) + 2)->pe_type == DFLT_B) ? ((p) + 2): ((p) + 3)))  */
end_comment

begin_define
define|#
directive|define
name|FDFLT_B
parameter_list|(
name|p
parameter_list|)
value|fdflt_b(p)
end_define

begin_comment
comment|/* try a function */
end_comment

begin_comment
comment|/* find the entry for this default entry - for encoding  * call a function - to keep looking till it finds it, this is the  * alternative to the above scheme.  */
end_comment

begin_define
define|#
directive|define
name|FDFLT_F
parameter_list|(
name|p
parameter_list|)
value|fdflt_f(p)
end_define

begin_comment
comment|/* have to use a function */
end_comment

begin_comment
comment|/* assumes encoding tables */
end_comment

begin_define
define|#
directive|define
name|OPT_PRESENT
parameter_list|(
name|p
parameter_list|,
name|parm
parameter_list|)
value|(BITTEST(parm + p->pe_ucode, p->pe_tag))
end_define

begin_comment
comment|/* assumes decoding tables */
end_comment

begin_define
define|#
directive|define
name|SET_OPT_PRESENT
parameter_list|(
name|p
parameter_list|,
name|parm
parameter_list|)
value|(BITSET(*parm + p->pe_ucode, p->pe_tag))
end_define

begin_define
define|#
directive|define
name|CLR_OPT_PRESENT
parameter_list|(
name|p
parameter_list|,
name|parm
parameter_list|)
value|(BITCLR(*parm + p->pe_ucode, p->pe_tag))
end_define

begin_define
define|#
directive|define
name|NO_DATA_USED
value|(OK + 1)
end_define

end_unit

