begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_struct
struct|struct
name|keymap
block|{
name|int
name|Type
decl_stmt|;
comment|/* keymap type */
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* keymap name */
name|data_obj
modifier|*
modifier|*
name|k_keys
decl_stmt|;
comment|/* keys array */
name|char
name|k_alloc_p
decl_stmt|;
comment|/* whether we alloced k_keys */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|data_obj
modifier|*
name|MainKeys
index|[
name|NCHARS
index|]
decl_stmt|,
modifier|*
name|EscKeys
index|[
name|NCHARS
index|]
decl_stmt|,
modifier|*
name|CtlxKeys
index|[
name|NCHARS
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_comment
comment|/* used in About Jove... */
end_comment

begin_define
define|#
directive|define
name|F_MAINMAP
value|'\001'
end_define

begin_define
define|#
directive|define
name|F_PREF1MAP
value|'\002'
end_define

begin_define
define|#
directive|define
name|F_PREF2MAP
value|'\003'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|this_cmd
decl_stmt|,
comment|/* ... */
name|last_cmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last command ... to implement appending 			   to kill buffer */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|BindSomething
name|proto
argument_list|(
operator|(
expr|struct
name|data_obj
operator|*
call|(
modifier|*
name|proc
call|)
argument_list|()
operator|,
expr|struct
name|keymap
operator|*
name|map
operator|)
argument_list|)
decl_stmt|,
name|BindWMap
name|proto
argument_list|(
operator|(
expr|struct
name|keymap
operator|*
name|map
operator|,
name|int
name|lastkey
operator|,
expr|struct
name|data_obj
operator|*
name|cmd
operator|)
argument_list|)
decl_stmt|,
name|DescMap
name|proto
argument_list|(
operator|(
expr|struct
name|keymap
operator|*
name|map
operator|,
name|char
operator|*
name|pref
operator|)
argument_list|)
decl_stmt|,
name|DescWMap
name|proto
argument_list|(
operator|(
expr|struct
name|keymap
operator|*
name|map
operator|,
name|int
name|key
operator|)
argument_list|)
decl_stmt|,
name|dispatch
name|proto
argument_list|(
operator|(
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|PrefChar
name|proto
argument_list|(
operator|(
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Is `c' a prefix character */
end_comment

end_unit

