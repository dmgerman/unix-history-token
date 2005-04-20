begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENCAT_H
end_ifndef

begin_define
define|#
directive|define
name|GENCAT_H
end_define

begin_comment
comment|/*********************************************************** Copyright 1990, by Alfalfa Software Incorporated, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that Alfalfa's name not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  ALPHALPHA DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL ALPHALPHA BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  If you make any modifications, bugfixes or other changes to this software we'd appreciate it if you could send a copy to us so we can keep things up-to-date.  Many thanks. 				Kee Hinckley 				Alfalfa Software, Inc. 				267 Allston St., #3 				Cambridge, MA 02139  USA 				nazgul@alfalfa.com  ******************************************************************/
end_comment

begin_comment
comment|/*  * $set n comment  *	My extension:  If the comment begins with # treat the next string  *	 as a constant identifier.  * $delset n comment  *	n goes from 1 to NL_SETMAX  *	Deletes a set from the MC  * $ comment  *	My extension:  If comment begins with # treat the next string as  *	 a constant identifier for the next message.  * m message-text  *	m goes from 1 to NL_MSGMAX  *	If message-text is empty, and a space or tab is present, put  *	 empty string in catalog.  *	If message-text is empty, delete the message.  *	Length of text is 0 to NL_TEXTMAX  *	My extension:  If '#' is used instead of a number, the number  *	 is generated automatically.  A # followed by anything is an empty message.  * $quote c  *	Optional quote character which can surround message-text to  *	 show where spaces are.  *  * Escape Characters  *	\n (newline), \t (horiz tab), \v (vert tab), \b (backspace),  *	\r (carriage return), \f (formfeed), \\ (backslash), \ddd (bitpattern  *	in octal).  *	Also, \ at end of line is a continuation.  *  */
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

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_function_decl
specifier|extern
name|void
name|MCAddSet
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MCDelSet
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MCAddMsg
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MCDelMsg
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MCParse
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MCReadCat
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MCWriteConst
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MCWriteCat
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|MCGetByteOrder
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GENCAT_H */
end_comment

end_unit

