begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__objXSUB_h__
end_ifndef

begin_define
define|#
directive|define
name|__objXSUB_h__
end_define

begin_comment
comment|/* Varibles */
end_comment

begin_undef
undef|#
directive|undef
name|PL_Sv
end_undef

begin_define
define|#
directive|define
name|PL_Sv
value|pPerl->PL_Sv
end_define

begin_undef
undef|#
directive|undef
name|PL_Xpv
end_undef

begin_define
define|#
directive|define
name|PL_Xpv
value|pPerl->PL_Xpv
end_define

begin_undef
undef|#
directive|undef
name|PL_av_fetch_sv
end_undef

begin_define
define|#
directive|define
name|PL_av_fetch_sv
value|pPerl->PL_av_fetch_sv
end_define

begin_undef
undef|#
directive|undef
name|PL_bodytarget
end_undef

begin_define
define|#
directive|define
name|PL_bodytarget
value|pPerl->PL_bodytarget
end_define

begin_undef
undef|#
directive|undef
name|PL_bostr
end_undef

begin_define
define|#
directive|define
name|PL_bostr
value|pPerl->PL_bostr
end_define

begin_undef
undef|#
directive|undef
name|PL_chopset
end_undef

begin_define
define|#
directive|define
name|PL_chopset
value|pPerl->PL_chopset
end_define

begin_undef
undef|#
directive|undef
name|PL_colors
end_undef

begin_define
define|#
directive|define
name|PL_colors
value|pPerl->PL_colors
end_define

begin_undef
undef|#
directive|undef
name|PL_colorset
end_undef

begin_define
define|#
directive|define
name|PL_colorset
value|pPerl->PL_colorset
end_define

begin_undef
undef|#
directive|undef
name|PL_cred_mutex
end_undef

begin_define
define|#
directive|define
name|PL_cred_mutex
value|pPerl->PL_cred_mutex
end_define

begin_undef
undef|#
directive|undef
name|PL_curcop
end_undef

begin_define
define|#
directive|define
name|PL_curcop
value|pPerl->PL_curcop
end_define

begin_undef
undef|#
directive|undef
name|PL_curpad
end_undef

begin_define
define|#
directive|define
name|PL_curpad
value|pPerl->PL_curpad
end_define

begin_undef
undef|#
directive|undef
name|PL_curpm
end_undef

begin_define
define|#
directive|define
name|PL_curpm
value|pPerl->PL_curpm
end_define

begin_undef
undef|#
directive|undef
name|PL_curstack
end_undef

begin_define
define|#
directive|define
name|PL_curstack
value|pPerl->PL_curstack
end_define

begin_undef
undef|#
directive|undef
name|PL_curstackinfo
end_undef

begin_define
define|#
directive|define
name|PL_curstackinfo
value|pPerl->PL_curstackinfo
end_define

begin_undef
undef|#
directive|undef
name|PL_curstash
end_undef

begin_define
define|#
directive|define
name|PL_curstash
value|pPerl->PL_curstash
end_define

begin_undef
undef|#
directive|undef
name|PL_defoutgv
end_undef

begin_define
define|#
directive|define
name|PL_defoutgv
value|pPerl->PL_defoutgv
end_define

begin_undef
undef|#
directive|undef
name|PL_defstash
end_undef

begin_define
define|#
directive|define
name|PL_defstash
value|pPerl->PL_defstash
end_define

begin_undef
undef|#
directive|undef
name|PL_delaymagic
end_undef

begin_define
define|#
directive|define
name|PL_delaymagic
value|pPerl->PL_delaymagic
end_define

begin_undef
undef|#
directive|undef
name|PL_dirty
end_undef

begin_define
define|#
directive|define
name|PL_dirty
value|pPerl->PL_dirty
end_define

begin_undef
undef|#
directive|undef
name|PL_extralen
end_undef

begin_define
define|#
directive|define
name|PL_extralen
value|pPerl->PL_extralen
end_define

begin_undef
undef|#
directive|undef
name|PL_firstgv
end_undef

begin_define
define|#
directive|define
name|PL_firstgv
value|pPerl->PL_firstgv
end_define

begin_undef
undef|#
directive|undef
name|PL_formtarget
end_undef

begin_define
define|#
directive|define
name|PL_formtarget
value|pPerl->PL_formtarget
end_define

begin_undef
undef|#
directive|undef
name|PL_hv_fetch_ent_mh
end_undef

begin_define
define|#
directive|define
name|PL_hv_fetch_ent_mh
value|pPerl->PL_hv_fetch_ent_mh
end_define

begin_undef
undef|#
directive|undef
name|PL_hv_fetch_sv
end_undef

begin_define
define|#
directive|define
name|PL_hv_fetch_sv
value|pPerl->PL_hv_fetch_sv
end_define

begin_undef
undef|#
directive|undef
name|PL_in_eval
end_undef

begin_define
define|#
directive|define
name|PL_in_eval
value|pPerl->PL_in_eval
end_define

begin_undef
undef|#
directive|undef
name|PL_last_in_gv
end_undef

begin_define
define|#
directive|define
name|PL_last_in_gv
value|pPerl->PL_last_in_gv
end_define

begin_undef
undef|#
directive|undef
name|PL_lastgotoprobe
end_undef

begin_define
define|#
directive|define
name|PL_lastgotoprobe
value|pPerl->PL_lastgotoprobe
end_define

begin_undef
undef|#
directive|undef
name|PL_lastscream
end_undef

begin_define
define|#
directive|define
name|PL_lastscream
value|pPerl->PL_lastscream
end_define

begin_undef
undef|#
directive|undef
name|PL_localizing
end_undef

begin_define
define|#
directive|define
name|PL_localizing
value|pPerl->PL_localizing
end_define

begin_undef
undef|#
directive|undef
name|PL_mainstack
end_undef

begin_define
define|#
directive|define
name|PL_mainstack
value|pPerl->PL_mainstack
end_define

begin_undef
undef|#
directive|undef
name|PL_markstack
end_undef

begin_define
define|#
directive|define
name|PL_markstack
value|pPerl->PL_markstack
end_define

begin_undef
undef|#
directive|undef
name|PL_markstack_max
end_undef

begin_define
define|#
directive|define
name|PL_markstack_max
value|pPerl->PL_markstack_max
end_define

begin_undef
undef|#
directive|undef
name|PL_markstack_ptr
end_undef

begin_define
define|#
directive|define
name|PL_markstack_ptr
value|pPerl->PL_markstack_ptr
end_define

begin_undef
undef|#
directive|undef
name|PL_maxscream
end_undef

begin_define
define|#
directive|define
name|PL_maxscream
value|pPerl->PL_maxscream
end_define

begin_undef
undef|#
directive|undef
name|PL_modcount
end_undef

begin_define
define|#
directive|define
name|PL_modcount
value|pPerl->PL_modcount
end_define

begin_undef
undef|#
directive|undef
name|PL_nrs
end_undef

begin_define
define|#
directive|define
name|PL_nrs
value|pPerl->PL_nrs
end_define

begin_undef
undef|#
directive|undef
name|PL_ofs
end_undef

begin_define
define|#
directive|define
name|PL_ofs
value|pPerl->PL_ofs
end_define

begin_undef
undef|#
directive|undef
name|PL_ofslen
end_undef

begin_define
define|#
directive|define
name|PL_ofslen
value|pPerl->PL_ofslen
end_define

begin_undef
undef|#
directive|undef
name|PL_op
end_undef

begin_define
define|#
directive|define
name|PL_op
value|pPerl->PL_op
end_define

begin_undef
undef|#
directive|undef
name|PL_opsave
end_undef

begin_define
define|#
directive|define
name|PL_opsave
value|pPerl->PL_opsave
end_define

begin_undef
undef|#
directive|undef
name|PL_reg_eval_set
end_undef

begin_define
define|#
directive|define
name|PL_reg_eval_set
value|pPerl->PL_reg_eval_set
end_define

begin_undef
undef|#
directive|undef
name|PL_reg_flags
end_undef

begin_define
define|#
directive|define
name|PL_reg_flags
value|pPerl->PL_reg_flags
end_define

begin_undef
undef|#
directive|undef
name|PL_reg_start_tmp
end_undef

begin_define
define|#
directive|define
name|PL_reg_start_tmp
value|pPerl->PL_reg_start_tmp
end_define

begin_undef
undef|#
directive|undef
name|PL_reg_start_tmpl
end_undef

begin_define
define|#
directive|define
name|PL_reg_start_tmpl
value|pPerl->PL_reg_start_tmpl
end_define

begin_undef
undef|#
directive|undef
name|PL_regbol
end_undef

begin_define
define|#
directive|define
name|PL_regbol
value|pPerl->PL_regbol
end_define

begin_undef
undef|#
directive|undef
name|PL_regcc
end_undef

begin_define
define|#
directive|define
name|PL_regcc
value|pPerl->PL_regcc
end_define

begin_undef
undef|#
directive|undef
name|PL_regcode
end_undef

begin_define
define|#
directive|define
name|PL_regcode
value|pPerl->PL_regcode
end_define

begin_undef
undef|#
directive|undef
name|PL_regcomp_parse
end_undef

begin_define
define|#
directive|define
name|PL_regcomp_parse
value|pPerl->PL_regcomp_parse
end_define

begin_undef
undef|#
directive|undef
name|PL_regcomp_rx
end_undef

begin_define
define|#
directive|define
name|PL_regcomp_rx
value|pPerl->PL_regcomp_rx
end_define

begin_undef
undef|#
directive|undef
name|PL_regcompp
end_undef

begin_define
define|#
directive|define
name|PL_regcompp
value|pPerl->PL_regcompp
end_define

begin_undef
undef|#
directive|undef
name|PL_regdata
end_undef

begin_define
define|#
directive|define
name|PL_regdata
value|pPerl->PL_regdata
end_define

begin_undef
undef|#
directive|undef
name|PL_regdummy
end_undef

begin_define
define|#
directive|define
name|PL_regdummy
value|pPerl->PL_regdummy
end_define

begin_undef
undef|#
directive|undef
name|PL_regendp
end_undef

begin_define
define|#
directive|define
name|PL_regendp
value|pPerl->PL_regendp
end_define

begin_undef
undef|#
directive|undef
name|PL_regeol
end_undef

begin_define
define|#
directive|define
name|PL_regeol
value|pPerl->PL_regeol
end_define

begin_undef
undef|#
directive|undef
name|PL_regexecp
end_undef

begin_define
define|#
directive|define
name|PL_regexecp
value|pPerl->PL_regexecp
end_define

begin_undef
undef|#
directive|undef
name|PL_regflags
end_undef

begin_define
define|#
directive|define
name|PL_regflags
value|pPerl->PL_regflags
end_define

begin_undef
undef|#
directive|undef
name|PL_regindent
end_undef

begin_define
define|#
directive|define
name|PL_regindent
value|pPerl->PL_regindent
end_define

begin_undef
undef|#
directive|undef
name|PL_reginput
end_undef

begin_define
define|#
directive|define
name|PL_reginput
value|pPerl->PL_reginput
end_define

begin_undef
undef|#
directive|undef
name|PL_reginterp_cnt
end_undef

begin_define
define|#
directive|define
name|PL_reginterp_cnt
value|pPerl->PL_reginterp_cnt
end_define

begin_undef
undef|#
directive|undef
name|PL_reglastparen
end_undef

begin_define
define|#
directive|define
name|PL_reglastparen
value|pPerl->PL_reglastparen
end_define

begin_undef
undef|#
directive|undef
name|PL_regnarrate
end_undef

begin_define
define|#
directive|define
name|PL_regnarrate
value|pPerl->PL_regnarrate
end_define

begin_undef
undef|#
directive|undef
name|PL_regnaughty
end_undef

begin_define
define|#
directive|define
name|PL_regnaughty
value|pPerl->PL_regnaughty
end_define

begin_undef
undef|#
directive|undef
name|PL_regnpar
end_undef

begin_define
define|#
directive|define
name|PL_regnpar
value|pPerl->PL_regnpar
end_define

begin_undef
undef|#
directive|undef
name|PL_regprecomp
end_undef

begin_define
define|#
directive|define
name|PL_regprecomp
value|pPerl->PL_regprecomp
end_define

begin_undef
undef|#
directive|undef
name|PL_regprev
end_undef

begin_define
define|#
directive|define
name|PL_regprev
value|pPerl->PL_regprev
end_define

begin_undef
undef|#
directive|undef
name|PL_regprogram
end_undef

begin_define
define|#
directive|define
name|PL_regprogram
value|pPerl->PL_regprogram
end_define

begin_undef
undef|#
directive|undef
name|PL_regsawback
end_undef

begin_define
define|#
directive|define
name|PL_regsawback
value|pPerl->PL_regsawback
end_define

begin_undef
undef|#
directive|undef
name|PL_regseen
end_undef

begin_define
define|#
directive|define
name|PL_regseen
value|pPerl->PL_regseen
end_define

begin_undef
undef|#
directive|undef
name|PL_regsize
end_undef

begin_define
define|#
directive|define
name|PL_regsize
value|pPerl->PL_regsize
end_define

begin_undef
undef|#
directive|undef
name|PL_regstartp
end_undef

begin_define
define|#
directive|define
name|PL_regstartp
value|pPerl->PL_regstartp
end_define

begin_undef
undef|#
directive|undef
name|PL_regtill
end_undef

begin_define
define|#
directive|define
name|PL_regtill
value|pPerl->PL_regtill
end_define

begin_undef
undef|#
directive|undef
name|PL_regxend
end_undef

begin_define
define|#
directive|define
name|PL_regxend
value|pPerl->PL_regxend
end_define

begin_undef
undef|#
directive|undef
name|PL_restartop
end_undef

begin_define
define|#
directive|define
name|PL_restartop
value|pPerl->PL_restartop
end_define

begin_undef
undef|#
directive|undef
name|PL_retstack
end_undef

begin_define
define|#
directive|define
name|PL_retstack
value|pPerl->PL_retstack
end_define

begin_undef
undef|#
directive|undef
name|PL_retstack_ix
end_undef

begin_define
define|#
directive|define
name|PL_retstack_ix
value|pPerl->PL_retstack_ix
end_define

begin_undef
undef|#
directive|undef
name|PL_retstack_max
end_undef

begin_define
define|#
directive|define
name|PL_retstack_max
value|pPerl->PL_retstack_max
end_define

begin_undef
undef|#
directive|undef
name|PL_rs
end_undef

begin_define
define|#
directive|define
name|PL_rs
value|pPerl->PL_rs
end_define

begin_undef
undef|#
directive|undef
name|PL_savestack
end_undef

begin_define
define|#
directive|define
name|PL_savestack
value|pPerl->PL_savestack
end_define

begin_undef
undef|#
directive|undef
name|PL_savestack_ix
end_undef

begin_define
define|#
directive|define
name|PL_savestack_ix
value|pPerl->PL_savestack_ix
end_define

begin_undef
undef|#
directive|undef
name|PL_savestack_max
end_undef

begin_define
define|#
directive|define
name|PL_savestack_max
value|pPerl->PL_savestack_max
end_define

begin_undef
undef|#
directive|undef
name|PL_scopestack
end_undef

begin_define
define|#
directive|define
name|PL_scopestack
value|pPerl->PL_scopestack
end_define

begin_undef
undef|#
directive|undef
name|PL_scopestack_ix
end_undef

begin_define
define|#
directive|define
name|PL_scopestack_ix
value|pPerl->PL_scopestack_ix
end_define

begin_undef
undef|#
directive|undef
name|PL_scopestack_max
end_undef

begin_define
define|#
directive|define
name|PL_scopestack_max
value|pPerl->PL_scopestack_max
end_define

begin_undef
undef|#
directive|undef
name|PL_screamfirst
end_undef

begin_define
define|#
directive|define
name|PL_screamfirst
value|pPerl->PL_screamfirst
end_define

begin_undef
undef|#
directive|undef
name|PL_screamnext
end_undef

begin_define
define|#
directive|define
name|PL_screamnext
value|pPerl->PL_screamnext
end_define

begin_undef
undef|#
directive|undef
name|PL_secondgv
end_undef

begin_define
define|#
directive|define
name|PL_secondgv
value|pPerl->PL_secondgv
end_define

begin_undef
undef|#
directive|undef
name|PL_seen_evals
end_undef

begin_define
define|#
directive|define
name|PL_seen_evals
value|pPerl->PL_seen_evals
end_define

begin_undef
undef|#
directive|undef
name|PL_seen_zerolen
end_undef

begin_define
define|#
directive|define
name|PL_seen_zerolen
value|pPerl->PL_seen_zerolen
end_define

begin_undef
undef|#
directive|undef
name|PL_sortcop
end_undef

begin_define
define|#
directive|define
name|PL_sortcop
value|pPerl->PL_sortcop
end_define

begin_undef
undef|#
directive|undef
name|PL_sortcxix
end_undef

begin_define
define|#
directive|define
name|PL_sortcxix
value|pPerl->PL_sortcxix
end_define

begin_undef
undef|#
directive|undef
name|PL_sortstash
end_undef

begin_define
define|#
directive|define
name|PL_sortstash
value|pPerl->PL_sortstash
end_define

begin_undef
undef|#
directive|undef
name|PL_stack_base
end_undef

begin_define
define|#
directive|define
name|PL_stack_base
value|pPerl->PL_stack_base
end_define

begin_undef
undef|#
directive|undef
name|PL_stack_max
end_undef

begin_define
define|#
directive|define
name|PL_stack_max
value|pPerl->PL_stack_max
end_define

begin_undef
undef|#
directive|undef
name|PL_stack_sp
end_undef

begin_define
define|#
directive|define
name|PL_stack_sp
value|pPerl->PL_stack_sp
end_define

begin_undef
undef|#
directive|undef
name|PL_start_env
end_undef

begin_define
define|#
directive|define
name|PL_start_env
value|pPerl->PL_start_env
end_define

begin_undef
undef|#
directive|undef
name|PL_statbuf
end_undef

begin_define
define|#
directive|define
name|PL_statbuf
value|pPerl->PL_statbuf
end_define

begin_undef
undef|#
directive|undef
name|PL_statcache
end_undef

begin_define
define|#
directive|define
name|PL_statcache
value|pPerl->PL_statcache
end_define

begin_undef
undef|#
directive|undef
name|PL_statgv
end_undef

begin_define
define|#
directive|define
name|PL_statgv
value|pPerl->PL_statgv
end_define

begin_undef
undef|#
directive|undef
name|PL_statname
end_undef

begin_define
define|#
directive|define
name|PL_statname
value|pPerl->PL_statname
end_define

begin_undef
undef|#
directive|undef
name|PL_tainted
end_undef

begin_define
define|#
directive|define
name|PL_tainted
value|pPerl->PL_tainted
end_define

begin_undef
undef|#
directive|undef
name|PL_timesbuf
end_undef

begin_define
define|#
directive|define
name|PL_timesbuf
value|pPerl->PL_timesbuf
end_define

begin_undef
undef|#
directive|undef
name|PL_tmps_floor
end_undef

begin_define
define|#
directive|define
name|PL_tmps_floor
value|pPerl->PL_tmps_floor
end_define

begin_undef
undef|#
directive|undef
name|PL_tmps_ix
end_undef

begin_define
define|#
directive|define
name|PL_tmps_ix
value|pPerl->PL_tmps_ix
end_define

begin_undef
undef|#
directive|undef
name|PL_tmps_max
end_undef

begin_define
define|#
directive|define
name|PL_tmps_max
value|pPerl->PL_tmps_max
end_define

begin_undef
undef|#
directive|undef
name|PL_tmps_stack
end_undef

begin_define
define|#
directive|define
name|PL_tmps_stack
value|pPerl->PL_tmps_stack
end_define

begin_undef
undef|#
directive|undef
name|PL_top_env
end_undef

begin_define
define|#
directive|define
name|PL_top_env
value|pPerl->PL_top_env
end_define

begin_undef
undef|#
directive|undef
name|PL_toptarget
end_undef

begin_define
define|#
directive|define
name|PL_toptarget
value|pPerl->PL_toptarget
end_define

begin_undef
undef|#
directive|undef
name|PL_Argv
end_undef

begin_define
define|#
directive|define
name|PL_Argv
value|pPerl->PL_Argv
end_define

begin_undef
undef|#
directive|undef
name|PL_Cmd
end_undef

begin_define
define|#
directive|define
name|PL_Cmd
value|pPerl->PL_Cmd
end_define

begin_undef
undef|#
directive|undef
name|PL_DBcv
end_undef

begin_define
define|#
directive|define
name|PL_DBcv
value|pPerl->PL_DBcv
end_define

begin_undef
undef|#
directive|undef
name|PL_DBgv
end_undef

begin_define
define|#
directive|define
name|PL_DBgv
value|pPerl->PL_DBgv
end_define

begin_undef
undef|#
directive|undef
name|PL_DBline
end_undef

begin_define
define|#
directive|define
name|PL_DBline
value|pPerl->PL_DBline
end_define

begin_undef
undef|#
directive|undef
name|PL_DBsignal
end_undef

begin_define
define|#
directive|define
name|PL_DBsignal
value|pPerl->PL_DBsignal
end_define

begin_undef
undef|#
directive|undef
name|PL_DBsingle
end_undef

begin_define
define|#
directive|define
name|PL_DBsingle
value|pPerl->PL_DBsingle
end_define

begin_undef
undef|#
directive|undef
name|PL_DBsub
end_undef

begin_define
define|#
directive|define
name|PL_DBsub
value|pPerl->PL_DBsub
end_define

begin_undef
undef|#
directive|undef
name|PL_DBtrace
end_undef

begin_define
define|#
directive|define
name|PL_DBtrace
value|pPerl->PL_DBtrace
end_define

begin_undef
undef|#
directive|undef
name|PL_ampergv
end_undef

begin_define
define|#
directive|define
name|PL_ampergv
value|pPerl->PL_ampergv
end_define

begin_undef
undef|#
directive|undef
name|PL_archpat_auto
end_undef

begin_define
define|#
directive|define
name|PL_archpat_auto
value|pPerl->PL_archpat_auto
end_define

begin_undef
undef|#
directive|undef
name|PL_argvgv
end_undef

begin_define
define|#
directive|define
name|PL_argvgv
value|pPerl->PL_argvgv
end_define

begin_undef
undef|#
directive|undef
name|PL_argvoutgv
end_undef

begin_define
define|#
directive|define
name|PL_argvoutgv
value|pPerl->PL_argvoutgv
end_define

begin_undef
undef|#
directive|undef
name|PL_basetime
end_undef

begin_define
define|#
directive|define
name|PL_basetime
value|pPerl->PL_basetime
end_define

begin_undef
undef|#
directive|undef
name|PL_beginav
end_undef

begin_define
define|#
directive|define
name|PL_beginav
value|pPerl->PL_beginav
end_define

begin_undef
undef|#
directive|undef
name|PL_cddir
end_undef

begin_define
define|#
directive|define
name|PL_cddir
value|pPerl->PL_cddir
end_define

begin_undef
undef|#
directive|undef
name|PL_compcv
end_undef

