begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    regexp.h  */
end_comment

begin_comment
comment|/*  * Definitions etc. for regexp(3) routines.  *  * Caveat:  this is V8 regexp(3) [actually, a reimplementation thereof],  * not the System V one.  */
end_comment

begin_struct
struct|struct
name|regnode
block|{
name|U8
name|flags
decl_stmt|;
name|U8
name|type
decl_stmt|;
name|U16
name|next_off
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|regnode
name|regnode
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|reg_substr_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reg_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|regexp
block|{
name|I32
modifier|*
name|startp
decl_stmt|;
name|I32
modifier|*
name|endp
decl_stmt|;
name|regnode
modifier|*
name|regstclass
decl_stmt|;
name|struct
name|reg_substr_data
modifier|*
name|substrs
decl_stmt|;
name|char
modifier|*
name|precomp
decl_stmt|;
comment|/* pre-compilation regular expression */
name|struct
name|reg_data
modifier|*
name|data
decl_stmt|;
comment|/* Additional data. */
name|char
modifier|*
name|subbeg
decl_stmt|;
comment|/* saved or original string  				   so \digit works forever. */
name|I32
name|sublen
decl_stmt|;
comment|/* Length of string pointed by subbeg */
name|I32
name|refcnt
decl_stmt|;
name|I32
name|minlen
decl_stmt|;
comment|/* mininum possible length of $& */
name|I32
name|prelen
decl_stmt|;
comment|/* length of precomp */
name|U32
name|nparens
decl_stmt|;
comment|/* number of parentheses */
name|U32
name|lastparen
decl_stmt|;
comment|/* last paren matched */
name|U32
name|reganch
decl_stmt|;
comment|/* Internal use only + 				   Tainted information used by regexec? */
name|regnode
name|program
index|[
literal|1
index|]
decl_stmt|;
comment|/* Unwarranted chumminess with compiler. */
block|}
name|regexp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ROPT_ANCH
value|(ROPT_ANCH_BOL|ROPT_ANCH_MBOL|ROPT_ANCH_GPOS|ROPT_ANCH_SBOL)
end_define

begin_define
define|#
directive|define
name|ROPT_ANCH_SINGLE
value|(ROPT_ANCH_SBOL|ROPT_ANCH_GPOS)
end_define

begin_define
define|#
directive|define
name|ROPT_ANCH_BOL
value|0x00001
end_define

begin_define
define|#
directive|define
name|ROPT_ANCH_MBOL
value|0x00002
end_define

begin_define
define|#
directive|define
name|ROPT_ANCH_SBOL
value|0x00004
end_define

begin_define
define|#
directive|define
name|ROPT_ANCH_GPOS
value|0x00008
end_define

begin_define
define|#
directive|define
name|ROPT_SKIP
value|0x00010
end_define

begin_define
define|#
directive|define
name|ROPT_IMPLICIT
value|0x00020
end_define

begin_comment
comment|/* Converted .* to ^.* */
end_comment

begin_define
define|#
directive|define
name|ROPT_NOSCAN
value|0x00040
end_define

begin_comment
comment|/* Check-string always at start. */
end_comment

begin_define
define|#
directive|define
name|ROPT_GPOS_SEEN
value|0x00080
end_define

begin_define
define|#
directive|define
name|ROPT_CHECK_ALL
value|0x00100
end_define

begin_define
define|#
directive|define
name|ROPT_LOOKBEHIND_SEEN
value|0x00200
end_define

begin_define
define|#
directive|define
name|ROPT_EVAL_SEEN
value|0x00400
end_define

begin_comment
comment|/* 0xf800 of reganch is used by PMf_COMPILETIME */
end_comment

begin_define
define|#
directive|define
name|ROPT_UTF8
value|0x10000
end_define

begin_define
define|#
directive|define
name|ROPT_NAUGHTY
value|0x20000
end_define

begin_comment
comment|/* how exponential is this pattern? */
end_comment

begin_define
define|#
directive|define
name|ROPT_COPY_DONE
value|0x40000
end_define

begin_comment
comment|/* subbeg is a copy of the string */
end_comment

begin_define
define|#
directive|define
name|ROPT_TAINTED_SEEN
value|0x80000
end_define

begin_define
define|#
directive|define
name|RE_USE_INTUIT_NOML
value|0x0100000
end_define

begin_comment
comment|/* Best to intuit before matching */
end_comment

begin_define
define|#
directive|define
name|RE_USE_INTUIT_ML
value|0x0200000
end_define

begin_define
define|#
directive|define
name|REINT_AUTORITATIVE_NOML
value|0x0400000
end_define

begin_comment
comment|/* Can trust a positive answer */
end_comment

begin_define
define|#
directive|define
name|REINT_AUTORITATIVE_ML
value|0x0800000
end_define

begin_define
define|#
directive|define
name|REINT_ONCE_NOML
value|0x1000000
end_define

begin_comment
comment|/* Intuit can succed once only. */
end_comment

begin_define
define|#
directive|define
name|REINT_ONCE_ML
value|0x2000000
end_define

begin_define
define|#
directive|define
name|RE_INTUIT_ONECHAR
value|0x4000000
end_define

begin_define
define|#
directive|define
name|RE_INTUIT_TAIL
value|0x8000000
end_define

begin_define
define|#
directive|define
name|RE_USE_INTUIT
value|(RE_USE_INTUIT_NOML|RE_USE_INTUIT_ML)
end_define

begin_define
define|#
directive|define
name|REINT_AUTORITATIVE
value|(REINT_AUTORITATIVE_NOML|REINT_AUTORITATIVE_ML)
end_define

begin_define
define|#
directive|define
name|REINT_ONCE
value|(REINT_ONCE_NOML|REINT_ONCE_ML)
end_define

begin_define
define|#
directive|define
name|RX_MATCH_TAINTED
parameter_list|(
name|prog
parameter_list|)
value|((prog)->reganch& ROPT_TAINTED_SEEN)
end_define

begin_define
define|#
directive|define
name|RX_MATCH_TAINTED_on
parameter_list|(
name|prog
parameter_list|)
value|((prog)->reganch |= ROPT_TAINTED_SEEN)
end_define

begin_define
define|#
directive|define
name|RX_MATCH_TAINTED_off
parameter_list|(
name|prog
parameter_list|)
value|((prog)->reganch&= ~ROPT_TAINTED_SEEN)
end_define

begin_define
define|#
directive|define
name|RX_MATCH_TAINTED_set
parameter_list|(
name|prog
parameter_list|,
name|t
parameter_list|)
value|((t) \ 				       ? RX_MATCH_TAINTED_on(prog) \ 				       : RX_MATCH_TAINTED_off(prog))
end_define

begin_define
define|#
directive|define
name|RX_MATCH_COPIED
parameter_list|(
name|prog
parameter_list|)
value|((prog)->reganch& ROPT_COPY_DONE)
end_define

begin_define
define|#
directive|define
name|RX_MATCH_COPIED_on
parameter_list|(
name|prog
parameter_list|)
value|((prog)->reganch |= ROPT_COPY_DONE)
end_define

begin_define
define|#
directive|define
name|RX_MATCH_COPIED_off
parameter_list|(
name|prog
parameter_list|)
value|((prog)->reganch&= ~ROPT_COPY_DONE)
end_define

begin_define
define|#
directive|define
name|RX_MATCH_COPIED_set
parameter_list|(
name|prog
parameter_list|,
name|t
parameter_list|)
value|((t) \ 					 ? RX_MATCH_COPIED_on(prog) \ 					 : RX_MATCH_COPIED_off(prog))
end_define

begin_define
define|#
directive|define
name|REXEC_COPY_STR
value|0x01
end_define

begin_comment
comment|/* Need to copy the string. */
end_comment

begin_define
define|#
directive|define
name|REXEC_CHECKED
value|0x02
end_define

begin_comment
comment|/* check_substr already checked. */
end_comment

begin_define
define|#
directive|define
name|REXEC_SCREAM
value|0x04
end_define

begin_comment
comment|/* use scream table. */
end_comment

begin_define
define|#
directive|define
name|REXEC_IGNOREPOS
value|0x08
end_define

begin_comment
comment|/* \G matches at start. */
end_comment

begin_define
define|#
directive|define
name|REXEC_NOT_FIRST
value|0x10
end_define

begin_comment
comment|/* This is another iteration of //g. */
end_comment

begin_define
define|#
directive|define
name|REXEC_ML
value|0x20
end_define

begin_comment
comment|/* $* was set. */
end_comment

begin_define
define|#
directive|define
name|ReREFCNT_inc
parameter_list|(
name|re
parameter_list|)
value|((void)(re&& re->refcnt++), re)
end_define

begin_define
define|#
directive|define
name|ReREFCNT_dec
parameter_list|(
name|re
parameter_list|)
value|CALLREGFREE(aTHX_ re)
end_define

begin_define
define|#
directive|define
name|FBMcf_TAIL_DOLLAR
value|1
end_define

begin_define
define|#
directive|define
name|FBMcf_TAIL_DOLLARM
value|2
end_define

begin_define
define|#
directive|define
name|FBMcf_TAIL_Z
value|4
end_define

begin_define
define|#
directive|define
name|FBMcf_TAIL_z
value|8
end_define

begin_define
define|#
directive|define
name|FBMcf_TAIL
value|(FBMcf_TAIL_DOLLAR|FBMcf_TAIL_DOLLARM|FBMcf_TAIL_Z|FBMcf_TAIL_z)
end_define

begin_define
define|#
directive|define
name|FBMrf_MULTILINE
value|1
end_define

begin_struct_decl
struct_decl|struct
name|re_scream_pos_data_s
struct_decl|;
end_struct_decl

end_unit

