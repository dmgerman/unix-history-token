begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"header.h"
end_include

begin_macro
name|println
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|esc
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%c%s"
argument_list|,
literal|27
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|esc2
argument_list|(
argument|s1
argument_list|,
argument|s2
argument_list|)
end_macro

begin_decl_stmt
name|char
name|s1
decl_stmt|,
name|s2
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%c%s%s"
argument_list|,
literal|27
argument_list|,
name|s1
argument_list|,
name|s2
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|brcstr
argument_list|(
argument|ps
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ps
decl_stmt|,
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%c[%s%c"
argument_list|,
literal|27
argument_list|,
name|ps
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|brc
argument_list|(
argument|pn
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%c[%d%c"
argument_list|,
literal|27
argument_list|,
name|pn
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|brc2
argument_list|(
argument|pn1
argument_list|,
argument|pn2
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn1
decl_stmt|,
name|pn2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%c[%d;%d%c"
argument_list|,
literal|27
argument_list|,
name|pn1
argument_list|,
name|pn2
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cub
argument_list|(
argument|pn
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Cursor Backward */
name|brc
argument_list|(
name|pn
argument_list|,
literal|'D'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cud
argument_list|(
argument|pn
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Cursor Down */
name|brc
argument_list|(
name|pn
argument_list|,
literal|'B'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cuf
argument_list|(
argument|pn
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Cursor Forward */
name|brc
argument_list|(
name|pn
argument_list|,
literal|'C'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cup
argument_list|(
argument|pn1
argument_list|,
argument|pn2
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn1
decl_stmt|,
name|pn2
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Cursor Position */
name|brc2
argument_list|(
name|pn1
argument_list|,
name|pn2
argument_list|,
literal|'H'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cuu
argument_list|(
argument|pn
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Cursor Up */
name|brc
argument_list|(
name|pn
argument_list|,
literal|'A'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|da
argument_list|()
end_macro

begin_block
block|{
comment|/* Device Attributes */
name|brc
argument_list|(
literal|0
argument_list|,
literal|'c'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|decaln
argument_list|()
end_macro

begin_block
block|{
comment|/* Screen Alignment Display */
name|esc
argument_list|(
literal|"#8"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|decdhl
argument_list|(
argument|lower
argument_list|)
end_macro

begin_decl_stmt
name|int
name|lower
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Double Height Line (also double width) */
if|if
condition|(
name|lower
condition|)
name|esc
argument_list|(
literal|"#4"
argument_list|)
expr_stmt|;
else|else
name|esc
argument_list|(
literal|"#3"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|decdwl
argument_list|()
end_macro

begin_block
block|{
comment|/* Double Wide Line */
name|esc
argument_list|(
literal|"#6"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|deckpam
argument_list|()
end_macro

begin_block
block|{
comment|/* Keypad Application Mode */
name|esc
argument_list|(
literal|"="
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|deckpnm
argument_list|()
end_macro

begin_block
block|{
comment|/* Keypad Numeric Mode */
name|esc
argument_list|(
literal|">"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|decll
argument_list|(
argument|ps
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ps
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Load LEDs */
name|brcstr
argument_list|(
name|ps
argument_list|,
literal|'q'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|decrc
argument_list|()
end_macro

begin_block
block|{
comment|/* Restore Cursor */
name|esc
argument_list|(
literal|"8"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|decreqtparm
argument_list|(
argument|pn
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Request Terminal Parameters */
name|brc
argument_list|(
name|pn
argument_list|,
literal|'x'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|decsc
argument_list|()
end_macro

begin_block
block|{
comment|/* Save Cursor */
name|esc
argument_list|(
literal|"7"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|decstbm
argument_list|(
argument|pn1
argument_list|,
argument|pn2
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn1
decl_stmt|,
name|pn2
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Set Top and Bottom Margins */
if|if
condition|(
name|pn1
operator|||
name|pn2
condition|)
name|brc2
argument_list|(
name|pn1
argument_list|,
name|pn2
argument_list|,
literal|'r'
argument_list|)
expr_stmt|;
else|else
name|esc
argument_list|(
literal|"[r"
argument_list|)
expr_stmt|;
comment|/* Good for>24-line terminals */
block|}
end_block

begin_macro
name|decswl
argument_list|()
end_macro

begin_block
block|{
comment|/* Single With Line */
name|esc
argument_list|(
literal|"#5"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|dectst
argument_list|(
argument|pn
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Invoke Confidence Test */
name|brc2
argument_list|(
literal|2
argument_list|,
name|pn
argument_list|,
literal|'y'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|dsr
argument_list|(
argument|pn
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Device Status Report */
name|brc
argument_list|(
name|pn
argument_list|,
literal|'n'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ed
argument_list|(
argument|pn
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Erase in Display */
name|brc
argument_list|(
name|pn
argument_list|,
literal|'J'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|el
argument_list|(
argument|pn
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Erase in Line */
name|brc
argument_list|(
name|pn
argument_list|,
literal|'K'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|hts
argument_list|()
end_macro

begin_block
block|{
comment|/* Horizontal Tabulation Set */
name|esc
argument_list|(
literal|"H"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|hvp
argument_list|(
argument|pn1
argument_list|,
argument|pn2
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn1
decl_stmt|,
name|pn2
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Horizontal and Vertical Position */
name|brc2
argument_list|(
name|pn1
argument_list|,
name|pn2
argument_list|,
literal|'f'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ind
argument_list|()
end_macro

begin_block
block|{
comment|/* Index */
name|esc
argument_list|(
literal|"D"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|nel
argument_list|()
end_macro

begin_block
block|{
comment|/* Next Line */
name|esc
argument_list|(
literal|"E"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ri
argument_list|()
end_macro

begin_block
block|{
comment|/* Reverse Index */
name|esc
argument_list|(
literal|"M"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ris
argument_list|()
end_macro

begin_block
block|{
comment|/*  Reset to Initial State */
name|esc
argument_list|(
literal|"c"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|rm
argument_list|(
argument|ps
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ps
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Reset Mode */
name|brcstr
argument_list|(
name|ps
argument_list|,
literal|'l'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|scs
argument_list|(
argument|g
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|g
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Select character Set */
name|printf
argument_list|(
literal|"%c%c%c%c%c%c%c"
argument_list|,
literal|27
argument_list|,
name|g
condition|?
literal|')'
else|:
literal|'('
argument_list|,
name|c
argument_list|,
literal|27
argument_list|,
name|g
condition|?
literal|'('
else|:
literal|')'
argument_list|,
literal|'B'
argument_list|,
name|g
condition|?
literal|14
else|:
literal|15
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|sgr
argument_list|(
argument|ps
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ps
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Select Graphic Rendition */
name|brcstr
argument_list|(
name|ps
argument_list|,
literal|'m'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|sm
argument_list|(
argument|ps
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ps
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Set Mode */
name|brcstr
argument_list|(
name|ps
argument_list|,
literal|'h'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|tbc
argument_list|(
argument|pn
argument_list|)
end_macro

begin_decl_stmt
name|int
name|pn
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Tabulation Clear */
name|brc
argument_list|(
name|pn
argument_list|,
literal|'g'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|vt52cup
argument_list|(
argument|l
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|l
decl_stmt|,
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%cY%c%c"
argument_list|,
literal|27
argument_list|,
name|l
operator|+
literal|31
argument_list|,
name|c
operator|+
literal|31
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|char
name|inchar
parameter_list|()
block|{
comment|/*    *   Wait until a character is typed on the terminal    *   then read it, without waiting for CR.    */
ifdef|#
directive|ifdef
name|UNIX
name|int
name|lval
decl_stmt|,
name|waittime
decl_stmt|,
name|getpid
argument_list|()
decl_stmt|;
specifier|static
name|int
name|val
decl_stmt|;
name|char
name|ch
decl_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|lval
operator|=
name|val
expr_stmt|;
name|brkrd
operator|=
literal|0
expr_stmt|;
name|reading
operator|=
literal|1
expr_stmt|;
name|read
argument_list|(
literal|0
argument_list|,
operator|&
name|ch
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|reading
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|brkrd
condition|)
name|val
operator|=
literal|0177
expr_stmt|;
else|else
name|val
operator|=
name|ch
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|==
literal|0177
operator|)
operator|&&
operator|(
name|val
operator|==
name|lval
operator|)
condition|)
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
operator|(
name|int
operator|)
name|SIGTERM
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SARG10
name|int
name|val
decl_stmt|,
name|waittime
decl_stmt|;
name|waittime
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|!
name|uuo
argument_list|(
literal|051
argument_list|,
literal|2
argument_list|,
operator|&
name|val
argument_list|)
condition|)
block|{
comment|/* TTCALL 2, (INCHRS)	*/
name|zleep
argument_list|(
literal|100
argument_list|)
expr_stmt|;
comment|/* Wait 0.1 seconds	*/
if|if
condition|(
operator|(
name|waittime
operator|+=
name|ttymode
operator|)
operator|>
literal|600
condition|)
comment|/* Time-out, in case	*/
return|return
operator|(
literal|'\177'
operator|)
return|;
comment|/* of hung in ttybin(1)	*/
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SARG20
comment|/* try to fix a time-out function */
name|int
name|val
decl_stmt|,
name|waittime
decl_stmt|;
name|waittime
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|jsys
argument_list|(
name|SIBE
argument_list|,
literal|2
argument_list|,
name|_PRIIN
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* Is input empty? */
name|zleep
argument_list|(
literal|100
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|waittime
operator|+=
name|ttymode
operator|)
operator|>
literal|600
condition|)
return|return
operator|(
literal|'\177'
operator|)
return|;
block|}
name|ejsys
argument_list|(
name|BIN
argument_list|,
name|_PRIIN
argument_list|)
expr_stmt|;
name|val
operator|=
name|jsac
index|[
literal|2
index|]
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|instr
parameter_list|()
block|{
comment|/*    *   Get an unfinished string from the terminal:    *   wait until a character is typed on the terminal,    *   then read it, and all other available characters.    *   Return a pointer to that string.    */
name|int
name|i
decl_stmt|,
name|val
decl_stmt|,
name|crflag
decl_stmt|;
name|long
name|l1
decl_stmt|;
name|char
name|ch
decl_stmt|;
specifier|static
name|char
name|result
index|[
literal|80
index|]
decl_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
name|result
index|[
name|i
operator|++
index|]
operator|=
name|inchar
argument_list|()
expr_stmt|;
comment|/* Wait 0.1 seconds (1 second in vanilla UNIX) */
ifdef|#
directive|ifdef
name|SARG10
if|if
condition|(
name|trmop
argument_list|(
literal|01031
argument_list|,
literal|0
argument_list|)
operator|<
literal|5
condition|)
name|zleep
argument_list|(
literal|500
argument_list|)
expr_stmt|;
comment|/* wait longer if low speed */
else|else
name|zleep
argument_list|(
literal|100
argument_list|)
expr_stmt|;
else|#
directive|else
name|zleep
argument_list|(
literal|100
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|UNIX
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|XENIX
while|while
condition|(
name|rdchk
argument_list|(
literal|0
argument_list|)
condition|)
block|{
name|read
argument_list|(
literal|0
argument_list|,
name|result
operator|+
name|i
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|++
operator|==
literal|78
condition|)
break|break;
block|}
else|#
directive|else
ifdef|#
directive|ifdef
name|SIII
while|while
condition|(
name|read
argument_list|(
literal|2
argument_list|,
name|result
operator|+
name|i
argument_list|,
literal|1
argument_list|)
operator|==
literal|1
condition|)
if|if
condition|(
name|i
operator|++
operator|==
literal|78
condition|)
break|break;
else|#
directive|else
while|while
condition|(
name|ioctl
argument_list|(
literal|0
argument_list|,
name|FIONREAD
argument_list|,
operator|&
name|l1
argument_list|)
operator|,
name|l1
operator|>
literal|0L
condition|)
block|{
while|while
condition|(
name|l1
operator|--
operator|>
literal|0L
condition|)
block|{
name|read
argument_list|(
literal|0
argument_list|,
name|result
operator|+
name|i
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|++
operator|==
literal|78
condition|)
goto|goto
name|out1
goto|;
block|}
block|}
name|out1
label|:
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SARG10
while|while
condition|(
name|uuo
argument_list|(
literal|051
argument_list|,
literal|2
argument_list|,
operator|&
name|val
argument_list|)
condition|)
block|{
comment|/* TTCALL 2, (INCHRS)  */
if|if
condition|(
operator|!
operator|(
name|val
operator|==
literal|'\012'
operator|&&
name|crflag
operator|)
condition|)
comment|/* TOPS-10 adds LF to CR */
name|result
index|[
name|i
operator|++
index|]
operator|=
name|val
expr_stmt|;
name|crflag
operator|=
name|val
operator|==
literal|'\015'
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|79
condition|)
break|break;
name|zleep
argument_list|(
literal|50
argument_list|)
expr_stmt|;
comment|/* Wait 0.05 seconds */
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SARG20
while|while
condition|(
name|jsys
argument_list|(
name|SIBE
argument_list|,
literal|2
argument_list|,
name|_PRIIN
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* read input until buffer is empty */
name|ejsys
argument_list|(
name|BIN
argument_list|,
name|_PRIIN
argument_list|)
expr_stmt|;
name|result
index|[
name|i
operator|++
index|]
operator|=
name|jsac
index|[
literal|2
index|]
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|79
condition|)
break|break;
name|zleep
argument_list|(
literal|50
argument_list|)
expr_stmt|;
comment|/* Wait 0.05 seconds */
block|}
endif|#
directive|endif
name|result
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_macro
name|ttybin
argument_list|(
argument|bin
argument_list|)
end_macro

begin_decl_stmt
name|int
name|bin
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|SARG10
define|#
directive|define
name|OPEN
value|050
define|#
directive|define
name|IO_MOD
value|0000017
define|#
directive|define
name|_IOPIM
value|2
define|#
directive|define
name|_IOASC
value|0
define|#
directive|define
name|_TOPAG
value|01021
define|#
directive|define
name|_TOSET
value|01000
name|int
name|v
decl_stmt|;
specifier|static
name|int
name|arglst
index|[]
init|=
block|{
name|_IOPIM
block|,
operator|`
name|TTY
operator|`
block|,
literal|0
block|}
decl_stmt|;
name|arglst
index|[
literal|0
index|]
operator|=
name|bin
condition|?
name|_IOPIM
else|:
name|_IOASC
expr_stmt|;
name|v
operator|=
name|uuo
argument_list|(
name|OPEN
argument_list|,
literal|1
argument_list|,
operator|&
name|arglst
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|v
condition|)
block|{
name|printf
argument_list|(
literal|"OPEN failed"
argument_list|)
expr_stmt|;
name|exit
argument_list|()
expr_stmt|;
block|}
name|trmop
argument_list|(
name|_TOPAG
operator|+
name|_TOSET
argument_list|,
name|bin
condition|?
literal|0
else|:
literal|1
argument_list|)
expr_stmt|;
name|ttymode
operator|=
name|bin
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SARG20
comment|/*	TTYBIN will set the line in BINARY/ASCII mode    *	BINARY mode is needed to send control characters    *	Bit 28 must be 0 (we don't flip it).    *	Bit 29 is used for the mode change.    */
define|#
directive|define
name|_TTASC
value|0000100
define|#
directive|define
name|_MOXOF
value|0000043
name|int
name|v
decl_stmt|;
name|ejsys
argument_list|(
name|RFMOD
argument_list|,
name|_CTTRM
argument_list|)
expr_stmt|;
name|v
operator|=
name|ejsys
argument_list|(
name|SFMOD
argument_list|,
name|_CTTRM
argument_list|,
name|bin
condition|?
operator|(
operator|~
name|_TTASC
operator|&
name|jsac
index|[
literal|2
index|]
operator|)
else|:
operator|(
name|_TTASC
operator||
name|jsac
index|[
literal|2
index|]
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|v
condition|)
block|{
name|printf
argument_list|(
literal|"SFMOD failed"
argument_list|)
expr_stmt|;
name|exit
argument_list|()
expr_stmt|;
block|}
name|v
operator|=
name|ejsys
argument_list|(
name|MTOPR
argument_list|,
name|_CTTRM
argument_list|,
name|_MOXOF
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|v
condition|)
block|{
name|printf
argument_list|(
literal|"MTOPR failed"
argument_list|)
expr_stmt|;
name|exit
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|SARG20
end_ifdef

begin_comment
comment|/*  *	SUPERBIN turns off/on all input character interrupts  *	This affects ^C, ^O, ^T  *	Beware where and how you use it !!!!!!!  */
end_comment

begin_macro
name|superbin
argument_list|(
argument|bin
argument_list|)
end_macro

begin_decl_stmt
name|int
name|bin
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|v
decl_stmt|;
name|v
operator|=
name|ejsys
argument_list|(
argument|STIW
argument_list|,
argument|(
literal|0
comment|//-5), bin ? 0 : -1);
argument|if (v) { printf(
literal|"STIW superbinary setting failed"
argument|); exit(); }   ttymode = bin; }
comment|/*  *	PAGE affects the ^S/^Q handshake.  *	Set bit 34 to turn it on. Clear it for off.  */
argument|page(bin) int bin; {   int v;
define|#
directive|define
name|TT_PGM
value|0000002
argument|ejsys(RFMOD,_CTTRM);
comment|/* Get the current terminal status */
argument|v = ejsys(STPAR,_CTTRM, bin ? (TT_PGM | jsac[
literal|2
argument|]) : (~TT_PGM& jsac[
literal|2
argument|]));   if (v) { printf(
literal|"STPAR failed"
argument|); exit(); } }
endif|#
directive|endif
argument|trmop(fc,arg) int fc, arg; {
ifdef|#
directive|ifdef
name|SARG10
argument|int retvalp;   int arglst[
literal|3
argument|];
comment|/* TRMOP is a TOPS-10 monitor call that does things to the terminal. */
comment|/* Find out TTY nbr (PA1050 barfs if TRMOP get -1 instead of udx)    */
comment|/* A TRMNO monitor call returns the udx (Universal Device Index)     */
argument|arglst[
literal|0
argument|] = fc;
comment|/* function code	*/
argument|arglst[
literal|1
argument|] = calli(
literal|0115
argument|, -
literal|1
argument|);
comment|/* udx, TRMNO. UUO	*/
argument|arglst[
literal|2
argument|] = arg;
comment|/* Optional argument	*/
argument|if (calli(
literal|0116
argument|,
literal|3
comment|//&arglst[0],&retvalp))           /* TRMOP. UUO */
argument|return (retvalp);   else {     printf(
literal|"?Error return in TRMOP."
argument|);     exit();   }
endif|#
directive|endif
argument|}  inputline(s) char *s; {   scanf(
literal|"%s"
argument|,s);
ifdef|#
directive|ifdef
name|SARG10
argument|readnl();
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SARG20
argument|readnl();
endif|#
directive|endif
argument|}  inflush() {
comment|/*    *   Flush input buffer, make sure no pending input character    */
argument|int val;
ifdef|#
directive|ifdef
name|UNIX
ifdef|#
directive|ifdef
name|XENIX
argument|while(rdchk(
literal|0
argument|)) read(
literal|0
argument|,&val,
literal|1
argument|);
else|#
directive|else
ifdef|#
directive|ifdef
name|SIII
argument|while(read(
literal|2
argument|,&val,
literal|1
argument|));
else|#
directive|else
argument|long l1;   ioctl (
literal|0
argument|, FIONREAD,&l1);   while(l1-->
literal|0L
argument|) read(
literal|0
argument|,&val,
literal|1
argument|);
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SARG10
argument|while(uuo(
literal|051
argument|,
literal|2
argument|,&val))
comment|/* TTCALL 2, (INCHRS)  */
argument|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SARG20
argument|ejsys(CFIBF,_PRIIN);
comment|/* Clear input buffer */
endif|#
directive|endif
argument|}  zleep(t) int t; {
comment|/*  *    Sleep and do nothing (don't waste CPU) for t milliseconds  */
ifdef|#
directive|ifdef
name|SARG10
argument|calli(
literal|072
argument|,t);
comment|/* (HIBER) t milliseconds */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SARG20
argument|ejsys(DISMS,t);
comment|/* DISMISS for t milliseconds */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|UNIX
argument|t = t /
literal|1000
argument|;   if (t ==
literal|0
argument|) t =
literal|1
argument|;   sleep(t);
comment|/* UNIX can only sleep whole seconds */
endif|#
directive|endif
argument|}
end_block

end_unit