begin_define
define|#
directive|define
name|PL_compcv
value|pPerl->PL_compcv
end_define

begin_undef
undef|#
directive|undef
name|PL_compiling
end_undef

begin_define
define|#
directive|define
name|PL_compiling
value|pPerl->PL_compiling
end_define

begin_undef
undef|#
directive|undef
name|PL_comppad
end_undef

begin_define
define|#
directive|define
name|PL_comppad
value|pPerl->PL_comppad
end_define

begin_undef
undef|#
directive|undef
name|PL_comppad_name
end_undef

begin_define
define|#
directive|define
name|PL_comppad_name
value|pPerl->PL_comppad_name
end_define

begin_undef
undef|#
directive|undef
name|PL_comppad_name_fill
end_undef

begin_define
define|#
directive|define
name|PL_comppad_name_fill
value|pPerl->PL_comppad_name_fill
end_define

begin_undef
undef|#
directive|undef
name|PL_comppad_name_floor
end_undef

begin_define
define|#
directive|define
name|PL_comppad_name_floor
value|pPerl->PL_comppad_name_floor
end_define

begin_undef
undef|#
directive|undef
name|PL_copline
end_undef

begin_define
define|#
directive|define
name|PL_copline
value|pPerl->PL_copline
end_define

begin_undef
undef|#
directive|undef
name|PL_curcopdb
end_undef

begin_define
define|#
directive|define
name|PL_curcopdb
value|pPerl->PL_curcopdb
end_define

begin_undef
undef|#
directive|undef
name|PL_curstname
end_undef

begin_define
define|#
directive|define
name|PL_curstname
value|pPerl->PL_curstname
end_define

begin_undef
undef|#
directive|undef
name|PL_dbargs
end_undef

begin_define
define|#
directive|define
name|PL_dbargs
value|pPerl->PL_dbargs
end_define

begin_undef
undef|#
directive|undef
name|PL_debdelim
end_undef

begin_define
define|#
directive|define
name|PL_debdelim
value|pPerl->PL_debdelim
end_define

begin_undef
undef|#
directive|undef
name|PL_debname
end_undef

begin_define
define|#
directive|define
name|PL_debname
value|pPerl->PL_debname
end_define

begin_undef
undef|#
directive|undef
name|PL_debstash
end_undef

begin_define
define|#
directive|define
name|PL_debstash
value|pPerl->PL_debstash
end_define

begin_undef
undef|#
directive|undef
name|PL_defgv
end_undef

begin_define
define|#
directive|define
name|PL_defgv
value|pPerl->PL_defgv
end_define

begin_undef
undef|#
directive|undef
name|PL_diehook
end_undef

begin_define
define|#
directive|define
name|PL_diehook
value|pPerl->PL_diehook
end_define

begin_undef
undef|#
directive|undef
name|PL_dlevel
end_undef

begin_define
define|#
directive|define
name|PL_dlevel
value|pPerl->PL_dlevel
end_define

begin_undef
undef|#
directive|undef
name|PL_dlmax
end_undef

begin_define
define|#
directive|define
name|PL_dlmax
value|pPerl->PL_dlmax
end_define

begin_undef
undef|#
directive|undef
name|PL_doextract
end_undef

begin_define
define|#
directive|define
name|PL_doextract
value|pPerl->PL_doextract
end_define

begin_undef
undef|#
directive|undef
name|PL_doswitches
end_undef

begin_define
define|#
directive|define
name|PL_doswitches
value|pPerl->PL_doswitches
end_define

begin_undef
undef|#
directive|undef
name|PL_dowarn
end_undef

begin_define
define|#
directive|define
name|PL_dowarn
value|pPerl->PL_dowarn
end_define

begin_undef
undef|#
directive|undef
name|PL_dumplvl
end_undef

begin_define
define|#
directive|define
name|PL_dumplvl
value|pPerl->PL_dumplvl
end_define

begin_undef
undef|#
directive|undef
name|PL_e_script
end_undef

begin_define
define|#
directive|define
name|PL_e_script
value|pPerl->PL_e_script
end_define

begin_undef
undef|#
directive|undef
name|PL_endav
end_undef

begin_define
define|#
directive|define
name|PL_endav
value|pPerl->PL_endav
end_define

begin_undef
undef|#
directive|undef
name|PL_envgv
end_undef

begin_define
define|#
directive|define
name|PL_envgv
value|pPerl->PL_envgv
end_define

begin_undef
undef|#
directive|undef
name|PL_errgv
end_undef

begin_define
define|#
directive|define
name|PL_errgv
value|pPerl->PL_errgv
end_define

begin_undef
undef|#
directive|undef
name|PL_eval_root
end_undef

begin_define
define|#
directive|define
name|PL_eval_root
value|pPerl->PL_eval_root
end_define

begin_undef
undef|#
directive|undef
name|PL_eval_start
end_undef

begin_define
define|#
directive|define
name|PL_eval_start
value|pPerl->PL_eval_start
end_define

begin_undef
undef|#
directive|undef
name|PL_exitlist
end_undef

begin_define
define|#
directive|define
name|PL_exitlist
value|pPerl->PL_exitlist
end_define

begin_undef
undef|#
directive|undef
name|PL_exitlistlen
end_undef

begin_define
define|#
directive|define
name|PL_exitlistlen
value|pPerl->PL_exitlistlen
end_define

begin_undef
undef|#
directive|undef
name|PL_fdpid
end_undef

begin_define
define|#
directive|define
name|PL_fdpid
value|pPerl->PL_fdpid
end_define

begin_undef
undef|#
directive|undef
name|PL_filemode
end_undef

begin_define
define|#
directive|define
name|PL_filemode
value|pPerl->PL_filemode
end_define

begin_undef
undef|#
directive|undef
name|PL_forkprocess
end_undef

begin_define
define|#
directive|define
name|PL_forkprocess
value|pPerl->PL_forkprocess
end_define

begin_undef
undef|#
directive|undef
name|PL_formfeed
end_undef

begin_define
define|#
directive|define
name|PL_formfeed
value|pPerl->PL_formfeed
end_define

begin_undef
undef|#
directive|undef
name|PL_generation
end_undef

begin_define
define|#
directive|define
name|PL_generation
value|pPerl->PL_generation
end_define

begin_undef
undef|#
directive|undef
name|PL_gensym
end_undef

begin_define
define|#
directive|define
name|PL_gensym
value|pPerl->PL_gensym
end_define

begin_undef
undef|#
directive|undef
name|PL_globalstash
end_undef

begin_define
define|#
directive|define
name|PL_globalstash
value|pPerl->PL_globalstash
end_define

begin_undef
undef|#
directive|undef
name|PL_hintgv
end_undef

begin_define
define|#
directive|define
name|PL_hintgv
value|pPerl->PL_hintgv
end_define

begin_undef
undef|#
directive|undef
name|PL_in_clean_all
end_undef

begin_define
define|#
directive|define
name|PL_in_clean_all
value|pPerl->PL_in_clean_all
end_define

begin_undef
undef|#
directive|undef
name|PL_in_clean_objs
end_undef

begin_define
define|#
directive|define
name|PL_in_clean_objs
value|pPerl->PL_in_clean_objs
end_define

begin_undef
undef|#
directive|undef
name|PL_incgv
end_undef

begin_define
define|#
directive|define
name|PL_incgv
value|pPerl->PL_incgv
end_define

begin_undef
undef|#
directive|undef
name|PL_initav
end_undef

begin_define
define|#
directive|define
name|PL_initav
value|pPerl->PL_initav
end_define

begin_undef
undef|#
directive|undef
name|PL_inplace
end_undef

begin_define
define|#
directive|define
name|PL_inplace
value|pPerl->PL_inplace
end_define

begin_undef
undef|#
directive|undef
name|PL_last_proto
end_undef

begin_define
define|#
directive|define
name|PL_last_proto
value|pPerl->PL_last_proto
end_define

begin_undef
undef|#
directive|undef
name|PL_lastfd
end_undef

begin_define
define|#
directive|define
name|PL_lastfd
value|pPerl->PL_lastfd
end_define

begin_undef
undef|#
directive|undef
name|PL_lastsize
end_undef

begin_define
define|#
directive|define
name|PL_lastsize
value|pPerl->PL_lastsize
end_define

begin_undef
undef|#
directive|undef
name|PL_lastspbase
end_undef

begin_define
define|#
directive|define
name|PL_lastspbase
value|pPerl->PL_lastspbase
end_define

begin_undef
undef|#
directive|undef
name|PL_laststatval
end_undef

begin_define
define|#
directive|define
name|PL_laststatval
value|pPerl->PL_laststatval
end_define

begin_undef
undef|#
directive|undef
name|PL_laststype
end_undef

begin_define
define|#
directive|define
name|PL_laststype
value|pPerl->PL_laststype
end_define

begin_undef
undef|#
directive|undef
name|PL_leftgv
end_undef

begin_define
define|#
directive|define
name|PL_leftgv
value|pPerl->PL_leftgv
end_define

begin_undef
undef|#
directive|undef
name|PL_lineary
end_undef

begin_define
define|#
directive|define
name|PL_lineary
value|pPerl->PL_lineary
end_define

begin_undef
undef|#
directive|undef
name|PL_linestart
end_undef

begin_define
define|#
directive|define
name|PL_linestart
value|pPerl->PL_linestart
end_define

begin_undef
undef|#
directive|undef
name|PL_localpatches
end_undef

begin_define
define|#
directive|define
name|PL_localpatches
value|pPerl->PL_localpatches
end_define

begin_undef
undef|#
directive|undef
name|PL_main_cv
end_undef

begin_define
define|#
directive|define
name|PL_main_cv
value|pPerl->PL_main_cv
end_define

begin_undef
undef|#
directive|undef
name|PL_main_root
end_undef

begin_define
define|#
directive|define
name|PL_main_root
value|pPerl->PL_main_root
end_define

begin_undef
undef|#
directive|undef
name|PL_main_start
end_undef

begin_define
define|#
directive|define
name|PL_main_start
value|pPerl->PL_main_start
end_define

begin_undef
undef|#
directive|undef
name|PL_maxsysfd
end_undef

begin_define
define|#
directive|define
name|PL_maxsysfd
value|pPerl->PL_maxsysfd
end_define

begin_undef
undef|#
directive|undef
name|PL_mess_sv
end_undef

begin_define
define|#
directive|define
name|PL_mess_sv
value|pPerl->PL_mess_sv
end_define

begin_undef
undef|#
directive|undef
name|PL_minus_F
end_undef

begin_define
define|#
directive|define
name|PL_minus_F
value|pPerl->PL_minus_F
end_define

begin_undef
undef|#
directive|undef
name|PL_minus_a
end_undef

begin_define
define|#
directive|define
name|PL_minus_a
value|pPerl->PL_minus_a
end_define

begin_undef
undef|#
directive|undef
name|PL_minus_c
end_undef

begin_define
define|#
directive|define
name|PL_minus_c
value|pPerl->PL_minus_c
end_define

begin_undef
undef|#
directive|undef
name|PL_minus_l
end_undef

begin_define
define|#
directive|define
name|PL_minus_l
value|pPerl->PL_minus_l
end_define

begin_undef
undef|#
directive|undef
name|PL_minus_n
end_undef

begin_define
define|#
directive|define
name|PL_minus_n
value|pPerl->PL_minus_n
end_define

begin_undef
undef|#
directive|undef
name|PL_minus_p
end_undef

begin_define
define|#
directive|define
name|PL_minus_p
value|pPerl->PL_minus_p
end_define

begin_undef
undef|#
directive|undef
name|PL_modglobal
end_undef

begin_define
define|#
directive|define
name|PL_modglobal
value|pPerl->PL_modglobal
end_define

begin_undef
undef|#
directive|undef
name|PL_multiline
end_undef

begin_define
define|#
directive|define
name|PL_multiline
value|pPerl->PL_multiline
end_define

begin_undef
undef|#
directive|undef
name|PL_mystrk
end_undef

begin_define
define|#
directive|define
name|PL_mystrk
value|pPerl->PL_mystrk
end_define

begin_undef
undef|#
directive|undef
name|PL_ofmt
end_undef

begin_define
define|#
directive|define
name|PL_ofmt
value|pPerl->PL_ofmt
end_define

begin_undef
undef|#
directive|undef
name|PL_oldlastpm
end_undef

begin_define
define|#
directive|define
name|PL_oldlastpm
value|pPerl->PL_oldlastpm
end_define

begin_undef
undef|#
directive|undef
name|PL_oldname
end_undef

begin_define
define|#
directive|define
name|PL_oldname
value|pPerl->PL_oldname
end_define

begin_undef
undef|#
directive|undef
name|PL_op_mask
end_undef

begin_define
define|#
directive|define
name|PL_op_mask
value|pPerl->PL_op_mask
end_define

begin_undef
undef|#
directive|undef
name|PL_origargc
end_undef

begin_define
define|#
directive|define
name|PL_origargc
value|pPerl->PL_origargc
end_define

begin_undef
undef|#
directive|undef
name|PL_origargv
end_undef

begin_define
define|#
directive|define
name|PL_origargv
value|pPerl->PL_origargv
end_define

begin_undef
undef|#
directive|undef
name|PL_origfilename
end_undef

begin_define
define|#
directive|define
name|PL_origfilename
value|pPerl->PL_origfilename
end_define

begin_undef
undef|#
directive|undef
name|PL_ors
end_undef

begin_define
define|#
directive|define
name|PL_ors
value|pPerl->PL_ors
end_define

begin_undef
undef|#
directive|undef
name|PL_orslen
end_undef

begin_define
define|#
directive|define
name|PL_orslen
value|pPerl->PL_orslen
end_define

begin_undef
undef|#
directive|undef
name|PL_parsehook
end_undef

begin_define
define|#
directive|define
name|PL_parsehook
value|pPerl->PL_parsehook
end_define

begin_undef
undef|#
directive|undef
name|PL_patchlevel
end_undef

begin_define
define|#
directive|define
name|PL_patchlevel
value|pPerl->PL_patchlevel
end_define

begin_undef
undef|#
directive|undef
name|PL_pending_ident
end_undef

begin_define
define|#
directive|define
name|PL_pending_ident
value|pPerl->PL_pending_ident
end_define

begin_undef
undef|#
directive|undef
name|PL_perl_destruct_level
end_undef

begin_define
define|#
directive|define
name|PL_perl_destruct_level
value|pPerl->PL_perl_destruct_level
end_define

begin_undef
undef|#
directive|undef
name|PL_perldb
end_undef

begin_define
define|#
directive|define
name|PL_perldb
value|pPerl->PL_perldb
end_define

begin_undef
undef|#
directive|undef
name|PL_preambleav
end_undef

begin_define
define|#
directive|define
name|PL_preambleav
value|pPerl->PL_preambleav
end_define

begin_undef
undef|#
directive|undef
name|PL_preambled
end_undef

begin_define
define|#
directive|define
name|PL_preambled
value|pPerl->PL_preambled
end_define

begin_undef
undef|#
directive|undef
name|PL_preprocess
end_undef

begin_define
define|#
directive|define
name|PL_preprocess
value|pPerl->PL_preprocess
end_define

begin_undef
undef|#
directive|undef
name|PL_profiledata
end_undef

begin_define
define|#
directive|define
name|PL_profiledata
value|pPerl->PL_profiledata
end_define

begin_undef
undef|#
directive|undef
name|PL_replgv
end_undef

begin_define
define|#
directive|define
name|PL_replgv
value|pPerl->PL_replgv
end_define

begin_undef
undef|#
directive|undef
name|PL_rightgv
end_undef

begin_define
define|#
directive|define
name|PL_rightgv
value|pPerl->PL_rightgv
end_define

begin_undef
undef|#
directive|undef
name|PL_rsfp
end_undef

begin_define
define|#
directive|define
name|PL_rsfp
value|pPerl->PL_rsfp
end_define

begin_undef
undef|#
directive|undef
name|PL_rsfp_filters
end_undef

begin_define
define|#
directive|define
name|PL_rsfp_filters
value|pPerl->PL_rsfp_filters
end_define

begin_undef
undef|#
directive|undef
name|PL_sawampersand
end_undef

begin_define
define|#
directive|define
name|PL_sawampersand
value|pPerl->PL_sawampersand
end_define

begin_undef
undef|#
directive|undef
name|PL_sawstudy
end_undef

begin_define
define|#
directive|define
name|PL_sawstudy
value|pPerl->PL_sawstudy
end_define

begin_undef
undef|#
directive|undef
name|PL_sawvec
end_undef

begin_define
define|#
directive|define
name|PL_sawvec
value|pPerl->PL_sawvec
end_define

begin_undef
undef|#
directive|undef
name|PL_siggv
end_undef

begin_define
define|#
directive|define
name|PL_siggv
value|pPerl->PL_siggv
end_define

begin_undef
undef|#
directive|undef
name|PL_splitstr
end_undef

begin_define
define|#
directive|define
name|PL_splitstr
value|pPerl->PL_splitstr
end_define

begin_undef
undef|#
directive|undef
name|PL_statusvalue
end_undef

begin_define
define|#
directive|define
name|PL_statusvalue
value|pPerl->PL_statusvalue
end_define

begin_undef
undef|#
directive|undef
name|PL_statusvalue_vms
end_undef

begin_define
define|#
directive|define
name|PL_statusvalue_vms
value|pPerl->PL_statusvalue_vms
end_define

begin_undef
undef|#
directive|undef
name|PL_stdingv
end_undef

begin_define
define|#
directive|define
name|PL_stdingv
value|pPerl->PL_stdingv
end_define

begin_undef
undef|#
directive|undef
name|PL_strchop
end_undef

begin_define
define|#
directive|define
name|PL_strchop
value|pPerl->PL_strchop
end_define

begin_undef
undef|#
directive|undef
name|PL_strtab
end_undef

begin_define
define|#
directive|define
name|PL_strtab
value|pPerl->PL_strtab
end_define

begin_undef
undef|#
directive|undef
name|PL_strtab_mutex
end_undef

begin_define
define|#
directive|define
name|PL_strtab_mutex
value|pPerl->PL_strtab_mutex
end_define

begin_undef
undef|#
directive|undef
name|PL_sub_generation
end_undef

begin_define
define|#
directive|define
name|PL_sub_generation
value|pPerl->PL_sub_generation
end_define

begin_undef
undef|#
directive|undef
name|PL_sublex_info
end_undef

begin_define
define|#
directive|define
name|PL_sublex_info
value|pPerl->PL_sublex_info
end_define

begin_undef
undef|#
directive|undef
name|PL_sv_arenaroot
end_undef

begin_define
define|#
directive|define
name|PL_sv_arenaroot
value|pPerl->PL_sv_arenaroot
end_define

begin_undef
undef|#
directive|undef
name|PL_sv_count
end_undef

begin_define
define|#
directive|define
name|PL_sv_count
value|pPerl->PL_sv_count
end_define

begin_undef
undef|#
directive|undef
name|PL_sv_objcount
end_undef

begin_define
define|#
directive|define
name|PL_sv_objcount
value|pPerl->PL_sv_objcount
end_define

begin_undef
undef|#
directive|undef
name|PL_sv_root
end_undef

begin_define
define|#
directive|define
name|PL_sv_root
value|pPerl->PL_sv_root
end_define

begin_undef
undef|#
directive|undef
name|PL_sys_intern
end_undef

begin_define
define|#
directive|define
name|PL_sys_intern
value|pPerl->PL_sys_intern
end_define

begin_undef
undef|#
directive|undef
name|PL_tainting
end_undef

begin_define
define|#
directive|define
name|PL_tainting
value|pPerl->PL_tainting
end_define

begin_undef
undef|#
directive|undef
name|PL_threadnum
end_undef

begin_define
define|#
directive|define
name|PL_threadnum
value|pPerl->PL_threadnum
end_define

begin_undef
undef|#
directive|undef
name|PL_thrsv
end_undef

begin_define
define|#
directive|define
name|PL_thrsv
value|pPerl->PL_thrsv
end_define

begin_undef
undef|#
directive|undef
name|PL_unsafe
end_undef

begin_define
define|#
directive|define
name|PL_unsafe
value|pPerl->PL_unsafe
end_define

begin_undef
undef|#
directive|undef
name|PL_warnhook
end_undef

begin_define
define|#
directive|define
name|PL_warnhook
value|pPerl->PL_warnhook
end_define

begin_undef
undef|#
directive|undef
name|PL_No
end_undef

begin_define
define|#
directive|define
name|PL_No
value|pPerl->PL_No
end_define

begin_undef
undef|#
directive|undef
name|PL_Yes
end_undef

begin_define
define|#
directive|define
name|PL_Yes
value|pPerl->PL_Yes
end_define

begin_undef
undef|#
directive|undef
name|PL_amagic_generation
end_undef

begin_define
define|#
directive|define
name|PL_amagic_generation
value|pPerl->PL_amagic_generation
end_define

begin_undef
undef|#
directive|undef
name|PL_an
end_undef

begin_define
define|#
directive|define
name|PL_an
value|pPerl->PL_an
end_define

begin_undef
undef|#
directive|undef
name|PL_bufend
end_undef

begin_define
define|#
directive|define
name|PL_bufend
value|pPerl->PL_bufend
end_define

begin_undef
undef|#
directive|undef
name|PL_bufptr
end_undef

begin_define
define|#
directive|define
name|PL_bufptr
value|pPerl->PL_bufptr
end_define

begin_undef
undef|#
directive|undef
name|PL_collation_ix
end_undef

begin_define
define|#
directive|define
name|PL_collation_ix
value|pPerl->PL_collation_ix
end_define

begin_undef
undef|#
directive|undef
name|PL_collation_name
end_undef

begin_define
define|#
directive|define
name|PL_collation_name
value|pPerl->PL_collation_name
end_define

begin_undef
undef|#
directive|undef
name|PL_collation_standard
end_undef

begin_define
define|#
directive|define
name|PL_collation_standard
value|pPerl->PL_collation_standard
end_define

begin_undef
undef|#
directive|undef
name|PL_collxfrm_base
end_undef

begin_define
define|#
directive|define
name|PL_collxfrm_base
value|pPerl->PL_collxfrm_base
end_define

begin_undef
undef|#
directive|undef
name|PL_collxfrm_mult
end_undef

begin_define
define|#
directive|define
name|PL_collxfrm_mult
value|pPerl->PL_collxfrm_mult
end_define

begin_undef
undef|#
directive|undef
name|PL_cop_seqmax
end_undef

begin_define
define|#
directive|define
name|PL_cop_seqmax
value|pPerl->PL_cop_seqmax
end_define

begin_undef
undef|#
directive|undef
name|PL_cryptseen
end_undef

begin_define
define|#
directive|define
name|PL_cryptseen
value|pPerl->PL_cryptseen
end_define

begin_undef
undef|#
directive|undef
name|PL_cshlen
end_undef

begin_define
define|#
directive|define
name|PL_cshlen
value|pPerl->PL_cshlen
end_define

begin_undef
undef|#
directive|undef
name|PL_cshname
end_undef

