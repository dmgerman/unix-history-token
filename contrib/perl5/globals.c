begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"INTERN.h"
end_include

begin_include
include|#
directive|include
file|"perl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_undef
undef|#
directive|undef
name|pp_null
end_undef

begin_define
define|#
directive|define
name|pp_null
value|CPerlObj::Perl_pp_null
end_define

begin_undef
undef|#
directive|undef
name|pp_stub
end_undef

begin_define
define|#
directive|define
name|pp_stub
value|CPerlObj::Perl_pp_stub
end_define

begin_undef
undef|#
directive|undef
name|pp_scalar
end_undef

begin_define
define|#
directive|define
name|pp_scalar
value|CPerlObj::Perl_pp_scalar
end_define

begin_undef
undef|#
directive|undef
name|pp_pushmark
end_undef

begin_define
define|#
directive|define
name|pp_pushmark
value|CPerlObj::Perl_pp_pushmark
end_define

begin_undef
undef|#
directive|undef
name|pp_wantarray
end_undef

begin_define
define|#
directive|define
name|pp_wantarray
value|CPerlObj::Perl_pp_wantarray
end_define

begin_undef
undef|#
directive|undef
name|pp_const
end_undef

begin_define
define|#
directive|define
name|pp_const
value|CPerlObj::Perl_pp_const
end_define

begin_undef
undef|#
directive|undef
name|pp_gvsv
end_undef

begin_define
define|#
directive|define
name|pp_gvsv
value|CPerlObj::Perl_pp_gvsv
end_define

begin_undef
undef|#
directive|undef
name|pp_gv
end_undef

begin_define
define|#
directive|define
name|pp_gv
value|CPerlObj::Perl_pp_gv
end_define

begin_undef
undef|#
directive|undef
name|pp_gelem
end_undef

begin_define
define|#
directive|define
name|pp_gelem
value|CPerlObj::Perl_pp_gelem
end_define

begin_undef
undef|#
directive|undef
name|pp_padsv
end_undef

begin_define
define|#
directive|define
name|pp_padsv
value|CPerlObj::Perl_pp_padsv
end_define

begin_undef
undef|#
directive|undef
name|pp_padav
end_undef

begin_define
define|#
directive|define
name|pp_padav
value|CPerlObj::Perl_pp_padav
end_define

begin_undef
undef|#
directive|undef
name|pp_padhv
end_undef

begin_define
define|#
directive|define
name|pp_padhv
value|CPerlObj::Perl_pp_padhv
end_define

begin_undef
undef|#
directive|undef
name|pp_padany
end_undef

begin_define
define|#
directive|define
name|pp_padany
value|CPerlObj::Perl_pp_padany
end_define

begin_undef
undef|#
directive|undef
name|pp_pushre
end_undef

begin_define
define|#
directive|define
name|pp_pushre
value|CPerlObj::Perl_pp_pushre
end_define

begin_undef
undef|#
directive|undef
name|pp_rv2gv
end_undef

begin_define
define|#
directive|define
name|pp_rv2gv
value|CPerlObj::Perl_pp_rv2gv
end_define

begin_undef
undef|#
directive|undef
name|pp_rv2sv
end_undef

begin_define
define|#
directive|define
name|pp_rv2sv
value|CPerlObj::Perl_pp_rv2sv
end_define

begin_undef
undef|#
directive|undef
name|pp_av2arylen
end_undef

begin_define
define|#
directive|define
name|pp_av2arylen
value|CPerlObj::Perl_pp_av2arylen
end_define

begin_undef
undef|#
directive|undef
name|pp_rv2cv
end_undef

begin_define
define|#
directive|define
name|pp_rv2cv
value|CPerlObj::Perl_pp_rv2cv
end_define

begin_undef
undef|#
directive|undef
name|pp_anoncode
end_undef

begin_define
define|#
directive|define
name|pp_anoncode
value|CPerlObj::Perl_pp_anoncode
end_define

begin_undef
undef|#
directive|undef
name|pp_prototype
end_undef

begin_define
define|#
directive|define
name|pp_prototype
value|CPerlObj::Perl_pp_prototype
end_define

begin_undef
undef|#
directive|undef
name|pp_refgen
end_undef

begin_define
define|#
directive|define
name|pp_refgen
value|CPerlObj::Perl_pp_refgen
end_define

begin_undef
undef|#
directive|undef
name|pp_srefgen
end_undef

begin_define
define|#
directive|define
name|pp_srefgen
value|CPerlObj::Perl_pp_srefgen
end_define

begin_undef
undef|#
directive|undef
name|pp_ref
end_undef

begin_define
define|#
directive|define
name|pp_ref
value|CPerlObj::Perl_pp_ref
end_define

begin_undef
undef|#
directive|undef
name|pp_bless
end_undef

begin_define
define|#
directive|define
name|pp_bless
value|CPerlObj::Perl_pp_bless
end_define

begin_undef
undef|#
directive|undef
name|pp_backtick
end_undef

begin_define
define|#
directive|define
name|pp_backtick
value|CPerlObj::Perl_pp_backtick
end_define

begin_undef
undef|#
directive|undef
name|pp_glob
end_undef

begin_define
define|#
directive|define
name|pp_glob
value|CPerlObj::Perl_pp_glob
end_define

begin_undef
undef|#
directive|undef
name|pp_readline
end_undef

begin_define
define|#
directive|define
name|pp_readline
value|CPerlObj::Perl_pp_readline
end_define

begin_undef
undef|#
directive|undef
name|pp_rcatline
end_undef

begin_define
define|#
directive|define
name|pp_rcatline
value|CPerlObj::Perl_pp_rcatline
end_define

begin_undef
undef|#
directive|undef
name|pp_regcmaybe
end_undef

begin_define
define|#
directive|define
name|pp_regcmaybe
value|CPerlObj::Perl_pp_regcmaybe
end_define

begin_undef
undef|#
directive|undef
name|pp_regcreset
end_undef

begin_define
define|#
directive|define
name|pp_regcreset
value|CPerlObj::Perl_pp_regcreset
end_define

begin_undef
undef|#
directive|undef
name|pp_regcomp
end_undef

begin_define
define|#
directive|define
name|pp_regcomp
value|CPerlObj::Perl_pp_regcomp
end_define

begin_undef
undef|#
directive|undef
name|pp_match
end_undef

begin_define
define|#
directive|define
name|pp_match
value|CPerlObj::Perl_pp_match
end_define

begin_undef
undef|#
directive|undef
name|pp_qr
end_undef

begin_define
define|#
directive|define
name|pp_qr
value|CPerlObj::Perl_pp_qr
end_define

begin_undef
undef|#
directive|undef
name|pp_subst
end_undef

begin_define
define|#
directive|define
name|pp_subst
value|CPerlObj::Perl_pp_subst
end_define

begin_undef
undef|#
directive|undef
name|pp_substcont
end_undef

begin_define
define|#
directive|define
name|pp_substcont
value|CPerlObj::Perl_pp_substcont
end_define

begin_undef
undef|#
directive|undef
name|pp_trans
end_undef

begin_define
define|#
directive|define
name|pp_trans
value|CPerlObj::Perl_pp_trans
end_define

begin_undef
undef|#
directive|undef
name|pp_sassign
end_undef

begin_define
define|#
directive|define
name|pp_sassign
value|CPerlObj::Perl_pp_sassign
end_define

begin_undef
undef|#
directive|undef
name|pp_aassign
end_undef

begin_define
define|#
directive|define
name|pp_aassign
value|CPerlObj::Perl_pp_aassign
end_define

begin_undef
undef|#
directive|undef
name|pp_chop
end_undef

begin_define
define|#
directive|define
name|pp_chop
value|CPerlObj::Perl_pp_chop
end_define

begin_undef
undef|#
directive|undef
name|pp_schop
end_undef

begin_define
define|#
directive|define
name|pp_schop
value|CPerlObj::Perl_pp_schop
end_define

begin_undef
undef|#
directive|undef
name|pp_chomp
end_undef

begin_define
define|#
directive|define
name|pp_chomp
value|CPerlObj::Perl_pp_chomp
end_define

begin_undef
undef|#
directive|undef
name|pp_schomp
end_undef

begin_define
define|#
directive|define
name|pp_schomp
value|CPerlObj::Perl_pp_schomp
end_define

begin_undef
undef|#
directive|undef
name|pp_defined
end_undef

begin_define
define|#
directive|define
name|pp_defined
value|CPerlObj::Perl_pp_defined
end_define

begin_undef
undef|#
directive|undef
name|pp_undef
end_undef

begin_define
define|#
directive|define
name|pp_undef
value|CPerlObj::Perl_pp_undef
end_define

begin_undef
undef|#
directive|undef
name|pp_study
end_undef

begin_define
define|#
directive|define
name|pp_study
value|CPerlObj::Perl_pp_study
end_define

begin_undef
undef|#
directive|undef
name|pp_pos
end_undef

begin_define
define|#
directive|define
name|pp_pos
value|CPerlObj::Perl_pp_pos
end_define

begin_undef
undef|#
directive|undef
name|pp_preinc
end_undef

begin_define
define|#
directive|define
name|pp_preinc
value|CPerlObj::Perl_pp_preinc
end_define

begin_undef
undef|#
directive|undef
name|pp_i_preinc
end_undef

begin_define
define|#
directive|define
name|pp_i_preinc
value|CPerlObj::Perl_pp_preinc
end_define

begin_undef
undef|#
directive|undef
name|pp_predec
end_undef

begin_define
define|#
directive|define
name|pp_predec
value|CPerlObj::Perl_pp_predec
end_define

begin_undef
undef|#
directive|undef
name|pp_i_predec
end_undef

begin_define
define|#
directive|define
name|pp_i_predec
value|CPerlObj::Perl_pp_predec
end_define

begin_undef
undef|#
directive|undef
name|pp_postinc
end_undef

begin_define
define|#
directive|define
name|pp_postinc
value|CPerlObj::Perl_pp_postinc
end_define

begin_undef
undef|#
directive|undef
name|pp_i_postinc
end_undef

begin_define
define|#
directive|define
name|pp_i_postinc
value|CPerlObj::Perl_pp_postinc
end_define

begin_undef
undef|#
directive|undef
name|pp_postdec
end_undef

begin_define
define|#
directive|define
name|pp_postdec
value|CPerlObj::Perl_pp_postdec
end_define

begin_undef
undef|#
directive|undef
name|pp_i_postdec
end_undef

begin_define
define|#
directive|define
name|pp_i_postdec
value|CPerlObj::Perl_pp_postdec
end_define

begin_undef
undef|#
directive|undef
name|pp_pow
end_undef

begin_define
define|#
directive|define
name|pp_pow
value|CPerlObj::Perl_pp_pow
end_define

begin_undef
undef|#
directive|undef
name|pp_multiply
end_undef

begin_define
define|#
directive|define
name|pp_multiply
value|CPerlObj::Perl_pp_multiply
end_define

begin_undef
undef|#
directive|undef
name|pp_i_multiply
end_undef

begin_define
define|#
directive|define
name|pp_i_multiply
value|CPerlObj::Perl_pp_i_multiply
end_define

begin_undef
undef|#
directive|undef
name|pp_divide
end_undef

begin_define
define|#
directive|define
name|pp_divide
value|CPerlObj::Perl_pp_divide
end_define

begin_undef
undef|#
directive|undef
name|pp_i_divide
end_undef

begin_define
define|#
directive|define
name|pp_i_divide
value|CPerlObj::Perl_pp_i_divide
end_define

begin_undef
undef|#
directive|undef
name|pp_modulo
end_undef

begin_define
define|#
directive|define
name|pp_modulo
value|CPerlObj::Perl_pp_modulo
end_define

begin_undef
undef|#
directive|undef
name|pp_i_modulo
end_undef

begin_define
define|#
directive|define
name|pp_i_modulo
value|CPerlObj::Perl_pp_i_modulo
end_define

begin_undef
undef|#
directive|undef
name|pp_repeat
end_undef

begin_define
define|#
directive|define
name|pp_repeat
value|CPerlObj::Perl_pp_repeat
end_define

begin_undef
undef|#
directive|undef
name|pp_add
end_undef

begin_define
define|#
directive|define
name|pp_add
value|CPerlObj::Perl_pp_add
end_define

begin_undef
undef|#
directive|undef
name|pp_i_add
end_undef

begin_define
define|#
directive|define
name|pp_i_add
value|CPerlObj::Perl_pp_i_add
end_define

begin_undef
undef|#
directive|undef
name|pp_subtract
end_undef

begin_define
define|#
directive|define
name|pp_subtract
value|CPerlObj::Perl_pp_subtract
end_define

begin_undef
undef|#
directive|undef
name|pp_i_subtract
end_undef

