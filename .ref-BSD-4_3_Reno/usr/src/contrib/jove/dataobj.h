begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FUNCTION
value|1
end_define

begin_define
define|#
directive|define
name|VARIABLE
value|2
end_define

begin_define
define|#
directive|define
name|MACRO
value|3
end_define

begin_define
define|#
directive|define
name|KEYMAP
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_define
define|#
directive|define
name|BUFFER
value|6
end_define

begin_comment
comment|/* menus can point to buffers, too */
end_comment

begin_define
define|#
directive|define
name|STRING
value|7
end_define

begin_comment
comment|/* a menu string or divider */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TYPEMASK
value|07
end_define

begin_define
define|#
directive|define
name|obj_type
parameter_list|(
name|o
parameter_list|)
value|((o)->Type& TYPEMASK)
end_define

begin_define
define|#
directive|define
name|MAJOR_MODE
value|010
end_define

begin_define
define|#
directive|define
name|MINOR_MODE
value|020
end_define

begin_define
define|#
directive|define
name|MODIFIER
value|040
end_define

begin_define
define|#
directive|define
name|MODFUNC
value|(FUNCTION|MODIFIER)
end_define

begin_define
define|#
directive|define
name|DefMajor
parameter_list|(
name|x
parameter_list|)
value|(FUNCTION|MAJOR_MODE|((x)<< 8))
end_define

begin_define
define|#
directive|define
name|DefMinor
parameter_list|(
name|x
parameter_list|)
value|(FUNCTION|MINOR_MODE|((x)<< 8))
end_define

begin_struct
struct|struct
name|macro
block|{
name|int
name|Type
decl_stmt|;
comment|/* in this case a macro */
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* name is always second ... */
name|int
name|m_len
decl_stmt|,
comment|/* length of macro so we can use ^@ */
name|m_buflen
decl_stmt|,
comment|/* memory allocated for it */
name|m_flags
decl_stmt|;
name|char
modifier|*
name|m_body
decl_stmt|;
comment|/* actual body of the macro */
name|struct
name|macro
modifier|*
name|m_nextm
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cmd
block|{
name|int
name|Type
decl_stmt|;
name|char
modifier|*
name|Name
decl_stmt|;
name|void
argument_list|(
argument|*c_proc
argument_list|)
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MAC
name|char
name|c_map
decl_stmt|;
comment|/* prefix map for About Jove... */
name|char
name|c_key
decl_stmt|;
comment|/* key binding for About Jove... */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|data_obj
block|{
name|int
name|Type
decl_stmt|;
name|char
modifier|*
name|Name
decl_stmt|;
block|}
name|data_obj
typedef|;
end_typedef

begin_comment
comment|/* points to cmd, macro, keymap or variable */
end_comment

begin_decl_stmt
specifier|extern
name|data_obj
modifier|*
name|LastCmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last command invoked */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|cmd
name|commands
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|macro
modifier|*
name|macros
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|macro
modifier|*
name|macstack
index|[]
decl_stmt|,
name|KeyMacro
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|cmd
modifier|*
name|FindCmd
name|proto
argument_list|(
operator|(
name|void
argument_list|(
argument|*proc
argument_list|)
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|data_obj
modifier|*
name|findcom
name|proto
argument_list|(
operator|(
name|char
operator|*
name|prompt
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|findmac
name|proto
argument_list|(
operator|(
name|char
operator|*
name|prompt
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|findvar
name|proto
argument_list|(
operator|(
name|char
operator|*
name|prompt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

