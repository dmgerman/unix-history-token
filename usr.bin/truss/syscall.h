begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * System call arguments come in several flavours:  * Hex -- values that should be printed in hex (addresses)  * Octal -- Same as above, but octal  * Int -- normal integer values (file descriptors, for example)  * String -- pointers to sensible data.  Note that we treat read() and  *	write() arguments as such, even though they may *not* be  *	printable data.  * Ptr -- pointer to some specific structure.  Just print as hex for now.  * Quad -- a double-word value.  e.g., lseek(int, offset_t, int)  * Stat -- a pointer to a stat buffer.  Currently unused.  * Ioctl -- an ioctl command.  Woefully limited.  *  * In addition, the pointer types (String, Ptr) may have OUT masked in --  * this means that the data is set on *return* from the system call -- or  * IN (meaning that the data is passed *into* the system call).  */
end_comment

begin_comment
comment|/*  * $Id: syscall.h,v 1.1 1997/12/06 05:23:07 sef Exp $  */
end_comment

begin_enum
enum|enum
name|Argtype
block|{
name|None
init|=
literal|1
block|,
name|Hex
block|,
name|Octal
block|,
name|Int
block|,
name|String
block|,
name|Ptr
block|,
name|Stat
block|,
name|Ioctl
block|,
name|Quad
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|ARG_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|OUT
value|0x100
end_define

begin_define
define|#
directive|define
name|IN
comment|/*0x20*/
value|0
end_define

begin_struct
struct|struct
name|syscall_args
block|{
name|enum
name|Argtype
name|type
decl_stmt|;
name|int
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|syscall
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|ret_type
decl_stmt|;
comment|/* 0, 1, or 2 return values */
name|int
name|nargs
decl_stmt|;
comment|/* actual number of meaningful arguments */
comment|/* Hopefully, no syscalls with> 10 args */
name|struct
name|syscall_args
name|args
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|syscall
modifier|*
name|get_syscall
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_string
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|print_arg
parameter_list|(
name|int
parameter_list|,
name|struct
name|syscall_args
modifier|*
parameter_list|,
name|unsigned
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_syscall
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