begin_define
define|#
directive|define
name|pp_i_subtract
value|CPerlObj::Perl_pp_i_subtract
end_define

begin_undef
undef|#
directive|undef
name|pp_concat
end_undef

begin_define
define|#
directive|define
name|pp_concat
value|CPerlObj::Perl_pp_concat
end_define

begin_undef
undef|#
directive|undef
name|pp_stringify
end_undef

begin_define
define|#
directive|define
name|pp_stringify
value|CPerlObj::Perl_pp_stringify
end_define

begin_undef
undef|#
directive|undef
name|pp_left_shift
end_undef

begin_define
define|#
directive|define
name|pp_left_shift
value|CPerlObj::Perl_pp_left_shift
end_define

begin_undef
undef|#
directive|undef
name|pp_right_shift
end_undef

begin_define
define|#
directive|define
name|pp_right_shift
value|CPerlObj::Perl_pp_right_shift
end_define

begin_undef
undef|#
directive|undef
name|pp_lt
end_undef

begin_define
define|#
directive|define
name|pp_lt
value|CPerlObj::Perl_pp_lt
end_define

begin_undef
undef|#
directive|undef
name|pp_i_lt
end_undef

begin_define
define|#
directive|define
name|pp_i_lt
value|CPerlObj::Perl_pp_i_lt
end_define

begin_undef
undef|#
directive|undef
name|pp_gt
end_undef

begin_define
define|#
directive|define
name|pp_gt
value|CPerlObj::Perl_pp_gt
end_define

begin_undef
undef|#
directive|undef
name|pp_i_gt
end_undef

begin_define
define|#
directive|define
name|pp_i_gt
value|CPerlObj::Perl_pp_i_gt
end_define

begin_undef
undef|#
directive|undef
name|pp_le
end_undef

begin_define
define|#
directive|define
name|pp_le
value|CPerlObj::Perl_pp_le
end_define

begin_undef
undef|#
directive|undef
name|pp_i_le
end_undef

begin_define
define|#
directive|define
name|pp_i_le
value|CPerlObj::Perl_pp_i_le
end_define

begin_undef
undef|#
directive|undef
name|pp_ge
end_undef

begin_define
define|#
directive|define
name|pp_ge
value|CPerlObj::Perl_pp_ge
end_define

begin_undef
undef|#
directive|undef
name|pp_i_ge
end_undef

begin_define
define|#
directive|define
name|pp_i_ge
value|CPerlObj::Perl_pp_i_ge
end_define

begin_undef
undef|#
directive|undef
name|pp_eq
end_undef

begin_define
define|#
directive|define
name|pp_eq
value|CPerlObj::Perl_pp_eq
end_define

begin_undef
undef|#
directive|undef
name|pp_i_eq
end_undef

begin_define
define|#
directive|define
name|pp_i_eq
value|CPerlObj::Perl_pp_i_eq
end_define

begin_undef
undef|#
directive|undef
name|pp_ne
end_undef

begin_define
define|#
directive|define
name|pp_ne
value|CPerlObj::Perl_pp_ne
end_define

begin_undef
undef|#
directive|undef
name|pp_i_ne
end_undef

begin_define
define|#
directive|define
name|pp_i_ne
value|CPerlObj::Perl_pp_i_ne
end_define

begin_undef
undef|#
directive|undef
name|pp_ncmp
end_undef

begin_define
define|#
directive|define
name|pp_ncmp
value|CPerlObj::Perl_pp_ncmp
end_define

begin_undef
undef|#
directive|undef
name|pp_i_ncmp
end_undef

begin_define
define|#
directive|define
name|pp_i_ncmp
value|CPerlObj::Perl_pp_i_ncmp
end_define

begin_undef
undef|#
directive|undef
name|pp_slt
end_undef

begin_define
define|#
directive|define
name|pp_slt
value|CPerlObj::Perl_pp_slt
end_define

begin_undef
undef|#
directive|undef
name|pp_sgt
end_undef

begin_define
define|#
directive|define
name|pp_sgt
value|CPerlObj::Perl_pp_sgt
end_define

begin_undef
undef|#
directive|undef
name|pp_sle
end_undef

begin_define
define|#
directive|define
name|pp_sle
value|CPerlObj::Perl_pp_sle
end_define

begin_undef
undef|#
directive|undef
name|pp_sge
end_undef

begin_define
define|#
directive|define
name|pp_sge
value|CPerlObj::Perl_pp_sge
end_define

begin_undef
undef|#
directive|undef
name|pp_seq
end_undef

begin_define
define|#
directive|define
name|pp_seq
value|CPerlObj::Perl_pp_seq
end_define

begin_undef
undef|#
directive|undef
name|pp_sne
end_undef

begin_define
define|#
directive|define
name|pp_sne
value|CPerlObj::Perl_pp_sne
end_define

begin_undef
undef|#
directive|undef
name|pp_scmp
end_undef

begin_define
define|#
directive|define
name|pp_scmp
value|CPerlObj::Perl_pp_scmp
end_define

begin_undef
undef|#
directive|undef
name|pp_bit_and
end_undef

begin_define
define|#
directive|define
name|pp_bit_and
value|CPerlObj::Perl_pp_bit_and
end_define

begin_undef
undef|#
directive|undef
name|pp_bit_xor
end_undef

begin_define
define|#
directive|define
name|pp_bit_xor
value|CPerlObj::Perl_pp_bit_xor
end_define

begin_undef
undef|#
directive|undef
name|pp_bit_or
end_undef

begin_define
define|#
directive|define
name|pp_bit_or
value|CPerlObj::Perl_pp_bit_or
end_define

begin_undef
undef|#
directive|undef
name|pp_negate
end_undef

begin_define
define|#
directive|define
name|pp_negate
value|CPerlObj::Perl_pp_negate
end_define

begin_undef
undef|#
directive|undef
name|pp_i_negate
end_undef

begin_define
define|#
directive|define
name|pp_i_negate
value|CPerlObj::Perl_pp_i_negate
end_define

begin_undef
undef|#
directive|undef
name|pp_not
end_undef

begin_define
define|#
directive|define
name|pp_not
value|CPerlObj::Perl_pp_not
end_define

begin_undef
undef|#
directive|undef
name|pp_complement
end_undef

begin_define
define|#
directive|define
name|pp_complement
value|CPerlObj::Perl_pp_complement
end_define

begin_undef
undef|#
directive|undef
name|pp_atan2
end_undef

begin_define
define|#
directive|define
name|pp_atan2
value|CPerlObj::Perl_pp_atan2
end_define

begin_undef
undef|#
directive|undef
name|pp_sin
end_undef

begin_define
define|#
directive|define
name|pp_sin
value|CPerlObj::Perl_pp_sin
end_define

begin_undef
undef|#
directive|undef
name|pp_cos
end_undef

begin_define
define|#
directive|define
name|pp_cos
value|CPerlObj::Perl_pp_cos
end_define

begin_undef
undef|#
directive|undef
name|pp_rand
end_undef

begin_define
define|#
directive|define
name|pp_rand
value|CPerlObj::Perl_pp_rand
end_define

begin_undef
undef|#
directive|undef
name|pp_srand
end_undef

begin_define
define|#
directive|define
name|pp_srand
value|CPerlObj::Perl_pp_srand
end_define

begin_undef
undef|#
directive|undef
name|pp_exp
end_undef

begin_define
define|#
directive|define
name|pp_exp
value|CPerlObj::Perl_pp_exp
end_define

begin_undef
undef|#
directive|undef
name|pp_log
end_undef

begin_define
define|#
directive|define
name|pp_log
value|CPerlObj::Perl_pp_log
end_define

begin_undef
undef|#
directive|undef
name|pp_sqrt
end_undef

begin_define
define|#
directive|define
name|pp_sqrt
value|CPerlObj::Perl_pp_sqrt
end_define

begin_undef
undef|#
directive|undef
name|pp_int
end_undef

begin_define
define|#
directive|define
name|pp_int
value|CPerlObj::Perl_pp_int
end_define

begin_undef
undef|#
directive|undef
name|pp_hex
end_undef

begin_define
define|#
directive|define
name|pp_hex
value|CPerlObj::Perl_pp_hex
end_define

begin_undef
undef|#
directive|undef
name|pp_oct
end_undef

begin_define
define|#
directive|define
name|pp_oct
value|CPerlObj::Perl_pp_oct
end_define

begin_undef
undef|#
directive|undef
name|pp_abs
end_undef

begin_define
define|#
directive|define
name|pp_abs
value|CPerlObj::Perl_pp_abs
end_define

begin_undef
undef|#
directive|undef
name|pp_length
end_undef

begin_define
define|#
directive|define
name|pp_length
value|CPerlObj::Perl_pp_length
end_define

begin_undef
undef|#
directive|undef
name|pp_substr
end_undef

begin_define
define|#
directive|define
name|pp_substr
value|CPerlObj::Perl_pp_substr
end_define

begin_undef
undef|#
directive|undef
name|pp_vec
end_undef

begin_define
define|#
directive|define
name|pp_vec
value|CPerlObj::Perl_pp_vec
end_define

begin_undef
undef|#
directive|undef
name|pp_index
end_undef

begin_define
define|#
directive|define
name|pp_index
value|CPerlObj::Perl_pp_index
end_define

begin_undef
undef|#
directive|undef
name|pp_rindex
end_undef

begin_define
define|#
directive|define
name|pp_rindex
value|CPerlObj::Perl_pp_rindex
end_define

begin_undef
undef|#
directive|undef
name|pp_sprintf
end_undef

begin_define
define|#
directive|define
name|pp_sprintf
value|CPerlObj::Perl_pp_sprintf
end_define

begin_undef
undef|#
directive|undef
name|pp_formline
end_undef

begin_define
define|#
directive|define
name|pp_formline
value|CPerlObj::Perl_pp_formline
end_define

begin_undef
undef|#
directive|undef
name|pp_ord
end_undef

begin_define
define|#
directive|define
name|pp_ord
value|CPerlObj::Perl_pp_ord
end_define

begin_undef
undef|#
directive|undef
name|pp_chr
end_undef

begin_define
define|#
directive|define
name|pp_chr
value|CPerlObj::Perl_pp_chr
end_define

begin_undef
undef|#
directive|undef
name|pp_crypt
end_undef

begin_define
define|#
directive|define
name|pp_crypt
value|CPerlObj::Perl_pp_crypt
end_define

begin_undef
undef|#
directive|undef
name|pp_ucfirst
end_undef

begin_define
define|#
directive|define
name|pp_ucfirst
value|CPerlObj::Perl_pp_ucfirst
end_define

begin_undef
undef|#
directive|undef
name|pp_lcfirst
end_undef

begin_define
define|#
directive|define
name|pp_lcfirst
value|CPerlObj::Perl_pp_lcfirst
end_define

begin_undef
undef|#
directive|undef
name|pp_uc
end_undef

begin_define
define|#
directive|define
name|pp_uc
value|CPerlObj::Perl_pp_uc
end_define

begin_undef
undef|#
directive|undef
name|pp_lc
end_undef

begin_define
define|#
directive|define
name|pp_lc
value|CPerlObj::Perl_pp_lc
end_define

begin_undef
undef|#
directive|undef
name|pp_quotemeta
end_undef

begin_define
define|#
directive|define
name|pp_quotemeta
value|CPerlObj::Perl_pp_quotemeta
end_define

begin_undef
undef|#
directive|undef
name|pp_rv2av
end_undef

begin_define
define|#
directive|define
name|pp_rv2av
value|CPerlObj::Perl_pp_rv2av
end_define

begin_undef
undef|#
directive|undef
name|pp_aelemfast
end_undef

begin_define
define|#
directive|define
name|pp_aelemfast
value|CPerlObj::Perl_pp_aelemfast
end_define

begin_undef
undef|#
directive|undef
name|pp_aelem
end_undef

begin_define
define|#
directive|define
name|pp_aelem
value|CPerlObj::Perl_pp_aelem
end_define

begin_undef
undef|#
directive|undef
name|pp_aslice
end_undef

begin_define
define|#
directive|define
name|pp_aslice
value|CPerlObj::Perl_pp_aslice
end_define

begin_undef
undef|#
directive|undef
name|pp_each
end_undef

begin_define
define|#
directive|define
name|pp_each
value|CPerlObj::Perl_pp_each
end_define

begin_undef
undef|#
directive|undef
name|pp_values
end_undef

begin_define
define|#
directive|define
name|pp_values
value|CPerlObj::Perl_pp_values
end_define

begin_undef
undef|#
directive|undef
name|pp_keys
end_undef

begin_define
define|#
directive|define
name|pp_keys
value|CPerlObj::Perl_pp_keys
end_define

