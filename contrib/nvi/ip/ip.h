begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)ip.h	8.3 (Berkeley) 10/13/96  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ip_private
block|{
name|int
name|i_fd
decl_stmt|;
comment|/* Input file descriptor. */
name|int
name|o_fd
decl_stmt|;
comment|/* Output file descriptor. */
name|size_t
name|row
decl_stmt|;
comment|/* Current row. */
name|size_t
name|col
decl_stmt|;
comment|/* Current column. */
name|size_t
name|iblen
decl_stmt|;
comment|/* Input buffer length. */
name|size_t
name|iskip
decl_stmt|;
comment|/* Returned input buffer. */
name|char
name|ibuf
index|[
literal|256
index|]
decl_stmt|;
comment|/* Input buffer. */
define|#
directive|define
name|IP_SCR_VI_INIT
value|0x0001
comment|/* Vi screen initialized. */
name|u_int32_t
name|flags
decl_stmt|;
block|}
name|IP_PRIVATE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPP
parameter_list|(
name|sp
parameter_list|)
value|((IP_PRIVATE *)((sp)->gp->ip_private))
end_define

begin_define
define|#
directive|define
name|GIPP
parameter_list|(
name|gp
parameter_list|)
value|((IP_PRIVATE *)((gp)->ip_private))
end_define

begin_comment
comment|/* The screen line relative to a specific window. */
end_comment

begin_define
define|#
directive|define
name|RLNO
parameter_list|(
name|sp
parameter_list|,
name|lno
parameter_list|)
value|(sp)->woff + (lno)
end_define

begin_comment
comment|/*  * The IP protocol consists of frames, each containing:  *  *<IPO_><object>  *  * XXX  * We should have a marking byte, 0xaa to delimit frames.  *  */
end_comment

begin_define
define|#
directive|define
name|IPO_CODE
value|1
end_define

begin_comment
comment|/* An event specification. */
end_comment

begin_define
define|#
directive|define
name|IPO_INT
value|2
end_define

begin_comment
comment|/* 4-byte, network order integer. */
end_comment

begin_define
define|#
directive|define
name|IPO_STR
value|3
end_define

begin_comment
comment|/* IPO_INT: followed by N bytes. */
end_comment

begin_define
define|#
directive|define
name|IPO_CODE_LEN
value|1
end_define

begin_define
define|#
directive|define
name|IPO_INT_LEN
value|4
end_define

begin_comment
comment|/* A structure that can hold the information for any frame. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ip_buf
block|{
name|int
name|code
decl_stmt|;
comment|/* Event code. */
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
comment|/* String. */
name|size_t
name|len
decl_stmt|;
comment|/* String length. */
name|u_int32_t
name|val1
decl_stmt|;
comment|/* First value. */
name|u_int32_t
name|val2
decl_stmt|;
comment|/* Second value. */
block|}
name|IP_BUF
typedef|;
end_typedef

begin_comment
comment|/*  * Screen/editor IP_CODE's.  *  * The program structure depends on the event loop being able to return  * IPO_EOF/IPOE_ERR multiple times -- eventually enough things will end  * due to the events that vi will reach the command level for the screen,  * at which point the exit flags will be set and vi will exit.  *  * IP events sent from the screen to vi.  */
end_comment

begin_define
define|#
directive|define
name|IPO_EOF
value|1
end_define

begin_comment
comment|/* End of input (NOT ^D). */
end_comment

begin_define
define|#
directive|define
name|IPO_ERR
value|2
end_define

begin_comment
comment|/* Input error. */
end_comment

begin_define
define|#
directive|define
name|IPO_INTERRUPT
value|3
end_define

begin_comment
comment|/* Interrupt. */
end_comment

begin_define
define|#
directive|define
name|IPO_QUIT
value|4
end_define

begin_comment
comment|/* Quit. */
end_comment

begin_define
define|#
directive|define
name|IPO_RESIZE
value|5
end_define

begin_comment
comment|/* Screen resize: IPO_INT, IPO_INT. */
end_comment

begin_define
define|#
directive|define
name|IPO_SIGHUP
value|6
end_define

begin_comment
comment|/* SIGHUP. */
end_comment

begin_define
define|#
directive|define
name|IPO_SIGTERM
value|7
end_define

begin_comment
comment|/* SIGTERM. */
end_comment

begin_define
define|#
directive|define
name|IPO_STRING
value|8
end_define

begin_comment
comment|/* Input string: IPO_STR. */
end_comment

begin_define
define|#
directive|define
name|IPO_WRITE
value|9
end_define

begin_comment
comment|/* Write. */
end_comment

begin_comment
comment|/*  * IP events sent from vi to the screen.  */
end_comment

begin_define
define|#
directive|define
name|IPO_ADDSTR
value|1
end_define

begin_comment
comment|/* Add a string: IPO_STR. */
end_comment

begin_define
define|#
directive|define
name|IPO_ATTRIBUTE
value|2
end_define

begin_comment
comment|/* Set screen attribute: IPO_INT, IPO_INT. */
end_comment

begin_define
define|#
directive|define
name|IPO_BELL
value|3
end_define

begin_comment
comment|/* Beep/bell/flash the terminal. */
end_comment

begin_define
define|#
directive|define
name|IPO_BUSY
value|4
end_define

begin_comment
comment|/* Display a busy message: IPO_STR. */
end_comment

begin_define
define|#
directive|define
name|IPO_CLRTOEOL
value|5
end_define

begin_comment
comment|/* Clear to the end of the line. */
end_comment

begin_define
define|#
directive|define
name|IPO_DELETELN
value|6
end_define

begin_comment
comment|/* Delete a line. */
end_comment

begin_define
define|#
directive|define
name|IPO_INSERTLN
value|7
end_define

begin_comment
comment|/* Insert a line. */
end_comment

begin_define
define|#
directive|define
name|IPO_MOVE
value|8
end_define

begin_comment
comment|/* Move the cursor: IPO_INT, IPO_INT. */
end_comment

begin_define
define|#
directive|define
name|IPO_REDRAW
value|9
end_define

begin_comment
comment|/* Redraw the screen. */
end_comment

begin_define
define|#
directive|define
name|IPO_REFRESH
value|10
end_define

begin_comment
comment|/* Refresh the screen. */
end_comment

begin_define
define|#
directive|define
name|IPO_RENAME
value|11
end_define

begin_comment
comment|/* Rename the screen: IPO_STR. */
end_comment

begin_define
define|#
directive|define
name|IPO_REWRITE
value|12
end_define

begin_comment
comment|/* Rewrite a line: IPO_INT. */
end_comment

begin_include
include|#
directive|include
file|"ip_extern.h"
end_include

end_unit