begin_define
define|#
directive|define
name|PL_cshname
value|pPerl->PL_cshname
end_define

begin_undef
undef|#
directive|undef
name|PL_curinterp
end_undef

begin_define
define|#
directive|define
name|PL_curinterp
value|pPerl->PL_curinterp
end_define

begin_undef
undef|#
directive|undef
name|PL_curthr
end_undef

begin_define
define|#
directive|define
name|PL_curthr
value|pPerl->PL_curthr
end_define

begin_undef
undef|#
directive|undef
name|PL_debug
end_undef

begin_define
define|#
directive|define
name|PL_debug
value|pPerl->PL_debug
end_define

begin_undef
undef|#
directive|undef
name|PL_do_undump
end_undef

begin_define
define|#
directive|define
name|PL_do_undump
value|pPerl->PL_do_undump
end_define

begin_undef
undef|#
directive|undef
name|PL_egid
end_undef

begin_define
define|#
directive|define
name|PL_egid
value|pPerl->PL_egid
end_define

begin_undef
undef|#
directive|undef
name|PL_error_count
end_undef

begin_define
define|#
directive|define
name|PL_error_count
value|pPerl->PL_error_count
end_define

begin_undef
undef|#
directive|undef
name|PL_euid
end_undef

begin_define
define|#
directive|define
name|PL_euid
value|pPerl->PL_euid
end_define

begin_undef
undef|#
directive|undef
name|PL_eval_cond
end_undef

begin_define
define|#
directive|define
name|PL_eval_cond
value|pPerl->PL_eval_cond
end_define

begin_undef
undef|#
directive|undef
name|PL_eval_mutex
end_undef

begin_define
define|#
directive|define
name|PL_eval_mutex
value|pPerl->PL_eval_mutex
end_define

begin_undef
undef|#
directive|undef
name|PL_eval_owner
end_undef

begin_define
define|#
directive|define
name|PL_eval_owner
value|pPerl->PL_eval_owner
end_define

begin_undef
undef|#
directive|undef
name|PL_evalseq
end_undef

begin_define
define|#
directive|define
name|PL_evalseq
value|pPerl->PL_evalseq
end_define

begin_undef
undef|#
directive|undef
name|PL_expect
end_undef

begin_define
define|#
directive|define
name|PL_expect
value|pPerl->PL_expect
end_define

begin_undef
undef|#
directive|undef
name|PL_gid
end_undef

begin_define
define|#
directive|define
name|PL_gid
value|pPerl->PL_gid
end_define

begin_undef
undef|#
directive|undef
name|PL_he_root
end_undef

begin_define
define|#
directive|define
name|PL_he_root
value|pPerl->PL_he_root
end_define

begin_undef
undef|#
directive|undef
name|PL_hexdigit
end_undef

begin_define
define|#
directive|define
name|PL_hexdigit
value|pPerl->PL_hexdigit
end_define

begin_undef
undef|#
directive|undef
name|PL_hints
end_undef

begin_define
define|#
directive|define
name|PL_hints
value|pPerl->PL_hints
end_define

begin_undef
undef|#
directive|undef
name|PL_in_my
end_undef

begin_define
define|#
directive|define
name|PL_in_my
value|pPerl->PL_in_my
end_define

begin_undef
undef|#
directive|undef
name|PL_in_my_stash
end_undef

begin_define
define|#
directive|define
name|PL_in_my_stash
value|pPerl->PL_in_my_stash
end_define

begin_undef
undef|#
directive|undef
name|PL_last_lop
end_undef

begin_define
define|#
directive|define
name|PL_last_lop
value|pPerl->PL_last_lop
end_define

begin_undef
undef|#
directive|undef
name|PL_last_lop_op
end_undef

begin_define
define|#
directive|define
name|PL_last_lop_op
value|pPerl->PL_last_lop_op
end_define

begin_undef
undef|#
directive|undef
name|PL_last_uni
end_undef

begin_define
define|#
directive|define
name|PL_last_uni
value|pPerl->PL_last_uni
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_brackets
end_undef

begin_define
define|#
directive|define
name|PL_lex_brackets
value|pPerl->PL_lex_brackets
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_brackstack
end_undef

begin_define
define|#
directive|define
name|PL_lex_brackstack
value|pPerl->PL_lex_brackstack
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_casemods
end_undef

begin_define
define|#
directive|define
name|PL_lex_casemods
value|pPerl->PL_lex_casemods
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_casestack
end_undef

begin_define
define|#
directive|define
name|PL_lex_casestack
value|pPerl->PL_lex_casestack
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_defer
end_undef

begin_define
define|#
directive|define
name|PL_lex_defer
value|pPerl->PL_lex_defer
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_dojoin
end_undef

begin_define
define|#
directive|define
name|PL_lex_dojoin
value|pPerl->PL_lex_dojoin
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_expect
end_undef

begin_define
define|#
directive|define
name|PL_lex_expect
value|pPerl->PL_lex_expect
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_fakebrack
end_undef

begin_define
define|#
directive|define
name|PL_lex_fakebrack
value|pPerl->PL_lex_fakebrack
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_formbrack
end_undef

begin_define
define|#
directive|define
name|PL_lex_formbrack
value|pPerl->PL_lex_formbrack
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_inpat
end_undef

begin_define
define|#
directive|define
name|PL_lex_inpat
value|pPerl->PL_lex_inpat
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_inwhat
end_undef

begin_define
define|#
directive|define
name|PL_lex_inwhat
value|pPerl->PL_lex_inwhat
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_op
end_undef

begin_define
define|#
directive|define
name|PL_lex_op
value|pPerl->PL_lex_op
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_repl
end_undef

begin_define
define|#
directive|define
name|PL_lex_repl
value|pPerl->PL_lex_repl
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_starts
end_undef

begin_define
define|#
directive|define
name|PL_lex_starts
value|pPerl->PL_lex_starts
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_state
end_undef

begin_define
define|#
directive|define
name|PL_lex_state
value|pPerl->PL_lex_state
end_define

begin_undef
undef|#
directive|undef
name|PL_lex_stuff
end_undef

begin_define
define|#
directive|define
name|PL_lex_stuff
value|pPerl->PL_lex_stuff
end_define

begin_undef
undef|#
directive|undef
name|PL_linestr
end_undef

begin_define
define|#
directive|define
name|PL_linestr
value|pPerl->PL_linestr
end_define

begin_undef
undef|#
directive|undef
name|PL_malloc_mutex
end_undef

begin_define
define|#
directive|define
name|PL_malloc_mutex
value|pPerl->PL_malloc_mutex
end_define

begin_undef
undef|#
directive|undef
name|PL_max_intro_pending
end_undef

begin_define
define|#
directive|define
name|PL_max_intro_pending
value|pPerl->PL_max_intro_pending
end_define

begin_undef
undef|#
directive|undef
name|PL_maxo
end_undef

begin_define
define|#
directive|define
name|PL_maxo
value|pPerl->PL_maxo
end_define

begin_undef
undef|#
directive|undef
name|PL_min_intro_pending
end_undef

begin_define
define|#
directive|define
name|PL_min_intro_pending
value|pPerl->PL_min_intro_pending
end_define

begin_undef
undef|#
directive|undef
name|PL_multi_close
end_undef

begin_define
define|#
directive|define
name|PL_multi_close
value|pPerl->PL_multi_close
end_define

begin_undef
undef|#
directive|undef
name|PL_multi_end
end_undef

begin_define
define|#
directive|define
name|PL_multi_end
value|pPerl->PL_multi_end
end_define

begin_undef
undef|#
directive|undef
name|PL_multi_open
end_undef

begin_define
define|#
directive|define
name|PL_multi_open
value|pPerl->PL_multi_open
end_define

begin_undef
undef|#
directive|undef
name|PL_multi_start
end_undef

begin_define
define|#
directive|define
name|PL_multi_start
value|pPerl->PL_multi_start
end_define

begin_undef
undef|#
directive|undef
name|PL_na
end_undef

begin_define
define|#
directive|define
name|PL_na
value|pPerl->PL_na
end_define

begin_undef
undef|#
directive|undef
name|PL_nexttoke
end_undef

begin_define
define|#
directive|define
name|PL_nexttoke
value|pPerl->PL_nexttoke
end_define

begin_undef
undef|#
directive|undef
name|PL_nexttype
end_undef

begin_define
define|#
directive|define
name|PL_nexttype
value|pPerl->PL_nexttype
end_define

begin_undef
undef|#
directive|undef
name|PL_nextval
end_undef

begin_define
define|#
directive|define
name|PL_nextval
value|pPerl->PL_nextval
end_define

begin_undef
undef|#
directive|undef
name|PL_nice_chunk
end_undef

begin_define
define|#
directive|define
name|PL_nice_chunk
value|pPerl->PL_nice_chunk
end_define

begin_undef
undef|#
directive|undef
name|PL_nice_chunk_size
end_undef

begin_define
define|#
directive|define
name|PL_nice_chunk_size
value|pPerl->PL_nice_chunk_size
end_define

begin_undef
undef|#
directive|undef
name|PL_ninterps
end_undef

begin_define
define|#
directive|define
name|PL_ninterps
value|pPerl->PL_ninterps
end_define

begin_undef
undef|#
directive|undef
name|PL_nomemok
end_undef

begin_define
define|#
directive|define
name|PL_nomemok
value|pPerl->PL_nomemok
end_define

begin_undef
undef|#
directive|undef
name|PL_nthreads
end_undef

begin_define
define|#
directive|define
name|PL_nthreads
value|pPerl->PL_nthreads
end_define

begin_undef
undef|#
directive|undef
name|PL_nthreads_cond
end_undef

begin_define
define|#
directive|define
name|PL_nthreads_cond
value|pPerl->PL_nthreads_cond
end_define

begin_undef
undef|#
directive|undef
name|PL_numeric_local
end_undef

begin_define
define|#
directive|define
name|PL_numeric_local
value|pPerl->PL_numeric_local
end_define

begin_undef
undef|#
directive|undef
name|PL_numeric_name
end_undef

begin_define
define|#
directive|define
name|PL_numeric_name
value|pPerl->PL_numeric_name
end_define

begin_undef
undef|#
directive|undef
name|PL_numeric_standard
end_undef

begin_define
define|#
directive|define
name|PL_numeric_standard
value|pPerl->PL_numeric_standard
end_define

begin_undef
undef|#
directive|undef
name|PL_oldbufptr
end_undef

begin_define
define|#
directive|define
name|PL_oldbufptr
value|pPerl->PL_oldbufptr
end_define

begin_undef
undef|#
directive|undef
name|PL_oldoldbufptr
end_undef

begin_define
define|#
directive|define
name|PL_oldoldbufptr
value|pPerl->PL_oldoldbufptr
end_define

begin_undef
undef|#
directive|undef
name|PL_op_seqmax
end_undef

begin_define
define|#
directive|define
name|PL_op_seqmax
value|pPerl->PL_op_seqmax
end_define

begin_undef
undef|#
directive|undef
name|PL_origalen
end_undef

begin_define
define|#
directive|define
name|PL_origalen
value|pPerl->PL_origalen
end_define

begin_undef
undef|#
directive|undef
name|PL_origenviron
end_undef

begin_define
define|#
directive|define
name|PL_origenviron
value|pPerl->PL_origenviron
end_define

begin_undef
undef|#
directive|undef
name|PL_osname
end_undef

begin_define
define|#
directive|define
name|PL_osname
value|pPerl->PL_osname
end_define

begin_undef
undef|#
directive|undef
name|PL_pad_reset_pending
end_undef

begin_define
define|#
directive|define
name|PL_pad_reset_pending
value|pPerl->PL_pad_reset_pending
end_define

begin_undef
undef|#
directive|undef
name|PL_padix
end_undef

begin_define
define|#
directive|define
name|PL_padix
value|pPerl->PL_padix
end_define

begin_undef
undef|#
directive|undef
name|PL_padix_floor
end_undef

begin_define
define|#
directive|define
name|PL_padix_floor
value|pPerl->PL_padix_floor
end_define

begin_undef
undef|#
directive|undef
name|PL_patleave
end_undef

begin_define
define|#
directive|define
name|PL_patleave
value|pPerl->PL_patleave
end_define

begin_undef
undef|#
directive|undef
name|PL_pidstatus
end_undef

begin_define
define|#
directive|define
name|PL_pidstatus
value|pPerl->PL_pidstatus
end_define

begin_undef
undef|#
directive|undef
name|PL_runops
end_undef

begin_define
define|#
directive|define
name|PL_runops
value|pPerl->PL_runops
end_define

begin_undef
undef|#
directive|undef
name|PL_sh_path
end_undef

begin_define
define|#
directive|define
name|PL_sh_path
value|pPerl->PL_sh_path
end_define

begin_undef
undef|#
directive|undef
name|PL_sighandlerp
end_undef

begin_define
define|#
directive|define
name|PL_sighandlerp
value|pPerl->PL_sighandlerp
end_define

begin_undef
undef|#
directive|undef
name|PL_specialsv_list
end_undef

begin_define
define|#
directive|define
name|PL_specialsv_list
value|pPerl->PL_specialsv_list
end_define

begin_undef
undef|#
directive|undef
name|PL_subline
end_undef

begin_define
define|#
directive|define
name|PL_subline
value|pPerl->PL_subline
end_define

begin_undef
undef|#
directive|undef
name|PL_subname
end_undef

begin_define
define|#
directive|define
name|PL_subname
value|pPerl->PL_subname
end_define

begin_undef
undef|#
directive|undef
name|PL_sv_mutex
end_undef

begin_define
define|#
directive|define
name|PL_sv_mutex
value|pPerl->PL_sv_mutex
end_define

begin_undef
undef|#
directive|undef
name|PL_sv_no
end_undef

begin_define
define|#
directive|define
name|PL_sv_no
value|pPerl->PL_sv_no
end_define

begin_undef
undef|#
directive|undef
name|PL_sv_undef
end_undef

begin_define
define|#
directive|define
name|PL_sv_undef
value|pPerl->PL_sv_undef
end_define

begin_undef
undef|#
directive|undef
name|PL_sv_yes
end_undef

begin_define
define|#
directive|define
name|PL_sv_yes
value|pPerl->PL_sv_yes
end_define

begin_undef
undef|#
directive|undef
name|PL_svref_mutex
end_undef

begin_define
define|#
directive|define
name|PL_svref_mutex
value|pPerl->PL_svref_mutex
end_define

begin_undef
undef|#
directive|undef
name|PL_thisexpr
end_undef

begin_define
define|#
directive|define
name|PL_thisexpr
value|pPerl->PL_thisexpr
end_define

begin_undef
undef|#
directive|undef
name|PL_thr_key
end_undef

begin_define
define|#
directive|define
name|PL_thr_key
value|pPerl->PL_thr_key
end_define

begin_undef
undef|#
directive|undef
name|PL_threads_mutex
end_undef

begin_define
define|#
directive|define
name|PL_threads_mutex
value|pPerl->PL_threads_mutex
end_define

begin_undef
undef|#
directive|undef
name|PL_threadsv_names
end_undef

begin_define
define|#
directive|define
name|PL_threadsv_names
value|pPerl->PL_threadsv_names
end_define

begin_undef
undef|#
directive|undef
name|PL_tokenbuf
end_undef

begin_define
define|#
directive|define
name|PL_tokenbuf
value|pPerl->PL_tokenbuf
end_define

begin_undef
undef|#
directive|undef
name|PL_uid
end_undef

begin_define
define|#
directive|define
name|PL_uid
value|pPerl->PL_uid
end_define

begin_undef
undef|#
directive|undef
name|PL_xiv_arenaroot
end_undef

begin_define
define|#
directive|define
name|PL_xiv_arenaroot
value|pPerl->PL_xiv_arenaroot
end_define

begin_undef
undef|#
directive|undef
name|PL_xiv_root
end_undef

begin_define
define|#
directive|define
name|PL_xiv_root
value|pPerl->PL_xiv_root
end_define

begin_undef
undef|#
directive|undef
name|PL_xnv_root
end_undef

begin_define
define|#
directive|define
name|PL_xnv_root
value|pPerl->PL_xnv_root
end_define

begin_undef
undef|#
directive|undef
name|PL_xpv_root
end_undef

begin_define
define|#
directive|define
name|PL_xpv_root
value|pPerl->PL_xpv_root
end_define

begin_undef
undef|#
directive|undef
name|PL_xrv_root
end_undef

begin_define
define|#
directive|define
name|PL_xrv_root
value|pPerl->PL_xrv_root
end_define

begin_comment
comment|/* Functions */
end_comment

begin_undef
undef|#
directive|undef
name|amagic_call
end_undef

begin_define
define|#
directive|define
name|amagic_call
value|pPerl->Perl_amagic_call
end_define

begin_undef
undef|#
directive|undef
name|Perl_GetVars
end_undef

begin_define
define|#
directive|define
name|Perl_GetVars
value|pPerl->Perl_GetVars
end_define

begin_undef
undef|#
directive|undef
name|Gv_AMupdate
end_undef

begin_define
define|#
directive|define
name|Gv_AMupdate
value|pPerl->Perl_Gv_AMupdate
end_define

begin_undef
undef|#
directive|undef
name|append_elem
end_undef

begin_define
define|#
directive|define
name|append_elem
value|pPerl->Perl_append_elem
end_define

begin_undef
undef|#
directive|undef
name|append_list
end_undef

begin_define
define|#
directive|define
name|append_list
value|pPerl->Perl_append_list
end_define

begin_undef
undef|#
directive|undef
name|apply
end_undef

begin_define
define|#
directive|define
name|apply
value|pPerl->Perl_apply
end_define

begin_undef
undef|#
directive|undef
name|assertref
end_undef

begin_define
define|#
directive|define
name|assertref
value|pPerl->Perl_assertref
end_define

begin_undef
undef|#
directive|undef
name|av_clear
end_undef

begin_define
define|#
directive|define
name|av_clear
value|pPerl->Perl_av_clear
end_define

begin_undef
undef|#
directive|undef
name|av_extend
end_undef

begin_define
define|#
directive|define
name|av_extend
value|pPerl->Perl_av_extend
end_define

begin_undef
undef|#
directive|undef
name|av_fake
end_undef

begin_define
define|#
directive|define
name|av_fake
value|pPerl->Perl_av_fake
end_define

begin_undef
undef|#
directive|undef
name|av_fetch
end_undef

begin_define
define|#
directive|define
name|av_fetch
value|pPerl->Perl_av_fetch
end_define

begin_undef
undef|#
directive|undef
name|av_fill
end_undef

begin_define
define|#
directive|define
name|av_fill
value|pPerl->Perl_av_fill
end_define

begin_undef
undef|#
directive|undef
name|av_len
end_undef

begin_define
define|#
directive|define
name|av_len
value|pPerl->Perl_av_len
end_define

begin_undef
undef|#
directive|undef
name|av_make
end_undef

begin_define
define|#
directive|define
name|av_make
value|pPerl->Perl_av_make
end_define

begin_undef
undef|#
directive|undef
name|av_pop
end_undef

begin_define
define|#
directive|define
name|av_pop
value|pPerl->Perl_av_pop
end_define

begin_undef
undef|#
directive|undef
name|av_push
end_undef

begin_define
define|#
directive|define
name|av_push
value|pPerl->Perl_av_push
end_define

begin_undef
undef|#
directive|undef
name|av_reify
end_undef

begin_define
define|#
directive|define
name|av_reify
value|pPerl->Perl_av_reify
end_define

begin_undef
undef|#
directive|undef
name|av_shift
end_undef

begin_define
define|#
directive|define
name|av_shift
value|pPerl->Perl_av_shift
end_define

begin_undef
undef|#
directive|undef
name|av_store
end_undef

begin_define
define|#
directive|define
name|av_store
value|pPerl->Perl_av_store
end_define

begin_undef
undef|#
directive|undef
name|av_undef
end_undef

begin_define
define|#
directive|define
name|av_undef
value|pPerl->Perl_av_undef
end_define

begin_undef
undef|#
directive|undef
name|av_unshift
end_undef

begin_define
define|#
directive|define
name|av_unshift
value|pPerl->Perl_av_unshift
end_define

begin_undef
undef|#
directive|undef
name|avhv_exists_ent
end_undef

begin_define
define|#
directive|define
name|avhv_exists_ent
value|pPerl->Perl_avhv_exists_ent
end_define

begin_undef
undef|#
directive|undef
name|avhv_fetch_ent
end_undef

begin_define
define|#
directive|define
name|avhv_fetch_ent
value|pPerl->Perl_avhv_fetch_ent
end_define

begin_undef
undef|#
directive|undef
name|avhv_iternext
end_undef

begin_define
define|#
directive|define
name|avhv_iternext
value|pPerl->Perl_avhv_iternext
end_define

begin_undef
undef|#
directive|undef
name|avhv_iterval
end_undef

begin_define
define|#
directive|define
name|avhv_iterval
value|pPerl->Perl_avhv_iterval
end_define

begin_undef
undef|#
directive|undef
name|avhv_keys
end_undef

begin_define
define|#
directive|define
name|avhv_keys
value|pPerl->Perl_avhv_keys
end_define

begin_undef
undef|#
directive|undef
name|bind_match
end_undef

begin_define
define|#
directive|define
name|bind_match
value|pPerl->Perl_bind_match
end_define

begin_undef
undef|#
directive|undef
name|block_end
end_undef

begin_define
define|#
directive|define
name|block_end
value|pPerl->Perl_block_end
end_define

begin_undef
undef|#
directive|undef
name|block_gimme
end_undef

begin_define
define|#
directive|define
name|block_gimme
value|pPerl->Perl_block_gimme
end_define

begin_undef
undef|#
directive|undef
name|block_start
end_undef

begin_define
define|#
directive|define
name|block_start
value|pPerl->Perl_block_start
end_define

begin_undef
undef|#
directive|undef
name|byterun
end_undef

begin_define
define|#
directive|define
name|byterun
value|pPerl->Perl_byterun
end_define

begin_undef
undef|#
directive|undef
name|call_list
end_undef

begin_define
define|#
directive|define
name|call_list
value|pPerl->Perl_call_list
end_define

begin_undef
undef|#
directive|undef
name|cando
end_undef

begin_define
define|#
directive|define
name|cando
value|pPerl->Perl_cando
end_define

begin_undef
undef|#
directive|undef
name|cast_ulong
end_undef

begin_define
define|#
directive|define
name|cast_ulong
value|pPerl->Perl_cast_ulong
end_define

begin_undef
undef|#
directive|undef
name|checkcomma
end_undef

begin_define
define|#
directive|define
name|checkcomma
value|pPerl->Perl_checkcomma
end_define

begin_undef
undef|#
directive|undef
name|check_uni
end_undef

begin_define
define|#
directive|define
name|check_uni
value|pPerl->Perl_check_uni
end_define

begin_undef
undef|#
directive|undef
name|ck_concat
end_undef

begin_define
define|#
directive|define
name|ck_concat
value|pPerl->Perl_ck_concat
end_define

begin_undef
undef|#
directive|undef
name|ck_delete
end_undef