begin_undef
undef|#
directive|undef
name|pp_delete
end_undef

begin_define
define|#
directive|define
name|pp_delete
value|CPerlObj::Perl_pp_delete
end_define

begin_undef
undef|#
directive|undef
name|pp_exists
end_undef

begin_define
define|#
directive|define
name|pp_exists
value|CPerlObj::Perl_pp_exists
end_define

begin_undef
undef|#
directive|undef
name|pp_rv2hv
end_undef

begin_define
define|#
directive|define
name|pp_rv2hv
value|CPerlObj::Perl_pp_rv2hv
end_define

begin_undef
undef|#
directive|undef
name|pp_helem
end_undef

begin_define
define|#
directive|define
name|pp_helem
value|CPerlObj::Perl_pp_helem
end_define

begin_undef
undef|#
directive|undef
name|pp_hslice
end_undef

begin_define
define|#
directive|define
name|pp_hslice
value|CPerlObj::Perl_pp_hslice
end_define

begin_undef
undef|#
directive|undef
name|pp_unpack
end_undef

begin_define
define|#
directive|define
name|pp_unpack
value|CPerlObj::Perl_pp_unpack
end_define

begin_undef
undef|#
directive|undef
name|pp_pack
end_undef

begin_define
define|#
directive|define
name|pp_pack
value|CPerlObj::Perl_pp_pack
end_define

begin_undef
undef|#
directive|undef
name|pp_split
end_undef

begin_define
define|#
directive|define
name|pp_split
value|CPerlObj::Perl_pp_split
end_define

begin_undef
undef|#
directive|undef
name|pp_join
end_undef

begin_define
define|#
directive|define
name|pp_join
value|CPerlObj::Perl_pp_join
end_define

begin_undef
undef|#
directive|undef
name|pp_list
end_undef

begin_define
define|#
directive|define
name|pp_list
value|CPerlObj::Perl_pp_list
end_define

begin_undef
undef|#
directive|undef
name|pp_lslice
end_undef

begin_define
define|#
directive|define
name|pp_lslice
value|CPerlObj::Perl_pp_lslice
end_define

begin_undef
undef|#
directive|undef
name|pp_anonlist
end_undef

begin_define
define|#
directive|define
name|pp_anonlist
value|CPerlObj::Perl_pp_anonlist
end_define

begin_undef
undef|#
directive|undef
name|pp_anonhash
end_undef

begin_define
define|#
directive|define
name|pp_anonhash
value|CPerlObj::Perl_pp_anonhash
end_define

begin_undef
undef|#
directive|undef
name|pp_splice
end_undef

begin_define
define|#
directive|define
name|pp_splice
value|CPerlObj::Perl_pp_splice
end_define

begin_undef
undef|#
directive|undef
name|pp_push
end_undef

begin_define
define|#
directive|define
name|pp_push
value|CPerlObj::Perl_pp_push
end_define

begin_undef
undef|#
directive|undef
name|pp_pop
end_undef

begin_define
define|#
directive|define
name|pp_pop
value|CPerlObj::Perl_pp_pop
end_define

begin_undef
undef|#
directive|undef
name|pp_shift
end_undef

begin_define
define|#
directive|define
name|pp_shift
value|CPerlObj::Perl_pp_shift
end_define

begin_undef
undef|#
directive|undef
name|pp_unshift
end_undef

begin_define
define|#
directive|define
name|pp_unshift
value|CPerlObj::Perl_pp_unshift
end_define

begin_undef
undef|#
directive|undef
name|pp_sort
end_undef

begin_define
define|#
directive|define
name|pp_sort
value|CPerlObj::Perl_pp_sort
end_define

begin_undef
undef|#
directive|undef
name|pp_reverse
end_undef

begin_define
define|#
directive|define
name|pp_reverse
value|CPerlObj::Perl_pp_reverse
end_define

begin_undef
undef|#
directive|undef
name|pp_grepstart
end_undef

begin_define
define|#
directive|define
name|pp_grepstart
value|CPerlObj::Perl_pp_grepstart
end_define

begin_undef
undef|#
directive|undef
name|pp_grepwhile
end_undef

begin_define
define|#
directive|define
name|pp_grepwhile
value|CPerlObj::Perl_pp_grepwhile
end_define

begin_undef
undef|#
directive|undef
name|pp_mapstart
end_undef

begin_define
define|#
directive|define
name|pp_mapstart
value|CPerlObj::Perl_pp_mapstart
end_define

begin_undef
undef|#
directive|undef
name|pp_mapwhile
end_undef

begin_define
define|#
directive|define
name|pp_mapwhile
value|CPerlObj::Perl_pp_mapwhile
end_define

begin_undef
undef|#
directive|undef
name|pp_range
end_undef

begin_define
define|#
directive|define
name|pp_range
value|CPerlObj::Perl_pp_range
end_define

begin_undef
undef|#
directive|undef
name|pp_flip
end_undef

begin_define
define|#
directive|define
name|pp_flip
value|CPerlObj::Perl_pp_flip
end_define

begin_undef
undef|#
directive|undef
name|pp_flop
end_undef

begin_define
define|#
directive|define
name|pp_flop
value|CPerlObj::Perl_pp_flop
end_define

begin_undef
undef|#
directive|undef
name|pp_and
end_undef

begin_define
define|#
directive|define
name|pp_and
value|CPerlObj::Perl_pp_and
end_define

begin_undef
undef|#
directive|undef
name|pp_or
end_undef

begin_define
define|#
directive|define
name|pp_or
value|CPerlObj::Perl_pp_or
end_define

begin_undef
undef|#
directive|undef
name|pp_xor
end_undef

begin_define
define|#
directive|define
name|pp_xor
value|CPerlObj::Perl_pp_xor
end_define

begin_undef
undef|#
directive|undef
name|pp_cond_expr
end_undef

begin_define
define|#
directive|define
name|pp_cond_expr
value|CPerlObj::Perl_pp_cond_expr
end_define

begin_undef
undef|#
directive|undef
name|pp_andassign
end_undef

begin_define
define|#
directive|define
name|pp_andassign
value|CPerlObj::Perl_pp_andassign
end_define

begin_undef
undef|#
directive|undef
name|pp_orassign
end_undef

begin_define
define|#
directive|define
name|pp_orassign
value|CPerlObj::Perl_pp_orassign
end_define

begin_undef
undef|#
directive|undef
name|pp_method
end_undef

begin_define
define|#
directive|define
name|pp_method
value|CPerlObj::Perl_pp_method
end_define

begin_undef
undef|#
directive|undef
name|pp_entersub
end_undef

begin_define
define|#
directive|define
name|pp_entersub
value|CPerlObj::Perl_pp_entersub
end_define

begin_undef
undef|#
directive|undef
name|pp_leavesub
end_undef

begin_define
define|#
directive|define
name|pp_leavesub
value|CPerlObj::Perl_pp_leavesub
end_define

begin_undef
undef|#
directive|undef
name|pp_caller
end_undef

begin_define
define|#
directive|define
name|pp_caller
value|CPerlObj::Perl_pp_caller
end_define

begin_undef
undef|#
directive|undef
name|pp_warn
end_undef

begin_define
define|#
directive|define
name|pp_warn
value|CPerlObj::Perl_pp_warn
end_define

begin_undef
undef|#
directive|undef
name|pp_die
end_undef

begin_define
define|#
directive|define
name|pp_die
value|CPerlObj::Perl_pp_die
end_define

begin_undef
undef|#
directive|undef
name|pp_reset
end_undef

begin_define
define|#
directive|define
name|pp_reset
value|CPerlObj::Perl_pp_reset
end_define

begin_undef
undef|#
directive|undef
name|pp_lineseq
end_undef

begin_define
define|#
directive|define
name|pp_lineseq
value|CPerlObj::Perl_pp_lineseq
end_define

begin_undef
undef|#
directive|undef
name|pp_nextstate
end_undef

begin_define
define|#
directive|define
name|pp_nextstate
value|CPerlObj::Perl_pp_nextstate
end_define

begin_undef
undef|#
directive|undef
name|pp_dbstate
end_undef

begin_define
define|#
directive|define
name|pp_dbstate
value|CPerlObj::Perl_pp_dbstate
end_define

begin_undef
undef|#
directive|undef
name|pp_unstack
end_undef

begin_define
define|#
directive|define
name|pp_unstack
value|CPerlObj::Perl_pp_unstack
end_define

begin_undef
undef|#
directive|undef
name|pp_enter
end_undef

begin_define
define|#
directive|define
name|pp_enter
value|CPerlObj::Perl_pp_enter
end_define

begin_undef
undef|#
directive|undef
name|pp_leave
end_undef

begin_define
define|#
directive|define
name|pp_leave
value|CPerlObj::Perl_pp_leave
end_define

begin_undef
undef|#
directive|undef
name|pp_scope
end_undef

begin_define
define|#
directive|define
name|pp_scope
value|CPerlObj::Perl_pp_scope
end_define

begin_undef
undef|#
directive|undef
name|pp_enteriter
end_undef

begin_define
define|#
directive|define
name|pp_enteriter
value|CPerlObj::Perl_pp_enteriter
end_define

begin_undef
undef|#
directive|undef
name|pp_iter
end_undef

begin_define
define|#
directive|define
name|pp_iter
value|CPerlObj::Perl_pp_iter
end_define

begin_undef
undef|#
directive|undef
name|pp_enterloop
end_undef

begin_define
define|#
directive|define
name|pp_enterloop
value|CPerlObj::Perl_pp_enterloop
end_define

begin_undef
undef|#
directive|undef
name|pp_leaveloop
end_undef

begin_define
define|#
directive|define
name|pp_leaveloop
value|CPerlObj::Perl_pp_leaveloop
end_define

begin_undef
undef|#
directive|undef
name|pp_return
end_undef

begin_define
define|#
directive|define
name|pp_return
value|CPerlObj::Perl_pp_return
end_define

begin_undef
undef|#
directive|undef
name|pp_last
end_undef

begin_define
define|#
directive|define
name|pp_last
value|CPerlObj::Perl_pp_last
end_define

begin_undef
undef|#
directive|undef
name|pp_next
end_undef

begin_define
define|#
directive|define
name|pp_next
value|CPerlObj::Perl_pp_next
end_define

begin_undef
undef|#
directive|undef
name|pp_redo
end_undef

begin_define
define|#
directive|define
name|pp_redo
value|CPerlObj::Perl_pp_redo
end_define

begin_undef
undef|#
directive|undef
name|pp_dump
end_undef

begin_define
define|#
directive|define
name|pp_dump
value|CPerlObj::Perl_pp_dump
end_define

begin_undef
undef|#
directive|undef
name|pp_goto
end_undef

begin_define
define|#
directive|define
name|pp_goto
value|CPerlObj::Perl_pp_goto
end_define

begin_undef
undef|#
directive|undef
name|pp_exit
end_undef

begin_define
define|#
directive|define
name|pp_exit
value|CPerlObj::Perl_pp_exit
end_define

begin_undef
undef|#
directive|undef
name|pp_open
end_undef

begin_define
define|#
directive|define
name|pp_open
value|CPerlObj::Perl_pp_open
end_define

begin_undef
undef|#
directive|undef
name|pp_close
end_undef

begin_define
define|#
directive|define
name|pp_close
value|CPerlObj::Perl_pp_close
end_define

begin_undef
undef|#
directive|undef
name|pp_pipe_op
end_undef

begin_define
define|#
directive|define
name|pp_pipe_op
value|CPerlObj::Perl_pp_pipe_op
end_define

begin_undef
undef|#
directive|undef
name|pp_fileno
end_undef

begin_define
define|#
directive|define
name|pp_fileno
value|CPerlObj::Perl_pp_fileno
end_define

begin_undef
undef|#
directive|undef
name|pp_umask
end_undef

begin_define
define|#
directive|define
name|pp_umask
value|CPerlObj::Perl_pp_umask
end_define

begin_undef
undef|#
directive|undef
name|pp_binmode
end_undef

begin_define
define|#
directive|define
name|pp_binmode
value|CPerlObj::Perl_pp_binmode
end_define

begin_undef
undef|#
directive|undef
name|pp_tie
end_undef

begin_define
define|#
directive|define
name|pp_tie
value|CPerlObj::Perl_pp_tie
end_define

begin_undef
undef|#
directive|undef
name|pp_untie
end_undef

begin_define
define|#
directive|define
name|pp_untie
value|CPerlObj::Perl_pp_untie
end_define

begin_undef
undef|#
directive|undef
name|pp_tied
end_undef

begin_define
define|#
directive|define
name|pp_tied
value|CPerlObj::Perl_pp_tied
end_define

begin_undef
undef|#
directive|undef
name|pp_dbmopen
end_undef

