begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$  *  * $Log: pch.h,v $  * Revision 2.0.1.1  87/01/30  22:47:16  lwall  * Added do_ed_script().  *  * Revision 2.0  86/09/17  15:39:57  lwall  * Baseline for netwide release.  *  */
end_comment

begin_function_decl
name|EXT
name|FILE
modifier|*
name|pfp
name|INIT
parameter_list|(
name|Nullfp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* patch file pointer */
end_comment

begin_function_decl
name|void
name|re_patch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|open_patch_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_hunkmax
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|grow_hunkmax
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|there_is_another_patch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intuit_diff_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|next_intuit_at
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|skip_to
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|another_hunk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|pch_swap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pfetch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|short
name|pch_line_len
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_first
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_ptrn_lines
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_newfirst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_repl_lines
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_end
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_context
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|LINENUM
name|pch_hunk_beg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|pch_char
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pfetch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pgets
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_ed_script
parameter_list|()
function_decl|;
end_function_decl

end_unit

