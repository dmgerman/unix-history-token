begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Diacritics processing for a few character codes.    Copyright (C) 1990, 1991, 1992, 1993 Free Software Foundation, Inc.    Francois Pinard<pinard@iro.umontreal.ca>, 1988.     All this file is a temporary hack, waiting for locales in GNU. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|diacrit_base
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* characters without diacritics */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|diacrit_diac
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* diacritic code for each character */
end_comment

begin_comment
comment|/* Returns CHR without its diacritic.  CHR is known to be alphabetic.  */
end_comment

begin_define
define|#
directive|define
name|tobase
parameter_list|(
name|chr
parameter_list|)
value|(diacrit_base[(unsigned char) (chr)])
end_define

begin_comment
comment|/* Returns a diacritic code for CHR.  CHR is known to be alphabetic.  */
end_comment

begin_define
define|#
directive|define
name|todiac
parameter_list|(
name|chr
parameter_list|)
value|(diacrit_diac[(unsigned char) (chr)])
end_define

end_unit

