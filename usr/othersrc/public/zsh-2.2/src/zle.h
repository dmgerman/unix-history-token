begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * zle.h - header file for line editor  *  * This file is part of zsh, the Z shell.  *  * This software is Copyright 1992 by Paul Falstad  *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ZLEGLOBALS
end_ifdef

begin_define
define|#
directive|define
name|ZLEXTERN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ZLEXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ZLE
end_ifdef

begin_comment
comment|/* cursor position */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|cs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line length */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|ll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of line buffer */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|linesz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of mark */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|mark
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last character pressed */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the z_ binding id for this key */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|bindk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command argument */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|mult
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* insert mode/overwrite mode flag */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|insmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cost of last update */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|cost
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flags associated with last command */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|lastcmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* column position before last LINEMOVE movement */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|lastcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we're getting a vi range */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|virangeflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kludge to get cw and dw to work right */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|wordflag
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* last named command done */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|lastnamed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we're done editing */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|done
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of prompt on screen */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|pptlen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current history line number */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|histline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZLEXTERN
name|int
name|eofsent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we need to call resetvideo() */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|resetneeded
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if the line editor is active */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|zleactive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the line buffer */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|unsigned
name|char
modifier|*
name|line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the cut buffer */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|char
modifier|*
name|cutbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prompt and rprompt */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|char
modifier|*
name|pmpt
decl_stmt|,
modifier|*
name|pmpt2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the last line in the history (the current one) */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|char
modifier|*
name|curhistline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the status line */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|char
modifier|*
name|statusline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if a complete added a slash at the end of a directory name */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|addedslash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	the current history line and cursor position for the top line 	on the buffer stack */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|stackhist
decl_stmt|,
name|stackcs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we are in the middle of a menu completion */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|menucmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if we are making undo records */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|undoing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last vi change buffer */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|vichgbufsz
decl_stmt|,
name|vichgbufptr
decl_stmt|,
name|vichgflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZLEXTERN
name|char
modifier|*
name|vichgbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZLEXTERN
name|int
name|viinsbegin
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|bindfunc
name|DCLPROTO
typedef|((
name|void
typedef|));
end_typedef

begin_typedef
typedef|typedef
name|bindfunc
modifier|*
name|F
typedef|;
end_typedef

