begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|fnsv
init|=
literal|"C-Kermit functions, 5A(080) 24 Nov 92"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  C K C F N S  --  System-independent Kermit protocol support functions.  */
end_comment

begin_comment
comment|/*  ...Part 1 (others moved to ckcfn2,3 to make this module small enough) */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_comment
comment|/*  System-dependent primitives defined in:     ck?tio.c -- terminal i/o    cx?fio.c -- file i/o, directory structure */
end_comment

begin_include
include|#
directive|include
file|"ckcsym.h"
end_include

begin_comment
comment|/* Once needed this for Mac... */
end_comment

begin_include
include|#
directive|include
file|"ckcasc.h"
end_include

begin_comment
comment|/* ASCII symbols */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_comment
comment|/* Debug formats, typedefs, etc. */
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
file|"ckcxla.h"
end_include

begin_comment
comment|/* Character set symbols */
end_comment

begin_comment
comment|/* Externals from ckcmai.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|spsiz
decl_stmt|,
name|spmax
decl_stmt|,
name|rpsiz
decl_stmt|,
name|timint
decl_stmt|,
name|srvtim
decl_stmt|,
name|rtimo
decl_stmt|,
name|npad
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
decl_stmt|,
name|fncact
decl_stmt|,
name|pkttim
decl_stmt|,
name|autopar
decl_stmt|,
name|spsizr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pktnum
decl_stmt|,
name|bctr
decl_stmt|,
name|bctu
decl_stmt|,
name|bctl
decl_stmt|,
name|fmask
decl_stmt|,
name|clfils
decl_stmt|,
name|sbufnum
decl_stmt|,
name|size
decl_stmt|,
name|osize
decl_stmt|,
name|spktl
decl_stmt|,
name|nfils
decl_stmt|,
name|warn
decl_stmt|,
name|timef
decl_stmt|,
name|spsizf
decl_stmt|,
name|sndtyp
decl_stmt|,
name|success
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parity
decl_stmt|,
name|turn
decl_stmt|,
name|network
decl_stmt|,
name|what
decl_stmt|,
name|fsecs
decl_stmt|,
name|delay
decl_stmt|,
name|displa
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
name|fsize
decl_stmt|,
name|speed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fblksiz
decl_stmt|,
name|frecl
decl_stmt|,
name|frecfm
decl_stmt|,
name|forg
decl_stmt|,
name|fcctrl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|spackets
decl_stmt|,
name|rpackets
decl_stmt|,
name|timeouts
decl_stmt|,
name|retrans
decl_stmt|,
name|crunched
decl_stmt|,
name|wmax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
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
name|int
name|nakstate
decl_stmt|,
name|discard
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rq
decl_stmt|,
name|rqf
decl_stmt|,
name|sq
decl_stmt|,
name|wslots
decl_stmt|,
name|wslotn
decl_stmt|,
name|wslotr
decl_stmt|,
name|winlo
decl_stmt|,
name|urpsiz
decl_stmt|,
name|rln
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atcapr
decl_stmt|,
name|atcapb
decl_stmt|,
name|atcapu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lpcapr
decl_stmt|,
name|lpcapb
decl_stmt|,
name|lpcapu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|swcapr
decl_stmt|,
name|swcapb
decl_stmt|,
name|swcapu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lscapr
decl_stmt|,
name|lscapb
decl_stmt|,
name|lscapu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bsave
decl_stmt|,
name|bsavef
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sseqtbl
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|numerrs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|rptn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxtry
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOCSETS
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|tcharset
decl_stmt|,
name|fcharset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ntcsets
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|csinfo
name|tcsinfo
index|[]
decl_stmt|,
name|fcsinfo
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOCSETS */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|atenci
decl_stmt|,
name|atenco
decl_stmt|,
name|atdati
decl_stmt|,
name|atdato
decl_stmt|,
name|atleni
decl_stmt|,
name|atleno
decl_stmt|,
name|atblki
decl_stmt|,
name|atblko
decl_stmt|,
name|attypi
decl_stmt|,
name|attypo
decl_stmt|,
name|atsidi
decl_stmt|,
name|atsido
decl_stmt|,
name|atsysi
decl_stmt|,
name|atsyso
decl_stmt|,
name|atdisi
decl_stmt|,
name|atdiso
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bigsbsiz
decl_stmt|,
name|bigrbsiz
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_decl_stmt
specifier|extern
name|CHAR
modifier|*
name|srvcmd
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|CHAR
name|srvcmd
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_decl_stmt
specifier|extern
name|CHAR
name|padch
decl_stmt|,
name|mypadc
decl_stmt|,
name|eol
decl_stmt|,
name|seol
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
modifier|*
name|recpkt
decl_stmt|,
modifier|*
name|data
decl_stmt|,
name|padbuf
index|[]
decl_stmt|,
name|stchr
decl_stmt|,
name|mystch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CHAR
modifier|*
name|srvptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CHAR
modifier|*
name|rdatap
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
decl_stmt|,
name|filnam
index|[]
decl_stmt|,
name|fspec
index|[]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|CHAR
operator|*
name|rpar
argument_list|,
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int lslook
argument_list|,
argument|(unsigned int b)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Locking Shift Lookahead */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int szeof
argument_list|,
argument|(CHAR *s)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* International character sets */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOCSETS
end_ifndef

begin_comment
comment|/* Pointers to translation functions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CK_ANSIC
end_ifdef

begin_function_decl
specifier|extern
name|CHAR
function_decl|(
modifier|*
name|xls
index|[
name|MAXTCSETS
operator|+
literal|1
index|]
index|[
name|MAXFCSETS
operator|+
literal|1
index|]
function_decl|)
parameter_list|(
name|CHAR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Character set */
end_comment