begin_define
define|#
directive|define
name|ck_delete
value|pPerl->Perl_ck_delete
end_define

begin_undef
undef|#
directive|undef
name|ck_eof
end_undef

begin_define
define|#
directive|define
name|ck_eof
value|pPerl->Perl_ck_eof
end_define

begin_undef
undef|#
directive|undef
name|ck_eval
end_undef

begin_define
define|#
directive|define
name|ck_eval
value|pPerl->Perl_ck_eval
end_define

begin_undef
undef|#
directive|undef
name|ck_exec
end_undef

begin_define
define|#
directive|define
name|ck_exec
value|pPerl->Perl_ck_exec
end_define

begin_undef
undef|#
directive|undef
name|ck_formline
end_undef

begin_define
define|#
directive|define
name|ck_formline
value|pPerl->Perl_ck_formline
end_define

begin_undef
undef|#
directive|undef
name|ck_ftst
end_undef

begin_define
define|#
directive|define
name|ck_ftst
value|pPerl->Perl_ck_ftst
end_define

begin_undef
undef|#
directive|undef
name|ck_fun
end_undef

begin_define
define|#
directive|define
name|ck_fun
value|pPerl->Perl_ck_fun
end_define

begin_undef
undef|#
directive|undef
name|ck_glob
end_undef

begin_define
define|#
directive|define
name|ck_glob
value|pPerl->Perl_ck_glob
end_define

begin_undef
undef|#
directive|undef
name|ck_grep
end_undef

begin_define
define|#
directive|define
name|ck_grep
value|pPerl->Perl_ck_grep
end_define

begin_undef
undef|#
directive|undef
name|ck_gvconst
end_undef

begin_define
define|#
directive|define
name|ck_gvconst
value|pPerl->Perl_ck_gvconst
end_define

begin_undef
undef|#
directive|undef
name|ck_index
end_undef

begin_define
define|#
directive|define
name|ck_index
value|pPerl->Perl_ck_index
end_define

begin_undef
undef|#
directive|undef
name|ck_lengthconst
end_undef

begin_define
define|#
directive|define
name|ck_lengthconst
value|pPerl->Perl_ck_lengthconst
end_define

begin_undef
undef|#
directive|undef
name|ck_lfun
end_undef

begin_define
define|#
directive|define
name|ck_lfun
value|pPerl->Perl_ck_lfun
end_define

begin_undef
undef|#
directive|undef
name|ck_listiob
end_undef

begin_define
define|#
directive|define
name|ck_listiob
value|pPerl->Perl_ck_listiob
end_define

begin_undef
undef|#
directive|undef
name|ck_match
end_undef

begin_define
define|#
directive|define
name|ck_match
value|pPerl->Perl_ck_match
end_define

begin_undef
undef|#
directive|undef
name|ck_null
end_undef

begin_define
define|#
directive|define
name|ck_null
value|pPerl->Perl_ck_null
end_define

begin_undef
undef|#
directive|undef
name|ck_repeat
end_undef

begin_define
define|#
directive|define
name|ck_repeat
value|pPerl->Perl_ck_repeat
end_define

begin_undef
undef|#
directive|undef
name|ck_require
end_undef

begin_define
define|#
directive|define
name|ck_require
value|pPerl->Perl_ck_require
end_define

begin_undef
undef|#
directive|undef
name|ck_retarget
end_undef

begin_define
define|#
directive|define
name|ck_retarget
value|pPerl->Perl_ck_retarget
end_define

begin_undef
undef|#
directive|undef
name|ck_rfun
end_undef

begin_define
define|#
directive|define
name|ck_rfun
value|pPerl->Perl_ck_rfun
end_define

begin_undef
undef|#
directive|undef
name|ck_rvconst
end_undef

begin_define
define|#
directive|define
name|ck_rvconst
value|pPerl->Perl_ck_rvconst
end_define

begin_undef
undef|#
directive|undef
name|ck_select
end_undef

begin_define
define|#
directive|define
name|ck_select
value|pPerl->Perl_ck_select
end_define

begin_undef
undef|#
directive|undef
name|ck_shift
end_undef

begin_define
define|#
directive|define
name|ck_shift
value|pPerl->Perl_ck_shift
end_define

begin_undef
undef|#
directive|undef
name|ck_sort
end_undef

begin_define
define|#
directive|define
name|ck_sort
value|pPerl->Perl_ck_sort
end_define

begin_undef
undef|#
directive|undef
name|ck_spair
end_undef

begin_define
define|#
directive|define
name|ck_spair
value|pPerl->Perl_ck_spair
end_define

begin_undef
undef|#
directive|undef
name|ck_split
end_undef

begin_define
define|#
directive|define
name|ck_split
value|pPerl->Perl_ck_split
end_define

begin_undef
undef|#
directive|undef
name|ck_subr
end_undef

begin_define
define|#
directive|define
name|ck_subr
value|pPerl->Perl_ck_subr
end_define

begin_undef
undef|#
directive|undef
name|ck_svconst
end_undef

begin_define
define|#
directive|define
name|ck_svconst
value|pPerl->Perl_ck_svconst
end_define

begin_undef
undef|#
directive|undef
name|ck_trunc
end_undef

begin_define
define|#
directive|define
name|ck_trunc
value|pPerl->Perl_ck_trunc
end_define

begin_undef
undef|#
directive|undef
name|condpair_magic
end_undef

begin_define
define|#
directive|define
name|condpair_magic
value|pPerl->Perl_condpair_magic
end_define

begin_undef
undef|#
directive|undef
name|convert
end_undef

begin_define
define|#
directive|define
name|convert
value|pPerl->Perl_convert
end_define

begin_undef
undef|#
directive|undef
name|cpytill
end_undef

begin_define
define|#
directive|define
name|cpytill
value|pPerl->Perl_cpytill
end_define

begin_undef
undef|#
directive|undef
name|croak
end_undef

begin_define
define|#
directive|define
name|croak
value|pPerl->Perl_croak
end_define

begin_undef
undef|#
directive|undef
name|cv_ckproto
end_undef

begin_define
define|#
directive|define
name|cv_ckproto
value|pPerl->Perl_cv_ckproto
end_define

begin_undef
undef|#
directive|undef
name|cv_clone
end_undef

begin_define
define|#
directive|define
name|cv_clone
value|pPerl->Perl_cv_clone
end_define

begin_undef
undef|#
directive|undef
name|cv_const_sv
end_undef

begin_define
define|#
directive|define
name|cv_const_sv
value|pPerl->Perl_cv_const_sv
end_define

begin_undef
undef|#
directive|undef
name|cv_undef
end_undef

begin_define
define|#
directive|define
name|cv_undef
value|pPerl->Perl_cv_undef
end_define

begin_undef
undef|#
directive|undef
name|cx_dump
end_undef

begin_define
define|#
directive|define
name|cx_dump
value|pPerl->Perl_cx_dump
end_define

begin_undef
undef|#
directive|undef
name|cxinc
end_undef

begin_define
define|#
directive|define
name|cxinc
value|pPerl->Perl_cxinc
end_define

begin_undef
undef|#
directive|undef
name|deb
end_undef

begin_define
define|#
directive|define
name|deb
value|pPerl->Perl_deb
end_define

begin_undef
undef|#
directive|undef
name|deb_growlevel
end_undef

begin_define
define|#
directive|define
name|deb_growlevel
value|pPerl->Perl_deb_growlevel
end_define

begin_undef
undef|#
directive|undef
name|debprofdump
end_undef

begin_define
define|#
directive|define
name|debprofdump
value|pPerl->Perl_debprofdump
end_define

begin_undef
undef|#
directive|undef
name|debop
end_undef

begin_define
define|#
directive|define
name|debop
value|pPerl->Perl_debop
end_define

begin_undef
undef|#
directive|undef
name|debstack
end_undef

begin_define
define|#
directive|define
name|debstack
value|pPerl->Perl_debstack
end_define

begin_undef
undef|#
directive|undef
name|debstackptrs
end_undef

begin_define
define|#
directive|define
name|debstackptrs
value|pPerl->Perl_debstackptrs
end_define

begin_undef
undef|#
directive|undef
name|delimcpy
end_undef

begin_define
define|#
directive|define
name|delimcpy
value|pPerl->Perl_delimcpy
end_define

begin_undef
undef|#
directive|undef
name|deprecate
end_undef

begin_define
define|#
directive|define
name|deprecate
value|pPerl->Perl_deprecate
end_define

begin_undef
undef|#
directive|undef
name|die
end_undef

begin_define
define|#
directive|define
name|die
value|pPerl->Perl_die
end_define

begin_undef
undef|#
directive|undef
name|die_where
end_undef

begin_define
define|#
directive|define
name|die_where
value|pPerl->Perl_die_where
end_define

begin_undef
undef|#
directive|undef
name|dopoptoeval
end_undef

begin_define
define|#
directive|define
name|dopoptoeval
value|pPerl->Perl_dopoptoeval
end_define

begin_undef
undef|#
directive|undef
name|dounwind
end_undef

begin_define
define|#
directive|define
name|dounwind
value|pPerl->Perl_dounwind
end_define

begin_undef
undef|#
directive|undef
name|do_aexec
end_undef

begin_define
define|#
directive|define
name|do_aexec
value|pPerl->Perl_do_aexec
end_define

begin_undef
undef|#
directive|undef
name|do_binmode
end_undef

begin_define
define|#
directive|define
name|do_binmode
value|pPerl->Perl_do_binmode
end_define

begin_undef
undef|#
directive|undef
name|do_chomp
end_undef

begin_define
define|#
directive|define
name|do_chomp
value|pPerl->Perl_do_chomp
end_define

begin_undef
undef|#
directive|undef
name|do_chop
end_undef

begin_define
define|#
directive|define
name|do_chop
value|pPerl->Perl_do_chop
end_define

begin_undef
undef|#
directive|undef
name|do_close
end_undef

begin_define
define|#
directive|define
name|do_close
value|pPerl->Perl_do_close
end_define

begin_undef
undef|#
directive|undef
name|do_eof
end_undef

begin_define
define|#
directive|define
name|do_eof
value|pPerl->Perl_do_eof
end_define

begin_undef
undef|#
directive|undef
name|do_exec
end_undef

begin_define
define|#
directive|define
name|do_exec
value|pPerl->Perl_do_exec
end_define

begin_undef
undef|#
directive|undef
name|do_execfree
end_undef

begin_define
define|#
directive|define
name|do_execfree
value|pPerl->Perl_do_execfree
end_define

begin_undef
undef|#
directive|undef
name|do_join
end_undef

begin_define
define|#
directive|define
name|do_join
value|pPerl->Perl_do_join
end_define

begin_undef
undef|#
directive|undef
name|do_kv
end_undef

begin_define
define|#
directive|define
name|do_kv
value|pPerl->Perl_do_kv
end_define

begin_undef
undef|#
directive|undef
name|do_open
end_undef

begin_define
define|#
directive|define
name|do_open
value|pPerl->Perl_do_open
end_define

begin_undef
undef|#
directive|undef
name|do_pipe
end_undef

begin_define
define|#
directive|define
name|do_pipe
value|pPerl->Perl_do_pipe
end_define

begin_undef
undef|#
directive|undef
name|do_print
end_undef

begin_define
define|#
directive|define
name|do_print
value|pPerl->Perl_do_print
end_define

begin_undef
undef|#
directive|undef
name|do_readline
end_undef

begin_define
define|#
directive|define
name|do_readline
value|pPerl->Perl_do_readline
end_define

begin_undef
undef|#
directive|undef
name|do_seek
end_undef

begin_define
define|#
directive|define
name|do_seek
value|pPerl->Perl_do_seek
end_define

begin_undef
undef|#
directive|undef
name|do_sprintf
end_undef

begin_define
define|#
directive|define
name|do_sprintf
value|pPerl->Perl_do_sprintf
end_define

begin_undef
undef|#
directive|undef
name|do_sysseek
end_undef

begin_define
define|#
directive|define
name|do_sysseek
value|pPerl->Perl_do_sysseek
end_define

begin_undef
undef|#
directive|undef
name|do_tell
end_undef

begin_define
define|#
directive|define
name|do_tell
value|pPerl->Perl_do_tell
end_define

begin_undef
undef|#
directive|undef
name|do_trans
end_undef

begin_define
define|#
directive|define
name|do_trans
value|pPerl->Perl_do_trans
end_define

begin_undef
undef|#
directive|undef
name|do_vecset
end_undef

begin_define
define|#
directive|define
name|do_vecset
value|pPerl->Perl_do_vecset
end_define

begin_undef
undef|#
directive|undef
name|do_vop
end_undef

begin_define
define|#
directive|define
name|do_vop
value|pPerl->Perl_do_vop
end_define

begin_undef
undef|#
directive|undef
name|dofile
end_undef

begin_define
define|#
directive|define
name|dofile
value|pPerl->Perl_dofile
end_define

begin_undef
undef|#
directive|undef
name|dowantarray
end_undef

begin_define
define|#
directive|define
name|dowantarray
value|pPerl->Perl_dowantarray
end_define

begin_undef
undef|#
directive|undef
name|dump_all
end_undef

begin_define
define|#
directive|define
name|dump_all
value|pPerl->Perl_dump_all
end_define

begin_undef
undef|#
directive|undef
name|dump_eval
end_undef

begin_define
define|#
directive|define
name|dump_eval
value|pPerl->Perl_dump_eval
end_define

begin_undef
undef|#
directive|undef
name|dump_fds
end_undef

begin_define
define|#
directive|define
name|dump_fds
value|pPerl->Perl_dump_fds
end_define

begin_undef
undef|#
directive|undef
name|dump_form
end_undef

begin_define
define|#
directive|define
name|dump_form
value|pPerl->Perl_dump_form
end_define

begin_undef
undef|#
directive|undef
name|dump_gv
end_undef

begin_define
define|#
directive|define
name|dump_gv
value|pPerl->Perl_dump_gv
end_define

begin_undef
undef|#
directive|undef
name|dump_mstats
end_undef

begin_define
define|#
directive|define
name|dump_mstats
value|pPerl->Perl_dump_mstats
end_define

begin_undef
undef|#
directive|undef
name|dump_op
end_undef

begin_define
define|#
directive|define
name|dump_op
value|pPerl->Perl_dump_op
end_define

begin_undef
undef|#
directive|undef
name|dump_pm
end_undef

begin_define
define|#
directive|define
name|dump_pm
value|pPerl->Perl_dump_pm
end_define

begin_undef
undef|#
directive|undef
name|dump_packsubs
end_undef

begin_define
define|#
directive|define
name|dump_packsubs
value|pPerl->Perl_dump_packsubs
end_define

begin_undef
undef|#
directive|undef
name|dump_sub
end_undef

begin_define
define|#
directive|define
name|dump_sub
value|pPerl->Perl_dump_sub
end_define

begin_undef
undef|#
directive|undef
name|fbm_compile
end_undef

begin_define
define|#
directive|define
name|fbm_compile
value|pPerl->Perl_fbm_compile
end_define

begin_undef
undef|#
directive|undef
name|fbm_instr
end_undef

begin_define
define|#
directive|define
name|fbm_instr
value|pPerl->Perl_fbm_instr
end_define

begin_undef
undef|#
directive|undef
name|filter_add
end_undef

begin_define
define|#
directive|define
name|filter_add
value|pPerl->Perl_filter_add
end_define

begin_undef
undef|#
directive|undef
name|filter_del
end_undef

begin_define
define|#
directive|define
name|filter_del
value|pPerl->Perl_filter_del
end_define

begin_undef
undef|#
directive|undef
name|filter_read
end_undef

begin_define
define|#
directive|define
name|filter_read
value|pPerl->Perl_filter_read
end_define

begin_undef
undef|#
directive|undef
name|find_threadsv
end_undef

begin_define
define|#
directive|define
name|find_threadsv
value|pPerl->Perl_find_threadsv
end_define

begin_undef
undef|#
directive|undef
name|find_script
end_undef

begin_define
define|#
directive|define
name|find_script
value|pPerl->Perl_find_script
end_define

begin_undef
undef|#
directive|undef
name|force_ident
end_undef

begin_define
define|#
directive|define
name|force_ident
value|pPerl->Perl_force_ident
end_define

begin_undef
undef|#
directive|undef
name|force_list
end_undef

begin_define
define|#
directive|define
name|force_list
value|pPerl->Perl_force_list
end_define

begin_undef
undef|#
directive|undef
name|force_next
end_undef

begin_define
define|#
directive|define
name|force_next
value|pPerl->Perl_force_next
end_define

begin_undef
undef|#
directive|undef
name|force_word
end_undef

begin_define
define|#
directive|define
name|force_word
value|pPerl->Perl_force_word
end_define

begin_undef
undef|#
directive|undef
name|form
end_undef

begin_define
define|#
directive|define
name|form
value|pPerl->Perl_form
end_define

begin_undef
undef|#
directive|undef
name|fold_constants
end_undef

begin_define
define|#
directive|define
name|fold_constants
value|pPerl->Perl_fold_constants
end_define

begin_undef
undef|#
directive|undef
name|fprintf
end_undef

begin_define
define|#
directive|define
name|fprintf
value|pPerl->fprintf
end_define

begin_undef
undef|#
directive|undef
name|free_tmps
end_undef

begin_define
define|#
directive|define
name|free_tmps
value|pPerl->Perl_free_tmps
end_define

begin_undef
undef|#
directive|undef
name|gen_constant_list
end_undef

begin_define
define|#
directive|define
name|gen_constant_list
value|pPerl->Perl_gen_constant_list
end_define

begin_undef
undef|#
directive|undef
name|get_op_descs
end_undef

begin_define
define|#
directive|define
name|get_op_descs
value|pPerl->Perl_get_op_descs
end_define

begin_undef
undef|#
directive|undef
name|get_op_names
end_undef

begin_define
define|#
directive|define
name|get_op_names
value|pPerl->Perl_get_op_names
end_define

begin_undef
undef|#
directive|undef
name|get_no_modify
end_undef

begin_define
define|#
directive|define
name|get_no_modify
value|pPerl->Perl_get_no_modify
end_define

begin_undef
undef|#
directive|undef
name|get_opargs
end_undef

begin_define
define|#
directive|define
name|get_opargs
value|pPerl->Perl_get_opargs
end_define

begin_undef
undef|#
directive|undef
name|get_specialsv_list
end_undef

begin_define
define|#
directive|define
name|get_specialsv_list
value|pPerl->Perl_get_specialsv_list
end_define

begin_undef
undef|#
directive|undef
name|get_vtbl
end_undef

begin_define
define|#
directive|define
name|get_vtbl
value|pPerl->Perl_get_vtbl
end_define

begin_undef
undef|#
directive|undef
name|gp_free
end_undef

begin_define
define|#
directive|define
name|gp_free
value|pPerl->Perl_gp_free
end_define

begin_undef
undef|#
directive|undef
name|gp_ref
end_undef

begin_define
define|#
directive|define
name|gp_ref
value|pPerl->Perl_gp_ref
end_define

begin_undef
undef|#
directive|undef
name|gv_AVadd
end_undef

begin_define
define|#
directive|define
name|gv_AVadd
value|pPerl->Perl_gv_AVadd
end_define

begin_undef
undef|#
directive|undef
name|gv_HVadd
end_undef

begin_define
define|#
directive|define
name|gv_HVadd
value|pPerl->Perl_gv_HVadd
end_define

begin_undef
undef|#
directive|undef
name|gv_IOadd
end_undef

begin_define
define|#
directive|define
name|gv_IOadd
value|pPerl->Perl_gv_IOadd
end_define

begin_undef
undef|#
directive|undef
name|gv_autoload4
end_undef

begin_define
define|#
directive|define
name|gv_autoload4
value|pPerl->Perl_gv_autoload4
end_define

begin_undef
undef|#
directive|undef
name|gv_check
end_undef

begin_define
define|#
directive|define
name|gv_check
value|pPerl->Perl_gv_check
end_define

begin_undef
undef|#
directive|undef
name|gv_efullname
end_undef

begin_define
define|#
directive|define
name|gv_efullname
value|pPerl->Perl_gv_efullname
end_define

begin_undef
undef|#
directive|undef
name|gv_efullname3
end_undef

begin_define
define|#
directive|define
name|gv_efullname3
value|pPerl->Perl_gv_efullname3
end_define

begin_undef
undef|#
directive|undef
name|gv_fetchfile
end_undef

begin_define
define|#
directive|define
name|gv_fetchfile
value|pPerl->Perl_gv_fetchfile
end_define

begin_undef
undef|#
directive|undef
name|gv_fetchmeth
end_undef

begin_define
define|#
directive|define
name|gv_fetchmeth
value|pPerl->Perl_gv_fetchmeth
end_define

begin_undef
undef|#
directive|undef
name|gv_fetchmethod
end_undef

begin_define
define|#
directive|define
name|gv_fetchmethod
value|pPerl->Perl_gv_fetchmethod
end_define

begin_undef
undef|#
directive|undef
name|gv_fetchmethod_autoload
end_undef

begin_define
define|#
directive|define
name|gv_fetchmethod_autoload
value|pPerl->Perl_gv_fetchmethod_autoload
end_define

begin_undef
undef|#
directive|undef
name|gv_fetchpv
end_undef

begin_define
define|#
directive|define
name|gv_fetchpv
value|pPerl->Perl_gv_fetchpv
end_define

begin_undef
undef|#
directive|undef
name|gv_fullname
end_undef

begin_define
define|#
directive|define
name|gv_fullname
value|pPerl->Perl_gv_fullname
end_define

begin_undef
undef|#
directive|undef
name|gv_fullname3
end_undef

begin_define
define|#
directive|define
name|gv_fullname3
value|pPerl->Perl_gv_fullname3
end_define

begin_undef
undef|#
directive|undef
name|gv_init
end_undef

begin_define
define|#
directive|define
name|gv_init
value|pPerl->Perl_gv_init
end_define

begin_undef
undef|#
directive|undef
name|gv_stashpv
end_undef

begin_define
define|#
directive|define
name|gv_stashpv
value|pPerl->Perl_gv_stashpv
end_define

begin_undef
undef|#
directive|undef
name|gv_stashpvn
end_undef

begin_define
define|#
directive|define
name|gv_stashpvn
value|pPerl->Perl_gv_stashpvn
end_define

begin_undef
undef|#
directive|undef
name|gv_stashsv
end_undef

begin_define
define|#
directive|define
name|gv_stashsv
value|pPerl->Perl_gv_stashsv
end_define

begin_undef
undef|#
directive|undef
name|he_delayfree
end_undef

begin_define
define|#
directive|define
name|he_delayfree
value|pPerl->Perl_he_delayfree
end_define

begin_undef
undef|#
directive|undef
name|he_free
end_undef

begin_define
define|#
directive|define
name|he_free
value|pPerl->Perl_he_free
end_define

begin_undef
undef|#
directive|undef
name|hoistmust
end_undef

begin_define
define|#
directive|define
name|hoistmust
value|pPerl->Perl_hoistmust
end_define

begin_undef
undef|#
directive|undef
name|hv_clear
end_undef

