begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|fnsv
init|=
literal|"C-Kermit functions, 4C(047) 31 Jul 85"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  C K C F N S  --  System-independent Kermit protocol support functions.  */
end_comment

begin_comment
comment|/*  ...Part 1 (others moved to ckcfn2 to make this module small enough) */
end_comment

begin_comment
comment|/*  Author: Frank da Cruz (SY.FDC@CU20B),  Columbia University Center for Computing Activities, January 1985.  Copyright (C) 1985, Trustees of Columbia University in the City of New York.  Permission is granted to any individual or institution to use, copy, or  redistribute this software so long as it is not sold for profit, provided this  copyright notice is retained.  */
end_comment

begin_comment
comment|/*  System-dependent primitives defined in:     ck?tio.c -- terminal i/o    cx?fio.c -- file i/o, directory structure */
end_comment

begin_include
include|#
directive|include
file|"ckcker.h"
end_include

begin_comment
comment|/* Symbol definitions for Kermit */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_comment
comment|/* Debug formats, typedefs, etc. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Externals from ckcmai.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|spsiz
decl_stmt|,
name|rpsiz
decl_stmt|,
name|timint
decl_stmt|,
name|rtimo
decl_stmt|,
name|npad
decl_stmt|,
name|chklen
decl_stmt|,
name|ebq
decl_stmt|,
name|ebqflg
decl_stmt|,
name|rpt
decl_stmt|,
name|rptq
decl_stmt|,
name|rptflg
decl_stmt|,
name|capas
decl_stmt|,
name|keep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pktnum
decl_stmt|,
name|prvpkt
decl_stmt|,
name|sndtyp
decl_stmt|,
name|bctr
decl_stmt|,
name|bctu
decl_stmt|,
name|size
decl_stmt|,
name|osize
decl_stmt|,
name|maxsize
decl_stmt|,
name|spktl
decl_stmt|,
name|nfils
decl_stmt|,
name|stdouf
decl_stmt|,
name|warn
decl_stmt|,
name|timef
decl_stmt|,
name|spsizf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parity
decl_stmt|,
name|speed
decl_stmt|,
name|turn
decl_stmt|,
name|turnch
decl_stmt|,
name|delay
decl_stmt|,
name|displa
decl_stmt|,
name|pktlog
decl_stmt|,
name|tralog
decl_stmt|,
name|seslog
decl_stmt|,
name|xflg
decl_stmt|,
name|mypadn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|filcnt
decl_stmt|,
name|ffc
decl_stmt|,
name|flci
decl_stmt|,
name|flco
decl_stmt|,
name|tlci
decl_stmt|,
name|tlco
decl_stmt|,
name|tfc
decl_stmt|,
name|tsecs
decl_stmt|,
name|fsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|deblog
decl_stmt|,
name|hcflg
decl_stmt|,
name|binary
decl_stmt|,
name|savmod
decl_stmt|,
name|fncnv
decl_stmt|,
name|local
decl_stmt|,
name|server
decl_stmt|,
name|cxseen
decl_stmt|,
name|czseen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CHAR
name|padch
decl_stmt|,
name|mypadc
decl_stmt|,
name|eol
decl_stmt|,
name|ctlq
decl_stmt|,
name|myctlq
decl_stmt|,
name|sstate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CHAR
name|filnam
index|[]
decl_stmt|,
name|sndpkt
index|[]
decl_stmt|,
name|recpkt
index|[]
decl_stmt|,
name|data
index|[]
decl_stmt|,
name|srvcmd
index|[]
decl_stmt|,
name|stchr
decl_stmt|,
name|mystch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cmarg
decl_stmt|,
modifier|*
name|cmarg2
decl_stmt|,
modifier|*
name|hlptxt
decl_stmt|,
modifier|*
modifier|*
name|cmlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CHAR
modifier|*
name|srvptr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|long
name|zchki
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Variables local to this module */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|memptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer for memory strings */
end_comment

begin_decl_stmt
specifier|static
name|char
name|cmdstr
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Unix system command string */
end_comment

begin_decl_stmt
specifier|static
name|int
name|sndsrc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag for where to send from: */
end_comment

begin_comment
comment|/* -1: name in cmdata */
end_comment

begin_comment
comment|/*  0: stdin          */
end_comment

begin_comment
comment|/*>0: list in cmlist */
end_comment

begin_decl_stmt
specifier|static
name|int
name|memstr
decl_stmt|,
comment|/* Flag for input from memory string */
name|first
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag for first char from input */
end_comment

begin_decl_stmt
specifier|static
name|CHAR
name|t
decl_stmt|,
comment|/* Current character */
name|next
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Next character */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  E N C S T R  --  Encode a string from memory. */
end_comment

begin_comment
comment|/*  Call this instead of getpkt() if source is a string, rather than a file. */
end_comment

begin_macro
name|encstr
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
name|int
name|m
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|m
operator|=
name|memstr
expr_stmt|;
name|p
operator|=
name|memptr
expr_stmt|;
comment|/* Save these. */
name|memptr
operator|=
name|s
expr_stmt|;
comment|/* Point to the string. */
name|memstr
operator|=
literal|1
expr_stmt|;
comment|/* Flag memory string as source. */
name|first
operator|=
literal|1
expr_stmt|;
comment|/* Initialize character lookahead. */
name|getpkt
argument_list|(
name|spsiz
argument_list|)
expr_stmt|;
comment|/* Fill a packet from the string. */
name|memstr
operator|=
name|m
expr_stmt|;
comment|/* Restore memory string flag */
name|memptr
operator|=
name|p
expr_stmt|;
comment|/* and pointer */
name|first
operator|=
literal|1
expr_stmt|;
comment|/* Put this back as we found it. */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* E N C O D E - Kermit packet encoding procedure */
end_comment

begin_macro
name|encode
argument_list|(
argument|a
argument_list|)
end_macro

