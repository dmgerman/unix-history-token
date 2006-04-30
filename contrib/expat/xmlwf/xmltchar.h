begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|XML_UNICODE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|XML_UNICODE_WCHAR_T
end_ifndef

begin_error
error|#
directive|error
error|xmlwf requires a 16-bit Unicode-compatible wchar_t
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|T
parameter_list|(
name|x
parameter_list|)
value|L ## x
end_define

begin_define
define|#
directive|define
name|ftprintf
value|fwprintf
end_define

begin_define
define|#
directive|define
name|tfopen
value|_wfopen
end_define

begin_define
define|#
directive|define
name|fputts
value|fputws
end_define

begin_define
define|#
directive|define
name|puttc
value|putwc
end_define

begin_define
define|#
directive|define
name|tcscmp
value|wcscmp
end_define

begin_define
define|#
directive|define
name|tcscpy
value|wcscpy
end_define

begin_define
define|#
directive|define
name|tcscat
value|wcscat
end_define

begin_define
define|#
directive|define
name|tcschr
value|wcschr
end_define

begin_define
define|#
directive|define
name|tcsrchr
value|wcsrchr
end_define

begin_define
define|#
directive|define
name|tcslen
value|wcslen
end_define

begin_define
define|#
directive|define
name|tperror
value|_wperror
end_define

begin_define
define|#
directive|define
name|topen
value|_wopen
end_define

begin_define
define|#
directive|define
name|tmain
value|wmain
end_define

begin_define
define|#
directive|define
name|tremove
value|_wremove
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not XML_UNICODE */
end_comment

begin_define
define|#
directive|define
name|T
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ftprintf
value|fprintf
end_define

begin_define
define|#
directive|define
name|tfopen
value|fopen
end_define

begin_define
define|#
directive|define
name|fputts
value|fputs
end_define

begin_define
define|#
directive|define
name|puttc
value|putc
end_define

begin_define
define|#
directive|define
name|tcscmp
value|strcmp
end_define

begin_define
define|#
directive|define
name|tcscpy
value|strcpy
end_define

begin_define
define|#
directive|define
name|tcscat
value|strcat
end_define

begin_define
define|#
directive|define
name|tcschr
value|strchr
end_define

begin_define
define|#
directive|define
name|tcsrchr
value|strrchr
end_define

begin_define
define|#
directive|define
name|tcslen
value|strlen
end_define

begin_define
define|#
directive|define
name|tperror
value|perror
end_define

begin_define
define|#
directive|define
name|topen
value|open
end_define

begin_define
define|#
directive|define
name|tmain
value|main
end_define

begin_define
define|#
directive|define
name|tremove
value|remove
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not XML_UNICODE */
end_comment

end_unit