begin_function_decl
specifier|extern
name|CHAR
function_decl|(
modifier|*
name|xlr
index|[
name|MAXTCSETS
operator|+
literal|1
index|]
index|[
name|MAXFCSETS
operator|+
literal|1
index|]
function_decl|)
parameter_list|(
name|CHAR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* translation functions */
end_comment

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|CHAR
function_decl|(
modifier|*
name|xls
index|[
name|MAXTCSETS
operator|+
literal|1
index|]
index|[
name|MAXFCSETS
operator|+
literal|1
index|]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Character set */
end_comment

begin_function_decl
specifier|extern
name|CHAR
function_decl|(
modifier|*
name|xlr
index|[
name|MAXTCSETS
operator|+
literal|1
index|]
index|[
name|MAXFCSETS
operator|+
literal|1
index|]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* translation functions. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ANSIC */
end_comment

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|CHAR
argument_list|(
operator|*
name|rx
argument_list|)
argument_list|,
operator|(
name|CHAR
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Input translation function */
end_comment

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|CHAR
argument_list|(
operator|*
name|sx
argument_list|)
argument_list|,
operator|(
name|CHAR
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Output translation function */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|CHAR ident
argument_list|,
argument|(CHAR)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Identity translation function */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOCSETS */
end_comment

begin_comment
comment|/* Windowing things */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rseqtbl
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Rec'd-packet sequence # table */
end_comment

begin_comment
comment|/* (PWP) external def. of things used in buffered file input and output */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zinbuffer
decl_stmt|,
modifier|*
name|zoutbuffer
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
name|zinbuffer
index|[]
decl_stmt|,
name|zoutbuffer
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zinptr
decl_stmt|,
modifier|*
name|zoutptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|zincnt
decl_stmt|,
name|zoutcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables defined in this module, but shared by ckcfn3, to which */
end_comment

begin_comment
comment|/* several functions have been moved... */
end_comment

begin_decl_stmt
name|int
name|sndsrc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag for where to get names of files to send: */
end_comment

begin_comment
comment|/* -1: znext() function */
end_comment

begin_comment
comment|/*  0: stdin */
end_comment

begin_comment
comment|/*>0: list in cmlist */
end_comment

begin_decl_stmt
name|int
name|memstr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag for input from memory string */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_decl_stmt
name|CHAR
name|myinit
index|[
literal|25
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copy of my Send-Init data */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|CHAR
name|myinit
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copy of my Send-Init data */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pdp11 */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|cmdstr
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System command string. */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|char
name|cmdstr
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pdp11 */
end_comment

begin_decl_stmt
specifier|static
name|int
name|drain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For draining stacked-up ACKs. */
end_comment

begin_decl_stmt
specifier|static
name|int
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

begin_decl_stmt
specifier|static
name|int
name|lsstate
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Locking shift state */
end_comment

begin_decl_stmt
specifier|static
name|int
name|lsquote
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Locking shift quote */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|datageneral
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|quiet
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/*  E N C S T R  --  Encode a string from memory. */
end_comment

begin_comment
comment|/*   Call this instead of getpkt() if source is a string, rather than a file.   Note: Character set translation is never done in this case. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_define
define|#
directive|define
name|ENCBUFL
value|100
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENCBUFL
value|200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pdp11 */
end_comment

begin_decl_stmt
name|CHAR
name|encbuf
index|[
name|ENCBUFL
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|encstr
parameter_list|(
name|s
parameter_list|)
name|CHAR
modifier|*
name|s
decl_stmt|;
block|{
name|int
name|m
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|CHAR
modifier|*
name|dsave
decl_stmt|;
if|if
condition|(
operator|(
name|m
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
operator|(
name|char
operator|*
operator|)
name|s
argument_list|)
operator|)
operator|>
name|ENCBUFL
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"encstr string too long for buffer"
argument_list|,
name|s
argument_list|,
name|ENCBUFL
argument_list|)
expr_stmt|;
name|s
index|[
name|ENCBUFL
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
if|if
condition|(
name|m
operator|>
name|spsiz
operator|-
name|bctl
operator|-
literal|3
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"encstr string too long for packet"
argument_list|,
name|s
argument_list|,
name|spsiz
operator|-
name|bctl
operator|-
literal|3
argument_list|)
expr_stmt|;
name|s
index|[
name|spsiz
operator|-
name|bctl
operator|-
literal|3
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
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
operator|(
name|char
operator|*
operator|)
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
name|dsave
operator|=
name|data
expr_stmt|;
comment|/* Boy is this ugly... */
name|data
operator|=
name|encbuf
operator|+
literal|7
expr_stmt|;
comment|/* Why + 7?  See spack()... */
ifdef|#
directive|ifdef
name|COMMENT
name|getpkt
argument_list|(
name|spsiz
operator|-
name|bctl
operator|-
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Fill a packet from the string. */
else|#
directive|else
name|getpkt
argument_list|(
name|spsiz
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
name|data
operator|=
name|dsave
expr_stmt|;
comment|/* (sorry...) */
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
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/*   We don't use this routine any more -- the code has been incorporated   directly into getpkt() to reduce per-character function call overhead.   Also, watch out: it hasn't been updated since it was commented out a   long time ago. */
end_comment

begin_comment
comment|/* E N C O D E - Kermit packet encoding procedure */
end_comment

begin_function
name|VOID
name|encode
parameter_list|(
name|a
parameter_list|)
name|CHAR
name|a
decl_stmt|;
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
ifndef|#
directive|ifndef
name|NOCSETS
if|if
condition|(
operator|!
name|binary
operator|&&
name|sx
condition|)
name|a
operator|=
call|(
modifier|*
name|sx
call|)
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* Translate. */
endif|#
directive|endif
comment|/* NOCSETS */
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
name|rptn
operator|+=
name|rpt
expr_stmt|;
comment|/* Count, for stats */
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
name|rptn
operator|+=
name|rpt
expr_stmt|;
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
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  Output functions passed to 'decode':  */
end_comment

begin_function
name|int
comment|/*  Put character in server command buffer  */
ifdef|#
directive|ifdef
name|CK_ANSIC
name|putsrv
parameter_list|(
name|char
name|c
parameter_list|)
else|#
directive|else
function|putsrv
parameter_list|(
name|c
parameter_list|)
specifier|register
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* putsrv */
block|{
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
end_function

begin_function
name|int
comment|/*  Output character to console.  */
ifdef|#
directive|ifdef
name|CK_ANSIC
name|puttrm
parameter_list|(
name|char
name|c
parameter_list|)
else|#
directive|else
function|puttrm
parameter_list|(
name|c
parameter_list|)
specifier|register
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* puttrm */
block|{
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
end_function

begin_function
name|int
comment|/*  Output char to file. */
ifdef|#
directive|ifdef
name|CK_ANSIC
name|putfil
parameter_list|(
name|char
name|c
parameter_list|)
else|#
directive|else
function|putfil
parameter_list|(
name|c
parameter_list|)
specifier|register
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* putfil */
block|{
if|if
condition|(
name|zchout
argument_list|(
name|ZOFILE
argument_list|,
call|(
name|char
call|)
argument_list|(
name|c
operator|&
name|fmask
argument_list|)
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
end_function

begin_comment
comment|/* D E C O D E  --  Kermit packet decoding procedure */
end_comment

begin_comment
comment|/*  Call with string to be decoded and an output function.  Returns 0 on success, -1 on failure (e.g. disk full).   This is the "inner loop" when receiving files, and must be coded as   efficiently as possible.  Note some potential problems:  if a packet  is badly formed, having a prefixed sequence ending prematurely, this  function, as coded, could read past the end of the packet.  This has  never happened, thus the additional (time-consuming) tests have not  been added. */
end_comment

begin_decl_stmt
specifier|static
name|CHAR
modifier|*
name|xdbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global version of decode()'s buffer pointer */
end_comment

begin_comment
comment|/* for use by translation functions. */
end_comment

begin_comment
comment|/* Function for pushing a character onto decode()'s input stream. */
end_comment

begin_function
name|VOID
ifdef|#
directive|ifdef
name|CK_ANSIC
name|zdstuff
parameter_list|(
name|CHAR
name|c
parameter_list|)
else|#
directive|else
function|zdstuff
parameter_list|(
name|c
parameter_list|)
name|CHAR
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* zdstuff */
block|{
name|xdbuf
operator|--
expr_stmt|;
comment|/* Back up the pointer. */
operator|*
name|xdbuf
operator|=
name|c
expr_stmt|;
comment|/* Stuff the character. */
block|}
end_function

begin_decl_stmt
name|int
ifdef|#
directive|ifdef
name|CK_ANSIC
name|decode
argument_list|(
name|CHAR
operator|*
name|buf
argument_list|,
name|int
argument_list|(
operator|*
name|fn
argument_list|)
argument_list|(
name|char
argument_list|)
argument_list|,
name|int
name|xlate
argument_list|)
else|#
directive|else
name|decode
argument_list|(
name|buf
argument_list|,
name|fn
argument_list|,
name|xlate
argument_list|)
decl|register
name|CHAR
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|register
name|int
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|xlate
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ANSIC */
end_comment

begin_comment
comment|/* decode */
end_comment

begin_block
block|{
specifier|register
name|unsigned
name|int
name|a
decl_stmt|,
name|a7
decl_stmt|,
name|a8
decl_stmt|,
name|b8
decl_stmt|;
comment|/* Various copies of current char */
name|int
name|t
decl_stmt|;
comment|/* Int version of character */
name|int
name|ssflg
decl_stmt|;
comment|/* Character was single-shifted */
comment|/*   Catch the case in which we are asked to decode into a file that is not open,   for example, if the user interrupted the transfer, but the other Kermit   keeps sending. */
if|if
condition|(
operator|(
name|cxseen
operator|||
name|czseen
operator|||
name|discard
operator|)
operator|&&
operator|(
name|fn
operator|==
name|putfil
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|xdbuf
operator|=
name|buf
expr_stmt|;
comment|/* Make global copy of pointer. */
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
name|xdbuf
operator|++
operator|&
literal|0xFF
operator|)
operator|!=
literal|'\0'
condition|)
block|{
comment|/* Get next character. */
if|if
condition|(
name|a
operator|==
name|rptq
operator|&&
name|rptflg
condition|)
block|{
comment|/* Got a repeat prefix? */
name|rpt
operator|=
name|xunchar
argument_list|(
operator|*
name|xdbuf
operator|++
operator|&
literal|0xFF
argument_list|)
expr_stmt|;
comment|/* Yes, get the repeat count, */
name|rptn
operator|+=
name|rpt
expr_stmt|;
name|a
operator|=
operator|*
name|xdbuf
operator|++
operator|&
literal|0xFF
expr_stmt|;
comment|/* and get the prefixed character. */
block|}
name|b8
operator|=
name|lsstate
condition|?
literal|0200
else|:
literal|0
expr_stmt|;
comment|/* 8th-bit value from SHIFT-STATE */
if|if
condition|(
name|ebqflg
operator|&&
name|a
operator|==
name|ebq
condition|)
block|{
comment|/* Have 8th-bit prefix? */
name|b8
operator|^=
literal|0200
expr_stmt|;
comment|/* Yes, invert the 8th bit's value, */
name|ssflg
operator|=
literal|1
expr_stmt|;
comment|/* remember we did this, */
name|a
operator|=
operator|*
name|xdbuf
operator|++
operator|&
literal|0xFF
expr_stmt|;
comment|/* and get the prefixed character. */
block|}
else|else
name|ssflg
operator|=
literal|0
expr_stmt|;
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
name|xdbuf
operator|++
operator|&
literal|0xFF
expr_stmt|;
comment|/* get its operand */
name|a7
operator|=
name|a
operator|&
literal|0x7F
expr_stmt|;
comment|/* and its low 7 bits. */
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
comment|/* Controllify */
name|a
operator|=
name|ctl
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* if in control range. */
if|if
condition|(
name|lscapu
condition|)
block|{
comment|/* If doing locking shifts... */
if|if
condition|(
name|lsstate
condition|)
comment|/* If SHIFTED */
name|a8
operator|=
operator|(
name|a
operator|&
operator|~
name|b8
operator|)
operator|&
literal|0xFF
expr_stmt|;
comment|/* Invert meaning of 8th bit */
else|else
comment|/* otherwise */
name|a8
operator|=
name|a
operator||
name|b8
expr_stmt|;
comment|/* OR in 8th bit */
comment|/* If we're not in a quoted sequence */
if|if
condition|(
operator|!
name|lsquote
operator|&&
operator|(
operator|!
name|lsstate
operator|||
operator|!
name|ssflg
operator|)
condition|)
block|{
if|if
condition|(
name|a8
operator|==
name|DLE
condition|)
block|{
comment|/* Check for DLE quote */
name|lsquote
operator|=
literal|1
expr_stmt|;
comment|/* prefixed by single shift! */
continue|continue;
block|}
elseif|else
if|if
condition|(
name|a8
operator|==
name|SO
condition|)
block|{
comment|/* Check for Shift-Out */
name|lsstate
operator|=
literal|1
expr_stmt|;
comment|/* SHIFT-STATE = SHIFTED */
continue|continue;
block|}
elseif|else
if|if
condition|(
name|a8
operator|==
name|SI
condition|)
block|{
comment|/* or Shift-In */
name|lsstate
operator|=
literal|0
expr_stmt|;
comment|/* SHIFT-STATE = UNSHIFTED */
continue|continue;
block|}
block|}
else|else
name|lsquote
operator|=
literal|0
expr_stmt|;
block|}
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
if|if
condition|(
operator|!
name|binary
condition|)
block|{
comment|/* If in text mode, */
ifdef|#
directive|ifdef
name|NLCHAR
if|if
condition|(
name|a
operator|==
name|CR
condition|)
continue|continue;
comment|/* Discard carriage returns, */
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
endif|#
directive|endif
comment|/* NLCHAR */
ifndef|#
directive|ifndef
name|NOCSETS
comment|/* Character-set translation */
ifdef|#
directive|ifdef
name|KANJI
comment|/* For Kanji transfers, */
if|if
condition|(
name|tcharset
operator|!=
name|TC_JEUC
condition|)
comment|/* postpone translation. */
endif|#
directive|endif
comment|/* KANJI */
if|if
condition|(
name|xlate
operator|&&
name|rx
condition|)
name|a
operator|=
call|(
modifier|*
name|rx
call|)
argument_list|(
operator|(
name|CHAR
operator|)
name|a
argument_list|)
expr_stmt|;
comment|/* Translate charset */
endif|#
directive|endif
comment|/* NOCSETS */
block|}
if|if
condition|(
name|fn
operator|==
name|putfil
condition|)
block|{
comment|/* (PWP) speedup via buffered output and a macro */
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
ifndef|#
directive|ifndef
name|NOCSETS
ifdef|#
directive|ifdef
name|KANJI
if|if
condition|(
operator|!
name|binary
operator|&&
name|tcharset
operator|==
name|TC_JEUC
operator|&&
name|fcharset
operator|!=
name|FC_JEUC
condition|)
block|{
comment|/* Translating from J-EUC */
if|if
condition|(
name|ffc
operator|==
literal|0L
condition|)
name|xkanjf
argument_list|()
expr_stmt|;
if|if
condition|(
name|xkanji
argument_list|(
name|a
argument_list|,
name|fn
argument_list|)
operator|<
literal|0
condition|)
comment|/* to something else? */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
elseif|else
endif|#
directive|endif
comment|/* KANJI */
endif|#
directive|endif
comment|/* NOCSETS */
if|if
condition|(
operator|(
name|t
operator|=
name|zmchout
argument_list|(
name|a
operator|&
name|fmask
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* zmchout is a macro */
ifdef|#
directive|ifdef
name|COMMENT
comment|/* Too costly, uncomment these if you really need them. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"decode zmchout"
argument_list|,
literal|""
argument_list|,
name|t
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"decode zoutcnt"
argument_list|,
literal|""
argument_list|,
name|zoutcnt
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"decode a"
argument_list|,
literal|""
argument_list|,
name|a
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|ffc
operator|++
expr_stmt|;
comment|/* Count the character */
block|}
block|}
else|else
block|{
comment|/* Output to something else. */
name|a
operator|&=
name|fmask
expr_stmt|;
comment|/* Apply file mask */
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
if|if
condition|(
call|(
modifier|*
name|fn
call|)
argument_list|(
operator|(
name|char
operator|)
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
comment|/* Send to output func. */
name|ffc
operator|++
expr_stmt|;
block|}
block|}
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
comment|/*  Gets characters from the current source -- file or memory string.  Encodes the data into the packet, filling the packet optimally.  Set first = 1 when calling for the first time on a given input stream  (string or file).   Call with:  bufmax -- current send-packet size  xlate  -- flag: 0 to skip character-set translation, 1 to translate   Uses global variables:  t     -- current character.  first -- flag: 1 to start up, 0 for input in progress, -1 for EOF.  next  -- next character.  data  -- pointer to the packet data buffer.  size  -- number of characters in the data buffer.  memstr - flag that input is coming from a memory string instead of a file.  memptr - pointer to string in memory.  (*sx)()  character set translation function  Returns the size as value of the function, and also sets global "size", and fills (and null-terminates) the global data array.  Returns 0 upon eof.  Rewritten by Paul W. Placeway (PWP) of Ohio State University, March 1989. Incorporates old getchx() and encode() inline to reduce function calls, uses buffered input for much-improved efficiency, and clears up some confusion with line termination (CRLF vs LF vs CR).  Rewritten again by Frank da Cruz to incorporate locking shift mechanism, May 1991. */
end_comment

begin_comment
comment|/*   Lookahead function to decide whether locking shift is worth it.  Looks at   the next four input characters to see if all of their 8th bits match the   argument.  Call with 0 or 0200.  Returns 1 if so, 0 if not.  If we don't   happen to have at least 4 more characters waiting in the input buffer,   returns 1.  Note that zinptr points two characters ahead of the current   character because of repeat-count lookahead. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KANJI
end_ifdef

begin_function
name|int
name|kgetf
parameter_list|()
block|{
return|return
operator|(
name|zminchar
argument_list|()
operator|)
return|;
block|}
end_function

begin_function
name|int
name|kgetm
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
if|if
condition|(
name|x
operator|=
operator|*
name|memptr
operator|++
condition|)
return|return
operator|(
name|x
operator|)
return|;
else|else
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KANJI */
end_comment

begin_function
name|int
name|lslook
parameter_list|(
name|b
parameter_list|)
name|unsigned
name|int
name|b
decl_stmt|;
block|{
comment|/* Locking Shift Lookahead */
name|int
name|i
decl_stmt|;
if|if
condition|(
name|zincnt
operator|<
literal|3
condition|)
comment|/* If not enough chars in buffer, */
return|return
operator|(
literal|1
operator|)
return|;
comment|/* force shift-state switch. */
name|b
operator|&=
literal|0200
expr_stmt|;
comment|/* Force argument to proper form. */
for|for
control|(
name|i
operator|=
operator|-
literal|1
init|;
name|i
operator|<
literal|3
condition|;
name|i
operator|++
control|)
comment|/* Look at next 5 characters to */
if|if
condition|(
operator|(
operator|(
operator|*
operator|(
name|zinptr
operator|+
name|i
operator|)
operator|)
operator|&
literal|0200
operator|)
operator|!=
name|b
condition|)
comment|/* see if all their 8th bits match.  */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* They don't. */
return|return
operator|(
literal|1
operator|)
return|;
comment|/* They do. */
block|}
end_function

begin_function
name|int
name|getpkt
parameter_list|(
name|bufmax
parameter_list|,
name|xlate
parameter_list|)
name|int
name|bufmax
decl_stmt|,
name|xlate
decl_stmt|;
block|{
comment|/* Fill one packet buffer */
specifier|register
name|CHAR
name|rt
init|=
name|t
decl_stmt|,
name|rnext
init|=
name|next
decl_stmt|;
comment|/* register shadows of the globals */
specifier|register
name|CHAR
modifier|*
name|dp
decl_stmt|,
modifier|*
name|odp
decl_stmt|,
modifier|*
name|odp2
decl_stmt|,
modifier|*
name|p1
decl_stmt|,
modifier|*
name|p2
decl_stmt|;
comment|/* pointers... */
specifier|register
name|int
name|x
decl_stmt|;
comment|/* Loop index. */
specifier|register
name|int
name|a7
decl_stmt|;
comment|/* Low 7 bits of character */
specifier|static
name|CHAR
name|leftover
index|[
literal|9
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
block|,
literal|'\0'
block|,
literal|'\0'
block|,
literal|'\0'
block|}
decl_stmt|;
name|CHAR
name|xxls
decl_stmt|,
name|xxdl
decl_stmt|,
name|xxrc
decl_stmt|,
name|xxss
decl_stmt|,
name|xxcq
decl_stmt|;
comment|/* Pieces of prefixed sequence */
name|int
name|n
decl_stmt|;
comment|/* worker */
comment|/*   Assume bufmax is the receiver's total receive-packet buffer length.   Our whole packet has to fit into it, so we adjust the data field length.   We also decide optimally whether it is better to use a short-format or   long-format packet when we're near the borderline. */
name|n
operator|=
name|bufmax
operator|-
literal|5
expr_stmt|;
comment|/* Space for Data and Checksum */
if|if
condition|(
name|n
operator|>
literal|92
operator|&&
name|n
operator|<
literal|96
condition|)
name|n
operator|=
literal|92
expr_stmt|;
comment|/* "Short" Long packets don't pay */
if|if
condition|(
name|n
operator|>
literal|92
operator|&&
name|lpcapu
operator|==
literal|0
condition|)
comment|/* If long packets needed, */
name|n
operator|=
literal|92
expr_stmt|;
comment|/* make sure they've been negotiated */
name|bufmax
operator|=
name|n
operator|-
name|bctl
expr_stmt|;
comment|/* Space for data */
if|if
condition|(
name|n
operator|>
literal|92
condition|)
name|bufmax
operator|-=
literal|3
expr_stmt|;
comment|/* Long packet needs header chksum */
if|if
condition|(
name|first
operator|==
literal|1
condition|)
block|{
comment|/* If first character of this file... */
name|ffc
operator|=
literal|0L
expr_stmt|;
comment|/* Reset file character counter */
name|first
operator|=
literal|0
expr_stmt|;
comment|/* Next character won't be first */
operator|*
name|leftover
operator|=
literal|'\0'
expr_stmt|;
comment|/* Discard any interrupted leftovers, */
comment|/* get first character of file into rt, watching out for null file */
ifndef|#
directive|ifndef
name|NOCSETS
ifdef|#
directive|ifdef
name|KANJI
if|if
condition|(
operator|!
name|binary
operator|&&
name|tcharset
operator|==
name|TC_JEUC
operator|&&
name|xlate
condition|)
block|{
name|x
operator|=
name|zkanjf
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|x
operator|=
name|zkanji
argument_list|(
name|memstr
condition|?
name|kgetm
else|:
name|kgetf
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|first
operator|=
operator|-
literal|1
expr_stmt|;
name|size
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|x
operator|==
operator|-
literal|2
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"getpkt(zkanji): input error"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|cxseen
operator|=
literal|1
expr_stmt|;
block|}
else|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"getpkt(zkanji): empty string/file"
argument_list|,
literal|""
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
name|ffc
operator|++
expr_stmt|;
name|rt
operator|=
name|x
expr_stmt|;
block|}
else|else
block|{
endif|#
directive|endif
comment|/* KANJI */
endif|#
directive|endif
comment|/* not NOCSETS */
if|if
condition|(
name|memstr
condition|)
block|{
comment|/* Reading data from memory string */
if|if
condition|(
operator|(
name|rt
operator|=
operator|*
name|memptr
operator|++
operator|)
operator|==
literal|'\0'
condition|)
block|{
comment|/* end of string ==> EOF */
name|first
operator|=
operator|-
literal|1
expr_stmt|;
name|size
operator|=
literal|0
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"getpkt: empty string"
argument_list|,
literal|""
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
else|else
block|{
comment|/* Reading data from a file */
if|if
condition|(
operator|(
name|x
operator|=
name|zminchar
argument_list|()
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* End of file or input error */
name|first
operator|=
operator|-
literal|1
expr_stmt|;
name|size
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|x
operator|==
operator|-
literal|2
condition|)
block|{
comment|/* Error */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"getpkt: input error"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|cxseen
operator|=
literal|1
expr_stmt|;
comment|/* Interrupt the file transfer */
block|}
else|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"getpkt: empty file"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Empty file */
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|ffc
operator|++
expr_stmt|;
comment|/* Count a file character */
name|rt
operator|=
name|x
expr_stmt|;
comment|/* Convert int to char */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getpkt zminchar"
argument_list|,
literal|""
argument_list|,
name|rt
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|NOCSETS
ifdef|#
directive|ifdef
name|KANJI
block|}
endif|#
directive|endif
comment|/* KANJI */
endif|#
directive|endif
comment|/* not NOCSETS */
name|rt
operator|&=
name|fmask
expr_stmt|;
comment|/* Apply SET FILE BYTESIZE mask */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getpkt fmask"
argument_list|,
literal|""
argument_list|,
name|fmask
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getpkt new rt"
argument_list|,
literal|""
argument_list|,
name|rt
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOCSETS
if|if
condition|(
name|xlate
condition|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getpkt about to call translate function"
argument_list|,
literal|""
argument_list|,
name|rt
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tcharset"
argument_list|,
literal|""
argument_list|,
name|tcharset
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"fcharset"
argument_list|,
literal|""
argument_list|,
name|fcharset
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|KANJI
if|if
condition|(
name|tcharset
operator|!=
name|TC_JEUC
condition|)
endif|#
directive|endif
comment|/* KANJI */
if|if
condition|(
operator|!
name|binary
operator|&&
name|sx
operator|&&
name|xlate
condition|)
block|{
name|rt
operator|=
call|(
modifier|*
name|sx
call|)
argument_list|(
name|rt
argument_list|)
expr_stmt|;
comment|/* Translate */
name|debug
argument_list|(
name|F101
argument_list|,
literal|" translate function returns"
argument_list|,
literal|""
argument_list|,
name|rt
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* not NOCSETS */
comment|/* PWP: handling of NLCHAR is done later (in the while loop)... */
block|}
elseif|else
if|if
condition|(
operator|(
name|first
operator|==
operator|-
literal|1
operator|)
operator|&&
operator|(
operator|*
name|leftover
operator|==
literal|'\0'
operator|)
condition|)
comment|/* EOF from last time? */
return|return
operator|(
name|size
operator|=
literal|0
operator|)
return|;
comment|/*   Here we handle characters that were encoded for the last packet but   did not fit, and so were saved in the "leftover" array. */
name|dp
operator|=
name|data
expr_stmt|;
comment|/* Point to packet data buffer */
for|for
control|(
name|p1
operator|=
name|leftover
init|;
operator|(
operator|*
name|dp
operator|=
operator|*
name|p1
operator|)
operator|!=
literal|'\0'
condition|;
name|p1
operator|++
operator|,
name|dp
operator|++
control|)
comment|/* Copy leftovers */
empty_stmt|;
operator|*
name|leftover
operator|=
literal|'\0'
expr_stmt|;
comment|/* Delete leftovers */
if|if
condition|(
name|first
operator|==
operator|-
literal|1
condition|)
comment|/* Handle EOF */
return|return
operator|(
name|size
operator|=
operator|(
name|dp
operator|-
name|data
operator|)
operator|)
return|;
comment|/* Now fill up the rest of the packet. */
name|rpt
operator|=
literal|0
expr_stmt|;
comment|/* Initialize character repeat count */
while|while
condition|(
name|first
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* Until EOF... */
ifndef|#
directive|ifndef
name|NOCSETS
ifdef|#
directive|ifdef
name|KANJI
if|if
condition|(
operator|!
name|binary
operator|&&
name|xlate
operator|&&
name|tcharset
operator|==
name|TC_JEUC
condition|)
block|{
if|if
condition|(
operator|(
name|x
operator|=
name|zkanji
argument_list|(
name|memstr
condition|?
name|kgetm
else|:
name|kgetf
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|first
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|x
operator|==
operator|-
literal|2
condition|)
name|cxseen
operator|=
literal|1
expr_stmt|;
block|}
name|ffc
operator|++
expr_stmt|;
name|rnext
operator|=
name|x
operator|&
name|fmask
expr_stmt|;
block|}
else|else
block|{
endif|#
directive|endif
comment|/* KANJI */
endif|#
directive|endif
comment|/* not NOCSETS */
if|if
condition|(
name|memstr
condition|)
block|{
comment|/* Get next char from memory string */
if|if
condition|(
operator|(
name|x
operator|=
operator|*
name|memptr
operator|++
operator|)
operator|==
literal|'\0'
condition|)
comment|/* End of string means EOF */
name|first
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Flag EOF for next time. */
name|rnext
operator|=
name|x
operator|&
name|fmask
expr_stmt|;
comment|/* Apply file mask */
block|}
else|else
block|{
if|if
condition|(
operator|(
name|x
operator|=
name|zminchar
argument_list|()
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* Real file, check for EOF */
name|first
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Flag eof for next time. */
if|if
condition|(
name|x
operator|==
operator|-
literal|2
condition|)
name|cxseen
operator|=
literal|1
expr_stmt|;
comment|/* If error, cancel this file. */
block|}
name|rnext
operator|=
name|x
operator|&
name|fmask
expr_stmt|;
comment|/* Apply file mask */
block|}
name|ffc
operator|++
expr_stmt|;
comment|/* Count the character */
ifndef|#
directive|ifndef
name|NOCSETS
ifdef|#
directive|ifdef
name|KANJI
block|}
endif|#
directive|endif
comment|/* KANJI */
endif|#
directive|endif
comment|/* not NOCSETS */
comment|/*** debug(F101,"getpkt rnext","",rnext); ***/
ifndef|#
directive|ifndef
name|NOCSETS
ifdef|#
directive|ifdef
name|KANJI
if|if
condition|(
name|tcharset
operator|!=
name|TC_JEUC
condition|)
endif|#
directive|endif
comment|/* KANJI */
if|if
condition|(
operator|!
name|binary
operator|&&
name|sx
operator|&&
name|xlate
condition|)
block|{
name|rnext
operator|=
call|(
modifier|*
name|sx
call|)
argument_list|(
name|rnext
argument_list|)
expr_stmt|;
comment|/* Translate */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getpkt xlated rnext to"
argument_list|,
literal|""
argument_list|,
name|rnext
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* not NOCSETS */
name|odp
operator|=
name|dp
expr_stmt|;
comment|/* Remember where we started. */
name|xxls
operator|=
name|xxdl
operator|=
name|xxrc
operator|=
name|xxss
operator|=
name|xxcq
operator|=
name|NUL
expr_stmt|;
comment|/* Clear these. */
comment|/*   Now encode the character according to the options that are in effect:     binary: text or binary mode.     rptflg: repeat counts enabled.     ebqflg: 8th-bit prefixing enabled.     lscapu: locking shifts enabled. */
if|if
condition|(
name|rptflg
condition|)
block|{
comment|/* Repeat processing is on? */
if|if
condition|(
ifdef|#
directive|ifdef
name|NLCHAR
comment|/* 		 * If the next char is really CRLF, then we cannot 		 * be doing a repeat (unless CR,CR,LF which becomes 		 * "~<n-1> CR CR LF", which is OK but not most efficient). 		 * I just plain don't worry about this case.  The actual 		 * conversion from NL to CRLF is done after the rptflg if... 		 */
operator|(
name|binary
operator|||
operator|(
name|rnext
operator|!=
name|NLCHAR
operator|)
operator|)
operator|&&
endif|#
directive|endif
comment|/* NLCHAR */
operator|(
name|rt
operator|==
name|rnext
operator|)
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
block|{
comment|/* Below max, just count */
continue|continue;
comment|/* go back and get another */
block|}
elseif|else
if|if
condition|(
name|rpt
operator|==
literal|94
condition|)
block|{
comment|/* Reached max, must dump */
name|xxrc
operator|=
name|tochar
argument_list|(
name|rpt
argument_list|)
expr_stmt|;
comment|/* Put the repeat count here */
name|rptn
operator|+=
name|rpt
expr_stmt|;
comment|/* Accumulate it for statistics */
name|rpt
operator|=
literal|0
expr_stmt|;
comment|/* And reset it */
block|}
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
name|xxrc
operator|=
name|tochar
argument_list|(
operator|++
name|rpt
argument_list|)
expr_stmt|;
comment|/* and count. */
name|rptn
operator|+=
name|rpt
expr_stmt|;
name|rpt
operator|=
literal|0
expr_stmt|;
comment|/* Reset repeat counter. */
block|}
comment|/* 	      If (rpt == 1) we must encode exactly two characters. 	      This is done later, after the first character is encoded. 	    */
block|}
ifdef|#
directive|ifdef
name|NLCHAR
if|if
condition|(
operator|!
name|binary
operator|&&
operator|(
name|rt
operator|==
name|NLCHAR
operator|)
condition|)
block|{
comment|/* It's the newline character */
if|if
condition|(
name|lscapu
operator|&&
name|lsstate
condition|)
block|{
comment|/* If SHIFT-STATE is SHIFTED */
if|if
condition|(
name|ebqflg
condition|)
block|{
comment|/* If single shifts enabled, */
operator|*
name|dp
operator|++
operator|=
name|ebq
expr_stmt|;
comment|/* insert a single shift. */
block|}
else|else
block|{
comment|/* Otherwise must shift in. */
operator|*
name|dp
operator|++
operator|=
name|myctlq
expr_stmt|;
comment|/* Insert shift-out code */
operator|*
name|dp
operator|++
operator|=
literal|'O'
expr_stmt|;
name|lsstate
operator|=
literal|0
expr_stmt|;
comment|/* Change shift state */
block|}
block|}
operator|*
name|dp
operator|++
operator|=
name|myctlq
expr_stmt|;
comment|/* Insert carriage return directly */
operator|*
name|dp
operator|++
operator|=
literal|'M'
expr_stmt|;
name|rt
operator|=
name|LF
expr_stmt|;
comment|/* Now make next char be linefeed. */
block|}
endif|#
directive|endif
comment|/* NLCHAR */
comment|/*   Now handle the 8th bit of the file character.  If we have an 8-bit   connection, we preserve the 8th bit.  If we have a 7-bit connection,   we employ either single or locking shifts (if they are enabled). */
name|a7
operator|=
name|rt
operator|&
literal|0177
expr_stmt|;
comment|/* Get low 7 bits of character */
if|if
condition|(
name|rt
operator|&
literal|0200
condition|)
block|{
comment|/* 8-bit character? */
if|if
condition|(
name|lscapu
condition|)
block|{
comment|/* Locking shifts enabled? */
if|if
condition|(
operator|!
name|lsstate
condition|)
block|{
comment|/* Not currently shifted? */
name|x
operator|=
name|lslook
argument_list|(
literal|0200
argument_list|)
expr_stmt|;
comment|/* Look ahead */
if|if
condition|(
name|x
operator|!=
literal|0
operator|||
name|ebqflg
operator|==
literal|0
condition|)
block|{
comment|/* Locking shift decision */
name|xxls
operator|=
literal|'N'
expr_stmt|;
comment|/* Need locking shift-out */
name|lsstate
operator|=
literal|1
expr_stmt|;
comment|/* and change to shifted state */
block|}
elseif|else
if|if
condition|(
name|ebqflg
condition|)
block|{
comment|/* Not worth it */
name|xxss
operator|=
name|ebq
expr_stmt|;
comment|/* Use single shift */
block|}
block|}
name|rt
operator|=
name|a7
expr_stmt|;
comment|/* Replace character by 7-bit value */
block|}
elseif|else
if|if
condition|(
name|ebqflg
condition|)
block|{
comment|/* 8th bit prefixing is on? */
name|xxss
operator|=
name|ebq
expr_stmt|;
comment|/* Insert single shift */
name|rt
operator|=
name|a7
expr_stmt|;
comment|/* Replace character by 7-bit value */
block|}
block|}
elseif|else
if|if
condition|(
name|lscapu
condition|)
block|{
comment|/* 7-bit character */
if|if
condition|(
name|lsstate
condition|)
block|{
comment|/* Comes while shifted out? */
name|x
operator|=
name|lslook
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Yes, look ahead */
if|if
condition|(
name|x
operator|||
name|ebqflg
operator|==
literal|0
condition|)
block|{
comment|/* Time to shift in. */
name|xxls
operator|=
literal|'O'
expr_stmt|;
comment|/* Set shift-in code */
name|lsstate
operator|=
literal|0
expr_stmt|;
comment|/* Exit shifted state */
block|}
elseif|else
if|if
condition|(
name|ebqflg
condition|)
block|{
comment|/* Not worth it, stay shifted out */
name|xxss
operator|=
name|ebq
expr_stmt|;
comment|/* Insert single shift */
block|}
block|}
block|}
comment|/* If data character is significant to locking shift protocol... */
if|if
condition|(
name|lscapu
operator|&&
operator|(
name|a7
operator|==
name|SO
operator|||
name|a7
operator|==
name|SI
operator|||
name|a7
operator|==
name|DLE
operator|)
condition|)
name|xxdl
operator|=
literal|'P'
expr_stmt|;
comment|/* Insert datalink escape */
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
comment|/* Do control prefixing if necessary */
name|xxcq
operator|=
name|myctlq
expr_stmt|;
comment|/* The prefix */
name|rt
operator|=
name|ctl
argument_list|(
name|rt
argument_list|)
expr_stmt|;
comment|/* Uncontrollify the character */
block|}
if|if
condition|(
name|a7
operator|==
name|myctlq
condition|)
comment|/* Always prefix the control prefix */
name|xxcq
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
name|xxcq
operator|=
name|myctlq
expr_stmt|;
comment|/* prefix it if doing repeat counts */
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
comment|/* Prefix the 8th-bit prefix */
name|xxcq
operator|=
name|myctlq
expr_stmt|;
comment|/* if doing 8th-bit prefixes */
comment|/* Now construct the entire sequence */
if|if
condition|(
name|xxls
condition|)
block|{
operator|*
name|dp
operator|++
operator|=
name|myctlq
expr_stmt|;
operator|*
name|dp
operator|++
operator|=
name|xxls
expr_stmt|;
block|}
comment|/* Locking shift */
name|odp2
operator|=
name|dp
expr_stmt|;
comment|/* (Save this place) */
if|if
condition|(
name|xxdl
condition|)
block|{
operator|*
name|dp
operator|++
operator|=
name|myctlq
expr_stmt|;
operator|*
name|dp
operator|++
operator|=
name|xxdl
expr_stmt|;
block|}
comment|/* Datalink escape */
if|if
condition|(
name|xxrc
condition|)
block|{
operator|*
name|dp
operator|++
operator|=
name|rptq
expr_stmt|;
operator|*
name|dp
operator|++
operator|=
name|xxrc
expr_stmt|;
block|}
comment|/* Repeat count */
if|if
condition|(
name|xxss
condition|)
block|{
operator|*
name|dp
operator|++
operator|=
name|ebq
expr_stmt|;
block|}
comment|/* Single shift */
if|if
condition|(
name|xxcq
condition|)
block|{
operator|*
name|dp
operator|++
operator|=
name|myctlq
expr_stmt|;
block|}
comment|/* Control prefix */
operator|*
name|dp
operator|++
operator|=
name|rt
expr_stmt|;
comment|/* Finally, the character itself */
if|if
condition|(
name|rpt
operator|==
literal|1
condition|)
block|{
comment|/* Exactly two copies? */
name|rpt
operator|=
literal|0
expr_stmt|;
name|p2
operator|=
name|dp
expr_stmt|;
comment|/* Save place temporarily */
for|for
control|(
name|p1
operator|=
name|odp2
init|;
name|p1
operator|<
name|p2
condition|;
name|p1
operator|++
control|)
comment|/* Copy the old chars over again */
operator|*
name|dp
operator|++
operator|=
operator|*
name|p1
expr_stmt|;
if|if
condition|(
operator|(
name|p2
operator|-
name|data
operator|)
operator|<=
name|bufmax
condition|)
name|odp
operator|=
name|p2
expr_stmt|;
comment|/* Check packet bounds */
block|}
name|rt
operator|=
name|rnext
expr_stmt|;
comment|/* Next character is now current. */
comment|/* Done encoding the character.  Now take care of packet buffer overflow. */
if|if
condition|(
operator|(
name|dp
operator|-
name|data
operator|)
operator|>=
name|bufmax
condition|)
block|{
comment|/* If too big, save some for next. */
name|size
operator|=
operator|(
name|dp
operator|-
name|data
operator|)
expr_stmt|;
comment|/* Calculate the size. */
operator|*
name|dp
operator|=
literal|'\0'
expr_stmt|;
comment|/* Mark the end. */
if|if
condition|(
operator|(
name|dp
operator|-
name|data
operator|)
operator|>
name|bufmax
condition|)
block|{
comment|/* if packet is overfull */
comment|/* copy the part that doesn't fit into the leftover buffer, */
comment|/* taking care not to split a prefixed sequence. */
for|for
control|(
name|p1
operator|=
name|leftover
operator|,
name|p2
operator|=
name|odp
init|;
operator|(
operator|*
name|p1
operator|=
operator|*
name|p2
operator|)
operator|!=
literal|'\0'
condition|;
name|p1
operator|++
operator|,
name|p2
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
operator|(
name|odp
operator|-
name|data
operator|)
argument_list|)
expr_stmt|;
name|size
operator|=
operator|(
name|odp
operator|-
name|data
operator|)
expr_stmt|;
comment|/* Return truncated packet. */
operator|*
name|odp
operator|=
literal|'\0'
expr_stmt|;
comment|/* Mark the new end */
block|}
name|t
operator|=
name|rt
expr_stmt|;
name|next
operator|=
name|rnext
expr_stmt|;
comment|/* save for next time */
return|return
operator|(
name|size
operator|)
return|;
block|}
block|}
comment|/* Otherwise, keep filling. */
name|size
operator|=
operator|(
name|dp
operator|-
name|data
operator|)
expr_stmt|;
comment|/* End of file */
operator|*
name|dp
operator|=
literal|'\0'
expr_stmt|;
comment|/* Mark the end of the data. */
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
end_function

begin_escape
end_escape

begin_comment
comment|/*  T I N I T  --  Initialize a transaction  */
end_comment

begin_function
name|int
name|tinit
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
ifndef|#
directive|ifndef
name|NOCSETS
if|if
condition|(
name|tcharset
operator|==
name|TC_TRANSP
condition|)
block|{
comment|/* Character set translation */
name|rx
operator|=
name|sx
operator|=
name|NULL
expr_stmt|;
comment|/* Transparent, no translation */
ifdef|#
directive|ifdef
name|KANJI
block|}
elseif|else
if|if
condition|(
name|tcharset
operator|==
name|TC_JEUC
condition|)
block|{
name|rx
operator|=
name|sx
operator|=
name|NULL
expr_stmt|;
comment|/* Transparent, no translation */
endif|#
directive|endif
comment|/* KANJI */
block|}
else|else
block|{
comment|/* otherwise */
name|rx
operator|=
name|xlr
index|[
name|tcharset
index|]
index|[
name|fcharset
index|]
expr_stmt|;
comment|/* Input translation function */
name|sx
operator|=
name|xls
index|[
name|tcharset
index|]
index|[
name|fcharset
index|]
expr_stmt|;
comment|/* Output translation function */
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tinit tcharset"
argument_list|,
literal|""
argument_list|,
name|tcharset
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tinit fcharset"
argument_list|,
literal|""
argument_list|,
name|fcharset
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|COMMENT
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tinit sx   "
argument_list|,
literal|""
argument_list|,
name|sx
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tinit rx   "
argument_list|,
literal|""
argument_list|,
name|rx
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
endif|#
directive|endif
comment|/* NOCSETS */
name|myinit
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* Haven't sent init string yet */
name|autopar
operator|=
literal|0
expr_stmt|;
comment|/* Automatic parity detection flag */
name|retrans
operator|=
literal|0
expr_stmt|;
comment|/* Packet retransmission count */
name|sndtyp
operator|=
literal|0
expr_stmt|;
comment|/* No previous packet */
name|xflg
operator|=
literal|0
expr_stmt|;
comment|/* Reset x-packet flag */
name|rqf
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Reset 8th-bit-quote request flag */
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
name|bctl
operator|=
literal|1
expr_stmt|;
comment|/* Reset block check type to 1 */
name|ebq
operator|=
name|MYEBQ
expr_stmt|;
comment|/* Reset 8th-bit quoting stuff */
name|ebqflg
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|savmod
condition|)
block|{
comment|/* If global file mode was saved, */
name|binary
operator|=
name|savmod
expr_stmt|;
comment|/*  restore it, */
name|savmod
operator|=
literal|0
expr_stmt|;
comment|/*  unsave it. */
block|}
name|pktnum
operator|=
literal|0
expr_stmt|;
comment|/* Initial packet number */
name|cxseen
operator|=
name|czseen
operator|=
name|discard
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
name|spktl
operator|=
literal|0
expr_stmt|;
comment|/* And its length */
name|nakstate
operator|=
literal|0
expr_stmt|;
comment|/* Assume not in a NAK'ing state */
name|numerrs
operator|=
literal|0
expr_stmt|;
comment|/* Transmission error counter */
if|if
condition|(
name|server
condition|)
comment|/* If acting as server, */
name|timint
operator|=
name|srvtim
expr_stmt|;
comment|/* Use server timeout interval. */
else|else
comment|/* Otherwise */
name|timint
operator|=
name|chktimo
argument_list|(
name|rtimo
argument_list|,
name|timef
argument_list|)
expr_stmt|;
comment|/* Begin by using local value */
name|spsiz
operator|=
name|spsizr
expr_stmt|;
comment|/* Initial send-packet size */
name|wslots
operator|=
literal|1
expr_stmt|;
comment|/* One window slot */
name|wslotn
operator|=
literal|1
expr_stmt|;
comment|/* No window negotiated yet */
name|winlo
operator|=
literal|0
expr_stmt|;
comment|/* Packet 0 is at window-low */
name|x
operator|=
name|mksbuf
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Make a 1-slot send-packet buffer */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
name|x
operator|=
name|getsbuf
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Allocate first send-buffer. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tinit getsbuf"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
name|dumpsbuf
argument_list|()
expr_stmt|;
name|x
operator|=
name|mkrbuf
argument_list|(
name|wslots
argument_list|)
expr_stmt|;
comment|/*& a 1-slot receive-packet buffer. */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
name|what
operator|=
name|W_NOTHING
expr_stmt|;
comment|/* Doing nothing so far... */
name|lsstate
operator|=
literal|0
expr_stmt|;
comment|/* Initialize locking shift state */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|VOID
name|pktinit
parameter_list|()
block|{
comment|/* Initialize packet sequence */
name|pktnum
operator|=
literal|0
expr_stmt|;
comment|/* number& window low. */
name|winlo
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  R I N I T  --  Respond to S or I packet  */
end_comment

begin_function
name|VOID
name|rinit
parameter_list|(
name|d
parameter_list|)
name|CHAR
modifier|*
name|d
decl_stmt|;
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
literal|0L
argument_list|)
expr_stmt|;
comment|/* Make transaction log entry */
if|if
condition|(
name|binary
condition|)
name|tlog
argument_list|(
name|F100
argument_list|,
literal|"Global file mode = binary"
argument_list|,
literal|""
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
else|else
name|tlog
argument_list|(
name|F100
argument_list|,
literal|"Global file mode = text"
argument_list|,
literal|""
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
name|filcnt
operator|=
literal|0
expr_stmt|;
comment|/* Init file counter */
name|spar
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|ack1
argument_list|(
name|rpar
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|datageneral
if|if
condition|(
operator|(
name|local
operator|)
operator|&&
operator|(
operator|!
name|quiet
operator|)
condition|)
comment|/* Only do this if local& not quiet */
name|consta_mt
argument_list|()
expr_stmt|;
comment|/* Start the asynch read task */
endif|#
directive|endif
comment|/* datageneral */
block|}
end_function

begin_comment
comment|/*  R E S E T C  --  Reset per-transaction character counters */
end_comment

begin_function
name|VOID
name|resetc
parameter_list|()
block|{
name|rptn
operator|=
literal|0
expr_stmt|;
comment|/* Repeat counts */
name|fsecs
operator|=
name|flci
operator|=
name|flco
operator|=
literal|0L
expr_stmt|;
comment|/* File chars in and out */
name|tfc
operator|=
name|tlci
operator|=
name|tlco
operator|=
literal|0L
expr_stmt|;
comment|/* Total file, line chars in& out */
ifdef|#
directive|ifdef
name|COMMENT
name|fsize
operator|=
operator|-
literal|1L
expr_stmt|;
comment|/* File size */
else|#
directive|else
if|if
condition|(
name|what
operator|!=
name|W_SEND
condition|)
name|fsize
operator|=
operator|-
literal|1L
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"resetc fsize"
argument_list|,
literal|""
argument_list|,
name|fsize
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
name|timeouts
operator|=
name|retrans
operator|=
literal|0
expr_stmt|;
comment|/* Timeouts, retransmissions */
name|spackets
operator|=
name|rpackets
operator|=
literal|0
expr_stmt|;
comment|/* Packet counts out& in */
name|crunched
operator|=
literal|0
expr_stmt|;
comment|/* Crunched packets */
name|wmax
operator|=
literal|1
expr_stmt|;
comment|/* Maximum window size used */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  S I N I T  --  Get& verify first file name, then send Send-Init packet */
end_comment

begin_comment
comment|/*  Returns:    1 if send operation begins successfully    0 if send operation fails */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|cmargbuf
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
name|cmargbuf
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cmargp
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|sinit
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
comment|/* Worker int */
name|char
modifier|*
name|tp
decl_stmt|,
modifier|*
name|xp
decl_stmt|,
modifier|*
name|m
decl_stmt|;
comment|/* Worker string pointers */
name|filcnt
operator|=
literal|0
expr_stmt|;
comment|/* Initialize file counter */
name|sndsrc
operator|=
name|nfils
expr_stmt|;
comment|/* Source for filenames */
ifdef|#
directive|ifdef
name|DYNAMIC
if|if
condition|(
operator|!
name|cmargbuf
operator|&&
operator|!
operator|(
name|cmargbuf
operator|=
name|malloc
argument_list|(
literal|256
argument_list|)
operator|)
condition|)
name|fatal
argument_list|(
literal|"sinit: no memory for cmargbuf"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DYNAMIC */
name|cmargbuf
index|[
literal|0
index|]
operator|=
name|NUL
expr_stmt|;
comment|/* Initialize name buffer */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sinit nfils"
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
literal|"sinit cmarg"
argument_list|,
name|cmarg
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"sinit cmarg2"
argument_list|,
name|cmarg2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|nfils
operator|==
literal|0
condition|)
block|{
comment|/* Sending from stdin or memory. */
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
name|cmarg
operator|=
name|cmarg2
expr_stmt|;
comment|/* If F packet, "as-name" is used */
name|cmarg2
operator|=
literal|""
expr_stmt|;
comment|/* if provided */
block|}
else|else
name|cmarg
operator|=
literal|"stdin"
expr_stmt|;
comment|/* otherwise just use "stdin" */
name|strcpy
argument_list|(
name|cmargbuf
argument_list|,
name|cmarg
argument_list|)
expr_stmt|;
name|cmargp
index|[
literal|0
index|]
operator|=
name|cmargbuf
expr_stmt|;
name|cmargp
index|[
literal|1
index|]
operator|=
literal|""
expr_stmt|;
name|cmlist
operator|=
name|cmargp
expr_stmt|;
name|nfils
operator|=
literal|1
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|COMMENT
if|if
condition|(
name|nfils
operator|<
literal|1
condition|)
block|{
comment|/* Filespec pointed to by cmarg */
if|if
condition|(
name|nfils
operator|<
literal|0
condition|)
name|sndsrc
operator|=
literal|1
expr_stmt|;
name|nfils
operator|=
literal|1
expr_stmt|;
comment|/* Change it to cmlist */
name|strcpy
argument_list|(
name|cmargbuf
argument_list|,
name|cmarg
argument_list|)
expr_stmt|;
comment|/* so we have a consistent way */
name|cmargp
index|[
literal|0
index|]
operator|=
name|cmargbuf
expr_stmt|;
comment|/* of going thru the file list. */
name|cmargp
index|[
literal|1
index|]
operator|=
literal|""
expr_stmt|;
name|cmlist
operator|=
name|cmargp
expr_stmt|;
block|}
comment|/* At this point, cmlist contains the list of filespecs to send */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"sinit *cmlist"
argument_list|,
operator|*
name|cmlist
argument_list|,
name|nfils
argument_list|)
expr_stmt|;
name|xp
operator|=
operator|*
name|cmlist
expr_stmt|;
comment|/* Save this for messages */
else|#
directive|else
name|xp
operator|=
operator|(
name|nfils
operator|<
literal|0
operator|)
condition|?
name|cmarg
else|:
operator|*
name|cmlist
expr_stmt|;
endif|#
directive|endif
name|x
operator|=
name|gnfile
argument_list|()
expr_stmt|;
comment|/* Get first filename. */
name|m
operator|=
name|NULL
expr_stmt|;
comment|/* Error message pointer */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sinit gnfil"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|x
condition|)
block|{
case|case
operator|-
literal|5
case|:
name|m
operator|=
literal|"Too many files match wildcard"
expr_stmt|;
break|break;
case|case
operator|-
literal|4
case|:
name|m
operator|=
literal|"Cancelled"
expr_stmt|;
break|break;
case|case
operator|-
literal|3
case|:
name|m
operator|=
literal|"Read access denied"
expr_stmt|;
break|break;
case|case
operator|-
literal|2
case|:
name|m
operator|=
literal|"File is not readable"
expr_stmt|;
break|break;
case|case
operator|-
literal|1
case|:
name|m
operator|=
name|iswild
argument_list|(
name|filnam
argument_list|)
condition|?
literal|"No files match"
else|:
literal|"File not found"
expr_stmt|;
break|break;
case|case
literal|0
case|:
name|m
operator|=
literal|"No filespec given!"
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sinit nfils"
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
literal|"sinit filnam"
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
literal|"sinit cmdstr"
argument_list|,
name|cmdstr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|1
condition|)
block|{
comment|/* Didn't get a file. */
if|if
condition|(
name|server
condition|)
comment|/* Doing GET command */
name|errpkt
argument_list|(
operator|(
name|CHAR
operator|*
operator|)
name|m
argument_list|)
expr_stmt|;
comment|/* so send Error packet. */
else|else
comment|/* Doing SEND command */
name|screen
argument_list|(
name|SCR_EM
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
name|m
argument_list|)
expr_stmt|;
comment|/* so print message. */
name|tlog
argument_list|(
name|F110
argument_list|,
name|xp
argument_list|,
name|m
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
comment|/* Make transaction log entry. */
name|freerbuf
argument_list|(
name|rseqtbl
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* Free the buffer the GET came in. */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Return failure code */
block|}
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
comment|/* Delay if requested */
ifdef|#
directive|ifdef
name|datageneral
if|if
condition|(
operator|(
name|local
operator|)
operator|&&
operator|(
operator|!
name|quiet
operator|)
condition|)
comment|/* Only do this if local& not quiet */
name|consta_mt
argument_list|()
expr_stmt|;
comment|/* Start the asynch read task */
endif|#
directive|endif
comment|/* datageneral */
name|freerbuf
argument_list|(
name|rseqtbl
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* Free the buffer the GET came in. */
name|sipkt
argument_list|(
literal|'S'
argument_list|)
expr_stmt|;
comment|/* Send the Send-Init packet. */
name|ztime
argument_list|(
operator|&
name|tp
argument_list|)
expr_stmt|;
comment|/* Get current date/time */
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Transaction begins"
argument_list|,
name|tp
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
comment|/* Make transaction log entry */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"sinit ok"
argument_list|,
name|filnam
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
end_function

begin_function
name|int
ifdef|#
directive|ifdef
name|CK_ANSIC
name|sipkt
parameter_list|(
name|char
name|c
parameter_list|)
comment|/* Send S or I packet. */
else|#
directive|else
function|sipkt
parameter_list|(
name|c
parameter_list|)
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* sipkt */
block|{
name|CHAR
modifier|*
name|rp
decl_stmt|;
name|int
name|k
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sipkt pktnum"
argument_list|,
literal|""
argument_list|,
name|pktnum
argument_list|)
expr_stmt|;
name|k
operator|=
name|sseqtbl
index|[
name|pktnum
index|]
expr_stmt|;
comment|/* Find slot for this packet */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sipkt k"
argument_list|,
literal|""
argument_list|,
name|k
argument_list|)
expr_stmt|;
if|if
condition|(
name|k
operator|<
literal|0
condition|)
block|{
comment|/* No slot? */
name|k
operator|=
name|getsbuf
argument_list|(
name|winlo
operator|=
name|pktnum
argument_list|)
expr_stmt|;
comment|/* Make one. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sipkt getsbuf"
argument_list|,
literal|""
argument_list|,
name|k
argument_list|)
expr_stmt|;
block|}
name|ttflui
argument_list|()
expr_stmt|;
comment|/* Flush pending input. */
name|rp
operator|=
name|rpar
argument_list|()
expr_stmt|;
comment|/* Get protocol parameters. */
return|return
operator|(
name|spack
argument_list|(
name|c
argument_list|,
name|pktnum
argument_list|,
operator|(
name|int
operator|)
name|strlen
argument_list|(
operator|(
name|char
operator|*
operator|)
name|rp
argument_list|)
argument_list|,
name|rp
argument_list|)
operator|)
return|;
comment|/* Send them. */
block|}
end_function

begin_comment
comment|/*  X S I N I T  --  Retransmit S-packet  */
end_comment

begin_comment
comment|/*   For use in the GET-SEND sequence, when we start to send, but receive another   copy of the GET command because the receiver didn't get our S packet.   This retransmits the S packet and frees the receive buffer for the ACK.   The only reason this special case is necessary is that packet number zero   is being re-used. */
end_comment

begin_function
name|VOID
name|xsinit
parameter_list|()
block|{
name|int
name|k
decl_stmt|;
name|k
operator|=
name|rseqtbl
index|[
literal|0
index|]
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"xsinit k"
argument_list|,
literal|""
argument_list|,
name|k
argument_list|)
expr_stmt|;
if|if
condition|(
name|k
operator|>
operator|-
literal|1
condition|)
name|freerbuf
argument_list|(
name|k
argument_list|)
expr_stmt|;
name|resend
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  R C V F I L -- Receive a file  */
end_comment

begin_comment
comment|/*   Incoming filename is in data field of F packet.   This function decodes it into the srvcmd buffer, substituting an   alternate "as-name", if one was given.   Then it does any requested transformations (like converting to   lowercase), and finally if a file of the same name already exists,    takes the desired collision action. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_define
define|#
directive|define
name|XNAMLEN
value|65
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XNAMLEN
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pdp11 */
end_comment

begin_function
name|int
name|rcvfil
parameter_list|(
name|n
parameter_list|)
name|char
modifier|*
name|n
decl_stmt|;
block|{
name|char
name|xname
index|[
name|XNAMLEN
index|]
decl_stmt|,
modifier|*
name|xp
decl_stmt|;
comment|/* Buffer for constructing name */
ifdef|#
directive|ifdef
name|DTILDE
name|char
modifier|*
name|dirp
decl_stmt|,
modifier|*
name|tilde_expand
argument_list|()
decl_stmt|;
endif|#
directive|endif
comment|/* DTILDE */
name|lsstate
operator|=
literal|0
expr_stmt|;
comment|/* Cancel locking-shift state */
name|srvptr
operator|=
name|srvcmd
expr_stmt|;
comment|/* Decode file name from packet. */
name|decode
argument_list|(
name|rdatap
argument_list|,
name|putsrv
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Don't xlate charsets. */
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
operator|(
name|char
operator|*
operator|)
name|srvcmd
argument_list|,
literal|"NONAME"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DTILDE
name|dirp
operator|=
name|tilde_expand
argument_list|(
operator|(
name|char
operator|*
operator|)
name|srvcmd
argument_list|)
expr_stmt|;
comment|/* Expand tilde, if any. */
if|if
condition|(
operator|*
name|dirp
operator|!=
literal|'\0'
condition|)
name|strcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|srvcmd
argument_list|,
name|dirp
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DTILDE */
name|screen
argument_list|(
name|SCR_FN
argument_list|,
literal|0
argument_list|,
literal|0l
argument_list|,
operator|(
name|char
operator|*
operator|)
name|srvcmd
argument_list|)
expr_stmt|;
comment|/* Put it on screen if local */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"rcvfil"
argument_list|,
operator|(
name|char
operator|*
operator|)
name|srvcmd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Debug log entry */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"rcvfil cmarg2"
argument_list|,
literal|""
argument_list|,
name|cmarg2
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Receiving"
argument_list|,
operator|(
name|char
operator|*
operator|)
name|srvcmd
argument_list|,
literal|0L
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
operator|(
name|char
operator|*
operator|)
name|srvcmd
argument_list|,
name|cmarg2
argument_list|)
expr_stmt|;
comment|/* Got one, use it. */
block|}
block|}
else|else
name|cmarg2
operator|=
literal|""
expr_stmt|;
comment|/*   NOTE: Much of this code should be moved to opena(), where the file is   actually opened, AFTER we have received the Attribute packet(s).  That   way, if the file is mail, or is being sent to the printer, we don't have   to fuss with collision options, etc, but instead we just pipe the data   straight into lpr or mail (in UNIX anyway), and then we can also have   nice subject lines for mail messages by using whatever is in the file   header packet data field, whether it's a legal filename or not. */
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
operator|(
name|char
operator|*
operator|)
name|srvcmd
argument_list|)
operator|>
name|XNAMLEN
condition|)
comment|/* Watch out for overflow */
operator|*
operator|(
name|srvcmd
operator|+
name|XNAMLEN
operator|-
literal|1
operator|)
operator|=
name|NUL
expr_stmt|;
name|xp
operator|=
name|xname
expr_stmt|;
comment|/* OK to proceed. */
if|if
condition|(
name|fncnv
operator|&&
operator|!
operator|*
name|cmarg2
condition|)
name|zrtol
argument_list|(
operator|(
name|char
operator|*
operator|)
name|srvcmd
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
operator|(
name|char
operator|*
operator|)
name|srvcmd
argument_list|)
expr_stmt|;
comment|/* use it literally */
name|cmarg2
operator|=
literal|""
expr_stmt|;
comment|/* Remove alternate name */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"rcvfil as"
argument_list|,
name|xname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|COMMENT
comment|/* Old code... */
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
endif|#
directive|endif
comment|/* COMMENT */
comment|/* Filename collision action section. */
if|if
condition|(
ifdef|#
directive|ifdef
name|UNIX
name|strcmp
argument_list|(
name|xname
argument_list|,
literal|"/dev/null"
argument_list|)
operator|&&
comment|/* It's not the null device? */
endif|#
directive|endif
comment|/* UNIX */
operator|(
name|zchki
argument_list|(
name|xname
argument_list|)
operator|!=
operator|-
literal|1
operator|)
comment|/* File of same name exists? */
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"rcvfil exists"
argument_list|,
name|xname
argument_list|,
name|fncact
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|fncact
condition|)
block|{
comment|/* Yes, do what user said. */
case|case
name|XYFX_A
case|:
comment|/* Append */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"rcvfil append"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|XYFX_Q
case|:
comment|/* Query (Ask) */
break|break;
comment|/* not yet implemented */
case|case
name|XYFX_B
case|:
comment|/* Backup (rename old file) */
name|znewn
argument_list|(
name|xname
argument_list|,
operator|&
name|xp
argument_list|)
expr_stmt|;
comment|/* Get new unique name */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"rcvfil backup"
argument_list|,
name|xname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"rcvfil backup"
argument_list|,
name|xp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|zrename
argument_list|(
name|xname
argument_list|,
name|xp
argument_list|)
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F110
argument_list|,
literal|"rcvfil rename fails"
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
break|break;
case|case
name|XYFX_D
case|:
comment|/* Discard (refuse new file) */
name|discard
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"rcvfil discard"
argument_list|,
literal|""
argument_list|,
name|discard
argument_list|)
expr_stmt|;
break|break;
comment|/* not yet implemented */
case|case
name|XYFX_R
case|:
comment|/* Rename new file */
name|znewn
argument_list|(
name|xname
argument_list|,
operator|&
name|xp
argument_list|)
expr_stmt|;
comment|/* Make new name. */
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
literal|"rcvfil rename"
argument_list|,
name|xname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
case|case
name|XYFX_X
case|:
comment|/* Replace old file */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"rcvfil overwrite"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|XYFX_U
case|:
comment|/* Refuse if older */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"rcvfil update"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
comment|/* Not here, we don't have */
comment|/* the attribute packet yet. */
default|default:
name|debug
argument_list|(
name|F101
argument_list|,
literal|"rcvfil bad collision action"
argument_list|,
literal|""
argument_list|,
name|fncact
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|debug
argument_list|(
name|F110
argument_list|,
literal|"rcvfil: xname"
argument_list|,
name|xname
argument_list|,
literal|0
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
name|xname
argument_list|)
expr_stmt|;
comment|/* Display it */
name|strcpy
argument_list|(
name|n
argument_list|,
name|xname
argument_list|)
expr_stmt|;
comment|/* Return pointer to actual name. */
ifndef|#
directive|ifndef
name|NOICP
ifndef|#
directive|ifndef
name|MAC
comment|/* Why not Mac? */
name|strcpy
argument_list|(
name|fspec
argument_list|,
name|xname
argument_list|)
expr_stmt|;
comment|/* Here too for \v(filespec) */
endif|#
directive|endif
comment|/* MAC */
endif|#
directive|endif
comment|/* NOICP */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"rcvfil: n"
argument_list|,
name|n
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ffc
operator|=
literal|0L
expr_stmt|;
comment|/* Init per-file counters */
name|fsecs
operator|=
name|gtimer
argument_list|()
expr_stmt|;
comment|/* Time this file started */
name|filcnt
operator|++
expr_stmt|;
name|intmsg
argument_list|(
name|filcnt
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Always succeeds */
block|}
end_function

begin_comment
comment|/*  R E O F  --  Receive End Of File packet for incoming file */
end_comment

begin_comment
comment|/*   Closes the received file.   Returns:     0 on success.    -1 if file could not be closed.     2 if disposition was mail, mail was sent, but temp file not deleted.     3 if disposition was print, file was printed, but not deleted.    -2 if disposition was mail and mail could not be sent    -3 if disposition was print and file could not be printed */
end_comment

begin_function
name|int
name|reof
parameter_list|(
name|f
parameter_list|,
name|yy
parameter_list|)
name|char
modifier|*
name|f
decl_stmt|;
name|struct
name|zattr
modifier|*
name|yy
decl_stmt|;
block|{
name|int
name|x
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|char
name|c
decl_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"reof fncact"
argument_list|,
name|f
argument_list|,
name|fncact
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"reof discard"
argument_list|,
literal|""
argument_list|,
name|discard
argument_list|)
expr_stmt|;
name|success
operator|=
literal|1
expr_stmt|;
comment|/* Assume status is OK */
name|lsstate
operator|=
literal|0
expr_stmt|;
comment|/* Cancel locking-shift state */
if|if
condition|(
ifdef|#
directive|ifdef
name|COMMENT
comment|/*   If the discard flag is set, for whatever reason, we discard it, right? */
operator|(
name|fncact
operator|==
name|XYFX_D
operator|||
name|fncact
operator|==
name|XYFX_U
operator|)
operator|&&
endif|#
directive|endif
comment|/* COMMENT */
name|discard
operator|!=
literal|0
condition|)
block|{
comment|/* SET FILE COLLISION DISCARD or UPDATE */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"reof discarding"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|discard
operator|=
literal|0
expr_stmt|;
comment|/* We never opened it, */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* so we won't close it. */
block|}
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
name|rdatap
operator|==
literal|'D'
operator|)
expr_stmt|;
comment|/* Got cancel directive? */
name|success
operator|=
operator|(
name|cxseen
operator|||
name|czseen
operator|)
condition|?
literal|0
else|:
literal|1
expr_stmt|;
comment|/* Set SUCCESS flag appropriately */
name|x
operator|=
name|clsof
argument_list|(
name|cxseen
operator|||
name|czseen
argument_list|)
expr_stmt|;
comment|/* Close the file (resets cxseen) */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|success
operator|=
literal|0
expr_stmt|;
comment|/* If failure to close, FAIL */
if|if
condition|(
name|atcapu
condition|)
name|zstime
argument_list|(
name|f
argument_list|,
name|yy
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Set file creation date */
comment|/* Handle dispositions from attribute packet... */
ifndef|#
directive|ifndef
name|NOFRILLS
if|if
condition|(
name|yy
operator|->
name|disp
operator|.
name|len
operator|!=
literal|0
condition|)
block|{
name|p
operator|=
name|yy
operator|->
name|disp
operator|.
name|val
expr_stmt|;
name|c
operator|=
operator|*
name|p
operator|++
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'M'
condition|)
block|{
comment|/* Mail to user. */
name|x
operator|=
name|zmail
argument_list|(
name|p
argument_list|,
name|filnam
argument_list|)
expr_stmt|;
comment|/* Do the system's mail command */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|success
operator|=
literal|0
expr_stmt|;
comment|/* Remember status */
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"mailed"
argument_list|,
name|filnam
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F110
argument_list|,
literal|" to"
argument_list|,
name|p
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
name|zdelet
argument_list|(
name|filnam
argument_list|)
expr_stmt|;
comment|/* Delete the file */
block|}
elseif|else
if|if
condition|(
name|c
operator|==
literal|'P'
condition|)
block|{
comment|/* Print the file. */
name|x
operator|=
name|zprint
argument_list|(
name|p
argument_list|,
name|filnam
argument_list|)
expr_stmt|;
comment|/* Do the system's print command */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|success
operator|=
literal|0
expr_stmt|;
comment|/* Remember status */
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"printed"
argument_list|,
name|filnam
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F110
argument_list|,
literal|" with options"
argument_list|,
name|p
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|VMS
if|if
condition|(
name|zdelet
argument_list|(
name|filnam
argument_list|)
operator|&&
name|x
operator|==
literal|0
condition|)
name|x
operator|=
literal|3
expr_stmt|;
comment|/* Delete the file */
endif|#
directive|endif
comment|/* VMS */
block|}
block|}
endif|#
directive|endif
comment|/* NOFRILLS */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"reof returns"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
operator|*
name|filnam
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  R E O T  --  Receive End Of Transaction  */
end_comment

begin_function
name|VOID
name|reot
parameter_list|()
block|{
name|cxseen
operator|=
name|czseen
operator|=
name|discard
operator|=
literal|0
expr_stmt|;
comment|/* Reset interruption flags */
name|tstats
argument_list|()
expr_stmt|;
block|}
end_function

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

begin_function
name|int
name|sfile
parameter_list|(
name|x
parameter_list|)
name|int
name|x
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|pdp11
define|#
directive|define
name|PKTNL
value|64
else|#
directive|else
define|#
directive|define
name|PKTNL
value|256
endif|#
directive|endif
comment|/* pdp11 */
name|char
name|pktnam
index|[
name|PKTNL
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Local copy of name */
name|char
modifier|*
name|s
decl_stmt|;
name|lsstate
operator|=
literal|0
expr_stmt|;
comment|/* Cancel locking-shift state */
if|if
condition|(
name|nxtpkt
argument_list|()
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Bump packet number, get buffer */
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
name|strncpy
argument_list|(
name|pktnam
argument_list|,
name|cmarg2
argument_list|,
name|PKTNL
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
name|strncpy
argument_list|(
name|pktnam
argument_list|,
name|filnam
argument_list|,
name|PKTNL
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
name|encstr
argument_list|(
operator|(
name|CHAR
operator|*
operator|)
name|s
argument_list|)
expr_stmt|;
comment|/* Encode the name into encbuf[]. */
comment|/* Send the F or X packet */
name|spack
argument_list|(
call|(
name|char
call|)
argument_list|(
name|x
condition|?
literal|'X'
else|:
literal|'F'
argument_list|)
argument_list|,
name|pktnum
argument_list|,
name|size
argument_list|,
name|encbuf
operator|+
literal|7
argument_list|)
expr_stmt|;
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
literal|0L
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
literal|0L
argument_list|)
expr_stmt|;
if|if
condition|(
name|binary
condition|)
block|{
comment|/* Log file mode in transaction log */
name|tlog
argument_list|(
name|F101
argument_list|,
literal|" mode: binary"
argument_list|,
literal|""
argument_list|,
operator|(
name|long
operator|)
name|binary
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* If text mode, check character set */
name|tlog
argument_list|(
name|F100
argument_list|,
literal|" mode: text"
argument_list|,
literal|""
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOCSETS
name|tlog
argument_list|(
name|F110
argument_list|,
literal|" file character set"
argument_list|,
name|fcsinfo
index|[
name|fcharset
index|]
operator|.
name|name
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
if|if
condition|(
name|tcharset
operator|==
name|TC_TRANSP
condition|)
name|tlog
argument_list|(
name|F110
argument_list|,
literal|" xfer character set"
argument_list|,
literal|"transparent"
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
else|else
name|tlog
argument_list|(
name|F110
argument_list|,
literal|" xfer character set"
argument_list|,
name|tcsinfo
index|[
name|tcharset
index|]
operator|.
name|name
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOCSETS */
block|}
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
literal|0L
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
name|ffc
operator|=
literal|0L
expr_stmt|;
comment|/* Init file character counter. */
name|fsecs
operator|=
name|gtimer
argument_list|()
expr_stmt|;
comment|/* Time this file started */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"SFILE fsecs"
argument_list|,
literal|""
argument_list|,
name|fsecs
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  S D A T A -- Send a data packet */
end_comment

begin_comment
comment|/*   Returns -1 if no data to send (end of file).  If there is data, a data   packet is sent, and sdata() returns 1.    For window size greater than 1, keep sending data packets until window   is full or characters start to appear from the other Kermit, whichever   happens first.    In the windowing case, when there is no more data left to send (or when   sending has been interrupted), sdata() does nothing and returns 0 each time   it is called until the current packet number catches up to the last data   packet that was sent. */
end_comment

begin_function
name|int
name|sdata
parameter_list|()
block|{
name|int
name|i
decl_stmt|,
name|x
decl_stmt|,
name|len
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sdata entry, first"
argument_list|,
literal|""
argument_list|,
name|first
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" drain"
argument_list|,
literal|""
argument_list|,
name|drain
argument_list|)
expr_stmt|;
comment|/* The "drain" flag is used with window size> 1.  It means we have sent  */
comment|/* our last data packet.  If called and drain is not zero, then we return */
comment|/* 0 as if we had sent an empty data packet, until all data packets have  */
comment|/* been ACK'd, then then we can finally return -1 indicating EOF, so that */
comment|/* the protocol can switch to seof state.  This is a kludge, but at least */
comment|/* it's localized...  */
if|if
condition|(
name|first
operator|==
literal|1
condition|)
name|drain
operator|=
literal|0
expr_stmt|;
comment|/* Start of file, init drain flag. */
if|if
condition|(
name|drain
condition|)
block|{
comment|/* If draining... */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sdata draining, winlo"
argument_list|,
literal|""
argument_list|,
name|winlo
argument_list|)
expr_stmt|;
if|if
condition|(
name|winlo
operator|==
name|pktnum
condition|)
comment|/* If all data packets are ACK'd */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* return EOF indication */
else|else
comment|/* otherwise */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* pretend we sent a data packet. */
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sdata sbufnum"
argument_list|,
literal|""
argument_list|,
name|sbufnum
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|sbufnum
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sdata countdown"
argument_list|,
literal|""
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|x
operator|=
name|nxtpkt
argument_list|()
expr_stmt|;
comment|/* Get next pkt number and buffer */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sdata packet"
argument_list|,
literal|""
argument_list|,
name|pktnum
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/***	dumpsbuf(); */
if|if
condition|(
name|cxseen
operator|||
name|czseen
condition|)
block|{
comment|/* If interrupted, done. */
if|if
condition|(
name|wslots
operator|>
literal|1
condition|)
block|{
name|drain
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sdata cx/zseen, drain"
argument_list|,
literal|""
argument_list|,
name|cxseen
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
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
ifdef|#
directive|ifdef
name|COMMENT
if|if
condition|(
name|spsiz
operator|>
literal|94
condition|)
comment|/* Fill the packet's data buffer */
name|len
operator|=
name|getpkt
argument_list|(
name|spsiz
operator|-
name|bctl
operator|-
literal|6
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* long packet */
else|else
comment|/*  or */
name|len
operator|=
name|getpkt
argument_list|(
name|spsiz
operator|-
name|bctl
operator|-
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* short packet */
else|#
directive|else
name|len
operator|=
name|getpkt
argument_list|(
name|spsiz
argument_list|,
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
if|if
condition|(
name|len
operator|==
literal|0
condition|)
block|{
comment|/* Done if no data. */
if|if
condition|(
name|pktnum
operator|==
name|winlo
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|drain
operator|=
literal|1
expr_stmt|;
comment|/* But can't return -1 until all */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sdata eof, drain"
argument_list|,
literal|""
argument_list|,
name|drain
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
comment|/* ACKs are drained. */
block|}
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
comment|/* Send the data packet. */
name|x
operator|=
name|ttchk
argument_list|()
expr_stmt|;
comment|/* Peek at input buffer. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sdata ttchk"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|/* ACKs waiting, maybe?  */
if|if
condition|(
name|x
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Yes, stop sending data packets */
block|}
comment|/* and go try to read the ACKs. */
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  S E O F -- Send an End-Of-File packet */
end_comment

begin_comment
comment|/*  Call with a string pointer to character to put in the data field, */
end_comment

begin_comment
comment|/*  or else a null pointer or "" for no data.  */
end_comment

begin_comment
comment|/*   There are two "send-eof" functions.  seof() is used to send the normal eof   packet at the end of a file's data (even if the file has no data), or when   a file transfer is interrupted.  sxeof() is used to send an EOF packet that   occurs because of attribute refusal.  The difference is purely a matter of   buffer allocation and packet sequence number management.  Both functions   act as "front ends" to the common send-eof function, szeof(). */
end_comment

begin_comment
comment|/* Code common to both seof() and sxeof() */
end_comment

begin_function
name|int
name|szeof
parameter_list|(
name|s
parameter_list|)
name|CHAR
modifier|*
name|s
decl_stmt|;
block|{
name|lsstate
operator|=
literal|0
expr_stmt|;
comment|/* Cancel locking-shift state */
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
literal|0L
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
operator|(
name|CHAR
operator|*
operator|)
literal|""
argument_list|)
expr_stmt|;
block|}
name|discard
operator|=
literal|0
expr_stmt|;
comment|/* Turn off per-file discard flag */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|seof
parameter_list|(
name|s
parameter_list|)
name|CHAR
modifier|*
name|s
decl_stmt|;
block|{
comment|/*   ckcpro.w, before calling seof(), sets window size back to 1 and then calls   window(), which clears out the old buffers.  This is OK because the final   data packet for the file has been ACK'd.  However, sdata() has already   called nxtpkt(), which set the new value of pktnum which seof() will use.   So all we need to do here is is allocate a new send-buffer. */
if|if
condition|(
name|getsbuf
argument_list|(
name|pktnum
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Get a buffer for packet n */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"seof can't get s-buffer"
argument_list|,
literal|""
argument_list|,
name|pktnum
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
name|szeof
argument_list|(
name|s
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*   Version of seof() to be called when sdata() has not been called before.  The   difference is that this version calls nxtpkt() to allocate a send-buffer and   get the next packet number. */
end_comment

begin_function
name|int
name|sxeof
parameter_list|(
name|s
parameter_list|)
name|CHAR
modifier|*
name|s
decl_stmt|;
block|{
name|int
name|x
decl_stmt|;
name|x
operator|=
name|nxtpkt
argument_list|()
expr_stmt|;
comment|/* Get next pkt number and buffer */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sxeof nxtpkt fails"
argument_list|,
literal|""
argument_list|,
name|pktnum
argument_list|)
expr_stmt|;
else|else
name|debug
argument_list|(
name|F101
argument_list|,
literal|"sxeof packet"
argument_list|,
literal|""
argument_list|,
name|pktnum
argument_list|)
expr_stmt|;
return|return
operator|(
name|szeof
argument_list|(
name|s
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  S E O T -- Send an End-Of-Transaction packet */
end_comment

begin_function
name|int
name|seot
parameter_list|()
block|{
if|if
condition|(
name|nxtpkt
argument_list|()
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Bump packet number, get buffer */
name|spack
argument_list|(
literal|'B'
argument_list|,
name|pktnum
argument_list|,
literal|0
argument_list|,
operator|(
name|CHAR
operator|*
operator|)
literal|""
argument_list|)
expr_stmt|;
comment|/* Send the EOT packet */
name|cxseen
operator|=
name|czseen
operator|=
name|discard
operator|=
literal|0
expr_stmt|;
comment|/* Reset interruption flags */
name|tstats
argument_list|()
expr_stmt|;
comment|/* Log timing info */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*   R P A R -- Fill the data array with my send-init parameters  */
end_comment

begin_decl_stmt
name|CHAR
name|dada
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use this instead of data[]. */
end_comment

begin_comment
comment|/* To avoid some kind of wierd */
end_comment

begin_comment
comment|/* addressing foulup in spack()... */
end_comment

begin_comment
comment|/* (which might be fixed now...) */
end_comment

begin_function
name|CHAR
modifier|*
name|rpar
parameter_list|()
block|{
if|if
condition|(
name|rpsiz
operator|>
name|MAXPACK
condition|)
comment|/* Biggest normal packet I want. */
name|dada
index|[
literal|0
index|]
operator|=
name|tochar
argument_list|(
name|MAXPACK
argument_list|)
expr_stmt|;
comment|/* If> 94, use 94, but specify */
else|else
comment|/* extended packet length below... */
name|dada
index|[
literal|0
index|]
operator|=
name|tochar
argument_list|(
name|rpsiz
argument_list|)
expr_stmt|;
comment|/* else use what the user said. */
name|dada
index|[
literal|1
index|]
operator|=
name|tochar
argument_list|(
name|chktimo
argument_list|(
name|pkttim
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|/* When I want to be timed out */
name|dada
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
name|dada
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
name|dada
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
name|dada
index|[
literal|5
index|]
operator|=
literal|'#'
expr_stmt|;
comment|/* Control-Quote character I send */
switch|switch
condition|(
name|rqf
condition|)
block|{
comment|/* 8th-bit prefix */
case|case
operator|-
literal|1
case|:
case|case
literal|1
case|:
if|if
condition|(
name|parity
condition|)
name|ebq
operator|=
name|sq
operator|=
literal|'&'
expr_stmt|;
break|break;
case|case
literal|0
case|:
case|case
literal|2
case|:
break|break;
block|}
name|debug
argument_list|(
name|F000
argument_list|,
literal|"rpar 8bq sq"
argument_list|,
literal|""
argument_list|,
name|sq
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F000
argument_list|,
literal|"rpar 8bq ebq"
argument_list|,
literal|""
argument_list|,
name|ebq
argument_list|)
expr_stmt|;
if|if
condition|(
name|lscapu
operator|==
literal|2
condition|)
comment|/* LOCKING-SHIFT FORCED */
name|dada
index|[
literal|6
index|]
operator|=
literal|'N'
expr_stmt|;
comment|/* means no single-shift */
else|else
name|dada
index|[
literal|6
index|]
operator|=
name|sq
expr_stmt|;
name|dada
index|[
literal|7
index|]
operator|=
operator|(
name|bctr
operator|==
literal|4
operator|)
condition|?
literal|'B'
else|:
name|bctr
operator|+
literal|'0'
expr_stmt|;
comment|/* Block check type */
if|if
condition|(
name|rptflg
condition|)
comment|/* Run length encoding */
name|dada
index|[
literal|8
index|]
operator|=
name|rptq
expr_stmt|;
comment|/* If receiving, agree. */
else|else
name|dada
index|[
literal|8
index|]
operator|=
literal|'~'
expr_stmt|;
comment|/* CAPAS mask */
name|dada
index|[
literal|9
index|]
operator|=
name|tochar
argument_list|(
operator|(
name|lscapr
condition|?
name|lscapb
else|:
literal|0
operator|)
operator||
comment|/* Locking shifts */
operator|(
name|atcapr
condition|?
name|atcapb
else|:
literal|0
operator|)
operator||
comment|/* Attribute packets */
operator|(
name|lpcapr
condition|?
name|lpcapb
else|:
literal|0
operator|)
operator||
comment|/* Long packets */
operator|(
name|swcapr
condition|?
name|swcapb
else|:
literal|0
operator|)
argument_list|)
expr_stmt|;
comment|/* Sliding windows */
name|dada
index|[
literal|10
index|]
operator|=
name|tochar
argument_list|(
name|swcapr
condition|?
name|wslotr
else|:
literal|1
argument_list|)
expr_stmt|;
comment|/* Window size */
name|rpsiz
operator|=
name|urpsiz
operator|-
literal|1
expr_stmt|;
comment|/* Long packets ... */
name|dada
index|[
literal|11
index|]
operator|=
name|tochar
argument_list|(
name|rpsiz
operator|/
literal|95
argument_list|)
expr_stmt|;
comment|/* Long packet size, big part */
name|dada
index|[
literal|12
index|]
operator|=
name|tochar
argument_list|(
name|rpsiz
operator|%
literal|95
argument_list|)
expr_stmt|;
comment|/* Long packet size, little part */
name|dada
index|[
literal|13
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* Terminate the init string */
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|deblog
condition|)
block|{
name|debug
argument_list|(
name|F110
argument_list|,
literal|"rpar"
argument_list|,
name|dada
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|rdebu
argument_list|(
name|dada
argument_list|,
operator|(
name|int
operator|)
name|strlen
argument_list|(
operator|(
name|char
operator|*
operator|)
name|dada
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* DEBUG */
name|strcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|myinit
argument_list|,
operator|(
name|char
operator|*
operator|)
name|dada
argument_list|)
expr_stmt|;
return|return
operator|(
name|dada
operator|)
return|;
comment|/* Return pointer to string. */
block|}
end_function

begin_escape
end_escape

begin_function
name|int
name|spar
parameter_list|(
name|s
parameter_list|)
name|CHAR
modifier|*
name|s
decl_stmt|;
block|{
comment|/* Set parameters */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|lpsiz
decl_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"entering spar"
argument_list|,
name|s
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|s
operator|--
expr_stmt|;
comment|/* Line up with field numbers. */
comment|/* Limit on size of outbound packets */
name|x
operator|=
operator|(
name|rln
operator|>=
literal|1
operator|)
condition|?
name|xunchar
argument_list|(
name|s
index|[
literal|1
index|]
argument_list|)
else|:
literal|80
expr_stmt|;
name|lpsiz
operator|=
name|spsizr
expr_stmt|;
comment|/* Remember what they SET. */
if|if
condition|(
name|spsizf
condition|)
block|{
comment|/* SET-command override? */
if|if
condition|(
name|x
operator|<
name|spsizr
condition|)
name|spsiz
operator|=
name|x
expr_stmt|;
comment|/* Ignore LEN unless smaller */
block|}
else|else
block|{
comment|/* otherwise */
name|spsiz
operator|=
operator|(
name|x
operator|<
literal|10
operator|)
condition|?
literal|80
else|:
name|x
expr_stmt|;
comment|/* believe them if reasonable */
block|}
name|spmax
operator|=
name|spsiz
expr_stmt|;
comment|/* Remember maximum size */
comment|/* Timeout on inbound packets */
if|if
condition|(
name|timef
condition|)
block|{
name|timint
operator|=
name|rtimo
expr_stmt|;
comment|/* SET SEND TIMEOUT value overrides */
block|}
else|else
block|{
comment|/* Otherwise use requested value, */
name|x
operator|=
operator|(
name|rln
operator|>=
literal|2
operator|)
condition|?
name|xunchar
argument_list|(
name|s
index|[
literal|2
index|]
argument_list|)
else|:
name|rtimo
expr_stmt|;
comment|/* if it is legal. */
name|timint
operator|=
operator|(
name|x
operator|<
literal|0
operator|)
condition|?
name|rtimo
else|:
name|x
expr_stmt|;
block|}
name|timint
operator|=
name|chktimo
argument_list|(
name|timint
argument_list|,
name|timef
argument_list|)
expr_stmt|;
comment|/* Adjust if necessary */
comment|/* Outbound Padding */
name|npad
operator|=
literal|0
expr_stmt|;
name|padch
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|rln
operator|>=
literal|3
condition|)
block|{
name|npad
operator|=
name|xunchar
argument_list|(
name|s
index|[
literal|3
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|rln
operator|>=
literal|4
condition|)
name|padch
operator|=
name|ctl
argument_list|(
name|s
index|[
literal|4
index|]
argument_list|)
expr_stmt|;
else|else
name|padch
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|npad
condition|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|npad
condition|;
name|i
operator|++
control|)
name|padbuf
index|[
name|i
index|]
operator|=
name|dopar
argument_list|(
name|padch
argument_list|)
expr_stmt|;
block|}
comment|/* Outbound Packet Terminator */
name|seol
operator|=
operator|(
name|rln
operator|>=
literal|5
operator|)
condition|?
name|xunchar
argument_list|(
name|s
index|[
literal|5
index|]
argument_list|)
else|:
name|CR
expr_stmt|;
if|if
condition|(
operator|(
name|seol
operator|<
literal|2
operator|)
operator|||
operator|(
name|seol
operator|>
literal|31
operator|)
condition|)
name|seol
operator|=
name|CR
expr_stmt|;
comment|/* Control prefix */
name|x
operator|=
operator|(
name|rln
operator|>=
literal|6
operator|)
condition|?
name|s
index|[
literal|6
index|]
else|:
literal|'#'
expr_stmt|;
name|myctlq
operator|=
operator|(
operator|(
name|x
operator|>
literal|32
operator|&&
name|x
operator|<
literal|63
operator|)
operator|||
operator|(
name|x
operator|>
literal|95
operator|&&
name|x
operator|<
literal|127
operator|)
operator|)
condition|?
name|x
else|:
literal|'#'
expr_stmt|;
comment|/* 8th-bit prefix */
name|rq
operator|=
operator|(
name|rln
operator|>=
literal|7
operator|)
condition|?
name|s
index|[
literal|7
index|]
else|:
literal|0
expr_stmt|;
if|if
condition|(
name|rq
operator|==
literal|'Y'
condition|)
name|rqf
operator|=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|rq
operator|>
literal|32
operator|&&
name|rq
operator|<
literal|63
operator|)
operator|||
operator|(
name|rq
operator|>
literal|95
operator|&&
name|rq
operator|<
literal|127
operator|)
condition|)
name|rqf
operator|=
literal|2
expr_stmt|;
else|else
name|rqf
operator|=
literal|0
expr_stmt|;
name|debug
argument_list|(
name|F000
argument_list|,
literal|"spar 8bq rq"
argument_list|,
literal|""
argument_list|,
name|rq
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F000
argument_list|,
literal|"spar 8bq sq"
argument_list|,
literal|""
argument_list|,
name|sq
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F000
argument_list|,
literal|"spar 8bq ebq"
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
literal|"spar 8bq rqf"
argument_list|,
literal|""
argument_list|,
name|rqf
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|rqf
condition|)
block|{
case|case
literal|0
case|:
name|ebqflg
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|1
case|:
if|if
condition|(
name|parity
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
break|break;
case|case
literal|2
case|:
if|if
condition|(
name|ebqflg
operator|=
operator|(
name|ebq
operator|==
name|sq
operator|||
name|sq
operator|==
literal|'Y'
operator|)
condition|)
name|ebq
operator|=
name|rq
expr_stmt|;
block|}
if|if
condition|(
name|lscapu
operator|==
literal|2
condition|)
block|{
comment|/* No single-shifts if LOCKING-SHIFT FORCED */
name|ebqflg
operator|=
literal|0
expr_stmt|;
name|ebq
operator|=
literal|'N'
expr_stmt|;
block|}
comment|/* Block check */
name|x
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|rln
operator|>=
literal|8
condition|)
block|{
if|if
condition|(
name|s
index|[
literal|8
index|]
operator|==
literal|'B'
condition|)
name|x
operator|=
literal|4
expr_stmt|;
else|else
name|x
operator|=
name|s
index|[
literal|8
index|]
operator|-
literal|'0'
expr_stmt|;
if|if
condition|(
operator|(
name|x
operator|<
literal|1
operator|)
operator|||
operator|(
name|x
operator|>
literal|4
operator|)
condition|)
name|x
operator|=
literal|1
expr_stmt|;
block|}
name|bctr
operator|=
name|x
expr_stmt|;
comment|/* Repeat prefix */
if|if
condition|(
name|rln
operator|>=
literal|9
condition|)
block|{
name|rptq
operator|=
name|s
index|[
literal|9
index|]
expr_stmt|;
name|rptflg
operator|=
operator|(
operator|(
name|rptq
operator|>
literal|32
operator|&&
name|rptq
operator|<
literal|63
operator|)
operator|||
operator|(
name|rptq
operator|>
literal|95
operator|&&
name|rptq
operator|<
literal|127
operator|)
operator|)
expr_stmt|;
block|}
else|else
name|rptflg
operator|=
literal|0
expr_stmt|;
comment|/* Capabilities */
name|atcapu
operator|=
name|lpcapu
operator|=
name|swcapu
operator|=
literal|0
expr_stmt|;
comment|/* Assume none of these */
if|if
condition|(
name|lscapu
operator|!=
literal|2
condition|)
name|lscapu
operator|=
literal|0
expr_stmt|;
comment|/* Assume no LS unless forced. */
name|y
operator|=
literal|11
expr_stmt|;
comment|/* Position of next field, if any */
if|if
condition|(
name|rln
operator|>=
literal|10
condition|)
block|{
name|x
operator|=
name|xunchar
argument_list|(
name|s
index|[
literal|10
index|]
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar capas"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|atcapu
operator|=
operator|(
name|x
operator|&
name|atcapb
operator|)
operator|&&
name|atcapr
expr_stmt|;
name|lpcapu
operator|=
operator|(
name|x
operator|&
name|lpcapb
operator|)
operator|&&
name|lpcapr
expr_stmt|;
name|swcapu
operator|=
operator|(
name|x
operator|&
name|swcapb
operator|)
operator|&&
name|swcapr
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar lscapu"
argument_list|,
literal|""
argument_list|,
name|lscapu
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar lscapr"
argument_list|,
literal|""
argument_list|,
name|lscapr
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar ebqflg"
argument_list|,
literal|""
argument_list|,
name|ebqflg
argument_list|)
expr_stmt|;
if|if
condition|(
name|lscapu
operator|!=
literal|2
condition|)
name|lscapu
operator|=
operator|(
operator|(
name|x
operator|&
name|lscapb
operator|)
operator|&&
name|lscapr
operator|&&
name|ebqflg
operator|)
condition|?
literal|1
else|:
literal|0
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar swcapr"
argument_list|,
literal|""
argument_list|,
name|swcapr
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar swcapu"
argument_list|,
literal|""
argument_list|,
name|swcapu
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar lscapu"
argument_list|,
literal|""
argument_list|,
name|lscapu
argument_list|)
expr_stmt|;
for|for
control|(
name|y
operator|=
literal|10
init|;
operator|(
name|xunchar
argument_list|(
name|s
index|[
name|y
index|]
argument_list|)
operator|&
literal|1
operator|)
operator|&&
operator|(
name|rln
operator|>=
name|y
operator|)
condition|;
name|y
operator|++
control|)
empty_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar y"
argument_list|,
literal|""
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
comment|/* Long Packets */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar lpcapu"
argument_list|,
literal|""
argument_list|,
name|lpcapu
argument_list|)
expr_stmt|;
if|if
condition|(
name|lpcapu
condition|)
block|{
if|if
condition|(
name|rln
operator|>
name|y
operator|+
literal|1
condition|)
block|{
name|x
operator|=
name|xunchar
argument_list|(
name|s
index|[
name|y
operator|+
literal|2
index|]
argument_list|)
operator|*
literal|95
operator|+
name|xunchar
argument_list|(
name|s
index|[
name|y
operator|+
literal|3
index|]
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar lp len"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|spsizf
condition|)
block|{
comment|/* If overriding negotiations */
name|spsiz
operator|=
operator|(
name|x
operator|<
name|lpsiz
operator|)
condition|?
name|x
else|:
name|lpsiz
expr_stmt|;
comment|/* do this, */
block|}
else|else
block|{
comment|/* otherwise */
name|spsiz
operator|=
operator|(
name|x
operator|>
name|MAXSP
operator|)
condition|?
name|MAXSP
else|:
name|x
expr_stmt|;
comment|/* do this. */
block|}
if|if
condition|(
name|spsiz
operator|<
literal|10
condition|)
name|spsiz
operator|=
literal|80
expr_stmt|;
comment|/* Be defensive... */
block|}
block|}
comment|/* (PWP) save current send packet size for optimal packet size calcs */
name|spmax
operator|=
name|spsiz
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar lp spmax"
argument_list|,
literal|""
argument_list|,
name|spmax
argument_list|)
expr_stmt|;
name|timint
operator|=
name|chktimo
argument_list|(
name|timint
argument_list|,
name|timef
argument_list|)
expr_stmt|;
comment|/* Recalculate the packet timeout! */
comment|/* Sliding Windows... */
if|if
condition|(
name|swcapr
condition|)
block|{
comment|/* Only if requested... */
if|if
condition|(
name|rln
operator|>
name|y
condition|)
block|{
comment|/* See what other Kermit says */
name|x
operator|=
name|xunchar
argument_list|(
name|s
index|[
name|y
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar window"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|wslotn
operator|=
operator|(
name|x
operator|>
name|MAXWS
operator|)
condition|?
name|MAXWS
else|:
name|x
expr_stmt|;
comment|/*   wslotn = negotiated size (from other Kermit's S or I packet).   wslotr = requested window size (from this Kermit's SET WINDOW command). */
if|if
condition|(
name|wslotn
operator|>
name|wslotr
condition|)
comment|/* Use the smaller of the two */
name|wslotn
operator|=
name|wslotr
expr_stmt|;
if|if
condition|(
name|wslotn
operator|<
literal|1
condition|)
comment|/* Watch out for bad negotiation */
name|wslotn
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|wslotn
operator|>
literal|1
condition|)
name|swcapu
operator|=
literal|1
expr_stmt|;
comment|/* We do windows... */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar window after adjustment"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* No window size specified. */
name|wslotn
operator|=
literal|1
expr_stmt|;
comment|/* We don't do windows... */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar window"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|swcapu
operator|=
literal|0
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar no windows"
argument_list|,
literal|""
argument_list|,
name|wslotn
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Now recalculate packet length based on number of windows.   */
comment|/* The nogotiated number of window slots will be allocated,    */
comment|/* and the maximum packet length will be reduced if necessary, */
comment|/* so that a windowful of packets can fit in the big buffer.   */
if|if
condition|(
name|wslotn
operator|>
literal|1
condition|)
block|{
comment|/* Shrink to fit... */
name|x
operator|=
name|adjpkl
argument_list|(
name|spsiz
argument_list|,
name|wslotn
argument_list|,
name|bigsbsiz
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
name|spsiz
condition|)
block|{
name|spsiz
operator|=
name|spmax
operator|=
name|x
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"spar sending, redefine spsiz"
argument_list|,
literal|""
argument_list|,
name|spsiz
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* Record parameters in debug log */
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|deblog
condition|)
name|sdebu
argument_list|(
name|rln
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
name|numerrs
operator|=
literal|0
expr_stmt|;
comment|/* Start counting errors here. */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  G N F I L E  --  Get name of next file to send  */
end_comment

begin_comment
comment|/*   Expects global sndsrc to be:    -1: next filename to be obtained by calling znext().     0: no next file name     1: (or greater) next filename to be obtained from **cmlist.   Returns:     1, with name of next file in filnam.     0, no more files, with filnam set to empty string.    -1, file not found    -2, file is not readable    -3, read access denied    -4, cancelled    -5, too many files match wildcard */
end_comment

begin_function
name|int
name|gnfile
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|long
name|y
decl_stmt|;
name|int
name|retcode
init|=
literal|0
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"gnfile sndsrc"
argument_list|,
literal|""
argument_list|,
name|sndsrc
argument_list|)
expr_stmt|;
name|fsize
operator|=
operator|-
literal|1L
expr_stmt|;
comment|/* Initialize file size */
if|if
condition|(
name|sndsrc
operator|==
literal|0
condition|)
block|{
comment|/* It's not really a file */
if|if
condition|(
name|nfils
operator|>
literal|0
condition|)
block|{
comment|/* It's a pipe, or stdin */
name|strcpy
argument_list|(
name|filnam
argument_list|,
operator|*
name|cmlist
argument_list|)
expr_stmt|;
comment|/* Copy its "name" */
name|nfils
operator|=
literal|0
expr_stmt|;
comment|/* There is no next file */
return|return
operator|(
literal|1
operator|)
return|;
comment|/* OK this time */
block|}
else|else
return|return
operator|(
literal|0
operator|)
return|;
comment|/* but not next time */
block|}
comment|/* If file group interruption (C-Z) occurred, fail.  */
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
literal|0L
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"gnfile czseen"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|4
operator|)
return|;
block|}
comment|/* Loop through file list till we find a readable, sendable file */
name|y
operator|=
operator|-
literal|1L
expr_stmt|;
comment|/* Loop exit (file size) variable */
while|while
condition|(
name|y
operator|<
literal|0L
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
comment|/* File list in cmlist */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"gnfile nfils"
argument_list|,
literal|""
argument_list|,
name|nfils
argument_list|)
expr_stmt|;
if|if
condition|(
name|nfils
operator|--
operator|>
literal|0
condition|)
block|{
comment|/* Still some left? */
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
literal|"gnfile cmlist filnam"
argument_list|,
name|filnam
argument_list|,
name|nfils
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|clfils
condition|)
block|{
comment|/* Expand only if not from cmdline */
name|x
operator|=
name|zxpand
argument_list|(
name|filnam
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"gnfile zxpand"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|1
condition|)
block|{
name|znext
argument_list|(
name|filnam
argument_list|)
expr_stmt|;
goto|goto
name|gotnam
goto|;
block|}
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{
name|retcode
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* None match */
continue|continue;
block|}
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|5
operator|)
return|;
comment|/* Too many to expand */
name|sndsrc
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Change send-source to znext() */
block|}
block|}
else|else
block|{
comment|/* We're out of files. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"gnfile done"
argument_list|,
literal|""
argument_list|,
name|nfils
argument_list|)
expr_stmt|;
operator|*
name|filnam
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|retcode
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
literal|"gnfile znext"
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
block|{
comment|/* If no more, */
name|sndsrc
operator|=
literal|1
expr_stmt|;
comment|/* go back to list */
continue|continue;
block|}
block|}
comment|/* Get here with a filename. */
name|gotnam
label|:
if|if
condition|(
name|sndsrc
condition|)
block|{
name|y
operator|=
name|zchki
argument_list|(
name|filnam
argument_list|)
expr_stmt|;
comment|/* Check if file readable */
name|retcode
operator|=
operator|(
name|int
operator|)
name|y
expr_stmt|;
comment|/* Possible return code */
if|if
condition|(
name|y
operator|==
operator|-
literal|1L
condition|)
block|{
comment|/* If not found */
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
continue|continue;
block|}
elseif|else
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
continue|continue;
block|}
else|else
block|{
name|fsize
operator|=
name|y
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
else|else
return|return
operator|(
literal|1
operator|)
return|;
comment|/* sndsrc is 0... */
block|}
operator|*
name|filnam
operator|=
literal|'\0'
expr_stmt|;
comment|/* Should never get here */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  S N D H L P  --  Routine to send builtin help  */
end_comment

begin_function
name|int
name|sndhlp
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|NOSERVER
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
name|savmod
operator|=
name|binary
expr_stmt|;
comment|/*  remember to restore it later. */
name|binary
operator|=
literal|0
expr_stmt|;
comment|/*  turn it back to text for this, */
block|}
return|return
operator|(
name|sinit
argument_list|()
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* NOSERVER */
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_comment
comment|/*  S N D S P A C E -- send disk space message  */
end_comment

begin_function
name|int
name|sndspace
parameter_list|(
name|int
name|drive
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|NOSERVER
specifier|static
name|char
name|spctext
index|[
literal|64
index|]
decl_stmt|;
if|if
condition|(
name|drive
condition|)
name|sprintf
argument_list|(
name|spctext
argument_list|,
literal|" Drive %c: %ldK free\n"
argument_list|,
name|drive
argument_list|,
name|zdskspace
argument_list|(
name|drive
operator|-
literal|'A'
operator|+
literal|1
argument_list|)
operator|/
literal|1024L
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|spctext
argument_list|,
literal|" Free space: %ldK\n"
argument_list|,
name|zdskspace
argument_list|(
literal|0
argument_list|)
operator|/
literal|1024L
argument_list|)
expr_stmt|;
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
literal|"free space"
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
name|spctext
expr_stmt|;
comment|/* And the pointer. */
if|if
condition|(
name|binary
condition|)
block|{
comment|/* If file mode is binary, */
name|savmod
operator|=
name|binary
expr_stmt|;
comment|/*  remember to restore it later. */
name|binary
operator|=
literal|0
expr_stmt|;
comment|/*  turn it back to text for this, */
block|}
return|return
operator|(
name|sinit
argument_list|()
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* NOSERVER */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_comment
comment|/*  C W D  --  Change current working directory  */
end_comment

begin_comment
comment|/*  String passed has first byte as length of directory name, rest of string  is name.  Fails if can't connect, else ACKs (with name) and succeeds.  */
end_comment

begin_function
name|int
name|cwd
parameter_list|(
name|vdir
parameter_list|)
name|char
modifier|*
name|vdir
decl_stmt|;
block|{
name|char
modifier|*
name|cdd
decl_stmt|,
modifier|*
name|zgtdir
argument_list|()
decl_stmt|,
modifier|*
name|dirp
decl_stmt|;
name|vdir
index|[
name|xunchar
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
comment|/* Terminate string with a null */
name|dirp
operator|=
name|vdir
operator|+
literal|1
expr_stmt|;
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Directory requested: "
argument_list|,
name|dirp
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
if|if
condition|(
name|zchdir
argument_list|(
name|dirp
argument_list|)
condition|)
block|{
comment|/* Try to change */
name|cdd
operator|=
name|zgtdir
argument_list|()
expr_stmt|;
comment|/* Get new working directory. */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"cwd"
argument_list|,
name|cdd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|encstr
argument_list|(
operator|(
name|CHAR
operator|*
operator|)
name|cdd
argument_list|)
expr_stmt|;
name|ack1
argument_list|(
operator|(
name|CHAR
operator|*
operator|)
operator|(
name|encbuf
operator|+
literal|7
operator|)
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Changed directory to"
argument_list|,
name|cdd
argument_list|,
literal|0L
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
name|debug
argument_list|(
name|F110
argument_list|,
literal|"cwd failed"
argument_list|,
name|dirp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|tlog
argument_list|(
name|F110
argument_list|,
literal|"Failed to change directory to"
argument_list|,
name|dirp
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/*  S Y S C M D  --  Do a system command  */
end_comment

begin_comment
comment|/*  Command string is formed by concatenating the two arguments.  */
end_comment

begin_function
name|int
name|syscmd
parameter_list|(
name|prefix
parameter_list|,
name|suffix
parameter_list|)
name|char
modifier|*
name|prefix
decl_stmt|,
decl|*
name|suffix
decl_stmt|;
end_function

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
comment|/* copy suffix */
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
name|zxcmd
argument_list|(
name|ZIFILE
argument_list|,
name|cmdstr
argument_list|)
operator|>
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F110
argument_list|,
literal|"syscmd zxcmd ok"
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
comment|/* Flag that input is from stdin */
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
name|savmod
operator|=
name|binary
expr_stmt|;
comment|/*  remember to restore it later. */
name|binary
operator|=
literal|0
expr_stmt|;
comment|/*  turn it back to text for this, */
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
literal|"syscmd zxcmd failed"
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

begin_comment
comment|/*  R E M S E T  --  Remote Set  */
end_comment

begin_comment
comment|/*  Called by server to set variables as commanded in REMOTE SET packets.  */
end_comment

begin_comment
comment|/*  Returns 1 on success, 0 on failure.  */
end_comment

begin_function
name|int
name|remset
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|int
name|len
decl_stmt|,
name|i
decl_stmt|,
name|x
decl_stmt|,
name|y
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|len
operator|=
name|xunchar
argument_list|(
operator|*
name|s
operator|++
argument_list|)
expr_stmt|;
comment|/* Length of first field */
name|p
operator|=
name|s
operator|+
name|len
expr_stmt|;
comment|/* Pointer to second length field */
operator|*
name|p
operator|++
operator|=
literal|'\0'
expr_stmt|;
comment|/* Zero out second length field */
name|x
operator|=
name|atoi
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* Value of first field */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"remset"
argument_list|,
name|s
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"remset"
argument_list|,
name|p
argument_list|,
literal|0
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|x
condition|)
block|{
comment|/* Do the right thing */
case|case
literal|132
case|:
comment|/* Attributes (all, in) */
name|atcapr
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|133
case|:
comment|/* File length attributes */
case|case
literal|233
case|:
comment|/* IN/OUT combined */
case|case
literal|148
case|:
comment|/* Both kinds of lengths */
case|case
literal|248
case|:
name|atleni
operator|=
name|atleno
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|134
case|:
comment|/* File Type (text/binary) */
case|case
literal|234
case|:
name|attypi
operator|=
name|attypo
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|135
case|:
comment|/* File creation date */
case|case
literal|235
case|:
name|atdati
operator|=
name|atdato
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|139
case|:
comment|/* File Blocksize */
case|case
literal|239
case|:
name|atblki
operator|=
name|atblko
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|141
case|:
comment|/* Encoding / Character Set */
case|case
literal|241
case|:
name|atenci
operator|=
name|atenco
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|142
case|:
comment|/* Disposition */
case|case
literal|242
case|:
name|atdisi
operator|=
name|atdiso
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|145
case|:
comment|/* System ID */
case|case
literal|245
case|:
name|atsidi
operator|=
name|atsido
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|147
case|:
comment|/* System-Dependent Info */
case|case
literal|247
case|:
name|atsysi
operator|=
name|atsyso
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|232
case|:
comment|/* Attributes (all, out) */
name|atcapr
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|300
case|:
comment|/* File type (text, binary) */
name|binary
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|301
case|:
comment|/* File name conversion */
name|fncnv
operator|=
literal|1
operator|-
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* (oops) */
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|302
case|:
comment|/* File name collision */
name|x
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|==
name|XYFX_R
condition|)
name|warn
operator|=
literal|1
expr_stmt|;
comment|/* Rename */
if|if
condition|(
name|x
operator|==
name|XYFX_X
condition|)
name|warn
operator|=
literal|0
expr_stmt|;
comment|/* Replace */
name|fncact
operator|=
name|x
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|310
case|:
comment|/* Incomplete File Disposition */
name|keep
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* Keep, Discard */
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|311
case|:
comment|/* Blocksize */
name|fblksiz
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|312
case|:
comment|/* Record Length */
name|frecl
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|313
case|:
comment|/* Record format */
name|frecfm
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|314
case|:
comment|/* File organization */
name|forg
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|315
case|:
comment|/* File carriage control */
name|fcctrl
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|400
case|:
comment|/* Block check */
name|y
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|<
literal|5
operator|&&
name|y
operator|>
literal|0
condition|)
block|{
name|bctr
operator|=
name|y
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
elseif|else
if|if
condition|(
operator|*
name|p
operator|==
literal|'B'
condition|)
block|{
name|bctr
operator|=
literal|4
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|401
case|:
comment|/* Receive packet-length */
name|urpsiz
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|urpsiz
operator|>
name|MAXRP
condition|)
name|urpsiz
operator|=
name|MAXRP
expr_stmt|;
name|urpsiz
operator|=
name|adjpkl
argument_list|(
name|urpsiz
argument_list|,
name|wslots
argument_list|,
name|bigrbsiz
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|402
case|:
comment|/* Receive timeout */
name|y
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* Client is telling us */
if|if
condition|(
name|y
operator|>
operator|-
literal|1
operator|&&
name|y
operator|<
literal|999
condition|)
block|{
comment|/* the timeout that it wants */
name|pkttim
operator|=
name|chktimo
argument_list|(
name|y
argument_list|,
name|timef
argument_list|)
expr_stmt|;
comment|/* us to tell it to use. */
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|403
case|:
comment|/* Retry limit */
name|y
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|>
operator|-
literal|1
operator|&&
name|y
operator|<
literal|95
condition|)
block|{
name|maxtry
operator|=
name|y
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|404
case|:
comment|/* Server timeout */
name|y
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|srvtim
operator|=
name|y
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
ifndef|#
directive|ifndef
name|NOCSETS
case|case
literal|405
case|:
comment|/* Transfer character set */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ntcsets
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|tcsinfo
index|[
name|i
index|]
operator|.
name|designator
argument_list|,
name|p
argument_list|)
condition|)
break|break;
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"remset xfer charset lookup"
argument_list|,
literal|""
argument_list|,
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
name|ntcsets
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|tcharset
operator|=
name|tcsinfo
index|[
name|i
index|]
operator|.
name|code
expr_stmt|;
comment|/* if known, use it */
if|if
condition|(
name|tcharset
operator|==
name|TC_TRANSP
condition|)
name|rx
operator|=
name|NULL
expr_stmt|;
else|else
name|rx
operator|=
name|xlr
index|[
name|tcharset
index|]
index|[
name|fcharset
index|]
expr_stmt|;
comment|/* translation function */
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
comment|/* NOCSETS */
case|case
literal|406
case|:
comment|/* Window slots */
name|y
operator|=
name|atoi
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|==
literal|0
condition|)
name|y
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|y
operator|<
literal|1
operator|&&
name|y
operator|>
literal|31
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|wslotr
operator|=
name|y
expr_stmt|;
name|swcapr
operator|=
literal|1
expr_stmt|;
name|urpsiz
operator|=
name|adjpkl
argument_list|(
name|urpsiz
argument_list|,
name|wslots
argument_list|,
name|bigrbsiz
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
default|default:
comment|/* Anything else... */
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/* Adjust packet length based on number of window slots and buffer size */
end_comment

begin_function
name|int
name|adjpkl
parameter_list|(
name|pktlen
parameter_list|,
name|slots
parameter_list|,
name|bufsiz
parameter_list|)
name|int
name|pktlen
decl_stmt|,
name|slots
decl_stmt|,
name|bufsiz
decl_stmt|;
block|{
name|debug
argument_list|(
name|F101
argument_list|,
literal|"adjpkl len"
argument_list|,
literal|""
argument_list|,
name|pktlen
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"adjpkl slots"
argument_list|,
literal|""
argument_list|,
name|slots
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"adjpkl bufsiz"
argument_list|,
literal|""
argument_list|,
name|bufsiz
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|pktlen
operator|+
literal|6
operator|)
operator|*
name|slots
operator|)
operator|>
name|bufsiz
condition|)
name|pktlen
operator|=
operator|(
name|bufsiz
operator|/
name|slots
operator|)
operator|-
literal|6
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"adjpkl new len"
argument_list|,
literal|""
argument_list|,
name|pktlen
argument_list|)
expr_stmt|;
return|return
operator|(
name|pktlen
operator|)
return|;
block|}
end_function

end_unit

