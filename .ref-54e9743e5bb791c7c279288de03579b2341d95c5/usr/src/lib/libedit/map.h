begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * %sccs.include.redist.c%  *  *	@(#)map.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * el.map.h:	Editor maps  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_map
end_ifndef

begin_define
define|#
directive|define
name|_h_el_map
end_define

begin_typedef
typedef|typedef
struct|struct
name|el_bindings_t
block|{
comment|/* for the "bind" shell command */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* function name for bind command */
name|int
name|func
decl_stmt|;
comment|/* function numeric value */
specifier|const
name|char
modifier|*
name|description
decl_stmt|;
comment|/* description of function */
block|}
name|el_bindings_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|el_map_t
block|{
name|el_action_t
modifier|*
name|alt
decl_stmt|;
comment|/* The current alternate key map	*/
name|el_action_t
modifier|*
name|key
decl_stmt|;
comment|/* The current normal key map		*/
name|el_action_t
modifier|*
name|current
decl_stmt|;
comment|/* The keymap we are using		*/
name|el_action_t
modifier|*
name|emacs
decl_stmt|;
comment|/* The default emacs key map		*/
name|el_action_t
modifier|*
name|vic
decl_stmt|;
comment|/* The vi command mode key map		*/
name|el_action_t
modifier|*
name|vii
decl_stmt|;
comment|/* The vi insert mode key map		*/
name|int
name|type
decl_stmt|;
comment|/* Emacs or vi				*/
name|el_bindings_t
modifier|*
name|help
decl_stmt|;
comment|/* The help for the editor functions	*/
name|el_func_t
modifier|*
name|func
decl_stmt|;
comment|/* List of available functions		*/
name|int
name|nfunc
decl_stmt|;
comment|/* The number of functions/help items	*/
block|}
name|el_map_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAP_EMACS
value|0
end_define

begin_define
define|#
directive|define
name|MAP_VI
value|1
end_define

begin_decl_stmt
name|protected
name|int
name|map_bind
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
name|map_init
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
name|map_end
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
name|map_init_vi
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
name|map_init_emacs
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
name|map_set_editor
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
name|int
name|map_addfunc
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|el_func_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_el_map */
end_comment

end_unit

