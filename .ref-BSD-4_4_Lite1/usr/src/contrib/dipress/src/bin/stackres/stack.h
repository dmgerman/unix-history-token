begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985 Xerox Corp.  *  * stack.h -- elements of the RES stack.  */
end_comment

begin_comment
comment|/* stack element types */
end_comment

begin_define
define|#
directive|define
name|type_number
value|1
end_define

begin_define
define|#
directive|define
name|type_string
value|2
end_define

begin_define
define|#
directive|define
name|type_vector
value|4
end_define

begin_define
define|#
directive|define
name|type_operator
value|8
end_define

begin_define
define|#
directive|define
name|type_color
value|16
end_define

begin_define
define|#
directive|define
name|type_pixelarray
value|32
end_define

begin_define
define|#
directive|define
name|type_transformation
value|64
end_define

begin_define
define|#
directive|define
name|type_integers
value|128
end_define

begin_comment
comment|/* number sub types */
end_comment

begin_define
define|#
directive|define
name|subtype_integer
value|1
end_define

begin_define
define|#
directive|define
name|subtype_rational
value|2
end_define

begin_comment
comment|/* string sub types */
end_comment

begin_define
define|#
directive|define
name|subtype_identifier
value|4
end_define

begin_define
define|#
directive|define
name|subtype_string
value|8
end_define

begin_comment
comment|/* vector sub types */
end_comment

begin_define
define|#
directive|define
name|subtype_general
value|16
end_define

begin_define
define|#
directive|define
name|subtype_integers
value|32
end_define

begin_define
define|#
directive|define
name|subtype_samples
value|64
end_define

begin_comment
comment|/* operator sub types */
end_comment

begin_define
define|#
directive|define
name|subtype_decompressop
value|128
end_define

begin_define
define|#
directive|define
name|subtype_colorop
value|256
end_define

begin_define
define|#
directive|define
name|subtype_colormodelop
value|512
end_define

begin_comment
comment|/* color sub types */
end_comment

begin_define
define|#
directive|define
name|subtype_value
value|1024
end_define

begin_define
define|#
directive|define
name|subtype_name
value|2048
end_define

begin_define
define|#
directive|define
name|subtype_operator
value|4096
end_define

begin_extern
extern|extern stackempty(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|pop
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern push(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|duplicate
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern gettype(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern getsubtype(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern getlength(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern checktype(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|gettypename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getsubtypename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|makenumber
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern getnumlen(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|getnumber
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern getint(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|double
name|getdouble
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|getnumerator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|getdenominator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|makestring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|makeidentifier
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getstring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|makevector
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
modifier|*
name|getvector
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern getdepth(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|makeoperator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
modifier|*
name|getoperator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|makecolor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
modifier|*
name|getcolor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|makepixelarray
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|makeselect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
modifier|*
name|getpixelarray
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|maketransformation
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
modifier|*
name|gettransformation
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|makeintegers
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern getbytesPerInteger(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|long
name|getbytepos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|getbytelength
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Change Log  *  * K. Knox,          25-Mar-85 15:48:54, Created first version.  *  *  *  */
end_comment

end_unit

