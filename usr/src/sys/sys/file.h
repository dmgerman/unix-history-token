begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	file.h	4.9	81/11/08	*/
end_comment

begin_comment
comment|/*  * One file structure is allocated  * for each open/creat/pipe call.  * Main use is to hold the read/write  * pointer associated with each open  * file.  */
end_comment

begin_struct
struct|struct
name|file
block|{
name|short
name|f_flag
decl_stmt|;
comment|/* read/write and type (socket or inode) */
name|short
name|f_count
decl_stmt|;
comment|/* reference count */
union|union
block|{
struct|struct
name|f_in
block|{
name|struct
name|inode
modifier|*
name|fi_inode
decl_stmt|;
name|off_t
name|fi_offset
decl_stmt|;
block|}
name|f_in
struct|;
struct|struct
name|f_so
block|{
name|struct
name|socket
modifier|*
name|fs_socket
decl_stmt|;
block|}
name|f_so
struct|;
block|}
name|f_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|f_offset
value|f_un.f_in.fi_offset
end_define

begin_define
define|#
directive|define
name|f_inode
value|f_un.f_in.fi_inode
end_define

begin_define
define|#
directive|define
name|f_socket
value|f_un.f_so.fs_socket
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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

begin_function_decl
name|struct
name|file
modifier|*
name|getf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|file
modifier|*
name|falloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|FINODE
value|0x0
end_define

begin_comment
comment|/* descriptor of an inode (pseudo) */
end_comment

begin_define
define|#
directive|define
name|FREAD
value|0x1
end_define

begin_comment
comment|/* descriptor read/receive'able */
end_comment

begin_define
define|#
directive|define
name|FWRITE
value|0x2
end_define

begin_comment
comment|/* descriptor write/send'able */
end_comment

begin_define
define|#
directive|define
name|FSOCKET
value|0x4
end_define

begin_comment
comment|/* descriptor of a socket */
end_comment

end_unit

