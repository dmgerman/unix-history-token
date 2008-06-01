begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Implementation header for mudflap runtime library.    Mudflap: narrow-pointer bounds-checking by tree rewriting.    Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Frank Ch. Eigler<fche@redhat.com>    and Graydon Hoare<graydon@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  In addition to the permissions in the GNU General Public License, the Free Software Foundation gives you unlimited permission to link the compiled version of this file into combinations with other programs, and to distribute those combinations without any restriction coming from the use of this file.  (The General Public License restrictions do apply in other respects; for example, they cover modification of the file, and distribution when not linked into a combine executable.)  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Public libmudflap declarations -*- C -*- */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MF_RUNTIME_H
end_ifndef

begin_define
define|#
directive|define
name|MF_RUNTIME_H
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|__mf_ptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__mf_uintptr_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__pointer__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|__mf_size_t
typedef|;
end_typedef

begin_comment
comment|/* Global declarations used by instrumentation.  When _MUDFLAP is    defined, these have been auto-declared by the compiler and we    should not declare them again (ideally we *would* declare them    again, to verify that the compiler's declarations match the    library's, but the C++ front end has no mechanism for allowing    the re-definition of a structure type).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MUDFLAP
end_ifndef

begin_struct
struct|struct
name|__mf_cache
block|{
name|__mf_uintptr_t
name|low
decl_stmt|;
name|__mf_uintptr_t
name|high
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|__mf_cache
name|__mf_lookup_cache
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|__mf_uintptr_t
name|__mf_lc_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|__mf_lc_shift
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Multithreading support.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MUDFLAPTH
end_ifdef

begin_comment
comment|/* extern pthread_mutex_t __mf_biglock; */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_REENTRANT
end_ifndef

begin_define
define|#
directive|define
name|_REENTRANT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_THREAD_SAFE
end_ifndef

begin_define
define|#
directive|define
name|_THREAD_SAFE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Codes to describe the type of access to check: __mf_check arg 3 */
end_comment

begin_define
define|#
directive|define
name|__MF_CHECK_READ
value|0
end_define

begin_define
define|#
directive|define
name|__MF_CHECK_WRITE
value|1
end_define

begin_comment
comment|/* Codes to describe a region of memory being registered: __mf_*register arg 3 */
end_comment

begin_define
define|#
directive|define
name|__MF_TYPE_NOACCESS
value|0
end_define

begin_define
define|#
directive|define
name|__MF_TYPE_HEAP
value|1
end_define

begin_define
define|#
directive|define
name|__MF_TYPE_HEAP_I
value|2
end_define

begin_define
define|#
directive|define
name|__MF_TYPE_STACK
value|3
end_define

begin_define
define|#
directive|define
name|__MF_TYPE_STATIC
value|4
end_define

begin_define
define|#
directive|define
name|__MF_TYPE_GUESS
value|5
end_define

