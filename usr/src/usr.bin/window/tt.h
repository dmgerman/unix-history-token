begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)tt.h	3.5 83/08/17  */
end_comment

begin_struct
struct|struct
name|tt
block|{
name|int
function_decl|(
modifier|*
name|tt_init
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_end
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_setinsert
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_setmodes
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_move
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_insline
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_delline
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_delchar
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_write
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_putc
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_blank
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_clreol
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_clreos
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_clear
function_decl|)
parameter_list|()
function_decl|;
name|int
name|tt_nrow
decl_stmt|;
name|int
name|tt_ncol
decl_stmt|;
name|char
name|tt_availmodes
decl_stmt|;
name|char
modifier|*
name|tt_frame
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|tt
name|tt
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|tt_tab
block|{
name|char
modifier|*
name|tt_name
decl_stmt|;
name|int
name|tt_len
decl_stmt|;
name|int
function_decl|(
modifier|*
name|tt_func
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|tt_tab
name|tt_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * nicer interface to termcap routines  */
end_comment

begin_decl_stmt
name|char
name|tt_strings
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string buffer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tt_strp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer for it */
end_comment

begin_function_decl
name|int
name|tt_pc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* just putchar() */
end_comment

begin_function_decl
name|int
name|tt_sc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* *tt_strp++ = c */
end_comment

begin_function_decl
name|char
modifier|*
name|tt_xgetstr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* tgetstr() and expand delays */
end_comment

begin_define
define|#
directive|define
name|tt_tgetstr
parameter_list|(
name|s
parameter_list|)
value|tgetstr((s),&tt_strp)
end_define

begin_define
define|#
directive|define
name|tt_tputs
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|tputs((s), (n), tt_pc)
end_define

end_unit

