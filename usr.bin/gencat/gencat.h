begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** Copyright 1990, by Alfalfa Software Incorporated, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that Alfalfa's name not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  ALPHALPHA DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL ALPHALPHA BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  If you make any modifications, bugfixes or other changes to this software we'd appreciate it if you could send a copy to us so we can keep things up-to-date.  Many thanks. 				Kee Hinckley 				Alfalfa Software, Inc. 				267 Allston St., #3 				Cambridge, MA 02139  USA 				nazgul@alfalfa.com  ******************************************************************/
end_comment

begin_comment
comment|/* Edit History  02/25/91   2 nazgul	Added MCGetByteOrder 01/18/91   2 hamilton	#if not reparsed 01/12/91   2 schulert	conditionally use prototypes 11/03/90   1 hamilton	Alphalpha->Alfalfa& OmegaMail->Poste 08/13/90   1 schulert	move from ua to omu */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gencat_h
end_ifndef

begin_define
define|#
directive|define
name|gencat_h
end_define

begin_comment
comment|/*  * $set n comment  *	My extension:  If the comment begins with # treat the next string  *	 as a constant identifier.  * $delset n comment  *	n goes from 1 to NL_SETMAX  *	Deletes a set from the MC  * $ comment  *	My extension:  If comment begins with # treat the next string as  *	 a constant identifier for the next message.  * m message-text  *	m goes from 1 to NL_MSGMAX  *	If message-text is empty, and a space or tab is present, put  *	 empty string in catalog.  *	If message-text is empty, delete the message.  *	Length of text is 0 to NL_TEXTMAX  *	My extension:  If '#' is used instead of a number, the number  *	 is generated automatically.  A # followed by anything is an empty message.  * $quote c  *	Optional quote character which can suround message-text to  *	 show where spaces are.  *  * Escape Characters  *	\n (newline), \t (horiz tab), \v (vert tab), \b (backspace),  *	\r (carriage return), \f (formfeed), \\ (backslash), \ddd (bitpattern  *	in octal).  *	Also, \ at end of line is a continuation.  *  */
end_comment

begin_define
define|#
directive|define
name|MCLangC
value|0
end_define

begin_define
define|#
directive|define
name|MCLangCPlusPlus
value|1
end_define

begin_define
define|#
directive|define
name|MCLangANSIC
value|2
end_define

begin_define
define|#
directive|define
name|MAXTOKEN
value|1024
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANSI_C
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|ANSI_C
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ANSI_C
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|P_
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P_
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|MCAddSet
name|P_
argument_list|(
operator|(
name|int
name|setId
operator|,
name|char
operator|*
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|MCDelSet
name|P_
argument_list|(
operator|(
name|int
name|setId
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|MCAddMsg
name|P_
argument_list|(
operator|(
name|int
name|msgId
operator|,
name|char
operator|*
name|msg
operator|,
name|char
operator|*
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|MCDelMsg
name|P_
argument_list|(
operator|(
name|int
name|msgId
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|MCParse
name|P_
argument_list|(
operator|(
name|int
name|fd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|MCReadCat
name|P_
argument_list|(
operator|(
name|int
name|fd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|MCWriteConst
name|P_
argument_list|(
operator|(
name|int
name|fd
operator|,
name|int
name|type
operator|,
name|int
name|orConsts
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|MCWriteCat
name|P_
argument_list|(
operator|(
name|int
name|fd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|MCGetByteOrder
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|True
end_ifndef

begin_define
define|#
directive|define
name|True
value|~0
end_define

begin_define
define|#
directive|define
name|False
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

