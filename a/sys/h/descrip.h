begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	descrip.h	5.3	82/07/21	*/
end_comment

begin_define
define|#
directive|define
name|DNSTD
value|5
end_define

begin_comment
comment|/* number of standard descriptors */
end_comment

begin_comment
comment|/* offsets of standard descriptors from dstd() */
end_comment

begin_define
define|#
directive|define
name|DOFF_KERNEL
value|0
end_define

begin_comment
comment|/* descriptor of kernel */
end_comment

begin_define
define|#
directive|define
name|DOFF_IPC
value|1
end_define

begin_comment
comment|/* UNIX ipc domain */
end_comment

begin_define
define|#
directive|define
name|DOFF_ROOT
value|2
end_define

begin_comment
comment|/* root directory */
end_comment

begin_define
define|#
directive|define
name|DOFF_DOT
value|3
end_define

begin_comment
comment|/* current directory */
end_comment

begin_define
define|#
directive|define
name|DOFF_TERMINAL
value|4
end_define

begin_comment
comment|/* terminal, used in /dev/tty */
end_comment

begin_comment
comment|/* types of descriptors */
end_comment

begin_define
define|#
directive|define
name|DTYPE_KERNEL
value|1
end_define

begin_comment
comment|/* handle to UNIX kernel */
end_comment

begin_define
define|#
directive|define
name|DTYPE_FILESYS
value|2
end_define

begin_comment
comment|/* handle to file system */
end_comment

begin_define
define|#
directive|define
name|DTYPE_FILE
value|3
end_define

begin_comment
comment|/* file */
end_comment

begin_define
define|#
directive|define
name|DTYPE_DIR
value|4
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|DTYPE_BDEV
value|5
end_define

begin_comment
comment|/* structured device */
end_comment

begin_define
define|#
directive|define
name|DTYPE_CDEV
value|6
end_define

begin_comment
comment|/* unstructured device */
end_comment

begin_define
define|#
directive|define
name|DTYPE_PROCESS
value|7
end_define

begin_comment
comment|/* process control handle */
end_comment

begin_define
define|#
directive|define
name|DTYPE_SOCKET
value|8
end_define

begin_comment
comment|/* communications endpoint */
end_comment

begin_define
define|#
directive|define
name|DTYPE_DOMAIN
value|9
end_define

begin_comment
comment|/* communications domain */
end_comment

begin_define
define|#
directive|define
name|DTYPE_TERMINAL
value|10
end_define

begin_comment
comment|/* terminal */
end_comment

begin_comment
comment|/* descriptor type structure for dtype and dwrap */
end_comment

begin_struct
struct|struct
name|dtype
block|{
name|int
name|dt_type
decl_stmt|;
comment|/* object type */
name|int
name|dt_protocol
decl_stmt|;
comment|/* protocol implementing type */
block|}
struct|;
end_struct

begin_comment
comment|/* flags for how in dnblock(d, how) */
end_comment

begin_define
define|#
directive|define
name|DNBLOCK_IN
value|0x1
end_define

begin_comment
comment|/* input */
end_comment

begin_define
define|#
directive|define
name|DNBLOCK_OUT
value|0x2
end_define

begin_comment
comment|/* output or in-progress operation */
end_comment

begin_define
define|#
directive|define
name|DNBLOCK_INOUT
value|0x3
end_define

begin_comment
comment|/* input and output */
end_comment

begin_define
define|#
directive|define
name|DNBLOCK_EXCEPT
value|0x4
end_define

begin_comment
comment|/* exceptional condition */
end_comment

begin_define
define|#
directive|define
name|DNBLOCK_SAME
value|0x8
end_define

begin_comment
comment|/* leave as is */
end_comment

end_unit

