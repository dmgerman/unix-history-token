begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SGML Character Use: EBCDIC */
end_comment

begin_define
define|#
directive|define
name|EOFCHAR
value|'\077'
end_define

begin_comment
comment|/* FUNCTION: EE (entity end: files). */
end_comment

begin_define
define|#
directive|define
name|EOBCHAR
value|'\034'
end_define

begin_comment
comment|/* NONCHAR: EOB (file entity: end of buffer. */
end_comment

begin_define
define|#
directive|define
name|RSCHAR
value|'\045'
end_define

begin_comment
comment|/* FUNCTION: RS (record start). */
end_comment

begin_define
define|#
directive|define
name|RECHAR
value|'\015'
end_define

begin_comment
comment|/* FUNCTION: RE (record end). */
end_comment

begin_define
define|#
directive|define
name|TABCHAR
value|'\005'
end_define

begin_comment
comment|/* FUNCTION: TAB (horizontal tab). */
end_comment

begin_define
define|#
directive|define
name|SPCCHAR
value|'\100'
end_define

begin_comment
comment|/* FUNCTION: SPACE (horizontal space). */
end_comment

begin_define
define|#
directive|define
name|GENRECHAR
value|'\026'
end_define

begin_comment
comment|/* NONCHAR: Generated RE. */
end_comment

begin_define
define|#
directive|define
name|DELCDATA
value|'\035'
end_define

begin_comment
comment|/* NONCHAR: Delimiter for CDATA entity in 				 attribute value. */
end_comment

begin_define
define|#
directive|define
name|DELSDATA
value|'\036'
end_define

begin_comment
comment|/* NONCHAR: Delimiter for SDATA entity in 				 attribute value. */
end_comment

begin_define
define|#
directive|define
name|DELNONCH
value|'\037'
end_define

begin_comment
comment|/* NONCHAR: non-SGML character prefix. */
end_comment

begin_comment
comment|/* This should work for EBCDIC.  See comment in latin1.h. */
end_comment

begin_define
define|#
directive|define
name|SHIFTNON
parameter_list|(
name|ch
parameter_list|)
value|((UNCH)(ch) | 0200)
end_define

begin_define
define|#
directive|define
name|UNSHIFTNON
parameter_list|(
name|ch
parameter_list|)
value|((UNCH)(ch)& ~0200)
end_define

begin_comment
comment|/* See comment in latin1.h. */
end_comment

begin_define
define|#
directive|define
name|CANON_NONSGML
value|255
end_define

begin_comment
comment|/* See comment in latin1.h. */
end_comment

begin_define
define|#
directive|define
name|CANON_DATACHAR
value|254
end_define

end_unit

