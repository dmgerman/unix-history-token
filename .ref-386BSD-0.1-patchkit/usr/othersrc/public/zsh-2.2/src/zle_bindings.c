begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * zle_bindings.c - commands and keymaps  *  * This file is part of zsh, the Z shell.  *  * This software is Copyright 1992 by Paul Falstad  *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   *  */
end_comment

begin_define
define|#
directive|define
name|ZLE
end_define

begin_include
include|#
directive|include
file|"zsh.h"
end_include

begin_decl_stmt
name|struct
name|zlecmd
name|zlecmds
index|[]
init|=
block|{
literal|"accept-and-hold"
block|,
name|acceptandhold
block|,
literal|0
block|,
literal|"accept-and-infer-next-history"
block|,
name|acceptandinfernexthistory
block|,
literal|0
block|,
literal|"accept-and-menu-complete"
block|,
name|acceptandmenucomplete
block|,
name|ZLE_MENUCMP
block|,
literal|"accept-line"
block|,
name|acceptline
block|,
literal|0
block|,
literal|"accept-line-and-down-history"
block|,
name|acceptlineanddownhistory
block|,
literal|0
block|,
literal|"backward-char"
block|,
name|backwardchar
block|,
name|ZLE_MOVEMENT
block|,
literal|"backward-delete-char"
block|,
name|backwarddeletechar
block|,
literal|0
block|,
literal|"backward-delete-word"
block|,
name|backwarddeleteword
block|,
literal|0
block|,
literal|"backward-kill-line"
block|,
name|backwardkillline
block|,
name|ZLE_KILL
block|,
literal|"backward-kill-word"
block|,
name|backwardkillword
block|,
name|ZLE_KILL
block|,
literal|"backward-word"
block|,
name|backwardword
block|,
name|ZLE_MOVEMENT
block|,
literal|"beginning-of-buffer-or-history"
block|,
name|beginningofbufferorhistory
block|,
name|ZLE_MOVEMENT
block|,
literal|"beginning-of-history"
block|,
name|beginningofhistory
block|,
literal|0
block|,
literal|"beginning-of-line"
block|,
name|beginningofline
block|,
name|ZLE_MOVEMENT
block|,
literal|"beginning-of-line-hist"
block|,
name|beginningoflinehist
block|,
name|ZLE_MOVEMENT
block|,
literal|"capitalize-word"
block|,
name|capitalizeword
block|,
literal|0
block|,
literal|"clear-screen"
block|,
name|clearscreen
block|,
literal|0
block|,
literal|"complete-word"
block|,
name|completeword
block|,
name|ZLE_MENUCMP
block|,
literal|"copy-prev-word"
block|,
name|copyprevword
block|,
literal|0
block|,
literal|"copy-region-as-kill"
block|,
name|copyregionaskill
block|,
name|ZLE_KILL
block|,
literal|"delete-char"
block|,
name|deletechar
block|,
literal|0
block|,
literal|"delete-char-or-list"
block|,
name|deletecharorlist
block|,
name|ZLE_MENUCMP
block|,
literal|"delete-word"
block|,
name|deleteword
block|,
literal|0
block|,
literal|"digit-argument"
block|,
name|digitargument
block|,
name|ZLE_ARG
block|,
literal|"down-case-word"
block|,
name|downcaseword
block|,
literal|0
block|,
literal|"down-history"
block|,
name|downhistory
block|,
literal|0
block|,
literal|"down-line-or-history"
block|,
name|downlineorhistory
block|,
name|ZLE_MOVEMENT
operator||
name|ZLE_LINEMOVE
block|,
literal|"end-of-buffer-or-history"
block|,
name|endofbufferorhistory
block|,
name|ZLE_MOVEMENT
block|,
literal|"end-of-history"
block|,
name|endofhistory
block|,
literal|0
block|,
literal|"end-of-line"
block|,
name|endofline
block|,
name|ZLE_MOVEMENT
block|,
literal|"end-of-line-hist"
block|,
name|endoflinehist
block|,
name|ZLE_MOVEMENT
block|,
literal|"exchange-point-and-mark"
block|,
name|exchangepointandmark
block|,
name|ZLE_MOVEMENT
block|,
literal|"execute-last-named-cmd"
block|,
name|NULL
block|,
literal|0
block|,
literal|"execute-named-cmd"
block|,
name|NULL
block|,
literal|0
block|,
literal|"expand-history"
block|,
name|expandhistory
block|,
literal|0
block|,
literal|"expand-or-complete"
block|,
name|expandorcomplete
block|,
name|ZLE_MENUCMP
block|,
literal|"expand-word"
block|,
name|expandword
block|,
literal|0
block|,
literal|"forward-char"
block|,
name|forwardchar
block|,
name|ZLE_MOVEMENT
block|,
literal|"forward-word"
block|,
name|forwardword
block|,
name|ZLE_MOVEMENT
block|,
literal|"get-line"
block|,
name|getline
block|,
literal|0
block|,
literal|"gosmacs-transpose-chars"
block|,
name|gosmacstransposechars
block|,
literal|0
block|,
literal|"history-incremental-search-backward"
block|,
name|historyincrementalsearchbackward
block|,
literal|0
block|,
literal|"history-incremental-search-forward"
block|,
name|historyincrementalsearchforward
block|,
literal|0
block|,
literal|"history-search-backward"
block|,
name|historysearchbackward
block|,
name|ZLE_HISTSEARCH
block|,
literal|"history-search-forward"
block|,
name|historysearchforward
block|,
name|ZLE_HISTSEARCH
block|,
literal|"infer-next-history"
block|,
name|infernexthistory
block|,
literal|0
block|,
literal|"insert-last-word"
block|,
name|insertlastword
block|,
name|ZLE_INSERT
block|,
literal|"kill-buffer"
block|,
name|killbuffer
block|,
name|ZLE_KILL
block|,
literal|"kill-line"
block|,
name|killline
block|,
name|ZLE_KILL
block|,
literal|"kill-region"
block|,
name|killregion
block|,
name|ZLE_KILL
block|,
literal|"kill-whole-line"
block|,
name|killwholeline
block|,
name|ZLE_KILL
block|,
literal|"list-choices"
block|,
name|listchoices
block|,
literal|0
block|,
literal|"list-expand"
block|,
name|listexpand
block|,
name|ZLE_MENUCMP
block|,
literal|"magic-space"
block|,
name|magicspace
block|,
literal|0
block|,
literal|"menu-complete"
block|,
name|menucompleteword
block|,
name|ZLE_MENUCMP
block|,
literal|"menu-expand-or-complete"
block|,
name|menuexpandorcomplete
block|,
name|ZLE_MENUCMP
block|,
literal|"overwrite-mode"
block|,
name|overwritemode
block|,
literal|0
block|,
literal|"push-line"
block|,
name|pushline
block|,
literal|0
block|,
literal|"quoted-insert"
block|,
name|quotedinsert
block|,
name|ZLE_INSERT
block|,
literal|"quote-line"
block|,
name|quoteline
block|,
literal|0
block|,
literal|"quote-region"
block|,
name|quoteregion
block|,
literal|0
block|,
literal|"redisplay"
block|,
name|redisplay
block|,
literal|0
block|,
literal|"reverse-menu-complete"
block|,
name|reversemenucomplete
block|,
name|ZLE_MENUCMP
block|,
literal|"run-help"
block|,
name|processcmd
block|,
literal|0
block|,
literal|"self-insert"
block|,
name|selfinsert
block|,
name|ZLE_INSERT
block|,
literal|"self-insert-unmeta"
block|,
name|selfinsertunmeta
block|,
name|ZLE_INSERT
block|,
literal|"send-break"
block|,
name|sendbreak
block|,
literal|0
block|,
literal|"send-string"
block|,
name|sendstring
block|,
literal|0
block|,
literal|""
block|,
name|NULL
block|,
literal|0
block|,
literal|"set-mark-command"
block|,
name|setmarkcommand
block|,
literal|0
block|,
literal|"spell-word"
block|,
name|spellword
block|,
literal|0
block|,
literal|"toggle-literal-history"
block|,
name|toggleliteralhistory
block|,
literal|0
block|,
literal|"transpose-chars"
block|,
name|transposechars
block|,
literal|0
block|,
literal|"transpose-words"
block|,
name|transposewords
block|,
literal|0
block|,
literal|"undefined-key"
block|,
name|undefinedkey
block|,
literal|0
block|,
literal|"undo"
block|,
name|undo
block|,
name|ZLE_UNDO
block|,
literal|"universal-argument"
block|,
name|universalargument
block|,
name|ZLE_ARG
block|,
literal|"up-case-word"
block|,
name|upcaseword
block|,
literal|0
block|,
literal|"up-history"
block|,
name|uphistory
block|,
literal|0
block|,
literal|"up-line-or-history"
block|,
name|uplineorhistory
block|,
name|ZLE_LINEMOVE
operator||
name|ZLE_MOVEMENT
block|,
literal|"vi-add-eol"
block|,
name|viaddeol
block|,
literal|0
block|,
literal|"vi-add-next"
block|,
name|viaddnext
block|,
literal|0
block|,
literal|"vi-backward-blank-word"
block|,
name|vibackwardblankword
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-backward-char"
block|,
name|vibackwardchar
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-backward-delete-char"
block|,
name|vibackwarddeletechar
block|,
name|ZLE_KILL
block|,
literal|"vi-beginning-of-line"
block|,
name|vibeginningofline
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-caps-lock-panic"
block|,
name|vicapslockpanic
block|,
literal|0
block|,
literal|"vi-change"
block|,
name|vichange
block|,
literal|0
block|,
literal|"vi-change-eol"
block|,
name|vichangeeol
block|,
literal|0
block|,
literal|"vi-change-whole-line"
block|,
name|vichangewholeline
block|,
literal|0
block|,
literal|"vi-cmd-mode"
block|,
name|vicmdmode
block|,
literal|0
block|,
literal|"vi-delete"
block|,
name|videlete
block|,
name|ZLE_KILL
block|,
literal|"vi-delete-char"
block|,
name|videletechar
block|,
name|ZLE_KILL
block|,
literal|"vi-digit-or-beginning-of-line"
block|,
name|NULL
block|,
literal|0
block|,
literal|"vi-end-of-line"
block|,
name|viendofline
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-fetch-history"
block|,
name|vifetchhistory
block|,
literal|0
block|,
literal|"vi-find-next-char"
block|,
name|vifindnextchar
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-find-next-char-skip"
block|,
name|vifindnextcharskip
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-find-prev-char"
block|,
name|vifindprevchar
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-find-prev-char-skip"
block|,
name|vifindprevcharskip
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-first-non-blank"
block|,
name|vifirstnonblank
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-forward-blank-word"
block|,
name|viforwardblankword
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-forward-blank-word-end"
block|,
name|viforwardblankwordend
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-forward-char"
block|,
name|viforwardchar
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-forward-word-end"
block|,
name|viforwardwordend
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-goto-column"
block|,
name|vigotocolumn
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-goto-mark"
block|,
name|vigotomark
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-goto-mark-line"
block|,
name|vigotomarkline
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-history-search-backward"
block|,
name|vihistorysearchbackward
block|,
literal|0
block|,
literal|"vi-history-search-forward"
block|,
name|vihistorysearchforward
block|,
literal|0
block|,
literal|"vi-indent"
block|,
name|viindent
block|,
literal|0
block|,
literal|"vi-insert"
block|,
name|viinsert
block|,
literal|0
block|,
literal|"vi-insert-bol"
block|,
name|viinsertbol
block|,
literal|0
block|,
literal|"vi-join"
block|,
name|vijoin
block|,
literal|0
block|,
literal|"vi-match-bracket"
block|,
name|vimatchbracket
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-open-line-above"
block|,
name|viopenlineabove
block|,
literal|0
block|,
literal|"vi-open-line-below"
block|,
name|viopenlinebelow
block|,
literal|0
block|,
literal|"vi-oper-swap-case"
block|,
name|vioperswapcase
block|,
literal|0
block|,
literal|"vi-put-after"
block|,
name|viputafter
block|,
name|ZLE_YANK
block|,
literal|"vi-repeat-change"
block|,
name|virepeatchange
block|,
literal|0
block|,
literal|"vi-repeat-find"
block|,
name|virepeatfind
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-repeat-search"
block|,
name|virepeatsearch
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-replace"
block|,
name|vireplace
block|,
literal|0
block|,
literal|"vi-replace-chars"
block|,
name|vireplacechars
block|,
literal|0
block|,
literal|"vi-rev-repeat-find"
block|,
name|virevrepeatfind
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-rev-repeat-search"
block|,
name|virevrepeatsearch
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-set-buffer"
block|,
name|visetbuffer
block|,
literal|0
block|,
literal|"vi-set-mark"
block|,
name|visetmark
block|,
literal|0
block|,
literal|"vi-substitute"
block|,
name|visubstitute
block|,
literal|0
block|,
literal|"vi-swap-case"
block|,
name|viswapcase
block|,
literal|0
block|,
literal|"vi-undo-change"
block|,
name|undo
block|,
literal|0
block|,
literal|"vi-unindent"
block|,
name|viunindent
block|,
literal|0
block|,
literal|"vi-yank"
block|,
name|viyank
block|,
literal|0
block|,
literal|"vi-yank-eol"
block|,
name|viyankeol
block|,
literal|0
block|,
literal|"which-command"
block|,
name|processcmd
block|,
literal|0
block|,
literal|"yank"
block|,
name|yank
block|,
name|ZLE_YANK
operator||
name|ZLE_NAMEDBUFFER
block|,
literal|"yank-pop"
block|,
name|yankpop
block|,
name|ZLE_YANK
block|,
literal|"emacs-forward-word"
block|,
name|emacsforwardword
block|,
name|ZLE_MOVEMENT
block|,
literal|"emacs-backward-word"
block|,
name|emacsbackwardword
block|,
name|ZLE_MOVEMENT
block|,
literal|"kill-word"
block|,
name|killword
block|,
name|ZLE_KILL
block|,
literal|"vi-kill-line"
block|,
name|vikillline
block|,
literal|0
block|,
literal|"vi-backward-kill-word"
block|,
name|vibackwardkillword
block|,
literal|0
block|,
literal|"expand-cmd-path"
block|,
name|expandcmdpath
block|,
literal|0
block|,
literal|"neg-argument"
block|,
name|negargument
block|,
name|ZLE_NEGARG
block|,
literal|"pound-insert"
block|,
name|poundinsert
block|,
literal|0
block|,
literal|"vi-forward-word"
block|,
name|viforwardword
block|,
name|ZLE_MOVEMENT
block|,
literal|"vi-backward-word"
block|,
name|vibackwardword
block|,
name|ZLE_MOVEMENT
block|,
literal|""
block|,
name|NULL
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|emacsbind
index|[
literal|256
index|]
init|=
block|{
comment|/* ^@ */
name|z_setmarkcommand
block|,
comment|/* ^A */
name|z_beginningofline
block|,
comment|/* ^B */
name|z_backwardchar
block|,
comment|/* ^C */
name|z_sendbreak
block|,
comment|/* ^D */
name|z_deletecharorlist
block|,
comment|/* ^E */
name|z_endofline
block|,
comment|/* ^F */
name|z_forwardchar
block|,
comment|/* ^G */
name|z_undefinedkey
block|,
comment|/* ^H */
name|z_backwarddeletechar
block|,
comment|/* ^I */
name|z_expandorcomplete
block|,
comment|/* ^J */
name|z_acceptline
block|,
comment|/* ^K */
name|z_killline
block|,
comment|/* ^L */
name|z_clearscreen
block|,
comment|/* ^M */
name|z_acceptline
block|,
comment|/* ^N */
name|z_downlineorhistory
block|,
comment|/* ^O */
name|z_acceptlineanddownhistory
block|,
comment|/* ^P */
name|z_uplineorhistory
block|,
comment|/* ^Q */
name|z_pushline
block|,
comment|/* ^R */
name|z_historyincrementalsearchbackward
block|,
comment|/* ^S */
name|z_historyincrementalsearchforward
block|,
comment|/* ^T */
name|z_transposechars
block|,
comment|/* ^U */
name|z_killwholeline
block|,
comment|/* ^V */
name|z_quotedinsert
block|,
comment|/* ^W */
name|z_backwardkillword
block|,
comment|/* ^X */
name|z_sequenceleadin
block|,
comment|/* ^Y */
name|z_yank
block|,
comment|/* ^Z */
name|z_undefinedkey
block|,
comment|/* ^[ */
name|z_sequenceleadin
block|,
comment|/* ^\ */
name|z_undefinedkey
block|,
comment|/* ^] */
name|z_undefinedkey
block|,
comment|/* ^^ */
name|z_undefinedkey
block|,
comment|/* ^_ */
name|z_undo
block|,
comment|/*   */
name|z_selfinsert
block|,
comment|/* ! */
name|z_selfinsert
block|,
comment|/* " */
name|z_selfinsert
block|,
comment|/* # */
name|z_selfinsert
block|,
comment|/* $ */
name|z_selfinsert
block|,
comment|/* % */
name|z_selfinsert
block|,
comment|/*& */
name|z_selfinsert
block|,
comment|/* ' */
name|z_selfinsert
block|,
comment|/* ( */
name|z_selfinsert
block|,
comment|/* ) */
name|z_selfinsert
block|,
comment|/* * */
name|z_selfinsert
block|,
comment|/* + */
name|z_selfinsert
block|,
comment|/* , */
name|z_selfinsert
block|,
comment|/* - */
name|z_selfinsert
block|,
comment|/* . */
name|z_selfinsert
block|,
comment|/* / */
name|z_selfinsert
block|,
comment|/* 0 */
name|z_selfinsert
block|,
comment|/* 1 */
name|z_selfinsert
block|,
comment|/* 2 */
name|z_selfinsert
block|,
comment|/* 3 */
name|z_selfinsert
block|,
comment|/* 4 */
name|z_selfinsert
block|,
comment|/* 5 */
name|z_selfinsert
block|,
comment|/* 6 */
name|z_selfinsert
block|,
comment|/* 7 */
name|z_selfinsert
block|,
comment|/* 8 */
name|z_selfinsert
block|,
comment|/* 9 */
name|z_selfinsert
block|,
comment|/* : */
name|z_selfinsert
block|,
comment|/* ; */
name|z_selfinsert
block|,
comment|/*< */
name|z_selfinsert
block|,
comment|/* = */
name|z_selfinsert
block|,
comment|/*> */
name|z_selfinsert
block|,
comment|/* ? */
name|z_selfinsert
block|,
comment|/* @ */
name|z_selfinsert
block|,
comment|/* A */
name|z_selfinsert
block|,
comment|/* B */
name|z_selfinsert
block|,
comment|/* C */
name|z_selfinsert
block|,
comment|/* D */
name|z_selfinsert
block|,
comment|/* E */
name|z_selfinsert
block|,
comment|/* F */
name|z_selfinsert
block|,
comment|/* G */
name|z_selfinsert
block|,
comment|/* H */
name|z_selfinsert
block|,
comment|/* I */
name|z_selfinsert
block|,
comment|/* J */
name|z_selfinsert
block|,
comment|/* K */
name|z_selfinsert
block|,
comment|/* L */
name|z_selfinsert
block|,
comment|/* M */
name|z_selfinsert
block|,
comment|/* N */
name|z_selfinsert
block|,
comment|/* O */
name|z_selfinsert
block|,
comment|/* P */
name|z_selfinsert
block|,
comment|/* Q */
name|z_selfinsert
block|,
comment|/* R */
name|z_selfinsert
block|,
comment|/* S */
name|z_selfinsert
block|,
comment|/* T */
name|z_selfinsert
block|,
comment|/* U */
name|z_selfinsert
block|,
comment|/* V */
name|z_selfinsert
block|,
comment|/* W */
name|z_selfinsert
block|,
comment|/* X */
name|z_selfinsert
block|,
comment|/* Y */
name|z_selfinsert
block|,
comment|/* Z */
name|z_selfinsert
block|,
comment|/* [ */
name|z_selfinsert
block|,
comment|/* \ */
name|z_selfinsert
block|,
comment|/* ] */
name|z_selfinsert
block|,
comment|/* ^ */
name|z_selfinsert
block|,
comment|/* _ */
name|z_selfinsert
block|,
comment|/* ` */
name|z_selfinsert
block|,
comment|/* a */
name|z_selfinsert
block|,
comment|/* b */
name|z_selfinsert
block|,
comment|/* c */
name|z_selfinsert
block|,
comment|/* d */
name|z_selfinsert
block|,
comment|/* e */
name|z_selfinsert
block|,
comment|/* f */
name|z_selfinsert
block|,
comment|/* g */
name|z_selfinsert
block|,
comment|/* h */
name|z_selfinsert
block|,
comment|/* i */
name|z_selfinsert
block|,
comment|/* j */
name|z_selfinsert
block|,
comment|/* k */
name|z_selfinsert
block|,
comment|/* l */
name|z_selfinsert
block|,
comment|/* m */
name|z_selfinsert
block|,
comment|/* n */
name|z_selfinsert
block|,
comment|/* o */
name|z_selfinsert
block|,
comment|/* p */
name|z_selfinsert
block|,
comment|/* q */
name|z_selfinsert
block|,
comment|/* r */
name|z_selfinsert
block|,
comment|/* s */
name|z_selfinsert
block|,
comment|/* t */
name|z_selfinsert
block|,
comment|/* u */
name|z_selfinsert
block|,
comment|/* v */
name|z_selfinsert
block|,
comment|/* w */
name|z_selfinsert
block|,
comment|/* x */
name|z_selfinsert
block|,
comment|/* y */
name|z_selfinsert
block|,
comment|/* z */
name|z_selfinsert
block|,
comment|/* { */
name|z_selfinsert
block|,
comment|/* | */
name|z_selfinsert
block|,
comment|/* } */
name|z_selfinsert
block|,
comment|/* ~ */
name|z_selfinsert
block|,
comment|/* ^? */
name|z_backwarddeletechar
block|,
comment|/* M-^@ */
name|z_undefinedkey
block|,
comment|/* M-^A */
name|z_undefinedkey
block|,
comment|/* M-^B */
name|z_undefinedkey
block|,
comment|/* M-^C */
name|z_undefinedkey
block|,
comment|/* M-^D */
name|z_listchoices
block|,
comment|/* M-^E */
name|z_undefinedkey
block|,
comment|/* M-^F */
name|z_undefinedkey
block|,
comment|/* M-^G */
name|z_undefinedkey
block|,
comment|/* M-^H */
name|z_backwardkillword
block|,
comment|/* M-^I */
name|z_selfinsertunmeta
block|,
comment|/* M-^J */
name|z_selfinsertunmeta
block|,
comment|/* M-^K */
name|z_undefinedkey
block|,
comment|/* M-^L */
name|z_clearscreen
block|,
comment|/* M-^M */
name|z_selfinsertunmeta
block|,
comment|/* M-^N */
name|z_undefinedkey
block|,
comment|/* M-^O */
name|z_undefinedkey
block|,
comment|/* M-^P */
name|z_undefinedkey
block|,
comment|/* M-^Q */
name|z_undefinedkey
block|,
comment|/* M-^R */
name|z_undefinedkey
block|,
comment|/* M-^S */
name|z_undefinedkey
block|,
comment|/* M-^T */
name|z_undefinedkey
block|,
comment|/* M-^U */
name|z_undefinedkey
block|,
comment|/* M-^V */
name|z_undefinedkey
block|,
comment|/* M-^W */
name|z_undefinedkey
block|,
comment|/* M-^X */
name|z_undefinedkey
block|,
comment|/* M-^Y */
name|z_undefinedkey
block|,
comment|/* M-^Z */
name|z_undefinedkey
block|,
comment|/* M-^[ */
name|z_undefinedkey
block|,
comment|/* M-^\ */
name|z_undefinedkey
block|,
comment|/* M-^] */
name|z_undefinedkey
block|,
comment|/* M-^^ */
name|z_undefinedkey
block|,
comment|/* M-^_ */
name|z_copyprevword
block|,
comment|/* M-  */
name|z_expandhistory
block|,
comment|/* M-! */
name|z_expandhistory
block|,
comment|/* M-" */
name|z_quoteregion
block|,
comment|/* M-# */
name|z_undefinedkey
block|,
comment|/* M-$ */
name|z_spellword
block|,
comment|/* M-% */
name|z_undefinedkey
block|,
comment|/* M-& */
name|z_undefinedkey
block|,
comment|/* M-' */
name|z_quoteline
block|,
comment|/* M-( */
name|z_undefinedkey
block|,
comment|/* M-) */
name|z_undefinedkey
block|,
comment|/* M-* */
name|z_undefinedkey
block|,
comment|/* M-+ */
name|z_undefinedkey
block|,
comment|/* M-, */
name|z_undefinedkey
block|,
comment|/* M-- */
name|z_negargument
block|,
comment|/* M-. */
name|z_insertlastword
block|,
comment|/* M-/ */
name|z_undefinedkey
block|,
comment|/* M-0 */
name|z_digitargument
block|,
comment|/* M-1 */
name|z_digitargument
block|,
comment|/* M-2 */
name|z_digitargument
block|,
comment|/* M-3 */
name|z_digitargument
block|,
comment|/* M-4 */
name|z_digitargument
block|,
comment|/* M-5 */
name|z_digitargument
block|,
comment|/* M-6 */
name|z_digitargument
block|,
comment|/* M-7 */
name|z_digitargument
block|,
comment|/* M-8 */
name|z_digitargument
block|,
comment|/* M-9 */
name|z_digitargument
block|,
comment|/* M-: */
name|z_undefinedkey
block|,
comment|/* M-; */
name|z_undefinedkey
block|,
comment|/* M-< */
name|z_beginningofbufferorhistory
block|,
comment|/* M-= */
name|z_undefinedkey
block|,
comment|/* M-> */
name|z_endofbufferorhistory
block|,
comment|/* M-? */
name|z_whichcommand
block|,
comment|/* M-@ */
name|z_undefinedkey
block|,
comment|/* M-A */
name|z_acceptandhold
block|,
comment|/* M-B */
name|z_backwardword
block|,
comment|/* M-C */
name|z_capitalizeword
block|,
comment|/* M-D */
name|z_deleteword
block|,
comment|/* M-E */
name|z_undefinedkey
block|,
comment|/* M-F */
name|z_forwardword
block|,
comment|/* M-G */
name|z_getline
block|,
comment|/* M-H */
name|z_runhelp
block|,
comment|/* M-I */
name|z_undefinedkey
block|,
comment|/* M-J */
name|z_undefinedkey
block|,
comment|/* M-K */
name|z_undefinedkey
block|,
comment|/* M-L */
name|z_downcaseword
block|,
comment|/* M-M */
name|z_undefinedkey
block|,
comment|/* M-N */
name|z_historysearchforward
block|,
comment|/* M-O */
name|z_undefinedkey
block|,
comment|/* M-P */
name|z_historysearchbackward
block|,
comment|/* M-Q */
name|z_pushline
block|,
comment|/* M-R */
name|z_toggleliteralhistory
block|,
comment|/* M-S */
name|z_spellword
block|,
comment|/* M-T */
name|z_transposewords
block|,
comment|/* M-U */
name|z_upcaseword
block|,
comment|/* M-V */
name|z_undefinedkey
block|,
comment|/* M-W */
name|z_copyregionaskill
block|,
comment|/* M-X */
name|z_undefinedkey
block|,
comment|/* M-Y */
name|z_undefinedkey
block|,
comment|/* M-Z */
name|z_undefinedkey
block|,
comment|/* M-[ */
name|z_sequenceleadin
block|,
comment|/* M-\ */
name|z_undefinedkey
block|,
comment|/* M-] */
name|z_undefinedkey
block|,
comment|/* M-^ */
name|z_undefinedkey
block|,
comment|/* M-_ */
name|z_insertlastword
block|,
comment|/* M-` */
name|z_undefinedkey
block|,
comment|/* M-a */
name|z_acceptandhold
block|,
comment|/* M-b */
name|z_backwardword
block|,
comment|/* M-c */
name|z_capitalizeword
block|,
comment|/* M-d */
name|z_deleteword
block|,
comment|/* M-e */
name|z_undefinedkey
block|,
comment|/* M-f */
name|z_forwardword
block|,
comment|/* M-g */
name|z_getline
block|,
comment|/* M-h */
name|z_runhelp
block|,
comment|/* M-i */
name|z_undefinedkey
block|,
comment|/* M-j */
name|z_undefinedkey
block|,
comment|/* M-k */
name|z_undefinedkey
block|,
comment|/* M-l */
name|z_downcaseword
block|,
comment|/* M-m */
name|z_undefinedkey
block|,
comment|/* M-n */
name|z_historysearchforward
block|,
comment|/* M-o */
name|z_undefinedkey
block|,
comment|/* M-p */
name|z_historysearchbackward
block|,
comment|/* M-q */
name|z_pushline
block|,
comment|/* M-r */
name|z_toggleliteralhistory
block|,
comment|/* M-s */
name|z_spellword
block|,
comment|/* M-t */
name|z_transposewords
block|,
comment|/* M-u */
name|z_upcaseword
block|,
comment|/* M-v */
name|z_undefinedkey
block|,
comment|/* M-w */
name|z_copyregionaskill
block|,
comment|/* M-x */
name|z_executenamedcmd
block|,
comment|/* M-y */
name|z_yankpop
block|,
comment|/* M-z */
name|z_executelastnamedcmd
block|,
comment|/* M-{ */
name|z_undefinedkey
block|,
comment|/* M-| */
name|z_vigotocolumn
block|,
comment|/* M-} */
name|z_undefinedkey
block|,
comment|/* M-~ */
name|z_undefinedkey
block|,
comment|/* M-^? */
name|z_backwardkillword
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|viinsbind
index|[
literal|32
index|]
init|=
block|{
comment|/* ^@ */
name|z_undefinedkey
block|,
comment|/* ^A */
name|z_selfinsert
block|,
comment|/* ^B */
name|z_selfinsert
block|,
comment|/* ^C */
name|z_sendbreak
block|,
comment|/* ^D */
name|z_listchoices
block|,
comment|/* ^E */
name|z_selfinsert
block|,
comment|/* ^F */
name|z_selfinsert
block|,
comment|/* ^G */
name|z_selfinsert
block|,
comment|/* ^H */
name|z_vibackwarddeletechar
block|,
comment|/* ^I */
name|z_expandorcomplete
block|,
comment|/* ^J */
name|z_acceptline
block|,
comment|/* ^K */
name|z_killline
block|,
comment|/* ^L */
name|z_clearscreen
block|,
comment|/* ^M */
name|z_acceptline
block|,
comment|/* ^N */
name|z_selfinsert
block|,
comment|/* ^O */
name|z_selfinsert
block|,
comment|/* ^P */
name|z_selfinsert
block|,
comment|/* ^Q */
name|z_selfinsert
block|,
comment|/* ^R */
name|z_redisplay
block|,
comment|/* ^S */
name|z_selfinsert
block|,
comment|/* ^T */
name|z_selfinsert
block|,
comment|/* ^U */
name|z_vikillline
block|,
comment|/* ^V */
name|z_quotedinsert
block|,
comment|/* ^W */
name|z_vibackwardkillword
block|,
comment|/* ^X */
name|z_selfinsert
block|,
comment|/* ^Y */
name|z_selfinsert
block|,
comment|/* ^Z */
name|z_selfinsert
block|,
comment|/* ^[ */
name|z_vicmdmode
block|,
comment|/* ^\ */
name|z_selfinsert
block|,
comment|/* ^] */
name|z_selfinsert
block|,
comment|/* ^^ */
name|z_selfinsert
block|,
comment|/* ^_ */
name|z_selfinsert
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vicmdbind
index|[
literal|128
index|]
init|=
block|{
comment|/* ^@ */
name|z_undefinedkey
block|,
comment|/* ^A */
name|z_beginningofline
block|,
comment|/* ^B */
name|z_undefinedkey
block|,
comment|/* ^C */
name|z_sendbreak
block|,
comment|/* ^D */
name|z_listchoices
block|,
comment|/* ^E */
name|z_endofline
block|,
comment|/* ^F */
name|z_undefinedkey
block|,
comment|/* ^G */
name|z_listexpand
block|,
comment|/* ^H */
name|z_backwarddeletechar
block|,
comment|/* ^I */
name|z_completeword
block|,
comment|/* ^J */
name|z_acceptline
block|,
comment|/* ^K */
name|z_killline
block|,
comment|/* ^L */
name|z_clearscreen
block|,
comment|/* ^M */
name|z_acceptline
block|,
comment|/* ^N */
name|z_downhistory
block|,
comment|/* ^O */
name|z_undefinedkey
block|,
comment|/* ^P */
name|z_uphistory
block|,
comment|/* ^Q */
name|z_undefinedkey
block|,
comment|/* ^R */
name|z_redisplay
block|,
comment|/* ^S */
name|z_undefinedkey
block|,
comment|/* ^T */
name|z_undefinedkey
block|,
comment|/* ^U */
name|z_killbuffer
block|,
comment|/* ^V */
name|z_undefinedkey
block|,
comment|/* ^W */
name|z_backwardkillword
block|,
comment|/* ^X */
name|z_expandorcomplete
block|,
comment|/* ^Y */
name|z_undefinedkey
block|,
comment|/* ^Z */
name|z_undefinedkey
block|,
comment|/* ^[ */
name|z_sequenceleadin
block|,
comment|/* ^\ */
name|z_undefinedkey
block|,
comment|/* ^] */
name|z_undefinedkey
block|,
comment|/* ^^ */
name|z_undefinedkey
block|,
comment|/* ^_ */
name|z_undefinedkey
block|,
comment|/*   */
name|z_viforwardchar
block|,
comment|/* ! */
name|z_undefinedkey
block|,
comment|/* " */
name|z_visetbuffer
block|,
comment|/* # */
name|z_poundinsert
block|,
comment|/* $ */
name|z_viendofline
block|,
comment|/* % */
name|z_vimatchbracket
block|,
comment|/*& */
name|z_undefinedkey
block|,
comment|/* ' */
name|z_vigotomarkline
block|,
comment|/* ( */
name|z_undefinedkey
block|,
comment|/* ) */
name|z_undefinedkey
block|,
comment|/* * */
name|z_undefinedkey
block|,
comment|/* + */
name|z_downlineorhistory
block|,
comment|/* , */
name|z_virevrepeatfind
block|,
comment|/* - */
name|z_uplineorhistory
block|,
comment|/* . */
name|z_virepeatchange
block|,
comment|/* / */
name|z_vihistorysearchbackward
block|,
comment|/* 0 */
name|z_vidigitorbeginningofline
block|,
comment|/* 1 */
name|z_digitargument
block|,
comment|/* 2 */
name|z_digitargument
block|,
comment|/* 3 */
name|z_digitargument
block|,
comment|/* 4 */
name|z_digitargument
block|,
comment|/* 5 */
name|z_digitargument
block|,
comment|/* 6 */
name|z_digitargument
block|,
comment|/* 7 */
name|z_digitargument
block|,
comment|/* 8 */
name|z_digitargument
block|,
comment|/* 9 */
name|z_digitargument
block|,
comment|/* : */
name|z_undefinedkey
block|,
comment|/* ; */
name|z_virepeatfind
block|,
comment|/*< */
name|z_viunindent
block|,
comment|/* = */
name|z_listchoices
block|,
comment|/*> */
name|z_viindent
block|,
comment|/* ? */
name|z_vihistorysearchforward
block|,
comment|/* @ */
name|z_undefinedkey
block|,
comment|/* A */
name|z_viaddeol
block|,
comment|/* B */
name|z_vibackwardblankword
block|,
comment|/* C */
name|z_vichangeeol
block|,
comment|/* D */
name|z_killline
block|,
comment|/* E */
name|z_viforwardblankwordend
block|,
comment|/* F */
name|z_vifindprevchar
block|,
comment|/* G */
name|z_vifetchhistory
block|,
comment|/* H */
name|z_vicapslockpanic
block|,
comment|/* I */
name|z_viinsertbol
block|,
comment|/* J */
name|z_historysearchforward
block|,
comment|/* K */
name|z_historysearchbackward
block|,
comment|/* L */
name|z_undefinedkey
block|,
comment|/* M */
name|z_undefinedkey
block|,
comment|/* N */
name|z_virevrepeatsearch
block|,
comment|/* O */
name|z_viopenlineabove
block|,
comment|/* P */
name|z_yank
block|,
comment|/* Q */
name|z_undefinedkey
block|,
comment|/* R */
name|z_vireplace
block|,
comment|/* S */
name|z_vichangewholeline
block|,
comment|/* T */
name|z_vifindprevcharskip
block|,
comment|/* U */
name|z_undefinedkey
block|,
comment|/* V */
name|z_undefinedkey
block|,
comment|/* W */
name|z_viforwardblankword
block|,
comment|/* X */
name|z_vibackwarddeletechar
block|,
comment|/* Y */
name|z_viyankeol
block|,
comment|/* Z */
name|z_undefinedkey
block|,
comment|/* [ */
name|z_undefinedkey
block|,
comment|/* \ */
name|z_completeword
block|,
comment|/* ] */
name|z_undefinedkey
block|,
comment|/* ^ */
name|z_vifirstnonblank
block|,
comment|/* _ */
name|z_undefinedkey
block|,
comment|/* ` */
name|z_vigotomark
block|,
comment|/* a */
name|z_viaddnext
block|,
comment|/* b */
name|z_vibackwardword
block|,
comment|/* c */
name|z_vichange
block|,
comment|/* d */
name|z_videlete
block|,
comment|/* e */
name|z_viforwardwordend
block|,
comment|/* f */
name|z_vifindnextchar
block|,
comment|/* g */
name|z_undefinedkey
block|,
comment|/* h */
name|z_vibackwardchar
block|,
comment|/* i */
name|z_viinsert
block|,
comment|/* j */
name|z_downlineorhistory
block|,
comment|/* k */
name|z_uplineorhistory
block|,
comment|/* l */
name|z_viforwardchar
block|,
comment|/* m */
name|z_visetmark
block|,
comment|/* n */
name|z_virepeatsearch
block|,
comment|/* o */
name|z_viopenlinebelow
block|,
comment|/* p */
name|z_viputafter
block|,
comment|/* q */
name|z_undefinedkey
block|,
comment|/* r */
name|z_vireplacechars
block|,
comment|/* s */
name|z_visubstitute
block|,
comment|/* t */
name|z_vifindnextcharskip
block|,
comment|/* u */
name|z_viundochange
block|,
comment|/* v */
name|z_undefinedkey
block|,
comment|/* w */
name|z_viforwardword
block|,
comment|/* x */
name|z_videletechar
block|,
comment|/* y */
name|z_viyank
block|,
comment|/* z */
name|z_undefinedkey
block|,
comment|/* { */
name|z_undefinedkey
block|,
comment|/* | */
name|z_vigotocolumn
block|,
comment|/* } */
name|z_undefinedkey
block|,
comment|/* ~ */
name|z_viswapcase
block|,
comment|/* ^? */
name|z_backwarddeletechar
block|, }
decl_stmt|;
end_decl_stmt

end_unit

