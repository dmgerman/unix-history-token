begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * %sccs.include.redist.c%  *  *	@(#)key.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * el.key.h: Key macro header  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_key
end_ifndef

begin_define
define|#
directive|define
name|_h_el_key
end_define

begin_typedef
typedef|typedef
union|union
name|key_value_t
block|{
name|el_action_t
name|cmd
decl_stmt|;
comment|/* If it is a command the #	*/
name|char
modifier|*
name|str
decl_stmt|;
comment|/* If it is a string...		*/
block|}
name|key_value_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|key_node_t
name|key_node_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|el_key_t
block|{
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* Key print buffer		*/
name|key_node_t
modifier|*
name|map
decl_stmt|;
comment|/* Key map			*/
name|key_value_t
name|val
decl_stmt|;
comment|/* Local conversion buffer	*/
block|}
name|el_key_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XK_CMD
value|0
end_define

begin_define
define|#
directive|define
name|XK_STR
value|1
end_define

begin_define
define|#
directive|define
name|XK_NOD
value|2
end_define

begin_define
define|#
directive|define
name|XK_EXE
value|3
end_define

begin_decl_stmt
name|protected
name|int
name|key_init
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
name|key_end
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
name|key_value_t
modifier|*
name|key_map_cmd
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
name|key_value_t
modifier|*
name|key_map_str
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|key_reset
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
name|key_get
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|char
operator|*
operator|,
name|key_value_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|key_add
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|char
operator|*
operator|,
name|key_value_t
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
name|key_clear
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|el_action_t
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|int
name|key_delete
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|key_print
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|void
name|key_kprint
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|char
operator|*
operator|,
name|key_value_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|protected
name|char
modifier|*
name|key__decode_str
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_el_key */
end_comment

end_unit

