begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|wartv
init|=
literal|"Wart Version 2A(009) 14 Jan 92"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MDEBUG
end_ifdef

begin_comment
comment|/* Use the real ones in this module only */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|malloc
end_ifdef

begin_undef
undef|#
directive|undef
name|malloc
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* malloc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|calloc
end_ifdef

begin_undef
undef|#
directive|undef
name|calloc
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* calloc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|realloc
end_ifdef

begin_undef
undef|#
directive|undef
name|realloc
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* realloc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|free
end_ifdef

begin_undef
undef|#
directive|undef
name|free
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* free */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MDEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_comment
comment|/* W A R T */
end_comment

begin_comment
comment|/*   A small subset of "lex".    Authors: Jeff Damens, Frank da Cruz   Columbia University Center for Computing Activites.   First released November 1984.   Copyright (C) 1984, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_comment
comment|/*  * input format is:  *  lines to be copied | %state<state names...>  *  %%  *<state> |<state,state,...> CHAR  { actions }  * ...  *  %%  *  more lines to be copied  */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_comment
comment|/* Includes */
end_comment

begin_comment
comment|/*  The following "char" should be changed to "short", "int", or "long" if your  wart program will generate more than 127 states.  Since wart is used mainly  with C-Kermit, which has about 50 states, "char" is adequate.  This   keeps the program about 3K-4K smaller. */
end_comment

begin_define
define|#
directive|define
name|TBL_TYPE
value|"char"
end_define

begin_comment
comment|/* C data type of state table */
end_comment

begin_define
define|#
directive|define
name|C_L
value|014
end_define

begin_comment
comment|/* Formfeed */
end_comment

begin_define
define|#
directive|define
name|SEP
value|1
end_define

begin_comment
comment|/* Token types */
end_comment

begin_define
define|#
directive|define
name|LBRACK
value|2
end_define

begin_define
define|#
directive|define
name|RBRACK
value|3
end_define

begin_define
define|#
directive|define
name|WORD
value|4
end_define

begin_define
define|#
directive|define
name|COMMA
value|5
end_define

begin_comment
comment|/* Storage sizes */
end_comment

begin_define
define|#
directive|define
name|MAXSTATES
value|50
end_define

begin_comment
comment|/* max number of states */
end_comment

begin_define
define|#
directive|define
name|MAXWORD
value|50
end_define

begin_comment
comment|/* max # of chars/word */
end_comment

begin_define
define|#
directive|define
name|SBYTES
value|((MAXSTATES+6)/8)
end_define

begin_comment
comment|/* # of bytes for state bitmask */
end_comment

begin_comment
comment|/* Name of wart function in generated program */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FNAME
end_ifndef

begin_define
define|#
directive|define
name|FNAME
value|"wart"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FNAME */
end_comment

begin_comment
comment|/* Structure for state information */
end_comment