begin_decl_stmt
name|CHAR
name|a
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* The current character */
name|int
name|a7
decl_stmt|;
comment|/* Low order 7 bits of character */
name|int
name|b8
decl_stmt|;
comment|/* 8th bit of character */
if|if
condition|(
name|rptflg
condition|)
block|{
comment|/* Repeat processing? */
if|if
condition|(
name|a
operator|==
name|next
operator|&&
operator|(
name|first
operator|==
literal|0
operator|)
condition|)
block|{
comment|/* Got a run... */
if|if
condition|(
operator|++
name|rpt
operator|<
literal|94
condition|)
comment|/* Below max, just count */
return|return;
elseif|else
if|if
condition|(
name|rpt
operator|==
literal|94
condition|)
block|{
comment|/* Reached max, must dump */
name|data
index|[
name|size
operator|++
index|]
operator|=
name|rptq
expr_stmt|;
name|data
index|[
name|size
operator|++
index|]
operator|=
name|tochar
argument_list|(
name|rpt
argument_list|)
expr_stmt|;
name|rpt
operator|=
literal|0
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|rpt
operator|==
literal|1
condition|)
block|{
comment|/* Run broken, only 2? */
name|rpt
operator|=
literal|0
expr_stmt|;
comment|/* Yes, reset repeat flag& count. */
name|encode
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* Do the character twice. */
if|if
condition|(
name|size
operator|<=
name|maxsize
condition|)
name|osize
operator|=
name|size
expr_stmt|;
name|rpt
operator|=
literal|0
expr_stmt|;
name|encode
argument_list|(
name|a
argument_list|)
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
name|rpt
operator|>
literal|1
condition|)
block|{
comment|/* More than two */
name|data
index|[
name|size
operator|++
index|]
operator|=
name|rptq
expr_stmt|;
comment|/* Insert the repeat prefix */
name|data
index|[
name|size
operator|++
index|]
operator|=
name|tochar
argument_list|(
operator|++
name|rpt
argument_list|)
expr_stmt|;
comment|/* and count. */
name|rpt
operator|=
literal|0
expr_stmt|;
comment|/* Reset repeat counter. */
block|}
block|}
name|a7
operator|=
name|a
operator|&
literal|0177
expr_stmt|;
comment|/* Isolate ASCII part */
name|b8
operator|=
name|a
operator|&
literal|0200
expr_stmt|;
comment|/* and 8th (parity) bit. */
if|if
condition|(
name|ebqflg
operator|&&
name|b8
condition|)
block|{
comment|/* Do 8th bit prefix if necessary. */
name|data
index|[
name|size
operator|++
index|]
operator|=
name|ebq
expr_stmt|;
name|a
operator|=
name|a7
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|a7
operator|<
name|SP
operator|)
operator|||
operator|(
name|a7
operator|==
name|DEL
operator|)
condition|)
block|{
comment|/* Do control prefix if necessary */
name|data
index|[
name|size
operator|++
index|]
operator|=
name|myctlq
expr_stmt|;
name|a
operator|=
name|ctl
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|a7
operator|==
name|myctlq
condition|)
comment|/* Prefix the control prefix */
name|data
index|[
name|size
operator|++
index|]
operator|=
name|myctlq
expr_stmt|;
if|if
condition|(
operator|(
name|rptflg
operator|)
operator|&&
operator|(
name|a7
operator|==
name|rptq
operator|)
condition|)
comment|/* If it's the repeat prefix, */
name|data
index|[
name|size
operator|++
index|]
operator|=
name|myctlq
expr_stmt|;
comment|/* quote it if doing repeat counts. */
if|if
condition|(
operator|(
name|ebqflg
operator|)
operator|&&
operator|(
name|a7
operator|==
name|ebq
operator|)
condition|)
comment|/* Prefix the 8th bit prefix */
name|data
index|[
name|size
operator|++
index|]
operator|=
name|myctlq
expr_stmt|;
comment|/* if doing 8th-bit prefixes */
name|data
index|[
name|size
operator|++
index|]
operator|=
name|a
expr_stmt|;
comment|/* Finally, insert the character */
name|data
index|[
name|size
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* itself, and mark the end. */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* D E C O D E  --  Kermit packet decoding procedure */
end_comment

begin_comment
comment|/* Call with string to be decoded and an output function. */
end_comment

begin_comment
comment|/* Returns 0 on success, -1 on failure (e.g. disk full).  */
end_comment

begin_macro
name|decode
argument_list|(
argument|buf
argument_list|,
argument|fn
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{
name|unsigned
name|int
name|a
decl_stmt|,
name|a7
decl_stmt|,
name|b8
decl_stmt|;
comment|/* Low order 7 bits, and the 8th bit */
name|rpt
operator|=
literal|0
expr_stmt|;
comment|/* Initialize repeat count. */
while|while
condition|(
operator|(
name|a
operator|=
operator|*
name|buf
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
block|{
if|if
condition|(
name|rptflg
condition|)
block|{
comment|/* Repeat processing? */
if|if
condition|(
name|a
operator|==
name|rptq
condition|)
block|{
comment|/* Yes, got a repeat prefix? */
name|rpt
operator|=
name|unchar
argument_list|(
operator|*
name|buf
operator|++
argument_list|)
expr_stmt|;
comment|/* Yes, get the repeat count, */
name|a
operator|=
operator|*
name|buf
operator|++
expr_stmt|;
comment|/* and get the prefixed character. */
block|}
block|}
name|b8
operator|=
literal|0
expr_stmt|;
comment|/* Check high order "8th" bit */
if|if
condition|(
name|ebqflg
condition|)
block|{
comment|/* 8th-bit prefixing? */
if|if
condition|(
name|a
operator|==
name|ebq
condition|)
block|{
comment|/* Yes, got an 8th-bit prefix? */
name|b8
operator|=
literal|0200
expr_stmt|;
comment|/* Yes, remember this, */
name|a
operator|=
operator|*
name|buf
operator|++
expr_stmt|;
comment|/* and get the prefixed character. */
block|}
block|}
if|if
condition|(
name|a
operator|==
name|ctlq
condition|)
block|{
comment|/* If control prefix, */
name|a
operator|=
operator|*
name|buf
operator|++
expr_stmt|;
comment|/* get its operand. */
name|a7
operator|=
name|a
operator|&
literal|0177
expr_stmt|;
comment|/* Only look at low 7 bits. */
if|if
condition|(
operator|(
name|a7
operator|>=
literal|0100
operator|&&
name|a7
operator|<=
literal|0137
operator|)
operator|||
name|a7
operator|==
literal|'?'
condition|)
comment|/* Uncontrollify */
name|a
operator|=
name|ctl
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* if in control range. */
block|}
name|a
operator||=
name|b8
expr_stmt|;
comment|/* OR in the 8th bit */
if|if
condition|(
name|rpt
operator|==
literal|0
condition|)
name|rpt
operator|=
literal|1
expr_stmt|;
comment|/* If no repeats, then one */
ifdef|#
directive|ifdef
name|NLCHAR
if|if
condition|(
operator|!
name|binary
condition|)
block|{
comment|/* If in text mode, */
if|if
condition|(
name|a
operator|==
name|CR
condition|)
continue|continue;
comment|/* discard carriage returns, */
if|if
condition|(
name|a
operator|==
name|LF
condition|)
name|a
operator|=
name|NLCHAR
expr_stmt|;
comment|/* convert LF to system's newline. */
block|}
endif|#
directive|endif
for|for
control|(
init|;
name|rpt
operator|>
literal|0
condition|;
name|rpt
operator|--
control|)
block|{
comment|/* Output the char RPT times */
name|ffc
operator|++
operator|,
name|tfc
operator|++
expr_stmt|;
comment|/* Count the character */
if|if
condition|(
call|(
modifier|*
name|fn
call|)
argument_list|(
name|a
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Send it to the output function. */
block|}
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  Output functions passed to 'decode':  */
end_comment

begin_macro
name|putsrv
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/*  Put character in server command buffer  */
operator|*
name|srvptr
operator|++
operator|=
name|c
expr_stmt|;
operator|*
name|srvptr
operator|=
literal|'\0'
expr_stmt|;
comment|/* Make sure buffer is null-terminated */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|puttrm
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/*  Output character to console.  */
name|conoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|putfil
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/*  Output char to file. */
if|if
condition|(
name|zchout
argument_list|(
name|ZOFILE
argument_list|,
name|c
argument_list|)
operator|<
literal|0
condition|)
block|{
name|czseen
operator|=
literal|1
expr_stmt|;
comment|/* If write error... */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"putfil zchout write error, setting czseen"
argument_list|,
literal|""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  G E T P K T -- Fill a packet data field  */
end_comment

begin_comment
comment|/*  Gets characters from the current source -- file or memory string.  Encodes the data into the packet, filling the packet optimally.  Set first = 1 when calling for the first time on a given input stream  (string or file).   Uses global variables:  t     -- current character.  first -- flag: 1 to start up, 0 for input in progress, -1 for EOF.  next  -- next character.  data  -- the packet data buffer.  size  -- number of characters in the data buffer.  Returns the size as value of the function, and also sets global size, and fills (and null-terminates) the global data array.  Returns 0 upon eof. */
end_comment

begin_macro
name|getpkt
argument_list|(
argument|maxsize
argument_list|)
end_macro

begin_decl_stmt
name|int
name|maxsize
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Fill one packet buffer */
name|int
name|i
decl_stmt|,
name|x
decl_stmt|;
comment|/* Loop index. */
specifier|static
name|char
name|leftover
index|[
literal|6
index|]
init|=
block|{
literal|'\0'
block|,
literal|'\0'
block|,
literal|'\0'
block|,
literal|'\0'
block|,
literal|'\0'
block|,
literal|'\0'
block|}
decl_stmt|;
if|if
condition|(
name|first
operator|==
literal|1
condition|)
block|{
comment|/* If first time thru...  */
name|first
operator|=
literal|0
expr_stmt|;
comment|/* remember, */
operator|*
name|leftover
operator|=
literal|'\0'
expr_stmt|;
comment|/* discard any interrupted leftovers, */
name|x
operator|=
name|getchx
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
comment|/* get first character of file into t, */
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{
comment|/* watching out for null file, */
name|first
operator|=
literal|1
expr_stmt|;
return|return
operator|(
name|size
operator|=
literal|0
operator|)
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|first
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* EOF from last time? */
name|first
operator|=
literal|1
expr_stmt|;
comment|/* Setup for next time. */
return|return
operator|(
name|size
operator|=
literal|0
operator|)
return|;
block|}
else|else
name|x
operator|=
literal|1
expr_stmt|;
comment|/* Do any leftovers */
for|for
control|(
name|size
operator|=
literal|0
init|;
operator|(
name|data
index|[
name|size
index|]
operator|=
name|leftover
index|[
name|size
index|]
operator|)
operator|!=
literal|'\0'
condition|;
name|size
operator|++
control|)
empty_stmt|;
operator|*
name|leftover
operator|=
literal|'\0'
expr_stmt|;
comment|/* Now fill up the rest of the packet. */
name|rpt
operator|=
literal|0
expr_stmt|;
comment|/* Clear out any old repeat count. */
while|while
condition|(
name|x
operator|>
literal|0
condition|)
block|{
comment|/* Until EOF... */
name|x
operator|=
name|getchx
argument_list|(
operator|&
name|next
argument_list|)
expr_stmt|;
comment|/* Get next character for lookahead. */
if|if
condition|(
name|x
operator|==
literal|0
condition|)
name|first
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Flag eof for next time. */
name|osize
operator|=
name|size
expr_stmt|;
comment|/* Remember current position. */
name|encode
argument_list|(
name|t
argument_list|)
expr_stmt|;
comment|/* Encode the current character. */
name|t
operator|=
name|next
expr_stmt|;
comment|/* Next is now current. */
if|if
condition|(
name|size
operator|==
name|maxsize
condition|)
block|{
comment|/* If the packet is exactly full, */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getpkt exact fit"
argument_list|,
literal|""
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
name|size
operator|)
return|;
comment|/* ... return. */
block|}
if|if
condition|(
name|size
operator|>
name|maxsize
condition|)
block|{
comment|/* If too big, save some for next. */
for|for
control|(
name|i
operator|=
literal|0
init|;
operator|(
name|leftover
index|[
name|i
index|]
operator|=
name|data
index|[
name|osize
operator|+
name|i
index|]
operator|)
operator|!=
literal|'\0'
condition|;
name|i
operator|++
control|)
empty_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"getpkt leftover"
argument_list|,
name|leftover
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" osize"
argument_list|,
literal|""
argument_list|,
name|osize
argument_list|)
expr_stmt|;
name|size
operator|=
name|osize
expr_stmt|;
comment|/* Return truncated packet. */
name|data
index|[
name|size
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|size
operator|)
return|;
block|}
block|}
comment|/* Otherwise, keep filling. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"getpkt eof/eot"
argument_list|,
name|data
argument_list|,
name|size
argument_list|)
expr_stmt|;
comment|/* Fell thru before packet full, */
return|return
operator|(
name|size
operator|)
return|;
comment|/* return partially filled last packet. */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  G E T C H X  --  Get the next character from file (or pipe). */
end_comment

begin_comment
comment|/*  On systems like Unix, the Macintosh, etc, that use a single character  (NLCHAR, defined in ckcdeb.h) to separate lines in text files, and  when in text/ascii mode (binary == 0), this function maps the newline  character to CRLF.  If NLCHAR is not defined, then this mapping is  not done, even in text mode.   Returns 1 on success with ch set to the character, or 0 on failure (EOF) */
end_comment

begin_macro
name|getchx
argument_list|(
argument|ch
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ch
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Get next character */
name|int
name|x
decl_stmt|;
name|CHAR
name|a
decl_stmt|;
comment|/* The character to return. */
specifier|static
name|int
name|b
init|=
literal|0
decl_stmt|;
comment|/* A character to remember. */
if|if
condition|(
name|b
operator|>
literal|0
condition|)
block|{
comment|/* Do we have a LF saved? */
name|b
operator|=
literal|0
expr_stmt|;
comment|/* Yes, return that. */
operator|*
name|ch
operator|=
name|LF
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|memstr
condition|)
comment|/* Try to get the next character */
name|x
operator|=
operator|(
operator|(
name|a
operator|=
operator|*
name|memptr
operator|++
operator|)
operator|==
literal|'\0'
operator|)
expr_stmt|;
comment|/* from the appropriate source, */
else|else
comment|/* memory or the current file. */
name|x
operator|=
operator|(
name|zchin
argument_list|(
name|ZIFILE
argument_list|,
operator|&
name|a
argument_list|)
operator|==
operator|-
literal|1
operator|)
expr_stmt|;
if|if
condition|(
name|x
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* No more, return 0 for EOF. */
else|else
block|{
comment|/* Otherwise, read the next char. */
name|ffc
operator|++
operator|,
name|tfc
operator|++
expr_stmt|;
comment|/* Count it. */
ifdef|#
directive|ifdef
name|NLCHAR
if|if
condition|(
operator|!
name|binary
operator|&&
operator|(
name|a
operator|==
name|NLCHAR
operator|)
condition|)
block|{
comment|/* If nl and we must do nl-CRLF */
name|b
operator|=
literal|1
expr_stmt|;
comment|/* mapping, remember a linefeed, */
operator|*
name|ch
operator|=
name|CR
expr_stmt|;
comment|/* and return a carriage return. */
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
block|{
operator|*
name|ch
operator|=
name|a
expr_stmt|;
comment|/*  General case, return the char. */
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|#
directive|else
operator|*
name|ch
operator|=
name|a
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
block|}
block|}
end_block

begin_comment
comment|/*  C A N N E D  --  Check if current file transfer cancelled */
end_comment

begin_macro
name|canned
argument_list|(
argument|buf
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|*
name|buf
operator|==
literal|'X'
condition|)
name|cxseen
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|*
name|buf
operator|==
literal|'Z'
condition|)
name|czseen
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"canned: cxseen"
argument_list|,
literal|""
argument_list|,
name|cxseen
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" czseen"
argument_list|,
literal|""
argument_list|,
name|czseen
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|czseen
operator|||
name|cxseen
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  T I N I T  --  Initialize a transaction  */
end_comment

begin_macro
name|tinit
argument_list|()
end_macro

begin_block
block|{
name|xflg
operator|=
literal|0
expr_stmt|;
comment|/* Reset x-packet flag */
name|memstr
operator|=
literal|0
expr_stmt|;
comment|/* Reset memory-string flag */
name|memptr
operator|=
name|NULL
expr_stmt|;
comment|/*  and pointer */
name|bctu
operator|=
literal|1
expr_stmt|;
comment|/* Reset block check type to 1 */
name|ebq
operator|=
name|ebqflg
operator|=
literal|0
expr_stmt|;
comment|/* Reset 8th-bit quoting stuff */
if|if
condition|(
name|savmod
condition|)
block|{
comment|/* If binary file mode was saved, */
name|binary
operator|=
literal|1
expr_stmt|;
comment|/*  restore it, */
name|savmod
operator|=
literal|0
expr_stmt|;
comment|/*  unsave it. */
block|}
name|filcnt
operator|=
literal|0
expr_stmt|;
comment|/* Reset file counter */
name|tfc
operator|=
name|tlci
operator|=
name|tlco
operator|=
literal|0
expr_stmt|;
comment|/* Reset character counters */
name|prvpkt
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Reset packet number */
name|pktnum
operator|=
literal|0
expr_stmt|;
name|cxseen
operator|=
name|czseen
operator|=
literal|0
expr_stmt|;
comment|/* Reset interrupt flags */
operator|*
name|filnam
operator|=
literal|'\0'
expr_stmt|;
comment|/* Clear file name */
if|if
condition|(
name|server
condition|)
block|{
comment|/* If acting as server, */
name|timint
operator|=
literal|30
expr_stmt|;
comment|/* Use 30 second timeout, */
name|nack
argument_list|()
expr_stmt|;
comment|/* Send first NAK */
block|}
block|}
end_block

begin_comment
comment|/*  R I N I T  --  Respond to S packet  */
end_comment

begin_macro
name|rinit
argument_list|(
argument|d
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|d
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|tp
decl_stmt|;
name|ztime
argument_list|(
operator|&
name|tp
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Transaction begins"
argument_list|,
name|tp
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
comment|/* Make transaction log entry */
name|tfc
operator|=
name|tlci
operator|=
name|tlco
operator|=
literal|0
expr_stmt|;
name|spar
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|rpar
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|ack1
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  S I N I T  --  Make sure file exists, then send Send-Init packet */
end_comment

begin_macro
name|sinit
argument_list|()
end_macro

begin_block
block|{
name|int
name|x
decl_stmt|;
name|char
modifier|*
name|tp
decl_stmt|;
name|sndsrc
operator|=
name|nfils
expr_stmt|;
comment|/* Where to look for files to send */
name|ztime
argument_list|(
operator|&
name|tp
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Transaction begins"
argument_list|,
name|tp
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
comment|/* Make transaction log entry */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sinit: sndsrc"
argument_list|,
literal|""
argument_list|,
name|sndsrc
argument_list|)
expr_stmt|;
if|if
condition|(
name|sndsrc
operator|<
literal|0
condition|)
block|{
comment|/* Must expand from 'send' command */
name|nfils
operator|=
name|zxpand
argument_list|(
name|cmarg
argument_list|)
expr_stmt|;
comment|/* Look up literal name. */
if|if
condition|(
name|nfils
operator|<
literal|0
condition|)
block|{
name|screen
argument_list|(
name|SCR_EM
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"Too many files"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|nfils
operator|==
literal|0
condition|)
block|{
comment|/* If none found, */
name|char
name|xname
index|[
literal|100
index|]
decl_stmt|;
comment|/* convert the name. */
name|zrtol
argument_list|(
name|cmarg
argument_list|,
name|xname
argument_list|)
expr_stmt|;
name|nfils
operator|=
name|zxpand
argument_list|(
name|xname
argument_list|)
expr_stmt|;
comment|/* Look it up again. */
block|}
if|if
condition|(
name|nfils
operator|<
literal|1
condition|)
block|{
comment|/* If no match, report error. */
if|if
condition|(
name|server
condition|)
name|errpkt
argument_list|(
literal|"File not found"
argument_list|)
expr_stmt|;
else|else
name|screen
argument_list|(
name|SCR_EM
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"File not found"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|x
operator|=
name|gnfile
argument_list|()
expr_stmt|;
comment|/* Position to first file. */
if|if
condition|(
name|x
operator|<
literal|1
condition|)
block|{
if|if
condition|(
operator|!
name|server
condition|)
name|screen
argument_list|(
name|SCR_EM
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"No readable file to send"
argument_list|)
expr_stmt|;
else|else
name|errpkt
argument_list|(
literal|"No readable file to send"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|sndsrc
operator|>
literal|0
condition|)
block|{
comment|/* Command line arglist -- */
name|x
operator|=
name|gnfile
argument_list|()
expr_stmt|;
comment|/* Get the first file from it. */
if|if
condition|(
name|x
operator|<
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* (if any) */
block|}
elseif|else
if|if
condition|(
name|sndsrc
operator|==
literal|0
condition|)
block|{
comment|/* stdin or memory always exist... */
if|if
condition|(
operator|(
name|cmarg2
operator|!=
name|NULL
operator|)
operator|&&
operator|(
operator|*
name|cmarg2
operator|)
condition|)
block|{
name|strcpy
argument_list|(
name|filnam
argument_list|,
name|cmarg2
argument_list|)
expr_stmt|;
comment|/* If F packet, "as" name is used */
name|cmarg2
operator|=
literal|""
expr_stmt|;
comment|/* if provided, */
block|}
else|else
comment|/* otherwise */
name|strcpy
argument_list|(
name|filnam
argument_list|,
literal|"stdin"
argument_list|)
expr_stmt|;
comment|/* just use this. */
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sinit: nfils"
argument_list|,
literal|""
argument_list|,
name|nfils
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|" filnam"
argument_list|,
name|filnam
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|" cmdstr"
argument_list|,
name|cmdstr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ttflui
argument_list|()
expr_stmt|;
comment|/* Flush input buffer. */
if|if
condition|(
operator|!
name|local
operator|&&
operator|!
name|server
condition|)
name|sleep
argument_list|(
name|delay
argument_list|)
expr_stmt|;
name|sipkt
argument_list|(
literal|'S'
argument_list|)
expr_stmt|;
comment|/* Send the Send-Init packet. */
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_macro
name|sipkt
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Send S or I packet. */
name|int
name|x
decl_stmt|;
name|ttflui
argument_list|()
expr_stmt|;
comment|/* Flush pending input. */
name|x
operator|=
name|rpar
argument_list|(
name|data
argument_list|)
expr_stmt|;
comment|/* Send an I-Packet. */
name|spack
argument_list|(
name|c
argument_list|,
name|pktnum
argument_list|,
name|x
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  R C V F I L -- Receive a file  */
end_comment

begin_macro
name|rcvfil
argument_list|()
end_macro

begin_block
block|{
name|int
name|x
decl_stmt|;
name|ffc
operator|=
name|flci
operator|=
name|flco
operator|=
literal|0
expr_stmt|;
comment|/* Init per-file counters */
name|srvptr
operator|=
name|srvcmd
expr_stmt|;
comment|/* Decode file name from packet. */
name|decode
argument_list|(
name|data
argument_list|,
name|putsrv
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|srvcmd
operator|==
literal|'\0'
condition|)
comment|/* Watch out for null F packet. */
name|strcpy
argument_list|(
name|srvcmd
argument_list|,
literal|"NONAME"
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_FN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
name|srvcmd
argument_list|)
expr_stmt|;
comment|/* Put it on screen */
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Receiving"
argument_list|,
name|srvcmd
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
comment|/* Transaction log entry */
if|if
condition|(
name|cmarg2
operator|!=
name|NULL
condition|)
block|{
comment|/* Check for alternate name */
if|if
condition|(
operator|*
name|cmarg2
operator|!=
literal|'\0'
condition|)
block|{
name|strcpy
argument_list|(
name|srvcmd
argument_list|,
name|cmarg2
argument_list|)
expr_stmt|;
comment|/* Got one, use it. */
operator|*
name|cmarg2
operator|=
literal|'\0'
expr_stmt|;
block|}
block|}
name|x
operator|=
name|openo
argument_list|(
name|srvcmd
argument_list|,
name|filnam
argument_list|)
expr_stmt|;
comment|/* Try to open it */
if|if
condition|(
name|x
condition|)
block|{
name|tlog
argument_list|(
name|F110
argument_list|,
literal|" as"
argument_list|,
name|filnam
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_AN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
name|filnam
argument_list|)
expr_stmt|;
name|intmsg
argument_list|(
operator|++
name|filcnt
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Failure to open"
argument_list|,
name|filnam
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_EM
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"Can't open file"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|x
operator|)
return|;
comment|/* Pass on return code from openo */
block|}
end_block

begin_comment
comment|/*  R E O F  --  Receive End Of File  */
end_comment

begin_macro
name|reof
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|cxseen
operator|==
literal|0
condition|)
name|cxseen
operator|=
operator|(
operator|*
name|data
operator|==
literal|'D'
operator|)
expr_stmt|;
comment|/* Got discard directive? */
name|clsof
argument_list|(
name|cxseen
operator||
name|czseen
argument_list|)
expr_stmt|;
if|if
condition|(
name|cxseen
operator|||
name|czseen
condition|)
block|{
name|tlog
argument_list|(
name|F100
argument_list|,
literal|" *** Discarding"
argument_list|,
literal|""
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
block|}
else|else
name|fstats
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  R E O T  --  Receive End Of Transaction  */
end_comment

begin_macro
name|reot
argument_list|()
end_macro

begin_block
block|{
name|cxseen
operator|=
name|czseen
operator|=
literal|0
expr_stmt|;
comment|/* Reset interruption flags */
name|tstats
argument_list|()
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  S F I L E -- Send File header or teXt header packet  */
end_comment

begin_comment
comment|/*  Call with x nonzero for X packet, zero for F packet  */
end_comment

begin_comment
comment|/*  Returns 1 on success, 0 on failure                   */
end_comment

begin_macro
name|sfile
argument_list|(
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|pktnam
index|[
literal|100
index|]
decl_stmt|;
comment|/* Local copy of name */
name|char
modifier|*
name|s
decl_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{
comment|/* F-Packet setup */
if|if
condition|(
operator|*
name|cmarg2
operator|!=
literal|'\0'
condition|)
block|{
comment|/* If we have a send-as name, */
name|strcpy
argument_list|(
name|pktnam
argument_list|,
name|cmarg2
argument_list|)
expr_stmt|;
comment|/* copy it literally, */
name|cmarg2
operator|=
literal|""
expr_stmt|;
comment|/* and blank it out for next time. */
block|}
else|else
block|{
comment|/* Otherwise use actual file name: */
if|if
condition|(
name|fncnv
condition|)
block|{
comment|/* If converting names, */
name|zltor
argument_list|(
name|filnam
argument_list|,
name|pktnam
argument_list|)
expr_stmt|;
comment|/* convert it to common form, */
block|}
else|else
block|{
comment|/* otherwise, */
name|strcpy
argument_list|(
name|pktnam
argument_list|,
name|filnam
argument_list|)
expr_stmt|;
comment|/* copy it literally. */
block|}
block|}
name|debug
argument_list|(
name|F110
argument_list|,
literal|"sfile"
argument_list|,
name|filnam
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Log debugging info */
name|debug
argument_list|(
name|F110
argument_list|,
literal|" pktnam"
argument_list|,
name|pktnam
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|openi
argument_list|(
name|filnam
argument_list|)
operator|==
literal|0
condition|)
comment|/* Try to open the file */
return|return
operator|(
literal|0
operator|)
return|;
name|s
operator|=
name|pktnam
expr_stmt|;
comment|/* Name for packet data field */
block|}
else|else
block|{
comment|/* X-packet setup */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"sxpack"
argument_list|,
name|cmdstr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Log debugging info */
name|s
operator|=
name|cmdstr
expr_stmt|;
comment|/* Name for data field */
block|}
name|flci
operator|=
name|flco
operator|=
name|ffc
operator|=
literal|0
expr_stmt|;
comment|/* Init counters, etc. */
name|encstr
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* Encode the name into data[]. */
name|nxtpkt
argument_list|(
operator|&
name|pktnum
argument_list|)
expr_stmt|;
comment|/* Increment the packet number */
name|spack
argument_list|(
name|x
condition|?
literal|'X'
else|:
literal|'F'
argument_list|,
name|pktnum
argument_list|,
name|size
argument_list|,
name|data
argument_list|)
expr_stmt|;
comment|/* Send the F or X packet */
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{
comment|/* Display for F packet */
if|if
condition|(
name|displa
condition|)
block|{
comment|/* Screen */
name|screen
argument_list|(
name|SCR_FN
argument_list|,
literal|'F'
argument_list|,
operator|(
name|long
operator|)
name|pktnum
argument_list|,
name|filnam
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_AN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
name|pktnam
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_FS
argument_list|,
literal|0
argument_list|,
operator|(
name|long
operator|)
name|fsize
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Sending"
argument_list|,
name|filnam
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
comment|/* Transaction log entry */
name|tlog
argument_list|(
name|F110
argument_list|,
literal|" as"
argument_list|,
name|pktnam
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Display for X-packet */
name|screen
argument_list|(
name|SCR_XD
argument_list|,
literal|'X'
argument_list|,
operator|(
name|long
operator|)
name|pktnum
argument_list|,
name|cmdstr
argument_list|)
expr_stmt|;
comment|/* Screen */
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Sending from:"
argument_list|,
name|cmdstr
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
comment|/* Transaction log */
block|}
name|intmsg
argument_list|(
operator|++
name|filcnt
argument_list|)
expr_stmt|;
comment|/* Count file, give interrupt msg */
name|first
operator|=
literal|1
expr_stmt|;
comment|/* Init file character lookahead. */
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  S D A T A -- Send a data packet */
end_comment

begin_comment
comment|/*  Return -1 if no data to send, else send packet and return length  */
end_comment

begin_macro
name|sdata
argument_list|()
end_macro

begin_block
block|{
name|int
name|len
decl_stmt|;
if|if
condition|(
name|cxseen
operator|||
name|czseen
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* If interrupted, done. */
if|if
condition|(
operator|(
name|len
operator|=
name|getpkt
argument_list|(
name|spsiz
operator|-
name|chklen
operator|-
literal|3
argument_list|)
operator|)
operator|==
literal|0
condition|)
comment|/* Done if no data. */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|nxtpkt
argument_list|(
operator|&
name|pktnum
argument_list|)
expr_stmt|;
comment|/* Increment the packet number */
name|spack
argument_list|(
literal|'D'
argument_list|,
name|pktnum
argument_list|,
name|len
argument_list|,
name|data
argument_list|)
expr_stmt|;
comment|/* Send the packet */
return|return
operator|(
name|len
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  S E O F -- Send an End-Of-File packet */
end_comment

begin_comment
comment|/*  Call with a string pointer to character to put in the data field, */
end_comment

begin_comment
comment|/*  or else a null pointer or "" for no data.  */
end_comment

begin_macro
name|seof
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
name|nxtpkt
argument_list|(
operator|&
name|pktnum
argument_list|)
expr_stmt|;
comment|/* Increment the packet number */
if|if
condition|(
operator|(
name|s
operator|!=
name|NULL
operator|)
operator|&&
operator|(
operator|*
name|s
operator|!=
literal|'\0'
operator|)
condition|)
block|{
name|spack
argument_list|(
literal|'Z'
argument_list|,
name|pktnum
argument_list|,
literal|1
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F100
argument_list|,
literal|" *** interrupted, sending discard request"
argument_list|,
literal|""
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|spack
argument_list|(
literal|'Z'
argument_list|,
name|pktnum
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|fstats
argument_list|()
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  S E O T -- Send an End-Of-Transaction packet */
end_comment

begin_macro
name|seot
argument_list|()
end_macro

begin_block
block|{
name|nxtpkt
argument_list|(
operator|&
name|pktnum
argument_list|)
expr_stmt|;
comment|/* Increment the packet number */
name|spack
argument_list|(
literal|'B'
argument_list|,
name|pktnum
argument_list|,
literal|0
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|/* Send the EOT packet */
name|cxseen
operator|=
name|czseen
operator|=
literal|0
expr_stmt|;
comment|/* Reset interruption flags */
name|tstats
argument_list|()
expr_stmt|;
comment|/* Log timing info */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  F S T A T S  --  Record file statistics in transaction log  */
end_comment

begin_macro
name|fstats
argument_list|()
end_macro

begin_block
block|{
name|tlog
argument_list|(
name|F100
argument_list|,
literal|" end of file"
argument_list|,
literal|""
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F101
argument_list|,
literal|"  file characters        "
argument_list|,
literal|""
argument_list|,
name|ffc
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F101
argument_list|,
literal|"  communication line in  "
argument_list|,
literal|""
argument_list|,
name|flci
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F101
argument_list|,
literal|"  communication line out "
argument_list|,
literal|""
argument_list|,
name|flco
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  T S T A T S  --  Record statistics in transaction log  */
end_comment

begin_macro
name|tstats
argument_list|()
end_macro

begin_block
block|{
name|char
modifier|*
name|tp
decl_stmt|;
name|int
name|x
decl_stmt|;
name|ztime
argument_list|(
operator|&
name|tp
argument_list|)
expr_stmt|;
comment|/* Get time stamp */
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"End of transaction"
argument_list|,
name|tp
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
comment|/* Record it */
if|if
condition|(
name|filcnt
operator|<
literal|1
condition|)
return|return;
comment|/* If no files, done. */
comment|/* If multiple files, record character totals for all files */
if|if
condition|(
name|filcnt
operator|>
literal|1
condition|)
block|{
name|tlog
argument_list|(
name|F101
argument_list|,
literal|" files"
argument_list|,
literal|""
argument_list|,
name|filcnt
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F101
argument_list|,
literal|" total file characters   "
argument_list|,
literal|""
argument_list|,
name|tfc
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F101
argument_list|,
literal|" communication line in   "
argument_list|,
literal|""
argument_list|,
name|tlci
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F101
argument_list|,
literal|" communication line out  "
argument_list|,
literal|""
argument_list|,
name|tlco
argument_list|)
expr_stmt|;
block|}
comment|/* Record timing info for one or more files */
name|tlog
argument_list|(
name|F101
argument_list|,
literal|" elapsed time (seconds)  "
argument_list|,
literal|""
argument_list|,
name|tsecs
argument_list|)
expr_stmt|;
if|if
condition|(
name|tsecs
operator|>
literal|0
condition|)
block|{
name|x
operator|=
operator|(
name|tfc
operator|/
name|tsecs
operator|)
operator|*
literal|10
expr_stmt|;
name|tlog
argument_list|(
name|F101
argument_list|,
literal|" effective baud rate     "
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|speed
operator|>
literal|0
condition|)
block|{
name|x
operator|=
operator|(
name|x
operator|*
literal|100
operator|)
operator|/
name|speed
expr_stmt|;
name|tlog
argument_list|(
name|F101
argument_list|,
literal|" efficiency (percent)    "
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
block|}
name|tlog
argument_list|(
name|F100
argument_list|,
literal|""
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Leave a blank line */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*   R P A R -- Fill the data array with my send-init parameters  */
end_comment

begin_macro
name|rpar
argument_list|(
argument|data
argument_list|)
end_macro

begin_decl_stmt
name|char
name|data
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|data
index|[
literal|0
index|]
operator|=
name|tochar
argument_list|(
name|rpsiz
argument_list|)
expr_stmt|;
comment|/* Biggest packet I can receive */
name|data
index|[
literal|1
index|]
operator|=
name|tochar
argument_list|(
name|rtimo
argument_list|)
expr_stmt|;
comment|/* When I want to be timed out */
name|data
index|[
literal|2
index|]
operator|=
name|tochar
argument_list|(
name|mypadn
argument_list|)
expr_stmt|;
comment|/* How much padding I need (none) */
name|data
index|[
literal|3
index|]
operator|=
name|ctl
argument_list|(
name|mypadc
argument_list|)
expr_stmt|;
comment|/* Padding character I want */
name|data
index|[
literal|4
index|]
operator|=
name|tochar
argument_list|(
name|eol
argument_list|)
expr_stmt|;
comment|/* End-Of-Line character I want */
name|data
index|[
literal|5
index|]
operator|=
name|CTLQ
expr_stmt|;
comment|/* Control-Quote character I send */
if|if
condition|(
name|parity
operator|||
name|ebqflg
condition|)
block|{
comment|/* 8-bit quoting... */
name|data
index|[
literal|6
index|]
operator|=
literal|'&'
expr_stmt|;
comment|/* If parity or flag on, send&. */
if|if
condition|(
operator|(
name|ebq
operator|>
literal|0040
operator|&&
name|ebq
operator|<
literal|0100
operator|)
operator|||
comment|/* If flag off, then turn it on  */
operator|(
name|ebq
operator|>
literal|0140
operator|&&
name|ebq
operator|<
literal|0177
operator|)
operator|||
comment|/* if other side has asked us to */
operator|(
name|ebq
operator|==
literal|'Y'
operator|)
condition|)
name|ebqflg
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
comment|/* Normally, */
name|data
index|[
literal|6
index|]
operator|=
literal|'Y'
expr_stmt|;
comment|/* just say we're willing. */
block|}
name|data
index|[
literal|7
index|]
operator|=
name|bctr
operator|+
literal|'0'
expr_stmt|;
comment|/* Block check type */
name|data
index|[
literal|8
index|]
operator|=
name|MYRPTQ
expr_stmt|;
comment|/* Do repeat counts */
name|data
index|[
literal|9
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
literal|9
operator|)
return|;
comment|/* Return the length. */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*   S P A R -- Get the other system's Send-Init parameters.  */
end_comment

begin_macro
name|spar
argument_list|(
argument|data
argument_list|)
end_macro

begin_decl_stmt
name|char
name|data
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|len
decl_stmt|,
name|x
decl_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|data
argument_list|)
expr_stmt|;
comment|/* Number of fields */
name|x
operator|=
operator|(
name|len
operator|--
operator|>
literal|0
operator|)
condition|?
name|unchar
argument_list|(
name|data
index|[
literal|0
index|]
argument_list|)
else|:
name|DSPSIZ
expr_stmt|;
comment|/* Packet size */
if|if
condition|(
name|spsizf
operator|==
literal|0
condition|)
name|spsiz
operator|=
operator|(
name|x
operator|<
literal|10
operator|)
condition|?
name|DSPSIZ
else|:
name|x
expr_stmt|;
name|x
operator|=
operator|(
name|len
operator|--
operator|>
literal|0
operator|)
condition|?
name|unchar
argument_list|(
name|data
index|[
literal|1
index|]
argument_list|)
else|:
name|DMYTIM
expr_stmt|;
comment|/* Timeout */
if|if
condition|(
name|timef
operator|==
literal|0
condition|)
name|timint
operator|=
operator|(
name|x
operator|<
literal|0
operator|)
condition|?
name|DMYTIM
else|:
name|x
expr_stmt|;
name|npad
operator|=
literal|0
expr_stmt|;
name|padch
operator|=
literal|'\0'
expr_stmt|;
comment|/* Padding */
if|if
condition|(
name|len
operator|--
operator|>
literal|0
condition|)
block|{
name|npad
operator|=
name|unchar
argument_list|(
name|data
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
operator|--
operator|>
literal|0
condition|)
name|padch
operator|=
name|ctl
argument_list|(
name|data
index|[
literal|3
index|]
argument_list|)
expr_stmt|;
else|else
name|padch
operator|=
literal|0
expr_stmt|;
block|}
name|eol
operator|=
operator|(
name|len
operator|--
operator|>
literal|0
operator|)
condition|?
name|unchar
argument_list|(
name|data
index|[
literal|4
index|]
argument_list|)
else|:
literal|'\r'
expr_stmt|;
comment|/* Terminator  */
if|if
condition|(
operator|(
name|eol
operator|<
literal|2
operator|)
operator|||
operator|(
name|eol
operator|>
literal|037
operator|)
condition|)
name|eol
operator|=
literal|'\r'
expr_stmt|;
name|ctlq
operator|=
operator|(
name|len
operator|--
operator|>
literal|0
operator|)
condition|?
name|data
index|[
literal|5
index|]
else|:
name|CTLQ
expr_stmt|;
comment|/* Control prefix */
if|if
condition|(
name|len
operator|--
operator|>
literal|0
condition|)
block|{
comment|/* 8th-bit prefix */
name|ebq
operator|=
name|data
index|[
literal|6
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|ebq
operator|>
literal|040
operator|&&
name|ebq
operator|<
literal|0100
operator|)
operator|||
operator|(
name|ebq
operator|>
literal|0140
operator|&&
name|ebq
operator|<
literal|0177
operator|)
condition|)
block|{
name|ebqflg
operator|=
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|parity
operator|||
name|ebqflg
operator|)
operator|&&
operator|(
name|ebq
operator|==
literal|'Y'
operator|)
condition|)
block|{
name|ebqflg
operator|=
literal|1
expr_stmt|;
name|ebq
operator|=
literal|'&'
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ebq
operator|==
literal|'N'
condition|)
block|{
name|ebqflg
operator|=
literal|0
expr_stmt|;
block|}
else|else
name|ebqflg
operator|=
literal|0
expr_stmt|;
block|}
else|else
name|ebqflg
operator|=
literal|0
expr_stmt|;
name|chklen
operator|=
literal|1
expr_stmt|;
comment|/* Block check */
if|if
condition|(
name|len
operator|--
operator|>
literal|0
condition|)
block|{
name|chklen
operator|=
name|data
index|[
literal|7
index|]
operator|-
literal|'0'
expr_stmt|;
if|if
condition|(
operator|(
name|chklen
operator|<
literal|1
operator|)
operator|||
operator|(
name|chklen
operator|>
literal|3
operator|)
condition|)
name|chklen
operator|=
literal|1
expr_stmt|;
block|}
name|bctr
operator|=
name|chklen
expr_stmt|;
if|if
condition|(
name|len
operator|--
operator|>
literal|0
condition|)
block|{
comment|/* Repeat prefix */
name|rptq
operator|=
name|data
index|[
literal|8
index|]
expr_stmt|;
name|rptflg
operator|=
operator|(
operator|(
name|rptq
operator|>
literal|040
operator|&&
name|rptq
operator|<
literal|0100
operator|)
operator|||
operator|(
name|rptq
operator|>
literal|0140
operator|&&
name|rptq
operator|<
literal|0177
operator|)
operator|)
expr_stmt|;
block|}
else|else
name|rptflg
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|deblog
condition|)
name|sdebu
argument_list|(
name|len
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  S D E B U  -- Record spar results in debugging log  */
end_comment

begin_macro
name|sdebu
argument_list|(
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"spar: data"
argument_list|,
name|data
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" spsiz "
argument_list|,
literal|""
argument_list|,
name|spsiz
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" timint"
argument_list|,
literal|""
argument_list|,
name|timint
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" npad  "
argument_list|,
literal|""
argument_list|,
name|npad
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" padch "
argument_list|,
literal|""
argument_list|,
name|padch
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" eol   "
argument_list|,
literal|""
argument_list|,
name|eol
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" ctlq  "
argument_list|,
literal|""
argument_list|,
name|ctlq
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" ebq   "
argument_list|,
literal|""
argument_list|,
name|ebq
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" ebqflg"
argument_list|,
literal|""
argument_list|,
name|ebqflg
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" chklen"
argument_list|,
literal|""
argument_list|,
name|chklen
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" rptq  "
argument_list|,
literal|""
argument_list|,
name|rptq
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" rptflg"
argument_list|,
literal|""
argument_list|,
name|rptflg
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  G N F I L E  --  Get the next file name from a file group.  */
end_comment

begin_comment
comment|/*  Returns 1 if there's a next file, 0 otherwise  */
end_comment

begin_macro
name|gnfile
argument_list|()
end_macro

begin_block
block|{
name|int
name|x
decl_stmt|;
name|long
name|y
decl_stmt|;
comment|/* If file group interruption (C-Z) occured, fail.  */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"gnfile: czseen"
argument_list|,
literal|""
argument_list|,
name|czseen
argument_list|)
expr_stmt|;
if|if
condition|(
name|czseen
condition|)
block|{
name|tlog
argument_list|(
name|F100
argument_list|,
literal|"Transaction cancelled"
argument_list|,
literal|""
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* If input was stdin or memory string, there is no next file.  */
if|if
condition|(
name|sndsrc
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* If file list comes from command line args, get the next list element. */
name|y
operator|=
operator|-
literal|1
expr_stmt|;
while|while
condition|(
name|y
operator|<
literal|0
condition|)
block|{
comment|/* Keep trying till we get one... */
if|if
condition|(
name|sndsrc
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|nfils
operator|--
operator|>
literal|0
condition|)
block|{
name|strcpy
argument_list|(
name|filnam
argument_list|,
operator|*
name|cmlist
operator|++
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"gnfile: cmlist filnam"
argument_list|,
name|filnam
argument_list|,
name|nfils
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|*
name|filnam
operator|=
literal|'\0'
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"gnfile cmlist: nfils"
argument_list|,
literal|""
argument_list|,
name|nfils
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
comment|/* Otherwise, step to next element of internal wildcard expansion list. */
if|if
condition|(
name|sndsrc
operator|<
literal|0
condition|)
block|{
name|x
operator|=
name|znext
argument_list|(
name|filnam
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"gnfile znext: filnam"
argument_list|,
name|filnam
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* Get here with a filename. */
name|y
operator|=
name|zchki
argument_list|(
name|filnam
argument_list|)
expr_stmt|;
comment|/* Check if file readable */
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F110
argument_list|,
literal|"gnfile skipping:"
argument_list|,
name|filnam
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F111
argument_list|,
name|filnam
argument_list|,
literal|"not sent, reason"
argument_list|,
operator|(
name|long
operator|)
name|y
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_ST
argument_list|,
name|ST_SKIP
argument_list|,
literal|0l
argument_list|,
name|filnam
argument_list|)
expr_stmt|;
block|}
else|else
name|fsize
operator|=
name|y
expr_stmt|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  O P E N I  --  Open an existing file for input  */
end_comment

begin_macro
name|openi
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|,
name|filno
decl_stmt|;
if|if
condition|(
name|memstr
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Just return if file is memory. */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"openi"
argument_list|,
name|name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" sndsrc"
argument_list|,
literal|""
argument_list|,
name|sndsrc
argument_list|)
expr_stmt|;
name|filno
operator|=
operator|(
name|sndsrc
operator|==
literal|0
operator|)
condition|?
name|ZSTDIO
else|:
name|ZIFILE
expr_stmt|;
comment|/* ... */
name|debug
argument_list|(
name|F101
argument_list|,
literal|" file number"
argument_list|,
literal|""
argument_list|,
name|filno
argument_list|)
expr_stmt|;
if|if
condition|(
name|zopeni
argument_list|(
name|filno
argument_list|,
name|name
argument_list|)
condition|)
block|{
comment|/* Otherwise, try to open it. */
name|debug
argument_list|(
name|F110
argument_list|,
literal|" ok"
argument_list|,
name|name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
block|{
comment|/* If not found, */
name|char
name|xname
index|[
literal|100
index|]
decl_stmt|;
comment|/* convert the name */
name|zrtol
argument_list|(
name|name
argument_list|,
name|xname
argument_list|)
expr_stmt|;
comment|/* to local form and then */
name|x
operator|=
name|zopeni
argument_list|(
name|filno
argument_list|,
name|xname
argument_list|)
expr_stmt|;
comment|/* try opening it again. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|" zopeni"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
condition|)
block|{
name|debug
argument_list|(
name|F110
argument_list|,
literal|" ok"
argument_list|,
name|xname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
comment|/* It worked. */
block|}
else|else
block|{
name|screen
argument_list|(
name|SCR_EM
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
literal|"Can't open file"
argument_list|)
expr_stmt|;
comment|/* It didn't work. */
name|tlog
argument_list|(
name|F110
argument_list|,
name|xname
argument_list|,
literal|"could not be opened"
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|" openi failed"
argument_list|,
name|xname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  O P E N O  --  Open a new file for output.  */
end_comment

begin_comment
comment|/*  Returns actual name under which the file was opened in string 'name2'. */
end_comment

begin_macro
name|openo
argument_list|(
argument|name
argument_list|,
argument|name2
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|,
modifier|*
name|name2
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|xname
index|[
literal|100
index|]
decl_stmt|,
modifier|*
name|xp
decl_stmt|;
if|if
condition|(
name|stdouf
condition|)
comment|/* Receiving to stdout? */
return|return
operator|(
name|zopeno
argument_list|(
name|ZSTDIO
argument_list|,
literal|""
argument_list|)
operator|)
return|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"openo: name"
argument_list|,
name|name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|cxseen
operator|||
name|czseen
condition|)
block|{
comment|/* If interrupted, get out before */
name|debug
argument_list|(
name|F100
argument_list|,
literal|" open cancelled"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* destroying existing file. */
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Pretend to succeed. */
block|}
name|xp
operator|=
name|xname
expr_stmt|;
comment|/* OK to proceed. */
if|if
condition|(
name|fncnv
condition|)
comment|/* If desired, */
name|zrtol
argument_list|(
name|name
argument_list|,
name|xp
argument_list|)
expr_stmt|;
comment|/* convert name to local form */
else|else
comment|/* otherwise, */
name|strcpy
argument_list|(
name|xname
argument_list|,
name|name
argument_list|)
expr_stmt|;
comment|/* use it literally */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"openo: xname"
argument_list|,
name|xname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|warn
condition|)
block|{
comment|/* File collision avoidance? */
if|if
condition|(
name|zchki
argument_list|(
name|xname
argument_list|)
operator|!=
operator|-
literal|1
condition|)
block|{
comment|/* Yes, file exists? */
name|znewn
argument_list|(
name|xname
argument_list|,
operator|&
name|xp
argument_list|)
expr_stmt|;
comment|/* Yes, make new name. */
name|strcpy
argument_list|(
name|xname
argument_list|,
name|xp
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|" exists, new name "
argument_list|,
name|xname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|zopeno
argument_list|(
name|ZOFILE
argument_list|,
name|xname
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* Try to open the file */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"openo failed"
argument_list|,
name|xname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Failure to open"
argument_list|,
name|xname
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|else
block|{
name|strcpy
argument_list|(
name|name2
argument_list|,
name|xname
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"openo ok, name2"
argument_list|,
name|name2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
end_block

begin_comment
comment|/*  O P E N T  --  Open the terminal for output, in place of a file  */
end_comment

begin_macro
name|opent
argument_list|()
end_macro

begin_block
block|{
name|ffc
operator|=
name|tfc
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|zopeno
argument_list|(
name|ZCTERM
argument_list|,
literal|""
argument_list|)
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  C L S I F  --  Close the current input file. */
end_comment

begin_macro
name|clsif
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|memstr
condition|)
block|{
comment|/* If input was memory string, */
name|memstr
operator|=
literal|0
expr_stmt|;
comment|/* indicate no more. */
block|}
else|else
name|zclose
argument_list|(
name|ZIFILE
argument_list|)
expr_stmt|;
comment|/* else close input file. */
if|if
condition|(
name|czseen
operator|||
name|cxseen
condition|)
name|screen
argument_list|(
name|SCR_ST
argument_list|,
name|ST_DISC
argument_list|,
literal|0l
argument_list|,
literal|""
argument_list|)
expr_stmt|;
else|else
name|screen
argument_list|(
name|SCR_ST
argument_list|,
name|ST_OK
argument_list|,
literal|0l
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|cxseen
operator|=
name|hcflg
operator|=
literal|0
expr_stmt|;
comment|/* Reset flags, */
operator|*
name|filnam
operator|=
literal|'\0'
expr_stmt|;
comment|/* and current file name */
block|}
end_block

begin_comment
comment|/*  C L S O F  --  Close an output file.  */
end_comment

begin_comment
comment|/*  Call with disp != 0 if file is to be discarded.  */
end_comment

begin_comment
comment|/*  Returns -1 upon failure to close, 0 or greater on success. */
end_comment

begin_macro
name|clsof
argument_list|(
argument|disp
argument_list|)
end_macro

begin_decl_stmt
name|int
name|disp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|;
if|if
condition|(
operator|(
name|x
operator|=
name|zclose
argument_list|(
name|ZOFILE
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* Try to close the file */
name|tlog
argument_list|(
name|F100
argument_list|,
literal|"Failure to close"
argument_list|,
name|filnam
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_ST
argument_list|,
name|ST_ERR
argument_list|,
literal|0l
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|disp
operator|&&
operator|(
name|keep
operator|==
literal|0
operator|)
condition|)
block|{
comment|/* Delete it if interrupted, */
if|if
condition|(
operator|*
name|filnam
condition|)
name|zdelet
argument_list|(
name|filnam
argument_list|)
expr_stmt|;
comment|/* and not keeping incomplete files */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"Discarded"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F100
argument_list|,
literal|"Discarded"
argument_list|,
literal|""
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
name|screen
argument_list|(
name|SCR_ST
argument_list|,
name|ST_DISC
argument_list|,
literal|0l
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Nothing wrong, just keep it */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"Closed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* and give comforting messages. */
name|screen
argument_list|(
name|SCR_ST
argument_list|,
name|ST_OK
argument_list|,
literal|0l
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
operator|*
name|filnam
operator|=
literal|'\0'
expr_stmt|;
comment|/* Zero the current file name. */
return|return
operator|(
name|x
operator|)
return|;
comment|/* Send back zclose() return code. */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  S N D H L P  --  Routine to send builtin help  */
end_comment

begin_macro
name|sndhlp
argument_list|()
end_macro

begin_block
block|{
name|nfils
operator|=
literal|0
expr_stmt|;
comment|/* No files, no lists. */
name|xflg
operator|=
literal|1
expr_stmt|;
comment|/* Flag we must send X packet. */
name|strcpy
argument_list|(
name|cmdstr
argument_list|,
literal|"help text"
argument_list|)
expr_stmt|;
comment|/* Data for X packet. */
name|first
operator|=
literal|1
expr_stmt|;
comment|/* Init getchx lookahead */
name|memstr
operator|=
literal|1
expr_stmt|;
comment|/* Just set the flag. */
name|memptr
operator|=
name|hlptxt
expr_stmt|;
comment|/* And the pointer. */
if|if
condition|(
name|binary
condition|)
block|{
comment|/* If file mode is binary, */
name|binary
operator|=
literal|0
expr_stmt|;
comment|/*  turn it back to text for this, */
name|savmod
operator|=
literal|1
expr_stmt|;
comment|/*  remember to restore it later. */
block|}
return|return
operator|(
name|sinit
argument_list|()
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  C W D  --  Change current working directory  */
end_comment

begin_comment
comment|/*  String passed has first byte as length of directory name, rest of string  is name.  Fails if can't connect, else ACKs (with name) and succeeds.  */
end_comment

begin_macro
name|cwd
argument_list|(
argument|vdir
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|vdir
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|vdir
index|[
name|unchar
argument_list|(
operator|*
name|vdir
argument_list|)
operator|+
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* End with a null */
if|if
condition|(
name|zchdir
argument_list|(
name|vdir
operator|+
literal|1
argument_list|)
condition|)
block|{
name|encstr
argument_list|(
name|vdir
operator|+
literal|1
argument_list|)
expr_stmt|;
name|ack1
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Changed directory to"
argument_list|,
name|vdir
operator|+
literal|1
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
block|{
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Failed to change directory to"
argument_list|,
name|vdir
operator|+
literal|1
argument_list|,
literal|0l
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_block

begin_comment
comment|/*  S Y S C M D  --  Do a system command  */
end_comment

begin_comment
comment|/*  Command string is formed by concatenating the two arguments.  */
end_comment

begin_macro
name|syscmd
argument_list|(
argument|prefix
argument_list|,
argument|suffix
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|prefix
decl_stmt|,
modifier|*
name|suffix
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|cp
decl_stmt|;
if|if
condition|(
name|prefix
operator|==
name|NULL
operator|||
operator|*
name|prefix
operator|==
literal|'\0'
condition|)
return|return
operator|(
literal|0
operator|)
return|;
for|for
control|(
name|cp
operator|=
name|cmdstr
init|;
operator|*
name|prefix
operator|!=
literal|'\0'
condition|;
operator|*
name|cp
operator|++
operator|=
operator|*
name|prefix
operator|++
control|)
empty_stmt|;
while|while
condition|(
operator|*
name|cp
operator|++
operator|=
operator|*
name|suffix
operator|++
condition|)
empty_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"syscmd"
argument_list|,
name|cmdstr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|zopeni
argument_list|(
name|ZSYSFN
argument_list|,
name|cmdstr
argument_list|)
operator|>
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"syscmd zopeni ok"
argument_list|,
name|cmdstr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|nfils
operator|=
name|sndsrc
operator|=
literal|0
expr_stmt|;
comment|/* Flag that input from stdin */
name|xflg
operator|=
name|hcflg
operator|=
literal|1
expr_stmt|;
comment|/* And special flags for pipe */
if|if
condition|(
name|binary
condition|)
block|{
comment|/* If file mode is binary, */
name|binary
operator|=
literal|0
expr_stmt|;
comment|/*  turn it back to text for this, */
name|savmod
operator|=
literal|1
expr_stmt|;
comment|/*  remember to restore it later. */
block|}
return|return
operator|(
name|sinit
argument_list|()
operator|)
return|;
comment|/* Send S packet */
block|}
else|else
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"syscmd zopeni failed"
argument_list|,
name|cmdstr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_block

end_unit

