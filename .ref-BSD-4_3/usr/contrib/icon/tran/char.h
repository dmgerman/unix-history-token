begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Macros for determining character type.  *  * The table chrtype (in char.c) classifies each character  *  in one of the categories defined below.  */
end_comment

begin_define
define|#
directive|define
name|_S
value|01
end_define

begin_comment
comment|/* space */
end_comment

begin_define
define|#
directive|define
name|_U
value|02
end_define

begin_comment
comment|/* upper case */
end_comment

begin_define
define|#
directive|define
name|_L
value|04
end_define

begin_comment
comment|/* lower case */
end_comment

begin_define
define|#
directive|define
name|_A
value|010
end_define

begin_comment
comment|/* other alphabetic (e.g. "_") */
end_comment

begin_define
define|#
directive|define
name|_N
value|020
end_define

begin_comment
comment|/* digit */
end_comment

begin_define
define|#
directive|define
name|_UL
value|(_U | _L)
end_define

begin_comment
comment|/* letter */
end_comment

begin_define
define|#
directive|define
name|_ULA
value|(_UL | _A)
end_define

begin_comment
comment|/* alphabetic */
end_comment

begin_define
define|#
directive|define
name|_ULAN
value|(_ULA | _N)
end_define

begin_comment
comment|/* alphanumeric */
end_comment

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|(chrtype[c]& _S)
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|(chrtype[c]& _U)
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|(chrtype[c]& _L)
end_define

begin_define
define|#
directive|define
name|isletter
parameter_list|(
name|c
parameter_list|)
value|(chrtype[c]& _UL)
end_define

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|(chrtype[c]& _ULA)
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|(chrtype[c]& _N)
end_define

begin_define
define|#
directive|define
name|isalnum
parameter_list|(
name|c
parameter_list|)
value|(chrtype[c]& _ULAN)
end_define

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|(islower(c)? (c - ('a'-'A')) : c)
end_define

begin_define
define|#
directive|define
name|tolower
parameter_list|(
name|c
parameter_list|)
value|(isupper(c)? (c + ('a'-'A')) : c)
end_define

begin_define
define|#
directive|define
name|tonum
parameter_list|(
name|c
parameter_list|)
value|(isdigit(c)? (c - '0') : ((c& 037) + 9))
end_define

begin_decl_stmt
specifier|extern
name|char
name|chrtype
index|[]
decl_stmt|;
end_decl_stmt

end_unit

