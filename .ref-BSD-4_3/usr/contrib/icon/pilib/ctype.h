begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Macros for determining character type.  *  * The table chrtype (in char.c) classifies each character  *  in one of the categories defined below.  */
end_comment

begin_define
define|#
directive|define
name|_U
value|01
end_define

begin_comment
comment|/* upper case */
end_comment

begin_define
define|#
directive|define
name|_L
value|02
end_define

begin_comment
comment|/* lower case */
end_comment

begin_define
define|#
directive|define
name|_N
value|04
end_define

begin_comment
comment|/* digit */
end_comment

begin_define
define|#
directive|define
name|_S
value|010
end_define

begin_comment
comment|/* space */
end_comment

begin_define
define|#
directive|define
name|_P
value|020
end_define

begin_comment
comment|/* punctuation */
end_comment

begin_define
define|#
directive|define
name|_C
value|040
end_define

begin_comment
comment|/* control */
end_comment

begin_define
define|#
directive|define
name|_X
value|0100
end_define

begin_comment
comment|/* hex digit (a-f) */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ctype
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|(ctype[(c)&0377]&(_U|_L))
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|(ctype[(c)&0377]&_U)
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|(ctype[(c)&0377]&_L)
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|(ctype[(c)&0377]&_N)
end_define

begin_define
define|#
directive|define
name|isxdigit
parameter_list|(
name|c
parameter_list|)
value|(ctype[(c)&0377]&(_N|_X))
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|(ctype[(c)&0377]&_S)
end_define

begin_define
define|#
directive|define
name|ispunct
parameter_list|(
name|c
parameter_list|)
value|(ctype[(c)&0377]&_P)
end_define

begin_define
define|#
directive|define
name|isalnum
parameter_list|(
name|c
parameter_list|)
value|(ctype[(c)&0377]&(_U|_L|_N))
end_define

begin_define
define|#
directive|define
name|isprint
parameter_list|(
name|c
parameter_list|)
value|(ctype[(c)&0377]&(_P|_U|_L|_N))
end_define

begin_define
define|#
directive|define
name|iscntrl
parameter_list|(
name|c
parameter_list|)
value|(ctype[(c)&0377]&_C)
end_define

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|((unsigned)(c)<=0177)
end_define

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|(((c)&0377)-'a'+'A')
end_define

begin_define
define|#
directive|define
name|tolower
parameter_list|(
name|c
parameter_list|)
value|(((c)&0377)-'A'+'a')
end_define

begin_define
define|#
directive|define
name|toascii
parameter_list|(
name|c
parameter_list|)
value|(((c)&0177)
end_define

begin_define
define|#
directive|define
name|tonum
parameter_list|(
name|c
parameter_list|)
value|(isdigit(c)?(c)-'0':10+(((c)|(040))-'a'))
end_define

end_unit

