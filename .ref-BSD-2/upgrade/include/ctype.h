begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|_U
value|01
end_define

begin_define
define|#
directive|define
name|_L
value|02
end_define

begin_define
define|#
directive|define
name|_A
value|03
end_define

begin_define
define|#
directive|define
name|_N
value|04
end_define

begin_define
define|#
directive|define
name|_S
value|010
end_define

begin_decl_stmt
specifier|extern
name|char
name|_ctype
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
value|(_ctype[c]&_A)
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|(_ctype[c]&_U)
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|(_ctype[c]&_L)
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|(_ctype[c]&_N)
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|(_ctype[c]&_S)
end_define

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|((c)-'a'+'A')
end_define

begin_define
define|#
directive|define
name|tolower
parameter_list|(
name|c
parameter_list|)
value|((c)-'A'+'a')
end_define

end_unit

