begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * %sccs.include.redist.c%  *  *	@(#)term.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * el.term.h: Termcap header  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_term
end_ifndef

begin_define
define|#
directive|define
name|_h_el_term
end_define

begin_include
include|#
directive|include
file|"histedit.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|coord_t
name|t_size
decl_stmt|;
comment|/* # lines and cols	*/
name|bool_t
name|t_flags
decl_stmt|;
define|#
directive|define
name|TERM_CAN_INSERT
value|0x01
comment|/* Has insert cap	*/
define|#
directive|define
name|TERM_CAN_DELETE
value|0x02
comment|/* Has delete cap	*/
define|#
directive|define
name|TERM_CAN_CEOL
value|0x04
comment|/* Has CEOL cap		*/
define|#
directive|define
name|TERM_CAN_TAB
value|0x08
comment|/* Can use tabs		*/
define|#
directive|define
name|TERM_CAN_ME
value|0x10
comment|/* Can turn all attrs.	*/
define|#
directive|define
name|TERM_CAN_UP
value|0x20
comment|/* Can move up		*/
define|#
directive|define
name|TERM_HAS_META
value|0x40
comment|/* Has a meta key	*/
name|char
modifier|*
name|t_buf
decl_stmt|;
comment|/* Termcap buffer	*/
name|int
name|t_loc
decl_stmt|;
comment|/* location used	*/
name|char
modifier|*
modifier|*
name|t_str
decl_stmt|;
comment|/* termcap strings	*/
name|int
modifier|*
name|t_val
decl_stmt|;
comment|/* termcap values	*/
name|char
modifier|*
name|t_cap
decl_stmt|;
comment|/* Termcap buffer	*/
block|}
name|el_term_t
typedef|;
end_typedef

begin_decl_stmt
name|protected
name|void
name|term_move_to_line
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|term_move_to_char
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|term_clear_EOL
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|term_overwrite
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|term_insertwrite
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|term_deletechars
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|term_clear_screen
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|term_beep
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|term_change_size
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|term_get_size
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|term_init
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|term_bind_arrows
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|term_end
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|term_settc
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|term_telltc
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|term_echotc
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|term__putc
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|term__flush
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Easy access macros  */
end_comment

begin_define
define|#
directive|define
name|EL_FLAGS
value|(el)->el_term.t_flags
end_define

begin_define
define|#
directive|define
name|EL_CAN_INSERT
value|(EL_FLAGS& TERM_CAN_INSERT)
end_define

begin_define
define|#
directive|define
name|EL_CAN_DELETE
value|(EL_FLAGS& TERM_CAN_DELETE)
end_define

begin_define
define|#
directive|define
name|EL_CAN_CEOL
value|(EL_FLAGS& TERM_CAN_CEOL)
end_define

begin_define
define|#
directive|define
name|EL_CAN_TAB
value|(EL_FLAGS& TERM_CAN_TAB)
end_define

begin_define
define|#
directive|define
name|EL_CAN_ME
value|(EL_FLAGS& TERM_CAN_ME)
end_define

begin_define
define|#
directive|define
name|EL_HAS_META
value|(EL_FLAGS& TERM_HAS_META)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_el_term */
end_comment

end_unit

