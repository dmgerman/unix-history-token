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

begin_struct
struct|struct
name|reg_data
block|{
name|U32
name|count
decl_stmt|;
name|U8
modifier|*
name|what
decl_stmt|;
name|void
modifier|*
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|reg_substr_datum
block|{
name|I32
name|min_offset
decl_stmt|;
name|I32
name|max_offset
decl_stmt|;
name|SV
modifier|*
name|substr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|reg_substr_data
block|{
name|struct
name|reg_substr_datum
name|data
index|[
literal|3
index|]
decl_stmt|;
comment|/* Actual array */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|regexp
block|{
name|I32
name|refcnt
decl_stmt|;
name|char
modifier|*
modifier|*
name|startp
decl_stmt|;
name|char
modifier|*
modifier|*
name|endp
decl_stmt|;
name|regnode
modifier|*
name|regstclass
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
name|char
modifier|*
name|precomp
decl_stmt|;
comment|/* pre-compilation regular expression */
name|char
modifier|*
name|subbase
decl_stmt|;
comment|/* saved string so \digit works forever */
name|char
modifier|*
name|subbeg
decl_stmt|;
comment|/* same, but not responsible for allocation */
name|char
modifier|*
name|subend
decl_stmt|;
comment|/* end of subbase */
name|U16
name|naughty
decl_stmt|;
comment|/* how exponential is this pattern? */
name|U16
name|reganch
decl_stmt|;
comment|/* Internal use only + 				   Tainted information used by regexec? */
if|#
directive|if
literal|0
block|SV *anchored_substr;
comment|/* Substring at fixed position wrt start. */
block|I32 anchored_offset;
comment|/* Position of it. */
block|SV *float_substr;
comment|/* Substring at variable position wrt start. */
block|I32 float_min_offset;
comment|/* Minimal position of it. */
block|I32 float_max_offset;
comment|/* Maximal position of it. */
block|SV *check_substr;
comment|/* Substring to check before matching. */
block|I32 check_offset_min;
comment|/* Offset of the above. */
block|I32 check_offset_max;
comment|/* Offset of the above. */
else|#
directive|else
name|struct
name|reg_substr_data
modifier|*
name|substrs
decl_stmt|;
endif|#
directive|endif
name|struct
name|reg_data
modifier|*
name|data
decl_stmt|;
comment|/* Additional data. */
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
name|anchored_substr
value|substrs->data[0].substr
end_define

begin_define
define|#
directive|define
name|anchored_offset
value|substrs->data[0].min_offset
end_define

begin_define
define|#
directive|define
name|float_substr
value|substrs->data[1].substr
end_define

begin_define
define|#
directive|define
name|float_min_offset
value|substrs->data[1].min_offset
end_define

begin_define
define|#
directive|define
name|float_max_offset
value|substrs->data[1].max_offset
end_define

begin_define
define|#
directive|define
name|check_substr
value|substrs->data[2].substr
end_define

begin_define
define|#
directive|define
name|check_offset_min
value|substrs->data[2].min_offset
end_define

begin_define
define|#
directive|define
name|check_offset_max
value|substrs->data[2].max_offset
end_define

begin_define
define|#
directive|define
name|ROPT_ANCH
value|(ROPT_ANCH_BOL|ROPT_ANCH_MBOL|ROPT_ANCH_GPOS)
end_define

begin_define
define|#
directive|define
name|ROPT_ANCH_SINGLE
value|(ROPT_ANCH_BOL|ROPT_ANCH_GPOS)
end_define

begin_define
define|#
directive|define
name|ROPT_ANCH_BOL
value|1
end_define

begin_define
define|#
directive|define
name|ROPT_ANCH_MBOL
value|2
end_define

begin_define
define|#
directive|define
name|ROPT_ANCH_GPOS
value|4
end_define

begin_define
define|#
directive|define
name|ROPT_SKIP
value|8
end_define

begin_define
define|#
directive|define
name|ROPT_IMPLICIT
value|0x10
end_define

begin_comment
comment|/* Converted .* to ^.* */
end_comment

begin_define
define|#
directive|define
name|ROPT_NOSCAN
value|0x20
end_define

begin_comment
comment|/* Check-string always at start. */
end_comment

begin_define
define|#
directive|define
name|ROPT_GPOS_SEEN
value|0x40
end_define

begin_define
define|#
directive|define
name|ROPT_CHECK_ALL
value|0x80
end_define

begin_define
define|#
directive|define
name|ROPT_LOOKBEHIND_SEEN
value|0x100
end_define

begin_define
define|#
directive|define
name|ROPT_EVAL_SEEN
value|0x200
end_define

begin_define
define|#
directive|define
name|ROPT_TAINTED_SEEN
value|0x400
end_define

begin_comment
comment|/* 0xf800 of reganch is used by PMf_COMPILETIME */
end_comment

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
name|REXEC_COPY_STR
value|1
end_define

begin_comment
comment|/* Need to copy the string. */
end_comment

begin_define
define|#
directive|define
name|REXEC_CHECKED
value|2
end_define

begin_comment
comment|/* check_substr already checked. */
end_comment

begin_define
define|#
directive|define
name|ReREFCNT_inc
parameter_list|(
name|re
parameter_list|)
value|((re&& re->refcnt++), re)
end_define

begin_define
define|#
directive|define
name|ReREFCNT_dec
parameter_list|(
name|re
parameter_list|)
value|pregfree(re)
end_define

end_unit

