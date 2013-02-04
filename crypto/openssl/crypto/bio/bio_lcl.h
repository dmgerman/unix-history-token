begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<openssl/bio.h>
end_include

begin_if
if|#
directive|if
name|BIO_FLAGS_UPLINK
operator|==
literal|0
end_if

begin_comment
comment|/* Shortcut UPLINK calls on most platforms... */
end_comment

begin_define
define|#
directive|define
name|UP_stdin
value|stdin
end_define

begin_define
define|#
directive|define
name|UP_stdout
value|stdout
end_define

begin_define
define|#
directive|define
name|UP_stderr
value|stderr
end_define

begin_define
define|#
directive|define
name|UP_fprintf
value|fprintf
end_define

begin_define
define|#
directive|define
name|UP_fgets
value|fgets
end_define

begin_define
define|#
directive|define
name|UP_fread
value|fread
end_define

begin_define
define|#
directive|define
name|UP_fwrite
value|fwrite
end_define

begin_undef
undef|#
directive|undef
name|UP_fsetmod
end_undef

begin_define
define|#
directive|define
name|UP_feof
value|feof
end_define

begin_define
define|#
directive|define
name|UP_fclose
value|fclose
end_define

begin_define
define|#
directive|define
name|UP_fopen
value|fopen
end_define

begin_define
define|#
directive|define
name|UP_fseek
value|fseek
end_define

begin_define
define|#
directive|define
name|UP_ftell
value|ftell
end_define

begin_define
define|#
directive|define
name|UP_fflush
value|fflush
end_define

begin_define
define|#
directive|define
name|UP_ferror
value|ferror
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|UP_fileno
value|_fileno
end_define

begin_define
define|#
directive|define
name|UP_open
value|_open
end_define

begin_define
define|#
directive|define
name|UP_read
value|_read
end_define

begin_define
define|#
directive|define
name|UP_write
value|_write
end_define

begin_define
define|#
directive|define
name|UP_lseek
value|_lseek
end_define

begin_define
define|#
directive|define
name|UP_close
value|_close
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UP_fileno
value|fileno
end_define

begin_define
define|#
directive|define
name|UP_open
value|open
end_define

begin_define
define|#
directive|define
name|UP_read
value|read
end_define

begin_define
define|#
directive|define
name|UP_write
value|write
end_define

begin_define
define|#
directive|define
name|UP_lseek
value|lseek
end_define

begin_define
define|#
directive|define
name|UP_close
value|close
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

