begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//    This is part of the iostream library, providing -*- C++ -*- input/output.
end_comment

begin_comment
comment|//    Copyright (C) 1991 Per Bothner.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    This library is free software; you can redistribute it and/or
end_comment

begin_comment
comment|//    modify it under the terms of the GNU Library General Public
end_comment

begin_comment
comment|//    License as published by the Free Software Foundation; either
end_comment

begin_comment
comment|//    version 2 of the License, or (at your option) any later version.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|//    but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
end_comment

begin_comment
comment|//    Library General Public License for more details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    You should have received a copy of the GNU Library General Public
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STREAMBUF_H
end_ifndef

begin_define
define|#
directive|define
name|_STREAMBUF_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #define _G_IO_THROW */
end_comment

begin_comment
comment|/* Not implemented:  ios::failure */
end_comment

begin_include
include|#
directive|include
file|<_G_config.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_G_NEED_STDARG_H
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|fpos_t
end_ifndef

begin_define
define|#
directive|define
name|fpos_t
value|_G_fpos_t
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

begin_define
define|#
directive|define
name|NULL
value|((void*)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|class
name|ostream
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|streambuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|backupbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|// In case some header files defines these as macros.
end_comment

begin_undef
undef|#
directive|undef
name|open
end_undef

begin_undef
undef|#
directive|undef
name|close
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_G_FRIEND_BUG
end_ifdef

begin_function_decl
specifier|extern
name|int
name|__UNDERFLOW
parameter_list|(
name|streambuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__OVERFLOW
parameter_list|(
name|streambuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern
literal|"C"
name|int
name|__underflow
parameter_list|(
name|streambuf
modifier|*
parameter_list|)
function_decl|;
end_extern

begin_extern
extern|extern
literal|"C"
name|int
name|__overflow
parameter_list|(
name|streambuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_extern

begin_typedef
typedef|typedef
name|_G_off_t
name|streamoff
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_G_off_t
name|streampos
typedef|;
end_typedef

begin_comment
comment|// Should perhaps be _G_fpos_t ?
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|__fmtflags
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|__iostate
typedef|;
end_typedef

begin_struct
struct|struct
name|_ios_fields
block|{
comment|// The data members of an ios.
name|streambuf
modifier|*
name|_strbuf
decl_stmt|;
name|ostream
modifier|*
name|_tie
decl_stmt|;
name|int
name|_width
decl_stmt|;
name|__fmtflags
name|_flags
decl_stmt|;
name|_G_wchar_t
name|_fill
decl_stmt|;
name|__iostate
name|_state
decl_stmt|;
name|__iostate
name|_exceptions
decl_stmt|;
name|int
name|_precision
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_IOS_GOOD
value|0
end_define

begin_define
define|#
directive|define
name|_IOS_EOF
value|1
end_define

begin_define
define|#
directive|define
name|_IOS_FAIL
value|2
end_define

begin_define
define|#
directive|define
name|_IOS_BAD
value|4
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|_STREAM_COMPAT
end_ifdef

begin_enum
enum|enum
name|state_value
block|{
name|_good
init|=
name|_IOS_GOOD
block|,
name|_eof
init|=
name|_IOS_EOF
block|,
name|_fail
init|=
name|_IOS_FAIL
block|,
name|_bad
init|=
name|_IOS_BAD
block|}
enum|;
end_enum

begin_enum
enum|enum
name|open_mode
block|{
name|input
init|=
name|_IOS_INPUT
block|,
name|output
init|=
name|_IOS_OUTPUT
block|,
name|atend
init|=
name|_IOS_ATEND
block|,
name|append
init|=
name|_IOS_APPEND
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|class
name|ios
range|:
name|public
name|_ios_fields
block|{
name|public
operator|:
typedef|typedef
name|__fmtflags
name|fmtflags
typedef|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|iostate
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|openmode
typedef|;
end_typedef

begin_enum
enum|enum
name|io_state
block|{
name|goodbit
init|=
name|_IOS_GOOD
block|,
name|eofbit
init|=
name|_IOS_EOF
block|,
name|failbit
init|=
name|_IOS_FAIL
block|,
name|badbit
init|=
name|_IOS_BAD
block|}
enum|;
end_enum

begin_enum
enum|enum
name|open_mode
block|{
name|in
init|=
name|_IOS_INPUT
block|,
name|out
init|=
name|_IOS_OUTPUT
block|,
name|ate
init|=
name|_IOS_ATEND
block|,
name|app
init|=
name|_IOS_APPEND
block|,
name|trunc
init|=
name|_IOS_TRUNC
block|,
name|nocreate
init|=
name|_IOS_NOCREATE
block|,
name|noreplace
init|=
name|_IOS_NOREPLACE
block|,
name|bin
init|=
name|_IOS_BIN
block|}
enum|;
end_enum

begin_enum
enum|enum
name|seek_dir
block|{
name|beg
block|,
name|cur
block|,
name|end
block|}
enum|;
end_enum

begin_comment
comment|// ANSI: typedef enum seek_dir seekdir; etc
end_comment

begin_enum
enum|enum
block|{
name|skipws
init|=
literal|01
block|,
name|left
init|=
literal|02
block|,
name|right
init|=
literal|04
block|,
name|internal
init|=
literal|010
block|,
name|dec
init|=
literal|020
block|,
name|oct
init|=
literal|040
block|,
name|hex
init|=
literal|0100
block|,
name|showbase
init|=
literal|0200
block|,
name|showpoint
init|=
literal|0400
block|,
name|uppercase
init|=
literal|01000
block|,
name|showpos
init|=
literal|02000
block|,
name|scientific
init|=
literal|04000
block|,
name|fixed
init|=
literal|010000
block|,
name|unitbuf
init|=
literal|020000
block|,
name|stdio
init|=
literal|040000
block|,
name|dont_close
init|=
literal|0x80000000
comment|//Don't delete streambuf on stream destruction
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|// Masks.
name|basefield
init|=
name|dec
operator|+
name|oct
operator|+
name|hex
block|,
name|floatfield
init|=
name|scientific
operator|+
name|fixed
block|,
name|adjustfield
init|=
name|left
operator|+
name|right
operator|+
name|internal
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|_G_IO_THROW
end_ifdef

begin_decl_stmt
name|class
name|failure
range|:
name|public
name|xmsg
block|{
name|ios
operator|*
name|_stream
block|;
name|public
operator|:
name|failure
argument_list|(
argument|ios* stream
argument_list|)
block|{
name|_stream
operator|=
name|stream
block|; }
name|failure
argument_list|(
argument|string cause
argument_list|,
argument|ios* stream
argument_list|)
block|{
name|_stream
operator|=
name|stream
block|; }
name|ios
operator|*
name|rdios
argument_list|()
specifier|const
block|{
return|return
name|_stream
return|;
block|}
expr|}
block|;
endif|#
directive|endif
name|ostream
operator|*
name|tie
argument_list|()
specifier|const
block|{
return|return
name|_tie
return|;
block|}
name|ostream
operator|*
name|tie
argument_list|(
argument|ostream* val
argument_list|)
block|{
name|ostream
operator|*
name|save
operator|=
name|_tie
block|;
name|_tie
operator|=
name|val
block|;
return|return
name|save
return|;
block|}
comment|// Methods to change the format state.
name|_G_wchar_t
name|fill
argument_list|()
specifier|const
block|{
return|return
operator|(
name|_G_wchar_t
operator|)
name|_fill
return|;
block|}
name|_G_wchar_t
name|fill
argument_list|(
argument|_G_wchar_t newf
argument_list|)
block|{
name|_G_wchar_t
name|oldf
operator|=
operator|(
name|_G_wchar_t
operator|)
name|_fill
block|;
name|_fill
operator|=
operator|(
name|char
operator|)
name|newf
block|;
return|return
name|oldf
return|;
block|}
name|fmtflags
name|flags
argument_list|()
specifier|const
block|{
return|return
name|_flags
return|;
block|}
name|fmtflags
name|flags
argument_list|(
argument|fmtflags new_val
argument_list|)
block|{
name|fmtflags
name|old_val
operator|=
name|_flags
block|;
name|_flags
operator|=
name|new_val
block|;
return|return
name|old_val
return|;
block|}
name|int
name|precision
argument_list|()
specifier|const
block|{
return|return
name|_precision
return|;
block|}
name|int
name|precision
argument_list|(
argument|int newp
argument_list|)
block|{
name|unsigned
name|short
name|oldp
operator|=
name|_precision
block|;
name|_precision
operator|=
operator|(
name|unsigned
name|short
operator|)
name|newp
block|;
return|return
name|oldp
return|;
block|}
name|fmtflags
name|setf
argument_list|(
argument|fmtflags val
argument_list|)
block|{
name|fmtflags
name|oldbits
operator|=
name|_flags
block|;
name|_flags
operator||=
name|val
block|;
return|return
name|oldbits
return|;
block|}
name|fmtflags
name|setf
argument_list|(
argument|fmtflags val
argument_list|,
argument|fmtflags mask
argument_list|)
block|{
name|fmtflags
name|oldbits
operator|=
name|_flags
block|;
name|_flags
operator|=
operator|(
name|_flags
operator|&
operator|~
name|mask
operator|)
operator||
operator|(
name|val
operator|&
name|mask
operator|)
block|;
return|return
name|oldbits
return|;
block|}
name|fmtflags
name|unsetf
argument_list|(
argument|fmtflags mask
argument_list|)
block|{
name|fmtflags
name|oldbits
operator|=
name|_flags
operator|&
name|mask
block|;
name|_flags
operator|&=
operator|~
name|mask
block|;
return|return
name|oldbits
return|;
block|}
name|int
name|width
argument_list|()
specifier|const
block|{
return|return
name|_width
return|;
block|}
name|int
name|width
argument_list|(
argument|int val
argument_list|)
block|{
name|int
name|save
operator|=
name|_width
block|;
name|_width
operator|=
name|val
block|;
return|return
name|save
return|;
block|}
ifdef|#
directive|ifdef
name|_G_IO_THROW
name|void
name|_throw_failure
argument_list|()
block|{
name|throw
name|new
name|ios
operator|::
name|failure
argument_list|(
name|this
argument_list|)
block|; }
else|#
directive|else
name|void
name|_throw_failure
argument_list|()
block|{ }
endif|#
directive|endif
name|streambuf
operator|*
name|rdbuf
argument_list|()
specifier|const
block|{
return|return
name|_strbuf
return|;
block|}
name|void
name|clear
argument_list|(
argument|iostate state =
literal|0
argument_list|)
block|{
name|_state
operator|=
name|_strbuf
operator|?
name|state
operator|:
name|state
operator||
name|badbit
block|;
if|if
condition|(
name|_state
operator|&
name|_exceptions
condition|)
name|_throw_failure
argument_list|()
expr_stmt|;
block|}
name|void
name|set
argument_list|(
argument|iostate flag
argument_list|)
block|{
name|_state
operator||=
name|flag
block|;
if|if
condition|(
name|_state
operator|&
name|_exceptions
condition|)
name|_throw_failure
argument_list|()
expr_stmt|;
block|}
name|int
name|good
argument_list|()
specifier|const
block|{
return|return
name|_state
operator|==
literal|0
return|;
block|}
name|int
name|eof
argument_list|()
specifier|const
block|{
return|return
name|_state
operator|&
name|ios
operator|::
name|eofbit
return|;
block|}
name|int
name|fail
argument_list|()
specifier|const
block|{
return|return
name|_state
operator|&
operator|(
name|ios
operator|::
name|badbit
operator||
name|ios
operator|::
name|failbit
operator|)
return|;
block|}
name|int
name|bad
argument_list|()
specifier|const
block|{
return|return
name|_state
operator|&
name|ios
operator|::
name|badbit
return|;
block|}
name|iostate
name|rdstate
argument_list|()
specifier|const
block|{
return|return
name|_state
return|;
block|}
name|operator
name|void
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|fail
argument_list|()
operator|?
operator|(
name|void
operator|*
operator|)
literal|0
operator|:
operator|(
name|void
operator|*
operator|)
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|int
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
name|fail
argument_list|()
return|;
block|}
name|iostate
name|exception
argument_list|(
argument|iostate enable
argument_list|)
block|{
name|iostate
name|old
operator|=
name|_exceptions
block|;
name|_exceptions
operator|=
name|enable
block|;
if|if
condition|(
name|_state
operator|&
name|_exceptions
condition|)
name|_throw_failure
argument_list|()
expr_stmt|;
return|return
name|old
return|;
block|}
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|sync_with_stdio
parameter_list|(
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|sync_with_stdio
parameter_list|()
block|{
name|sync_with_stdio
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_STREAM_COMPAT
end_ifdef

begin_function
name|void
name|unset
parameter_list|(
name|state_value
name|flag
parameter_list|)
block|{
name|_state
operator|&=
operator|~
name|flag
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|writable
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|ios
argument_list|(
name|streambuf
operator|*
name|sb
operator|=
literal|0
argument_list|,
name|ostream
operator|*
name|tie
operator|=
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
operator|~
name|ios
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|init
parameter_list|(
name|streambuf
modifier|*
name|sb
parameter_list|)
block|{
name|_state
operator|=
literal|0
expr_stmt|;
name|_strbuf
operator|=
name|sb
expr_stmt|;
block|}
end_function

begin_if
unit|};
if|#
directive|if
name|__GNUG__
operator|==
literal|1
end_if

begin_typedef
typedef|typedef
name|int
name|_seek_dir
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|ios
operator|::
name|seek_dir
name|_seek_dir
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Magic numbers and bits for the _flags field.
end_comment

begin_comment
comment|// The magic numbers use the high-order bits of _flags;
end_comment

begin_comment
comment|// the remaining bits are abailable for variable flags.
end_comment

begin_comment
comment|// Note: The magic numbers must all be negative if stdio
end_comment

begin_comment
comment|// emulation is desired.
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
name|_S_USER_BUF
value|1
end_define

begin_comment
comment|/* User owns buffer; don't delete it on close. */
end_comment

begin_define
define|#
directive|define
name|_S_UNBUFFERED
value|2
end_define

begin_define
define|#
directive|define
name|_S_NO_READS
value|4
end_define

begin_comment
comment|/* Reading not allowed */
end_comment

begin_define
define|#
directive|define
name|_S_NO_WRITES
value|8
end_define

begin_comment
comment|/* Writing not allowd */
end_comment

begin_define
define|#
directive|define
name|_S_EOF_SEEN
value|0x10
end_define

begin_define
define|#
directive|define
name|_S_ERR_SEEN
value|0x20
end_define

begin_define
define|#
directive|define
name|_S_DELETE_DONT_CLOSE
value|0x40
end_define

begin_define
define|#
directive|define
name|_S_LINKED
value|0x80
end_define

begin_comment
comment|// Set if linked (using _chain) to streambuf::_list_all.
end_comment

begin_define
define|#
directive|define
name|_S_IN_BACKUP
value|0x100
end_define

begin_define
define|#
directive|define
name|_S_LINE_BUF
value|0x200
end_define

begin_define
define|#
directive|define
name|_S_TIED_PUT_GET
value|0x400
end_define

begin_comment
comment|// Set if put and get pointer logicly tied.
end_comment

begin_define
define|#
directive|define
name|_S_CURRENTLY_PUTTING
value|0x800
end_define

begin_define
define|#
directive|define
name|_S_IS_APPENDING
value|0x1000
end_define

begin_define
define|#
directive|define
name|_S_IS_BACKUPBUF
value|0x4000
end_define

begin_define
define|#
directive|define
name|_S_IS_FILEBUF
value|0x8000
end_define

begin_comment
comment|// A streammarker remembers a position in a buffer.
end_comment

begin_comment
comment|// You are guaranteed to be able to seek back to it if it is saving().
end_comment

begin_decl_stmt
name|class
name|streammarker
block|{
name|friend
name|class
name|streambuf
decl_stmt|;
ifdef|#
directive|ifdef
name|_G_FRIEND_BUG
name|friend
name|int
name|__UNDERFLOW
parameter_list|(
name|streambuf
modifier|*
parameter_list|)
function_decl|;
else|#
directive|else
name|friend
name|int
name|__underflow
parameter_list|(
name|streambuf
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
name|struct
name|streammarker
modifier|*
name|_next
decl_stmt|;
comment|// Only if saving()
name|streambuf
modifier|*
name|_sbuf
decl_stmt|;
comment|// Only valid if saving().
name|streampos
name|_spos
decl_stmt|;
comment|// -2: means that _pos is valid.
name|void
name|set_streampos
parameter_list|(
name|streampos
name|sp
parameter_list|)
block|{
name|_spos
operator|=
name|sp
expr_stmt|;
block|}
name|void
name|set_offset
parameter_list|(
name|int
name|offset
parameter_list|)
block|{
name|_pos
operator|=
name|offset
expr_stmt|;
name|_spos
operator|=
call|(
name|streampos
call|)
argument_list|(
operator|-
literal|2
argument_list|)
expr_stmt|;
block|}
comment|// If _pos>= 0, it points to _buf->Gbase()+_pos.
comment|// if _pos< 0, it points to _buf->eBptr()+_pos.
name|int
name|_pos
decl_stmt|;
name|public
label|:
name|streammarker
argument_list|(
name|streambuf
operator|*
name|sb
argument_list|)
expr_stmt|;
operator|~
name|streammarker
argument_list|()
expr_stmt|;
name|int
name|saving
parameter_list|()
block|{
return|return
name|_spos
operator|==
operator|-
literal|2
return|;
block|}
name|int
name|delta
parameter_list|(
name|streammarker
modifier|&
parameter_list|)
function_decl|;
name|int
name|delta
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|__streambuf
block|{
comment|// NOTE: If this is changed, also change __FILE in stdio/stdio.h!
name|int
name|_flags
decl_stmt|;
comment|/* High-order word is _IO_MAGIC; rest is flags. */
name|char
modifier|*
name|_gptr
decl_stmt|;
comment|/* Current get pointer */
name|char
modifier|*
name|_egptr
decl_stmt|;
comment|/* End of get area. */
name|char
modifier|*
name|_eback
decl_stmt|;
comment|/* Start of putback+get area. */
name|char
modifier|*
name|_pbase
decl_stmt|;
comment|/* Start of put area. */
name|char
modifier|*
name|_pptr
decl_stmt|;
comment|/* Current put pointer. */
name|char
modifier|*
name|_epptr
decl_stmt|;
comment|/* End of put area. */
name|char
modifier|*
name|_base
decl_stmt|;
comment|/* Start of reserve area. */
name|char
modifier|*
name|_ebuf
decl_stmt|;
comment|/* End of reserve area. */
name|struct
name|streambuf
modifier|*
name|_chain
decl_stmt|;
comment|// The following fields are used to support backing up and undo.
name|friend
name|class
name|streammarker
decl_stmt|;
name|char
modifier|*
name|_other_gbase
decl_stmt|;
comment|// Pointer to start of non-current get area.
name|char
modifier|*
name|_aux_limit
decl_stmt|;
comment|// Pointer to first valid character of backup area,
name|char
modifier|*
name|_other_egptr
decl_stmt|;
comment|// Pointer to end of non-current get area.
name|streammarker
modifier|*
name|_markers
decl_stmt|;
define|#
directive|define
name|__HAVE_COLUMN
comment|/* temporary */
comment|// 1+column number of pbase(); 0 is unknown.
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
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|unsigned
name|__adjust_column
parameter_list|(
name|unsigned
name|start
parameter_list|,
specifier|const
name|char
modifier|*
name|line
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|streambuf
range|:
name|private
name|__streambuf
block|{
name|friend
name|class
name|ios
block|;
name|friend
name|class
name|istream
block|;
name|friend
name|class
name|ostream
block|;
name|friend
name|class
name|streammarker
block|;
ifdef|#
directive|ifdef
name|_G_FRIEND_BUG
name|friend
name|int
name|__UNDERFLOW
argument_list|(
name|streambuf
operator|*
argument_list|)
block|;
else|#
directive|else
name|friend
name|int
name|__underflow
argument_list|(
name|streambuf
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|protected
operator|:
specifier|static
name|streambuf
operator|*
name|_list_all
block|;
comment|/* List of open streambufs. */
name|streambuf
operator|*
operator|&
name|xchain
argument_list|()
block|{
return|return
name|_chain
return|;
block|}
name|void
name|_un_link
argument_list|()
block|;
name|void
name|_link_in
argument_list|()
block|;
name|char
operator|*
name|gptr
argument_list|()
specifier|const
block|{
return|return
name|_gptr
return|;
block|}
name|char
operator|*
name|pptr
argument_list|()
specifier|const
block|{
return|return
name|_pptr
return|;
block|}
name|char
operator|*
name|egptr
argument_list|()
specifier|const
block|{
return|return
name|_egptr
return|;
block|}
name|char
operator|*
name|epptr
argument_list|()
specifier|const
block|{
return|return
name|_epptr
return|;
block|}
name|char
operator|*
name|pbase
argument_list|()
specifier|const
block|{
return|return
name|_pbase
return|;
block|}
name|char
operator|*
name|eback
argument_list|()
specifier|const
block|{
return|return
name|_eback
return|;
block|}
name|char
operator|*
name|base
argument_list|()
specifier|const
block|{
return|return
name|_base
return|;
block|}
name|char
operator|*
name|ebuf
argument_list|()
specifier|const
block|{
return|return
name|_ebuf
return|;
block|}
name|int
name|blen
argument_list|()
specifier|const
block|{
return|return
name|_ebuf
operator|-
name|_base
return|;
block|}
name|void
name|xput_char
argument_list|(
argument|char c
argument_list|)
block|{
operator|*
name|_pptr
operator|++
operator|=
name|c
block|; }
name|int
name|xflags
argument_list|()
block|{
return|return
name|_flags
return|;
block|}
name|int
name|xflags
argument_list|(
argument|int f
argument_list|)
block|{
name|int
name|fl
operator|=
name|_flags
block|;
name|_flags
operator|=
name|f
block|;
return|return
name|fl
return|;
block|}
name|void
name|xsetflags
argument_list|(
argument|int f
argument_list|)
block|{
name|_flags
operator||=
name|f
block|; }
name|void
name|xsetflags
argument_list|(
argument|int f
argument_list|,
argument|int mask
argument_list|)
block|{
name|_flags
operator|=
operator|(
name|_flags
operator|&
operator|~
name|mask
operator|)
operator||
operator|(
name|f
operator|&
name|mask
operator|)
block|; }
name|void
name|gbump
argument_list|(
argument|int n
argument_list|)
block|{
name|_gptr
operator|+=
name|n
block|; }
name|void
name|pbump
argument_list|(
argument|int n
argument_list|)
block|{
name|_pptr
operator|+=
name|n
block|; }
name|void
name|setb
argument_list|(
argument|char* b
argument_list|,
argument|char* eb
argument_list|,
argument|int a=
literal|0
argument_list|)
block|;
name|void
name|setp
argument_list|(
argument|char* p
argument_list|,
argument|char* ep
argument_list|)
block|{
name|_pbase
operator|=
name|_pptr
operator|=
name|p
block|;
name|_epptr
operator|=
name|ep
block|; }
name|void
name|setg
argument_list|(
argument|char* eb
argument_list|,
argument|char* g
argument_list|,
argument|char *eg
argument_list|)
block|{
name|_eback
operator|=
name|eb
block|;
name|_gptr
operator|=
name|g
block|;
name|_egptr
operator|=
name|eg
block|; }
name|char
operator|*
name|shortbuf
argument_list|()
block|{
return|return
name|_shortbuf
return|;
block|}
name|int
name|in_backup
argument_list|()
block|{
return|return
name|_flags
operator|&
name|_S_IN_BACKUP
return|;
block|}
comment|// The start of the main get area:  FIXME:  wrong for write-mode filebuf?
name|char
operator|*
name|Gbase
argument_list|()
block|{
return|return
name|in_backup
argument_list|()
operator|?
name|_other_gbase
operator|:
name|_eback
return|;
block|}
comment|// The end of the main get area:
name|char
operator|*
name|eGptr
argument_list|()
block|{
return|return
name|in_backup
argument_list|()
condition|?
name|_other_egptr
else|:
name|_egptr
return|;
block|}
comment|// The start of the backup area:
name|char
operator|*
name|Bbase
argument_list|()
block|{
return|return
name|in_backup
argument_list|()
condition|?
name|_eback
else|:
name|_other_gbase
return|;
block|}
name|char
operator|*
name|Bptr
argument_list|()
block|{
return|return
name|_aux_limit
return|;
block|}
comment|// The end of the backup area:
name|char
operator|*
name|eBptr
argument_list|()
block|{
return|return
name|in_backup
argument_list|()
condition|?
name|_egptr
else|:
name|_other_egptr
return|;
block|}
name|char
operator|*
name|Nbase
argument_list|()
block|{
return|return
name|_other_gbase
return|;
block|}
name|char
operator|*
name|eNptr
argument_list|()
block|{
return|return
name|_other_egptr
return|;
block|}
name|int
name|have_backup
argument_list|()
block|{
return|return
name|_other_gbase
operator|!=
name|NULL
return|;
block|}
name|int
name|have_markers
argument_list|()
block|{
return|return
name|_markers
operator|!=
name|NULL
return|;
block|}
name|int
name|_least_marker
argument_list|()
block|;
name|void
name|switch_to_main_get_area
argument_list|()
block|;
name|void
name|switch_to_backup_area
argument_list|()
block|;
name|void
name|free_backup_area
argument_list|()
block|;
name|void
name|unsave_markers
argument_list|()
block|;
comment|// Make all streammarkers !saving().
name|int
name|put_mode
argument_list|()
block|{
return|return
name|_flags
operator|&
name|_S_CURRENTLY_PUTTING
return|;
block|}
name|int
name|switch_to_get_mode
argument_list|()
block|;
name|streambuf
argument_list|(
argument|int flags=
literal|0
argument_list|)
block|;
name|public
operator|:
specifier|static
name|int
name|flush_all
argument_list|()
block|;
specifier|static
name|void
name|flush_all_linebuffered
argument_list|()
block|;
comment|// Flush all line buffered files.
name|virtual
name|int
name|underflow
argument_list|()
operator|=
literal|0
block|;
comment|// Leave public for now
name|virtual
name|int
name|overflow
argument_list|(
argument|int c = EOF
argument_list|)
operator|=
literal|0
block|;
comment|// Leave public for now
name|virtual
name|int
name|doallocate
argument_list|()
block|;
name|virtual
name|streampos
name|seekoff
argument_list|(
argument|streamoff
argument_list|,
argument|_seek_dir
argument_list|,
argument|int mode=ios::in|ios::out
argument_list|)
block|;
name|virtual
name|streampos
name|seekpos
argument_list|(
argument|streampos pos
argument_list|,
argument|int mode = ios::in|ios::out
argument_list|)
block|;
name|int
name|seekmark
argument_list|(
argument|streammarker& mark
argument_list|,
argument|int delta =
literal|0
argument_list|)
block|;
name|int
name|sputbackc
argument_list|(
argument|char c
argument_list|)
block|;
name|int
name|sungetc
argument_list|()
block|;
name|virtual
operator|~
name|streambuf
argument_list|()
block|;
name|int
name|unbuffered
argument_list|()
block|{
return|return
name|_flags
operator|&
name|_S_UNBUFFERED
condition|?
literal|1
else|:
literal|0
return|;
block|}
name|int
name|linebuffered
argument_list|()
block|{
return|return
name|_flags
operator|&
name|_S_LINE_BUF
condition|?
literal|1
else|:
literal|0
return|;
block|}
name|void
name|unbuffered
argument_list|(
argument|int i
argument_list|)
block|{
if|if
condition|(
name|i
condition|)
name|_flags
operator||=
name|_S_UNBUFFERED
expr_stmt|;
else|else
name|_flags
operator|&=
operator|~
name|_S_UNBUFFERED
expr_stmt|;
block|}
name|void
name|linebuffered
argument_list|(
argument|int i
argument_list|)
block|{
if|if
condition|(
name|i
condition|)
name|_flags
operator||=
name|_S_LINE_BUF
expr_stmt|;
else|else
name|_flags
operator|&=
operator|~
name|_S_LINE_BUF
expr_stmt|;
block|}
name|int
name|allocate
argument_list|()
block|{
comment|// For AT&T compatibility
if|if
condition|(
name|base
argument_list|()
operator|||
name|unbuffered
argument_list|()
condition|)
return|return
literal|0
return|;
else|else
return|return
name|doallocate
argument_list|()
return|;
block|}
comment|// Allocate a buffer if needed; use _shortbuf if appropriate.
name|void
name|allocbuf
argument_list|()
block|{
if|if
condition|(
name|base
argument_list|()
operator|==
name|NULL
condition|)
name|doallocbuf
argument_list|()
expr_stmt|;
block|}
name|void
name|doallocbuf
argument_list|()
block|;
name|virtual
name|int
name|sync
argument_list|()
block|;
name|virtual
name|int
name|pbackfail
argument_list|(
argument|int c
argument_list|)
block|;
name|virtual
name|streambuf
operator|*
name|setbuf
argument_list|(
argument|char* p
argument_list|,
argument|int len
argument_list|)
block|;
name|int
name|in_avail
argument_list|()
block|{
return|return
name|_egptr
operator|-
name|_gptr
return|;
block|}
name|int
name|out_waiting
argument_list|()
block|{
return|return
name|_pptr
operator|-
name|_pbase
return|;
block|}
name|virtual
name|int
name|xsputn
argument_list|(
argument|const char* s
argument_list|,
argument|int n
argument_list|)
block|;
name|int
name|sputn
argument_list|(
argument|const char* s
argument_list|,
argument|int n
argument_list|)
block|{
return|return
name|xsputn
argument_list|(
name|s
argument_list|,
name|n
argument_list|)
return|;
block|}
name|int
name|padn
argument_list|(
argument|char pad
argument_list|,
argument|int n
argument_list|)
block|;
comment|// Emit 'n' copies of 'pad'.
name|virtual
name|int
name|xsgetn
argument_list|(
argument|char* s
argument_list|,
argument|int n
argument_list|)
block|;
name|int
name|sgetn
argument_list|(
argument|char* s
argument_list|,
argument|int n
argument_list|)
block|{
return|return
name|xsgetn
argument_list|(
name|s
argument_list|,
name|n
argument_list|)
return|;
block|}
name|int
name|ignore
argument_list|(
name|int
argument_list|)
block|;
name|virtual
name|int
name|get_column
argument_list|()
block|;
name|virtual
name|int
name|set_column
argument_list|(
name|int
argument_list|)
block|;
name|long
name|sgetline
argument_list|(
argument|char* buf
argument_list|,
argument|_G_size_t n
argument_list|,
argument|char delim
argument_list|,
argument|int putback_delim
argument_list|)
block|;
name|int
name|sbumpc
argument_list|()
block|{
if|if
condition|(
name|_gptr
operator|>=
name|_egptr
operator|&&
name|__underflow
argument_list|(
name|this
argument_list|)
operator|==
name|EOF
condition|)
return|return
name|EOF
return|;
else|else
return|return
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
name|_gptr
operator|++
return|;
block|}
name|int
name|sgetc
argument_list|()
block|{
if|if
condition|(
name|_gptr
operator|>=
name|_egptr
operator|&&
name|__underflow
argument_list|(
name|this
argument_list|)
operator|==
name|EOF
condition|)
return|return
name|EOF
return|;
else|else
return|return
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
name|_gptr
return|;
block|}
name|int
name|snextc
argument_list|()
block|{
if|if
condition|(
name|_gptr
operator|>=
name|_egptr
operator|&&
name|__underflow
argument_list|(
name|this
argument_list|)
operator|==
name|EOF
condition|)
return|return
name|EOF
return|;
return|return
name|_gptr
operator|++
operator|,
name|sgetc
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|int
name|sputc
parameter_list|(
name|int
name|c
parameter_list|)
block|{
if|if
condition|(
name|_pptr
operator|>=
name|_epptr
condition|)
return|return
name|__overflow
argument_list|(
name|this
argument_list|,
operator|(
name|unsigned
name|char
operator|)
name|c
argument_list|)
return|;
else|else
return|return
operator|*
name|_pptr
operator|++
operator|=
name|c
operator|,
operator|(
name|unsigned
name|char
operator|)
name|c
return|;
block|}
end_function

begin_function
name|void
name|stossc
parameter_list|()
block|{
if|if
condition|(
name|_gptr
operator|<
name|_egptr
condition|)
name|_gptr
operator|++
expr_stmt|;
block|}
end_function

begin_function_decl
name|int
name|vscan
parameter_list|(
name|char
specifier|const
modifier|*
name|fmt0
parameter_list|,
name|_G_va_list
name|ap
parameter_list|,
name|ios
modifier|*
name|stream
init|=
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scan
parameter_list|(
name|char
specifier|const
modifier|*
name|fmt0
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vform
parameter_list|(
name|char
specifier|const
modifier|*
name|fmt0
parameter_list|,
name|_G_va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|form
parameter_list|(
name|char
specifier|const
modifier|*
name|fmt0
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Work in progress */
end_comment

begin_comment
unit|int collumn();
comment|// Current collumn number (of put pointer). -1 is unknown.
end_comment

begin_comment
unit|void collumn(int c);
comment|// Set collumn number of put pointer to c.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|};
comment|// A backupbuf is a streambuf with full backup and savepoints on reading.
end_comment

begin_comment
comment|// All standard streambufs in the GNU iostream library are backupbufs.
end_comment

begin_comment
comment|// A backupbuf may have two get area:
end_comment

begin_comment
comment|// - The main get area, and (sometimes) the putback area.
end_comment

begin_comment
comment|// Whichever one of these contains the gptr is the current get area;
end_comment

begin_comment
comment|// the other one is the non-current get area.
end_comment

begin_decl_stmt
name|class
name|backupbuf
range|:
name|public
name|streambuf
block|{
name|friend
name|class
name|streammarker
block|;
name|protected
operator|:
name|backupbuf
argument_list|(
argument|int flags=
literal|0
argument_list|)
operator|:
name|streambuf
argument_list|(
argument|flags|_S_IS_BACKUPBUF
argument_list|)
block|{ }
name|public
operator|:
name|virtual
name|int
name|pbackfail
argument_list|(
argument|int c
argument_list|)
block|;
name|virtual
name|int
name|underflow
argument_list|()
block|;
name|virtual
name|int
name|overflow
argument_list|(
argument|int c = EOF
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|__file_fields
block|{
name|short
name|_fileno
decl_stmt|;
name|int
name|_blksize
decl_stmt|;
name|fpos_t
name|_offset
decl_stmt|;
comment|//    char* _save_gptr;  char* _save_egptr;
block|}
struct|;
end_struct

begin_decl_stmt
name|class
name|filebuf
range|:
name|public
name|backupbuf
block|{
name|protected
operator|:
expr|struct
name|__file_fields
name|_fb
block|;
name|void
name|init
argument_list|()
block|;
name|public
operator|:
specifier|static
specifier|const
name|int
name|openprot
block|;
comment|// Non-ANSI AT&T-ism:  Default open protection.
name|filebuf
argument_list|()
block|;
name|filebuf
argument_list|(
argument|int fd
argument_list|)
block|;
name|filebuf
argument_list|(
argument|int fd
argument_list|,
argument|char* p
argument_list|,
argument|int len
argument_list|)
block|;
operator|~
name|filebuf
argument_list|()
block|;
name|filebuf
operator|*
name|attach
argument_list|(
argument|int fd
argument_list|)
block|;
name|filebuf
operator|*
name|open
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|,
specifier|const
name|char
operator|*
name|mode
argument_list|)
block|;
name|filebuf
operator|*
name|open
argument_list|(
argument|const char *filename
argument_list|,
argument|ios::openmode mode
argument_list|,
argument|int prot =
literal|0664
argument_list|)
block|;
name|virtual
name|int
name|underflow
argument_list|()
block|;
name|virtual
name|int
name|overflow
argument_list|(
argument|int c = EOF
argument_list|)
block|;
name|int
name|is_open
argument_list|()
specifier|const
block|{
return|return
name|_fb
operator|.
name|_fileno
operator|>=
literal|0
return|;
block|}
name|int
name|fd
argument_list|()
specifier|const
block|{
return|return
name|is_open
argument_list|()
operator|?
name|_fb
operator|.
name|_fileno
operator|:
name|EOF
return|;
block|}
name|filebuf
operator|*
name|close
argument_list|()
block|;
name|virtual
name|int
name|doallocate
argument_list|()
block|;
name|virtual
name|streampos
name|seekoff
argument_list|(
argument|streamoff
argument_list|,
argument|_seek_dir
argument_list|,
argument|int mode=ios::in|ios::out
argument_list|)
block|;
name|virtual
name|streambuf
operator|*
name|setbuf
argument_list|(
argument|char* p
argument_list|,
argument|int len
argument_list|)
block|;
name|int
name|xsputn
argument_list|(
argument|const char* s
argument_list|,
argument|int n
argument_list|)
block|;
name|int
name|xsgetn
argument_list|(
argument|char* s
argument_list|,
argument|int n
argument_list|)
block|;
name|virtual
name|int
name|sync
argument_list|()
block|;
name|protected
operator|:
comment|// See documentation in filebuf.C.
comment|//    virtual int pbackfail(int c);
name|int
name|is_reading
argument_list|()
block|{
return|return
name|eback
argument_list|()
operator|!=
name|egptr
argument_list|()
return|;
block|}
name|char
operator|*
name|cur_ptr
argument_list|()
block|{
return|return
name|is_reading
argument_list|()
condition|?
name|gptr
argument_list|()
else|:
name|pptr
argument_list|()
return|;
block|}
comment|/* System's idea of pointer */
name|char
operator|*
name|file_ptr
argument_list|()
block|{
return|return
name|eGptr
argument_list|()
return|;
block|}
name|int
name|do_write
argument_list|(
argument|const char *data
argument_list|,
argument|int to_do
argument_list|)
block|;
name|int
name|do_flush
argument_list|()
block|{
return|return
name|do_write
argument_list|(
name|_pbase
argument_list|,
name|_pptr
operator|-
name|_pbase
argument_list|)
return|;
block|}
comment|// Low-level operations (Usually invoke system calls.)
name|virtual
name|_G_ssize_t
name|sys_read
argument_list|(
argument|char* buf
argument_list|,
argument|_G_size_t size
argument_list|)
block|;
name|virtual
name|fpos_t
name|sys_seek
argument_list|(
name|fpos_t
argument_list|,
name|_seek_dir
argument_list|)
block|;
name|virtual
name|_G_ssize_t
name|sys_write
argument_list|(
specifier|const
name|void
operator|*
argument_list|,
name|long
argument_list|)
block|;
name|virtual
name|int
name|sys_stat
argument_list|(
name|void
operator|*
argument_list|)
block|;
comment|// Actually, a (struct stat*)
name|virtual
name|int
name|sys_close
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|inline
name|ios
operator|::
name|ios
argument_list|(
argument|streambuf* sb
comment|/* = 0 */
argument_list|,
argument|ostream* tie
comment|/* = 0 */
argument_list|)
block|{
name|_state
operator|=
name|sb
operator|?
name|ios
operator|::
name|goodbit
operator|:
name|ios
operator|::
name|badbit
block|;
name|_exceptions
operator|=
literal|0
block|;
name|_strbuf
operator|=
name|sb
block|;
name|_tie
operator|=
name|tie
block|;
name|_width
operator|=
literal|0
block|;
name|_fill
operator|=
literal|' '
block|;
name|_flags
operator|=
name|ios
operator|::
name|skipws
operator||
name|ios
operator|::
name|dec
block|;
name|_precision
operator|=
literal|6
block|; }
specifier|inline
name|ios
operator|::
operator|~
name|ios
argument_list|()
block|{
if|if
condition|(
operator|!
operator|(
name|_flags
operator|&
operator|(
name|unsigned
name|int
operator|)
name|ios
operator|::
name|dont_close
operator|)
condition|)
name|delete
name|_strbuf
decl_stmt|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STREAMBUF_H */
end_comment

end_unit

