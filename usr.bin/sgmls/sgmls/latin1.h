begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SGML Character Use: ISO Latin 1. */
end_comment

begin_define
define|#
directive|define
name|EOFCHAR
value|'\032'
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
value|'\012'
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
value|'\011'
end_define

begin_comment
comment|/* FUNCTION: TAB (horizontal tab). */
end_comment

begin_define
define|#
directive|define
name|SPCCHAR
value|'\040'
end_define

begin_comment
comment|/* FUNCTION: SPACE (horizontal space). */
end_comment

begin_define
define|#
directive|define
name|GENRECHAR
value|'\010'
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
comment|/* These two macros are used to handle non-SGML characters. A non-SGML by character is represented by a DELNONCH character followed by SHIFTNON(original_character).  SHIFTNON must transform any character in the set 0, EOFCHAR, EOBCHAR, GENRECHAR, DELCDATA, DELSDATA, DELNONCH into a character that is not one of the set 0, EOFCHAR, EOBCHAR.  Furthermore UNSHIFTNON(SHIFTNON(c)) must be equal to c for every character c in the former set. */
end_comment

begin_comment
comment|/* This is a simple definition that works for ASCII-like character sets. */
end_comment

begin_define
define|#
directive|define
name|SHIFTNON
parameter_list|(
name|ch
parameter_list|)
value|((UNCH)(ch) | 0100)
end_define

begin_define
define|#
directive|define
name|UNSHIFTNON
parameter_list|(
name|ch
parameter_list|)
value|((UNCH)(ch)& ~0100)
end_define

begin_comment
comment|/* A canonical NONSGML character. The character number that is shunned in the reference concrete syntax and is not the number of a significant (in the reference concrete syntax) character nor one of the above characters nor 0. */
end_comment

begin_define
define|#
directive|define
name|CANON_NONSGML
value|255
end_define

begin_comment
comment|/* A canonical DATACHAR character. The character number that is not shunned in the reference concrete syntax and is not the number of a significant (in the reference concrete syntax) SGML character nor one of the above characters. */
end_comment

begin_define
define|#
directive|define
name|CANON_DATACHAR
value|254
end_define

end_unit

