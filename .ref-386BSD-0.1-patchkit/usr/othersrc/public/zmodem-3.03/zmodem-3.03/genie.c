begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  *  Rev 5-08-89  *  This file contains GEnie specific code for setting terminal modes,  *  very little is specific to ZMODEM or YMODEM per se (that code is in  *  sz.c and rz.c).  The CRC-16 routines used by XMODEM, YMODEM, and ZMODEM  *  are also in this file, a fast table driven macro version  *  *   This file is #included so the main file can set parameters such as HOWMANY.  *   See the main file rz.c for compile instructions.  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_define
define|#
directive|define
name|XARGSFILE
value|"/"
end_define

begin_define
define|#
directive|define
name|XX
end_define

begin_decl_stmt
name|STATIC
name|char
name|Myattn
index|[]
init|=
block|{
literal|0335
block|,
literal|0336
block|,
literal|0336
block|,
literal|0
block|,
literal|24
block|,
literal|24
block|,
literal|24
block|,
literal|24
block|,
literal|24
block|,
literal|24
block|,
literal|24
block|,
literal|24
block|,
literal|24
block|,
literal|24
block|,
literal|13
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ALTCANOFF
value|4
end_define

begin_comment
comment|/* extern unsigned int _fmode = O_BINARY; */
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
block|{
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|cucheck
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_decl_stmt
name|int
name|Twostop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use two stop bits */
end_comment

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
specifier|static
name|did0
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
switch|switch
condition|(
name|n
condition|)
block|{
case|case
literal|2
case|:
comment|/* Un-raw mode used by sz, sb when -g detected */
case|case
literal|1
case|:
case|case
literal|3
case|:
name|did0
operator|=
name|TRUE
expr_stmt|;
name|system
argument_list|(
literal|"set x on"
argument_list|)
expr_stmt|;
name|system
argument_list|(
literal|"set e off"
argument_list|)
expr_stmt|;
name|system
argument_list|(
literal|"set t13,10"
argument_list|)
expr_stmt|;
comment|/* 		system("set b3"); */
name|reset
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|binary
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Assume fd 1 is stdout (not documented in GEnie) */
name|fcntl
argument_list|(
literal|1
argument_list|,
name|F_SETFL
argument_list|,
operator|(
operator|(
name|fcntl
argument_list|(
literal|1
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
operator||
name|O_BINARY
operator|)
operator|&
operator|~
name|O_POST_BREAK
operator|)
argument_list|)
expr_stmt|;
return|return
name|OK
return|;
case|case
literal|0
case|:
if|if
condition|(
operator|!
name|did0
condition|)
return|return
name|ERROR
return|;
return|return
name|OK
return|;
default|default:
return|return
name|ERROR
return|;
block|}
block|}
end_block

begin_macro
name|sendbrk
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/*  * readline(timeout) reads character(s) from file descriptor 0  * timeout is in tenths of seconds  */
end_comment

begin_macro
name|readline
argument_list|(
argument|timeout
argument_list|)
end_macro

begin_block
block|{
specifier|static
name|char
name|byt
index|[
literal|1
index|]
decl_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|read
argument_list|(
literal|0
argument_list|,
name|byt
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
name|byt
index|[
literal|0
index|]
operator|&
literal|0377
operator|)
return|;
block|}
end_block

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
block|}
end_block

begin_macro
name|purgeline
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_comment
comment|/* End of genie.c */
end_comment

end_unit