begin_comment
comment|/* The public mudflap API */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
name|void
name|__mf_check
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|__mf_size_t
name|sz
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|location
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(nothrow
block|)
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|__mf_register
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|__mf_size_t
name|sz
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(nothrow
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|__mf_unregister
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|__mf_size_t
name|sz
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(nothrow
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|unsigned
name|__mf_watch
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|__mf_size_t
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|__mf_unwatch
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|__mf_size_t
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__mf_report
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__mf_set_options
parameter_list|(
specifier|const
name|char
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Redirect some standard library functions to libmudflap.  These are    done by simple #define rather than linker wrapping, since only    instrumented modules are meant to be affected.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MUDFLAP
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|memcpy
name|__mfwrap_memcpy
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|memmove
name|__mfwrap_memmove
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|memset
name|__mfwrap_memset
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|memcmp
name|__mfwrap_memcmp
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|memchr
name|__mfwrap_memchr
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|memrchr
name|__mfwrap_memrchr
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strcpy
name|__mfwrap_strcpy
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strncpy
name|__mfwrap_strncpy
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strcat
name|__mfwrap_strcat
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strncat
name|__mfwrap_strncat
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strcmp
name|__mfwrap_strcmp
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strcasecmp
name|__mfwrap_strcasecmp
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strncmp
name|__mfwrap_strncmp
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strncasecmp
name|__mfwrap_strncasecmp
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strdup
name|__mfwrap_strdup
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strndup
name|__mfwrap_strndup
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strchr
name|__mfwrap_strchr
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strrchr
name|__mfwrap_strrchr
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strstr
name|__mfwrap_strstr
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|memmem
name|__mfwrap_memmem
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strlen
name|__mfwrap_strlen
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strnlen
name|__mfwrap_strnlen
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|bzero
name|__mfwrap_bzero
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|bcopy
name|__mfwrap_bcopy
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|bcmp
name|__mfwrap_bcmp
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|index
name|__mfwrap_index
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|rindex
name|__mfwrap_rindex
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|asctime
name|__mfwrap_asctime
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|ctime
name|__mfwrap_ctime
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|gmtime
name|__mfwrap_gmtime
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|localtime
name|__mfwrap_localtime
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|time
name|__mfwrap_time
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|strerror
name|__mfwrap_strerror
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fopen
name|__mfwrap_fopen
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fdopen
name|__mfwrap_fdopen
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|freopen
name|__mfwrap_freopen
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fclose
name|__mfwrap_fclose
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fread
name|__mfwrap_fread
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fwrite
name|__mfwrap_fwrite
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fgetc
name|__mfwrap_fgetc
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fgets
name|__mfwrap_fgets
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getc
name|__mfwrap_getc
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|gets
name|__mfwrap_gets
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|ungetc
name|__mfwrap_ungetc
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fputc
name|__mfwrap_fputc
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fputs
name|__mfwrap_fputs
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|putc
name|__mfwrap_putc
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|puts
name|__mfwrap_puts
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|clearerr
name|__mfwrap_clearerr
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|feof
name|__mfwrap_feof
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|ferror
name|__mfwrap_ferror
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fileno
name|__mfwrap_fileno
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|printf
name|__mfwrap_printf
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fprintf
name|__mfwrap_fprintf
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|sprintf
name|__mfwrap_sprintf
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|snprintf
name|__mfwrap_snprintf
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|vprintf
name|__mfwrap_vprintf
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|vfprintf
name|__mfwrap_vfprintf
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|vsprintf
name|__mfwrap_vsprintf
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|vsnprintf
name|__mfwrap_vsnprintf
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|access
name|__mfwrap_access
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|remove
name|__mfwrap_remove
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fflush
name|__mfwrap_fflush
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fseek
name|__mfwrap_fseek
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|ftell
name|__mfwrap_ftell
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|rewind
name|__mfwrap_rewind
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fgetpos
name|__mfwrap_fgetpos
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fsetpos
name|__mfwrap_fsetpos
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|stat
name|__mfwrap_stat
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fstat
name|__mfwrap_fstat
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|lstat
name|__mfwrap_lstat
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|mkfifo
name|__mfwrap_mkfifo
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|setvbuf
name|__mfwrap_setvbuf
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|setbuf
name|__mfwrap_setbuf
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|setbuffer
name|__mfwrap_setbuffer
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|setlinebuf
name|__mfwrap_setlinebuf
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|opendir
name|__mfwrap_opendir
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|closedir
name|__mfwrap_closedir
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|readdir
name|__mfwrap_readdir
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|recv
name|__mfwrap_recv
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|recvfrom
name|__mfwrap_recvfrom
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|recvmsg
name|__mfwrap_recvmsg
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|send
name|__mfwrap_send
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|sendto
name|__mfwrap_sendto
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|sendmsg
name|__mfwrap_sendmsg
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|setsockopt
name|__mfwrap_setsockopt
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getsockopt
name|__mfwrap_getsockopt
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|accept
name|__mfwrap_accept
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|bind
name|__mfwrap_bind
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|connect
name|__mfwrap_connect
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|gethostname
name|__mfwrap_gethostname
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|sethostname
name|__mfwrap_sethostname
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|gethostbyname
name|__mfwrap_gethostbyname
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|wait
name|__mfwrap_wait
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|waitpid
name|__mfwrap_waitpid
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|popen
name|__mfwrap_popen
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|pclose
name|__mfwrap_pclose
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|execve
name|__mfwrap_execve
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|execv
name|__mfwrap_execv
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|execvp
name|__mfwrap_execvp
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|system
name|__mfwrap_system
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|dlopen
name|__mfwrap_dlopen
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|dlerror
name|__mfwrap_dlerror
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|dlsym
name|__mfwrap_dlsym
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|dlclose
name|__mfwrap_dlclose
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fopen64
name|__mfwrap_fopen64
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|freopen64
name|__mfwrap_freopen64
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|stat64
name|__mfwrap_stat64
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|fseeko64
name|__mfwrap_fseeko64
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|ftello64
name|__mfwrap_ftello64
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|semop
name|__mfwrap_semop
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|semctl
name|__mfwrap_semctl
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|shmctl
name|__mfwrap_shmctl
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|shmat
name|__mfwrap_shmat
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|shmdt
name|__mfwrap_shmdt
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__ctype_b_loc
name|__mfwrap___ctype_b_loc
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__ctype_toupper_loc
name|__mfwrap___ctype_toupper_loc
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__ctype_tolower_loc
name|__mfwrap___ctype_tolower_loc
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getlogin
name|__mfwrap_getlogin
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|cuserid
name|__mfwrap_cuserid
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getpwnam
name|__mfwrap_getpwnam
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getpwuid
name|__mfwrap_getpwuid
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getgrnam
name|__mfwrap_getgrnam
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getgrgid
name|__mfwrap_getgrgid
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getservent
name|__mfwrap_getservent
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getservbyname
name|__mfwrap_getservbyname
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getservbyport
name|__mfwrap_getservbyport
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|gai_strerror
name|__mfwrap_gai_strerror
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getmntent
name|__mfwrap_getmntent
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|inet_ntoa
name|__mfwrap_inet_ntoa
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getprotoent
name|__mfwrap_getprotoent
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getprotobyname
name|__mfwrap_getprotobyname
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|getprotobynumber
name|__mfwrap_getprotobynumber
end_pragma

begin_comment
comment|/* Disable glibc macros.  */
end_comment

begin_define
define|#
directive|define
name|__NO_STRING_INLINES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MUDFLAP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MF_RUNTIME_H */
end_comment

end_unit

