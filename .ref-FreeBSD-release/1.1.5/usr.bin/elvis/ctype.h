begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ctype.h */
end_comment

begin_comment
comment|/* This file contains macros definitions and extern declarations for a  * version of<ctype.h> which is aware of the o_flipcase letters used in  * elvis.  *  * This file uses the "uchar" data type and "UCHAR" conversion macro which  * are defined in "config.h".  Consequently, any file that includes this  * header must include config.h first.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CT_UPPER
end_ifndef

begin_define
define|#
directive|define
name|_CT_UPPER
value|0x01
end_define

begin_define
define|#
directive|define
name|_CT_LOWER
value|0x02
end_define

begin_define
define|#
directive|define
name|_CT_SPACE
value|0x04
end_define

begin_define
define|#
directive|define
name|_CT_DIGIT
value|0x08
end_define

begin_define
define|#
directive|define
name|_CT_ALNUM
value|0x10
end_define

begin_define
define|#
directive|define
name|_CT_CNTRL
value|0x20
end_define

begin_define
define|#
directive|define
name|isalnum
parameter_list|(
name|c
parameter_list|)
value|(_ct_ctypes[UCHAR(c)]& _CT_ALNUM)
end_define

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|(_ct_ctypes[UCHAR(c)]& (_CT_LOWER|_CT_UPPER))
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|(_ct_ctypes[UCHAR(c)]& _CT_DIGIT)
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|(_ct_ctypes[UCHAR(c)]& _CT_LOWER)
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|(_ct_ctypes[UCHAR(c)]& _CT_SPACE)
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|(_ct_ctypes[UCHAR(c)]& _CT_UPPER)
end_define

begin_define
define|#
directive|define
name|iscntrl
parameter_list|(
name|c
parameter_list|)
value|(_ct_ctypes[UCHAR(c)]& _CT_CNTRL)
end_define

begin_define
define|#
directive|define
name|ispunct
parameter_list|(
name|c
parameter_list|)
value|(!_ct_ctypes[UCHAR(c)])
end_define

begin_comment
comment|/* punct = "none of the above" */
end_comment

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|(!((c)& 0x80))
end_define

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|_ct_toupper[UCHAR(c)]
end_define

begin_define
define|#
directive|define
name|tolower
parameter_list|(
name|c
parameter_list|)
value|_ct_tolower[UCHAR(c)]
end_define

begin_decl_stmt
specifier|extern
name|uchar
name|_ct_toupper
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uchar
name|_ct_tolower
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uchar
name|_ct_ctypes
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|_ct_init
parameter_list|(
comment|/* char *flipcase */
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _CT_UPPER */
end_comment

end_unit