begin_define
define|#
directive|define
name|hv_clear
value|pPerl->Perl_hv_clear
end_define

begin_undef
undef|#
directive|undef
name|hv_delayfree_ent
end_undef

begin_define
define|#
directive|define
name|hv_delayfree_ent
value|pPerl->Perl_hv_delayfree_ent
end_define

begin_undef
undef|#
directive|undef
name|hv_delete
end_undef

begin_define
define|#
directive|define
name|hv_delete
value|pPerl->Perl_hv_delete
end_define

begin_undef
undef|#
directive|undef
name|hv_delete_ent
end_undef

begin_define
define|#
directive|define
name|hv_delete_ent
value|pPerl->Perl_hv_delete_ent
end_define

begin_undef
undef|#
directive|undef
name|hv_exists
end_undef

begin_define
define|#
directive|define
name|hv_exists
value|pPerl->Perl_hv_exists
end_define

begin_undef
undef|#
directive|undef
name|hv_exists_ent
end_undef

begin_define
define|#
directive|define
name|hv_exists_ent
value|pPerl->Perl_hv_exists_ent
end_define

begin_undef
undef|#
directive|undef
name|hv_fetch
end_undef

begin_define
define|#
directive|define
name|hv_fetch
value|pPerl->Perl_hv_fetch
end_define

begin_undef
undef|#
directive|undef
name|hv_fetch_ent
end_undef

begin_define
define|#
directive|define
name|hv_fetch_ent
value|pPerl->Perl_hv_fetch_ent
end_define

begin_undef
undef|#
directive|undef
name|hv_free_ent
end_undef

begin_define
define|#
directive|define
name|hv_free_ent
value|pPerl->Perl_hv_free_ent
end_define

begin_undef
undef|#
directive|undef
name|hv_iterinit
end_undef

begin_define
define|#
directive|define
name|hv_iterinit
value|pPerl->Perl_hv_iterinit
end_define

begin_undef
undef|#
directive|undef
name|hv_iterkey
end_undef

begin_define
define|#
directive|define
name|hv_iterkey
value|pPerl->Perl_hv_iterkey
end_define

begin_undef
undef|#
directive|undef
name|hv_iterkeysv
end_undef

begin_define
define|#
directive|define
name|hv_iterkeysv
value|pPerl->Perl_hv_iterkeysv
end_define

begin_undef
undef|#
directive|undef
name|hv_iternext
end_undef

begin_define
define|#
directive|define
name|hv_iternext
value|pPerl->Perl_hv_iternext
end_define

begin_undef
undef|#
directive|undef
name|hv_iternextsv
end_undef

begin_define
define|#
directive|define
name|hv_iternextsv
value|pPerl->Perl_hv_iternextsv
end_define

begin_undef
undef|#
directive|undef
name|hv_iterval
end_undef

begin_define
define|#
directive|define
name|hv_iterval
value|pPerl->Perl_hv_iterval
end_define

begin_undef
undef|#
directive|undef
name|hv_ksplit
end_undef

begin_define
define|#
directive|define
name|hv_ksplit
value|pPerl->Perl_hv_ksplit
end_define

begin_undef
undef|#
directive|undef
name|hv_magic
end_undef

begin_define
define|#
directive|define
name|hv_magic
value|pPerl->Perl_hv_magic
end_define

begin_undef
undef|#
directive|undef
name|hv_store
end_undef

begin_define
define|#
directive|define
name|hv_store
value|pPerl->Perl_hv_store
end_define

begin_undef
undef|#
directive|undef
name|hv_store_ent
end_undef

begin_define
define|#
directive|define
name|hv_store_ent
value|pPerl->Perl_hv_store_ent
end_define

begin_undef
undef|#
directive|undef
name|hv_undef
end_undef

begin_define
define|#
directive|define
name|hv_undef
value|pPerl->Perl_hv_undef
end_define

begin_undef
undef|#
directive|undef
name|ibcmp
end_undef

begin_define
define|#
directive|define
name|ibcmp
value|pPerl->Perl_ibcmp
end_define

begin_undef
undef|#
directive|undef
name|ibcmp_locale
end_undef

begin_define
define|#
directive|define
name|ibcmp_locale
value|pPerl->Perl_ibcmp_locale
end_define

begin_undef
undef|#
directive|undef
name|incpush
end_undef

begin_define
define|#
directive|define
name|incpush
value|pPerl->incpush
end_define

begin_undef
undef|#
directive|undef
name|incline
end_undef

begin_define
define|#
directive|define
name|incline
value|pPerl->incline
end_define

begin_undef
undef|#
directive|undef
name|incl_perldb
end_undef

begin_define
define|#
directive|define
name|incl_perldb
value|pPerl->incl_perldb
end_define

begin_undef
undef|#
directive|undef
name|ingroup
end_undef

begin_define
define|#
directive|define
name|ingroup
value|pPerl->Perl_ingroup
end_define

begin_undef
undef|#
directive|undef
name|init_stacks
end_undef

begin_define
define|#
directive|define
name|init_stacks
value|pPerl->Perl_init_stacks
end_define

begin_undef
undef|#
directive|undef
name|instr
end_undef

begin_define
define|#
directive|define
name|instr
value|pPerl->Perl_instr
end_define

begin_undef
undef|#
directive|undef
name|intro_my
end_undef

begin_define
define|#
directive|define
name|intro_my
value|pPerl->Perl_intro_my
end_define

begin_undef
undef|#
directive|undef
name|intuit_method
end_undef

begin_define
define|#
directive|define
name|intuit_method
value|pPerl->intuit_method
end_define

begin_undef
undef|#
directive|undef
name|intuit_more
end_undef

begin_define
define|#
directive|define
name|intuit_more
value|pPerl->Perl_intuit_more
end_define

begin_undef
undef|#
directive|undef
name|invert
end_undef

begin_define
define|#
directive|define
name|invert
value|pPerl->Perl_invert
end_define

begin_undef
undef|#
directive|undef
name|io_close
end_undef

begin_define
define|#
directive|define
name|io_close
value|pPerl->Perl_io_close
end_define

begin_undef
undef|#
directive|undef
name|ioctl
end_undef

begin_define
define|#
directive|define
name|ioctl
value|pPerl->ioctl
end_define

begin_undef
undef|#
directive|undef
name|jmaybe
end_undef

begin_define
define|#
directive|define
name|jmaybe
value|pPerl->Perl_jmaybe
end_define

begin_undef
undef|#
directive|undef
name|keyword
end_undef

begin_define
define|#
directive|define
name|keyword
value|pPerl->Perl_keyword
end_define

begin_undef
undef|#
directive|undef
name|leave_scope
end_undef

begin_define
define|#
directive|define
name|leave_scope
value|pPerl->Perl_leave_scope
end_define

begin_undef
undef|#
directive|undef
name|lex_end
end_undef

begin_define
define|#
directive|define
name|lex_end
value|pPerl->Perl_lex_end
end_define

begin_undef
undef|#
directive|undef
name|lex_start
end_undef

begin_define
define|#
directive|define
name|lex_start
value|pPerl->Perl_lex_start
end_define

begin_undef
undef|#
directive|undef
name|linklist
end_undef

begin_define
define|#
directive|define
name|linklist
value|pPerl->Perl_linklist
end_define

begin_undef
undef|#
directive|undef
name|list
end_undef

begin_define
define|#
directive|define
name|list
value|pPerl->Perl_list
end_define

begin_undef
undef|#
directive|undef
name|listkids
end_undef

begin_define
define|#
directive|define
name|listkids
value|pPerl->Perl_listkids
end_define

begin_undef
undef|#
directive|undef
name|lop
end_undef

begin_define
define|#
directive|define
name|lop
value|pPerl->lop
end_define

begin_undef
undef|#
directive|undef
name|localize
end_undef

begin_define
define|#
directive|define
name|localize
value|pPerl->Perl_localize
end_define

begin_undef
undef|#
directive|undef
name|looks_like_number
end_undef

begin_define
define|#
directive|define
name|looks_like_number
value|pPerl->Perl_looks_like_number
end_define

begin_undef
undef|#
directive|undef
name|magic_clear_all_env
end_undef

begin_define
define|#
directive|define
name|magic_clear_all_env
value|pPerl->Perl_magic_clear_all_env
end_define

begin_undef
undef|#
directive|undef
name|magic_clearenv
end_undef

begin_define
define|#
directive|define
name|magic_clearenv
value|pPerl->Perl_magic_clearenv
end_define

begin_undef
undef|#
directive|undef
name|magic_clearpack
end_undef

begin_define
define|#
directive|define
name|magic_clearpack
value|pPerl->Perl_magic_clearpack
end_define

begin_undef
undef|#
directive|undef
name|magic_clearsig
end_undef

begin_define
define|#
directive|define
name|magic_clearsig
value|pPerl->Perl_magic_clearsig
end_define

begin_undef
undef|#
directive|undef
name|magic_existspack
end_undef

begin_define
define|#
directive|define
name|magic_existspack
value|pPerl->Perl_magic_existspack
end_define

begin_undef
undef|#
directive|undef
name|magic_freeregexp
end_undef

begin_define
define|#
directive|define
name|magic_freeregexp
value|pPerl->Perl_magic_freeregexp
end_define

begin_undef
undef|#
directive|undef
name|magic_get
end_undef

begin_define
define|#
directive|define
name|magic_get
value|pPerl->Perl_magic_get
end_define

begin_undef
undef|#
directive|undef
name|magic_getarylen
end_undef

begin_define
define|#
directive|define
name|magic_getarylen
value|pPerl->Perl_magic_getarylen
end_define

begin_undef
undef|#
directive|undef
name|magic_getdefelem
end_undef

begin_define
define|#
directive|define
name|magic_getdefelem
value|pPerl->Perl_magic_getdefelem
end_define

begin_undef
undef|#
directive|undef
name|magic_getpack
end_undef

begin_define
define|#
directive|define
name|magic_getpack
value|pPerl->Perl_magic_getpack
end_define

begin_undef
undef|#
directive|undef
name|magic_getglob
end_undef

begin_define
define|#
directive|define
name|magic_getglob
value|pPerl->Perl_magic_getglob
end_define

begin_undef
undef|#
directive|undef
name|magic_getnkeys
end_undef

begin_define
define|#
directive|define
name|magic_getnkeys
value|pPerl->Perl_magic_getnkeys
end_define

begin_undef
undef|#
directive|undef
name|magic_getpos
end_undef

begin_define
define|#
directive|define
name|magic_getpos
value|pPerl->Perl_magic_getpos
end_define

begin_undef
undef|#
directive|undef
name|magic_getsig
end_undef

begin_define
define|#
directive|define
name|magic_getsig
value|pPerl->Perl_magic_getsig
end_define

begin_undef
undef|#
directive|undef
name|magic_getsubstr
end_undef

begin_define
define|#
directive|define
name|magic_getsubstr
value|pPerl->Perl_magic_getsubstr
end_define

begin_undef
undef|#
directive|undef
name|magic_gettaint
end_undef

begin_define
define|#
directive|define
name|magic_gettaint
value|pPerl->Perl_magic_gettaint
end_define

begin_undef
undef|#
directive|undef
name|magic_getuvar
end_undef

begin_define
define|#
directive|define
name|magic_getuvar
value|pPerl->Perl_magic_getuvar
end_define

begin_undef
undef|#
directive|undef
name|magic_getvec
end_undef

begin_define
define|#
directive|define
name|magic_getvec
value|pPerl->Perl_magic_getvec
end_define

begin_undef
undef|#
directive|undef
name|magic_len
end_undef

begin_define
define|#
directive|define
name|magic_len
value|pPerl->Perl_magic_len
end_define

begin_undef
undef|#
directive|undef
name|magic_methpack
end_undef

begin_define
define|#
directive|define
name|magic_methpack
value|pPerl->magic_methpack
end_define

begin_undef
undef|#
directive|undef
name|magic_mutexfree
end_undef

begin_define
define|#
directive|define
name|magic_mutexfree
value|pPerl->Perl_magic_mutexfree
end_define

begin_undef
undef|#
directive|undef
name|magic_nextpack
end_undef

begin_define
define|#
directive|define
name|magic_nextpack
value|pPerl->Perl_magic_nextpack
end_define

begin_undef
undef|#
directive|undef
name|magic_set
end_undef

begin_define
define|#
directive|define
name|magic_set
value|pPerl->Perl_magic_set
end_define

begin_undef
undef|#
directive|undef
name|magic_set_all_env
end_undef

begin_define
define|#
directive|define
name|magic_set_all_env
value|pPerl->Perl_magic_set_all_env
end_define

begin_undef
undef|#
directive|undef
name|magic_setamagic
end_undef

begin_define
define|#
directive|define
name|magic_setamagic
value|pPerl->Perl_magic_setamagic
end_define

begin_undef
undef|#
directive|undef
name|magic_setarylen
end_undef

begin_define
define|#
directive|define
name|magic_setarylen
value|pPerl->Perl_magic_setarylen
end_define

begin_undef
undef|#
directive|undef
name|magic_setbm
end_undef

begin_define
define|#
directive|define
name|magic_setbm
value|pPerl->Perl_magic_setbm
end_define

begin_undef
undef|#
directive|undef
name|magic_setcollxfrm
end_undef

begin_define
define|#
directive|define
name|magic_setcollxfrm
value|pPerl->Perl_magic_setcollxfrm
end_define

begin_undef
undef|#
directive|undef
name|magic_setdbline
end_undef

begin_define
define|#
directive|define
name|magic_setdbline
value|pPerl->Perl_magic_setdbline
end_define

begin_undef
undef|#
directive|undef
name|magic_setdefelem
end_undef

begin_define
define|#
directive|define
name|magic_setdefelem
value|pPerl->Perl_magic_setdefelem
end_define

begin_undef
undef|#
directive|undef
name|magic_setenv
end_undef

begin_define
define|#
directive|define
name|magic_setenv
value|pPerl->Perl_magic_setenv
end_define

begin_undef
undef|#
directive|undef
name|magic_setfm
end_undef

begin_define
define|#
directive|define
name|magic_setfm
value|pPerl->Perl_magic_setfm
end_define

begin_undef
undef|#
directive|undef
name|magic_setisa
end_undef

begin_define
define|#
directive|define
name|magic_setisa
value|pPerl->Perl_magic_setisa
end_define

begin_undef
undef|#
directive|undef
name|magic_setglob
end_undef

begin_define
define|#
directive|define
name|magic_setglob
value|pPerl->Perl_magic_setglob
end_define

begin_undef
undef|#
directive|undef
name|magic_setmglob
end_undef

begin_define
define|#
directive|define
name|magic_setmglob
value|pPerl->Perl_magic_setmglob
end_define

begin_undef
undef|#
directive|undef
name|magic_setnkeys
end_undef

begin_define
define|#
directive|define
name|magic_setnkeys
value|pPerl->Perl_magic_setnkeys
end_define

begin_undef
undef|#
directive|undef
name|magic_setpack
end_undef

begin_define
define|#
directive|define
name|magic_setpack
value|pPerl->Perl_magic_setpack
end_define

begin_undef
undef|#
directive|undef
name|magic_setpos
end_undef

begin_define
define|#
directive|define
name|magic_setpos
value|pPerl->Perl_magic_setpos
end_define

begin_undef
undef|#
directive|undef
name|magic_setsig
end_undef

begin_define
define|#
directive|define
name|magic_setsig
value|pPerl->Perl_magic_setsig
end_define

begin_undef
undef|#
directive|undef
name|magic_setsubstr
end_undef

begin_define
define|#
directive|define
name|magic_setsubstr
value|pPerl->Perl_magic_setsubstr
end_define

begin_undef
undef|#
directive|undef
name|magic_settaint
end_undef

begin_define
define|#
directive|define
name|magic_settaint
value|pPerl->Perl_magic_settaint
end_define

begin_undef
undef|#
directive|undef
name|magic_setuvar
end_undef

begin_define
define|#
directive|define
name|magic_setuvar
value|pPerl->Perl_magic_setuvar
end_define

begin_undef
undef|#
directive|undef
name|magic_setvec
end_undef

begin_define
define|#
directive|define
name|magic_setvec
value|pPerl->Perl_magic_setvec
end_define

begin_undef
undef|#
directive|undef
name|magic_sizepack
end_undef

begin_define
define|#
directive|define
name|magic_sizepack
value|pPerl->Perl_magic_sizepack
end_define

begin_undef
undef|#
directive|undef
name|magic_unchain
end_undef

begin_define
define|#
directive|define
name|magic_unchain
value|pPerl->Perl_magic_unchain
end_define

begin_undef
undef|#
directive|undef
name|magic_wipepack
end_undef

begin_define
define|#
directive|define
name|magic_wipepack
value|pPerl->Perl_magic_wipepack
end_define

begin_undef
undef|#
directive|undef
name|magicname
end_undef

begin_define
define|#
directive|define
name|magicname
value|pPerl->Perl_magicname
end_define

begin_undef
undef|#
directive|undef
name|malloced_size
end_undef

begin_define
define|#
directive|define
name|malloced_size
value|pPerl->Perl_malloced_size
end_define

begin_undef
undef|#
directive|undef
name|markstack_grow
end_undef

begin_define
define|#
directive|define
name|markstack_grow
value|pPerl->Perl_markstack_grow
end_define

begin_undef
undef|#
directive|undef
name|mem_collxfrm
end_undef

begin_define
define|#
directive|define
name|mem_collxfrm
value|pPerl->Perl_mem_collxfrm
end_define

begin_undef
undef|#
directive|undef
name|mess
end_undef

begin_define
define|#
directive|define
name|mess
value|pPerl->Perl_mess
end_define

begin_undef
undef|#
directive|undef
name|mg_clear
end_undef

begin_define
define|#
directive|define
name|mg_clear
value|pPerl->Perl_mg_clear
end_define

begin_undef
undef|#
directive|undef
name|mg_copy
end_undef

begin_define
define|#
directive|define
name|mg_copy
value|pPerl->Perl_mg_copy
end_define

begin_undef
undef|#
directive|undef
name|mg_find
end_undef

begin_define
define|#
directive|define
name|mg_find
value|pPerl->Perl_mg_find
end_define

begin_undef
undef|#
directive|undef
name|mg_free
end_undef

begin_define
define|#
directive|define
name|mg_free
value|pPerl->Perl_mg_free
end_define

begin_undef
undef|#
directive|undef
name|mg_get
end_undef

begin_define
define|#
directive|define
name|mg_get
value|pPerl->Perl_mg_get
end_define

begin_undef
undef|#
directive|undef
name|mg_magical
end_undef

begin_define
define|#
directive|define
name|mg_magical
value|pPerl->Perl_mg_magical
end_define

begin_undef
undef|#
directive|undef
name|mg_length
end_undef

begin_define
define|#
directive|define
name|mg_length
value|pPerl->Perl_mg_length
end_define

begin_undef
undef|#
directive|undef
name|mg_set
end_undef

begin_define
define|#
directive|define
name|mg_set
value|pPerl->Perl_mg_set
end_define

begin_undef
undef|#
directive|undef
name|mg_size
end_undef

begin_define
define|#
directive|define
name|mg_size
value|pPerl->Perl_mg_size
end_define

begin_undef
undef|#
directive|undef
name|missingterm
end_undef

begin_define
define|#
directive|define
name|missingterm
value|pPerl->missingterm
end_define

begin_undef
undef|#
directive|undef
name|mod
end_undef

begin_define
define|#
directive|define
name|mod
value|pPerl->Perl_mod
end_define

begin_undef
undef|#
directive|undef
name|modkids
end_undef

begin_define
define|#
directive|define
name|modkids
value|pPerl->Perl_modkids
end_define

begin_undef
undef|#
directive|undef
name|moreswitches
end_undef

begin_define
define|#
directive|define
name|moreswitches
value|pPerl->Perl_moreswitches
end_define

begin_undef
undef|#
directive|undef
name|more_sv
end_undef

begin_define
define|#
directive|define
name|more_sv
value|pPerl->more_sv
end_define

begin_undef
undef|#
directive|undef
name|more_xiv
end_undef

begin_define
define|#
directive|define
name|more_xiv
value|pPerl->more_xiv
end_define

begin_undef
undef|#
directive|undef
name|more_xnv
end_undef

begin_define
define|#
directive|define
name|more_xnv
value|pPerl->more_xnv
end_define

begin_undef
undef|#
directive|undef
name|more_xpv
end_undef

begin_define
define|#
directive|define
name|more_xpv
value|pPerl->more_xpv
end_define

begin_undef
undef|#
directive|undef
name|more_xrv
end_undef

begin_define
define|#
directive|define
name|more_xrv
value|pPerl->more_xrv
end_define

begin_undef
undef|#
directive|undef
name|my
end_undef

begin_define
define|#
directive|define
name|my
value|pPerl->Perl_my
end_define

begin_undef
undef|#
directive|undef
name|my_bcopy
end_undef

begin_define
define|#
directive|define
name|my_bcopy
value|pPerl->Perl_my_bcopy
end_define

begin_undef
undef|#
directive|undef
name|my_bzero
end_undef

begin_define
define|#
directive|define
name|my_bzero
value|pPerl->Perl_my_bzero
end_define

begin_undef
undef|#
directive|undef
name|my_chsize
end_undef

begin_define
define|#
directive|define
name|my_chsize
value|pPerl->Perl_my_chsize
end_define

begin_undef
undef|#
directive|undef
name|my_exit
end_undef

begin_define
define|#
directive|define
name|my_exit
value|pPerl->Perl_my_exit
end_define

begin_undef
undef|#
directive|undef
name|my_failure_exit
end_undef

begin_define
define|#
directive|define
name|my_failure_exit
value|pPerl->Perl_my_failure_exit
end_define

begin_undef
undef|#
directive|undef
name|my_htonl
end_undef

begin_define
define|#
directive|define
name|my_htonl
value|pPerl->Perl_my_htonl
end_define

begin_undef
undef|#
directive|undef
name|my_lstat
end_undef

begin_define
define|#
directive|define
name|my_lstat
value|pPerl->Perl_my_lstat
end_define

begin_undef
undef|#
directive|undef
name|my_memcmp
end_undef

begin_define
define|#
directive|define
name|my_memcmp
value|pPerl->my_memcmp
end_define

begin_undef
undef|#
directive|undef
name|my_ntohl
end_undef

begin_define
define|#
directive|define
name|my_ntohl
value|pPerl->Perl_my_ntohl
end_define

begin_undef
undef|#
directive|undef
name|my_pclose
end_undef

begin_define
define|#
directive|define
name|my_pclose
value|pPerl->Perl_my_pclose
end_define

begin_undef
undef|#
directive|undef
name|my_popen
end_undef

begin_define
define|#
directive|define
name|my_popen
value|pPerl->Perl_my_popen
end_define

begin_undef
undef|#
directive|undef
name|my_setenv
end_undef

begin_define
define|#
directive|define
name|my_setenv
value|pPerl->Perl_my_setenv
end_define

begin_undef
undef|#
directive|undef
name|my_stat
end_undef

begin_define
define|#
directive|define
name|my_stat
value|pPerl->Perl_my_stat
end_define