begin_define
define|#
directive|define
name|pp_dbmopen
value|CPerlObj::Perl_pp_dbmopen
end_define

begin_undef
undef|#
directive|undef
name|pp_dbmclose
end_undef

begin_define
define|#
directive|define
name|pp_dbmclose
value|CPerlObj::Perl_pp_dbmclose
end_define

begin_undef
undef|#
directive|undef
name|pp_sselect
end_undef

begin_define
define|#
directive|define
name|pp_sselect
value|CPerlObj::Perl_pp_sselect
end_define

begin_undef
undef|#
directive|undef
name|pp_select
end_undef

begin_define
define|#
directive|define
name|pp_select
value|CPerlObj::Perl_pp_select
end_define

begin_undef
undef|#
directive|undef
name|pp_getc
end_undef

begin_define
define|#
directive|define
name|pp_getc
value|CPerlObj::Perl_pp_getc
end_define

begin_undef
undef|#
directive|undef
name|pp_read
end_undef

begin_define
define|#
directive|define
name|pp_read
value|CPerlObj::Perl_pp_read
end_define

begin_undef
undef|#
directive|undef
name|pp_enterwrite
end_undef

begin_define
define|#
directive|define
name|pp_enterwrite
value|CPerlObj::Perl_pp_enterwrite
end_define

begin_undef
undef|#
directive|undef
name|pp_leavewrite
end_undef

begin_define
define|#
directive|define
name|pp_leavewrite
value|CPerlObj::Perl_pp_leavewrite
end_define

begin_undef
undef|#
directive|undef
name|pp_prtf
end_undef

begin_define
define|#
directive|define
name|pp_prtf
value|CPerlObj::Perl_pp_prtf
end_define

begin_undef
undef|#
directive|undef
name|pp_print
end_undef

begin_define
define|#
directive|define
name|pp_print
value|CPerlObj::Perl_pp_print
end_define

begin_undef
undef|#
directive|undef
name|pp_sysopen
end_undef

begin_define
define|#
directive|define
name|pp_sysopen
value|CPerlObj::Perl_pp_sysopen
end_define

begin_undef
undef|#
directive|undef
name|pp_sysseek
end_undef

begin_define
define|#
directive|define
name|pp_sysseek
value|CPerlObj::Perl_pp_sysseek
end_define

begin_undef
undef|#
directive|undef
name|pp_sysread
end_undef

begin_define
define|#
directive|define
name|pp_sysread
value|CPerlObj::Perl_pp_sysread
end_define

begin_undef
undef|#
directive|undef
name|pp_syswrite
end_undef

begin_define
define|#
directive|define
name|pp_syswrite
value|CPerlObj::Perl_pp_syswrite
end_define

begin_undef
undef|#
directive|undef
name|pp_send
end_undef

begin_define
define|#
directive|define
name|pp_send
value|CPerlObj::Perl_pp_send
end_define

begin_undef
undef|#
directive|undef
name|pp_recv
end_undef

begin_define
define|#
directive|define
name|pp_recv
value|CPerlObj::Perl_pp_recv
end_define

begin_undef
undef|#
directive|undef
name|pp_eof
end_undef

begin_define
define|#
directive|define
name|pp_eof
value|CPerlObj::Perl_pp_eof
end_define

begin_undef
undef|#
directive|undef
name|pp_tell
end_undef

begin_define
define|#
directive|define
name|pp_tell
value|CPerlObj::Perl_pp_tell
end_define

begin_undef
undef|#
directive|undef
name|pp_seek
end_undef

begin_define
define|#
directive|define
name|pp_seek
value|CPerlObj::Perl_pp_seek
end_define

begin_undef
undef|#
directive|undef
name|pp_truncate
end_undef

begin_define
define|#
directive|define
name|pp_truncate
value|CPerlObj::Perl_pp_truncate
end_define

begin_undef
undef|#
directive|undef
name|pp_fcntl
end_undef

begin_define
define|#
directive|define
name|pp_fcntl
value|CPerlObj::Perl_pp_fcntl
end_define

begin_undef
undef|#
directive|undef
name|pp_ioctl
end_undef

begin_define
define|#
directive|define
name|pp_ioctl
value|CPerlObj::Perl_pp_ioctl
end_define

begin_undef
undef|#
directive|undef
name|pp_flock
end_undef

begin_define
define|#
directive|define
name|pp_flock
value|CPerlObj::Perl_pp_flock
end_define

begin_undef
undef|#
directive|undef
name|pp_socket
end_undef

begin_define
define|#
directive|define
name|pp_socket
value|CPerlObj::Perl_pp_socket
end_define

begin_undef
undef|#
directive|undef
name|pp_sockpair
end_undef

begin_define
define|#
directive|define
name|pp_sockpair
value|CPerlObj::Perl_pp_sockpair
end_define

begin_undef
undef|#
directive|undef
name|pp_bind
end_undef

begin_define
define|#
directive|define
name|pp_bind
value|CPerlObj::Perl_pp_bind
end_define

begin_undef
undef|#
directive|undef
name|pp_connect
end_undef

begin_define
define|#
directive|define
name|pp_connect
value|CPerlObj::Perl_pp_connect
end_define

begin_undef
undef|#
directive|undef
name|pp_listen
end_undef

begin_define
define|#
directive|define
name|pp_listen
value|CPerlObj::Perl_pp_listen
end_define

begin_undef
undef|#
directive|undef
name|pp_accept
end_undef

begin_define
define|#
directive|define
name|pp_accept
value|CPerlObj::Perl_pp_accept
end_define

begin_undef
undef|#
directive|undef
name|pp_shutdown
end_undef

begin_define
define|#
directive|define
name|pp_shutdown
value|CPerlObj::Perl_pp_shutdown
end_define

begin_undef
undef|#
directive|undef
name|pp_gsockopt
end_undef

begin_define
define|#
directive|define
name|pp_gsockopt
value|CPerlObj::Perl_pp_gsockopt
end_define

begin_undef
undef|#
directive|undef
name|pp_ssockopt
end_undef

begin_define
define|#
directive|define
name|pp_ssockopt
value|CPerlObj::Perl_pp_ssockopt
end_define

begin_undef
undef|#
directive|undef
name|pp_getsockname
end_undef

begin_define
define|#
directive|define
name|pp_getsockname
value|CPerlObj::Perl_pp_getsockname
end_define

begin_undef
undef|#
directive|undef
name|pp_getpeername
end_undef

begin_define
define|#
directive|define
name|pp_getpeername
value|CPerlObj::Perl_pp_getpeername
end_define

begin_undef
undef|#
directive|undef
name|pp_lstat
end_undef

begin_define
define|#
directive|define
name|pp_lstat
value|CPerlObj::Perl_pp_lstat
end_define

begin_undef
undef|#
directive|undef
name|pp_stat
end_undef

begin_define
define|#
directive|define
name|pp_stat
value|CPerlObj::Perl_pp_stat
end_define

begin_undef
undef|#
directive|undef
name|pp_ftrread
end_undef

begin_define
define|#
directive|define
name|pp_ftrread
value|CPerlObj::Perl_pp_ftrread
end_define

begin_undef
undef|#
directive|undef
name|pp_ftrwrite
end_undef

begin_define
define|#
directive|define
name|pp_ftrwrite
value|CPerlObj::Perl_pp_ftrwrite
end_define

begin_undef
undef|#
directive|undef
name|pp_ftrexec
end_undef

begin_define
define|#
directive|define
name|pp_ftrexec
value|CPerlObj::Perl_pp_ftrexec
end_define

begin_undef
undef|#
directive|undef
name|pp_fteread
end_undef

begin_define
define|#
directive|define
name|pp_fteread
value|CPerlObj::Perl_pp_fteread
end_define

begin_undef
undef|#
directive|undef
name|pp_ftewrite
end_undef

begin_define
define|#
directive|define
name|pp_ftewrite
value|CPerlObj::Perl_pp_ftewrite
end_define

begin_undef
undef|#
directive|undef
name|pp_fteexec
end_undef

begin_define
define|#
directive|define
name|pp_fteexec
value|CPerlObj::Perl_pp_fteexec
end_define

begin_undef
undef|#
directive|undef
name|pp_ftis
end_undef

begin_define
define|#
directive|define
name|pp_ftis
value|CPerlObj::Perl_pp_ftis
end_define

begin_undef
undef|#
directive|undef
name|pp_fteowned
end_undef

begin_define
define|#
directive|define
name|pp_fteowned
value|CPerlObj::Perl_pp_fteowned
end_define

begin_undef
undef|#
directive|undef
name|pp_ftrowned
end_undef

begin_define
define|#
directive|define
name|pp_ftrowned
value|CPerlObj::Perl_pp_ftrowned
end_define

begin_undef
undef|#
directive|undef
name|pp_ftzero
end_undef

begin_define
define|#
directive|define
name|pp_ftzero
value|CPerlObj::Perl_pp_ftzero
end_define

begin_undef
undef|#
directive|undef
name|pp_ftsize
end_undef

begin_define
define|#
directive|define
name|pp_ftsize
value|CPerlObj::Perl_pp_ftsize
end_define

begin_undef
undef|#
directive|undef
name|pp_ftmtime
end_undef

begin_define
define|#
directive|define
name|pp_ftmtime
value|CPerlObj::Perl_pp_ftmtime
end_define

begin_undef
undef|#
directive|undef
name|pp_ftatime
end_undef

begin_define
define|#
directive|define
name|pp_ftatime
value|CPerlObj::Perl_pp_ftatime
end_define

begin_undef
undef|#
directive|undef
name|pp_ftctime
end_undef

begin_define
define|#
directive|define
name|pp_ftctime
value|CPerlObj::Perl_pp_ftctime
end_define

begin_undef
undef|#
directive|undef
name|pp_ftsock
end_undef

begin_define
define|#
directive|define
name|pp_ftsock
value|CPerlObj::Perl_pp_ftsock
end_define

begin_undef
undef|#
directive|undef
name|pp_ftchr
end_undef

begin_define
define|#
directive|define
name|pp_ftchr
value|CPerlObj::Perl_pp_ftchr
end_define

begin_undef
undef|#
directive|undef
name|pp_ftblk
end_undef

begin_define
define|#
directive|define
name|pp_ftblk
value|CPerlObj::Perl_pp_ftblk
end_define

begin_undef
undef|#
directive|undef
name|pp_ftfile
end_undef

begin_define
define|#
directive|define
name|pp_ftfile
value|CPerlObj::Perl_pp_ftfile
end_define

begin_undef
undef|#
directive|undef
name|pp_ftdir
end_undef

begin_define
define|#
directive|define
name|pp_ftdir
value|CPerlObj::Perl_pp_ftdir
end_define

begin_undef
undef|#
directive|undef
name|pp_ftpipe
end_undef

begin_define
define|#
directive|define
name|pp_ftpipe
value|CPerlObj::Perl_pp_ftpipe
end_define

begin_undef
undef|#
directive|undef
name|pp_ftlink
end_undef

begin_define
define|#
directive|define
name|pp_ftlink
value|CPerlObj::Perl_pp_ftlink
end_define

begin_undef
undef|#
directive|undef
name|pp_ftsuid
end_undef

begin_define
define|#
directive|define
name|pp_ftsuid
value|CPerlObj::Perl_pp_ftsuid
end_define

begin_undef
undef|#
directive|undef
name|pp_ftsgid
end_undef

begin_define
define|#
directive|define
name|pp_ftsgid
value|CPerlObj::Perl_pp_ftsgid
end_define

begin_undef
undef|#
directive|undef
name|pp_ftsvtx
end_undef

begin_define
define|#
directive|define
name|pp_ftsvtx
value|CPerlObj::Perl_pp_ftsvtx
end_define

begin_undef
undef|#
directive|undef
name|pp_fttty
end_undef

begin_define
define|#
directive|define
name|pp_fttty
value|CPerlObj::Perl_pp_fttty
end_define

begin_undef
undef|#
directive|undef
name|pp_fttext
end_undef

begin_define
define|#
directive|define
name|pp_fttext
value|CPerlObj::Perl_pp_fttext
end_define

begin_undef
undef|#
directive|undef
name|pp_ftbinary
end_undef

begin_define
define|#
directive|define
name|pp_ftbinary
value|CPerlObj::Perl_pp_ftbinary
end_define

begin_undef
undef|#
directive|undef
name|pp_chdir
end_undef

begin_define
define|#
directive|define
name|pp_chdir
value|CPerlObj::Perl_pp_chdir
end_define

begin_undef
undef|#
directive|undef
name|pp_chown
end_undef

begin_define
define|#
directive|define
name|pp_chown
value|CPerlObj::Perl_pp_chown
end_define

begin_undef
undef|#
directive|undef
name|pp_chroot
end_undef

