begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"vmodem.h"
end_include

begin_include
include|#
directive|include
include|ssdef
end_include

begin_include
include|#
directive|include
include|tt2def
end_include

begin_include
include|#
directive|include
include|ttdef
end_include

begin_define
define|#
directive|define
name|SS_NORMAL
value|SS$_NORMAL
end_define

begin_comment
comment|/*  VMS structures  */
end_comment

begin_comment
comment|/*  *	TT_INFO structures are used for passing information about  *	the terminal.  Used in GTTY and STTY calls.  */
end_comment

begin_decl_stmt
name|struct
name|tt_info
name|ttys
decl_stmt|,
name|ttysnew
decl_stmt|,
name|ttystemp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  */
end_comment

begin_comment
comment|/*  * return 1 iff stdout and stderr are different devices  *  indicating this program operating with a modem on a  *  different line  */
end_comment

begin_decl_stmt
name|int
name|Fromcu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Were called from cu or yam */
end_comment

begin_macro
name|from_cu
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|cucheck
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/*  * mode(n)  *  3: save old tty stat, set raw mode with flow control  *  2: set XON/XOFF for sb/sz with ZMODEM or YMODEM-g  *  1: save old tty stat, set raw mode   *  0: restore original tty mode  */
end_comment

begin_macro
name|mode
argument_list|(
argument|n
argument_list|)
end_macro

