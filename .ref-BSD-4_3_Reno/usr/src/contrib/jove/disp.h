begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DIRTY
value|((daddr) 01)
end_define

begin_comment
comment|/* needs update for some reason */
end_comment

begin_define
define|#
directive|define
name|MODELINE
value|02
end_define

begin_comment
comment|/* this is a modeline */
end_comment

begin_define
define|#
directive|define
name|L_MOD
value|04
end_define

begin_comment
comment|/* line has been modified internally */
end_comment

begin_define
define|#
directive|define
name|makedirty
parameter_list|(
name|line
parameter_list|)
value|{ (line)->l_dline |= DIRTY; }
end_define

begin_define
define|#
directive|define
name|isdirty
parameter_list|(
name|line
parameter_list|)
value|((line)->l_dline& DIRTY)
end_define

begin_struct
struct|struct
name|scrimage
block|{
name|int
name|s_offset
decl_stmt|,
comment|/* offset to start printing at */
name|s_flags
decl_stmt|,
comment|/* various flags */
name|s_id
decl_stmt|,
comment|/* which buffer line */
name|s_vln
decl_stmt|;
comment|/* Visible Line Number */
name|Line
modifier|*
name|s_lp
decl_stmt|;
comment|/* so we can turn off red bit */
name|Window
modifier|*
name|s_window
decl_stmt|;
comment|/* window that contains this line */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|scrimage
modifier|*
name|DesiredScreen
decl_stmt|,
comment|/* what we want */
modifier|*
name|PhysScreen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* what we got */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|UpdModLine
decl_stmt|,
comment|/* whether we want to update the mode line */
name|UpdMesg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* update the message line */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|chkmail
name|proto
argument_list|(
operator|(
name|int
name|force
operator|)
argument_list|)
decl_stmt|,
name|calc_pos
name|proto
argument_list|(
operator|(
name|char
operator|*
name|lp
operator|,
name|int
name|c_char
operator|)
argument_list|)
decl_stmt|,
name|find_pos
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line
operator|,
name|int
name|c_char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|disp_opt_init
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|ChkWindows
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line1
operator|,
expr|struct
name|line
operator|*
name|line2
operator|)
argument_list|)
decl_stmt|,
name|DrawMesg
name|proto
argument_list|(
operator|(
name|int
name|abortable
operator|)
argument_list|)
decl_stmt|,
name|TOstart
name|proto
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|int
name|auto_newline
operator|)
argument_list|)
decl_stmt|,
name|TOstop
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|Typeout
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|,
name|rbell
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|redisplay
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|DisabledRedisplay
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ID_CHAR
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|IN_INSmode
decl_stmt|,
name|DClen
decl_stmt|,
name|MDClen
decl_stmt|,
name|IClen
decl_stmt|,
name|MIClen
decl_stmt|,
name|IMlen
decl_stmt|,
name|CElen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|INSmode
name|proto
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ID_CHAR */
end_comment

end_unit

