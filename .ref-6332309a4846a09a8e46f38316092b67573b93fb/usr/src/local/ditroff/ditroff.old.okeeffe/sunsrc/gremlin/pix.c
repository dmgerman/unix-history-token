begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)pix.c	1.1	%G%  *  * Picture subwindow routines for the SUN Gremlin picture editor.  *  * Mark Opperman (opcode@monet.BERKELEY)  *  */
end_comment

begin_include
include|#
directive|include
file|<suntool/tool_hs.h>
end_include

begin_include
include|#
directive|include
file|"gremlin.h"
end_include

begin_include
include|#
directive|include
file|"icondata.h"
end_include

begin_comment
comment|/* imports from graphics.c */
end_comment

begin_extern
extern|extern GRCurrentSetOn(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from text.c */
end_comment

begin_extern
extern|extern TxMsgOK(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from main.c */
end_comment

begin_decl_stmt
specifier|extern
name|ELT
modifier|*
name|cset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|PX
decl_stmt|,
name|PY
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pixwin
modifier|*
name|pix_pw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rect
name|pix_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pixrect
modifier|*
name|cset_pr
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern SUN_XORIGIN;
end_extern

begin_extern
extern|extern SUN_YORIGIN;
end_extern

begin_comment
comment|/* imports from help.c */
end_comment

begin_extern
extern|extern pixsw_help(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|pix_left
argument_list|(
name|ie
argument_list|)
specifier|register
expr|struct
name|inputevent
operator|*
name|ie
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|TxMsgOK
argument_list|()
expr_stmt|;
name|PX
operator|=
name|winx_to_db
argument_list|(
name|ie
operator|->
name|ie_locx
argument_list|)
expr_stmt|;
name|PY
operator|=
name|winy_to_db
argument_list|(
name|ie
operator|->
name|ie_locy
argument_list|)
expr_stmt|;
name|LGPoint
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|pix_middle
argument_list|(
name|ie
argument_list|)
specifier|register
expr|struct
name|inputevent
operator|*
name|ie
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|TxMsgOK
argument_list|()
expr_stmt|;
name|LGDeletePoint
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|pix_right
argument_list|(
name|ie
argument_list|)
specifier|register
expr|struct
name|inputevent
operator|*
name|ie
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|TxMsgOK
argument_list|()
expr_stmt|;
name|pixsw_help
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|pix_winexit
argument_list|(
name|ie
argument_list|)
specifier|register
expr|struct
name|inputevent
operator|*
name|ie
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
operator|(
name|ie
operator|->
name|ie_locx
operator|>=
name|pix_size
operator|.
name|r_width
operator|)
operator|||
operator|(
name|ie
operator|->
name|ie_locy
operator|>=
name|pix_size
operator|.
name|r_height
operator|)
condition|)
name|GRCurrentSetOn
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

