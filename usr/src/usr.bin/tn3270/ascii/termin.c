begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright (c) 1984, 1985, 1986 by the Regents of the  *	University of California and by Gregory Glenn Minshall.  *  *	Permission to use, copy, modify, and distribute these  *	programs and their documentation for any purpose and  *	without fee is hereby granted, provided that this  *	copyright and permission appear on all copies and  *	supporting documentation, the name of the Regents of  *	the University of California not be used in advertising  *	or publicity pertaining to distribution of the programs  *	without specific prior permission, and notice be given in  *	supporting documentation that copying and distribution is  *	by permission of the Regents of the University of California  *	and by Gregory Glenn Minshall.  Neither the Regents of the  *	University of California nor Gregory Glenn Minshall make  *	representations about the suitability of this software  *	for any purpose.  It is provided "as is" without  *	express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)termin.c	3.1  10/29/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef lint */
end_comment

begin_comment
comment|/* this takes characters from the keyboard, and produces 3270 keystroke 	codes  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"../general/general.h"
end_include

begin_include
include|#
directive|include
file|"../ctlr/function.h"
end_include

begin_include
include|#
directive|include
file|"../ctlr/inbound.ext"
end_include

begin_include
include|#
directive|include
file|"../ctlr/outbound.ext"
end_include

begin_include
include|#
directive|include
file|"../telnet.ext"
end_include

begin_include
include|#
directive|include
file|"termin.ext"
end_include

begin_include
include|#
directive|include
file|"astosc.h"
end_include

begin_include
include|#
directive|include
file|"state.h"
end_include

begin_include
include|#
directive|include
file|"../general/globals.h"
end_include

begin_define
define|#
directive|define
name|IsControl
parameter_list|(
name|c
parameter_list|)
value|(!isprint(c) || (isspace(c)&& ((c) != ' ')))
end_define

begin_define
define|#
directive|define
name|NextState
parameter_list|(
name|x
parameter_list|)
value|(x->next)
end_define

begin_escape
end_escape

begin_comment
comment|/* XXX temporary - hard code in the state table */
end_comment

begin_define
define|#
directive|define
name|MATCH_ANY
value|0xff
end_define

begin_comment
comment|/* actually, match any character */
end_comment

begin_escape
end_escape

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|ourBuffer
index|[
literal|100
index|]
decl_stmt|,
comment|/* where we store stuff */
modifier|*
name|ourPHead
init|=
name|ourBuffer
decl_stmt|,
comment|/* first character in buffer */
modifier|*
name|ourPTail
init|=
name|ourBuffer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where next character goes */
end_comment

begin_decl_stmt
specifier|static
name|int
name|InControl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|WaitingForSynch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|astosc
modifier|*
name|spacePTR
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Space is hard to enter */
end_comment

begin_decl_stmt
specifier|static
name|state
modifier|*
name|headOfControl
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where we enter code state table */
end_comment

begin_define
define|#
directive|define
name|FullChar
value|((ourPTail+5)>= ourBuffer+sizeof ourBuffer)
end_define

begin_define
define|#
directive|define
name|EmptyChar
value|(ourPTail == ourPHead)
end_define

begin_escape
end_escape

begin_comment
comment|/*  * init_keyboard()  *  * Initialize the keyboard variables.  */
end_comment

begin_function
name|void
name|init_keyboard
parameter_list|()
block|{
name|ourPHead
operator|=
name|ourPTail
operator|=
name|ourBuffer
expr_stmt|;
name|InControl
operator|=
literal|0
expr_stmt|;
name|WaitingForSynch
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Initialize the keyboard mapping file.  */
end_comment

begin_function
name|void
name|InitMapping
parameter_list|()
block|{
specifier|extern
name|state
modifier|*
name|InitControl
parameter_list|()
function_decl|;
specifier|register
name|struct
name|astosc
modifier|*
name|ptr
decl_stmt|;
if|if
condition|(
operator|!
name|headOfControl
condition|)
block|{
comment|/* need to initialize */
name|headOfControl
operator|=
name|InitControl
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|,
name|ascii_to_index
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|headOfControl
condition|)
block|{
comment|/* should not occur */
name|quit
argument_list|()
expr_stmt|;
block|}
for|for
control|(
name|ptr
operator|=
operator|&
name|astosc
index|[
literal|0
index|]
init|;
name|ptr
operator|<=
operator|&
name|astosc
index|[
name|highestof
argument_list|(
name|astosc
argument_list|)
index|]
condition|;
name|ptr
operator|++
control|)
block|{
if|if
condition|(
name|ptr
operator|->
name|function
operator|==
name|FCN_SPACE
condition|)
block|{
name|spacePTR
operator|=
name|ptr
expr_stmt|;
block|}
block|}
block|}
block|}
end_function

begin_comment
comment|/* AddChar - put a function index in our buffer */
end_comment

