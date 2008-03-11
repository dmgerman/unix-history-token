begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /p/tcsh/cvsroot/tcsh/snames.h,v 1.3 1996/04/26 19:20:31 christos Exp $ */
end_comment

begin_comment
comment|/*  * snames.h: Short names for old compilers  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_snames_h
end_ifndef

begin_define
define|#
directive|define
name|_snames_h
end_define

begin_define
define|#
directive|define
name|tw_cmd_add
value|twcmdadd
end_define

begin_define
define|#
directive|define
name|tw_cmd_alias
value|twcmdalias
end_define

begin_define
define|#
directive|define
name|tw_cmd_sort
value|twcmdsort
end_define

begin_define
define|#
directive|define
name|tw_cmd_start
value|twcmdstart
end_define

begin_define
define|#
directive|define
name|tw_logname_end
value|twnameend
end_define

begin_define
define|#
directive|define
name|tw_logname_next
value|twnamenext
end_define

begin_define
define|#
directive|define
name|tw_logname_start
value|twnamestart
end_define

begin_define
define|#
directive|define
name|tw_file_next
value|twfilenext
end_define

begin_define
define|#
directive|define
name|tw_file_start
value|twfilestart
end_define

begin_define
define|#
directive|define
name|tw_item_add
value|twitemadd
end_define

begin_define
define|#
directive|define
name|tw_item_find
value|twitemfind
end_define

begin_define
define|#
directive|define
name|tw_item_get
value|twitemget
end_define

begin_define
define|#
directive|define
name|tw_bind_next
value|twbindnext
end_define

begin_define
define|#
directive|define
name|tw_bind_start
value|twbindstart
end_define

begin_define
define|#
directive|define
name|tw_limit_next
value|twlimitnext
end_define

begin_define
define|#
directive|define
name|tw_limit_start
value|twlimitstart
end_define

begin_define
define|#
directive|define
name|tw_collect
value|twcllct
end_define

begin_define
define|#
directive|define
name|tw_collect_items
value|twcllcti
end_define

begin_define
define|#
directive|define
name|e_complete
value|ecomp
end_define

begin_define
define|#
directive|define
name|e_complete_all
value|ecompall
end_define

begin_define
define|#
directive|define
name|e_complete_back
value|ecompback
end_define

begin_define
define|#
directive|define
name|e_complete_fwd
value|ecompfwd
end_define

begin_define
define|#
directive|define
name|e_correct
value|ecrrct
end_define

begin_define
define|#
directive|define
name|e_correctl
value|ecrrctl
end_define

begin_define
define|#
directive|define
name|e_expand_glob
value|eexpandglob
end_define

begin_define
define|#
directive|define
name|e_expand_vars
value|eexpandvars
end_define

begin_define
define|#
directive|define
name|e_delnext
value|edelnxt
end_define

begin_define
define|#
directive|define
name|e_delnext_eof
value|edelnxteof
end_define

begin_define
define|#
directive|define
name|e_delnext_list
value|edelnxtlst
end_define

begin_define
define|#
directive|define
name|e_delnext_list_eof
value|edellsteof
end_define

begin_define
define|#
directive|define
name|e_delwordnext
value|edelwrdnext
end_define

begin_define
define|#
directive|define
name|e_delwordprev
value|edelwrdprev
end_define

begin_define
define|#
directive|define
name|e_expand
value|eexp
end_define

begin_define
define|#
directive|define
name|e_expand_history
value|eexphistory
end_define

begin_define
define|#
directive|define
name|e_expand_vars
value|eexpvars
end_define

begin_define
define|#
directive|define
name|e_tty_starto
value|ettystarto
end_define

begin_define
define|#
directive|define
name|e_tty_stopo
value|ettystopo
end_define

begin_define
define|#
directive|define
name|v_csearch_back
value|vcsrchback
end_define

begin_define
define|#
directive|define
name|v_csearch_fwd
value|vcsrchfwd
end_define

begin_define
define|#
directive|define
name|v_charto_back
value|vchartovack
end_define

begin_define
define|#
directive|define
name|v_charto_fwd
value|vchartofwd
end_define

begin_define
define|#
directive|define
name|v_rchar_back
value|vrcharback
end_define

begin_define
define|#
directive|define
name|v_rchar_fwd
value|vrcharfwd
end_define

begin_define
define|#
directive|define
name|v_rsrch_back
value|vrsrchback
end_define

begin_define
define|#
directive|define
name|v_rsrch_fwd
value|vrsrchfwd
end_define

begin_define
define|#
directive|define
name|ed_InitMaps
value|edInitMaps
end_define

begin_define
define|#
directive|define
name|ed_InitMetaBindings
value|edInitMetaBindings
end_define

begin_define
define|#
directive|define
name|QuoteModeOff
value|QuoteOff
end_define

begin_define
define|#
directive|define
name|QuoteModeOn
value|QuoteOn
end_define

begin_define
define|#
directive|define
name|GetNextChar
value|GetNxtChar
end_define

begin_define
define|#
directive|define
name|GetNextCommand
value|GetNxtCommand
end_define

begin_define
define|#
directive|define
name|tty_gettabs
value|ttygettabs
end_define

begin_define
define|#
directive|define
name|tty_getty
value|ttygetty
end_define

begin_define
define|#
directive|define
name|printkey
value|prntkey
end_define

begin_define
define|#
directive|define
name|printkeys
value|prntkeys
end_define

begin_define
define|#
directive|define
name|STRprompt
value|STRpmpt
end_define

begin_define
define|#
directive|define
name|STRprompt2
value|STRpmpt2
end_define

begin_define
define|#
directive|define
name|STRprompt3
value|STRpmpt3
end_define

begin_define
define|#
directive|define
name|STRtildotdirs
value|STRtdotdirs
end_define

begin_define
define|#
directive|define
name|STRtildothist
value|STRtdothist
end_define

begin_define
define|#
directive|define
name|STRpushdsilent
value|STRpushsilent
end_define

begin_define
define|#
directive|define
name|STRpushdtohome
value|STRpushtohome
end_define

begin_define
define|#
directive|define
name|STRdefault
value|STRdef
end_define

begin_define
define|#
directive|define
name|STRdefautologout
value|STRdefautologout
end_define

begin_define
define|#
directive|define
name|STRfakecom
value|STRfake
end_define

begin_define
define|#
directive|define
name|STRfakecom1
value|STRfake1
end_define

begin_define
define|#
directive|define
name|STRLparen
value|STRLpar
end_define

begin_define
define|#
directive|define
name|STRLparensp
value|STRLparsp
end_define

begin_define
define|#
directive|define
name|STRspLarrowsp
value|STRspLarrowsp
end_define

begin_define
define|#
directive|define
name|STRspLarrow2sp
value|STRspL2arrowsp
end_define

begin_define
define|#
directive|define
name|STRspRarrow
value|STRspRarrow
end_define

begin_define
define|#
directive|define
name|STRspRarrow2
value|STRspR2arrow
end_define

begin_define
define|#
directive|define
name|STRcontinue
value|STRcont
end_define

begin_define
define|#
directive|define
name|STRcontinue_args
value|STRcont_args
end_define

begin_define
define|#
directive|define
name|STRsldotcshrc
value|STRsdotcshrc
end_define

begin_define
define|#
directive|define
name|STRsldottcshrc
value|STRsdottcshrc
end_define

begin_define
define|#
directive|define
name|STRsldotlogin
value|STRsdotlogin
end_define

begin_define
define|#
directive|define
name|STRlistmax
value|STRlmax
end_define

begin_define
define|#
directive|define
name|STRlistmaxrows
value|STRlmaxrows
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _snames_h */
end_comment

end_unit

