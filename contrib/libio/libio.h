begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 92, 93, 94, 95, 97, 98 Free Software Foundation, Inc.    This file is part of the GNU IO Library.    Written by Per Bothner<bothner@cygnus.com>.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2, or (at    your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this library; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.     As a special exception, if you link this library with files    compiled with a GNU compiler to produce an executable, this does    not cause the resulting executable to be covered by the GNU General    Public License.  This exception does not however invalidate any    other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IO_STDIO_H
end_ifndef

begin_define
define|#
directive|define
name|_IO_STDIO_H
end_define

begin_include
include|#
directive|include
file|<_G_config.h>
end_include

begin_define
define|#
directive|define
name|_IO_pos_t
value|_G_fpos_t
end_define

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|_IO_fpos_t
value|_G_fpos_t
end_define

begin_define
define|#
directive|define
name|_IO_size_t
value|_G_size_t
end_define

begin_define
define|#
directive|define
name|_IO_ssize_t
value|_G_ssize_t
end_define

begin_define
define|#
directive|define
name|_IO_off_t
value|_G_off_t
end_define

begin_define
define|#
directive|define
name|_IO_pid_t
value|_G_pid_t
end_define

begin_define
define|#
directive|define
name|_IO_uid_t
value|_G_uid_t
end_define

begin_define
define|#
directive|define
name|_IO_HAVE_SYS_WAIT
value|_G_HAVE_SYS_WAIT
end_define

begin_define
define|#
directive|define
name|_IO_HAVE_ST_BLKSIZE
value|_G_HAVE_ST_BLKSIZE
end_define

begin_define
define|#
directive|define
name|_IO_BUFSIZ
value|_G_BUFSIZ
end_define

begin_define
define|#
directive|define
name|_IO_va_list
value|_G_va_list
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_G_IO_IO_FILE_VERSION
argument_list|)
operator|&&
name|_G_IO_IO_FILE_VERSION
operator|==
literal|0x20001
end_if

begin_define
define|#
directive|define
name|_IO_fpos64_t
value|_G_fpos64_t
end_define

begin_define
define|#
directive|define
name|_IO_off64_t
value|_G_off64_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_G_NEED_STDARG_H
end_ifdef

begin_comment
comment|/* This define avoids name pollution if we're using GNU stdarg.h */
end_comment

begin_define
define|#
directive|define
name|__need___va_list
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC_VA_LIST
end_ifdef

begin_undef
undef|#
directive|undef
name|_IO_va_list
end_undef

begin_define
define|#
directive|define
name|_IO_va_list
value|__gnuc_va_list
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC_VA_LIST */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_if
if|#
directive|if
name|_G_HAVE_SYS_CDEFS
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|p
parameter_list|)
value|p
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|p
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!__P*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PMT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__PMT
parameter_list|(
name|p
parameter_list|)
value|p
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__PMT
parameter_list|(
name|p
parameter_list|)
value|()
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
comment|/*!__P*/
end_comment

begin_comment
comment|/* For backward compatibility */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PARAMS
end_ifndef

begin_define
define|#
directive|define
name|_PARAMS
parameter_list|(
name|protos
parameter_list|)
value|__P(protos)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!_PARAMS*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_IO_UNIFIED_JUMPTABLES
value|1
end_define

begin_if
if|#
directive|if
operator|!
name|_G_HAVE_PRINTF_FP
end_if

begin_define
define|#
directive|define
name|_IO_USE_DTOA
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EOF
end_ifndef

