begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|PPDEF
argument_list|(
argument|pp_null
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_stub
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_scalar
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_pushmark
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_wantarray
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_const
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gvsv
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gv
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gelem
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_padsv
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_padav
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_padhv
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_padany
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_pushre
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_rv2gv
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_rv2sv
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_av2arylen
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_rv2cv
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_anoncode
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_prototype
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_refgen
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_srefgen
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ref
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_bless
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_backtick
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_glob
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_readline
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_rcatline
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_regcmaybe
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_regcreset
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_regcomp
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_match
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_qr
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_subst
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_substcont
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_trans
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sassign
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_aassign
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_chop
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_schop
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_chomp
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_schomp
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_defined
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_undef
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_study
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_pos
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_preinc
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_predec
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_postinc
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_postdec
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_pow
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_multiply
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_i_multiply
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_divide
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_i_divide
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_modulo
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_i_modulo
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_repeat
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_add
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_i_add
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_subtract
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_i_subtract
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_concat
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_stringify
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_left_shift
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_right_shift
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_lt
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_i_lt
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gt
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_i_gt
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_le
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_i_le
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ge
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_i_ge
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_eq
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_i_eq
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ne
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_i_ne
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ncmp
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_i_ncmp
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_slt
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sgt
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sle
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sge
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_seq
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sne
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_scmp
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_bit_and
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_bit_xor
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_bit_or
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_negate
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_i_negate
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_not
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_complement
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_atan2
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sin
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_cos
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_rand
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_srand
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_exp
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_log
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sqrt
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_int
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_hex
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_oct
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_abs
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_length
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_substr
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_vec
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_index
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_rindex
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sprintf
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_formline
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ord
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_chr
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_crypt
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ucfirst
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_lcfirst
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_uc
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_lc
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_quotemeta
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_rv2av
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_aelemfast
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_aelem
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_aslice
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_each
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_values
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_keys
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_delete
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_exists
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_rv2hv
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_helem
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_hslice
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_unpack
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_pack
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_split
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_join
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_list
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_lslice
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_anonlist
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_anonhash
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_splice
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_push
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_pop
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_shift
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_unshift
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sort
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_reverse
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_grepstart
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_grepwhile
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_mapstart
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_mapwhile
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_range
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_flip
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_flop
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_and
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_or
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_xor
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_cond_expr
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_andassign
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_orassign
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_method
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_entersub
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_leavesub
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_caller
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_warn
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_die
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_reset
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_lineseq
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_nextstate
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_dbstate
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_unstack
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_enter
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_leave
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_scope
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_enteriter
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_iter
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_enterloop
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_leaveloop
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_return
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_last
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_next
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_redo
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_dump
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_goto
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_exit
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_open
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_close
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_pipe_op
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_fileno
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_umask
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_binmode
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_tie
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_untie
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_tied
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_dbmopen
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_dbmclose
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sselect
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_select
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_getc
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_read
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_enterwrite
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_leavewrite
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_prtf
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_print
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sysopen
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sysseek
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sysread
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_syswrite
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_send
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_recv
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_eof
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_tell
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_seek
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_truncate
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_fcntl
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ioctl
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_flock
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_socket
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sockpair
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_bind
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_connect
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_listen
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_accept
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_shutdown
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gsockopt
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ssockopt
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_getsockname
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_getpeername
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_lstat
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_stat
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftrread
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftrwrite
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftrexec
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_fteread
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftewrite
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_fteexec
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftis
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_fteowned
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftrowned
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftzero
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftsize
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftmtime
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftatime
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftctime
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftsock
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftchr
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftblk
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftfile
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftdir
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftpipe
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftlink
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftsuid
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftsgid
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftsvtx
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_fttty
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_fttext
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ftbinary
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_chdir
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_chown
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_chroot
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_unlink
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_chmod
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_utime
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_rename
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_link
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_symlink
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_readlink
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_mkdir
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_rmdir
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_open_dir
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_readdir
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_telldir
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_seekdir
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_rewinddir
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_closedir
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_fork
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_wait
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_waitpid
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_system
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_exec
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_kill
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_getppid
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_getpgrp
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_setpgrp
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_getpriority
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_setpriority
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_time
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_tms
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_localtime
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gmtime
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_alarm
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sleep
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_shmget
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_shmctl
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_shmread
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_shmwrite
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_msgget
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_msgctl
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_msgsnd
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_msgrcv
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_semget
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_semctl
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_semop
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_require
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_dofile
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_entereval
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_leaveeval
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_entertry
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_leavetry
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ghbyname
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ghbyaddr
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ghostent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gnbyname
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gnbyaddr
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gnetent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gpbyname
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gpbynumber
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gprotoent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gsbyname
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gsbyport
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gservent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_shostent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_snetent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sprotoent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sservent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ehostent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_enetent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_eprotoent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_eservent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gpwnam
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gpwuid
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_gpwent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_spwent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_epwent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ggrnam
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ggrgid
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_ggrent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_sgrent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_egrent
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_getlogin
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_syscall
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_lock
argument_list|)
end_macro

begin_macro
name|PPDEF
argument_list|(
argument|pp_threadsv
argument_list|)
end_macro

end_unit