begin_struct
struct|struct
name|transx
block|{
name|CHAR
name|states
index|[
name|SBYTES
index|]
decl_stmt|;
comment|/* included states */
name|int
name|anyst
decl_stmt|;
comment|/* true if this good from any state */
name|CHAR
name|inchr
decl_stmt|;
comment|/* input character */
name|int
name|actno
decl_stmt|;
comment|/* associated action */
name|struct
name|transx
modifier|*
name|nxt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* next transition */
end_comment

begin_typedef
typedef|typedef
name|struct
name|transx
modifier|*
name|trans
typedef|;
end_typedef

begin_comment
comment|/* Function prototypes */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID setwstate
argument_list|,
argument|(int, trans)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int teststate
argument_list|,
argument|(int, trans)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|trans rdinput
argument_list|,
argument|(FILE *, FILE *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID initial
argument_list|,
argument|(FILE *, FILE *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int isin
argument_list|,
argument|(char *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int isword
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID rdword
argument_list|,
argument|(FILE *, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID rdstates
argument_list|,
argument|(FILE *, FILE *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|trans newtrans
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|trans rdrules
argument_list|,
argument|(FILE *, FILE *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID statelist
argument_list|,
argument|(FILE *, trans)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID copyact
argument_list|,
argument|(FILE *, FILE *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int faction
argument_list|,
argument|(trans, int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID emptytbl
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID addaction
argument_list|,
argument|(int, int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID writetbl
argument_list|,
argument|(FILE *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID warray
argument_list|,
argument|(FILE *, char *, int [], int, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID fatal
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID prolog
argument_list|,
argument|(FILE *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID epilogue
argument_list|,
argument|(FILE *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID copyrest
argument_list|,
argument|(FILE *, FILE *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int gettoken
argument_list|,
argument|(FILE *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID rdcmnt
argument_list|,
argument|(FILE *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID clrhash
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int hash
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID enter
argument_list|,
argument|(char *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int lkup
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
specifier|static
name|char
operator|*
name|copy
argument_list|,
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Variables and tables */
end_comment

begin_comment
comment|/* lt 1992-10-08 Begin  * provide definition for deblog variable  * ckcdeb.h declares as extern. DECC AXP is strict about ref/def model  * Variable is unused herein, to the best of my knowledge.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_decl_stmt
name|int
name|deblog
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_comment
comment|/* lt 1992-10-08 End  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|lines
decl_stmt|,
name|nstates
decl_stmt|,
name|nacts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|tokval
index|[
name|MAXWORD
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|tbl
index|[
name|MAXSTATES
operator|*
literal|96
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tbl_type
init|=
name|TBL_TYPE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|txt1
init|=
literal|"\n#define BEGIN state =\n\nint state = 0;\n\nint\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fname
init|=
name|FNAME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generated function name goes here */
end_comment

begin_comment
comment|/* rest of program... */
end_comment

begin_decl_stmt
name|char
modifier|*
name|txt2
init|=
literal|"()\n\ {\n\     int c,actno;\n\     extern "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data type of state table is inserted here (short or int) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|txt2a
init|=
literal|" tbl[];\n    while (1) {\n	c = input() - 32;\n\         if (c< 0 || c> 95) c = 0;\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|txt2b
init|=
literal|"	if ((actno = tbl[c + state*96]) != -1)\n\ 	    switch(actno) {\n"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this program's output goes here, followed by final text... */
end_comment

begin_decl_stmt
name|char
modifier|*
name|txt3
init|=
literal|"\n	    }\n    }\n}\n\n"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * turn on the bit associated with the given state  *  */
end_comment

begin_function
name|VOID
name|setwstate
parameter_list|(
name|state
parameter_list|,
name|t
parameter_list|)
name|int
name|state
decl_stmt|;
name|trans
name|t
decl_stmt|;
block|{
name|int
name|idx
decl_stmt|,
name|msk
decl_stmt|;
name|idx
operator|=
name|state
operator|/
literal|8
expr_stmt|;
comment|/* byte associated with state */
name|msk
operator|=
literal|0x80
operator|>>
operator|(
name|state
operator|%
literal|8
operator|)
expr_stmt|;
comment|/* bit mask for state */
name|t
operator|->
name|states
index|[
name|idx
index|]
operator||=
name|msk
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * see if the state is involved in the transition  *  */
end_comment

begin_function
name|int
name|teststate
parameter_list|(
name|state
parameter_list|,
name|t
parameter_list|)
name|int
name|state
decl_stmt|;
name|trans
name|t
decl_stmt|;
block|{
name|int
name|idx
decl_stmt|,
name|msk
decl_stmt|;
name|idx
operator|=
name|state
operator|/
literal|8
expr_stmt|;
name|msk
operator|=
literal|0x80
operator|>>
operator|(
name|state
operator|%
literal|8
operator|)
expr_stmt|;
return|return
operator|(
name|t
operator|->
name|states
index|[
name|idx
index|]
operator|&
name|msk
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * read input from here...  *  */
end_comment

begin_function
name|trans
name|rdinput
parameter_list|(
name|infp
parameter_list|,
name|outfp
parameter_list|)
name|FILE
modifier|*
name|infp
decl_stmt|,
decl|*
name|outfp
decl_stmt|;
end_function

begin_block
block|{
name|trans
name|x
decl_stmt|,
name|rdrules
argument_list|()
decl_stmt|;
name|lines
operator|=
literal|1
expr_stmt|;
comment|/* line counter */
name|nstates
operator|=
literal|0
expr_stmt|;
comment|/* no states */
name|nacts
operator|=
literal|0
expr_stmt|;
comment|/* no actions yet */
name|fprintf
argument_list|(
name|outfp
argument_list|,
literal|"\n%c* WARNING -- This C source program generated by "
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|outfp
argument_list|,
literal|"Wart preprocessor. */\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|outfp
argument_list|,
literal|"%c* Do not edit this file; edit the Wart-format "
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|outfp
argument_list|,
literal|"source file instead, */\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|outfp
argument_list|,
literal|"%c* and then run it through Wart to produce a new "
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|outfp
argument_list|,
literal|"C source file.     */\n\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|outfp
argument_list|,
literal|"%c* Wart Version Info: */\n"
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|outfp
argument_list|,
literal|"char *wartv = \"%s\";\n\n"
argument_list|,
name|wartv
argument_list|)
expr_stmt|;
name|initial
argument_list|(
name|infp
argument_list|,
name|outfp
argument_list|)
expr_stmt|;
comment|/* read state names, initial defs */
name|prolog
argument_list|(
name|outfp
argument_list|)
expr_stmt|;
comment|/* write out our initial code */
name|x
operator|=
name|rdrules
argument_list|(
name|infp
argument_list|,
name|outfp
argument_list|)
expr_stmt|;
comment|/* read rules */
name|epilogue
argument_list|(
name|outfp
argument_list|)
expr_stmt|;
comment|/* write out epilogue code */
return|return
operator|(
name|x
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * initial - read initial definitions and state names.  Returns  * on EOF or %%.  *  */
end_comment

begin_function
name|VOID
name|initial
parameter_list|(
name|infp
parameter_list|,
name|outfp
parameter_list|)
name|FILE
modifier|*
name|infp
decl_stmt|,
decl|*
name|outfp
decl_stmt|;
end_function

begin_block
block|{
name|int
name|c
decl_stmt|;
name|char
name|wordbuf
index|[
name|MAXWORD
index|]
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|infp
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
block|{
if|if
condition|(
name|c
operator|==
literal|'%'
condition|)
block|{
name|rdword
argument_list|(
name|infp
argument_list|,
name|wordbuf
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|wordbuf
argument_list|,
literal|"states"
argument_list|)
operator|==
literal|0
condition|)
name|rdstates
argument_list|(
name|infp
argument_list|,
name|outfp
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|wordbuf
argument_list|,
literal|"%"
argument_list|)
operator|==
literal|0
condition|)
return|return;
else|else
name|fprintf
argument_list|(
name|outfp
argument_list|,
literal|"%%%s"
argument_list|,
name|wordbuf
argument_list|)
expr_stmt|;
block|}
else|else
name|putc
argument_list|(
name|c
argument_list|,
name|outfp
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'\n'
condition|)
name|lines
operator|++
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * boolean function to tell if the given character can be part of  * a word.  *  */
end_comment

begin_function
name|int
name|isin
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|c
decl_stmt|;
block|{
for|for
control|(
init|;
operator|*
name|s
operator|!=
literal|'\0'
condition|;
name|s
operator|++
control|)
if|if
condition|(
operator|*
name|s
operator|==
operator|(
name|char
operator|)
name|c
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|isword
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
specifier|static
name|char
name|special
index|[]
init|=
literal|".%_-$@"
decl_stmt|;
comment|/* these are allowable */
return|return
operator|(
name|isalnum
argument_list|(
name|c
argument_list|)
operator|||
name|isin
argument_list|(
name|special
argument_list|,
name|c
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * read the next word into the given buffer.  *  */
end_comment

begin_function
name|VOID
name|rdword
parameter_list|(
name|fp
parameter_list|,
name|buf
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
block|{
name|int
name|len
init|=
literal|0
decl_stmt|,
name|c
decl_stmt|;
while|while
condition|(
name|isword
argument_list|(
name|c
operator|=
name|getc
argument_list|(
name|fp
argument_list|)
argument_list|)
operator|&&
operator|++
name|len
operator|<
name|MAXWORD
condition|)
operator|*
name|buf
operator|++
operator|=
operator|(
name|char
operator|)
name|c
expr_stmt|;
operator|*
name|buf
operator|++
operator|=
literal|'\0'
expr_stmt|;
comment|/* tie off word */
name|ungetc
argument_list|(
name|c
argument_list|,
name|fp
argument_list|)
expr_stmt|;
comment|/* put break char back */
block|}
end_function

begin_comment
comment|/*  * read state names, up to a newline.  *  */
end_comment

begin_function
name|VOID
name|rdstates
parameter_list|(
name|fp
parameter_list|,
name|ofp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|,
decl|*
name|ofp
decl_stmt|;
end_function

begin_block
block|{
name|int
name|c
decl_stmt|;
name|char
name|wordbuf
index|[
name|MAXWORD
index|]
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|fp
argument_list|)
operator|)
operator|!=
name|EOF
operator|&&
name|c
operator|!=
literal|'\n'
condition|)
block|{
if|if
condition|(
name|isspace
argument_list|(
name|c
argument_list|)
operator|||
name|c
operator|==
name|C_L
condition|)
continue|continue;
comment|/* skip whitespace */
name|ungetc
argument_list|(
name|c
argument_list|,
name|fp
argument_list|)
expr_stmt|;
comment|/* put char back */
name|rdword
argument_list|(
name|fp
argument_list|,
name|wordbuf
argument_list|)
expr_stmt|;
comment|/* read the whole word */
name|enter
argument_list|(
name|wordbuf
argument_list|,
operator|++
name|nstates
argument_list|)
expr_stmt|;
comment|/* put into symbol tbl */
name|fprintf
argument_list|(
name|ofp
argument_list|,
literal|"#define %s %d\n"
argument_list|,
name|wordbuf
argument_list|,
name|nstates
argument_list|)
expr_stmt|;
block|}
name|lines
operator|++
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * allocate a new, empty transition node  *  */
end_comment

begin_function
name|trans
name|newtrans
parameter_list|()
block|{
name|trans
name|new
decl_stmt|;
name|int
name|i
decl_stmt|;
name|new
operator|=
operator|(
name|trans
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|transx
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|SBYTES
condition|;
name|i
operator|++
control|)
name|new
operator|->
name|states
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|new
operator|->
name|anyst
operator|=
literal|0
expr_stmt|;
name|new
operator|->
name|nxt
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|new
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * read all the rules.  *  */
end_comment

begin_function
name|trans
name|rdrules
parameter_list|(
name|fp
parameter_list|,
name|out
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|,
decl|*
name|out
decl_stmt|;
end_function

begin_block
block|{
name|trans
name|head
decl_stmt|,
name|cur
decl_stmt|,
name|prev
decl_stmt|;
name|int
name|curtok
decl_stmt|;
name|head
operator|=
name|cur
operator|=
name|prev
operator|=
name|NULL
expr_stmt|;
while|while
condition|(
operator|(
name|curtok
operator|=
name|gettoken
argument_list|(
name|fp
argument_list|)
operator|)
operator|!=
name|SEP
condition|)
switch|switch
condition|(
name|curtok
condition|)
block|{
case|case
name|LBRACK
case|:
if|if
condition|(
name|cur
operator|==
name|NULL
condition|)
name|cur
operator|=
name|newtrans
argument_list|()
expr_stmt|;
else|else
name|fatal
argument_list|(
literal|"duplicate state list"
argument_list|)
expr_stmt|;
name|statelist
argument_list|(
name|fp
argument_list|,
name|cur
argument_list|)
expr_stmt|;
comment|/* set states */
continue|continue;
comment|/* prepare to read char */
case|case
name|WORD
case|:
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|tokval
argument_list|)
operator|!=
literal|1
condition|)
name|fatal
argument_list|(
literal|"multiple chars in state"
argument_list|)
expr_stmt|;
if|if
condition|(
name|cur
operator|==
name|NULL
condition|)
block|{
name|cur
operator|=
name|newtrans
argument_list|()
expr_stmt|;
name|cur
operator|->
name|anyst
operator|=
literal|1
expr_stmt|;
block|}
name|cur
operator|->
name|actno
operator|=
operator|++
name|nacts
expr_stmt|;
name|cur
operator|->
name|inchr
operator|=
call|(
name|char
call|)
argument_list|(
name|tokval
index|[
literal|0
index|]
operator|-
literal|32
argument_list|)
expr_stmt|;
if|if
condition|(
name|head
operator|==
name|NULL
condition|)
name|head
operator|=
name|cur
expr_stmt|;
else|else
name|prev
operator|->
name|nxt
operator|=
name|cur
expr_stmt|;
name|prev
operator|=
name|cur
expr_stmt|;
name|cur
operator|=
name|NULL
expr_stmt|;
name|copyact
argument_list|(
name|fp
argument_list|,
name|out
argument_list|,
name|nacts
argument_list|)
expr_stmt|;
break|break;
default|default:
name|fatal
argument_list|(
literal|"bad input format"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|head
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * read a list of (comma-separated) states, set them in the  * given transition.  *  */
end_comment

begin_function
name|VOID
name|statelist
parameter_list|(
name|fp
parameter_list|,
name|t
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
name|trans
name|t
decl_stmt|;
block|{
name|int
name|curtok
decl_stmt|,
name|sval
decl_stmt|;
name|curtok
operator|=
name|COMMA
expr_stmt|;
while|while
condition|(
name|curtok
operator|!=
name|RBRACK
condition|)
block|{
if|if
condition|(
name|curtok
operator|!=
name|COMMA
condition|)
name|fatal
argument_list|(
literal|"missing comma"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|curtok
operator|=
name|gettoken
argument_list|(
name|fp
argument_list|)
operator|)
operator|!=
name|WORD
condition|)
name|fatal
argument_list|(
literal|"missing state name"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|sval
operator|=
name|lkup
argument_list|(
name|tokval
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"state %s undefined\n"
argument_list|,
name|tokval
argument_list|)
expr_stmt|;
name|fatal
argument_list|(
literal|"undefined state"
argument_list|)
expr_stmt|;
block|}
name|setwstate
argument_list|(
name|sval
argument_list|,
name|t
argument_list|)
expr_stmt|;
name|curtok
operator|=
name|gettoken
argument_list|(
name|fp
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * copy an action from the input to the output file  *  */
end_comment

begin_function
name|VOID
name|copyact
parameter_list|(
name|inp
parameter_list|,
name|outp
parameter_list|,
name|actno
parameter_list|)
name|FILE
modifier|*
name|inp
decl_stmt|,
decl|*
name|outp
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|actno
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|c
decl_stmt|,
name|bcnt
decl_stmt|;
name|fprintf
argument_list|(
name|outp
argument_list|,
literal|"case %d:\n"
argument_list|,
name|actno
argument_list|)
expr_stmt|;
while|while
condition|(
name|c
operator|=
name|getc
argument_list|(
name|inp
argument_list|)
operator|,
operator|(
name|isspace
argument_list|(
name|c
argument_list|)
operator|||
name|c
operator|==
name|C_L
operator|)
condition|)
if|if
condition|(
name|c
operator|==
literal|'\n'
condition|)
name|lines
operator|++
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'{'
condition|)
block|{
name|bcnt
operator|=
literal|1
expr_stmt|;
name|fputs
argument_list|(
literal|"    {"
argument_list|,
name|outp
argument_list|)
expr_stmt|;
while|while
condition|(
name|bcnt
operator|>
literal|0
operator|&&
operator|(
name|c
operator|=
name|getc
argument_list|(
name|inp
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
block|{
if|if
condition|(
name|c
operator|==
literal|'{'
condition|)
name|bcnt
operator|++
expr_stmt|;
elseif|else
if|if
condition|(
name|c
operator|==
literal|'}'
condition|)
name|bcnt
operator|--
expr_stmt|;
elseif|else
if|if
condition|(
name|c
operator|==
literal|'\n'
condition|)
name|lines
operator|++
expr_stmt|;
name|putc
argument_list|(
name|c
argument_list|,
name|outp
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|bcnt
operator|>
literal|0
condition|)
name|fatal
argument_list|(
literal|"action doesn't end"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
while|while
condition|(
name|c
operator|!=
literal|'\n'
operator|&&
name|c
operator|!=
name|EOF
condition|)
block|{
name|putc
argument_list|(
name|c
argument_list|,
name|outp
argument_list|)
expr_stmt|;
name|c
operator|=
name|getc
argument_list|(
name|inp
argument_list|)
expr_stmt|;
block|}
name|lines
operator|++
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|outp
argument_list|,
literal|"\n    break;\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * find the action associated with a given character and state.  * returns -1 if one can't be found.  *  */
end_comment

begin_function
name|int
name|faction
parameter_list|(
name|hd
parameter_list|,
name|state
parameter_list|,
name|chr
parameter_list|)
name|trans
name|hd
decl_stmt|;
name|int
name|state
decl_stmt|,
name|chr
decl_stmt|;
block|{
while|while
condition|(
name|hd
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|hd
operator|->
name|anyst
operator|||
name|teststate
argument_list|(
name|state
argument_list|,
name|hd
argument_list|)
condition|)
if|if
condition|(
name|hd
operator|->
name|inchr
operator|==
operator|(
literal|'.'
operator|-
literal|32
operator|)
operator|||
name|hd
operator|->
name|inchr
operator|==
operator|(
name|char
operator|)
name|chr
condition|)
return|return
operator|(
name|hd
operator|->
name|actno
operator|)
return|;
name|hd
operator|=
name|hd
operator|->
name|nxt
expr_stmt|;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * empty the table...  *  */
end_comment

begin_function
name|VOID
name|emptytbl
parameter_list|()
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
name|nstates
operator|*
literal|96
condition|;
name|i
operator|++
control|)
name|tbl
index|[
name|i
index|]
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * add the specified action to the output for the given state and chr.  *  */
end_comment

begin_function
name|VOID
name|addaction
parameter_list|(
name|act
parameter_list|,
name|state
parameter_list|,
name|chr
parameter_list|)
name|int
name|act
decl_stmt|,
name|state
decl_stmt|,
name|chr
decl_stmt|;
block|{
name|tbl
index|[
name|state
operator|*
literal|96
operator|+
name|chr
index|]
operator|=
name|act
expr_stmt|;
block|}
end_function

begin_function
name|VOID
name|writetbl
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
name|warray
argument_list|(
name|fp
argument_list|,
literal|"tbl"
argument_list|,
name|tbl
argument_list|,
literal|96
operator|*
operator|(
name|nstates
operator|+
literal|1
operator|)
argument_list|,
name|TBL_TYPE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * write an array to the output file, given its name and size.  *  */
end_comment

begin_function
name|VOID
name|warray
parameter_list|(
name|fp
parameter_list|,
name|nam
parameter_list|,
name|cont
parameter_list|,
name|siz
parameter_list|,
name|typ
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
name|char
modifier|*
name|nam
decl_stmt|;
name|int
name|cont
index|[]
decl_stmt|,
name|siz
decl_stmt|;
name|char
modifier|*
name|typ
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%s %s[] = {\n"
argument_list|,
name|typ
argument_list|,
name|nam
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|siz
operator|-
literal|1
condition|;
control|)
block|{
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%2d, "
argument_list|,
name|cont
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|++
name|i
operator|%
literal|16
operator|)
operator|==
literal|0
condition|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|fp
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%2d "
argument_list|,
name|cont
index|[
name|siz
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"};\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|VOID
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|trans
name|head
decl_stmt|;
name|int
name|state
decl_stmt|,
name|c
decl_stmt|;
name|FILE
modifier|*
name|infile
decl_stmt|,
modifier|*
name|outfile
decl_stmt|;
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
if|if
condition|(
operator|(
name|infile
operator|=
name|fopen
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't open %s\n"
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|fatal
argument_list|(
literal|"unreadable input file"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
name|infile
operator|=
name|stdin
expr_stmt|;
if|if
condition|(
name|argc
operator|>
literal|2
condition|)
block|{
if|if
condition|(
operator|(
name|outfile
operator|=
name|fopen
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't write to %s\n"
argument_list|,
name|argv
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|fatal
argument_list|(
literal|"bad output file"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
name|outfile
operator|=
name|stdout
expr_stmt|;
name|clrhash
argument_list|()
expr_stmt|;
comment|/* empty hash table */
name|head
operator|=
name|rdinput
argument_list|(
name|infile
argument_list|,
name|outfile
argument_list|)
expr_stmt|;
comment|/* read input file */
name|emptytbl
argument_list|()
expr_stmt|;
comment|/* empty our tables */
for|for
control|(
name|state
operator|=
literal|0
init|;
name|state
operator|<=
name|nstates
condition|;
name|state
operator|++
control|)
for|for
control|(
name|c
operator|=
literal|1
init|;
name|c
operator|<
literal|96
condition|;
name|c
operator|++
control|)
comment|/* find actions, */
name|addaction
argument_list|(
name|faction
argument_list|(
name|head
argument_list|,
name|state
argument_list|,
name|c
argument_list|)
argument_list|,
name|state
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|/* add to tbl */
name|writetbl
argument_list|(
name|outfile
argument_list|)
expr_stmt|;
name|copyrest
argument_list|(
name|infile
argument_list|,
name|outfile
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d states, %d actions\n"
argument_list|,
name|nstates
argument_list|,
name|nacts
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|GOOD_EXIT
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * fatal error handler  *  */
end_comment

begin_function
name|VOID
name|fatal
parameter_list|(
name|msg
parameter_list|)
name|char
modifier|*
name|msg
decl_stmt|;
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"error in line %d: %s\n"
argument_list|,
name|lines
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|BAD_EXIT
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|VOID
name|prolog
parameter_list|(
name|outfp
parameter_list|)
name|FILE
modifier|*
name|outfp
decl_stmt|;
block|{
name|int
name|c
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|txt1
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
name|putc
argument_list|(
name|c
argument_list|,
name|outfp
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|fname
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
name|putc
argument_list|(
name|c
argument_list|,
name|outfp
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|txt2
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
name|putc
argument_list|(
name|c
argument_list|,
name|outfp
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|tbl_type
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
name|putc
argument_list|(
name|c
argument_list|,
name|outfp
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|txt2a
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
name|putc
argument_list|(
name|c
argument_list|,
name|outfp
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|txt2b
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
name|putc
argument_list|(
name|c
argument_list|,
name|outfp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|VOID
name|epilogue
parameter_list|(
name|outfp
parameter_list|)
name|FILE
modifier|*
name|outfp
decl_stmt|;
block|{
name|int
name|c
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|txt3
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
name|putc
argument_list|(
name|c
argument_list|,
name|outfp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|VOID
name|copyrest
parameter_list|(
name|in
parameter_list|,
name|out
parameter_list|)
name|FILE
modifier|*
name|in
decl_stmt|,
decl|*
name|out
decl_stmt|;
end_function

begin_block
block|{
name|int
name|c
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|in
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
name|putc
argument_list|(
name|c
argument_list|,
name|out
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * gettoken - returns token type of next token, sets tokval  * to the string value of the token if appropriate.  *  */
end_comment

begin_function
name|int
name|gettoken
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
name|int
name|c
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
comment|/* loop if reading comments... */
do|do
block|{
name|c
operator|=
name|getc
argument_list|(
name|fp
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'\n'
condition|)
name|lines
operator|++
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|isspace
argument_list|(
name|c
argument_list|)
operator|||
name|c
operator|==
name|C_L
operator|)
condition|)
do|;
comment|/* skip whitespace */
switch|switch
condition|(
name|c
condition|)
block|{
case|case
name|EOF
case|:
return|return
operator|(
name|SEP
operator|)
return|;
case|case
literal|'%'
case|:
if|if
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|fp
argument_list|)
operator|)
operator|==
literal|'%'
condition|)
return|return
operator|(
name|SEP
operator|)
return|;
name|tokval
index|[
literal|0
index|]
operator|=
literal|'%'
expr_stmt|;
name|tokval
index|[
literal|1
index|]
operator|=
operator|(
name|char
operator|)
name|c
expr_stmt|;
name|rdword
argument_list|(
name|fp
argument_list|,
name|tokval
operator|+
literal|2
argument_list|)
expr_stmt|;
return|return
operator|(
name|WORD
operator|)
return|;
case|case
literal|'<'
case|:
return|return
operator|(
name|LBRACK
operator|)
return|;
case|case
literal|'>'
case|:
return|return
operator|(
name|RBRACK
operator|)
return|;
case|case
literal|','
case|:
return|return
operator|(
name|COMMA
operator|)
return|;
case|case
literal|'/'
case|:
if|if
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|fp
argument_list|)
operator|)
operator|==
literal|'*'
condition|)
block|{
name|rdcmnt
argument_list|(
name|fp
argument_list|)
expr_stmt|;
comment|/* skip over the comment */
continue|continue;
block|}
else|else
block|{
comment|/* and keep looping */
name|ungetc
argument_list|(
name|c
argument_list|,
name|fp
argument_list|)
expr_stmt|;
comment|/* put this back into input */
name|c
operator|=
literal|'/'
expr_stmt|;
comment|/* put character back, fall thru */
block|}
default|default:
if|if
condition|(
name|isword
argument_list|(
name|c
argument_list|)
condition|)
block|{
name|ungetc
argument_list|(
name|c
argument_list|,
name|fp
argument_list|)
expr_stmt|;
name|rdword
argument_list|(
name|fp
argument_list|,
name|tokval
argument_list|)
expr_stmt|;
return|return
operator|(
name|WORD
operator|)
return|;
block|}
else|else
name|fatal
argument_list|(
literal|"Invalid character in input"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/*  * skip over a comment  *  */
end_comment

begin_function
name|VOID
name|rdcmnt
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
name|int
name|c
decl_stmt|,
name|star
decl_stmt|,
name|prcnt
decl_stmt|;
name|prcnt
operator|=
name|star
operator|=
literal|0
expr_stmt|;
comment|/* no star seen yet */
while|while
condition|(
operator|!
operator|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|fp
argument_list|)
operator|)
operator|==
literal|'/'
operator|&&
name|star
operator|)
condition|)
block|{
if|if
condition|(
name|c
operator|==
name|EOF
operator|||
operator|(
name|prcnt
operator|&&
name|c
operator|==
literal|'%'
operator|)
condition|)
name|fatal
argument_list|(
literal|"Unterminated comment"
argument_list|)
expr_stmt|;
name|prcnt
operator|=
operator|(
name|c
operator|==
literal|'%'
operator|)
expr_stmt|;
name|star
operator|=
operator|(
name|c
operator|==
literal|'*'
operator|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'\n'
condition|)
name|lines
operator|++
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * symbol table management for wart  *  * entry points:  *   clrhash - empty hash table.  *   enter - enter a name into the symbol table  *   lkup - find a name's value in the symbol table.  *  */
end_comment

begin_define
define|#
directive|define
name|HASHSIZE
value|101
end_define

begin_comment
comment|/* # of entries in hash table */
end_comment

begin_struct
struct|struct
name|sym
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* symbol name */
name|int
name|val
decl_stmt|;
comment|/* value */
name|struct
name|sym
modifier|*
name|hnxt
decl_stmt|;
comment|/* next on collision chain */
block|}
modifier|*
name|htab
index|[
name|HASHSIZE
index|]
struct|;
end_struct

begin_comment
comment|/* the hash table */
end_comment

begin_comment
comment|/*  * empty the hash table before using it...  *  */
end_comment

begin_function
name|VOID
name|clrhash
parameter_list|()
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
name|HASHSIZE
condition|;
name|i
operator|++
control|)
name|htab
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * compute the value of the hash for a symbol  *  */
end_comment

begin_function
name|int
name|hash
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|int
name|sum
decl_stmt|;
for|for
control|(
name|sum
operator|=
literal|0
init|;
operator|*
name|name
operator|!=
literal|'\0'
condition|;
name|name
operator|++
control|)
name|sum
operator|+=
operator|(
name|sum
operator|+
operator|*
name|name
operator|)
expr_stmt|;
name|sum
operator|%=
name|HASHSIZE
expr_stmt|;
comment|/* take sum mod hashsize */
if|if
condition|(
name|sum
operator|<
literal|0
condition|)
name|sum
operator|+=
name|HASHSIZE
expr_stmt|;
comment|/* disallow negative hash value */
return|return
operator|(
name|sum
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * make a private copy of a string...  *  */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|copy
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|char
modifier|*
name|new
decl_stmt|;
name|new
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|new
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|new
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * enter state name into the hash table  *  */
end_comment

begin_function
name|VOID
name|enter
parameter_list|(
name|name
parameter_list|,
name|svalue
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|svalue
decl_stmt|;
block|{
name|int
name|h
decl_stmt|;
name|struct
name|sym
modifier|*
name|cur
decl_stmt|;
if|if
condition|(
name|lkup
argument_list|(
name|name
argument_list|)
operator|!=
operator|-
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"state \"%s\" appears twice...\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|BAD_EXIT
argument_list|)
expr_stmt|;
block|}
name|h
operator|=
name|hash
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|cur
operator|=
operator|(
expr|struct
name|sym
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|sym
argument_list|)
argument_list|)
expr_stmt|;
name|cur
operator|->
name|name
operator|=
name|copy
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|cur
operator|->
name|val
operator|=
name|svalue
expr_stmt|;
name|cur
operator|->
name|hnxt
operator|=
name|htab
index|[
name|h
index|]
expr_stmt|;
name|htab
index|[
name|h
index|]
operator|=
name|cur
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * find name in the symbol table, return its value.  Returns -1  * if not found.  *  */
end_comment

begin_function
name|int
name|lkup
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|struct
name|sym
modifier|*
name|cur
decl_stmt|;
for|for
control|(
name|cur
operator|=
name|htab
index|[
name|hash
argument_list|(
name|name
argument_list|)
index|]
init|;
name|cur
operator|!=
name|NULL
condition|;
name|cur
operator|=
name|cur
operator|->
name|hnxt
control|)
if|if
condition|(
name|strcmp
argument_list|(
name|cur
operator|->
name|name
argument_list|,
name|name
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|cur
operator|->
name|val
operator|)
return|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