begin_function
specifier|static
name|void
name|AddChar
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|FullChar
condition|)
block|{
operator|*
name|ourPTail
operator|++
operator|=
name|c
expr_stmt|;
block|}
else|else
block|{
name|RingBell
argument_list|(
literal|"Typeahead buffer full"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* FlushChar - put everything where it belongs */
end_comment

begin_function
specifier|static
name|void
name|FlushChar
parameter_list|()
block|{
name|ourPTail
operator|=
name|ourBuffer
expr_stmt|;
name|ourPHead
operator|=
name|ourBuffer
expr_stmt|;
block|}
end_function

begin_function
name|int
name|TerminalIn
parameter_list|()
block|{
comment|/* send data from us to next link in stream */
name|int
name|work
init|=
literal|0
decl_stmt|;
specifier|register
name|struct
name|astosc
modifier|*
name|ptr
decl_stmt|;
while|while
condition|(
operator|!
name|EmptyChar
condition|)
block|{
comment|/* send up the link */
if|if
condition|(
operator|*
name|ourPHead
operator|==
literal|' '
condition|)
block|{
name|ptr
operator|=
name|spacePTR
expr_stmt|;
block|}
else|else
block|{
name|ptr
operator|=
operator|&
name|astosc
index|[
operator|*
name|ourPHead
index|]
expr_stmt|;
block|}
if|if
condition|(
name|AcceptKeystroke
argument_list|(
name|ptr
operator|->
name|scancode
argument_list|,
name|ptr
operator|->
name|shiftstate
argument_list|)
operator|==
literal|1
condition|)
block|{
name|ourPHead
operator|++
expr_stmt|;
name|work
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
break|break;
block|}
block|}
if|if
condition|(
name|EmptyChar
condition|)
block|{
name|FlushChar
argument_list|()
expr_stmt|;
block|}
comment|/* return value answers question: "did we do anything useful?" */
return|return
name|work
return|;
block|}
end_function

begin_function
name|int
name|DataFromTerminal
parameter_list|(
name|buffer
parameter_list|,
name|count
parameter_list|)
specifier|register
name|char
modifier|*
name|buffer
decl_stmt|;
comment|/* the data read in */
specifier|register
name|int
name|count
decl_stmt|;
comment|/* how many bytes in this buffer */
block|{
specifier|register
name|state
modifier|*
name|regControlPointer
decl_stmt|;
specifier|register
name|char
name|c
decl_stmt|;
specifier|register
name|int
name|result
decl_stmt|;
name|int
name|origCount
decl_stmt|;
specifier|extern
name|int
name|bellwinup
decl_stmt|;
specifier|static
name|state
modifier|*
name|controlPointer
decl_stmt|;
if|if
condition|(
name|bellwinup
condition|)
block|{
name|BellOff
argument_list|()
expr_stmt|;
block|}
name|origCount
operator|=
name|count
expr_stmt|;
while|while
condition|(
name|count
condition|)
block|{
name|c
operator|=
operator|*
name|buffer
operator|++
operator|&
literal|0x7f
expr_stmt|;
name|count
operator|--
expr_stmt|;
if|if
condition|(
operator|!
name|InControl
operator|&&
operator|!
name|IsControl
argument_list|(
name|c
argument_list|)
condition|)
block|{
name|AddChar
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* add ascii character */
block|}
else|else
block|{
if|if
condition|(
operator|!
name|InControl
condition|)
block|{
comment|/* first character of sequence */
name|InControl
operator|=
literal|1
expr_stmt|;
name|controlPointer
operator|=
name|headOfControl
expr_stmt|;
block|}
comment|/* control pointer points to current position in state table */
for|for
control|(
name|regControlPointer
operator|=
name|controlPointer
init|;
condition|;
name|regControlPointer
operator|=
name|NextState
argument_list|(
name|regControlPointer
argument_list|)
control|)
block|{
if|if
condition|(
operator|!
name|regControlPointer
condition|)
block|{
comment|/* ran off end */
name|RingBell
argument_list|(
literal|"Invalid control sequence"
argument_list|)
expr_stmt|;
name|regControlPointer
operator|=
name|headOfControl
expr_stmt|;
name|InControl
operator|=
literal|0
expr_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
comment|/* Flush current input */
break|break;
block|}
if|if
condition|(
operator|(
name|regControlPointer
operator|->
name|match
operator|==
name|c
operator|)
comment|/* hit this character */
operator|||
operator|(
name|regControlPointer
operator|->
name|match
operator|==
name|MATCH_ANY
operator|)
condition|)
block|{
name|result
operator|=
name|regControlPointer
operator|->
name|result
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|STATE_GOTO
condition|)
block|{
name|regControlPointer
operator|=
name|regControlPointer
operator|->
name|address
expr_stmt|;
break|break;
comment|/* go to next character */
block|}
if|if
condition|(
name|WaitingForSynch
condition|)
block|{
if|if
condition|(
name|astosc
index|[
name|result
index|]
operator|.
name|function
operator|==
name|FCN_SYNCH
condition|)
block|{
name|WaitingForSynch
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|RingBell
argument_list|(
literal|"Need to type synch character"
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|astosc
index|[
name|result
index|]
operator|.
name|function
operator|==
name|FCN_FLINP
condition|)
block|{
name|FlushChar
argument_list|()
expr_stmt|;
comment|/* Don't add FLINP */
block|}
else|else
block|{
if|if
condition|(
name|astosc
index|[
name|result
index|]
operator|.
name|function
operator|==
name|FCN_MASTER_RESET
condition|)
block|{
name|FlushChar
argument_list|()
expr_stmt|;
block|}
name|AddChar
argument_list|(
name|result
argument_list|)
expr_stmt|;
comment|/* add this code */
block|}
name|InControl
operator|=
literal|0
expr_stmt|;
comment|/* out of control now */
break|break;
block|}
block|}
name|controlPointer
operator|=
name|regControlPointer
expr_stmt|;
comment|/* save state */
block|}
block|}
operator|(
name|void
operator|)
name|TerminalIn
argument_list|()
expr_stmt|;
comment|/* try to send data */
return|return
operator|(
name|origCount
operator|-
name|count
operator|)
return|;
block|}
end_function

end_unit