begin_undef
undef|#
directive|undef
name|my_swap
end_undef

begin_define
define|#
directive|define
name|my_swap
value|pPerl->Perl_my_swap
end_define

begin_undef
undef|#
directive|undef
name|my_unexec
end_undef

begin_define
define|#
directive|define
name|my_unexec
value|pPerl->Perl_my_unexec
end_define

begin_undef
undef|#
directive|undef
name|newANONLIST
end_undef

begin_define
define|#
directive|define
name|newANONLIST
value|pPerl->Perl_newANONLIST
end_define

begin_undef
undef|#
directive|undef
name|newANONHASH
end_undef

begin_define
define|#
directive|define
name|newANONHASH
value|pPerl->Perl_newANONHASH
end_define

begin_undef
undef|#
directive|undef
name|newANONSUB
end_undef

begin_define
define|#
directive|define
name|newANONSUB
value|pPerl->Perl_newANONSUB
end_define

begin_undef
undef|#
directive|undef
name|newASSIGNOP
end_undef

begin_define
define|#
directive|define
name|newASSIGNOP
value|pPerl->Perl_newASSIGNOP
end_define

begin_undef
undef|#
directive|undef
name|newCONDOP
end_undef

begin_define
define|#
directive|define
name|newCONDOP
value|pPerl->Perl_newCONDOP
end_define

begin_undef
undef|#
directive|undef
name|newCONSTSUB
end_undef

begin_define
define|#
directive|define
name|newCONSTSUB
value|pPerl->Perl_newCONSTSUB
end_define

begin_undef
undef|#
directive|undef
name|newFORM
end_undef

begin_define
define|#
directive|define
name|newFORM
value|pPerl->Perl_newFORM
end_define

begin_undef
undef|#
directive|undef
name|newFOROP
end_undef

begin_define
define|#
directive|define
name|newFOROP
value|pPerl->Perl_newFOROP
end_define

begin_undef
undef|#
directive|undef
name|newLOGOP
end_undef

begin_define
define|#
directive|define
name|newLOGOP
value|pPerl->Perl_newLOGOP
end_define

begin_undef
undef|#
directive|undef
name|newLOOPEX
end_undef

begin_define
define|#
directive|define
name|newLOOPEX
value|pPerl->Perl_newLOOPEX
end_define

begin_undef
undef|#
directive|undef
name|newLOOPOP
end_undef

begin_define
define|#
directive|define
name|newLOOPOP
value|pPerl->Perl_newLOOPOP
end_define

begin_undef
undef|#
directive|undef
name|newMETHOD
end_undef

begin_define
define|#
directive|define
name|newMETHOD
value|pPerl->Perl_newMETHOD
end_define

begin_undef
undef|#
directive|undef
name|newNULLLIST
end_undef

begin_define
define|#
directive|define
name|newNULLLIST
value|pPerl->Perl_newNULLLIST
end_define

begin_undef
undef|#
directive|undef
name|newOP
end_undef

begin_define
define|#
directive|define
name|newOP
value|pPerl->Perl_newOP
end_define

begin_undef
undef|#
directive|undef
name|newPROG
end_undef

begin_define
define|#
directive|define
name|newPROG
value|pPerl->Perl_newPROG
end_define

begin_undef
undef|#
directive|undef
name|newRANGE
end_undef

begin_define
define|#
directive|define
name|newRANGE
value|pPerl->Perl_newRANGE
end_define

begin_undef
undef|#
directive|undef
name|newSLICEOP
end_undef

begin_define
define|#
directive|define
name|newSLICEOP
value|pPerl->Perl_newSLICEOP
end_define

begin_undef
undef|#
directive|undef
name|newSTATEOP
end_undef

begin_define
define|#
directive|define
name|newSTATEOP
value|pPerl->Perl_newSTATEOP
end_define

begin_undef
undef|#
directive|undef
name|newSUB
end_undef

begin_define
define|#
directive|define
name|newSUB
value|pPerl->Perl_newSUB
end_define

begin_undef
undef|#
directive|undef
name|newXS
end_undef

begin_define
define|#
directive|define
name|newXS
value|pPerl->Perl_newXS
end_define

begin_undef
undef|#
directive|undef
name|newAV
end_undef

begin_define
define|#
directive|define
name|newAV
value|pPerl->Perl_newAV
end_define

begin_undef
undef|#
directive|undef
name|newAVREF
end_undef

begin_define
define|#
directive|define
name|newAVREF
value|pPerl->Perl_newAVREF
end_define

begin_undef
undef|#
directive|undef
name|newBINOP
end_undef

begin_define
define|#
directive|define
name|newBINOP
value|pPerl->Perl_newBINOP
end_define

begin_undef
undef|#
directive|undef
name|newCVREF
end_undef

begin_define
define|#
directive|define
name|newCVREF
value|pPerl->Perl_newCVREF
end_define

begin_undef
undef|#
directive|undef
name|newCVOP
end_undef

begin_define
define|#
directive|define
name|newCVOP
value|pPerl->Perl_newCVOP
end_define

begin_undef
undef|#
directive|undef
name|newGVOP
end_undef

begin_define
define|#
directive|define
name|newGVOP
value|pPerl->Perl_newGVOP
end_define

begin_undef
undef|#
directive|undef
name|newGVgen
end_undef

begin_define
define|#
directive|define
name|newGVgen
value|pPerl->Perl_newGVgen
end_define

begin_undef
undef|#
directive|undef
name|newGVREF
end_undef

begin_define
define|#
directive|define
name|newGVREF
value|pPerl->Perl_newGVREF
end_define

begin_undef
undef|#
directive|undef
name|newHVREF
end_undef

begin_define
define|#
directive|define
name|newHVREF
value|pPerl->Perl_newHVREF
end_define

begin_undef
undef|#
directive|undef
name|newHV
end_undef

begin_define
define|#
directive|define
name|newHV
value|pPerl->Perl_newHV
end_define

begin_undef
undef|#
directive|undef
name|newHVhv
end_undef

begin_define
define|#
directive|define
name|newHVhv
value|pPerl->Perl_newHVhv
end_define

begin_undef
undef|#
directive|undef
name|newIO
end_undef

begin_define
define|#
directive|define
name|newIO
value|pPerl->Perl_newIO
end_define

begin_undef
undef|#
directive|undef
name|newLISTOP
end_undef

begin_define
define|#
directive|define
name|newLISTOP
value|pPerl->Perl_newLISTOP
end_define

begin_undef
undef|#
directive|undef
name|newPMOP
end_undef

begin_define
define|#
directive|define
name|newPMOP
value|pPerl->Perl_newPMOP
end_define

begin_undef
undef|#
directive|undef
name|newPVOP
end_undef

begin_define
define|#
directive|define
name|newPVOP
value|pPerl->Perl_newPVOP
end_define

begin_undef
undef|#
directive|undef
name|newRV
end_undef

begin_define
define|#
directive|define
name|newRV
value|pPerl->Perl_newRV
end_define

begin_undef
undef|#
directive|undef
name|newRV_noinc
end_undef

begin_undef
undef|#
directive|undef
name|Perl_newRV_noinc
end_undef

begin_define
define|#
directive|define
name|newRV_noinc
value|pPerl->Perl_newRV_noinc
end_define

begin_undef
undef|#
directive|undef
name|newSV
end_undef

begin_define
define|#
directive|define
name|newSV
value|pPerl->Perl_newSV
end_define

begin_undef
undef|#
directive|undef
name|newSVREF
end_undef

begin_define
define|#
directive|define
name|newSVREF
value|pPerl->Perl_newSVREF
end_define

begin_undef
undef|#
directive|undef
name|newSVOP
end_undef

begin_define
define|#
directive|define
name|newSVOP
value|pPerl->Perl_newSVOP
end_define

begin_undef
undef|#
directive|undef
name|newSViv
end_undef

begin_define
define|#
directive|define
name|newSViv
value|pPerl->Perl_newSViv
end_define

begin_undef
undef|#
directive|undef
name|newSVnv
end_undef

begin_define
define|#
directive|define
name|newSVnv
value|pPerl->Perl_newSVnv
end_define

begin_undef
undef|#
directive|undef
name|newSVpv
end_undef

begin_define
define|#
directive|define
name|newSVpv
value|pPerl->Perl_newSVpv
end_define

begin_undef
undef|#
directive|undef
name|newSVpvf
end_undef

begin_define
define|#
directive|define
name|newSVpvf
value|pPerl->Perl_newSVpvf
end_define

begin_undef
undef|#
directive|undef
name|newSVpvn
end_undef

begin_define
define|#
directive|define
name|newSVpvn
value|pPerl->Perl_newSVpvn
end_define

begin_undef
undef|#
directive|undef
name|newSVrv
end_undef

begin_define
define|#
directive|define
name|newSVrv
value|pPerl->Perl_newSVrv
end_define

begin_undef
undef|#
directive|undef
name|newSVsv
end_undef

begin_define
define|#
directive|define
name|newSVsv
value|pPerl->Perl_newSVsv
end_define

begin_undef
undef|#
directive|undef
name|newUNOP
end_undef

begin_define
define|#
directive|define
name|newUNOP
value|pPerl->Perl_newUNOP
end_define

begin_undef
undef|#
directive|undef
name|newWHILEOP
end_undef

begin_define
define|#
directive|define
name|newWHILEOP
value|pPerl->Perl_newWHILEOP
end_define

begin_undef
undef|#
directive|undef
name|new_struct_thread
end_undef

begin_define
define|#
directive|define
name|new_struct_thread
value|pPerl->Perl_new_struct_thread
end_define

begin_undef
undef|#
directive|undef
name|new_stackinfo
end_undef

begin_define
define|#
directive|define
name|new_stackinfo
value|pPerl->Perl_new_stackinfo
end_define

begin_undef
undef|#
directive|undef
name|new_sv
end_undef

begin_define
define|#
directive|define
name|new_sv
value|pPerl->new_sv
end_define

begin_undef
undef|#
directive|undef
name|new_xnv
end_undef

begin_define
define|#
directive|define
name|new_xnv
value|pPerl->new_xnv
end_define

begin_undef
undef|#
directive|undef
name|new_xpv
end_undef

begin_define
define|#
directive|define
name|new_xpv
value|pPerl->new_xpv
end_define

begin_undef
undef|#
directive|undef
name|nextargv
end_undef

begin_define
define|#
directive|define
name|nextargv
value|pPerl->Perl_nextargv
end_define

begin_undef
undef|#
directive|undef
name|nextchar
end_undef

begin_define
define|#
directive|define
name|nextchar
value|pPerl->nextchar
end_define

begin_undef
undef|#
directive|undef
name|ninstr
end_undef

begin_define
define|#
directive|define
name|ninstr
value|pPerl->Perl_ninstr
end_define

begin_undef
undef|#
directive|undef
name|no_fh_allowed
end_undef

begin_define
define|#
directive|define
name|no_fh_allowed
value|pPerl->Perl_no_fh_allowed
end_define

begin_undef
undef|#
directive|undef
name|no_op
end_undef

begin_define
define|#
directive|define
name|no_op
value|pPerl->Perl_no_op
end_define

begin_undef
undef|#
directive|undef
name|package
end_undef

begin_define
define|#
directive|define
name|package
value|pPerl->Perl_package
end_define

begin_undef
undef|#
directive|undef
name|pad_alloc
end_undef

begin_define
define|#
directive|define
name|pad_alloc
value|pPerl->Perl_pad_alloc
end_define

begin_undef
undef|#
directive|undef
name|pad_allocmy
end_undef

begin_define
define|#
directive|define
name|pad_allocmy
value|pPerl->Perl_pad_allocmy
end_define

begin_undef
undef|#
directive|undef
name|pad_findmy
end_undef

begin_define
define|#
directive|define
name|pad_findmy
value|pPerl->Perl_pad_findmy
end_define

begin_undef
undef|#
directive|undef
name|op_const_sv
end_undef

begin_define
define|#
directive|define
name|op_const_sv
value|pPerl->Perl_op_const_sv
end_define

begin_undef
undef|#
directive|undef
name|op_free
end_undef

begin_define
define|#
directive|define
name|op_free
value|pPerl->Perl_op_free
end_define

begin_undef
undef|#
directive|undef
name|oopsCV
end_undef

begin_define
define|#
directive|define
name|oopsCV
value|pPerl->Perl_oopsCV
end_define

begin_undef
undef|#
directive|undef
name|oopsAV
end_undef

begin_define
define|#
directive|define
name|oopsAV
value|pPerl->Perl_oopsAV
end_define

begin_undef
undef|#
directive|undef
name|oopsHV
end_undef

begin_define
define|#
directive|define
name|oopsHV
value|pPerl->Perl_oopsHV
end_define

begin_undef
undef|#
directive|undef
name|opendir
end_undef

begin_define
define|#
directive|define
name|opendir
value|pPerl->opendir
end_define

begin_undef
undef|#
directive|undef
name|pad_leavemy
end_undef

begin_define
define|#
directive|define
name|pad_leavemy
value|pPerl->Perl_pad_leavemy
end_define

begin_undef
undef|#
directive|undef
name|pad_sv
end_undef

begin_define
define|#
directive|define
name|pad_sv
value|pPerl->Perl_pad_sv
end_define

begin_undef
undef|#
directive|undef
name|pad_findlex
end_undef

begin_define
define|#
directive|define
name|pad_findlex
value|pPerl->pad_findlex
end_define

begin_undef
undef|#
directive|undef
name|pad_free
end_undef

begin_define
define|#
directive|define
name|pad_free
value|pPerl->Perl_pad_free
end_define

begin_undef
undef|#
directive|undef
name|pad_reset
end_undef

begin_define
define|#
directive|define
name|pad_reset
value|pPerl->Perl_pad_reset
end_define

begin_undef
undef|#
directive|undef
name|pad_swipe
end_undef

begin_define
define|#
directive|define
name|pad_swipe
value|pPerl->Perl_pad_swipe
end_define

begin_undef
undef|#
directive|undef
name|peep
end_undef

begin_define
define|#
directive|define
name|peep
value|pPerl->Perl_peep
end_define

begin_undef
undef|#
directive|undef
name|perl_atexit
end_undef

begin_define
define|#
directive|define
name|perl_atexit
value|pPerl->perl_atexit
end_define

begin_undef
undef|#
directive|undef
name|perl_call_argv
end_undef

begin_define
define|#
directive|define
name|perl_call_argv
value|pPerl->perl_call_argv
end_define

begin_undef
undef|#
directive|undef
name|perl_call_method
end_undef

begin_define
define|#
directive|define
name|perl_call_method
value|pPerl->perl_call_method
end_define

begin_undef
undef|#
directive|undef
name|perl_call_pv
end_undef

begin_define
define|#
directive|define
name|perl_call_pv
value|pPerl->perl_call_pv
end_define

begin_undef
undef|#
directive|undef
name|perl_call_sv
end_undef

begin_define
define|#
directive|define
name|perl_call_sv
value|pPerl->perl_call_sv
end_define

begin_undef
undef|#
directive|undef
name|perl_callargv
end_undef

begin_define
define|#
directive|define
name|perl_callargv
value|pPerl->perl_callargv
end_define

begin_undef
undef|#
directive|undef
name|perl_callpv
end_undef

begin_define
define|#
directive|define
name|perl_callpv
value|pPerl->perl_callpv
end_define

begin_undef
undef|#
directive|undef
name|perl_callsv
end_undef

begin_define
define|#
directive|define
name|perl_callsv
value|pPerl->perl_callsv
end_define

begin_undef
undef|#
directive|undef
name|perl_eval_pv
end_undef

begin_define
define|#
directive|define
name|perl_eval_pv
value|pPerl->perl_eval_pv
end_define

begin_undef
undef|#
directive|undef
name|perl_eval_sv
end_undef

begin_define
define|#
directive|define
name|perl_eval_sv
value|pPerl->perl_eval_sv
end_define

begin_undef
undef|#
directive|undef
name|perl_get_sv
end_undef

begin_define
define|#
directive|define
name|perl_get_sv
value|pPerl->perl_get_sv
end_define

begin_undef
undef|#
directive|undef
name|perl_get_av
end_undef

begin_define
define|#
directive|define
name|perl_get_av
value|pPerl->perl_get_av
end_define

begin_undef
undef|#
directive|undef
name|perl_get_hv
end_undef

begin_define
define|#
directive|define
name|perl_get_hv
value|pPerl->perl_get_hv
end_define

begin_undef
undef|#
directive|undef
name|perl_get_cv
end_undef

begin_define
define|#
directive|define
name|perl_get_cv
value|pPerl->perl_get_cv
end_define

begin_undef
undef|#
directive|undef
name|perl_init_i18nl10n
end_undef

begin_define
define|#
directive|define
name|perl_init_i18nl10n
value|pPerl->perl_init_i18nl10n
end_define

begin_undef
undef|#
directive|undef
name|perl_init_i18nl14n
end_undef

begin_define
define|#
directive|define
name|perl_init_i18nl14n
value|pPerl->perl_init_i18nl14n
end_define

begin_undef
undef|#
directive|undef
name|perl_new_collate
end_undef

begin_define
define|#
directive|define
name|perl_new_collate
value|pPerl->perl_new_collate
end_define

begin_undef
undef|#
directive|undef
name|perl_new_ctype
end_undef

begin_define
define|#
directive|define
name|perl_new_ctype
value|pPerl->perl_new_ctype
end_define

begin_undef
undef|#
directive|undef
name|perl_new_numeric
end_undef

begin_define
define|#
directive|define
name|perl_new_numeric
value|pPerl->perl_new_numeric
end_define

begin_undef
undef|#
directive|undef
name|perl_set_numeric_local
end_undef

begin_define
define|#
directive|define
name|perl_set_numeric_local
value|pPerl->perl_set_numeric_local
end_define

begin_undef
undef|#
directive|undef
name|perl_set_numeric_standard
end_undef

begin_define
define|#
directive|define
name|perl_set_numeric_standard
value|pPerl->perl_set_numeric_standard
end_define

begin_undef
undef|#
directive|undef
name|perl_require_pv
end_undef

begin_define
define|#
directive|define
name|perl_require_pv
value|pPerl->perl_require_pv
end_define

begin_undef
undef|#
directive|undef
name|pidgone
end_undef

begin_define
define|#
directive|define
name|pidgone
value|pPerl->Perl_pidgone
end_define

begin_undef
undef|#
directive|undef
name|pmflag
end_undef

begin_define
define|#
directive|define
name|pmflag
value|pPerl->Perl_pmflag
end_define

begin_undef
undef|#
directive|undef
name|pmruntime
end_undef

begin_define
define|#
directive|define
name|pmruntime
value|pPerl->Perl_pmruntime
end_define

begin_undef
undef|#
directive|undef
name|pmtrans
end_undef

begin_define
define|#
directive|define
name|pmtrans
value|pPerl->Perl_pmtrans
end_define

begin_undef
undef|#
directive|undef
name|pop_return
end_undef

begin_define
define|#
directive|define
name|pop_return
value|pPerl->Perl_pop_return
end_define

begin_undef
undef|#
directive|undef
name|pop_scope
end_undef

begin_define
define|#
directive|define
name|pop_scope
value|pPerl->Perl_pop_scope
end_define

begin_undef
undef|#
directive|undef
name|prepend_elem
end_undef

begin_define
define|#
directive|define
name|prepend_elem
value|pPerl->Perl_prepend_elem
end_define

begin_undef
undef|#
directive|undef
name|push_return
end_undef

begin_define
define|#
directive|define
name|push_return
value|pPerl->Perl_push_return
end_define

begin_undef
undef|#
directive|undef
name|push_scope
end_undef

begin_define
define|#
directive|define
name|push_scope
value|pPerl->Perl_push_scope
end_define

begin_undef
undef|#
directive|undef
name|pregcomp
end_undef

begin_define
define|#
directive|define
name|pregcomp
value|pPerl->Perl_pregcomp
end_define

begin_undef
undef|#
directive|undef
name|ref
end_undef

begin_define
define|#
directive|define
name|ref
value|pPerl->Perl_ref
end_define

begin_undef
undef|#
directive|undef
name|refkids
end_undef

begin_define
define|#
directive|define
name|refkids
value|pPerl->Perl_refkids
end_define

begin_undef
undef|#
directive|undef
name|regexec_flags
end_undef

begin_define
define|#
directive|define
name|regexec_flags
value|pPerl->Perl_regexec_flags
end_define

begin_undef
undef|#
directive|undef
name|pregexec
end_undef

begin_define
define|#
directive|define
name|pregexec
value|pPerl->Perl_pregexec
end_define

begin_undef
undef|#
directive|undef
name|pregfree
end_undef

begin_define
define|#
directive|define
name|pregfree
value|pPerl->Perl_pregfree
end_define

begin_undef
undef|#
directive|undef
name|regdump
end_undef

begin_define
define|#
directive|define
name|regdump
value|pPerl->Perl_regdump
end_define

begin_undef
undef|#
directive|undef
name|regnext
end_undef

begin_define
define|#
directive|define
name|regnext
value|pPerl->Perl_regnext
end_define

begin_undef
undef|#
directive|undef
name|regnoderegnext
end_undef

begin_define
define|#
directive|define
name|regnoderegnext
value|pPerl->regnoderegnext
end_define

begin_undef
undef|#
directive|undef
name|regprop
end_undef

begin_define
define|#
directive|define
name|regprop
value|pPerl->Perl_regprop
end_define

begin_undef
undef|#
directive|undef
name|repeatcpy
end_undef

begin_define
define|#
directive|define
name|repeatcpy
value|pPerl->Perl_repeatcpy
end_define

begin_undef
undef|#
directive|undef
name|rninstr
end_undef

begin_define
define|#
directive|define
name|rninstr
value|pPerl->Perl_rninstr
end_define

begin_undef
undef|#
directive|undef
name|rsignal
end_undef

begin_define
define|#
directive|define
name|rsignal
value|pPerl->Perl_rsignal
end_define

begin_undef
undef|#
directive|undef
name|rsignal_restore
end_undef

begin_define
define|#
directive|define
name|rsignal_restore
value|pPerl->Perl_rsignal_restore
end_define

begin_undef
undef|#
directive|undef
name|rsignal_save
end_undef

begin_define
define|#
directive|define
name|rsignal_save
value|pPerl->Perl_rsignal_save
end_define

begin_undef
undef|#
directive|undef
name|rsignal_state
end_undef

begin_define
define|#
directive|define
name|rsignal_state
value|pPerl->Perl_rsignal_state
end_define

begin_undef
undef|#
directive|undef
name|run
end_undef

begin_define
define|#
directive|define
name|run
value|pPerl->Perl_run
end_define

begin_undef
undef|#
directive|undef
name|rxres_free
end_undef

begin_define
define|#
directive|define
name|rxres_free
value|pPerl->Perl_rxres_free
end_define

begin_undef
undef|#
directive|undef
name|rxres_restore
end_undef

begin_define
define|#
directive|define
name|rxres_restore
value|pPerl->Perl_rxres_restore
end_define