begin_block
block|{
name|int
modifier|*
name|iptr
decl_stmt|,
name|parameters
decl_stmt|;
specifier|static
name|savedmodes
operator|=
name|FALSE
expr_stmt|;
name|vfile
argument_list|(
literal|"mode:%d"
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|savedmodes
condition|)
block|{
if|if
condition|(
name|gtty
argument_list|(
operator|&
name|ttys
argument_list|)
operator|!=
name|SS$_NORMAL
condition|)
name|death
argument_list|(
literal|"SETMODES:  error return from GTTY (1)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|gtty
argument_list|(
operator|&
name|ttysnew
argument_list|)
operator|!=
name|SS$_NORMAL
condition|)
name|death
argument_list|(
literal|"SETMODES:  error return from GTTY (2)"
argument_list|)
expr_stmt|;
name|savedmodes
operator|=
name|TRUE
expr_stmt|;
block|}
comment|/* 	 * Set new terminal parameters. 	 *  Note:  there are three bytes of terminal characteristics, 	 *  so we should make sure the fourth byte of the integer is unchanged. 	 */
switch|switch
condition|(
name|n
condition|)
block|{
case|case
literal|1
case|:
case|case
literal|2
case|:
case|case
literal|3
case|:
name|iptr
operator|=
operator|&
operator|(
name|ttysnew
operator|.
name|dev_characteristics
operator|.
name|bcharacteristics
operator|)
expr_stmt|;
name|parameters
operator|=
operator|*
name|iptr
expr_stmt|;
name|parameters
operator|&=
operator|~
name|TT$M_ESCAPE
expr_stmt|;
comment|/*  ESCAPE   OFF  */
name|parameters
operator|&=
operator|~
name|TT$M_HOSTSYNC
expr_stmt|;
comment|/*  HOSTSYNC OFF  */
name|parameters
operator||=
name|TT$M_NOECHO
expr_stmt|;
comment|/*  NOECHO   ON   */
name|parameters
operator||=
name|TT$M_PASSALL
expr_stmt|;
comment|/*  PASSALL  ON   */
name|parameters
operator|&=
operator|~
name|TT$M_READSYNC
expr_stmt|;
comment|/*  READSYNC OFF  */
name|parameters
operator|&=
operator|~
name|TT$M_TTSYNC
expr_stmt|;
comment|/*  TTSYNC   OFF  */
name|parameters
operator|&=
operator|~
name|TT$M_WRAP
expr_stmt|;
comment|/*  WRAP     OFF  */
name|parameters
operator||=
name|TT$M_EIGHTBIT
expr_stmt|;
comment|/*  EIGHTBIT ON   */
if|if
condition|(
name|n
operator|==
literal|3
condition|)
block|{
name|parameters
operator||=
name|TT$M_HOSTSYNC
expr_stmt|;
comment|/*  HOSTSYNC On  */
block|}
if|if
condition|(
name|n
operator|==
literal|2
condition|)
block|{
name|parameters
operator||=
name|TT$M_TTSYNC
expr_stmt|;
comment|/*  TTSYNC On  */
block|}
operator|*
name|iptr
operator|=
name|parameters
expr_stmt|;
if|if
condition|(
name|stty
argument_list|(
operator|&
name|ttysnew
argument_list|)
operator|!=
name|SS_NORMAL
condition|)
name|fatal
argument_list|(
literal|"SETMODES:  error return from STTY"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0
case|:
name|stty
argument_list|(
operator|&
name|ttys
argument_list|)
expr_stmt|;
comment|/*  Restore original modes  */
comment|/* error return to /dev/null */
break|break;
block|}
block|}
end_block

begin_comment
comment|/* set tty modes for vrzsz transfers */
end_comment

begin_macro
name|setmodes
argument_list|()
end_macro

begin_block
block|{
comment|/*  Device characteristics for VMS  */
block|}
end_block

begin_macro
name|fatal
argument_list|(
argument|msg
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|msg
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|mode
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* put back normal tty modes */
name|printf
argument_list|(
literal|"vrzsz:  %s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|SS_NORMAL
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Call this instead if funny modes haven't been set yet */
end_comment

begin_macro
name|death
argument_list|(
argument|msg
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|msg
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"vrzsz:  %s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|SS_NORMAL
argument_list|)
expr_stmt|;
block|}
end_block

begin_define
define|#
directive|define
name|LSIZE
value|64
end_define

begin_comment
comment|/* Size of send& receive buffers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFREAD
end_ifdef

begin_decl_stmt
name|char
name|Rxlbuf
index|[
name|LSIZE
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Rxleft
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of characters in Rxlbuf */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Rxcdq
init|=
name|Rxlbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer for removing chars from Rxlbuf */
end_comment

begin_comment
comment|/*  * This version of readline is reasoably well suited for  * reading many characters.  *  * timeout is in tenths of seconds  */
end_comment

begin_macro
name|readline
argument_list|(
argument|timeout
argument_list|)
end_macro

begin_decl_stmt
name|int
name|timeout
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|c
decl_stmt|;
extern|extern errno;
if|if
condition|(
operator|--
name|Rxleft
operator|>=
literal|0
condition|)
return|return
operator|(
operator|*
name|Rxcdq
operator|++
operator|&
literal|0377
operator|)
return|;
ifdef|#
directive|ifdef
name|DEBUGG
name|eprintf
argument_list|(
literal|"Calling read: "
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|(
name|c
operator|=
name|timeout
operator|/
literal|10
operator|)
operator|<
literal|2
condition|)
name|c
operator|=
literal|2
expr_stmt|;
do|do
block|{
name|Rxleft
operator|=
name|raw_read
argument_list|(
name|LSIZE
argument_list|,
name|Rxcdq
operator|=
name|Rxlbuf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|Rxleft
operator|==
name|SS$_TIMEOUT
operator|&&
operator|--
name|c
operator|>=
literal|0
condition|)
do|;
ifdef|#
directive|ifdef
name|DEBUGG
name|eprintf
argument_list|(
literal|"Read returned %d bytes\n"
argument_list|,
name|Rxleft
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|Rxleft
operator|==
name|SS$_TIMEOUT
operator|||
operator|--
name|Rxleft
operator|<
literal|0
condition|)
block|{
name|Rxleft
operator|=
literal|0
expr_stmt|;
return|return
name|TIMEOUT
return|;
block|}
return|return
operator|(
operator|*
name|Rxcdq
operator|++
operator|&
literal|0377
operator|)
return|;
block|}
end_block

begin_macro
name|purgeline
argument_list|()
end_macro

begin_block
block|{
name|Rxleft
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BUFREAD */
end_comment

begin_comment
comment|/* get a byte from data stream -- timeout if "dseconds" elapses */
end_comment

begin_comment
comment|/*	NOTE, however, that this function returns an INT, not a BYTE!!!  */
end_comment

begin_macro
name|readline
argument_list|(
argument|dseconds
argument_list|)
end_macro

begin_block
block|{
name|int
name|seconds
decl_stmt|;
name|int
name|ret
decl_stmt|,
name|c
decl_stmt|;
name|seconds
operator|=
name|dseconds
operator|/
literal|10
expr_stmt|;
if|if
condition|(
name|seconds
operator|<
literal|2
condition|)
name|seconds
operator|=
literal|2
expr_stmt|;
name|ret
operator|=
name|raw_read
argument_list|(
literal|1
argument_list|,
operator|&
name|c
argument_list|,
name|seconds
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
name|SS$_TIMEOUT
condition|)
return|return
operator|(
name|TIMEOUT
operator|)
return|;
return|return
operator|(
name|c
operator|&
literal|0377
operator|)
return|;
comment|/* return the char */
block|}
end_block

begin_macro
name|purgeline
argument_list|()
end_macro

begin_block
block|{
name|int
name|c
decl_stmt|;
do|do
block|{
name|c
operator|=
name|readline
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|c
operator|!=
name|TIMEOUT
condition|)
do|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BUFWRITE
end_ifdef

begin_decl_stmt
name|char
name|Txlbuf
index|[
name|LSIZE
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Txleft
init|=
name|LSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of characters in Txlbuf */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Txcq
init|=
name|Txlbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer for removing chars from Rxlbuf */
end_comment

begin_macro
name|sendline
argument_list|(
argument|c
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
operator|--
name|Txleft
operator|>=
literal|0
condition|)
operator|*
name|Txcq
operator|++
operator|=
name|c
expr_stmt|;
else|else
block|{
name|Txleft
operator|=
literal|0
expr_stmt|;
name|flushmoc
argument_list|()
expr_stmt|;
operator|--
name|Txleft
expr_stmt|;
operator|*
name|Txcq
operator|++
operator|=
name|c
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|flushmoc
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|n
decl_stmt|;
name|n
operator|=
name|LSIZE
operator|-
name|Txleft
expr_stmt|;
name|Txcq
operator|=
name|Txlbuf
expr_stmt|;
name|Txleft
operator|=
name|LSIZE
expr_stmt|;
name|raw_wbuf
argument_list|(
name|n
argument_list|,
name|Txlbuf
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *  Wait for the modem line outbuffer to drain  */
end_comment

begin_macro
name|flushmo
argument_list|()
end_macro

begin_block
block|{
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|flushmoc
argument_list|()
expr_stmt|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BUFWRITE */
end_comment

begin_comment
comment|/* send a byte to data stream */
end_comment

begin_macro
name|sendline
argument_list|(
argument|data
argument_list|)
end_macro

begin_block
block|{
name|char
name|dataout
decl_stmt|;
name|dataout
operator|=
name|data
expr_stmt|;
name|raw_write
argument_list|(
name|dataout
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|flushmo
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_macro
name|flushmoc
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|sendbrk
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/* End of vrzsz.c */
end_comment

end_unit

