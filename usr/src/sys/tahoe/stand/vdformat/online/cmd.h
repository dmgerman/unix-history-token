begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	cmd.h	1.1	86/07/05	*/
end_comment

begin_define
define|#
directive|define
name|QUIT
value|-1
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cmd_token
decl_stmt|;
name|char
modifier|*
name|cmd_text
decl_stmt|;
name|char
modifier|*
name|cmd_help
decl_stmt|;
block|}
name|cmd_text_element
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cmd_min
decl_stmt|;
name|int
name|cmd_max
decl_stmt|;
block|}
name|cmd_digit_element
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ismustmatch
parameter_list|(
name|c
parameter_list|)
value|((((c)>' ')&&((c)<'a')) || (((c)>'z')&&((c)<='~')))
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 'A')&& ((c)<= 'Z'))
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 'a')&& ((c)<= 'z'))
end_define

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|(islower(c) ? ((c)& ~040) : c)
end_define

begin_define
define|#
directive|define
name|tolower
parameter_list|(
name|c
parameter_list|)
value|(isupper(c) ? ((c) | 040) : c)
end_define

begin_define
define|#
directive|define
name|skipdigits
parameter_list|(
name|ptr
parameter_list|)
value|while(is_digit(*ptr)) ptr++
end_define

begin_define
define|#
directive|define
name|skip_junk
parameter_list|(
name|ptr
parameter_list|)
value|while(*ptr&& !is_digit(*ptr)&&\ 			    (*ptr != '-')&& (*ptr != '~')) ptr++
end_define

begin_define
define|#
directive|define
name|is_digit
parameter_list|(
name|c
parameter_list|)
value|(((c)>= '0')&& ((c)<= '9'))
end_define

begin_define
define|#
directive|define
name|finddigit
parameter_list|(
name|ptr
parameter_list|)
value|while(*ptr&& !is_digit(*ptr)) ptr++
end_define

begin_define
define|#
directive|define
name|trim_white
parameter_list|(
name|ptr
parameter_list|)
value|while((*ptr == ' ') || (*ptr == '\t')) ptr++
end_define

end_unit

