begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** field.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	field.h,v $  * Revision 5.2  92/01/06  08:10:24  brennan  * set_binmode() proto for MSDOS  *   * Revision 5.1  91/12/05  07:59:16  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/* field.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FIELD_H
end_ifndef

begin_define
define|#
directive|define
name|FIELD_H
value|1
end_define

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|set_field0
argument_list|,
operator|(
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|split_field0
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|space_split
argument_list|,
operator|(
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|field_assign
argument_list|,
operator|(
name|CELL
operator|*
operator|,
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|PROTO
argument_list|(
name|is_string_split
argument_list|,
operator|(
name|PTR
operator|,
name|unsigned
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|slow_cell_assign
argument_list|,
operator|(
name|CELL
operator|*
operator|,
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CELL
modifier|*
name|PROTO
argument_list|(
name|slow_field_ptr
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|field_addr_to_index
argument_list|,
operator|(
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|set_binmode
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUM_PFIELDS
value|5
end_define

begin_decl_stmt
specifier|extern
name|CELL
name|field
index|[
name|FBANK_SZ
operator|+
name|NUM_PFIELDS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* $0, $1 ... $(MAX_SPLIT), NF, RS, RS, CONVFMT, OFMT */
end_comment

begin_comment
comment|/* more fields if needed go here */
end_comment

begin_decl_stmt
specifier|extern
name|CELL
modifier|*
name|fbank
index|[
name|NUM_FBANK
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fbank[0] == field */
end_comment

begin_comment
comment|/* index to CELL *  for a field */
end_comment

begin_define
define|#
directive|define
name|field_ptr
parameter_list|(
name|i
parameter_list|)
value|((i)<=MAX_SPLIT?field+(i):slow_field_ptr(i))
end_define

begin_comment
comment|/* the pseudo fields, assignment has side effects */
end_comment

begin_define
define|#
directive|define
name|NF
value|(field+MAX_SPLIT+1)
end_define

begin_comment
comment|/* must be first */
end_comment

begin_define
define|#
directive|define
name|RS
value|(field+MAX_SPLIT+2)
end_define

begin_define
define|#
directive|define
name|FS
value|(field+MAX_SPLIT+3)
end_define

begin_define
define|#
directive|define
name|CONVFMT
value|(field+MAX_SPLIT+4)
end_define

begin_define
define|#
directive|define
name|OFMT
value|(field+MAX_SPLIT+5)
end_define

begin_comment
comment|/* must be last */
end_comment

begin_define
define|#
directive|define
name|LAST_PFIELD
value|OFMT
end_define

begin_comment
comment|/* some compilers choke on (NF-field) in a case statement    even though it's constant so ... */
end_comment

begin_define
define|#
directive|define
name|NF_field
value|(MAX_SPLIT+1)
end_define

begin_define
define|#
directive|define
name|RS_field
value|(MAX_SPLIT+2)
end_define

begin_define
define|#
directive|define
name|FS_field
value|(MAX_SPLIT+3)
end_define

begin_define
define|#
directive|define
name|CONVFMT_field
value|(MAX_SPLIT+4)
end_define

begin_define
define|#
directive|define
name|OFMT_field
value|(MAX_SPLIT+5)
end_define

begin_decl_stmt
specifier|extern
name|int
name|nf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shadows NF */
end_comment

begin_comment
comment|/* a shadow type for RS and FS */
end_comment

begin_define
define|#
directive|define
name|SEP_SPACE
value|0
end_define

begin_define
define|#
directive|define
name|SEP_CHAR
value|1
end_define

begin_define
define|#
directive|define
name|SEP_STR
value|2
end_define

begin_define
define|#
directive|define
name|SEP_RE
value|3
end_define

begin_define
define|#
directive|define
name|SEP_MLR
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|type
decl_stmt|;
name|char
name|c
decl_stmt|;
name|PTR
name|ptr
decl_stmt|;
comment|/* STRING* or RE machine* */
block|}
name|SEPARATOR
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|SEPARATOR
name|rs_shadow
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CELL
name|fs_shadow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  types for splitting overflow */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|spov
block|{
name|struct
name|spov
modifier|*
name|link
decl_stmt|;
name|STRING
modifier|*
name|sval
decl_stmt|;
block|}
name|SPLIT_OV
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|SPLIT_OV
modifier|*
name|split_ov_list
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIELD_H  */
end_comment

end_unit