begin_define
define|#
directive|define
name|pp_chroot
value|CPerlObj::Perl_pp_chroot
end_define

begin_undef
undef|#
directive|undef
name|pp_unlink
end_undef

begin_define
define|#
directive|define
name|pp_unlink
value|CPerlObj::Perl_pp_unlink
end_define

begin_undef
undef|#
directive|undef
name|pp_chmod
end_undef

begin_define
define|#
directive|define
name|pp_chmod
value|CPerlObj::Perl_pp_chmod
end_define

begin_undef
undef|#
directive|undef
name|pp_utime
end_undef

begin_define
define|#
directive|define
name|pp_utime
value|CPerlObj::Perl_pp_utime
end_define

begin_undef
undef|#
directive|undef
name|pp_rename
end_undef

begin_define
define|#
directive|define
name|pp_rename
value|CPerlObj::Perl_pp_rename
end_define

begin_undef
undef|#
directive|undef
name|pp_link
end_undef

begin_define
define|#
directive|define
name|pp_link
value|CPerlObj::Perl_pp_link
end_define

begin_undef
undef|#
directive|undef
name|pp_symlink
end_undef

begin_define
define|#
directive|define
name|pp_symlink
value|CPerlObj::Perl_pp_symlink
end_define

begin_undef
undef|#
directive|undef
name|pp_readlink
end_undef

begin_define
define|#
directive|define
name|pp_readlink
value|CPerlObj::Perl_pp_readlink
end_define

begin_undef
undef|#
directive|undef
name|pp_mkdir
end_undef

begin_define
define|#
directive|define
name|pp_mkdir
value|CPerlObj::Perl_pp_mkdir
end_define

begin_undef
undef|#
directive|undef
name|pp_rmdir
end_undef

begin_define
define|#
directive|define
name|pp_rmdir
value|CPerlObj::Perl_pp_rmdir
end_define

begin_undef
undef|#
directive|undef
name|pp_open_dir
end_undef

begin_define
define|#
directive|define
name|pp_open_dir
value|CPerlObj::Perl_pp_open_dir
end_define

begin_undef
undef|#
directive|undef
name|pp_readdir
end_undef

begin_define
define|#
directive|define
name|pp_readdir
value|CPerlObj::Perl_pp_readdir
end_define

begin_undef
undef|#
directive|undef
name|pp_telldir
end_undef

begin_define
define|#
directive|define
name|pp_telldir
value|CPerlObj::Perl_pp_telldir
end_define

begin_undef
undef|#
directive|undef
name|pp_seekdir
end_undef

begin_define
define|#
directive|define
name|pp_seekdir
value|CPerlObj::Perl_pp_seekdir
end_define

begin_undef
undef|#
directive|undef
name|pp_rewinddir
end_undef

begin_define
define|#
directive|define
name|pp_rewinddir
value|CPerlObj::Perl_pp_rewinddir
end_define

begin_undef
undef|#
directive|undef
name|pp_closedir
end_undef

begin_define
define|#
directive|define
name|pp_closedir
value|CPerlObj::Perl_pp_closedir
end_define

begin_undef
undef|#
directive|undef
name|pp_fork
end_undef

begin_define
define|#
directive|define
name|pp_fork
value|CPerlObj::Perl_pp_fork
end_define

begin_undef
undef|#
directive|undef
name|pp_wait
end_undef

begin_define
define|#
directive|define
name|pp_wait
value|CPerlObj::Perl_pp_wait
end_define

begin_undef
undef|#
directive|undef
name|pp_waitpid
end_undef

begin_define
define|#
directive|define
name|pp_waitpid
value|CPerlObj::Perl_pp_waitpid
end_define

begin_undef
undef|#
directive|undef
name|pp_system
end_undef

begin_define
define|#
directive|define
name|pp_system
value|CPerlObj::Perl_pp_system
end_define

begin_undef
undef|#
directive|undef
name|pp_exec
end_undef

begin_define
define|#
directive|define
name|pp_exec
value|CPerlObj::Perl_pp_exec
end_define

begin_undef
undef|#
directive|undef
name|pp_kill
end_undef

begin_define
define|#
directive|define
name|pp_kill
value|CPerlObj::Perl_pp_kill
end_define

begin_undef
undef|#
directive|undef
name|pp_getppid
end_undef

begin_define
define|#
directive|define
name|pp_getppid
value|CPerlObj::Perl_pp_getppid
end_define

begin_undef
undef|#
directive|undef
name|pp_getpgrp
end_undef

begin_define
define|#
directive|define
name|pp_getpgrp
value|CPerlObj::Perl_pp_getpgrp
end_define

begin_undef
undef|#
directive|undef
name|pp_setpgrp
end_undef

begin_define
define|#
directive|define
name|pp_setpgrp
value|CPerlObj::Perl_pp_setpgrp
end_define

begin_undef
undef|#
directive|undef
name|pp_getpriority
end_undef

begin_define
define|#
directive|define
name|pp_getpriority
value|CPerlObj::Perl_pp_getpriority
end_define

begin_undef
undef|#
directive|undef
name|pp_setpriority
end_undef

begin_define
define|#
directive|define
name|pp_setpriority
value|CPerlObj::Perl_pp_setpriority
end_define

begin_undef
undef|#
directive|undef
name|pp_time
end_undef

begin_define
define|#
directive|define
name|pp_time
value|CPerlObj::Perl_pp_time
end_define

begin_undef
undef|#
directive|undef
name|pp_tms
end_undef

begin_define
define|#
directive|define
name|pp_tms
value|CPerlObj::Perl_pp_tms
end_define

begin_undef
undef|#
directive|undef
name|pp_localtime
end_undef

begin_define
define|#
directive|define
name|pp_localtime
value|CPerlObj::Perl_pp_localtime
end_define

begin_undef
undef|#
directive|undef
name|pp_gmtime
end_undef

begin_define
define|#
directive|define
name|pp_gmtime
value|CPerlObj::Perl_pp_gmtime
end_define

begin_undef
undef|#
directive|undef
name|pp_alarm
end_undef

begin_define
define|#
directive|define
name|pp_alarm
value|CPerlObj::Perl_pp_alarm
end_define

begin_undef
undef|#
directive|undef
name|pp_sleep
end_undef

begin_define
define|#
directive|define
name|pp_sleep
value|CPerlObj::Perl_pp_sleep
end_define

begin_undef
undef|#
directive|undef
name|pp_shmget
end_undef

begin_define
define|#
directive|define
name|pp_shmget
value|CPerlObj::Perl_pp_shmget
end_define

begin_undef
undef|#
directive|undef
name|pp_shmctl
end_undef

begin_define
define|#
directive|define
name|pp_shmctl
value|CPerlObj::Perl_pp_shmctl
end_define

begin_undef
undef|#
directive|undef
name|pp_shmread
end_undef

begin_define
define|#
directive|define
name|pp_shmread
value|CPerlObj::Perl_pp_shmread
end_define

begin_undef
undef|#
directive|undef
name|pp_shmwrite
end_undef

begin_define
define|#
directive|define
name|pp_shmwrite
value|CPerlObj::Perl_pp_shmwrite
end_define

begin_undef
undef|#
directive|undef
name|pp_msgget
end_undef

begin_define
define|#
directive|define
name|pp_msgget
value|CPerlObj::Perl_pp_msgget
end_define

begin_undef
undef|#
directive|undef
name|pp_msgctl
end_undef

begin_define
define|#
directive|define
name|pp_msgctl
value|CPerlObj::Perl_pp_msgctl
end_define

begin_undef
undef|#
directive|undef
name|pp_msgsnd
end_undef

begin_define
define|#
directive|define
name|pp_msgsnd
value|CPerlObj::Perl_pp_msgsnd
end_define

begin_undef
undef|#
directive|undef
name|pp_msgrcv
end_undef

begin_define
define|#
directive|define
name|pp_msgrcv
value|CPerlObj::Perl_pp_msgrcv
end_define

begin_undef
undef|#
directive|undef
name|pp_semget
end_undef

begin_define
define|#
directive|define
name|pp_semget
value|CPerlObj::Perl_pp_semget
end_define

begin_undef
undef|#
directive|undef
name|pp_semctl
end_undef

begin_define
define|#
directive|define
name|pp_semctl
value|CPerlObj::Perl_pp_semctl
end_define

begin_undef
undef|#
directive|undef
name|pp_semop
end_undef

begin_define
define|#
directive|define
name|pp_semop
value|CPerlObj::Perl_pp_semop
end_define

begin_undef
undef|#
directive|undef
name|pp_require
end_undef

begin_define
define|#
directive|define
name|pp_require
value|CPerlObj::Perl_pp_require
end_define

begin_undef
undef|#
directive|undef
name|pp_dofile
end_undef

begin_define
define|#
directive|define
name|pp_dofile
value|CPerlObj::Perl_pp_dofile
end_define

begin_undef
undef|#
directive|undef
name|pp_entereval
end_undef

begin_define
define|#
directive|define
name|pp_entereval
value|CPerlObj::Perl_pp_entereval
end_define

begin_undef
undef|#
directive|undef
name|pp_leaveeval
end_undef

begin_define
define|#
directive|define
name|pp_leaveeval
value|CPerlObj::Perl_pp_leaveeval
end_define

begin_undef
undef|#
directive|undef
name|pp_entertry
end_undef

begin_define
define|#
directive|define
name|pp_entertry
value|CPerlObj::Perl_pp_entertry
end_define

begin_undef
undef|#
directive|undef
name|pp_leavetry
end_undef

begin_define
define|#
directive|define
name|pp_leavetry
value|CPerlObj::Perl_pp_leavetry
end_define

begin_undef
undef|#
directive|undef
name|pp_ghbyname
end_undef

begin_define
define|#
directive|define
name|pp_ghbyname
value|CPerlObj::Perl_pp_ghbyname
end_define

begin_undef
undef|#
directive|undef
name|pp_ghbyaddr
end_undef

begin_define
define|#
directive|define
name|pp_ghbyaddr
value|CPerlObj::Perl_pp_ghbyaddr
end_define

begin_undef
undef|#
directive|undef
name|pp_ghostent
end_undef

begin_define
define|#
directive|define
name|pp_ghostent
value|CPerlObj::Perl_pp_ghostent
end_define

begin_undef
undef|#
directive|undef
name|pp_gnbyname
end_undef

begin_define
define|#
directive|define
name|pp_gnbyname
value|CPerlObj::Perl_pp_gnbyname
end_define

begin_undef
undef|#
directive|undef
name|pp_gnbyaddr
end_undef

begin_define
define|#
directive|define
name|pp_gnbyaddr
value|CPerlObj::Perl_pp_gnbyaddr
end_define

begin_undef
undef|#
directive|undef
name|pp_gnetent
end_undef

begin_define
define|#
directive|define
name|pp_gnetent
value|CPerlObj::Perl_pp_gnetent
end_define

begin_undef
undef|#
directive|undef
name|pp_gpbyname
end_undef

begin_define
define|#
directive|define
name|pp_gpbyname
value|CPerlObj::Perl_pp_gpbyname
end_define

begin_undef
undef|#
directive|undef
name|pp_gpbynumber
end_undef

begin_define
define|#
directive|define
name|pp_gpbynumber
value|CPerlObj::Perl_pp_gpbynumber
end_define

begin_undef
undef|#
directive|undef
name|pp_gprotoent
end_undef

begin_define
define|#
directive|define
name|pp_gprotoent
value|CPerlObj::Perl_pp_gprotoent
end_define

begin_undef
undef|#
directive|undef
name|pp_gsbyname
end_undef

begin_define
define|#
directive|define
name|pp_gsbyname
value|CPerlObj::Perl_pp_gsbyname
end_define

begin_undef
undef|#
directive|undef
name|pp_gsbyport
end_undef

begin_define
define|#
directive|define
name|pp_gsbyport
value|CPerlObj::Perl_pp_gsbyport
end_define

begin_undef
undef|#
directive|undef
name|pp_gservent
end_undef

begin_define
define|#
directive|define
name|pp_gservent
value|CPerlObj::Perl_pp_gservent
end_define

begin_undef
undef|#
directive|undef
name|pp_shostent
end_undef

begin_define
define|#
directive|define
name|pp_shostent
value|CPerlObj::Perl_pp_shostent
end_define

begin_undef
undef|#
directive|undef
name|pp_snetent
end_undef

begin_define
define|#
directive|define
name|pp_snetent
value|CPerlObj::Perl_pp_snetent
end_define

begin_undef
undef|#
directive|undef
name|pp_sprotoent
end_undef

begin_define
define|#
directive|define
name|pp_sprotoent
value|CPerlObj::Perl_pp_sprotoent
end_define

