begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m_msgdef.c - some defines for sbr/m_getfld.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|ident
index|[]
init|=
literal|"@(#)$Id: m_msgdef.c,v 1.2 1992/12/15 00:20:22 jromine Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_include
include|#
directive|include
file|"../h/mh.h"
end_include

begin_decl_stmt
name|int
name|msg_count
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* disgusting hack for "inc" so it can 			 * know how many characters were stuffed 			 * in the buffer on the last call (see 			 * comments in uip/scansbr.c) */
end_comment

begin_decl_stmt
name|int
name|msg_style
init|=
name|MS_DEFAULT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The "full" delimiter string for a packed maildrop consists  * of a newline followed by the actual delimiter.  E.g., the  * full string for a Unix maildrop would be: "\n\nFrom ".  * "Fdelim" points to the start of the full string and is used  * in the BODY case of the main routine to search the buffer for  * a possible eom.  Msg_delim points to the first character of  * the actual delim. string (i.e., fdelim+1).  Edelim  * points to the 2nd character of actual delimiter string.  It  * is used in m_Eom because the first character of the string  * has been read and matched before m_Eom is called.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|msg_delim
init|=
literal|""
decl_stmt|;
end_decl_stmt

end_unit