begin_undef
undef|#
directive|undef
name|rxres_save
end_undef

begin_define
define|#
directive|define
name|rxres_save
value|pPerl->Perl_rxres_save
end_define

begin_undef
undef|#
directive|undef
name|safefree
end_undef

begin_define
define|#
directive|define
name|safefree
value|pPerl->Perl_safefree
end_define

begin_undef
undef|#
directive|undef
name|safecalloc
end_undef

begin_define
define|#
directive|define
name|safecalloc
value|pPerl->Perl_safecalloc
end_define

begin_undef
undef|#
directive|undef
name|safemalloc
end_undef

begin_define
define|#
directive|define
name|safemalloc
value|pPerl->Perl_safemalloc
end_define

begin_undef
undef|#
directive|undef
name|saferealloc
end_undef

begin_define
define|#
directive|define
name|saferealloc
value|pPerl->Perl_saferealloc
end_define

begin_undef
undef|#
directive|undef
name|safexcalloc
end_undef

begin_define
define|#
directive|define
name|safexcalloc
value|pPerl->Perl_safexcalloc
end_define

begin_undef
undef|#
directive|undef
name|safexfree
end_undef

begin_define
define|#
directive|define
name|safexfree
value|pPerl->Perl_safexfree
end_define

begin_undef
undef|#
directive|undef
name|safexmalloc
end_undef

begin_define
define|#
directive|define
name|safexmalloc
value|pPerl->Perl_safexmalloc
end_define

begin_undef
undef|#
directive|undef
name|safexrealloc
end_undef

begin_define
define|#
directive|define
name|safexrealloc
value|pPerl->Perl_safexrealloc
end_define

begin_undef
undef|#
directive|undef
name|same_dirent
end_undef

begin_define
define|#
directive|define
name|same_dirent
value|pPerl->Perl_same_dirent
end_define

begin_undef
undef|#
directive|undef
name|savepv
end_undef

begin_define
define|#
directive|define
name|savepv
value|pPerl->Perl_savepv
end_define

begin_undef
undef|#
directive|undef
name|savepvn
end_undef

begin_define
define|#
directive|define
name|savepvn
value|pPerl->Perl_savepvn
end_define

begin_undef
undef|#
directive|undef
name|savestack_grow
end_undef

begin_define
define|#
directive|define
name|savestack_grow
value|pPerl->Perl_savestack_grow
end_define

begin_undef
undef|#
directive|undef
name|save_aelem
end_undef

begin_define
define|#
directive|define
name|save_aelem
value|pPerl->Perl_save_aelem
end_define

begin_undef
undef|#
directive|undef
name|save_aptr
end_undef

begin_define
define|#
directive|define
name|save_aptr
value|pPerl->Perl_save_aptr
end_define

begin_undef
undef|#
directive|undef
name|save_ary
end_undef

begin_define
define|#
directive|define
name|save_ary
value|pPerl->Perl_save_ary
end_define

begin_undef
undef|#
directive|undef
name|save_clearsv
end_undef

begin_define
define|#
directive|define
name|save_clearsv
value|pPerl->Perl_save_clearsv
end_define

begin_undef
undef|#
directive|undef
name|save_delete
end_undef

begin_define
define|#
directive|define
name|save_delete
value|pPerl->Perl_save_delete
end_define

begin_undef
undef|#
directive|undef
name|save_destructor
end_undef

begin_define
define|#
directive|define
name|save_destructor
value|pPerl->Perl_save_destructor
end_define

begin_undef
undef|#
directive|undef
name|save_freesv
end_undef

begin_define
define|#
directive|define
name|save_freesv
value|pPerl->Perl_save_freesv
end_define

begin_undef
undef|#
directive|undef
name|save_freeop
end_undef

begin_define
define|#
directive|define
name|save_freeop
value|pPerl->Perl_save_freeop
end_define

begin_undef
undef|#
directive|undef
name|save_freepv
end_undef

begin_define
define|#
directive|define
name|save_freepv
value|pPerl->Perl_save_freepv
end_define

begin_undef
undef|#
directive|undef
name|save_generic_svref
end_undef

begin_define
define|#
directive|define
name|save_generic_svref
value|pPerl->Perl_generic_save_svref
end_define

begin_undef
undef|#
directive|undef
name|save_gp
end_undef

begin_define
define|#
directive|define
name|save_gp
value|pPerl->Perl_save_gp
end_define

begin_undef
undef|#
directive|undef
name|save_hash
end_undef

begin_define
define|#
directive|define
name|save_hash
value|pPerl->Perl_save_hash
end_define

begin_undef
undef|#
directive|undef
name|save_helem
end_undef

begin_define
define|#
directive|define
name|save_helem
value|pPerl->Perl_save_helem
end_define

begin_undef
undef|#
directive|undef
name|save_hints
end_undef

begin_define
define|#
directive|define
name|save_hints
value|pPerl->Perl_save_hints
end_define

begin_undef
undef|#
directive|undef
name|save_hptr
end_undef

begin_define
define|#
directive|define
name|save_hptr
value|pPerl->Perl_save_hptr
end_define

begin_undef
undef|#
directive|undef
name|save_I16
end_undef

begin_define
define|#
directive|define
name|save_I16
value|pPerl->Perl_save_I16
end_define

begin_undef
undef|#
directive|undef
name|save_I32
end_undef

begin_define
define|#
directive|define
name|save_I32
value|pPerl->Perl_save_I32
end_define

begin_undef
undef|#
directive|undef
name|save_int
end_undef

begin_define
define|#
directive|define
name|save_int
value|pPerl->Perl_save_int
end_define

begin_undef
undef|#
directive|undef
name|save_item
end_undef

begin_define
define|#
directive|define
name|save_item
value|pPerl->Perl_save_item
end_define

begin_undef
undef|#
directive|undef
name|save_iv
end_undef

begin_define
define|#
directive|define
name|save_iv
value|pPerl->Perl_save_iv
end_define

begin_undef
undef|#
directive|undef
name|save_list
end_undef

begin_define
define|#
directive|define
name|save_list
value|pPerl->Perl_save_list
end_define

begin_undef
undef|#
directive|undef
name|save_long
end_undef

begin_define
define|#
directive|define
name|save_long
value|pPerl->Perl_save_long
end_define

begin_undef
undef|#
directive|undef
name|save_nogv
end_undef

begin_define
define|#
directive|define
name|save_nogv
value|pPerl->Perl_save_nogv
end_define

begin_undef
undef|#
directive|undef
name|save_op
end_undef

begin_define
define|#
directive|define
name|save_op
value|pPerl->Perl_save_op
end_define

begin_undef
undef|#
directive|undef
name|save_scalar
end_undef

begin_define
define|#
directive|define
name|save_scalar
value|pPerl->Perl_save_scalar
end_define

begin_undef
undef|#
directive|undef
name|save_pptr
end_undef

begin_define
define|#
directive|define
name|save_pptr
value|pPerl->Perl_save_pptr
end_define

begin_undef
undef|#
directive|undef
name|save_sptr
end_undef

begin_define
define|#
directive|define
name|save_sptr
value|pPerl->Perl_save_sptr
end_define

begin_undef
undef|#
directive|undef
name|save_svref
end_undef

begin_define
define|#
directive|define
name|save_svref
value|pPerl->Perl_save_svref
end_define

begin_undef
undef|#
directive|undef
name|save_threadsv
end_undef

begin_define
define|#
directive|define
name|save_threadsv
value|pPerl->Perl_save_threadsv
end_define

begin_undef
undef|#
directive|undef
name|sawparens
end_undef

begin_define
define|#
directive|define
name|sawparens
value|pPerl->Perl_sawparens
end_define

begin_undef
undef|#
directive|undef
name|scalar
end_undef

begin_define
define|#
directive|define
name|scalar
value|pPerl->Perl_scalar
end_define

begin_undef
undef|#
directive|undef
name|scalarkids
end_undef

begin_define
define|#
directive|define
name|scalarkids
value|pPerl->Perl_scalarkids
end_define

begin_undef
undef|#
directive|undef
name|scalarseq
end_undef

begin_define
define|#
directive|define
name|scalarseq
value|pPerl->Perl_scalarseq
end_define

begin_undef
undef|#
directive|undef
name|scalarvoid
end_undef

begin_define
define|#
directive|define
name|scalarvoid
value|pPerl->Perl_scalarvoid
end_define

begin_undef
undef|#
directive|undef
name|scan_const
end_undef

begin_define
define|#
directive|define
name|scan_const
value|pPerl->Perl_scan_const
end_define

begin_undef
undef|#
directive|undef
name|scan_formline
end_undef

begin_define
define|#
directive|define
name|scan_formline
value|pPerl->Perl_scan_formline
end_define

begin_undef
undef|#
directive|undef
name|scan_ident
end_undef

begin_define
define|#
directive|define
name|scan_ident
value|pPerl->Perl_scan_ident
end_define

begin_undef
undef|#
directive|undef
name|scan_inputsymbol
end_undef

begin_define
define|#
directive|define
name|scan_inputsymbol
value|pPerl->Perl_scan_inputsymbol
end_define

begin_undef
undef|#
directive|undef
name|scan_heredoc
end_undef

begin_define
define|#
directive|define
name|scan_heredoc
value|pPerl->Perl_scan_heredoc
end_define

begin_undef
undef|#
directive|undef
name|scan_hex
end_undef

begin_define
define|#
directive|define
name|scan_hex
value|pPerl->Perl_scan_hex
end_define

begin_undef
undef|#
directive|undef
name|scan_num
end_undef

begin_define
define|#
directive|define
name|scan_num
value|pPerl->Perl_scan_num
end_define

begin_undef
undef|#
directive|undef
name|scan_oct
end_undef

begin_define
define|#
directive|define
name|scan_oct
value|pPerl->Perl_scan_oct
end_define

begin_undef
undef|#
directive|undef
name|scan_pat
end_undef

begin_define
define|#
directive|define
name|scan_pat
value|pPerl->Perl_scan_pat
end_define

begin_undef
undef|#
directive|undef
name|scan_str
end_undef

begin_define
define|#
directive|define
name|scan_str
value|pPerl->Perl_scan_str
end_define

begin_undef
undef|#
directive|undef
name|scan_subst
end_undef

begin_define
define|#
directive|define
name|scan_subst
value|pPerl->Perl_scan_subst
end_define

begin_undef
undef|#
directive|undef
name|scan_trans
end_undef

begin_define
define|#
directive|define
name|scan_trans
value|pPerl->Perl_scan_trans
end_define

begin_undef
undef|#
directive|undef
name|scope
end_undef

begin_define
define|#
directive|define
name|scope
value|pPerl->Perl_scope
end_define

begin_undef
undef|#
directive|undef
name|screaminstr
end_undef

begin_define
define|#
directive|define
name|screaminstr
value|pPerl->Perl_screaminstr
end_define

begin_undef
undef|#
directive|undef
name|setdefout
end_undef

begin_define
define|#
directive|define
name|setdefout
value|pPerl->Perl_setdefout
end_define

begin_undef
undef|#
directive|undef
name|setenv_getix
end_undef

begin_define
define|#
directive|define
name|setenv_getix
value|pPerl->Perl_setenv_getix
end_define

begin_undef
undef|#
directive|undef
name|share_hek
end_undef

begin_define
define|#
directive|define
name|share_hek
value|pPerl->Perl_share_hek
end_define

begin_undef
undef|#
directive|undef
name|sharepvn
end_undef

begin_define
define|#
directive|define
name|sharepvn
value|pPerl->Perl_sharepvn
end_define

begin_undef
undef|#
directive|undef
name|sighandler
end_undef

begin_define
define|#
directive|define
name|sighandler
value|pPerl->Perl_sighandler
end_define

begin_undef
undef|#
directive|undef
name|skipspace
end_undef

begin_define
define|#
directive|define
name|skipspace
value|pPerl->Perl_skipspace
end_define

begin_undef
undef|#
directive|undef
name|stack_grow
end_undef

begin_define
define|#
directive|define
name|stack_grow
value|pPerl->Perl_stack_grow
end_define

begin_undef
undef|#
directive|undef
name|start_subparse
end_undef

begin_define
define|#
directive|define
name|start_subparse
value|pPerl->Perl_start_subparse
end_define

begin_undef
undef|#
directive|undef
name|sub_crush_depth
end_undef

begin_define
define|#
directive|define
name|sub_crush_depth
value|pPerl->Perl_sub_crush_depth
end_define

begin_undef
undef|#
directive|undef
name|sublex_done
end_undef

begin_define
define|#
directive|define
name|sublex_done
value|pPerl->Perl_sublex_done
end_define

begin_undef
undef|#
directive|undef
name|sublex_start
end_undef

begin_define
define|#
directive|define
name|sublex_start
value|pPerl->Perl_sublex_start
end_define

begin_undef
undef|#
directive|undef
name|sv_2bool
end_undef

begin_define
define|#
directive|define
name|sv_2bool
value|pPerl->Perl_sv_2bool
end_define

begin_undef
undef|#
directive|undef
name|sv_2cv
end_undef

begin_define
define|#
directive|define
name|sv_2cv
value|pPerl->Perl_sv_2cv
end_define

begin_undef
undef|#
directive|undef
name|sv_2io
end_undef

begin_define
define|#
directive|define
name|sv_2io
value|pPerl->Perl_sv_2io
end_define

begin_undef
undef|#
directive|undef
name|sv_2iv
end_undef

begin_define
define|#
directive|define
name|sv_2iv
value|pPerl->Perl_sv_2iv
end_define

begin_undef
undef|#
directive|undef
name|sv_2mortal
end_undef

begin_define
define|#
directive|define
name|sv_2mortal
value|pPerl->Perl_sv_2mortal
end_define

begin_undef
undef|#
directive|undef
name|sv_2nv
end_undef

begin_define
define|#
directive|define
name|sv_2nv
value|pPerl->Perl_sv_2nv
end_define

begin_undef
undef|#
directive|undef
name|sv_2pv
end_undef

begin_define
define|#
directive|define
name|sv_2pv
value|pPerl->Perl_sv_2pv
end_define

begin_undef
undef|#
directive|undef
name|sv_2uv
end_undef

begin_define
define|#
directive|define
name|sv_2uv
value|pPerl->Perl_sv_2uv
end_define

begin_undef
undef|#
directive|undef
name|sv_add_arena
end_undef

begin_define
define|#
directive|define
name|sv_add_arena
value|pPerl->Perl_sv_add_arena
end_define

begin_undef
undef|#
directive|undef
name|sv_backoff
end_undef

begin_define
define|#
directive|define
name|sv_backoff
value|pPerl->Perl_sv_backoff
end_define

begin_undef
undef|#
directive|undef
name|sv_bless
end_undef

begin_define
define|#
directive|define
name|sv_bless
value|pPerl->Perl_sv_bless
end_define

begin_undef
undef|#
directive|undef
name|sv_catpv
end_undef

begin_define
define|#
directive|define
name|sv_catpv
value|pPerl->Perl_sv_catpv
end_define

begin_undef
undef|#
directive|undef
name|sv_catpvf
end_undef

begin_define
define|#
directive|define
name|sv_catpvf
value|pPerl->Perl_sv_catpvf
end_define

begin_undef
undef|#
directive|undef
name|sv_catpvn
end_undef

begin_define
define|#
directive|define
name|sv_catpvn
value|pPerl->Perl_sv_catpvn
end_define

begin_undef
undef|#
directive|undef
name|sv_catsv
end_undef

begin_define
define|#
directive|define
name|sv_catsv
value|pPerl->Perl_sv_catsv
end_define

begin_undef
undef|#
directive|undef
name|sv_chop
end_undef

begin_define
define|#
directive|define
name|sv_chop
value|pPerl->Perl_sv_chop
end_define

begin_undef
undef|#
directive|undef
name|sv_clean_all
end_undef

begin_define
define|#
directive|define
name|sv_clean_all
value|pPerl->Perl_sv_clean_all
end_define

begin_undef
undef|#
directive|undef
name|sv_clean_objs
end_undef

begin_define
define|#
directive|define
name|sv_clean_objs
value|pPerl->Perl_sv_clean_objs
end_define

begin_undef
undef|#
directive|undef
name|sv_clear
end_undef

begin_define
define|#
directive|define
name|sv_clear
value|pPerl->Perl_sv_clear
end_define

begin_undef
undef|#
directive|undef
name|sv_cmp
end_undef

begin_define
define|#
directive|define
name|sv_cmp
value|pPerl->Perl_sv_cmp
end_define

begin_undef
undef|#
directive|undef
name|sv_cmp_locale
end_undef

begin_define
define|#
directive|define
name|sv_cmp_locale
value|pPerl->Perl_sv_cmp_locale
end_define

begin_undef
undef|#
directive|undef
name|sv_collxfrm
end_undef

begin_define
define|#
directive|define
name|sv_collxfrm
value|pPerl->Perl_sv_collxfrm
end_define

begin_undef
undef|#
directive|undef
name|sv_compile_2op
end_undef

begin_define
define|#
directive|define
name|sv_compile_2op
value|pPerl->Perl_sv_compile_2op
end_define

begin_undef
undef|#
directive|undef
name|sv_dec
end_undef

begin_define
define|#
directive|define
name|sv_dec
value|pPerl->Perl_sv_dec
end_define

begin_undef
undef|#
directive|undef
name|sv_derived_from
end_undef

begin_define
define|#
directive|define
name|sv_derived_from
value|pPerl->Perl_sv_derived_from
end_define

begin_undef
undef|#
directive|undef
name|sv_dump
end_undef

begin_define
define|#
directive|define
name|sv_dump
value|pPerl->Perl_sv_dump
end_define

begin_undef
undef|#
directive|undef
name|sv_eq
end_undef

begin_define
define|#
directive|define
name|sv_eq
value|pPerl->Perl_sv_eq
end_define

begin_undef
undef|#
directive|undef
name|sv_free
end_undef

begin_define
define|#
directive|define
name|sv_free
value|pPerl->Perl_sv_free
end_define

begin_undef
undef|#
directive|undef
name|sv_free_arenas
end_undef

begin_define
define|#
directive|define
name|sv_free_arenas
value|pPerl->Perl_sv_free_arenas
end_define

begin_undef
undef|#
directive|undef
name|sv_gets
end_undef

begin_define
define|#
directive|define
name|sv_gets
value|pPerl->Perl_sv_gets
end_define

begin_undef
undef|#
directive|undef
name|sv_grow
end_undef

begin_define
define|#
directive|define
name|sv_grow
value|pPerl->Perl_sv_grow
end_define

begin_undef
undef|#
directive|undef
name|sv_inc
end_undef

begin_define
define|#
directive|define
name|sv_inc
value|pPerl->Perl_sv_inc
end_define

begin_undef
undef|#
directive|undef
name|sv_insert
end_undef

begin_define
define|#
directive|define
name|sv_insert
value|pPerl->Perl_sv_insert
end_define

begin_undef
undef|#
directive|undef
name|sv_isa
end_undef

begin_define
define|#
directive|define
name|sv_isa
value|pPerl->Perl_sv_isa
end_define

begin_undef
undef|#
directive|undef
name|sv_isobject
end_undef

begin_define
define|#
directive|define
name|sv_isobject
value|pPerl->Perl_sv_isobject
end_define

begin_undef
undef|#
directive|undef
name|sv_iv
end_undef

begin_define
define|#
directive|define
name|sv_iv
value|pPerl->Perl_sv_iv
end_define

begin_undef
undef|#
directive|undef
name|sv_len
end_undef

begin_define
define|#
directive|define
name|sv_len
value|pPerl->Perl_sv_len
end_define

begin_undef
undef|#
directive|undef
name|sv_magic
end_undef

begin_define
define|#
directive|define
name|sv_magic
value|pPerl->Perl_sv_magic
end_define

begin_undef
undef|#
directive|undef
name|sv_mortalcopy
end_undef

begin_define
define|#
directive|define
name|sv_mortalcopy
value|pPerl->Perl_sv_mortalcopy
end_define

begin_undef
undef|#
directive|undef
name|sv_newmortal
end_undef

begin_define
define|#
directive|define
name|sv_newmortal
value|pPerl->Perl_sv_newmortal
end_define

begin_undef
undef|#
directive|undef
name|sv_newref
end_undef

begin_define
define|#
directive|define
name|sv_newref
value|pPerl->Perl_sv_newref
end_define

begin_undef
undef|#
directive|undef
name|sv_nv
end_undef

begin_define
define|#
directive|define
name|sv_nv
value|pPerl->Perl_sv_nv
end_define

begin_undef
undef|#
directive|undef
name|sv_peek
end_undef

begin_define
define|#
directive|define
name|sv_peek
value|pPerl->Perl_sv_peek
end_define

begin_undef
undef|#
directive|undef
name|sv_pvn
end_undef

begin_define
define|#
directive|define
name|sv_pvn
value|pPerl->Perl_sv_pvn
end_define

begin_undef
undef|#
directive|undef
name|sv_pvn_force
end_undef

begin_define
define|#
directive|define
name|sv_pvn_force
value|pPerl->Perl_sv_pvn_force
end_define

begin_undef
undef|#
directive|undef
name|sv_reftype
end_undef

begin_define
define|#
directive|define
name|sv_reftype
value|pPerl->Perl_sv_reftype
end_define

begin_undef
undef|#
directive|undef
name|sv_replace
end_undef

begin_define
define|#
directive|define
name|sv_replace
value|pPerl->Perl_sv_replace
end_define

begin_undef
undef|#
directive|undef
name|sv_report_used
end_undef

begin_define
define|#
directive|define
name|sv_report_used
value|pPerl->Perl_sv_report_used
end_define

begin_undef
undef|#
directive|undef
name|sv_reset
end_undef

begin_define
define|#
directive|define
name|sv_reset
value|pPerl->Perl_sv_reset
end_define

begin_undef
undef|#
directive|undef
name|sv_setiv
end_undef

begin_define
define|#
directive|define
name|sv_setiv
value|pPerl->Perl_sv_setiv
end_define

begin_undef
undef|#
directive|undef
name|sv_setnv
end_undef

begin_define
define|#
directive|define
name|sv_setnv
value|pPerl->Perl_sv_setnv
end_define

begin_undef
undef|#
directive|undef
name|sv_setpv
end_undef

begin_define
define|#
directive|define
name|sv_setpv
value|pPerl->Perl_sv_setpv
end_define

begin_undef
undef|#
directive|undef
name|sv_setpvf
end_undef

begin_define
define|#
directive|define
name|sv_setpvf
value|pPerl->Perl_sv_setpvf
end_define

begin_undef
undef|#
directive|undef
name|sv_setpviv
end_undef

begin_define
define|#
directive|define
name|sv_setpviv
value|pPerl->Perl_sv_setpviv
end_define

begin_undef
undef|#
directive|undef
name|sv_setpvn
end_undef

begin_define
define|#
directive|define
name|sv_setpvn
value|pPerl->Perl_sv_setpvn
end_define

begin_undef
undef|#
directive|undef
name|sv_setref_iv
end_undef

begin_define
define|#
directive|define
name|sv_setref_iv
value|pPerl->Perl_sv_setref_iv
end_define