begin_undef
undef|#
directive|undef
name|pp_sservent
end_undef

begin_define
define|#
directive|define
name|pp_sservent
value|CPerlObj::Perl_pp_sservent
end_define

begin_undef
undef|#
directive|undef
name|pp_ehostent
end_undef

begin_define
define|#
directive|define
name|pp_ehostent
value|CPerlObj::Perl_pp_ehostent
end_define

begin_undef
undef|#
directive|undef
name|pp_enetent
end_undef

begin_define
define|#
directive|define
name|pp_enetent
value|CPerlObj::Perl_pp_enetent
end_define

begin_undef
undef|#
directive|undef
name|pp_eprotoent
end_undef

begin_define
define|#
directive|define
name|pp_eprotoent
value|CPerlObj::Perl_pp_eprotoent
end_define

begin_undef
undef|#
directive|undef
name|pp_eservent
end_undef

begin_define
define|#
directive|define
name|pp_eservent
value|CPerlObj::Perl_pp_eservent
end_define

begin_undef
undef|#
directive|undef
name|pp_gpwnam
end_undef

begin_define
define|#
directive|define
name|pp_gpwnam
value|CPerlObj::Perl_pp_gpwnam
end_define

begin_undef
undef|#
directive|undef
name|pp_gpwuid
end_undef

begin_define
define|#
directive|define
name|pp_gpwuid
value|CPerlObj::Perl_pp_gpwuid
end_define

begin_undef
undef|#
directive|undef
name|pp_gpwent
end_undef

begin_define
define|#
directive|define
name|pp_gpwent
value|CPerlObj::Perl_pp_gpwent
end_define

begin_undef
undef|#
directive|undef
name|pp_spwent
end_undef

begin_define
define|#
directive|define
name|pp_spwent
value|CPerlObj::Perl_pp_spwent
end_define

begin_undef
undef|#
directive|undef
name|pp_epwent
end_undef

begin_define
define|#
directive|define
name|pp_epwent
value|CPerlObj::Perl_pp_epwent
end_define

begin_undef
undef|#
directive|undef
name|pp_ggrnam
end_undef

begin_define
define|#
directive|define
name|pp_ggrnam
value|CPerlObj::Perl_pp_ggrnam
end_define

begin_undef
undef|#
directive|undef
name|pp_ggrgid
end_undef

begin_define
define|#
directive|define
name|pp_ggrgid
value|CPerlObj::Perl_pp_ggrgid
end_define

begin_undef
undef|#
directive|undef
name|pp_ggrent
end_undef

begin_define
define|#
directive|define
name|pp_ggrent
value|CPerlObj::Perl_pp_ggrent
end_define

begin_undef
undef|#
directive|undef
name|pp_sgrent
end_undef

begin_define
define|#
directive|define
name|pp_sgrent
value|CPerlObj::Perl_pp_sgrent
end_define

begin_undef
undef|#
directive|undef
name|pp_egrent
end_undef

begin_define
define|#
directive|define
name|pp_egrent
value|CPerlObj::Perl_pp_egrent
end_define

begin_undef
undef|#
directive|undef
name|pp_getlogin
end_undef

begin_define
define|#
directive|define
name|pp_getlogin
value|CPerlObj::Perl_pp_getlogin
end_define

begin_undef
undef|#
directive|undef
name|pp_syscall
end_undef

begin_define
define|#
directive|define
name|pp_syscall
value|CPerlObj::Perl_pp_syscall
end_define

begin_undef
undef|#
directive|undef
name|pp_lock
end_undef

begin_define
define|#
directive|define
name|pp_lock
value|CPerlObj::Perl_pp_lock
end_define

begin_undef
undef|#
directive|undef
name|pp_threadsv
end_undef

begin_define
define|#
directive|define
name|pp_threadsv
value|CPerlObj::Perl_pp_threadsv
end_define

begin_macro
name|OP
end_macro