begin_define
define|#
directive|define
name|EOF
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_if
if|#
directive|if
name|defined
name|__GNUG__
operator|&&
expr|\
operator|(
name|__GNUC__
operator|>
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|8
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|NULL
value|(__null)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|NULL
value|((void*)0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NULL
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_IOS_INPUT
value|1
end_define

begin_define
define|#
directive|define
name|_IOS_OUTPUT
value|2
end_define

begin_define
define|#
directive|define
name|_IOS_ATEND
value|4
end_define

begin_define
define|#
directive|define
name|_IOS_APPEND
value|8
end_define

begin_define
define|#
directive|define
name|_IOS_TRUNC
value|16
end_define

begin_define
define|#
directive|define
name|_IOS_NOCREATE
value|32
end_define

begin_define
define|#
directive|define
name|_IOS_NOREPLACE
value|64
end_define

begin_define
define|#
directive|define
name|_IOS_BIN
value|128
end_define

begin_comment
comment|/* Magic numbers and bits for the _flags field.    The magic numbers use the high-order bits of _flags;    the remaining bits are available for variable flags.    Note: The magic numbers must all be negative if stdio    emulation is desired. */
end_comment

begin_define
define|#
directive|define
name|_IO_MAGIC
value|0xFBAD0000
end_define

begin_comment
comment|/* Magic number */
end_comment

begin_define
define|#
directive|define
name|_OLD_STDIO_MAGIC
value|0xFABC0000
end_define

begin_comment
comment|/* Emulate old stdio. */
end_comment

begin_define
define|#
directive|define
name|_IO_MAGIC_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|_IO_USER_BUF
value|1
end_define

begin_comment
comment|/* User owns buffer; don't delete it on close. */
end_comment

begin_define
define|#
directive|define
name|_IO_UNBUFFERED
value|2
end_define

begin_define
define|#
directive|define
name|_IO_NO_READS
value|4
end_define

begin_comment
comment|/* Reading not allowed */
end_comment

begin_define
define|#
directive|define
name|_IO_NO_WRITES
value|8
end_define

begin_comment
comment|/* Writing not allowd */
end_comment

begin_define
define|#
directive|define
name|_IO_EOF_SEEN
value|0x10
end_define

begin_define
define|#
directive|define
name|_IO_ERR_SEEN
value|0x20
end_define

begin_define
define|#
directive|define
name|_IO_DELETE_DONT_CLOSE
value|0x40
end_define

begin_comment
comment|/* Don't call close(_fileno) on cleanup. */
end_comment

begin_define
define|#
directive|define
name|_IO_LINKED
value|0x80
end_define

begin_comment
comment|/* Set if linked (using _chain) to streambuf::_list_all.*/
end_comment

begin_define
define|#
directive|define
name|_IO_IN_BACKUP
value|0x100
end_define

begin_define
define|#
directive|define
name|_IO_LINE_BUF
value|0x200
end_define

begin_define
define|#
directive|define
name|_IO_TIED_PUT_GET
value|0x400
end_define

begin_comment
comment|/* Set if put and get pointer logicly tied. */
end_comment

begin_define
define|#
directive|define
name|_IO_CURRENTLY_PUTTING
value|0x800
end_define

begin_define
define|#
directive|define
name|_IO_IS_APPENDING
value|0x1000
end_define

begin_define
define|#
directive|define
name|_IO_IS_FILEBUF
value|0x2000
end_define

begin_define
define|#
directive|define
name|_IO_BAD_SEEN
value|0x4000
end_define

begin_define
define|#
directive|define
name|_IO_USER_LOCK
value|0x8000
end_define

begin_comment
comment|/* These are "formatting flags" matching the iostream fmtflags enum values. */
end_comment

begin_define
define|#
directive|define
name|_IO_SKIPWS
value|01
end_define

begin_define
define|#
directive|define
name|_IO_LEFT
value|02
end_define

begin_define
define|#
directive|define
name|_IO_RIGHT
value|04
end_define

begin_define
define|#
directive|define
name|_IO_INTERNAL
value|010
end_define

begin_define
define|#
directive|define
name|_IO_DEC
value|020
end_define

begin_define
define|#
directive|define
name|_IO_OCT
value|040
end_define

begin_define
define|#
directive|define
name|_IO_HEX
value|0100
end_define

begin_define
define|#
directive|define
name|_IO_SHOWBASE
value|0200
end_define

begin_define
define|#
directive|define
name|_IO_SHOWPOINT
value|0400
end_define

begin_define
define|#
directive|define
name|_IO_UPPERCASE
value|01000
end_define

begin_define
define|#
directive|define
name|_IO_SHOWPOS
value|02000
end_define

begin_define
define|#
directive|define
name|_IO_SCIENTIFIC
value|04000
end_define

begin_define
define|#
directive|define
name|_IO_FIXED
value|010000
end_define

begin_define
define|#
directive|define
name|_IO_UNITBUF
value|020000
end_define

begin_define
define|#
directive|define
name|_IO_STDIO
value|040000
end_define

begin_define
define|#
directive|define
name|_IO_DONT_CLOSE
value|0100000
end_define

begin_define
define|#
directive|define
name|_IO_BOOLALPHA
value|0200000
end_define

begin_struct_decl
struct_decl|struct
name|_IO_jump_t
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_IO_FILE
struct_decl|;
end_struct_decl

begin_comment
comment|/* Handle lock.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_IO_MTSAFE_IO
end_ifdef

begin_if
if|#
directive|if
name|defined
name|__GLIBC__
operator|&&
name|__GLIBC__
operator|>=
literal|2
end_if

begin_if
if|#
directive|if
name|__GLIBC_MINOR__
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<bits/stdio-lock.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdio-lock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_IO_LOCK_T
value|_IO_lock_t *
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*# include<comthread.h>*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|&&
name|__GLIBC__
operator|>=
literal|2
end_if

begin_typedef
typedef|typedef
name|void
name|_IO_lock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_IO_LOCK_T
value|void *
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_struct
struct|struct
name|_IO_lock_t
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|short
name|int
name|field1
decl_stmt|;
name|short
name|int
name|field2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_IO_LOCK_T
value|struct _IO_lock_t
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|void
name|_IO_lock_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A streammarker remembers a position in a buffer. */
end_comment

begin_struct
struct|struct
name|_IO_marker
block|{
name|struct
name|_IO_marker
modifier|*
name|_next
decl_stmt|;
name|struct
name|_IO_FILE
modifier|*
name|_sbuf
decl_stmt|;
comment|/* If _pos>= 0  it points to _buf->Gbase()+_pos. FIXME comment */
comment|/* if _pos< 0, it points to _buf->eBptr()+_pos. FIXME comment */
name|int
name|_pos
decl_stmt|;
if|#
directive|if
literal|0
block|void set_streampos(streampos sp) { _spos = sp; }     void set_offset(int offset) { _pos = offset; _spos = (streampos)(-2); }   public:     streammarker(streambuf *sb);     ~streammarker();     int saving() { return  _spos == -2; }     int delta(streammarker&);     int delta();
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_IO_FILE
block|{
name|int
name|_flags
decl_stmt|;
comment|/* High-order word is _IO_MAGIC; rest is flags. */
define|#
directive|define
name|_IO_file_flags
value|_flags
comment|/* The following pointers correspond to the C++ streambuf protocol. */
comment|/* Note:  Tk uses the _IO_read_ptr and _IO_read_end fields directly. */
name|char
modifier|*
name|_IO_read_ptr
decl_stmt|;
comment|/* Current read pointer */
name|char
modifier|*
name|_IO_read_end
decl_stmt|;
comment|/* End of get area. */
name|char
modifier|*
name|_IO_read_base
decl_stmt|;
comment|/* Start of putback+get area. */
name|char
modifier|*
name|_IO_write_base
decl_stmt|;
comment|/* Start of put area. */
name|char
modifier|*
name|_IO_write_ptr
decl_stmt|;
comment|/* Current put pointer. */
name|char
modifier|*
name|_IO_write_end
decl_stmt|;
comment|/* End of put area. */
name|char
modifier|*
name|_IO_buf_base
decl_stmt|;
comment|/* Start of reserve area. */
name|char
modifier|*
name|_IO_buf_end
decl_stmt|;
comment|/* End of reserve area. */
comment|/* The following fields are used to support backing up and undo. */
name|char
modifier|*
name|_IO_save_base
decl_stmt|;
comment|/* Pointer to start of non-current get area. */
name|char
modifier|*
name|_IO_backup_base
decl_stmt|;
comment|/* Pointer to first valid character of backup area */
name|char
modifier|*
name|_IO_save_end
decl_stmt|;
comment|/* Pointer to end of non-current get area. */
name|struct
name|_IO_marker
modifier|*
name|_markers
decl_stmt|;
name|struct
name|_IO_FILE
modifier|*
name|_chain
decl_stmt|;
name|int
name|_fileno
decl_stmt|;
name|int
name|_blksize
decl_stmt|;
ifdef|#
directive|ifdef
name|_G_IO_IO_FILE_VERSION
name|_IO_off_t
name|_old_offset
decl_stmt|;
else|#
directive|else
name|_IO_off_t
name|_offset
decl_stmt|;
endif|#
directive|endif
define|#
directive|define
name|__HAVE_COLUMN
comment|/* temporary */
comment|/* 1+column number of pbase(); 0 is unknown. */
name|unsigned
name|short
name|_cur_column
decl_stmt|;
name|char
name|_unused
decl_stmt|;
name|char
name|_shortbuf
index|[
literal|1
index|]
decl_stmt|;
comment|/*  char* _save_gptr;  char* _save_egptr; */
ifdef|#
directive|ifdef
name|_IO_LOCK_T
name|_IO_LOCK_T
name|_lock
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|_G_IO_IO_FILE_VERSION
argument_list|)
operator|&&
name|_G_IO_IO_FILE_VERSION
operator|==
literal|0x20001
name|_IO_off64_t
name|_offset
decl_stmt|;
name|int
name|_unused2
index|[
literal|16
index|]
decl_stmt|;
comment|/* Make sure we don't get into trouble again.  */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|_IO_FILE
name|_IO_FILE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_G_IO_IO_FILE_VERSION
argument_list|)
operator|&&
name|_G_IO_IO_FILE_VERSION
operator|==
literal|0x20001
end_if

begin_define
define|#
directive|define
name|_IO_stdin_
value|_IO_2_1_stdin_
end_define

begin_define
define|#
directive|define
name|_IO_stdout_
value|_IO_2_1_stdout_
end_define

begin_define
define|#
directive|define
name|_IO_stderr_
value|_IO_2_1_stderr_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|_IO_FILE_plus
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|_IO_FILE_plus
name|_IO_stdin_
decl_stmt|,
name|_IO_stdout_
decl_stmt|,
name|_IO_stderr_
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_IO_stdin
value|((_IO_FILE*)(&_IO_stdin_))
end_define

begin_define
define|#
directive|define
name|_IO_stdout
value|((_IO_FILE*)(&_IO_stdout_))
end_define

begin_define
define|#
directive|define
name|_IO_stderr
value|((_IO_FILE*)(&_IO_stderr_))
end_define

begin_comment
comment|/* Define the user-visible type, with user-friendly member names.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|_IO_ssize_t
argument_list|(
argument|*read
argument_list|)
name|__PMT
argument_list|(
operator|(
expr|struct
name|_IO_FILE
operator|*
operator|,
name|void
operator|*
operator|,
name|_IO_ssize_t
operator|)
argument_list|)
expr_stmt|;
name|_IO_ssize_t
argument_list|(
argument|*write
argument_list|)
name|__PMT
argument_list|(
operator|(
expr|struct
name|_IO_FILE
operator|*
operator|,
specifier|const
name|void
operator|*
operator|,
name|_IO_ssize_t
operator|)
argument_list|)
expr_stmt|;
name|_IO_off_t
argument_list|(
argument|*seek
argument_list|)
name|__PMT
argument_list|(
operator|(
expr|struct
name|_IO_FILE
operator|*
operator|,
name|_IO_off_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*close
argument_list|)
name|__PMT
argument_list|(
operator|(
expr|struct
name|_IO_FILE
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
name|_IO_cookie_io_functions_t
typedef|;
end_typedef

begin_comment
comment|/* Special file type for fopencookie function.  */
end_comment

begin_struct
struct|struct
name|_IO_cookie_file
block|{
name|struct
name|_IO_FILE
name|file
decl_stmt|;
specifier|const
name|void
modifier|*
name|vtable
decl_stmt|;
name|void
modifier|*
name|cookie
decl_stmt|;
name|_IO_cookie_io_functions_t
name|io_functions
decl_stmt|;
block|}
struct|;
end_struct

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
name|int
name|__underflow
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|__uflow
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|__overflow
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
define|#
directive|define
name|_IO_getc_unlocked
parameter_list|(
name|_fp
parameter_list|)
define|\
value|((_fp)->_IO_read_ptr>= (_fp)->_IO_read_end ? __uflow (_fp) \ 	: *(unsigned char *) (_fp)->_IO_read_ptr++)
define|#
directive|define
name|_IO_peekc_unlocked
parameter_list|(
name|_fp
parameter_list|)
define|\
value|((_fp)->_IO_read_ptr>= (_fp)->_IO_read_end \&& __underflow (_fp) == EOF ? EOF \ 	: *(unsigned char *) (_fp)->_IO_read_ptr)
define|#
directive|define
name|_IO_putc_unlocked
parameter_list|(
name|_ch
parameter_list|,
name|_fp
parameter_list|)
define|\
value|(((_fp)->_IO_write_ptr>= (_fp)->_IO_write_end) \     ? __overflow (_fp, (unsigned char) (_ch)) \     : (unsigned char) (*(_fp)->_IO_write_ptr++ = (_ch)))
define|#
directive|define
name|_IO_feof_unlocked
parameter_list|(
name|__fp
parameter_list|)
value|(((__fp)->_flags& _IO_EOF_SEEN) != 0)
define|#
directive|define
name|_IO_ferror_unlocked
parameter_list|(
name|__fp
parameter_list|)
value|(((__fp)->_flags& _IO_ERR_SEEN) != 0)
specifier|extern
name|int
name|_IO_getc
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
name|__fp
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|_IO_putc
name|__P
argument_list|(
operator|(
name|int
name|__c
operator|,
name|_IO_FILE
operator|*
name|__fp
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|_IO_feof
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
name|__fp
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|_IO_ferror
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
name|__fp
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|_IO_peekc_locked
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
name|__fp
operator|)
argument_list|)
decl_stmt|;
comment|/* This one is for Emacs. */
define|#
directive|define
name|_IO_PENDING_OUTPUT_COUNT
parameter_list|(
name|_fp
parameter_list|)
define|\
value|((_fp)->_IO_write_ptr - (_fp)->_IO_write_base)
specifier|extern
name|void
name|_IO_flockfile
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|_IO_funlockfile
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|_IO_ftrylockfile
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|_IO_MTSAFE_IO
define|#
directive|define
name|_IO_peekc
parameter_list|(
name|_fp
parameter_list|)
value|_IO_peekc_locked (_fp)
else|#
directive|else
define|#
directive|define
name|_IO_peekc
parameter_list|(
name|_fp
parameter_list|)
value|_IO_peekc_unlocked (_fp)
define|#
directive|define
name|_IO_flockfile
parameter_list|(
name|_fp
parameter_list|)
comment|/**/
define|#
directive|define
name|_IO_funlockfile
parameter_list|(
name|_fp
parameter_list|)
comment|/**/
define|#
directive|define
name|_IO_ftrylockfile
parameter_list|(
name|_fp
parameter_list|)
comment|/**/
define|#
directive|define
name|_IO_cleanup_region_start
parameter_list|(
name|_fct
parameter_list|,
name|_fp
parameter_list|)
comment|/**/
define|#
directive|define
name|_IO_cleanup_region_end
parameter_list|(
name|_Doit
parameter_list|)
comment|/**/
endif|#
directive|endif
comment|/* !_IO_MTSAFE_IO */
specifier|extern
name|int
name|_IO_vfscanf
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|_IO_va_list
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|_IO_vfprintf
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|_IO_va_list
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|_IO_ssize_t
name|_IO_padn
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|,
name|int
operator|,
name|_IO_ssize_t
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|_IO_size_t
name|_IO_sgetn
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|,
name|void
operator|*
operator|,
name|_IO_size_t
operator|)
argument_list|)
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|_G_IO_IO_FILE_VERSION
argument_list|)
operator|&&
name|_G_IO_IO_FILE_VERSION
operator|==
literal|0x20001
specifier|extern
name|_IO_off64_t
name|_IO_seekoff
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|,
name|_IO_off64_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|_IO_off64_t
name|_IO_seekpos
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|,
name|_IO_off64_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
else|#
directive|else
specifier|extern
name|_IO_off_t
name|_IO_seekoff
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|,
name|_IO_off_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|_IO_off_t
name|_IO_seekpos
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|,
name|_IO_off_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
endif|#
directive|endif
specifier|extern
name|void
name|_IO_free_backup_area
name|__P
argument_list|(
operator|(
name|_IO_FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IO_STDIO_H */
end_comment

end_unit

