begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)file.h	7.5 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"fcntl.h"
end_include

begin_include
include|#
directive|include
file|"unistd.h"
end_include

begin_comment
comment|/*  * Descriptor table entry.  * One for each kernel object.  */
end_comment

begin_struct
struct|struct
name|file
block|{
name|int
name|f_flag
decl_stmt|;
comment|/* see below */
define|#
directive|define
name|DTYPE_VNODE
value|1
comment|/* file */
define|#
directive|define
name|DTYPE_SOCKET
value|2
comment|/* communications endpoint */
name|short
name|f_type
decl_stmt|;
comment|/* descriptor type */
name|short
name|f_count
decl_stmt|;
comment|/* reference count */
name|short
name|f_msgcount
decl_stmt|;
comment|/* references from message queue */
name|struct
name|ucred
modifier|*
name|f_cred
decl_stmt|;
comment|/* credentials associated with descriptor */
struct|struct
name|fileops
block|{
name|int
function_decl|(
modifier|*
name|fo_read
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_write
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_ioctl
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_select
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_close
function_decl|)
parameter_list|()
function_decl|;
block|}
modifier|*
name|f_ops
struct|;
name|caddr_t
name|f_data
decl_stmt|;
comment|/* inode */
name|off_t
name|f_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|file
modifier|*
name|file
decl_stmt|,
modifier|*
name|fileNFILE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* convert O_RDONLY/O_WRONLY/O_RDWR to FREAD/FWRITE */
end_comment

begin_define
define|#
directive|define
name|FOPEN
value|(-1)
end_define

begin_define
define|#
directive|define
name|FREAD
value|1
end_define

begin_define
define|#
directive|define
name|FWRITE
value|2
end_define

begin_comment
comment|/* kernel only versions -- deprecated, should be removed */
end_comment

begin_define
define|#
directive|define
name|FCREAT
value|O_CREAT
end_define

begin_define
define|#
directive|define
name|FDEFER
value|O_DEFER
end_define

begin_define
define|#
directive|define
name|FEXCL
value|O_EXCL
end_define

begin_define
define|#
directive|define
name|FEXLOCK
value|O_EXLOCK
end_define

begin_define
define|#
directive|define
name|FMARK
value|O_MARK
end_define

begin_define
define|#
directive|define
name|FSHLOCK
value|O_SHLOCK
end_define

begin_define
define|#
directive|define
name|FTRUNC
value|O_TRUNC
end_define

begin_comment
comment|/* bits to save after open */
end_comment

begin_define
define|#
directive|define
name|FMASK
value|(FREAD|FWRITE|O_APPEND|O_ASYNC|O_NONBLOCK)
end_define

begin_comment
comment|/* bits not settable by fcntl(F_SETFL, ...) */
end_comment

begin_define
define|#
directive|define
name|FCNTLCANT
value|(FREAD|FWRITE|O_DEFER|O_EXLOCK|O_MARK|O_SHLOCK)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* operation for lseek(2); renamed by POSIX 1003.1 to unistd.h */
end_comment

begin_define
define|#
directive|define
name|L_SET
value|0
end_define

begin_comment
comment|/* set file offset to offset */
end_comment

begin_define
define|#
directive|define
name|L_INCR
value|1
end_define

begin_comment
comment|/* set file offset to current plus offset */
end_comment

begin_define
define|#
directive|define
name|L_XTND
value|2
end_define

begin_comment
comment|/* set file offset to EOF plus offset */
end_comment

end_unit