begin_expr_stmt
operator|*
operator|(
name|CPERLscope
argument_list|(
operator|*
name|check
argument_list|)
index|[]
operator|)
name|_
argument_list|(
operator|(
name|OP
operator|*
name|op
operator|)
argument_list|)
operator|=
block|{
name|ck_null
block|,
comment|/* null */
name|ck_null
block|,
comment|/* stub */
name|ck_fun
block|,
comment|/* scalar */
name|ck_null
block|,
comment|/* pushmark */
name|ck_null
block|,
comment|/* wantarray */
name|ck_svconst
block|,
comment|/* const */
name|ck_null
block|,
comment|/* gvsv */
name|ck_null
block|,
comment|/* gv */
name|ck_null
block|,
comment|/* gelem */
name|ck_null
block|,
comment|/* padsv */
name|ck_null
block|,
comment|/* padav */
name|ck_null
block|,
comment|/* padhv */
name|ck_null
block|,
comment|/* padany */
name|ck_null
block|,
comment|/* pushre */
name|ck_rvconst
block|,
comment|/* rv2gv */
name|ck_rvconst
block|,
comment|/* rv2sv */
name|ck_null
block|,
comment|/* av2arylen */
name|ck_rvconst
block|,
comment|/* rv2cv */
name|ck_anoncode
block|,
comment|/* anoncode */
name|ck_null
block|,
comment|/* prototype */
name|ck_spair
block|,
comment|/* refgen */
name|ck_null
block|,
comment|/* srefgen */
name|ck_fun
block|,
comment|/* ref */
name|ck_fun
block|,
comment|/* bless */
name|ck_null
block|,
comment|/* backtick */
name|ck_glob
block|,
comment|/* glob */
name|ck_null
block|,
comment|/* readline */
name|ck_null
block|,
comment|/* rcatline */
name|ck_fun
block|,
comment|/* regcmaybe */
name|ck_fun
block|,
comment|/* regcreset */
name|ck_null
block|,
comment|/* regcomp */
name|ck_match
block|,
comment|/* match */
name|ck_match
block|,
comment|/* qr */
name|ck_null
block|,
comment|/* subst */
name|ck_null
block|,
comment|/* substcont */
name|ck_null
block|,
comment|/* trans */
name|ck_null
block|,
comment|/* sassign */
name|ck_null
block|,
comment|/* aassign */
name|ck_spair
block|,
comment|/* chop */
name|ck_null
block|,
comment|/* schop */
name|ck_spair
block|,
comment|/* chomp */
name|ck_null
block|,
comment|/* schomp */
name|ck_rfun
block|,
comment|/* defined */
name|ck_lfun
block|,
comment|/* undef */
name|ck_fun
block|,
comment|/* study */
name|ck_lfun
block|,
comment|/* pos */
name|ck_lfun
block|,
comment|/* preinc */
name|ck_lfun
block|,
comment|/* i_preinc */
name|ck_lfun
block|,
comment|/* predec */
name|ck_lfun
block|,
comment|/* i_predec */
name|ck_lfun
block|,
comment|/* postinc */
name|ck_lfun
block|,
comment|/* i_postinc */
name|ck_lfun
block|,
comment|/* postdec */
name|ck_lfun
block|,
comment|/* i_postdec */
name|ck_null
block|,
comment|/* pow */
name|ck_null
block|,
comment|/* multiply */
name|ck_null
block|,
comment|/* i_multiply */
name|ck_null
block|,
comment|/* divide */
name|ck_null
block|,
comment|/* i_divide */
name|ck_null
block|,
comment|/* modulo */
name|ck_null
block|,
comment|/* i_modulo */
name|ck_repeat
block|,
comment|/* repeat */
name|ck_null
block|,
comment|/* add */
name|ck_null
block|,
comment|/* i_add */
name|ck_null
block|,
comment|/* subtract */
name|ck_null
block|,
comment|/* i_subtract */
name|ck_concat
block|,
comment|/* concat */
name|ck_fun
block|,
comment|/* stringify */
name|ck_bitop
block|,
comment|/* left_shift */
name|ck_bitop
block|,
comment|/* right_shift */
name|ck_null
block|,
comment|/* lt */
name|ck_null
block|,
comment|/* i_lt */
name|ck_null
block|,
comment|/* gt */
name|ck_null
block|,
comment|/* i_gt */
name|ck_null
block|,
comment|/* le */
name|ck_null
block|,
comment|/* i_le */
name|ck_null
block|,
comment|/* ge */
name|ck_null
block|,
comment|/* i_ge */
name|ck_null
block|,
comment|/* eq */
name|ck_null
block|,
comment|/* i_eq */
name|ck_null
block|,
comment|/* ne */
name|ck_null
block|,
comment|/* i_ne */
name|ck_null
block|,
comment|/* ncmp */
name|ck_null
block|,
comment|/* i_ncmp */
name|ck_scmp
block|,
comment|/* slt */
name|ck_scmp
block|,
comment|/* sgt */
name|ck_scmp
block|,
comment|/* sle */
name|ck_scmp
block|,
comment|/* sge */
name|ck_null
block|,
comment|/* seq */
name|ck_null
block|,
comment|/* sne */
name|ck_scmp
block|,
comment|/* scmp */
name|ck_bitop
block|,
comment|/* bit_and */
name|ck_bitop
block|,
comment|/* bit_xor */
name|ck_bitop
block|,
comment|/* bit_or */
name|ck_null
block|,
comment|/* negate */
name|ck_null
block|,
comment|/* i_negate */
name|ck_null
block|,
comment|/* not */
name|ck_bitop
block|,
comment|/* complement */
name|ck_fun
block|,
comment|/* atan2 */
name|ck_fun
block|,
comment|/* sin */
name|ck_fun
block|,
comment|/* cos */
name|ck_fun
block|,
comment|/* rand */
name|ck_fun
block|,
comment|/* srand */
name|ck_fun
block|,
comment|/* exp */
name|ck_fun
block|,
comment|/* log */
name|ck_fun
block|,
comment|/* sqrt */
name|ck_fun
block|,
comment|/* int */
name|ck_fun
block|,
comment|/* hex */
name|ck_fun
block|,
comment|/* oct */
name|ck_fun
block|,
comment|/* abs */
name|ck_lengthconst
block|,
comment|/* length */
name|ck_fun
block|,
comment|/* substr */
name|ck_fun
block|,
comment|/* vec */
name|ck_index
block|,
comment|/* index */
name|ck_index
block|,
comment|/* rindex */
name|ck_fun_locale
block|,
comment|/* sprintf */
name|ck_fun
block|,
comment|/* formline */
name|ck_fun
block|,
comment|/* ord */
name|ck_fun
block|,
comment|/* chr */
name|ck_fun
block|,
comment|/* crypt */
name|ck_fun_locale
block|,
comment|/* ucfirst */
name|ck_fun_locale
block|,
comment|/* lcfirst */
name|ck_fun_locale
block|,
comment|/* uc */
name|ck_fun_locale
block|,
comment|/* lc */
name|ck_fun
block|,
comment|/* quotemeta */
name|ck_rvconst
block|,
comment|/* rv2av */
name|ck_null
block|,
comment|/* aelemfast */
name|ck_null
block|,
comment|/* aelem */
name|ck_null
block|,
comment|/* aslice */
name|ck_fun
block|,
comment|/* each */
name|ck_fun
block|,
comment|/* values */
name|ck_fun
block|,
comment|/* keys */
name|ck_delete
block|,
comment|/* delete */
name|ck_exists
block|,
comment|/* exists */
name|ck_rvconst
block|,
comment|/* rv2hv */
name|ck_null
block|,
comment|/* helem */
name|ck_null
block|,
comment|/* hslice */
name|ck_fun
block|,
comment|/* unpack */
name|ck_fun
block|,
comment|/* pack */
name|ck_split
block|,
comment|/* split */
name|ck_fun
block|,
comment|/* join */
name|ck_null
block|,
comment|/* list */
name|ck_null
block|,
comment|/* lslice */
name|ck_fun
block|,
comment|/* anonlist */
name|ck_fun
block|,
comment|/* anonhash */
name|ck_fun
block|,
comment|/* splice */
name|ck_fun
block|,
comment|/* push */
name|ck_shift
block|,
comment|/* pop */
name|ck_shift
block|,
comment|/* shift */
name|ck_fun
block|,
comment|/* unshift */
name|ck_sort
block|,
comment|/* sort */
name|ck_fun
block|,
comment|/* reverse */
name|ck_grep
block|,
comment|/* grepstart */
name|ck_null
block|,
comment|/* grepwhile */
name|ck_grep
block|,
comment|/* mapstart */
name|ck_null
block|,
comment|/* mapwhile */
name|ck_null
block|,
comment|/* range */
name|ck_null
block|,
comment|/* flip */
name|ck_null
block|,
comment|/* flop */
name|ck_null
block|,
comment|/* and */
name|ck_null
block|,
comment|/* or */
name|ck_null
block|,
comment|/* xor */
name|ck_null
block|,
comment|/* cond_expr */
name|ck_null
block|,
comment|/* andassign */
name|ck_null
block|,
comment|/* orassign */
name|ck_null
block|,
comment|/* method */
name|ck_subr
block|,
comment|/* entersub */
name|ck_null
block|,
comment|/* leavesub */
name|ck_fun
block|,
comment|/* caller */
name|ck_fun
block|,
comment|/* warn */
name|ck_fun
block|,
comment|/* die */
name|ck_fun
block|,
comment|/* reset */
name|ck_null
block|,
comment|/* lineseq */
name|ck_null
block|,
comment|/* nextstate */
name|ck_null
block|,
comment|/* dbstate */
name|ck_null
block|,
comment|/* unstack */
name|ck_null
block|,
comment|/* enter */
name|ck_null
block|,
comment|/* leave */
name|ck_null
block|,
comment|/* scope */
name|ck_null
block|,
comment|/* enteriter */
name|ck_null
block|,
comment|/* iter */
name|ck_null
block|,
comment|/* enterloop */
name|ck_null
block|,
comment|/* leaveloop */
name|ck_null
block|,
comment|/* return */
name|ck_null
block|,
comment|/* last */
name|ck_null
block|,
comment|/* next */
name|ck_null
block|,
comment|/* redo */
name|ck_null
block|,
comment|/* dump */
name|ck_null
block|,
comment|/* goto */
name|ck_fun
block|,
comment|/* exit */
name|ck_fun
block|,
comment|/* open */
name|ck_fun
block|,
comment|/* close */
name|ck_fun
block|,
comment|/* pipe_op */
name|ck_fun
block|,
comment|/* fileno */
name|ck_fun
block|,
comment|/* umask */
name|ck_fun
block|,
comment|/* binmode */
name|ck_fun
block|,
comment|/* tie */
name|ck_fun
block|,
comment|/* untie */
name|ck_fun
block|,
comment|/* tied */
name|ck_fun
block|,
comment|/* dbmopen */
name|ck_fun
block|,
comment|/* dbmclose */
name|ck_select
block|,
comment|/* sselect */
name|ck_select
block|,
comment|/* select */
name|ck_eof
block|,
comment|/* getc */
name|ck_fun
block|,
comment|/* read */
name|ck_fun
block|,
comment|/* enterwrite */
name|ck_null
block|,
comment|/* leavewrite */
name|ck_listiob
block|,
comment|/* prtf */
name|ck_listiob
block|,
comment|/* print */
name|ck_fun
block|,
comment|/* sysopen */
name|ck_fun
block|,
comment|/* sysseek */
name|ck_fun
block|,
comment|/* sysread */
name|ck_fun
block|,
comment|/* syswrite */
name|ck_fun
block|,
comment|/* send */
name|ck_fun
block|,
comment|/* recv */
name|ck_eof
block|,
comment|/* eof */
name|ck_fun
block|,
comment|/* tell */
name|ck_fun
block|,
comment|/* seek */
name|ck_trunc
block|,
comment|/* truncate */
name|ck_fun
block|,
comment|/* fcntl */
name|ck_fun
block|,
comment|/* ioctl */
name|ck_fun
block|,
comment|/* flock */
name|ck_fun
block|,
comment|/* socket */
name|ck_fun
block|,
comment|/* sockpair */
name|ck_fun
block|,
comment|/* bind */
name|ck_fun
block|,
comment|/* connect */
name|ck_fun
block|,
comment|/* listen */
name|ck_fun
block|,
comment|/* accept */
name|ck_fun
block|,
comment|/* shutdown */
name|ck_fun
block|,
comment|/* gsockopt */
name|ck_fun
block|,
comment|/* ssockopt */
name|ck_fun
block|,
comment|/* getsockname */
name|ck_fun
block|,
comment|/* getpeername */
name|ck_ftst
block|,
comment|/* lstat */
name|ck_ftst
block|,
comment|/* stat */
name|ck_ftst
block|,
comment|/* ftrread */
name|ck_ftst
block|,
comment|/* ftrwrite */
name|ck_ftst
block|,
comment|/* ftrexec */
name|ck_ftst
block|,
comment|/* fteread */
name|ck_ftst
block|,
comment|/* ftewrite */
name|ck_ftst
block|,
comment|/* fteexec */
name|ck_ftst
block|,
comment|/* ftis */
name|ck_ftst
block|,
comment|/* fteowned */
name|ck_ftst
block|,
comment|/* ftrowned */
name|ck_ftst
block|,
comment|/* ftzero */
name|ck_ftst
block|,
comment|/* ftsize */
name|ck_ftst
block|,
comment|/* ftmtime */
name|ck_ftst
block|,
comment|/* ftatime */
name|ck_ftst
block|,
comment|/* ftctime */
name|ck_ftst
block|,
comment|/* ftsock */
name|ck_ftst
block|,
comment|/* ftchr */
name|ck_ftst
block|,
comment|/* ftblk */
name|ck_ftst
block|,
comment|/* ftfile */
name|ck_ftst
block|,
comment|/* ftdir */
name|ck_ftst
block|,
comment|/* ftpipe */
name|ck_ftst
block|,
comment|/* ftlink */
name|ck_ftst
block|,
comment|/* ftsuid */
name|ck_ftst
block|,
comment|/* ftsgid */
name|ck_ftst
block|,
comment|/* ftsvtx */
name|ck_ftst
block|,
comment|/* fttty */
name|ck_ftst
block|,
comment|/* fttext */
name|ck_ftst
block|,
comment|/* ftbinary */
name|ck_fun
block|,
comment|/* chdir */
name|ck_fun
block|,
comment|/* chown */
name|ck_fun
block|,
comment|/* chroot */
name|ck_fun
block|,
comment|/* unlink */
name|ck_fun
block|,
comment|/* chmod */
name|ck_fun
block|,
comment|/* utime */
name|ck_fun
block|,
comment|/* rename */
name|ck_fun
block|,
comment|/* link */
name|ck_fun
block|,
comment|/* symlink */
name|ck_fun
block|,
comment|/* readlink */
name|ck_fun
block|,
comment|/* mkdir */
name|ck_fun
block|,
comment|/* rmdir */
name|ck_fun
block|,
comment|/* open_dir */
name|ck_fun
block|,
comment|/* readdir */
name|ck_fun
block|,
comment|/* telldir */
name|ck_fun
block|,
comment|/* seekdir */
name|ck_fun
block|,
comment|/* rewinddir */
name|ck_fun
block|,
comment|/* closedir */
name|ck_null
block|,
comment|/* fork */
name|ck_null
block|,
comment|/* wait */
name|ck_fun
block|,
comment|/* waitpid */
name|ck_exec
block|,
comment|/* system */
name|ck_exec
block|,
comment|/* exec */
name|ck_fun
block|,
comment|/* kill */
name|ck_null
block|,
comment|/* getppid */
name|ck_fun
block|,
comment|/* getpgrp */
name|ck_fun
block|,
comment|/* setpgrp */
name|ck_fun
block|,
comment|/* getpriority */
name|ck_fun
block|,
comment|/* setpriority */
name|ck_null
block|,
comment|/* time */
name|ck_null
block|,
comment|/* tms */
name|ck_fun
block|,
comment|/* localtime */
name|ck_fun
block|,
comment|/* gmtime */
name|ck_fun
block|,
comment|/* alarm */
name|ck_fun
block|,
comment|/* sleep */
name|ck_fun
block|,
comment|/* shmget */
name|ck_fun
block|,
comment|/* shmctl */
name|ck_fun
block|,
comment|/* shmread */
name|ck_fun
block|,
comment|/* shmwrite */
name|ck_fun
block|,
comment|/* msgget */
name|ck_fun
block|,
comment|/* msgctl */
name|ck_fun
block|,
comment|/* msgsnd */
name|ck_fun
block|,
comment|/* msgrcv */
name|ck_fun
block|,
comment|/* semget */
name|ck_fun
block|,
comment|/* semctl */
name|ck_fun
block|,
comment|/* semop */
name|ck_require
block|,
comment|/* require */
name|ck_fun
block|,
comment|/* dofile */
name|ck_eval
block|,
comment|/* entereval */
name|ck_null
block|,
comment|/* leaveeval */
name|ck_null
block|,
comment|/* entertry */
name|ck_null
block|,
comment|/* leavetry */
name|ck_fun
block|,
comment|/* ghbyname */
name|ck_fun
block|,
comment|/* ghbyaddr */
name|ck_null
block|,
comment|/* ghostent */
name|ck_fun
block|,
comment|/* gnbyname */
name|ck_fun
block|,
comment|/* gnbyaddr */
name|ck_null
block|,
comment|/* gnetent */
name|ck_fun
block|,
comment|/* gpbyname */
name|ck_fun
block|,
comment|/* gpbynumber */
name|ck_null
block|,
comment|/* gprotoent */
name|ck_fun
block|,
comment|/* gsbyname */
name|ck_fun
block|,
comment|/* gsbyport */
name|ck_null
block|,
comment|/* gservent */
name|ck_fun
block|,
comment|/* shostent */
name|ck_fun
block|,
comment|/* snetent */
name|ck_fun
block|,
comment|/* sprotoent */
name|ck_fun
block|,
comment|/* sservent */
name|ck_null
block|,
comment|/* ehostent */
name|ck_null
block|,
comment|/* enetent */
name|ck_null
block|,
comment|/* eprotoent */
name|ck_null
block|,
comment|/* eservent */
name|ck_fun
block|,
comment|/* gpwnam */
name|ck_fun
block|,
comment|/* gpwuid */
name|ck_null
block|,
comment|/* gpwent */
name|ck_null
block|,
comment|/* spwent */
name|ck_null
block|,
comment|/* epwent */
name|ck_fun
block|,
comment|/* ggrnam */
name|ck_fun
block|,
comment|/* ggrgid */
name|ck_null
block|,
comment|/* ggrent */
name|ck_null
block|,
comment|/* sgrent */
name|ck_null
block|,
comment|/* egrent */
name|ck_null
block|,
comment|/* getlogin */
name|ck_fun
block|,
comment|/* syscall */
name|ck_rfun
block|,
comment|/* lock */
name|ck_null
block|,
comment|/* threadsv */
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OP
argument_list|*
operator|(
name|CPERLscope
argument_list|(
operator|*
name|ppaddr
argument_list|)
index|[]
operator|)
operator|(
name|ARGSproto
operator|)
operator|=
block|{
name|pp_null
block|,
name|pp_stub
block|,
name|pp_scalar
block|,
name|pp_pushmark
block|,
name|pp_wantarray
block|,
name|pp_const
block|,
name|pp_gvsv
block|,
name|pp_gv
block|,
name|pp_gelem
block|,
name|pp_padsv
block|,
name|pp_padav
block|,
name|pp_padhv
block|,
name|pp_padany
block|,
name|pp_pushre
block|,
name|pp_rv2gv
block|,
name|pp_rv2sv
block|,
name|pp_av2arylen
block|,
name|pp_rv2cv
block|,
name|pp_anoncode
block|,
name|pp_prototype
block|,
name|pp_refgen
block|,
name|pp_srefgen
block|,
name|pp_ref
block|,
name|pp_bless
block|,
name|pp_backtick
block|,
name|pp_glob
block|,
name|pp_readline
block|,
name|pp_rcatline
block|,
name|pp_regcmaybe
block|,
name|pp_regcreset
block|,
name|pp_regcomp
block|,
name|pp_match
block|,
name|pp_qr
block|,
name|pp_subst
block|,
name|pp_substcont
block|,
name|pp_trans
block|,
name|pp_sassign
block|,
name|pp_aassign
block|,
name|pp_chop
block|,
name|pp_schop
block|,
name|pp_chomp
block|,
name|pp_schomp
block|,
name|pp_defined
block|,
name|pp_undef
block|,
name|pp_study
block|,
name|pp_pos
block|,
name|pp_preinc
block|,
name|pp_i_preinc
block|,
name|pp_predec
block|,
name|pp_i_predec
block|,
name|pp_postinc
block|,
name|pp_i_postinc
block|,
name|pp_postdec
block|,
name|pp_i_postdec
block|,
name|pp_pow
block|,
name|pp_multiply
block|,
name|pp_i_multiply
block|,
name|pp_divide
block|,
name|pp_i_divide
block|,
name|pp_modulo
block|,
name|pp_i_modulo
block|,
name|pp_repeat
block|,
name|pp_add
block|,
name|pp_i_add
block|,
name|pp_subtract
block|,
name|pp_i_subtract
block|,
name|pp_concat
block|,
name|pp_stringify
block|,
name|pp_left_shift
block|,
name|pp_right_shift
block|,
name|pp_lt
block|,
name|pp_i_lt
block|,
name|pp_gt
block|,
name|pp_i_gt
block|,
name|pp_le
block|,
name|pp_i_le
block|,
name|pp_ge
block|,
name|pp_i_ge
block|,
name|pp_eq
block|,
name|pp_i_eq
block|,
name|pp_ne
block|,
name|pp_i_ne
block|,
name|pp_ncmp
block|,
name|pp_i_ncmp
block|,
name|pp_slt
block|,
name|pp_sgt
block|,
name|pp_sle
block|,
name|pp_sge
block|,
name|pp_seq
block|,
name|pp_sne
block|,
name|pp_scmp
block|,
name|pp_bit_and
block|,
name|pp_bit_xor
block|,
name|pp_bit_or
block|,
name|pp_negate
block|,
name|pp_i_negate
block|,
name|pp_not
block|,
name|pp_complement
block|,
name|pp_atan2
block|,
name|pp_sin
block|,
name|pp_cos
block|,
name|pp_rand
block|,
name|pp_srand
block|,
name|pp_exp
block|,
name|pp_log
block|,
name|pp_sqrt
block|,
name|pp_int
block|,
name|pp_hex
block|,
name|pp_oct
block|,
name|pp_abs
block|,
name|pp_length
block|,
name|pp_substr
block|,
name|pp_vec
block|,
name|pp_index
block|,
name|pp_rindex
block|,
name|pp_sprintf
block|,
name|pp_formline
block|,
name|pp_ord
block|,
name|pp_chr
block|,
name|pp_crypt
block|,
name|pp_ucfirst
block|,
name|pp_lcfirst
block|,
name|pp_uc
block|,
name|pp_lc
block|,
name|pp_quotemeta
block|,
name|pp_rv2av
block|,
name|pp_aelemfast
block|,
name|pp_aelem
block|,
name|pp_aslice
block|,
name|pp_each
block|,
name|pp_values
block|,
name|pp_keys
block|,
name|pp_delete
block|,
name|pp_exists
block|,
name|pp_rv2hv
block|,
name|pp_helem
block|,
name|pp_hslice
block|,
name|pp_unpack
block|,
name|pp_pack
block|,
name|pp_split
block|,
name|pp_join
block|,
name|pp_list
block|,
name|pp_lslice
block|,
name|pp_anonlist
block|,
name|pp_anonhash
block|,
name|pp_splice
block|,
name|pp_push
block|,
name|pp_pop
block|,
name|pp_shift
block|,
name|pp_unshift
block|,
name|pp_sort
block|,
name|pp_reverse
block|,
name|pp_grepstart
block|,
name|pp_grepwhile
block|,
name|pp_mapstart
block|,
name|pp_mapwhile
block|,
name|pp_range
block|,
name|pp_flip
block|,
name|pp_flop
block|,
name|pp_and
block|,
name|pp_or
block|,
name|pp_xor
block|,
name|pp_cond_expr
block|,
name|pp_andassign
block|,
name|pp_orassign
block|,
name|pp_method
block|,
name|pp_entersub
block|,
name|pp_leavesub
block|,
name|pp_caller
block|,
name|pp_warn
block|,
name|pp_die
block|,
name|pp_reset
block|,
name|pp_lineseq
block|,
name|pp_nextstate
block|,
name|pp_dbstate
block|,
name|pp_unstack
block|,
name|pp_enter
block|,
name|pp_leave
block|,
name|pp_scope
block|,
name|pp_enteriter
block|,
name|pp_iter
block|,
name|pp_enterloop
block|,
name|pp_leaveloop
block|,
name|pp_return
block|,
name|pp_last
block|,
name|pp_next
block|,
name|pp_redo
block|,
name|pp_dump
block|,
name|pp_goto
block|,
name|pp_exit
block|,
name|pp_open
block|,
name|pp_close
block|,
name|pp_pipe_op
block|,
name|pp_fileno
block|,
name|pp_umask
block|,
name|pp_binmode
block|,
name|pp_tie
block|,
name|pp_untie
block|,
name|pp_tied
block|,
name|pp_dbmopen
block|,
name|pp_dbmclose
block|,
name|pp_sselect
block|,
name|pp_select
block|,
name|pp_getc
block|,
name|pp_read
block|,
name|pp_enterwrite
block|,
name|pp_leavewrite
block|,
name|pp_prtf
block|,
name|pp_print
block|,
name|pp_sysopen
block|,
name|pp_sysseek
block|,
name|pp_sysread
block|,
name|pp_syswrite
block|,
name|pp_send
block|,
name|pp_recv
block|,
name|pp_eof
block|,
name|pp_tell
block|,
name|pp_seek
block|,
name|pp_truncate
block|,
name|pp_fcntl
block|,
name|pp_ioctl
block|,
name|pp_flock
block|,
name|pp_socket
block|,
name|pp_sockpair
block|,
name|pp_bind
block|,
name|pp_connect
block|,
name|pp_listen
block|,
name|pp_accept
block|,
name|pp_shutdown
block|,
name|pp_gsockopt
block|,
name|pp_ssockopt
block|,
name|pp_getsockname
block|,
name|pp_getpeername
block|,
name|pp_lstat
block|,
name|pp_stat
block|,
name|pp_ftrread
block|,
name|pp_ftrwrite
block|,
name|pp_ftrexec
block|,
name|pp_fteread
block|,
name|pp_ftewrite
block|,
name|pp_fteexec
block|,
name|pp_ftis
block|,
name|pp_fteowned
block|,
name|pp_ftrowned
block|,
name|pp_ftzero
block|,
name|pp_ftsize
block|,
name|pp_ftmtime
block|,
name|pp_ftatime
block|,
name|pp_ftctime
block|,
name|pp_ftsock
block|,
name|pp_ftchr
block|,
name|pp_ftblk
block|,
name|pp_ftfile
block|,
name|pp_ftdir
block|,
name|pp_ftpipe
block|,
name|pp_ftlink
block|,
name|pp_ftsuid
block|,
name|pp_ftsgid
block|,
name|pp_ftsvtx
block|,
name|pp_fttty
block|,
name|pp_fttext
block|,
name|pp_ftbinary
block|,
name|pp_chdir
block|,
name|pp_chown
block|,
name|pp_chroot
block|,
name|pp_unlink
block|,
name|pp_chmod
block|,
name|pp_utime
block|,
name|pp_rename
block|,
name|pp_link
block|,
name|pp_symlink
block|,
name|pp_readlink
block|,
name|pp_mkdir
block|,
name|pp_rmdir
block|,
name|pp_open_dir
block|,
name|pp_readdir
block|,
name|pp_telldir
block|,
name|pp_seekdir
block|,
name|pp_rewinddir
block|,
name|pp_closedir
block|,
name|pp_fork
block|,
name|pp_wait
block|,
name|pp_waitpid
block|,
name|pp_system
block|,
name|pp_exec
block|,
name|pp_kill
block|,
name|pp_getppid
block|,
name|pp_getpgrp
block|,
name|pp_setpgrp
block|,
name|pp_getpriority
block|,
name|pp_setpriority
block|,
name|pp_time
block|,
name|pp_tms
block|,
name|pp_localtime
block|,
name|pp_gmtime
block|,
name|pp_alarm
block|,
name|pp_sleep
block|,
name|pp_shmget
block|,
name|pp_shmctl
block|,
name|pp_shmread
block|,
name|pp_shmwrite
block|,
name|pp_msgget
block|,
name|pp_msgctl
block|,
name|pp_msgsnd
block|,
name|pp_msgrcv
block|,
name|pp_semget
block|,
name|pp_semctl
block|,
name|pp_semop
block|,
name|pp_require
block|,
name|pp_dofile
block|,
name|pp_entereval
block|,
name|pp_leaveeval
block|,
name|pp_entertry
block|,
name|pp_leavetry
block|,
name|pp_ghbyname
block|,
name|pp_ghbyaddr
block|,
name|pp_ghostent
block|,
name|pp_gnbyname
block|,
name|pp_gnbyaddr
block|,
name|pp_gnetent
block|,
name|pp_gpbyname
block|,
name|pp_gpbynumber
block|,
name|pp_gprotoent
block|,
name|pp_gsbyname
block|,
name|pp_gsbyport
block|,
name|pp_gservent
block|,
name|pp_shostent
block|,
name|pp_snetent
block|,
name|pp_sprotoent
block|,
name|pp_sservent
block|,
name|pp_ehostent
block|,
name|pp_enetent
block|,
name|pp_eprotoent
block|,
name|pp_eservent
block|,
name|pp_gpwnam
block|,
name|pp_gpwuid
block|,
name|pp_gpwent
block|,
name|pp_spwent
block|,
name|pp_epwent
block|,
name|pp_ggrnam
block|,
name|pp_ggrgid
block|,
name|pp_ggrent
block|,
name|pp_sgrent
block|,
name|pp_egrent
block|,
name|pp_getlogin
block|,
name|pp_syscall
block|,
name|pp_lock
block|,
name|pp_threadsv
block|, }
argument_list|;
name|int
name|fprintf
argument_list|(
argument|PerlIO *stream
argument_list|,
argument|const char *format
argument_list|,
argument|...
argument_list|)
block|{
name|va_list
argument_list|(
name|arglist
argument_list|)
block|;
name|va_start
argument_list|(
name|arglist
argument_list|,
name|format
argument_list|)
block|;
return|return
name|PerlIO_vprintf
argument_list|(
name|stream
argument_list|,
name|format
argument_list|,
name|arglist
argument_list|)
return|;
block|}
end_expr_stmt

begin_undef
undef|#
directive|undef
name|PERLVAR
end_undef

begin_define
define|#
directive|define
name|PERLVAR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_undef
undef|#
directive|undef
name|PERLVARI
end_undef

begin_define
define|#
directive|define
name|PERLVARI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|PL_##x = z;
end_define

begin_undef
undef|#
directive|undef
name|PERLVARIC
end_undef

begin_define
define|#
directive|define
name|PERLVARIC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|PL_##x = z;
end_define

begin_expr_stmt
name|CPerlObj
operator|::
name|CPerlObj
argument_list|(
argument|IPerlMem* ipM
argument_list|,
argument|IPerlEnv* ipE
argument_list|,
argument|IPerlStdIO* ipStd
argument_list|,
argument|IPerlLIO* ipLIO
argument_list|,
argument|IPerlDir* ipD
argument_list|,
argument|IPerlSock* ipS
argument_list|,
argument|IPerlProc* ipP
argument_list|)
block|{
name|memset
argument_list|(
operator|(
operator|(
name|char
operator|*
operator|)
name|this
operator|)
operator|+
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|CPerlObj
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
block|;
include|#
directive|include
file|"thrdvar.h"
include|#
directive|include
file|"intrpvar.h"
include|#
directive|include
file|"perlvars.h"
name|PL_piMem
operator|=
name|ipM
block|;
name|PL_piENV
operator|=
name|ipE
block|;
name|PL_piStdIO
operator|=
name|ipStd
block|;
name|PL_piLIO
operator|=
name|ipLIO
block|;
name|PL_piDir
operator|=
name|ipD
block|;
name|PL_piSock
operator|=
name|ipS
block|;
name|PL_piProc
operator|=
name|ipP
block|; }
name|void
operator|*
name|CPerlObj
operator|::
name|operator
name|new
argument_list|(
argument|size_t nSize
argument_list|,
argument|IPerlMem *pvtbl
argument_list|)
block|{
if|if
condition|(
name|pvtbl
operator|!=
name|NULL
condition|)
return|return
name|pvtbl
operator|->
name|Malloc
argument_list|(
name|nSize
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|NULL
return|;
end_return

begin_expr_stmt
unit|}  int
operator|&
name|CPerlObj
operator|::
name|ErrorNo
argument_list|(
argument|void
argument_list|)
block|{
return|return
name|errno
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|void
name|CPerlObj
operator|::
name|Init
argument_list|(
argument|void
argument_list|)
block|{ }
ifdef|#
directive|ifdef
name|WIN32
comment|/* XXX why are these needed? */
name|bool
name|do_exec
argument_list|(
argument|char *cmd
argument_list|)
block|{
return|return
name|PerlProc_Cmd
argument_list|(
name|cmd
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|int
name|do_aspawn
parameter_list|(
name|void
modifier|*
name|vreally
parameter_list|,
name|void
modifier|*
modifier|*
name|vmark
parameter_list|,
name|void
modifier|*
modifier|*
name|vsp
parameter_list|)
block|{
return|return
name|PerlProc_aspawn
argument_list|(
name|vreally
argument_list|,
name|vmark
argument_list|,
name|vsp
argument_list|)
return|;
block|}
end_function

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
comment|/* PERL_OBJECT */
end_comment

end_unit

