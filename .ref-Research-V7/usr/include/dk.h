begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * switch commands  */
end_comment

begin_define
define|#
directive|define
name|RAM_ON
value|0226
end_define

begin_define
define|#
directive|define
name|ROM_ON
value|0322
end_define

begin_define
define|#
directive|define
name|R_CNTL
value|0264
end_define

begin_define
define|#
directive|define
name|W_CNTL
value|0170
end_define

begin_comment
comment|/*  * library routine declarations  */
end_comment

begin_function_decl
specifier|extern
name|long
name|cmread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|ocmread
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * call setup struct  */
end_comment

begin_struct
struct|struct
name|dialout
block|{
name|char
name|srv
decl_stmt|;
name|char
name|area
decl_stmt|;
name|char
name|sw
decl_stmt|;
name|char
name|mch
decl_stmt|;
name|char
name|chan
decl_stmt|;
name|char
name|other
decl_stmt|;
name|short
name|check
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|indial
block|{
name|char
name|i_lchan
decl_stmt|;
name|char
name|i_rhost
decl_stmt|;
name|char
name|i_rchan
decl_stmt|;
name|char
name|i_srv
decl_stmt|;
name|char
name|i_area
decl_stmt|;
name|char
name|i_sw
decl_stmt|;
name|char
name|i_mch
decl_stmt|;
name|char
name|i_chan
decl_stmt|;
name|char
name|i_other
decl_stmt|;
name|short
name|i_check
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|D_SH
value|1
end_define

begin_define
define|#
directive|define
name|D_FS
value|2
end_define

begin_define
define|#
directive|define
name|D_LSTNR
value|3
end_define

begin_struct
struct|struct
name|ring
block|{
name|char
name|r_lchan
decl_stmt|;
name|char
name|r_srv
decl_stmt|;
block|}
struct|;
end_struct

end_unit