begin_undef
undef|#
directive|undef
name|sv_setref_nv
end_undef

begin_define
define|#
directive|define
name|sv_setref_nv
value|pPerl->Perl_sv_setref_nv
end_define

begin_undef
undef|#
directive|undef
name|sv_setref_pv
end_undef

begin_define
define|#
directive|define
name|sv_setref_pv
value|pPerl->Perl_sv_setref_pv
end_define

begin_undef
undef|#
directive|undef
name|sv_setref_pvn
end_undef

begin_define
define|#
directive|define
name|sv_setref_pvn
value|pPerl->Perl_sv_setref_pvn
end_define

begin_undef
undef|#
directive|undef
name|sv_setsv
end_undef

begin_define
define|#
directive|define
name|sv_setsv
value|pPerl->Perl_sv_setsv
end_define

begin_undef
undef|#
directive|undef
name|sv_setuv
end_undef

begin_define
define|#
directive|define
name|sv_setuv
value|pPerl->Perl_sv_setuv
end_define

begin_undef
undef|#
directive|undef
name|sv_taint
end_undef

begin_define
define|#
directive|define
name|sv_taint
value|pPerl->Perl_sv_taint
end_define

begin_undef
undef|#
directive|undef
name|sv_tainted
end_undef

begin_define
define|#
directive|define
name|sv_tainted
value|pPerl->Perl_sv_tainted
end_define

begin_undef
undef|#
directive|undef
name|sv_true
end_undef

begin_define
define|#
directive|define
name|sv_true
value|pPerl->Perl_sv_true
end_define

begin_undef
undef|#
directive|undef
name|sv_unmagic
end_undef

begin_define
define|#
directive|define
name|sv_unmagic
value|pPerl->Perl_sv_unmagic
end_define

begin_undef
undef|#
directive|undef
name|sv_unref
end_undef

begin_define
define|#
directive|define
name|sv_unref
value|pPerl->Perl_sv_unref
end_define

begin_undef
undef|#
directive|undef
name|sv_untaint
end_undef

begin_define
define|#
directive|define
name|sv_untaint
value|pPerl->Perl_sv_untaint
end_define

begin_undef
undef|#
directive|undef
name|sv_upgrade
end_undef

begin_define
define|#
directive|define
name|sv_upgrade
value|pPerl->Perl_sv_upgrade
end_define

begin_undef
undef|#
directive|undef
name|sv_usepvn
end_undef

begin_define
define|#
directive|define
name|sv_usepvn
value|pPerl->Perl_sv_usepvn
end_define

begin_undef
undef|#
directive|undef
name|sv_uv
end_undef

begin_define
define|#
directive|define
name|sv_uv
value|pPerl->Perl_sv_uv
end_define

begin_undef
undef|#
directive|undef
name|sv_vcatpvfn
end_undef

begin_define
define|#
directive|define
name|sv_vcatpvfn
value|pPerl->Perl_sv_vcatpvfn
end_define

begin_undef
undef|#
directive|undef
name|sv_vsetpvfn
end_undef

begin_define
define|#
directive|define
name|sv_vsetpvfn
value|pPerl->Perl_sv_vsetpvfn
end_define

begin_undef
undef|#
directive|undef
name|taint_env
end_undef

begin_define
define|#
directive|define
name|taint_env
value|pPerl->Perl_taint_env
end_define

begin_undef
undef|#
directive|undef
name|taint_not
end_undef

begin_define
define|#
directive|define
name|taint_not
value|pPerl->Perl_taint_not
end_define

begin_undef
undef|#
directive|undef
name|taint_proper
end_undef

begin_define
define|#
directive|define
name|taint_proper
value|pPerl->Perl_taint_proper
end_define

begin_undef
undef|#
directive|undef
name|too_few_arguments
end_undef

begin_define
define|#
directive|define
name|too_few_arguments
value|pPerl->Perl_too_few_arguments
end_define

begin_undef
undef|#
directive|undef
name|too_many_arguments
end_undef

begin_define
define|#
directive|define
name|too_many_arguments
value|pPerl->Perl_too_many_arguments
end_define

begin_undef
undef|#
directive|undef
name|unlnk
end_undef

begin_define
define|#
directive|define
name|unlnk
value|pPerl->Perl_unlnk
end_define

begin_undef
undef|#
directive|undef
name|unlock_condpair
end_undef

begin_define
define|#
directive|define
name|unlock_condpair
value|pPerl->Perl_unlock_condpair
end_define

begin_undef
undef|#
directive|undef
name|unshare_hek
end_undef

begin_define
define|#
directive|define
name|unshare_hek
value|pPerl->Perl_unshare_hek
end_define

begin_undef
undef|#
directive|undef
name|unsharepvn
end_undef

begin_define
define|#
directive|define
name|unsharepvn
value|pPerl->Perl_unsharepvn
end_define

begin_undef
undef|#
directive|undef
name|utilize
end_undef

begin_define
define|#
directive|define
name|utilize
value|pPerl->Perl_utilize
end_define

begin_undef
undef|#
directive|undef
name|vivify_defelem
end_undef

begin_define
define|#
directive|define
name|vivify_defelem
value|pPerl->Perl_vivify_defelem
end_define

begin_undef
undef|#
directive|undef
name|vivify_ref
end_undef

begin_define
define|#
directive|define
name|vivify_ref
value|pPerl->Perl_vivify_ref
end_define

begin_undef
undef|#
directive|undef
name|wait4pid
end_undef

begin_define
define|#
directive|define
name|wait4pid
value|pPerl->Perl_wait4pid
end_define

begin_undef
undef|#
directive|undef
name|warn
end_undef

begin_define
define|#
directive|define
name|warn
value|pPerl->Perl_warn
end_define

begin_undef
undef|#
directive|undef
name|watch
end_undef

begin_define
define|#
directive|define
name|watch
value|pPerl->Perl_watch
end_define

begin_undef
undef|#
directive|undef
name|whichsig
end_undef

begin_define
define|#
directive|define
name|whichsig
value|pPerl->Perl_whichsig
end_define

begin_undef
undef|#
directive|undef
name|yyerror
end_undef

begin_define
define|#
directive|define
name|yyerror
value|pPerl->Perl_yyerror
end_define

begin_undef
undef|#
directive|undef
name|yylex
end_undef

begin_define
define|#
directive|define
name|yylex
value|pPerl->Perl_yylex
end_define

begin_undef
undef|#
directive|undef
name|yyparse
end_undef

begin_define
define|#
directive|define
name|yyparse
value|pPerl->Perl_yyparse
end_define

begin_undef
undef|#
directive|undef
name|yywarn
end_undef

begin_define
define|#
directive|define
name|yywarn
value|pPerl->Perl_yywarn
end_define

begin_undef
undef|#
directive|undef
name|PL_piMem
end_undef

begin_define
define|#
directive|define
name|PL_piMem
value|(pPerl->PL_piMem)
end_define

begin_undef
undef|#
directive|undef
name|PL_piENV
end_undef

begin_define
define|#
directive|define
name|PL_piENV
value|(pPerl->PL_piENV)
end_define

begin_undef
undef|#
directive|undef
name|PL_piStdIO
end_undef

begin_define
define|#
directive|define
name|PL_piStdIO
value|(pPerl->PL_piStdIO)
end_define

begin_undef
undef|#
directive|undef
name|PL_piLIO
end_undef

begin_define
define|#
directive|define
name|PL_piLIO
value|(pPerl->PL_piLIO)
end_define

begin_undef
undef|#
directive|undef
name|PL_piDir
end_undef

begin_define
define|#
directive|define
name|PL_piDir
value|(pPerl->PL_piDir)
end_define

begin_undef
undef|#
directive|undef
name|PL_piSock
end_undef

begin_define
define|#
directive|define
name|PL_piSock
value|(pPerl->PL_piSock)
end_define

begin_undef
undef|#
directive|undef
name|PL_piProc
end_undef

begin_define
define|#
directive|define
name|PL_piProc
value|(pPerl->PL_piProc)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_XSLOCKS
end_ifndef

begin_undef
undef|#
directive|undef
name|closedir
end_undef

begin_undef
undef|#
directive|undef
name|opendir
end_undef

begin_undef
undef|#
directive|undef
name|stdin
end_undef

begin_undef
undef|#
directive|undef
name|stdout
end_undef

begin_undef
undef|#
directive|undef
name|stderr
end_undef

begin_undef
undef|#
directive|undef
name|feof
end_undef

begin_undef
undef|#
directive|undef
name|ferror
end_undef

begin_undef
undef|#
directive|undef
name|fgetpos
end_undef

begin_undef
undef|#
directive|undef
name|ioctl
end_undef

begin_undef
undef|#
directive|undef
name|getlogin
end_undef

begin_undef
undef|#
directive|undef
name|setjmp
end_undef

begin_undef
undef|#
directive|undef
name|getc
end_undef

begin_undef
undef|#
directive|undef
name|ungetc
end_undef

begin_undef
undef|#
directive|undef
name|fileno
end_undef

begin_define
define|#
directive|define
name|mkdir
value|PerlDir_mkdir
end_define

begin_define
define|#
directive|define
name|chdir
value|PerlDir_chdir
end_define

begin_define
define|#
directive|define
name|rmdir
value|PerlDir_rmdir
end_define

begin_define
define|#
directive|define
name|closedir
value|PerlDir_close
end_define

begin_define
define|#
directive|define
name|opendir
value|PerlDir_open
end_define

begin_define
define|#
directive|define
name|readdir
value|PerlDir_read
end_define

begin_define
define|#
directive|define
name|rewinddir
value|PerlDir_rewind
end_define

begin_define
define|#
directive|define
name|seekdir
value|PerlDir_seek
end_define

begin_define
define|#
directive|define
name|telldir
value|PerlDir_tell
end_define

begin_define
define|#
directive|define
name|putenv
value|PerlEnv_putenv
end_define

begin_define
define|#
directive|define
name|getenv
value|PerlEnv_getenv
end_define

begin_define
define|#
directive|define
name|stdin
value|PerlIO_stdin()
end_define

begin_define
define|#
directive|define
name|stdout
value|PerlIO_stdout()
end_define

begin_define
define|#
directive|define
name|stderr
value|PerlIO_stderr()
end_define

begin_define
define|#
directive|define
name|fopen
value|PerlIO_open
end_define

begin_define
define|#
directive|define
name|fclose
value|PerlIO_close
end_define

begin_define
define|#
directive|define
name|feof
value|PerlIO_eof
end_define

begin_define
define|#
directive|define
name|ferror
value|PerlIO_error
end_define

begin_define
define|#
directive|define
name|fclearerr
value|PerlIO_clearerr
end_define

begin_define
define|#
directive|define
name|getc
value|PerlIO_getc
end_define

begin_define
define|#
directive|define
name|fputc
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_putc(f,c)
end_define

begin_define
define|#
directive|define
name|fputs
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|PerlIO_puts(f,s)
end_define

begin_define
define|#
directive|define
name|fflush
value|PerlIO_flush
end_define

begin_define
define|#
directive|define
name|ungetc
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_ungetc((f),(c))
end_define

begin_define
define|#
directive|define
name|fileno
value|PerlIO_fileno
end_define

begin_define
define|#
directive|define
name|fdopen
value|PerlIO_fdopen
end_define

begin_define
define|#
directive|define
name|freopen
value|PerlIO_reopen
end_define

begin_define
define|#
directive|define
name|fread
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_read((f),(b),(s*c))
end_define

begin_define
define|#
directive|define
name|fwrite
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_write((f),(b),(s*c))
end_define

begin_define
define|#
directive|define
name|setbuf
value|PerlIO_setbuf
end_define

begin_define
define|#
directive|define
name|setvbuf
value|PerlIO_setvbuf
end_define

begin_define
define|#
directive|define
name|setlinebuf
value|PerlIO_setlinebuf
end_define

begin_define
define|#
directive|define
name|stdoutf
value|PerlIO_stdoutf
end_define

begin_define
define|#
directive|define
name|vfprintf
value|PerlIO_vprintf
end_define

begin_define
define|#
directive|define
name|ftell
value|PerlIO_tell
end_define

begin_define
define|#
directive|define
name|fseek
value|PerlIO_seek
end_define

begin_define
define|#
directive|define
name|fgetpos
value|PerlIO_getpos
end_define

begin_define
define|#
directive|define
name|fsetpos
value|PerlIO_setpos
end_define

begin_define
define|#
directive|define
name|frewind
value|PerlIO_rewind
end_define

begin_define
define|#
directive|define
name|tmpfile
value|PerlIO_tmpfile
end_define

begin_define
define|#
directive|define
name|access
value|PerlLIO_access
end_define

begin_define
define|#
directive|define
name|chmod
value|PerlLIO_chmod
end_define

begin_define
define|#
directive|define
name|chsize
value|PerlLIO_chsize
end_define

begin_define
define|#
directive|define
name|close
value|PerlLIO_close
end_define

begin_define
define|#
directive|define
name|dup
value|PerlLIO_dup
end_define

begin_define
define|#
directive|define
name|dup2
value|PerlLIO_dup2
end_define

begin_define
define|#
directive|define
name|flock
value|PerlLIO_flock
end_define

begin_define
define|#
directive|define
name|fstat
value|PerlLIO_fstat
end_define

begin_define
define|#
directive|define
name|ioctl
value|PerlLIO_ioctl
end_define

begin_define
define|#
directive|define
name|isatty
value|PerlLIO_isatty
end_define

begin_define
define|#
directive|define
name|lseek
value|PerlLIO_lseek
end_define

begin_define
define|#
directive|define
name|lstat
value|PerlLIO_lstat
end_define

begin_define
define|#
directive|define
name|mktemp
value|PerlLIO_mktemp
end_define

begin_define
define|#
directive|define
name|open
value|PerlLIO_open
end_define

begin_define
define|#
directive|define
name|read
value|PerlLIO_read
end_define

begin_define
define|#
directive|define
name|rename
value|PerlLIO_rename
end_define

begin_define
define|#
directive|define
name|setmode
value|PerlLIO_setmode
end_define

begin_define
define|#
directive|define
name|stat
value|PerlLIO_stat
end_define

begin_define
define|#
directive|define
name|tmpnam
value|PerlLIO_tmpnam
end_define

begin_define
define|#
directive|define
name|umask
value|PerlLIO_umask
end_define

begin_define
define|#
directive|define
name|unlink
value|PerlLIO_unlink
end_define

begin_define
define|#
directive|define
name|utime
value|PerlLIO_utime
end_define

begin_define
define|#
directive|define
name|write
value|PerlLIO_write
end_define

begin_define
define|#
directive|define
name|malloc
value|PerlMem_malloc
end_define

begin_define
define|#
directive|define
name|realloc
value|PerlMem_realloc
end_define

begin_define
define|#
directive|define
name|free
value|PerlMem_free
end_define

begin_define
define|#
directive|define
name|abort
value|PerlProc_abort
end_define

begin_define
define|#
directive|define
name|exit
value|PerlProc_exit
end_define

begin_define
define|#
directive|define
name|_exit
value|PerlProc__exit
end_define

begin_define
define|#
directive|define
name|execl
value|PerlProc_execl
end_define

begin_define
define|#
directive|define
name|execv
value|PerlProc_execv
end_define

begin_define
define|#
directive|define
name|execvp
value|PerlProc_execvp
end_define

begin_define
define|#
directive|define
name|getuid
value|PerlProc_getuid
end_define

begin_define
define|#
directive|define
name|geteuid
value|PerlProc_geteuid
end_define

begin_define
define|#
directive|define
name|getgid
value|PerlProc_getgid
end_define

begin_define
define|#
directive|define
name|getegid
value|PerlProc_getegid
end_define

begin_define
define|#
directive|define
name|getlogin
value|PerlProc_getlogin
end_define

begin_define
define|#
directive|define
name|kill
value|PerlProc_kill
end_define

begin_define
define|#
directive|define
name|killpg
value|PerlProc_killpg
end_define

begin_define
define|#
directive|define
name|pause
value|PerlProc_pause
end_define

begin_define
define|#
directive|define
name|popen
value|PerlProc_popen
end_define

begin_define
define|#
directive|define
name|pclose
value|PerlProc_pclose
end_define

begin_define
define|#
directive|define
name|pipe
value|PerlProc_pipe
end_define

begin_define
define|#
directive|define
name|setuid
value|PerlProc_setuid
end_define

begin_define
define|#
directive|define
name|setgid
value|PerlProc_setgid
end_define

begin_define
define|#
directive|define
name|sleep
value|PerlProc_sleep
end_define

begin_define
define|#
directive|define
name|times
value|PerlProc_times
end_define

begin_define
define|#
directive|define
name|wait
value|PerlProc_wait
end_define

begin_define
define|#
directive|define
name|setjmp
value|PerlProc_setjmp
end_define

begin_define
define|#
directive|define
name|longjmp
value|PerlProc_longjmp
end_define

begin_define
define|#
directive|define
name|signal
value|PerlProc_signal
end_define

begin_define
define|#
directive|define
name|htonl
value|PerlSock_htonl
end_define

begin_define
define|#
directive|define
name|htons
value|PerlSock_htons
end_define

begin_define
define|#
directive|define
name|ntohl
value|PerlSock_ntohl
end_define

begin_define
define|#
directive|define
name|ntohs
value|PerlSock_ntohs
end_define

begin_define
define|#
directive|define
name|accept
value|PerlSock_accept
end_define

begin_define
define|#
directive|define
name|bind
value|PerlSock_bind
end_define

begin_define
define|#
directive|define
name|connect
value|PerlSock_connect
end_define

begin_define
define|#
directive|define
name|endhostent
value|PerlSock_endhostent
end_define

begin_define
define|#
directive|define
name|endnetent
value|PerlSock_endnetent
end_define

begin_define
define|#
directive|define
name|endprotoent
value|PerlSock_endprotoent
end_define

begin_define
define|#
directive|define
name|endservent
value|PerlSock_endservent
end_define

begin_define
define|#
directive|define
name|gethostbyaddr
value|PerlSock_gethostbyaddr
end_define

begin_define
define|#
directive|define
name|gethostbyname
value|PerlSock_gethostbyname
end_define

begin_define
define|#
directive|define
name|gethostent
value|PerlSock_gethostent
end_define

begin_define
define|#
directive|define
name|gethostname
value|PerlSock_gethostname
end_define

begin_define
define|#
directive|define
name|getnetbyaddr
value|PerlSock_getnetbyaddr
end_define

begin_define
define|#
directive|define
name|getnetbyname
value|PerlSock_getnetbyname
end_define

begin_define
define|#
directive|define
name|getnetent
value|PerlSock_getnetent
end_define

begin_define
define|#
directive|define
name|getpeername
value|PerlSock_getpeername
end_define

begin_define
define|#
directive|define
name|getprotobyname
value|PerlSock_getprotobyname
end_define

begin_define
define|#
directive|define
name|getprotobynumber
value|PerlSock_getprotobynumber
end_define

begin_define
define|#
directive|define
name|getprotoent
value|PerlSock_getprotoent
end_define

begin_define
define|#
directive|define
name|getservbyname
value|PerlSock_getservbyname
end_define

begin_define
define|#
directive|define
name|getservbyport
value|PerlSock_getservbyport
end_define

begin_define
define|#
directive|define
name|getservent
value|PerlSock_getservent
end_define

begin_define
define|#
directive|define
name|getsockname
value|PerlSock_getsockname
end_define

begin_define
define|#
directive|define
name|getsockopt
value|PerlSock_getsockopt
end_define

begin_define
define|#
directive|define
name|inet_addr
value|PerlSock_inet_addr
end_define

begin_define
define|#
directive|define
name|inet_ntoa
value|PerlSock_inet_ntoa
end_define

begin_define
define|#
directive|define
name|listen
value|PerlSock_listen
end_define

begin_define
define|#
directive|define
name|recvfrom
value|PerlSock_recvfrom
end_define

begin_define
define|#
directive|define
name|select
value|PerlSock_select
end_define

begin_define
define|#
directive|define
name|send
value|PerlSock_send
end_define

begin_define
define|#
directive|define
name|sendto
value|PerlSock_sendto
end_define

begin_define
define|#
directive|define
name|sethostent
value|PerlSock_sethostent
end_define

begin_define
define|#
directive|define
name|setnetent
value|PerlSock_setnetent
end_define

begin_define
define|#
directive|define
name|setprotoent
value|PerlSock_setprotoent
end_define

begin_define
define|#
directive|define
name|setservent
value|PerlSock_setservent
end_define

begin_define
define|#
directive|define
name|setsockopt
value|PerlSock_setsockopt
end_define

begin_define
define|#
directive|define
name|shutdown
value|PerlSock_shutdown
end_define

begin_define
define|#
directive|define
name|socket
value|PerlSock_socket
end_define

begin_define
define|#
directive|define
name|socketpair
value|PerlSock_socketpair
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_XSLOCKS */
end_comment

begin_undef
undef|#
directive|undef
name|PERL_OBJECT_THIS
end_undef

begin_define
define|#
directive|define
name|PERL_OBJECT_THIS
value|pPerl
end_define

begin_undef
undef|#
directive|undef
name|PERL_OBJECT_THIS_
end_undef

begin_define
define|#
directive|define
name|PERL_OBJECT_THIS_
value|pPerl,
end_define

begin_undef
undef|#
directive|undef
name|SAVEDESTRUCTOR
end_undef

begin_define
define|#
directive|define
name|SAVEDESTRUCTOR
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|)
define|\
value|pPerl->Perl_save_destructor((FUNC_NAME_TO_PTR(f)),(p))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32IO_IS_STDIO
end_ifndef

begin_undef
undef|#
directive|undef
name|errno
end_undef

begin_define
define|#
directive|define
name|errno
value|ErrorNo()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ErrorNo
end_undef

begin_define
define|#
directive|define
name|ErrorNo
value|pPerl->ErrorNo
end_define

begin_undef
undef|#
directive|undef
name|NtCrypt
end_undef

begin_define
define|#
directive|define
name|NtCrypt
value|pPerl->NtCrypt
end_define

begin_undef
undef|#
directive|undef
name|NtGetLib
end_undef

begin_define
define|#
directive|define
name|NtGetLib
value|pPerl->NtGetLib
end_define

begin_undef
undef|#
directive|undef
name|NtGetArchLib
end_undef

begin_define
define|#
directive|define
name|NtGetArchLib
value|pPerl->NtGetArchLib
end_define

begin_undef
undef|#
directive|undef
name|NtGetSiteLib
end_undef

begin_define
define|#
directive|define
name|NtGetSiteLib
value|pPerl->NtGetSiteLib
end_define

begin_undef
undef|#
directive|undef
name|NtGetBin
end_undef

begin_define
define|#
directive|define
name|NtGetBin
value|pPerl->NtGetBin
end_define

begin_undef
undef|#
directive|undef
name|NtGetDebugScriptStr
end_undef

begin_define
define|#
directive|define
name|NtGetDebugScriptStr
value|pPerl->NtGetDebugScriptStr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __objXSUB_h__ */
end_comment

end_unit