begin_struct
struct|struct
name|key
block|{
name|struct
name|hashnode
modifier|*
name|next
decl_stmt|;
name|int
name|canfree
decl_stmt|;
name|char
modifier|*
name|nam
decl_stmt|;
comment|/* hash data */
name|int
name|func
decl_stmt|;
comment|/* function code for this key */
name|char
modifier|*
name|str
decl_stmt|;
comment|/* string corresponding to this key, 								if func = z_sequenceleadin				 */
name|int
name|len
decl_stmt|;
comment|/* length of string */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|zlecmd
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of function */
name|F
name|func
decl_stmt|;
comment|/* handler function */
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* undo event */
end_comment

begin_struct
struct|struct
name|undoent
block|{
name|int
name|pref
decl_stmt|;
comment|/* number of initial chars unchanged */
name|int
name|suff
decl_stmt|;
comment|/* number of trailing chars unchanged */
name|int
name|len
decl_stmt|;
comment|/* length of changed chars */
name|int
name|cs
decl_stmt|;
comment|/* cursor pos before change */
name|char
modifier|*
name|change
decl_stmt|;
comment|/* NOT null terminated */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNDOCT
value|64
end_define

begin_decl_stmt
name|struct
name|undoent
name|undos
index|[
name|UNDOCT
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the line before last mod (for undo purposes) */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|unsigned
name|char
modifier|*
name|lastline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer specified with "x */
end_comment

begin_decl_stmt
name|ZLEXTERN
name|int
name|vibufspec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZLEXTERN
name|int
name|undoct
decl_stmt|,
name|lastcs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZLEXTERN
name|char
modifier|*
name|visrchstr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZLEXTERN
name|int
name|visrchsense
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ZLE_MOVEMENT
value|1
end_define

begin_define
define|#
directive|define
name|ZLE_MENUCMP
value|2
end_define

begin_define
define|#
directive|define
name|ZLE_UNDO
value|4
end_define

begin_define
define|#
directive|define
name|ZLE_YANK
value|8
end_define

begin_define
define|#
directive|define
name|ZLE_LINEMOVE
value|16
end_define

begin_define
define|#
directive|define
name|ZLE_ARG
value|32
end_define

begin_define
define|#
directive|define
name|ZLE_NAMEDBUFFER
value|128
end_define

begin_define
define|#
directive|define
name|ZLE_KILL
value|(64|ZLE_NAMEDBUFFER)
end_define

begin_define
define|#
directive|define
name|ZLE_HISTSEARCH
value|256
end_define

begin_define
define|#
directive|define
name|ZLE_NEGARG
value|512
end_define

begin_define
define|#
directive|define
name|ZLE_INSERT
value|1024
end_define

begin_typedef
typedef|typedef
name|struct
name|key
modifier|*
name|Key
typedef|;
end_typedef

begin_decl_stmt
name|ZLEXTERN
name|int
modifier|*
name|bindtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|emacsbind
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZLEXTERN
name|int
name|altbindtab
index|[
literal|256
index|]
decl_stmt|,
name|mainbindtab
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|viinsbind
index|[]
decl_stmt|,
name|vicmdbind
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZLEXTERN
name|int
name|vimarkcs
index|[
literal|27
index|]
decl_stmt|,
name|vimarkline
index|[
literal|27
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|KRINGCT
value|8
end_define

begin_decl_stmt
name|ZLEXTERN
name|char
modifier|*
name|kring
index|[
name|KRINGCT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZLEXTERN
name|int
name|kringnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ZLEXTERN
name|char
modifier|*
name|vibuf
index|[
literal|36
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|z_acceptandhold
value|0
end_define

begin_define
define|#
directive|define
name|z_acceptandinfernexthistory
value|1
end_define

begin_define
define|#
directive|define
name|z_acceptandmenucomplete
value|2
end_define

begin_define
define|#
directive|define
name|z_acceptline
value|3
end_define

begin_define
define|#
directive|define
name|z_acceptlineanddownhistory
value|4
end_define

begin_define
define|#
directive|define
name|z_backwardchar
value|5
end_define

begin_define
define|#
directive|define
name|z_backwarddeletechar
value|6
end_define

begin_define
define|#
directive|define
name|z_backwarddeleteword
value|7
end_define

begin_define
define|#
directive|define
name|z_backwardkillline
value|8
end_define

begin_define
define|#
directive|define
name|z_backwardkillword
value|9
end_define

begin_define
define|#
directive|define
name|z_backwardword
value|10
end_define

begin_define
define|#
directive|define
name|z_beginningofbufferorhistory
value|11
end_define

begin_define
define|#
directive|define
name|z_beginningofhistory
value|12
end_define

begin_define
define|#
directive|define
name|z_beginningofline
value|13
end_define

begin_define
define|#
directive|define
name|z_beginningoflinehist
value|14
end_define

begin_define
define|#
directive|define
name|z_capitalizeword
value|15
end_define

begin_define
define|#
directive|define
name|z_clearscreen
value|16
end_define

begin_define
define|#
directive|define
name|z_completeword
value|17
end_define

begin_define
define|#
directive|define
name|z_copyprevword
value|18
end_define

begin_define
define|#
directive|define
name|z_copyregionaskill
value|19
end_define

begin_define
define|#
directive|define
name|z_deletechar
value|20
end_define

begin_define
define|#
directive|define
name|z_deletecharorlist
value|21
end_define

begin_define
define|#
directive|define
name|z_deleteword
value|22
end_define

begin_define
define|#
directive|define
name|z_digitargument
value|23
end_define

begin_define
define|#
directive|define
name|z_downcaseword
value|24
end_define

begin_define
define|#
directive|define
name|z_downhistory
value|25
end_define

begin_define
define|#
directive|define
name|z_downlineorhistory
value|26
end_define

begin_define
define|#
directive|define
name|z_endofbufferorhistory
value|27
end_define

begin_define
define|#
directive|define
name|z_endofhistory
value|28
end_define

begin_define
define|#
directive|define
name|z_endofline
value|29
end_define

begin_define
define|#
directive|define
name|z_endoflinehist
value|30
end_define

begin_define
define|#
directive|define
name|z_exchangepointandmark
value|31
end_define

begin_define
define|#
directive|define
name|z_executelastnamedcmd
value|32
end_define

begin_define
define|#
directive|define
name|z_executenamedcmd
value|33
end_define

begin_define
define|#
directive|define
name|z_expandhistory
value|34
end_define

begin_define
define|#
directive|define
name|z_expandorcomplete
value|35
end_define

begin_define
define|#
directive|define
name|z_expandword
value|36
end_define

begin_define
define|#
directive|define
name|z_forwardchar
value|37
end_define

begin_define
define|#
directive|define
name|z_forwardword
value|38
end_define

begin_define
define|#
directive|define
name|z_getline
value|39
end_define

begin_define
define|#
directive|define
name|z_gosmacstransposechars
value|40
end_define

begin_define
define|#
directive|define
name|z_historyincrementalsearchbackward
value|41
end_define

begin_define
define|#
directive|define
name|z_historyincrementalsearchforward
value|42
end_define

begin_define
define|#
directive|define
name|z_historysearchbackward
value|43
end_define

begin_define
define|#
directive|define
name|z_historysearchforward
value|44
end_define

begin_define
define|#
directive|define
name|z_infernexthistory
value|45
end_define

begin_define
define|#
directive|define
name|z_insertlastword
value|46
end_define

begin_define
define|#
directive|define
name|z_killbuffer
value|47
end_define

begin_define
define|#
directive|define
name|z_killline
value|48
end_define

begin_define
define|#
directive|define
name|z_killregion
value|49
end_define

begin_define
define|#
directive|define
name|z_killwholeline
value|50
end_define

begin_define
define|#
directive|define
name|z_listchoices
value|51
end_define

begin_define
define|#
directive|define
name|z_listexpand
value|52
end_define

begin_define
define|#
directive|define
name|z_magicspace
value|53
end_define

begin_define
define|#
directive|define
name|z_menucompleteword
value|54
end_define

begin_define
define|#
directive|define
name|z_menuexpandorcomplete
value|55
end_define

begin_define
define|#
directive|define
name|z_overwritemode
value|56
end_define

begin_define
define|#
directive|define
name|z_pushline
value|57
end_define

begin_define
define|#
directive|define
name|z_quotedinsert
value|58
end_define

begin_define
define|#
directive|define
name|z_quoteline
value|59
end_define

begin_define
define|#
directive|define
name|z_quoteregion
value|60
end_define

begin_define
define|#
directive|define
name|z_redisplay
value|61
end_define

begin_define
define|#
directive|define
name|z_reversemenucomplete
value|62
end_define

begin_define
define|#
directive|define
name|z_runhelp
value|63
end_define

begin_define
define|#
directive|define
name|z_selfinsert
value|64
end_define

begin_define
define|#
directive|define
name|z_selfinsertunmeta
value|65
end_define

begin_define
define|#
directive|define
name|z_sendbreak
value|66
end_define

begin_define
define|#
directive|define
name|z_sendstring
value|67
end_define

begin_define
define|#
directive|define
name|z_sequenceleadin
value|68
end_define

begin_define
define|#
directive|define
name|z_setmarkcommand
value|69
end_define

begin_define
define|#
directive|define
name|z_spellword
value|70
end_define

begin_define
define|#
directive|define
name|z_toggleliteralhistory
value|71
end_define

begin_define
define|#
directive|define
name|z_transposechars
value|72
end_define

begin_define
define|#
directive|define
name|z_transposewords
value|73
end_define

begin_define
define|#
directive|define
name|z_undefinedkey
value|74
end_define

begin_define
define|#
directive|define
name|z_undo
value|75
end_define

begin_define
define|#
directive|define
name|z_universalargument
value|76
end_define

begin_define
define|#
directive|define
name|z_upcaseword
value|77
end_define

begin_define
define|#
directive|define
name|z_uphistory
value|78
end_define

begin_define
define|#
directive|define
name|z_uplineorhistory
value|79
end_define

begin_define
define|#
directive|define
name|z_viaddeol
value|80
end_define

begin_define
define|#
directive|define
name|z_viaddnext
value|81
end_define

begin_define
define|#
directive|define
name|z_vibackwardblankword
value|82
end_define

begin_define
define|#
directive|define
name|z_vibackwardchar
value|83
end_define

begin_define
define|#
directive|define
name|z_vibackwarddeletechar
value|84
end_define

begin_define
define|#
directive|define
name|z_vibeginningofline
value|85
end_define

begin_define
define|#
directive|define
name|z_vicapslockpanic
value|86
end_define

begin_define
define|#
directive|define
name|z_vichange
value|87
end_define

begin_define
define|#
directive|define
name|z_vichangeeol
value|88
end_define

begin_define
define|#
directive|define
name|z_vichangewholeline
value|89
end_define

begin_define
define|#
directive|define
name|z_vicmdmode
value|90
end_define

begin_define
define|#
directive|define
name|z_videlete
value|91
end_define

begin_define
define|#
directive|define
name|z_videletechar
value|92
end_define

begin_define
define|#
directive|define
name|z_vidigitorbeginningofline
value|93
end_define

begin_define
define|#
directive|define
name|z_viendofline
value|94
end_define

begin_define
define|#
directive|define
name|z_vifetchhistory
value|95
end_define

begin_define
define|#
directive|define
name|z_vifindnextchar
value|96
end_define

begin_define
define|#
directive|define
name|z_vifindnextcharskip
value|97
end_define

begin_define
define|#
directive|define
name|z_vifindprevchar
value|98
end_define

begin_define
define|#
directive|define
name|z_vifindprevcharskip
value|99
end_define

begin_define
define|#
directive|define
name|z_vifirstnonblank
value|100
end_define

begin_define
define|#
directive|define
name|z_viforwardblankword
value|101
end_define

begin_define
define|#
directive|define
name|z_viforwardblankwordend
value|102
end_define

begin_define
define|#
directive|define
name|z_viforwardchar
value|103
end_define

begin_define
define|#
directive|define
name|z_viforwardwordend
value|104
end_define

begin_define
define|#
directive|define
name|z_vigotocolumn
value|105
end_define

begin_define
define|#
directive|define
name|z_vigotomark
value|106
end_define

begin_define
define|#
directive|define
name|z_vigotomarkline
value|107
end_define

begin_define
define|#
directive|define
name|z_vihistorysearchbackward
value|108
end_define

begin_define
define|#
directive|define
name|z_vihistorysearchforward
value|109
end_define

begin_define
define|#
directive|define
name|z_viindent
value|110
end_define

begin_define
define|#
directive|define
name|z_viinsert
value|111
end_define

begin_define
define|#
directive|define
name|z_viinsertbol
value|112
end_define

begin_define
define|#
directive|define
name|z_vijoin
value|113
end_define

begin_define
define|#
directive|define
name|z_vimatchbracket
value|114
end_define

begin_define
define|#
directive|define
name|z_viopenlineabove
value|115
end_define

begin_define
define|#
directive|define
name|z_viopenlinebelow
value|116
end_define

begin_define
define|#
directive|define
name|z_vioperswapcases
value|117
end_define

begin_define
define|#
directive|define
name|z_viputafter
value|118
end_define

begin_define
define|#
directive|define
name|z_virepeatchange
value|119
end_define

begin_define
define|#
directive|define
name|z_virepeatfind
value|120
end_define

begin_define
define|#
directive|define
name|z_virepeatsearch
value|121
end_define

begin_define
define|#
directive|define
name|z_vireplace
value|122
end_define

begin_define
define|#
directive|define
name|z_vireplacechars
value|123
end_define

begin_define
define|#
directive|define
name|z_virevrepeatfind
value|124
end_define

begin_define
define|#
directive|define
name|z_virevrepeatsearch
value|125
end_define

begin_define
define|#
directive|define
name|z_visetbuffer
value|126
end_define

begin_define
define|#
directive|define
name|z_visetmark
value|127
end_define

begin_define
define|#
directive|define
name|z_visubstitute
value|128
end_define

begin_define
define|#
directive|define
name|z_viswapcase
value|129
end_define

begin_define
define|#
directive|define
name|z_viundochange
value|130
end_define

begin_define
define|#
directive|define
name|z_viunindent
value|131
end_define

begin_define
define|#
directive|define
name|z_viyank
value|132
end_define

begin_define
define|#
directive|define
name|z_viyankeol
value|133
end_define

begin_define
define|#
directive|define
name|z_whichcommand
value|134
end_define

begin_define
define|#
directive|define
name|z_yank
value|135
end_define

begin_define
define|#
directive|define
name|z_yankpop
value|136
end_define

begin_define
define|#
directive|define
name|z_emacsbackwardword
value|137
end_define

begin_define
define|#
directive|define
name|z_emacsforwardword
value|138
end_define

begin_define
define|#
directive|define
name|z_killword
value|139
end_define

begin_define
define|#
directive|define
name|z_vikillline
value|140
end_define

begin_define
define|#
directive|define
name|z_vibackwardkillword
value|141
end_define

begin_define
define|#
directive|define
name|z_expandcmdpath
value|142
end_define

begin_define
define|#
directive|define
name|z_negargument
value|143
end_define

begin_define
define|#
directive|define
name|z_poundinsert
value|144
end_define

begin_define
define|#
directive|define
name|z_viforwardword
value|145
end_define

begin_define
define|#
directive|define
name|z_vibackwardword
value|146
end_define

begin_define
define|#
directive|define
name|ZLECMDCOUNT
value|147
end_define

begin_decl_stmt
specifier|extern
name|struct
name|zlecmd
name|zlecmds
index|[]
decl_stmt|;
end_decl_stmt

end_unit

